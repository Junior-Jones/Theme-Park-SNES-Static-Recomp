# ADR-0001: static authority and sequencing

Status: accepted for Milestone Zero.

Theme Park ROM bytes, primary hardware specifications, and Theme Park-owned finite proofs are the only production authorities. Starter SNES v10 owns the 01C-18C process. Rock may answer workflow-review questions only after each version completes. Emulator/oracle work is disabled until the static core is complete and then may only confirm missing or broken behavior.

Production has no runtime CPU/SPC700 decoder, learned target, captured future state, silent fallback, or frontend before 18C. Unknowns fail closed. Builds may create objects and static libraries but never an executable.

