# 15C — Input/controller timing and target persistence transitions

Status: closed at source/static-library level. No executable, target run, frontend, host key mapping, gameplay or oracle use.

Theme Park's exact source domain contains JOY1 low/high reads at `$4218/$4219` and 22 writes to NMITIMEN using the proved values `$00`, `$01` and `$81`. The sole input owner now implements standard-pad manual serial reads at `$4016/$4017`, combined CPU/automatic latch ownership, the existing PAL scheduler's phases 0-34, `$4218-$421F` result registers and auto-joy busy timing.

Live reports, serial shifts and automatic results are distinct state. S-CPU reset preserves the externally present standard-pad reports but clears guest strobe, shift and auto-result state. Host keys, direction filtering and pause behavior are not guest hardware and remain post-18C frontend work.

The 01C cartridge proof declares zero SRAM bytes and the 08C bus has no SRAM window. Therefore 15C closes persistence by proving there is no target byte store, RTC or special persistent device to transition; it does not invent an empty SRAM API.

The complete 683-source production selection compiled with warnings as errors into MSVC and GCC static libraries. The directed verifier covers the changed owner and its deterministic manual, automatic and reset transitions. Unchanged earlier owners are carried by their governing hashes and will be globally reconciled in 17C/18C.
