#include "theme_park_apu.h"
#include "theme_park_spc700_aot.h"
#include "theme_park_spc700.h"

#include <string.h>

/* Immutable 64-byte SNES S-SMP IPL mask ROM.  This is architectural bootstrap
   storage, not target program code and not a runtime instruction decoder. */
static const uint8_t tp_apu_ipl_rom[64] = {
    0xCDu,0xEFu,0xBDu,0xE8u,0x00u,0xC6u,0x1Du,0xD0u,
    0xFCu,0x8Fu,0xAAu,0xF4u,0x8Fu,0xBBu,0xF5u,0x78u,
    0xCCu,0xF4u,0xD0u,0xFBu,0x2Fu,0x19u,0xEBu,0xF4u,
    0xD0u,0xFCu,0x7Eu,0xF4u,0xD0u,0x0Bu,0xE4u,0xF5u,
    0xCBu,0xF4u,0xD7u,0x00u,0xFCu,0xD0u,0xF3u,0xABu,
    0x01u,0x10u,0xEFu,0x7Eu,0xF4u,0x10u,0xEBu,0xBAu,
    0xF6u,0xDAu,0x00u,0xBAu,0xF4u,0xC4u,0xF4u,0xDDu,
    0x5Du,0xD0u,0xDBu,0x1Fu,0x00u,0x00u,0xC0u,0xFFu
};

static void tp_apu_mark_known(TPApu *a, uint16_t address) {
    a->aram_known[address >> 3u] |= (uint8_t)(1u << (address & 7u));
}

static void tp_apu_finish_cpu_input_latch(TPApu *a) {
    unsigned port;
    for (port = 0u; port < 4u; ++port) {
        if ((a->cpu_to_smp_pending_mask & (uint8_t)(1u << port)) != 0u)
            a->cpu_to_smp[port] = a->cpu_to_smp_pending[port];
    }
    a->cpu_to_smp_pending_mask = 0u;
}

int tp_apu_aram_byte_known(const TPApu *a, uint16_t address) {
    return a != NULL && (a->aram_known[address >> 3u] &
        (uint8_t)(1u << (address & 7u))) != 0u;
}

static void tp_apu_ipl_ready(TPApu *a) {
    memset(a->cpu_to_smp, 0, sizeof(a->cpu_to_smp));
    memset(a->smp_to_cpu, 0, sizeof(a->smp_to_cpu));
    memset(a->cpu_port_write_clock, 0, sizeof(a->cpu_port_write_clock));
    memset(a->cpu_port_write_sequence, 0, sizeof(a->cpu_port_write_sequence));
    memset(&a->spc, 0, sizeof(a->spc));
    a->spc.pc = 0xFFC0u;
    a->phase = TP_APU_IPL_EXECUTING;
    a->expected_token = a->last_token = a->last_token_valid = 0u;
    a->upload_address = 0u;
    a->static_entry_pc = 0xFFC0u;
    a->uploaded_bytes = 0u;
    a->ipl_rom_enabled = 1u;
    /* The S-SMP oscillator is live immediately, but the reset sequencer holds
       instruction execution for two processor clocks before the first IPL
       opcode fetch.  These clocks are visible in the independent phase domain
       and must not be replaced by a PAL-master delay. */
    a->smp_startup_cycles_remaining = 2u;
}

void tp_apu_power_on(TPApu *a, TPScheduler *scheduler) {
    if (a == NULL) return;
    memset(a, 0, sizeof(*a));
    a->scheduler = scheduler;
    tp_sdsp_power_on(&a->sdsp, a->aram, a->aram_known);
    tp_apu_ipl_ready(a);
}

void tp_apu_cpu_reset(TPApu *a) {
    /* RESET is an S-CPU line.  It does not reset the S-SMP, its directional
       latches, timer phase, upload epoch, or ARAM. */
    (void)a;
}

void tp_apu_start_static_spc700(TPApu *a) {
    if (a == NULL || a->phase != TP_APU_STATIC_ENTRY_REQUIRED ||
        a->static_entry_pc != 0x0300u || !tp_apu_aram_byte_known(a, 0x0300u)) {
        if (a != NULL) { a->phase = TP_APU_FAILED; a->failure = TP_BUS_STOP_APUIO_UNAVAILABLE; }
        return;
    }
    a->phase = TP_APU_STATIC_RUNNING;
}

