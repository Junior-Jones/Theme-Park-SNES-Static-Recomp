#!/usr/bin/env python3
"""Build Theme Park 17C's newest-evidence Pass-A global ledger.

Natural runs are integration evidence only and never become source authority.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DOCS = ROOT / "docs"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def load_json(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def read_csv(path: Path) -> list[dict[str, str]]:
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream))


def write_json(path: Path, payload: object) -> None:
    path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n",
                    encoding="utf-8", newline="\n")


def row(owner: str, obligation: str, classification: str, blocking: bool,
        evidence: str, detail: str) -> dict[str, object]:
    return {
        "owner": owner,
        "obligation": obligation,
        "classification": classification,
        "blocking": blocking,
        "evidence": evidence,
        "detail": detail,
    }


def require(condition: bool, message: str) -> None:
    if not condition:
        raise AssertionError(message)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path)
    parser.add_argument("--cold-dir", type=Path, required=True)
    args = parser.parse_args()

    require(args.rom.is_file(), "canonical ROM is missing")
    require(sha(args.rom) ==
            "c0a7e27131a7d8c9ef52a5227329e6de5846c045a9da1f3f84845e3be8e4efba",
            "canonical ROM identity changed")
    require(args.cold_dir.is_dir(), "fresh Pass-A output directory is missing")
    executables = [path.relative_to(ROOT).as_posix() for path in ROOT.rglob("*.exe")]
    require(executables == ["build/v17c-natural/theme_park_v17c_natural_runner.exe"],
            "missing or unexpected executable product")

    cold_names = (
        "V01C-byte-census.csv", "V01C-cartridge-profile.json",
        "V03C-byte-classification.csv", "V03C-lexical-summary.json",
        "V03C-lexical-validity-ranges.csv", "V03C-region-signals.json",
        "V03C-root-candidates.csv", "V03C-subsystem-interest.json",
        "V04C-byte-conflicts.csv", "V04C-context-intelligence.csv",
        "V04C-context-summary.json", "V04C-contexts.csv",
        "V04C-direct-edges.csv", "V04C-frontiers.csv",
        "V05C-byte-conflicts.csv", "V05C-contexts.csv",
        "V05C-dynamic-proofs.csv", "V05C-edges.csv",
        "V05C-flow-summary.json", "V05C-frontiers.csv",
        "V05C-interrupt-reentry.csv", "V05C-nmi-phase-writes.csv",
    )
    cold_hashes: dict[str, str] = {}
    for name in cold_names:
        fresh = args.cold_dir / name
        sealed = DOCS / name
        require(fresh.is_file() and sealed.is_file(), f"missing cold/sealed product: {name}")
        fresh_hash = sha(fresh)
        require(fresh_hash == sha(sealed), f"cold regeneration differs: {name}")
        cold_hashes[name] = fresh_hash

    fresh_flow = load_json(args.cold_dir / "V05C-flow-summary.json")
    require(fresh_flow["status"] == "FLOW_CLOSED_NOT_PRODUCTION_ADMITTED",
            "fresh exact-flow universe is not closed")
    require(fresh_flow["exact_contexts"] == 71986 and
            fresh_flow["frontiers"] == 0 and
            fresh_flow["byte_conflict_rows"] == 0,
            "fresh exact-flow universe changed")

    fresh_contexts = read_csv(args.cold_dir / "V05C-contexts.csv")
    production = read_csv(DOCS / "V07C-production-manifest.csv")
    fresh_keys = {entry["Context"] for entry in fresh_contexts}
    production_keys = {entry["Context"] for entry in production}
    require(len(fresh_contexts) == len(fresh_keys) == 71986,
            "fresh exact-context set contains duplicates or changed size")
    require(len(production) == len(production_keys) == 71986,
            "production context set contains duplicates or changed size")
    require(fresh_keys == production_keys,
            "fresh exact contexts and production contexts differ")

    mnemonic_counts: dict[str, int] = {}
    for entry in production:
        mnemonic_counts[entry["Mnemonic"]] = mnemonic_counts.get(entry["Mnemonic"], 0) + 1
    require(mnemonic_counts.get("SED", 0) == 0,
            "decimal-set instruction entered the admitted universe")
    require(fresh_flow["interrupt_disable_invariant"]["proved"] is True and
            fresh_flow["dbr_zero_theorem"]["proved"] is True and
            fresh_flow["nmi_phase"]["reentry_gate"] is True,
            "fresh interrupt/return invariants changed")

    expected = {
        "V02C-SEMANTIC-MANIFEST.json": ("status", "OFFLINE_SEMANTIC_FOUNDATION"),
        "V06C-executable-memory-summary.json": ("status", "COMPLETE_ZERO_EXECUTABLE_RAM_EPOCHS"),
        "V07C-lowering-summary.json": ("status", "COMPLETE_71986_SOURCE_CONTEXTS_STATIC_LIBRARIES_NO_EXECUTABLE"),
        "V08C-bus-map-summary.json": ("status", "PASS_EXHAUSTIVE_SOURCE_CONTRACT_RECONCILED"),
        "V09C-verification-summary.json": ("result", "PASS_STATIC_EVENT_ORDER_AND_PAL_PROFILE_GATE"),
        "V10C-verification-summary.json": ("status", "PASS_V10C_GENERAL_DMA_HDMA_AND_ALL_EXACT_SOURCE_CONFIGURATIONS"),
        "V11C-verification-summary.json": ("status", "PASS_V11C_PPU_STATE_SOURCE_DMA_JOIN_STATIC_LIBRARIES_NO_EXECUTABLE"),
        "V12C-verification-summary.json": ("status", "PASS_V12C_APUIO_IPL_TIMERS_ARAM_EPOCH_STATIC_LIBRARIES_NO_EXECUTABLE"),
        "V13C-verification-summary.json": ("status", "PASS_V13C_STATIC_SSMP_EXACT_PC_EXECUTABLE_ARAM_NO_INTERPRETER_NO_EXECUTABLE"),
        "V14C-verification-summary.json": ("status", "PASS_V14C_THEME_PARK_MODES_2_3_RASTER_PUBLICATION_STATIC_LIBRARIES_NO_EXECUTABLE"),
        "V15C-verification-summary.json": ("status", "PASS_V15C_THEME_PARK_INPUT_AUTOJOY_RESET_ZERO_SRAM_STATIC_LIBRARIES_NO_EXECUTABLE"),
        "V16C-verification-summary.json": ("status", "PASS_V16C_THEME_PARK_PROJECT_SDSP_32_PHASE_KNOWN_PCM_STATIC_LIBRARIES_NO_EXECUTABLE"),
    }
    evidence_hashes: dict[str, str] = {}
    for name, (field, wanted) in expected.items():
        path = DOCS / name
        payload = load_json(path)
        require(payload.get(field) == wanted, f"current owner receipt failed: {name}")
        evidence_hashes[name] = sha(path)

    selection = load_json(ROOT / "config/production-selection.json")
    require(selection["admitted_contexts"] == selection["generated_contexts"] == 71986,
            "production S-CPU membership changed")
    require(selection["runtime_decoder_allowed"] is False and
            selection["spc700_runtime_decoder_selected"] is False and
            selection["spc700_runtime_fallback_selected"] is False and
            selection["sdsp_third_party_driver_selected"] is False and
            selection["frontend_selected"] is False,
            "forbidden or premature production owner is selected")

    compile_receipt = load_json(DOCS / "V17C-static-compile-receipt.json")
    symbol_receipt = load_json(DOCS / "V17C-static-symbol-audit.json")
    authority_audit = load_json(DOCS / "V17C-production-authority-audit.json")
    impact_audit = load_json(DOCS / "V17C-integration-impact-audit.json")
    require(compile_receipt["status"] ==
            "PASS_17C_INTEGRATED_FRAME_PCM_STATIC_LIBRARIES",
            "current complete static-library receipt failed")
    require(symbol_receipt["status"] ==
            "PASS_ONE_INTEGRATED_FRAME_PCM_MACHINE_NO_FOREIGN_OR_FALLBACK_OWNER",
            "current archive authority audit failed")
    require(authority_audit["status"] ==
            "PASS_ONE_CURRENT_STATIC_SOURCE_GRAPH_NO_FOREIGN_OWNER_OR_FALLBACK" and
            authority_audit["selected_sources"] == 684,
            "current production source-graph audit failed")
    require(impact_audit["status"] ==
            "PASS_ONLY_PERMITTED_16C_TO_17C_INTEGRATION_DELTA" and
            impact_audit["historical_v16_receipt_rewritten"] is False and
            impact_audit["natural_validation_runner_authorized"] is True,
            "16C-to-17C integration impact audit failed")
    natural = load_json(DOCS / "V17C-natural-ladder-summary.json")
    require(natural["status"] ==
            "PASS_COLD_CORE_NATURAL_LADDER_DETERMINISTIC_ZERO_WRAM_V1" and
            natural["frontend_used"] is False and natural["oracle_used"] is False,
            "17C cold natural ladder is not closed")
    for compiler in ("msvc", "gcc"):
        library = ROOT / compile_receipt[compiler]["library"]
        require(library.is_file(), f"current {compiler} static library is missing")
        require(sha(library) == compile_receipt[compiler]["library_sha256"],
                f"current {compiler} static library hash changed")

    owners = {
        "BUS": ["runtime/include/theme_park_bus.h", "runtime/src/theme_park_bus.c"],
        "SCHEDULER": ["runtime/include/theme_park_scheduler.h", "runtime/src/theme_park_scheduler.c"],
        "DMA_HDMA": ["runtime/include/theme_park_dma.h", "runtime/src/theme_park_dma.c"],
        "PPU_RENDERER": ["runtime/include/theme_park_ppu.h", "runtime/src/theme_park_ppu.c", "runtime/src/theme_park_renderer.c"],
        "INPUT": ["runtime/include/theme_park_input.h", "runtime/src/theme_park_input.c"],
        "SSMP": ["runtime/include/theme_park_spc700.h", "runtime/src/theme_park_spc700.c", "runtime/generated/theme_park_spc700_aot.c"],
        "SDSP_PCM": ["runtime/include/theme_park_sdsp.h", "runtime/src/theme_park_sdsp.c"],
        "MACHINE": ["runtime/include/theme_park_machine.h", "runtime/src/theme_park_machine.c"],
    }
    owner_hashes = {
        owner: {name: sha(ROOT / name) for name in names}
        for owner, names in owners.items()
    }

    rows = [
        row("01C", "ROM identity and conservative physical-byte census", "CLOSED_SOURCE_PROVED", False,
            "cold V01C products", "Cold products are byte-identical; logical LoROM/FastROM target is fixed."),
        row("02C", "W65C816 semantic owner", "CLOSED_SOURCE_PROVED", False,
            "docs/V02C-SEMANTIC-MANIFEST.json", "Offline semantics are fixed and no production decoder is selected."),
        row("03C", "Whole-ROM lexical and byte-classification universe", "CLOSED_SOURCE_PROVED", False,
            "cold V03C products", "All physical offsets regenerate identically; lexical candidates remain non-authoritative."),
        row("04C-05C", "Exact contexts, calls, returns and NMI re-entry", "CLOSED_SOURCE_PROVED", False,
            "cold V04C/V05C products", "71,986 exact contexts, zero flow frontiers and zero byte conflicts regenerate identically."),
        row("06C", "Executable-memory epochs", "UNREACHABLE_UNDER_CERTIFIED_AUTHORITY", False,
            "docs/V06C-executable-memory-summary.json", "Every exact execution target is canonical ROM; no executable RAM epoch exists."),
        row("07C", "Static S-CPU generated authority", "CLOSED_SOURCE_PROVED", False,
            "docs/V07C-production-manifest.csv", "Fresh exact and admitted/generated memberships are equal at 71,986 contexts."),
        row("08C", "Bus, reset, memory, MMIO, persistence and power-on profiles", "CLOSED_RUNTIME_SEMANTICS", False,
            "docs/V08C-bus-map-summary.json + config/power-on-profiles.json", "All 24-bit addresses and source-reached memory effects have one current owner. Strict unknown WRAM remains the default; deterministic zero WRAM is an explicit validation-only profile."),
        row("09C", "Master scheduler and clock domains", "CLOSED_RUNTIME_SEMANTICS", False,
            "docs/V09C-verification-summary.json", "PAL master-clock event owner and residual domain joins are selected."),
        row("10C", "DMA/HDMA source-to-receiver chains", "CLOSED_RUNTIME_SEMANTICS", False,
            "docs/V10C-verification-summary.json", "General controller owns all exact source configurations."),
        row("11C", "PPU register/storage state", "CLOSED_RUNTIME_SEMANTICS", False,
            "docs/V11C-verification-summary.json", "Exact CPU/DMA/HDMA receivers join the sole PPU owner."),
        row("12C", "APUIO, IPL, timers and ARAM epoch", "CLOSED_SOURCE_PROVED", False,
            "docs/V12C-verification-summary.json", "Cartridge-authored upload and directional port ownership are closed."),
        row("13C", "Static S-SMP AOT", "CLOSED_SOURCE_PROVED", False,
            "docs/V13C-verification-summary.json", "Exact-PC generated authority has no runtime decoder or fallback."),
        row("14C", "Raster renderer and published framebuffer", "CLOSED_RUNTIME_SEMANTICS", False,
            "docs/V14C-verification-summary.json + docs/V17C-natural-ladder-summary.json", "Reached Modes 2/3 have one raster owner and completed frames pass the cold natural ladder."),
        row("15C", "Input and persistence transitions", "CLOSED_RUNTIME_SEMANTICS", False,
            "docs/V15C-verification-summary.json", "Standard-pad/manual/autojoy/reset and zero-SRAM contract are closed."),
        row("16C", "S-DSP and bounded core PCM", "CLOSED_RUNTIME_SEMANTICS", False,
            "docs/V16C-verification-summary.json + docs/V17C-natural-ladder-summary.json", "One project-owned 32-phase DSP produces known active PCM through the cold natural ladder."),
        row("01C/08C", "Physical PCB catalogue identity", "OUTSIDE_DECLARED_TARGET", False,
            "docs/V01C-cartridge-profile.json + docs/V08C-bus-map-summary.json",
            "The static-core target is the exact ROM's source-proved logical LoROM/FastROM/no-enhancement contract, not archival PCB part-number identification."),
        row("01C/03C/05C", "Historical unresolved ROM bytes", "SUPERSEDED_PROVED", False,
            "cold V03C/V05C products", "01C UNRESOLVED bytes are superseded by total conservative 03C classification and the exact 05C execution universe."),
        row("02C/05C", "Invalid packed-BCD behavior", "UNREACHABLE_UNDER_CERTIFIED_AUTHORITY", False,
            "cold V05C products + docs/V07C-production-manifest.csv",
            "Reset clears decimal mode, the admitted universe contains zero SED contexts, PLP is source-paired and NMI RTI only preserves interrupted status; production still fails closed if this authority changes."),
        row("07C-16C", "One current production graph and negative authority retirement", "RETIRED_NEGATIVE_PROOF", False,
            "docs/V17C-production-authority-audit.json + docs/V17C-static-symbol-audit.json",
            "No S-CPU/SPC700 decoder, fallback, third-party DSP owner or frontend is selected; current archives match their receipts."),
        row("08C/17C", "Strict-default WRAM $0016-$0017 first-use state", "HARDWARE_INDETERMINATE", False,
            "docs/V17C-wram-0016-power-on-provenance.json + docs/V17C-natural-300-frames-unprofiled-boundary.json",
            "Strict unknown-WRAM execution stops at source-identified first consumption. The separate deterministic-zero-WRAM-v1 profile does not become cartridge or universal hardware authority."),
        row("17C", "Natural master-clock framebuffer and active Theme Park PCM validation", "CLOSED_RUNTIME_SEMANTICS", False,
            "docs/V17C-natural-ladder-summary.json",
            "Cold 300/600/10000-frame and exact 60/120/180-second master-clock rungs pass; the 300-frame rung repeats byte-identically; no unknown PCM or owner stop occurs."),
    ]

    ledger_path = DOCS / "V17C-global-frontier-ledger.csv"
    with ledger_path.open("w", encoding="utf-8", newline="") as stream:
        fields = ("Owner", "Obligation", "Classification", "Blocking", "Evidence", "Detail")
        writer = csv.DictWriter(stream, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        for entry in rows:
            writer.writerow({
                "Owner": entry["owner"], "Obligation": entry["obligation"],
                "Classification": entry["classification"],
                "Blocking": str(entry["blocking"]).lower(),
                "Evidence": entry["evidence"], "Detail": entry["detail"],
            })

    blocking = [entry for entry in rows if entry["blocking"]]
    ledger = {
        "schema": "theme-park-v17c-global-frontier-ledger-v1",
        "status": "PASS_A_FIXED_POINT_ZERO_BLOCKING_ROWS",
        "rows": rows,
        "row_count": len(rows),
        "blocking_rows": len(blocking),
        "blocking_obligations": [entry["obligation"] for entry in blocking],
        "new_source_obligations": 0,
        "cold_exact_contexts": 71986,
        "cold_lexical_rows": 5242880,
        "cold_products_sha256": cold_hashes,
        "current_evidence_sha256": evidence_hashes,
        "owner_sha256": owner_hashes,
        "production_selection_sha256": sha(ROOT / "config/production-selection.json"),
        "current_static_compile_receipt_sha256": sha(DOCS / "V17C-static-compile-receipt.json"),
        "current_static_symbol_audit_sha256": sha(DOCS / "V17C-static-symbol-audit.json"),
        "production_authority_audit_sha256": sha(DOCS / "V17C-production-authority-audit.json"),
        "integration_impact_audit_sha256": sha(DOCS / "V17C-integration-impact-audit.json"),
        "static_compile_receipt_sha256": sha(DOCS / "V17C-static-compile-receipt.json"),
        "static_symbol_audit_sha256": sha(DOCS / "V17C-static-symbol-audit.json"),
        "natural_ladder_summary_sha256": sha(DOCS / "V17C-natural-ladder-summary.json"),
        "power_on_provenance_sha256": sha(DOCS / "V17C-wram-0016-power-on-provenance.json"),
        "csv_sha256": sha(ledger_path),
    }
    write_json(DOCS / "V17C-global-frontier-ledger.json", ledger)

    receipt = {
        "schema": "theme-park-v17c-pass-a-source-reconciliation-v1",
        "status": "PASS_A_WHOLE_CORE_FIXED_POINT_NATURAL_LADDER_CLOSED",
        "rom_sha256": sha(args.rom),
        "fresh_products_byte_identical": len(cold_hashes),
        "fresh_exact_contexts": len(fresh_keys),
        "production_contexts": len(production_keys),
        "fresh_equals_production": fresh_keys == production_keys,
        "fresh_flow_frontiers": fresh_flow["frontiers"],
        "fresh_byte_conflicts": fresh_flow["byte_conflict_rows"],
        "sed_contexts": mnemonic_counts.get("SED", 0),
        "invalid_bcd_classification": "UNREACHABLE_UNDER_CERTIFIED_AUTHORITY_FAIL_CLOSED_IF_REOPENED",
        "blocking_rows": len(blocking),
        "natural_integration_executed": True,
        "active_theme_park_pcm_validated": True,
        "completed_theme_park_frame_validated": True,
        "natural_validation_runner": executables[0],
        "frontend_selected": False,
        "oracle_used": False,
        "global_frontier_ledger_sha256": sha(DOCS / "V17C-global-frontier-ledger.json"),
        "global_frontier_csv_sha256": sha(ledger_path),
        "production_authority_audit_sha256": sha(DOCS / "V17C-production-authority-audit.json"),
        "integration_impact_audit_sha256": sha(DOCS / "V17C-integration-impact-audit.json"),
        "static_compile_receipt_sha256": sha(DOCS / "V17C-static-compile-receipt.json"),
        "static_symbol_audit_sha256": sha(DOCS / "V17C-static-symbol-audit.json"),
        "natural_ladder_summary_sha256": sha(DOCS / "V17C-natural-ladder-summary.json"),
    }
    write_json(DOCS / "V17C-pass-a-source-reconciliation.json", receipt)
    print(json.dumps({
        "status": receipt["status"],
        "cold_products": len(cold_hashes),
        "exact_contexts": len(fresh_keys),
        "blocking_rows": len(blocking),
    }, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
