#ifndef THEME_PARK_APU_H
#define THEME_PARK_APU_H

#include <stdint.h>

#include "theme_park_bus.h"
#include "theme_park_scheduler.h"
#include "theme_park_sdsp.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TP_APU_ARAM_BYTES 65536u
/* Deterministic measured S-SMP oscillator profile used by the Starter oracle
 * and mature reference cores: 32,040 DSP frames/s * 32 processor clocks.  The
 * oscillator is independent of the PAL S-CPU master; the scheduler joins the
 * domains with its rational remainder rather than rounding per frame. */
#define TP_APU_SSMP_HZ UINT64_C(1025280)
#define TP_APU_SSMP_PHASE_HZ (TP_APU_SSMP_HZ * UINT64_C(2))

typedef enum TPApuBootstrapPhase {
    TP_APU_IPL_EXECUTING = 0,
    TP_APU_STATIC_ENTRY_REQUIRED,
    TP_APU_STATIC_RUNNING,
    TP_APU_FAILED
} TPApuBootstrapPhase;

typedef struct TPSpc700State {
    uint16_t pc, active_pc;
    uint16_t return_pc[256];
    uint8_t a, x, y, sp, psw;
    uint8_t active_branch_taken, active;
    uint8_t active_cycle_index, active_latch_low, active_latch_high;
    uint16_t return_depth;
    uint32_t active_cycles_remaining;
    uint64_t instructions;
} TPSpc700State;

typedef void (*TPApuInstructionTraceHook)(void *opaque, uint64_t smp_cycle,
                                          const TPSpc700State *state);

typedef struct TPApuTimer {
    uint16_t divider;
    uint8_t target;
    uint8_t stage;
    uint8_t output;
    uint8_t enabled;
} TPApuTimer;

typedef struct TPApu {
    TPScheduler *scheduler;
    uint8_t aram[TP_APU_ARAM_BYTES];
    uint8_t aram_known[TP_APU_ARAM_BYTES / 8u];
    uint8_t cpu_to_smp[4], cpu_to_smp_pending[4], cpu_to_smp_pending_mask;
    uint8_t smp_to_cpu[4];
    uint64_t cpu_port_write_clock[4];
    uint64_t cpu_port_write_smp_phase[4];
    uint64_t cpu_port_write_sequence[4];
    uint64_t smp_port_first_write_clock[4];
    uint64_t smp_cycles, smp_phase_units, port_write_sequence;
    uint64_t final_token_read_master_clock, final_token_read_phase_units;
    uint64_t static_entry_master_clock, static_entry_smp_cycle;
    uint16_t upload_address, static_entry_pc;
    uint32_t uploaded_bytes, epoch;
    uint8_t expected_token, last_token, last_token_valid;
    uint8_t control, dsp_address, aux[2], ipl_rom_enabled;
    uint8_t smp_startup_cycles_remaining, static_entry_record_pending;
    uint8_t phase;
    TPSpc700State spc;
    TPApuTimer timer[3];
    TPSdsp sdsp;
    TPBusStop failure;
    TPApuInstructionTraceHook instruction_trace;
    void *instruction_trace_opaque;
} TPApu;

void tp_apu_power_on(TPApu *apu, TPScheduler *scheduler);
void tp_apu_cpu_reset(TPApu *apu);
TPBusStop tp_apu_cpu_read(void *opaque, uint16_t reg, uint8_t *value);
TPBusStop tp_apu_cpu_write(void *opaque, uint16_t reg, uint8_t value);
TPSchedulerStop tp_apu_advance_domain(void *opaque, uint64_t target_phase_units);
TPBusStop tp_apu_smp_read(TPApu *apu, uint16_t address, uint8_t *value);
TPBusStop tp_apu_smp_write(TPApu *apu, uint16_t address, uint8_t value);
int tp_apu_aram_byte_known(const TPApu *apu, uint16_t address);
void tp_apu_start_static_spc700(TPApu *apu);
void tp_apu_set_instruction_trace(TPApu *apu, TPApuInstructionTraceHook hook,
                                  void *opaque);

#ifdef __cplusplus
}
#endif

#endif
