#include "theme_park_sdsp.h"

#include <limits.h>
#include <string.h>

/* Fixed S-DSP interpolation coefficients.  These are architectural hardware
   data, transcribed independently from the CC-BY-4.0 SnesLab coefficient
   census (S-DSP/Gaussian Filter, oldid 11666), not from another recomp. */
static const uint16_t tp_gaussian[512] = {
0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,
1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,2u,2u,2u,2u,2u,
2u,2u,3u,3u,3u,3u,3u,4u,4u,4u,4u,4u,5u,5u,5u,5u,
6u,6u,6u,6u,7u,7u,7u,8u,8u,8u,9u,9u,9u,10u,10u,10u,
11u,11u,11u,12u,12u,13u,13u,14u,14u,15u,15u,15u,16u,16u,17u,17u,
18u,19u,19u,20u,20u,21u,21u,22u,23u,23u,24u,24u,25u,26u,27u,27u,
28u,29u,29u,30u,31u,32u,32u,33u,34u,35u,36u,36u,37u,38u,39u,40u,
41u,42u,43u,44u,45u,46u,47u,48u,49u,50u,51u,52u,53u,54u,55u,56u,
58u,59u,60u,61u,62u,64u,65u,66u,67u,69u,70u,71u,73u,74u,76u,77u,
78u,80u,81u,83u,84u,86u,87u,89u,90u,92u,94u,95u,97u,99u,100u,102u,
104u,106u,107u,109u,111u,113u,115u,117u,118u,120u,122u,124u,126u,128u,130u,132u,
134u,137u,139u,141u,143u,145u,147u,150u,152u,154u,156u,159u,161u,163u,166u,168u,
171u,173u,175u,178u,180u,183u,186u,188u,191u,193u,196u,199u,201u,204u,207u,210u,
212u,215u,218u,221u,224u,227u,230u,233u,236u,239u,242u,245u,248u,251u,254u,257u,
260u,263u,267u,270u,273u,276u,280u,283u,286u,290u,293u,297u,300u,304u,307u,311u,
314u,318u,321u,325u,328u,332u,336u,339u,343u,347u,351u,354u,358u,362u,366u,370u,
374u,378u,381u,385u,389u,393u,397u,401u,405u,410u,414u,418u,422u,426u,430u,434u,
439u,443u,447u,451u,456u,460u,464u,469u,473u,477u,482u,486u,491u,495u,499u,504u,
508u,513u,517u,522u,527u,531u,536u,540u,545u,550u,554u,559u,563u,568u,573u,577u,
582u,587u,592u,596u,601u,606u,611u,615u,620u,625u,630u,635u,640u,644u,649u,654u,
659u,664u,669u,674u,678u,683u,688u,693u,698u,703u,708u,713u,718u,723u,728u,732u,
737u,742u,747u,752u,757u,762u,767u,772u,777u,782u,787u,792u,797u,802u,806u,811u,
816u,821u,826u,831u,836u,841u,846u,851u,855u,860u,865u,870u,875u,880u,884u,889u,
894u,899u,904u,908u,913u,918u,923u,927u,932u,937u,941u,946u,951u,955u,960u,965u,
969u,974u,978u,983u,988u,992u,997u,1001u,1005u,1010u,1014u,1019u,1023u,1027u,1032u,1036u,
1040u,1045u,1049u,1053u,1057u,1061u,1066u,1070u,1074u,1078u,1082u,1086u,1090u,1094u,1098u,1102u,
1106u,1109u,1113u,1117u,1121u,1125u,1128u,1132u,1136u,1139u,1143u,1146u,1150u,1153u,1157u,1160u,
1164u,1167u,1170u,1174u,1177u,1180u,1183u,1186u,1190u,1193u,1196u,1199u,1202u,1205u,1207u,1210u,
1213u,1216u,1219u,1221u,1224u,1227u,1229u,1232u,1234u,1237u,1239u,1241u,1244u,1246u,1248u,1251u,
1253u,1255u,1257u,1259u,1261u,1263u,1265u,1267u,1269u,1270u,1272u,1274u,1275u,1277u,1279u,1280u,
1282u,1283u,1284u,1286u,1287u,1288u,1290u,1291u,1292u,1293u,1294u,1295u,1296u,1297u,1297u,1298u,
1299u,1300u,1300u,1301u,1302u,1302u,1303u,1303u,1303u,1304u,1304u,1304u,1304u,1304u,1305u,1305u
};

static int tp_bit_get(const uint8_t *bits, uint16_t address) {
    return bits != NULL && (bits[address >> 3u] &
        (uint8_t)(1u << (address & 7u))) != 0u;
}

static void tp_bit_put(uint8_t *bits, uint16_t address, int known) {
    uint8_t mask;
    if (bits == NULL) return;
    mask = (uint8_t)(1u << (address & 7u));
    if (known) bits[address >> 3u] |= mask;
    else bits[address >> 3u] &= (uint8_t)~mask;
}

