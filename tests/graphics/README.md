# ROM-free graphics regressions

These four standalone C11 programs exercise the actual production renderer.
Each includes `runtime/src/theme_park_renderer.c` so its internal compositor,
offset lookup and object evaluation are tested without a game ROM, generated
CPU execution, emulator, window, audio device or filesystem access. The test
programs create synthetic PPU memories and report failures with a nonzero exit.

| Source | Independent expected behavior | Cases |
|---|---|---:|
| `test_priority.c` | Mode 2/3 back-to-front order: BG2-low, OBJ0, BG1-low, OBJ1, BG2-high, OBJ2, BG1-high, OBJ3; checks the composed color of three overlapping layers | 32 |
| `test_mode2_offsets.c` | First partial column keeps ordinary scroll; later columns use preceding BG3 entries, retain fine horizontal scroll, respect each layer's enable bits and independently sized tilemaps | 245,764 |
| `test_bg_sampling.c` | Visible row 1 samples physical BG row 1; mosaic groups repeat the first visible row of each block before adding scroll; checks both layer enables, sizes 1–16 and scroll wrap, plus Mode 3's first/last visible rows | 43,016 |
| `test_obj_cache.c` | Explicit OBSEL byte-address tables, name-select offsets and VRAM wrap; 32-object/34-sliver limits; the second raster pixel reuses a completed line cache even after overflow | 394 |

The Mode 2 inputs populate distinct values in named tilemap screens; they do
not use the renderer's lookup to construct expected results. The raster tests
paint expected output-space blocks from independently colored tile rows.
The OBJ cache test makes OAM and VRAM unknown after the first pixel: a second
fetch fails, while correct cache reuse succeeds. These are hardware regressions,
not tests that simply compare two copies of the implementation.

Build each source with `runtime/include` and `static-core/internal` on the
include path. Do not link it with the production renderer or core library again:
the renderer is already included in its translation unit. For example, from
the source root:

```sh
cc -std=c11 -O2 -Wall -Wextra -Wpedantic -Werror \
  -Iruntime/include -Istatic-core/internal \
  tests/graphics/test_priority.c -o test_priority
./test_priority
```

The same sources build as C11 under MSVC with `/W4 /WX` and the same two include
directories. `TP_GRAPHICS_RENDERER_SOURCE` can be overridden at compile time
for negative controls; its default always selects this source tree's renderer.

All four programs pass strict GCC and MSVC compilation. Six isolated negative
controls, each reverting one repaired behavior in a separate renderer copy,
all compile successfully and are rejected by the relevant test: priority,
Mode 2 offsets, visible BG origin, mosaic origin, OBJ addressing and overflow
cache completion. Local negative-control files and compiler outputs remain
outside this source tree.

These tests qualify the named hardware behaviors. They do not claim complete
gameplay, frontend presentation, arbitrary PPU modes or all SNES hardware.
