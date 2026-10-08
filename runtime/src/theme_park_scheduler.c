#include "theme_park_scheduler.h"

#include <string.h>

#define TP_DRAM_REFRESH_CLOCKS 40u
#define TP_HDMA_LINE_HCLOCK 1104u

static TPSchedulerStop tp_sched_fail(TPScheduler *s, TPSchedulerStop reason,
                                     uint32_t detail) {
    if (s != NULL) {
        s->failure.reason = reason;
        s->failure.master_clock = s->master_clock;
        s->failure.scanline = s->scanline;
        s->failure.hclock = s->hclock;
        s->failure.detail = detail;
    }
    return reason;
}

const char *tp_scheduler_stop_name(TPSchedulerStop stop) {
    static const char *const names[] = {
        "OK", "ARGUMENT", "ODD_MASTER_CLOCK", "DOMAIN_PROFILE",
        "DOMAIN_CALLBACK", "DMA_UNAVAILABLE", "INPUT_UNAVAILABLE",
        "STP_REQUIRES_RESET"
    };
    return (unsigned)stop < sizeof(names) / sizeof(names[0]) ? names[stop] : "INVALID";
}

static void tp_event(TPScheduler *s, uint32_t code, uint32_t detail) {
    uint64_t value = ((uint64_t)code << 56u) ^ ((uint64_t)s->scanline << 40u) ^
                     ((uint64_t)s->hclock << 24u) ^ (uint64_t)detail ^ s->master_clock;
    s->event_digest ^= value + UINT64_C(0x9E3779B97F4A7C15) +
                       (s->event_digest << 6u) + (s->event_digest >> 2u);
    s->event_count++;
}

static uint16_t tp_vblank_start(const TPScheduler *s) {
    return s->overscan != 0u ? 240u : 225u;
}

static uint16_t tp_frame_lines(const TPScheduler *s) {
    return (uint16_t)(TP_PAL_BASE_FRAME_LINES +
                      ((s->interlace != 0u && s->field != 0u) ? 1u : 0u));
}

static uint16_t tp_line_clocks(const TPScheduler *s) {
    return (s->interlace != 0u && s->field != 0u && s->scanline == 311u)
        ? TP_PAL_LONG_LINE_CLOCKS : TP_PAL_NORMAL_LINE_CLOCKS;
}

static int tp_hblank(const TPScheduler *s) {
    return !(s->hclock >= 4u && s->hclock <= 1096u);
}

static int tp_vblank(const TPScheduler *s) {
    return s->scanline >= s->vblank_start_scanline;
}

static void tp_irq_update_level(TPScheduler *s) {
    const int h_enabled = (s->nmitimen & 0x10u) != 0u;
    const int v_enabled = (s->nmitimen & 0x20u) != 0u;
    uint8_t level;
    if (!h_enabled && !v_enabled) {
        s->irq_level = 0u;
        return;
    }
    level = (uint8_t)((!h_enabled || s->h_counter == s->h_timer) &&
                      (!v_enabled || s->v_counter == s->v_timer));
    if (s->irq_level == 0u && level != 0u)
        s->irq_need_ticks = (uint8_t)(h_enabled && s->hclock == 6u ? 3u : 2u);
    s->irq_level = level;
}

static void tp_irq_tick(TPScheduler *s) {
    if (s->irq_need_ticks != 0u) {
        s->irq_need_ticks--;
        if (s->irq_need_ticks == 1u) {
            s->irq_flag = 1u;
            tp_event(s, 7u, 1u);
        } else if (s->irq_need_ticks == 0u) {
            s->irq_line = s->irq_flag;
            tp_event(s, 8u, s->irq_line);
        }
    }
    if (s->hclock > 10u) {
        s->h_counter = (uint16_t)((s->h_counter + 1u) & 0x01FFu);
    } else if (s->hclock == 10u) {
        s->h_counter = 0u;
    } else if (s->hclock == 6u) {
        s->h_counter = 0u;
        if (s->scanline > 0u) s->v_counter = (uint16_t)((s->v_counter + 1u) & 0x01FFu);
    } else if (s->hclock == 2u) {
        s->h_counter = (uint16_t)((s->h_counter + 1u) & 0x01FFu);
        if (s->scanline == s->vblank_start_scanline) {
            s->nmi_flag = 1u;
            if ((s->nmitimen & 0x80u) != 0u) s->nmi_pending = 1u;
            tp_event(s, 5u, s->nmi_pending);
        } else if (s->scanline == 0u) {
            s->nmi_flag = 0u;
            s->v_counter = 0u;
            tp_event(s, 6u, 0u);
        }
    }
    tp_irq_update_level(s);
}

