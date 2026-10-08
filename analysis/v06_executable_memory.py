"""Executable-memory address classification for Theme Park 06C."""
from __future__ import annotations


def classify_execution_address(bank: int, pc: int) -> str:
    if not 0 <= bank <= 0xFF or not 0 <= pc <= 0xFFFF:
        raise ValueError("execution address outside 24-bit domain")
    if bank in (0x7E, 0x7F):
        return "WRAM"
    if (bank & 0x7F) < 0x40 and pc < 0x2000:
        return "LOW_WRAM_MIRROR"
    if (bank & 0x7F) < 0x20 and pc >= 0x8000:
        return "CANONICAL_LOROM"
    return "UNMAPPED_OR_NONCANONICAL"


def parse_context_key(value: str) -> tuple[int, int]:
    fields = value.split(":")
    if len(fields) < 2:
        raise ValueError(f"invalid context key: {value}")
    return int(fields[0], 16), int(fields[1], 16)
