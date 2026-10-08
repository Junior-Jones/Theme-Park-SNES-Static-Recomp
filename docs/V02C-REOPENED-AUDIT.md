# V02C reopened audit

The initial 02C candidate passed its own 61 tests and reproducibility checks, but review identified proof gaps that invalidate the closed label:

- conditional branches lack the emulation-mode taken-page-cross timing case;
- indexed and native/emulation interrupt timing annotations are incomplete;
- access profiles classify operations but do not yet give complete ordered bus events;
- WAI does not distinguish wake without IRQ service from interrupt entry, and STP does not prove reset-only recovery;
- invalid packed-decimal inputs have only determinism checks, not independent semantic proof.

The former V02 source archive is withdrawn from active Temp evidence. 03C products generated before this audit are provisional only and cannot be admitted or packaged. Repair must use the WDC specification and non-emulator proof; Mesen remains forbidden. After repair, rerun 01C→02C cold gates and reconcile every provisional 03C product against the new decoder semantic hash.

## Repair disposition

- Branch timing now calculates taken and emulation-mode taken-page-cross cycles; BRA is represented as always taken.
- Indexed-read timing now adds the Table 5-7 note 4 cycle for either a page crossing or a 16-bit index, and BRK/COP/RTI native/emulation frame differences are calculated.
- WAI and STP now have an explicit external-signal transition model, including masked-IRQ resume, ABORT-without-restart, and reset-only STP recovery.
- Invalid packed-BCD digits now fail closed with `UnprovedDecimalInput`; the prior guessed total-result claim was removed.
- CPU-visible access annotations continue to own width, pointer-read count, stack direction, RMW modify/write behavior, and 16-bit write order. Complete physical 24-bit bus-event scheduling is not falsely claimed here: Starter v10 assigns that implementation to 08C, which must consume and reconcile these annotations.
- Zero native lowerers and zero production contexts are expected at 02C. Starter v10 separates those claims and assigns exact-context proof to 04C-06C and native lowering to 07C.

The repaired generator, semantic checks, fail-closed verifier, and cumulative 01C check passed from the repaired sources. The decoder semantic SHA-256 changed from the withdrawn candidate to `914698dc0b12dea54229d3b319c9463d4a0c2d8211977dc655239935e954ddf9`; therefore every provisional 03C product must be regenerated. This audit is closed for 02C but remains a mandatory backward-reconciliation input for later owners.

## 09C successor reconciliation

09C consumed this audit instead of treating the repaired 02C annotations as physical timing proof. Its exact-context timing plans and scheduler close the later-owner portions of the review for all 71,986 admitted contexts:

- conditional-branch, page-cross, indexed-width, and native/emulation interrupt timing are represented in the generated per-context timing plans;
- instruction reads, writes, RMW intermediate writes, stack traffic, and deferred JSL fetches are placed as ordered bus events on the master-clock timeline;
- WAI wake without service, mask-qualified IRQ entry, NMI entry, and reset-only STP recovery are owned by the machine/scheduler join;
- failed vector access or an unadmitted interrupt target does not earn a completed interrupt in CPU accounting.

The remaining invalid packed-BCD case is **not** claimed as proved by 09C. It remains an explicit fail-closed semantic frontier (`UnprovedDecimalInput`) and is recorded separately in the frontier ledger. No emulator oracle was used for this reconciliation.
