# V05C six-project method review

Starter SNES v10 is the milestone authority. The six existing SNES static recompilations below are method evidence only. Their code, ROM facts, addresses, hashes, counts, bounds, acceptance records and milestone numbering are not Theme Park inputs.

## Shared method intersection

The review found the same defensible control-flow method across the projects:

1. Keep the generated/runtime context identity compact: `PBR:PC:E:M:X`.
2. Use richer state only in the offline proof engine: procedure identity, exact continuation relations, saved-status provenance, interrupt/re-entry provenance and any required stack relation.
3. Summarize a callee interprocedurally and join its proved return states to the exact finite set of registered caller continuations. Compute this relation to a fixed point instead of enumerating an ever-growing call string.
4. Prove matching `RTS`/`RTL` classes, `PHP`/`PLP` status restoration, stack balance and `RTI` re-entry explicitly. Do not infer them from a successful decode.
5. Keep indirect transfers, executable-WRAM epochs, scheduler wake/re-entry and other dynamic families outside the admitted graph until their source-defined finite target set is proved.
6. Fail closed on an unresolved family. A diagnostic stop, trace hit or emulator observation is not a promotion.

## Project evidence and limits

- **Rock n' Roll Racing:** exact logical call/status/interrupt frames, matching returns and finite RTI re-entry. Its observed stack bounds and all project facts are Rock-specific and are not reused.
- **Jungle Strike:** the same compact context key with richer path identity, named `PHP`/`PLP` scopes and scheduler-boundary handling. Its observed depths are not Theme Park limits.
- **Gundam Wing:** source-proved finite dynamic targets, continuation relations, status restoration and explicit fail-closed frontiers. Its older version numbering does not override Starter v10.
- **SimCity:** interprocedural callee summaries prevent mutually exclusive call strings from becoming combinatorial analysis state while generated runtime calls and returns remain real. Its oracle-derived fallbacks are expressly rejected for Theme Park.
- **Civilization:** each call edge names callee, caller, continuation and site; each normal return set is the exact union of caller continuations for the owning procedure specialization. This is the clearest model for the Theme Park fixed point.
- **Top Gear:** normalized runtime contexts are separated from richer analysis and re-entry state; executable-WRAM exits remain a distinct proof surface.

## Theme Park decision

The initial full-call-string V05C enumerator was diagnostic only and its products were withdrawn. Theme Park will use a finite procedure-summary fixed point keyed by exact entry context and return class, with exact caller-continuation unions and independently proved local stack/status effects. No arbitrary depth or context cap is an acceptance rule.

The implementation must still satisfy Starter v10's 05C ledger requirements for every dynamic family: producer, consumer, width/mask, bank rule, table bytes or stack provenance, finite admitted and rejected target sets, and failure rule. Native lowering remains Starter v10 milestone 07C; no older project's milestone label moves it forward.

The first Theme Park fixed-point pass also confirmed why SimCity performs a narrow source-proved constant-status fold after graph construction: decoding both outcomes of a branch whose status input is already proved can create a wrong-width phantom stream. Theme Park will implement the underlying W65C816 status relation generally; it will not copy SimCity code or add an address-specific exclusion.
