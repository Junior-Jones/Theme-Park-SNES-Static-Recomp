#!/usr/bin/env python3
"""Generate Theme Park context timing choreography for the 09C scheduler join.

The generated table contains no game behaviour and admits no contexts.  It
projects the already-frozen V07C contexts onto named W65C816 bus/internal-cycle
phases so the runtime does not move all idle time to instruction retirement.
"""
from __future__ import annotations

import csv
import json
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from analysis.w65c816.opcodes import OPCODES
from analysis.w65c816.timing import cycle_count

READ = {"ADC", "AND", "BIT", "CMP", "CPX", "CPY", "EOR", "LDA", "LDX", "LDY", "ORA", "SBC"}
WRITE = {"STA", "STX", "STY", "STZ"}
RMW = {"ASL", "DEC", "INC", "LSR", "ROL", "ROR", "TRB", "TSB"}
COND_BRANCH = {"BCC", "BCS", "BEQ", "BMI", "BNE", "BPL", "BVC", "BVS"}
DIRECT = {mode for mode in {op.mode for op in OPCODES} if mode.startswith("DP")}
INDEX_READ = {"ABS_X", "ABS_Y", "DP_IND_Y"}
POINTER = {"DP_IND": 2, "DP_X_IND": 2, "DP_IND_Y": 2,
           "STACK_REL_IND_Y": 2, "ABS_IND": 2, "ABS_X_IND": 2,
           "DP_IND_LONG": 3, "DP_IND_LONG_Y": 3, "ABS_IND_LONG": 3}

RULES = {
    "DIRECT_LOW_PRE": 1 << 0,
    "INDEX_DYNAMIC_PRE_DATA": 1 << 1,
    "BRANCH_TAKEN_POST": 1 << 2,
    "BRANCH_PAGE_POST": 1 << 3,
    "JSL_DEFERRED_BANK_FETCH": 1 << 4,
    "STACK_PUSH_PRE": 1 << 5,
    "STACK_PULL_PRE2": 1 << 6,
    "RETURN_POST": 1 << 7,
    "IMPLIED_PRE": 1 << 8,
    "EXTRA_IMPLIED_PRE": 1 << 9,
    "STATUS_PRE": 1 << 10,
    "BRANCH_ALWAYS_POST": 1 << 11,
    "RELLONG_PRE": 1 << 12,
    "RMW_INTERMEDIATE": 1 << 13,
    "INDEX_FIXED_PRE_DATA": 1 << 14,
}


def context_key(text: str) -> int:
    bank, pc, e, m, x = text.split(":")
    return (int(bank, 16) << 19) | (int(pc, 16) << 3) | (int(e) << 2) | (int(m) << 1) | int(x)


def data_width(mnemonic: str, m: int, x: int) -> int:
    if mnemonic in {"CPX", "CPY", "LDX", "LDY", "STX", "STY"}:
        return 1 if x else 2
    return 1 if m else 2


def stack_bytes(mnemonic: str, e: int, m: int, x: int) -> int:
    if mnemonic == "JSL": return 3
    if mnemonic == "JSR": return 2
    if mnemonic in {"PHA", "PLA"}: return 1 if m else 2
    if mnemonic in {"PHX", "PHY", "PLX", "PLY"}: return 1 if x else 2
    if mnemonic in {"PHD", "PLD"}: return 2
    if mnemonic in {"PHB", "PHK", "PHP", "PLB", "PLP"}: return 1
    if mnemonic == "RTI": return 3 if e else 4
    if mnemonic == "RTL": return 3
    if mnemonic == "RTS": return 2
    return 0


