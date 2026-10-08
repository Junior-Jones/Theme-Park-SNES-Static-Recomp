# V05C finite procedure-summary repair

The first exact call-frame implementation correctly closed the initial JSL/RTL pair and the reached PHP/PLP status restoration, but retaining the entire caller chain as an analysis-state key duplicated common callees across many legitimate call strings. Diagnostic-only runs were stopped before acceptance; their provisional products were withdrawn.

The replacement fixed point is source-owned and has no numeric depth cap:

1. Key each procedure summary by exact callee entry `PBR:PC:E:M:X` and required return class (`RTS` or `RTL`).
2. At a direct call, register the exact caller continuation, caller procedure identity and any live saved-status relation; traverse the callee once per distinct semantic input relation.
3. At a matching return, publish the finite returned E/M/X, carry, Z, interrupt-mask and NMI-phase relation for that procedure key.
4. Join each newly published return summary to every registered exact continuation. Requeue only the changed dependency cone.
5. Iterate until no procedure summary or continuation edge changes.
6. A recursive call is handled by the same monotone fixed point. It is not rejected merely for recursion and is never hidden behind an arbitrary call-depth limit.
7. PLP restoration uses byte-counted status provenance. All explicit data-stack pushes and pulls also update a local byte delta, even when no status token is live; a normal return is publishable only at zero local delta.
8. Stack-pointer replacement inside a non-root procedure is not silently summarized. It remains fail closed until a source-specific stack theorem proves its relation.
9. Empty/mismatched returns, unbalanced or exhausted stack provenance, indirect call targets and unproved re-entry remain explicit fail-closed frontier rows.
10. Hardware NMI uses a separate phase proof: every source-owned `$4200` enable/disable write is enumerated under the proved DBR=0 invariant, and RTI may resume only an already-produced native foreground context whose phase includes NMI enabled.

Only the fixed-point products may become 05C evidence. The withdrawn path-enumerator counts and files are not Theme Park progress. Current cold regeneration closes the source-flow gate while retaining zero production admissions and zero native lowerings.

