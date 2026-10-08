#!/usr/bin/env python3
"""Generate Theme Park's exact-PC static SPC700 bodies from closed source proof."""
from __future__ import annotations

import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DISCOVERY = ROOT / "docs/V13C-spc700-discovery.json"
HEADER = ROOT / "runtime/include/theme_park_spc700_aot.h"
SOURCE = ROOT / "runtime/generated/theme_park_spc700_aot.c"
RECEIPT = ROOT / "docs/V13C-spc700-aot-generation.json"

# Architectural base cycles.  Conditional relative branches add two when taken.
OP_CYCLES = (
    2,8,4,5,3,4,3,6,2,6,5,4,5,4,6,8, 2,8,4,5,4,5,5,6,5,5,6,5,2,2,4,6,
    2,8,4,5,3,4,3,6,2,6,5,4,5,4,5,4, 2,8,4,5,4,5,5,6,5,5,6,5,2,2,3,8,
    2,8,4,5,3,4,3,6,2,6,4,4,5,4,6,6, 2,8,4,5,4,5,5,6,5,5,4,5,2,2,4,3,
    2,8,4,5,3,4,3,6,2,6,4,4,5,4,5,5, 2,8,4,5,4,5,5,6,5,5,5,5,2,2,3,6,
    2,8,4,5,3,4,3,6,2,6,5,4,5,2,4,5, 2,8,4,5,4,5,5,6,5,5,5,5,2,2,12,5,
    3,8,4,5,3,4,3,6,2,6,4,4,5,2,4,4, 2,8,4,5,4,5,5,6,5,5,5,5,2,2,3,4,
    3,8,4,5,4,5,4,7,2,5,6,4,5,2,4,9, 2,8,4,5,5,6,6,7,4,5,4,5,2,2,6,3,
    2,8,4,5,3,4,3,6,2,4,5,3,4,3,4,3, 2,8,4,5,4,5,5,6,3,4,5,4,2,2,4,3,
)
COND = {0x10: "!(s->psw & TP_SPC_N)", 0x30: "s->psw & TP_SPC_N",
        0x90: "!(s->psw & TP_SPC_C)", 0xB0: "s->psw & TP_SPC_C",
        0xD0: "!(s->psw & TP_SPC_Z)", 0xF0: "s->psw & TP_SPC_Z"}
SUPPORTED = {0x04,0x08,0x0B,0x10,0x1C,0x1D,0x1F,0x20,0x28,0x2D,0x2F,0x30,
             0x3C,0x3D,0x3F,0x48,0x4D,0x5C,0x5D,0x5F,0x60,0x64,0x68,0x6B,
             0x6D,0x6F,0x74,0x76,0x7A,0x80,0x84,0x88,0x8B,0x8D,0x8F,0x90,
             0x97,0x98,0x9C,0x9F,0xA4,0xA8,0xAB,0xAD,0xAE,0xB0,0xB7,0xB8,
             0xBA,0xBC,0xC4,0xC8,0xCB,0xCD,0xCE,0xCF,0xD0,0xD4,0xD5,0xD6,
             0xD7,0xD8,0xDA,0xDC,0xDD,0xE4,0xE8,0xEB,0xEE,0xF0,0xF4,0xF5,
             0xF6,0xF7,0xF8,0xFA,0xFC,0xFD}
TABLES = {0x0382: (0x0454, 21), 0x088F: (0x0A51, 16), 0x0B7B: (0x0C30, 16)}


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def u16(raw: bytes) -> int:
    return raw[1] | raw[2] << 8


def rel(pc: int, raw: bytes) -> int:
    value = raw[-1] - 256 if raw[-1] >= 128 else raw[-1]
    return (pc + len(raw) + value) & 0xFFFF


