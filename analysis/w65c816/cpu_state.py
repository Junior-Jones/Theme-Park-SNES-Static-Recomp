"""Width/status transitions used by offline W65C816 semantic proofs."""
from __future__ import annotations

from dataclasses import dataclass, replace

N, V, M, X, D, I, Z, C = (0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01)


@dataclass(frozen=True)
class CpuState:
    a: int = 0
    x: int = 0
    y: int = 0
    s: int = 0x01FF
    d: int = 0
    dbr: int = 0
    pbr: int = 0
    pc: int = 0
    p: int = M | X | I
    e: int = 1
    waiting: bool = False
    stopped: bool = False

    def normalized(self) -> "CpuState":
        fields = (self.a, self.x, self.y, self.s, self.d, self.pc)
        if any(not 0 <= value <= 0xFFFF for value in fields):
            raise ValueError("word register outside domain")
        if any(not 0 <= value <= 0xFF for value in (self.dbr, self.pbr, self.p)):
            raise ValueError("byte register outside domain")
        if self.e not in (0, 1):
            raise ValueError("E outside bit domain")
        p, x_value, y_value, s_value = self.p, self.x, self.y, self.s
        if self.e:
            p |= M | X
            s_value = 0x0100 | (s_value & 0xFF)
        if p & X:
            x_value &= 0xFF
            y_value &= 0xFF
        return replace(self, p=p, x=x_value, y=y_value, s=s_value)

    @property
    def m8(self) -> bool:
        return bool(self.p & M)

    @property
    def x8(self) -> bool:
        return bool(self.p & X)


def set_status(state: CpuState, new_p: int) -> CpuState:
    if not 0 <= new_p <= 0xFF:
        raise ValueError("status outside byte domain")
    return replace(state, p=new_p).normalized()


def rep(state: CpuState, mask: int) -> CpuState:
    if not 0 <= mask <= 0xFF:
        raise ValueError("REP mask outside byte domain")
    return set_status(state, state.p & ~mask)


def sep(state: CpuState, mask: int) -> CpuState:
    if not 0 <= mask <= 0xFF:
        raise ValueError("SEP mask outside byte domain")
    return set_status(state, state.p | mask)


def xce(state: CpuState) -> CpuState:
    old_e = state.e
    old_c = 1 if state.p & C else 0
    p = (state.p | C) if old_e else (state.p & ~C)
    return replace(state, p=p, e=old_c).normalized()


def accumulator_write(state: CpuState, value: int) -> CpuState:
    if state.m8:
        if not 0 <= value <= 0xFF:
            raise ValueError("8-bit accumulator write outside byte domain")
        return replace(state, a=(state.a & 0xFF00) | value)
    if not 0 <= value <= 0xFFFF:
        raise ValueError("16-bit accumulator write outside word domain")
    return replace(state, a=value)


def index_write(state: CpuState, register: str, value: int) -> CpuState:
    if register not in ("x", "y"):
        raise ValueError("index register must be x or y")
    limit = 0xFF if state.x8 else 0xFFFF
    if not 0 <= value <= limit:
        raise ValueError("index write outside active width")
    return replace(state, **{register: value})


def with_nz(state: CpuState, value: int, width: int) -> CpuState:
    if width not in (8, 16) or not 0 <= value < (1 << width):
        raise ValueError("N/Z value outside selected width")
    p = state.p & ~(N | Z)
    if value == 0:
        p |= Z
    if value & (1 << (width - 1)):
        p |= N
    return replace(state, p=p)


def transfer(state: CpuState, mnemonic: str) -> CpuState:
    """Apply the twelve register-transfer families with their owning width."""
    if mnemonic in ("TAX", "TAY"):
        register = mnemonic[-1].lower()
        width = 8 if state.x8 else 16
        value = state.a & ((1 << width) - 1)
        return with_nz(index_write(state, register, value), value, width)
    if mnemonic in ("TXA", "TYA"):
        value = getattr(state, mnemonic[1].lower()) & (0xFF if state.m8 else 0xFFFF)
        return with_nz(accumulator_write(state, value), value, 8 if state.m8 else 16)
    if mnemonic in ("TXY", "TYX"):
        source, destination = mnemonic[1].lower(), mnemonic[2].lower()
        width = 8 if state.x8 else 16
        value = getattr(state, source) & ((1 << width) - 1)
        return with_nz(index_write(state, destination, value), value, width)
    if mnemonic == "TSX":
        width = 8 if state.x8 else 16
        value = state.s & ((1 << width) - 1)
        return with_nz(index_write(state, "x", value), value, width)
    if mnemonic == "TXS":
        return replace(state, s=state.x).normalized()
    if mnemonic == "TCS":
        return replace(state, s=state.a).normalized()
    if mnemonic == "TSC":
        return with_nz(replace(state, a=state.s), state.s, 16)
    if mnemonic == "TCD":
        return with_nz(replace(state, d=state.a), state.a, 16)
    if mnemonic == "TDC":
        return with_nz(replace(state, a=state.d), state.d, 16)
    raise ValueError("not a register-transfer mnemonic")


def xba(state: CpuState) -> CpuState:
    value = ((state.a & 0xFF) << 8) | (state.a >> 8)
    return with_nz(replace(state, a=value), value & 0xFF, 8)


def block_move_step(state: CpuState, mnemonic: str, destination_bank: int) -> tuple[CpuState, bool]:
    if mnemonic not in ("MVN", "MVP") or not 0 <= destination_bank <= 0xFF:
        raise ValueError("invalid block move")
    delta = 1 if mnemonic == "MVN" else -1
    index_mask = 0xFF if state.x8 else 0xFFFF
    next_a = (state.a - 1) & 0xFFFF
    moved = replace(state, a=next_a, x=(state.x + delta) & index_mask,
                    y=(state.y + delta) & index_mask, dbr=destination_bank).normalized()
    return moved, next_a != 0xFFFF


def flag_instruction(state: CpuState, mnemonic: str) -> CpuState:
    changes = {"CLC": (C, False), "SEC": (C, True), "CLD": (D, False), "SED": (D, True),
               "CLI": (I, False), "SEI": (I, True), "CLV": (V, False)}
    if mnemonic not in changes:
        raise ValueError("not a flag instruction")
    mask, enabled = changes[mnemonic]
    return replace(state, p=(state.p | mask) if enabled else (state.p & ~mask))

