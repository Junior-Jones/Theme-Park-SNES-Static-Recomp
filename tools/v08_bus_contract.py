#!/usr/bin/env python3
"""Independent 08C map/reconciliation model; never production runtime authority."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_SIZE = 0x100000
WRAM_SIZE = 0x20000
ROM_SHA256 = "c0a7e27131a7d8c9ef52a5227329e6de5846c045a9da1f3f84845e3be8e4efba"


def region(address: int) -> tuple[str, int | None, bool]:
    if not 0 <= address <= 0xFFFFFF:
        raise ValueError("address outside 24-bit bus")
    bank, local = address >> 16, address & 0xFFFF
    if bank in (0x7E, 0x7F):
        return "WRAM", ((bank - 0x7E) << 16) | local, True
    system = bank <= 0x3F or 0x80 <= bank <= 0xBF
    if system:
        if local < 0x2000:
            return "WRAM", local, True
        if 0x2100 <= local <= 0x213F:
            return "PPU", None, local <= 0x2133
        if 0x2140 <= local <= 0x217F:
            return "APUIO", None, True
        if 0x2180 <= local <= 0x2183:
            return "WRAM_PORT", None, True
        if local in (0x4016, 0x4017):
            return "INPUT", None, local == 0x4016
        if 0x4200 <= local <= 0x421F:
            return "CPU_IO", None, local <= 0x420D
        if 0x4300 <= local <= 0x437F:
            return "DMA", None, True
        if local < 0x8000:
            return "OPEN_BUS", None, False
    offset = ((bank & 0x1F) << 15) | (local & 0x7FFF)
    return "ROM", offset, False


def access_clocks(address: int, memsel: int) -> int:
    bank_class, page = (address >> 22) & 3, (address >> 8) & 0xFF
    if bank_class == 1:
        return 8
    if bank_class == 3:
        return 6 if memsel & 1 else 8
    if page <= 0x1F:
        return 8
    if page <= 0x3F:
        return 6
    if page in (0x40, 0x41):
        return 12
    if page <= 0x5F:
        return 6
    if page <= 0x7F:
        return 8
    return 8 if bank_class == 0 else 6 if memsel & 1 else 8


def parse_address(text: str) -> int:
    bank, local = text.split(":")
    return (int(bank, 16) << 16) | int(local, 16)


def owner_for(address: int) -> str:
    kind, _, _ = region(address)
    reg = address & 0xFFFF
    if kind in {"WRAM", "ROM", "WRAM_PORT", "OPEN_BUS"}:
        return "08C_BUS_MEMORY"
    if kind == "PPU":
        return "11C_PPU_STATE"
    if kind == "APUIO":
        return "12C_SSMP_APUIO"
    if kind == "INPUT" or 0x4218 <= reg <= 0x421F:
        return "15C_INPUT"
    if kind == "DMA" or reg in (0x420B, 0x420C):
        return "10C_DMA_HDMA"
    if reg in (0x4210, 0x4211, 0x4212) or reg in range(0x4207, 0x420B) or reg == 0x4200:
        return "09C_SCHEDULER_INTERRUPTS"
    return "08C_CPU_IO"


def reconcile(out_dir: Path, rom_path: Path) -> dict[str, object]:
    data = rom_path.read_bytes()
    if len(data) != ROM_SIZE or hashlib.sha256(data).hexdigest() != ROM_SHA256:
        raise ValueError("wrong Theme Park ROM identity")
    events_path = ROOT / "docs/V07C-hardware-intelligence.csv"
    exact = [row for row in csv.DictReader(events_path.open(encoding="utf-8", newline=""))
             if row["Authority_State"] == "SOURCE_REACHED_REGISTER_EVENT_NOT_IMPLEMENTED_OR_CERTIFIED"]
    output_rows = []
    for row in exact:
        address = parse_address(row["Effective_Address"])
        kind, offset, writable = region(address)
        output_rows.append({
            "Stable_Id": row["Stable_Id"], "Context": row["Context"],
            "Effective_Address": row["Effective_Address"], "Access": row["Access"],
            "Bus_Region": kind, "Physical_Offset": "" if offset is None else f"0x{offset:06X}",
            "Writable": "YES" if writable else "NO", "Current_Owner": owner_for(address),
            "08C_Result": "OWNED_LOCAL" if owner_for(address).startswith("08C_") else "ROUTED_FAIL_CLOSED_UNTIL_OWNER",
        })
    fieldnames = list(output_rows[0])
    csv_path = out_dir / "V08C-source-memory-effects.csv"
    with csv_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fieldnames, lineterminator="\n")
        writer.writeheader(); writer.writerows(output_rows)

    counts = Counter()
    aliases = [0] * ROM_SIZE
    for address in range(0x1000000):
        kind, offset, _ = region(address)
        counts[kind] += 1
        if kind == "ROM":
            assert offset is not None and offset < ROM_SIZE
            aliases[offset] += 1
    alias_distribution = Counter(aliases)
    if alias_distribution != Counter({12: 983040, 10: 65536}):
        raise AssertionError(f"unexpected exact ROM alias domain: {Counter(aliases)}")
    expected = {
        "WRAM": 1179648, "ROM": 12451840, "PPU": 8192, "APUIO": 8192,
        "WRAM_PORT": 512, "INPUT": 256, "CPU_IO": 4096, "DMA": 16384,
        "OPEN_BUS": 3108096,
    }
    if dict(counts) != expected:
        raise AssertionError((counts, expected))
    owner_counts = Counter(row["Current_Owner"] for row in output_rows)
    summary = {
        "schema": "theme-park-v08c-bus-map-v1",
        "status": "PASS_EXHAUSTIVE_SOURCE_CONTRACT_RECONCILED",
        "rom_sha256": ROM_SHA256,
        "rom_size": ROM_SIZE,
        "sram_bytes": 0,
        "address_space_classified": 0x1000000,
        "region_address_counts": dict(sorted(counts.items())),
        "rom_alias_distribution": {str(k): v for k, v in sorted(alias_distribution.items())},
        "source_reached_events_reconciled": len(output_rows),
        "source_reached_owner_counts": dict(sorted(owner_counts.items())),
        "deferred_address_class_events_preserved": 32750,
        "power_on_wram_policy": "UNKNOWN_BITS_WITH_ZERO_REPRESENTATIVE_NOT_AUTHORITY",
        "reset_policy": "PRESERVE_WRAM_MDR_WRIO_TIMERS_MEMSEL_WMADD_MATH; CLEAR_NMITIMEN",
        "open_bus_policy": "CPU_INTERNAL_IO_DOES_NOT_UPDATE_MDR; EXTERNAL_READ_WRITE_DOES",
        "scheduler_boundary": "ACCESS_CLOCK_CLASS_EXPOSED; 09C_OWNS_MASTER_TIME_AND_EVENT_ORDER",
        "persistence": "NO_SRAM_PROVED_BY_01C_PROFILE; NO_LOAD_WRITE_FLUSH_SURFACE",
        "oracle_inputs": [],
    }
    summary_path = out_dir / "V08C-bus-map-summary.json"
    summary_path.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    return summary


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--rom", type=Path, required=True)
    parser.add_argument("--out", type=Path, default=ROOT / "docs")
    args = parser.parse_args()
    summary = reconcile(args.out, args.rom)
    print(json.dumps(summary, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