static void tp_schedule_autojoy(TPScheduler *s) {
    uint64_t earliest = s->master_clock + 130u;
    uint64_t aligned = earliest + ((earliest & 0xFFu) != 0u
                                   ? 256u - (earliest & 0xFFu) : 0u);
    s->autojoy_start_clock = aligned - 128u;
    s->autojoy_next_clock = s->autojoy_start_clock;
    s->autojoy_phase_index = 0u;
    s->autojoy_disabled = 0u;
    s->autojoy_active = 0u;
    tp_event(s, 9u, (uint32_t)s->autojoy_start_clock);
}

static TPSchedulerStop tp_process_autojoy(TPScheduler *s) {
    while (s->autojoy_disabled == 0u && s->master_clock >= s->autojoy_next_clock) {
        uint8_t phase = s->autojoy_phase_index;
        const int enabled = (s->nmitimen & 1u) != 0u;
        if (phase == 0u) {
            if (enabled && s->hooks.autojoy_phase == NULL)
                return tp_sched_fail(s, TP_SCHEDULER_STOP_INPUT_UNAVAILABLE, phase);
        } else if (phase == 1u) {
            if (!enabled) {
                s->autojoy_disabled = 1u;
                s->autojoy_active = 0u;
            } else {
                s->autojoy_active = 1u;
            }
        } else if (phase >= 34u) {
            s->autojoy_active = 0u;
            s->autojoy_disabled = 1u;
        } else if (!enabled) {
            s->autojoy_active = 0u;
            s->autojoy_disabled = 1u;
        }
        if (s->hooks.autojoy_phase != NULL) {
            TPSchedulerStop result = s->hooks.autojoy_phase(s->hooks.input_opaque, phase,
                                                             (uint8_t)enabled);
            if (result != TP_SCHEDULER_OK) return tp_sched_fail(s, result, phase);
        }
        tp_event(s, 10u, phase);
        if (s->autojoy_disabled != 0u) break;
        s->autojoy_phase_index++;
        s->autojoy_next_clock += 128u;
    }
    return TP_SCHEDULER_OK;
}

static TPSchedulerStop tp_advance_domain_delta(TPScheduler *s, TPSchedulerDomain *domain,
                                                uint32_t master_delta) {
    uint64_t product;
    uint64_t old_target;
    if (domain->configured == 0u) return TP_SCHEDULER_OK;
    product = domain->remainder + (uint64_t)master_delta * domain->numerator;
    old_target = domain->target_ticks;
    domain->target_ticks += product / domain->denominator;
    domain->remainder = product % domain->denominator;
    if (domain->advance != NULL && domain->target_ticks != old_target) {
        TPSchedulerStop result = domain->advance(domain->opaque, domain->target_ticks);
        if (result != TP_SCHEDULER_OK)
            return tp_sched_fail(s, TP_SCHEDULER_STOP_DOMAIN_CALLBACK, (uint32_t)result);
    }
    return TP_SCHEDULER_OK;
}

TPSchedulerStop tp_scheduler_sync_domains(TPScheduler *s) {
    unsigned id;
    if (s == NULL) return TP_SCHEDULER_STOP_ARGUMENT;
    for (id = 0u; id < TP_SCHEDULER_DOMAIN_COUNT; ++id) {
        TPSchedulerDomain *domain = &s->domains[id];
        if (domain->configured != 0u && domain->advance != NULL) {
            TPSchedulerStop result = domain->advance(domain->opaque, domain->target_ticks);
            if (result != TP_SCHEDULER_OK)
                return tp_sched_fail(s, TP_SCHEDULER_STOP_DOMAIN_CALLBACK, (uint32_t)result);
        }
    }
    return TP_SCHEDULER_OK;
}

