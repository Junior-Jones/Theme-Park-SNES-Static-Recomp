"""Pure W65C816 address-formation rules for offline semantic proof."""
from __future__ import annotations


def _u8(value: int, name: str) -> int:
    if not 0 <= value <= 0xFF:
        raise ValueError(f"{name} outside byte domain")
    return value


def _u16(value: int, name: str) -> int:
    if not 0 <= value <= 0xFFFF:
        raise ValueError(f"{name} outside word domain")
    return value


def _u24(value: int, name: str) -> int:
    if not 0 <= value <= 0xFFFFFF:
        raise ValueError(f"{name} outside 24-bit domain")
    return value


def program_advance(pbr: int, pc: int, amount: int) -> int:
    _u8(pbr, "PBR")
    _u16(pc, "PC")
    if amount < 0:
        raise ValueError("negative program advance")
    return (pbr << 16) | ((pc + amount) & 0xFFFF)


def relative_target(pbr: int, next_pc: int, displacement: int, bits: int) -> int:
    _u8(pbr, "PBR")
    _u16(next_pc, "next PC")
    if bits not in (8, 16):
        raise ValueError("relative displacement width must be 8 or 16")
    mask = (1 << bits) - 1
    if not 0 <= displacement <= mask:
        raise ValueError("relative displacement outside selected width")
    signed = displacement - (1 << bits) if displacement & (1 << (bits - 1)) else displacement
    return (pbr << 16) | ((next_pc + signed) & 0xFFFF)


def absolute_data(dbr: int, operand: int) -> int:
    return (_u8(dbr, "DBR") << 16) | _u16(operand, "absolute operand")


def absolute_indexed(dbr: int, operand: int, index: int) -> int:
    base = absolute_data(dbr, operand)
    _u16(index, "index")
    return (base + index) & 0xFFFFFF


def absolute_long(bank: int, operand: int) -> int:
    return (_u8(bank, "bank") << 16) | _u16(operand, "long operand")


def absolute_long_indexed(bank: int, operand: int, index: int) -> int:
    _u16(index, "index")
    return (absolute_long(bank, operand) + index) & 0xFFFFFF


def direct_address(d: int, offset: int, *, index: int = 0, e: int = 0) -> int:
    _u16(d, "D")
    _u8(offset, "direct offset")
    _u16(index, "index")
    if e not in (0, 1):
        raise ValueError("E must be a bit")
    if e and (d & 0xFF) == 0:
        return (d & 0xFF00) | ((offset + index) & 0xFF)
    return (d + offset + index) & 0xFFFF


def direct_pointer_byte_addresses(
    d: int, offset: int, *, byte_count: int, e: int, long_or_pei: bool = False, index: int = 0
) -> tuple[int, ...]:
    if byte_count not in (2, 3):
        raise ValueError("pointer width must be two or three bytes")
    base = direct_address(d, offset, index=index, e=e)
    if e and (d & 0xFF) == 0 and not long_or_pei:
        page = base & 0xFF00
        return tuple(page | ((base + position) & 0xFF) for position in range(byte_count))
    return tuple((base + position) & 0xFFFF for position in range(byte_count))


def indirect16(dbr: int, low: int, high: int) -> int:
    return (_u8(dbr, "DBR") << 16) | (_u8(low, "pointer low") | (_u8(high, "pointer high") << 8))


def indirect24(low: int, high: int, bank: int) -> int:
    return _u8(low, "pointer low") | (_u8(high, "pointer high") << 8) | (_u8(bank, "pointer bank") << 16)


def indirect_indexed(base: int, index: int) -> int:
    _u24(base, "indirect base")
    _u16(index, "index")
    return (base + index) & 0xFFFFFF


def stack_relative(s: int, offset: int) -> int:
    return (_u16(s, "S") + _u8(offset, "stack offset")) & 0xFFFF


def absolute_indirect_pointer_addresses(operand: int, *, pbr: int | None = None, index: int = 0, count: int = 2) -> tuple[int, ...]:
    _u16(operand, "absolute indirect operand")
    _u16(index, "index")
    if count not in (2, 3):
        raise ValueError("pointer count must be two or three")
    bank = 0 if pbr is None else _u8(pbr, "PBR")
    base = (operand + index) & 0xFFFF
    return tuple((bank << 16) | ((base + position) & 0xFFFF) for position in range(count))

