#include "theme_park_scpu.h"

static void tp_copy_reason(char *destination, size_t capacity, const char *source) {
    size_t index = 0u;
    if (capacity == 0u) {
        return;
    }
    if (source != NULL) {
        while (index + 1u < capacity && source[index] != '\0') {
            destination[index] = source[index];
            ++index;
        }
    }
    destination[index] = '\0';
}

uint32_t tp_scpu_context_key(const TPScpuState *cpu) {
    const uint32_t m = (cpu->p & TP_P_M) != 0u ? 1u : 0u;
    const uint32_t x = (cpu->p & TP_P_X) != 0u ? 1u : 0u;
    return ((uint32_t)cpu->pbr << 19u) | ((uint32_t)cpu->pc << 3u)
        | ((uint32_t)cpu->e << 2u) | (m << 1u) | x;
}

uint32_t tp_scpu_address(const TPScpuState *cpu) {
    return ((uint32_t)cpu->pbr << 16u) | (uint32_t)cpu->pc;
}

int tp_scpu_validate_state(const TPScpuState *cpu) {
    if (cpu == NULL || cpu->e > 1u) {
        return 0;
    }
    if (cpu->e != 0u && (cpu->p & (TP_P_M | TP_P_X)) != (TP_P_M | TP_P_X)) {
        return 0;
    }
    if ((cpu->p & TP_P_X) != 0u && ((cpu->x | cpu->y) & 0xFF00u) != 0u) {
        return 0;
    }
    if (cpu->e != 0u && (cpu->s & 0xFF00u) != 0x0100u) {
        return 0;
    }
    return 1;
}

TPScpuExecResult tp_scpu_stop(TPScpuState *cpu, uint32_t address,
                              const char *reason) {
    if (cpu != NULL) {
        cpu->failure.failed = 1u;
        cpu->failure.context_key = tp_scpu_context_key(cpu);
        cpu->failure.address = address & 0xFFFFFFu;
        tp_copy_reason(cpu->failure.reason, sizeof(cpu->failure.reason), reason);
    }
    return TP_SCPU_STOPPED;
}

TPScpuExecResult tp_scpu_guard_code(TPScpuState *cpu, const TPScpuBus *bus,
                                    uint32_t address, const uint8_t *bytes,
                                    size_t count) {
    if (bus == NULL || bus->guard_code == NULL || bytes == NULL || count == 0u) {
        return tp_scpu_stop(cpu, address, "MISSING_CODE_GUARD_OWNER");
    }
    if (bus->guard_code(bus->opaque, cpu, address & 0xFFFFFFu, bytes, count) == 0) {
        return tp_scpu_stop(cpu, address, "SOURCE_BYTE_GUARD_MISMATCH");
    }
    return TP_SCPU_EXECUTED;
}

TPScpuExecResult tp_scpu_read8(TPScpuState *cpu, const TPScpuBus *bus,
                               uint32_t address, uint8_t *value) {
    if (bus == NULL || bus->read8 == NULL || value == NULL) {
        return tp_scpu_stop(cpu, address, "MISSING_READ8_OWNER");
    }
    if (bus->read8(bus->opaque, cpu, address & 0xFFFFFFu, value) == 0) {
        return tp_scpu_stop(cpu, address, "UNOWNED_OR_FAILED_READ8");
    }
    return TP_SCPU_EXECUTED;
}

TPScpuExecResult tp_scpu_write8(TPScpuState *cpu, const TPScpuBus *bus,
                                uint32_t address, uint8_t value) {
    if (bus == NULL || bus->write8 == NULL) {
        return tp_scpu_stop(cpu, address, "MISSING_WRITE8_OWNER");
    }
    if (bus->write8(bus->opaque, cpu, address & 0xFFFFFFu, value) == 0) {
        return tp_scpu_stop(cpu, address, "UNOWNED_OR_FAILED_WRITE8");
    }
    return TP_SCPU_EXECUTED;
}

