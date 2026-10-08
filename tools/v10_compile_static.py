#!/usr/bin/env python3
"""Compile the 10C DMA-joined static core as libraries; never create an executable."""
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
BUILD = ROOT / "build/v10c-static"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def write_rsp(path: Path, arguments: list[str]) -> None:
    path.write_text("\n".join(f'"{item}"' if " " in item else item for item in arguments) + "\n",
                    encoding="utf-8", newline="\n")


def msvc_environment(vcvars: Path) -> dict[str, str]:
    result = subprocess.run(["cmd.exe", "/d", "/c", "call", str(vcvars), ">nul", "&&", "set"],
                            check=True, capture_output=True, text=True)
    environment = os.environ.copy()
    for line in result.stdout.splitlines():
        if "=" in line:
            key, value = line.split("=", 1)
            environment[key] = value
    return environment


def main() -> int:
    receipt_only = sys.argv[1:] == ["--receipt-only"]
    if sys.argv[1:] not in ([], ["--receipt-only"]):
        raise ValueError("usage: v10_compile_static.py [--receipt-only]")
    inventory = json.loads((ROOT / "config/compiler-inventory.json").read_text(encoding="utf-8"))
    generation = json.loads((GENERATED / "V07C-generation-manifest.json").read_text(encoding="utf-8"))
    timing = json.loads((ROOT / "docs/V09C-timing-plan-summary.json").read_text(encoding="utf-8"))
    source_join = json.loads((ROOT / "docs/V10C-dma-source-join-summary.json").read_text(encoding="utf-8"))
    if generation["context_count"] != 71986 or timing["contexts"] != 71986:
        raise ValueError("V07/V09 authority surface is incomplete")
    if source_join["exact_byte_register_events"] != 548 or source_join["open_trigger_value_domains"] != 0:
        raise ValueError("V10 exact source trigger join is incomplete")
    sources = [(ROOT / line).resolve() for line in
               (GENERATED / "tp_v07_sources.txt").read_text(encoding="utf-8").splitlines()]
    sources += [(ROOT / name).resolve() for name in (
        "runtime/src/theme_park_bus.c", "runtime/src/theme_park_scheduler.c",
        "runtime/src/theme_park_dma.c", "runtime/src/theme_park_machine.c",
        "static-core/generated/timing/theme_park_v09_timing.c")]
    if len(sources) != 677 or any(not path.is_file() for path in sources):
        raise ValueError("10C source inventory is incomplete")
    includes = [ROOT / "static-core/internal", GENERATED, TIMING, ROOT / "runtime/include"]
    compile_inputs = {
        "production_manifest": sha(ROOT / "docs/V07C-production-manifest.csv"),
        "timing_plan": sha(TIMING / "theme_park_v09_timing.c"),
        "scheduler": sha(ROOT / "runtime/src/theme_park_scheduler.c"),
        "bus": sha(ROOT / "runtime/src/theme_park_bus.c"),
        "dma": sha(ROOT / "runtime/src/theme_park_dma.c"),
        "machine": sha(ROOT / "runtime/src/theme_park_machine.c"),
    }

    msvc_dir = BUILD / "msvc"
    msvc_dir.mkdir(parents=True, exist_ok=True)
    msvc_objects = [msvc_dir / (path.stem + ".obj") for path in sources]
    msvc_library = msvc_dir / "theme_park_v10c.lib"
    if not receipt_only:
        write_rsp(msvc_dir / "compile.rsp",
                  ["/nologo", "/c", "/TC", "/std:c11", "/O2", "/W4", "/WX", "/MP"] +
                  [f"/I{path.resolve()}" for path in includes] + [str(path) for path in sources])
        vcvars = Path(inventory["selected_future_primary"]["installation"]) / "VC/Auxiliary/Build/vcvars64.bat"
        compiler = Path(inventory["selected_future_primary"]["compiler_path"])
        librarian = Path(inventory["selected_future_primary"]["librarian_path"])
        subprocess.run([str(compiler), f"@{msvc_dir / 'compile.rsp'}"], cwd=msvc_dir, check=True,
                       env=msvc_environment(vcvars))
        write_rsp(msvc_dir / "library.rsp", [str(path) for path in msvc_objects])
        subprocess.run([str(librarian), "/NOLOGO", f"/OUT:{msvc_library}",
                        f"@{msvc_dir / 'library.rsp'}"], cwd=msvc_dir, check=True)
    if any(not path.is_file() for path in msvc_objects) or not msvc_library.is_file():
        raise ValueError("MSVC object/library set incomplete")

    gcc_dir = BUILD / "gcc"
    gcc_dir.mkdir(parents=True, exist_ok=True)
    gcc = Path(inventory["selected_future_secondary"]["path"])
    archiver = Path(inventory["selected_future_secondary"]["archiver"])
    gcc_objects = [gcc_dir / (path.stem + ".o") for path in sources]
    gcc_library = gcc_dir / "libtheme_park_v10c.a"
    if not receipt_only:
        write_rsp(gcc_dir / "compile.rsp",
                  ["-c", "-std=c11", "-O2", "-Wall", "-Wextra", "-Werror"] +
                  [f"-I{path.resolve()}" for path in includes] + [str(path) for path in sources])
        subprocess.run([str(gcc), f"@{gcc_dir / 'compile.rsp'}"], cwd=gcc_dir, check=True)
        write_rsp(gcc_dir / "library.rsp", [str(path) for path in gcc_objects])
        subprocess.run([str(archiver), "rcs", str(gcc_library), f"@{gcc_dir / 'library.rsp'}"],
                       cwd=gcc_dir, check=True)
    if any(not path.is_file() for path in gcc_objects) or not gcc_library.is_file():
        raise ValueError("GCC object/library set incomplete")

    executables = list(BUILD.rglob("*.exe"))
    if executables:
        raise AssertionError(f"forbidden executable products: {executables}")
    receipt_path = ROOT / "docs/V10C-static-compile-receipt.json"
    if receipt_only:
        old = json.loads(receipt_path.read_text(encoding="utf-8"))
        for key, value in compile_inputs.items():
            if old["inputs_sha256"].get(key) != value:
                raise ValueError(f"cannot reuse libraries: compile input changed: {key}")
        if (old["msvc"]["library_sha256"] != sha(msvc_library) or
                old["gcc"]["library_sha256"] != sha(gcc_library)):
            raise ValueError("cannot reuse libraries: library hash changed")
    receipt = {
        "schema": "theme-park-v10c-static-compile-v1",
        "status": "PASS_DMA_JOINED_STATIC_CORE_LIBRARIES_NO_EXECUTABLE",
        "contexts": 71986, "source_files": len(sources), "executables_created": 0,
        "msvc": {"objects": len(msvc_objects),
                 "library": str(msvc_library.relative_to(ROOT)).replace("\\", "/"),
                 "library_sha256": sha(msvc_library)},
        "gcc": {"objects": len(gcc_objects),
                "library": str(gcc_library.relative_to(ROOT)).replace("\\", "/"),
                "library_sha256": sha(gcc_library)},
        "compile_action": ("REUSED_HASH_MATCHING_STATIC_OBJECTS_AND_LIBRARIES"
                           if receipt_only else "COMPILED_OBJECTS_AND_STATIC_LIBRARIES"),
        "inputs_sha256": compile_inputs,
        "qualification_inputs_sha256": {
            "source_join": sha(ROOT / "docs/V10C-dma-source-join-summary.json"),
            "startup_phase_certificate": sha(ROOT / "docs/V10C-hdma-ch0-startup-phase-certificate.json"),
        },
    }
    receipt_path.write_text(
        json.dumps(receipt, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps({"status": receipt["status"], "objects_per_toolchain": len(sources)}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
