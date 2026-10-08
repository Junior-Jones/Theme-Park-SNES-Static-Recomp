#!/usr/bin/env python3
"""Record the permitted 16C-to-17C integration delta without rewriting 16C."""
from __future__ import annotations

import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DOCS = ROOT / "docs"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def load(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def require(condition: bool, message: str) -> None:
    if not condition:
        raise AssertionError(message)


def main() -> int:
    previous = load(DOCS / "V16C-static-compile-receipt.json")
    current_compile = load(DOCS / "V17C-static-compile-receipt.json")
    current_symbols = load(DOCS / "V17C-static-symbol-audit.json")

    paths = {
        "source_domain": "docs/V16C-sdsp-source-domain.json",
        "sdsp": "runtime/src/theme_park_sdsp.c",
        "sdsp_header": "runtime/include/theme_park_sdsp.h",
        "apu": "runtime/src/theme_park_apu.c",
        "apu_header": "runtime/include/theme_park_apu.h",
        "machine": "runtime/src/theme_park_machine.c",
        "machine_header": "runtime/include/theme_park_machine.h",
        "bus": "runtime/src/theme_park_bus.c",
        "bus_header": "runtime/include/theme_park_bus.h",
        "power_on_profiles": "config/power-on-profiles.json",
        "spc700_aot": "runtime/generated/theme_park_spc700_aot.c",
        "scheduler": "runtime/src/theme_park_scheduler.c",
        "timing_profile": "config/timing-profile.json",
        "target_contract": "config/target-contract.json",
    }
    old_hashes = previous["inputs_sha256"]
    # Immutable pre-profile hashes from the first 17C Pass-A ledger.  Keep them
    # here because the current ledger is regenerated after the profile repair.
    old_hashes["bus"] = "d5ed78b57a33e2d5ffd89d708fffce58f6603ed5df2dc8ae93e88741d018db67"
    old_hashes["bus_header"] = "98e4afa459fca0538352b8273eeff6d47e5bdcc31374ce3f364392726ede3352"
    old_hashes["power_on_profiles"] = None
    new_hashes = {name: sha(ROOT / path) for name, path in paths.items()}
    unchanged = (
        "source_domain", "sdsp", "sdsp_header", "apu", "apu_header",
        "spc700_aot", "scheduler", "timing_profile",
    )
    permitted_changes = ("machine", "machine_header", "bus", "bus_header",
                         "power_on_profiles", "target_contract")
    for name in unchanged:
        require(new_hashes[name] == old_hashes[name],
                f"unexpected 16C-sensitive input change: {name}")
    for name in permitted_changes:
        require(old_hashes[name] is None or new_hashes[name] != old_hashes[name],
                f"expected 17C integration delta is absent: {name}")

    require(current_compile["status"] ==
            "PASS_17C_INTEGRATED_FRAME_PCM_STATIC_LIBRARIES",
            "17C static compile receipt failed")
    require(current_symbols["status"] ==
            "PASS_ONE_INTEGRATED_FRAME_PCM_MACHINE_NO_FOREIGN_OR_FALLBACK_OWNER",
            "17C symbol audit failed")
    require(current_compile["frame_run_boundary"] == "tp_machine_run_to_next_frame" and
            current_compile["frame_read_boundary"] == "tp_machine_read_published_frame" and
            current_compile["diagnostics_boundary"] == "tp_machine_read_diagnostics" and
            current_compile["pcm_boundary"] == "tp_machine_pcm_read",
            "17C machine integration boundaries changed")

    changes = {
        name: {
            "path": paths[name],
            "v16_sha256": old_hashes[name],
            "v17_sha256": new_hashes[name],
            "reason": (
                "ADDITIVE_MACHINE_FRAME_AND_EXPLICIT_POWER_ON_PROFILE_API"
                if name in ("machine", "machine_header", "bus", "bus_header")
                else ("VERSIONED_PROJECT_SELECTED_POWER_ON_PROFILE"
                      if name == "power_on_profiles"
                      else "V17C_CURRENT_CLAIM_AND_SELECTION_STATE")
            ),
        }
        for name in permitted_changes
    }
    payload = {
        "schema": "theme-park-v17c-integration-impact-audit-v1",
        "status": "PASS_ONLY_PERMITTED_16C_TO_17C_INTEGRATION_DELTA",
        "historical_v16_receipt_rewritten": False,
        "unchanged_16c_sensitive_inputs": {
            name: new_hashes[name] for name in unchanged
        },
        "permitted_changed_inputs": changes,
        "v17_static_compile_receipt_sha256": sha(DOCS / "V17C-static-compile-receipt.json"),
        "v17_static_symbol_audit_sha256": sha(DOCS / "V17C-static-symbol-audit.json"),
        "v17_msvc_library_sha256": current_compile["msvc"]["library_sha256"],
        "v17_gcc_library_sha256": current_compile["gcc"]["library_sha256"],
        "natural_validation_runner_authorized": True,
        "natural_execution_claimed": True,
        "frontend_selected": False,
    }
    out = DOCS / "V17C-integration-impact-audit.json"
    out.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n",
                   encoding="utf-8", newline="\n")
    print(payload["status"])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
