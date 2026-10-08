# Current runtime status

Updated: 2026-10-06

This page is the authoritative summary of the current integrated build. Earlier milestone reports describe the state that existed when each milestone closed; statements such as “no frontend”, “black output” or “silent output” in those historical records are not the current result.

## Confirmed current result

- The Theme Park static core is selected and linked. No Rock n' Roll Racing or Jungle Strike game core is selected.
- The Windows frontend is the Starter SNES v11 Jungle Strike-derived port, connected through Theme Park's opaque core adapter.
- The exact Europe PAL ROM is loaded from a user-selected external path. The packaged test copy contains no ROM and has no saved ROM path.
- The machine runs at Theme Park's natural PAL timing: 21,281,370 master clocks per second, 312 lines and `322445/6448` frames per second (about 50.006979 FPS).
- Graphics work. The deterministic route reaches the first park at frame 2200 with active Mode 2 rendering and no PPU, bus, scheduler, APU or S-DSP stop. The produced park-entrance frame was visually compared with online SNES gameplay imagery: the entrance building, three tents, road, river, grass and bottom date/status layout agree. No graphics fault is currently recorded.
- Audio works. Title, menu and nickname screens do not provide continuous music on the natural route, but their sound effects play. The first playable park produces sustained in-game music. Headed user testing confirmed audible output.
- Compile-time representation compaction has been selected after an exact compiler-token comparison over all 670 shards and matching gameplay framebuffer/PCM evidence. Original generated source is preserved in build/v18c-precompaction-recovery/scpu. The current Windows launcher and headless probe rebuilt successfully; full 18C certification remains pending. See V18C-REPRESENTATION-PROGRESS.md.

## Repeatable gameplay route

The launcher accepts `--gameplay-test` to replay the already-discovered route. The equivalent headless inputs hold each button for three frames:

| Frame | Button | Purpose |
|---:|---|---|
| 300 | Start | Leave the title screen |
| 380 | A | Continue |
| 460, 520, 580 | Y | Enter `AAA` |
| 660 | X | Submit nickname |
| 780 | Y | Select `ENTER CODE? NO` |
| 1240 | Y | Select Easy |
| 1440 | Y | Continue default setup |
| 1840 | X | Buy United Kingdom land |

At frame 2200 the route has reached the park and produced 1,410,025 stereo PCM frames, 526,777 nonzero samples and a peak magnitude of 27,875.

## Evidence

- Core frame: `build/frontend-user-test/headless-evidence/gameplay-route-discovery-08/frame.bmp`
- Core audio: `build/frontend-user-test/headless-evidence/gameplay-route-discovery-08/audio.wav`
- Whole-machine diagnostics: `build/frontend-user-test/headless-evidence/gameplay-route-discovery-08/diag.txt`
- Integration receipt: `docs/FRONTEND-user-test-connection-receipt.json`
- Online visual reference: <https://gamesdb.launchbox-app.com/games/details/6013-theme-park>

The online images are visual corroboration only. They are not lowering authority and do not replace Theme Park's own source-derived core evidence.
