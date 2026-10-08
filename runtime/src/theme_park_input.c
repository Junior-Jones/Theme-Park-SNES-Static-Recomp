#include "theme_park_input.h"

#include <string.h>

static void tp_input_latch(TPInput *in) {
    in->serial_shift[0] = in->live_pad[0];
    in->serial_shift[1] = in->live_pad[1];
}

static void tp_input_update_strobe(TPInput *in) {
    in->effective_strobe = (uint8_t)((in->cpu_strobe | in->auto_strobe) & 1u);
    if (in->effective_strobe != 0u) tp_input_latch(in);
}

static uint8_t tp_input_serial(TPInput *in, unsigned port) {
    uint8_t bit;
    if (in->effective_strobe != 0u) tp_input_latch(in);
    bit = (uint8_t)((in->serial_shift[port] >> 15u) & 1u);
    if (in->effective_strobe == 0u)
        in->serial_shift[port] = (uint16_t)((in->serial_shift[port] << 1u) | 1u);
    in->serial_reads[port]++;
    return bit;
}

void tp_input_power_on(TPInput *in, TPBus *bus) {
    if (in == NULL) return;
    memset(in, 0, sizeof(*in));
    in->bus = bus;
    tp_input_latch(in);
}

void tp_input_cpu_reset(TPInput *in) {
    TPBus *bus;
    uint16_t live0, live1;
    uint64_t sequence;
    if (in == NULL) return;
    bus = in->bus;
    live0 = in->live_pad[0];
    live1 = in->live_pad[1];
    sequence = in->report_sequence;
    memset(in, 0, sizeof(*in));
    in->bus = bus;
    in->live_pad[0] = live0;
    in->live_pad[1] = live1;
    in->report_sequence = sequence;
    tp_input_latch(in);
}

void tp_input_set_standard_pad(TPInput *in, unsigned port, uint16_t state) {
    if (in == NULL || port >= 2u) return;
    in->live_pad[port] = (uint16_t)(state & TP_INPUT_STANDARD_PAD_MASK);
    in->report_sequence++;
    if (in->effective_strobe != 0u) tp_input_latch(in);
}

uint16_t tp_input_auto_result(const TPInput *in, unsigned index) {
    return in != NULL && index < 4u ? in->auto_result[index] : 0u;
}

TPBusStop tp_input_bus_read(void *opaque, uint16_t reg, uint8_t *value) {
    TPInput *in = (TPInput *)opaque;
    uint8_t open_bus;
    if (in == NULL || value == NULL || in->bus == NULL) return TP_BUS_STOP_ARGUMENT;
    if (reg >= 0x4218u && reg <= 0x421Fu) {
        unsigned index = (unsigned)((reg - 0x4218u) >> 1u);
        uint16_t result = in->auto_result[index];
        *value = (uint8_t)(((reg & 1u) != 0u) ? (result >> 8u) : result);
        return TP_BUS_OK;
    }
    if (reg != 0x4016u && reg != 0x4017u) return TP_BUS_STOP_INPUT_UNAVAILABLE;
    if (in->bus->open_bus_known == 0u) return TP_BUS_STOP_UNKNOWN_OPEN_BUS;
    open_bus = in->bus->open_bus;
    if (reg == 0x4016u)
        *value = (uint8_t)((open_bus & 0xFCu) | tp_input_serial(in, 0u));
    else
        *value = (uint8_t)((open_bus & 0xE0u) | 0x1Cu | tp_input_serial(in, 1u));
    return TP_BUS_OK;
}

TPBusStop tp_input_bus_write(void *opaque, uint16_t reg, uint8_t value) {
    TPInput *in = (TPInput *)opaque;
    if (in == NULL) return TP_BUS_STOP_ARGUMENT;
    if (reg != 0x4016u) return TP_BUS_STOP_INPUT_UNAVAILABLE;
    in->cpu_strobe = (uint8_t)(value & 1u);
    tp_input_update_strobe(in);
    return TP_BUS_OK;
}

TPSchedulerStop tp_input_autojoy_phase(void *opaque, uint8_t phase, uint8_t enabled) {
    TPInput *in = (TPInput *)opaque;
    unsigned port;
    if (in == NULL) return TP_SCHEDULER_STOP_INPUT_UNAVAILABLE;
    if (enabled == 0u) {
        in->auto_strobe = 0u;
        tp_input_update_strobe(in);
        return TP_SCHEDULER_OK;
    }
    if (phase == 0u) {
        in->auto_strobe = 1u;
        tp_input_update_strobe(in);
    } else if (phase == 1u) {
        memset(in->auto_result, 0, sizeof(in->auto_result));
    } else if (phase == 2u) {
        in->auto_strobe = 0u;
        tp_input_update_strobe(in);
    } else if (phase >= 3u && phase <= 34u) {
        if ((phase & 1u) != 0u) {
            in->sampled_serial[0] = tp_input_serial(in, 0u);
            in->sampled_serial[1] = tp_input_serial(in, 1u);
            in->sampled_serial[2] = 0u;
            in->sampled_serial[3] = 0u;
            in->autojoy_samples++;
        } else {
            for (port = 0u; port < 4u; ++port)
                in->auto_result[port] = (uint16_t)((in->auto_result[port] << 1u) |
                                                   (in->sampled_serial[port] & 1u));
        }
    }
    return TP_SCHEDULER_OK;
}
