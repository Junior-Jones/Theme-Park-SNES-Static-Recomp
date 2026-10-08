#!/usr/bin/env python3
"""Audit 17C static archives for one integrated Theme Park machine graph."""
from __future__ import annotations

import hashlib
import json
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / "docs/V17C-static-symbol-audit.json"


def digest(text: str) -> str:
    return hashlib.sha256(text.replace("\r\n", "\n").encode()).hexdigest()


def main() -> int:
    inventory = json.loads((ROOT / "config/compiler-inventory.json").read_text(encoding="utf-8"))
    gcc_lib = ROOT / "build/v17c-static/gcc/libtheme_park_v17c.a"
    msvc_lib = ROOT / "build/v17c-static/msvc/theme_park_v17c.lib"
    ar = Path(inventory["selected_future_secondary"]["archiver"])
    nm = ar.with_name("nm.exe")
    librarian = Path(inventory["selected_future_primary"]["librarian_path"])
    gcc_members_text = subprocess.run([str(ar), "t", str(gcc_lib)], check=True,
                                      text=True, capture_output=True).stdout
    gcc_symbols = subprocess.run([str(nm), "-g", "--defined-only", str(gcc_lib)],
                                 check=True, text=True, capture_output=True).stdout
    msvc_members_text = subprocess.run([str(librarian), "/NOLOGO", "/LIST", str(msvc_lib)],
                                       check=True, text=True, capture_output=True).stdout
    gcc_members = [line.strip() for line in gcc_members_text.splitlines() if line.strip()]
    msvc_members = [line.strip() for line in msvc_members_text.splitlines()
                    if line.strip() and not line.startswith("Microsoft") and
                    not line.startswith("Copyright")]
    forbidden = ("rock", "topgear", "simcity", "civilization", "jungle", "gundam",
                 "snes9x", "mesen", "bsnes", "bapu", "spc_dsp", "snes_spc")
    forbidden_symbols = [term for term in forbidden if term in gcc_symbols.lower()]
    forbidden_members = [name for name in gcc_members + msvc_members
                         if any(term in Path(name).name.lower() for term in forbidden)]
    required = (
        "tp_v07_dispatch", "tp_machine_power_on", "tp_machine_power_on_profile", "tp_machine_step",
        "tp_bus_power_on_profile",
        "tp_machine_run_to_next_frame", "tp_machine_read_published_frame",
        "tp_machine_read_diagnostics",
        "tp_machine_pcm_available", "tp_machine_pcm_read",
        "tp_ppu_read_published_frame", "tp_sdsp_step_phase",
        "tp_sdsp_write_register", "tp_sdsp_read_register", "tp_sdsp_pcm_read",
        "tp_spc700_aot_begin", "tp_spc700_aot_complete",
    )
    missing = [name for name in required if name not in gcc_symbols]
    if len(gcc_members) != 684 or len(msvc_members) != 684:
        raise AssertionError("17C archive membership changed")
    singular = {
        "scpu_dispatch": gcc_members.count("tp_v07_dispatch.o"),
        "machine": gcc_members.count("theme_park_machine.o"),
        "renderer": gcc_members.count("theme_park_renderer.o"),
        "spc700_aot": gcc_members.count("theme_park_spc700_aot.o"),
        "sdsp": gcc_members.count("theme_park_sdsp.o"),
    }
    if any(value != 1 for value in singular.values()):
        raise AssertionError(f"17C current owner membership is not singular: {singular}")
    if forbidden_symbols or forbidden_members or missing:
        raise AssertionError("17C static authority audit failed")
    payload = {
        "schema": "theme-park-v17c-static-symbol-audit-v1",
        "status": "PASS_ONE_INTEGRATED_FRAME_PCM_MACHINE_NO_FOREIGN_OR_FALLBACK_OWNER",
        "gcc_archive_members": len(gcc_members),
        "msvc_archive_members": len(msvc_members),
        "singular_current_owner_objects": singular,
        "required_symbols": list(required),
        "missing_required_symbols": missing,
        "forbidden_terms": list(forbidden),
        "forbidden_symbols": forbidden_symbols,
        "forbidden_archive_members": forbidden_members,
        "gcc_member_listing_sha256": digest(gcc_members_text),
        "gcc_defined_symbol_listing_sha256": digest(gcc_symbols),
        "msvc_member_listing_sha256": digest(msvc_members_text),
    }
    OUTPUT.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n",
                      encoding="utf-8", newline="\n")
    print(payload["status"])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
