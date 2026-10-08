#!/usr/bin/env python3
"""Prove whether Theme Park's exact generated S-CPU authority can be pruned."""
from __future__ import annotations

import csv
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main() -> int:
    manifest = ROOT / "docs/V07C-production-manifest.csv"
    with manifest.open(encoding="utf-8", newline="") as stream:
        rows = list(csv.DictReader(stream))
    contexts = [row["Context"] for row in rows]
    if len(contexts) != 71986 or len(set(contexts)) != 71986:
        raise AssertionError("canonical production contexts are not a unique 71,986-row set")

    shards = sorted((ROOT / "static-core/generated/scpu").glob("tp_v07_shard_*.c"))
    cases: list[int] = []
    source_bytes = 0
    for path in shards:
        text = path.read_text(encoding="utf-8")
        source_bytes += path.stat().st_size
        cases.extend(int(value, 16) for value in
                     re.findall(r"^        case 0x([0-9A-Fa-f]{8})u: \{", text, re.MULTILINE))
    if len(cases) != 71986 or len(set(cases)) != 71986:
        raise AssertionError("generated case membership is not exactly unique")
    if set(cases) != {int(row["Compact_Key"], 16) for row in rows}:
        raise AssertionError("generated context keys differ from production manifest")

    sources = ROOT / "static-core/generated/scpu/tp_v07_sources.txt"
    generated_hashes = {
        path.relative_to(ROOT).as_posix(): sha(path)
        for path in [sources, ROOT / "static-core/generated/scpu/tp_v07_dispatch.c",
                     ROOT / "static-core/generated/scpu/tp_v18_compact.h", *shards]
    }
    payload = {
        "schema": "theme-park-v18c-compaction-audit-v1",
        "status": "PASS_UNIQUE_CONTEXT_MEMBERSHIP_PRUNING_AUDIT_ONLY",
        "canonical_contexts": len(contexts),
        "unique_canonical_contexts": len(set(contexts)),
        "generated_case_labels": len(cases),
        "unique_generated_case_labels": len(set(cases)),
        "shadowed_contexts": 0,
        "structural_only_contexts_selected": 0,
        "unreachable_contexts_selected": 0,
        "duplicate_context_representations": 0,
        "contexts_removed": 0,
        "source_bytes_before": source_bytes,
        "source_bytes_after": source_bytes,
        "reason": "Unique exact PBR:PC:E:M:X case membership is established. This check does not prove reachability or absence of representation factoring. See V18C-representation-compaction.json and V18C-compiler-token-equivalence.json for the separate compile-time transformation.",
        "unknown_context_policy": "UNCHANGED_FAIL_CLOSED",
        "runtime_decoder_or_fallback_added": False,
        "production_manifest_sha256": sha(manifest),
        "generated_sources_sha256": generated_hashes,
    }
    out = ROOT / "docs/V18C-compaction-audit.json"
    out.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n",
                   encoding="utf-8", newline="\n")
    print(payload["status"])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
