# 13C — Static S-SMP AOT and executable-ARAM closure

Status: closed at source/static-library level. No executable and no audio-output claim.

- Source-owned epoch 1: entry `$0300`, 1,392 exact PCs, 2,683 instruction bytes, 78 reached opcode forms, 1,592 edges, zero unresolved frontier.
- Computed control: three finite source tables, 53 targets total, with runtime selector and table-word guards.
- Generated authority: exact-PC byte-guarded begin/complete bodies, exact cycle totals, static call/return proof stack, and 2,789 protected instruction/control-flow bytes.
- Runtime integration: S-SMP domain advances generated instructions and 12C timers together; ports remain directional; changed authority bytes and all unknowns fail closed.
- Production purity: no runtime SPC700 decoder, interpreter, fallback, learning, oracle promotion, or foreign target authority.
- Deliberate boundary: reached `$F3` S-DSP data semantics remain fail closed for 16C. Therefore 13C does not claim PCM, sound, renderer output, gameplay, or a runnable executable.

The version gate is the named verifier and the two static-library receipts. 14C must not weaken any 13C epoch, return, or no-fallback boundary.
