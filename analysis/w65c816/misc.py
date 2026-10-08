"""Reserved/no-operation instruction semantics."""
from __future__ import annotations

from .cpu_state import CpuState


def no_effect(state: CpuState, mnemonic: str, signature: int | None = None) -> CpuState:
    if mnemonic == "NOP" and signature is None:
        return state
    if mnemonic == "WDM" and signature is not None and 0 <= signature <= 0xFF:
        return state
    raise ValueError("invalid NOP/WDM form")