TPScpuExecResult tp_scpu_read16(TPScpuState *cpu, const TPScpuBus *bus,
                                uint32_t address, uint16_t *value) {
    uint8_t low = 0u;
    uint8_t high = 0u;
    if (value == NULL) {
        return tp_scpu_stop(cpu, address, "MISSING_READ16_DESTINATION");
    }
    if (tp_scpu_read8(cpu, bus, address, &low) != TP_SCPU_EXECUTED ||
        tp_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != TP_SCPU_EXECUTED) {
        return TP_SCPU_STOPPED;
    }
    *value = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
    return TP_SCPU_EXECUTED;
}

TPScpuExecResult tp_scpu_write16(TPScpuState *cpu, const TPScpuBus *bus,
                                 uint32_t address, uint16_t value) {
    if (tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED ||
        tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu,
                       (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED) {
        return TP_SCPU_STOPPED;
    }
    return TP_SCPU_EXECUTED;
}

TPScpuExecResult tp_scpu_push8(TPScpuState *cpu, const TPScpuBus *bus,
                               uint8_t value) {
    if (tp_scpu_write8(cpu, bus, (uint32_t)cpu->s, value) != TP_SCPU_EXECUTED) {
        return TP_SCPU_STOPPED;
    }
    cpu->s = cpu->e != 0u
        ? (uint16_t)(0x0100u | ((cpu->s - 1u) & 0x00FFu))
        : (uint16_t)(cpu->s - 1u);
    return TP_SCPU_EXECUTED;
}

TPScpuExecResult tp_scpu_pull8(TPScpuState *cpu, const TPScpuBus *bus,
                               uint8_t *value) {
    cpu->s = cpu->e != 0u
        ? (uint16_t)(0x0100u | ((cpu->s + 1u) & 0x00FFu))
        : (uint16_t)(cpu->s + 1u);
    return tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, value);
}

