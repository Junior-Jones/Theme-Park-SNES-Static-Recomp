"""Offline-only W65C816 byte decoder. This module is forbidden from production selection."""
from __future__ import annotations

from dataclasses import dataclass

from .opcodes import OPCODES, Opcode, instruction_length

OFFLINE_ONLY = True


@dataclass(frozen=True)
class DecodedInstruction:
    opcode: Opcode
    raw: bytes
    operand: int
    e: int
    m: int
    x: int


def decode(data: bytes, *, e: int, m: int, x: int) -> DecodedInstruction:
    if not data:
        raise ValueError("missing opcode byte")
    length = instruction_length(data[0], e=e, m=m, x=x)
    if len(data) < length:
        raise ValueError("truncated instruction")
    raw = bytes(data[:length])
    operand = int.from_bytes(raw[1:], "little")
    return DecodedInstruction(OPCODES[raw[0]], raw, operand, e, m, x)
