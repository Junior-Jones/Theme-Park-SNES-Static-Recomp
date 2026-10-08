"""Width-explicit W65C816 arithmetic and flag semantics."""
from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True)
class AluResult:
    value: int
    c: int
    z: int
    v: int
    n: int


class UnprovedDecimalInput(ValueError):
    """Raised where WDC does not specify an invalid packed-BCD digit result."""


def _domain(a: int, b: int, carry: int, width: int) -> tuple[int, int]:
    if width not in (8, 16):
        raise ValueError("width must be 8 or 16")
    mask = (1 << width) - 1
    if not 0 <= a <= mask or not 0 <= b <= mask:
        raise ValueError("operand outside selected width")
    if carry not in (0, 1):
        raise ValueError("carry outside bit domain")
    return mask, 1 << (width - 1)


def _finish(value: int, carry: bool, overflow: bool, mask: int, sign: int) -> AluResult:
    value &= mask
    return AluResult(value, int(carry), int(value == 0), int(overflow), int(bool(value & sign)))


def _require_packed_bcd(a: int, b: int, width: int) -> None:
    for shift in range(0, width, 4):
        if ((a >> shift) & 0xF) > 9 or ((b >> shift) & 0xF) > 9:
            raise UnprovedDecimalInput("invalid packed-BCD digit has no qualified hardware result")


def adc_binary(a: int, b: int, carry: int, width: int) -> AluResult:
    mask, sign = _domain(a, b, carry, width)
    total = a + b + carry
    value = total & mask
    return _finish(value, total > mask, bool(~(a ^ b) & (a ^ value) & sign), mask, sign)


def sbc_binary(a: int, b: int, carry: int, width: int) -> AluResult:
    mask, sign = _domain(a, b, carry, width)
    difference = a - b - (1 - carry)
    value = difference & mask
    return _finish(value, difference >= 0, bool((a ^ b) & (a ^ value) & sign), mask, sign)


def adc_decimal(a: int, b: int, carry: int, width: int) -> AluResult:
    mask, sign = _domain(a, b, carry, width)
    _require_packed_bcd(a, b, width)
    binary_value = (a + b + carry) & mask
    overflow = bool(~(a ^ b) & (a ^ binary_value) & sign)
    result = 0
    digit_carry = carry
    for shift in range(0, width, 4):
        digit = ((a >> shift) & 0xF) + ((b >> shift) & 0xF) + digit_carry
        if digit > 9:
            digit += 6
        digit_carry = 1 if digit > 0xF else 0
        result |= (digit & 0xF) << shift
    return _finish(result, bool(digit_carry), overflow, mask, sign)


def sbc_decimal(a: int, b: int, carry: int, width: int) -> AluResult:
    mask, sign = _domain(a, b, carry, width)
    _require_packed_bcd(a, b, width)
    binary_value = (a - b - (1 - carry)) & mask
    overflow = bool((a ^ b) & (a ^ binary_value) & sign)
    result = 0
    borrow = 1 - carry
    for shift in range(0, width, 4):
        digit = ((a >> shift) & 0xF) - ((b >> shift) & 0xF) - borrow
        if digit < 0:
            digit -= 6
            borrow = 1
        else:
            borrow = 0
        result |= (digit & 0xF) << shift
    return _finish(result, borrow == 0, overflow, mask, sign)


def compare(left: int, right: int, width: int) -> AluResult:
    return sbc_binary(left, right, 1, width)