def semantics(pc: int, raw: bytes) -> list[str]:
    op, n = raw[0], (pc + len(raw)) & 0xFFFF
    dp = f"tp_spc_dp(a, 0x{raw[1]:02X}u)" if len(raw) > 1 else "0u"
    absolute = f"0x{u16(raw):04X}u" if len(raw) > 2 else "0u"
    L: list[str] = []
    if op == 0x04: L += [f"R({dp}, v);", "s->a |= v; tp_spc_nz8(a,s->a);"]
    elif op == 0x08: L += [f"s->a |= 0x{raw[1]:02X}u; tp_spc_nz8(a,s->a);"]
    elif op == 0x0B: L += [f"R({dp}, v); v=tp_spc_asl8(a,v); W({dp},v);"]
    elif op in COND: L += [f"if(s->active_branch_taken) s->pc=0x{rel(pc,raw):04X}u;"]
    elif op == 0x1C: L += ["s->a=tp_spc_asl8(a,s->a);"]
    elif op == 0x1D: L += ["--s->x; tp_spc_nz8(a,s->x);"]
    elif op == 0x1F:
        base, count = TABLES[pc]
        L += [f"if((s->x & 1u)!=0u || s->x>{2*(count-1)}u) return tp_spc_fail(a);",
              f"R16((uint16_t)(0x{base:04X}u+s->x), w);", "switch(s->x) {"]
        # Targets are checked against the source-owned table at generation time.
        discovery = json.loads(DISCOVERY.read_text(encoding="utf-8"))
        aram = reconstruct_aram(discovery)
        for i in range(count):
            target = aram[base+i*2] | aram[base+i*2+1] << 8
            L += [f"case {i*2}u: if(w!=0x{target:04X}u) return tp_spc_fail(a); s->pc=0x{target:04X}u; break;"]
        L += ["default: return tp_spc_fail(a);", "}"]
    elif op == 0x20: L += ["tp_spc_clear_flags(a,TP_SPC_P);"]
    elif op == 0x28: L += [f"s->a &= 0x{raw[1]:02X}u; tp_spc_nz8(a,s->a);"]
    elif op == 0x2D: L += ["if(!tp_spc_push(a,s->a)) return 0;"]
    elif op == 0x2F: L += [f"s->pc=0x{rel(pc,raw):04X}u;"]
    elif op == 0x3C: L += ["s->a=tp_spc_rol8(a,s->a);"]
    elif op == 0x3D: L += ["++s->x; tp_spc_nz8(a,s->x);"]
    elif op == 0x3F: L += ["if(s->return_depth>=256u)return tp_spc_fail(a);",
                           f"if(!tp_spc_push(a,0x{n>>8:02X}u)||!tp_spc_push(a,0x{n&255:02X}u)) return 0;",
                           f"s->return_pc[s->return_depth++]=0x{n:04X}u;", f"s->pc={absolute};"]
    elif op == 0x48: L += [f"s->a ^= 0x{raw[1]:02X}u; tp_spc_nz8(a,s->a);"]
    elif op == 0x4D: L += ["if(!tp_spc_push(a,s->x)) return 0;"]
    elif op == 0x5C: L += ["s->a=tp_spc_lsr8(a,s->a);"]
    elif op == 0x5D: L += ["s->x=s->a; tp_spc_nz8(a,s->x);"]
    elif op == 0x5F: L += [f"s->pc={absolute};"]
    elif op == 0x60: L += ["tp_spc_clear_flags(a,TP_SPC_C);"]
    elif op == 0x64: L += [f"R({dp},v); tp_spc_cmp8(a,s->a,v);"]
    elif op == 0x68: L += [f"tp_spc_cmp8(a,s->a,0x{raw[1]:02X}u);"]
    elif op == 0x6B: L += [f"R({dp},v); v=tp_spc_ror8(a,v); W({dp},v);"]
    elif op == 0x6D: L += ["if(!tp_spc_push(a,s->y)) return 0;"]
    elif op == 0x6F: L += ["if(s->return_depth==0u)return tp_spc_fail(a);",
                           "if(!tp_spc_pop(a,&lo)||!tp_spc_pop(a,&hi)) return 0; w=(uint16_t)(lo|((uint16_t)hi<<8u));",
                           "if(w!=s->return_pc[--s->return_depth])return tp_spc_fail(a);s->pc=w;"]
    elif op == 0x74: L += [f"R(tp_spc_dp(a,(uint8_t)(0x{raw[1]:02X}u+s->x)),v); tp_spc_cmp8(a,s->a,v);"]
    elif op == 0x76: L += [f"R((uint16_t)({absolute}+s->y),v); tp_spc_cmp8(a,s->a,v);"]
    elif op == 0x7A: L += [f"R16DP(0x{raw[1]:02X}u,w); w=tp_spc_addw(a,(uint16_t)(s->a|((uint16_t)s->y<<8u)),w); s->a=(uint8_t)w; s->y=(uint8_t)(w>>8u);"]
    elif op == 0x80: L += ["s->psw |= TP_SPC_C;"]
    elif op == 0x84: L += [f"R({dp},v); s->a=tp_spc_adc8(a,s->a,v);"]
    elif op == 0x88: L += [f"s->a=tp_spc_adc8(a,s->a,0x{raw[1]:02X}u);"]
    elif op == 0x8B: L += [f"R({dp},v); --v; tp_spc_nz8(a,v); W({dp},v);"]
    elif op == 0x8D: L += [f"s->y=0x{raw[1]:02X}u; tp_spc_nz8(a,s->y);"]
    elif op == 0x8F: L += [f"W(tp_spc_dp(a,0x{raw[2]:02X}u),0x{raw[1]:02X}u);"]
    elif op == 0x97: L += [f"R16DP(0x{raw[1]:02X}u,w); R((uint16_t)(w+s->y),v); s->a=tp_spc_adc8(a,s->a,v);"]
    elif op == 0x98: L += [f"R(tp_spc_dp(a,0x{raw[2]:02X}u),v); v=tp_spc_adc8(a,v,0x{raw[1]:02X}u); W(tp_spc_dp(a,0x{raw[2]:02X}u),v);"]
    elif op == 0x9C: L += ["--s->a; tp_spc_nz8(a,s->a);"]
    elif op == 0x9F: L += ["s->a=(uint8_t)((s->a<<4u)|(s->a>>4u)); tp_spc_nz8(a,s->a);"]
    elif op == 0xA4: L += [f"R({dp},v); s->a=tp_spc_sbc8(a,s->a,v);"]
    elif op == 0xA8: L += [f"s->a=tp_spc_sbc8(a,s->a,0x{raw[1]:02X}u);"]
    elif op == 0xAB: L += [f"R({dp},v); ++v; tp_spc_nz8(a,v); W({dp},v);"]
    elif op == 0xAD: L += [f"tp_spc_cmp8(a,s->y,0x{raw[1]:02X}u);"]
    elif op == 0xAE: L += ["if(!tp_spc_pop(a,&s->a)) return 0; tp_spc_nz8(a,s->a);"]
    elif op == 0xB7: L += [f"R16DP(0x{raw[1]:02X}u,w); R((uint16_t)(w+s->y),v); s->a=tp_spc_sbc8(a,s->a,v);"]
    elif op == 0xB8: L += [f"R(tp_spc_dp(a,0x{raw[2]:02X}u),v); v=tp_spc_sbc8(a,v,0x{raw[1]:02X}u); W(tp_spc_dp(a,0x{raw[2]:02X}u),v);"]
    elif op == 0xBA: L += [f"R16DP(0x{raw[1]:02X}u,w); s->a=(uint8_t)w; s->y=(uint8_t)(w>>8u); tp_spc_nz16(a,w);"]
    elif op == 0xBC: L += ["++s->a; tp_spc_nz8(a,s->a);"]
    elif op == 0xC4: L += [f"W({dp},s->a);"]
    elif op == 0xC8: L += [f"tp_spc_cmp8(a,s->x,0x{raw[1]:02X}u);"]
    elif op == 0xCB: L += [f"W({dp},s->y);"]
    elif op == 0xCD: L += [f"s->x=0x{raw[1]:02X}u; tp_spc_nz8(a,s->x);"]
    elif op == 0xCE: L += ["if(!tp_spc_pop(a,&s->x)) return 0; tp_spc_nz8(a,s->x);"]
    elif op == 0xCF: L += ["w=(uint16_t)s->a*s->y; s->a=(uint8_t)w; s->y=(uint8_t)(w>>8u); tp_spc_nz8(a,s->y);"]
    elif op == 0xD4: L += [f"W(tp_spc_dp(a,(uint8_t)(0x{raw[1]:02X}u+s->x)),s->a);"]
    elif op == 0xD5: L += [f"W((uint16_t)({absolute}+s->x),s->a);"]
    elif op == 0xD6: L += [f"W((uint16_t)({absolute}+s->y),s->a);"]
    elif op == 0xD7: L += [f"R16DP(0x{raw[1]:02X}u,w); W((uint16_t)(w+s->y),s->a);"]
    elif op == 0xD8: L += [f"W({dp},s->x);"]
    elif op == 0xDA: L += [f"W({dp},s->a); W(tp_spc_dp(a,(uint8_t)(0x{raw[1]:02X}u+1u)),s->y);"]
    elif op == 0xDC: L += ["--s->y; tp_spc_nz8(a,s->y);"]
    elif op == 0xDD: L += ["s->a=s->y; tp_spc_nz8(a,s->a);"]
    elif op == 0xE4: L += [f"R({dp},s->a); tp_spc_nz8(a,s->a);"]
    elif op == 0xE8: L += [f"s->a=0x{raw[1]:02X}u; tp_spc_nz8(a,s->a);"]
    elif op == 0xEB: L += [f"R({dp},s->y); tp_spc_nz8(a,s->y);"]
    elif op == 0xEE: L += ["if(!tp_spc_pop(a,&s->y)) return 0; tp_spc_nz8(a,s->y);"]
    elif op == 0xF4: L += [f"R(tp_spc_dp(a,(uint8_t)(0x{raw[1]:02X}u+s->x)),s->a); tp_spc_nz8(a,s->a);"]
    elif op == 0xF5: L += [f"R((uint16_t)({absolute}+s->x),s->a); tp_spc_nz8(a,s->a);"]
    elif op == 0xF6: L += [f"R((uint16_t)({absolute}+s->y),s->a); tp_spc_nz8(a,s->a);"]
    elif op == 0xF7: L += [f"R16DP(0x{raw[1]:02X}u,w); R((uint16_t)(w+s->y),s->a); tp_spc_nz8(a,s->a);"]
    elif op == 0xF8: L += [f"R({dp},s->x); tp_spc_nz8(a,s->x);"]
    elif op == 0xFA: L += [f"R(tp_spc_dp(a,0x{raw[1]:02X}u),v); W(tp_spc_dp(a,0x{raw[2]:02X}u),v);"]
    elif op == 0xFC: L += ["++s->y; tp_spc_nz8(a,s->y);"]
    elif op == 0xFD: L += ["s->y=s->a; tp_spc_nz8(a,s->y);"]
    else: raise ValueError(f"unemitted opcode ${op:02X} at ${pc:04X}")
    return L


