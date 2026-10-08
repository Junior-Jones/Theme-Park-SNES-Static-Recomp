#!/usr/bin/env python3
"""Derive every explicitly selected complete Theme Park 07C procedure family."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from analysis.v07_families import derive_procedure_family


def read_csv(path: Path) -> list[dict[str, str]]:
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def canonical_sha(value: object) -> str:
    payload = json.dumps(value, sort_keys=True, separators=(",", ":")).encode("utf-8")
    return hashlib.sha256(payload).hexdigest()


def write_csv(path: Path, fields: tuple[str, ...], rows: list[dict[str, str]]) -> None:
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)


def compact_key(value: str) -> int:
    bank, pc, e, m, x = value.split(":")
    return (int(bank, 16) << 19) | (int(pc, 16) << 3) | (int(e) << 2) | (int(m) << 1) | int(x)


def operand(row: dict[str, str]) -> int:
    return int.from_bytes(bytes.fromhex(row["Bytes"])[1:], "little")


def access_expression(row: dict[str, str]) -> str:
    value = operand(row)
    if row["Mode"] == "ABS":
        return f"DBR:{value:04X}"
    if row["Mode"] == "ABS_X":
        return f"DBR:{value:04X}+X"
    if row["Mode"] == "ABSL_X":
        return f"{value >> 16:02X}:{value & 0xFFFF:04X}+X"
    return "NONE"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--out", type=Path, default=ROOT / "docs")
    parser.add_argument("--plan", type=Path, default=ROOT / "config/v07-family-plan.json")
    args = parser.parse_args()
    plan = json.loads(args.plan.read_text(encoding="utf-8"))
    if plan["compile_policy"] != "FORBIDDEN_UNTIL_ALL_07C_FAMILIES_ARE_LOWERED_AND_RECONCILED":
        raise ValueError("07C family plan weakened the no-partial-compile rule")
    contexts_path = ROOT / "docs/V05C-contexts.csv"
    edges_path = ROOT / "docs/V05C-edges.csv"
    proofs_path = ROOT / "docs/V05C-dynamic-proofs.csv"
    interrupt_reentry_path = ROOT / "docs/V05C-interrupt-reentry.csv"
    summary_path = ROOT / "docs/V05C-flow-summary.json"
    v06_path = ROOT / "docs/V06C-executable-memory-summary.json"
    contexts = read_csv(contexts_path)
    edges = read_csv(edges_path)
    proofs = read_csv(proofs_path)
    interrupt_reentries = read_csv(interrupt_reentry_path)
    by_key = {row["Context"]: row for row in contexts}
    if json.loads(summary_path.read_text(encoding="utf-8"))["status"] != "FLOW_CLOSED_NOT_PRODUCTION_ADMITTED":
        raise ValueError("07C requires closed 05C flow")
    if json.loads(v06_path.read_text(encoding="utf-8"))["status"] != "COMPLETE_ZERO_EXECUTABLE_RAM_EPOCHS":
        raise ValueError("07C requires closed 06C executable-memory ownership")
    args.out.mkdir(parents=True, exist_ok=True)
    combined_contexts: dict[str, dict[str, str]] = {}
    memberships: dict[str, list[str]] = defaultdict(list)
    combined_edges: dict[tuple[str, str, str], dict[str, str]] = {}
    family_summaries = []

    for spec in plan["families"]:
        family_id = spec["family_id"]
        root = spec["root_context"]
        family = derive_procedure_family(contexts, edges, proofs, root)
        if len(family.contexts) != spec["expected_context_count"]:
            raise ValueError(f"{family_id} context count changed")
        if len(family.call_sites) != spec["expected_nested_call_count"]:
            raise ValueError(f"{family_id} nested-call count changed")
        actual_calls = [
            {"call_source": source, "call_target": target}
            for source, target in family.call_sites
        ]
        if "expected_call_sites" in spec and actual_calls != spec["expected_call_sites"]:
            raise ValueError(f"{family_id} nested-call family changed: {actual_calls}")
        if ("expected_call_sites_sha256" in spec and
                canonical_sha(actual_calls) != spec["expected_call_sites_sha256"]):
            raise ValueError(f"{family_id} hashed nested-call family changed")
        actual_returns = [
            {"return_source": source, "return_target": target, "call_source": call}
            for source, target, call in family.return_relations
        ]
        if "expected_returns" in spec:
            if actual_returns != spec["expected_returns"]:
                raise ValueError(f"{family_id} return relation changed: {actual_returns}")
        elif (len(actual_returns) != spec["expected_return_count"] or
              canonical_sha(actual_returns) != spec["expected_returns_sha256"]):
            raise ValueError(f"{family_id} hashed return relation changed")
        parents = sorted(
            ({"call_source": row["Producer"], "proof_id": row["Proof_Id"]}
             for row in proofs if row["Class"] == "DIRECT_CALL" and row["Target"] == root),
            key=lambda row: (row["call_source"], row["proof_id"]),
        )
        if "parent_call_source" in spec:
            expected_parents = [row for row in parents
                                if row["call_source"] == spec["parent_call_source"]]
            if len(expected_parents) != 1:
                raise ValueError(f"{family_id} parent call proof changed")
            admitted_parents = expected_parents
        else:
            if (len(parents) != spec["expected_parent_call_count"] or
                    canonical_sha(parents) != spec["expected_parent_calls_sha256"]):
                raise ValueError(f"{family_id} hashed parent call family changed")
            admitted_parents = parents
        selected = [by_key[key] for key in family.contexts]
        context_rows = []
        for row in selected:
            output = {
                "Family": family_id, "Context": row["Context"],
                "ROM_Offset": row["ROM_Offset"], "Bytes": row["Bytes"],
                "Mnemonic": row["Mnemonic"], "Mode": row["Mode"],
                "Carry_In_Facts": row["Carry_In_Facts"],
                "Zero_In_Facts": row["Zero_In_Facts"],
                "Access_Expression": access_expression(row),
                "Proof_Source": "V05C-contexts.csv",
                "Admission_State": "SOURCE_PROVED_NOT_YET_ADMITTED",
            }
            context_rows.append(output)
            if row["Context"] in combined_contexts:
                comparable = {key: output[key] for key in ("Context", "ROM_Offset", "Bytes", "Mnemonic", "Mode", "Carry_In_Facts", "Zero_In_Facts", "Access_Expression")}
                existing = {key: combined_contexts[row["Context"]][key] for key in comparable}
                if comparable != existing:
                    raise ValueError(f"incompatible overlapping family context: {row['Context']}")
            else:
                combined_contexts[row["Context"]] = output
            memberships[row["Context"]].append(family_id)
        family_edge_rows = [
            {"Family": family_id, "Source": source, "Kind": kind, "Target": target,
             "Proof_Source": "V05C-edges.csv"}
            for source, kind, target in family.internal_edges
        ]
        family_edge_rows += [
            {"Family": family_id, "Source": source, "Kind": "DIRECT_CALL", "Target": target,
             "Proof_Source": "V05C-dynamic-proofs.csv"}
            for source, target in family.call_sites
        ]
        runtime_returns = sorted(
            {(row["Source"], row["Target"]) for row in edges
             if row["Source"] in family.contexts and row["Kind"] == "RETURN_PROVED"}
        )
        family_edge_rows += [
            {"Family": family_id, "Source": source, "Kind": "RETURN_PROVED", "Target": target,
             "Proof_Source": "V05C-edges.csv"}
            for source, target in runtime_returns
        ]
        family_edge_rows.sort(key=lambda row: (row["Source"], row["Kind"], row["Target"]))
        for row in family_edge_rows:
            combined_edges[(row["Source"], row["Kind"], row["Target"])] = row
        number = family_id[-3:]
        contexts_out = args.out / f"V07C-family-{number}-contexts.csv"
        edges_out = args.out / f"V07C-family-{number}-edges.csv"
        write_csv(contexts_out, tuple(context_rows[0]), context_rows)
        write_csv(edges_out, tuple(family_edge_rows[0]), family_edge_rows)
        forms = Counter(f'{row["Mnemonic"]}:{row["Mode"]}' for row in selected)
        default_kind = ("SHARED_LEAF_PROCEDURE" if len(admitted_parents) > 1 else
                        "LEAF_PROCEDURE_REACHED_FROM_RESET_BOOTSTRAP")
        entry_kind = spec.get("entry_kind", default_kind)
        if "entry_kind" in spec:
            if entry_kind not in ("EMULATION_RESET_VECTOR", "NATIVE_NMI_VECTOR"):
                raise ValueError(f"{family_id} has an unsupported explicit entry kind")
            if admitted_parents:
                raise ValueError(f"{family_id} vector entry unexpectedly has a direct-call parent")
        understanding = {
            "schema": "theme-park-v07c-family-understanding-v1",
            "family_id": family_id,
            "status": "UNDERSTOOD_SOURCE_PROVED_NOT_YET_ADMITTED",
            "kind": entry_kind,
            "root_context": root,
            "parent_calls": admitted_parents,
            "context_count": len(selected),
            "internal_edge_count": len(family.internal_edges),
            "nested_call_count": len(family.call_sites),
            "nested_calls": actual_calls,
            "return_relations": actual_returns,
            "runtime_return_edge_count": len(runtime_returns),
            "runtime_return_edges_sha256": canonical_sha(runtime_returns),
            "instruction_form_counts": dict(sorted(forms.items())),
            "mode_set": sorted({":".join(key.rsplit(":", 3)[-3:]) for key in family.contexts}),
            "dbr_proof": "V05C closed DBR=0 theorem; absolute accesses fail closed if DBR differs",
            "executable_memory_epoch": "IMMUTABLE_CANONICAL_LOROM; V06C proves zero RAM epochs",
            "runtime_decoder_required": False,
            "trace_or_oracle_inputs": [],
            "dependencies": {
                "family_plan_sha256": sha(args.plan),
                "v05_contexts_sha256": sha(contexts_path),
                "v05_edges_sha256": sha(edges_path),
                "v05_dynamic_proofs_sha256": sha(proofs_path),
                "v05_summary_sha256": sha(summary_path),
                "v06_summary_sha256": sha(v06_path),
            },
            "products": {"contexts_sha256": sha(contexts_out), "edges_sha256": sha(edges_out)},
        }
        understanding_out = args.out / f"V07C-family-{number}-understanding.json"
        understanding_out.write_text(json.dumps(understanding, indent=2, sort_keys=True) + "\n",
                                     encoding="utf-8", newline="\n")
        family_summaries.append({
            "family_id": family_id, "root_context": root,
            "context_count": len(selected), "form_count": len(forms),
            "contexts_sha256": sha(contexts_out), "edges_sha256": sha(edges_out),
            "understanding_sha256": sha(understanding_out),
        })

    # RTI is not an ordinary call/return edge.  Preserve the exact finite NMI
    # resume domain proved by 05C as one union-level relation set rather than
    # copying all 70,076 relations into each of the four NMI family files.
    selected_keys = set(combined_contexts)
    admitted_reentries = []
    for row in interrupt_reentries:
        if (row["Interrupt"] != "NMI" or
                row["Handler_Entry"] != "00:8216" or
                row["RTI_Context"] != "00:83A3:0:0:0" or
                row["Status"] != "CLOSED_SOURCE_PROVED"):
            raise ValueError(f"unexpected 05C interrupt-reentry row: {row}")
        if row["RTI_Context"] not in selected_keys or row["Resume_Context"] not in selected_keys:
            raise ValueError(f"interrupt reentry leaves selected 07C union: {row}")
        edge = {
            "Family": "V05C_NMI_REENTRY_DOMAIN",
            "Source": row["RTI_Context"],
            "Kind": "INTERRUPT_REENTRY_PROVED",
            "Target": row["Resume_Context"],
            "Proof_Source": "V05C-interrupt-reentry.csv",
        }
        combined_edges[(edge["Source"], edge["Kind"], edge["Target"])] = edge
        admitted_reentries.append((edge["Source"], edge["Target"]))
    if len(admitted_reentries) != 70076 or len(set(admitted_reentries)) != 70076:
        raise ValueError("05C NMI interrupt-reentry domain changed")

    union_rows = []
    for key in sorted(combined_contexts, key=compact_key):
        row = combined_contexts[key]
        union_rows.append({
            "Families": ";".join(sorted(memberships[key])),
            "Context": key, "ROM_Offset": row["ROM_Offset"], "Bytes": row["Bytes"],
            "Mnemonic": row["Mnemonic"], "Mode": row["Mode"],
            "Carry_In_Facts": row["Carry_In_Facts"],
            "Zero_In_Facts": row["Zero_In_Facts"],
            "Access_Expression": row["Access_Expression"],
            "Proof_Source": row["Proof_Source"],
        })
    union_edges = [
        {"Source": source, "Kind": kind, "Target": target,
         "Proof_Source": combined_edges[(source, kind, target)]["Proof_Source"]}
        for source, kind, target in sorted(combined_edges)
    ]
    union_context_path = args.out / "V07C-selected-contexts.csv"
    union_edge_path = args.out / "V07C-selected-edges.csv"
    write_csv(union_context_path, tuple(union_rows[0]), union_rows)
    write_csv(union_edge_path, tuple(union_edges[0]), union_edges)
    selection = {
        "schema": "theme-park-v07c-selected-families-v1",
        "status": "SOURCE_FAMILIES_UNDERSTOOD_NOT_YET_ADMITTED",
        "compile_policy": plan["compile_policy"],
        "family_count": len(family_summaries),
        "unique_context_count": len(union_rows),
        "interrupt_reentry_count": len(admitted_reentries),
        "interrupt_reentry_sha256": canonical_sha(sorted(admitted_reentries)),
        "families": family_summaries,
        "products": {
            "selected_contexts_sha256": sha(union_context_path),
            "selected_edges_sha256": sha(union_edge_path),
            "v05_interrupt_reentry_sha256": sha(interrupt_reentry_path),
        },
    }
    (args.out / "V07C-selected-families.json").write_text(
        json.dumps(selection, indent=2, sort_keys=True) + "\n",
        encoding="utf-8", newline="\n")
    print(json.dumps({
        "families": len(family_summaries), "unique_contexts": len(union_rows),
        "status": selection["status"],
    }, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
