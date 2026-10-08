#ifndef THEME_PARK_INPUT_H
#define THEME_PARK_INPUT_H

#include <stdint.h>

#include "theme_park_bus.h"
#include "theme_park_scheduler.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TP_INPUT_STANDARD_PAD_MASK 0xFFF0u

typedef struct TPInput {
    TPBus *bus;
    uint16_t live_pad[2];
    uint16_t serial_shift[2];
    uint16_t auto_result[4];
    uint8_t sampled_serial[4];
    uint8_t cpu_strobe;
    uint8_t auto_strobe;
    uint8_t effective_strobe;
    uint64_t serial_reads[2];
    uint64_t autojoy_samples;
    uint64_t report_sequence;
} TPInput;

/* state uses the native JOY register layout: B at bit 15 through R at bit 4. */
void tp_input_power_on(TPInput *input, TPBus *bus);
void tp_input_cpu_reset(TPInput *input);
void tp_input_set_standard_pad(TPInput *input, unsigned port, uint16_t state);
uint16_t tp_input_auto_result(const TPInput *input, unsigned index);
TPBusStop tp_input_bus_read(void *opaque, uint16_t reg, uint8_t *value);
TPBusStop tp_input_bus_write(void *opaque, uint16_t reg, uint8_t value);
TPSchedulerStop tp_input_autojoy_phase(void *opaque, uint8_t phase, uint8_t enabled);

#ifdef __cplusplus
}
#endif

#endif
