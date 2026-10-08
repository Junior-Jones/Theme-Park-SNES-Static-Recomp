"""Theme Park 03C whole-ROM lexical census; candidates are never execution proof."""
from __future__ import annotations

import hashlib
import math
import struct
from collections import Counter
from pathlib import Path

from analysis.w65c816.opcodes import OPCODES, instruction_length
from analysis.w65c816.state import legal_modes

ROM_SHA256 = "c0a7e27131a7d8c9ef52a5227329e6de5846c045a9da1f3f84845e3be8e4efba"
ROM_SIZE = 0x100000
LOROM_BANK_BYTES = 0x8000


def load_canonical_rom(path: Path) -> bytes:
    data = path.read_bytes()
    if len(data) != ROM_SIZE or hashlib.sha256(data).hexdigest() != ROM_SHA256:
        raise ValueError("03C requires the exact canonical Theme Park ROM")
    return data


def offset_to_canonical_address(offset: int) -> int:
    if not 0 <= offset < ROM_SIZE:
        raise ValueError("physical offset outside ROM")
    return ((offset // LOROM_BANK_BYTES) << 16) | (0x8000 + offset % LOROM_BANK_BYTES)


def lexical_scan(rom: bytes) -> tuple[dict, tuple[int, ...]]:
    if len(rom) != ROM_SIZE:
        raise ValueError("unexpected canonical ROM size")
    digest = hashlib.sha256()
    length_histogram = Counter()
    valid_masks = []
    invalid_rows = 0
    modes = legal_modes()
    for offset, opcode in enumerate(rom):
        within_bank = offset % LOROM_BANK_BYTES
        mask = 0
        for mode_index, (e, m, x) in enumerate(modes):
            length = instruction_length(opcode, e=e, m=m, x=x)
            valid = within_bank + length <= LOROM_BANK_BYTES
            length_histogram[length] += 1
            invalid_rows += int(not valid)
            mask |= int(valid) << mode_index
            digest.update(struct.pack("<IBBBB", offset, mode_index, opcode, length, int(valid)))
        valid_masks.append(mask)
    return ({
        "physical_offsets": len(rom),
        "legal_contexts_per_offset": len(modes),
        "rows": len(rom) * len(modes),
        "valid_rows": len(rom) * len(modes) - invalid_rows,
        "invalid_fetch_rows_at_lorom_bank_boundary": invalid_rows,
        "instruction_length_histogram": {str(key): length_histogram[key] for key in sorted(length_histogram)},
        "row_digest_serialization": "little-endian <IBBBB = physical_offset,legal_mode_index,opcode,length,fetch_valid",
        "legal_mode_order": [f"{e}{m}{x}" for e, m, x in modes],
        "row_digest_sha256": digest.hexdigest(),
    }, tuple(valid_masks))


def mask_ranges(masks: tuple[int, ...]) -> list[dict]:
    if not masks:
        return []
    rows = []
    start = 0
    current = masks[0]
    for offset in range(1, len(masks) + 1):
        value = masks[offset] if offset < len(masks) else None
        if value != current:
            rows.append({"start": start, "end": offset - 1, "byte_count": offset - start,
                         "legal_mode_mask": current, "any_lexical_start": bool(current)})
            start, current = offset, value
    return rows


def interest_inventory(rom: bytes, masks: tuple[int, ...]) -> dict:
    ranges = ((0x2100, 0x21FF, "PPU_LOW16"), (0x2140, 0x2143, "APUIO_LOW16"),
              (0x4200, 0x421F, "CPU_IO_LOW16"), (0x4300, 0x437F, "DMA_HDMA_LOW16"))
    counts = Counter()
    digest = hashlib.sha256()
    examples: dict[str, list[str]] = {}
    absolute_modes = {"ABS", "ABS_X", "ABS_Y"}
    long_modes = {"ABSL", "ABSL_X"}
    for offset, opcode in enumerate(rom):
        if not masks[offset]:
            continue
        item = OPCODES[opcode]
        address = offset_to_canonical_address(offset)
        remaining = LOROM_BANK_BYTES - (offset % LOROM_BANK_BYTES)
        if item.mode in absolute_modes and remaining >= 3:
            operand = rom[offset + 1] | (rom[offset + 2] << 8)
            for low, high, name in ranges:
                if low <= operand <= high:
                    key = name + "_DBR_UNPROVED"
                    counts[key] += 1
                    examples.setdefault(key, [])
                    if len(examples[key]) < 8:
                        examples[key].append(f"{address >> 16:02X}:{address & 0xFFFF:04X}")
                    digest.update(struct.pack("<IBH", offset, opcode, operand))
        elif item.mode in long_modes and remaining >= 4:
            operand = int.from_bytes(rom[offset + 1:offset + 4], "little")
            bank, low16 = operand >> 16, operand & 0xFFFF
            for low, high, name in ranges:
                if bank == 0 and low <= low16 <= high:
                    key = name + "_EXACT_BANK0"
                    counts[key] += 1
                    examples.setdefault(key, [])
                    if len(examples[key]) < 8:
                        examples[key].append(f"{address >> 16:02X}:{address & 0xFFFF:04X}")
                    digest.update(struct.pack("<IBI", offset, opcode, operand))
            if item.mnemonic in ("STA", "STX", "STY", "STZ") and bank in (0x7E, 0x7F):
                counts["WRAM_WRITE_EXACT_BANK"] += 1
    return {"authority": "LEXICAL_INTEREST_ONLY_NOT_REACHABILITY", "counts": dict(sorted(counts.items())),
            "examples_are_non_authoritative": examples, "row_digest_sha256": digest.hexdigest()}


def region_signals(rom: bytes) -> dict:
    padding_runs = []
    start = 0
    while start < len(rom):
        value = rom[start]
        end = start + 1
        while end < len(rom) and rom[end] == value:
            end += 1
        if value in (0x00, 0xFF) and end - start >= 16:
            padding_runs.append((start, end - 1, value))
        start = end
    ascii_runs = []
    start = 0
    while start < len(rom):
        if 0x20 <= rom[start] <= 0x7E:
            end = start + 1
            while end < len(rom) and 0x20 <= rom[end] <= 0x7E:
                end += 1
            if end - start >= 4:
                ascii_runs.append((start, end - 1))
            start = end
        else:
            start += 1
    entropy_buckets = Counter()
    for offset in range(0, len(rom), 256):
        block = rom[offset:offset + 256]
        counts = Counter(block)
        entropy = -sum((count / len(block)) * math.log2(count / len(block)) for count in counts.values())
        entropy_buckets[str(min(8, int(entropy)))] += 1
    return {
        "authority": "HEURISTIC_REGION_SIGNALS_ONLY_NO_CODE_OR_DATA_PROMOTION",
        "padding_runs_00_or_ff_at_least_16": len(padding_runs),
        "padding_digest_sha256": hashlib.sha256(repr(padding_runs).encode()).hexdigest(),
        "printable_ascii_runs_at_least_4": len(ascii_runs),
        "ascii_digest_sha256": hashlib.sha256(repr(ascii_runs).encode()).hexdigest(),
        "entropy_floor_bucket_window_counts": dict(sorted(entropy_buckets.items())),
        "classification_limit": "Pointer/script/text/audio/tile/compressed signals remain candidates until source-owned consumers prove them.",
    }
