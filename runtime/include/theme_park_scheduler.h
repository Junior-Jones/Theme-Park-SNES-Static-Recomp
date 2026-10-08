#ifndef THEME_PARK_SCHEDULER_H
#define THEME_PARK_SCHEDULER_H

#include <stdint.h>

#include "theme_park_bus.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TP_PAL_MASTER_HZ_NUMERATOR UINT64_C(21281370)
#define TP_PAL_MASTER_HZ_DENOMINATOR UINT64_C(1)
#define TP_PAL_NORMAL_LINE_CLOCKS 1364u
#define TP_PAL_LONG_LINE_CLOCKS 1368u
#define TP_PAL_BASE_FRAME_LINES 312u
#define TP_SCHEDULER_DOMAIN_COUNT 3u

typedef enum TPSchedulerStop {
    TP_SCHEDULER_OK = 0,
    TP_SCHEDULER_STOP_ARGUMENT,
    TP_SCHEDULER_STOP_ODD_MASTER_CLOCK,
    TP_SCHEDULER_STOP_DOMAIN_PROFILE,
    TP_SCHEDULER_STOP_DOMAIN_CALLBACK,
    TP_SCHEDULER_STOP_DMA_UNAVAILABLE,
    TP_SCHEDULER_STOP_INPUT_UNAVAILABLE,
    TP_SCHEDULER_STOP_STP_REQUIRES_RESET
} TPSchedulerStop;

typedef enum TPSchedulerDomainId {
    TP_DOMAIN_SSMP = 0,
    TP_DOMAIN_SDSP = 1,
    TP_DOMAIN_CARTRIDGE = 2
} TPSchedulerDomainId;

typedef enum TPSchedulerDmaEvent {
    TP_DMA_EVENT_MANUAL = 1,
    TP_DMA_EVENT_HDMA_INIT = 2,
    TP_DMA_EVENT_HDMA_LINE = 3
} TPSchedulerDmaEvent;

typedef TPSchedulerStop (*TPSchedulerAdvanceDomain)(void *opaque, uint64_t target_ticks);
typedef TPSchedulerStop (*TPSchedulerDmaHook)(void *opaque, TPSchedulerDmaEvent event,
                                               uint8_t mask);
typedef TPSchedulerStop (*TPSchedulerAutoJoyHook)(void *opaque, uint8_t phase,
                                                  uint8_t enabled);
typedef TPSchedulerStop (*TPSchedulerRasterHook)(void *opaque, uint64_t master_clock,
                                                 uint16_t scanline, uint16_t hclock);

typedef struct TPSchedulerDomain {
    uint64_t numerator;
    uint64_t denominator;
    uint64_t target_ticks;
    uint64_t remainder;
    void *opaque;
    TPSchedulerAdvanceDomain advance;
    uint8_t configured;
} TPSchedulerDomain;

typedef struct TPSchedulerHooks {
    void *dma_opaque;
    TPSchedulerDmaHook dma_event;
    void *input_opaque;
    TPSchedulerAutoJoyHook autojoy_phase;
    void *raster_opaque;
    TPSchedulerRasterHook raster_edge;
} TPSchedulerHooks;

typedef struct TPSchedulerFailure {
    TPSchedulerStop reason;
    uint64_t master_clock;
    uint16_t scanline;
    uint16_t hclock;
    uint32_t detail;
} TPSchedulerFailure;

