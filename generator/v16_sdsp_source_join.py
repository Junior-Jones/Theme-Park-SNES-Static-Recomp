#!/usr/bin/env python3
"""Join Theme Park's exact static S-SMP DSP-port sites to the 16C owner.

This is source/AOT analysis only.  It neither executes the guest nor consults an
emulator.  The generated AOT completion switch is already the admitted 13C
authority, so parsing it avoids treating arbitrary $F2/$F3 data bytes as I/O.
"""
from __future__ import annotations

import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
AOT = ROOT / "runtime/generated/theme_park_spc700_aot.c"
DISCOVERY = ROOT / "docs/V13C-spc700-discovery.json"
OUTPUT = ROOT / "docs/V16C-sdsp-source-domain.json"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main() -> int:
    discovery = json.loads(DISCOVERY.read_text(encoding="utf-8"))
    contexts = {int(row["pc"][1:], 16): row for row in discovery["contexts"]}
    text = AOT.read_text(encoding="utf-8")
    completion = text.split("int tp_spc700_aot_complete", 1)[1]
    sites: list[dict[str, object]] = []
    case_re = re.compile(r"case 0x([0-9A-F]{4})u:(.*?)(?=\ncase |\ndefault:)", re.S)
    io_re = re.compile(r"([RW])\(tp_spc_dp\(a,\s*0xF([23])u\),\s*([^;]+?)\)")
    immediate_re = re.compile(r"0x([0-9A-F]{2})u$")
    for match in case_re.finditer(completion):
        pc = int(match.group(1), 16)
        body = " ".join(match.group(2).split())
        for access in io_re.finditer(body):
            operation, port, expression = access.groups()
            immediate = immediate_re.fullmatch(expression.strip())
            sites.append({
                "pc": f"${pc:04X}",
                "instruction_bytes": contexts[pc]["bytes"],
                "port": f"$F{port}",
                "access": "READ" if operation == "R" else "WRITE",
                "value_expression_class": "IMMEDIATE" if immediate else "LIVE_S_SMP_STATE",
                "immediate_value": f"${int(immediate.group(1),16):02X}" if immediate else None,
            })
    if not sites:
        raise ValueError("no exact DSP-port sites found")
    if len({row["pc"] for row in sites}) != len(sites):
        raise ValueError("unexpected multiple DSP-port effects in one exact-PC body")

    lexical_pairs: list[dict[str, str]] = []
    for left, right in zip(sites, sites[1:]):
        if (left["port"] == "$F2" and left["access"] == "WRITE" and
                left["immediate_value"] is not None and right["port"] == "$F3"):
            lexical_pairs.append({
                "address_pc": str(left["pc"]),
                "data_pc": str(right["pc"]),
                "register": str(left["immediate_value"]),
                "data_access": str(right["access"]),
                "qualification": "LEXICALLY_ADJACENT_EXACT_AOT_SITES_NOT_A_RUNTIME_TRACE",
            })

    counts: dict[str, int] = {}
    for row in sites:
        key = f'{row["port"]}_{row["access"]}'
        counts[key] = counts.get(key, 0) + 1
    reached = sorted({pair["register"] for pair in lexical_pairs})
    payload = {
        "schema": "theme-park-v16c-sdsp-source-domain-v1",
        "status": "CLOSED_EXACT_AOT_DSP_PORT_PRODUCERS_JOINED_TO_GENERIC_128_REGISTER_OWNER",
        "authority_policy": "SOURCE_RECONSTRUCTED_ARAM_AND_13C_EXACT_AOT_ONLY_NO_ORACLE_NO_TRACE",
        "inputs_sha256": {"spc700_aot": sha(AOT), "spc700_discovery": sha(DISCOVERY)},
        "exact_access_sites": len(sites),
        "exact_pc_sites": len({row["pc"] for row in sites}),
        "access_counts": dict(sorted(counts.items())),
        "lexically_proved_immediate_registers": reached,
        "dynamic_register_address_sites_present": any(
            row["port"] == "$F2" and row["immediate_value"] is None for row in sites),
        "receiver": {
            "address_owner": "TPApu.dsp_address",
            "data_owner": "TPSdsp.registers[128]",
            "fixed_hardware_owner": "runtime/src/theme_park_sdsp.c",
            "all_128_register_addresses_accepted": True,
            "unknown_aram_propagates_knownness": True,
            "unknown_control_flow": "FAIL_CLOSED_BY_13C_AOT",
        },
        "oracle_used": False,
        "trace_used": False,
        "frontend_used": False,
        "lexical_immediate_pairs": lexical_pairs,
        "sites": sites,
    }
    OUTPUT.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n",
                      encoding="utf-8", newline="\n")
    print(json.dumps({
        "status": payload["status"],
        "exact_access_sites": len(sites),
        "immediate_registers": len(reached),
    }, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
