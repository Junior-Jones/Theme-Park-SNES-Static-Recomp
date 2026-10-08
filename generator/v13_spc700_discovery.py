#!/usr/bin/env python3
"""Discover Theme Park's exact source-owned SPC700 instruction starts offline."""
from __future__ import annotations

import argparse
import hashlib
import json
from collections import Counter, deque
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM = ROOT.parents[1] / "Theme Park (Europe) (En,Fr,De).sfc"
CONTRACT = ROOT / "config/target-contract.json"
UPLOAD_PHYSICAL = 0x70313

# Architectural SPC700 instruction lengths, indexed directly by opcode.  This is
# offline decode metadata; it is never compiled into the production dispatcher.
OP_SIZE = (
    1,1,2,3,2,3,1,2,2,3,3,2,3,1,3,1,
    2,1,2,3,2,3,3,2,3,1,2,2,1,1,3,3,
    1,1,2,3,2,3,1,2,2,3,3,2,3,1,3,2,
    2,1,2,3,2,3,3,2,3,1,2,2,1,1,2,3,
    1,1,2,3,2,3,1,2,2,3,3,2,3,1,3,2,
    2,1,2,3,2,3,3,2,3,1,2,2,1,1,3,3,
    1,1,2,3,2,3,1,2,2,3,3,2,3,1,3,1,
    2,1,2,3,2,3,3,2,3,1,2,2,1,1,2,1,
    1,1,2,3,2,3,1,2,2,3,3,2,3,2,1,3,
    2,1,2,3,2,3,3,2,3,1,2,2,1,1,1,1,
    1,1,2,3,2,3,1,2,2,3,3,2,3,2,1,1,
    2,1,2,3,2,3,3,2,3,1,2,2,1,1,1,1,
    1,1,2,3,2,3,1,2,2,3,3,2,3,2,1,1,
    2,1,2,3,2,3,3,2,2,2,2,2,1,1,3,1,
    1,1,2,3,2,3,1,2,2,3,3,2,3,1,1,1,
    2,1,2,3,2,3,3,2,2,2,3,2,1,1,2,1,
)
COND_REL1 = {0x10, 0x30, 0x50, 0x70, 0x90, 0xB0, 0xD0, 0xF0, 0xFE}
COND_REL2 = {0x03,0x13,0x23,0x33,0x43,0x53,0x63,0x73,
             0x83,0x93,0xA3,0xB3,0xC3,0xD3,0xE3,0xF3,0x2E,0x6E,0xDE}
TERMINAL = {0x6F, 0x7F, 0xEF, 0xFF}
TABLE_JUMPS = {
    # $037C CALL $0DD5 obtains the CPU->S-SMP command byte, then $0380 ASL A
    # and $0381 MOV X,A index this contiguous 21-word table.  The S-CPU command
    # producer's declared command domain ends at immediate $14 (20).
    0x0382: {"base": 0x0454, "indices": range(21),
             "proof": "SCPU_COMMAND_DOMAIN_00_TO_14_AND_21_WORD_ARAM_TABLE"},
    # The event-record selector loaded at $088B from the source-owned record
    # field is doubled before this 16-word table.  The table ends at $0A71,
    # where the first handler body begins.
    0x088F: {"base": 0x0A51, "indices": range(16),
             "proof": "EVENT_RECORD_SELECTOR_0_TO_15_AND_16_WORD_ARAM_TABLE"},
    # Direct-page selector $1A is doubled immediately before this 16-word
    # operation table.  The next source-owned instruction begins at $0C50.
    0x0B7B: {"base": 0x0C30, "indices": range(16),
             "proof": "DRIVER_OPERATION_SELECTOR_0_TO_15_AND_16_WORD_ARAM_TABLE"},
}


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def signed(value: int) -> int:
    return value - 256 if value >= 128 else value


def known(mask: bytes, address: int) -> bool:
    address &= 0xFFFF
    return bool(mask[address >> 3] & (1 << (address & 7)))


