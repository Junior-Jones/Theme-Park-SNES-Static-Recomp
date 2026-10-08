#include "theme_park_spc700.h"

int tp_spc_fail(TPApu *a) {
    if (a != NULL) {
        a->phase = TP_APU_FAILED;
        a->failure = TP_BUS_STOP_APUIO_UNAVAILABLE;
    }
    return 0;
}

int tp_spc_guard(TPApu *a, uint16_t pc, const uint8_t *expected, unsigned length) {
    unsigned offset;
    if (a == NULL || expected == NULL || length == 0u) return tp_spc_fail(a);
    for (offset = 0u; offset < length; ++offset) {
        uint16_t address = (uint16_t)(pc + offset);
        if (!tp_apu_aram_byte_known(a, address) || a->aram[address] != expected[offset])
            return tp_spc_fail(a);
    }
    return 1;
}

uint16_t tp_spc_dp(const TPApu *a, uint8_t address) {
    return (uint16_t)(address | ((a->spc.psw & TP_SPC_P) != 0u ? 0x0100u : 0u));
}

int tp_spc_read(TPApu *a, uint16_t address, uint8_t *value) {
    return tp_apu_smp_read(a, address, value) == TP_BUS_OK ? 1 : tp_spc_fail(a);
}

int tp_spc_write(TPApu *a, uint16_t address, uint8_t value) {
    return tp_apu_smp_write(a, address, value) == TP_BUS_OK ? 1 : tp_spc_fail(a);
}

int tp_spc_read_dp_word(TPApu *a, uint8_t address, uint16_t *value) {
    uint8_t low, high;
    if (value == NULL || !tp_spc_read(a, tp_spc_dp(a, address), &low) ||
        !tp_spc_read(a, tp_spc_dp(a, (uint8_t)(address + 1u)), &high)) return tp_spc_fail(a);
    *value = (uint16_t)(low | ((uint16_t)high << 8u));
    return 1;
}

int tp_spc_push(TPApu *a, uint8_t value) {
    if (!tp_spc_write(a, (uint16_t)(0x0100u | a->spc.sp), value)) return 0;
    a->spc.sp--;
    return 1;
}

int tp_spc_pop(TPApu *a, uint8_t *value) {
    a->spc.sp++;
    return tp_spc_read(a, (uint16_t)(0x0100u | a->spc.sp), value);
}

void tp_spc_clear_flags(TPApu *a, uint8_t flags) {
    a->spc.psw = (uint8_t)(a->spc.psw & (uint8_t)(0xFFu ^ flags));
}

void tp_spc_nz8(TPApu *a, uint8_t value) {
    tp_spc_clear_flags(a, (uint8_t)(TP_SPC_N | TP_SPC_Z));
    if (value == 0u) a->spc.psw |= TP_SPC_Z;
    if ((value & 0x80u) != 0u) a->spc.psw |= TP_SPC_N;
}

void tp_spc_nz16(TPApu *a, uint16_t value) {
    tp_spc_clear_flags(a, (uint8_t)(TP_SPC_N | TP_SPC_Z));
    if (value == 0u) a->spc.psw |= TP_SPC_Z;
    if ((value & 0x8000u) != 0u) a->spc.psw |= TP_SPC_N;
}

void tp_spc_cmp8(TPApu *a, uint8_t left, uint8_t right) {
    tp_spc_clear_flags(a, TP_SPC_C);
    if (left >= right) a->spc.psw |= TP_SPC_C;
    tp_spc_nz8(a, (uint8_t)(left - right));
}

uint8_t tp_spc_adc8(TPApu *a, uint8_t left, uint8_t right) {
    uint8_t carry = (uint8_t)((a->spc.psw & TP_SPC_C) != 0u);
    uint16_t sum = (uint16_t)left + right + carry;
    uint8_t result = (uint8_t)sum;
    tp_spc_clear_flags(a, (uint8_t)(TP_SPC_C | TP_SPC_H | TP_SPC_V));
    if (sum > 0xFFu) a->spc.psw |= TP_SPC_C;
    if ((left & 0x0Fu) + (right & 0x0Fu) + carry > 0x0Fu) a->spc.psw |= TP_SPC_H;
    if (((uint8_t)~(left ^ right) & (left ^ result) & 0x80u) != 0u) a->spc.psw |= TP_SPC_V;
    tp_spc_nz8(a, result);
    return result;
}

uint8_t tp_spc_sbc8(TPApu *a, uint8_t left, uint8_t right) {
    uint8_t borrow = (uint8_t)((a->spc.psw & TP_SPC_C) == 0u);
    int difference = (int)left - (int)right - (int)borrow;
    uint8_t result = (uint8_t)difference;
    tp_spc_clear_flags(a, (uint8_t)(TP_SPC_C | TP_SPC_H | TP_SPC_V));
    if (difference >= 0) a->spc.psw |= TP_SPC_C;
    if ((int)(left & 0x0Fu) - (int)(right & 0x0Fu) - (int)borrow >= 0) a->spc.psw |= TP_SPC_H;
    if (((left ^ right) & (left ^ result) & 0x80u) != 0u) a->spc.psw |= TP_SPC_V;
    tp_spc_nz8(a, result);
    return result;
}

uint16_t tp_spc_addw(TPApu *a, uint16_t left, uint16_t right) {
    uint32_t sum = (uint32_t)left + right;
    uint16_t result = (uint16_t)sum;
    tp_spc_clear_flags(a, (uint8_t)(TP_SPC_C | TP_SPC_H | TP_SPC_V));
    if (sum > 0xFFFFu) a->spc.psw |= TP_SPC_C;
    if ((left & 0x0FFFu) + (right & 0x0FFFu) > 0x0FFFu) a->spc.psw |= TP_SPC_H;
    if (((uint16_t)~(left ^ right) & (left ^ result) & 0x8000u) != 0u) a->spc.psw |= TP_SPC_V;
    tp_spc_nz16(a, result);
    return result;
}

uint8_t tp_spc_asl8(TPApu *a, uint8_t value) {
    tp_spc_clear_flags(a, TP_SPC_C);
    if ((value & 0x80u) != 0u) a->spc.psw |= TP_SPC_C;
    value = (uint8_t)(value << 1u); tp_spc_nz8(a, value); return value;
}

uint8_t tp_spc_lsr8(TPApu *a, uint8_t value) {
    tp_spc_clear_flags(a, TP_SPC_C);
    if ((value & 1u) != 0u) a->spc.psw |= TP_SPC_C;
    value >>= 1u; tp_spc_nz8(a, value); return value;
}

uint8_t tp_spc_rol8(TPApu *a, uint8_t value) {
    uint8_t carry = (uint8_t)((a->spc.psw & TP_SPC_C) != 0u);
    tp_spc_clear_flags(a, TP_SPC_C);
    if ((value & 0x80u) != 0u) a->spc.psw |= TP_SPC_C;
    value = (uint8_t)((value << 1u) | carry); tp_spc_nz8(a, value); return value;
}

uint8_t tp_spc_ror8(TPApu *a, uint8_t value) {
    uint8_t carry = (uint8_t)((a->spc.psw & TP_SPC_C) != 0u);
    tp_spc_clear_flags(a, TP_SPC_C);
    if ((value & 1u) != 0u) a->spc.psw |= TP_SPC_C;
    value = (uint8_t)((value >> 1u) | (carry << 7u)); tp_spc_nz8(a, value); return value;
}
