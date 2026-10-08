#!/usr/bin/env python3
"""Harvest offline hardware intelligence from admitted Theme Park 07C contexts."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import re
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from analysis.w65c816.access import access_profile


FIELDS = (
    "Stable_Id", "Families", "Context", "ROM_Offset", "Bytes", "Mnemonic", "Mode",
    "Access", "Instruction_Access_Width", "Byte_Event_Index", "Effective_Address",
    "Address_Proof", "Subsystem", "Feature_or_Register", "Timing_Relevance",
    "Authority_State", "Owning_Milestone", "Evidence", "Known_Limit",
)

CHECKLIST_FIELDS = (
    "Hardware_Area", "Subsystem", "Feature_or_Register", "Usage_Status",
    "Exact_Event_Count", "Deferred_Obligation_Count", "Context_Count", "Accesses", "Widths",
    "First_Context", "Implemented", "Reached", "Certified", "Owning_Milestone",
    "Proved_Value_Domain", "Timing_Claim", "Evidence", "Known_Limit",
)

HARDWARE_AREAS = (
    ("CARTRIDGE", "CARTRIDGE", "mapper/region/ROM/SRAM profile", "01C"),
    ("CPU", "CPU", "E/M/X, interrupts, WAI/STP, open bus", "02C/07C"),
    ("MEMORY", "MEMORY", "WRAM/mirrors/ROM data/executable RAM", "06C"),
    ("MATH_IO", "CPU_IO", "$4202-$421F math, status, IRQ and auto-joypad", "08C"),
    ("TIMING", "TIMING", "scanline/dot/field, blanking, refresh, NMI/IRQ", "07C"),
    ("DMA_HDMA", "DMA_HDMA", "manual DMA and HDMA tables/channels/timing", "08C"),
    ("PPU_STORAGE", "PPU", "VRAM/CGRAM/OAM ports and latches", "09C"),
    ("BACKGROUNDS", "PPU", "BG modes/maps/tiles/scroll/mosaic/Mode 7/EXTBG", "09C/14C"),
    ("OBJECTS", "PPU", "OAM/OBJ size/tile/palette/priority/overflow", "09C/14C"),
    ("COMPOSITION", "PPU", "main/subscreen/windows/color math/fixed color", "09C/14C"),
    ("DISPLAY", "PPU", "brightness/blanking/interlace/overscan/hires", "09C/14C"),
    ("INPUT", "INPUT", "manual serial/automatic polling/controllers", "15C"),
    ("AUDIO_IO", "APUIO", "$2140-$2143 protocol/upload/synchronization", "11C"),
    ("S_SMP", "S_SMP", "SPC700 contexts/timers/ARAM/code epochs/ports", "12C/13C"),
    ("S_DSP", "DSP", "BRR/voices/envelopes/interpolation/mix/echo", "16C"),
    ("PERSISTENCE", "PERSISTENCE", "SRAM initialization/write/flush", "15C"),
)


def read_csv(path: Path) -> list[dict[str, str]]:
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def subsystem(address: int) -> tuple[str, str, str] | None:
    bank, low = (address >> 16) & 0xFF, address & 0xFFFF
    mmio_bank = bank <= 0x3F or 0x80 <= bank <= 0xBF
    if mmio_bank and 0x2100 <= low <= 0x213F:
        return "PPU", f"PPU_${low:04X}", "09C"
    if mmio_bank and 0x2140 <= low <= 0x2143:
        return "APUIO", f"APUIO_${low:04X}", "11C"
    if mmio_bank and 0x2180 <= low <= 0x2183:
        return "WRAM_IO", f"WRAM_PORT_${low:04X}", "08C"
    if mmio_bank and low in (0x4016, 0x4017):
        return "INPUT", f"JOY_SERIAL_${low:04X}", "15C"
    if mmio_bank and 0x4200 <= low <= 0x421F:
        return "CPU_IO", f"CPU_IO_${low:04X}", "08C"
    if mmio_bank and 0x4300 <= low <= 0x437F:
        return "DMA_HDMA", f"DMA_HDMA_${low:04X}", "08C"
    if (0x70 <= bank <= 0x7D or 0xF0 <= bank <= 0xFF) and low < 0x8000:
        return "PERSISTENCE", "CARTRIDGE_SRAM", "15C"
    return None


def operand(raw: bytes) -> int:
    return int.from_bytes(raw[1:], "little")


def event_id(context: str, address: str, index: str, access: str) -> str:
    value = f"{context}|{address}|{index}|{access}".encode("ascii")
    return "TPHW-" + hashlib.sha256(value).hexdigest()[:20].upper()


def ppu_area(feature: str) -> str:
    low = int(feature[-4:], 16)
    if low in (0x2100, 0x2133, 0x2137) or 0x213C <= low <= 0x213F:
        return "DISPLAY"
    if low == 0x2101:
        return "OBJECTS"
    if 0x2102 <= low <= 0x2104:
        return "PPU_STORAGE"
    if 0x2105 <= low <= 0x2114 or 0x211A <= low <= 0x2120 or 0x2134 <= low <= 0x2136:
        return "BACKGROUNDS"
    if 0x2115 <= low <= 0x2119 or 0x2121 <= low <= 0x2122 or 0x2138 <= low <= 0x213B:
        return "PPU_STORAGE"
    if 0x2123 <= low <= 0x2132:
        return "COMPOSITION"
    return "PPU_STORAGE"


def hardware_area(row: dict[str, str]) -> str:
    return sorted(hardware_areas(row))[0]


def hardware_areas(row: dict[str, str]) -> set[str]:
    if row["Subsystem"] == "PPU":
        feature = row["Feature_or_Register"]
        return {ppu_area(feature)} if re.search(r"\$[0-9A-F]{4}$", feature) else {
            "PPU_STORAGE", "BACKGROUNDS", "OBJECTS", "COMPOSITION", "DISPLAY"}
    if row["Subsystem"] == "CPU_IO":
        match = re.search(r"\$([0-9A-F]{4})", row["Feature_or_Register"])
        if match is None:
            return {"MATH_IO", "TIMING", "INPUT", "DMA_HDMA"}
        address = int(match.group(1), 16)
        if address in (0x420B, 0x420C):
            return {"DMA_HDMA"}
        if address == 0x4200:
            return {"TIMING", "INPUT"}
        if 0x4207 <= address <= 0x420A or 0x4210 <= address <= 0x4212:
            return {"TIMING"}
        if 0x4218 <= address <= 0x421F:
            return {"INPUT"}
        return {"MATH_IO"}
    return {{"DMA_HDMA": "DMA_HDMA", "APUIO": "AUDIO_IO",
             "WRAM_IO": "MEMORY"}.get(row["Subsystem"], row["Subsystem"])}


HARDWARE_CLASS_RANGES = (
    (0x2100, 0x213F, "PPU", "PPU_CLASS_$2100-$213F", "09C"),
    (0x2140, 0x2143, "APUIO", "APUIO_CLASS_$2140-$2143", "11C"),
    (0x2180, 0x2183, "WRAM_IO", "WRAM_PORT_CLASS_$2180-$2183", "08C"),
    (0x4016, 0x4017, "INPUT", "JOY_SERIAL_CLASS_$4016-$4017", "15C"),
    (0x4200, 0x421F, "CPU_IO", "CPU_IO_CLASS_$4200-$421F", "08C"),
    (0x4300, 0x437F, "DMA_HDMA", "DMA_HDMA_CLASS_$4300-$437F", "08C"),
)


def wrapped_segments(start: int, maximum_delta: int, mask: int) -> list[tuple[int, int]]:
    end = start + maximum_delta
    if end <= mask:
        return [(start, end)]
    return [(start, mask), (0, end & mask)]


def unresolved_classes(row: dict[str, str], raw: bytes) -> list[tuple[str, str, str, str]]:
    """Conservatively name hardware classes an unresolved EA can intersect."""
    mode = row["Mode"]
    _bank, _pc, _e, _m, x = row["Context"].split(":")
    expression = ""
    segments: list[tuple[int, int]] = []
    if mode in ("ABS_X", "ABS_Y"):
        base = operand(raw)
        expression = f"00:{base:04X}+{mode[-1]}[0..{'00FF' if x == '1' else 'FFFF'}]"
        segments = wrapped_segments(base, 0xFF if x == "1" else 0xFFFF, 0xFFFF)
    elif mode == "ABSL_X":
        base = operand(raw)
        expression = f"{base:06X}+X[0..{'00FF' if x == '1' else 'FFFF'}]"
        long_segments = wrapped_segments(base, 0xFF if x == "1" else 0xFFFF, 0xFFFFFF)
        # MMIO is visible only in banks 00-3F/80-BF.  Project the long domain
        # onto every intersected bank without pretending an exact EA is known.
        for lo, hi in long_segments:
            first_bank, last_bank = lo >> 16, hi >> 16
            for bank in range(first_bank, last_bank + 1):
                if bank <= 0x3F or 0x80 <= bank <= 0xBF:
                    bank_lo = lo & 0xFFFF if bank == first_bank else 0
                    bank_hi = hi & 0xFFFF if bank == last_bank else 0xFFFF
                    segments.append((bank_lo, bank_hi))
    elif mode == "DP":
        expression = f"D+${operand(raw):02X};D_UNRESOLVED_BANK00"
        segments = [(0, 0xFFFF)]
    elif mode in ("DP_IND_LONG", "DP_IND_LONG_Y"):
        expression = f"[D+${operand(raw):02X}]_LONG" + ("+Y" if mode.endswith("_Y") else "")
        segments = [(0, 0xFFFF)]
    else:
        return []
    results = []
    for low, high, subsystem_name, feature, milestone in HARDWARE_CLASS_RANGES:
        if any(start <= high and end >= low for start, end in segments):
            results.append((subsystem_name, feature, milestone, expression))
    return results


def exact_base(row: dict[str, str], raw: bytes) -> int | None:
    mode = row["Mode"]
    value = operand(raw)
    if mode == "ABS":
        # V05C's closed DBR=0 theorem owns this bank decision.
        return value
    if mode == "ABSL":
        return value
    return None


def indexed_candidate(row: dict[str, str], raw: bytes) -> tuple[int, str] | None:
    mode = row["Mode"]
    value = operand(raw)
    if mode in ("ABS_X", "ABS_Y"):
        return value, f"00:{value:04X}+{mode[-1]}"
    if mode == "ABSL_X":
        return value, f"{value >> 16:02X}:{value & 0xFFFF:04X}+X"
    return None


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--selected", type=Path, default=ROOT / "docs/V07C-selected-contexts.csv")
    parser.add_argument("--events", type=Path, default=ROOT / "docs/V07C-hardware-intelligence.csv")
    parser.add_argument("--summary", type=Path, default=ROOT / "docs/V07C-hardware-intelligence-summary.json")
    parser.add_argument("--checklist", type=Path, default=ROOT / "docs/V07C-hardware-checklist.csv")
    args = parser.parse_args()
    selected_rows = read_csv(args.selected)
    rows: list[dict[str, str]] = []
    for source in selected_rows:
        context = source["Context"]
        _bank, _pc, e, m, x = context.split(":")
        raw = bytes.fromhex(source["Bytes"])
        profile = access_profile(raw[0], e=int(e), m=int(m), x=int(x))
        if profile.operand_access == "none":
            continue
        for subsystem_name, feature, milestone, expression in unresolved_classes(source, raw):
            rows.append({
                "Stable_Id": event_id(context, expression + "|" + feature, "", profile.operand_access),
                "Families": source["Families"], "Context": context,
                "ROM_Offset": source["ROM_Offset"], "Bytes": source["Bytes"],
                "Mnemonic": source["Mnemonic"], "Mode": source["Mode"],
                "Access": profile.operand_access.upper(),
                "Instruction_Access_Width": str(profile.operand_bytes), "Byte_Event_Index": "",
                "Effective_Address": expression,
                "Address_Proof": "CONSERVATIVE_WIDTH_BOUNDED_CLASS_INTERSECTION_NOT_EXACT_EA",
                "Subsystem": subsystem_name, "Feature_or_Register": feature,
                "Timing_Relevance": "POSSIBLE_HARDWARE_ACCESS_ORDER_REQUIRES_ADDRESS_PROOF",
                "Authority_State": "DEFERRED_SIDE_OBLIGATION_NOT_HARDWARE_REACHED",
                "Owning_Milestone": milestone,
                "Evidence": "V05C exact context/state plus unresolved effective-address producer",
                "Known_Limit": "CLASS_INTERSECTION_ONLY_NOT_PROOF_OF_RUNTIME_HARDWARE_REACH",
            })
        base = exact_base(source, raw)
        if base is not None:
            for index in range(profile.operand_bytes):
                address = (base + index) & 0xFFFFFF
                owner = subsystem(address)
                if owner is None:
                    continue
                subsystem_name, feature, milestone = owner
                address_text = f"{address >> 16:02X}:{address & 0xFFFF:04X}"
                rows.append({
                    "Stable_Id": event_id(context, address_text, str(index), profile.operand_access),
                    "Families": source["Families"], "Context": context,
                    "ROM_Offset": source["ROM_Offset"], "Bytes": source["Bytes"],
                    "Mnemonic": source["Mnemonic"], "Mode": source["Mode"],
                    "Access": profile.operand_access.upper(),
                    "Instruction_Access_Width": str(profile.operand_bytes),
                    "Byte_Event_Index": str(index), "Effective_Address": address_text,
                    "Address_Proof": "EXACT_START_PLUS_DBR_OR_LONG_BANK_PLUS_WIDTH_EXPANSION",
                    "Subsystem": subsystem_name, "Feature_or_Register": feature,
                    "Timing_Relevance": "BUS_EVENT_ORDER_REQUIRED",
                    "Authority_State": "SOURCE_REACHED_REGISTER_EVENT_NOT_IMPLEMENTED_OR_CERTIFIED",
                    "Owning_Milestone": milestone,
                    "Evidence": "V05C exact context/DBR theorem; V07C admitted source family",
                    "Known_Limit": "VALUE_DOMAIN_AND_HARDWARE_SEMANTICS_DEFERRED_TO_OWNER",
                })
            continue
        candidate = indexed_candidate(source, raw)
        if candidate is None:
            continue
        candidate_base, expression = candidate
        owner = subsystem(candidate_base)
        if owner is None:
            continue
        subsystem_name, feature, milestone = owner
        rows.append({
            "Stable_Id": event_id(context, expression, "", profile.operand_access),
            "Families": source["Families"], "Context": context,
            "ROM_Offset": source["ROM_Offset"], "Bytes": source["Bytes"],
            "Mnemonic": source["Mnemonic"], "Mode": source["Mode"],
            "Access": profile.operand_access.upper(),
            "Instruction_Access_Width": str(profile.operand_bytes), "Byte_Event_Index": "",
            "Effective_Address": expression,
            "Address_Proof": "BASE_LITERAL_ONLY_INDEX_PRODUCER_UNRESOLVED",
            "Subsystem": subsystem_name, "Feature_or_Register": feature,
            "Timing_Relevance": "POSSIBLE_HARDWARE_ACCESS_ORDER_REQUIRES_ADDRESS_PROOF",
            "Authority_State": "DEFERRED_SIDE_OBLIGATION_NOT_HARDWARE_REACHED",
            "Owning_Milestone": milestone,
            "Evidence": "V07C exact instruction start; indexed effective address unresolved",
            "Known_Limit": "MUST_PROVE_COMPLETE_INDEX_DOMAIN_BEFORE_REGISTER_SEMANTICS",
        })

    rows.sort(key=lambda row: (row["Context"], row["Effective_Address"], row["Byte_Event_Index"]))
    args.events.parent.mkdir(parents=True, exist_ok=True)
    with args.events.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=FIELDS, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)
    states = Counter(row["Authority_State"] for row in rows)
    systems = Counter(row["Subsystem"] for row in rows)
    grouped: dict[tuple[str, str, str], list[dict[str, str]]] = {}
    for row in rows:
        for area in hardware_areas(row):
            key = (area, row["Subsystem"], row["Feature_or_Register"])
            grouped.setdefault(key, []).append(row)
    checklist_rows: list[dict[str, str]] = []
    for area, subsystem_name, feature, milestone in HARDWARE_AREAS:
        matching = [row for row in rows if area in hardware_areas(row)]
        exact = [row for row in matching if row["Authority_State"].startswith("SOURCE_REACHED")]
        deferred = [row for row in matching if row["Authority_State"].startswith("DEFERRED")]
        usage = "SOURCE_REACHED" if exact else "POSSIBLE_UNRESOLVED" if deferred else "NOT_YET_SOURCE_PROVED"
        reached = "YES" if exact else "NO"
        implemented = "NO_LATER_MILESTONE_OWNER"
        certified = "NO"
        value_domain = "UNRESOLVED_AT_07C"
        timing_claim = "BUS_ORDER_ONLY" if matching else "NONE_YET"
        evidence = "V07C-hardware-intelligence.csv" if matching else "Starter v10 completeness row"
        limit = "07C_RECORDS_REACHABILITY_NOT_SUBSYSTEM_COMPLETION"
        if area == "CARTRIDGE":
            usage, reached, implemented, certified = "SOURCE_PROVED_PROFILE", "YES", "PROFILE_ONLY", "YES_01C"
            value_domain = "LOROM_FASTROM; EUROPE; PAL; SRAM_SIZE_CODE_ZERO"
            evidence = "V01C-cartridge-profile.json"
            limit = "PHYSICAL_PCB_IDENTITY_AND_COMPLETE_BUS_WINDOWS_DEFERRED"
        elif area == "CPU":
            usage, reached, implemented, certified = (
                "SOURCE_PROVED_SEMANTIC_FOUNDATION_AND_NATIVE_CONTEXT_SURFACE",
                "YES", "07C_NATIVE_SOURCE_EMITTED", "NO_COMPLETE_MACHINE")
            value_domain = "71986 SOURCE-CANDIDATE CONTEXTS; RUNTIME-REACHED COUNT UNKNOWN"
            timing_claim = "INSTRUCTION_LOCAL_CYCLES_EMITTED; SYSTEM_MASTER_CLOCK_DEFERRED"
            evidence = "V02C-SEMANTIC-MANIFEST.json; V07C-production-manifest.csv"
            limit = "DOES_NOT_CERTIFY_LATER_BUS_PPU_APU_INPUT_OR_RUNTIME_REACHABILITY"
        elif area == "MEMORY":
            usage, reached, implemented, certified = (
                "SOURCE_PROVED_PROFILE_AND_OPERAND_CLASSES", "YES",
                "ADDRESS_CLASSES_ONLY", "NO")
            value_domain = "LOROM/WRAM/MIRRORS/ROM; ZERO EXECUTABLE-RAM EPOCHS; SRAM ABSENT"
            evidence = "V01C-cartridge-profile.json; V05C-contexts.csv; V06C-executable-memory-summary.json"
            limit = "08C STILL OWNS COMPLETE BUS MAPPING AND MMIO BEHAVIOR"
        elif area == "TIMING":
            usage, reached = "SOURCE_PROVED_PAL_REGION_PROFILE_PENDING", "YES"
            implemented, certified = "INSTRUCTION_CYCLES_ONLY", "NO"
            value_domain = "PAL_REGION; EXACT_MASTER_CLOCK_RASTER_PROFILE_UNRESOLVED"
            timing_claim = "ONE_MONOTONIC_MASTER_SCHEDULER_REQUIRED; INTEGER_RATIONAL_DOMAIN_JOINS"
            evidence = "V01C-cartridge-profile.json; Starter-v10 docs/24 and docs/52"
            limit = "09C_MUST_OWN_MASTER_CLOCK_RASTER_INTERRUPTS_STALLS_AND_PHASE_REMAINDERS"
        elif area == "PERSISTENCE":
            usage, reached, implemented, certified = (
                "SOURCE_PROVED_NOT_PRESENT", "NO", "NOT_REQUIRED_FOR_ZERO_SRAM_PROFILE",
                "YES_01C_PROFILE_ONLY")
            value_domain = "CANONICAL_HEADER_SRAM_SIZE_CODE_ZERO"
            evidence = "V01C-cartridge-profile.json"
            limit = "15C HOST TRANSITION CONTRACT REMAINS OWNER IF LATER EVIDENCE CONTRADICTS PROFILE"
        checklist_rows.append({
            "Hardware_Area": area, "Subsystem": subsystem_name,
            "Feature_or_Register": feature, "Usage_Status": usage,
            "Exact_Event_Count": str(len(exact)), "Deferred_Obligation_Count": str(len(deferred)),
            "Context_Count": str(len({row["Context"] for row in matching})),
            "Accesses": ";".join(sorted({row["Access"] for row in matching})),
            "Widths": ";".join(sorted({row["Instruction_Access_Width"] for row in matching})),
            "First_Context": min((row["Context"] for row in matching), default=""),
            "Implemented": implemented, "Reached": reached, "Certified": certified,
            "Owning_Milestone": milestone, "Proved_Value_Domain": value_domain,
            "Timing_Claim": timing_claim, "Evidence": evidence, "Known_Limit": limit,
        })
    for (area, subsystem_name, feature), matching in sorted(grouped.items()):
        exact = [row for row in matching if row["Authority_State"].startswith("SOURCE_REACHED")]
        deferred = [row for row in matching if row["Authority_State"].startswith("DEFERRED")]
        checklist_rows.append({
            "Hardware_Area": area, "Subsystem": subsystem_name,
            "Feature_or_Register": feature,
            "Usage_Status": "SOURCE_REACHED" if exact else "POSSIBLE_UNRESOLVED",
            "Exact_Event_Count": str(len(exact)), "Deferred_Obligation_Count": str(len(deferred)),
            "Context_Count": str(len({row["Context"] for row in matching})),
            "Accesses": ";".join(sorted({row["Access"] for row in matching})),
            "Widths": ";".join(sorted({row["Instruction_Access_Width"] for row in matching})),
            "First_Context": min(row["Context"] for row in matching),
            "Implemented": "NO_LATER_MILESTONE_OWNER", "Reached": "YES" if exact else "NO",
            "Certified": "NO", "Owning_Milestone": matching[0]["Owning_Milestone"],
            "Proved_Value_Domain": "UNRESOLVED_AT_07C",
            "Timing_Claim": ";".join(sorted({row["Timing_Relevance"] for row in matching})),
            "Evidence": ";".join(sorted(row["Stable_Id"] for row in matching)),
            "Known_Limit": "VALUE_SEMANTICS_AND_VISIBLE_OR_AUDIBLE_EFFECT_DEFERRED",
        })
    with args.checklist.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=CHECKLIST_FIELDS, lineterminator="\n")
        writer.writeheader()
        writer.writerows(checklist_rows)
    plan = json.loads((ROOT / "config/v07-family-plan.json").read_text(encoding="utf-8"))
    planned_families = {spec["family_id"] for spec in plan["families"]}
    selected_families = {
        family for source in selected_rows for family in source["Families"].split(";") if family
    }
    event_families = {
        family for row in rows for family in row["Families"].split(";") if family
    }
    if selected_families != planned_families:
        raise ValueError("hardware sidecar selected-family coverage differs from the 07C plan")
    summary = {
        "schema": "theme-park-v07c-hardware-intelligence-v1",
        "status": "OFFLINE_SIDECAR_RECONCILED_NOT_RUNTIME_AUTHORITY",
        "context_policy": "PBR:PC:E:M:X",
        "runtime_policy": {
            "compiled_into_runtime": False,
            "runtime_context_key_extension_allowed": False,
            "sidecar_may_authorize_context_by_itself": False,
        },
        "timing_contract": {
            "source_proved_video_standard": "PAL",
            "exact_master_clock_raster_profile": "UNRESOLVED_OWNED_BY_09C",
            "instruction_cycle_completion": "OWNED_BY_07C_NATIVE_BODIES",
            "scheduler_requirement": "ONE_MONOTONIC_INTEGER_MASTER_TIMELINE",
            "independent_domain_join": "INTEGER_RATIONAL_WITH_PRESERVED_REMAINDER",
            "frontend_or_wall_clock_is_guest_authority": False,
        },
        "gates": ["EXACT_INSTRUCTION_START", "EFFECTIVE_BANK_ADDRESS_PROOF", "WIDTH_EXPANDED_BYTE_EVENTS"],
        "event_count": len(rows), "authority_state_counts": dict(sorted(states.items())),
        "subsystem_counts": dict(sorted(systems.items())),
        "backfill_coverage": {
            "selected_context_count": len(selected_rows),
            "planned_family_count": len(planned_families),
            "selected_family_count": len(selected_families),
            "families_with_hardware_events": len(event_families),
            "families_without_hardware_events": len(planned_families - event_families),
            "all_planned_families_rechecked": selected_families == planned_families,
        },
        "dependencies": {
            "selected_contexts_sha256": sha(args.selected),
            "v05_contexts_sha256": sha(ROOT / "docs/V05C-contexts.csv"),
            "v05_flow_summary_sha256": sha(ROOT / "docs/V05C-flow-summary.json"),
            "v06_executable_memory_sha256": sha(ROOT / "docs/V06C-executable-memory-summary.json"),
        },
        "events_sha256": sha(args.events), "checklist_rows": len(checklist_rows),
        "checklist_sha256": sha(args.checklist), "oracle_or_trace_inputs": [],
    }
    args.summary.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n",
                            encoding="utf-8", newline="\n")
    print(json.dumps({"hardware_sidecar_events": len(rows), "hardware_checklist_rows": len(checklist_rows),
                      "status": summary["status"]}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
