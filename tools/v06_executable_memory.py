#!/usr/bin/env python3
"""Prove Theme Park's executable WRAM/RAM epoch result from closed 05C authority."""
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
from analysis.v06_executable_memory import classify_execution_address, parse_context_key


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read_csv(path: Path) -> list[dict[str, str]]:
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def write_json(path: Path, value: object) -> None:
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + "\n",
                    encoding="utf-8", newline="\n")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument("--out", type=Path, default=ROOT / "docs")
    args = parser.parse_args()
    load_canonical_rom(args.rom)

    summary_path = ROOT / "docs" / "V05C-flow-summary.json"
    v05 = json.loads(summary_path.read_text(encoding="utf-8"))
    if v05.get("status") != "FLOW_CLOSED_NOT_PRODUCTION_ADMITTED":
        raise ValueError("06C requires closed 05C source-flow authority")
    if v05["frontiers"] or v05["byte_conflict_rows"]:
        raise ValueError("06C cannot consume unresolved 05C flow")

    contexts_path = ROOT / "docs" / "V05C-contexts.csv"
    edges_path = ROOT / "docs" / "V05C-edges.csv"
    reentry_path = ROOT / "docs" / "V05C-interrupt-reentry.csv"
    contexts = read_csv(contexts_path)
    edges = read_csv(edges_path)
    reentry = read_csv(reentry_path)

    rows: list[dict[str, str]] = []
    for row in contexts:
        domain = classify_execution_address(*parse_context_key(row["Context"]))
        rows.append({"Source": "05C_CONTEXT", "Kind": "CONTEXT", "Target": row["Context"],
                     "Domain": domain, "Proof_Source": "V05C-contexts.csv"})
    for row in edges:
        domain = classify_execution_address(*parse_context_key(row["Target"]))
        rows.append({"Source": row["Source"], "Kind": row["Kind"], "Target": row["Target"],
                     "Domain": domain, "Proof_Source": "V05C-edges.csv"})
    for row in reentry:
        domain = classify_execution_address(*parse_context_key(row["Resume_Context"]))
        rows.append({"Source": row["RTI_Context"], "Kind": "NMI_RTI_REENTRY",
                     "Target": row["Resume_Context"], "Domain": domain,
                     "Proof_Source": "V05C-interrupt-reentry.csv"})
    rows.sort(key=lambda row: (row["Source"], row["Kind"], row["Target"], row["Proof_Source"]))

    args.out.mkdir(parents=True, exist_ok=True)
    ledger_path = args.out / "V06C-executable-target-audit.csv"
    with ledger_path.open("w", encoding="utf-8", newline="") as handle:
        fields = ("Source", "Kind", "Target", "Domain", "Proof_Source")
        writer = csv.DictWriter(handle, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)

    non_rom = [row for row in rows if row["Domain"] != "CANONICAL_LOROM"]
    result = {
        "schema": "theme-park-v06c-executable-memory-v1",
        "status": "COMPLETE_ZERO_EXECUTABLE_RAM_EPOCHS" if not non_rom else "FAIL_NON_ROM_EXECUTION_TARGET",
        "dependency_v05_summary_sha256": sha(summary_path),
        "dependency_v05_contexts_sha256": sha(contexts_path),
        "dependency_v05_edges_sha256": sha(edges_path),
        "dependency_v05_interrupt_reentry_sha256": sha(reentry_path),
        "target_rows_checked": len(rows),
        "context_rows_checked": len(contexts),
        "edge_rows_checked": len(edges),
        "interrupt_reentry_rows_checked": len(reentry),
        "non_rom_execution_targets": non_rom,
        "admitted_executable_ram_epochs": 0,
        "admitted_executable_ram_contexts": 0,
        "mutable_operand_fields": [],
        "executable_memory_producers_requiring_epoch": 0,
        "code_overlap_writers_requiring_reconciliation": 0,
        "unknown_ram_pc_policy": "FAIL_CLOSED_NO_RUNTIME_DECODER",
        "changed_opcode_policy": "FAIL_CLOSED_NEW_SOURCE_PROVED_EPOCH_REQUIRED",
        "trace_promotions": 0,
        "oracle_promotions": 0,
        "admitted_production_contexts": 0,
        "native_lowered_contexts": 0,
        "ledger_sha256": sha(ledger_path),
    }
    write_json(args.out / "V06C-executable-memory-summary.json", result)
    print(json.dumps(result, sort_keys=True))
    return 0 if not non_rom else 1


if __name__ == "__main__":
    raise SystemExit(main())
