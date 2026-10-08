#!/usr/bin/env python3
"""Compare compiler-expanded C tokens for every original and staged shard."""
from __future__ import annotations
import argparse
import concurrent.futures
import hashlib
import json
import re
import subprocess
from pathlib import Path
ROOT = Path(__file__).resolve().parents[1]
TOKEN = re.compile(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|[A-Za-z_][A-Za-z_0-9]*|(?:[0-9][A-Za-z_0-9.]*)|\S')

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('stage', type=Path)
    parser.add_argument('--original', type=Path, default=ROOT/'static-core/generated/scpu')
    args = parser.parse_args()
    stage = args.stage.resolve()
    inventory = json.loads((ROOT/'config/compiler-inventory.json').read_text())
    compiler = inventory['selected_future_secondary']['path']
    includes = [ROOT/'static-core/internal', ROOT/'static-core/generated/scpu', ROOT/'static-core/generated/timing', ROOT/'runtime/include']
    def check(path):
        def tokens(source):
            result = subprocess.run([compiler, '-E', '-P', '-std=c11', *[f'-I{p}' for p in includes], str(source)], check=True, capture_output=True)
            return TOKEN.findall(result.stdout.decode('utf-8'))
        original = tokens(args.original/path.name)
        compact = tokens(path)
        if original != compact:
            first = next((i for i,(a,b) in enumerate(zip(original,compact)) if a!=b), min(len(original),len(compact)))
            raise AssertionError(f'{path.name}: preprocessor token mismatch at {first}')
        return dict(path=path.name, token_count=len(original), expanded_tokens_sha256=hashlib.sha256('\n'.join(original).encode()).hexdigest())
    with concurrent.futures.ThreadPoolExecutor(max_workers=6) as pool:
        rows = list(pool.map(check, sorted(stage.glob('tp_v07_shard_*.c'))))
    receipt = dict(status='PASS_ALL_SHARDS_COMPILER_EXPANDED_TOKENS_IDENTICAL', compiler=compiler, shards=len(rows), files=rows)
    (stage/'compiler-token-equivalence.json').write_text(json.dumps(receipt,indent=2,sort_keys=True)+'\n',encoding='utf-8')
    print(receipt['status'], len(rows))
if __name__ == '__main__':
    main()
