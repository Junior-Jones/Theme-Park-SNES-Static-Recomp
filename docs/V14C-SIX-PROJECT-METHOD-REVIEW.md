# 14C six-project method review

Only renderer method and hardware ordering were transferred. Theme Park's reached modes, register values, addresses and feature exclusions come from its own 07C/11C evidence.

| Project | Method retained | Theme Park decision |
|---|---|---|
| Rock n' Roll Racing | One PPU-owned BG/OBJ/compositor path, causal selectors, raster publication, and separate work/published frames | Use its offset-per-tile and publication process as architectural guidance only; do not copy its broad modes, target constants or frame evidence. |
| Top Gear | Direct pixel ownership and raster-time state rather than end-frame reconstruction | Keep Theme Park's scheduler hook authoritative; no host renderer or final-state snapshot shortcut. |
| SimCity | Compact machine-owned framebuffer and host-read boundary | Publish BGR555 pixels plus knownness through a read-only core API; frontend remains absent. |
| Civilization | Source-domain and static-purity accounting | Prove exact mode/layer/register domains before implementing optional features; no oracle-derived feature promotion. |
| Jungle Strike | Explicit scanline/raster diagnostics, causal black selectors and completed-frame ownership | Forced blank and brightness zero resolve black before OAM/VRAM/CGRAM dependencies; later unknown selected inputs stop. |
| Gundam Wing | Source-reached mode inventory, focused functional owner, 32-sprite/34-sliver limits, immutable publication | Theme Park adopts the SNES limits and one-current-owner boundary, but not Gundam's Mode 0/1 facts, fixtures or hashes. |

Theme Park's own source domain is Modes 2 and 3, BG1/BG2, Mode-2 BG3 offset tables, mosaic, size-selector-zero OBJ, main-screen masks `$01/$03/$13`, no subscreen writer, no window writer, no `$2131` color-math writer, no direct color, and zero SETINI. `$211B/$211C` are multiply-register use, not evidence for a Mode 7 display path.
