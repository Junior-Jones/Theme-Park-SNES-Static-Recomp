#!/usr/bin/env python3
"""Generate Theme Park 05C exact call/return flow closure products."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from analysis.v03_lexical import load_canonical_rom
from analysis.v04_contexts import Context, byte_conflicts, cpu_to_rom_offset
from analysis.v05_procedures import discover_summarized


def write_json(path: Path, value: object) -> None:
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument("--out", type=Path, default=ROOT / "docs")
    args = parser.parse_args()
    rom = load_canonical_rom(args.rom)
    profile = json.loads((ROOT / "docs" / "V01C-cartridge-profile.json").read_text(encoding="utf-8"))
    vectors = {row["name"]: int(row["value"], 16) for row in profile["vectors"]}
    reset = Context(0, vectors["emulation_reset"], 1, 1, 1)
    roots = {reset: ("EMULATION_RESET_VECTOR",)}
    root_return_classes: dict[Context, str] = {}
    root_interrupt_disable: dict[Context, int | None] = {reset: 1}
    interrupt_roots: list[dict[str, object]] = []
    # The reset graph contains no reachable BRK/COP and executes CLC/XCE before
    # interrupt enable. SNES exposes no cartridge ABORT source. As in the
    # reviewed Rock source-only vector pass, only source-reachable hardware
    # vectors are roots. Theme Park never clears I after reset/SEI, so native
    # IRQ is rejected; native NMI is the sole conservative asynchronous root.
    # Exact resume sets remain explicitly open at RTI.
    vector_dispositions = {
        "native_nmi": "CANDIDATE_EXECUTABLE_ASYNCHRONOUS_ROOT",
        "native_irq": "REJECTED_MASKED_I_INVARIANT_NO_CLI_OR_REP_I_CLEAR",
        "native_abort": "REJECTED_SNES_HAS_NO_EXPOSED_CARTRIDGE_ABORT_SOURCE",
        "native_cop": "REJECTED_NO_RESET_REACHED_COP",
        "native_brk": "REJECTED_NO_RESET_REACHED_BRK",
        "emulation_nmi": "REJECTED_RESET_ENTERS_NATIVE_BEFORE_INTERRUPT_ENABLE",
        "emulation_irq_brk": "REJECTED_RESET_ENTERS_NATIVE_AND_IRQ_REMAINS_MASKED",
        "emulation_abort": "REJECTED_SNES_HAS_NO_EXPOSED_CARTRIDGE_ABORT_SOURCE",
        "emulation_cop": "REJECTED_NO_RESET_REACHED_COP",
    }
    for vector_name in ("native_nmi",):
        pc = vectors[vector_name]
        for m in (0, 1):
            for x in (0, 1):
                context = Context(0, pc, 0, m, x)
                roots.setdefault(context, tuple())
                roots[context] = tuple(sorted(set(roots[context]) | {f"{vector_name.upper()}_VECTOR"}))
                root_return_classes[context] = "RTI"
                root_interrupt_disable[context] = 1
                interrupt_roots.append({"vector": vector_name, "context": context.key})
    software_vectors = {
        ("BRK", 0): vectors["native_brk"], ("BRK", 1): vectors["emulation_irq_brk"],
        ("COP", 0): vectors["native_cop"], ("COP", 1): vectors["emulation_cop"],
    }
    root_nmi_enabled: dict[Context, int | None] = {reset: 0}
    for context in root_return_classes:
        root_nmi_enabled[context] = 1

    structural = discover_summarized(
        rom, roots, software_vectors, root_return_classes,
        root_interrupt_disable, root_nmi_enabled)

    # Theme Park DBR theorem for the current source graph: reset starts DBR=0;
    # the only PLB sites are reset's LDA #0/PHA/PLB, NMI's PHK/PLB (PBR=0),
    # and NMI's balanced PHB/.../PLB restore. No block move rewrites DBR.
    expected_plb = {"00:8022:0:1:1", "00:821B:0:0:0", "00:83A1:0:0:0"}
    actual_plb = {context.key for context in structural.contexts
                  if structural.mnemonic_by_context[context] == "PLB"}
    block_move_contexts = [context.key for context in structural.contexts
                           if structural.mnemonic_by_context[context] in ("MVN", "MVP")]
    dbr_zero_proved = actual_plb == expected_plb and not block_move_contexts

    incoming: dict[Context, list[object]] = {}
    for edge in structural.edges:
        incoming.setdefault(edge.target, []).append(edge)
    nmi_enable_writes: dict[Context, int] = {}
    nmi_write_proofs: list[dict[str, object]] = []
    unresolved_nmi_writes: list[str] = []
    for context in structural.contexts:
        raw = structural.raw_by_context[context]
        mnemonic = structural.mnemonic_by_context[context]
        mode = structural.mode_by_context[context]
        operand = int.from_bytes(raw[1:], "little")
        if mode != "ABS" or operand != 0x4200 or mnemonic not in ("STA", "STZ"):
            continue
        producer = ""
        value: int | None = 0 if mnemonic == "STZ" else None
        if mnemonic == "STA":
            values: set[int] = set()
            producers: set[str] = set()
            for edge in incoming.get(context, []):
                source = edge.source
                source_raw = structural.raw_by_context[source]
                if (edge.kind == "FALLTHROUGH"
                        and structural.mnemonic_by_context[source] == "LDA"
                        and structural.mode_by_context[source] == "IMM_M"
                        and source.m == 1
                        and ((source.pc + len(source_raw)) & 0xFFFF) == context.pc):
                    values.add(source_raw[1])
                    producers.add(source.key)
            if len(values) == 1:
                source_value = next(iter(values))
                value = 1 if source_value & 0x80 else 0
                producer = "|".join(sorted(producers))
        else:
            producer = context.key
        if value is None or not dbr_zero_proved:
            unresolved_nmi_writes.append(context.key)
            continue
        nmi_enable_writes[context] = value
        nmi_write_proofs.append({
            "context": context.key,
            "producer": producer,
            "written_value": "00" if mnemonic == "STZ" else f"{next(iter({structural.raw_by_context[e.source][1] for e in incoming.get(context, []) if structural.mnemonic_by_context[e.source] == 'LDA'})):02X}",
            "nmi_enabled_after": value,
            "dbr_rule": "DBR_ZERO_SOURCE_THEOREM",
        })

    return_proof_rows: list[dict[str, str]] = []
    result = discover_summarized(
        rom, roots, software_vectors, root_return_classes,
        root_interrupt_disable, root_nmi_enabled, nmi_enable_writes,
        proof_sink=return_proof_rows)
    foreground = discover_summarized(
        rom, {reset: ("EMULATION_RESET_VECTOR",)}, software_vectors,
        root_interrupt_disable={reset: 1}, root_nmi_enabled={reset: 0},
        nmi_enable_writes=nmi_enable_writes)
    resume_candidates = sorted(
        context for context in foreground.contexts
        if "1" in foreground.nmi_enable_facts[context]
    )
    async_rti_contexts = sorted({
        row.source for row in result.frontiers
        if row.kind == "ASYNC_RTI_REENTRY_SET_OPEN"
    })
    expected_async_rti = [Context(0, 0x83A3, 0, 0, 0)]
    reentry_gate = (
        dbr_zero_proved
        and not unresolved_nmi_writes
        and not foreground.frontiers
        and async_rti_contexts == expected_async_rti
        and bool(resume_candidates)
        and all(context.e == 0 for context in resume_candidates)
        and all(result.interrupt_disable_facts[context] == ("1",)
                for context in result.contexts)
    )
    unresolved_frontiers = tuple(
        row for row in result.frontiers
        if not (reentry_gate and row.kind == "ASYNC_RTI_REENTRY_SET_OPEN")
    )
    args.out.mkdir(parents=True, exist_ok=True)

    contexts_path = args.out / "V05C-contexts.csv"
    with contexts_path.open("w", encoding="utf-8", newline="") as handle:
        fields = ("Context", "ROM_Offset", "Bytes", "Mnemonic", "Mode",
                  "Carry_In_Facts", "Zero_In_Facts", "Interrupt_Disable_In_Facts",
                  "NMI_Enable_In_Facts", "Origins")
        writer = csv.DictWriter(handle, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        for context in result.contexts:
            writer.writerow({"Context": context.key,
                             "ROM_Offset": f"0x{cpu_to_rom_offset(context.pbr, context.pc):06X}",
                             "Bytes": result.raw_by_context[context].hex().upper(),
                             "Mnemonic": result.mnemonic_by_context[context], "Mode": result.mode_by_context[context],
                             "Carry_In_Facts": "|".join(result.carry_facts[context]),
                             "Zero_In_Facts": "|".join(result.zero_facts[context]),
                             "Interrupt_Disable_In_Facts": "|".join(
                                 result.interrupt_disable_facts[context]),
                             "NMI_Enable_In_Facts": "|".join(result.nmi_enable_facts[context]),
                             "Origins": "|".join(result.origins[context])})

    edges_path = args.out / "V05C-edges.csv"
    with edges_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=("Source", "Kind", "Target"), lineterminator="\n")
        writer.writeheader()
        for row in result.edges:
            writer.writerow({"Source": row.source.key, "Kind": row.kind, "Target": row.target.key})

    frontiers_path = args.out / "V05C-frontiers.csv"
    with frontiers_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=("Source", "Kind", "Detail", "Owner"), lineterminator="\n")
        writer.writeheader()
        for row in unresolved_frontiers:
            writer.writerow({"Source": row.source.key, "Kind": row.kind, "Detail": row.detail, "Owner": row.owner})

    conflicts = byte_conflicts(result)
    conflicts_path = args.out / "V05C-byte-conflicts.csv"
    with conflicts_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=("ROM_Offset", "Owners"), lineterminator="\n")
        writer.writeheader()
        for offset, owners in conflicts:
            writer.writerow({"ROM_Offset": f"0x{offset:06X}", "Owners": "|".join(owners)})

    nmi_writes_path = args.out / "V05C-nmi-phase-writes.csv"
    with nmi_writes_path.open("w", encoding="utf-8", newline="") as handle:
        fields = ("Context", "Producer", "Written_Value", "NMI_Enabled_After", "DBR_Rule")
        writer = csv.DictWriter(handle, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        for row in sorted(nmi_write_proofs, key=lambda item: str(item["context"])):
            writer.writerow({
                "Context": row["context"], "Producer": row["producer"],
                "Written_Value": row["written_value"],
                "NMI_Enabled_After": row["nmi_enabled_after"],
                "DBR_Rule": row["dbr_rule"],
            })

    interrupt_path = args.out / "V05C-interrupt-reentry.csv"
    with interrupt_path.open("w", encoding="utf-8", newline="") as handle:
        fields = ("Interrupt", "Handler_Entry", "RTI_Context", "Resume_Context",
                  "Proof_Id", "Status")
        writer = csv.DictWriter(handle, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        for rti in async_rti_contexts:
            for target in resume_candidates:
                writer.writerow({
                    "Interrupt": "NMI", "Handler_Entry": "00:8216",
                    "RTI_Context": rti.key, "Resume_Context": target.key,
                    "Proof_Id": "V05-NMI-PHASE-0001",
                    "Status": ("CLOSED_SOURCE_PROVED" if reentry_gate
                               else "CANDIDATE_NOT_ADMITTED_PENDING_REENTRY_GATE"),
                })

    dynamic_path = args.out / "V05C-dynamic-proofs.csv"
    with dynamic_path.open("w", encoding="utf-8", newline="") as handle:
        fields = ("Proof_Id", "Class", "Producer", "Consumer", "Callee_Entry",
                  "Target", "Width", "Mask", "Bank_Rule", "Table_Bytes",
                  "Index_Domain", "Admitted_Targets", "Rejected_Values", "Phase",
                  "Failure_Rule")
        writer = csv.DictWriter(handle, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        proof_index = 0
        for row in result.edges:
            if row.kind != "DIRECT_CALL":
                continue
            proof_index += 1
            mnemonic = result.mnemonic_by_context[row.source]
            width = "16" if mnemonic == "JSR" else "24"
            writer.writerow({
                "Proof_Id": f"V05P{proof_index:05d}", "Class": "DIRECT_CALL",
                "Producer": row.source.key, "Consumer": row.source.key,
                "Callee_Entry": row.target.key, "Target": row.target.key,
                "Width": width, "Mask": "ENCODED_OPERAND",
                "Bank_Rule": "CALLER_PBR" if mnemonic == "JSR" else "ENCODED_BANK",
                "Table_Bytes": result.raw_by_context[row.source].hex().upper(),
                "Index_Domain": "SINGLE_ENCODED_TARGET",
                "Admitted_Targets": row.target.key, "Rejected_Values": "ALL_OTHER_TARGETS",
                "Phase": "RESET_OR_SOURCE_PROVED_NMI_GRAPH",
                "Failure_Rule": "FAIL_CLOSED_IF_ENCODED_TARGET_IS_NOT_AN_ADMITTED_CONTEXT",
            })
        for proof in sorted(return_proof_rows,
                            key=lambda row: (row["return_source"], row["call_source"],
                                             row["continuation"])):
            proof_index += 1
            width = "16_BIT_PC_FRAME" if proof["return_class"] == "RTS" else "24_BIT_PBR_PC_FRAME"
            writer.writerow({
                "Proof_Id": f"V05P{proof_index:05d}", "Class": "RETURN_PROVED",
                "Producer": proof["call_source"], "Consumer": proof["return_source"],
                "Callee_Entry": proof["callee_entry"], "Target": proof["continuation"],
                "Width": width, "Mask": "EXACT_LOGICAL_FRAME",
                "Bank_Rule": ("SAVED_CALLER_PBR" if proof["return_class"] == "RTL"
                              else "CURRENT_CALLEE_PBR"),
                "Table_Bytes": "N/A_LOGICAL_CALL_FRAME",
                "Index_Domain": "REGISTERED_EXACT_CALLER_CONTINUATION",
                "Admitted_Targets": proof["continuation"],
                "Rejected_Values": "EMPTY_MISMATCHED_OR_UNREGISTERED_STACK_FRAME",
                "Phase": "FINITE_PROCEDURE_SUMMARY_FIXED_POINT",
                "Failure_Rule": "FAIL_CLOSED_WITHOUT_MATCHING_CALL_CLASS_AND_CONTINUATION",
            })

    frontier_counts: dict[str, int] = {}
    edge_counts: dict[str, int] = {}
    for row in unresolved_frontiers:
        frontier_counts[row.kind] = frontier_counts.get(row.kind, 0) + 1
    for row in result.edges:
        edge_counts[row.kind] = edge_counts.get(row.kind, 0) + 1
    products = (contexts_path, edges_path, frontiers_path, conflicts_path, dynamic_path,
                nmi_writes_path, interrupt_path)
    candidate_rejected = bool(conflicts or unresolved_frontiers or unresolved_nmi_writes)
    interrupt_disable_non_one = [
        context.key for context in result.contexts
        if result.interrupt_disable_facts[context] != ("1",)
    ]
    summary = {
        "schema": "theme-park-v05c-flow-summary-v1",
        "status": ("REJECTED_CANDIDATE_UNRESOLVED_FLOW_OR_BYTE_CONFLICTS"
                   if candidate_rejected else "FLOW_CLOSED_NOT_PRODUCTION_ADMITTED"),
        "candidate_contexts": len(result.contexts),
        "exact_contexts": 0 if candidate_rejected else len(result.contexts),
        "unique_cpu_addresses": len({(row.pbr, row.pc) for row in result.contexts}),
        "root_count": len(roots),
        "interrupt_roots": interrupt_roots,
        "interrupt_root_policy": (
            "SOURCE_ONLY_NATIVE_NMI_ALL_MX; RTI resumes only to the finite "
            "source-proved NMI-enabled foreground set; "
            "IRQ remains masked by reset I=1 plus SEI and no CLI/REP-I-clear; "
            "PLP restores only source-paired PHP status; ABORT unavailable; "
            "BRK/COP absent from reset-reached graph"),
        "vector_dispositions": vector_dispositions,
        "interrupt_disable_invariant": {
            "expected": "I=1 for every currently reached reset/NMI context",
            "contexts_not_proved_i_one": interrupt_disable_non_one,
            "proved": not interrupt_disable_non_one,
        },
        "dbr_zero_theorem": {
            "expected_plb_contexts": sorted(expected_plb),
            "actual_plb_contexts": sorted(actual_plb),
            "block_move_contexts": block_move_contexts,
            "proved": dbr_zero_proved,
        },
        "nmi_phase": {
            "source_proved_writes": len(nmi_enable_writes),
            "enable_writes": sum(value == 1 for value in nmi_enable_writes.values()),
            "disable_writes": sum(value == 0 for value in nmi_enable_writes.values()),
            "unresolved_writes": unresolved_nmi_writes,
            "resume_candidates": len(resume_candidates),
            "rti_contexts": [context.key for context in async_rti_contexts],
            "reentry_gate": reentry_gate,
            "status": ("CLOSED_SOURCE_PROVED_NOT_PRODUCTION_ADMITTED" if reentry_gate
                       else "CANDIDATE_NOT_ADMITTED_PENDING_REENTRY_GATE"),
        },
        "edges": len(result.edges),
        "edges_by_kind": dict(sorted(edge_counts.items())),
        "dynamic_proofs": proof_index,
        "return_relation_rows": len(return_proof_rows),
        "frontiers": len(unresolved_frontiers),
        "frontiers_by_kind": dict(sorted(frontier_counts.items())),
        "resolved_frontiers": {"ASYNC_RTI_REENTRY_SET_OPEN": 1 if reentry_gate else 0},
        "byte_conflict_rows": len(conflicts),
        "admitted_production_contexts": 0,
        "native_lowered_contexts": 0,
        "trace_promotions": 0,
        "oracle_promotions": 0,
        "dependency_v04_context_sha256": hashlib.sha256((ROOT / "docs" / "V04C-contexts.csv").read_bytes()).hexdigest(),
        "artifacts_sha256": {path.name: hashlib.sha256(path.read_bytes()).hexdigest() for path in products},
    }
    write_json(args.out / "V05C-flow-summary.json", summary)
    print(json.dumps(summary, sort_keys=True))
    return 1 if candidate_rejected else 0


if __name__ == "__main__":
    raise SystemExit(main())
