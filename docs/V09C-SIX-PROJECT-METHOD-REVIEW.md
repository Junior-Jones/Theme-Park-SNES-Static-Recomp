# 09C six-project method review

The six SNES recomp projects were consulted as process comparisons only. No game-specific code, address, ROM fact, generated body, trace, hash, acceptance claim or captured state was imported into Theme Park.

## Compared methods

- Rock n Roll Racing demonstrated the strongest relevant pattern: a context-keyed offline timing plan, timed instruction-byte fetches, bus-side effects at a defined access phase, named internal-cycle placement, and an observed-cycle reconciliation at retirement.
- Top Gear reinforced one machine-owned timeline and explicit rendezvous between the S-CPU and independently clocked audio work.
- SimCity reinforced that host presentation pace is not guest time and that subsystem clocks must remain behind the core boundary.
- Civilization reinforced keeping scheduler authority separate from frontend and renderer convenience paths.
- Jungle Strike contributed phase-aligned refresh, DMA-at-CPU-boundary ownership, rational clock remainders, and targeted boundary evidence. Its older prefix-idle approach was treated as a warning where it could move an idle before the wrong side effect.
- Gundam Wing provided the most useful negative lesson: if generated bodies expose bus effects but not enough phase information, execution must remain fail-closed rather than claim exact timing from an instruction total.

## Theme Park decisions

- Generate one Theme Park plan for every one of the 71,986 already-admitted contexts. The plan cannot admit a context and is not an opcode decoder.
- Time each instruction fetch, pointer read, data access, stack access and internal cycle in hardware order. Reads apply their side effect four master clocks before completion; writes apply it at completion.
- Preserve the pre-instruction CPU state for branch, direct-page and indexed-page timing decisions. Version 09 owns the exact cycle result instead of trusting an older aggregate cycle expression.
- Keep JSL's final operand fetch in its deferred hardware position, between stack activity, rather than fetching all four bytes as one untimed guard.
- Give NMI, IRQ, WAI wake, STP, RESET, refresh, DMA/HDMA rendezvous, auto-joypad phases and independent clock-domain remainders one machine/scheduler owner.
- Use the PAL target profile and integer/rational joins. No fixed-60-Hz, frame-step or frontend clock is allowed to advance guest hardware.

The Mesen oracle was not used. No executable or frontend was created.
