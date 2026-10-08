#ifndef THEME_PARK_SPC700_H
#define THEME_PARK_SPC700_H

#include <stdint.h>

#include "theme_park_apu.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TP_SPC_C 0x01u
#define TP_SPC_Z 0x02u
#define TP_SPC_I 0x04u
#define TP_SPC_H 0x08u
#define TP_SPC_B 0x10u
#define TP_SPC_P 0x20u
#define TP_SPC_V 0x40u
#define TP_SPC_N 0x80u

int tp_spc_fail(TPApu *apu);
int tp_spc_guard(TPApu *apu, uint16_t pc, const uint8_t *expected, unsigned length);
uint16_t tp_spc_dp(const TPApu *apu, uint8_t address);
int tp_spc_read(TPApu *apu, uint16_t address, uint8_t *value);
int tp_spc_write(TPApu *apu, uint16_t address, uint8_t value);
int tp_spc_read_dp_word(TPApu *apu, uint8_t address, uint16_t *value);
int tp_spc_push(TPApu *apu, uint8_t value);
int tp_spc_pop(TPApu *apu, uint8_t *value);
void tp_spc_clear_flags(TPApu *apu, uint8_t flags);
void tp_spc_nz8(TPApu *apu, uint8_t value);
void tp_spc_nz16(TPApu *apu, uint16_t value);
void tp_spc_cmp8(TPApu *apu, uint8_t left, uint8_t right);
uint8_t tp_spc_adc8(TPApu *apu, uint8_t left, uint8_t right);
uint8_t tp_spc_sbc8(TPApu *apu, uint8_t left, uint8_t right);
uint16_t tp_spc_addw(TPApu *apu, uint16_t left, uint16_t right);
uint8_t tp_spc_asl8(TPApu *apu, uint8_t value);
uint8_t tp_spc_lsr8(TPApu *apu, uint8_t value);
uint8_t tp_spc_rol8(TPApu *apu, uint8_t value);
uint8_t tp_spc_ror8(TPApu *apu, uint8_t value);

#ifdef __cplusplus
}
#endif

#endif
