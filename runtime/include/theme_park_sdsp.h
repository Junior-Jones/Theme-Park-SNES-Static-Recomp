#ifndef THEME_PARK_SDSP_H
#define THEME_PARK_SDSP_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TP_SDSP_REGISTER_COUNT 128u
#define TP_SDSP_VOICE_COUNT 8u
#define TP_SDSP_PHASE_COUNT 32u
#define TP_SDSP_NATIVE_RATE_HZ 32040u
#define TP_SDSP_PCM_FIFO_FRAMES 8192u

typedef enum TPSdspStop {
    TP_SDSP_OK = 0,
    TP_SDSP_STOP_ARGUMENT,
    TP_SDSP_STOP_REGISTER_UNKNOWN,
    TP_SDSP_STOP_PHASE_INVARIANT,
    TP_SDSP_STOP_PCM_FIFO_OVERFLOW
} TPSdspStop;

typedef enum TPSdspEnvelopeMode {
    TP_SDSP_ENV_RELEASE = 0,
    TP_SDSP_ENV_ATTACK,
    TP_SDSP_ENV_DECAY,
    TP_SDSP_ENV_SUSTAIN
} TPSdspEnvelopeMode;

typedef struct TPSdspVoice {
    int16_t sample[12];
    uint8_t sample_known[12];
    uint16_t brr_address;
    uint16_t brr_offset;
    uint8_t brr_address_known;
    uint32_t interpolation_position;
    uint8_t interpolation_known;
    int32_t envelope;
    int32_t calculated_envelope;
    int16_t output;
    uint8_t output_known;
    uint8_t buffer_position;
    uint8_t key_on_delay;
    uint8_t envelope_mode;
    uint8_t active;
    uint8_t env_out;
} TPSdspVoice;

typedef struct TPSdsp {
    uint8_t *aram;
    uint8_t *aram_known;
    uint8_t registers[TP_SDSP_REGISTER_COUNT];
    uint8_t register_known[TP_SDSP_REGISTER_COUNT / 8u];
    TPSdspVoice voice[TP_SDSP_VOICE_COUNT];

    uint8_t phase;
    uint8_t every_other_sample;
    uint8_t key_on;
    uint8_t new_key_on;
    uint8_t key_off;
    uint8_t pmon_latch;
    uint8_t noise_latch;
    uint8_t echo_voice_latch;
    uint8_t directory_latch;
    uint8_t echo_start_latch;
    uint8_t echo_write_enabled;
    uint8_t source_number;
    uint8_t adsr1;
    uint8_t brr_header;
    uint8_t brr_header_known;
    uint8_t brr_data;
    uint8_t brr_data_known;
    uint8_t looped;
    uint8_t looped_known;
    uint8_t endx_buffer;
    uint8_t endx_buffer_known;
    uint8_t envx_buffer;
    uint8_t outx_buffer;
    uint8_t outx_buffer_known;

    uint16_t counter;
    uint16_t noise_lfsr;
    uint16_t sample_directory_address;
    uint16_t next_brr_address;
    uint8_t next_brr_known;
    uint16_t pitch;
    uint8_t pitch_known;
    int32_t current_voice_output;
    uint8_t current_voice_known;

    int32_t dry_mix[2];
    uint8_t dry_mix_known[2];
    int32_t echo_mix[2];
    uint8_t echo_mix_known[2];
    int16_t echo_history[8][2];
    uint8_t echo_history_known[8][2];
    uint8_t echo_history_position;
    int32_t fir_sum[2];
    uint8_t fir_known[2];
    uint16_t echo_pointer;
    uint16_t echo_offset;
    uint16_t echo_length;

    int16_t pcm[TP_SDSP_PCM_FIFO_FRAMES * 2u];
    uint8_t pcm_known[TP_SDSP_PCM_FIFO_FRAMES];
    size_t pcm_read_index;
    size_t pcm_write_index;
    size_t pcm_count;
    uint64_t phase_steps;
    uint64_t sample_frames;
    uint64_t known_frames;
    uint64_t unknown_frames;
    uint64_t overflow_count;
    uint64_t register_reads;
    uint64_t register_writes;
    uint64_t aram_reads;
    uint64_t aram_writes;
    uint64_t pcm_fnv1a64;
    TPSdspStop stop;
} TPSdsp;

void tp_sdsp_power_on(TPSdsp *dsp, uint8_t *aram, uint8_t *aram_known);
TPSdspStop tp_sdsp_read_register(TPSdsp *dsp, uint8_t address, uint8_t *value);
TPSdspStop tp_sdsp_write_register(TPSdsp *dsp, uint8_t address, uint8_t value);
TPSdspStop tp_sdsp_step_phase(TPSdsp *dsp);
TPSdspStop tp_sdsp_advance_cycles(TPSdsp *dsp, uint32_t cycles);
size_t tp_sdsp_pcm_available(const TPSdsp *dsp);
size_t tp_sdsp_pcm_read(TPSdsp *dsp, int16_t *stereo, uint8_t *known,
                        size_t frame_capacity);

#ifdef __cplusplus
}
#endif

#endif
