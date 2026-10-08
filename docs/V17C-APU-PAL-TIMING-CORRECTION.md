# Theme Park PAL/APU timing correction — 2026-10-04

Status: PAL/APU correction implemented; visible rendering and active native PCM restored; full route/device acceptance remains open.

Theme Park is a PAL target. The current machine profile uses the 21,281,370 Hz
PAL master clock, 312 base scanlines and rational natural presentation pacing of
approximately 50.006979 frames per second. The independent audio oscillator is
1,025,280 S-SMP clocks per second and 32,040 DSP sample phases per second; it is
not an NTSC selector and does not replace the PAL machine clock.

The reset-to-first-APUIO comparison showed identical S-CPU instruction clocks up
to the first polling divergence. The defect was in the S-SMP owner: its oscillator
advanced correctly, but IPL instruction execution began two processor clocks too
early. The correction now:

- retains half-phase rational scheduling with residual phase;
- advances timers/DSP during the two-clock S-SMP reset-startup hold;
- prevents SPC700 opcode execution during that hold;
- stages immutable IPL reads and writes at exact bus-event positions;
- records static entry on the first uploaded-code bus event rather than on the
  preceding jump's completion;
- labels and paces the copied frontend as natural PAL rather than NTSC.

Focused evidence after correction:

- first S-CPU port-2 setup write: master clock 50,324 in both implementations;
- final setup writes: ports 2/3/1 at 1,810,854 / 1,810,860 / 1,810,974;
- final token write: port 0 value `3E` at 1,811,056;
- first post-upload command: port 0 value `4A` at 1,933,774;
- static entry processor cycle: 87,303, matching reference phase 174,606;
- upload size remains 3,387 bytes and no core owner stop occurs in the focused run.

The later black-screen investigation found a separate 08C/09C integration bug:
the `$4202-$4206` arithmetic unit was implemented but never advanced by the
context timing-plan bus/internal cycles. At `04:80C4`, the reference read `001A`
from `$4216` while the core read zero and branched into the wrong boot path.
Advancing that owner once per S-CPU cycle removed the mismatch; 13,525 consecutive
S-CPU pre-instruction states then agreed across the former divergence window.

The corrected natural-PAL 300-frame run is nonblank at brightness 15 in Mode 3
and displays the Theme Park/Bullfrog title image. It produces 192,675 stereo PCM
frames but all samples remain zero; the comparison machine is also silent at this
title checkpoint. The first 20,000 uploaded S-SMP pre-instruction states and
sparse checkpoints through instruction 300,000 match the comparison state.

A natural 600-frame run with a one-frame Start input at frame 300 produces
384,888 known stereo PCM frames through the public frontend FIFO, including
10,246 nonzero samples with peak magnitude 27,875. Start and A independently
produce the same active-audio result at that checkpoint. This closes the earlier
question of whether the core can produce and deliver active native PCM; it does
not by itself close the complete gameplay route or physical DirectSound device
acceptance. Older V16C/V17C PASS records remain superseded and are not current
Theme Park completion evidence.
