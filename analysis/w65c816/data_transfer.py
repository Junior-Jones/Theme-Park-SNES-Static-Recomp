"""Width-owned load/store semantics independent of any game or bus implementation."""
from __future__ import annotations

from .cpu_state import CpuState, accumulator_write, index_write, with_nz


def load(state: CpuState, mnemonic: str, value: int) -> CpuState:
    if mnemonic == "LDA":
        width = 8 if state.m8 else 16
        return with_nz(accumulator_write(state, value), value, width)
    if mnemonic in ("LDX", "LDY"):
        width = 8 if state.x8 else 16
        return with_nz(index_write(state, mnemonic[-1].lower(), value), value, width)
    raise ValueError("not a load mnemonic")


def store_value(state: CpuState, mnemonic: str) -> tuple[int, int]:
    if mnemonic == "STA":
        width = 8 if state.m8 else 16
        return state.a & ((1 << width) - 1), width
    if mnemonic in ("STX", "STY"):
        width = 8 if state.x8 else 16
        return getattr(state, mnemonic[-1].lower()) & ((1 << width) - 1), width
    if mnemonic == "STZ":
        width = 8 if state.m8 else 16
        return 0, width
    raise ValueError("not a store mnemonic")
