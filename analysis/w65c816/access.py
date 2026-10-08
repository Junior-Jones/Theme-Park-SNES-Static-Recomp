"""Width-explicit abstract bus-access annotations for every legal opcode context."""
from __future__ import annotations

from dataclasses import dataclass

from .opcodes import OPCODES, instruction_length
from .state import legal_modes

READ = frozenset(("ADC", "AND", "BIT", "CMP", "CPX", "CPY", "EOR", "LDA", "LDX", "LDY", "ORA", "SBC"))
WRITE = frozenset(("STA", "STX", "STY", "STZ"))
RMW = frozenset(("ASL", "DEC", "INC", "LSR", "ROL", "ROR", "TRB", "TSB"))
M_WIDTH = frozenset(("ADC", "AND", "ASL", "BIT", "CMP", "DEC", "EOR", "INC", "LDA", "LSR", "ORA",
                     "ROL", "ROR", "SBC", "STA", "STZ", "TRB", "TSB"))
X_WIDTH = frozenset(("CPX", "CPY", "LDX", "LDY", "STX", "STY"))
PUSH = frozenset(("PEA", "PEI", "PER", "PHA", "PHB", "PHD", "PHK", "PHP", "PHX", "PHY"))
PULL = frozenset(("PLA", "PLB", "PLD", "PLP", "PLX", "PLY"))
CONTROL = frozenset(("BCC", "BCS", "BEQ", "BMI", "BNE", "BPL", "BRA", "BRK", "BRL", "BVC", "BVS",
                     "COP", "JML", "JMP", "JSL", "JSR", "RTI", "RTL", "RTS", "STP", "WAI"))
INDIRECT_16 = frozenset(("DP_IND", "DP_X_IND", "DP_IND_Y", "STACK_REL_IND_Y", "ABS_IND", "ABS_X_IND"))
INDIRECT_24 = frozenset(("DP_IND_LONG", "DP_IND_LONG_Y", "ABS_IND_LONG"))


@dataclass(frozen=True)
class AccessProfile:
    instruction_bytes: int
    operand_access: str
    operand_bytes: int
    pointer_bytes: int
    stack_effect: str
    control_effect: bool
    rmw_write_order: str
    emulation_modify_cycle_is_write: bool


def access_profile(opcode: int, *, e: int, m: int, x: int) -> AccessProfile:
    if not 0 <= opcode <= 0xFF or (e, m, x) not in legal_modes():
        raise ValueError("invalid opcode or E/M/X mode")
    item = OPCODES[opcode]
    if item.mnemonic in READ:
        kind = "read"
    elif item.mnemonic in WRITE:
        kind = "write"
    elif item.mnemonic in RMW and item.mode != "ACC":
        kind = "read_modify_write"
    elif item.mnemonic in ("MVN", "MVP"):
        kind = "block_read_write"
    else:
        kind = "none"
    if kind == "none":
        operand_bytes = 0
    elif item.mnemonic in M_WIDTH:
        operand_bytes = 1 if m else 2
    elif item.mnemonic in X_WIDTH:
        operand_bytes = 1 if x else 2
    else:
        operand_bytes = 1
    pointer_bytes = 3 if item.mode in INDIRECT_24 else 2 if item.mode in INDIRECT_16 else 0
    if item.mnemonic in PUSH or item.mnemonic in ("JSL", "JSR", "BRK", "COP"):
        stack = "push"
    elif item.mnemonic in PULL or item.mnemonic in ("RTI", "RTL", "RTS"):
        stack = "pull"
    else:
        stack = "none"
    memory_rmw = kind == "read_modify_write"
    order = "HIGH_THEN_LOW" if memory_rmw and not m else "LOW" if memory_rmw else "NONE"
    return AccessProfile(instruction_length(opcode, e=e, m=m, x=x), kind, operand_bytes,
                         pointer_bytes, stack, item.mnemonic in CONTROL, order, bool(memory_rmw and e))
