# V07C static S-CPU generation method review

Starter SNES v10 is the sole workflow authority. The six existing SNES recompilations were inspected only for established process choices. No source body, helper implementation, target address, ROM byte, hash, shard count, context count, test result, or acceptance state from another game is Theme Park authority.

## Governing Starter v10 requirements

- Preserve the exact admitted runtime identity `PBR:PC:E:M:X`; keep richer intelligence offline.
- Generate direct native bodies before considering factoring or compaction.
- Partition output into deterministic shards whose local miss means only "not mine."
- Route the final miss through one consolidated dispatcher to an exact diagnostic stop.
- Record ROM/input proof, semantic-owner and generator hashes for every generated product.
- Reconcile source-proved, admitted, generated and linked sets independently.
- Keep the offline W65C816 decoder and all learning/fallback routes out of production.
- Build objects and static libraries only. Theme Park must not create or run an executable.

## Six-project inspection

| Project | Inspected method evidence | Process lesson retained | Theme Park material explicitly not retained |
|---|---|---|---|
| Rock n' Roll Racing | `generator/v05c_static_lower.py`, `tools/verify_v05c_independent.py`, generated dispatcher | Deterministic address shards; each shard returns `NOT_MINE`; one dispatcher owns the final unknown-context stop; verification joins generated keys to the canonical manifest and audits the selected source list. | Generator code, runtime API, shard count/shift, addresses, contexts, ROM facts, hashes and results. |
| Gundam Wing | `work-packages/V05C-WP01/receipt.json`, `tools/compact_generated_scpu_native.py`, generated S-CPU manifests | Freeze generator/proof/input hashes; direct exact-context authority precedes compaction; generated groups preserve exact keys; the consolidated dispatcher alone turns a miss into `CURRENT_UNKNOWN_SCPU_CONTEXT`. | Compaction templates, helper code, group layout, target-specific boundaries, counts, hashes and acceptance. |
| SimCity | current `static-recomp/generated/sc_v11_bootstrap_dispatch.c`, `README.md`, and the Starter v10 SimCity compaction reference | Direct PC/E/M/X dispatch is generated ahead of time and explicitly excludes runtime opcode fetch/decode; compaction is a later, separately receipted transformation after direct authority exists. | Bootstrap addresses/bodies, runtime structure, compaction pruning rules, counts and claims. |
| Civilization | `tools/scpu/generate_v33_closed_core.py`, `tools/testing/verify_v33_closed_authority.py`, `tools/testing/static_purity_scan.py` | Independently verify generated shard membership/counts and scan production for interpreter/decoder/fallback contamination; keep generation and purity gates separate. | Generated semantics, shard contents, project wording matches, addresses, counts and closed-authority result. |
| Top Gear | `static-recomp/generated/v22/topgear_v22_dispatch_index.c`, `static-recomp/generated/topgear_v22_romwide_dispatch.json`, generated dispatch tests | Keep ROM and any executable-RAM/re-entry domains explicit; use a generated index plus bounded shard owners; verify unknown contexts and non-selected domains fail closed. Theme Park 06C proves the executable-RAM domain is empty, so only its ROM domain is applicable. | WRAM epoch machinery, re-entry addresses, target layouts, counts, generated bodies and tests. |
| Jungle Strike | `generator/generate_static_core_compact.py`, `generated/scpu/static_core_compact_dispatch.c`, `generated/scpu/static_core_compact_manifest.json` | Emit a deterministic source list and per-file manifest; preserve exact-context failure at the final dispatch boundary; treat compact templates as a post-authority optimization, not initial semantics. | Template implementation, dispatch bridge, source list, groups, addresses, counts, hashes and completion state. |

## Theme Park 07C choices justified by the shared method

1. **Context key:** pack only Theme Park's `PBR:PC:E:M:X`. This is the Starter rule and is shared by the inspected direct dispatchers.
2. **Admission unit:** close one complete source/proof family at a time through discover -> understand -> admit -> lower -> reconcile. No arbitrary fixed-size batch is admitted merely to make a count rise.
3. **Initial lowering:** emit auditable direct Theme Park instruction bodies. No template factoring or compaction is permitted until direct authority and membership reconciliation close.
4. **Sharding:** derive deterministic shard ownership from Theme Park's compact key/address distribution. The current 256-byte address grouping is a source-layout rule, not a compile measurement; no other project's fixed shard count is copied.
5. **Dispatch:** a shard miss returns `TP_SCPU_NOT_MINE`; the one current dispatcher converts the final miss to a Theme Park unknown-context diagnostic stop.
6. **Integrity:** generation records the canonical ROM hash, admitted-manifest hash, V02 semantic-owner hash, dynamic-flow proof hash, executable-memory proof hash, generator hash and per-output hashes.
7. **Production selection:** only the current generated dispatcher, current generated shards and explicitly named Theme Park runtime support may enter the static library. Historical or offline analyser sources remain non-selectable.
8. **Qualification:** during lowering, generate twice and compare bytes, reconcile admitted/generated membership, and purity-scan for runtime decoder/fallback. Only after every 07C family is lowered and the full admitted/generated subtraction is empty may the complete current surface be compiled warning-clean as static objects/libraries with MSVC and GCC. No per-family compilation is allowed, and no executable is produced or run.

