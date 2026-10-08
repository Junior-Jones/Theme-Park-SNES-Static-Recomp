"""Bank-zero stack and interrupt-frame rules from WDC tables 5-2, 5-3 and 5-7."""
from __future__ import annotations

from dataclasses import dataclass, replace

from .cpu_state import C, D, I, M, X, CpuState, set_status


NATIVE_VECTORS = {"COP": 0xFFE4, "BRK": 0xFFE6, "ABORT": 0xFFE8, "NMI": 0xFFEA, "IRQ": 0xFFEE}
EMULATION_VECTORS = {"COP": 0xFFF4, "ABORT": 0xFFF8, "NMI": 0xFFFA, "RESET": 0xFFFC,
                     "IRQ": 0xFFFE, "BRK": 0xFFFE}


@dataclass(frozen=True)
class StackWrite:
    address: int
    value: int


@dataclass(frozen=True)
class InterruptEntry:
    state: CpuState
    writes: tuple[StackWrite, ...]
    vector: int


@dataclass(frozen=True)
class TerminalSignalResult:
    state: CpuState
    woke: bool
    service: str | None
    aborted_wai: bool = False


def stack_step(s: int, delta: int, e: int) -> int:
    if not 0 <= s <= 0xFFFF or delta not in (-1, 1) or e not in (0, 1):
        raise ValueError("invalid stack step")
    if e:
        return 0x0100 | ((s + delta) & 0xFF)
    return (s + delta) & 0xFFFF


def push_bytes(state: CpuState, values: tuple[int, ...]) -> tuple[tuple[StackWrite, ...], CpuState]:
    s = state.s
    writes = []
    for value in values:
        if not 0 <= value <= 0xFF:
            raise ValueError("stack byte outside domain")
        writes.append(StackWrite(s, value))
        s = stack_step(s, -1, state.e)
    return tuple(writes), replace(state, s=s)


def pull_addresses(state: CpuState, count: int) -> tuple[tuple[int, ...], CpuState]:
    if count < 0:
        raise ValueError("negative pull count")
    s = state.s
    addresses = []
    for _ in range(count):
        s = stack_step(s, 1, state.e)
        addresses.append(s)
    return tuple(addresses), replace(state, s=s)


def interrupt_vector(kind: str, e: int) -> int:
    if e not in (0, 1):
        raise ValueError("E outside bit domain")
    table = EMULATION_VECTORS if e else NATIVE_VECTORS
    try:
        return table[kind]
    except KeyError as error:
        raise ValueError(f"unsupported interrupt kind {kind}") from error


def interrupt_entry(state: CpuState, kind: str, return_pc: int, target_pc: int) -> InterruptEntry:
    if kind not in ("BRK", "COP", "ABORT", "NMI", "IRQ"):
        raise ValueError("unsupported interrupt kind")
    if not 0 <= return_pc <= 0xFFFF or not 0 <= target_pc <= 0xFFFF:
        raise ValueError("PC outside word domain")
    pushed_p = state.p
    if state.e:
        if kind in ("BRK", "COP"):
            pushed_p |= 0x10
        else:
            pushed_p &= ~0x10
        values = ((return_pc >> 8) & 0xFF, return_pc & 0xFF, pushed_p)
    else:
        values = (state.pbr, (return_pc >> 8) & 0xFF, return_pc & 0xFF, pushed_p)
    writes, after_stack = push_bytes(state, values)
    entered = replace(after_stack, pc=target_pc, pbr=0, p=(state.p | I) & ~D, waiting=False).normalized()
    return InterruptEntry(entered, writes, interrupt_vector(kind, state.e))


def rti(state: CpuState, values: tuple[int, ...]) -> CpuState:
    expected = 3 if state.e else 4
    if len(values) != expected or any(not 0 <= value <= 0xFF for value in values):
        raise ValueError("RTI pull frame does not match mode")
    _, after_pull = pull_addresses(state, expected)
    p, pcl, pch = values[:3]
    pbr = state.pbr if state.e else values[3]
    return set_status(replace(after_pull, pc=pcl | (pch << 8), pbr=pbr), p)


def wai(state: CpuState) -> CpuState:
    return replace(state, waiting=True)


def stp(state: CpuState) -> CpuState:
    return replace(state, stopped=True, waiting=False)


def terminal_signal(state: CpuState, signal: str) -> TerminalSignalResult:
    """Apply an external signal to WAI/STP terminal state.

    This owns wake/service classification only.  Reset register mutation and
    interrupt entry frames remain in their respective later/core operations.
    WDC 7.13 specifies that ABORT aborts WAI without restarting the processor.
    """
    if signal not in ("RESET", "ABORT", "NMI", "IRQ"):
        raise ValueError("unsupported terminal signal")
    if state.stopped:
        if signal == "RESET":
            return TerminalSignalResult(replace(state, stopped=False, waiting=False), True, "RESET")
        return TerminalSignalResult(state, False, None)
    if not state.waiting:
        if signal == "RESET":
            return TerminalSignalResult(state, False, "RESET")
        if signal == "NMI":
            return TerminalSignalResult(state, False, "NMI")
        if signal == "IRQ" and not (state.p & I):
            return TerminalSignalResult(state, False, "IRQ")
        if signal == "ABORT":
            return TerminalSignalResult(state, False, "ABORT")
        return TerminalSignalResult(state, False, None)
    if signal == "ABORT":
        return TerminalSignalResult(state, False, None, aborted_wai=True)
    resumed = replace(state, waiting=False)
    if signal == "IRQ" and (state.p & I):
        return TerminalSignalResult(resumed, True, None)
    return TerminalSignalResult(resumed, True, signal)
