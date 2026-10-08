# V05C first contradictory-decode analysis

Status: resolved in current 05C authority.

The first finite procedure-summary pass is rejected. It reports eight overlapping physical instruction bytes around `06:875A-8791` and therefore admits zero exact or production contexts.

## Source proof of the first phantom path

1. `06:8745` is `LDA #$0000` in `E=0,M=0,X=1`; it sets Z.
2. `06:8748` is `LDX #$00` in the same context; it also sets Z.
3. `STA $0019` and `STX $001B` at `06:874A` and `06:874D` preserve Z.
4. Therefore `BEQ` at `06:8750` is necessarily taken.
5. The candidate not-taken edge to `06:8752`, and its `BRL` continuation to `06:8758` with `M=0`, are impossible under this source-defined status relation.
6. The conflicting `M=1` entry at `06:8758` has a distinct predecessor (`BNE` at `06:873F`) and is not rejected by this proof.
7. The false `M=0` stream propagates through `06:8762` to the second overlap at `06:878A`; it must disappear when the originating impossible edge is removed.

This was not repaired with an address-specific suppression rule. The offline fixed point now carries a general exact Z relation across immediate loads, status-preserving instructions, calls/returns and `PHP`/`PLP`. Regeneration removed all eight overlap rows and 47 phantom contexts. SimCity uses the same class of source-proved constant-Z reachability pruning; Rock, Jungle Strike and Gundam Wing likewise retain exact logical status provenance. Theme Park reproduced the method from its own ROM and v02 W65C816 semantics without copying their implementation or facts.

The resolved products are governed by `V05C-flow-summary.json` and the cold-regeneration gate in `tools/verify_v05.py`.
