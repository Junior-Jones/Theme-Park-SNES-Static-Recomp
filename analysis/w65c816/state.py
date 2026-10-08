"""W65C816 E/M/X mode-domain rules for offline proof."""
from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True, order=True)
class Mode:
    e: int
    m: int
    x: int

    def __post_init__(self) -> None:
        if (self.e, self.m, self.x) not in legal_modes():
            raise ValueError(f"illegal E/M/X combination: {self.e}/{self.m}/{self.x}")


def legal_modes() -> tuple[tuple[int, int, int], ...]:
    return ((0, 0, 0), (0, 0, 1), (0, 1, 0), (0, 1, 1), (1, 1, 1))


def normalize_mode(e: int, m: int, x: int) -> Mode:
    if any(value not in (0, 1) for value in (e, m, x)):
        raise ValueError("E/M/X values must be bits")
    if e:
        m = 1
        x = 1
    return Mode(e, m, x)


def raw_mode_accounting() -> tuple[int, int]:
    """Return legal and contradictory rows across all opcodes and raw E/M/X bits."""
    legal = rejected = 0
    for _opcode in range(256):
        for e in (0, 1):
            for m in (0, 1):
                for x in (0, 1):
                    if (e, m, x) in legal_modes():
                        legal += 1
                    else:
                        rejected += 1
    return legal, rejected