void tp_apu_set_instruction_trace(TPApu *a, TPApuInstructionTraceHook hook,
                                  void *opaque) {
    if (a == NULL) return;
    a->instruction_trace = hook;
    a->instruction_trace_opaque = opaque;
}

/* The immutable IPL is a finite static program, so it is lowered by exact PC
   rather than decoded at runtime.  Each lowered body also retains its S-SMP
   bus-event positions.  In particular, multi-byte reads and writes must not be
   collapsed onto the instruction boundary because the S-CPU port latch can
   change between those events. */
static int tp_apu_ipl_begin(TPApu *a) {
    TPSpc700State *s = &a->spc;
    const uint16_t pc = s->pc;
    uint32_t cycles;
    switch (s->pc) {
        case 0xFFC0u: case 0xFFC3u: cycles = 2u; s->pc += 2u; break;
        case 0xFFC2u: case 0xFFC5u: case 0xFFC6u: case 0xFFE4u:
        case 0xFFF7u: case 0xFFF8u: cycles = (s->pc == 0xFFC5u) ? 4u : 2u; s->pc += 1u; break;
        case 0xFFC7u: case 0xFFD2u: case 0xFFD8u: case 0xFFDCu:
        case 0xFFE5u: case 0xFFE9u: case 0xFFEBu: case 0xFFEDu:
        case 0xFFF9u:
            cycles = 2u; s->pc += 2u; break;
        case 0xFFC9u: case 0xFFCCu: case 0xFFCFu: cycles = 5u; s->pc += 3u; break;
        case 0xFFD4u: cycles = 4u; s->pc += 2u; break;
        case 0xFFD6u: case 0xFFDAu: case 0xFFDEu: cycles = 3u; s->pc += 2u; break;
        case 0xFFE0u: cycles = 4u; s->pc += 2u; break;
        case 0xFFE2u: cycles = 7u; s->pc += 2u; break;
        case 0xFFE7u: cycles = 4u; s->pc += 2u; break;
        case 0xFFEFu: case 0xFFF1u: case 0xFFF3u: cycles = 5u; s->pc += 2u; break;
        case 0xFFF5u: cycles = 4u; s->pc += 2u; break;
        case 0xFFFBu: cycles = 6u; s->pc += 3u; break;
        default: return tp_spc_fail(a);
    }
    s->active_pc = pc;
    s->active_cycle_index = 0u;
    s->active_latch_low = 0u;
    s->active_latch_high = 0u;
    s->active_branch_taken = 0u;
    if (s->active_pc == 0xFFC7u || s->active_pc == 0xFFD2u ||
        s->active_pc == 0xFFD8u || s->active_pc == 0xFFDCu ||
        s->active_pc == 0xFFE5u || s->active_pc == 0xFFE9u ||
        s->active_pc == 0xFFEDu || s->active_pc == 0xFFF9u) {
        const int take = s->active_pc == 0xFFE9u || s->active_pc == 0xFFEDu
            ? (s->psw & TP_SPC_N) == 0u : (s->psw & TP_SPC_Z) == 0u;
        s->active_branch_taken = (uint8_t)take;
        if (take) cycles += 2u;
    }
    s->active_cycles_remaining = cycles;
    s->active = 1u;
    return 1;
}

