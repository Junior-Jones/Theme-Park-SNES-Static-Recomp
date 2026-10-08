# 12C — S-SMP Bootstrap, APUIO, Timers, and ARAM Epoch

12C is closed at source and static-library level. It does not claim uploaded SPC700 execution, S-DSP behavior, PCM/audio output, pixels, completed frames, gameplay, frontend integration, or release acceptance.

## Theme Park evidence joined

- 21 exact `$2140-$2143` byte events across 18 contexts are bound to one directional APUIO owner.
- 5,457 conservative APUIO address intersections remain unresolved and non-authoritative.
- Theme Park's supported ROM contains one source-authored 3,387-byte upload block at physical `0x070313`, targeting ARAM `$0300-$103A`, followed by a zero-length terminator and static entry `$0300`.
- Independent record parsing and fixed-IPL protocol replay produce the same ARAM values and byte-knownness hash. No emulator or captured ARAM was used.

## Implemented bootstrap state

The owner supplies the immutable IPL mask-ROM overlay, AA/BB readiness, CC command rendezvous, byte counter acknowledgement, `expected + 3` terminator, directional APUIO latches, wide-store port ordering, 64 KiB ARAM with byte knownness, upload epoch accounting, S-SMP CONTROL/auxiliary registers, and three timers at 128/128/16-cycle rates with four-bit clear-on-read outputs. S-CPU RESET explicitly preserves the independently running S-SMP state.

At successful transfer control the owner records PC `$0300` and stops at `TP_APU_STATIC_ENTRY_REQUIRED`. Executing that program belongs to 13C exact-PC static SPC700 generation. `$00F3` remains fail-closed for the 16C S-DSP owner, and unsupported `$00F0` TEST/CLOCK writes fail closed.

## Static build boundary

Both selected C toolchains compiled 679 objects and archived complete static libraries. No executable was created. Verification authority is `docs/V12C-verification-summary.json`; upload authority is `docs/V12C-aram-epoch-receipt.json`; compiler authority is `docs/V12C-static-compile-receipt.json`.