static int16_t tp_clamp16(int32_t value) {
    if (value > INT16_MAX) return INT16_MAX;
    if (value < INT16_MIN) return INT16_MIN;
    return (int16_t)value;
}

static int32_t tp_arshift(int32_t value, unsigned shift) {
    int64_t magnitude;
    if (shift == 0u) return value;
    if (value >= 0) return value >> shift;
    magnitude = -(int64_t)value;
    return (int32_t)-((magnitude + (((int64_t)1 << shift) - 1)) >> shift);
}

static int16_t tp_even16(int32_t value) {
    uint16_t bits = (uint16_t)tp_clamp16(value);
    return (int16_t)(bits & UINT16_C(0xFFFE));
}

static uint8_t tp_reg(TPSdsp *d, uint8_t address) {
    return d->registers[address & 0x7Fu];
}

static void tp_reg_set(TPSdsp *d, uint8_t address, uint8_t value) {
    address &= 0x7Fu;
    d->registers[address] = value;
    d->register_known[address >> 3u] |= (uint8_t)(1u << (address & 7u));
}

static void tp_reg_set_known(TPSdsp *d, uint8_t address, uint8_t value,
                             uint8_t known) {
    address &= 0x7Fu;
    d->registers[address] = value;
    tp_bit_put(d->register_known, address, known != 0u);
}

static uint8_t tp_aram_read(TPSdsp *d, uint16_t address, uint8_t *known) {
    int k = tp_bit_get(d->aram_known, address);
    d->aram_reads++;
    if (known != NULL) *known = (uint8_t)k;
    return k && d->aram != NULL ? d->aram[address] : 0u;
}

static void tp_aram_write(TPSdsp *d, uint16_t address, uint8_t value,
                          uint8_t known) {
    if (d->aram != NULL) d->aram[address] = value;
    tp_bit_put(d->aram_known, address, known != 0u);
    d->aram_writes++;
}

static int tp_rate_event(const TPSdsp *d, unsigned rate) {
    static const uint16_t period[32] = {
        UINT16_MAX,2048u,1536u,1280u,1024u,768u,640u,512u,
        384u,320u,256u,192u,160u,128u,96u,80u,
        64u,48u,40u,32u,24u,20u,16u,12u,10u,8u,6u,5u,4u,3u,2u,1u
    };
    static const uint16_t offset[32] = {
        1u,0u,1040u,536u,0u,1040u,536u,0u,
        1040u,536u,0u,1040u,536u,0u,1040u,536u,
        0u,1040u,536u,0u,1040u,536u,0u,1040u,
        536u,0u,1040u,536u,0u,1040u,0u,0u
    };
    rate &= 31u;
    return (uint16_t)(d->counter + offset[rate]) % period[rate] == 0u;
}

static int16_t tp_interpolate(const TPSdspVoice *v, uint8_t *known) {
    unsigned fraction = (v->interpolation_position >> 4u) & 0xFFu;
    unsigned first = (unsigned)((v->buffer_position +
        (v->interpolation_position >> 12u)) % 12u);
    unsigned index[4] = {first,(first+1u)%12u,(first+2u)%12u,(first+3u)%12u};
    unsigned coefficient[4] = {255u-fraction,511u-fraction,256u+fraction,fraction};
    int32_t out = 0;
    unsigned i;
    uint8_t k = v->interpolation_known;
    for (i = 0u; i < 4u; ++i) {
        uint16_t c = tp_gaussian[coefficient[i]];
        if (c != 0u && v->sample_known[index[i]] == 0u) k = 0u;
        out += tp_arshift((int32_t)c * v->sample[index[i]], 11u);
        if (i == 2u) out = (int16_t)out;
    }
    if (known != NULL) *known = k;
    return tp_even16(out);
}