## Rejected choices

- Copying or adapting another game's lowering/runtime code.
- Choosing a shard count, key layout or helper ABI because another game used it.
- Bulk-promoting all discovered contexts before their complete source/proof families are lowered and reconciled.
- Factoring bodies before direct Theme Park authority closes.
- Adding A/X/Y/S/D/DBR or arbitrary memory values to the runtime key without a separate necessity proof.
- Runtime opcode fetch/decode, learned targets, interpreter fallback or permissive unknown-context handling.
- Using Mesen/oracle observations to author a context or semantic body.
- Frontend work before the 18C static-core certificate.

## Current 07C work packages

Each package owns one complete source-proved procedure family: freeze its exact member contexts and proof relations, implement the required Theme Park semantic bodies, generate deterministic direct output, and reconcile admitted/generated members. Packages must not compile. TP07F001 through TP07F486 are currently dependency-ordered and reconciled in source form, covering 60,525 deduplicated source-candidate contexts with zero linked contexts. F486 returned its own full cold `PASS_SELECTED_FAMILIES_SOURCE_ONLY_UNCOMPILED` result and is the frozen non-repetition baseline for the final tranche. “Source-candidate” is deliberately not “runtime-reached”: real-play reachability remains unknown until the completed core reaches the later permitted confirmation stage. Repeated instruction semantics reuse their existing native lowering, but distinct PC/state/control instances remain explicit in 07C; the later Starter-directed compaction stage, not 07C, owns equivalence-proved shrinking of the generated core. The hardware sidecar and checklist rebuild from the complete selected-context set on every pass, including families selected before the checklist existed, and verification requires every planned family to be included in that backfill. The former premature F069/F070 admissions were withdrawn because their callees had not yet been admitted; those identifiers were later reused only after returning to the last dependency-closed baseline and selecting valid leaf families. Later families repeat the same loop. Object/static-library compilation is one final whole-07C gate after all families are complete.

## Offline hardware and timing intelligence added during 07C

Every successful family admission now regenerates `V07C-hardware-intelligence.csv`, `V07C-hardware-intelligence-summary.json`, and `V07C-hardware-checklist.csv` across the entire admitted surface. The detailed ledger currently contains 774 source-derived register events/obligations; the checklist contains 94 completeness and reached-register rows. Exact hardware reach requires exact instruction-start authority, effective bank/address proof, and width expansion into byte-register events. Indexed bases without a complete index domain remain deferred obligations and are not counted as reached.

The checklist separately records used/reached, implemented, and certified state for cartridge, CPU/memory, math/I/O, master timing, DMA/HDMA, PPU storage, backgrounds, OBJ, composition, display, input, APUIO, S-SMP, S-DSP and persistence. Theme Park's PAL region is source-proved at 01C; exact master-clock/raster timing remains owned by 09C. The required contract is one monotonic integer guest timeline with rational, remainder-preserving joins for independent clock domains. Wall clock, frontend pacing and host audio clocks are explicitly non-authoritative.

The sidecar is deterministic, hash-governed, cold-regenerated by the verifier, consumes no trace/oracle input, cannot extend `PBR:PC:E:M:X`, and is excluded from production sources. The verifier also performs a retrospective ordered-dependency audit over every family, so a caller cannot be admitted before a distinct callee family is already present.

## Late-07C non-repetition correction retained for Starter v12

The early family loop cold-regenerated and semantically inspected the complete
selected surface after every appended family.  That was useful while the
generator, dispatcher and semantic owners were still changing globally, but it
became ceremonial once those owners were stable: an unchanged generated body
was being re-proved hundreds of times merely because a new procedure family
overlapped or appended contexts.

Starter v10 docs/36, docs/54 and docs/58, together with the six projects'
content-addressed manifests and bounded impact-cone practice, support the
corrected workflow:

1. Observe one final whole-surface cold PASS and freeze the ordered family
   prefix plus every old generated-body and hardware-event hash.
2. Select later work by a complete dependency/source theorem, not an arbitrary
   family or context count.  Batch dependency-eligible repeat-only families.
3. Regenerate deterministically, but compare old products by hash rather than
   rerunning their semantic checks.  An old mutation is a failure and reopens
   only its actual impact cone.
4. Semantically verify every genuinely new context and every explicitly named
   old form reached by a changed shared owner.  A wholly new emitter branch has
   an empty old impact set.
5. Continue the cheap whole-surface membership, dispatcher, purity,
   no-compilation and checklist-coverage invariants because they guard global
   structure rather than repeat instruction semantics.
6. Run another whole-surface semantic cold pass only for a real global
   mechanism change, an unexplained old mutation, or the final complete 07C
   closure.

The same correction applies to hardware intelligence.  Exact proved effective
addresses, conservative address-class intersections and unresolved producer
obligations are different evidence levels.  Indexed/non-literal operands must
not vanish merely because their literal base is outside MMIO, but an unresolved
class must not be promoted to reached hardware.  Compact group/member hashes
preserve these obligations without expanding the runtime key or generated core.
