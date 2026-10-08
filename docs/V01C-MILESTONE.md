# Theme Park 01C — cartridge identity, target contract, and byte census

Status: CLOSED after two stable regenerations, foreign-working-directory verification, wrong-ROM rejection, purity audit, and recoverable receipt.

The exact supported image is 1,048,576 bytes with SHA-256 `c0a7e27131a7d8c9ef52a5227329e6de5846c045a9da1f3f84845e3be8e4efba`; it has no copier header, so raw and canonical offsets are identical. The computed checksum `0x4335` equals the stored checksum and complements stored `0xBCCA`.

The LoROM header at `0x007FC0` scores 12 versus the HiROM candidate's 6. It declares title `THEME PARK`, FastROM map mode `0x30`, 1 MiB size code 10, PAL Europe region code `0x02`, ROM type `0x00`, SRAM size code zero, and emulation RESET `00:8000`. Logical LoROM/FastROM selection is frozen for analysis; complete bus-window semantics remain owned by 08C. Physical PCB identity remains explicitly unknown.

Every physical byte has a conservative 01C state: 32 header bytes, 32 vector-area bytes, and 1,048,512 unresolved bytes owned by 03C. No unresolved byte is mislabeled as code or data.

Not claimed: disassembly, CPU semantics, admitted contexts, dynamic targets, lowering, native bodies, machine runtime, renderer, audio, frontend, executable, gameplay, or release.

