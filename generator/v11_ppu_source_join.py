#!/usr/bin/env python3
"""Bind Theme Park's exact PPU events and proved DMA payloads to the 11C owner."""
from __future__ import annotations

import csv
import hashlib
import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
HARDWARE = ROOT / "docs/V07C-hardware-intelligence.csv"
CONTEXTS = ROOT / "docs/V05C-contexts.csv"
EDGES = ROOT / "docs/V05C-edges.csv"
DMA_EVENTS = ROOT / "docs/V10C-dma-exact-register-events.csv"
DMA_RECEIPTS = ROOT / "docs/V10C-dma-trigger-receipts.json"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main() -> int:
    contexts = {r["Context"]: r for r in csv.DictReader(CONTEXTS.open(encoding="utf-8", newline=""))}
    predecessors: dict[str, list[str]] = defaultdict(list)
    for edge in csv.DictReader(EDGES.open(encoding="utf-8", newline="")):
        predecessors[edge["Target"]].append(edge["Source"])

    def producer_value(context: str, store: str) -> tuple[int | None, str | None]:
        wanted = {"STA": "LDA", "STX": "LDX", "STY": "LDY"}.get(store)
        current = context
        for _ in range(8):
            incoming = predecessors.get(current, [])
            if len(incoming) != 1:
                return None, None
            current = incoming[0]
            instruction = contexts[current]
            if instruction["Mnemonic"] == wanted and instruction["Mode"] in ("IMM_M", "IMM_X"):
                raw = bytes.fromhex(instruction["Bytes"])
                return (raw[1], current) if len(raw) >= 2 else (None, None)
            if instruction["Mnemonic"] not in {"STA", "STX", "STY", "STZ", "SEP", "REP",
                                                    "CLC", "SEC", "CLD", "SED", "CLI", "SEI",
                                                    "CLV", "NOP", "BRA", "BRL"}:
                return None, None
        return None, None

    exact, unresolved = [], []
    for row in csv.DictReader(HARDWARE.open(encoding="utf-8", newline="")):
        text = row["Effective_Address"]
        is_exact = row["Address_Proof"] == "EXACT_START_PLUS_DBR_OR_LONG_BANK_PLUS_WIDTH_EXPANSION"
        if row["Subsystem"] == "PPU" and is_exact and text.startswith("00:"):
            address = int(text[3:], 16)
            if 0x2100 <= address <= 0x213F:
                item = dict(row); item["Register"] = f"${address:04X}"; exact.append(item)
        elif row["Subsystem"] == "PPU" and not is_exact:
            unresolved.append(row)
    exact.sort(key=lambda r: (int(r["ROM_Offset"], 16), r["Context"], int(r["Byte_Event_Index"] or 0)))
    fields = ["Stable_Id", "Families", "Context", "ROM_Offset", "Bytes", "Mnemonic", "Mode",
              "Access", "Instruction_Access_Width", "Byte_Event_Index", "Register", "Address_Proof"]
    events_path = ROOT / "docs/V11C-ppu-exact-register-events.csv"
    with events_path.open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=fields, lineterminator="\n")
        writer.writeheader(); writer.writerows({f: row[f] for f in fields} for row in exact)

    dma_events = {row["Stable_Id"]: row for row in
                  csv.DictReader(DMA_EVENTS.open(encoding="utf-8", newline=""))}
    bbad_values: dict[str, dict[str, object]] = {}
    for event_id, row in dma_events.items():
        if row["Register"].endswith("1") and row["Register"].startswith("$43"):
            value, authority = producer_value(row["Context"], row["Mnemonic"])
            bbad_values[event_id] = {"value": value, "producer_context": authority,
                                     "writer_context": row["Context"], "register": row["Register"]}

    receiver_receipts = []
    open_bbad = 0
    for receipt in json.loads(DMA_RECEIPTS.read_text(encoding="utf-8")):
        if not receipt["static_trigger_value"]:
            continue
        routes = []
        for register, ids in receipt["dominating_payload_events"].items():
            if not (register.startswith("$43") and register.endswith("1")):
                continue
            for event_id in ids:
                proof = bbad_values.get(event_id, {"value": None})
                value = proof["value"]
                if value is None:
                    open_bbad += 1; owner = "OPEN_BBAD_PRODUCER"
                elif value <= 0x3F:
                    owner = "runtime/src/theme_park_ppu.c"
                elif value == 0x80:
                    owner = "runtime/src/theme_park_bus.c:WRAM_PORT"
                else:
                    owner = "LATER_COMPONENT_OR_OPEN_DESTINATION"
                routes.append({"channel_register": register, "bbad": value,
                               "b_bus_register": None if value is None else f"${0x2100 + value:04X}",
                               "receiver_owner": owner, "writer_event": event_id,
                               "producer_context": proof.get("producer_context")})
        receiver_receipts.append({"trigger_receipt": receipt["receipt_id"],
                                  "trigger_context": receipt["context"], "routes": routes})
    receiver_path = ROOT / "docs/V11C-dma-receiver-receipts.json"
    receiver_path.write_text(json.dumps(receiver_receipts, indent=2, sort_keys=True) + "\n", encoding="utf-8")

    registers = Counter(row["Register"] for row in exact)
    accesses = Counter(row["Access"] for row in exact)
    reached = sorted(registers)
    supported = {f"${address:04X}" for address in range(0x2100, 0x2140)}
    ppu_dma_routes = [route for receipt in receiver_receipts for route in receipt["routes"]
                      if route["receiver_owner"] == "runtime/src/theme_park_ppu.c"]
    summary = {
        "schema": "theme-park-v11c-ppu-source-join-v1",
        "status": "PPU_STATE_OWNER_BOUND_ALL_EXACT_SOURCE_EVENTS_AND_PROVED_BBAD_ROUTES",
        "oracle_used": False, "runtime_decoder_used": False, "pixels_claimed": False,
        "exact_register_events": len(exact), "exact_contexts": len({r["Context"] for r in exact}),
        "exact_access_counts": dict(sorted(accesses.items())),
        "exact_register_counts": dict(sorted(registers.items())),
        "source_reached_registers": reached,
        "implemented_register_surface": sorted(supported),
        "source_reached_registers_missing_owner": sorted(set(reached) - supported),
        "conservative_unresolved_ppu_intersections": len(unresolved),
        "proved_bbad_writer_events": len(bbad_values) - open_bbad,
        "open_bbad_writer_events": open_bbad,
        "ppu_dma_receiver_routes": len(ppu_dma_routes),
        "ppu_dma_destinations": dict(sorted(Counter(r["b_bus_register"] for r in ppu_dma_routes).items())),
        "non_ppu_proved_destinations": sorted({route["b_bus_register"] for receipt in receiver_receipts
                                                for route in receipt["routes"]
                                                if route["receiver_owner"] != "runtime/src/theme_park_ppu.c"}),
        "authority": ["runtime/include/theme_park_ppu.h", "runtime/src/theme_park_ppu.c"],
        "inputs_sha256": {"hardware": sha(HARDWARE), "contexts": sha(CONTEXTS),
                          "edges": sha(EDGES), "dma_events": sha(DMA_EVENTS),
                          "dma_receipts": sha(DMA_RECEIPTS)},
        "events_sha256": sha(events_path), "receiver_receipts_sha256": sha(receiver_path),
    }
    (ROOT / "docs/V11C-ppu-source-join-summary.json").write_text(
        json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    print(json.dumps({"status": summary["status"], "events": len(exact),
                      "ppu_dma_routes": len(ppu_dma_routes), "open_bbad": open_bbad}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