def reconstruct() -> tuple[bytearray, bytearray, int, list[dict[str, object]]]:
    contract = json.loads(CONTRACT.read_text(encoding="utf-8"))
    rom = ROM.read_bytes()
    if len(rom) != contract["supported_rom_size_bytes"] or digest(rom) != contract["supported_rom_sha256"]:
        raise ValueError("Theme Park ROM identity mismatch")
    aram = bytearray(65536)
    mask = bytearray(8192)
    for address in range(1, 0xF0):
        mask[address >> 3] |= 1 << (address & 7)
    records: list[dict[str, object]] = []
    cursor = UPLOAD_PHYSICAL
    epoch = 0
    while True:
        size = int.from_bytes(rom[cursor:cursor + 2], "little")
        cursor += 2
        if size == 0:
            entry = int.from_bytes(rom[cursor:cursor + 2], "little")
            break
        destination = int.from_bytes(rom[cursor:cursor + 2], "little")
        cursor += 2
        payload = rom[cursor:cursor + size]
        cursor += size
        if len(payload) != size or destination + size > 65536:
            raise ValueError("invalid Theme Park upload record")
        epoch += 1
        for offset, value in enumerate(payload):
            address = destination + offset
            aram[address] = value
            mask[address >> 3] |= 1 << (address & 7)
        records.append({"epoch": epoch, "destination": destination, "size": size,
                        "payload_sha256": digest(payload)})
    return aram, mask, entry, records


