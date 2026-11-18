"""Refresh the portable source inventory from tracked/non-ignored repo files."""
from pathlib import Path
import hashlib
import json
import re
import subprocess

ROOT=Path(__file__).resolve().parents[1]
manifest=ROOT/'SOURCE-MANIFEST.json'
data=json.loads(manifest.read_text(encoding='utf-8-sig'))
version=re.search(r'^Version:\s*(\d+\.\d+\.\d+)',
                  (ROOT/'VERSION.txt').read_text(encoding='utf-8'),re.M)
assert version,'Missing release version'
data['version']=version[1]
result=subprocess.run(['git','ls-files','--cached','--others','--exclude-standard','-z'],
                      cwd=ROOT,capture_output=True,check=True)
paths=sorted(set(p for p in result.stdout.decode('utf-8').split('\0')
                 if p and p!='SOURCE-MANIFEST.json' and (ROOT/p).is_file()))
for rel in list(data['files']):
    if rel not in paths:del data['files'][rel]
for rel in paths:
    path=ROOT/rel
    assert path.resolve().is_relative_to(ROOT.resolve()),rel
    assert path.suffix.lower() not in {'.sfc','.smc','.srm','.sav','.state','.tpsnap','.scsnap','.exe','.dll','.pdb','.obj','.lib','.log','.bmp','.wav'},rel
    contents=path.read_bytes();entry=data['files'].setdefault(rel,{})
    entry['sha256']=hashlib.sha256(contents).hexdigest();entry['bytes']=len(contents)
manifest.write_bytes((json.dumps(data,indent=2)+'\n').replace('\n','\r\n').encode('utf-8'))
print(f"Source manifest {data['version']}: {len(paths)} files")
