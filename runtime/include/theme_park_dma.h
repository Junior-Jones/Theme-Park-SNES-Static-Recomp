#ifndef THEME_PARK_DMA_H
#define THEME_PARK_DMA_H

#include <stdint.h>

#include "theme_park_bus.h"
#include "theme_park_scheduler.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TPDmaChannel {
    uint8_t dmap;
    uint8_t bbad;
    uint16_t a1t;
    uint8_t a1b;
    uint16_t das;
    uint8_t dasb;
    uint16_t a2a;
    uint8_t ntrl;
    uint8_t unused;
    uint8_t dma_active;
    uint8_t hdma_finished;
    uint8_t hdma_do_transfer;
} TPDmaChannel;

typedef struct TPDma {
    TPBus *bus;
    TPScheduler *scheduler;
    TPDmaChannel channel[8];
    uint64_t transfer_bytes;
    uint64_t transfer_master_clocks;
    uint64_t wram_conflicts;
    uint32_t event_count;
    uint8_t hdma_enable;
    uint8_t active_channel;
    uint8_t servicing;
    TPBusStop failure;
} TPDma;

void tp_dma_power_on(TPDma *dma, TPBus *bus, TPScheduler *scheduler);
void tp_dma_reset(TPDma *dma);
TPBusStop tp_dma_bus_read(void *opaque, uint16_t reg, uint8_t *value);
TPBusStop tp_dma_bus_write(void *opaque, uint16_t reg, uint8_t value);
TPSchedulerStop tp_dma_scheduler_event(void *opaque, TPSchedulerDmaEvent event,
                                       uint8_t mask);

#ifdef __cplusplus
}
#endif

#endif
