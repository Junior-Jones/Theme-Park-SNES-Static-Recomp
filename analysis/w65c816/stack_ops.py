"""Register push/pull and effective-address push semantics."""
from __future__ import annotations

from dataclasses import replace

from .cpu_state import CpuState, accumulator_write, index_write, set_status, with_nz
from .stack_interrupt import StackWrite, pull_addresses, push_bytes


def _word(value: int) -> tuple[int, int]:
    if not 0 <= value <= 0xFFFF:
        raise ValueError("word outside domain")
    return ((value >> 8) & 0xFF, value & 0xFF)


def push_effective(state: CpuState, value: int) -> tuple[tuple[StackWrite, ...], CpuState]:
    return push_bytes(state, _word(value))


def push_register(state: CpuState, mnemonic: str) -> tuple[tuple[StackWrite, ...], CpuState]:
    if mnemonic == "PHA":
        values = (state.a & 0xFF,) if state.m8 else _word(state.a)
    elif mnemonic in ("PHX", "PHY"):
        value = getattr(state, mnemonic[-1].lower())
        values = (value & 0xFF,) if state.x8 else _word(value)
    elif mnemonic == "PHB":
        values = (state.dbr,)
    elif mnemonic == "PHD":
        values = _word(state.d)
    elif mnemonic == "PHK":
        values = (state.pbr,)
    elif mnemonic == "PHP":
        values = (state.p,)
    else:
        raise ValueError("not a push-register mnemonic")
    return push_bytes(state, values)


def pull_register(state: CpuState, mnemonic: str, values: tuple[int, ...]) -> CpuState:
    widths = {"PLA": 1 if state.m8 else 2, "PLX": 1 if state.x8 else 2,
              "PLY": 1 if state.x8 else 2, "PLB": 1, "PLD": 2, "PLP": 1}
    if mnemonic not in widths or len(values) != widths[mnemonic] or any(not 0 <= v <= 0xFF for v in values):
        raise ValueError("pull frame does not match register width")
    _, pulled = pull_addresses(state, len(values))
    value = values[0] if len(values) == 1 else values[0] | (values[1] << 8)
    if mnemonic == "PLA":
        width = 8 if state.m8 else 16
        return with_nz(accumulator_write(pulled, value), value, width)
    if mnemonic in ("PLX", "PLY"):
        width = 8 if state.x8 else 16
        return with_nz(index_write(pulled, mnemonic[-1].lower(), value), value, width)
    if mnemonic == "PLB":
        return with_nz(replace(pulled, dbr=value), value, 8)
    if mnemonic == "PLD":
        return with_nz(replace(pulled, d=value), value, 16)
    return set_status(pulled, value)
