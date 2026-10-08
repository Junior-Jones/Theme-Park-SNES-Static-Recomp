#include "theme_park_machine.h"

#include <string.h>

#include "theme_park_v09_timing.h"
#include "tp_v07_generated.h"

static uint64_t tp_machine_fnv1a64(const void *data, size_t size) {
    const uint8_t *bytes = (const uint8_t *)data;
    uint64_t hash = UINT64_C(1469598103934665603);
    size_t index;
    for (index = 0u; index < size; ++index) {
        hash ^= bytes[index];
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}

static void tp_machine_trace_step(TPMachine *m) {
    TPMachineTraceEntry *entry = &m->trace[m->trace_next];
    entry->master_clock = m->scheduler.master_clock;
    entry->address = tp_scpu_address(&m->cpu);
    entry->context_key = tp_scpu_context_key(&m->cpu);
    entry->a = m->cpu.a;
    entry->x = m->cpu.x;
    entry->y = m->cpu.y;
    entry->s = m->cpu.s;
    entry->d = m->cpu.d;
    entry->dbr = m->cpu.dbr;
    entry->pbr = m->cpu.pbr;
    entry->p = m->cpu.p;
    entry->e = m->cpu.e;
    m->trace_next = (m->trace_next + 1u) % TP_MACHINE_TRACE_CAPACITY;
    if (m->trace_count < TP_MACHINE_TRACE_CAPACITY) ++m->trace_count;
}

static int tp_machine_push8(TPMachine *m, uint8_t value) {
    if (tp_bus_cpu_write_cycle(&m->bus, m->cpu.s, value) != TP_BUS_OK) return 0;
    m->cpu.s = m->cpu.e != 0u
        ? (uint16_t)(0x0100u | ((m->cpu.s - 1u) & 0x00FFu))
        : (uint16_t)(m->cpu.s - 1u);
    return 1;
}

static int tp_machine_interrupt(TPMachine *m, int nmi) {
    uint8_t dummy = 0u, low = 0u, high = 0u;
    uint16_t vector;
    uint64_t interrupt_cycles;
    const uint32_t current = tp_scpu_address(&m->cpu);
    if (tp_bus_cpu_read_cycle(&m->bus, current, &dummy) != TP_BUS_OK ||
        tp_bus_cpu_internal_cycle(&m->bus) != TP_BUS_OK) return 0;
    if (m->cpu.e != 0u) {
        if (!tp_machine_push8(m, (uint8_t)(m->cpu.pc >> 8u)) ||
            !tp_machine_push8(m, (uint8_t)m->cpu.pc) ||
            !tp_machine_push8(m, (uint8_t)(m->cpu.p | 0x20u))) return 0;
        vector = (uint16_t)(nmi ? 0xFFFAu : 0xFFFEu);
        interrupt_cycles = 7u;
    } else {
        if (!tp_machine_push8(m, m->cpu.pbr) ||
            !tp_machine_push8(m, (uint8_t)(m->cpu.pc >> 8u)) ||
            !tp_machine_push8(m, (uint8_t)m->cpu.pc) ||
            !tp_machine_push8(m, m->cpu.p)) return 0;
        vector = (uint16_t)(nmi ? 0xFFEAu : 0xFFEEu);
        interrupt_cycles = 8u;
    }
    m->cpu.p = (uint8_t)((m->cpu.p | TP_P_I) & (uint8_t)~TP_P_D);
    m->cpu.pbr = 0u;
    if (tp_bus_cpu_read_cycle(&m->bus, vector, &low) != TP_BUS_OK ||
        tp_bus_cpu_read_cycle(&m->bus, (uint16_t)(vector + 1u), &high) != TP_BUS_OK) return 0;
    m->cpu.pc = (uint16_t)(low | ((uint16_t)high << 8u));
    if (tp_v09_timing_plan(tp_scpu_context_key(&m->cpu)) == NULL) {
        tp_scpu_stop(&m->cpu, tp_scpu_address(&m->cpu),
                     "UNADMITTED_INTERRUPT_TARGET");
        return 0;
    }
    m->cpu.completed_cycles += interrupt_cycles;
    return 1;
}

TPBusStop tp_machine_power_on(TPMachine *m, const uint8_t *rom,
                              size_t rom_size, TPBusPorts ports,
                              TPSchedulerHooks hooks) {
    return tp_machine_power_on_profile(m, rom, rom_size, ports, hooks,
                                       TP_POWER_ON_STRICT_UNKNOWN);
}

TPBusStop tp_machine_power_on_profile(TPMachine *m, const uint8_t *rom,
                                      size_t rom_size, TPBusPorts ports,
                                      TPSchedulerHooks hooks,
                                      TPPowerOnProfile profile) {
    TPBusStop result;
    if (m == NULL) return TP_BUS_STOP_ARGUMENT;
    memset(m, 0, sizeof(*m));
    hooks.dma_opaque = &m->dma;
    hooks.dma_event = tp_dma_scheduler_event;
    hooks.raster_opaque = &m->ppu;
    hooks.raster_edge = tp_ppu_raster_edge;
    tp_input_power_on(&m->input, &m->bus);
    hooks.input_opaque = &m->input;
    hooks.autojoy_phase = tp_input_autojoy_phase;
    tp_scheduler_power_on(&m->scheduler, hooks);
    ports.timing.opaque = &m->scheduler;
    ports.timing.read8 = tp_scheduler_bus_read;
    ports.timing.write8 = tp_scheduler_bus_write;
    ports.dma.opaque = &m->dma;
    ports.dma.read8 = tp_dma_bus_read;
    ports.dma.write8 = tp_dma_bus_write;
    tp_ppu_power_on(&m->ppu, &m->scheduler);
    ports.ppu.opaque = &m->ppu;
    ports.ppu.read8 = tp_ppu_bus_read;
    ports.ppu.write8 = tp_ppu_bus_write;
    tp_apu_power_on(&m->apu, &m->scheduler);
    ports.apuio.opaque = &m->apu;
    ports.apuio.read8 = tp_apu_cpu_read;
    ports.apuio.write8 = tp_apu_cpu_write;
    ports.input.opaque = &m->input;
    ports.input.read8 = tp_input_bus_read;
    ports.input.write8 = tp_input_bus_write;
    result = tp_bus_power_on_profile(&m->bus, rom, rom_size, ports, profile);
    if (result != TP_BUS_OK) return result;
    tp_bus_bind_scheduler(&m->bus, &m->scheduler);
    tp_dma_power_on(&m->dma, &m->bus, &m->scheduler);
    if (tp_scheduler_configure_domain(&m->scheduler, TP_DOMAIN_SSMP,
            TP_APU_SSMP_PHASE_HZ, TP_PAL_MASTER_HZ_NUMERATOR, 0u,
            &m->apu, tp_apu_advance_domain) != TP_SCHEDULER_OK)
        return TP_BUS_STOP_TIMING_UNAVAILABLE;
    m->cpu.s = 0x01FFu;
    m->cpu.p = TP_P_I | TP_P_M | TP_P_X;
    m->cpu.e = 1u;
    result = tp_bus_reset(&m->bus, &m->cpu);
    if (result != TP_BUS_OK) return result;
    if (tp_scheduler_advance_wall(&m->scheduler, TP_RESET_STARTUP_MASTER_CLOCKS) !=
        TP_SCHEDULER_OK) return TP_BUS_STOP_TIMING_UNAVAILABLE;
    return TP_BUS_OK;
}

TPBusStop tp_machine_reset(TPMachine *m) {
    TPBusStop result;
    if (m == NULL) return TP_BUS_STOP_ARGUMENT;
    tp_scheduler_cpu_reset(&m->scheduler);
    tp_dma_reset(&m->dma);
    tp_ppu_reset(&m->ppu);
    tp_apu_cpu_reset(&m->apu);
    tp_input_cpu_reset(&m->input);
    result = tp_bus_reset(&m->bus, &m->cpu);
    if (result != TP_BUS_OK) return result;
    if (tp_scheduler_advance_wall(&m->scheduler, TP_RESET_STARTUP_MASTER_CLOCKS) !=
        TP_SCHEDULER_OK) return TP_BUS_STOP_TIMING_UNAVAILABLE;
    return TP_BUS_OK;
}

void tp_machine_set_standard_pad(TPMachine *m, unsigned port, uint16_t state) {
    if (m != NULL) tp_input_set_standard_pad(&m->input, port, state);
}

size_t tp_machine_pcm_available(const TPMachine *m) {
    return m != NULL ? tp_sdsp_pcm_available(&m->apu.sdsp) : 0u;
}

size_t tp_machine_pcm_read(TPMachine *m, int16_t *stereo,
                           uint8_t *known, size_t frame_capacity) {
    return m != NULL
        ? tp_sdsp_pcm_read(&m->apu.sdsp, stereo, known, frame_capacity)
        : 0u;
}

int tp_machine_read_diagnostics(const TPMachine *m,
                                TPMachineDiagnostics *d) {
    if (m == NULL || d == NULL) return 0;
    memset(d, 0, sizeof(*d));
    d->master_clock = m->scheduler.master_clock;
    d->scheduler_frame_count = m->scheduler.frame_count;
    d->published_frame_sequence = m->ppu.published_sequence;
    d->pcm_frames_produced = m->apu.sdsp.sample_frames;
    d->pcm_frames_available = (uint64_t)m->apu.sdsp.pcm_count;
    d->pcm_fnv1a64 = m->apu.sdsp.pcm_fnv1a64;
    d->scpu_completed_cycles = m->cpu.completed_cycles;
    d->ssmp_cycles = m->apu.smp_cycles;
    d->ssmp_instructions = m->apu.spc.instructions;
    d->apu_static_entry_master_clock = m->apu.static_entry_master_clock;
    d->apu_static_entry_smp_cycle = m->apu.static_entry_smp_cycle;
    d->scheduler_event_count = m->scheduler.event_count;
    d->scheduler_event_digest = m->scheduler.event_digest;
    d->dma_transfer_bytes = m->dma.transfer_bytes;
    d->dma_transfer_master_clocks = m->dma.transfer_master_clocks;
    d->input_report_sequence = m->input.report_sequence;
    d->wram_fnv1a64 = tp_machine_fnv1a64(m->bus.wram, sizeof(m->bus.wram));
    d->vram_fnv1a64 = tp_machine_fnv1a64(m->ppu.vram, sizeof(m->ppu.vram));
    d->cgram_fnv1a64 = tp_machine_fnv1a64(m->ppu.cgram, sizeof(m->ppu.cgram));
    d->oam_fnv1a64 = tp_machine_fnv1a64(m->ppu.oam, sizeof(m->ppu.oam));
    d->published_frame_fnv1a64 = tp_machine_fnv1a64(
        m->ppu.published_frame, sizeof(m->ppu.published_frame));
    d->scpu_address = tp_scpu_address(&m->cpu);
    d->scpu_context_key = tp_scpu_context_key(&m->cpu);
    d->scpu_failure_address = m->cpu.failure.address;
    d->scpu_failure_context_key = m->cpu.failure.context_key;
    d->bus_failure_address = m->bus.failure.address;
    d->scheduler_failure_detail = m->scheduler.failure.detail;
    d->scanline = m->scheduler.scanline;
    d->hclock = m->scheduler.hclock;
    d->ssmp_pc = m->apu.spc.pc;
    d->ssmp_active_pc = m->apu.spc.active_pc;
    d->scpu_a = m->cpu.a;
    d->scpu_x = m->cpu.x;
    d->scpu_y = m->cpu.y;
    d->scpu_s = m->cpu.s;
    d->scpu_d = m->cpu.d;
    d->scpu_dbr = m->cpu.dbr;
    d->scpu_pbr = m->cpu.pbr;
    d->scpu_p = m->cpu.p;
    d->scpu_e = m->cpu.e;
    d->ssmp_a = m->apu.spc.a;
    d->ssmp_x = m->apu.spc.x;
    d->ssmp_y = m->apu.spc.y;
    d->ssmp_sp = m->apu.spc.sp;
    d->ssmp_psw = m->apu.spc.psw;
    d->ssmp_active = m->apu.spc.active;
    d->nmitimen = m->bus.nmitimen;
    d->nmi_flag = m->scheduler.nmi_flag;
    d->nmi_pending = m->scheduler.nmi_pending;
    d->forced_blank = m->ppu.forced_blank;
    d->brightness = m->ppu.brightness;
    d->bg_mode = (uint8_t)(m->ppu.registers[0x05u] & 7u);
    d->main_screen = m->ppu.registers[0x2Cu];
    d->sub_screen = m->ppu.registers[0x2Du];
    d->ppu_vram_address = m->ppu.vram_address;
    d->ppu_oam_address = m->ppu.oam_address;
    d->ppu_cgram_address = m->ppu.cgram_address;
    d->ppu_cgram_second = m->ppu.cgram_second;
    d->ppu_oam_write_pending = m->ppu.oam_write_pending;
    memcpy(d->cpu_to_smp, m->apu.cpu_to_smp, sizeof(d->cpu_to_smp));
    memcpy(d->smp_to_cpu, m->apu.smp_to_cpu, sizeof(d->smp_to_cpu));
    d->scpu_waiting = m->cpu.waiting;
    d->scpu_stopped = m->cpu.stopped;
    d->apu_phase = m->apu.phase;
    d->apu_uploaded_bytes = m->apu.uploaded_bytes;
    d->apu_epoch = m->apu.epoch;
    d->apu_upload_address = m->apu.upload_address;
    d->apu_static_entry_pc = m->apu.static_entry_pc;
    d->scheduler_field = m->scheduler.field;
    d->scheduler_irq_flag = m->scheduler.irq_flag;
    d->scheduler_irq_line = m->scheduler.irq_line;
    d->scheduler_autojoy_active = m->scheduler.autojoy_active;
    d->scheduler_dma_pending_mask = m->scheduler.dma_pending_mask;
    d->scheduler_hdma_enable_mask = m->scheduler.hdma_enable_mask;
    d->dma_active_channel = m->dma.active_channel;
    d->dma_servicing = m->dma.servicing;
    d->dma_hdma_enable = m->dma.hdma_enable;
    d->sdsp_phase = m->apu.sdsp.phase;
    d->sdsp_echo_pointer = m->apu.sdsp.echo_pointer;
    {
        unsigned voice;
        for (voice = 0u; voice < TP_SDSP_VOICE_COUNT; ++voice)
            if (m->apu.sdsp.voice[voice].active != 0u)
                d->sdsp_active_voice_mask |= (uint8_t)(1u << voice);
    }
    memcpy(d->input_live_pad, m->input.live_pad, sizeof(d->input_live_pad));
    memcpy(d->input_serial_shift, m->input.serial_shift, sizeof(d->input_serial_shift));
    memcpy(d->input_auto_result, m->input.auto_result, sizeof(d->input_auto_result));
    d->input_cpu_strobe = m->input.cpu_strobe;
    d->input_auto_strobe = m->input.auto_strobe;
    d->input_effective_strobe = m->input.effective_strobe;
    d->pcm_has_unknown_frames = m->apu.sdsp.unknown_frames != 0u;
    d->bus_stop = m->bus.failure.reason;
    d->ppu_stop = m->ppu.failure;
    d->apu_stop = m->apu.failure;
    d->scheduler_stop = m->scheduler.failure.reason;
    d->sdsp_stop = m->apu.sdsp.stop;
    d->power_on_profile = m->bus.power_on_profile;
    d->bus_failure_value = m->bus.failure.value;
    d->scheduler_failure_clock = m->scheduler.failure.master_clock;
    d->scheduler_failure_scanline = m->scheduler.failure.scanline;
    d->scheduler_failure_hclock = m->scheduler.failure.hclock;
    d->trace_count = m->trace_count;
    if (m->trace_count != 0u) {
        uint32_t index;
        const uint32_t oldest = (m->trace_next + TP_MACHINE_TRACE_CAPACITY -
                                 m->trace_count) % TP_MACHINE_TRACE_CAPACITY;
        for (index = 0u; index < m->trace_count; ++index)
            d->trace[index] = m->trace[(oldest + index) % TP_MACHINE_TRACE_CAPACITY];
    }
    memcpy(d->scpu_failure_reason, m->cpu.failure.reason,
           sizeof(d->scpu_failure_reason));
    return 1;
}

int tp_machine_read_published_frame(const TPMachine *m, uint16_t *pixels,
                                    uint8_t *known, uint32_t pixel_capacity,
                                    uint16_t *width, uint16_t *height,
                                    uint64_t *sequence) {
    return m != NULL
        ? tp_ppu_read_published_frame(&m->ppu, pixels, known, pixel_capacity,
                                      width, height, sequence)
        : 0;
}

TPScpuExecResult tp_machine_step(TPMachine *m) {
    TPScpuBus view;
    int nmi;
    if (m == NULL) return TP_SCPU_STOPPED;
    tp_machine_trace_step(m);
    if (m->cpu.stopped != 0u) {
        tp_scheduler_halted_quantum(&m->scheduler);
        return tp_scpu_stop(&m->cpu, tp_scpu_address(&m->cpu),
                            "STP_REQUIRES_RESET");
    }
    if (m->cpu.waiting != 0u) {
        if (tp_scheduler_halted_quantum(&m->scheduler) != TP_SCHEDULER_OK)
            return tp_scpu_stop(&m->cpu, tp_scpu_address(&m->cpu),
                                "WAI_SCHEDULER_FAILURE");
        if (m->scheduler.cpu_waiting != 0u) return TP_SCPU_EXECUTED;
        m->cpu.waiting = 0u;
    }
    nmi = tp_scheduler_take_nmi(&m->scheduler);
    if (nmi || (tp_scheduler_irq_asserted(&m->scheduler) &&
                (m->cpu.p & TP_P_I) == 0u)) {
        return tp_machine_interrupt(m, nmi) ? TP_SCPU_EXECUTED : TP_SCPU_STOPPED;
    }
    view = tp_bus_scpu_view(&m->bus);
    return tp_v07_dispatch(&m->cpu, &view);
}

TPMachineRunResult tp_machine_run_to_next_frame(TPMachine *m,
                                                uint64_t step_limit,
                                                uint64_t *steps_executed) {
    uint64_t steps = 0u;
    uint64_t initial_sequence;
    if (steps_executed != NULL) *steps_executed = 0u;
    if (m == NULL || step_limit == 0u) return TP_MACHINE_RUN_ARGUMENT;
    initial_sequence = m->ppu.published_sequence;
    while (steps < step_limit) {
        if (tp_machine_step(m) != TP_SCPU_EXECUTED) {
            if (steps_executed != NULL) *steps_executed = steps;
            return TP_MACHINE_RUN_STOPPED;
        }
        steps++;
        if (m->ppu.published_sequence != initial_sequence) {
            if (steps_executed != NULL) *steps_executed = steps;
            return TP_MACHINE_RUN_FRAME_READY;
        }
    }
    if (steps_executed != NULL) *steps_executed = steps;
    return TP_MACHINE_RUN_STEP_LIMIT;
}
