# 11C Six-Project PPU-State Method Review

This review uses the six SNES recompilations only as process and architecture comparisons. Theme Park's ROM, exact 07C source events, 09C scheduler, and 10C DMA receipts remain the only target authorities. No target code, data, hashes, acceptance records, or emulator-derived behavior was copied.

| Project | Reusable method observed | Theme Park decision |
|---|---|---|
| Rock n Roll Racing | One PPU owner behind the bus; explicit VRAM remap/increment/read buffer and storage knownness. | Use one Theme Park owner and fail closed on unknown storage. |
| Top Gear | Memory ports and DMA share the same PPU entry point; Mode 7 multiply reads are state-derived. | Route CPU/DMA/HDMA through `TPBusPorts.ppu`; implement `$2134-$2136` from matrix state. |
| SimCity | Separates register/storage ownership from later rendering and records raster position independently. | 11C claims state only; preserve scheduler ownership and no pixel claim. |
| Civilization | Limits certification to source-reached ports while keeping generic register semantics centralized. | Track implemented, reached, and certified surfaces separately. |
| Jungle Strike | Applies CGRAM access legality when the second byte commits, not when the first-byte latch loads. | Preserve the first-byte latch during active display; fail closed only on an illegal commit. |
| Gundam Wing | Carries byte knownness and fails closed where active-display results depend on unimplemented renderer internals. | Maintain VRAM/CGRAM/OAM known maps and reject unsupported access timing. |

Common method adopted: `source producer -> exact register/control event -> shared bus owner -> latch/storage semantics -> scheduler access legality -> later renderer consumer`. Unit conventions are explicit: VRAM storage is byte-addressed, VMADD is word-addressed, CGRAM is byte storage behind a color index, and OAM uses its 544-byte physical layout. The 14C raster/renderer milestone remains the owner of pixel correctness.