static int tp_apu_ipl_bus_event(TPApu *a) {
    TPSpc700State *s = &a->spc;
    uint16_t address;
    const uint8_t cycle = (uint8_t)(s->active_cycle_index + 1u);
    s->active_cycle_index = cycle;
    switch (s->active_pc) {
        case 0xFFCFu:
            if (cycle == 4u) {
                if (!tp_spc_read(a, 0x00F4u, &s->active_latch_low)) return 0;
                tp_spc_cmp8(a, s->active_latch_low, 0xCCu);
            }
            break;
        case 0xFFE2u:
            if (cycle == 3u) {
                if (!tp_spc_read(a, tp_spc_dp(a, 0x00u), &s->active_latch_low)) return 0;
            } else if (cycle == 4u) {
                if (!tp_spc_read(a, tp_spc_dp(a, 0x01u), &s->active_latch_high)) return 0;
            } else if (cycle == 7u) {
                address = (uint16_t)((uint16_t)(s->active_latch_low |
                    ((uint16_t)s->active_latch_high << 8u)) + s->y);
                if (!tp_spc_write(a, address, s->a)) return 0;
                a->upload_address = address;
                ++a->uploaded_bytes;
            }
            break;
        case 0xFFE7u:
            if (cycle == 3u) {
                if (!tp_spc_read(a, tp_spc_dp(a, 0x01u), &s->active_latch_low)) return 0;
                ++s->active_latch_low;
                tp_spc_nz8(a, s->active_latch_low);
            } else if (cycle == 4u) {
                if (!tp_spc_write(a, tp_spc_dp(a, 0x01u), s->active_latch_low)) return 0;
            }
            break;
        case 0xFFEFu:
            if (cycle == 3u) {
                if (!tp_spc_read(a, 0x00F6u, &s->active_latch_low)) return 0;
            } else if (cycle == 5u) {
                uint16_t word;
                if (!tp_spc_read(a, 0x00F7u, &s->active_latch_high)) return 0;
                word = (uint16_t)(s->active_latch_low |
                    ((uint16_t)s->active_latch_high << 8u));
                s->a = s->active_latch_low;
                s->y = s->active_latch_high;
                tp_spc_nz16(a, word);
            }
            break;
        case 0xFFF1u:
            if (cycle == 4u) {
                if (!tp_spc_write(a, tp_spc_dp(a, 0x00u), s->a)) return 0;
            } else if (cycle == 5u) {
                if (!tp_spc_write(a, tp_spc_dp(a, 0x01u), s->y)) return 0;
                a->upload_address = (uint16_t)(s->a | ((uint16_t)s->y << 8u));
            }
            break;
        case 0xFFF3u:
            if (cycle == 3u) {
                if (!tp_spc_read(a, 0x00F4u, &s->active_latch_low)) return 0;
            } else if (cycle == 5u) {
                uint16_t word;
                if (!tp_spc_read(a, 0x00F5u, &s->active_latch_high)) return 0;
                word = (uint16_t)(s->active_latch_low |
                    ((uint16_t)s->active_latch_high << 8u));
                s->a = s->active_latch_low;
                s->y = s->active_latch_high;
                tp_spc_nz16(a, word);
            }
            break;
        case 0xFFFBu:
            if (cycle == 5u) {
                if (!tp_spc_read(a, (uint16_t)s->x, &s->active_latch_low)) return 0;
            } else if (cycle == 6u) {
                if (!tp_spc_read(a, (uint16_t)(uint8_t)(s->x + 1u),
                                 &s->active_latch_high)) return 0;
            }
            break;
        default:
            break;
    }
    return 1;
}

static int tp_apu_ipl_complete(TPApu *a) {
    TPSpc700State *s = &a->spc;
    uint8_t value = 0u;
    if (!s->active || s->active_cycles_remaining != 0u) return tp_spc_fail(a);
    switch (s->active_pc) {
        case 0xFFC0u: s->x = 0xEFu; tp_spc_nz8(a, s->x); break;
        case 0xFFC2u: s->sp = s->x; break;
        case 0xFFC3u: s->a = 0u; tp_spc_nz8(a, s->a); break;
        case 0xFFC5u: if (!tp_spc_write(a, s->x, s->a)) return 0; break;
        case 0xFFC6u: --s->x; tp_spc_nz8(a, s->x); break;
        case 0xFFC7u: if (s->active_branch_taken) s->pc = 0xFFC5u; break;
        case 0xFFC9u: if (!tp_spc_write(a, 0x00F4u, 0xAAu)) return 0; break;
        case 0xFFCCu: if (!tp_spc_write(a, 0x00F5u, 0xBBu)) return 0; break;
        case 0xFFCFu: break;
        case 0xFFD2u: if (s->active_branch_taken) s->pc = 0xFFCFu; break;
        case 0xFFD4u: s->pc = 0xFFEFu; break;
        case 0xFFD6u: if (!tp_spc_read(a, 0x00F4u, &s->y)) return 0; tp_spc_nz8(a, s->y); break;
        case 0xFFD8u: if (s->active_branch_taken) s->pc = 0xFFD6u; break;
        case 0xFFDAu:
            if (!tp_spc_read(a, 0x00F4u, &value)) return 0;
            tp_spc_cmp8(a, s->y, value); break;
        case 0xFFDCu: if (s->active_branch_taken) s->pc = 0xFFE9u; break;
        case 0xFFDEu: if (!tp_spc_read(a, 0x00F5u, &s->a)) return 0; tp_spc_nz8(a, s->a); break;
        case 0xFFE0u: if (!tp_spc_write(a, 0x00F4u, s->y)) return 0; break;
        case 0xFFE2u: break;
        case 0xFFE4u: ++s->y; tp_spc_nz8(a, s->y); break;
        case 0xFFE5u: if (s->active_branch_taken) s->pc = 0xFFDAu; break;
        case 0xFFE7u: break;
        case 0xFFE9u: if (s->active_branch_taken) s->pc = 0xFFDAu; break;
        case 0xFFEBu:
            if (!tp_spc_read(a, 0x00F4u, &value)) return 0;
            tp_spc_cmp8(a, s->y, value); break;
        case 0xFFEDu: if (s->active_branch_taken) s->pc = 0xFFDAu; break;
        case 0xFFEFu: break;
        case 0xFFF1u: break;
        case 0xFFF3u: break;
        case 0xFFF5u: if (!tp_spc_write(a, 0x00F4u, s->a)) return 0; break;
        case 0xFFF7u: s->a = s->y; tp_spc_nz8(a, s->a); break;
        case 0xFFF8u: s->x = s->a; tp_spc_nz8(a, s->x); break;
        case 0xFFF9u:
            if (s->active_branch_taken) { ++a->epoch; s->pc = 0xFFD6u; }
            break;
        case 0xFFFBu:
            s->pc = (uint16_t)(s->active_latch_low |
                ((uint16_t)s->active_latch_high << 8u));
            a->static_entry_pc = s->pc;
            a->phase = TP_APU_STATIC_ENTRY_REQUIRED;
            tp_apu_start_static_spc700(a);
            if (a->phase == TP_APU_FAILED) return 0;
            a->static_entry_record_pending = 1u;
            break;
        default: return tp_spc_fail(a);
    }
    s->active = 0u;
    ++s->instructions;
    return 1;
}

