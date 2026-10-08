# Theme Park 08C — 24-bit bus, reset, memory and MMIO boundary

Status: `COMPLETE_SOURCE_AND_STATIC_LIBRARY_NO_EXECUTABLE`

## Implemented owner

- Complete 24-bit classification for cartridge ROM windows, WRAM and mirrors, system holes, exact MMIO ranges and dedicated 7E/7F WRAM banks.
- Exact one-megabyte LoROM physical offsets and exhaustively counted aliases.
- Power-on unknownness for WRAM/MDR, reset preservation, reset-vector sampling through the normal map, and fail-closed unknown WRAM/open-bus reads.
- WRAM port `$2180-$2183`, CPU math registers, WRIO, timer latches and MEMSEL.
- CPU internal-I/O versus external MDR behavior and access-clock classification.
- Static instruction-byte guards fetch through the same mapped/read/timing-accounting path as other bus reads; they compare pre-lowered bytes and never decode an opcode.
- Typed, component-specific ports for later scheduler, DMA, PPU, APU and input owners.
- No SRAM surface: 01C proves this cartridge has zero SRAM.
- Every one of the 1,912 exact source-reached 07C register effects is joined to either an 08C implementation or the correct fail-closed later-owner port. The 32,750 unresolved address-class obligations remain preserved, not promoted.

## Gate evidence

- `docs/V08C-bus-map-summary.json`: exhaustive address and alias audit.
- `docs/V08C-source-memory-effects.csv`: source-reached effect reconciliation.
- `tests/unit/test_v08_bus_contract.py`: independent map, timing-class, owner and invalid-address checks.
- `docs/V08C-static-compile-receipt.json`: 673 sources represented in both MSVC and GCC static libraries with warnings as errors.
- `docs/V08C-SIX-PROJECT-METHOD-REVIEW.md`: process comparison and non-copying boundary.

No executable was created or run. No emulator/oracle or frontend was used. This milestone does not claim a master scheduler, DMA engine, renderer, APU, input implementation, gameplay or runnable core; those remain owned by their canonical later versions.
