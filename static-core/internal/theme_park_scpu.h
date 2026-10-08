#ifndef THEME_PARK_SCPU_H
#define THEME_PARK_SCPU_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
    TP_P_C = 0x01u,
    TP_P_Z = 0x02u,
    TP_P_I = 0x04u,
    TP_P_D = 0x08u,
    TP_P_X = 0x10u,
    TP_P_M = 0x20u,
    TP_P_V = 0x40u,
    TP_P_N = 0x80u
};

typedef enum TPScpuExecResult {
    TP_SCPU_EXECUTED = 0,
    TP_SCPU_NOT_MINE = 1,
    TP_SCPU_STOPPED = 2
} TPScpuExecResult;

typedef struct TPScpuFailure {
    uint8_t failed;
    uint32_t context_key;
    uint32_t address;
    char reason[128];
} TPScpuFailure;

typedef struct TPScpuState {
    uint16_t a;
    uint16_t x;
    uint16_t y;
    uint16_t s;
    uint16_t d;
    uint16_t pc;
    uint8_t dbr;
    uint8_t pbr;
    uint8_t p;
    uint8_t e;
    uint8_t waiting;
    uint8_t stopped;
    uint64_t completed_cycles;
    TPScpuFailure failure;
} TPScpuState;

/* 08C supplies exact mapping/MMIO ownership; 09C supplies scheduler timing.
 * 07C uses only this narrow fail-closed boundary and never decodes an opcode. */
typedef struct TPScpuBus {
    void *opaque;
    int (*guard_code)(void *opaque, const TPScpuState *cpu, uint32_t address,
                      const uint8_t *expected, size_t count);
    int (*read8)(void *opaque, const TPScpuState *cpu,
                 uint32_t address, uint8_t *value);
    int (*write8)(void *opaque, const TPScpuState *cpu,
                  uint32_t address, uint8_t value);
    int (*finish_instruction)(void *opaque, const TPScpuState *cpu,
                              uint32_t *cycles);
} TPScpuBus;

uint32_t tp_scpu_context_key(const TPScpuState *cpu);
uint32_t tp_scpu_address(const TPScpuState *cpu);
int tp_scpu_validate_state(const TPScpuState *cpu);
TPScpuExecResult tp_scpu_stop(TPScpuState *cpu, uint32_t address,
                              const char *reason);
TPScpuExecResult tp_scpu_guard_code(TPScpuState *cpu, const TPScpuBus *bus,
                                    uint32_t address, const uint8_t *bytes,
                                    size_t count);
TPScpuExecResult tp_scpu_read8(TPScpuState *cpu, const TPScpuBus *bus,
                               uint32_t address, uint8_t *value);
TPScpuExecResult tp_scpu_write8(TPScpuState *cpu, const TPScpuBus *bus,
                                uint32_t address, uint8_t value);
TPScpuExecResult tp_scpu_read16(TPScpuState *cpu, const TPScpuBus *bus,
                                uint32_t address, uint16_t *value);
TPScpuExecResult tp_scpu_write16(TPScpuState *cpu, const TPScpuBus *bus,
                                 uint32_t address, uint16_t value);
TPScpuExecResult tp_scpu_push8(TPScpuState *cpu, const TPScpuBus *bus,
                               uint8_t value);
TPScpuExecResult tp_scpu_pull8(TPScpuState *cpu, const TPScpuBus *bus,
                               uint8_t *value);
TPScpuExecResult tp_scpu_adc(TPScpuState *cpu, uint16_t right,
                             uint32_t width);
TPScpuExecResult tp_scpu_sbc(TPScpuState *cpu, uint16_t right,
                             uint32_t width);
TPScpuExecResult tp_scpu_expect_next(TPScpuState *cpu, uint32_t expected_key);
TPScpuExecResult tp_scpu_finish(TPScpuState *cpu, const TPScpuBus *bus,
                                uint32_t cycles);

#ifdef __cplusplus
}
#endif

#endif