def reconstruct_aram(report: dict) -> bytearray:
    # Discovery receipts bind each upload payload; the target ROM is read only here.
    contract = json.loads((ROOT / "config/target-contract.json").read_text(encoding="utf-8"))
    rom_path = ROOT.parents[1] / "Theme Park (Europe) (En,Fr,De).sfc"
    rom = rom_path.read_bytes()
    if hashlib.sha256(rom).hexdigest() != contract["supported_rom_sha256"]:
        raise ValueError("Theme Park ROM identity mismatch")
    aram = bytearray(65536)
    cursor = 0x70313
    for record in report["upload_records"]:
        size = int.from_bytes(rom[cursor:cursor+2], "little")
        dest = int.from_bytes(rom[cursor+2:cursor+4], "little")
        payload = rom[cursor+4:cursor+4+size]
        if size != record["size"] or dest != record["destination"] or hashlib.sha256(payload).hexdigest() != record["payload_sha256"]:
            raise ValueError("upload receipt mismatch")
        aram[dest:dest+size] = payload
        cursor += 4 + size
    return aram


def main() -> int:
    report = json.loads(DISCOVERY.read_text(encoding="utf-8"))
    if report["status"] != "CLOSED" or report["oracle_promotions"] or report["trace_promotions"]:
        raise ValueError("discovery is not closed source-only authority")
    rows = []
    used = set()
    bitmap = bytearray(8192)
    for row in report["contexts"]:
        pc, raw = int(row["pc"][1:], 16), bytes.fromhex(row["bytes"])
        used.add(raw[0]); rows.append((pc, raw))
        for off in range(len(raw)):
            address = (pc + off) & 0xFFFF
            bitmap[address >> 3] |= 1 << (address & 7)
    instruction_bytes = sum(x.bit_count() for x in bitmap)
    # Indirect jump words are immutable control-flow authority even though they
    # are data rather than instruction starts.  Protect them in the same epoch.
    for base, count in TABLES.values():
        for address in range(base, base + count * 2):
            bitmap[address >> 3] |= 1 << (address & 7)
    if used != SUPPORTED:
        raise ValueError(f"semantic set mismatch: missing={sorted(used-SUPPORTED)} extra={sorted(SUPPORTED-used)}")

    header = """#ifndef THEME_PARK_SPC700_AOT_H\n#define THEME_PARK_SPC700_AOT_H\n#include <stdint.h>\n#include \"theme_park_apu.h\"\nint tp_spc700_aot_begin(TPApu *apu);\nint tp_spc700_aot_complete(TPApu *apu);\nint tp_spc700_aot_code_byte(uint16_t address);\n#endif\n"""
    out = ["/* Generated exact-PC Theme Park SPC700 authority. No runtime decoder. */\n",
           '#include "theme_park_spc700_aot.h"\n#include "theme_park_spc700.h"\n\n',
           "static const uint8_t tp_spc_code_bitmap[8192] = {\n"]
    for start in range(0, 8192, 16):
        out.append("  " + ",".join(f"0x{x:02X}u" for x in bitmap[start:start+16]) + ",\n")
    out += ["};\nint tp_spc700_aot_code_byte(uint16_t a){return (tp_spc_code_bitmap[a>>3u]&(1u<<(a&7u)))!=0u;}\n",
            "int tp_spc700_aot_begin(TPApu *a){TPSpc700State *s=&a->spc; switch(s->pc){\n"]
    for pc, raw in rows:
        expected = ",".join(f"0x{x:02X}u" for x in raw)
        branch = COND.get(raw[0])
        out += [f"case 0x{pc:04X}u:{{static const uint8_t e[]={{{expected}}}; if(!tp_spc_guard(a,0x{pc:04X}u,e,{len(raw)}u))return 0; ",
                f"s->active_pc=0x{pc:04X}u;s->pc=0x{(pc+len(raw))&0xffff:04X}u;s->active_branch_taken=0u;"]
        if branch:
            out += [f"s->active_branch_taken=(uint8_t)(({branch})!=0u);"]
        out += [f"s->active_cycles_remaining={OP_CYCLES[raw[0]]}u+(s->active_branch_taken?2u:0u);s->active=1u;return 1;}}\n"]
    out += ["default:return tp_spc_fail(a);}}\n",
            "#define R(addr,dst) do{if(!tp_spc_read(a,(uint16_t)(addr),&(dst)))return 0;}while(0)\n",
            "#define W(addr,val) do{if(!tp_spc_write(a,(uint16_t)(addr),(uint8_t)(val)))return 0;}while(0)\n",
            "#define R16(addr,dst) do{R((addr),lo);R((uint16_t)((addr)+1u),hi);(dst)=(uint16_t)(lo|((uint16_t)hi<<8u));}while(0)\n",
            "#define R16DP(addr,dst) do{if(!tp_spc_read_dp_word(a,(uint8_t)(addr),&(dst)))return 0;}while(0)\n",
            "int tp_spc700_aot_complete(TPApu *a){TPSpc700State *s=&a->spc;uint8_t v=0u,lo=0u,hi=0u;uint16_t w=0u;if(!s->active||s->active_cycles_remaining)return tp_spc_fail(a);switch(s->active_pc){\n"]
    for pc, raw in rows:
        out += [f"case 0x{pc:04X}u:"]
        for statement in semantics(pc, raw):
            out += [statement]
        out += ["break;\n"]
    out += ["default:return tp_spc_fail(a);}s->active=0u;s->instructions++;return 1;}\n",
            "#undef R\n#undef W\n#undef R16\n#undef R16DP\n"]
    HEADER.parent.mkdir(parents=True, exist_ok=True)
    SOURCE.parent.mkdir(parents=True, exist_ok=True)
    HEADER.write_text(header, encoding="utf-8", newline="\n")
    SOURCE.write_text("".join(out), encoding="utf-8", newline="\n")
    receipt = {"schema":"theme-park-v13c-spc700-aot-v1", "status":"CLOSED",
               "authority":DISCOVERY.name, "authority_sha256":sha(DISCOVERY),
               "exact_pc_contexts":len(rows), "instruction_bytes":instruction_bytes,
               "protected_control_flow_bytes":sum(x.bit_count() for x in bitmap),
               "used_opcode_forms":len(used), "used_opcodes":[f"{x:02X}" for x in sorted(used)],
               "source_only":True, "oracle_promotions":0, "trace_promotions":0,
               "runtime_decoder":False, "runtime_fallback":False,
               "unknown_pc":"FAIL_CLOSED", "changed_instruction_byte":"FAIL_CLOSED",
               "owned_code_write":"FAIL_CLOSED_NEW_EPOCH_REQUIRED",
               "header_sha256":sha(HEADER), "source_sha256":sha(SOURCE)}
    RECEIPT.write_text(json.dumps(receipt,indent=2,sort_keys=True)+"\n",encoding="utf-8",newline="\n")
    print(json.dumps(receipt,indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
