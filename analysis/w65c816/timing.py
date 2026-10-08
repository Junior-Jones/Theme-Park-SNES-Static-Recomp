"""WDC Table 5-4/5-7 timing rules for legal opcode contexts.

The annotation is proof metadata.  ``cycle_count`` is the executable timing
contract and requires callers to supply every run-time condition which can
change the result; it never silently assumes that a conditional cycle did not
happen.
"""
from __future__ import annotations

from dataclasses import dataclass

from .opcodes import OPCODES
from .state import legal_modes

DIRECT_MODES = frozenset(mode for mode in {item.mode for item in OPCODES} if mode.startswith("DP"))
CONDITIONAL_BRANCHES = frozenset(("BCC", "BCS", "BEQ", "BMI", "BNE", "BPL", "BVC", "BVS"))
M_WIDTH = frozenset(("ADC", "AND", "ASL", "BIT", "CMP", "DEC", "EOR", "INC", "LDA", "LSR",
                     "ORA", "ROL", "ROR", "SBC", "STA", "STZ", "TRB", "TSB"))
X_WIDTH = frozenset(("CPX", "CPY", "LDX", "LDY", "STX", "STY"))
RMW = frozenset(("ASL", "DEC", "INC", "LSR", "ROL", "ROR", "TRB", "TSB"))
PAGE_CROSS_READ = frozenset(("ADC", "AND", "BIT", "CMP", "EOR", "LDA", "LDX", "LDY", "ORA", "SBC"))
PAGE_CROSS_MODES = frozenset(("ABS_X", "ABS_Y", "DP_IND_Y"))


@dataclass(frozen=True)
class TimingAnnotation:
    base_cycles: int
    rules: tuple[str, ...]


@dataclass(frozen=True)
class TimingConditions:
    direct_low_nonzero: bool = False
    branch_taken: bool = False
    branch_page_crossed: bool = False
    index_page_crossed: bool = False


def cycle_count(opcode: int, *, e: int, m: int, x: int,
                conditions: TimingConditions = TimingConditions()) -> int:
    """Return completed-instruction cycles from WDC Table 5-4/5-7.

    WAI's unbounded wait and MVN/MVP repetition are deliberately outside this
    single-completion count.  Their annotations name those state-machine
    behaviours explicitly.
    """
    annotation = timing_annotation(opcode, e=e, m=m, x=x)
    item = OPCODES[opcode]
    cycles = annotation.base_cycles
    if item.mode in DIRECT_MODES and conditions.direct_low_nonzero:
        cycles += 1
    if item.mnemonic in CONDITIONAL_BRANCHES:
        if conditions.branch_page_crossed and not conditions.branch_taken:
            raise ValueError("an untaken branch cannot cross a page")
        if conditions.branch_taken:
            cycles += 1
            if e and conditions.branch_page_crossed:
                cycles += 1
    elif item.mnemonic == "BRA":
        cycles += 1
        if e and conditions.branch_page_crossed:
            cycles += 1
    elif conditions.branch_taken or conditions.branch_page_crossed:
        raise ValueError("branch conditions supplied for a non-branch opcode")
    if item.mnemonic in PAGE_CROSS_READ and item.mode in PAGE_CROSS_MODES:
        # Table 5-7 note 4: the optional index-add cycle becomes mandatory
        # either on a page crossing or with a 16-bit index register (X=0).
        if conditions.index_page_crossed or not x:
            cycles += 1
    elif conditions.index_page_crossed:
        raise ValueError("page-cross condition supplied where timing is fixed")
    if item.mnemonic in M_WIDTH and not m:
        cycles += 2 if item.mnemonic in RMW and item.mode != "ACC" else 1
    if item.mnemonic in X_WIDTH and not x:
        cycles += 1
    if item.mnemonic in ("PHA", "PLA") and not m:
        cycles += 1
    if item.mnemonic in ("PHX", "PHY", "PLX", "PLY") and not x:
        cycles += 1
    # Table 5-7 uses seven cycles as RTI's native base and note 7 removes the
    # PBR pull in emulation mode.  BRK/COP conversely gain the PBR push in
    # native mode over their seven-cycle emulation base.
    if item.mnemonic == "RTI" and e:
        cycles -= 1
    if item.mnemonic in ("BRK", "COP") and not e:
        cycles += 1
    return cycles


def timing_annotation(opcode: int, *, e: int, m: int, x: int) -> TimingAnnotation:
    if not 0 <= opcode <= 0xFF or (e, m, x) not in legal_modes():
        raise ValueError("invalid opcode or E/M/X mode")
    item = OPCODES[opcode]
    rules = []
    if item.mnemonic in CONDITIONAL_BRANCHES:
        rules.append("branch_taken:+1")
        rules.append("branch_taken_page_cross_e1:+1")
    if item.mnemonic == "BRA":
        rules.append("always_taken:+1")
        rules.append("page_cross_e1:+1")
    if item.mode in DIRECT_MODES:
        rules.append("direct_low_nonzero:+1")
    if item.mnemonic in PAGE_CROSS_READ and item.mode in PAGE_CROSS_MODES:
        rules.append("page_cross_or_x16:+1")
    if item.mnemonic in M_WIDTH and not m:
        rules.append("m16:+2_rmw_else_+1" if item.mnemonic in RMW and item.mode != "ACC" else "m16:+1")
    if item.mnemonic in X_WIDTH and not x:
        rules.append("x16:+1")
    if item.mnemonic in ("PHA", "PLA") and not m:
        rules.append("m16:+1")
    if item.mnemonic in ("PHX", "PHY", "PLX", "PLY") and not x:
        rules.append("x16:+1")
    if item.mnemonic in ("MVN", "MVP"):
        rules.append("repeat_until_A_underflows:7_each_byte")
    if item.mnemonic == "RTI":
        rules.append("e1:-1")
    if item.mnemonic in ("BRK", "COP"):
        rules.append("native_pbr_push:+1")
    if item.mnemonic == "WAI":
        rules.append("wait_at_cycle_2_until_interrupt_signal")
    if item.mnemonic == "STP":
        rules.append("stopped_until_reset")
    return TimingAnnotation(item.base_cycles, tuple(rules))