static void tp_decode_brr_group(TPSdsp *d, TPSdspVoice *v) {
    uint8_t next_known = 0u;
    uint8_t next = tp_aram_read(d,
        (uint16_t)(v->brr_address + v->brr_offset + 1u), &next_known);
    uint8_t bytes_known = (uint8_t)(v->brr_address_known && d->brr_header_known &&
        d->brr_data_known && next_known);
    uint8_t packed[2] = {d->brr_data,next};
    int32_t previous1 = v->sample[v->buffer_position != 0u ?
        v->buffer_position - 1u : 11u] / 2;
    int32_t previous2 = v->sample[v->buffer_position > 1u ?
        v->buffer_position - 2u : 10u] / 2;
    uint8_t previous1_known = v->sample_known[v->buffer_position != 0u ?
        v->buffer_position - 1u : 11u];
    uint8_t previous2_known = v->sample_known[v->buffer_position > 1u ?
        v->buffer_position - 2u : 10u];
    unsigned shift = d->brr_header >> 4u;
    unsigned filter = (d->brr_header >> 2u) & 3u;
    unsigned i;
    for (i = 0u; i < 4u; ++i) {
        uint8_t nibble = (uint8_t)((packed[i >> 1u] >> ((i & 1u) ? 0u : 4u)) & 0x0Fu);
        int32_t signed_nibble = nibble < 8u ? (int32_t)nibble : (int32_t)nibble - 16;
        /* BRR RD rounds negative odd values down, not toward zero. */
        int32_t sample = shift <= 12u ? tp_arshift(signed_nibble * (int32_t)(1u << shift), 1u) :
            (signed_nibble < 0 ? -2048 : 0);
        if (filter == 1u) sample += previous1 + tp_arshift(-previous1, 4u);
        else if (filter == 2u)
            sample += previous1 * 2 + tp_arshift(-(previous1 * 3), 5u) -
                previous2 + tp_arshift(previous2, 4u);
        else if (filter == 3u)
            sample += previous1 * 2 + tp_arshift(-(previous1 * 13), 6u) -
                previous2 + tp_arshift(previous2 * 3, 4u);
        uint8_t sample_known = bytes_known;
        if (filter == 1u) sample_known &= previous1_known;
        else if (filter >= 2u) sample_known &= (uint8_t)(previous1_known && previous2_known);
        v->sample[(v->buffer_position + i) % 12u] =
            (int16_t)(tp_clamp16(sample) * 2);
        v->sample_known[(v->buffer_position + i) % 12u] = sample_known;
        previous2 = previous1;
        previous2_known = previous1_known;
        previous1 = v->sample[(v->buffer_position + i) % 12u] / 2;
        previous1_known = sample_known;
    }
    v->buffer_position = (uint8_t)((v->buffer_position + 4u) % 12u);
}

static void tp_envelope(TPSdsp *d, TPSdspVoice *v, unsigned number) {
    uint8_t base = (uint8_t)(number << 4u);
    int32_t next = v->envelope;
    unsigned rate = 0u;
    if (v->envelope_mode == TP_SDSP_ENV_RELEASE) {
        next -= 8;
        v->envelope = next < 0 ? 0 : next;
        return;
    }
    if ((d->adsr1 & 0x80u) != 0u) {
        uint8_t adsr2 = tp_reg(d, (uint8_t)(base + 6u));
        if (v->envelope_mode == TP_SDSP_ENV_ATTACK) {
            rate = ((unsigned)(d->adsr1 & 0x0Fu) << 1u) | 1u;
            next += rate == 31u ? 1024 : 32;
        } else {
            next -= ((next - 1) >> 8u) + 1;
            rate = v->envelope_mode == TP_SDSP_ENV_DECAY ?
                (((unsigned)(d->adsr1 >> 3u) & 0x0Eu) | 0x10u) :
                (adsr2 & 0x1Fu);
            if (v->envelope_mode == TP_SDSP_ENV_DECAY &&
                (next >> 8u) == (adsr2 >> 5u)) v->envelope_mode = TP_SDSP_ENV_SUSTAIN;
        }
    } else {
        uint8_t gain = tp_reg(d, (uint8_t)(base + 7u));
        if ((gain & 0x80u) == 0u) {
            next = (int32_t)gain << 4u;
            rate = 31u;
        } else {
            rate = gain & 0x1Fu;
            switch (gain & 0x60u) {
                case 0x00u: next -= 32; break;
                case 0x20u: next -= ((next - 1) >> 8u) + 1; break;
                case 0x40u: next += 32; break;
                default: next += v->calculated_envelope < 0x600 ? 32 : 8; break;
            }
        }
    }
    v->calculated_envelope = next;
    if (next < 0) next = 0;
    if (next > 0x7FF) {
        next = 0x7FF;
        if (v->envelope_mode == TP_SDSP_ENV_ATTACK)
            v->envelope_mode = TP_SDSP_ENV_DECAY;
    }
    if (tp_rate_event(d, rate)) v->envelope = next;
}

static void tp_mix_voice(TPSdsp *d, unsigned number, unsigned channel) {
    int8_t volume = (int8_t)tp_reg(d,
        (uint8_t)((number << 4u) + channel));
    int32_t contribution = tp_arshift(d->current_voice_output * volume, 7u);
    uint8_t known = (uint8_t)(volume == 0 || d->current_voice_known);
    d->dry_mix[channel] = tp_clamp16(d->dry_mix[channel] + contribution);
    d->dry_mix_known[channel] &= known;
    if ((d->echo_voice_latch & (uint8_t)(1u << number)) != 0u) {
        d->echo_mix[channel] = tp_clamp16(d->echo_mix[channel] + contribution);
        d->echo_mix_known[channel] &= known;
    }
}

static void tp_voice_1(TPSdsp *d, unsigned n) {
    d->sample_directory_address = (uint16_t)(((uint16_t)d->directory_latch << 8u) +
        (uint16_t)d->source_number * 4u);
    d->source_number = tp_reg(d, (uint8_t)((n << 4u) + 4u));
}

