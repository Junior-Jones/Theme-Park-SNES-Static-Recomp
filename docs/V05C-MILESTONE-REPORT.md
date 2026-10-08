# Theme Park 05C milestone report

Status: **SOURCE FLOW CLOSED; NOT PRODUCTION ADMITTED; NOT NATIVE LOWERED**.

Starter SNES v10 remains the milestone authority. Existing SNES recompilations supplied method comparisons only; no foreign code, ROM facts, addresses, counts, hashes, bounds or acceptance state enter this result. Emulator/oracle and trace promotions are zero.

## Exact source graph

- Conservative source-candidate state contexts: 71,986.
- Distinct candidate ROM CPU addresses: 71,177.
- Exact graph edges: 78,156.
- Byte-conflict rows: zero.
- Unresolved flow frontiers: zero.
- Production-admitted contexts: zero.
- Native-lowered contexts: zero.

The graph uses compact `PBR:PC:E:M:X` identities. These are deduplicated members of a conservative source-reachability graph, not a claim that every member executes during real gameplay. Unknown branch predicates preserve both source-valid outcomes. The actual runtime-reached context count remains unknown until the completed core reaches the later permitted confirmation stage. The offline fixed point additionally carries only proof state needed to select exact bodies: procedure/return class, logical local stack, saved status, carry, Z, interrupt mask and NMI enable phase.

## Calls and returns

- Direct call edges: 2,412.
- Exact return edges: 2,458.
- Exact call/callee/return/continuation relation rows: 2,503.
- Total direct-call plus return ledger rows: 4,915.

Every return ledger row names its call-frame producer, callee entry, return consumer, exact continuation, frame width, bank rule, admitted target, rejected values, phase and failure rule. Empty, mismatched and unregistered logical frames remain fail closed.

## Interrupt and RTI proof

- Reset establishes native mode before interrupt enable.
- The carried status fixed point proves `I=1` at every current reset/NMI context. No reset-reached `CLI` or `REP` clears I, so native IRQ is not an executable root.
- SNES ABORT is unavailable and no reset-reached BRK/COP exists.
- Native NMI is entered conservatively in all four native M/X states at vector `00:8216`; these converge to RTI `00:83A3:E0M0X0`.
- The complete current graph has exactly three `PLB` sites and no `MVN/MVP`; their producers prove DBR remains zero.
- All 22 `$4200` writers are source-owned: 10 enable NMI and 12 disable it.
- RTI has a finite relation to 70,076 already-produced native foreground contexts whose carried phase includes NMI enabled.

The re-entry CSV is a static allow-list derived from source state. It contains no observed or learned target.

## Reproducibility and backward reconciliation

`scripts/run_v05.ps1` reruns 01C through 05C, including 01C ROM identity, all 64 V02 semantic checks, the 5,242,880-row V03 lexical census, V04 direct discovery, focused V05 fixed-point checks, and a cold empty-directory regeneration comparison of every 05C product. The cumulative run passes.

## Next Starter v10 responsibility

05C closure does not authorize lowering. The next milestone is 06C: identify every executable-WRAM/RAM producer, mutable field, epoch, entry/re-entry context and write barrier. Only after 06C closes may 07C generate native S-CPU bodies from the admitted exact universe.
