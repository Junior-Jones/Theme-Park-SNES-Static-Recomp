#!/usr/bin/env python3
"""Generate Theme Park 04C reset-rooted exact direct-flow products."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from analysis.v03_lexical import load_canonical_rom
from analysis.v04_contexts import Context, byte_conflicts, cpu_to_rom_offset, discover_direct


def write_json(path: Path, value: object) -> None:
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")


def sha256(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument("--out", type=Path, default=ROOT / "docs")
    args = parser.parse_args()
    rom = load_canonical_rom(args.rom)
    profile = json.loads((ROOT / "docs" / "V01C-cartridge-profile.json").read_text(encoding="utf-8"))
    vectors = {row["name"]: int(row["value"], 16) for row in profile["vectors"]}
    reset = Context(0, vectors["emulation_reset"], 1, 1, 1)
    software_vectors = {
        ("BRK", 0): vectors["native_brk"], ("BRK", 1): vectors["emulation_irq_brk"],
        ("COP", 0): vectors["native_cop"], ("COP", 1): vectors["emulation_cop"],
    }
    result = discover_direct(rom, {reset: ("EMULATION_RESET_VECTOR",)}, software_vectors)
    args.out.mkdir(parents=True, exist_ok=True)

    contexts_path = args.out / "V04C-contexts.csv"
    with contexts_path.open("w", encoding="utf-8", newline="") as handle:
        fields = ("Context", "PBR", "PC", "E", "M", "X", "ROM_Offset", "Bytes", "Mnemonic", "Mode", "Origins")
        writer = csv.DictWriter(handle, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        for context in result.contexts:
            writer.writerow({
                "Context": context.key, "PBR": f"{context.pbr:02X}", "PC": f"{context.pc:04X}",
                "E": context.e, "M": context.m, "X": context.x,
                "ROM_Offset": f"0x{cpu_to_rom_offset(context.pbr, context.pc):06X}",
                "Bytes": result.raw_by_context[context].hex().upper(),
                "Mnemonic": result.mnemonic_by_context[context], "Mode": result.mode_by_context[context],
                "Origins": "|".join(result.origins[context]),
            })

    edges_path = args.out / "V04C-direct-edges.csv"
    with edges_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=("Source", "Kind", "Target"), lineterminator="\n")
        writer.writeheader()
        for edge in result.edges:
            writer.writerow({"Source": edge.source.key, "Kind": edge.kind, "Target": edge.target.key})

    frontiers_path = args.out / "V04C-frontiers.csv"
    with frontiers_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=("Source", "Kind", "Detail", "Owner"), lineterminator="\n")
        writer.writeheader()
        for row in result.frontiers:
            writer.writerow({"Source": row.source.key, "Kind": row.kind, "Detail": row.detail, "Owner": row.owner})

    conflicts = byte_conflicts(result)
    conflicts_path = args.out / "V04C-byte-conflicts.csv"
    with conflicts_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=("ROM_Offset", "Context_Count", "Contexts"), lineterminator="\n")
        writer.writeheader()
        for offset, owners in conflicts:
            writer.writerow({"ROM_Offset": f"0x{offset:06X}", "Context_Count": len(owners), "Contexts": "|".join(owners)})

    sidecar_path = args.out / "V04C-context-intelligence.csv"
    with sidecar_path.open("w", encoding="utf-8", newline="") as handle:
        fields = ("Context", "Carry_In_Facts", "Control_Class", "Literal_Interest", "Deferred_Obligations", "Compiled_Into_Runtime")
        writer = csv.DictWriter(handle, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        frontier_by_source: dict[Context, list[str]] = {}
        for frontier in result.frontiers:
            frontier_by_source.setdefault(frontier.source, []).append(f"{frontier.owner}:{frontier.kind}")
        for context in result.contexts:
            raw = result.raw_by_context[context]
            mnemonic = result.mnemonic_by_context[context]
            mode = result.mode_by_context[context]
            control = "TERMINAL" if mnemonic in ("RTS", "RTL", "RTI", "WAI", "STP") else \
                      "CONTROL" if any(edge.source == context for edge in result.edges) else "LINEAR"
            interest = ""
            if mode in ("ABS", "ABS_X", "ABS_Y") and len(raw) >= 3:
                operand = int.from_bytes(raw[1:3], "little")
                if 0x2100 <= operand <= 0x21FF: interest = "PPU_DBR_UNPROVED"
                elif 0x2140 <= operand <= 0x2143: interest = "APUIO_DBR_UNPROVED"
                elif 0x4200 <= operand <= 0x421F: interest = "CPU_IO_DBR_UNPROVED"
                elif 0x4300 <= operand <= 0x437F: interest = "DMA_HDMA_DBR_UNPROVED"
            writer.writerow({"Context": context.key, "Carry_In_Facts": "|".join(result.carry_facts[context]),
                             "Control_Class": control, "Literal_Interest": interest,
                             "Deferred_Obligations": "|".join(sorted(frontier_by_source.get(context, []))),
                             "Compiled_Into_Runtime": "false"})

    mode_counts: dict[str, int] = {}
    mnemonic_counts: dict[str, int] = {}
    frontier_counts: dict[str, int] = {}
    for context in result.contexts:
        mode_key = f"{context.e}{context.m}{context.x}"
        mode_counts[mode_key] = mode_counts.get(mode_key, 0) + 1
        name = result.mnemonic_by_context[context]
        mnemonic_counts[name] = mnemonic_counts.get(name, 0) + 1
    for row in result.frontiers:
        frontier_counts[row.kind] = frontier_counts.get(row.kind, 0) + 1
    products = (contexts_path, edges_path, frontiers_path, conflicts_path, sidecar_path)
    summary = {
        "schema": "theme-park-v04c-context-summary-v1",
        "status": "DISCOVERY_IN_PROGRESS_NOT_PRODUCTION_ADMITTED",
        "root_policy": "EMULATION_RESET_ONLY; interrupt modes and re-entry deferred to 05C",
        "root_count": 1,
        "root_sha256": hashlib.sha256((reset.key + "|EMULATION_RESET_VECTOR\n").encode()).hexdigest(),
        "exact_direct_contexts": len(result.contexts),
        "unique_cpu_addresses": len({(row.pbr, row.pc) for row in result.contexts}),
        "contexts_by_emx": dict(sorted(mode_counts.items())),
        "mnemonic_counts": dict(sorted(mnemonic_counts.items())),
        "direct_edges": len(result.edges),
        "frontiers": len(result.frontiers),
        "frontiers_by_kind": dict(sorted(frontier_counts.items())),
        "byte_conflict_rows": len(conflicts),
        "admitted_production_contexts": 0,
        "native_lowered_contexts": 0,
        "trace_promotions": 0,
        "oracle_promotions": 0,
        "decoder_semantic_sha256": json.loads((ROOT / "docs" / "V02C-SEMANTIC-MANIFEST.json").read_text(encoding="utf-8"))["decoder_semantic_sha256"],
        "v03_row_digest_sha256": json.loads((ROOT / "docs" / "V03C-lexical-summary.json").read_text(encoding="utf-8"))["row_digest_sha256"],
        "artifacts_sha256": {path.name: sha256(path) for path in products},
    }
    write_json(args.out / "V04C-context-summary.json", summary)
    print(json.dumps(summary, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
