#!/usr/bin/env python3
"""Freeze the deterministic Theme Park V02C offline semantic authority."""
from __future__ import annotations

import csv
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from analysis.w65c816.coverage import semantic_matrix
from analysis.w65c816.opcodes import OPCODES, iter_legal_contexts
from analysis.w65c816.state import raw_mode_accounting

ANALYSIS = ROOT / "analysis" / "w65c816"
SPEC = ROOT / "research" / "w65c816s-2024-03-13.pdf"
EXPECTED_SPEC_SHA256 = "b9177e1b045d2c8a801d1b23619abb4e5b29b88868fa491df7296dbc0b13447e"
MANIFEST = ROOT / "docs" / "V02C-SEMANTIC-MANIFEST.json"
MATRIX = ROOT / "docs" / "V02C-SEMANTIC-LOWERER-MATRIX.csv"
SEMANTIC_FILES = tuple(sorted(path for path in ANALYSIS.glob("*.py") if path.name != "__init__.py"))


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def normalized(path: Path) -> bytes:
    return path.read_bytes().replace(b"\r\n", b"\n")


def build_manifest() -> dict:
    if SPEC.is_file() and sha256(SPEC.read_bytes()) != EXPECTED_SPEC_SHA256:
        raise ValueError("local WDC specification hash does not match frozen authority")
    hashes = {path.relative_to(ROOT).as_posix(): sha256(normalized(path)) for path in SEMANTIC_FILES}
    combined = b"".join(name.encode("utf-8") + b"\0" + hashes[name].encode("ascii") + b"\n"
                        for name in sorted(hashes))
    contexts = list(iter_legal_contexts())
    raw_legal, raw_rejected = raw_mode_accounting()
    return {
        "schema": "theme-park-v02c-semantic-manifest-v1",
        "status": "OFFLINE_SEMANTIC_FOUNDATION",
        "authority": "WDC W65C816S datasheet, March 13 2024",
        "specification": {
            "path": SPEC.relative_to(ROOT).as_posix(),
            "sha256": EXPECTED_SPEC_SHA256,
            "official_url": "https://www.westerndesigncenter.com/wdc/documentation/w65c816s.pdf",
        },
        "semantic_source_sha256": hashes,
        "decoder_semantic_sha256": sha256(combined),
        "counts": {
            "opcodes": len(OPCODES),
            "mnemonics": len({item.mnemonic for item in OPCODES}),
            "addressing_modes": len({item.mode for item in OPCODES}),
            "legal_e_m_x_contexts": len(contexts),
            "raw_opcode_e_m_x_rows": raw_legal + raw_rejected,
            "contradictory_emulation_rows_rejected": raw_rejected,
            "decoded_semantics": sum(row.decoded_semantic for row in semantic_matrix()),
            "native_lowerers": sum(row.native_lowerer_implemented for row in semantic_matrix()),
            "production_reached": sum(row.production_reached for row in semantic_matrix()),
        },
        "production": {
            "generic_decoder_selectable": False,
            "runtime_opcode_switch": False,
            "native_lowering_owner": "07C",
            "production_reachability_owner": "04C-07C",
        },
        "oracle_inputs": [],
        "emulator_semantic_inputs": [],
    }


def write() -> None:
    MANIFEST.write_text(json.dumps(build_manifest(), indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")
    with MATRIX.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.writer(handle, lineterminator="\n")
        writer.writerow(("mnemonic", "decoded_semantic", "native_lowerer_implemented", "production_reached"))
        for row in semantic_matrix():
            writer.writerow((row.mnemonic, str(row.decoded_semantic).lower(),
                             str(row.native_lowerer_implemented).lower(), str(row.production_reached).lower()))


if __name__ == "__main__":
    write()
