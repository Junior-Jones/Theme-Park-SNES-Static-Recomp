#!/usr/bin/env python3
"""Compile the closed 15C input owner into static libraries only."""
from __future__ import annotations
import argparse,json,subprocess
from pathlib import Path
from v13_compile_static import sha,write_rsp,msvc_environment

ROOT=Path(__file__).resolve().parents[1]
GENERATED=ROOT/"static-core/generated/scpu";TIMING=ROOT/"static-core/generated/timing"
BUILD=ROOT/"build/v15c-static"

def main()->int:
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--receipt-only",action="store_true",
                        help="rehash non-compiler evidence after verifying the complete object/library set")
    args=parser.parse_args()
    inventory=json.loads((ROOT/"config/compiler-inventory.json").read_text(encoding="utf-8"))
    domain=json.loads((ROOT/"docs/V15C-input-source-domain.json").read_text(encoding="utf-8"))
    if domain["status"]!="CLOSED_SOURCE_DOMAIN":raise ValueError("15C input domain is open")
    sources=[(ROOT/line).resolve() for line in (GENERATED/"tp_v07_sources.txt").read_text(encoding="utf-8").splitlines()]
    sources += [(ROOT/name).resolve() for name in (
      "runtime/src/theme_park_bus.c","runtime/src/theme_park_scheduler.c","runtime/src/theme_park_dma.c",
      "runtime/src/theme_park_ppu.c","runtime/src/theme_park_renderer.c","runtime/src/theme_park_apu.c",
      "runtime/src/theme_park_spc700.c","runtime/generated/theme_park_spc700_aot.c",
      "runtime/src/theme_park_input.c","runtime/src/theme_park_machine.c",
      "static-core/generated/timing/theme_park_v09_timing.c")]
    if len(sources)!=683 or any(not p.is_file() for p in sources):raise ValueError("15C source inventory incomplete")
    includes=[ROOT/"static-core/internal",GENERATED,TIMING,ROOT/"runtime/include"]
    paths={"source_domain":"docs/V15C-input-source-domain.json","input":"runtime/src/theme_park_input.c",
      "input_header":"runtime/include/theme_park_input.h","bus":"runtime/src/theme_park_bus.c",
      "scheduler":"runtime/src/theme_park_scheduler.c","scheduler_header":"runtime/include/theme_park_scheduler.h",
      "machine":"runtime/src/theme_park_machine.c","machine_header":"runtime/include/theme_park_machine.h",
      "target_contract":"config/target-contract.json","cartridge_profile":"docs/V01C-cartridge-profile.json"}
    inputs={key:sha(ROOT/value) for key,value in paths.items()}
    md=BUILD/"msvc";md.mkdir(parents=True,exist_ok=True);mo=[md/(p.stem+".obj") for p in sources];ml=md/"theme_park_v15c.lib"
    if not args.receipt_only:
        write_rsp(md/"compile.rsp",["/nologo","/c","/TC","/std:c11","/O2","/W4","/WX","/MP"]+[f"/I{p.resolve()}" for p in includes]+[str(p) for p in sources])
        vcvars=Path(inventory["selected_future_primary"]["installation"])/"VC/Auxiliary/Build/vcvars64.bat"
        subprocess.run([inventory["selected_future_primary"]["compiler_path"],f"@{md/'compile.rsp'}"],cwd=md,check=True,env=msvc_environment(vcvars))
        write_rsp(md/"library.rsp",[str(p) for p in mo]);subprocess.run([inventory["selected_future_primary"]["librarian_path"],"/NOLOGO",f"/OUT:{ml}",f"@{md/'library.rsp'}"],cwd=md,check=True)
    gd=BUILD/"gcc";gd.mkdir(parents=True,exist_ok=True);go=[gd/(p.stem+".o") for p in sources];gl=gd/"libtheme_park_v15c.a"
    if not args.receipt_only:
        write_rsp(gd/"compile.rsp",["-c","-std=c11","-O2","-Wall","-Wextra","-Werror"]+[f"-I{p.resolve()}" for p in includes]+[str(p) for p in sources])
        subprocess.run([inventory["selected_future_secondary"]["path"],f"@{gd/'compile.rsp'}"],cwd=gd,check=True)
        write_rsp(gd/"library.rsp",[str(p) for p in go]);subprocess.run([inventory["selected_future_secondary"]["archiver"],"rcs",str(gl),f"@{gd/'library.rsp'}"],cwd=gd,check=True)
    if any(not p.is_file() for p in mo+go) or not ml.is_file() or not gl.is_file():raise ValueError("15C static artifacts incomplete")
    if list(ROOT.rglob("*.exe")):raise AssertionError("forbidden executable product exists")
    receipt={"schema":"theme-park-v15c-static-compile-v1","status":"PASS_INPUT_TIMING_STATIC_LIBRARIES_NO_EXECUTABLE",
      "scpu_contexts":71986,"ssmp_contexts":1392,"source_files":len(sources),"executables_created":0,
      "msvc":{"objects":len(mo),"library":str(ml.relative_to(ROOT)).replace("\\","/"),"library_sha256":sha(ml)},
      "gcc":{"objects":len(go),"library":str(gl.relative_to(ROOT)).replace("\\","/"),"library_sha256":sha(gl)},
      "inputs_sha256":inputs,"compile_action":"REHASHED_NON_COMPILER_EVIDENCE_REUSED_COMPLETE_STATIC_LIBRARIES" if args.receipt_only else "COMPILED_ALL_OBJECTS_AND_STATIC_LIBRARIES"}
    (ROOT/"docs/V15C-static-compile-receipt.json").write_text(json.dumps(receipt,indent=2,sort_keys=True)+"\n",encoding="utf-8",newline="\n")
    print(json.dumps({"status":receipt["status"],"objects_per_toolchain":len(sources)},sort_keys=True));return 0
if __name__=="__main__":raise SystemExit(main())
