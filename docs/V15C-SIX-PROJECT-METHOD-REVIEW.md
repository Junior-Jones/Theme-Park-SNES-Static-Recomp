# 15C six-project method review

Only controller ownership, latch ordering, scheduler joins and persistence-transition methods were compared. Theme Park's reached registers, devices and zero-SRAM result come from its own source and cartridge proofs.

| Project | Method retained | Theme Park decision |
|---|---|---|
| Rock n' Roll Racing | Keep manual serial, auto-joy phases, scheduler busy state and bus register ownership in one machine graph | Use the event ordering as guidance; do not copy Rock's controller state, addresses, hashes or completion results. |
| Top Gear | `$4016/$4017` serial reads preserve open-bus bits, and frontend reports change physical state rather than guest memory | Preserve guest bus semantics and expose only a report setter; no frontend mapping is added. Its coarse 4,224-clock completion shortcut is not copied. |
| SimCity | Auto-joy results are latched independently of later live-report changes and exposed through `$4218-$421F` | Keep live, shift and result storage separate. SimCity's whole-report-at-start shortcut is not used because Theme Park already has phased scheduler ownership. |
| Civilization | Directed serial-order and SRAM-reset transition checks | Use small deterministic transition vectors. Theme Park has zero SRAM, so Civilization's SRAM buffer/API is explicitly excluded rather than copied. |
| Jungle Strike | CPU and auto strobes combine into one effective latch line; phases 0-34 perform latch, release, sample and shift | This is the clearest phase-owner pattern and is implemented generically for two standard pads, with target-specific facts supplied only by Theme Park evidence. |
| Gundam Wing | Separate live, latched and auto-result words; reset and source-reached-device scope stay explicit | Retain the separation and one-current-owner rule; do not import Gundam's target reports or fixtures. |

Theme Park itself proves reads of only `$4218/$4219`, writes `$4200` with `$00/$01/$81`, and declares zero cartridge SRAM. Standard pads on ports 1 and 2 satisfy the general 15C manual surface; no multitap, mouse, light gun, RTC or persistent special device is admitted.