TPScpuExecResult tp_scpu_adc(TPScpuState *cpu, uint16_t right,
                             uint32_t width) {
    const uint32_t mask = width == 8u ? 0xFFu : width == 16u ? 0xFFFFu : 0u;
    const uint32_t sign = width == 8u ? 0x80u : width == 16u ? 0x8000u : 0u;
    const uint32_t left = (uint32_t)cpu->a & mask;
    const uint32_t carry = (cpu->p & TP_P_C) != 0u ? 1u : 0u;
    const uint32_t binary_total = left + ((uint32_t)right & mask) + carry;
    const uint32_t binary_value = binary_total & mask;
    uint32_t value = binary_value;
    uint32_t result_carry = binary_total > mask ? 1u : 0u;
    uint32_t shift;
    if (mask == 0u || ((uint32_t)right & ~mask) != 0u) {
        return tp_scpu_stop(cpu, tp_scpu_address(cpu), "INVALID_ADC_WIDTH_OR_OPERAND");
    }
    if ((cpu->p & TP_P_D) != 0u) {
        uint32_t digit_carry = carry;
        value = 0u;
        for (shift = 0u; shift < width; shift += 4u) {
            uint32_t a_digit = (left >> shift) & 0x0Fu;
            uint32_t b_digit = ((uint32_t)right >> shift) & 0x0Fu;
            uint32_t digit;
            if (a_digit > 9u || b_digit > 9u) {
                return tp_scpu_stop(cpu, tp_scpu_address(cpu),
                                    "UNPROVED_INVALID_PACKED_BCD_ADC");
            }
            digit = a_digit + b_digit + digit_carry;
            if (digit > 9u) digit += 6u;
            digit_carry = digit > 0x0Fu ? 1u : 0u;
            value |= (digit & 0x0Fu) << shift;
        }
        result_carry = digit_carry;
    }
    cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_V | TP_P_Z | TP_P_C));
    if (result_carry != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
    if ((value & mask) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
    if ((value & sign) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
    if (((~(left ^ (uint32_t)right) & (left ^ binary_value)) & sign) != 0u)
        cpu->p = (uint8_t)(cpu->p | TP_P_V);
    if (width == 8u)
        cpu->a = (uint16_t)((cpu->a & 0xFF00u) | (uint16_t)(value & 0xFFu));
    else
        cpu->a = (uint16_t)value;
    return TP_SCPU_EXECUTED;
}

TPScpuExecResult tp_scpu_sbc(TPScpuState *cpu, uint16_t right,
                             uint32_t width) {
    const uint32_t mask = width == 8u ? 0xFFu : width == 16u ? 0xFFFFu : 0u;
    const uint32_t sign = width == 8u ? 0x80u : width == 16u ? 0x8000u : 0u;
    const uint32_t left = (uint32_t)cpu->a & mask;
    const uint32_t carry = (cpu->p & TP_P_C) != 0u ? 1u : 0u;
    const uint32_t borrow_in = 1u - carry;
    const uint32_t binary_value = (left - ((uint32_t)right & mask) - borrow_in) & mask;
    uint32_t value = binary_value;
    uint32_t result_carry = left >= (((uint32_t)right & mask) + borrow_in) ? 1u : 0u;
    uint32_t shift;
    if (mask == 0u || ((uint32_t)right & ~mask) != 0u) {
        return tp_scpu_stop(cpu, tp_scpu_address(cpu), "INVALID_SBC_WIDTH_OR_OPERAND");
    }
    if ((cpu->p & TP_P_D) != 0u) {
        int32_t borrow = (int32_t)borrow_in;
        value = 0u;
        for (shift = 0u; shift < width; shift += 4u) {
            const uint32_t a_digit = (left >> shift) & 0x0Fu;
            const uint32_t b_digit = ((uint32_t)right >> shift) & 0x0Fu;
            int32_t digit;
            if (a_digit > 9u || b_digit > 9u) {
                return tp_scpu_stop(cpu, tp_scpu_address(cpu),
                                    "UNPROVED_INVALID_PACKED_BCD_SBC");
            }
            digit = (int32_t)a_digit - (int32_t)b_digit - borrow;
            if (digit < 0) {
                digit -= 6;
                borrow = 1;
            } else {
                borrow = 0;
            }
            value |= ((uint32_t)digit & 0x0Fu) << shift;
        }
        result_carry = borrow == 0 ? 1u : 0u;
    }
    cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_V | TP_P_Z | TP_P_C));
    if (result_carry != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
    if ((value & mask) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
    if ((value & sign) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
    if ((((left ^ (uint32_t)right) & (left ^ binary_value)) & sign) != 0u)
        cpu->p = (uint8_t)(cpu->p | TP_P_V);
    if (width == 8u)
        cpu->a = (uint16_t)((cpu->a & 0xFF00u) | (uint16_t)(value & 0xFFu));
    else
        cpu->a = (uint16_t)value;
    return TP_SCPU_EXECUTED;
}

TPScpuExecResult tp_scpu_expect_next(TPScpuState *cpu, uint32_t expected_key) {
    if (tp_scpu_context_key(cpu) != expected_key) {
        return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_SUCCESSOR_CONTEXT");
    }
    return TP_SCPU_EXECUTED;
}

TPScpuExecResult tp_scpu_finish(TPScpuState *cpu, const TPScpuBus *bus,
                                uint32_t cycles) {
    if (bus == NULL || bus->finish_instruction == NULL ||
        bus->finish_instruction(bus->opaque, cpu, &cycles) == 0) {
        return tp_scpu_stop(cpu, tp_scpu_address(cpu),
                            "TIMING_PLAN_MISMATCH_OR_UNAVAILABLE");
    }
    cpu->completed_cycles += (uint64_t)cycles;
    return TP_SCPU_EXECUTED;
}
