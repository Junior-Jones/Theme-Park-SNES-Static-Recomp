#!/usr/bin/env python3
"""Compile the complete closed 07C source surface into static libraries only."""
from __future__ import annotations

import hashlib
import json
import os
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
GENERATED = ROOT / "static-core/generated/scpu"
BUILD = ROOT / "build/v07c-static"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def write_rsp(path: Path, arguments: list[str]) -> None:
    path.write_text("\n".join(f'"{item}"' if " " in item else item for item in arguments) + "\n",
                    encoding="utf-8", newline="\n")


def run(command: list[str], cwd: Path) -> None:
    subprocess.run(command, cwd=cwd, check=True)


def msvc_environment(vcvars: Path) -> dict[str, str]:
    result = subprocess.run(
        ["cmd.exe", "/d", "/c", "call", str(vcvars), ">nul", "&&", "set"],
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
    selection = json.loads((ROOT / "docs/V07C-selected-families.json").read_text(encoding="utf-8"))
    admission = json.loads((ROOT / "docs/V07C-selected-family-admission.json").read_text(encoding="utf-8"))
    if (generation["context_count"] != 71986 or selection["unique_context_count"] != 71986 or
            admission["admitted_contexts"] != 71986 or len(generation["family_ids"]) != 513):
        raise ValueError("complete 07C source gate is not closed")
    if generation["compiled_sources"]:
        raise ValueError("generation manifest must remain a source-generation receipt")
    sources = [(ROOT / line).resolve() for line in
               (GENERATED / "tp_v07_sources.txt").read_text(encoding="utf-8").splitlines()]
    if len(sources) != 672 or any(not path.is_file() for path in sources):
        raise ValueError("07C source inventory changed")
    BUILD.mkdir(parents=True, exist_ok=True)
    include_args = [f"/I{(ROOT / 'static-core/internal').resolve()}",
                    f"/I{GENERATED.resolve()}"]

    msvc_dir = BUILD / "msvc"
    msvc_dir.mkdir(exist_ok=True)
    msvc_rsp = msvc_dir / "compile.rsp"
    write_rsp(msvc_rsp, ["/nologo", "/c", "/TC", "/std:c11", "/O2", "/W4", "/WX", "/MP"] +
              include_args + [str(path) for path in sources])
    vcvars = (Path(inventory["selected_future_primary"]["installation"]) /
              "VC/Auxiliary/Build/vcvars64.bat")
    compiler = Path(inventory["selected_future_primary"]["compiler_path"])
    librarian = Path(inventory["selected_future_primary"]["librarian_path"])
    subprocess.run([str(compiler), f"@{msvc_rsp}"], cwd=msvc_dir, check=True,
                   env=msvc_environment(vcvars))
    msvc_objects = [msvc_dir / (path.stem + ".obj") for path in sources]
    if any(not path.is_file() for path in msvc_objects):
        raise ValueError("MSVC did not emit the complete object set")
    msvc_lib_rsp = msvc_dir / "library.rsp"
    write_rsp(msvc_lib_rsp, [str(path) for path in msvc_objects])
    msvc_library = msvc_dir / "theme_park_v07c.lib"
    run([str(librarian), "/NOLOGO", f"/OUT:{msvc_library}", f"@{msvc_lib_rsp}"], msvc_dir)

    gcc_dir = BUILD / "gcc"
    gcc_dir.mkdir(exist_ok=True)
    gcc = Path(inventory["selected_future_secondary"]["path"])
    archiver = Path(inventory["selected_future_secondary"]["archiver"])
    gcc_rsp = gcc_dir / "compile.rsp"
    write_rsp(gcc_rsp, ["-c", "-std=c11", "-O2", "-Wall", "-Wextra", "-Werror",
                        f"-I{(ROOT / 'static-core/internal').resolve()}", f"-I{GENERATED.resolve()}"] +
              [str(path) for path in sources])
    run([str(gcc), f"@{gcc_rsp}"], gcc_dir)
    gcc_objects = [gcc_dir / (path.stem + ".o") for path in sources]
    if any(not path.is_file() for path in gcc_objects):
        raise ValueError("GCC did not emit the complete object set")
    gcc_lib_rsp = gcc_dir / "library.rsp"
    write_rsp(gcc_lib_rsp, [str(path) for path in gcc_objects])
    gcc_library = gcc_dir / "libtheme_park_v07c.a"
    run([str(archiver), "rcs", str(gcc_library), f"@{gcc_lib_rsp}"], gcc_dir)

    executables = list(BUILD.rglob("*.exe"))
    if executables:
        raise AssertionError(f"forbidden executable products: {executables}")
    receipt = {
        "schema": "theme-park-v07c-static-compile-v1",
        "status": "PASS_COMPLETE_07C_OBJECTS_AND_STATIC_LIBRARIES_NO_EXECUTABLE",
        "families": 513,
        "contexts": 71986,
        "source_files": len(sources),
        "linked_contexts": 0,
        "executables_created": 0,
        "msvc": {"objects": len(msvc_objects), "library": str(msvc_library.relative_to(ROOT)).replace("\\", "/"),
                 "library_sha256": sha(msvc_library)},
        "gcc": {"objects": len(gcc_objects), "library": str(gcc_library.relative_to(ROOT)).replace("\\", "/"),
                "library_sha256": sha(gcc_library)},
        "inputs_sha256": {
            "generation_manifest": sha(GENERATED / "V07C-generation-manifest.json"),
            "production_manifest": sha(ROOT / "docs/V07C-production-manifest.csv"),
            "selected_families": sha(ROOT / "docs/V07C-selected-families.json"),
            "compiler_inventory": sha(ROOT / "config/compiler-inventory.json"),
        },
    }
    receipt_path = ROOT / "docs/V07C-static-compile-receipt.json"
    receipt_path.write_text(json.dumps(receipt, indent=2, sort_keys=True) + "\n",
                            encoding="utf-8", newline="\n")
    print(json.dumps({"status": receipt["status"], "sources": len(sources),
                      "msvc_objects": len(msvc_objects), "gcc_objects": len(gcc_objects)},
                     sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