static void tp_finish_line(TPScheduler *s) {
    s->scanline++;
    s->hclock = 0u;
    if (s->scanline >= s->frame_lines) {
        s->scanline = 0u;
        s->field ^= 1u;
        s->frame_count++;
        s->frame_lines = tp_frame_lines(s);
        tp_event(s, 4u, s->field);
    }
    s->vblank_start_scanline = tp_vblank_start(s);
    s->line_clocks = tp_line_clocks(s);
    s->dram_refresh_hclock = (uint16_t)(538u - (s->master_clock & 7u));
    s->hdma_init_hclock = (uint16_t)(12u + (s->master_clock & 7u));
    if (s->scanline == s->vblank_start_scanline) tp_schedule_autojoy(s);
    tp_event(s, 3u, s->scanline);
}

static TPSchedulerStop tp_tick2(TPScheduler *s) {
    unsigned id;
    TPSchedulerStop result;
    s->master_clock += 2u;
    s->hclock = (uint16_t)(s->hclock + 2u);

    if (s->scanline == 0u && s->hclock == s->hdma_init_hclock) {
        s->hdma_init_pending = 1u;
        s->dma_start_delay = 1u;
        tp_event(s, 11u, s->hdma_enable_mask);
    }
    if (s->hclock == s->dram_refresh_hclock) {
        if (s->in_dma_advance != 0u) s->dma_refresh_stall_clocks += TP_DRAM_REFRESH_CLOCKS;
        else if (s->in_cpu_advance != 0u && s->cpu_stall_clocks == 0u)
            s->cpu_stall_clocks = TP_DRAM_REFRESH_CLOCKS;
        tp_event(s, 1u, TP_DRAM_REFRESH_CLOCKS);
    }
    if (s->hclock == TP_HDMA_LINE_HCLOCK && s->scanline < s->vblank_start_scanline &&
        s->hdma_enable_mask != 0u) {
        s->hdma_line_pending = 1u;
        s->dma_start_delay = 1u;
        tp_event(s, 12u, s->hdma_enable_mask);
    }
    if ((s->hclock & 3u) == 2u) tp_irq_tick(s);
    result = tp_process_autojoy(s);
    if (result != TP_SCHEDULER_OK) return result;
    for (id = 0u; id < TP_SCHEDULER_DOMAIN_COUNT; ++id) {
        result = tp_advance_domain_delta(s, &s->domains[id], 2u);
        if (result != TP_SCHEDULER_OK) return result;
    }
    if ((s->hclock & 3u) == 0u && s->hooks.raster_edge != NULL) {
        result = s->hooks.raster_edge(s->hooks.raster_opaque, s->master_clock,
                                      s->scanline, s->hclock);
        if (result != TP_SCHEDULER_OK) return tp_sched_fail(s, result, 0u);
    }
    if (s->hclock >= s->line_clocks) tp_finish_line(s);
    return TP_SCHEDULER_OK;
}

void tp_scheduler_power_on(TPScheduler *s, TPSchedulerHooks hooks) {
    if (s == NULL) return;
    memset(s, 0, sizeof(*s));
    s->hooks = hooks;
    s->line_clocks = TP_PAL_NORMAL_LINE_CLOCKS;
    s->frame_lines = TP_PAL_BASE_FRAME_LINES;
    s->vblank_start_scanline = 225u;
    s->dram_refresh_hclock = 538u;
    s->hdma_init_hclock = 12u;
    s->h_timer = 0x01FFu;
    s->v_timer = 0x01FFu;
    s->autojoy_disabled = 1u;
    s->event_digest = UINT64_C(0xCBF29CE484222325);
    tp_event(s, 3u, 0u);
}

void tp_scheduler_cpu_reset(TPScheduler *s) {
    if (s == NULL) return;
    /* S-CPU RESET does not rewind raster time or independent-domain phase. */
    s->nmitimen = 0u;
    s->nmi_pending = 0u;
    s->irq_flag = 0u;
    s->irq_line = 0u;
    s->irq_level = 0u;
    s->irq_need_ticks = 0u;
    s->dma_pending_mask = 0u;
    s->hdma_init_pending = 0u;
    s->hdma_line_pending = 0u;
    s->dma_start_delay = 0u;
    s->autojoy_start_clock = 0u;
    s->autojoy_next_clock = 0u;
    s->autojoy_phase_index = 0u;
    s->autojoy_active = 0u;
    s->autojoy_disabled = 1u;
    s->cpu_waiting = 0u;
    s->cpu_stopped = 0u;
    memset(&s->failure, 0, sizeof(s->failure));
    tp_event(s, 13u, 0u);
}