def discover(aram: bytes, mask: bytes, entry: int) -> tuple[dict[int, dict], list[dict], list[dict]]:
    queue = deque([entry & 0xFFFF])
    contexts: dict[int, dict] = {}
    edges: list[dict] = []
    unresolved: list[dict] = []
    while queue:
        pc = queue.popleft() & 0xFFFF
        if pc in contexts:
            continue
        if not known(mask, pc):
            unresolved.append({"pc": f"${pc:04X}", "reason": "UNKNOWN_OPCODE_BYTE"})
            continue
        opcode = aram[pc]
        size = OP_SIZE[opcode]
        addresses = [(pc + offset) & 0xFFFF for offset in range(size)]
        if any(not known(mask, address) for address in addresses):
            unresolved.append({"pc": f"${pc:04X}", "opcode": f"${opcode:02X}",
                               "size": size, "reason": "UNKNOWN_INSTRUCTION_BYTE"})
            continue
        raw = bytes(aram[address] for address in addresses)
        fallthrough = (pc + size) & 0xFFFF
        contexts[pc] = {"pc": f"${pc:04X}", "opcode": f"${opcode:02X}",
                        "size": size, "bytes": raw.hex().upper(),
                        "bytes_sha256": digest(raw), "epoch": 1}
        successors: list[tuple[int, str]] = []
        if opcode in COND_REL1:
            successors = [(fallthrough, "FALLTHROUGH"),
                          ((fallthrough + signed(raw[1])) & 0xFFFF, "BRANCH_TAKEN")]
        elif opcode in COND_REL2:
            successors = [(fallthrough, "FALLTHROUGH"),
                          ((fallthrough + signed(raw[2])) & 0xFFFF, "BRANCH_TAKEN")]
        elif opcode == 0x2F:
            successors = [((fallthrough + signed(raw[1])) & 0xFFFF, "BRA")]
        elif opcode == 0x3F:
            successors = [(raw[1] | (raw[2] << 8), "CALL"), (fallthrough, "CALL_RETURN")]
        elif opcode == 0x4F:
            successors = [(0xFF00 | raw[1], "PCALL"), (fallthrough, "CALL_RETURN")]
        elif opcode == 0x5F:
            successors = [(raw[1] | (raw[2] << 8), "JMP")]
        elif opcode == 0x1F:
            proof = TABLE_JUMPS.get(pc)
            base = raw[1] | (raw[2] << 8)
            if proof is None or proof["base"] != base:
                unresolved.append({"pc": f"${pc:04X}", "opcode": "$1F",
                                   "bytes": raw.hex().upper(), "reason": "JMP_ABS_X_INDIRECT_TARGET_REQUIRED"})
            else:
                for index in proof["indices"]:
                    pointer = (base + index * 2) & 0xFFFF
                    if not known(mask, pointer) or not known(mask, pointer + 1):
                        unresolved.append({"pc": f"${pc:04X}", "table_index": index,
                                           "reason": "UNKNOWN_JUMP_TABLE_WORD"})
                        continue
                    target = aram[pointer] | (aram[(pointer + 1) & 0xFFFF] << 8)
                    successors.append((target, f"JMP_TABLE_{index:02d}"))
        elif (opcode & 0x0F) == 0x01:
            number = opcode >> 4
            vector = 0xFFDE - 2 * number
            if known(mask, vector) and known(mask, vector + 1):
                target = aram[vector] | (aram[vector + 1] << 8)
                successors = [(target, "TCALL"), (fallthrough, "CALL_RETURN")]
            else:
                unresolved.append({"pc": f"${pc:04X}", "opcode": f"${opcode:02X}",
                                   "vector": f"${vector:04X}", "reason": "UNKNOWN_TCALL_VECTOR"})
        elif opcode == 0x0F:
            vector = 0xFFDE
            if known(mask, vector) and known(mask, vector + 1):
                target = aram[vector] | (aram[vector + 1] << 8)
                successors = [(target, "BRK")]
            else:
                unresolved.append({"pc": f"${pc:04X}", "opcode": "$0F",
                                   "vector": "$FFDE", "reason": "UNKNOWN_BRK_VECTOR"})
        elif opcode not in TERMINAL:
            successors = [(fallthrough, "FALLTHROUGH")]
        for target, kind in successors:
            edges.append({"source": f"${pc:04X}", "kind": kind, "target": f"${target:04X}"})
            if target not in contexts:
                queue.append(target)
    return contexts, edges, unresolved


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, default=ROOT / "docs/V13C-spc700-discovery.json")
    args = parser.parse_args()
    aram, mask, entry, records = reconstruct()
    contexts, edges, unresolved = discover(aram, mask, entry)
    owned = Counter()
    for pc, row in contexts.items():
        for offset in range(row["size"]):
            owned[(pc + offset) & 0xFFFF] += 1
    overlap = [f"${address:04X}" for address, count in sorted(owned.items()) if count != 1]
    opcode_counts = Counter(row["opcode"] for row in contexts.values())
    result = {
        "schema": "theme-park-v13c-spc700-discovery-v1",
        "status": "CLOSED" if not unresolved and not overlap else "OPEN",
        "entry_pc": f"${entry:04X}", "epoch": 1, "upload_records": records,
        "aram_sha256": digest(aram), "known_mask_sha256": digest(mask),
        "known_bytes": sum(byte.bit_count() for byte in mask),
        "instruction_contexts": len(contexts), "edges": len(edges),
        "instruction_bytes": len(owned), "overlapping_instruction_bytes": overlap,
        "used_opcode_forms": len(opcode_counts), "opcode_counts": dict(sorted(opcode_counts.items())),
        "unresolved": unresolved, "contexts": [contexts[pc] for pc in sorted(contexts)],
        "edge_rows": edges,
        "authority_policy": "SOURCE_RECONSTRUCTED_ARAM_ONLY_NO_ORACLE_NO_TRACE_PROMOTION",
        "oracle_promotions": 0, "trace_promotions": 0,
        "runtime_decoder_allowed": False,
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps({key: result[key] for key in ("status", "entry_pc", "instruction_contexts",
                                                    "instruction_bytes", "used_opcode_forms", "edges",
                                                    "unresolved")}, indent=2))
    return 0 if result["status"] == "CLOSED" else 2


if __name__ == "__main__":
    raise SystemExit(main())
