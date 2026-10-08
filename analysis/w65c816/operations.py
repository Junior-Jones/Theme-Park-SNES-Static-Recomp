"""Pure W65C816 data-operation semantics for the offline proof library."""
from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True)
class OperationResult:
    value: int
    c: int | None
    z: int
    n: int | None
    v: int | None = None


def _checked(value: int, width: int) -> tuple[int, int]:
    if width not in (8, 16):
        raise ValueError("width must be 8 or 16")
    mask = (1 << width) - 1
    if not 0 <= value <= mask:
        raise ValueError("value outside selected width")
    return mask, 1 << (width - 1)


def _result(value: int, width: int, *, c: int | None = None, v: int | None = None) -> OperationResult:
    mask, sign = _checked(value, width)
    if c not in (None, 0, 1) or v not in (None, 0, 1):
        raise ValueError("flag outside bit domain")
    return OperationResult(value, c, int(value == 0), int(bool(value & sign)), v)


def logic(kind: str, left: int, right: int, width: int) -> OperationResult:
    mask, _ = _checked(left, width)
    _checked(right, width)
    if kind == "AND":
        value = left & right
    elif kind == "ORA":
        value = left | right
    elif kind == "EOR":
        value = left ^ right
    else:
        raise ValueError("logic operation must be AND, ORA or EOR")
    return _result(value & mask, width)


def shift(kind: str, value: int, carry: int, width: int) -> OperationResult:
    mask, sign = _checked(value, width)
    if carry not in (0, 1):
        raise ValueError("carry outside bit domain")
    if kind == "ASL":
        result, out = (value << 1) & mask, int(bool(value & sign))
    elif kind == "LSR":
        result, out = value >> 1, value & 1
    elif kind == "ROL":
        result, out = ((value << 1) | carry) & mask, int(bool(value & sign))
    elif kind == "ROR":
        result, out = (value >> 1) | (carry * sign), value & 1
    else:
        raise ValueError("shift operation must be ASL, LSR, ROL or ROR")
    return _result(result, width, c=out)


def increment(value: int, delta: int, width: int) -> OperationResult:
    mask, _ = _checked(value, width)
    if delta not in (-1, 1):
        raise ValueError("delta must be -1 or 1")
    return _result((value + delta) & mask, width)


def bit(accumulator: int, operand: int, width: int, *, immediate: bool = False) -> OperationResult:
    _, sign = _checked(accumulator, width)
    _checked(operand, width)
    overflow_bit = sign >> 1
    return OperationResult(
        operand,
        None,
        int((accumulator & operand) == 0),
        int(bool(operand & sign)) if not immediate else None,
        int(bool(operand & overflow_bit)) if not immediate else None,
    )


def test_and_modify(kind: str, accumulator: int, memory: int, width: int) -> OperationResult:
    mask, _ = _checked(accumulator, width)
    _checked(memory, width)
    if kind == "TSB":
        value = memory | accumulator
    elif kind == "TRB":
        value = memory & ~accumulator
    else:
        raise ValueError("operation must be TSB or TRB")
    result = _result(value & mask, width)
    return OperationResult(result.value, None, int((memory & accumulator) == 0), result.n)


def branch_condition(mnemonic: str, p: int) -> bool:
    if not 0 <= p <= 0xFF:
        raise ValueError("status outside byte domain")
    masks = {"BCC": (0x01, False), "BCS": (0x01, True), "BNE": (0x02, False),
             "BEQ": (0x02, True), "BPL": (0x80, False), "BMI": (0x80, True),
             "BVC": (0x40, False), "BVS": (0x40, True)}
    if mnemonic in ("BRA", "BRL"):
        return True
    if mnemonic not in masks:
        raise ValueError("not a branch mnemonic")
    mask, wanted = masks[mnemonic]
    return bool(p & mask) is wanted