def plan(row: dict[str, str]) -> dict[str, object]:
    bank, pc, e_s, m_s, x_s = row["Context"].split(":")
    e, m, x = int(e_s), int(m_s), int(x_s)
    raw = bytes.fromhex(row["Bytes"])
    opcode = raw[0]
    mnemonic, mode = row["Mnemonic"], row["Mode"]
    pointer = POINTER.get(mode, 0)
    data = 0
    if mnemonic in READ | WRITE and not mode.startswith("IMM"):
        data = data_width(mnemonic, m, x)
    elif mnemonic in RMW and mode != "ACC":
        width = data_width(mnemonic, m, x)
        data = width * 2
        if e and width == 1:
            data += 1  # emulation-mode modify cycle is a dummy write
    stack = stack_bytes(mnemonic, e, m, x)
    base = cycle_count(opcode, e=e, m=m, x=x)
    fixed_internal = base - len(raw) - pointer - data - stack
    names: list[str] = []
    if mode in DIRECT:
        names.append("DIRECT_LOW_PRE")
    if mnemonic in READ and mode in INDEX_READ:
        names.append("INDEX_FIXED_PRE_DATA" if not x else "INDEX_DYNAMIC_PRE_DATA")
    if mnemonic in WRITE and mode in {"ABS_X", "ABS_Y"}:
        names.append("INDEX_FIXED_PRE_DATA")
    if mnemonic in RMW and mode == "ABS_X":
        names.append("INDEX_FIXED_PRE_DATA")
    if mnemonic in COND_BRANCH:
        names += ["BRANCH_TAKEN_POST", "BRANCH_PAGE_POST"]
    elif mnemonic == "BRA":
        names.append("BRANCH_ALWAYS_POST")
    elif mnemonic == "BRL":
        names.append("RELLONG_PRE")
    if mnemonic == "JSL":
        names.append("JSL_DEFERRED_BANK_FETCH")
    elif mnemonic == "JSR" or mnemonic in {"PHA", "PHB", "PHD", "PHK", "PHP", "PHX", "PHY"}:
        names.append("STACK_PUSH_PRE")
    if mnemonic in {"PLA", "PLB", "PLD", "PLP", "PLX", "PLY", "RTI", "RTL", "RTS"}:
        names.append("STACK_PULL_PRE2")
    if mnemonic == "RTS":
        names.append("RETURN_POST")
    if mnemonic in RMW and mode != "ACC":
        names.append("RMW_INTERMEDIATE")
    if mnemonic in {"REP", "SEP"}:
        names.append("STATUS_PRE")
    elif mnemonic == "XBA":
        names += ["IMPLIED_PRE", "EXTRA_IMPLIED_PRE"]
    elif mode in {"IMP", "ACC"} and mnemonic not in {
            "PHA", "PHB", "PHD", "PHK", "PHP", "PHX", "PHY",
            "PLA", "PLB", "PLD", "PLP", "PLX", "PLY", "RTI", "RTL", "RTS"}:
        names.append("IMPLIED_PRE")
        if fixed_internal == 2:
            names.append("EXTRA_IMPLIED_PRE")

    fixed_names = [name for name in names if name not in {
        "DIRECT_LOW_PRE", "INDEX_DYNAMIC_PRE_DATA", "BRANCH_TAKEN_POST", "BRANCH_PAGE_POST"}]
    # JSL's rule contains one internal cycle; its deferred fetch remains a bus cycle.
    fixed_rule_cycles = sum(2 if name == "STACK_PULL_PRE2" else 1 for name in fixed_names)
    if fixed_rule_cycles != fixed_internal:
        raise ValueError(f"unclassified internal cycles {row['Context']} {mnemonic} {mode}: "
                         f"need {fixed_internal}, rules {fixed_names}={fixed_rule_cycles}")
    operand = int.from_bytes(raw[1:], "little")
    return {
        "key": context_key(row["Context"]),
        "address": (int(bank, 16) << 16) | int(pc, 16),
        "operand": operand,
        "flags": sum(RULES[name] for name in names),
        "opcode": opcode,
        "length": len(raw),
        "pointer_reads": pointer,
        "base_cycles": base,
        "mnemonic": mnemonic,
        "mode": mode,
        "rules": ";".join(names),
    }


def main() -> int:
    rows = list(csv.DictReader((ROOT / "docs/V07C-production-manifest.csv").open(encoding="utf-8", newline="")))
    plans = sorted((plan(row) for row in rows), key=lambda item: int(item["key"]))
    out = ROOT / "static-core/generated/timing"
    out.mkdir(parents=True, exist_ok=True)
    defines = "\n".join(f"#define TP_TIMING_{name} 0x{value:08X}u" for name, value in RULES.items())
    (out / "theme_park_v09_timing.h").write_text(f'''#ifndef THEME_PARK_V09_TIMING_H
#define THEME_PARK_V09_TIMING_H
#include <stddef.h>
#include <stdint.h>
{defines}
typedef struct TPScpuTimingPlan {{
    uint32_t key, address, operand, flags;
    uint8_t opcode, length, pointer_reads, base_cycles;
}} TPScpuTimingPlan;
const TPScpuTimingPlan *tp_v09_timing_plan(uint32_t key);
size_t tp_v09_timing_plan_count(void);
#endif
''', encoding="utf-8", newline="\n")
    lines = ['#include "theme_park_v09_timing.h"', '', 'static const TPScpuTimingPlan PLANS[] = {']
    for item in plans:
        lines.append(f'    {{0x{item["key"]:08X}u,0x{item["address"]:06X}u,0x{item["operand"]:06X}u,'
                     f'0x{item["flags"]:08X}u,0x{item["opcode"]:02X}u,{item["length"]}u,'
                     f'{item["pointer_reads"]}u,{item["base_cycles"]}u}},')
    lines += ['};', '', 'size_t tp_v09_timing_plan_count(void) { return sizeof(PLANS) / sizeof(PLANS[0]); }',
              'const TPScpuTimingPlan *tp_v09_timing_plan(uint32_t key) {',
              '    size_t lo = 0u, hi = tp_v09_timing_plan_count();',
              '    while (lo < hi) { size_t mid = lo + (hi - lo) / 2u; if (PLANS[mid].key < key) lo = mid + 1u; else hi = mid; }',
              '    return lo < tp_v09_timing_plan_count() && PLANS[lo].key == key ? &PLANS[lo] : NULL;',
              '}', '']
    (out / "theme_park_v09_timing.c").write_text("\n".join(lines), encoding="utf-8", newline="\n")
    summary = {"schema": 1, "milestone": "09C", "contexts": len(plans),
               "unique_keys": len({p["key"] for p in plans}),
               "rule_counts": dict(sorted(Counter(name for p in plans for name in str(p["rules"]).split(";") if name).items())),
               "authority": "THEME_PARK_V07C_CONTEXTS_PLUS_OFFLINE_W65C816_TIMING_METADATA",
               "runtime_decoder": False, "oracle_used": False}
    (ROOT / "docs/V09C-timing-plan-summary.json").write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    print(json.dumps(summary, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