static void tp_apu_timer_tick(TPApuTimer *timer, uint32_t clocks, uint16_t divider) {
    uint32_t stages;
    if (!timer->enabled) return;
    stages = (uint32_t)timer->divider + clocks;
    timer->divider = (uint16_t)(stages % divider);
    stages /= divider;
    while (stages-- != 0u) {
        timer->stage++;
        /* The hardware comparison is eight-bit.  A target register value of
           zero therefore fires when the stage counter wraps to zero. */
        if (timer->stage == timer->target) {
            timer->stage = 0u;
            timer->output = (uint8_t)((timer->output + 1u) & 0x0Fu);
        }
    }
}

TPSchedulerStop tp_apu_advance_domain(void *opaque, uint64_t target_phase_units) {
    TPApu *a = (TPApu *)opaque;
    if (a == NULL || target_phase_units + UINT64_C(1) < a->smp_phase_units)
        return TP_SCHEDULER_STOP_DOMAIN_CALLBACK;
    /* The hardware owner advances complete two-unit S-SMP bus events while
       its phase cursor is below floor(master * phase_rate) - 1.  An event may
       finish one unit beyond that target.  Keeping this half-cycle cursor is
       required for deterministic CPU-port latch ordering. */
    while (a->smp_phase_units + UINT64_C(1) < target_phase_units) {
        uint8_t executing_ipl;
        if (a->smp_startup_cycles_remaining == 0u && a->spc.active == 0u) {
            if (a->phase == TP_APU_STATIC_RUNNING && a->instruction_trace != NULL)
                a->instruction_trace(a->instruction_trace_opaque, a->smp_cycles,
                                     &a->spc);
            if (a->phase == TP_APU_IPL_EXECUTING) {
                if (!tp_apu_ipl_begin(a)) return TP_SCHEDULER_STOP_DOMAIN_CALLBACK;
            } else if (a->phase == TP_APU_STATIC_RUNNING &&
                       !tp_spc700_aot_begin(a)) return TP_SCHEDULER_STOP_DOMAIN_CALLBACK;
        }
        tp_apu_timer_tick(&a->timer[0], 1u, 128u);
        tp_apu_timer_tick(&a->timer[1], 1u, 128u);
        tp_apu_timer_tick(&a->timer[2], 1u, 16u);
        if (tp_sdsp_advance_cycles(&a->sdsp, 1u) != TP_SDSP_OK) {
            a->phase = TP_APU_FAILED;
            a->failure = TP_BUS_STOP_APUIO_UNAVAILABLE;
            return TP_SCHEDULER_STOP_DOMAIN_CALLBACK;
        }
        executing_ipl = (uint8_t)(a->phase == TP_APU_IPL_EXECUTING);
        if (a->smp_startup_cycles_remaining != 0u) {
            a->smp_startup_cycles_remaining--;
        } else if (a->phase == TP_APU_IPL_EXECUTING ||
                   a->phase == TP_APU_STATIC_RUNNING) {
            if (executing_ipl && !tp_apu_ipl_bus_event(a))
                return TP_SCHEDULER_STOP_DOMAIN_CALLBACK;
            a->spc.active_cycles_remaining--;
            if (!executing_ipl && a->static_entry_record_pending != 0u &&
                a->spc.active_pc == 0x0300u) {
                a->static_entry_master_clock = a->scheduler != NULL
                    ? a->scheduler->master_clock : 0u;
                a->static_entry_smp_cycle = a->smp_cycles + UINT64_C(1);
                a->static_entry_record_pending = 0u;
            }
            if (a->spc.active_cycles_remaining == 0u) {
                int completed = executing_ipl ? tp_apu_ipl_complete(a)
                                              : tp_spc700_aot_complete(a);
                if (!completed) return TP_SCHEDULER_STOP_DOMAIN_CALLBACK;
            }
        }
        /* This is an S-SMP bus-event boundary, not an instruction boundary.
           A semantic port read completed above therefore observes the old
           latch, matching the two-phase event ordering used by the mature
           static cores. */
        tp_apu_finish_cpu_input_latch(a);
        a->smp_phase_units += UINT64_C(2);
        a->smp_cycles++;
    }
    return a->phase == TP_APU_FAILED ? TP_SCHEDULER_STOP_DOMAIN_CALLBACK : TP_SCHEDULER_OK;
}

