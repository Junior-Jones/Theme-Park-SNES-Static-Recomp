# Frontend/core/ROM connection review

Date: 2026-10-04

This review compares the frontend boundary used by Theme Park with the six SNES
static-recomp method references.  It does not import code, cartridge facts, or
runtime state from those projects.

## Common launcher ROM-loading contract

Rock n Roll Racing, Top Gear, SimCity, Civilization, Jungle Strike, and Gundam
Wing all use the same ownership pattern in their Windows launchers:

1. Open the selected `.sfc` file in binary mode.
2. Allocate exactly the project's supported ROM size.
3. Read exactly that many bytes and reject a trailing byte.
4. Pass the temporary buffer to the project create API.
5. Free the temporary launcher buffer immediately after create returns.

Consequently, every successful create boundary must validate the image and keep
its own durable ROM storage (directly or through an opaque core which owns it).

## Per-project core boundary

| Method reference | ROM ownership/verification | Reset/create boundary | Frame/audio boundary |
| --- | --- | --- | --- |
| Rock n Roll Racing | App core verifies the exact image and copies it into the instance. | Create performs full cold power-on; reset repeats it. | Steps the machine until the core frame sequence changes; machine audio sink fills the host FIFO; published BGR555 is converted for the frontend. |
| Top Gear | Runtime verifies exact size, SHA-256, header/checksum/reset-vector facts and copies the ROM. | Create calls the runtime reset after taking ownership. | Static runtime advances to a scheduler frame target and exposes the resulting frame/PCM state. |
| SimCity | Recomp instance owns a ROM copy and its runtime is reattached to that copy on cold reset. | Cold reset reconstructs runtime state and reconnects its audio sink. | Generated CPU advances to the scheduler frame target, S-SMP is joined to master time, then the current frame and queued PCM are exposed. |
| Civilization | App instance copies the ROM; the frontend/core load boundary verifies and attaches it. | Reset reconstructs core state, reattaches the verified ROM, and reconnects PCM. | Runs the static core to the requested frame, renders only after a successful route, and drains the host PCM FIFO. |
| Jungle Strike | Public core inspection verifies the image; the opaque core created from it owns the required state. | Core create already performs cold power-on; frontend reset replaces it with a newly powered core. | Runs a completed core frame (or headless equivalent), obtains the published frame, and drains audio with knownness information. |
| Gundam Wing | App owns a ROM copy; host validates exact size/SHA-256 before creating the opaque static core. | Reset rebuilds a fresh host/core boundary and resets input/PCM cursors. | Advances one core-completed frame, reads the published BGR555 frame, and drains core PCM through a host cursor. |

## Host audio transport comparison

Rock n Roll Racing, Top Gear, Jungle Strike and Gundam Wing expose native PCM
through a bounded pull FIFO, resample it to the selected device rate and submit
it to a DirectSound ring. SimCity and Civilization use the same bounded
`available/read` pull boundary but submit buffered blocks through WinMM. All six
keep native PCM production and guest clocks inside the core; the device cursor
is host-only flow control.

Theme Park follows the first pattern. Its DirectSound source is identical to the
Jungle Strike reference except for an explicit INI-file flush, and its Hermite
resampler source is identical. It drains known 32,040 Hz stereo frames after
each completed PAL frame, pumps already-produced PCM during the streamed advance,
resamples to the configured 48,000 Hz default, and starts the device only after
the safety prebuffer is filled.

## Theme Park comparison

Theme Park now follows the same lifetime and connection contract:

- The launcher reads exactly 1,048,576 bytes and rejects trailing data.
- `jungle_recomp_create` verifies Theme Park Europe SHA-256
  `c0a7e27131a7d8c9ef52a5227329e6de5846c045a9da1f3f84845e3be8e4efba`.
- The adapter copies the ROM into instance-owned storage before the launcher's
  temporary buffer is freed.
- Cold power-on attaches that owned buffer to `TPMachine`.
- The frontend requests a core-completed PAL frame, reads the core-published
  BGR555 pixels, converts them to BGRA, and drains the machine PCM FIFO.
- No Rock n Roll Racing core, ROM, hash, or generated source is selected.

This establishes that the file-loading lifetime and frontend/core plumbing are
structurally connected correctly. It does **not** establish complete gameplay.
After repairing the core's frozen `$4202-$4206` arithmetic owner, the current
300-frame headless capture is the visible Theme Park/Bullfrog title screen at
PAL speed. Its 192,675 stereo PCM frames are zero, and the comparison machine is
also silent at that title checkpoint. A natural 600-frame run with a one-frame
Start input at frame 300 produces 384,888 known stereo PCM frames, including
10,246 nonzero samples with peak magnitude 27,875, through the same public
frontend FIFO. The connector test passes with 1,743 PCM frames over its first
three PAL frames, and the 32,040-to-48,000 Hz deterministic Hermite test passes
with 4,801 output frames. The original no-audio observation was therefore a
silent program checkpoint, not a ROM-load, PCM-FIFO, resampler or DirectSound
connection defect. Physical speaker/device acceptance remains a separate headed
user check.

## Result

Connection-method review: complete.

Visible connected core checkpoint: established at the 300-frame title screen.

Native active-PCM transport: established through the public frontend boundary.

Complete gameplay and physical device acceptance: not established. Version 17C
remains open pending the remaining natural route and headed user checks.
