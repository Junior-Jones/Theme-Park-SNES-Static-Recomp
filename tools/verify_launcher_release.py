"""Verify source integrity, official launcher schema and portable output.

Requires jsonschema 4.23.0. No ROM, GUI, credentials or runtime user data needed.
"""
from pathlib import Path
import argparse
import hashlib
import json
import urllib.request
import urllib.error
import zipfile
import jsonschema

ROOT=Path(__file__).resolve().parents[1]
FILES=('Launcher.exe','recomplauncher.json','README.txt','VERSION.txt',
       'SDL-LICENSE.txt','THIRD-PARTY-NOTICES.txt')
SCHEMA='https://recomplauncher.com/schema/recomplauncher.json'
SCHEMA_MIRROR=('https://raw.githubusercontent.com/elripalda/RecompLauncher/'
               '0a053e8d9f6f3b82cf6a4521b8bd906aeb470091/docs/recomplauncher.schema.json')
SCHEMA_MIRROR_DIGEST='bd5b7a672283e5cddef24afc32b2581c8a7b2226070ac77cb7a8776c48f7de50'

def official_schema():
    try:
        request=urllib.request.Request(SCHEMA,headers={'User-Agent':'ThemePark-release-validator/1.0.1'})
        with urllib.request.urlopen(request,timeout=30) as response:
            return json.load(response),SCHEMA
    except (urllib.error.URLError,TimeoutError) as error:
        # The public site can reject hosted CI IPs with HTTP 403. Use the same
        # official upstream schema at a fixed commit, never an unvalidated pass.
        print(f'Schema endpoint unavailable ({type(error).__name__}); checking pinned official upstream schema.')
        with urllib.request.urlopen(SCHEMA_MIRROR,timeout=30) as response:
            schema=json.load(response)
        digest=hashlib.sha256(json.dumps(schema,sort_keys=True).encode()).hexdigest()
        assert digest==SCHEMA_MIRROR_DIGEST,'Pinned upstream schema integrity mismatch'
        return schema,SCHEMA_MIRROR

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--release-dir',type=Path,required=True)
    parser.add_argument('--schema',type=Path)
    parser.add_argument('--zip',type=Path)
    args=parser.parse_args()
    inventory=json.loads((ROOT/'SOURCE-MANIFEST.json').read_text(encoding='utf-8-sig'))
    assert inventory['version']=='1.0.1','Incorrect source version'
    for rel,record in inventory['files'].items():
        path=ROOT/rel
        assert path.resolve().is_relative_to(ROOT.resolve()),rel
        assert path.stat().st_size==record['bytes'] and sha(path)==record['sha256'],rel
    profile=json.loads((ROOT/'recomplauncher.json').read_text(encoding='utf-8-sig'))
    if args.schema:
        schema=json.loads(args.schema.read_text(encoding='utf-8-sig'))
        schema_source=str(args.schema)
    else:schema,schema_source=official_schema()
    jsonschema.Draft7Validator.check_schema(schema)
    jsonschema.Draft7Validator(schema).validate(profile)
    assert profile['repo']=='Junior-Jones/Theme-Park-SNES-Static-Recomp'
    assert profile['start']['program']==['Launcher.exe']
    assert profile['start']['args']==['--game','{game}']
    assert profile['config'][0]['game_path']=='ROM/Path'
    assert profile['saves']==['{install}/Saves']
    assert not any('widescreen' in s['id'] for s in profile.get('settings',[]))
    assert 'Version: 1.0.1' in (ROOT/'VERSION.txt').read_text(encoding='utf-8')
    release=args.release_dir.resolve()
    for name in FILES:
        p=release/name
        assert p.is_file(),f'Missing release file: {name}'
        if name!='Launcher.exe':assert sha(p)==sha(ROOT/name),name
    binary=(release/'Launcher.exe').read_bytes()
    for encoding in ('ascii','utf-16le'):
        text=binary.decode(encoding,errors='ignore').lower()
        assert not any(v in text for v in ('tjon1','d:\\users','c:\\users','retro\\recomp','retro/recomp')),'Developer path in executable'
    if args.zip:
        args.zip.parent.mkdir(parents=True,exist_ok=True)
        with zipfile.ZipFile(args.zip,'x',zipfile.ZIP_DEFLATED,compresslevel=6) as z:
            for name in FILES:z.write(release/name,name)
        with zipfile.ZipFile(args.zip) as z:
            assert set(z.namelist())==set(FILES)
            assert z.testzip() is None
            for name in FILES:assert hashlib.sha256(z.read(name)).hexdigest()==sha(release/name)
    print(json.dumps({'source_files_verified':len(inventory['files']),
        'official_schema_valid':True,'release_files':list(FILES),
        'rom_and_user_data_included':False,'launcher_sha256':sha(release/'Launcher.exe'),
        'schema_sha256':hashlib.sha256(json.dumps(schema,sort_keys=True).encode()).hexdigest(),
        'schema_source':schema_source,
        'release_zip_sha256':sha(args.zip) if args.zip else None},indent=2))

if __name__=='__main__':main()
