# Theme Park 17C — whole-core reconciliation and fixed-point Pass A

Status: **REOPENED — historical Pass A claims are superseded and are not current acceptance.**

Correction notice (2026-10-04): the selected core had omitted the architectural
two-processor-clock S-SMP reset-startup hold, collapsed immutable IPL bus events
onto instruction completion, used an obsolete 32,000 Hz audio profile and failed
to advance the implemented S-CPU arithmetic owner. Those defects are corrected.
The connected headless frontend now publishes the visible Theme Park title and
a natural input route produces active known native PCM through the frontend FIFO.
The historical natural-ladder records below are still retained only as provenance;
they do not establish complete gameplay, physical device acceptance or 17C
completion. See
`docs/V17C-APU-PAL-TIMING-CORRECTION.md`.

Pass A cold-regenerated 22 authoritative 01C/03C/04C/05C products in a new empty
output directory. Every product is byte-identical to the sealed current authority.
The fresh exact S-CPU universe contains 71,986 unique contexts, zero unresolved
flow frontiers and zero byte conflicts, and exactly equals the admitted/generated
production context set.

All current 02C-16C owner receipts, both current static libraries, the selected
production graph and the archive purity receipt were joined into one normalized
global ledger. Historical physical-PCB, byte-ownership and invalid-BCD rows now
have explicit nonblocking dispositions rather than silently disappearing.

The machine integration gap found during Pass A is repaired at source: the core
now owns bounded advance-to-next-frame and published-frame read APIs beside its
existing PCM drain. All 684 selected sources compile with warnings as errors into
both MSVC and GCC static libraries, and archive member/symbol inspection proves
exactly one current dispatcher, machine, renderer, S-SMP AOT and S-DSP owner.
The 16C-to-17C impact audit also proves that the S-DSP, APU, S-SMP, scheduler and
timing inputs remain byte-identical. The permitted delta consists of the additive
machine frame/diagnostic APIs, the explicit bus/machine power-on-profile API, its
machine-readable profile contract, and current 17C claim documents. The
historical 16C receipt was not rewritten.

The authorized Theme Park-only runner preserved the strict-default fail-closed
boundary at the first cold read of indeterminate WRAM `$0016`. A separately
declared `DETERMINISTIC_ZERO_WRAM_V1` validation profile then passed cold 300,
600 and 10,000-frame rungs plus 60, 120 and 180 emulated PAL seconds. The 300
frame rung repeats byte-for-byte, active PCM has zero unknown frames and no
bus/scheduler/PPU/APU/S-DSP owner stops. No frontend or oracle was used.

Evidence:

- `docs/V17C-pass-a-source-reconciliation.json`
- `docs/V17C-global-frontier-ledger.json`
- `docs/V17C-global-frontier-ledger.csv`
- `docs/V17C-production-authority-audit.json`
- `docs/V17C-static-compile-receipt.json`
- `docs/V17C-static-symbol-audit.json`
- `docs/V17C-integration-impact-audit.json`
- `docs/V17C-hardware-checklist.csv`
- `docs/V17C-SIX-PROJECT-METHOD-REVIEW.md`
- `docs/V17C-natural-ladder-summary.json`
- `docs/V17C-wram-0016-power-on-provenance.json`

17C is reopened. Requalify the corrected 09C/12C/13C/16C dependency cone before
any new Pass A, then require a cold Pass B before 18C can be claimed.

The post-18C frontend source is already identity-bound, without copying it early,
in `docs/POST18-STARTER-V11-FRONTEND-HANDOFF.json`: Starter SNES v11's bundled
Jungle Strike 1.0.0 reference frontend is the required source.
