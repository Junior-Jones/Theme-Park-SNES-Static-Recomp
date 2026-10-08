# V10C — general DMA/HDMA controller and exact Theme Park source ownership

Status: **closed at source and static-library level; no executable created or run**.

## What is now owned

`runtime/src/theme_park_dma.c` is the sole production DMA/HDMA controller. It owns all eight channels, transfer modes 0-7, both directions, fixed/increment/decrement A-bus stepping, DAS zero wrap, direct and indirect HDMA, line repeat/reload/termination, channel priority, startup/end alignment, scheduler rendezvous, WRAM-port conflict handling and restricted A-bus behavior. The 08C bus and 09C PAL master scheduler are the only paths used.

The exact Theme Park join contains 548 byte-register events in 427 admitted S-CPU contexts and 124 trigger receipts. All trigger value domains are closed. The 63 zero-mask writes are proved disable operations. All 61 nonzero masks have their required payload-register writer lifetimes proved. The final channel-0 HDMA receipt is closed by `V10C-hdma-ch0-startup-phase-certificate.json`: reset leaves NMI disabled, reset-root code initializes `$4300-$4304`, `$4200=$81` enables NMI afterward, and only then can the NMI handler write `$420C=$01`.

The 5,459 conservative `$43xx` address-class intersections remain offline, unresolved and non-authoritative. They were not promoted into reached hardware.

## Gate evidence

- `V10C-dma-source-join-summary.json`: zero open trigger domains and zero open payload-writer sets.
- `V10C-dma-trigger-receipts.json`: one named receipt for every exact `$420B/$420C` trigger.
- `V10C-hdma-ch0-startup-phase-certificate.json`: source/scheduler proof for the cross-procedure reset-to-NMI lifetime.
- `V10C-verification-summary.json`: general controller and exact source-configuration gate.
- `V10C-static-compile-receipt.json`: 677 C sources compiled previously by MSVC and GCC into static libraries; current qualification evidence was refreshed by matching source/library hashes, without recompiling unchanged work and without producing an executable.
- `V10C-SIX-PROJECT-METHOD-REVIEW.md`: method comparison only; no foreign target code, facts, hashes or results were imported.

## Honest downstream boundary

10C names every DMA destination through the 08C B-bus port, but `$2100-$213F` semantic consumption belongs to 11C. Until 11C binds the sole PPU state owner, a destination access fails closed with `TP_BUS_STOP_PPU_UNAVAILABLE`. This is a named downstream frontier, not a claim that pixels or PPU storage are already correct.

No emulator/oracle was used. No frontend work was performed. No runtime decoder, target-specific DMA shortcut, executable, gameplay result or release claim exists.
