# V10C six-project DMA/HDMA method review

This review uses the six SNES static recomps as comparison evidence only. No game-specific implementation, address, value, ROM fact, or success claim is Theme Park authority.

| Project | Method retained | Mistake not inherited |
|---|---|---|
| Rock n Roll Racing | Separate a generic eight-channel controller from deterministic source-configuration receipts; preserve transfer modes, bus restrictions, HDMA tables and scheduler rendezvous. | Its target profiles and generated tables are not copied. |
| Top Gear | Keep CPU/DMA writes behind one PPU-facing bus authority and preserve mid-frame state effects for the later raster owner. | A combined game-specific PPU/DMA module is not treated as Theme Park proof. |
| SimCity | Use one master-clock timeline and make DMA a timed bus operation rather than a memcpy. | Old milestone numbering and target helper patches are not reused. |
| Civilization | Test arbitration, OAM-facing transfers and HDMA channel behavior as separate semantic families. | Oracle contracts are outside Theme Park's current boundary and were not used. |
| Jungle Strike | Reconcile exact contexts before value proof, expand wide stores into byte-register events, and keep controller coverage distinct from source reachability. | Conservative `$43xx` candidates are not promoted to reached configurations. |
| Gundam Wing | Retain fail-closed receiver binding, WRAM-port conflicts, power/reset distinctions and later reachability reconciliation. | Its target configuration fixtures and acceptance labels are not copied. |

Theme Park application: the generic controller is implemented independently in `runtime/src/theme_park_dma.c`. The source join consumes the existing V07 exact effective-address/width sidecar. It currently names 548 exact register-byte events and keeps the conservative intersections unresolved. Trigger values and payload lifetimes must be proved before 10C can close; the absence of a PPU owner until 11C is also explicit in each receipt.
