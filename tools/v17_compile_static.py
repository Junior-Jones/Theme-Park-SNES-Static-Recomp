#!/usr/bin/env python3
"""Compile Theme Park's 17C integrated frame/PCM core as static libraries."""
from __future__ import annotations

import argparse
import json
import subprocess
from pathlib import Path

from v13_compile_static import msvc_environment, sha, write_rsp

ROOT = Path(__file__).resolve().parents[1]
GENERATED = ROOT / "static-core/generated/scpu"
TIMING = ROOT / "static-core/generated/timing"
BUILD = ROOT / "build/v17c-static"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--receipt-only", action="store_true")
    args = parser.parse_args()
    inventory = json.loads((ROOT / "config/compiler-inventory.json").read_text(encoding="utf-8"))
    pass_a = json.loads((ROOT / "docs/V17C-pass-a-source-reconciliation.json").read_text(encoding="utf-8"))
    authority = json.loads((ROOT / "docs/V17C-production-authority-audit.json").read_text(encoding="utf-8"))
    if pass_a["status"] not in (
            "PASS_A_SOURCE_AND_AUTHORITY_RECONCILED_NATURAL_INTEGRATION_PENDING",
            "PASS_A_WHOLE_CORE_FIXED_POINT_NATURAL_LADDER_CLOSED"):
        raise ValueError("17C source reconciliation is not valid")
    if authority["status"] != "PASS_ONE_CURRENT_STATIC_SOURCE_GRAPH_NO_FOREIGN_OWNER_OR_FALLBACK":
        raise ValueError("17C production authority audit is open")

    sources = [(ROOT / line).resolve() for line in
               (GENERATED / "tp_v07_sources.txt").read_text(encoding="utf-8").splitlines()]
    sources += [(ROOT / name).resolve() for name in (
        "runtime/src/theme_park_bus.c", "runtime/src/theme_park_scheduler.c",
        "runtime/src/theme_park_dma.c", "runtime/src/theme_park_ppu.c",
        "runtime/src/theme_park_renderer.c", "runtime/src/theme_park_apu.c",
        "runtime/src/theme_park_spc700.c", "runtime/generated/theme_park_spc700_aot.c",
        "runtime/src/theme_park_input.c", "runtime/src/theme_park_sdsp.c",
        "runtime/src/theme_park_machine.c",
        "static-core/generated/timing/theme_park_v09_timing.c",
    )]
    if len(sources) != 684 or len(set(sources)) != 684 or any(not path.is_file() for path in sources):
        raise ValueError("17C source inventory incomplete")
    includes = [ROOT / "static-core/internal", GENERATED, TIMING, ROOT / "runtime/include"]
    inputs = {name: sha(ROOT / path) for name, path in {
        "production_authority_audit": "docs/V17C-production-authority-audit.json",
        "machine": "runtime/src/theme_park_machine.c",
        "machine_header": "runtime/include/theme_park_machine.h",
        "bus": "runtime/src/theme_park_bus.c",
        "bus_header": "runtime/include/theme_park_bus.h",
        "scheduler": "runtime/src/theme_park_scheduler.c",
        "dma": "runtime/src/theme_park_dma.c",
        "ppu": "runtime/src/theme_park_ppu.c",
        "renderer": "runtime/src/theme_park_renderer.c",
        "input": "runtime/src/theme_park_input.c",
        "apu": "runtime/src/theme_park_apu.c",
        "spc700_aot": "runtime/generated/theme_park_spc700_aot.c",
        "sdsp": "runtime/src/theme_park_sdsp.c",
        "timing_profile": "config/timing-profile.json",
        "target_contract": "config/target-contract.json",
        "power_on_profiles": "config/power-on-profiles.json",
    }.items()}

    msvc_dir = BUILD / "msvc"
    gcc_dir = BUILD / "gcc"
    msvc_dir.mkdir(parents=True, exist_ok=True)
    gcc_dir.mkdir(parents=True, exist_ok=True)
    msvc_objects = [msvc_dir / (path.stem + ".obj") for path in sources]
    gcc_objects = [gcc_dir / (path.stem + ".o") for path in sources]
    msvc_library = msvc_dir / "theme_park_v17c.lib"
    gcc_library = gcc_dir / "libtheme_park_v17c.a"

    if not args.receipt_only:
        write_rsp(msvc_dir / "compile.rsp",
                  ["/nologo", "/c", "/TC", "/std:c11", "/O2", "/W4", "/WX", "/MP"] +
                  [f"/I{path.resolve()}" for path in includes] + [str(path) for path in sources])
        vcvars = Path(inventory["selected_future_primary"]["installation"]) / "VC/Auxiliary/Build/vcvars64.bat"
        subprocess.run([inventory["selected_future_primary"]["compiler_path"],
                        f"@{msvc_dir / 'compile.rsp'}"], cwd=msvc_dir, check=True,
                       env=msvc_environment(vcvars))
        write_rsp(msvc_dir / "library.rsp", [str(path) for path in msvc_objects])
        subprocess.run([inventory["selected_future_primary"]["librarian_path"], "/NOLOGO",
                        f"/OUT:{msvc_library}", f"@{msvc_dir / 'library.rsp'}"],
                       cwd=msvc_dir, check=True)

        write_rsp(gcc_dir / "compile.rsp",
                  ["-c", "-std=c11", "-O2", "-Wall", "-Wextra", "-Werror"] +
                  [f"-I{path.resolve()}" for path in includes] + [str(path) for path in sources])
        subprocess.run([inventory["selected_future_secondary"]["path"],
                        f"@{gcc_dir / 'compile.rsp'}"], cwd=gcc_dir, check=True)
        write_rsp(gcc_dir / "library.rsp", [str(path) for path in gcc_objects])
        subprocess.run([inventory["selected_future_secondary"]["archiver"], "rcs",
                        str(gcc_library), f"@{gcc_dir / 'library.rsp'}"],
                       cwd=gcc_dir, check=True)

    if any(not path.is_file() for path in msvc_objects + gcc_objects):
        raise ValueError("17C object set incomplete")
    if not msvc_library.is_file() or not gcc_library.is_file():
        raise ValueError("17C static library missing")
    executables = [path.relative_to(ROOT).as_posix()
                   for path in ROOT.rglob("*.exe")]
    permitted_executables = [
        "build/v17c-natural/theme_park_v17c_natural_runner.exe"
    ]
    if any(path not in permitted_executables for path in executables):
        raise AssertionError("unexpected executable product exists")

    receipt = {
        "schema": "theme-park-v17c-static-compile-v1",
        "status": "PASS_17C_INTEGRATED_FRAME_PCM_STATIC_LIBRARIES",
        "source_files": len(sources),
        "scpu_contexts": 71986,
        "ssmp_contexts": 1392,
        "natural_validation_executables_present": executables,
        "frame_run_boundary": "tp_machine_run_to_next_frame",
        "frame_read_boundary": "tp_machine_read_published_frame",
        "pcm_boundary": "tp_machine_pcm_read",
        "diagnostics_boundary": "tp_machine_read_diagnostics",
        "msvc": {"objects": len(msvc_objects),
                 "library": str(msvc_library.relative_to(ROOT)).replace("\\", "/"),
                 "library_sha256": sha(msvc_library)},
        "gcc": {"objects": len(gcc_objects),
                "library": str(gcc_library.relative_to(ROOT)).replace("\\", "/"),
                "library_sha256": sha(gcc_library)},
        "inputs_sha256": inputs,
        "compile_action": ("REHASHED_EXISTING_OBJECTS_AND_STATIC_LIBRARIES"
                           if args.receipt_only else
                           "COMPILED_ALL_OBJECTS_AND_STATIC_LIBRARIES"),
    }
    (ROOT / "docs/V17C-static-compile-receipt.json").write_text(
        json.dumps(receipt, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps({"status": receipt["status"],
                      "objects_per_toolchain": len(sources)}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
