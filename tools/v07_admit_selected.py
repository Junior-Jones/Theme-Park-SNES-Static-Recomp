#!/usr/bin/env python3
"""Admit all selected 07C families as generated source, never partial binaries."""
from __future__ import annotations

import csv
import hashlib
import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read_csv(path: Path) -> list[dict[str, str]]:
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def write_json(path: Path, value: object) -> None:
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + "\n",
                    encoding="utf-8", newline="\n")


def main() -> int:
    selected_path = ROOT / "docs/V07C-selected-contexts.csv"
    selection_plan_path = ROOT / "docs/V07C-selected-families.json"
    production_path = ROOT / "docs/V07C-production-manifest.csv"
    generation_path = ROOT / "static-core/generated/scpu/V07C-generation-manifest.json"
    flow_path = ROOT / "docs/V05C-flow-summary.json"
    selected_rows = read_csv(selected_path)
    production_rows = read_csv(production_path)
    selection_plan = json.loads(selection_plan_path.read_text(encoding="utf-8"))
    generation = json.loads(generation_path.read_text(encoding="utf-8"))
    flow = json.loads(flow_path.read_text(encoding="utf-8"))
    if generation["status"] != "GENERATED_SOURCE_RECONCILED_COMPILE_DEFERRED_UNTIL_FULL_07C":
        raise ValueError("selected source generation is not at the admission boundary")
    selected_keys = {row["Context"] for row in selected_rows}
    production_keys = {row["Context"] for row in production_rows}
    if selected_keys != production_keys or len(production_rows) != generation["context_count"]:
        raise ValueError("selected/admitted/generated membership differs")
    for row in production_rows:
        row["Admission_State"] = "ADMITTED_NATIVE_SOURCE_UNCOMPILED"
    with production_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=tuple(production_rows[0]), lineterminator="\n")
        writer.writeheader()
        writer.writerows(production_rows)

    generated_sources = generation["compiled_sources"]
    production_selection = {
        "schema": "theme-park-production-selection-v2",
        "status": "V07C_PARTIAL_SELECTED_FAMILIES_SOURCE_ONLY",
        "admitted_contexts": len(production_rows),
        "generated_contexts": len(production_rows),
        "linked_contexts": 0,
        "compiled_sources": [],
        "generated_authority": generated_sources,
        "generated_dispatcher": "static-core/generated/scpu/tp_v07_dispatch.c",
        "admitted_context_manifest": "docs/V07C-production-manifest.csv",
        "offline_analysis_modules_production_selectable": False,
        "runtime_decoder_allowed": False,
        "partial_07c_compilation_allowed": False,
        "full_07c_compile_gate_reached": False,
    }
    production_selection_path = ROOT / "config/production-selection.json"
    write_json(production_selection_path, production_selection)

    forms = Counter(f'{row["Mnemonic"]}:{row["Mode"]}' for row in selected_rows)
    form_families: dict[str, set[str]] = defaultdict(set)
    for row in selected_rows:
        form_families[f'{row["Mnemonic"]}:{row["Mode"]}'].update(row["Families"].split(";"))
    coverage_path = ROOT / "docs/V07C-native-form-coverage.csv"
    with coverage_path.open("w", encoding="utf-8", newline="") as handle:
        fields = ("Form", "Context_Count", "Families", "State")
        writer = csv.DictWriter(handle, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        for form, count in sorted(forms.items()):
            writer.writerow({"Form": form, "Context_Count": count,
                             "Families": ";".join(sorted(form_families[form])),
                             "State": "DIRECT_NATIVE_SOURCE_GENERATED"})
    summary = {
        "schema": "theme-park-v07c-lowering-summary-v1",
        "status": "IN_PROGRESS_SELECTED_FAMILIES_ADMITTED_SOURCE_ONLY",
        "exact_source_proved_contexts": flow["exact_contexts"],
        "admitted_production_contexts": len(production_rows),
        "native_source_contexts": len(production_rows),
        "linked_contexts": 0,
        "confirmed_not_yet_lowered_contexts": flow["exact_contexts"] - len(production_rows),
        "source_candidate_contexts_total": flow["exact_contexts"],
        "selected_source_candidate_contexts": len(production_rows),
        "unselected_source_candidate_contexts": flow["exact_contexts"] - len(production_rows),
        "runtime_reached_contexts": None,
        "terminology": {
            "source_candidate": "A conservative source-graph context; selection or lowering does not prove real-play runtime reachability.",
            "runtime_reached": "Unknown until the completed core reaches the later permitted confirmation stage.",
        },
        "admitted_families": generation["family_ids"],
        "native_instruction_forms": len(forms),
        "native_mnemonics": len({form.split(":", 1)[0] for form in forms}),
        "runtime_opcode_decoder": False,
        "trace_promotions": 0,
        "oracle_promotions": 0,
        "partial_compilation_performed": False,
        "compile_policy": "DEFER_ALL_OBJECT_AND_STATIC_LIBRARY_COMPILATION_UNTIL_FULL_07C_LOWERING_RECONCILES",
        "admitted_minus_generated": [],
        "generated_minus_admitted": [],
        "dependencies": {
            "selected_families_sha256": sha(selection_plan_path),
            "generation_manifest_sha256": sha(generation_path),
            "v05_flow_summary_sha256": sha(flow_path),
        },
    }
    summary_path = ROOT / "docs/V07C-lowering-summary.json"
    write_json(summary_path, summary)
    receipt = {
        "schema": "theme-park-v07c-selected-family-admission-v1",
        "status": "PASS_SELECTED_FAMILY_SOURCE_ADMISSION_UNCOMPILED",
        "family_ids": generation["family_ids"],
        "admitted_contexts": len(production_rows),
        "generated_contexts": len(production_rows),
        "linked_contexts": 0,
        "compilation_performed": False,
        "products_sha256": {
            "production_manifest": sha(production_path),
            "native_form_coverage": sha(coverage_path),
            "lowering_summary": sha(summary_path),
            "production_selection": sha(production_selection_path),
        },
        "inputs_sha256": {
            "selected_contexts": sha(selected_path),
            "selected_families": sha(selection_plan_path),
            "generation_manifest": sha(generation_path),
        },
    }
    write_json(ROOT / "docs/V07C-selected-family-admission.json", receipt)
    for family in selection_plan["families"]:
        family_rows = [row for row in production_rows if family["family_id"] in row["Families"].split(";")]
        family_receipt = {
            "schema": "theme-park-v07c-family-admission-v1",
            "status": "PASS_SOURCE_ADMISSION_UNCOMPILED",
            "family_id": family["family_id"],
            "admitted_contexts": len(family_rows),
            "generated_contexts": len(family_rows),
            "linked_contexts": 0,
            "compilation_performed": False,
            "combined_admission_sha256": sha(ROOT / "docs/V07C-selected-family-admission.json"),
        }
        number = family["family_id"][-3:]
        write_json(ROOT / f"docs/V07C-family-{number}-admission.json", family_receipt)
    print(json.dumps({
        "families": len(generation["family_ids"]), "admitted": len(production_rows),
        "generated": len(production_rows), "linked": 0,
        "status": receipt["status"],
    }, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
