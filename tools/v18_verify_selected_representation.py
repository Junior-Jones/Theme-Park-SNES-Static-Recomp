#!/usr/bin/env python3
"""Bind historical lowering and compaction receipts to selected source bytes.

This is a source-chain check, not cold regeneration or full Pass-B approval.
"""
import argparse
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--original', type=Path,
                        default=ROOT / 'build/v18c-precompaction-recovery/scpu')
    parser.add_argument('--production', type=Path)
    args = parser.parse_args()
    receipt_path = ROOT / 'docs/V18C-representation-compaction.json'
    receipt = json.loads(receipt_path.read_text(encoding='utf-8'))
    tokens_path = ROOT / 'docs/V18C-compiler-token-equivalence.json'
    tokens = json.loads(tokens_path.read_text(encoding='utf-8'))
    selected = ROOT / 'static-core/generated/scpu'
    original = args.original
    names = {row['path'] for row in receipt['files']}
    assert len(names) == len(receipt['files']) == 670
    assert names == {p.name for p in selected.glob('tp_v07_shard_*.c')}
    assert names == {row['path'] for row in tokens['files']}
    assert tokens['status'] == 'PASS_ALL_SHARDS_COMPILER_EXPANDED_TOKENS_IDENTICAL'
    assert sha(ROOT / 'docs/V07C-production-manifest.csv') == receipt['canonical_manifest_sha256']
    assert sha(selected / 'tp_v18_compact.h') == receipt['macro_header_sha256']
    for row in receipt['files']:
        assert row['exact_statement_round_trip'] is True
        assert sha(original / row['path']) == row['sha256_before'], row['path']
        assert sha(selected / row['path']) == row['sha256_after'], row['path']
    production_check = None
    if args.production:
        with args.production.open(encoding='utf-8', newline='') as stream:
            fresh = list(csv.DictReader(stream))
        with (ROOT / 'docs/V07C-production-manifest.csv').open(encoding='utf-8', newline='') as stream:
            historical = list(csv.DictReader(stream))
        assert len(fresh) == len(historical) == 71986
        for current, prior in zip(fresh, historical):
            assert current.pop('Admission_State') == 'NATIVE_SOURCE_GENERATED_UNCOMPILED'
            assert prior.pop('Admission_State') == 'ADMITTED_NATIVE_SOURCE_UNCOMPILED'
            assert current == prior, current['Context']
        production_check = dict(rows=len(fresh),
            status='PASS_ALL_AUTHORITY_FIELDS_IDENTICAL_ONLY_HISTORICAL_ADMISSION_LABEL_DIFFERS',
            regenerated_sha256=sha(args.production))
    result = dict(
        schema='theme-park-selected-representation-chain-v1',
        status='PASS_SELECTED_BYTES_MATCH_ORIGINAL_COMPACTION_CHAIN',
        shards=len(names), contexts_removed=receipt['contexts_removed'],
        compaction_receipt_sha256=sha(receipt_path),
        token_receipt_sha256=sha(tokens_path),
        production_manifest_comparison=production_check,
        cold_regeneration_proven=False, full_pass_b_proven=False)
    (ROOT / 'docs/V18C-selected-representation-chain.json').write_text(
        json.dumps(result, indent=2, sort_keys=True)+'\n', encoding='utf-8')
    print(result['status'])

if __name__ == '__main__':
    main()
