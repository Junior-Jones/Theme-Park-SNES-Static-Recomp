# Theme Park 04C — exact reset-rooted S-CPU contexts and intelligence

Status: CLOSED for direct-flow discovery; named dynamic/return/re-entry obligations transfer to 05C.

Starting only from the emulation reset vector `00:8000:1:1:1`, the offline analyser follows source-encoded fallthrough, direct branches, direct calls and direct jumps while carrying exact `PBR:PC:E:M:X`. A carry relation is stored outside the context key; it proves the reset path's CLC→XCE transition into native `E=0,M=1,X=1` without adding C to production identity.

The closed direct-flow slice contains 54 exact contexts at 54 CPU addresses, 57 direct edges, zero instruction-byte ownership conflicts, zero trace/oracle promotions, zero native-lowered contexts and zero production admissions. Contexts span E/M/X states 000, 010, 011 and 111. Exact instruction bytes, proof origins and successor relations are deterministic.

Two paired frontiers remain: one JSL return continuation and its reached RTL. They are not guessed or linearly followed; return/call-stack closure is owned by 05C. Asynchronous interrupt roots are likewise not seeded with invented E/M/X state; interrupt re-entry belongs to 05C.

The intelligence sidecar records carry facts, control class, literal PPU/APUIO/CPU-I/O/DMA interest, and named deferred obligations. It declares `Compiled_Into_Runtime=false`. No extra analyser fact extends the runtime context key.

The cumulative 01C→04C runner cold-regenerated the context products and preserved the exact 01C identity/census, repaired 02C semantic hash and 03C lexical digest. No executable was built or run.

