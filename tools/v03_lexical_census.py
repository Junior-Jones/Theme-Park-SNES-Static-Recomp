#!/usr/bin/env python3
"""Generate Theme Park 03C lexical/candidate products without execution promotion."""
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

from analysis.v03_lexical import (ROM_SHA256, interest_inventory, lexical_scan, load_canonical_rom,
                                  mask_ranges, offset_to_canonical_address, region_signals)


def write_json(path: Path, value: object) -> None:
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")


def root_candidates(profile: dict) -> list[dict]:
    rows = []
    for vector in profile["vectors"]:
        name = vector["name"]
        target = int(vector["value"], 16)
        if "reserved" in name:
            status, modes = "EXCLUDED_RESERVED_VECTOR_SLOT", []
        elif target < 0x8000:
            status, modes = "REJECTED_OUTSIDE_CANONICAL_LOROM_WINDOW", []
        elif name.startswith("emulation_"):
            status, modes = "PROVED_VECTOR_ROOT_FOR_04C", [(1, 1, 1)]
        else:
            status, modes = "PROVED_VECTOR_ROOT_FOR_04C", [(0, 0, 0), (0, 0, 1), (0, 1, 0), (0, 1, 1)]
        if not modes:
            rows.append({"vector": name, "target": f"00:{target:04X}", "e": "", "m": "", "x": "", "status": status})
        for e, m, x in modes:
            rows.append({"vector": name, "target": f"00:{target:04X}", "e": e, "m": m, "x": x, "status": status})
    return rows


def byte_classification(masks: tuple[int, ...]) -> list[dict]:
    states = []
    for offset, mask in enumerate(masks):
        if 0x7FC0 <= offset <= 0x7FDF:
            states.append(("HEADER", "01C"))
        elif 0x7FE0 <= offset <= 0x7FFF:
            states.append(("VECTOR_AREA", "01C"))
        elif mask:
            states.append(("LEXICAL_START_CANDIDATE", "03C_CANDIDATE_NOT_CODE"))
        else:
            states.append(("NO_VALID_START_AT_BANK_TAIL", "03C"))
    rows = []
    start, current = 0, states[0]
    for offset in range(1, len(states) + 1):
        value = states[offset] if offset < len(states) else None
        if value != current:
            rows.append({"start": start, "end": offset - 1, "byte_count": offset - start,
                         "classification": current[0], "owner": current[1]})
            start, current = offset, value
    return rows


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument("--out", type=Path, default=ROOT / "docs")
    args = parser.parse_args()
    rom = load_canonical_rom(args.rom)
    summary, masks = lexical_scan(rom)
    profile = json.loads((ROOT / "docs" / "V01C-cartridge-profile.json").read_text(encoding="utf-8"))
    roots = root_candidates(profile)
    args.out.mkdir(parents=True, exist_ok=True)

    range_path = args.out / "V03C-lexical-validity-ranges.csv"
    with range_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=("Start_Offset", "End_Offset", "Byte_Count", "Legal_Mode_Mask", "Any_Lexical_Start"), lineterminator="\n")
        writer.writeheader()
        for row in mask_ranges(masks):
            writer.writerow({"Start_Offset": f"0x{row['start']:06X}", "End_Offset": f"0x{row['end']:06X}",
                             "Byte_Count": row["byte_count"], "Legal_Mode_Mask": f"0x{row['legal_mode_mask']:02X}",
                             "Any_Lexical_Start": str(row["any_lexical_start"]).lower()})

    classification_path = args.out / "V03C-byte-classification.csv"
    with classification_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=("Start_Offset", "End_Offset", "Byte_Count", "Classification", "Owner"), lineterminator="\n")
        writer.writeheader()
        for row in byte_classification(masks):
            writer.writerow({"Start_Offset": f"0x{row['start']:06X}", "End_Offset": f"0x{row['end']:06X}",
                             "Byte_Count": row["byte_count"], "Classification": row["classification"], "Owner": row["owner"]})

    roots_path = args.out / "V03C-root-candidates.csv"
    with roots_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=("Vector", "Target", "E", "M", "X", "Status"), lineterminator="\n")
        writer.writeheader()
        for row in roots:
            writer.writerow({key.title(): value for key, value in row.items()})

    interest_path = args.out / "V03C-subsystem-interest.json"
    region_path = args.out / "V03C-region-signals.json"
    write_json(interest_path, interest_inventory(rom, masks))
    write_json(region_path, region_signals(rom))

    classification_counts = {}
    for row in byte_classification(masks):
        classification_counts[row["classification"]] = classification_counts.get(row["classification"], 0) + row["byte_count"]
    summary.update({
        "schema": "theme-park-v03c-lexical-summary-v1",
        "milestone": "03C",
        "authority": "LEXICAL_CANDIDATES_ONLY_NO_EXACT_START_OR_PRODUCTION_ADMISSION",
        "rom_sha256": ROM_SHA256,
        "decoder_semantic_sha256": json.loads((ROOT / "docs" / "V02C-SEMANTIC-MANIFEST.json").read_text(encoding="utf-8"))["decoder_semantic_sha256"],
        "validity_range_rows": len(mask_ranges(masks)),
        "byte_classification_counts": classification_counts,
        "root_candidate_rows": len(roots),
        "proved_vector_context_candidates_for_04c": sum(row["status"] == "PROVED_VECTOR_ROOT_FOR_04C" for row in roots),
        "exact_contexts": 0,
        "admitted_production_contexts": 0,
        "oracle_promotions": 0,
        "trace_promotions": 0,
        "artifacts_sha256": {
            path.name: hashlib.sha256(path.read_bytes()).hexdigest()
            for path in (range_path, classification_path, roots_path, interest_path, region_path)
        },
    })
    write_json(args.out / "V03C-lexical-summary.json", summary)
    print(json.dumps({"status": "PASS", "rows": summary["rows"], "row_digest_sha256": summary["row_digest_sha256"]}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