TPSchedulerStop tp_scheduler_configure_domain(TPScheduler *s, TPSchedulerDomainId id,
                                               uint64_t numerator, uint64_t denominator,
                                               uint64_t initial_remainder, void *opaque,
                                               TPSchedulerAdvanceDomain advance) {
    TPSchedulerDomain *domain;
    if (s == NULL || (unsigned)id >= TP_SCHEDULER_DOMAIN_COUNT)
        return TP_SCHEDULER_STOP_ARGUMENT;
    if (numerator == 0u || denominator == 0u || initial_remainder >= denominator)
        return tp_sched_fail(s, TP_SCHEDULER_STOP_DOMAIN_PROFILE, (uint32_t)id);
    domain = &s->domains[id];
    memset(domain, 0, sizeof(*domain));
    domain->numerator = numerator;
    domain->denominator = denominator;
    domain->remainder = initial_remainder;
    domain->opaque = opaque;
    domain->advance = advance;
    domain->configured = 1u;
    return TP_SCHEDULER_OK;
}

TPSchedulerStop tp_scheduler_advance_wall(TPScheduler *s, uint32_t clocks) {
    if (s == NULL) return TP_SCHEDULER_STOP_ARGUMENT;
    if ((clocks & 1u) != 0u) return tp_sched_fail(s, TP_SCHEDULER_STOP_ODD_MASTER_CLOCK, clocks);
    while (clocks != 0u) {
        TPSchedulerStop result = tp_tick2(s);
        if (result != TP_SCHEDULER_OK) return result;
        clocks -= 2u;
    }
    return TP_SCHEDULER_OK;
}

static TPSchedulerStop tp_run_cpu_stall(TPScheduler *s) {
    while (s->cpu_stall_clocks != 0u) {
        uint32_t before = s->cpu_stall_clocks;
        TPSchedulerStop result = tp_tick2(s);
        if (result != TP_SCHEDULER_OK) return result;
        s->cpu_stall_clocks = before > 2u ? before - 2u : 0u;
        s->cpu_stall_clocks_total += 2u;
    }
    tp_event(s, 2u, 0u);
    return TP_SCHEDULER_OK;
}

TPSchedulerStop tp_scheduler_advance_cpu(TPScheduler *s, uint32_t clocks) {
    if (s == NULL) return TP_SCHEDULER_STOP_ARGUMENT;
    if ((clocks & 1u) != 0u) return tp_sched_fail(s, TP_SCHEDULER_STOP_ODD_MASTER_CLOCK, clocks);
    s->in_cpu_advance = 1u;
    while (clocks != 0u) {
        TPSchedulerStop result;
        if (s->cpu_stall_clocks != 0u) {
            result = tp_run_cpu_stall(s);
            if (result != TP_SCHEDULER_OK) { s->in_cpu_advance = 0u; return result; }
        }
        result = tp_tick2(s);
        if (result != TP_SCHEDULER_OK) { s->in_cpu_advance = 0u; return result; }
        s->cpu_active_clocks += 2u;
        clocks -= 2u;
        if (s->cpu_stall_clocks != 0u) {
            result = tp_run_cpu_stall(s);
            if (result != TP_SCHEDULER_OK) { s->in_cpu_advance = 0u; return result; }
        }
    }
    s->in_cpu_advance = 0u;
    return TP_SCHEDULER_OK;
}

TPSchedulerStop tp_scheduler_advance_cpu_cycle(TPScheduler *s, uint32_t clocks) {
    if (s != NULL) s->cpu_cycle_clocks = clocks;
    TPSchedulerStop result = tp_scheduler_cpu_cycle_boundary(s);
    if (result != TP_SCHEDULER_OK) return result;
    return tp_scheduler_advance_cpu(s, clocks);
}

