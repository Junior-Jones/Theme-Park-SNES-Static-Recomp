#!/usr/bin/env python3
"""Compile the 11C PPU-state core to static libraries, never an executable."""
from __future__ import annotations

import hashlib
import json
import os
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GENERATED = ROOT / "static-core/generated/scpu"
TIMING = ROOT / "static-core/generated/timing"
BUILD = ROOT / "build/v11c-static"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def write_rsp(path: Path, args: list[str]) -> None:
    path.write_text("\n".join(f'"{x}"' if " " in x else x for x in args) + "\n",
                    encoding="utf-8", newline="\n")


def msvc_environment(vcvars: Path) -> dict[str, str]:
    result = subprocess.run(["cmd.exe", "/d", "/c", "call", str(vcvars), ">nul", "&&", "set"],
                            check=True, capture_output=True, text=True)
    environment = os.environ.copy()
    for line in result.stdout.splitlines():
        if "=" in line:
            key, value = line.split("=", 1); environment[key] = value
    return environment


def main() -> int:
    ppu_only = sys.argv[1:] == ["--ppu-only"]
    if sys.argv[1:] not in ([], ["--ppu-only"]):
        raise ValueError("usage: v11_compile_static.py [--ppu-only]")
    inventory = json.loads((ROOT / "config/compiler-inventory.json").read_text(encoding="utf-8"))
    generation = json.loads((GENERATED / "V07C-generation-manifest.json").read_text(encoding="utf-8"))
    join = json.loads((ROOT / "docs/V11C-ppu-source-join-summary.json").read_text(encoding="utf-8"))
    if generation["context_count"] != 71986 or join["exact_register_events"] != 702:
        raise ValueError("V07/11 authority surface incomplete")
    if join["source_reached_registers_missing_owner"] or join["open_bbad_writer_events"]:
        raise ValueError("11C receiver proof is open")
    sources = [(ROOT / line).resolve() for line in
               (GENERATED / "tp_v07_sources.txt").read_text(encoding="utf-8").splitlines()]
    sources += [(ROOT / name).resolve() for name in (
        "runtime/src/theme_park_bus.c", "runtime/src/theme_park_scheduler.c",
        "runtime/src/theme_park_dma.c", "runtime/src/theme_park_ppu.c",
        "runtime/src/theme_park_machine.c", "static-core/generated/timing/theme_park_v09_timing.c")]
    if len(sources) != 678 or any(not path.is_file() for path in sources):
        raise ValueError("11C source inventory incomplete")
    includes = [ROOT / "static-core/internal", GENERATED, TIMING, ROOT / "runtime/include"]
    inputs = {name: sha(ROOT / path) for name, path in {
        "production_manifest": "docs/V07C-production-manifest.csv",
        "timing_plan": "static-core/generated/timing/theme_park_v09_timing.c",
        "scheduler": "runtime/src/theme_park_scheduler.c", "bus": "runtime/src/theme_park_bus.c",
        "dma": "runtime/src/theme_park_dma.c", "ppu": "runtime/src/theme_park_ppu.c",
        "ppu_header": "runtime/include/theme_park_ppu.h", "machine": "runtime/src/theme_park_machine.c",
        "source_join": "docs/V11C-ppu-source-join-summary.json"}.items()}

    msvc_dir = BUILD / "msvc"; msvc_dir.mkdir(parents=True, exist_ok=True)
    msvc_objects = [msvc_dir / (path.stem + ".obj") for path in sources]
    msvc_library = msvc_dir / "theme_park_v11c.lib"
    compile_sources = [ROOT / "runtime/src/theme_park_ppu.c"] if ppu_only else sources
    write_rsp(msvc_dir / "compile.rsp", ["/nologo", "/c", "/TC", "/std:c11", "/O2", "/W4", "/WX", "/MP"] +
              [f"/I{path.resolve()}" for path in includes] + [str(path) for path in compile_sources])
    vcvars = Path(inventory["selected_future_primary"]["installation"]) / "VC/Auxiliary/Build/vcvars64.bat"
    compiler = Path(inventory["selected_future_primary"]["compiler_path"])
    librarian = Path(inventory["selected_future_primary"]["librarian_path"])
    subprocess.run([str(compiler), f"@{msvc_dir / 'compile.rsp'}"], cwd=msvc_dir, check=True,
                   env=msvc_environment(vcvars))
    write_rsp(msvc_dir / "library.rsp", [str(path) for path in msvc_objects])
    subprocess.run([str(librarian), "/NOLOGO", f"/OUT:{msvc_library}",
                    f"@{msvc_dir / 'library.rsp'}"], cwd=msvc_dir, check=True)

    gcc_dir = BUILD / "gcc"; gcc_dir.mkdir(parents=True, exist_ok=True)
    gcc = Path(inventory["selected_future_secondary"]["path"])
    archiver = Path(inventory["selected_future_secondary"]["archiver"])
    gcc_objects = [gcc_dir / (path.stem + ".o") for path in sources]
    gcc_library = gcc_dir / "libtheme_park_v11c.a"
    write_rsp(gcc_dir / "compile.rsp", ["-c", "-std=c11", "-O2", "-Wall", "-Wextra", "-Werror"] +
              [f"-I{path.resolve()}" for path in includes] + [str(path) for path in compile_sources])
    subprocess.run([str(gcc), f"@{gcc_dir / 'compile.rsp'}"], cwd=gcc_dir, check=True)
    write_rsp(gcc_dir / "library.rsp", [str(path) for path in gcc_objects])
    subprocess.run([str(archiver), "rcs", str(gcc_library), f"@{gcc_dir / 'library.rsp'}"],
                   cwd=gcc_dir, check=True)
    if any(not p.is_file() for p in msvc_objects + gcc_objects) or not msvc_library.is_file() or not gcc_library.is_file():
        raise ValueError("object/library set incomplete")
    if list(ROOT.rglob("*.exe")):
        raise AssertionError("forbidden executable product exists")
    receipt = {
        "schema": "theme-park-v11c-static-compile-v1",
        "status": "PASS_PPU_STATE_STATIC_CORE_LIBRARIES_NO_EXECUTABLE",
        "contexts": 71986, "source_files": len(sources), "executables_created": 0,
        "msvc": {"objects": len(msvc_objects), "library": str(msvc_library.relative_to(ROOT)).replace("\\", "/"),
                 "library_sha256": sha(msvc_library)},
        "gcc": {"objects": len(gcc_objects), "library": str(gcc_library.relative_to(ROOT)).replace("\\", "/"),
                "library_sha256": sha(gcc_library)}, "inputs_sha256": inputs,
        "compile_action": ("RECOMPILED_CHANGED_PPU_OBJECT_AND_REARCHIVED_COMPLETE_LIBRARIES"
                           if ppu_only else "COMPILED_ALL_OBJECTS_AND_STATIC_LIBRARIES"),
    }
    (ROOT / "docs/V11C-static-compile-receipt.json").write_text(
        json.dumps(receipt, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps({"status": receipt["status"], "objects_per_toolchain": len(sources)}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
