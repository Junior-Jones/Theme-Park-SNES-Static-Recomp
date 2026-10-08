# Theme Park 13C S-SMP understanding record

## Source epoch and fixed point

The cartridge-owned upload reconstructed in 12C supplies epoch 1 at `$0300-$103A`, with static entry `$0300`. Offline recursive discovery reached a cold source fixed point of 1,392 exact instruction starts, 2,683 instruction bytes, 78 opcode forms, and 1,592 conservative edges. No instruction bytes overlap and no frontier remains.

Three computed jumps are finite source tables:

- `$0382` indexes 21 words at `$0454` with the S-CPU command selector `0..20`;
- `$088F` indexes 16 words at `$0A51` with the event-record selector `0..15`;
- `$0B7B` indexes 16 words at `$0C30` with the driver-operation selector `0..15`.

The generated bodies require an even in-range selector and re-read/compare the source-owned table word before accepting its fixed target. The 106 table bytes join the 2,683 instruction bytes in the epoch write barrier, for 2,789 protected control-flow bytes.

## Control and machine behavior

The graph contains 92 call sites, 29 return instructions, 87 conditional branches, 31 unconditional branches, and 26 jumps. CALL pushes high then low return bytes and also enters the same return in a static shadow stack. RET pops low then high and must equal the most recent proved call return. Unknown PCs and unrelated valid-looking return PCs therefore do not become authority.

Direct page follows PSW.P; direct-page words wrap within the selected page. Indexed 16-bit addresses wrap naturally. Arithmetic implements N/Z/C/H/V behavior for the reached ADC, SBC, ADDW, compare, shift and rotate forms. Stack traffic remains ordinary mutable ARAM and is separate from the proof shadow.

The reached program accesses `$F2/$F3` for S-DSP address/data and `$F4-$F7` for directional ports. `$F3` remains an intentional fail-closed 16C boundary, so 13C makes no sound or PCM claim. No exact discovered instruction directly reaches CONTROL, TEST/CLOCK, timer targets, or timer outputs; their 12C architectural owner remains present without a false source-reached claim.

Each exact-PC body validates all instruction bytes, latches branch choice and cycle count, advances the independent 1.024 MHz domain with timers in the same increments, then commits the fixed semantic. This is instruction-boundary cycle scheduling; later whole-machine reconciliation must not relabel it as universal microcycle/bus accuracy.

## Failure and mutation policy

Unknown PC, changed instruction byte, changed computed-jump word, out-of-domain table selector, return-stack mismatch, unemitted semantic, unknown required ARAM data, and writes to protected epoch-1 bytes all stop. A changed executable/control-flow byte requires a separately discovered epoch; there is no runtime decoder, learning path, or interpreter fallback.
