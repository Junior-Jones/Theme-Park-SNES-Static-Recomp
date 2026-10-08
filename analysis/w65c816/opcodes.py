"""Complete W65C816 opcode topology from WDC W65C816S Table 5-4.

This module is an offline decoder/proof input. Production selection is forbidden.
The table is a project transcription of WDC W65C816S datasheet Table 5-4.
"""
from __future__ import annotations

from dataclasses import dataclass

from .state import legal_modes


@dataclass(frozen=True)
class Opcode:
    value: int
    mnemonic: str
    mode: str
    base_cycles: int


ROWS = (
    "BRK:SIG8:7 ORA:DP_X_IND:6 COP:SIG8:7 ORA:STACK_REL:4 TSB:DP:5 ORA:DP:3 ASL:DP:5 ORA:DP_IND_LONG:6 PHP:IMP:3 ORA:IMM_M:2 ASL:ACC:2 PHD:IMP:4 TSB:ABS:6 ORA:ABS:4 ASL:ABS:6 ORA:ABSL:5",
    "BPL:REL8:2 ORA:DP_IND_Y:5 ORA:DP_IND:5 ORA:STACK_REL_IND_Y:7 TRB:DP:5 ORA:DP_X:4 ASL:DP_X:6 ORA:DP_IND_LONG_Y:6 CLC:IMP:2 ORA:ABS_Y:4 INC:ACC:2 TCS:IMP:2 TRB:ABS:6 ORA:ABS_X:4 ASL:ABS_X:7 ORA:ABSL_X:5",
    "JSR:ABS_JUMP:6 AND:DP_X_IND:6 JSL:ABSL_JUMP:8 AND:STACK_REL:4 BIT:DP:3 AND:DP:3 ROL:DP:5 AND:DP_IND_LONG:6 PLP:IMP:4 AND:IMM_M:2 ROL:ACC:2 PLD:IMP:5 BIT:ABS:4 AND:ABS:4 ROL:ABS:6 AND:ABSL:5",
    "BMI:REL8:2 AND:DP_IND_Y:5 AND:DP_IND:5 AND:STACK_REL_IND_Y:7 BIT:DP_X:4 AND:DP_X:4 ROL:DP_X:6 AND:DP_IND_LONG_Y:6 SEC:IMP:2 AND:ABS_Y:4 DEC:ACC:2 TSC:IMP:2 BIT:ABS_X:4 AND:ABS_X:4 ROL:ABS_X:7 AND:ABSL_X:5",
    "RTI:IMP:7 EOR:DP_X_IND:6 WDM:SIG8:2 EOR:STACK_REL:4 MVP:BLOCK_MOVE:7 EOR:DP:3 LSR:DP:5 EOR:DP_IND_LONG:6 PHA:IMP:3 EOR:IMM_M:2 LSR:ACC:2 PHK:IMP:3 JMP:ABS_JUMP:3 EOR:ABS:4 LSR:ABS:6 EOR:ABSL:5",
    "BVC:REL8:2 EOR:DP_IND_Y:5 EOR:DP_IND:5 EOR:STACK_REL_IND_Y:7 MVN:BLOCK_MOVE:7 EOR:DP_X:4 LSR:DP_X:6 EOR:DP_IND_LONG_Y:6 CLI:IMP:2 EOR:ABS_Y:4 PHY:IMP:3 TCD:IMP:2 JMP:ABSL_JUMP:4 EOR:ABS_X:4 LSR:ABS_X:7 EOR:ABSL_X:5",
    "RTS:IMP:6 ADC:DP_X_IND:6 PER:REL16:6 ADC:STACK_REL:4 STZ:DP:3 ADC:DP:3 ROR:DP:5 ADC:DP_IND_LONG:6 PLA:IMP:4 ADC:IMM_M:2 ROR:ACC:2 RTL:IMP:6 JMP:ABS_IND:5 ADC:ABS:4 ROR:ABS:6 ADC:ABSL:5",
    "BVS:REL8:2 ADC:DP_IND_Y:5 ADC:DP_IND:5 ADC:STACK_REL_IND_Y:7 STZ:DP_X:4 ADC:DP_X:4 ROR:DP_X:6 ADC:DP_IND_LONG_Y:6 SEI:IMP:2 ADC:ABS_Y:4 PLY:IMP:4 TDC:IMP:2 JMP:ABS_X_IND:6 ADC:ABS_X:4 ROR:ABS_X:7 ADC:ABSL_X:5",
    "BRA:REL8:2 STA:DP_X_IND:6 BRL:REL16:4 STA:STACK_REL:4 STY:DP:3 STA:DP:3 STX:DP:3 STA:DP_IND_LONG:6 DEY:IMP:2 BIT:IMM_M:2 TXA:IMP:2 PHB:IMP:3 STY:ABS:4 STA:ABS:4 STX:ABS:4 STA:ABSL:5",
    "BCC:REL8:2 STA:DP_IND_Y:6 STA:DP_IND:5 STA:STACK_REL_IND_Y:7 STY:DP_X:4 STA:DP_X:4 STX:DP_Y:4 STA:DP_IND_LONG_Y:6 TYA:IMP:2 STA:ABS_Y:5 TXS:IMP:2 TXY:IMP:2 STZ:ABS:4 STA:ABS_X:5 STZ:ABS_X:5 STA:ABSL_X:5",
    "LDY:IMM_X:2 LDA:DP_X_IND:6 LDX:IMM_X:2 LDA:STACK_REL:4 LDY:DP:3 LDA:DP:3 LDX:DP:3 LDA:DP_IND_LONG:6 TAY:IMP:2 LDA:IMM_M:2 TAX:IMP:2 PLB:IMP:4 LDY:ABS:4 LDA:ABS:4 LDX:ABS:4 LDA:ABSL:5",
    "BCS:REL8:2 LDA:DP_IND_Y:5 LDA:DP_IND:5 LDA:STACK_REL_IND_Y:7 LDY:DP_X:4 LDA:DP_X:4 LDX:DP_Y:4 LDA:DP_IND_LONG_Y:6 CLV:IMP:2 LDA:ABS_Y:4 TSX:IMP:2 TYX:IMP:2 LDY:ABS_X:4 LDA:ABS_X:4 LDX:ABS_Y:4 LDA:ABSL_X:5",
    "CPY:IMM_X:2 CMP:DP_X_IND:6 REP:IMM8:3 CMP:STACK_REL:4 CPY:DP:3 CMP:DP:3 DEC:DP:5 CMP:DP_IND_LONG:6 INY:IMP:2 CMP:IMM_M:2 DEX:IMP:2 WAI:IMP:3 CPY:ABS:4 CMP:ABS:4 DEC:ABS:6 CMP:ABSL:5",
    "BNE:REL8:2 CMP:DP_IND_Y:5 CMP:DP_IND:5 CMP:STACK_REL_IND_Y:7 PEI:DP_IND:6 CMP:DP_X:4 DEC:DP_X:6 CMP:DP_IND_LONG_Y:6 CLD:IMP:2 CMP:ABS_Y:4 PHX:IMP:3 STP:IMP:3 JML:ABS_IND_LONG:6 CMP:ABS_X:4 DEC:ABS_X:7 CMP:ABSL_X:5",
    "CPX:IMM_X:2 SBC:DP_X_IND:6 SEP:IMM8:3 SBC:STACK_REL:4 CPX:DP:3 SBC:DP:3 INC:DP:5 SBC:DP_IND_LONG:6 INX:IMP:2 SBC:IMM_M:2 NOP:IMP:2 XBA:IMP:3 CPX:ABS:4 SBC:ABS:4 INC:ABS:6 SBC:ABSL:5",
    "BEQ:REL8:2 SBC:DP_IND_Y:5 SBC:DP_IND:5 SBC:STACK_REL_IND_Y:7 PEA:IMM16:5 SBC:DP_X:4 INC:DP_X:6 SBC:DP_IND_LONG_Y:6 SED:IMP:2 SBC:ABS_Y:4 PLX:IMP:4 XCE:IMP:2 JSR:ABS_X_IND:8 SBC:ABS_X:4 INC:ABS_X:7 SBC:ABSL_X:5",
)


