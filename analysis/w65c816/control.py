"""Fixed jump, call and return semantics with explicit stack-byte ordering."""
from __future__ import annotations

from dataclasses import replace

from .cpu_state import CpuState
from .stack_interrupt import StackWrite, pull_addresses, push_bytes


def jump(state: CpuState, target_pc: int, target_bank: int | None = None) -> CpuState:
    if not 0 <= target_pc <= 0xFFFF or (target_bank is not None and not 0 <= target_bank <= 0xFF):
        raise ValueError("jump target outside domain")
    return replace(state, pc=target_pc, pbr=state.pbr if target_bank is None else target_bank)


def call(state: CpuState, mnemonic: str, return_pc: int, target_pc: int,
         target_bank: int | None = None) -> tuple[tuple[StackWrite, ...], CpuState]:
    if not 0 <= return_pc <= 0xFFFF:
        raise ValueError("return PC outside word domain")
    if mnemonic == "JSR":
        values = ((return_pc >> 8) & 0xFF, return_pc & 0xFF)
        bank = state.pbr
    elif mnemonic == "JSL":
        if target_bank is None:
            raise ValueError("JSL requires target bank")
        values = (state.pbr, (return_pc >> 8) & 0xFF, return_pc & 0xFF)
        bank = target_bank
    else:
        raise ValueError("call must be JSR or JSL")
    writes, stacked = push_bytes(state, values)
    return writes, jump(stacked, target_pc, bank)


def return_from_subroutine(state: CpuState, mnemonic: str, values: tuple[int, ...]) -> CpuState:
    expected = 2 if mnemonic == "RTS" else 3 if mnemonic == "RTL" else 0
    if not expected or len(values) != expected or any(not 0 <= value <= 0xFF for value in values):
        raise ValueError("invalid subroutine return frame")
    _, pulled = pull_addresses(state, expected)
    target = ((values[1] << 8) | values[0]) + 1
    bank = state.pbr if mnemonic == "RTS" else values[2]
    return replace(pulled, pc=target & 0xFFFF, pbr=bank)
