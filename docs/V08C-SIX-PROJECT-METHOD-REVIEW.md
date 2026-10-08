# 08C six-project method review

This review was performed after reading Starter SNES v10's complete 08C owner. The comparison projects were used only to challenge the method. No project-specific source, address, ROM fact, generated body, hash, result or acceptance claim was imported.

## Methods compared

- Rock n Roll Racing: separation of map selection, bus reads/writes, component ports and reset entry.
- Top Gear: a single machine boundary joining statically lowered CPU memory effects.
- SimCity: explicit bus ownership instead of letting generated CPU bodies emulate devices.
- Civilization: mapper classification kept separate from device semantics.
- Jungle Strike: component-specific unavailable stops and boundary-focused bus checks.
- Gundam Wing: compact map tables and static-core-only integration.

## Theme Park decisions after comparison

- Classify the entire 24-bit space, not just addresses already observed in instructions.
- Model the proved one-megabyte LoROM address lines exactly. Do not use arbitrary modulo mapping.
- Keep WRAM, WRAM port, CPU math/status and open-bus semantics in 08C. Route scheduler, DMA, PPU, APU and input registers through typed ports that stop distinctly when their later owner is absent.
- Keep map classification separate from device behavior so a classified address cannot be mistaken for an implemented future device.
- Distinguish power-on unknown WRAM/MDR from reset preservation.
- Expose access-clock class to 09C without claiming that 08C owns the master timeline.
- Omit SRAM APIs because the 01C cartridge proof says this target has zero SRAM.

Several older comparison implementations classify broad register windows or mirror ROM through convenient arithmetic. Those were treated as review warnings, not precedents. Theme Park uses exact register ranges and an exhaustive alias count.
