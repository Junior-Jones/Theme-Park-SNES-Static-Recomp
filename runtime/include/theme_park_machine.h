#ifndef THEME_PARK_MACHINE_H
#define THEME_PARK_MACHINE_H

#include "theme_park_bus.h"
#include "theme_park_apu.h"
#include "theme_park_dma.h"
#include "theme_park_input.h"
#include "theme_park_ppu.h"
#include "theme_park_scheduler.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TP_RESET_STARTUP_MASTER_CLOCKS 186u
#define TP_MACHINE_TRACE_CAPACITY 64u

typedef struct TPMachineTraceEntry {
    uint64_t master_clock;
    uint32_t address;
    uint32_t context_key;
    uint16_t a, x, y, s, d;
    uint8_t dbr, pbr, p, e;
} TPMachineTraceEntry;

typedef struct TPMachine {
    TPScpuState cpu;
    TPBus bus;
    TPScheduler scheduler;
    TPDma dma;
    TPPpu ppu;
    TPApu apu;
    TPInput input;
    TPMachineTraceEntry trace[TP_MACHINE_TRACE_CAPACITY];
    uint32_t trace_next;
    uint32_t trace_count;
} TPMachine;

typedef enum TPMachineRunResult {
    TP_MACHINE_RUN_FRAME_READY = 0,
    TP_MACHINE_RUN_STOPPED = 1,
    TP_MACHINE_RUN_STEP_LIMIT = 2,
    TP_MACHINE_RUN_ARGUMENT = 3
} TPMachineRunResult;

/* Stable, read-only whole-machine evidence for a stopped or running core.
 * This reports current owners; it does not interpret, repair, or suppress a
 * failure and therefore remains suitable for the opaque frontend boundary. */
typedef struct TPMachineDiagnostics {
    uint64_t master_clock;
    uint64_t scheduler_frame_count;
    uint64_t published_frame_sequence;
    uint64_t pcm_frames_produced;
    uint64_t pcm_frames_available;
    uint64_t pcm_fnv1a64;
    uint64_t scpu_completed_cycles;
    uint64_t ssmp_cycles;
    uint64_t ssmp_instructions;
    uint64_t apu_static_entry_master_clock;
    uint64_t apu_static_entry_smp_cycle;
    uint64_t scheduler_event_count;
    uint64_t scheduler_event_digest;
    uint64_t dma_transfer_bytes;
    uint64_t dma_transfer_master_clocks;
    uint64_t input_report_sequence;
    uint64_t wram_fnv1a64;
    uint64_t vram_fnv1a64;
    uint64_t cgram_fnv1a64;
    uint64_t oam_fnv1a64;
    uint64_t published_frame_fnv1a64;
    uint32_t scpu_address;
    uint32_t scpu_context_key;
    uint32_t scpu_failure_address;
    uint32_t scpu_failure_context_key;
    uint32_t bus_failure_address;
    uint32_t scheduler_failure_detail;
    uint16_t scanline;
    uint16_t hclock;
    uint16_t ssmp_pc;
    uint16_t ssmp_active_pc;
    uint16_t scpu_a, scpu_x, scpu_y, scpu_s, scpu_d;
    uint8_t scpu_dbr, scpu_pbr, scpu_p, scpu_e;
    uint8_t ssmp_a, ssmp_x, ssmp_y, ssmp_sp, ssmp_psw, ssmp_active;
    uint8_t nmitimen, nmi_flag, nmi_pending;
    uint8_t forced_blank, brightness, bg_mode, main_screen, sub_screen;
    uint16_t ppu_vram_address, ppu_oam_address;
    uint8_t ppu_cgram_address, ppu_cgram_second, ppu_oam_write_pending;
    uint8_t cpu_to_smp[4], smp_to_cpu[4];
    uint8_t scpu_waiting;
    uint8_t scpu_stopped;
    uint8_t apu_phase;
    uint32_t apu_uploaded_bytes, apu_epoch;
    uint16_t apu_upload_address, apu_static_entry_pc;
    uint8_t scheduler_field, scheduler_irq_flag, scheduler_irq_line;
    uint8_t scheduler_autojoy_active, scheduler_dma_pending_mask;
    uint8_t scheduler_hdma_enable_mask;
    uint8_t dma_active_channel, dma_servicing, dma_hdma_enable;
    uint8_t sdsp_phase, sdsp_active_voice_mask;
    uint16_t sdsp_echo_pointer;
    uint16_t input_live_pad[2], input_serial_shift[2], input_auto_result[4];
    uint8_t input_cpu_strobe, input_auto_strobe, input_effective_strobe;
    uint8_t pcm_has_unknown_frames;
    TPBusStop bus_stop;
    TPBusStop ppu_stop;
    TPBusStop apu_stop;
    TPSchedulerStop scheduler_stop;
    TPSdspStop sdsp_stop;
    TPPowerOnProfile power_on_profile;
    TPMachineTraceEntry trace[TP_MACHINE_TRACE_CAPACITY];
    uint32_t trace_count;
    uint8_t bus_failure_value;
    uint64_t scheduler_failure_clock;
    uint16_t scheduler_failure_scanline, scheduler_failure_hclock;
    char scpu_failure_reason[128];
} TPMachineDiagnostics;

TPBusStop tp_machine_power_on(TPMachine *machine, const uint8_t *rom,
                              size_t rom_size, TPBusPorts ports,
                              TPSchedulerHooks hooks);
TPBusStop tp_machine_power_on_profile(TPMachine *machine, const uint8_t *rom,
                                      size_t rom_size, TPBusPorts ports,
                                      TPSchedulerHooks hooks,
                                      TPPowerOnProfile profile);
TPBusStop tp_machine_reset(TPMachine *machine);
TPScpuExecResult tp_machine_step(TPMachine *machine);
TPMachineRunResult tp_machine_run_to_next_frame(TPMachine *machine,
                                                uint64_t step_limit,
                                                uint64_t *steps_executed);
int tp_machine_read_diagnostics(const TPMachine *machine,
                                TPMachineDiagnostics *diagnostics);
int tp_machine_read_published_frame(const TPMachine *machine, uint16_t *pixels,
                                    uint8_t *known, uint32_t pixel_capacity,
                                    uint16_t *width, uint16_t *height,
                                    uint64_t *sequence);
void tp_machine_set_standard_pad(TPMachine *machine, unsigned port, uint16_t state);
size_t tp_machine_pcm_available(const TPMachine *machine);
size_t tp_machine_pcm_read(TPMachine *machine, int16_t *stereo,
                           uint8_t *known, size_t frame_capacity);

#ifdef __cplusplus
}
#endif

#endif
