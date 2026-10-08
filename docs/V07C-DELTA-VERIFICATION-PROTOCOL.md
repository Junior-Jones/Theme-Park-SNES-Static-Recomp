# V07C delta verification after the F486 cold baseline

Status: pending the observed full cold result for TP07F486. This protocol must
not claim authority and the baseline must not be frozen until that process
returns its own PASS result.

## What does not change

- The lowering unit remains one complete source/proof procedure family.
- Families remain dependency ordered and fail closed on unresolved callees.
- The loop remains discover, understand, admit, lower and reconcile.
- Exact `PBR:PC:E:M:X`, source-byte guards, successors, bus accesses, cycles
  and stops remain explicit.
- No emulator/oracle input, runtime decoder, fallback, partial compilation or
  executable is permitted.

## F486 baseline

After TP07F486 returns a full cold PASS, freeze:

- the ordered family prefix through TP07F486;
- every admitted context's compact key, source bytes, form, shard and generated
  top-level body hash;
- every source-derived hardware event without its accumulating family label;
- the 02C semantic, 05C flow and 06C executable-memory authority hashes;
- the selected, generated and admitted counts.

The baseline is created by `tools/v07_delta_baseline.py freeze`. A later family
cannot remove or mutate a baseline body or hardware event. Family labels may
accumulate when a later family overlaps an old context; that does not change
the context or event semantics.

## F487 onward

1. Discover every currently dependency-eligible complete family.
2. Separate families containing only existing instruction forms from families
   that expose a new form.
3. Admit repeat-only families together. For a new form, understand and add one
   explicit semantic owner before admitting every eligible family that uses it.
4. Regenerate source deterministically. Compare the current surface with the
   frozen F486 baseline using `tools/v07_delta_baseline.py compare`.
5. The comparison must prove that all baseline contexts and hardware events
   still exist unchanged, the plan is an append-only family extension, and the
   production delta equals the new family union minus baseline overlap.
6. Run exact semantic checks only for newly admitted contexts and any older
   contexts in an explicitly named impact form. A new emitter branch normally
   has no older impact set. A shared helper change must name and recheck every
   form that calls that helper.  The delta verifier must consume both the
   context manifest and its append-only comparison receipt; it rejects a
   changed/duplicate manifest or a receipt that does not own the current plan
   suffix.
7. Reconcile the complete selected/admitted/generated key sets, dispatcher
   ownership, source purity, no-compilation state and hardware checklist counts.
   These are cheap global invariants, not repeated semantic lowering.
8. Record one delta receipt for the admitted tranche. Do not run the full cold
   verifier merely because one more family was appended.

## Final hardware-sidecar reconciliation

The retrospective checklist audit opened `TP07-SIDE-0001` through
`TP07-SIDE-0006`.  The current sidecar preserves exact fixed-address events but
does not yet emit complete deferred address-class obligations for unresolved
indexed, direct-page, indirect, stack-relative and block-move operands, and its
Memory summary underreports direct WRAM/mirror/ROM-data/SRAM classes.  The
top-level CPU, CPU-I/O functional ownership and zero-SRAM persistence rows also
need classification repair without claiming their later subsystem semantics.

This correction is offline evidence only.  It must not alter an admitted
context, generated body, runtime key or dispatcher.  Preserve every F486
hardware-event row byte-for-byte (apart from the deliberately excluded
accumulating `Families` label) and add separately identified deferred/class
rows.  If an old event must instead be changed or removed, the append-only
comparison must fail and the baseline cannot authorize the tranche.

After all F487-F513 contexts are admitted, regenerate the hardware sidecar over
the complete 71,986-context selected set, reconcile all six obligations, and
perform the already-required final whole-07C cold pass.  Thus the mechanism
correction does not create a ceremonial extra whole-core pass; it is qualified
at the real final closure gate.

## When a full cold pass is required

A new whole-core cold pass is required only when:

- a global key, dispatch, shard, code-guard or family-projection rule changes;
- a shared semantic helper changes and its bounded impact set cannot be proved;
- the frozen baseline comparison reports an old body/event mutation; or
- every 07C family is lowered and the final complete 07C gate is being closed.

The final 07C cold pass must regenerate and semantically verify the complete
surface. Only after that final source gate may the one whole-07C object/static
library compile gate run. No executable is produced.
