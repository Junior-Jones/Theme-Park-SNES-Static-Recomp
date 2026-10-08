# Theme Park 03C — whole-ROM lexical universe and conservative classification

Status: CLOSED.

The exact Theme Park ROM was scanned at every one of its 1,048,576 physical offsets under the five legal E/M/X decode states, producing 5,242,880 deterministic lexical rows. The row digest is `e339825d1e7e3bc6aecf6104e9101fef92207ac0e375133e169bde85ff09d50e`. Of those rows, 5,242,705 have a complete fetch within the owning LoROM bank and 175 are explicit bank-tail rejections.

The 01C byte census is preserved: all 1,048,576 physical bytes have exactly one current classification range. Header and vector areas retain 01C ownership. Other bytes are lexical-start candidates or explicit invalid bank-tail starts; a legal decode is never called code.

Hardware vector origins remain separate even when their target addresses duplicate. The output contains 21 origin/mode rows, of which 15 are proved vector context candidates for 04C. Reserved slots and targets outside the canonical LoROM fetch window are explicitly rejected. 03C admits zero exact contexts and zero production contexts.

The subsystem-interest inventory records only literal lexical indicators for PPU, APUIO, CPU I/O, DMA/HDMA and exact-bank WRAM writes. DBR-dependent operands remain marked unproved. Region signals for padding, printable text and entropy are heuristic only and cannot promote bytes to code or data.

The cumulative runner first revalidated 01C and repaired 02C, then regenerated all six 03C products byte-for-byte in a fresh temporary output directory. No emulator, trace, Mesen database, Rock target fact, or frontend input was used. No executable was created or run.

Not claimed: exact S-CPU reachability, direct-flow graph, dynamic targets, returns, interrupt re-entry, executable-RAM epochs, native lowerers, production contexts, bus/runtime hardware, renderer, audio, frontend, executable or gameplay.

