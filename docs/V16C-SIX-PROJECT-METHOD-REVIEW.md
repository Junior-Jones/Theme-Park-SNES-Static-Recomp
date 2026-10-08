# 16C six-project method review

This review was performed for workflow comparison only. Theme Park source, ROM facts,
addresses, hashes, generated products and acceptance results remain its own. Under the
project rule, Rock n' Roll Racing was inspected only after Theme Park's 16C owner had
compiled and passed its first complete verifier.

| Project | Reusable method observed | Theme Park decision |
|---|---|---|
| Rock n' Roll Racing | A project-owned fixed 32-phase S-DSP replaces the former runtime emulator owner; archive/symbol purity, known PCM counts and long natural runs are separate evidence. | Used the ownership/purity/long-run sequence. No Rock code, target data, NTSC clock choice, ARAM initialization, hashes or run results were imported. Theme Park active-audio natural runs remain a 17C validation input. |
| Top Gear | Phase-owned register visibility and a negative proof that the historical hybrid backend is not production-selected. | Used explicit phase and archive-owner audits. Rejected its oracle-derived S-SMP admission history and all target-specific extensions. |
| SimCity | Core PCM is a bounded, knownness-carrying boundary; speaker transport and resampling remain outside the machine. Snapshot continuation is a separate qualification check. | Added an opaque machine PCM drain API and explicit FIFO overflow. No frontend, speaker path or SimCity state was ported. Host snapshots remain outside Theme Park's target contract. |
| Civilization | Enumerates the complete 0-31 phase domain and audits production source/define selection and forbidden fallback authority. | Used an explicit phase-schedule verifier and two-archive symbol/member audit. Rejected its linked third-party DSP implementation and all project facts. |
| Jungle Strike | The early package honestly records that a generic bell interpolator is not proof of the SNES Gaussian table; the later workflow separates ARAM knownness, PCM knownness and overflow. | Required the exact 512-entry hardware coefficient census and causal knownness. No Jungle source/table was copied. |
| Gundam Wing | Splits voice 0's 3a/3b/3c work across the real schedule, delays register latches, keeps echo in phases 22-30, and propagates unknown data until first semantic use. | Used the phase-ownership and unknownness questions. Emulator phase comparison was not used because Theme Park's oracle boundary remains closed. |

## Resulting Theme Park workflow

1. Join every exact `$F2/$F3` AOT producer from the closed 13C authority.
2. Implement fixed hardware independently in Theme Park-owned C, including all 32
   phases and a bounded core FIFO.
3. Carry ARAM, interpolation, BRR-history, echo-history and PCM knownness; allow only
   proved annihilators such as zero volume or mute to recover a known observable.
4. Compile the complete selected core into two static archives and prove the sole DSP
   object/symbol owner while rejecting emulator/fallback names.
5. Preserve active Theme Park PCM and long natural validation for 17C. Neither a reset
   vector nor another game's successful run is promoted into a gameplay/audio claim.

