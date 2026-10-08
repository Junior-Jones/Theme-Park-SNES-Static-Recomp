#!/usr/bin/env python3
"""Compile the closed 16C S-DSP/audio owner into static libraries only."""
from __future__ import annotations
import argparse, json, subprocess
from pathlib import Path
from v13_compile_static import sha, write_rsp, msvc_environment

ROOT = Path(__file__).resolve().parents[1]
GENERATED = ROOT / "static-core/generated/scpu"
TIMING = ROOT / "static-core/generated/timing"
BUILD = ROOT / "build/v16c-static"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--receipt-only", action="store_true",
                        help="rehash evidence after verifying the complete object/library set")
    args = parser.parse_args()
    inventory = json.loads((ROOT / "config/compiler-inventory.json").read_text(encoding="utf-8"))
    domain = json.loads((ROOT / "docs/V16C-sdsp-source-domain.json").read_text(encoding="utf-8"))
    if not str(domain["status"]).startswith("CLOSED_"):
        raise ValueError("16C DSP source domain is open")
    sources = [(ROOT / line).resolve() for line in
               (GENERATED / "tp_v07_sources.txt").read_text(encoding="utf-8").splitlines()]
    sources += [(ROOT / name).resolve() for name in (
        "runtime/src/theme_park_bus.c", "runtime/src/theme_park_scheduler.c",
        "runtime/src/theme_park_dma.c", "runtime/src/theme_park_ppu.c",
        "runtime/src/theme_park_renderer.c", "runtime/src/theme_park_apu.c",
        "runtime/src/theme_park_spc700.c", "runtime/generated/theme_park_spc700_aot.c",
        "runtime/src/theme_park_input.c", "runtime/src/theme_park_sdsp.c",
        "runtime/src/theme_park_machine.c",
        "static-core/generated/timing/theme_park_v09_timing.c")]
    if len(sources) != 684 or any(not path.is_file() for path in sources):
        raise ValueError("16C source inventory incomplete")
    includes = [ROOT / "static-core/internal", GENERATED, TIMING, ROOT / "runtime/include"]
    evidence = {
        "source_domain": "docs/V16C-sdsp-source-domain.json",
        "sdsp": "runtime/src/theme_park_sdsp.c",
        "sdsp_header": "runtime/include/theme_park_sdsp.h",
        "apu": "runtime/src/theme_park_apu.c",
        "apu_header": "runtime/include/theme_park_apu.h",
        "machine": "runtime/src/theme_park_machine.c",
        "machine_header": "runtime/include/theme_park_machine.h",
        "spc700_aot": "runtime/generated/theme_park_spc700_aot.c",
        "scheduler": "runtime/src/theme_park_scheduler.c",
        "timing_profile": "config/timing-profile.json",
        "target_contract": "config/target-contract.json",
    }
    inputs = {key: sha(ROOT / value) for key, value in evidence.items()}

    msvc_dir = BUILD / "msvc"
    msvc_dir.mkdir(parents=True, exist_ok=True)
    msvc_objects = [msvc_dir / (path.stem + ".obj") for path in sources]
    msvc_library = msvc_dir / "theme_park_v16c.lib"
    if not args.receipt_only:
        write_rsp(msvc_dir / "compile.rsp",
                  ["/nologo", "/c", "/TC", "/std:c11", "/O2", "/W4", "/WX", "/MP"] +
                  [f"/I{path.resolve()}" for path in includes] + [str(path) for path in sources])
        vcvars = Path(inventory["selected_future_primary"]["installation"]) / "VC/Auxiliary/Build/vcvars64.bat"
        subprocess.run([inventory["selected_future_primary"]["compiler_path"],
                        f"@{msvc_dir/'compile.rsp'}"], cwd=msvc_dir, check=True,
                       env=msvc_environment(vcvars))
        write_rsp(msvc_dir / "library.rsp", [str(path) for path in msvc_objects])
        subprocess.run([inventory["selected_future_primary"]["librarian_path"], "/NOLOGO",
                        f"/OUT:{msvc_library}", f"@{msvc_dir/'library.rsp'}"],
                       cwd=msvc_dir, check=True)

    gcc_dir = BUILD / "gcc"
    gcc_dir.mkdir(parents=True, exist_ok=True)
    gcc_objects = [gcc_dir / (path.stem + ".o") for path in sources]
    gcc_library = gcc_dir / "libtheme_park_v16c.a"
    if not args.receipt_only:
        write_rsp(gcc_dir / "compile.rsp",
                  ["-c", "-std=c11", "-O2", "-Wall", "-Wextra", "-Werror"] +
                  [f"-I{path.resolve()}" for path in includes] + [str(path) for path in sources])
        subprocess.run([inventory["selected_future_secondary"]["path"],
                        f"@{gcc_dir/'compile.rsp'}"], cwd=gcc_dir, check=True)
        write_rsp(gcc_dir / "library.rsp", [str(path) for path in gcc_objects])
        subprocess.run([inventory["selected_future_secondary"]["archiver"], "rcs",
                        str(gcc_library), f"@{gcc_dir/'library.rsp'}"], cwd=gcc_dir, check=True)

    if any(not path.is_file() for path in msvc_objects + gcc_objects):
        raise ValueError("16C object set incomplete")
    if not msvc_library.is_file() or not gcc_library.is_file():
        raise ValueError("16C static library missing")
    if list(ROOT.rglob("*.exe")):
        raise AssertionError("forbidden executable product exists")
    receipt = {
        "schema": "theme-park-v16c-static-compile-v1",
        "status": "PASS_PROJECT_OWNED_SDSP_STATIC_LIBRARIES_NO_EXECUTABLE",
        "scpu_contexts": 71986,
        "ssmp_contexts": 1392,
        "source_files": len(sources),
        "executables_created": 0,
        "msvc": {"objects": len(msvc_objects),
                 "library": str(msvc_library.relative_to(ROOT)).replace("\\", "/"),
                 "library_sha256": sha(msvc_library)},
        "gcc": {"objects": len(gcc_objects),
                "library": str(gcc_library.relative_to(ROOT)).replace("\\", "/"),
                "library_sha256": sha(gcc_library)},
        "inputs_sha256": inputs,
        "compile_action": ("REHASHED_NON_COMPILER_EVIDENCE_REUSED_COMPLETE_STATIC_LIBRARIES"
                           if args.receipt_only else
                           "COMPILED_ALL_OBJECTS_AND_STATIC_LIBRARIES"),
    }
    (ROOT / "docs/V16C-static-compile-receipt.json").write_text(
        json.dumps(receipt, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps({"status": receipt["status"],
                      "objects_per_toolchain": len(sources)}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