static void tp_voice_2(TPSdsp *d, unsigned n) {
    TPSdspVoice *v = &d->voice[n];
    uint16_t address = d->sample_directory_address;
    uint8_t lo_known, hi_known, lo, hi;
    if (v->key_on_delay == 0u) address = (uint16_t)(address + 2u);
    lo = tp_aram_read(d, address, &lo_known);
    hi = tp_aram_read(d, (uint16_t)(address + 1u), &hi_known);
    d->next_brr_address = (uint16_t)(lo | ((uint16_t)hi << 8u));
    d->next_brr_known = (uint8_t)(lo_known && hi_known);
    d->adsr1 = tp_reg(d, (uint8_t)((n << 4u) + 5u));
    d->pitch = tp_reg(d, (uint8_t)((n << 4u) + 2u));
    d->pitch_known = 1u;
}

static void tp_voice_3a(TPSdsp *d, unsigned n) {
    d->pitch |= (uint16_t)((tp_reg(d, (uint8_t)((n << 4u) + 3u)) & 0x3Fu) << 8u);
}

static void tp_voice_3b(TPSdsp *d, unsigned n) {
    TPSdspVoice *v = &d->voice[n];
    d->brr_header = tp_aram_read(d, v->brr_address, &d->brr_header_known);
    d->brr_data = tp_aram_read(d, (uint16_t)(v->brr_address + v->brr_offset),
                              &d->brr_data_known);
    d->brr_header_known &= v->brr_address_known;
    d->brr_data_known &= v->brr_address_known;
}

static void tp_voice_3c(TPSdsp *d, unsigned n) {
    TPSdspVoice *v = &d->voice[n];
    uint8_t bit = (uint8_t)(1u << n);
    uint8_t sample_known;
    int32_t raw;
    if (n != 0u && (d->pmon_latch & bit) != 0u)
    {
        d->pitch = (uint16_t)((d->pitch +
            tp_arshift(tp_arshift(d->current_voice_output, 5u) *
                       (int32_t)d->pitch, 10u)) & 0x7FFFu);
        d->pitch_known &= d->current_voice_known;
    }
    if (v->key_on_delay != 0u) {
        if (v->key_on_delay == 5u) {
            v->brr_address = d->next_brr_address;
            v->brr_address_known = d->next_brr_known;
            v->brr_offset = 1u;
            v->buffer_position = 0u;
            d->brr_header = 0u;
            d->brr_header_known = 1u;
            v->active = 1u;
        }
        v->envelope = 0;
        v->calculated_envelope = 0;
        v->key_on_delay--;
        v->interpolation_position = (v->key_on_delay & 3u) != 0u ? 0x4000u : 0u;
        v->interpolation_known = 1u;
        d->pitch = 0u;
    }
    raw = tp_interpolate(v, &sample_known);
    if ((d->noise_latch & bit) != 0u) {
        raw = (int16_t)(d->noise_lfsr * 2u);
        sample_known = 1u;
    }
    d->current_voice_output = tp_arshift(raw * v->envelope, 11u);
    d->current_voice_output &= ~1;
    d->current_voice_known = (uint8_t)(v->envelope == 0 || sample_known);
    v->output = (int16_t)d->current_voice_output;
    v->output_known = d->current_voice_known;
    v->env_out = (uint8_t)(v->envelope >> 4u);
    if ((tp_reg(d, 0x6Cu) & 0x80u) != 0u ||
        (d->brr_header_known && (d->brr_header & 3u) == 1u)) {
        v->envelope_mode = TP_SDSP_ENV_RELEASE;
        v->envelope = 0;
    }
    if (d->every_other_sample != 0u) {
        if ((d->key_off & bit) != 0u) v->envelope_mode = TP_SDSP_ENV_RELEASE;
        if ((d->key_on & bit) != 0u) {
            v->key_on_delay = 5u;
            v->envelope_mode = TP_SDSP_ENV_ATTACK;
        }
    }
    if (v->key_on_delay == 0u) tp_envelope(d, v, n);
}

static void tp_voice_3(TPSdsp *d, unsigned n) {
    tp_voice_3a(d, n); tp_voice_3b(d, n); tp_voice_3c(d, n);
}

static void tp_voice_4(TPSdsp *d, unsigned n) {
    TPSdspVoice *v = &d->voice[n];
    d->looped = 0u;
    d->looped_known = 1u;
    if (v->active != 0u && v->interpolation_position >= 0x4000u) {
        tp_decode_brr_group(d, v);
        if (v->brr_offset >= 7u) {
            if (d->brr_header_known && (d->brr_header & 1u) != 0u) {
                v->brr_address = d->next_brr_address;
                v->brr_address_known = d->next_brr_known;
                d->looped = (uint8_t)(1u << n);
            } else {
                v->brr_address = (uint16_t)(v->brr_address + 9u);
                if (!d->brr_header_known) {
                    v->brr_address_known = 0u;
                    d->looped_known = 0u;
                }
            }
            v->brr_offset = 1u;
        } else v->brr_offset = (uint16_t)(v->brr_offset + 2u);
    }
    v->interpolation_position = (v->interpolation_position & 0x3FFFu) + d->pitch;
    v->interpolation_known &= d->pitch_known;
    if (v->interpolation_position > 0x7FFFu) v->interpolation_position = 0x7FFFu;
    tp_mix_voice(d, n, 0u);
}

