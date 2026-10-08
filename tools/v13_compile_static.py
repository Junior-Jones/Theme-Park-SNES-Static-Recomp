#!/usr/bin/env python3
"""Compile the closed 13C exact-PC S-SMP core to static libraries only."""
from __future__ import annotations

import hashlib
import json
import os
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GENERATED = ROOT / "static-core/generated/scpu"
TIMING = ROOT / "static-core/generated/timing"
BUILD = ROOT / "build/v13c-static"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def write_rsp(path: Path, args: list[str]) -> None:
    path.write_text("\n".join(f'"{v}"' if " " in v else v for v in args)+"\n", encoding="utf-8", newline="\n")


def msvc_environment(vcvars: Path) -> dict[str, str]:
    result = subprocess.run(["cmd.exe","/d","/c","call",str(vcvars),">nul","&&","set"],
                            check=True,capture_output=True,text=True)
    env=os.environ.copy()
    for line in result.stdout.splitlines():
        if "=" in line:
            key,value=line.split("=",1); env[key]=value
    return env


def main() -> int:
    inventory=json.loads((ROOT/"config/compiler-inventory.json").read_text(encoding="utf-8"))
    discovery=json.loads((ROOT/"docs/V13C-spc700-discovery.json").read_text(encoding="utf-8"))
    aot=json.loads((ROOT/"docs/V13C-spc700-aot-generation.json").read_text(encoding="utf-8"))
    if discovery["status"]!="CLOSED" or discovery["instruction_contexts"]!=1392 or discovery["unresolved"]:
        raise ValueError("13C discovery authority is not closed")
    if aot["status"]!="CLOSED" or aot["runtime_decoder"] or aot["runtime_fallback"]:
        raise ValueError("13C AOT authority is not closed/static")
    sources=[(ROOT/line).resolve() for line in (GENERATED/"tp_v07_sources.txt").read_text(encoding="utf-8").splitlines()]
    sources += [(ROOT/name).resolve() for name in (
        "runtime/src/theme_park_bus.c","runtime/src/theme_park_scheduler.c",
        "runtime/src/theme_park_dma.c","runtime/src/theme_park_ppu.c",
        "runtime/src/theme_park_apu.c","runtime/src/theme_park_spc700.c",
        "runtime/generated/theme_park_spc700_aot.c","runtime/src/theme_park_machine.c",
        "static-core/generated/timing/theme_park_v09_timing.c")]
    if len(sources)!=681 or any(not p.is_file() for p in sources):
        raise ValueError(f"13C source inventory incomplete ({len(sources)})")
    includes=[ROOT/"static-core/internal",GENERATED,TIMING,ROOT/"runtime/include"]
    input_paths={
        "discovery":"docs/V13C-spc700-discovery.json","aot_receipt":"docs/V13C-spc700-aot-generation.json",
        "apu":"runtime/src/theme_park_apu.c","apu_header":"runtime/include/theme_park_apu.h",
        "semantic_helpers":"runtime/src/theme_park_spc700.c","semantic_header":"runtime/include/theme_park_spc700.h",
        "aot_source":"runtime/generated/theme_park_spc700_aot.c","aot_header":"runtime/include/theme_park_spc700_aot.h"}
    inputs={key:sha(ROOT/value) for key,value in input_paths.items()}

    msvc_dir=BUILD/"msvc"; msvc_dir.mkdir(parents=True,exist_ok=True)
    msvc_objects=[msvc_dir/(p.stem+".obj") for p in sources]
    msvc_library=msvc_dir/"theme_park_v13c.lib"
    write_rsp(msvc_dir/"compile.rsp",["/nologo","/c","/TC","/std:c11","/O2","/W4","/WX","/MP"]+
              [f"/I{p.resolve()}" for p in includes]+[str(p) for p in sources])
    vcvars=Path(inventory["selected_future_primary"]["installation"])/"VC/Auxiliary/Build/vcvars64.bat"
    compiler=Path(inventory["selected_future_primary"]["compiler_path"])
    librarian=Path(inventory["selected_future_primary"]["librarian_path"])
    subprocess.run([str(compiler),f"@{msvc_dir/'compile.rsp'}"],cwd=msvc_dir,check=True,env=msvc_environment(vcvars))
    write_rsp(msvc_dir/"library.rsp",[str(p) for p in msvc_objects])
    subprocess.run([str(librarian),"/NOLOGO",f"/OUT:{msvc_library}",f"@{msvc_dir/'library.rsp'}"],cwd=msvc_dir,check=True)

    gcc_dir=BUILD/"gcc"; gcc_dir.mkdir(parents=True,exist_ok=True)
    gcc=Path(inventory["selected_future_secondary"]["path"])
    archiver=Path(inventory["selected_future_secondary"]["archiver"])
    gcc_objects=[gcc_dir/(p.stem+".o") for p in sources]
    gcc_library=gcc_dir/"libtheme_park_v13c.a"
    write_rsp(gcc_dir/"compile.rsp",["-c","-std=c11","-O2","-Wall","-Wextra","-Werror"]+
              [f"-I{p.resolve()}" for p in includes]+[str(p) for p in sources])
    subprocess.run([str(gcc),f"@{gcc_dir/'compile.rsp'}"],cwd=gcc_dir,check=True)
    write_rsp(gcc_dir/"library.rsp",[str(p) for p in gcc_objects])
    subprocess.run([str(archiver),"rcs",str(gcc_library),f"@{gcc_dir/'library.rsp'}"],cwd=gcc_dir,check=True)
    if any(not p.is_file() for p in msvc_objects+gcc_objects) or not msvc_library.is_file() or not gcc_library.is_file():
        raise ValueError("13C static artifacts incomplete")
    if list(ROOT.rglob("*.exe")):
        raise AssertionError("forbidden executable product exists")
    receipt={"schema":"theme-park-v13c-static-compile-v1",
             "status":"PASS_STATIC_SSMP_AOT_LIBRARIES_NO_EXECUTABLE",
             "scpu_contexts":71986,"ssmp_contexts":1392,"source_files":len(sources),"executables_created":0,
             "msvc":{"objects":len(msvc_objects),"library":str(msvc_library.relative_to(ROOT)).replace("\\","/"),"library_sha256":sha(msvc_library)},
             "gcc":{"objects":len(gcc_objects),"library":str(gcc_library.relative_to(ROOT)).replace("\\","/"),"library_sha256":sha(gcc_library)},
             "inputs_sha256":inputs,"compile_action":"COMPILED_ALL_OBJECTS_AND_STATIC_LIBRARIES"}
    (ROOT/"docs/V13C-static-compile-receipt.json").write_text(json.dumps(receipt,indent=2,sort_keys=True)+"\n",encoding="utf-8",newline="\n")
    print(json.dumps({"status":receipt["status"],"objects_per_toolchain":len(sources)},sort_keys=True))
    return 0


if __name__=="__main__": raise SystemExit(main())
