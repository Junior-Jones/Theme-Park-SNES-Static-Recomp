# Completion and gameplay workflow

Requested 2026-10-06. Keep this objective open until every required result is evidenced.

1. Freeze the working uncompacted core, frontend, PAL profile, gameplay input route and output hashes. Preserve recovery evidence.
2. In parallel with core work, extend the existing gameplay/audio route using the SNES guide and actual screenshots. Inspect available build items and management/statistics screens. Place a ride and food stall; capture each placement, then capture each completed entrance-to-item path. Change entrance and item pricing through game controls, open the park, spend available funds through ordinary play, and observe continued simulation. Record screenshots, input schedule, cash/guest/statistics checkpoints, PCM and exact owner failures. Discover controls headless before replaying the same route visibly.
3. Read Starter's compaction instructions and six-project methods. Audit representation compaction separately from context pruning: unique context keys alone do not prove that shared bodies/helpers or dispatcher representation cannot be reduced. Preserve every context, timing plan, hardware event and failure boundary.
4. Implement lossless compaction and compare the same route before/after; only after the shortest route agrees run the required natural ladder and cold Pass B.
5. Compare the final frontend against all six SNES references: menu layout and naming, keyboard/controller mappings, settings/defaults/persistence, snapshots and continuation, SRAM contract, screenshots, window/fullscreen, audio device/resampling/latency, focus/modal restoration, diagnostics, clean ROM selection and PAL natural pacing. Record and repair actual discrepancies.
6. Update affected earlier Starter v12 versions and 17C/18C from the proven lessons, then regenerate and cold-verify the starter package.
7. Receive the user's new Welcome text after confirming/fixing the frontend, apply it, and verify the final package. Until that text arrives, the Welcome-text requirement remains pending.

Guide candidates: https://www.neoseeker.com/theme-park/faqs/272017-snes.html and https://gamefaqs.gamespot.com/snes/571396-theme-park/faqs/1950 . Confirm SNES-specific controls before using advice from other platforms.

Current inspected state: CURRENT-RUNTIME-STATUS records previously confirmed graphics and gameplay music. Lossless compile-time representation factoring is now selected and rebuilt, with all 670 expanded-token comparisons and the 2200-frame BMP/PCM comparison passing. The selected-source receipt chain also passes. Full cold regeneration, natural qualification and Pass B remain open. The v18_compaction_audit establishes exact context membership only and is not a reachability proof or full compaction acceptance. Gameplay construction has not yet been confirmed; later routes are being investigated without redefining the earlier confirmed graphics/audio result.