static void tp_voice_5(TPSdsp *d, unsigned n) {
    TPSdspVoice *v = &d->voice[n];
    uint8_t bit = (uint8_t)(1u << n);
    tp_mix_voice(d, n, 1u);
    d->endx_buffer = (uint8_t)(tp_reg(d, 0x7Cu) | d->looped);
    d->endx_buffer_known = (uint8_t)(tp_bit_get(d->register_known,0x7Cu) &&
                                     d->looped_known);
    if (v->key_on_delay == 5u) d->endx_buffer &= (uint8_t)~bit;
}

static void tp_voice_6(TPSdsp *d) {
    d->outx_buffer = (uint8_t)((uint32_t)d->current_voice_output >> 8u);
    d->outx_buffer_known = d->current_voice_known;
}

static void tp_voice_7(TPSdsp *d, unsigned n) {
    tp_reg_set_known(d, 0x7Cu, d->endx_buffer, d->endx_buffer_known);
    d->envx_buffer = d->voice[n].env_out;
}

static void tp_voice_8(TPSdsp *d, unsigned n) {
    tp_reg_set_known(d, (uint8_t)((n << 4u) + 9u), d->outx_buffer,
                     d->outx_buffer_known);
}

static void tp_voice_9(TPSdsp *d, unsigned n) {
    tp_reg_set(d, (uint8_t)((n << 4u) + 8u), d->envx_buffer);
}

static int32_t tp_fir_term(TPSdsp *d, unsigned tap, unsigned channel,
                           uint8_t *known) {
    unsigned position = (d->echo_history_position + tap + 1u) & 7u;
    int8_t coefficient = (int8_t)tp_reg(d, (uint8_t)(0x0Fu + tap * 0x10u));
    if (coefficient != 0 && d->echo_history_known[position][channel] == 0u)
        *known = 0u;
    return tp_arshift((int32_t)d->echo_history[position][channel] * coefficient, 6u);
}

static void tp_echo_22(TPSdsp *d) {
    uint8_t lo_known, hi_known, lo, hi;
    d->echo_history_position = (uint8_t)((d->echo_history_position + 1u) & 7u);
    d->echo_pointer = (uint16_t)(((uint16_t)d->echo_start_latch << 8u) + d->echo_offset);
    lo = tp_aram_read(d, d->echo_pointer, &lo_known);
    hi = tp_aram_read(d, (uint16_t)(d->echo_pointer + 1u), &hi_known);
    d->echo_history[d->echo_history_position][0] =
        (int16_t)tp_arshift((int16_t)(lo | ((uint16_t)hi << 8u)), 1u);
    d->echo_history_known[d->echo_history_position][0] =
        (uint8_t)(lo_known && hi_known);
    d->fir_known[0] = d->fir_known[1] = 1u;
    d->looped_known = d->endx_buffer_known = d->outx_buffer_known = 1u;
    d->fir_sum[0] = tp_fir_term(d, 0u, 0u, &d->fir_known[0]);
    d->fir_sum[1] = tp_fir_term(d, 0u, 1u, &d->fir_known[1]);
}

static void tp_echo_23(TPSdsp *d) {
    uint8_t lo_known, hi_known, lo, hi;
    lo = tp_aram_read(d, (uint16_t)(d->echo_pointer + 2u), &lo_known);
    hi = tp_aram_read(d, (uint16_t)(d->echo_pointer + 3u), &hi_known);
    d->echo_history[d->echo_history_position][1] =
        (int16_t)tp_arshift((int16_t)(lo | ((uint16_t)hi << 8u)), 1u);
    d->echo_history_known[d->echo_history_position][1] =
        (uint8_t)(lo_known && hi_known);
    d->fir_sum[0] += tp_fir_term(d, 1u, 0u, &d->fir_known[0]);
    d->fir_sum[1] += tp_fir_term(d, 1u, 1u, &d->fir_known[1]);
    d->fir_sum[0] += tp_fir_term(d, 2u, 0u, &d->fir_known[0]);
    d->fir_sum[1] += tp_fir_term(d, 2u, 1u, &d->fir_known[1]);
}

static void tp_echo_taps(TPSdsp *d, unsigned first, unsigned last) {
    unsigned tap;
    for (tap = first; tap <= last; ++tap) {
        d->fir_sum[0] += tp_fir_term(d, tap, 0u, &d->fir_known[0]);
        d->fir_sum[1] += tp_fir_term(d, tap, 1u, &d->fir_known[1]);
    }
}

