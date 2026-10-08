#!/usr/bin/env python3
"""Generate direct native C for the selected Theme Park 07C families.

This is an offline generator.  It consumes only source-proved Theme Park
contexts and emits fixed semantic bodies; it never emits a runtime opcode
decoder or a learned target.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from analysis.w65c816.timing import TimingConditions, cycle_count

OUT = ROOT / "static-core" / "generated" / "scpu"


def read_csv(path: Path) -> list[dict[str, str]]:
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def parse_context(value: str) -> tuple[int, int, int, int, int]:
    bank, pc, e, m, x = value.split(":")
    return int(bank, 16), int(pc, 16), int(e), int(m), int(x)


def context_key(value: str) -> int:
    bank, pc, e, m, x = parse_context(value)
    return (bank << 19) | (pc << 3) | (e << 2) | (m << 1) | x


def c_hex(value: int, width: int = 8) -> str:
    return f"0x{value:0{width}X}u"


def set_next(target: str, cycles: int | str, indent: str = "            ") -> list[str]:
    bank, pc, _e, _m, _x = parse_context(target)
    cycle_expression = f"{cycles}u" if isinstance(cycles, int) else cycles
    return [
        f"{indent}cpu->pbr = {c_hex(bank, 2)};",
        f"{indent}cpu->pc = {c_hex(pc, 4)};",
        f"{indent}if (tp_scpu_expect_next(cpu, {c_hex(context_key(target))}) != TP_SCPU_EXECUTED)",
        f"{indent}    return TP_SCPU_STOPPED;",
        f"{indent}return tp_scpu_finish(cpu, bus, {cycle_expression});",
    ]


def nz8(value: str, indent: str = "            ") -> list[str]:
    return [
        f"{indent}cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));",
        f"{indent}if ((uint8_t)({value}) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
        f"{indent}if (((uint8_t)({value}) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
    ]


def nz16(value: str, indent: str = "            ") -> list[str]:
    return [
        f"{indent}cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));",
        f"{indent}if ((uint16_t)({value}) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
        f"{indent}if (((uint16_t)({value}) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
    ]


def only_target(edges: list[dict[str, str]], source: str) -> str:
    targets = sorted({row["Target"] for row in edges if row["Source"] == source})
    if len(targets) != 1:
        raise ValueError(f"{source} expected one successor, found {targets}")
    return targets[0]


def target_by_kind(edges: list[dict[str, str]], source: str, kind: str) -> str:
    targets = sorted({row["Target"] for row in edges
                      if row["Source"] == source and row["Kind"] == kind})
    if len(targets) != 1:
        raise ValueError(f"{source} expected one {kind} successor, found {targets}")
    return targets[0]


def targets_by_kind(edges: list[dict[str, str]], source: str, kind: str) -> list[str]:
    return sorted({row["Target"] for row in edges
                   if row["Source"] == source and row["Kind"] == kind}, key=context_key)


def successor_targets(edges: list[dict[str, str]], source: str) -> list[str]:
    return sorted({row["Target"] for row in edges if row["Source"] == source},
                  key=context_key)


def set_next_domain(targets: list[str], cycles: int | str,
                    indent: str = "            ") -> list[str]:
    if not targets:
        raise ValueError("empty successor domain")
    addresses = {(parse_context(target)[0], parse_context(target)[1]) for target in targets}
    if len(addresses) != 1:
        raise ValueError(f"mode-domain successors disagree on address: {targets}")
    bank, pc = next(iter(addresses))
    cycle_expression = f"{cycles}u" if isinstance(cycles, int) else cycles
    lines = [
        f"{indent}cpu->pbr = {c_hex(bank, 2)};",
        f"{indent}cpu->pc = {c_hex(pc, 4)};",
        f"{indent}switch (tp_scpu_context_key(cpu)) {{",
    ]
    lines += [f"{indent}    case {c_hex(context_key(target))}:" for target in targets]
    lines += [
        f"{indent}        return tp_scpu_finish(cpu, bus, {cycle_expression});",
        f"{indent}    default:",
        f"{indent}        return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"UNPROVED_SUCCESSOR_CONTEXT\");",
        f"{indent}}}",
    ]
    return lines


def emit_case(row: dict[str, str], edges: list[dict[str, str]]) -> list[str]:
    source = row["Context"]
    bank, pc, e, m, x = parse_context(source)
    raw = bytes.fromhex(row["Bytes"])
    opcode = raw[0]
    operand = int.from_bytes(raw[1:], "little")
    mnemonic, mode = row["Mnemonic"], row["Mode"]
    base_cycles = cycle_count(opcode, e=e, m=m, x=x)
    lines = [f"        case {c_hex(context_key(source))}: {{"]
    byte_values = ", ".join(c_hex(value, 2) for value in raw)
    lines += [
        f"            static const uint8_t expected_bytes[] = {{ {byte_values} }};",
        f"            if (tp_scpu_guard_code(cpu, bus, {c_hex((bank << 16) | pc, 6)},",
        "                                   expected_bytes, sizeof(expected_bytes)) != TP_SCPU_EXECUTED)",
        "                return TP_SCPU_STOPPED;",
    ]

    if mnemonic in ("SEP", "REP") and mode == "IMM8":
        if mnemonic == "SEP":
            lines.append(f"            cpu->p = (uint8_t)(cpu->p | {c_hex(operand, 2)});")
            lines += [
                "            if ((cpu->p & TP_P_X) != 0u) {",
                "                cpu->x &= 0x00FFu;",
                "                cpu->y &= 0x00FFu;",
                "            }",
            ]
        else:
            lines.append(f"            cpu->p = (uint8_t)(cpu->p & {c_hex((~operand) & 0xFF, 2)});")
        targets = successor_targets(edges, source)
        lines += (set_next(targets[0], base_cycles) if len(targets) == 1 else
                  set_next_domain(targets, base_cycles))
    elif mnemonic == "NOP" and mode == "IMP":
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "LDA" and mode == "IMM_M" and m == 1:
        lines.append(f"            const uint8_t value = {c_hex(operand, 2)};")
        lines.append("            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);")
        lines += nz8("value")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("LDX", "LDY") and mode == "IMM_X" and x == 0:
        lines.append(f"            const uint16_t value = {c_hex(operand, 4)};")
        lines.append(f"            cpu->{mnemonic[-1].lower()} = value;")
        lines += nz16("value")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("LDX", "LDY") and mode == "IMM_X" and x == 1:
        lines.append(f"            const uint8_t value = {c_hex(operand, 2)};")
        lines.append(f"            cpu->{mnemonic[-1].lower()} = value;")
        lines += nz8("value")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "LDA" and mode == "IMM_M" and m == 0:
        lines.append(f"            const uint16_t value = {c_hex(operand, 4)};")
        lines.append("            cpu->a = value;")
        lines += nz16("value")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "LDA" and mode == "ABSL_X":
        lines.append(f"            const uint32_t address = ({c_hex(operand, 6)} + (uint32_t)cpu->x) & 0xFFFFFFu;")
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = value;",
            ]
            lines += nz16("value")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "CMP" and mode == "ABSL_X":
        lines.append(
            f"            const uint32_t address = ({c_hex(operand, 6)} + (uint32_t)cpu->x) & 0xFFFFFFu;")
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);",
                "            const uint8_t result = (uint8_t)(left - value);",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                "            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
            ]
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint16_t left = cpu->a;",
                "            const uint16_t result = (uint16_t)(left - value);",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                "            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "ORA" and mode == "ABSL_X":
        lines.append(
            f"            const uint32_t address = ({c_hex(operand, 6)} + (uint32_t)cpu->x) & 0xFFFFFFu;")
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            value = (uint8_t)((cpu->a & 0x00FFu) | value);",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = (uint16_t)(cpu->a | value);",
            ]
            lines += nz16("cpu->a")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "ORA" and mode == "ABSL":
        lines.append(f"            const uint32_t address = {c_hex(operand, 6)};")
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            value = (uint8_t)((cpu->a & 0x00FFu) | value);",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = (uint16_t)(cpu->a | value);",
            ]
            lines += nz16("cpu->a")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "AND" and mode == "ABSL_X":
        lines.append(
            f"            const uint32_t address = ({c_hex(operand, 6)} + (uint32_t)cpu->x) & 0xFFFFFFu;")
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            value = (uint8_t)((cpu->a & 0x00FFu) & value);",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = (uint16_t)(cpu->a & value);",
            ]
            lines += nz16("cpu->a")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "ADC" and mode == "ABSL_X":
        lines.append(
            f"            const uint32_t address = ({c_hex(operand, 6)} + (uint32_t)cpu->x) & 0xFFFFFFu;")
        width = 8 if m == 1 else 16
        c_type = "uint8_t" if m == 1 else "uint16_t"
        read = "tp_scpu_read8" if m == 1 else "tp_scpu_read16"
        lines += [
            f"            {c_type} value = 0u;",
            f"            if ({read}(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            f"            if (tp_scpu_adc(cpu, value, {width}u) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "SBC" and mode == "ABSL_X":
        lines.append(
            f"            const uint32_t address = ({c_hex(operand, 6)} + (uint32_t)cpu->x) & 0xFFFFFFu;")
        width = 8 if m == 1 else 16
        c_type = "uint8_t" if m == 1 else "uint16_t"
        read = "tp_scpu_read8" if m == 1 else "tp_scpu_read16"
        lines += [
            f"            {c_type} value = 0u;",
            f"            if ({read}(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            f"            if (tp_scpu_sbc(cpu, value, {width}u) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("STA", "STZ") and mode in ("ABS", "ABS_X", "ABS_Y"):
        index = (" + (uint32_t)cpu->x" if mode == "ABS_X" else
                 " + (uint32_t)cpu->y" if mode == "ABS_Y" else "")
        value8 = "(uint8_t)(cpu->a & 0x00FFu)" if mnemonic == "STA" else "0u"
        value16 = "cpu->a" if mnemonic == "STA" else "0u"
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = ({c_hex(operand, 4)}{index}) & 0xFFFFFFu;",
        ]
        if m == 1:
            lines += [
                f"            if (tp_scpu_write8(cpu, bus, address, {value8}) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        else:
            lines += [
                f"            if (tp_scpu_write16(cpu, bus, address, {value16}) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("STX", "STY") and mode == "ABS":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = {c_hex(operand, 4)};",
        ]
        if x == 1:
            lines += [
                f"            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->{mnemonic[-1].lower()} & 0x00FFu)) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        else:
            lines += [
                f"            if (tp_scpu_write16(cpu, bus, address, cpu->{mnemonic[-1].lower()}) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("LDA", "LDX", "LDY") and mode == "ABS":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = {c_hex(operand, 4)};",
        ]
        width8 = m == 1 if mnemonic == "LDA" else x == 1
        register = "a" if mnemonic == "LDA" else mnemonic[-1].lower()
        if width8:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
            if mnemonic == "LDA":
                lines.append("            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);")
            else:
                lines.append(f"            cpu->{register} = value;")
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                f"            cpu->{register} = value;",
            ]
            lines += nz16("value")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "ORA" and mode == "ABS":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = {c_hex(operand, 4)};",
        ]
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            value = (uint8_t)((cpu->a & 0x00FFu) | value);",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = (uint16_t)(cpu->a | value);",
            ]
            lines += nz16("cpu->a")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "AND" and mode == "ABS":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = {c_hex(operand, 4)};",
        ]
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            value = (uint8_t)((cpu->a & 0x00FFu) & value);",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = (uint16_t)(cpu->a & value);",
            ]
            lines += nz16("cpu->a")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("AND", "ORA") and mode == "ABS_Y":
        operation = "&" if mnemonic == "AND" else "|"
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = ({c_hex(operand, 4)} + (uint32_t)cpu->y) & 0xFFFFFFu;",
        ]
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                f"            value = (uint8_t)((cpu->a & 0x00FFu) {operation} value);",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                f"            cpu->a = (uint16_t)(cpu->a {operation} value);",
            ]
            lines += nz16("cpu->a")
        timing = (base_cycles if x == 0 else
                  f"{base_cycles}u + ((({c_hex(operand & 0xFF, 2)} + (cpu->y & 0x00FFu)) > 0x00FFu) ? 1u : 0u)")
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic == "LDA" and mode == "ABS_X":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = ({c_hex(operand, 4)} + (uint32_t)cpu->x) & 0xFFFFFFu;",
        ]
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = value;",
            ]
            lines += nz16("value")
        timing = (base_cycles if x == 0 else
                  f"{base_cycles}u + ((({c_hex(operand & 0xFF, 2)} + (cpu->x & 0x00FFu)) > 0x00FFu) ? 1u : 0u)")
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic == "LDA" and mode == "ABS_Y":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = ({c_hex(operand, 4)} + (uint32_t)cpu->y) & 0xFFFFFFu;",
        ]
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = value;",
            ]
            lines += nz16("value")
        # WDC note 4 matches ABS_X: X=0 already paid the mandatory
        # index-add cycle in base_cycles; X=1 pays only on page crossing.
        timing = (base_cycles if x == 0 else
                  f"{base_cycles}u + ((({c_hex(operand & 0xFF, 2)} + (cpu->y & 0x00FFu)) > 0x00FFu) ? 1u : 0u)")
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic == "LDY" and mode == "ABS_X":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = ({c_hex(operand, 4)} + (uint32_t)cpu->x) & 0xFFFFFFu;",
        ]
        if x == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->y = value;",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->y = value;",
            ]
            lines += nz16("value")
        # WDC note 4: X=0 already owns the mandatory index-add cycle in
        # base_cycles; X=1 adds it only when the low-byte addition crosses.
        timing = (base_cycles if x == 0 else
                  f"{base_cycles}u + ((({c_hex(operand & 0xFF, 2)} + (cpu->x & 0x00FFu)) > 0x00FFu) ? 1u : 0u)")
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic == "CMP" and mode in ("ABS_X", "ABS_Y"):
        index = "x" if mode == "ABS_X" else "y"
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = ({c_hex(operand, 4)} + (uint32_t)cpu->{index}) & 0xFFFFFFu;",
        ]
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);",
                "            const uint8_t result = (uint8_t)(left - value);",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                "            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
            ]
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint16_t left = cpu->a;",
                "            const uint16_t result = (uint16_t)(left - value);",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                "            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
            ]
        # WDC note 4: an 8-bit index pays only on page crossing; the
        # X=0 mandatory index-add cycle is already included in base_cycles.
        timing = (base_cycles if x == 0 else
                  f"{base_cycles}u + ((({c_hex(operand & 0xFF, 2)} + (cpu->{index} & 0x00FFu)) > 0x00FFu) ? 1u : 0u)")
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic in ("PHP", "PHA", "PHX", "PHY", "PHK") and mode == "IMP":
        if mnemonic == "PHP":
            push_values = ["cpu->p"]
        elif mnemonic == "PHK":
            push_values = ["cpu->pbr"]
        elif mnemonic in ("PHX", "PHY"):
            register = mnemonic[-1].lower()
            push_values = ([f"(uint8_t)(cpu->{register} & 0x00FFu)"] if x == 1 else
                           [f"(uint8_t)(cpu->{register} >> 8u)",
                            f"(uint8_t)(cpu->{register} & 0x00FFu)"])
        elif m == 1:
            push_values = ["(uint8_t)(cpu->a & 0x00FFu)"]
        else:
            push_values = ["(uint8_t)(cpu->a >> 8u)", "(uint8_t)(cpu->a & 0x00FFu)"]
        for value in push_values:
            lines += [
                f"            if (tp_scpu_push8(cpu, bus, {value}) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("PLA", "PLP", "PLX", "PLY") and mode == "IMP":
        if mnemonic == "PLP":
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->p = value;",
                "            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }",
            ]
        elif mnemonic in ("PLX", "PLY") and x == 1:
            register = mnemonic[-1].lower()
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                f"            cpu->{register} = value;",
            ]
            lines += nz8("value")
        elif mnemonic in ("PLX", "PLY"):
            register = mnemonic[-1].lower()
            lines += [
                "            uint8_t low = 0u, high = 0u;",
                "            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||",
                "                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                f"            cpu->{register} = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));",
            ]
            lines += nz16(f"cpu->{register}")
        elif m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint8_t low = 0u, high = 0u;",
                "            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||",
                "                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));",
            ]
            lines += nz16("cpu->a")
        if mnemonic == "PLP":
            targets = successor_targets(edges, source)
            lines += (set_next(targets[0], base_cycles) if len(targets) == 1 else
                      set_next_domain(targets, base_cycles))
        else:
            lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("LDA", "ORA", "ADC", "SBC", "CMP", "STA", "STZ", "INC", "DEC") and mode == "DP":
        timing = f"{base_cycles}u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u)"
        lines.append(f"            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + {c_hex(operand, 2)});")
        if mnemonic in ("STA", "STZ"):
            store_value = "cpu->a" if mnemonic == "STA" else "0u"
            if m == 1:
                lines += [
                    f"            if (tp_scpu_write8(cpu, bus, address, (uint8_t)({store_value} & 0x00FFu)) != TP_SCPU_EXECUTED)",
                    "                return TP_SCPU_STOPPED;",
                ]
            else:
                lines += [
                    f"            if (tp_scpu_write16(cpu, bus, address, (uint16_t){store_value}) != TP_SCPU_EXECUTED)",
                    "                return TP_SCPU_STOPPED;",
                ]
        elif m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
            if mnemonic in ("INC", "DEC"):
                delta = "+ 1u" if mnemonic == "INC" else "- 1u"
                lines += [
                    f"            value = (uint8_t)(value {delta});",
                    "            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)",
                    "                return TP_SCPU_STOPPED;",
                ]
            elif mnemonic == "ORA":
                lines += [
                    "            value = (uint8_t)((cpu->a & 0x00FFu) | value);",
                    "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
                ]
                lines += nz8("value")
            elif mnemonic in ("ADC", "SBC"):
                helper = mnemonic.lower()
                lines += [
                    f"            if (tp_scpu_{helper}(cpu, value, 8u) != TP_SCPU_EXECUTED)",
                    "                return TP_SCPU_STOPPED;",
                ]
            elif mnemonic == "CMP":
                lines += [
                    "            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);",
                    "            const uint8_t result = (uint8_t)(left - value);",
                    "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                    "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                    "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                    "            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
                ]
            else:
                lines.append("            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);")
                lines += nz8("value")
            if mnemonic in ("INC", "DEC"):
                lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
            if mnemonic in ("INC", "DEC"):
                delta = "+ 1u" if mnemonic == "INC" else "- 1u"
                lines += [
                    f"            value = (uint16_t)(value {delta});",
                    "            if (tp_scpu_write16(cpu, bus, address, value) != TP_SCPU_EXECUTED)",
                    "                return TP_SCPU_STOPPED;",
                ]
            elif mnemonic == "ORA":
                lines += [
                    "            value = (uint16_t)(cpu->a | value);",
                    "            cpu->a = value;",
                ]
                lines += nz16("value")
            elif mnemonic in ("ADC", "SBC"):
                helper = mnemonic.lower()
                lines += [
                    f"            if (tp_scpu_{helper}(cpu, value, 16u) != TP_SCPU_EXECUTED)",
                    "                return TP_SCPU_STOPPED;",
                ]
            elif mnemonic == "CMP":
                lines += [
                    "            const uint16_t left = cpu->a;",
                    "            const uint16_t result = (uint16_t)(left - value);",
                    "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                    "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                    "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                    "            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
                ]
            else:
                lines.append("            cpu->a = value;")
                lines += nz16("value")
            if mnemonic in ("INC", "DEC"):
                lines += nz16("value")
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic in ("INC", "DEC") and mode == "ABS":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = {c_hex(operand, 4)};",
        ]
        delta = "+ 1u" if mnemonic == "INC" else "- 1u"
        if m == 1:
            lines += [
                "            uint8_t old_value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                f"            const uint8_t value = (uint8_t)(old_value {delta});",
            ]
            lines += nz8("value")
            if e == 1:
                lines += [
                    "            if (tp_scpu_write8(cpu, bus, address, old_value) != TP_SCPU_EXECUTED)",
                    "                return TP_SCPU_STOPPED;",
                ]
            lines += [
                "            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        else:
            lines += [
                "            uint16_t old_value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                f"            const uint16_t value = (uint16_t)(old_value {delta});",
            ]
            lines += nz16("value")
            # W65C816 16-bit memory RMW writes the high byte before the low byte.
            lines += [
                "            if (tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED ||",
                "                tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "LDA" and mode == "DP_IND_LONG":
        timing = f"{base_cycles}u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u)"
        lines += [
            "            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;",
            f"            const uint16_t pointer = (uint16_t)(cpu->d + {c_hex(operand, 2)});",
            "            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            const uint32_t address = ((uint32_t)pointer_bank << 16u) |",
            "                ((uint32_t)pointer_high << 8u) | pointer_low;",
        ]
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = value;",
            ]
            lines += nz16("value")
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic == "STA" and mode == "DP_IND_LONG":
        timing = f"{base_cycles}u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u)"
        lines += [
            "            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;",
            f"            const uint16_t pointer = (uint16_t)(cpu->d + {c_hex(operand, 2)});",
            "            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            const uint32_t address = ((uint32_t)pointer_bank << 16u) |",
            "                ((uint32_t)pointer_high << 8u) | pointer_low;",
        ]
        if m == 1:
            lines += [
                "            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        else:
            lines += [
                "            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic == "LDA" and mode == "DP_IND_LONG_Y":
        timing = f"{base_cycles}u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u)"
        lines += [
            "            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;",
            f"            const uint16_t pointer = (uint16_t)(cpu->d + {c_hex(operand, 2)});",
            "            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            const uint32_t address = (((uint32_t)pointer_bank << 16u) |",
            "                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y;",
        ]
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address & 0xFFFFFFu, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address & 0xFFFFFFu, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = value;",
            ]
            lines += nz16("value")
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic in ("AND", "ORA") and mode == "DP_IND_LONG_Y":
        timing = f"{base_cycles}u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u)"
        operation = "&" if mnemonic == "AND" else "|"
        lines += [
            "            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;",
            f"            const uint16_t pointer = (uint16_t)(cpu->d + {c_hex(operand, 2)});",
            "            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |",
            "                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;",
        ]
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                f"            value = (uint8_t)((cpu->a & 0x00FFu) {operation} value);",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                f"            cpu->a = (uint16_t)(cpu->a {operation} value);",
            ]
            lines += nz16("cpu->a")
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic == "STA" and mode == "DP_IND_LONG_Y":
        timing = f"{base_cycles}u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u)"
        lines += [
            "            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;",
            f"            const uint16_t pointer = (uint16_t)(cpu->d + {c_hex(operand, 2)});",
            "            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |",
            "                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;",
        ]
        if m == 1:
            lines += [
                "            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        else:
            lines += [
                "            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic in ("ADC", "SBC") and mode == "DP_IND_LONG_Y":
        timing = f"{base_cycles}u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u)"
        lines += [
            "            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;",
            f"            const uint16_t pointer = (uint16_t)(cpu->d + {c_hex(operand, 2)});",
            "            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |",
            "                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;",
        ]
        width = 8 if m == 1 else 16
        c_type = "uint8_t" if m == 1 else "uint16_t"
        read = "tp_scpu_read8" if m == 1 else "tp_scpu_read16"
        lines += [
            f"            {c_type} value = 0u;",
            f"            if ({read}(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            f"            if (tp_scpu_{mnemonic.lower()}(cpu, value, {width}u) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic == "CMP" and mode == "DP_IND_LONG_Y":
        timing = f"{base_cycles}u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u)"
        lines += [
            "            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;",
            f"            const uint16_t pointer = (uint16_t)(cpu->d + {c_hex(operand, 2)});",
            "            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |",
            "                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;",
        ]
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);",
                "            const uint8_t result = (uint8_t)(left - value);",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                "            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
            ]
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint16_t left = cpu->a;",
                "            const uint16_t result = (uint16_t)(left - value);",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                "            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
            ]
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic in ("CMP", "LDA") and mode == "ABSL":
        lines.append(f"            const uint32_t address = {c_hex(operand, 6)};")
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
            if mnemonic == "LDA":
                lines.append("            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);")
                lines += nz8("value")
            else:
                lines += [
                    "            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);",
                    "            const uint8_t result = (uint8_t)(left - value);",
                    "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                    "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                    "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                    "            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
                ]
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
            if mnemonic == "LDA":
                lines.append("            cpu->a = value;")
                lines += nz16("value")
            else:
                lines += [
                    "            const uint16_t left = cpu->a;",
                    "            const uint16_t result = (uint16_t)(left - value);",
                    "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                    "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                    "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                    "            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
                ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "CMP" and mode == "ABS":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = {c_hex(operand, 4)};",
        ]
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);",
                "            const uint8_t result = (uint8_t)(left - value);",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                "            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
            ]
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint16_t left = cpu->a;",
                "            const uint16_t result = (uint16_t)(left - value);",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                "            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "CPX" and mode == "ABS":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = {c_hex(operand, 4)};",
        ]
        if x == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);",
                "            const uint8_t result = (uint8_t)(left - value);",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                "            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
            ]
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint16_t left = cpu->x;",
                "            const uint16_t result = (uint16_t)(left - value);",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
                "            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
                "            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "STA" and mode == "ABSL":
        lines.append(f"            const uint32_t address = {c_hex(operand, 6)};")
        if m == 1:
            lines += [
                "            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        else:
            lines += [
                "            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "STA" and mode == "ABSL_X":
        lines.append(f"            const uint32_t address = ({c_hex(operand, 6)} + (uint32_t)cpu->x) & 0xFFFFFFu;")
        if m == 1:
            lines += [
                "            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        else:
            lines += [
                "            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "CMP" and mode == "IMM_M" and m == 1:
        lines += [
            "            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);",
            f"            const uint8_t right = {c_hex(operand, 2)};",
            "            const uint8_t result = (uint8_t)(left - right);",
            "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
            "            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
            "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
            "            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "CMP" and mode == "IMM_M" and m == 0:
        lines += [
            "            const uint16_t left = cpu->a;",
            f"            const uint16_t right = {c_hex(operand, 4)};",
            "            const uint16_t result = (uint16_t)(left - right);",
            "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
            "            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
            "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
            "            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("AND", "ORA", "EOR") and mode == "IMM_M":
        operation = {"AND": "&", "ORA": "|", "EOR": "^"}[mnemonic]
        if m == 1:
            lines += [
                f"            const uint8_t value = (uint8_t)(cpu->a {operation} {c_hex(operand, 2)});",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                f"            cpu->a = (uint16_t)(cpu->a {operation} {c_hex(operand, 4)});",
            ]
            lines += nz16("cpu->a")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("CPX", "CPY") and mode == "IMM_X" and x == 0:
        lines += [
            f"            const uint16_t left = cpu->{mnemonic[-1].lower()};",
            f"            const uint16_t right = {c_hex(operand, 4)};",
            "            const uint16_t result = (uint16_t)(left - right);",
            "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
            "            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
            "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
            "            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("CPX", "CPY") and mode == "IMM_X" and x == 1:
        lines += [
            f"            const uint8_t left = (uint8_t)(cpu->{mnemonic[-1].lower()} & 0x00FFu);",
            f"            const uint8_t right = {c_hex(operand, 2)};",
            "            const uint8_t result = (uint8_t)(left - right);",
            "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));",
            "            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
            "            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);",
            "            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("INX", "INY", "DEX", "DEY") and mode == "IMP":
        register = mnemonic[-1].lower()
        delta = "+ 1u" if mnemonic.startswith("IN") else "- 1u"
        mask = "0x00FFu" if x == 1 else "0xFFFFu"
        lines.append(f"            cpu->{register} = (uint16_t)((cpu->{register} {delta}) & {mask});")
        lines += nz8(f"cpu->{register}") if x == 1 else nz16(f"cpu->{register}")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "INC" and mode == "ACC":
        if m == 1:
            lines += [
                "            const uint8_t value = (uint8_t)((cpu->a + 1u) & 0x00FFu);",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += ["            cpu->a = (uint16_t)(cpu->a + 1u);"]
            lines += nz16("cpu->a")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "DEC" and mode == "ACC":
        if m == 1:
            lines += [
                "            const uint8_t value = (uint8_t)((cpu->a - 1u) & 0x00FFu);",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += ["            cpu->a = (uint16_t)(cpu->a - 1u);"]
            lines += nz16("cpu->a")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "XBA" and mode == "IMP":
        lines += [
            "            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));",
        ]
        lines += nz8("cpu->a & 0x00FFu")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("TAX", "TAY") and mode == "IMP":
        register = mnemonic[-1].lower()
        if x == 1:
            lines.append(f"            cpu->{register} = (uint16_t)(cpu->a & 0x00FFu);")
            lines += nz8(f"cpu->{register}")
        else:
            lines.append(f"            cpu->{register} = cpu->a;")
            lines += nz16(f"cpu->{register}")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("TXA", "TYA") and mode == "IMP":
        register = mnemonic[1].lower()
        if m == 1:
            lines += [
                f"            const uint8_t value = (uint8_t)(cpu->{register} & 0x00FFu);",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [f"            cpu->a = cpu->{register};"]
            lines += nz16("cpu->a")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "TXY" and mode == "IMP":
        if x == 1:
            lines.append("            cpu->y = (uint16_t)(cpu->x & 0x00FFu);")
            lines += nz8("cpu->y")
        else:
            lines.append("            cpu->y = cpu->x;")
            lines += nz16("cpu->y")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "TYX" and mode == "IMP":
        if x == 1:
            lines.append("            cpu->x = (uint16_t)(cpu->y & 0x00FFu);")
            lines += nz8("cpu->x")
        else:
            lines.append("            cpu->x = cpu->y;")
            lines += nz16("cpu->x")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("LSR", "ROR") and mode == "ABS_X":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = ({c_hex(operand, 4)} + (uint32_t)cpu->x) & 0xFFFFFFu;",
        ]
        if m == 1:
            expression = ("(old_value >> 1u)" if mnemonic == "LSR" else
                          "((old_value >> 1u) | (((cpu->p & TP_P_C) != 0u) ? 0x80u : 0u))")
            lines += [
                "            uint8_t old_value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                f"            const uint8_t value = (uint8_t){expression};",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
                "            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
            ]
            lines += nz8("value")
            if e == 1:
                lines += [
                    "            if (tp_scpu_write8(cpu, bus, address, old_value) != TP_SCPU_EXECUTED)",
                    "                return TP_SCPU_STOPPED;",
                ]
            lines += [
                "            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        else:
            expression = ("(old_value >> 1u)" if mnemonic == "LSR" else
                          "((old_value >> 1u) | (((cpu->p & TP_P_C) != 0u) ? 0x8000u : 0u))")
            lines += [
                "            uint16_t old_value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                f"            const uint16_t value = (uint16_t){expression};",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
                "            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
            ]
            lines += nz16("value")
            # W65C816 16-bit memory RMW writes the high byte before the low byte.
            lines += [
                "            if (tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED ||",
                "                tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "INC" and mode == "ABS_X":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = ({c_hex(operand, 4)} + (uint32_t)cpu->x) & 0xFFFFFFu;",
        ]
        if m == 1:
            lines += [
                "            uint8_t old_value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint8_t value = (uint8_t)(old_value + 1u);",
            ]
            lines += nz8("value")
            if e == 1:
                lines += [
                    "            if (tp_scpu_write8(cpu, bus, address, old_value) != TP_SCPU_EXECUTED)",
                    "                return TP_SCPU_STOPPED;",
                ]
            lines += [
                "            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        else:
            lines += [
                "            uint16_t old_value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint16_t value = (uint16_t)(old_value + 1u);",
            ]
            lines += nz16("value")
            lines += [
                "            if (tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED ||",
                "                tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "ROR" and mode == "ABS":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = {c_hex(operand, 4)};",
        ]
        if m == 1:
            lines += [
                "            uint8_t old_value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint8_t value = (uint8_t)((old_value >> 1u) | (((cpu->p & TP_P_C) != 0u) ? 0x80u : 0u));",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
                "            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
            ]
            lines += nz8("value")
            if e == 1:
                lines += [
                    "            if (tp_scpu_write8(cpu, bus, address, old_value) != TP_SCPU_EXECUTED)",
                    "                return TP_SCPU_STOPPED;",
                ]
            lines += [
                "            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        else:
            lines += [
                "            uint16_t old_value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint16_t value = (uint16_t)((old_value >> 1u) | (((cpu->p & TP_P_C) != 0u) ? 0x8000u : 0u));",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
                "            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
            ]
            lines += nz16("value")
            # W65C816 16-bit memory RMW writes the high byte before the low byte.
            lines += [
                "            if (tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED ||",
                "                tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "ROL" and mode == "ABS":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = {c_hex(operand, 4)};",
        ]
        if m == 1:
            lines += [
                "            uint8_t old_value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint8_t value = (uint8_t)((old_value << 1u) | (((cpu->p & TP_P_C) != 0u) ? 1u : 0u));",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
                "            if ((old_value & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
            ]
            lines += nz8("value")
            if e == 1:
                lines += [
                    "            if (tp_scpu_write8(cpu, bus, address, old_value) != TP_SCPU_EXECUTED)",
                    "                return TP_SCPU_STOPPED;",
                ]
            lines += [
                "            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        else:
            lines += [
                "            uint16_t old_value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            const uint16_t value = (uint16_t)((old_value << 1u) | (((cpu->p & TP_P_C) != 0u) ? 1u : 0u));",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
                "            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
            ]
            lines += nz16("value")
            lines += [
                "            if (tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED ||",
                "                tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("ASL", "LSR") and mode == "ABS":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = {c_hex(operand, 4)};",
        ]
        if m == 1:
            expression = "(old_value << 1u)" if mnemonic == "ASL" else "(old_value >> 1u)"
            carry_test = "(old_value & 0x80u) != 0u" if mnemonic == "ASL" else "(old_value & 1u) != 0u"
            lines += [
                "            uint8_t old_value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                f"            const uint8_t value = (uint8_t){expression};",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
                f"            if ({carry_test}) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
            ]
            lines += nz8("value")
            if e == 1:
                lines += [
                    "            if (tp_scpu_write8(cpu, bus, address, old_value) != TP_SCPU_EXECUTED)",
                    "                return TP_SCPU_STOPPED;",
                ]
            lines += [
                "            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        else:
            expression = "(old_value << 1u)" if mnemonic == "ASL" else "(old_value >> 1u)"
            carry_test = "(old_value & 0x8000u) != 0u" if mnemonic == "ASL" else "(old_value & 1u) != 0u"
            lines += [
                "            uint16_t old_value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                f"            const uint16_t value = (uint16_t){expression};",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
                f"            if ({carry_test}) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
            ]
            lines += nz16("value")
            lines += [
                "            if (tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED ||",
                "                tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
            ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "ROL" and mode == "ACC":
        if m == 1:
            lines += [
                "            const uint8_t old_value = (uint8_t)(cpu->a & 0x00FFu);",
                "            const uint8_t value = (uint8_t)((old_value << 1u) | ((cpu->p & TP_P_C) != 0u ? 1u : 0u));",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
                "            if ((old_value & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            const uint16_t old_value = cpu->a;",
                "            const uint16_t value = (uint16_t)((old_value << 1u) | ((cpu->p & TP_P_C) != 0u ? 1u : 0u));",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
                "            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            cpu->a = value;",
            ]
            lines += nz16("value")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "ROR" and mode == "ACC":
        if m == 1:
            lines += [
                "            const uint8_t old_value = (uint8_t)(cpu->a & 0x00FFu);",
                "            const uint8_t value = (uint8_t)((old_value >> 1u) | ((cpu->p & TP_P_C) != 0u ? 0x80u : 0u));",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
                "            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            const uint16_t old_value = cpu->a;",
                "            const uint16_t value = (uint16_t)((old_value >> 1u) | ((cpu->p & TP_P_C) != 0u ? 0x8000u : 0u));",
                "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
                "            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
                "            cpu->a = value;",
            ]
            lines += nz16("value")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("ASL", "LSR") and mode == "ACC":
        sign = "0x80u" if m == 1 else "0x8000u"
        c_test = f"(old_value & {sign}) != 0u" if mnemonic == "ASL" else "(old_value & 1u) != 0u"
        expression = "(old_value << 1u)" if mnemonic == "ASL" else "(old_value >> 1u)"
        c_type = "uint8_t" if m == 1 else "uint16_t"
        lines += [
            f"            const {c_type} old_value = ({c_type})(cpu->a & {'0x00FFu' if m == 1 else '0xFFFFu'});",
            f"            const {c_type} value = ({c_type}){expression};",
            "            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
            f"            if ({c_test}) cpu->p = (uint8_t)(cpu->p | TP_P_C);",
        ]
        if m == 1:
            lines.append("            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);")
            lines += nz8("value")
        else:
            lines.append("            cpu->a = value;")
            lines += nz16("value")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "ADC" and mode == "IMM_M":
        width = 8 if m == 1 else 16
        lines += [
            f"            if (tp_scpu_adc(cpu, {c_hex(operand, 2 if width == 8 else 4)}, {width}u) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "SBC" and mode == "IMM_M":
        width = 8 if m == 1 else 16
        lines += [
            f"            if (tp_scpu_sbc(cpu, {c_hex(operand, 2 if width == 8 else 4)}, {width}u) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "ADC" and mode == "ABS":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = {c_hex(operand, 4)};",
        ]
        width = 8 if m == 1 else 16
        c_type = "uint8_t" if m == 1 else "uint16_t"
        read = "tp_scpu_read8" if m == 1 else "tp_scpu_read16"
        lines += [
            f"            {c_type} value = 0u;",
            f"            if ({read}(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            f"            if (tp_scpu_adc(cpu, value, {width}u) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "ADC" and mode == "ABS_Y":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = ({c_hex(operand, 4)} + (uint32_t)cpu->y) & 0xFFFFFFu;",
        ]
        width = 8 if m == 1 else 16
        c_type = "uint8_t" if m == 1 else "uint16_t"
        read = "tp_scpu_read8" if m == 1 else "tp_scpu_read16"
        lines += [
            f"            {c_type} value = 0u;",
            f"            if ({read}(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            f"            if (tp_scpu_adc(cpu, value, {width}u) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        timing = (base_cycles if x == 0 else
                  f"{base_cycles}u + ((({c_hex(operand & 0xFF, 2)} + (cpu->y & 0x00FFu)) > 0x00FFu) ? 1u : 0u)")
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic in ("ADC", "SBC") and mode == "ABS_X":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = ({c_hex(operand, 4)} + (uint32_t)cpu->x) & 0xFFFFFFu;",
        ]
        width = 8 if m == 1 else 16
        c_type = "uint8_t" if m == 1 else "uint16_t"
        read = "tp_scpu_read8" if m == 1 else "tp_scpu_read16"
        helper = mnemonic.lower()
        lines += [
            f"            {c_type} value = 0u;",
            f"            if ({read}(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            f"            if (tp_scpu_{helper}(cpu, value, {width}u) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        # WDC indexed-read note: X=0 already includes the mandatory index-add
        # cycle in the decoded base count; X=1 adds a cycle only on page cross.
        timing = (base_cycles if x == 0 else
                  f"{base_cycles}u + ((({c_hex(operand & 0xFF, 2)} + (cpu->x & 0x00FFu)) > 0x00FFu) ? 1u : 0u)")
        lines += set_next(only_target(edges, source), timing)
    elif mnemonic == "SBC" and mode == "ABS":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = {c_hex(operand, 4)};",
        ]
        width = 8 if m == 1 else 16
        c_type = "uint8_t" if m == 1 else "uint16_t"
        read = "tp_scpu_read8" if m == 1 else "tp_scpu_read16"
        lines += [
            f"            {c_type} value = 0u;",
            f"            if ({read}(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            f"            if (tp_scpu_sbc(cpu, value, {width}u) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "SBC" and mode == "ABSL":
        lines.append(f"            const uint32_t address = {c_hex(operand, 6)};")
        width = 8 if m == 1 else 16
        c_type = "uint8_t" if m == 1 else "uint16_t"
        read = "tp_scpu_read8" if m == 1 else "tp_scpu_read16"
        lines += [
            f"            {c_type} value = 0u;",
            f"            if ({read}(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            f"            if (tp_scpu_sbc(cpu, value, {width}u) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "EOR" and mode == "ABS":
        lines += [
            "            if (cpu->dbr != 0u)",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"DBR_ZERO_PROOF_VIOLATION\");",
            f"            const uint32_t address = {c_hex(operand, 4)};",
        ]
        if m == 1:
            lines += [
                "            uint8_t value = 0u;",
                "            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            value = (uint8_t)((cpu->a & 0x00FFu) ^ value);",
                "            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);",
            ]
            lines += nz8("value")
        else:
            lines += [
                "            uint16_t value = 0u;",
                "            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)",
                "                return TP_SCPU_STOPPED;",
                "            cpu->a = (uint16_t)(cpu->a ^ value);",
            ]
            lines += nz16("cpu->a")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic in ("SEI", "CLC", "SEC") and mode == "IMP":
        if mnemonic == "SEI":
            lines.append("            cpu->p = (uint8_t)(cpu->p | TP_P_I);")
        elif mnemonic == "SEC":
            lines.append("            cpu->p = (uint8_t)(cpu->p | TP_P_C);")
        else:
            lines.append("            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "XCE" and mode == "IMP":
        if row["Carry_In_Facts"] not in ("0", "1"):
            raise ValueError(f"{source} XCE requires a singleton carry-in proof")
        expected_carry = row["Carry_In_Facts"] == "1"
        carry_violation = "== 0u" if expected_carry else "!= 0u"
        lines += [
            f"            if ((cpu->p & TP_P_C) {carry_violation})",
            "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"PROVED_XCE_CARRY_VIOLATION\");",
            "            const uint8_t old_e = cpu->e;",
            "            const uint8_t old_c = (cpu->p & TP_P_C) != 0u ? 1u : 0u;",
            "            cpu->p = old_e != 0u",
            "                ? (uint8_t)(cpu->p | TP_P_C)",
            "                : (uint8_t)(cpu->p & (uint8_t)~TP_P_C);",
            "            cpu->e = old_c;",
            "            if (cpu->e != 0u) {",
            "                cpu->p = (uint8_t)(cpu->p | TP_P_M | TP_P_X);",
            "                cpu->s = (uint16_t)(0x0100u | (cpu->s & 0x00FFu));",
            "            }",
            "            if ((cpu->p & TP_P_X) != 0u) {",
            "                cpu->x &= 0x00FFu;",
            "                cpu->y &= 0x00FFu;",
            "            }",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "TXS" and mode == "IMP":
        lines.append("            cpu->s = cpu->x;")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "TCD" and mode == "IMP":
        lines.append("            cpu->d = cpu->a;")
        lines += nz16("cpu->d")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "PHB" and mode == "IMP":
        lines += [
            "            if (tp_scpu_push8(cpu, bus, cpu->dbr) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "PHD" and mode == "IMP":
        lines += [
            "            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->d >> 8u)) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_push8(cpu, bus, (uint8_t)(cpu->d & 0x00FFu)) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "PLB" and mode == "IMP":
        lines += [
            "            uint8_t value = 0u;",
            "            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            cpu->dbr = value;",
        ]
        lines += nz8("value")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "PLD" and mode == "IMP":
        lines += [
            "            uint8_t low = 0u, high = 0u;",
            "            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            cpu->d = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));",
        ]
        lines += nz16("cpu->d")
        lines += set_next(only_target(edges, source), base_cycles)
    elif mnemonic == "JMP" and mode == "ABS_JUMP":
        lines += set_next(target_by_kind(edges, source, "DIRECT_JUMP"), base_cycles)
    elif mnemonic == "BRL" and mode == "REL16":
        lines += set_next(target_by_kind(edges, source, "BRANCH_ALWAYS"), base_cycles)
    elif mnemonic == "JSR" and mode == "ABS_JUMP":
        target = target_by_kind(edges, source, "DIRECT_CALL")
        return_pc = (pc + len(raw) - 1) & 0xFFFF
        lines += [
            f"            if (tp_scpu_push8(cpu, bus, {c_hex(return_pc >> 8, 2)}) != TP_SCPU_EXECUTED ||",
            f"                tp_scpu_push8(cpu, bus, {c_hex(return_pc & 0xFF, 2)}) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        lines += set_next(target, base_cycles)
    elif mnemonic == "JSL" and mode == "ABSL_JUMP":
        target = target_by_kind(edges, source, "DIRECT_CALL")
        return_pc = (pc + len(raw) - 1) & 0xFFFF
        lines += [
            "            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||",
            f"                tp_scpu_push8(cpu, bus, {c_hex(return_pc >> 8, 2)}) != TP_SCPU_EXECUTED ||",
            f"                tp_scpu_push8(cpu, bus, {c_hex(return_pc & 0xFF, 2)}) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
        ]
        lines += set_next(target, base_cycles)
    elif mnemonic in ("BEQ", "BNE", "BCC", "BCS", "BVC", "BVS", "BMI", "BPL") and mode == "REL8":
        taken_targets = targets_by_kind(edges, source, "BRANCH_TAKEN")
        not_taken_targets = targets_by_kind(edges, source, "BRANCH_NOT_TAKEN")
        if len(taken_targets) > 1 or len(not_taken_targets) > 1 or not (taken_targets or not_taken_targets):
            raise ValueError(f"{source} has invalid conditional-branch successor domain")
        conditions = {
            "BEQ": "(cpu->p & TP_P_Z) != 0u", "BNE": "(cpu->p & TP_P_Z) == 0u",
            "BCS": "(cpu->p & TP_P_C) != 0u", "BCC": "(cpu->p & TP_P_C) == 0u",
            "BVS": "(cpu->p & TP_P_V) != 0u", "BVC": "(cpu->p & TP_P_V) == 0u",
            "BMI": "(cpu->p & TP_P_N) != 0u", "BPL": "(cpu->p & TP_P_N) == 0u",
        }
        condition = conditions[mnemonic]
        next_pc = (pc + len(raw)) & 0xFFFF
        taken_page_crossed = bool(taken_targets and
                                  ((next_pc ^ parse_context(taken_targets[0])[1]) & 0xFF00))
        taken_cycles = cycle_count(opcode, e=e, m=m, x=x,
                                   conditions=TimingConditions(
                                       branch_taken=True,
                                       branch_page_crossed=taken_page_crossed))
        if taken_targets and not_taken_targets:
            lines.append(f"            if ({condition}) {{")
            lines += set_next(taken_targets[0], taken_cycles, "                ")
            lines.append("            }")
            lines += set_next(not_taken_targets[0], base_cycles)
        else:
            fact_owner = {
                "BEQ": ("Zero_In_Facts", "1"), "BNE": ("Zero_In_Facts", "0"),
                "BCS": ("Carry_In_Facts", "1"), "BCC": ("Carry_In_Facts", "0"),
            }.get(mnemonic)
            if fact_owner is None:
                raise ValueError(f"{source} one-arm {mnemonic} lacks an admitted flag-fact domain")
            fact_field, taken_fact = fact_owner
            expected_taken = bool(taken_targets)
            expected_fact = taken_fact if expected_taken else ("0" if taken_fact == "1" else "1")
            if row[fact_field] != expected_fact:
                raise ValueError(
                    f"{source} one-arm {mnemonic} is not justified by singleton {fact_field}")
            violation = f"!({condition})" if expected_taken else condition
            lines += [
                f"            if ({violation})",
                "                return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"PROVED_BRANCH_STATUS_VIOLATION\");",
            ]
            target = taken_targets[0] if expected_taken else not_taken_targets[0]
            lines += set_next(target, taken_cycles if expected_taken else base_cycles)
    elif mnemonic == "BRA" and mode == "REL8":
        lines += set_next(target_by_kind(edges, source, "BRANCH_ALWAYS"), base_cycles)
    elif mnemonic == "RTL" and mode == "IMP" and e == 0:
        targets = targets_by_kind(edges, source, "RETURN_PROVED")
        if not targets:
            raise ValueError(f"{source} has no proved RTL continuation")
        lines += [
            "            uint8_t low = 0u, high = 0u, return_bank = 0u;",
            "            cpu->s = (uint16_t)(cpu->s + 1u);",
            "            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            cpu->s = (uint16_t)(cpu->s + 1u);",
            "            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            cpu->s = (uint16_t)(cpu->s + 1u);",
            "            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);",
            "            cpu->pbr = return_bank;",
        ]
        lines += ["            switch (tp_scpu_context_key(cpu)) {"]
        lines += [f"                case {c_hex(context_key(target))}:" for target in targets]
        lines += [
            f"                    return tp_scpu_finish(cpu, bus, {base_cycles}u);",
            "                default:",
            "                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"UNPROVED_RTL_CONTINUATION\");",
            "            }",
        ]
    elif mnemonic == "RTS" and mode == "IMP":
        targets = targets_by_kind(edges, source, "RETURN_PROVED")
        if not targets:
            raise ValueError(f"{source} has no proved RTS continuation")
        lines += [
            "            uint8_t low = 0u, high = 0u;",
            "            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);",
            "            switch (tp_scpu_context_key(cpu)) {",
        ]
        lines += [f"                case {c_hex(context_key(target))}:" for target in targets]
        lines += [
            f"                    return tp_scpu_finish(cpu, bus, {base_cycles}u);",
            "                default:",
            "                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"UNPROVED_RTS_CONTINUATION\");",
            "            }",
        ]
    elif mnemonic == "RTI" and mode == "IMP" and e == 0:
        targets = targets_by_kind(edges, source, "INTERRUPT_REENTRY_PROVED")
        if len(targets) != 70076:
            raise ValueError(f"{source} expected 70076 proved NMI resumes, found {len(targets)}")
        lines += [
            "            uint8_t pulled_p = 0u, low = 0u, high = 0u, return_bank = 0u;",
            "            if (tp_scpu_pull8(cpu, bus, &pulled_p) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED ||",
            "                tp_scpu_pull8(cpu, bus, &return_bank) != TP_SCPU_EXECUTED)",
            "                return TP_SCPU_STOPPED;",
            "            cpu->p = pulled_p;",
            "            if ((cpu->p & TP_P_X) != 0u) {",
            "                cpu->x &= 0x00FFu;",
            "                cpu->y &= 0x00FFu;",
            "            }",
            "            cpu->pc = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));",
            "            cpu->pbr = return_bank;",
            "            switch (tp_scpu_context_key(cpu)) {",
        ]
        lines += [f"                case {c_hex(context_key(target))}:" for target in targets]
        lines += [
            f"                    return tp_scpu_finish(cpu, bus, {base_cycles}u);",
            "                default:",
            "                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"UNPROVED_NMI_RTI_CONTINUATION\");",
            "            }",
        ]
    else:
        raise ValueError(f"no current 07C native lowerer for {source} {mnemonic}:{mode} E/M/X={e}/{m}/{x}")
    lines += ["        }", ""]
    return lines


def write(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8", newline="\n")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--out", type=Path, default=OUT)
    parser.add_argument(
        "--production-manifest", type=Path,
        default=ROOT / "docs" / "V07C-production-manifest.csv")
    args = parser.parse_args()
    out = args.out
    family_path = ROOT / "docs" / "V07C-selected-contexts.csv"
    edges_path = ROOT / "docs" / "V07C-selected-edges.csv"
    selection_path = ROOT / "docs" / "V07C-selected-families.json"
    semantic_path = ROOT / "docs" / "V02C-SEMANTIC-MANIFEST.json"
    v05_path = ROOT / "docs" / "V05C-flow-summary.json"
    v06_path = ROOT / "docs" / "V06C-executable-memory-summary.json"
    rows = read_csv(family_path)
    edges = read_csv(edges_path)
    edges_by_source: dict[str, list[dict[str, str]]] = defaultdict(list)
    for edge in edges:
        edges_by_source[edge["Source"]].append(edge)
    baseline_path = ROOT / "docs/V07C-delta-baseline-bodies.csv"
    baseline_contexts = ({row["Context"] for row in read_csv(baseline_path)}
                         if baseline_path.exists() else set())
    preflight_rows = [row for row in rows if row["Context"] not in baseline_contexts]
    missing_lowerers = []
    for row in preflight_rows:
        try:
            emit_case(row, edges_by_source.get(row["Context"], []))
        except ValueError as error:
            missing_lowerers.append({
                "context": row["Context"],
                "form": f'{row["Mnemonic"]}:{row["Mode"]}',
                "state": ":".join(row["Context"].split(":")[-3:]),
                "error": str(error),
            })
    if missing_lowerers:
        raise ValueError(
            "new-context lowering preflight found missing owners: " +
            json.dumps(missing_lowerers, sort_keys=True))
    selection = json.loads(selection_path.read_text(encoding="utf-8"))
    if selection["status"] != "SOURCE_FAMILIES_UNDERSTOOD_NOT_YET_ADMITTED":
        raise ValueError("selected families are not at the generation boundary")
    if len(rows) != selection["unique_context_count"]:
        raise ValueError("selected family union count mismatch")
    keys = [context_key(row["Context"]) for row in rows]
    if len(keys) != len(set(keys)):
        raise ValueError("duplicate compact runtime key")
    groups: dict[int, list[dict[str, str]]] = defaultdict(list)
    for row in rows:
        bank, pc, _e, _m, _x = parse_context(row["Context"])
        groups[((bank << 16) | pc) >> 8].append(row)
    shard_paths = []
    prototypes = []
    dispatch_cases = []
    for group in sorted(groups):
        name = f"tp_v07_shard_{group:06X}"
        shard_path = out / f"{name}.c"
        shard_lines = [
            "/* Generated direct Theme Park S-CPU authority; do not edit. */",
            "#include \"tp_v07_generated.h\"", "",
            f"TPScpuExecResult {name}(TPScpuState *cpu, const TPScpuBus *bus) {{",
            "    switch (tp_scpu_context_key(cpu)) {",
        ]
        for row in sorted(groups[group], key=lambda item: context_key(item["Context"])):
            shard_lines += emit_case(row, edges_by_source.get(row["Context"], []))
        shard_lines += ["        default: return TP_SCPU_NOT_MINE;", "    }", "}", ""]
        write(shard_path, "\n".join(shard_lines))
        shard_paths.append(shard_path)
        prototypes.append(f"TPScpuExecResult {name}(TPScpuState *cpu, const TPScpuBus *bus);")
        dispatch_cases.append(f"        case 0x{group:06X}u: result = {name}(cpu, bus); break;")
    header = ["#ifndef TP_V07_GENERATED_H", "#define TP_V07_GENERATED_H",
              "#include \"theme_park_scpu.h\""] + prototypes + [
              "TPScpuExecResult tp_v07_dispatch(TPScpuState *cpu, const TPScpuBus *bus);",
              "#endif", ""]
    write(out / "tp_v07_generated.h", "\n".join(header))
    dispatch = [
        "/* Generated consolidated Theme Park 07C dispatcher; do not edit. */",
        "#include \"tp_v07_generated.h\"", "",
        "TPScpuExecResult tp_v07_dispatch(TPScpuState *cpu, const TPScpuBus *bus) {",
        "    TPScpuExecResult result;", "    uint32_t group;",
        "    if (!tp_scpu_validate_state(cpu))",
        "        return tp_scpu_stop(cpu, 0u, \"INVALID_SCPU_STATE_DOMAIN\");",
        "    group = tp_scpu_address(cpu) >> 8u;", "    switch (group) {",
    ] + dispatch_cases + [
        "        default: result = TP_SCPU_NOT_MINE; break;", "    }",
        "    if (result == TP_SCPU_NOT_MINE)",
        "        return tp_scpu_stop(cpu, tp_scpu_address(cpu), \"UNKNOWN_SCPU_CONTEXT\");",
        "    return result;", "}", ""]
    write(out / "tp_v07_dispatch.c", "\n".join(dispatch))
    source_list = [
        "static-core/src/theme_park_scpu.c",
        "static-core/generated/scpu/tp_v07_dispatch.c",
    ] + [f"static-core/generated/scpu/{path.name}" for path in shard_paths]
    write(out / "tp_v07_sources.txt", "\n".join(source_list) + "\n")

    generated = [
        out / "tp_v07_generated.h", out / "tp_v07_dispatch.c", out / "tp_v07_sources.txt",
    ] + shard_paths
    semantic = json.loads(semantic_path.read_text(encoding="utf-8"))
    manifest = {
        "schema": "theme-park-v07c-generation-v1",
        "status": "GENERATED_SOURCE_RECONCILED_COMPILE_DEFERRED_UNTIL_FULL_07C",
        "family_ids": [row["family_id"] for row in selection["families"]],
        "runtime_context_key": "PBR:PC:E:M:X packed into 27 bits",
        "shard_policy": "256-byte CPU-address group; shard miss returns TP_SCPU_NOT_MINE",
        "final_miss_policy": "one dispatcher stops UNKNOWN_SCPU_CONTEXT",
        "context_count": len(rows),
        "shard_count": len(groups),
        "runtime_opcode_decoder": False,
        "trace_promotions": 0,
        "oracle_promotions": 0,
        "decoder_semantic_sha256": semantic["decoder_semantic_sha256"],
        "generator_sha256": sha(Path(__file__)),
        "input_sha256": {
            "selected_contexts": sha(family_path),
            "selected_edges": sha(edges_path),
            "selected_families": sha(selection_path),
            "v02_semantic_manifest": sha(semantic_path),
            "v05_flow_summary": sha(v05_path),
            "v06_executable_memory_summary": sha(v06_path),
        },
        "generated_sha256": {
            f"static-core/generated/scpu/{path.name}": sha(path) for path in generated
        },
        "generated_source_files": source_list,
        "compiled_sources": [],
    }
    write(out / "V07C-generation-manifest.json",
          json.dumps(manifest, indent=2, sort_keys=True) + "\n")
    production_rows = [
        {
            "Families": row["Families"],
            "Context": row["Context"],
            "Compact_Key": f"{context_key(row['Context']):08X}",
            "Bytes": row["Bytes"],
            "Mnemonic": row["Mnemonic"],
            "Mode": row["Mode"],
            "Shard": f"tp_v07_shard_{(((parse_context(row['Context'])[0] << 16) | parse_context(row['Context'])[1]) >> 8):06X}.c",
            "Admission_State": "NATIVE_SOURCE_GENERATED_UNCOMPILED",
        }
        for row in sorted(rows, key=lambda item: context_key(item["Context"]))
    ]
    args.production_manifest.parent.mkdir(parents=True, exist_ok=True)
    with args.production_manifest.open(
            "w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=tuple(production_rows[0]), lineterminator="\n")
        writer.writeheader()
        writer.writerows(production_rows)
    print(json.dumps({
        "families": len(selection["families"]), "generated_contexts": len(rows), "shards": len(groups),
        "status": manifest["status"],
    }, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
