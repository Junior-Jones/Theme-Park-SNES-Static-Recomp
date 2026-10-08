#!/usr/bin/env python3
"""Compile the 09C timed static core as libraries; never create an executable."""
from __future__ import annotations

import hashlib
import json
import os
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GENERATED = ROOT / "static-core/generated/scpu"
TIMING = ROOT / "static-core/generated/timing"
BUILD = ROOT / "build/v09c-static"


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
    inventory = json.loads((ROOT / "config/compiler-inventory.json").read_text(encoding="utf-8"))
    generation = json.loads((GENERATED / "V07C-generation-manifest.json").read_text(encoding="utf-8"))
    timing_summary = json.loads((ROOT / "docs/V09C-timing-plan-summary.json").read_text(encoding="utf-8"))
    if generation["context_count"] != 71986 or timing_summary["contexts"] != 71986:
        raise ValueError("V07 semantic or V09 timing context surface is incomplete")
    sources = [(ROOT / line).resolve() for line in
               (GENERATED / "tp_v07_sources.txt").read_text(encoding="utf-8").splitlines()]
    sources += [(ROOT / name).resolve() for name in (
        "runtime/src/theme_park_bus.c", "runtime/src/theme_park_scheduler.c",
        "runtime/src/theme_park_machine.c",
        "static-core/generated/timing/theme_park_v09_timing.c")]
    if len(sources) != 676 or any(not path.is_file() for path in sources):
        raise ValueError("09C source inventory is incomplete")
    include_dirs = [ROOT / "static-core/internal", GENERATED, TIMING, ROOT / "runtime/include"]

    msvc_dir = BUILD / "msvc"
    msvc_dir.mkdir(parents=True, exist_ok=True)
    msvc_rsp = msvc_dir / "compile.rsp"
    write_rsp(msvc_rsp, ["/nologo", "/c", "/TC", "/std:c11", "/O2", "/W4", "/WX", "/MP"] +
              [f"/I{path.resolve()}" for path in include_dirs] + [str(path) for path in sources])
    vcvars = Path(inventory["selected_future_primary"]["installation"]) / "VC/Auxiliary/Build/vcvars64.bat"
    compiler = Path(inventory["selected_future_primary"]["compiler_path"])
    librarian = Path(inventory["selected_future_primary"]["librarian_path"])
    subprocess.run([str(compiler), f"@{msvc_rsp}"], cwd=msvc_dir, check=True,
                   env=msvc_environment(vcvars))
    msvc_objects = [msvc_dir / (path.stem + ".obj") for path in sources]
    if any(not path.is_file() for path in msvc_objects):
        raise ValueError("MSVC object set incomplete")
    write_rsp(msvc_dir / "library.rsp", [str(path) for path in msvc_objects])
    msvc_library = msvc_dir / "theme_park_v09c.lib"
    subprocess.run([str(librarian), "/NOLOGO", f"/OUT:{msvc_library}",
                    f"@{msvc_dir / 'library.rsp'}"], cwd=msvc_dir, check=True)

    gcc_dir = BUILD / "gcc"
    gcc_dir.mkdir(parents=True, exist_ok=True)
    gcc = Path(inventory["selected_future_secondary"]["path"])
    archiver = Path(inventory["selected_future_secondary"]["archiver"])
    gcc_rsp = gcc_dir / "compile.rsp"
    write_rsp(gcc_rsp, ["-c", "-std=c11", "-O2", "-Wall", "-Wextra", "-Werror"] +
              [f"-I{path.resolve()}" for path in include_dirs] + [str(path) for path in sources])
    subprocess.run([str(gcc), f"@{gcc_rsp}"], cwd=gcc_dir, check=True)
    gcc_objects = [gcc_dir / (path.stem + ".o") for path in sources]
    if any(not path.is_file() for path in gcc_objects):
        raise ValueError("GCC object set incomplete")
    write_rsp(gcc_dir / "library.rsp", [str(path) for path in gcc_objects])
    gcc_library = gcc_dir / "libtheme_park_v09c.a"
    subprocess.run([str(archiver), "rcs", str(gcc_library), f"@{gcc_dir / 'library.rsp'}"],
                   cwd=gcc_dir, check=True)

    executables = list(BUILD.rglob("*.exe"))
    if executables:
        raise AssertionError(f"forbidden executable products: {executables}")
    receipt = {
        "schema": "theme-park-v09c-static-compile-v1",
        "status": "PASS_TIMED_STATIC_CORE_LIBRARIES_NO_EXECUTABLE",
        "contexts": 71986, "source_files": len(sources), "executables_created": 0,
        "msvc": {"objects": len(msvc_objects),
                 "library": str(msvc_library.relative_to(ROOT)).replace("\\", "/"),
                 "library_sha256": sha(msvc_library)},
        "gcc": {"objects": len(gcc_objects),
                "library": str(gcc_library.relative_to(ROOT)).replace("\\", "/"),
                "library_sha256": sha(gcc_library)},
        "inputs_sha256": {
            "production_manifest": sha(ROOT / "docs/V07C-production-manifest.csv"),
            "timing_plan": sha(TIMING / "theme_park_v09_timing.c"),
            "scheduler": sha(ROOT / "runtime/src/theme_park_scheduler.c"),
            "bus": sha(ROOT / "runtime/src/theme_park_bus.c"),
            "machine": sha(ROOT / "runtime/src/theme_park_machine.c"),
        },
    }
    (ROOT / "docs/V09C-static-compile-receipt.json").write_text(
        json.dumps(receipt, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps({"status": receipt["status"], "objects_per_toolchain": len(sources)}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
