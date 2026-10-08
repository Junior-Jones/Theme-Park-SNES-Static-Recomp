# Post-07 Starter SNES v12 gate

Status: **07C COMPLETE; STARTER SNES V12 REWORK ACTIVE; 08C NOT STARTED**.

Historical gate note: this status records the deliberate pause after 07C. It is superseded for current build selection by `config/phase-table.csv` and `config/production-selection.json`; it must not be read as the present milestone.

After the complete 07C source universe is discovered, understood, lowered, reconciled, and independently cold-confirmed, pause Theme Park milestone work. Only then create a new Starter SNES v12 folder in the external `files` folder and rework Starter SNES v10 versions 02 through 07.

For each of versions 02-07, the v12 rewrite must record:

1. the unchanged milestone responsibility and prerequisites from v10;
2. the original start-to-finish process and evidence requirements;
3. what Theme Park did differently, including mistakes, reopenings, and repairs;
4. method lessons learned from examining the six SNES recomp projects, with no copied target facts or code;
5. improvements that are reusable for a different ROM rather than Theme Park-specific;
6. a discover -> understand -> admit -> lower -> reconcile loop where applicable;
7. a hardware/timing/subsystem checklist that is backfilled across work completed before the checklist existed;
8. explicit distinction between conservative source candidates, selected/lowered contexts, linked contexts, runtime-reached contexts, and later compaction;
9. exact failure, stop, reopen, and predecessor invalidation rules;
10. deterministic cold-regeneration and independent verification requirements;
11. the evidence package needed to close the version and authorize the next one.

The review must explicitly cover the lessons already established here: complete W65C816 semantic ownership and timing, invalid-BCD fail-closed behavior, exact E/M/X context identity, proved calls/returns and interrupt re-entry, executable-RAM epoch ownership, dependency-closed procedure families, reuse of understood instruction forms without premature compaction, deterministic generation, full selected-family hardware backfill, oracle prohibition until core completion, and deferred compilation until full 07C reconciliation.

Creating v12 does not authorize 08C. Resume Theme Park at 08C only after the user has had the v12 rework checkpoint presented.

## Living v12 refinement after the initial checkpoint

The post-07 checkpoint creates the v12 foundation by reworking versions 02-07; it is not the end of the Starter revision. As Theme Park later completes each of 08C-18C, revisit the corresponding v10 instructions and refine the v12 version from actual evidence gathered during that milestone. Compare the methods, failure modes, reopenings, convergence practices, and successful process controls of the six SNES static recomp projects at each matching stage. Import methods only: never copy target code, ROM facts, addresses, hashes, counts, or acceptance claims.

Each later refinement must preserve the milestone's canonical responsibility while adding reusable protections against premature advancement, subsystem hyper-focus, disconnected tests, stale authority, and unproved success. Tests must prove a named semantic, boundary, regression, or gate; test creation by itself is not progress. Before closing any version, perform an anti-hyperfocus audit across every downstream lane exposed by that version, including CPU, bus, timing, DMA, PPU, audio, input, persistence, renderer, and host separation as applicable. Record what evidence changed the workflow, what earlier owners were reopened, and which shortcuts or duplicate authorities were retired.