def _build() -> tuple[Opcode, ...]:
    result = []
    for row_index, row in enumerate(ROWS):
        cells = row.split()
        if len(cells) != 16:
            raise AssertionError(f"opcode row {row_index:X} has {len(cells)} cells")
        for column, cell in enumerate(cells):
            mnemonic, mode, cycles_text = cell.split(":")
            result.append(Opcode((row_index << 4) | column, mnemonic, mode, int(cycles_text)))
    if [item.value for item in result] != list(range(256)):
        raise AssertionError("opcode table is not complete and ordered")
    return tuple(result)


OPCODES = _build()

FIXED_LENGTHS = {
    "IMP": 1, "ACC": 1,
    "SIG8": 2, "IMM8": 2, "DP": 2, "DP_X": 2, "DP_Y": 2,
    "DP_IND": 2, "DP_X_IND": 2, "DP_IND_Y": 2, "DP_IND_LONG": 2,
    "DP_IND_LONG_Y": 2, "STACK_REL": 2, "STACK_REL_IND_Y": 2, "REL8": 2,
    "ABS": 3, "ABS_X": 3, "ABS_Y": 3, "ABS_JUMP": 3, "ABS_IND": 3,
    "ABS_IND_LONG": 3, "ABS_X_IND": 3, "REL16": 3, "IMM16": 3,
    "BLOCK_MOVE": 3, "ABSL": 4, "ABSL_X": 4, "ABSL_JUMP": 4,
}


def instruction_length(opcode: int, *, e: int, m: int, x: int) -> int:
    if not 0 <= opcode <= 0xFF:
        raise ValueError("opcode outside byte domain")
    if (e, m, x) not in legal_modes():
        raise ValueError("illegal E/M/X mode")
    mode = OPCODES[opcode].mode
    if mode == "IMM_M":
        return 2 if m else 3
    if mode == "IMM_X":
        return 2 if x else 3
    try:
        return FIXED_LENGTHS[mode]
    except KeyError as error:
        raise AssertionError(f"unowned addressing mode: {mode}") from error


def iter_legal_contexts():
    for opcode in OPCODES:
        for e, m, x in legal_modes():
            yield opcode, e, m, x, instruction_length(opcode.value, e=e, m=m, x=x)