static void tp_echo_25(TPSdsp *d) {
    unsigned channel;
    for (channel = 0u; channel < 2u; ++channel) {
        int16_t first = (int16_t)(d->fir_sum[channel] +
            tp_fir_term(d, 6u, channel, &d->fir_known[channel]));
        int16_t last = (int16_t)tp_fir_term(d, 7u, channel,
            &d->fir_known[channel]);
        d->fir_sum[channel] = tp_even16((int32_t)first + last);
    }
}

static TPSdspStop tp_pcm_push(TPSdsp *d, int16_t left, int16_t right,
                              uint8_t known) {
    uint16_t sample[2];
    unsigned i, byte;
    if (d->pcm_count == TP_SDSP_PCM_FIFO_FRAMES) {
        d->overflow_count++;
        d->stop = TP_SDSP_STOP_PCM_FIFO_OVERFLOW;
        return d->stop;
    }
    d->pcm[d->pcm_write_index * 2u] = left;
    d->pcm[d->pcm_write_index * 2u + 1u] = right;
    d->pcm_known[d->pcm_write_index] = known;
    d->pcm_write_index = (d->pcm_write_index + 1u) % TP_SDSP_PCM_FIFO_FRAMES;
    d->pcm_count++;
    d->sample_frames++;
    if (known) d->known_frames++; else d->unknown_frames++;
    sample[0] = (uint16_t)left; sample[1] = (uint16_t)right;
    for (i = 0u; i < 2u; ++i) for (byte = 0u; byte < 2u; ++byte) {
        d->pcm_fnv1a64 ^= (uint8_t)(sample[i] >> (byte * 8u));
        d->pcm_fnv1a64 *= UINT64_C(1099511628211);
    }
    return TP_SDSP_OK;
}

static void tp_echo_26(TPSdsp *d) {
    int8_t feedback = (int8_t)tp_reg(d, 0x0Du);
    unsigned channel;
    for (channel = 0u; channel < 2u; ++channel) {
        d->echo_mix[channel] = tp_even16(d->echo_mix[channel] +
            tp_arshift(d->fir_sum[channel] * feedback, 7u));
        d->echo_mix_known[channel] &= (uint8_t)(feedback == 0 || d->fir_known[channel]);
    }
    {
        int8_t master = (int8_t)tp_reg(d, 0x0Cu);
        int8_t echo_volume = (int8_t)tp_reg(d, 0x2Cu);
        uint8_t dry_known = (uint8_t)(master == 0 || d->dry_mix_known[0]);
        uint8_t wet_known = (uint8_t)(echo_volume == 0 || d->fir_known[0]);
        d->dry_mix[0] = tp_clamp16(tp_arshift(d->dry_mix[0] * master, 7u) +
                                  tp_arshift(d->fir_sum[0] * echo_volume, 7u));
        d->dry_mix_known[0] = (uint8_t)(dry_known && wet_known);
    }
}

static TPSdspStop tp_echo_27(TPSdsp *d) {
    int16_t left, right;
    uint8_t known;
    int8_t master = (int8_t)tp_reg(d, 0x1Cu);
    int8_t echo_volume = (int8_t)tp_reg(d, 0x3Cu);
    uint8_t dry_known = (uint8_t)(master == 0 || d->dry_mix_known[1]);
    uint8_t wet_known = (uint8_t)(echo_volume == 0 || d->fir_known[1]);
    d->dry_mix[1] = tp_clamp16(tp_arshift(d->dry_mix[1] * master, 7u) +
                              tp_arshift(d->fir_sum[1] * echo_volume, 7u));
    d->dry_mix_known[1] = (uint8_t)(dry_known && wet_known);
    if ((tp_reg(d, 0x6Cu) & 0x40u) != 0u) {
        left = right = 0;
        known = 1u;
    } else {
        left = tp_clamp16(d->dry_mix[0]);
        right = tp_clamp16(d->dry_mix[1]);
        known = (uint8_t)(d->dry_mix_known[0] && d->dry_mix_known[1]);
    }
    d->dry_mix[0] = d->dry_mix[1] = 0;
    d->dry_mix_known[0] = d->dry_mix_known[1] = 1u;
    return tp_pcm_push(d, left, right, known);
}

static void tp_echo_write_word(TPSdsp *d, uint16_t address, int32_t value,
                               uint8_t known) {
    uint16_t bits = (uint16_t)tp_even16(value);
    tp_aram_write(d, address, (uint8_t)bits, known);
    tp_aram_write(d, (uint16_t)(address + 1u), (uint8_t)(bits >> 8u), known);
}

