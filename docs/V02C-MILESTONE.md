# Theme Park 02C — complete W65C816 semantic/offline decoder foundation

Status: CLOSED_REPAIRED. The earlier 61-test candidate and its withdrawn archive remain historical rejected evidence. Closure applies only to the repaired semantic hash and cumulative 01C→02C run recorded below.

The offline library accounts for all 256 W65C816 opcodes, 92 mnemonics, 30 encoded addressing-mode classes, and all 2,048 raw opcode/E/M/X rows. It admits the 1,280 architecturally legal rows and rejects the 768 contradictory emulation rows. Project-owned pure semantics cover widths and hidden B, index truncation, status transitions, binary/decimal arithmetic, logic, shifts/rotates, BIT/TRB/TSB, loads/stores, every transfer family, stack operations, calls/returns, interrupt frames/vectors, block moves, WAI/STP, NOP and WDM.

Address and access evidence covers bank and program-counter wrapping, direct-page emulation exceptions, pointer fetch widths, stack wrapping, memory access width, RMW access class, emulation modify-cycle writes, and 16-bit RMW high-then-low write order. WDC Table 5-4/5-7 timing is executable for width, direct-page, branch-taken, emulation branch page-cross, indexed page-cross/X=0, and BRK/COP/RTI mode differences. WAI/STP external-signal transitions distinguish masked IRQ resume, interrupt service, ABORT-without-restart, and reset-only STP recovery.

Invalid packed-BCD digits are not guessed: they fail closed with `UnprovedDecimalInput` because the frozen primary source does not qualify their result. This satisfies Starter's unproved-form failure rule without claiming unavailable hardware authority. Complete physical 24-bit bus-event scheduling remains owned by 08C; 02C supplies the CPU-visible access and ordering annotations that 08C must reconcile.

The governing primary input is the official WDC W65C816S datasheet dated 13 March 2024, SHA-256 `b9177e1b045d2c8a801d1b23619abb4e5b29b88868fa491df7296dbc0b13447e`. No Mesen, Snes9x, Rock implementation, ROM trace, captured CPU state, or other emulator semantic source was used.

The generic decoder is offline-only. `config/production-selection.json` remains empty and forbids both offline-analysis selection and runtime decoding. The semantic/lowerer/production matrix records 92 decoded semantic families, zero native lowerers, and zero production-reached families. Theme Park discovery begins only in 03C; lowering remains owned by 07C.

Verification: 64 V02C checks pass, including complete 8-bit binary and valid-BCD domains, complete 16-bit left-operand binary sweeps against boundary operands, all 10,000 valid four-digit BCD left operands against decimal boundaries, address/stack/interrupt edges, all 1,280 legal access profiles, conditional timing calculation, terminal-signal behavior, and fail-closed invalid forms. The same command first reruns all four 01C checks; its profile and census hashes remain unchanged. Repaired decoder semantic SHA-256: `914698dc0b12dea54229d3b319c9463d4a0c2d8211977dc655239935e954ddf9`.

Not claimed: Theme Park instruction discovery, exact contexts, dynamic targets, executable-RAM epochs, native lowering, production CPU execution, bus/runtime/hardware subsystems, renderer, audio, frontend, executable, gameplay, or release.
