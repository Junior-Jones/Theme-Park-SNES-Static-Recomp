"""Read-only Theme Park 01C identity, header/vector, and byte-census generator."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
from pathlib import Path
import zlib

EXPECTED_SHA256 = "c0a7e27131a7d8c9ef52a5227329e6de5846c045a9da1f3f84845e3be8e4efba"
EXPECTED_SIZE = 1_048_576
HEADER = 0x7FC0
VECTOR_NAMES = {
    0x24: "native_cop", 0x26: "native_brk", 0x28: "native_abort",
    0x2A: "native_nmi", 0x2C: "native_reserved", 0x2E: "native_irq",
    0x34: "emulation_cop", 0x36: "emulation_reserved",
    0x38: "emulation_abort", 0x3A: "emulation_nmi",
    0x3C: "emulation_reset", 0x3E: "emulation_irq_brk",
}


def score_header(data: bytes, name: str, base: int) -> dict | None:
    if base + 0x40 > len(data):
        return None
    title = data[base:base + 21]
    map_mode = data[base + 0x15]
    rom_size_code = data[base + 0x17]
    complement = u16(data, base + 0x1C)
    checksum = u16(data, base + 0x1E)
    reset = u16(data, base + 0x3C)
    score = 0
    reasons = []
    if sum(32 <= byte <= 126 or byte == 0 for byte in title) >= 18:
        score += 2
        reasons.append("mostly printable title")
    if (checksum ^ complement) == 0xFFFF and (checksum or complement):
        score += 4
        reasons.append("checksum/complement pair")
    if reset >= 0x8000:
        score += 3
        reasons.append("reset vector in upper bank half")
    if map_mode & 0x0F in (0, 1, 2, 3, 5, 0xA):
        score += 2
        reasons.append("plausible map-mode nibble")
    if rom_size_code <= 0x0F:
        score += 1
        reasons.append("plausible ROM-size code")
    return {
        "mapping_candidate": name,
        "canonical_header_offset": f"0x{base:06X}",
        "score": score,
        "reasons": reasons,
        "title": "".join(chr(byte) if 32 <= byte <= 126 else "." for byte in title).rstrip(" ."),
        "map_mode": f"0x{map_mode:02X}",
        "rom_type": f"0x{data[base + 0x16]:02X}",
        "rom_size_code": rom_size_code,
        "sram_size_code": data[base + 0x18],
        "region_code": f"0x{data[base + 0x19]:02X}",
        "checksum_complement": f"0x{complement:04X}",
        "checksum": f"0x{checksum:04X}",
        "reset_vector": f"0x{reset:04X}",
    }


def u16(data: bytes, offset: int) -> int:
    return data[offset] | (data[offset + 1] << 8)


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def canonical_lorom_offset(cpu_address: int) -> int:
    """Map only the conservative 1 MiB canonical LoROM windows admitted by 01C."""
    if not 0 <= cpu_address <= 0xFFFFFF:
        raise ValueError("CPU address outside 24-bit domain")
    bank = cpu_address >> 16
    address = cpu_address & 0xFFFF
    if bank in (0x7E, 0x7F) or address < 0x8000:
        raise ValueError("address is not in an admitted canonical LoROM window")
    offset = (bank & 0x7F) * 0x8000 + (address & 0x7FFF)
    if offset >= EXPECTED_SIZE:
        raise ValueError("unproved mirror outside the canonical 1 MiB image")
    return offset


def analyze(rom_path: Path) -> tuple[dict, list[dict]]:
    data = rom_path.read_bytes()
    digest = sha256(data)
    if len(data) != EXPECTED_SIZE or digest != EXPECTED_SHA256:
        raise SystemExit(f"wrong Theme Park ROM: size={len(data)} sha256={digest}")
    checksum = u16(data, HEADER + 0x1E)
    complement = u16(data, HEADER + 0x1C)
    header_candidates = [
        item for name, base in (("LoROM", 0x7FC0), ("HiROM", 0xFFC0))
        if (item := score_header(data, name, base)) is not None
    ]
    header_candidates.sort(key=lambda item: (-item["score"], item["mapping_candidate"]))
    vectors = []
    for relative, name in VECTOR_NAMES.items():
        raw = HEADER + relative
        value = u16(data, raw)
        vectors.append({
            "name": name,
            "value": f"0x{value:04X}",
            "cpu_vector_address": f"0x00{0xFFC0 + relative:04X}",
            "canonical_offset": f"0x{raw:06X}",
            "raw_offset": f"0x{raw:06X}",
        })
    census = [
        {"start": 0x000000, "end": 0x007FBF, "state": "UNRESOLVED", "owner": "03C"},
        {"start": 0x007FC0, "end": 0x007FDF, "state": "HEADER", "owner": "01C"},
        {"start": 0x007FE0, "end": 0x007FFF, "state": "VECTOR", "owner": "01C"},
        {"start": 0x008000, "end": 0x0FFFFF, "state": "UNRESOLVED", "owner": "03C"},
    ]
    profile = {
        "schema": "theme-park-v01c-cartridge-profile-v1",
        "target_name": "Theme Park (Europe) (En,Fr,De)",
        "rom": {
            "input_basename": rom_path.name,
            "original_sha256": digest,
            "canonical_sha256": digest,
            "original_size_bytes": len(data),
            "canonical_size_bytes": len(data),
            "copier_header_bytes": 0,
            "crc32": f"{zlib.crc32(data) & 0xFFFFFFFF:08X}",
        },
        "header": {
            "canonical_offset": "0x007FC0",
            "raw_offset": "0x007FC0",
            "title": data[HEADER:HEADER + 21].decode("ascii").rstrip(),
            "map_mode": f"0x{data[HEADER + 0x15]:02X}",
            "rom_type": f"0x{data[HEADER + 0x16]:02X}",
            "rom_size_code": data[HEADER + 0x17],
            "sram_size_code": data[HEADER + 0x18],
            "destination_region_code": f"0x{data[HEADER + 0x19]:02X}",
            "version": data[HEADER + 0x1B],
            "checksum_complement": f"0x{complement:04X}",
            "checksum": f"0x{checksum:04X}",
            "computed_checksum": f"0x{sum(data) & 0xFFFF:04X}",
            "checksum_pair_valid": (checksum ^ complement) == 0xFFFF and checksum == (sum(data) & 0xFFFF),
        },
        "cartridge": {
            "logical_mapper": "LOROM",
            "speed": "FASTROM",
            "video_standard": "PAL",
            "region": "Europe",
            "header_declared_sram_bytes": 0,
            "header_declared_enhancement_hardware": "NONE_ROM_TYPE_0x00",
            "physical_pcb": "UNKNOWN_AT_01C",
            "full_24bit_bus_semantics_owner": "08C",
        },
        "mapping_evidence": {
            "header_candidates": header_candidates,
            "selected_candidate": "LoROM",
            "reset_vector": "0x8000",
            "reset_vector_lorom_physical_offset": f"0x{canonical_lorom_offset(0x008000):06X}",
            "admitted_canonical_windows": "banks 00-1F and 80-9F at addresses 8000-FFFF",
            "unproved_mirrors_owner": "08C",
            "invalid_mapping_policy": "REJECT_NOT_MODULO_WRAP",
        },
        "vectors": vectors,
        "context_key": ["PBR", "PC", "E", "M", "X"],
        "unknown_context_policy": "FAIL_CLOSED",
        "runtime_cpu_decoder_allowed": False,
        "candidate_observation_is_proof": False,
        "byte_census": {
            "path": "docs/V01C-byte-census.csv",
            "total_bytes": sum(row["end"] - row["start"] + 1 for row in census),
            "states": {"HEADER": 32, "VECTOR": 32, "UNRESOLVED": EXPECTED_SIZE - 64},
        },
        "not_claimed": [
            "disassembly", "proved code or data outside header/vector",
            "CPU contexts", "runtime core", "frontend", "gameplay", "release",
        ],
    }
    return profile, census


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    profile, census = analyze(args.rom)
    args.out.mkdir(parents=True, exist_ok=True)
    profile_path = args.out / "V01C-cartridge-profile.json"
    profile_path.write_text(json.dumps(profile, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")
    census_path = args.out / "V01C-byte-census.csv"
    with census_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.writer(handle, lineterminator="\n")
        writer.writerow(("Start_Offset", "End_Offset", "Byte_Count", "State", "Owner"))
        for row in census:
            writer.writerow((f"0x{row['start']:06X}", f"0x{row['end']:06X}", row["end"] - row["start"] + 1, row["state"], row["owner"]))
    print(json.dumps({"status": "PASS", "profile_sha256": sha256(profile_path.read_bytes()), "census_sha256": sha256(census_path.read_bytes())}, sort_keys=True))


if __name__ == "__main__":
    main()