static void tp_echo_29(TPSdsp *d) {
    if (d->echo_offset == 0u)
        d->echo_length = (uint16_t)((tp_reg(d, 0x7Du) & 0x0Fu) << 11u);
    d->echo_offset = (uint16_t)(d->echo_offset + 4u);
    if (d->echo_length == 0u || d->echo_offset >= d->echo_length) d->echo_offset = 0u;
    if (d->echo_write_enabled != 0u)
        tp_echo_write_word(d, d->echo_pointer, d->echo_mix[0], d->echo_mix_known[0]);
    d->echo_mix[0] = 0; d->echo_mix_known[0] = 1u;
    d->echo_start_latch = tp_reg(d, 0x6Du);
    d->echo_write_enabled = (uint8_t)((tp_reg(d, 0x6Cu) & 0x20u) == 0u);
}

static void tp_echo_30(TPSdsp *d) {
    if (d->echo_write_enabled != 0u)
        tp_echo_write_word(d, (uint16_t)(d->echo_pointer + 2u),
                           d->echo_mix[1], d->echo_mix_known[1]);
    d->echo_mix[1] = 0; d->echo_mix_known[1] = 1u;
}

void tp_sdsp_power_on(TPSdsp *d, uint8_t *aram, uint8_t *aram_known) {
    unsigned i;
    if (d == NULL) return;
    memset(d, 0, sizeof(*d));
    d->aram = aram;
    d->aram_known = aram_known;
    memset(d->register_known, 0xFF, sizeof(d->register_known));
    d->registers[0x6Cu] = 0xE0u;
    d->noise_lfsr = 0x4000u;
    d->every_other_sample = 1u;
    d->dry_mix_known[0] = d->dry_mix_known[1] = 1u;
    d->echo_mix_known[0] = d->echo_mix_known[1] = 1u;
    d->fir_known[0] = d->fir_known[1] = 1u;
    d->pcm_fnv1a64 = UINT64_C(14695981039346656037);
    for (i = 0u; i < TP_SDSP_VOICE_COUNT; ++i)
    {
        d->voice[i].envelope_mode = TP_SDSP_ENV_RELEASE;
        d->voice[i].interpolation_known = 1u;
    }
}

TPSdspStop tp_sdsp_read_register(TPSdsp *d, uint8_t address, uint8_t *value) {
    if (d == NULL || value == NULL) return TP_SDSP_STOP_ARGUMENT;
    address &= 0x7Fu;
    if (!tp_bit_get(d->register_known, address)) {
        d->stop = TP_SDSP_STOP_REGISTER_UNKNOWN;
        return d->stop;
    }
    *value = tp_reg(d, address);
    d->register_reads++;
    return d->stop;
}

TPSdspStop tp_sdsp_write_register(TPSdsp *d, uint8_t address, uint8_t value) {
    if (d == NULL) return TP_SDSP_STOP_ARGUMENT;
    address &= 0x7Fu;
    tp_reg_set(d, address, value);
    d->register_writes++;
    if ((address & 0x0Fu) == 8u) d->envx_buffer = value;
    if ((address & 0x0Fu) == 9u) {
        d->outx_buffer = value;
        d->outx_buffer_known = 1u;
    }
    if (address == 0x4Cu) d->new_key_on = value;
    if (address == 0x7Cu) {
        d->endx_buffer = 0u;
        d->endx_buffer_known = 1u;
        tp_reg_set(d, 0x7Cu, 0u);
    }
    return d->stop;
}

