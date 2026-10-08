#ifndef THEME_PARK_SPC700_AOT_H
#define THEME_PARK_SPC700_AOT_H
#include <stdint.h>
#include "theme_park_apu.h"
int tp_spc700_aot_begin(TPApu *apu);
int tp_spc700_aot_complete(TPApu *apu);
int tp_spc700_aot_code_byte(uint16_t address);
#endif
