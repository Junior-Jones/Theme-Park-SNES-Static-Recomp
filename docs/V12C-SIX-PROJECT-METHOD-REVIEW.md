# 12C Six-Project S-SMP Bootstrap Method Review

This review uses the six SNES recompilations only as process and architecture comparisons. Theme Park's verified ROM, 07C source events, 09C scheduler, and cartridge-owned upload bytes remain the only target authorities. No target program code, payload, hashes, completion records, or acceptance claims were copied.

| Project | Reusable method observed | Theme Park decision |
|---|---|---|
| Rock n Roll Racing | Separates a dedicated fixed-IPL protocol owner from later exact-PC SPC700 AOT; reconstructs ARAM and byte knownness from cartridge upload records. | Use a fixed bootstrap state machine only, retain unknown ARAM, and stop at the `$0300` 13C frontier. |
| Top Gear | Treats APUIO as directional latches synchronized at event-order clocks and shows why a 16-bit S-CPU store cannot acknowledge port 0 before port 1 has landed. | Bind APUIO to the 09C master scheduler and gate byte consumption by monotonic write order. |
| SimCity | Centralizes S-SMP MMIO, timer target/rate/read-clear behavior, port direction, and executable-memory epoch checks. | Keep all `$00F0-$00FF` ownership in one APU component and record upload epochs separately from later executed-code writes. |
| Civilization | Fails closed when production APUIO is reached before the audio owner is selected. | Make the 12C owner the sole `$2140-$2143` route; unsupported DSP/TEST behavior remains an explicit stop. |
| Jungle Strike | Preserves S-SMP/ARAM state across S-CPU RESET, proves only the IPL-cleared ARAM range, and commits upload data after the matching data-port write. | Add an explicit no-op S-CPU reset hook, byte-known map, and port-pair ordering rule. |
| Gundam Wing | Uses per-port write clocks to prevent stale port-1 data from being consumed after the low byte of a wide store. | Strengthen the clock rule with a monotonic write sequence so equal-clock direct calls are also ordered. |

The adopted chain is `exact S-CPU APUIO event -> directional latch -> fixed IPL handshake -> cartridge payload byte -> ARAM knownness/epoch -> explicit 13C entry frontier`. The immutable 64-byte IPL is architectural mask-ROM storage, not target code and not a generic runtime decoder. Renderer, frontend, S-DSP sample generation, and uploaded SPC700 execution are outside 12C.
