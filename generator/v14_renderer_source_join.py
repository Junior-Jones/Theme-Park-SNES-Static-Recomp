#!/usr/bin/env python3
"""Join Theme Park exact PPU producers to the reached 14C renderer domain."""
from __future__ import annotations
import csv,hashlib,json
from collections import defaultdict
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
EVENTS=ROOT/"docs/V11C-ppu-exact-register-events.csv"
MANIFEST=ROOT/"docs/V07C-production-manifest.csv"
OUTPUT=ROOT/"docs/V14C-renderer-source-domain.json"

def sha(p:Path)->str:return hashlib.sha256(p.read_bytes()).hexdigest()

def main()->int:
    contexts=list(csv.DictReader(MANIFEST.open(newline="",encoding="utf-8")))
    events=list(csv.DictReader(EVENTS.open(newline="",encoding="utf-8")))
    by_bank_pc={(int(r["Context"][:2],16),int(r["Context"][3:7],16)):r for r in contexts}
    values:dict[str,set[int]]=defaultdict(set); dynamic:dict[str,list[str]]=defaultdict(list)
    writes=defaultdict(int)
    for event in events:
        if event["Access"]!="WRITE":continue
        reg=event["Register"]; writes[reg]+=1
        bank=int(event["Context"][:2],16); pc=int(event["Context"][3:7],16)
        producer=by_bank_pc.get((bank,(pc-2)&0xffff))
        if producer and producer["Mnemonic"]=="LDA" and producer["Mode"]=="IMM_M" and len(bytes.fromhex(producer["Bytes"]))==2:
            values[reg].add(bytes.fromhex(producer["Bytes"])[1])
        else: dynamic[reg].append(event["Context"])
    expected={"$2101":{0x03},"$2105":{0x02,0x03},"$2107":{0x54,0x78},
              "$2108":{0x59},"$2109":{0x54},"$210B":{0x00,0x02},
              "$212C":{0x01,0x03,0x13},"$2130":{0x30},"$2132":{0xE0},"$2133":{0x00}}
    for reg,domain in expected.items():
        if values[reg]!=domain or dynamic.get(reg):
            raise ValueError(f"renderer domain mismatch {reg}: {values[reg]} dynamic={dynamic.get(reg)}")
    forbidden_reached=[reg for reg in ("$2123","$2124","$2125","$2126","$2127","$2128","$2129","$212A","$212B","$212D","$212E","$212F","$2131") if writes[reg]]
    if forbidden_reached:raise ValueError(f"unexpected window/subscreen/color-math writer: {forbidden_reached}")
    result={
      "schema":"theme-park-v14c-renderer-source-domain-v1","status":"CLOSED_SOURCE_DOMAIN",
      "inputs_sha256":{"events":sha(EVENTS),"contexts":sha(MANIFEST)},
      "exact_ppu_events":len(events),"exact_ppu_writes":sum(writes.values()),
      "proved_constant_domains":{reg:[f"${v:02X}" for v in sorted(domain)] for reg,domain in sorted(expected.items())},
      "dynamic_but_generically_implemented":{"$2100":"forced blank plus brightness 0..15","$2106":"mosaic size/layer mask",
          "$210D-$2112":"BG1/BG2/BG3 scroll","$2116-$2119":"VRAM upload addressing/data","$2121-$2122":"CGRAM upload addressing/data"},
      "display_modes":[2,3],"bg_layers":[1,2],"mode2_offset_per_tile":True,
      "mode3_depth":{"BG1":8,"BG2":4},"mode2_depth":{"BG1":4,"BG2":4},
      "obj_size_selector":0,"obj_small":"8x8","obj_large":"16x16",
      "main_screen_masks":["$01","$03","$13"],"subscreen_mask":"RESET_ZERO_NO_WRITER",
      "window_registers":"RESET_ZERO_NO_WRITER","color_math_enable":"RESET_ZERO_NO_$2131_WRITER",
      "direct_color":False,"overscan":False,"interlace":False,"extbg":False,"hires":False,
      "mode7_display":False,"mode7_register_use":"$211B/$211C hardware multiply only",
      "unreached_optional_writer_registers":forbidden_reached,
      "conservative_unresolved_ppu_intersections":5461,
      "authority":"SOURCE_EVENTS_AND_IMMEDIATE_PRODUCERS_ONLY_NO_ORACLE_NO_TRACE_PROMOTION"
    }
    OUTPUT.write_text(json.dumps(result,indent=2,sort_keys=True)+"\n",encoding="utf-8",newline="\n")
    print(json.dumps(result,indent=2,sort_keys=True));return 0
if __name__=="__main__":raise SystemExit(main())
