#!/usr/bin/env python3
"""Prove Theme Park's 12C APUIO surface and source-authored IPL upload."""
from __future__ import annotations

import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM = ROOT.parents[1] / "Theme Park (Europe) (En,Fr,De).sfc"
HARDWARE = ROOT / "docs/V07C-hardware-intelligence.csv"
CONTEXTS = ROOT / "docs/V05C-contexts.csv"
EDGES = ROOT / "docs/V05C-edges.csv"
CONTRACT = ROOT / "config/target-contract.json"
UPLOAD_PHYSICAL = 0x70313
IPL_CLEAR_START = 0x0001
IPL_CLEAR_END_EXCLUSIVE = 0x00F0


def sha_bytes(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def sha(path: Path) -> str:
    return sha_bytes(path.read_bytes())


def aram_state_hash(aram: bytes, known: bytes) -> str:
    digest = hashlib.sha256()
    digest.update(b"THEME-PARK-V12C-ARAM\0")
    digest.update(aram)
    digest.update(known)
    return digest.hexdigest()


def main() -> int:
    contract = json.loads(CONTRACT.read_text(encoding="utf-8"))
    rom = ROM.read_bytes()
    if len(rom) != contract["supported_rom_size_bytes"] or sha_bytes(rom) != contract["supported_rom_sha256"]:
        raise ValueError("Theme Park ROM identity mismatch")

    context_rows = list(csv.DictReader(CONTEXTS.open(encoding="utf-8", newline="")))
    contexts = {row["Context"]: row for row in context_rows}
    anchors = {
        "0E:8039:0:1:1": "08",
        "0E:8043:0:0:0": "A91383",
        "0E:8046:0:0:0": "8500",
        "0E:8048:0:0:0": "20A382",
        "0E:82A3:0:0:0": "08",
        "0E:82AC:0:0:0": "CF402100",
        "0E:82CE:0:0:0": "8F402100",
        "0E:82ED:0:0:0": "8F422100",
        "0E:8300:0:1:0": "8F402100",
    }
    for context, encoded in anchors.items():
        if context not in contexts or contexts[context]["Bytes"] != encoded:
            raise ValueError(f"upload routine anchor mismatch: {context}")
    edges = list(csv.DictReader(EDGES.open(encoding="utf-8", newline="")))
    if not any(row["Source"] == "0E:8048:0:0:0" and row["Kind"] == "DIRECT_CALL" and
               row["Target"] == "0E:82A3:0:0:0" for row in edges):
        raise ValueError("upload routine call edge is not source proved")

    exact, unresolved = [], []
    for row in csv.DictReader(HARDWARE.open(encoding="utf-8", newline="")):
        if row["Subsystem"] != "APUIO":
            continue
        proved = row["Address_Proof"] == "EXACT_START_PLUS_DBR_OR_LONG_BANK_PLUS_WIDTH_EXPANSION"
        if proved and row["Effective_Address"].startswith("00:"):
            address = int(row["Effective_Address"][3:], 16)
            if 0x2140 <= address <= 0x2143:
                item = dict(row)
                item["Register"] = f"${address:04X}"
                exact.append(item)
        elif not proved:
            unresolved.append(row)
    exact.sort(key=lambda row: (int(row["ROM_Offset"], 16), row["Context"],
                                int(row["Byte_Event_Index"] or 0)))
    fields = ["Stable_Id", "Families", "Context", "ROM_Offset", "Bytes", "Mnemonic", "Mode",
              "Access", "Instruction_Access_Width", "Byte_Event_Index", "Register", "Address_Proof"]
    events_path = ROOT / "docs/V12C-apuio-exact-register-events.csv"
    with events_path.open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        writer.writerows({field: row[field] for field in fields} for row in exact)

    aram = bytearray(65536)
    known = bytearray(8192)
    for address in range(IPL_CLEAR_START, IPL_CLEAR_END_EXCLUSIVE):
        known[address >> 3] |= 1 << (address & 7)
    records = []
    cursor = UPLOAD_PHYSICAL
    epoch = 0
    while True:
        if cursor + 2 > len(rom):
            raise ValueError("upload length outside ROM")
        size = int.from_bytes(rom[cursor:cursor + 2], "little")
        cursor += 2
        if size == 0:
            if cursor + 2 > len(rom):
                raise ValueError("upload entry outside ROM")
            entry = int.from_bytes(rom[cursor:cursor + 2], "little")
            cursor += 2
            break
        if cursor + 2 + size > len(rom):
            raise ValueError("upload payload outside ROM")
        destination = int.from_bytes(rom[cursor:cursor + 2], "little")
        cursor += 2
        payload_offset = cursor
        payload = rom[cursor:cursor + size]
        cursor += size
        if destination + size > 65536:
            raise ValueError("upload block wraps ARAM")
        for offset, value in enumerate(payload):
            address = destination + offset
            if known[address >> 3] & (1 << (address & 7)):
                raise ValueError(f"unproved upload overlap at ${address:04X}")
            aram[address] = value
            known[address >> 3] |= 1 << (address & 7)
        epoch += 1
        records.append({
            "epoch": epoch,
            "header_physical": f"0x{payload_offset - 4:06X}",
            "payload_physical": f"0x{payload_offset:06X}",
            "destination_start": f"${destination:04X}",
            "destination_end_inclusive": f"${destination + size - 1:04X}",
            "byte_count": size,
            "payload_sha256": sha_bytes(payload),
            "source": "SUPPORTED_THEME_PARK_ROM_UPLOAD_RECORD",
        })

    # Independently reproduce the fixed IPL token protocol from the parsed
    # cartridge bytes.  This does not execute an S-SMP decoder or consult an oracle.
    protocol_aram = bytearray(65536)
    protocol_known = bytearray(8192)
    for address in range(IPL_CLEAR_START, IPL_CLEAR_END_EXCLUSIVE):
        protocol_known[address >> 3] |= 1 << (address & 7)
    acknowledgements = 0
    for record in records:
        destination = int(record["destination_start"][1:], 16)
        payload_offset = int(record["payload_physical"], 16)
        payload = rom[payload_offset:payload_offset + record["byte_count"]]
        expected = 0
        for value in payload:
            protocol_aram[destination] = value
            protocol_known[destination >> 3] |= 1 << (destination & 7)
            destination = (destination + 1) & 0xFFFF
            acknowledgements += 1
            expected = (expected + 1) & 0xFF
        terminator = (expected + 3) & 0xFF
        if terminator != ((record["byte_count"] & 0xFF) + 3) & 0xFF:
            raise AssertionError("IPL terminator arithmetic mismatch")
    if protocol_aram != aram or protocol_known != known:
        raise AssertionError("parsed upload and fixed IPL reconstruction disagree")

    epoch_path = ROOT / "docs/V12C-aram-epoch-receipt.json"
    epoch_receipt = {
        "schema": "theme-park-v12c-aram-epochs-v1",
        "status": "SOURCE_AUTHORED_COLD_UPLOAD_RECONSTRUCTED",
        "fixed_ipl_known_clear": {"start": "$0001", "end_inclusive": "$00EF", "byte_count": 239},
        "upload_table_physical": f"0x{UPLOAD_PHYSICAL:06X}",
        "records": records,
        "terminator_physical": f"0x{cursor - 4:06X}",
        "static_entry_pc": f"${entry:04X}",
        "uploaded_bytes": sum(record["byte_count"] for record in records),
        "upload_epochs": len(records),
        "known_aram_bytes": sum(byte.bit_count() for byte in known),
        "protocol_byte_acknowledgements": acknowledgements,
        "aram_and_knownness_sha256": aram_state_hash(aram, known),
        "oracle_used": False,
        "runtime_spc700_decoder_used": False,
    }
    epoch_path.write_text(json.dumps(epoch_receipt, indent=2, sort_keys=True) + "\n", encoding="utf-8")

    register_counts = Counter(row["Register"] for row in exact)
    access_counts = Counter(row["Access"] for row in exact)
    summary = {
        "schema": "theme-park-v12c-apu-source-join-v1",
        "status": "APUIO_BOOTSTRAP_TIMERS_AND_ARAM_EPOCH_BOUND_TO_THEME_PARK_SOURCE",
        "exact_register_events": len(exact),
        "exact_contexts": len({row["Context"] for row in exact}),
        "exact_register_counts": dict(sorted(register_counts.items())),
        "exact_access_counts": dict(sorted(access_counts.items())),
        "source_reached_registers": sorted(register_counts),
        "implemented_register_surface": ["$2140", "$2141", "$2142", "$2143"],
        "source_reached_registers_missing_owner": [],
        "conservative_unresolved_apuio_intersections": len(unresolved),
        "upload_routine_anchors": anchors,
        "upload_epochs": len(records),
        "uploaded_bytes": sum(record["byte_count"] for record in records),
        "static_entry_pc": f"${entry:04X}",
        "authority": ["runtime/include/theme_park_apu.h", "runtime/src/theme_park_apu.c"],
        "spc700_aot_deferred_to": "13C",
        "sdsp_deferred_to": "16C",
        "oracle_used": False,
        "runtime_spc700_decoder_used": False,
        "frontend_used": False,
        "inputs_sha256": {"rom": sha(ROM), "hardware": sha(HARDWARE),
                          "contexts": sha(CONTEXTS), "edges": sha(EDGES),
                          "contract": sha(CONTRACT)},
        "events_sha256": sha(events_path),
        "epoch_receipt_sha256": sha(epoch_path),
    }
    (ROOT / "docs/V12C-apu-source-join-summary.json").write_text(
        json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    print(json.dumps({"status": summary["status"], "events": len(exact),
                      "unresolved": len(unresolved), "uploaded_bytes": summary["uploaded_bytes"],
                      "entry": summary["static_entry_pc"]}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
