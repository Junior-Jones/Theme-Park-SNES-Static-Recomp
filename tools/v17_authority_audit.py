#!/usr/bin/env python3
"""Hash and audit the complete currently selected Theme Park static source graph."""
from __future__ import annotations

import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / "docs/V17C-production-authority-audit.json"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main() -> int:
    generated_list = ROOT / "static-core/generated/scpu/tp_v07_sources.txt"
    generated = [ROOT / line for line in generated_list.read_text(encoding="utf-8").splitlines()]
    extra_names = (
        "runtime/src/theme_park_bus.c", "runtime/src/theme_park_scheduler.c",
        "runtime/src/theme_park_dma.c", "runtime/src/theme_park_ppu.c",
        "runtime/src/theme_park_renderer.c", "runtime/src/theme_park_apu.c",
        "runtime/src/theme_park_spc700.c", "runtime/generated/theme_park_spc700_aot.c",
        "runtime/src/theme_park_input.c", "runtime/src/theme_park_sdsp.c",
        "runtime/src/theme_park_machine.c",
        "static-core/generated/timing/theme_park_v09_timing.c",
    )
    sources = generated + [ROOT / name for name in extra_names]
    if len(generated) != 672 or len(sources) != 684 or len(set(sources)) != 684:
        raise AssertionError("current selected source inventory changed")
    missing = [str(path.relative_to(ROOT)) for path in sources if not path.is_file()]
    if missing:
        raise AssertionError(f"selected sources missing: {missing[:5]}")

    foreign_terms = ("rock n roll", "top gear", "simcity", "civilization",
                     "jungle strike", "gundam", "snes9x", "mesen", "bsnes",
                     "snes_spc", "spc_dsp")
    foreign_hits: list[dict[str, object]] = []
    decoder_hits: list[dict[str, object]] = []
    negative_decoder_comments: list[dict[str, object]] = []
    for path in sources:
        text = path.read_text(encoding="utf-8")
        lowered = text.lower()
        for term in foreign_terms:
            if term in lowered:
                foreign_hits.append({"path": str(path.relative_to(ROOT)).replace("\\", "/"),
                                     "term": term})
        for line_number, line in enumerate(text.splitlines(), 1):
            low = line.lower()
            if "runtime decoder" in low and ("no runtime decoder" in low or
                                                "not a runtime instruction decoder" in low):
                negative_decoder_comments.append({
                    "path": str(path.relative_to(ROOT)).replace("\\", "/"),
                    "line": line_number,
                })
                continue
            if (re.search(r"decode_opcode|opcode_table|switch\s*\(\s*opcode", low) or
                    re.search(r"fallback|learn(?:ed|ing)?\s+(?:context|target|edge)", low)):
                decoder_hits.append({
                    "path": str(path.relative_to(ROOT)).replace("\\", "/"),
                    "line": line_number,
                    "text": line.strip(),
                })

    # One opcode switch is deliberately the static timing-plan branch predicate;
    # it cannot fetch/decode/dispatch an instruction and is reviewed by exact text.
    permitted_timing = [{
        "path": "runtime/src/theme_park_bus.c",
        "line": 522,
        "text": "switch (opcode) {",
    }]
    if decoder_hits != permitted_timing:
        raise AssertionError(f"unexpected decoder/fallback-shaped source: {decoder_hits[:5]}")
    if foreign_hits:
        raise AssertionError(f"foreign project/emulator term in selected source: {foreign_hits[:5]}")

    selection = json.loads((ROOT / "config/production-selection.json").read_text(encoding="utf-8"))
    symbol_audit = json.loads((ROOT / "docs/V16C-static-symbol-audit.json").read_text(encoding="utf-8"))
    if (selection["runtime_decoder_allowed"] or
            selection["spc700_runtime_decoder_selected"] or
            selection["spc700_runtime_fallback_selected"] or
            selection["sdsp_third_party_driver_selected"] or
            selection["frontend_selected"]):
        raise AssertionError("forbidden production selector is enabled")
    if symbol_audit["status"] != "PASS_PROJECT_SDSP_PRESENT_NO_THIRD_PARTY_APU_OR_DSP_OWNER":
        raise AssertionError("archive symbol/member audit is not current")
    executables = [path.relative_to(ROOT).as_posix() for path in ROOT.rglob("*.exe")]
    if executables != ["build/v17c-natural/theme_park_v17c_natural_runner.exe"]:
        raise AssertionError("missing or unexpected executable product")

    inventory = [{
        "path": str(path.relative_to(ROOT)).replace("\\", "/"),
        "bytes": path.stat().st_size,
        "sha256": sha(path),
    } for path in sources]
    aggregate = hashlib.sha256()
    for entry in inventory:
        aggregate.update(entry["path"].encode("utf-8"))
        aggregate.update(b"\0")
        aggregate.update(entry["sha256"].encode("ascii"))
        aggregate.update(b"\n")

    payload = {
        "schema": "theme-park-v17c-production-authority-audit-v1",
        "status": "PASS_ONE_CURRENT_STATIC_SOURCE_GRAPH_NO_FOREIGN_OWNER_OR_FALLBACK",
        "selected_sources": len(sources),
        "generated_scpu_sources": len(generated),
        "current_machine_sources": len(extra_names),
        "unique_sources": len(set(sources)),
        "missing_sources": missing,
        "foreign_project_or_emulator_hits": foreign_hits,
        "runtime_decoder_or_fallback_hits": [],
        "reviewed_static_timing_opcode_predicate": permitted_timing,
        "negative_decoder_comment_markers": negative_decoder_comments,
        "frontend_selected": selection["frontend_selected"],
        "natural_validation_executables_present": executables,
        "archive_symbol_audit_sha256": sha(ROOT / "docs/V16C-static-symbol-audit.json"),
        "source_list_sha256": sha(generated_list),
        "source_inventory_aggregate_sha256": aggregate.hexdigest(),
        "sources": inventory,
    }
    OUTPUT.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n",
                      encoding="utf-8", newline="\n")
    print(json.dumps({"status": payload["status"],
                      "selected_sources": len(sources)}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