TPBusStop tp_apu_cpu_read(void *opaque, uint16_t reg, uint8_t *value) {
    TPApu *a = (TPApu *)opaque;
    if (a == NULL || value == NULL || reg < 0x2140u || reg > 0x2143u)
        return TP_BUS_STOP_APUIO_UNAVAILABLE;
    *value = a->smp_to_cpu[reg & 3u];
    return TP_BUS_OK;
}

TPBusStop tp_apu_cpu_write(void *opaque, uint16_t reg, uint8_t value) {
    TPApu *a = (TPApu *)opaque;
    unsigned port;
    if (a == NULL || reg < 0x2140u || reg > 0x2143u ||
        a->phase == TP_APU_STATIC_ENTRY_REQUIRED || a->phase == TP_APU_FAILED)
        return TP_BUS_STOP_APUIO_UNAVAILABLE;
    port = reg & 3u;
    a->cpu_to_smp_pending[port] = value;
    /* A write at or behind the completed S-SMP phase is visible immediately.
       A target one half-unit beyond that completed boundary belongs to the
       second half of the input tick and is committed after the next bus event.
       The cursor here names completed phase units (unlike implementations that
       name the phase being entered), so the boundary comparison is strict. */
    if (a->scheduler != NULL &&
        a->scheduler->domains[TP_DOMAIN_SSMP].target_ticks <=
            a->smp_phase_units) {
        a->cpu_to_smp[port] = value;
        a->cpu_to_smp_pending_mask &= (uint8_t)~(uint8_t)(1u << port);
    } else {
        a->cpu_to_smp_pending_mask |= (uint8_t)(1u << port);
    }
    a->cpu_port_write_clock[port] = a->scheduler != NULL ? a->scheduler->master_clock : a->smp_cycles;
    a->cpu_port_write_smp_phase[port] = a->smp_phase_units;
    a->cpu_port_write_sequence[port] = ++a->port_write_sequence;
    return TP_BUS_OK;
}