TPSchedulerStop tp_scheduler_advance_dma(TPScheduler *s, uint32_t clocks) {
    if (s == NULL) return TP_SCHEDULER_STOP_ARGUMENT;
    if ((clocks & 1u) != 0u) return tp_sched_fail(s, TP_SCHEDULER_STOP_ODD_MASTER_CLOCK, clocks);
    s->in_dma_advance++;
    while (clocks != 0u || s->dma_refresh_stall_clocks != 0u) {
        uint32_t refresh_before = s->dma_refresh_stall_clocks;
        TPSchedulerStop result = tp_tick2(s);
        if (result != TP_SCHEDULER_OK) { s->in_dma_advance--; return result; }
        if (refresh_before != 0u) {
            s->dma_refresh_stall_clocks = refresh_before > 2u ? refresh_before - 2u : 0u;
            s->cpu_stall_clocks_total += 2u;
        } else if (clocks != 0u) {
            clocks -= 2u;
            s->dma_clocks_total += 2u;
        }
    }
    s->in_dma_advance--;
    return TP_SCHEDULER_OK;
}

TPSchedulerStop tp_scheduler_cpu_cycle_boundary(TPScheduler *s) {
    TPSchedulerDmaEvent event;
    uint8_t mask;
    TPSchedulerStop result;
    if (s == NULL) return TP_SCHEDULER_STOP_ARGUMENT;
    if (s->dma_start_delay != 0u) {
        s->dma_start_delay--;
        return TP_SCHEDULER_OK;
    }
    if (s->hdma_line_pending != 0u) {
        event = TP_DMA_EVENT_HDMA_LINE;
        mask = s->hdma_enable_mask;
        s->hdma_line_pending = 0u;
    } else if (s->hdma_init_pending != 0u) {
        event = TP_DMA_EVENT_HDMA_INIT;
        mask = s->hdma_enable_mask;
        s->hdma_init_pending = 0u;
        if (mask == 0u) return TP_SCHEDULER_OK;
    } else if (s->dma_pending_mask != 0u) {
        event = TP_DMA_EVENT_MANUAL;
        mask = s->dma_pending_mask;
        s->dma_pending_mask = 0u;
    } else {
        return TP_SCHEDULER_OK;
    }
    if (s->hooks.dma_event == NULL)
        return tp_sched_fail(s, TP_SCHEDULER_STOP_DMA_UNAVAILABLE, mask);
    result = s->hooks.dma_event(s->hooks.dma_opaque, event, mask);
    if (result != TP_SCHEDULER_OK) return tp_sched_fail(s, result, mask);
    tp_event(s, 14u, ((uint32_t)event << 8u) | mask);
    return TP_SCHEDULER_OK;
}

void tp_scheduler_set_display(TPScheduler *s, int overscan, int interlace) {
    if (s == NULL) return;
    s->overscan = (uint8_t)(overscan != 0);
    s->interlace = (uint8_t)(interlace != 0);
    s->vblank_start_scanline = tp_vblank_start(s);
    s->frame_lines = tp_frame_lines(s);
    s->line_clocks = tp_line_clocks(s);
}

void tp_scheduler_write_nmitimen(TPScheduler *s, uint8_t value) {
    uint8_t old;
    if (s == NULL) return;
    old = s->nmitimen;
    s->nmitimen = value;
    if (s->nmi_flag != 0u && (value & 0x80u) != 0u && (old & 0x80u) == 0u)
        s->nmi_pending = 1u;
    if ((value & 0x30u) == 0u) {
        s->irq_need_ticks = 0u;
        s->irq_level = 0u;
        s->irq_flag = 0u;
        s->irq_line = 0u;
    } else {
        tp_irq_update_level(s);
    }
}

void tp_scheduler_set_h_timer(TPScheduler *s, uint16_t value) {
    if (s != NULL) { s->h_timer = (uint16_t)(value & 0x01FFu); tp_irq_update_level(s); }
}

void tp_scheduler_set_v_timer(TPScheduler *s, uint16_t value) {
    if (s != NULL) { s->v_timer = (uint16_t)(value & 0x01FFu); tp_irq_update_level(s); }
}

void tp_scheduler_request_dma(TPScheduler *s, uint8_t mask) {
    if (s != NULL && mask != 0u) {
        s->dma_pending_mask = (uint8_t)(s->dma_pending_mask | mask);
        s->dma_start_delay = 1u;
    }
}

void tp_scheduler_set_hdma_enable(TPScheduler *s, uint8_t mask) {
    if (s != NULL) s->hdma_enable_mask = mask;
}

