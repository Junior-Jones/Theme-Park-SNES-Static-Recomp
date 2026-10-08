#!/usr/bin/env python3
"""Close Theme Park's source-proved controller and persistence domain."""
from __future__ import annotations
import csv,hashlib,json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
EFFECTS=ROOT/"docs/V08C-source-memory-effects.csv"
MANIFEST=ROOT/"docs/V07C-production-manifest.csv"
TARGET=ROOT/"config/target-contract.json"
CARTRIDGE=ROOT/"docs/V01C-cartridge-profile.json"
OUTPUT=ROOT/"docs/V15C-input-source-domain.json"

def sha(path:Path)->str:return hashlib.sha256(path.read_bytes()).hexdigest()

def main()->int:
    effects=list(csv.DictReader(EFFECTS.open(newline="",encoding="utf-8")))
    contexts=list(csv.DictReader(MANIFEST.open(newline="",encoding="utf-8")))
    by_end:dict[tuple[int,int],list[dict[str,str]]]={}
    for row in contexts:
        bank=int(row["Context"][:2],16);pc=int(row["Context"][3:7],16)
        end=(pc+len(bytes.fromhex(row["Bytes"])))&0xffff
        by_end.setdefault((bank,end),[]).append(row)
    input_effects=[row for row in effects if row["Current_Owner"]=="15C_INPUT"]
    if {(r["Effective_Address"],r["Access"]) for r in input_effects}!={("00:4218","READ"),("00:4219","READ")}:
        raise ValueError("Theme Park exact input effect domain changed")
    nmitimen=[row for row in effects if row["Effective_Address"]=="00:4200" and row["Access"]=="WRITE"]
    values=set()
    for event in nmitimen:
        bank=int(event["Context"][:2],16);pc=int(event["Context"][3:7],16)
        producers=by_end.get((bank,pc),[])
        if any(r["Mnemonic"]=="STZ" for r in producers):values.add(0)
        for row in producers:
            raw=bytes.fromhex(row["Bytes"])
            if row["Mnemonic"]=="LDA" and row["Mode"]=="IMM_M" and len(raw)==2:values.add(raw[1])
    if values!={0x00,0x01,0x81}:raise ValueError(f"NMITIMEN source domain changed: {values}")
    cartridge=json.loads(CARTRIDGE.read_text(encoding="utf-8"))
    if cartridge["cartridge"]["header_declared_sram_bytes"]!=0:
        raise ValueError("zero-SRAM cartridge proof changed")
    result={
      "schema":"theme-park-v15c-input-source-domain-v1","status":"CLOSED_SOURCE_DOMAIN",
      "inputs_sha256":{"memory_effects":sha(EFFECTS),"contexts":sha(MANIFEST),"target_contract":sha(TARGET),"cartridge_profile":sha(CARTRIDGE)},
      "source_reached_input_effects":input_effects,"nmitimen_write_count":len(nmitimen),
      "nmitimen_proved_values":["$00","$01","$81"],"autojoy_enable_proved":True,
      "target_consumed_results":["$4218 JOY1 low","$4219 JOY1 high"],
      "manual_serial_surface":"GENERAL_STANDARD_PAD_$4016_$4017_REQUIRED_BY_15C",
      "controller_devices":["standard_pad_port_1","standard_pad_port_2"],
      "additional_devices":[],"autojoy_result_surface":"$4218-$421F",
      "report_layout":"B,Y,Select,Start,Up,Down,Left,Right,A,X,L,R at bits 15..4; signature bits 3..0 zero",
      "persistence":{"sram_bytes":0,"rtc":False,"special_persistent_device":False,
        "transition":"NO_TARGET_PERSISTENT_BYTES; SCPU_RESET_PRESERVES_EXTERNAL_LIVE_PAD_REPORTS_AND_CLEARS_GUEST_LATCH_SHIFT_AUTOJOY_STATE"},
      "deterministic_vectors":[
        {"name":"manual_two_pad","pad1":"$A550","pad2":"$5AA0","reads":16,
         "expected_serial_words":["$A550","$5AA0"]},
        {"name":"autojoy_two_pad","pad1":"$F0F0","pad2":"$0F00","phases":"0..34",
         "expected_auto_results":["$F0F0","$0F00","$0000","$0000"]},
        {"name":"reset_transition","pad1":"$8120","expected_live_after_reset":"$8120",
         "expected_shift_after_reset":"$8120","expected_auto_results":["$0000","$0000","$0000","$0000"]}
      ],
      "authority":"SOURCE_EFFECTS_AND_EXACT_CONTEXT_PREDECESSORS_ONLY_NO_ORACLE_NO_RUNTIME_TRACE"
    }
    OUTPUT.write_text(json.dumps(result,indent=2,sort_keys=True)+"\n",encoding="utf-8",newline="\n")
    print(json.dumps({"status":result["status"],"input_effects":len(input_effects),"nmitimen_writes":len(nmitimen)},sort_keys=True))
    return 0
if __name__=="__main__":raise SystemExit(main())
