# V06C executable-memory method review

Starter SNES v10 is the authority. This review uses the six existing SNES recompilations only to select a process; none of their target bytes, addresses, epoch identities, mutable fields, counts or runtime code are reusable Theme Park facts.

## Shared method

1. Begin with the closed source-flow universe, not a runtime trace.
2. Audit every control-flow target and re-entry relation for an executable RAM address.
3. If no target enters RAM, record a complete zero-epoch result and keep unknown mutable targets fail closed.
4. If a target enters RAM, prove its copy/decompression producer, destination range, complete bytes, epoch selector, entry/re-entry contexts and every subsequent overlapping writer.
5. Separate immutable opcode bytes from explicitly mutable operand fields. Hash the epoch image and validate live bytes before static dispatch.
6. Reject an unknown epoch, changed opcode, unproved operand value or unregistered RAM PC. Never install a runtime decoder.

## Project comparison

- **Rock n' Roll Racing:** audits the complete closed production context/successor union and proves zero WRAM contexts and zero WRAM targets. This is the applicable zero-epoch pattern.
- **Jungle Strike:** retains epoch guards and requires later context/lowering changes to reconcile both ROM and WRAM domains.
- **Gundam Wing:** records zero executable-WRAM epochs at its source-flow boundary and leaves unresolved flow fail closed rather than inventing an epoch.
- **SimCity:** the reviewed material warns that self-modifying paths require a new immutable epoch; it does not supply Theme Park evidence or an applicable positive epoch.
- **Civilization:** the reviewed classification report still lists executable-WRAM producer/epoch inventory as required work. It is evidence not to claim closure from a lexical scan alone.
- **Top Gear:** provides the positive case: fixed WRAM entry, complete epoch byte hash, exact generated addresses/contexts, named mutable operand sites, live-byte verification and no runtime opcode decoder.

## Theme Park decision

Theme Park 05C is source-flow closed with zero unresolved transfers. All direct, return and NMI re-entry targets are registered ROM contexts. There are no indirect JMP/JML/JSR sites, no WAI wake target, no arbitrary stack return and no control edge into low WRAM or banks 7E/7F. Therefore 06C first applies the Rock-style complete-union zero-epoch audit. A positive epoch will be created only if the full target ledger contradicts that result; no copied bytes will be labeled executable merely because they resemble instructions.