uint8_t tp_scheduler_read_rdnmi(TPScheduler *s) {
    uint8_t value;
    if (s == NULL) return 0u;
    value = (uint8_t)(s->nmi_flag != 0u ? 0x80u : 0u);
    if (s->nmi_flag != 0u && (s->hclock >= 6u || s->scanline != s->vblank_start_scanline))
        s->nmi_flag = 0u;
    return value;
}

uint8_t tp_scheduler_read_timeup(TPScheduler *s) {
    uint8_t value;
    if (s == NULL) return 0u;
    value = (uint8_t)(s->irq_flag != 0u ? 0x80u : 0u);
    if (s->irq_flag != 0u && s->irq_need_ticks == 0u) {
        s->irq_flag = 0u;
        s->irq_line = 0u;
    }
    return value;
}

uint8_t tp_scheduler_read_hvbjoy(TPScheduler *s) {
    if (s == NULL) return 0u;
    return (uint8_t)((tp_vblank(s) ? 0x80u : 0u) |
                     (tp_hblank(s) ? 0x40u : 0u) |
                     (s->autojoy_active != 0u ? 0x01u : 0u));
}

int tp_scheduler_take_nmi(TPScheduler *s) {
    if (s == NULL || s->nmi_pending == 0u) return 0;
    s->nmi_pending = 0u;
    return 1;
}

int tp_scheduler_irq_asserted(const TPScheduler *s) { return s != NULL && s->irq_line != 0u; }

void tp_scheduler_enter_wai(TPScheduler *s) { if (s != NULL) s->cpu_waiting = 1u; }
void tp_scheduler_enter_stp(TPScheduler *s) { if (s != NULL) s->cpu_stopped = 1u; }

TPSchedulerStop tp_scheduler_halted_quantum(TPScheduler *s) {
    TPSchedulerStop result;
    if (s == NULL) return TP_SCHEDULER_STOP_ARGUMENT;
    if (s->cpu_stopped != 0u)
        return tp_sched_fail(s, TP_SCHEDULER_STOP_STP_REQUIRES_RESET, 0u);
    if (s->cpu_waiting == 0u) return TP_SCHEDULER_OK;
    if (s->nmi_pending != 0u || s->irq_line != 0u) {
        result = tp_scheduler_advance_cpu(s, 12u);
        if (result == TP_SCHEDULER_OK) s->cpu_waiting = 0u;
        return result;
    }
    return tp_scheduler_advance_wall(s, 2u);
}

TPBusStop tp_scheduler_bus_read(void *opaque, uint16_t reg, uint8_t *value) {
    TPScheduler *s = (TPScheduler *)opaque;
    if (s == NULL || value == NULL) return TP_BUS_STOP_ARGUMENT;
    if (reg == 0x4210u) *value = tp_scheduler_read_rdnmi(s);
    else if (reg == 0x4211u) *value = tp_scheduler_read_timeup(s);
    else if (reg == 0x4212u) *value = tp_scheduler_read_hvbjoy(s);
    else return TP_BUS_STOP_TIMING_UNAVAILABLE;
    return TP_BUS_OK;
}

TPBusStop tp_scheduler_bus_write(void *opaque, uint16_t reg, uint8_t value) {
    TPScheduler *s = (TPScheduler *)opaque;
    if (s == NULL) return TP_BUS_STOP_ARGUMENT;
    if (reg == 0x4200u) tp_scheduler_write_nmitimen(s, value);
    else if (reg == 0x4207u) tp_scheduler_set_h_timer(s, (uint16_t)((s->h_timer & 0x100u) | value));
    else if (reg == 0x4208u) tp_scheduler_set_h_timer(s, (uint16_t)((s->h_timer & 0x0FFu) | ((value & 1u) << 8u)));
    else if (reg == 0x4209u) tp_scheduler_set_v_timer(s, (uint16_t)((s->v_timer & 0x100u) | value));
    else if (reg == 0x420Au) tp_scheduler_set_v_timer(s, (uint16_t)((s->v_timer & 0x0FFu) | ((value & 1u) << 8u)));
    else if (reg == 0x420Bu) tp_scheduler_request_dma(s, value);
    else if (reg == 0x420Cu) tp_scheduler_set_hdma_enable(s, value);
    else return TP_BUS_STOP_TIMING_UNAVAILABLE;
    return TP_BUS_OK;
}