typedef struct TPScheduler {
    TPSchedulerHooks hooks;
    TPSchedulerDomain domains[TP_SCHEDULER_DOMAIN_COUNT];
    TPSchedulerFailure failure;
    uint64_t master_clock;
    uint64_t frame_count;
    uint64_t cpu_active_clocks;
    uint64_t cpu_stall_clocks_total;
    uint64_t dma_clocks_total;
    uint64_t event_count;
    uint64_t event_digest;
    uint64_t autojoy_start_clock;
    uint64_t autojoy_next_clock;
    uint32_t cpu_stall_clocks;
    uint32_t dma_refresh_stall_clocks;
    uint32_t cpu_cycle_clocks;
    uint16_t scanline;
    uint16_t hclock;
    uint16_t line_clocks;
    uint16_t frame_lines;
    uint16_t vblank_start_scanline;
    uint16_t dram_refresh_hclock;
    uint16_t hdma_init_hclock;
    uint16_t h_timer;
    uint16_t v_timer;
    uint16_t h_counter;
    uint16_t v_counter;
    uint8_t field;
    uint8_t overscan;
    uint8_t interlace;
    uint8_t nmitimen;
    uint8_t nmi_flag;
    uint8_t nmi_pending;
    uint8_t irq_flag;
    uint8_t irq_line;
    uint8_t irq_level;
    uint8_t irq_need_ticks;
    uint8_t autojoy_active;
    uint8_t autojoy_disabled;
    uint8_t autojoy_phase_index;
    uint8_t dma_pending_mask;
    uint8_t hdma_enable_mask;
    uint8_t hdma_init_pending;
    uint8_t hdma_line_pending;
    uint8_t dma_start_delay;
    uint8_t cpu_waiting;
    uint8_t cpu_stopped;
    uint8_t in_dma_advance;
    uint8_t in_cpu_advance;
} TPScheduler;

const char *tp_scheduler_stop_name(TPSchedulerStop stop);
void tp_scheduler_power_on(TPScheduler *scheduler, TPSchedulerHooks hooks);
void tp_scheduler_cpu_reset(TPScheduler *scheduler);
TPSchedulerStop tp_scheduler_configure_domain(TPScheduler *scheduler,
                                               TPSchedulerDomainId id,
                                               uint64_t numerator,
                                               uint64_t denominator,
                                               uint64_t initial_remainder,
                                               void *opaque,
                                               TPSchedulerAdvanceDomain advance);
TPSchedulerStop tp_scheduler_sync_domains(TPScheduler *scheduler);
TPSchedulerStop tp_scheduler_advance_wall(TPScheduler *scheduler, uint32_t master_clocks);
TPSchedulerStop tp_scheduler_advance_cpu(TPScheduler *scheduler, uint32_t active_master_clocks);
TPSchedulerStop tp_scheduler_advance_cpu_cycle(TPScheduler *scheduler,
                                                uint32_t active_master_clocks);
TPSchedulerStop tp_scheduler_advance_dma(TPScheduler *scheduler, uint32_t active_master_clocks);
TPSchedulerStop tp_scheduler_cpu_cycle_boundary(TPScheduler *scheduler);
void tp_scheduler_set_display(TPScheduler *scheduler, int overscan, int interlace);
void tp_scheduler_write_nmitimen(TPScheduler *scheduler, uint8_t value);
void tp_scheduler_set_h_timer(TPScheduler *scheduler, uint16_t value);
void tp_scheduler_set_v_timer(TPScheduler *scheduler, uint16_t value);
void tp_scheduler_request_dma(TPScheduler *scheduler, uint8_t mask);
void tp_scheduler_set_hdma_enable(TPScheduler *scheduler, uint8_t mask);
uint8_t tp_scheduler_read_rdnmi(TPScheduler *scheduler);
uint8_t tp_scheduler_read_timeup(TPScheduler *scheduler);
uint8_t tp_scheduler_read_hvbjoy(TPScheduler *scheduler);
int tp_scheduler_take_nmi(TPScheduler *scheduler);
int tp_scheduler_irq_asserted(const TPScheduler *scheduler);
void tp_scheduler_enter_wai(TPScheduler *scheduler);
void tp_scheduler_enter_stp(TPScheduler *scheduler);
TPSchedulerStop tp_scheduler_halted_quantum(TPScheduler *scheduler);
TPBusStop tp_scheduler_bus_read(void *opaque, uint16_t reg, uint8_t *value);
TPBusStop tp_scheduler_bus_write(void *opaque, uint16_t reg, uint8_t value);

#ifdef __cplusplus
}
#endif

#endif
