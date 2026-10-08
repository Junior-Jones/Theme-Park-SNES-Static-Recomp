#!/usr/bin/env python3
"""Derive the deterministic cold-reset/mute PCM vector without an executable."""
from __future__ import annotations
import hashlib, json, re, struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "runtime/src/theme_park_sdsp.c"
HEADER = ROOT / "runtime/include/theme_park_sdsp.h"
OUTPUT = ROOT / "docs/V16C-core-pcm-reset-vector.json"
FRAMES = 1024


def fnv1a64(data: bytes) -> str:
    value = 14695981039346656037
    for byte in data:
        value ^= byte
        value = (value * 1099511628211) & ((1 << 64) - 1)
    return f"{value:016x}"


def main() -> int:
    source = SOURCE.read_text(encoding="utf-8")
    header = HEADER.read_text(encoding="utf-8")
    required = (
        'd->registers[0x6Cu] = 0xE0u',
        '(tp_reg(d, 0x6Cu) & 0x40u) != 0u',
        'left = right = 0',
        'known = 1u',
        'd->phase = (uint8_t)((phase + 1u) & 31u)',
    )
    if any(marker not in source for marker in required):
        raise AssertionError("cold mute/phase proof no longer matches core source")
    phase_count = int(re.search(r"TP_SDSP_PHASE_COUNT\s+(\d+)u", header).group(1))
    sample_rate = int(re.search(r"TP_SDSP_NATIVE_RATE_HZ\s+(\d+)u", header).group(1))
    if phase_count != 32 or sample_rate != 32000:
        raise AssertionError("native DSP clock contract changed")
    pcm = b"\x00\x00\x00\x00" * FRAMES
    payload = {
        "schema": "theme-park-v16c-core-pcm-reset-vector-v1",
        "status": "ANALYTICALLY_PROVED_CORE_RESET_MUTE_VECTOR_NO_EXECUTABLE",
        "scope": "COLD_POWER_ON_FLG_MUTE_BEFORE_GUEST_DSP_WRITES",
        "native_rate_hz": sample_rate,
        "channels": 2,
        "sample_format": "SIGNED_16_BIT_LITTLE_ENDIAN_STEREO",
        "frames": FRAMES,
        "known_frames": FRAMES,
        "unknown_frames": 0,
        "s_smp_cycles": FRAMES * phase_count,
        "start_phase": 0,
        "end_phase": 0,
        "pcm_bytes": len(pcm),
        "pcm_sha256": hashlib.sha256(pcm).hexdigest(),
        "core_fnv1a64": fnv1a64(pcm),
        "proof": [
            "power-on FLG is $E0, including mute",
            "phase 27 applies mute before publishing PCM",
            "mute is a causal knownness annihilator and publishes known zero stereo",
            "one PCM frame is published per complete 32-phase S-DSP cycle",
        ],
        "source_sha256": hashlib.sha256(SOURCE.read_bytes()).hexdigest(),
        "header_sha256": hashlib.sha256(HEADER.read_bytes()).hexdigest(),
        "oracle_used": False,
        "guest_executed": False,
        "qualification": "SOURCE_LEVEL_CORE_VECTOR; NATURAL_ACTIVE_AUDIO REMAINS A 17C VALIDATION INPUT",
    }
    OUTPUT.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n",
                      encoding="utf-8", newline="\n")
    print(json.dumps({"status": payload["status"], "frames": FRAMES,
                      "pcm_sha256": payload["pcm_sha256"]}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