TPSdspStop tp_sdsp_step_phase(TPSdsp *d) {
    TPSdspStop result = TP_SDSP_OK;
    uint8_t phase;
    if (d == NULL) return TP_SDSP_STOP_ARGUMENT;
    if (d->stop != TP_SDSP_OK) return d->stop;
    phase = d->phase;
    switch (phase) {
        case 0u: tp_voice_5(d,0u); tp_voice_2(d,1u); break;
        case 1u: tp_voice_6(d); tp_voice_3(d,1u); break;
        case 2u: tp_voice_7(d,0u); tp_voice_4(d,1u); tp_voice_1(d,3u); break;
        case 3u: tp_voice_8(d,0u); tp_voice_5(d,1u); tp_voice_2(d,2u); break;
        case 4u: tp_voice_9(d,0u); tp_voice_6(d); tp_voice_3(d,2u); break;
        case 5u: tp_voice_7(d,1u); tp_voice_4(d,2u); tp_voice_1(d,4u); break;
        case 6u: tp_voice_8(d,1u); tp_voice_5(d,2u); tp_voice_2(d,3u); break;
        case 7u: tp_voice_9(d,1u); tp_voice_6(d); tp_voice_3(d,3u); break;
        case 8u: tp_voice_7(d,2u); tp_voice_4(d,3u); tp_voice_1(d,5u); break;
        case 9u: tp_voice_8(d,2u); tp_voice_5(d,3u); tp_voice_2(d,4u); break;
        case 10u: tp_voice_9(d,2u); tp_voice_6(d); tp_voice_3(d,4u); break;
        case 11u: tp_voice_7(d,3u); tp_voice_4(d,4u); tp_voice_1(d,6u); break;
        case 12u: tp_voice_8(d,3u); tp_voice_5(d,4u); tp_voice_2(d,5u); break;
        case 13u: tp_voice_9(d,3u); tp_voice_6(d); tp_voice_3(d,5u); break;
        case 14u: tp_voice_7(d,4u); tp_voice_4(d,5u); tp_voice_1(d,7u); break;
        case 15u: tp_voice_8(d,4u); tp_voice_5(d,5u); tp_voice_2(d,6u); break;
        case 16u: tp_voice_9(d,4u); tp_voice_6(d); tp_voice_3(d,6u); break;
        case 17u: tp_voice_1(d,0u); tp_voice_7(d,5u); tp_voice_4(d,6u); break;
        case 18u: tp_voice_8(d,5u); tp_voice_5(d,6u); tp_voice_2(d,7u); break;
        case 19u: tp_voice_9(d,5u); tp_voice_6(d); tp_voice_3(d,7u); break;
        case 20u: tp_voice_1(d,1u); tp_voice_7(d,6u); tp_voice_4(d,7u); break;
        case 21u: tp_voice_8(d,6u); tp_voice_5(d,7u); tp_voice_2(d,0u); break;
        case 22u: tp_voice_3a(d,0u); tp_voice_9(d,6u); tp_voice_6(d); tp_echo_22(d); break;
        case 23u: tp_voice_7(d,7u); tp_echo_23(d); break;
        case 24u: tp_voice_8(d,7u); tp_echo_taps(d,3u,5u); break;
        case 25u: tp_voice_3b(d,0u); tp_voice_9(d,7u); tp_echo_25(d); break;
        case 26u: tp_echo_26(d); break;
        case 27u:
            d->pmon_latch = (uint8_t)(tp_reg(d,0x2Du) & 0xFEu);
            result = tp_echo_27(d); break;
        case 28u:
            d->directory_latch = tp_reg(d,0x5Du);
            d->noise_latch = tp_reg(d,0x3Du);
            d->echo_voice_latch = tp_reg(d,0x4Du);
            d->echo_write_enabled = (uint8_t)((tp_reg(d,0x6Cu)&0x20u)==0u); break;
        case 29u:
            d->every_other_sample ^= 1u;
            if (d->every_other_sample != 0u) d->new_key_on &= (uint8_t)~d->key_on;
            tp_echo_29(d); break;
        case 30u:
            if (d->every_other_sample != 0u) {
                d->key_on = d->new_key_on;
                d->key_off = tp_reg(d,0x5Cu);
            }
            d->counter = d->counter != 0u ? (uint16_t)(d->counter-1u) : 0x77FFu;
            if (tp_rate_event(d, tp_reg(d,0x6Cu)&0x1Fu)) {
                uint16_t feedback = (uint16_t)(((d->noise_lfsr << 14u) ^
                    (d->noise_lfsr << 13u)) & 0x4000u);
                d->noise_lfsr = (uint16_t)(feedback ^ (d->noise_lfsr >> 1u));
            }
            tp_voice_3c(d,0u); tp_echo_30(d); break;
        case 31u: tp_voice_4(d,0u); tp_voice_1(d,2u); break;
        default: d->stop = TP_SDSP_STOP_PHASE_INVARIANT; return d->stop;
    }
    if (result != TP_SDSP_OK) return result;
    d->phase = (uint8_t)((phase + 1u) & 31u);
    d->phase_steps++;
    return d->stop;
}

TPSdspStop tp_sdsp_advance_cycles(TPSdsp *d, uint32_t cycles) {
    uint32_t i;
    if (d == NULL) return TP_SDSP_STOP_ARGUMENT;
    for (i = 0u; i < cycles; ++i) {
        TPSdspStop result = tp_sdsp_step_phase(d);
        if (result != TP_SDSP_OK) return result;
    }
    return TP_SDSP_OK;
}

size_t tp_sdsp_pcm_available(const TPSdsp *d) {
    return d != NULL ? d->pcm_count : 0u;
}

size_t tp_sdsp_pcm_read(TPSdsp *d, int16_t *stereo, uint8_t *known,
                        size_t frame_capacity) {
    size_t count = 0u;
    if (d == NULL || stereo == NULL) return 0u;
    while (count < frame_capacity && d->pcm_count != 0u) {
        stereo[count * 2u] = d->pcm[d->pcm_read_index * 2u];
        stereo[count * 2u + 1u] = d->pcm[d->pcm_read_index * 2u + 1u];
        if (known != NULL) known[count] = d->pcm_known[d->pcm_read_index];
        d->pcm_read_index = (d->pcm_read_index + 1u) % TP_SDSP_PCM_FIFO_FRAMES;
        d->pcm_count--;
        count++;
    }
    return count;
}
