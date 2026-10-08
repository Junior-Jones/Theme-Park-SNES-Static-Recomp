#!/usr/bin/env python3
"""Join exact V07 S-CPU DMA register events to the generic V10 controller.

This is source-only. Conservative address intersections are retained as unresolved
obligations and never promoted to reached hardware.
"""
from __future__ import annotations

import csv
import hashlib
import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "docs/V07C-hardware-intelligence.csv"
CONTEXTS = ROOT / "docs/V05C-contexts.csv"
EDGES = ROOT / "docs/V05C-edges.csv"
EVENTS = ROOT / "docs/V10C-dma-exact-register-events.csv"
RECEIPTS = ROOT / "docs/V10C-dma-trigger-receipts.json"
SUMMARY = ROOT / "docs/V10C-dma-source-join-summary.json"
PHASE_CERT = ROOT / "docs/V10C-hdma-ch0-startup-phase-certificate.json"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def register_of(row: dict[str, str]) -> int | None:
    text = row["Effective_Address"]
    if not text.startswith("00:"):
        return None
    try:
        value = int(text[3:], 16)
    except ValueError:
        return None
    return value if value in (0x420B, 0x420C) or 0x4300 <= value <= 0x437F else None


def main() -> int:
    rows = list(csv.DictReader(SOURCE.open(encoding="utf-8", newline="")))
    contexts = {row["Context"]: row for row in
                csv.DictReader(CONTEXTS.open(encoding="utf-8", newline=""))}
    predecessors: dict[str, list[str]] = defaultdict(list)
    predecessor_edges: dict[str, list[tuple[str, str]]] = defaultdict(list)
    successors: dict[str, list[str]] = defaultdict(list)
    for edge in csv.DictReader(EDGES.open(encoding="utf-8", newline="")):
        predecessors[edge["Target"]].append(edge["Source"])
        predecessor_edges[edge["Target"]].append((edge["Source"], edge["Kind"]))
        successors[edge["Source"]].append(edge["Target"])
    exact: list[dict[str, str]] = []
    unresolved: list[dict[str, str]] = []
    for row in rows:
        register = register_of(row)
        if register is not None and row["Address_Proof"] == "EXACT_START_PLUS_DBR_OR_LONG_BANK_PLUS_WIDTH_EXPANSION":
            item = dict(row)
            item["Register"] = f"${register:04X}"
            exact.append(item)
        elif row["Subsystem"] == "DMA_HDMA" and row["Authority_State"].startswith("DEFERRED_"):
            unresolved.append(row)

    exact.sort(key=lambda r: (int(r["ROM_Offset"], 16), r["Context"], int(r["Byte_Event_Index"] or 0)))
    fields = ["Stable_Id", "Families", "Context", "ROM_Offset", "Bytes", "Mnemonic",
              "Mode", "Access", "Instruction_Access_Width", "Byte_Event_Index",
              "Register", "Address_Proof", "Timing_Relevance"]
    with EVENTS.open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        writer.writerows({name: row[name] for name in fields} for row in exact)

    family_writers: dict[str, set[str]] = defaultdict(set)
    events_by_context: dict[str, list[dict[str, str]]] = defaultdict(list)
    for row in exact:
        events_by_context[row["Context"]].append(row)
        for family in row["Families"].split(";"):
            family_writers[family].add(row["Register"])

    def trigger_value(context: str, store: str) -> int | None:
        wanted = {"STA": "LDA", "STX": "LDX", "STY": "LDY"}.get(store)
        current = context
        for _ in range(8):
            incoming = predecessors.get(current, [])
            if len(incoming) != 1:
                return None
            current = incoming[0]
            instruction = contexts[current]
            mnemonic = instruction["Mnemonic"]
            if mnemonic == wanted and instruction["Mode"] in ("IMM_M", "IMM_X"):
                raw = bytes.fromhex(instruction["Bytes"])
                return raw[1] if len(raw) >= 2 else None
            # These forms cannot change A/X/Y. Stop on everything else so the
            # proof never guesses through arithmetic, loads, calls or returns.
            if mnemonic not in {"STA", "STX", "STY", "STZ", "SEP", "REP",
                                "CLC", "SEC", "CLD", "SED", "CLI", "SEI",
                                "CLV", "NOP", "BRA", "BRL"}:
                return None
        return None

    receipts = []
    reset_root = "00:8000:1:1:1"

    def reachable_from(root: str, target: str, blocked: str | None = None) -> bool:
        pending = [root]
        visited: set[str] = set()
        while pending:
            node = pending.pop()
            if node == blocked or node in visited:
                continue
            if node == target:
                return True
            visited.add(node)
            pending.extend(successors.get(node, []))
        return False

    def reachable(target: str, blocked: str | None = None) -> bool:
        return reachable_from(reset_root, target, blocked)

    # Theme Park configures HDMA channel 0 during its reset-root initializer,
    # before it enables NMI.  The later $420C=$01 writer lives in the NMI
    # handler, so ordinary intraprocedural dominance is the wrong proof shape:
    # the ordering authority is the reset call/return chain plus the scheduler's
    # NMITIMEN gate.  Keep that argument explicit and machine-checkable instead
    # of weakening the generic graph walker.
    phase_context_bytes = {
        "00:80DC:0:0:0": "226F8A0C",  # reset-root initializer call
        "0C:8B0B:0:1:0": "2200800C",  # channel-0 setup call
        "0C:801E:0:1:0": "6B",        # setup return
        "0C:8B0F:0:1:0": "2243860C",  # intervening initializer call
        "0C:8748:0:1:0": "6B",        # intervening initializer return
        "0C:8B13:0:1:0": "22098200",  # NMITIMEN setup call
        "00:8210:0:1:1": "A981",      # LDA #$81
        "00:8212:0:1:1": "8D0042",    # STA $4200
        "00:8216:0:1:0": "C230",      # native NMI root
        "00:8350:0:1:0": "8D0C42",    # STA $420C
    }
    phase_edges = [
        ("00:80DC:0:0:0", "DIRECT_CALL", "0C:8A6F:0:0:0"),
        ("0C:8B0B:0:1:0", "DIRECT_CALL", "0C:8000:0:1:0"),
        ("0C:801E:0:1:0", "RETURN_PROVED", "0C:8B0F:0:1:0"),
        ("0C:8B0F:0:1:0", "DIRECT_CALL", "0C:8643:0:1:0"),
        ("0C:8748:0:1:0", "RETURN_PROVED", "0C:8B13:0:1:0"),
        ("0C:8B13:0:1:0", "DIRECT_CALL", "00:8209:0:1:0"),
        ("00:8210:0:1:1", "FALLTHROUGH", "00:8212:0:1:1"),
    ]
    edge_set = {(source, kind, target)
                for target, incoming in predecessor_edges.items()
                for source, kind in incoming}
    phase_contexts_valid = all(
        context in contexts and contexts[context]["Bytes"] == encoded
        for context, encoded in phase_context_bytes.items())
    phase_edges_valid = all(edge in edge_set for edge in phase_edges)
    phase_nmi_path_valid = reachable_from("00:8216:0:1:0", "00:8350:0:1:0")
    phase_enable_value_valid = trigger_value("00:8212:0:1:1", "STA") == 0x81
    phase_registers = ["$4300", "$4301", "$4302", "$4303", "$4304"]
    phase_unique_writers: dict[str, list[str]] = {}
    for register in phase_registers:
        register_events = [event for event in exact
                           if event["Register"] == register and
                           event["Access"] in ("WRITE", "READ_MODIFY_WRITE")]
        if len({event["Context"] for event in register_events}) == 1:
            phase_unique_writers[register] = sorted(event["Stable_Id"] for event in register_events)
    phase_scheduler = (ROOT / "runtime/src/theme_park_scheduler.c").read_text(encoding="utf-8")
    phase_machine = (ROOT / "runtime/src/theme_park_machine.c").read_text(encoding="utf-8")
    phase_scheduler_gate_valid = all(marker in phase_scheduler for marker in (
        "s->nmitimen = 0u;",
        "if ((s->nmitimen & 0x80u) != 0u) s->nmi_pending = 1u;",
        "if (s->nmi_flag != 0u && (value & 0x80u) != 0u && (old & 0x80u) == 0u)",
    )) and "nmi = tp_scheduler_take_nmi(&m->scheduler);" in phase_machine
    phase_certificate_valid = (
        phase_contexts_valid and phase_edges_valid and phase_nmi_path_valid and
        phase_enable_value_valid and len(phase_unique_writers) == len(phase_registers) and
        phase_scheduler_gate_valid)
    phase_certificate = {
        "schema": "theme-park-v10c-hdma-ch0-startup-phase-v1",
        "status": ("PROVED_INITIALIZED_BEFORE_NMI_ENABLE" if phase_certificate_valid
                   else "OPEN_STARTUP_PHASE_PROOF"),
        "trigger_context": "00:8350:0:1:0",
        "trigger_register": "$420C",
        "trigger_value": 1,
        "reset_nmitimen_state": 0,
        "nmi_enable_context": "00:8212:0:1:1",
        "nmi_enable_value": 0x81,
        "required_registers": phase_registers,
        "unique_writer_events": phase_unique_writers,
        "context_bytes": phase_context_bytes,
        "ordered_call_return_edges": [
            {"source": source, "kind": kind, "target": target}
            for source, kind, target in phase_edges
        ],
        "checks": {
            "context_bytes_exact": phase_contexts_valid,
            "call_return_edges_exact": phase_edges_valid,
            "nmi_root_reaches_trigger": phase_nmi_path_valid,
            "nmi_enable_value_exact": phase_enable_value_valid,
            "all_payload_register_writers_unique": len(phase_unique_writers) == len(phase_registers),
            "scheduler_nmi_gate_bound": phase_scheduler_gate_valid,
        },
        "authority": (
            "Theme Park reset-root source ordering plus the 09C NMITIMEN scheduler gate; "
            "no runtime trace or emulator oracle"
        ),
        "contexts_sha256": sha(CONTEXTS),
        "edges_sha256": sha(EDGES),
        "scheduler_sha256": sha(ROOT / "runtime/src/theme_park_scheduler.c"),
        "machine_sha256": sha(ROOT / "runtime/src/theme_park_machine.c"),
        "oracle_used": False,
    }
    PHASE_CERT.write_text(json.dumps(phase_certificate, indent=2, sort_keys=True) + "\n",
                          encoding="utf-8")

    def dominating_writers(trigger: str, register: str) -> list[str] | None:
        trigger_bank = trigger.split(":", 1)[0]
        pending = list(predecessor_edges.get(trigger, []))
        visited: set[str] = set()
        writers: set[str] = set()
        steps = 0
        local_failed = False
        while pending:
            node, kind = pending.pop()
            if node in visited:
                continue
            visited.add(node)
            steps += 1
            if (steps > 2048 or node.split(":", 1)[0] != trigger_bank or
                    kind.startswith("RETURN_") or kind.startswith("DIRECT_CALL")):
                local_failed = True
                break
            matches = [event["Stable_Id"] for event in events_by_context.get(node, [])
                       if event["Register"] == register and event["Access"] in ("WRITE", "READ_MODIFY_WRITE")]
            if matches:
                writers.update(matches)
                continue
            incoming = predecessor_edges.get(node, [])
            if not incoming:
                local_failed = True
                break
            pending.extend(incoming)
        if writers and not local_failed:
            return sorted(writers)
        # A register initialized once in the reset-root call tree can dominate a
        # later main-loop trigger even though it is in another bank/procedure.
        global_events = [event for event in exact if event["Register"] == register and
                         event["Access"] in ("WRITE", "READ_MODIFY_WRITE")]
        writer_contexts = {event["Context"] for event in global_events}
        if len(writer_contexts) == 1:
            writer = next(iter(writer_contexts))
            direct = reachable(trigger) and not reachable(trigger, writer)
            nmi_enable = "00:8212:0:1:1"
            nmi_root = "00:8216:0:1:1"
            phased = (trigger == "00:8350:0:1:0" and
                      register in phase_unique_writers and
                      phase_certificate_valid and
                      contexts[nmi_enable]["Bytes"] == "8D0042" and
                      trigger_value(nmi_enable, "STA") == 0x81 and
                      reachable_from(nmi_root, trigger))
            if direct or phased:
                return sorted(event["Stable_Id"] for event in global_events)
        return None

    for row in exact:
        if row["Register"] not in ("$420B", "$420C"):
            continue
        static_value = (0 if row["Mnemonic"] == "STZ" else
                        trigger_value(row["Context"], row["Mnemonic"]))
        families = row["Families"].split(";")
        needed: set[str] = set()
        if static_value:
            for channel in range(8):
                if static_value & (1 << channel):
                    if row["Register"] == "$420B":
                        needed.update(f"$43{channel:X}{offset:X}" for offset in range(7))
                    else:
                        # Direct HDMA consumes DMAP, BBAD and A1T/A1B. DASB is
                        # additionally required only when DMAP selects indirect.
                        needed.update(f"$43{channel:X}{offset:X}" for offset in range(5))
                        dmap_events = [event for event in exact
                                       if event["Register"] == f"$43{channel:X}0"]
                        dmap_values = {trigger_value(event["Context"], event["Mnemonic"])
                                       for event in dmap_events}
                        if any(value is not None and value & 0x40 for value in dmap_values):
                            needed.add(f"$43{channel:X}7")
        found: dict[str, list[str]] = {}
        for register in sorted(needed):
            writers = dominating_writers(row["Context"], register)
            if writers is not None:
                found[register] = writers
        missing = sorted(needed - found.keys())
        payload_status = ("NOT_APPLICABLE_DISABLE" if not static_value else
                          "UNIQUE_PREDECESSOR_INITIALIZATION_PROVED" if not missing else
                          "PAYLOAD_DOMINANCE_OPEN")
        receipts.append({
            "receipt_id": "TP10-" + row["Stable_Id"].removeprefix("TPHW-"),
            "trigger_event": row["Stable_Id"],
            "context": row["Context"],
            "families": families,
            "register": row["Register"],
            "access_width": int(row["Instruction_Access_Width"]),
            "static_trigger_value": static_value,
            "value_authority": ("EXACT_ZERO" if static_value == 0 else
                                "EXACT_IMMEDIATE_DOMINATING_PREDECESSOR" if static_value is not None else
                                "PRODUCER_DOMAIN_OPEN"),
            "family_register_surface": sorted(set().union(*(family_writers[f] for f in families))),
            "required_payload_registers": sorted(needed),
            "dominating_payload_events": dict(sorted(found.items())),
            "missing_dominating_payload_registers": missing,
            "payload_initialization_authority": payload_status,
            "controller_owner": "runtime/src/theme_park_dma.c",
            "scheduler_owner": "runtime/src/theme_park_scheduler.c",
            "receiver_owner": "11C_PPU_OR_LATER_COMPONENT_PENDING",
            "status": ("DISABLE_ONLY_PROVED" if static_value == 0 else
                       "TRIGGER_AND_PAYLOAD_WRITERS_PROVED_RECEIVER_PENDING" if static_value is not None and not missing else
                       "TRIGGER_MASK_PROVED_PAYLOAD_OPEN" if static_value is not None else
                       "SOURCE_REACHED_TRIGGER_AND_PAYLOAD_OPEN"),
        })
    RECEIPTS.write_text(json.dumps(receipts, indent=2, sort_keys=True) + "\n", encoding="utf-8")

    registers = Counter(row["Register"] for row in exact)
    summary = {
        "schema": "theme-park-v10c-dma-source-join-v1",
        "status": ("GENERAL_CONTROLLER_BOUND_ALL_EXACT_SOURCE_CONFIGURATIONS_PROVED"
                   if all(r["status"] != "TRIGGER_MASK_PROVED_PAYLOAD_OPEN" for r in receipts)
                   else "GENERAL_CONTROLLER_BOUND_EXACT_SOURCE_CONFIGURATION_PROOF_OPEN"),
        "oracle_used": False,
        "runtime_decoder_used": False,
        "exact_byte_register_events": len(exact),
        "exact_contexts": len({row["Context"] for row in exact}),
        "exact_trigger_events": len(receipts),
        "proved_disable_triggers": sum(r["status"] == "DISABLE_ONLY_PROVED" for r in receipts),
        "proved_nonzero_trigger_masks": sum(r["static_trigger_value"] not in (None, 0) for r in receipts),
        "proved_payload_writer_sets": sum(r["status"] == "TRIGGER_AND_PAYLOAD_WRITERS_PROVED_RECEIVER_PENDING" for r in receipts),
        "open_payload_writer_sets": sum(r["status"] == "TRIGGER_MASK_PROVED_PAYLOAD_OPEN" for r in receipts),
        "open_trigger_value_domains": sum(r["value_authority"] == "PRODUCER_DOMAIN_OPEN" for r in receipts),
        "conservative_unresolved_dma_intersections": len(unresolved),
        "register_event_counts": dict(sorted(registers.items())),
        "channels_with_exact_register_events": sorted({(int(r["Register"][1:], 16) - 0x4300) // 0x10
                                                        for r in exact if r["Register"].startswith("$43")}),
        "input_sha256": sha(SOURCE),
        "events_sha256": sha(EVENTS),
        "receipts_sha256": sha(RECEIPTS),
        "startup_phase_certificate": str(PHASE_CERT.relative_to(ROOT)).replace("\\", "/"),
        "startup_phase_certificate_sha256": sha(PHASE_CERT),
        "failure_rule": "unproved effective address or trigger/payload value cannot authorize a Theme Park transfer",
    }
    SUMMARY.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    print(json.dumps({"exact_events": len(exact), "triggers": len(receipts),
                      "unresolved": len(unresolved), "status": summary["status"]}))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