TPBusStop tp_apu_smp_read(TPApu *a, uint16_t address, uint8_t *value) {
    unsigned port;
    if (a == NULL || value == NULL) return TP_BUS_STOP_APUIO_UNAVAILABLE;
    if (address >= 0xFFC0u && a->ipl_rom_enabled != 0u) {
        *value = tp_apu_ipl_rom[address - 0xFFC0u]; return TP_BUS_OK;
    }
    if (address < 0x00F0u || address >= 0x0100u) {
        if (!tp_apu_aram_byte_known(a, address)) return TP_BUS_STOP_APUIO_UNAVAILABLE;
        *value = a->aram[address]; return TP_BUS_OK;
    }
    if (address >= 0x00F4u && address <= 0x00F7u) {
        port = address & 3u;
        *value = a->cpu_to_smp[port];
        if (port == 0u && *value == 0x3Eu && a->final_token_read_master_clock == 0u &&
            a->scheduler != NULL && a->scheduler->master_clock >= UINT64_C(1800000)) {
            a->final_token_read_master_clock = a->scheduler != NULL
                ? a->scheduler->master_clock : a->smp_cycles;
            a->final_token_read_phase_units = a->smp_phase_units;
        }
        return TP_BUS_OK;
    }
    if (address == 0x00F2u) { *value = a->dsp_address; return TP_BUS_OK; }
    if (address == 0x00F3u) {
        return tp_sdsp_read_register(&a->sdsp, a->dsp_address, value) == TP_SDSP_OK
            ? TP_BUS_OK : TP_BUS_STOP_APUIO_UNAVAILABLE;
    }
    if (address == 0x00F8u || address == 0x00F9u) { *value = a->aux[address & 1u]; return TP_BUS_OK; }
    if (address >= 0x00FDu) {
        port = address - 0x00FDu; *value = a->timer[port].output; a->timer[port].output = 0u; return TP_BUS_OK;
    }
    if (address == 0x00F0u || address == 0x00F1u ||
        (address >= 0x00FAu && address <= 0x00FCu)) {
        *value = 0u; return TP_BUS_OK;
    }
    return TP_BUS_STOP_APUIO_UNAVAILABLE;
}

TPBusStop tp_apu_smp_write(TPApu *a, uint16_t address, uint8_t value) {
    unsigned index;
    if (a == NULL) return TP_BUS_STOP_APUIO_UNAVAILABLE;
    if (address < 0x00F0u || address >= 0x0100u) {
        if (a->phase == TP_APU_STATIC_RUNNING && tp_spc700_aot_code_byte(address)) {
            a->phase = TP_APU_FAILED;
            a->failure = TP_BUS_STOP_APUIO_UNAVAILABLE;
            return a->failure;
        }
        a->aram[address] = value; tp_apu_mark_known(a, address); return TP_BUS_OK;
    }
    if (address == 0x00F0u)
        return TP_BUS_STOP_APUIO_UNAVAILABLE; /* TEST/CLOCK semantics are a later reached obligation. */
    if (address == 0x00F1u) {
        uint8_t old = a->control;
        a->control = value;
        if (value & 0x10u) {
            a->cpu_to_smp[0] = a->cpu_to_smp[1] = 0u;
            a->cpu_to_smp_pending[0] = a->cpu_to_smp_pending[1] = 0u;
            a->cpu_to_smp_pending_mask &= 0xFCu;
        }
        if (value & 0x20u) {
            a->cpu_to_smp[2] = a->cpu_to_smp[3] = 0u;
            a->cpu_to_smp_pending[2] = a->cpu_to_smp_pending[3] = 0u;
            a->cpu_to_smp_pending_mask &= 0xF3u;
        }
        a->ipl_rom_enabled = (uint8_t)((value & 0x80u) != 0u);
        for (index = 0u; index < 3u; ++index) {
            uint8_t enable = (uint8_t)((value >> index) & 1u);
            if (enable && (old & (uint8_t)(1u << index)) == 0u) {
                a->timer[index].divider = 0u; a->timer[index].stage = 0u; a->timer[index].output = 0u;
            }
            a->timer[index].enabled = enable;
        }
        return TP_BUS_OK;
    }
    if (address == 0x00F2u) { a->dsp_address = value; return TP_BUS_OK; }
    if (address == 0x00F3u) {
        return tp_sdsp_write_register(&a->sdsp, a->dsp_address, value) == TP_SDSP_OK
            ? TP_BUS_OK : TP_BUS_STOP_APUIO_UNAVAILABLE;
    }
    if (address >= 0x00F4u && address <= 0x00F7u) {
        unsigned port = address & 3u;
        a->smp_to_cpu[port] = value;
        if (a->smp_port_first_write_clock[port] == 0u)
            a->smp_port_first_write_clock[port] = a->scheduler != NULL
                ? a->scheduler->master_clock : a->smp_cycles;
        return TP_BUS_OK;
    }
    if (address == 0x00F8u || address == 0x00F9u) { a->aux[address & 1u] = value; return TP_BUS_OK; }
    if (address >= 0x00FAu && address <= 0x00FCu) { a->timer[address - 0x00FAu].target = value; return TP_BUS_OK; }
    return TP_BUS_OK; /* Writes to the read-only counter ports have no effect. */
}
