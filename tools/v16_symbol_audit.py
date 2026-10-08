#!/usr/bin/env python3
"""Audit 16C static archives for the project-owned DSP and forbidden owners."""
from __future__ import annotations
import hashlib, json, subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / "docs/V16C-static-symbol-audit.json"


def digest(text: str) -> str:
    return hashlib.sha256(text.replace("\r\n", "\n").encode()).hexdigest()


def main() -> int:
    inventory = json.loads((ROOT / "config/compiler-inventory.json").read_text(encoding="utf-8"))
    gcc_lib = ROOT / "build/v16c-static/gcc/libtheme_park_v16c.a"
    msvc_lib = ROOT / "build/v16c-static/msvc/theme_park_v16c.lib"
    ar = Path(inventory["selected_future_secondary"]["archiver"])
    nm = ar.with_name("nm.exe")
    librarian = Path(inventory["selected_future_primary"]["librarian_path"])
    gcc_members_text = subprocess.run([str(ar), "t", str(gcc_lib)], check=True,
                                      text=True, capture_output=True).stdout
    gcc_symbols = subprocess.run([str(nm), "-g", "--defined-only", str(gcc_lib)], check=True,
                                 text=True, capture_output=True).stdout
    msvc_members_text = subprocess.run([str(librarian), "/NOLOGO", "/LIST", str(msvc_lib)],
                                       check=True, text=True, capture_output=True).stdout
    gcc_members = [line.strip() for line in gcc_members_text.splitlines() if line.strip()]
    msvc_members = [line.strip() for line in msvc_members_text.splitlines()
                    if line.strip() and not line.startswith("Microsoft") and
                    not line.startswith("Copyright")]
    forbidden = ("snes9x", "mesen", "bsnes", "bapu", "spc_dsp", "snes_spc")
    lowered_symbols = gcc_symbols.lower()
    forbidden_symbols = [name for name in forbidden if name in lowered_symbols]
    forbidden_members = [name for name in gcc_members + msvc_members
                         if any(term in name.lower() for term in forbidden)]
    required = ("tp_sdsp_step_phase", "tp_sdsp_write_register",
                "tp_sdsp_read_register", "tp_sdsp_pcm_read", "tp_machine_pcm_read")
    missing_required = [name for name in required if name not in gcc_symbols]
    if len(gcc_members) != 684 or len(msvc_members) != 684:
        raise AssertionError(f"archive membership changed: GCC={len(gcc_members)} MSVC={len(msvc_members)}")
    if gcc_members.count("theme_park_sdsp.o") != 1:
        raise AssertionError("GCC project DSP object membership is not singular")
    if sum(Path(name).name == "theme_park_sdsp.obj" for name in msvc_members) != 1:
        raise AssertionError("MSVC project DSP object membership is not singular")
    if forbidden_symbols or forbidden_members or missing_required:
        raise AssertionError("static audio ownership audit failed")
    payload = {
        "schema": "theme-park-v16c-static-symbol-audit-v1",
        "status": "PASS_PROJECT_SDSP_PRESENT_NO_THIRD_PARTY_APU_OR_DSP_OWNER",
        "gcc_archive_members": len(gcc_members),
        "msvc_archive_members": len(msvc_members),
        "project_sdsp_objects": {"gcc": 1, "msvc": 1},
        "required_symbols": list(required),
        "missing_required_symbols": missing_required,
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
