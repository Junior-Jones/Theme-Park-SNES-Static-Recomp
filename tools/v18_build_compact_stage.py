#!/usr/bin/env python3
"""Build the token-qualified stage as a complete GCC static archive."""
import argparse
import concurrent.futures
import hashlib
import json
import subprocess
from pathlib import Path
ROOT = Path(__file__).resolve().parents[1]
def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('stage',type=Path)
    parser.add_argument('--archive-only',action='store_true')
    args=parser.parse_args()
    stage=args.stage.resolve()
    proof=json.loads((stage/'compiler-token-equivalence.json').read_text())
    if proof['status']!='PASS_ALL_SHARDS_COMPILER_EXPANDED_TOKENS_IDENTICAL':
        raise ValueError('compiler token proof required')
    inventory=json.loads((ROOT/'config/compiler-inventory.json').read_text())['selected_future_secondary']
    includes=[ROOT/'static-core/internal',ROOT/'static-core/generated/scpu',ROOT/'static-core/generated/timing',ROOT/'runtime/include']
    objects=stage/'objects'; objects.mkdir(exist_ok=True)
    def compile_source(path):
        target=objects/(path.stem+'.o')
        subprocess.run([inventory['path'],'-c','-std=c11','-O2','-Wall','-Wextra','-Werror',*[f'-I{p}' for p in includes],str(path),'-o',str(target)],check=True,capture_output=True)
        return target
    if args.archive_only:
        compact_objects=[objects/(p.stem+'.o') for p in sorted(stage.glob('tp_v07_shard_*.c'))]
        if any(not p.is_file() for p in compact_objects):
            raise ValueError('archive-only requires all compiled stage objects')
    else:
        with concurrent.futures.ThreadPoolExecutor(max_workers=6) as pool:
            compact_objects=list(pool.map(compile_source,sorted(stage.glob('tp_v07_shard_*.c'))))
    native=[ROOT/line for line in (ROOT/'static-core/generated/scpu/tp_v07_sources.txt').read_text().splitlines() if 'tp_v07_shard_' not in line]
    native += [ROOT/name for name in (
        'runtime/src/theme_park_bus.c','runtime/src/theme_park_scheduler.c',
        'runtime/src/theme_park_dma.c','runtime/src/theme_park_ppu.c',
        'runtime/src/theme_park_renderer.c','runtime/src/theme_park_apu.c',
        'runtime/src/theme_park_spc700.c','runtime/generated/theme_park_spc700_aot.c',
        'runtime/src/theme_park_input.c','runtime/src/theme_park_sdsp.c',
        'runtime/src/theme_park_machine.c','static-core/generated/timing/theme_park_v09_timing.c')]
    # Rebuild current native owners: historical archive receipts may predate repairs.
    reused=[compile_source(p) for p in native]
    if len(compact_objects)!=670 or len(reused)!=14:
        raise ValueError(f'incomplete archive members: compact={len(compact_objects)} reused={len(reused)}')
    archive=stage/'libtheme_park_v18c.a'
    response=stage/'archive.rsp'
    response.write_text('\n'.join('"'+str(p).replace('\\','/')+'"' for p in compact_objects+reused)+'\n',encoding='utf-8')
    subprocess.run([inventory['archiver'],'rcs',str(archive),'@'+str(response)],check=True)
    receipt=dict(status='PASS_STAGED_GCC_COMPLETE_ARCHIVE_RUNTIME_EQUIVALENCE_PENDING',archive_sha256=sha(archive),archive_bytes=archive.stat().st_size,compiled_shards=len(compact_objects),current_native_sources={str(p.relative_to(ROOT)):sha(p) for p in native},current_native_objects={p.name:sha(p) for p in reused})
    (stage/'static-build-receipt.json').write_text(json.dumps(receipt,indent=2,sort_keys=True)+'\n',encoding='utf-8')
    print(json.dumps(receipt,indent=2))
if __name__=='__main__': main()
