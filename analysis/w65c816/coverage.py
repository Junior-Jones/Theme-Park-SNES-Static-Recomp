"""Separate decoder semantics from later native-lowerer and production claims."""
from __future__ import annotations

from dataclasses import dataclass

from .opcodes import OPCODES


@dataclass(frozen=True)
class Coverage:
    mnemonic: str
    decoded_semantic: bool
    native_lowerer_implemented: bool
    production_reached: bool


def semantic_matrix() -> tuple[Coverage, ...]:
    names = sorted({item.mnemonic for item in OPCODES})
    return tuple(Coverage(name, True, False, False) for name in names)
