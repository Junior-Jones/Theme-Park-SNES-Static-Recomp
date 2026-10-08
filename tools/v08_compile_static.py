#!/usr/bin/env python3
"""Compile 08C bus ownership into the complete static core; never link an executable."""
from __future__ import annotations

import hashlib
import json
import os
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
V07_BUILD = ROOT / "build/v07c-static"
BUILD = ROOT / "build/v08c-static"
BUS_SOURCE = ROOT / "runtime/src/theme_park_bus.c"


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
    v07 = json.loads((ROOT / "docs/V07C-static-compile-receipt.json").read_text(encoding="utf-8"))
    inventory = json.loads((ROOT / "config/compiler-inventory.json").read_text(encoding="utf-8"))
    for flavor in ("msvc", "gcc"):
        library = ROOT / v07[flavor]["library"]
        if not library.is_file() or sha(library) != v07[flavor]["library_sha256"]:
            raise ValueError(f"sealed 07C {flavor} library changed")
    sources = [(ROOT / line).resolve() for line in
               (ROOT / "static-core/generated/scpu/tp_v07_sources.txt").read_text(encoding="utf-8").splitlines()]
    if len(sources) != 672:
        raise ValueError("sealed 07C source inventory changed")

    msvc_dir = BUILD / "msvc"
    msvc_dir.mkdir(parents=True, exist_ok=True)
    vcvars = Path(inventory["selected_future_primary"]["installation"]) / "VC/Auxiliary/Build/vcvars64.bat"
    compiler = Path(inventory["selected_future_primary"]["compiler_path"])
    librarian = Path(inventory["selected_future_primary"]["librarian_path"])
    subprocess.run([str(compiler), "/nologo", "/c", "/TC", "/std:c11", "/O2", "/W4", "/WX",
                    f"/I{ROOT / 'static-core/internal'}", f"/I{ROOT / 'runtime/include'}",
                    f"/Fo{msvc_dir / 'theme_park_bus.obj'}", str(BUS_SOURCE)],
                   cwd=msvc_dir, env=msvc_environment(vcvars), check=True)
    msvc_objects = [V07_BUILD / "msvc" / f"{path.stem}.obj" for path in sources]
    msvc_objects.append(msvc_dir / "theme_park_bus.obj")
    if any(not path.is_file() for path in msvc_objects):
        raise ValueError("sealed 07C MSVC object set is incomplete")
    write_rsp(msvc_dir / "library.rsp", [str(path) for path in msvc_objects])
    msvc_library = msvc_dir / "theme_park_v08c.lib"
    subprocess.run([str(librarian), "/NOLOGO", f"/OUT:{msvc_library}", f"@{msvc_dir / 'library.rsp'}"],
                   cwd=msvc_dir, check=True)

    gcc_dir = BUILD / "gcc"
    gcc_dir.mkdir(parents=True, exist_ok=True)
    gcc = Path(inventory["selected_future_secondary"]["path"])
    archiver = Path(inventory["selected_future_secondary"]["archiver"])
    gcc_object = gcc_dir / "theme_park_bus.o"
    subprocess.run([str(gcc), "-c", "-std=c11", "-O2", "-Wall", "-Wextra", "-Werror",
                    f"-I{ROOT / 'static-core/internal'}", f"-I{ROOT / 'runtime/include'}",
                    "-o", str(gcc_object), str(BUS_SOURCE)], cwd=gcc_dir, check=True)
    gcc_objects = [V07_BUILD / "gcc" / f"{path.stem}.o" for path in sources]
    gcc_objects.append(gcc_object)
    if any(not path.is_file() for path in gcc_objects):
        raise ValueError("sealed 07C GCC object set is incomplete")
    write_rsp(gcc_dir / "library.rsp", [str(path) for path in gcc_objects])
    gcc_library = gcc_dir / "libtheme_park_v08c.a"
    subprocess.run([str(archiver), "rcs", str(gcc_library), f"@{gcc_dir / 'library.rsp'}"],
                   cwd=gcc_dir, check=True)

    executables = list(BUILD.rglob("*.exe"))
    if executables:
        raise AssertionError(f"forbidden executable products: {executables}")
    receipt = {
        "schema": "theme-park-v08c-static-compile-v1",
        "status": "PASS_COMPLETE_07C_PLUS_08C_BUS_STATIC_LIBRARIES_NO_EXECUTABLE",
        "contexts": 71986, "source_files": 673, "executables_created": 0,
        "msvc": {"objects": 673, "library": str(msvc_library.relative_to(ROOT)).replace("\\", "/"),
                 "library_sha256": sha(msvc_library)},
        "gcc": {"objects": 673, "library": str(gcc_library.relative_to(ROOT)).replace("\\", "/"),
                "library_sha256": sha(gcc_library)},
        "inputs_sha256": {"v07_receipt": sha(ROOT / "docs/V07C-static-compile-receipt.json"),
                          "bus_header": sha(ROOT / "runtime/include/theme_park_bus.h"),
                          "bus_source": sha(BUS_SOURCE),
                          "compiler_inventory": sha(ROOT / "config/compiler-inventory.json")},
    }
    (ROOT / "docs/V08C-static-compile-receipt.json").write_text(
        json.dumps(receipt, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps({"status": receipt["status"], "objects_per_toolchain": 673}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
