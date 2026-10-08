# Version 09C — master scheduler and interrupt owner

Status: complete as a source/static-library milestone. This is not a natural gameplay, renderer, audio or frontend claim.

## Result

Theme Park now has one monotonic PAL master-clock owner joined to the complete 71,986-context native S-CPU surface. Instruction fetch, pointer/data/stack access and internal cycles are placed in event order; branch, indexed, direct-page, RMW, call/return and interrupt timing use the preserved pre-instruction state. Reads and writes expose their side effects at defined access phases.

The machine layer owns power/reset distinction, the 186-master-clock reset startup interval, NMI/IRQ entry, WAI wake ordering and STP reset-only recovery. The scheduler owns 312/313-line PAL fields, 1364/1368-clock line geometry, refresh stalls, blanking/status timing, IRQ/NMI state, automatic joypad phases, DMA/HDMA rendezvous and integer/rational independent-domain remainders.

## Authority and comparison

- Governing Starter documents: `docs/24`, `docs/43`, `docs/52`, the General Guide timing sections, and the dependent 08C bus owner.
- Six-project comparison: `docs/V09C-SIX-PROJECT-METHOD-REVIEW.md`.
- Theme Park timing-plan authority: `generator/v09_timing_plan.py` and `static-core/generated/timing/`.
- Runtime owners: `runtime/src/theme_park_scheduler.c`, `runtime/src/theme_park_bus.c`, and `runtime/src/theme_park_machine.c`.
- Deterministic profile: `config/timing-profile.json`.

No comparison-project game code or success record was copied. The Mesen oracle was not used.

## Gates

- 71,986 unique admitted contexts have timing plans; no runtime decoder or context promotion exists.
- All 676 sources compile with warnings-as-errors using MSVC and GCC into static libraries.
- `build/v09c-static` contains no executable.
- Independent arithmetic/static gate: `docs/V09C-verification-summary.json`.
- Compile receipt: `docs/V09C-static-compile-receipt.json`.

## Honest boundary

10C still owns the general DMA/HDMA transfer engine. Later owners still supply PPU, S-SMP/S-DSP, input and cartridge callbacks. No frame, pixel, PCM sample, gameplay result or frontend result is claimed here.
