#!/usr/bin/env python3
"""Stage reversible compile-time bookkeeping compaction; preserve exact bodies."""
from __future__ import annotations
import argparse
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ENTRY = re.compile(r'            static const uint8_t expected_bytes\[\] = \{ (?P<bytes>[^\n]+) \};\n            if \(tp_scpu_guard_code\(cpu, bus, (?P<address>0x[0-9A-F]+u),\n                                   expected_bytes, sizeof\(expected_bytes\)\) != TP_SCPU_EXECUTED\)\n                return TP_SCPU_STOPPED;')
EXIT = re.compile(r'            cpu->pbr = (?P<bank>0x[0-9A-F]+u);\n            cpu->pc = (?P<pc>0x[0-9A-F]+u);\n            if \(tp_scpu_expect_next\(cpu, (?P<next>0x[0-9A-F]+u)\) != TP_SCPU_EXECUTED\)\n                return TP_SCPU_STOPPED;\n            return tp_scpu_finish\(cpu, bus, (?P<cycles>[0-9]+u)\);')
HEADER = '''/* Compile-time factoring only; expanded statements retain original order. */
#define TP_STATIC_GUARD(address, ...) \\
    static const uint8_t expected_bytes[] = { __VA_ARGS__ }; \\
    if (tp_scpu_guard_code(cpu, bus, address, expected_bytes, sizeof(expected_bytes)) != TP_SCPU_EXECUTED) \\
        return TP_SCPU_STOPPED
#define TP_STATIC_EXIT(bank, pc_value, next_key, cycles) \\
    cpu->pbr = bank; \\
    cpu->pc = pc_value; \\
    if (tp_scpu_expect_next(cpu, next_key) != TP_SCPU_EXECUTED) \\
        return TP_SCPU_STOPPED; \\
    return tp_scpu_finish(cpu, bus, cycles)
'''

def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()

def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--source', type=Path, default=ROOT/'static-core/generated/scpu')
    args = parser.parse_args()
    output = args.output.resolve()
    if output == (ROOT / 'static-core/generated/scpu').resolve():
        raise ValueError('stage outside the current generated authority')
    output.mkdir(parents=True, exist_ok=True)
    rows = []
    if (args.source/'tp_v18_compact.h').exists():
        raise ValueError('source is already compacted; use the frozen predecessor or cold regenerated original')
    for path in sorted(args.source.glob('tp_v07_shard_*.c')):
        before = path.read_bytes()
        text = before.decode('utf-8').replace('\r\n', '\n')
        replacements = []
        def entry(match):
            replacement = f"            TP_STATIC_GUARD({match['address']}, {match['bytes']});"
            replacements.append((replacement, match[0]))
            return replacement
        def exit_body(match):
            replacement = f"            TP_STATIC_EXIT({match['bank']}, {match['pc']}, {match['next']}, {match['cycles']});"
            replacements.append((replacement, match[0]))
            return replacement
        compacted, entries = ENTRY.subn(entry, text)
        compacted, exits = EXIT.subn(exit_body, compacted)
        expanded = compacted
        for replacement, original in replacements:
            expanded = expanded.replace(replacement, original)
        if expanded != text:
            raise AssertionError(f'round-trip statement mismatch: {path.name}')
        compacted = compacted.replace('#include "tp_v07_generated.h"', '#include "tp_v07_generated.h"\n#include "tp_v18_compact.h"', 1)
        after = compacted.encode('utf-8')
        (output / path.name).write_bytes(after)
        rows.append(dict(path=path.name, sha256_before=digest(before), sha256_after=digest(after), bytes_before=len(before), bytes_after=len(after), entry_templates=entries, exit_templates=exits, exact_statement_round_trip=True))
    (output / 'tp_v18_compact.h').write_text(HEADER, encoding='utf-8', newline='\n')
    receipt = dict(schema='theme-park-representation-compaction-v1', status='STAGED_EXACT_STATEMENT_ROUND_TRIP_BUILD_AND_RUNTIME_PENDING', contexts_removed=0, files=rows, source_bytes_before=sum(r['bytes_before'] for r in rows), source_bytes_after=sum(r['bytes_after'] for r in rows)+len(HEADER.encode()), macro_header_sha256=digest(HEADER.encode()), canonical_manifest_sha256=digest((ROOT/'docs/V07C-production-manifest.csv').read_bytes()))
    (output / 'compaction-receipt.json').write_text(json.dumps(receipt, indent=2, sort_keys=True)+'\n', encoding='utf-8')
    print(json.dumps({k:v for k,v in receipt.items() if k!='files'}, indent=2))
    return 0

if __name__ == '__main__':
    raise SystemExit(main())
