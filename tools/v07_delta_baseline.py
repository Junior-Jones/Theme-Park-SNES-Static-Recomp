#!/usr/bin/env python3
"""Freeze or compare a verified 07C source baseline without recompiling it.

The expensive cold verifier remains the final whole-core authority.  This tool
supports the bounded family loop between cold gates: it proves that every
previously verified exact-context body and hardware event is unchanged, while
identifying the newly admitted delta for targeted semantic verification.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import re
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
GENERATED = ROOT / "static-core/generated/scpu"
DEFAULT_RECEIPT = ROOT / "docs/V07C-delta-baseline.json"
DEFAULT_BODIES = ROOT / "docs/V07C-delta-baseline-bodies.csv"
DEFAULT_EVENTS = ROOT / "docs/V07C-delta-baseline-hardware-events.csv"
DEFAULT_DELTA_CONTEXTS = ROOT / "docs/V07C-latest-delta-contexts.csv"


def read_csv(path: Path) -> list[dict[str, str]]:
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def write_csv(path: Path, fields: tuple[str, ...], rows: list[dict[str, str]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)


def sha_bytes(value: bytes) -> str:
    return hashlib.sha256(value).hexdigest()


def sha(path: Path) -> str:
    return sha_bytes(path.read_bytes())


def canonical_sha(value: object) -> str:
    payload = json.dumps(value, sort_keys=True, separators=(",", ":")).encode("utf-8")
    return sha_bytes(payload)


def generated_case_bodies() -> dict[str, str]:
    """Return compact-key -> canonical top-level case body text."""
    bodies: dict[str, str] = {}
    pattern = re.compile(
        r"^        case 0x([0-9A-F]{8})u: \{\n"
        r"(.*?)"
        r"(?=^        case 0x[0-9A-F]{8}u: \{|^        default:)",
        flags=re.MULTILINE | re.DOTALL,
    )
    for path in sorted(GENERATED.glob("tp_v07_shard_*.c")):
        text = path.read_text(encoding="utf-8").replace("\r\n", "\n")
        for match in pattern.finditer(text):
            key, body = match.groups()
            if key in bodies:
                raise AssertionError(f"duplicate generated compact key: {key}")
            bodies[key] = body
    return bodies


def body_rows(production: list[dict[str, str]]) -> list[dict[str, str]]:
    bodies = generated_case_bodies()
    expected = {row["Compact_Key"] for row in production}
    if set(bodies) != expected:
        missing = sorted(expected - set(bodies))[:8]
        extra = sorted(set(bodies) - expected)[:8]
        raise AssertionError(f"generated/production case mismatch: missing={missing} extra={extra}")
    return [
        {
            "Context": row["Context"],
            "Compact_Key": row["Compact_Key"],
            "Bytes": row["Bytes"],
            "Mnemonic": row["Mnemonic"],
            "Mode": row["Mode"],
            "Shard": row["Shard"],
            "Body_SHA256": sha_bytes(bodies[row["Compact_Key"]].encode("utf-8")),
        }
        for row in production
    ]


def hardware_rows() -> list[dict[str, str]]:
    events = read_csv(ROOT / "docs/V07C-hardware-intelligence.csv")
    rows = []
    for event in events:
        stable = {key: value for key, value in event.items() if key != "Families"}
        rows.append({
            "Stable_Id": event["Stable_Id"],
            "Context": event["Context"],
            "Event_SHA256_Without_Families": canonical_sha(stable),
        })
    return rows


def freeze(args: argparse.Namespace) -> int:
    plan_path = ROOT / "config/v07-family-plan.json"
    production_path = ROOT / "docs/V07C-production-manifest.csv"
    selected_path = ROOT / "docs/V07C-selected-contexts.csv"
    generation_path = GENERATED / "V07C-generation-manifest.json"
    hardware_summary_path = ROOT / "docs/V07C-hardware-intelligence-summary.json"
    plan = json.loads(plan_path.read_text(encoding="utf-8"))
    generation = json.loads(generation_path.read_text(encoding="utf-8"))
    hardware_summary = json.loads(hardware_summary_path.read_text(encoding="utf-8"))
    production = read_csv(production_path)
    selected = read_csv(selected_path)
    family_ids = [spec["family_id"] for spec in plan["families"]]
    if not family_ids or family_ids[-1] != args.last_family:
        raise ValueError("requested baseline family is not the current plan tail")
    if generation["family_ids"] != family_ids:
        raise ValueError("generation family list differs from the current plan")
    if generation["context_count"] != len(production) or len(selected) != len(production):
        raise ValueError("baseline selected/generated/admitted counts differ")
    if {row["Context"] for row in selected} != {row["Context"] for row in production}:
        raise ValueError("baseline selected/admitted membership differs")
    if any(row["Admission_State"] != "ADMITTED_NATIVE_SOURCE_UNCOMPILED"
           for row in production):
        raise ValueError("baseline contains a non-admitted or compiled context")
    if generation["compiled_sources"]:
        raise ValueError("baseline falsely contains compiled sources")
    if hardware_summary["backfill_coverage"]["selected_context_count"] != len(production):
        raise ValueError("hardware baseline does not cover every selected context")
    bodies = body_rows(production)
    events = hardware_rows()
    write_csv(args.bodies, tuple(bodies[0]), bodies)
    write_csv(args.events, tuple(events[0]), events)
    receipt = {
        "schema": "theme-park-v07c-delta-baseline-v1",
        "status": "FROZEN_AFTER_OBSERVED_FULL_COLD_PASS",
        "last_verified_family": args.last_family,
        "family_ids": family_ids,
        "family_count": len(family_ids),
        "context_count": len(production),
        "hardware_event_count": len(events),
        "compiled_contexts": 0,
        "linked_contexts": 0,
        "body_manifest": str(args.bodies.relative_to(ROOT)).replace("\\", "/"),
        "hardware_event_manifest": str(args.events.relative_to(ROOT)).replace("\\", "/"),
        "products_sha256": {
            "body_manifest": sha(args.bodies),
            "hardware_event_manifest": sha(args.events),
        },
        "authority_sha256": {
            "family_plan": sha(plan_path),
            "selected_contexts": sha(selected_path),
            "production_manifest": sha(production_path),
            "generation_manifest": sha(generation_path),
            "hardware_summary": sha(hardware_summary_path),
            "v02_semantics": sha(ROOT / "docs/V02C-SEMANTIC-MANIFEST.json"),
            "v05_flow": sha(ROOT / "docs/V05C-flow-summary.json"),
            "v06_executable_memory": sha(ROOT / "docs/V06C-executable-memory-summary.json"),
        },
        "policy": {
            "old_context_body_change_allowed": False,
            "old_context_removal_allowed": False,
            "old_hardware_event_change_allowed": False,
            "runtime_or_oracle_authority": False,
            "partial_compilation_allowed": False,
            "final_whole_07c_cold_pass_required": True,
        },
    }
    args.receipt.write_text(json.dumps(receipt, indent=2, sort_keys=True) + "\n",
                            encoding="utf-8", newline="\n")
    print(json.dumps({
        "baseline_family": args.last_family,
        "contexts": len(production),
        "families": len(family_ids),
        "hardware_events": len(events),
        "status": receipt["status"],
    }, sort_keys=True))
    return 0


def compare(args: argparse.Namespace) -> int:
    receipt = json.loads(args.receipt.read_text(encoding="utf-8"))
    baseline_bodies = read_csv(args.bodies)
    baseline_events = read_csv(args.events)
    if sha(args.bodies) != receipt["products_sha256"]["body_manifest"]:
        raise AssertionError("baseline body manifest hash changed")
    if sha(args.events) != receipt["products_sha256"]["hardware_event_manifest"]:
        raise AssertionError("baseline hardware manifest hash changed")
    plan = json.loads((ROOT / "config/v07-family-plan.json").read_text(encoding="utf-8"))
    current_family_ids = [spec["family_id"] for spec in plan["families"]]
    baseline_family_ids = receipt["family_ids"]
    if current_family_ids[:len(baseline_family_ids)] != baseline_family_ids:
        raise AssertionError("current family plan is not an append-only extension of the baseline")
    if len(current_family_ids) <= len(baseline_family_ids):
        raise AssertionError("delta verification requires at least one new family")
    production = read_csv(ROOT / "docs/V07C-production-manifest.csv")
    selected = read_csv(ROOT / "docs/V07C-selected-contexts.csv")
    current_rows = {row["Context"]: row for row in body_rows(production)}
    old_rows = {row["Context"]: row for row in baseline_bodies}
    if not set(old_rows) <= set(current_rows):
        raise AssertionError(f"verified baseline contexts were removed: {sorted(set(old_rows) - set(current_rows))[:8]}")
    immutable = ("Compact_Key", "Bytes", "Mnemonic", "Mode", "Shard", "Body_SHA256")
    changed = [context for context, old in old_rows.items()
               if any(old[field] != current_rows[context][field] for field in immutable)]
    if changed:
        raise AssertionError(f"verified baseline context bodies changed: {changed[:8]}")
    production_keys = set(current_rows)
    selected_keys = {row["Context"] for row in selected}
    if production_keys != selected_keys:
        raise AssertionError("current selected/admitted/generated membership differs")
    new_contexts = sorted(production_keys - set(old_rows))
    delta_family_ids = current_family_ids[len(baseline_family_ids):]
    delta_family_contexts: set[str] = set()
    for family_id in delta_family_ids:
        number = family_id[-3:]
        delta_family_contexts.update(
            row["Context"] for row in read_csv(ROOT / f"docs/V07C-family-{number}-contexts.csv"))
    if set(new_contexts) != delta_family_contexts - set(old_rows):
        raise AssertionError("new production contexts differ from the new family union")
    new_rows = [current_rows[context] for context in new_contexts]
    delta_fields = ("Context", "Compact_Key", "Bytes", "Mnemonic", "Mode",
                    "Shard", "Body_SHA256")
    write_csv(args.contexts, delta_fields, new_rows)
    current_events = {row["Stable_Id"]: row for row in hardware_rows()}
    old_events = {row["Stable_Id"]: row for row in baseline_events}
    if not set(old_events) <= set(current_events):
        raise AssertionError(f"verified hardware events were removed: {sorted(set(old_events) - set(current_events))[:8]}")
    changed_events = [stable_id for stable_id, old in old_events.items()
                      if old != current_events[stable_id]]
    if changed_events:
        raise AssertionError(f"verified hardware events changed: {changed_events[:8]}")
    result = {
        "schema": "theme-park-v07c-delta-comparison-v1",
        "status": "PASS_APPEND_ONLY_BODY_AND_HARDWARE_DELTA",
        "baseline_family": receipt["last_verified_family"],
        "delta_families": delta_family_ids,
        "baseline_contexts_unchanged": len(old_rows),
        "new_context_count": len(new_contexts),
        "new_contexts_sha256": canonical_sha(new_contexts),
        "new_context_manifest": str(args.contexts.relative_to(ROOT)).replace("\\", "/"),
        "new_context_manifest_sha256": sha(args.contexts),
        "baseline_hardware_events_unchanged": len(old_events),
        "new_hardware_event_count": len(current_events) - len(old_events),
        "semantic_verification_scope": "NEW_CONTEXTS_PLUS_EXPLICIT_IMPACT_FORMS",
        "final_whole_07c_cold_pass_required": True,
        "compilation_performed": False,
    }
    args.output.write_text(json.dumps(result, indent=2, sort_keys=True) + "\n",
                           encoding="utf-8", newline="\n")
    print(json.dumps(result, sort_keys=True))
    return 0


def main() -> int:
    parser = argparse.ArgumentParser()
    subparsers = parser.add_subparsers(dest="command", required=True)
    freeze_parser = subparsers.add_parser("freeze")
    freeze_parser.add_argument("--last-family", required=True)
    compare_parser = subparsers.add_parser("compare")
    for item in (freeze_parser, compare_parser):
        item.add_argument("--receipt", type=Path, default=DEFAULT_RECEIPT)
        item.add_argument("--bodies", type=Path, default=DEFAULT_BODIES)
        item.add_argument("--events", type=Path, default=DEFAULT_EVENTS)
    compare_parser.add_argument(
        "--output", type=Path,
        default=ROOT / "docs/V07C-latest-delta-comparison.json")
    compare_parser.add_argument("--contexts", type=Path, default=DEFAULT_DELTA_CONTEXTS)
    args = parser.parse_args()
    return freeze(args) if args.command == "freeze" else compare(args)


if __name__ == "__main__":
    raise SystemExit(main())
