# Theme Park Windows frontend — 1.0.0

The reusable Windows frontend originates from the Starter SNES Jungle Strike port. Internal `jungle_*` identifiers are lineage markers, not a selection of Jungle Strike's ROM or core. The production CMake target links only `theme_park_static_core` and the statically linked SDL3 gamepad dependency.

Included production features: Welcome-first startup, Launcher and Theme Park (SNES) titles, PAL pacing, keyboard/one-player gamepad input, DirectSound audio, settings, snapshots, screenshots and fail-closed error diagnostics. Tests, probes and scripted gameplay are excluded. Widescreen is not included.

See the root README.txt and VERSION.txt for current behavior and known audio limitations. SDL's license is included in `licenses/SDL-LICENSE.txt` and at the source root. No runtime emulator or third-party APU is linked.
