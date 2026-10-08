# 11C — PPU State Owner

11C is closed at source and static-library level. It does not claim pixels, completed frames, gameplay, frontend integration, or release acceptance.

## Theme Park evidence joined

- 702 exact `$2100-$213F` source events across 612 contexts are bound to one PPU owner.
- 5,461 conservative PPU address intersections remain explicitly unresolved and non-authoritative.
- All 61 exact BBAD writer events have source-proved values. The 59 PPU receiver routes reach `$2104`, `$210F`, `$2118`, and `$2122`; the two `$2180` routes remain with the WRAM-port owner.
- CPU, DMA and HDMA use the same `TPBusPorts.ppu` authority.

## Implemented state semantics

The owner includes forced blank/brightness, register images, BG/OBJ/window/color configuration state, scroll and shared Mode 7 latches, Mode 7 multiply reads, VRAM remap/increment/read buffer, CGRAM two-byte latch, OAM addressing/write buffer/high-table mirroring, counter/status reads, PAL/interlace/overscan state, storage byte knownness, and scheduler-derived blanking access legality. RESET resets PPU control/latch state without inventing cleared PPU RAM.

VRAM storage is byte-addressed while VMADD remains word-addressed. Unknown storage reads and unsupported active-display memory access fail closed. The renderer and per-scanline pixel consumption remain 14C work.

## Static build boundary

Both selected C toolchains compiled 678 objects and archived complete static libraries. No executable was created. Verification authority is `docs/V11C-verification-summary.json` and the compiler receipt is `docs/V11C-static-compile-receipt.json`.
