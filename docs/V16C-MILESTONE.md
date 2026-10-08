# 16C — S-DSP/audio synthesis, command provenance and core PCM evidence

Status: closed at source/static-library level under the no-executable and pre-core
oracle restrictions. This is not a claim that Theme Park music/gameplay has run.

The closed 13C exact-PC authority contains 94 S-DSP port sites: 47 `$F2` writes,
46 `$F3` writes and one `$F3` read. The join preserves live S-SMP address/value
producers and routes the full 128-register domain to one Theme Park-owned fixed
hardware model rather than narrowing production to the twelve lexically immediate
global registers.

The owner advances one phase per scheduled S-SMP cycle. Its 32 phases implement the
eight voice pipelines, BRR range/filter/end/loop behavior, the exact 512-entry
Gaussian coefficient set, pitch/PMON, noise, KON/KOFF delay, ADSR/GAIN,
ENVX/OUTX/ENDX, master/echo volume, ESA/EDL, eight-tap FIR, feedback, echo writes,
mute/reset, saturation and signed stereo publication.

Knownness follows ARAM, retained BRR history, interpolation position, PMON, echo
history and PCM. Zero coefficients, zero volume, zero envelope and mute recover a
known observable only where causally valid. An unknown S-DSP register read that can
enter S-SMP control flow fails closed. PCM uses an 8,192-frame core FIFO with an
explicit overflow counter and stop; the public machine API only drains native PCM.

The deterministic cold-reset vector proves 1,024 known muted frames over 32,768
S-SMP/DSP phases. It is deliberately labelled source-level evidence because this
milestone may not create or run an executable. Active Theme Park PCM, long-run FIFO
behavior and whole-machine phase continuity are 17C natural-integration checks and
cannot be replaced by another recomp's results. Oracle comparison remains forbidden
until the static core is complete.

All 684 selected sources compile with warnings as errors into MSVC and GCC static
libraries. Archive membership and defined-symbol audits find exactly one project DSP
owner and no Snes9x, Mesen, bsnes, bapu, snes_spc or historical DSP owner.

