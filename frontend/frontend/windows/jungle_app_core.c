#include "jungle_app_core.h"
#include "theme_park_machine.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#include <bcrypt.h>
#endif

#define JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES 8192u
#define THEME_PARK_FRAME_STEP_LIMIT UINT64_C(10000000)

struct JungleStrikeRecomp {
    TPMachine *machine;
    uint8_t *rom;
    uint16_t snes_pixels[TP_FRAME_PIXELS];
    uint8_t pixel_known[(TP_FRAME_PIXELS + 7u) / 8u];
    uint32_t frame_pixels[JUNGLE_RECOMP_FRAME_WIDTH * JUNGLE_RECOMP_FRAME_HEIGHT];
    int16_t audio_samples[JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES * 2u];
    size_t audio_read_index, audio_write_index, audio_frames;
    uint32_t current_frame;
    uint64_t instruction_count;
    int frame_available, failed, audio_overflowed;
    uint64_t audio_frames_dropped;
    char last_error[4096];
};

static void set_error(char *dst, size_t cap, const char *message) {
    if (!dst || !cap) return;
    (void)snprintf(dst, cap, "%s", message ? message : "");
    dst[cap - 1u] = '\0';
}

static void set_instance_error(JungleStrikeRecomp *instance,
                               const char *message) {
    if (instance) set_error(instance->last_error, sizeof(instance->last_error), message);
}

static int theme_park_rom_matches(const uint8_t *rom, size_t rom_size) {
    static const uint8_t expected[32] = {
        0xC0,0xA7,0xE2,0x71,0x31,0xA7,0xD8,0xC9,
        0xEF,0x52,0xA5,0x22,0x73,0x29,0xE6,0xDE,
        0x58,0x46,0xC0,0x45,0xA9,0xDA,0x1F,0x3F,
        0x84,0x84,0x5E,0x3B,0xE8,0xE4,0xEF,0xBA
    };
#ifdef _WIN32
    BCRYPT_ALG_HANDLE algorithm = NULL;
    BCRYPT_HASH_HANDLE hash = NULL;
    PUCHAR object = NULL;
    DWORD object_size = 0u;
    DWORD result_size = 0u;
    uint8_t digest[32];
    int matches = 0;
    if (!rom || rom_size != JUNGLE_RECOMP_ROM_SIZE || rom_size > ULONG_MAX)
        return 0;
    if (BCryptOpenAlgorithmProvider(&algorithm, BCRYPT_SHA256_ALGORITHM,
                                    NULL, 0u) < 0 ||
        BCryptGetProperty(algorithm, BCRYPT_OBJECT_LENGTH,
                          (PUCHAR)&object_size, sizeof(object_size),
                          &result_size, 0u) < 0)
        goto cleanup;
    object = (PUCHAR)malloc(object_size);
    if (!object || BCryptCreateHash(algorithm, &hash, object, object_size,
                                    NULL, 0u, 0u) < 0 ||
        BCryptHashData(hash, (PUCHAR)rom, (ULONG)rom_size, 0u) < 0 ||
        BCryptFinishHash(hash, digest, sizeof(digest), 0u) < 0)
        goto cleanup;
    matches = memcmp(digest, expected, sizeof(expected)) == 0;
cleanup:
    if (hash) BCryptDestroyHash(hash);
    if (algorithm) BCryptCloseAlgorithmProvider(algorithm, 0u);
    free(object);
    return matches;
#else
    (void)rom;
    (void)rom_size;
    return 0;
#endif
}

static void describe_machine(JungleStrikeRecomp *instance, const char *summary) {
    TPMachineDiagnostics d;
    char detail[4096];
    memset(&d, 0, sizeof(d));
    if (!instance || !instance->machine ||
        !tp_machine_read_diagnostics(instance->machine, &d)) {
        set_instance_error(instance, summary);
        return;
    }
    (void)snprintf(detail, sizeof(detail),
        "%s\r\nS-CPU: $%06X context $%08X\r\nS-SMP PC: $%04X\r\n"
        "Frame: %llu\r\nMaster clock: %llu\r\nRaster: %u:%u\r\n"
        "S-CPU stop: %s\r\nBus/PPU/APU/scheduler/DSP stops: %u/%u/%u/%u/%u\r\n"
        "Bus failure address: $%06X\r\nPower-on profile: %u",
        summary ? summary : "Theme Park static core stopped.",
        (unsigned)d.scpu_address, (unsigned)d.scpu_context_key,
        (unsigned)d.ssmp_pc, (unsigned long long)d.scheduler_frame_count,
        (unsigned long long)d.master_clock, (unsigned)d.scanline,
        (unsigned)d.hclock,
        d.scpu_failure_reason[0] ? d.scpu_failure_reason : "none",
        (unsigned)d.bus_stop, (unsigned)d.ppu_stop, (unsigned)d.apu_stop,
        (unsigned)d.scheduler_stop, (unsigned)d.sdsp_stop,
        (unsigned)d.bus_failure_address, (unsigned)d.power_on_profile);
    set_instance_error(instance, detail);
}

static void append_audio_frames(JungleStrikeRecomp *instance,
                                const int16_t *source, size_t frames) {
    size_t free_frames, dropped, first;
    if (!frames) return;
    if (frames >= JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES) {
        dropped = instance->audio_frames + frames - JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES;
        source += (frames - JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES) * 2u;
        frames = JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES;
        instance->audio_read_index = instance->audio_write_index = instance->audio_frames = 0u;
        if (dropped) {
            instance->audio_frames_dropped += dropped;
            instance->audio_overflowed = 1;
        }
    } else {
        free_frames = JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES - instance->audio_frames;
        if (frames > free_frames) {
            dropped = frames - free_frames;
            instance->audio_read_index = (instance->audio_read_index + dropped) %
                                         JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES;
            instance->audio_frames -= dropped;
            instance->audio_frames_dropped += dropped;
            instance->audio_overflowed = 1;
        }
    }
    first = JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES - instance->audio_write_index;
    if (first > frames) first = frames;
    memcpy(instance->audio_samples + instance->audio_write_index * 2u,
           source, first * 2u * sizeof(int16_t));
    if (frames > first)
        memcpy(instance->audio_samples, source + first * 2u,
               (frames - first) * 2u * sizeof(int16_t));
    instance->audio_write_index = (instance->audio_write_index + frames) %
                                  JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES;
    instance->audio_frames += frames;
}

static int drain_machine_audio(JungleStrikeRecomp *instance) {
    int16_t samples[512u * 2u];
    uint8_t known[512u];
    size_t count, index;
    while (tp_machine_pcm_available(instance->machine) != 0u) {
        count = tp_machine_pcm_read(instance->machine, samples, known, 512u);
        if (!count) break;
        for (index = 0u; index < count; ++index) {
            if (!known[index]) {
                instance->failed = 1;
                describe_machine(instance, "Theme Park produced an unknown PCM sample.");
                return 0;
            }
        }
        append_audio_frames(instance, samples, count);
    }
    return 1;
}

static int refresh_frame(JungleStrikeRecomp *instance) {
    uint16_t width = 0u, height = 0u;
    uint64_t sequence = 0u;
    size_t index;
    if (!tp_machine_read_published_frame(instance->machine,
            instance->snes_pixels, instance->pixel_known, TP_FRAME_PIXELS,
            &width, &height, &sequence) || width != JUNGLE_RECOMP_FRAME_WIDTH ||
        height < JUNGLE_RECOMP_FRAME_HEIGHT) {
        instance->failed = 1;
        describe_machine(instance, "Theme Park did not publish a complete 256x224 frame.");
        return 0;
    }
    for (index = 0u; index < JUNGLE_RECOMP_FRAME_WIDTH * JUNGLE_RECOMP_FRAME_HEIGHT; ++index) {
        uint16_t color;
        uint32_t red, green, blue;
        if ((instance->pixel_known[index >> 3u] & (uint8_t)(1u << (index & 7u))) == 0u) {
            instance->failed = 1;
            describe_machine(instance, "Theme Park published an unknown visible pixel.");
            return 0;
        }
        color = instance->snes_pixels[index];
        red = color & 31u;
        green = (color >> 5u) & 31u;
        blue = (color >> 10u) & 31u;
        red = (red << 3u) | (red >> 2u);
        green = (green << 3u) | (green >> 2u);
        blue = (blue << 3u) | (blue >> 2u);
        instance->frame_pixels[index] = UINT32_C(0xFF000000) |
            (red << 16u) | (green << 8u) | blue;
    }
    instance->current_frame = sequence > UINT32_MAX ? UINT32_MAX : (uint32_t)sequence;
    instance->frame_available = 1;
    return 1;
}

static int cold_power_on(JungleStrikeRecomp *instance) {
    TPBusPorts ports;
    TPSchedulerHooks hooks;
    TPBusStop stop;
    memset(&ports, 0, sizeof(ports));
    memset(&hooks, 0, sizeof(hooks));
    stop = tp_machine_power_on_profile(instance->machine, instance->rom,
        JUNGLE_RECOMP_ROM_SIZE, ports, hooks, TP_POWER_ON_DETERMINISTIC_ZERO_WRAM_V1);
    if (stop != TP_BUS_OK) {
        instance->failed = 1;
        describe_machine(instance, "Theme Park static core could not power on.");
        return 0;
    }
    instance->audio_read_index = instance->audio_write_index = instance->audio_frames = 0u;
    instance->current_frame = 0u;
    instance->instruction_count = 0u;
    instance->frame_available = instance->failed = instance->audio_overflowed = 0;
    instance->audio_frames_dropped = 0u;
    set_instance_error(instance, "");
    return 1;
}

int jungle_recomp_create(JungleStrikeRecomp **out_instance,
                         const uint8_t *rom, size_t rom_size,
                         char *error, size_t error_capacity) {
    JungleStrikeRecomp *instance;
    if (out_instance) *out_instance = NULL;
    if (!out_instance || !rom || rom_size != JUNGLE_RECOMP_ROM_SIZE) {
        set_error(error, error_capacity, "Select the exact supported 1 MiB Theme Park Europe ROM.");
        return 0;
    }
    if (!theme_park_rom_matches(rom, rom_size)) {
        set_error(error, error_capacity,
                  "The ROM SHA-256 does not match the supported Theme Park Europe image.");
        return 0;
    }
    instance = (JungleStrikeRecomp *)calloc(1u, sizeof(*instance));
    if (!instance) {
        set_error(error, error_capacity, "Out of memory creating the static core.");
        return 0;
    }
    instance->machine = (TPMachine *)calloc(1u, sizeof(*instance->machine));
    instance->rom = (uint8_t *)malloc(JUNGLE_RECOMP_ROM_SIZE);
    if (!instance->machine || !instance->rom) {
        jungle_recomp_destroy(instance);
        set_error(error, error_capacity, "Out of memory creating the static core.");
        return 0;
    }
    memcpy(instance->rom, rom, JUNGLE_RECOMP_ROM_SIZE);
    if (!cold_power_on(instance)) {
        set_error(error, error_capacity, instance->last_error);
        jungle_recomp_destroy(instance);
        return 0;
    }
    *out_instance = instance;
    set_error(error, error_capacity, "");
    return 1;
}

void jungle_recomp_destroy(JungleStrikeRecomp *instance) {
    if (!instance) return;
    free(instance->machine);
    free(instance->rom);
    free(instance);
}

int jungle_recomp_reset(JungleStrikeRecomp *instance,
                        char *error, size_t error_capacity) {
    if (!instance || !instance->machine || !instance->rom || !cold_power_on(instance)) {
        set_error(error, error_capacity, instance ? instance->last_error :
                  "No Theme Park static core is loaded.");
        return 0;
    }
    set_error(error, error_capacity, "");
    return 1;
}

static int advance_frames(JungleStrikeRecomp *instance, uint16_t input_mask,
                          uint32_t frame_count, int render_output,
                          JungleStrikeRecompAudioProgressCallback progress,
                          void *opaque, JungleStrikeRecompFrameResult *result) {
    uint32_t start, index;
    if (!instance || !instance->machine || instance->failed) return 0;
    start = instance->current_frame;
    for (index = 0u; index < frame_count; ++index) {
        uint64_t steps = 0u;
        TPMachineRunResult run;
        tp_machine_set_standard_pad(instance->machine, 0u, input_mask);
        if (progress) {
            uint64_t sequence = instance->machine->ppu.published_sequence;
            run = TP_MACHINE_RUN_STEP_LIMIT;
            /* Same instruction/frame boundary and fail-closed limit as the
             * machine runner. Host transport may drain completed PCM between
             * instructions; no guest clocks, instruction bodies or samples
             * are skipped or resampled here. Check in bounded batches rather
             * than invoke device work after every instruction. */
            while (steps < THEME_PARK_FRAME_STEP_LIMIT) {
                if (tp_machine_step(instance->machine) != TP_SCPU_EXECUTED) {
                    run = TP_MACHINE_RUN_STOPPED;
                    break;
                }
                ++steps;
                if (instance->machine->ppu.published_sequence != sequence) {
                    run = TP_MACHINE_RUN_FRAME_READY;
                    break;
                }
                if ((steps & 255u) == 0u &&
                    tp_machine_pcm_available(instance->machine) >= 128u) {
                    if (!drain_machine_audio(instance)) {
                        instance->instruction_count += steps;
                        return 0;
                    }
                    progress(instance, opaque);
                }
            }
        } else {
            run = tp_machine_run_to_next_frame(instance->machine,
                                               THEME_PARK_FRAME_STEP_LIMIT, &steps);
        }
        instance->instruction_count += steps;
        if (run != TP_MACHINE_RUN_FRAME_READY) {
            instance->failed = 1;
            describe_machine(instance, run == TP_MACHINE_RUN_STEP_LIMIT
                ? "Theme Park exceeded the per-frame static dispatch limit."
                : "Theme Park static core stopped before the next frame.");
            return 0;
        }
        if (!drain_machine_audio(instance)) return 0;
        if (progress) progress(instance, opaque);
        if (!refresh_frame(instance)) return 0;
        if (!render_output) instance->frame_available = 0;
    }
    if (result) {
        memset(result, 0, sizeof(*result));
        result->route_continued = 1u;
        result->frame_rendered = render_output && instance->frame_available;
        result->input_mask = input_mask;
        result->start_frame = start;
        result->end_frame = instance->current_frame;
    }
    return 1;
}

int jungle_recomp_advance(JungleStrikeRecomp *i, uint16_t m, uint32_t n,
                          JungleStrikeRecompFrameResult *r) {
    return advance_frames(i, m, n, 1, NULL, NULL, r);
}
int jungle_recomp_advance_streamed(JungleStrikeRecomp *i, uint16_t m, uint32_t n,
    JungleStrikeRecompAudioProgressCallback p, void *o, JungleStrikeRecompFrameResult *r) {
    return advance_frames(i, m, n, 1, p, o, r);
}
int jungle_recomp_advance_headless(JungleStrikeRecomp *i, uint16_t m, uint32_t n,
                                   JungleStrikeRecompFrameResult *r) {
    return advance_frames(i, m, n, 0, NULL, NULL, r);
}
const uint32_t *jungle_recomp_frame_bgra(const JungleStrikeRecomp *i) {
    return i && i->frame_available ? i->frame_pixels : NULL;
}
uint32_t jungle_recomp_frame_width(const JungleStrikeRecomp *i) { (void)i; return JUNGLE_RECOMP_FRAME_WIDTH; }
uint32_t jungle_recomp_current_frame(const JungleStrikeRecomp *i) { return i ? i->current_frame : 0u; }
uint64_t jungle_recomp_instruction_count(const JungleStrikeRecomp *i) { return i ? i->instruction_count : 0u; }
int jungle_recomp_failed(const JungleStrikeRecomp *i) { return i ? i->failed : 1; }
const char *jungle_recomp_last_error(const JungleStrikeRecomp *i) {
    return i ? i->last_error : "No Theme Park static core is loaded.";
}
size_t jungle_recomp_audio_available(const JungleStrikeRecomp *i) { return i ? i->audio_frames : 0u; }

size_t jungle_recomp_audio_read(JungleStrikeRecomp *i, int16_t *stereo, size_t capacity) {
    size_t frames, first;
    if (!i || !stereo || !capacity) return 0u;
    frames = i->audio_frames < capacity ? i->audio_frames : capacity;
    first = JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES - i->audio_read_index;
    if (first > frames) first = frames;
    memcpy(stereo, i->audio_samples + i->audio_read_index * 2u,
           first * 2u * sizeof(int16_t));
    if (frames > first) memcpy(stereo + first * 2u, i->audio_samples,
                               (frames - first) * 2u * sizeof(int16_t));
    i->audio_read_index = (i->audio_read_index + frames) % JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES;
    i->audio_frames -= frames;
    if (!i->audio_frames) i->audio_write_index = i->audio_read_index;
    return frames;
}
size_t jungle_recomp_audio_discard(JungleStrikeRecomp *i) {
    size_t discarded = i ? i->audio_frames : 0u;
    if (i) i->audio_frames = i->audio_read_index = i->audio_write_index = 0u;
    return discarded;
}
int jungle_recomp_audio_overflowed(const JungleStrikeRecomp *i) { return i ? i->audio_overflowed : 0; }
uint64_t jungle_recomp_audio_dropped_frames(const JungleStrikeRecomp *i) { return i ? i->audio_frames_dropped : 0u; }
void jungle_recomp_audio_clear_overflow(JungleStrikeRecomp *i) { if (i) i->audio_overflowed = 0; }
int jungle_recomp_widescreen_enabled(const JungleStrikeRecomp *i) { (void)i; return 0; }

static int unsupported(char *error, size_t cap) {
    set_error(error, cap, "This operation is not exposed by the Theme Park static core.");
    return 0;
}
int jungle_recomp_set_widescreen(JungleStrikeRecomp *i, int enabled, char *e, size_t c) {
    (void)i; return enabled ? unsupported(e, c) : 1;
}
int jungle_recomp_snapshot_save(const JungleStrikeRecomp *i, const char *p, char *e, size_t c) {
    (void)i; (void)p; return unsupported(e, c);
}
int jungle_recomp_snapshot_load(JungleStrikeRecomp *i, const char *p, char *e, size_t c) {
    (void)i; (void)p; return unsupported(e, c);
}
int jungle_recomp_sram_copy(const JungleStrikeRecomp *i, void *d, size_t c) {
    (void)i; (void)d; (void)c; return 0;
}
int jungle_recomp_sram_load(JungleStrikeRecomp *i, const void *s, size_t n, char *e, size_t c) {
    (void)i; (void)s; (void)n; return unsupported(e, c);
}
int jungle_recomp_sram_dirty(const JungleStrikeRecomp *i) { (void)i; return 0; }
void jungle_recomp_sram_mark_clean(JungleStrikeRecomp *i) { (void)i; }

static int write_diagnostics(const JungleStrikeRecomp *i, const char *path,
                             const char *mode, const char *title,
                             char *error, size_t cap) {
    TPMachineDiagnostics d;
    FILE *file;
    uint32_t trace_index;
    if (!i || !i->machine || !path || !path[0] ||
        !tp_machine_read_diagnostics(i->machine, &d)) {
        set_error(error, cap, "A loaded Theme Park core and diagnostic path are required.");
        return 0;
    }
    file = fopen(path, mode);
    if (!file) { set_error(error, cap, "Unable to write the diagnostic log."); return 0; }
    if (title && title[0]) (void)fprintf(file, "\r\n--- %s ---\r\n", title);
    (void)fprintf(file,
        "diagnostic_schema=theme-park-machine-diagnostic-v2\r\n"
        "timestamp_unix=%lld\r\n"
        "rom_sha256=C0A7E27131A7D8C9EF52A5227329E6DE5846C045A9DA1F3F84845E3BE8E4EFBA\r\n"
        "machine_profile=PAL_21281370HZ_312LINES_50.006979FPS_SMP_1025280HZ_ZERO_WRAM_V2\r\n",
        (long long)time(NULL));
    (void)fprintf(file,
        "Theme Park static-core diagnostic\r\nframe=%llu\r\nmaster_clock=%llu\r\n"
        "scpu_address=%06X\r\nscpu_context=%08X\r\nssmp_pc=%04X\r\n"
        "scpu_A=%04X\r\nscpu_X=%04X\r\nscpu_Y=%04X\r\nscpu_S=%04X\r\n"
        "scpu_D=%04X\r\nscpu_DBR=%02X\r\nscpu_PBR=%02X\r\nscpu_P=%02X\r\nscpu_E=%u\r\n"
        "raster=%u:%u\r\nnmitimen=%02X\r\nnmi_flag=%u\r\nnmi_pending=%u\r\n"
        "ppu_forced_blank=%u\r\nppu_brightness=%u\r\nppu_bg_mode=%u\r\n"
        "ppu_main_screen=%02X\r\nppu_sub_screen=%02X\r\n"
        "cpu_to_smp=%02X,%02X,%02X,%02X\r\nsmp_to_cpu=%02X,%02X,%02X,%02X\r\n"
        "wram_fnv1a64=%016llX\r\nvram_fnv1a64=%016llX\r\n"
        "cgram_fnv1a64=%016llX\r\noam_fnv1a64=%016llX\r\n"
        "published_frame_fnv1a64=%016llX\r\npcm_fnv1a64=%016llX\r\n"
        "scpu_completed_cycles=%llu\r\nssmp_cycles=%llu\r\n"
        "bus_stop=%u\r\nppu_stop=%u\r\napu_stop=%u\r\nscheduler_stop=%u\r\n"
        "sdsp_stop=%u\r\nbus_failure_address=%06X\r\n"
        "scpu_failure_address=%06X\r\nscpu_failure_context=%08X\r\nreason=%s\r\n",
        (unsigned long long)d.scheduler_frame_count, (unsigned long long)d.master_clock,
        (unsigned)d.scpu_address, (unsigned)d.scpu_context_key, (unsigned)d.ssmp_pc,
        (unsigned)d.scpu_a, (unsigned)d.scpu_x, (unsigned)d.scpu_y,
        (unsigned)d.scpu_s, (unsigned)d.scpu_d, (unsigned)d.scpu_dbr,
        (unsigned)d.scpu_pbr, (unsigned)d.scpu_p, (unsigned)d.scpu_e,
        (unsigned)d.scanline, (unsigned)d.hclock, (unsigned)d.nmitimen,
        (unsigned)d.nmi_flag, (unsigned)d.nmi_pending,
        (unsigned)d.forced_blank, (unsigned)d.brightness, (unsigned)d.bg_mode,
        (unsigned)d.main_screen, (unsigned)d.sub_screen,
        (unsigned)d.cpu_to_smp[0], (unsigned)d.cpu_to_smp[1],
        (unsigned)d.cpu_to_smp[2], (unsigned)d.cpu_to_smp[3],
        (unsigned)d.smp_to_cpu[0], (unsigned)d.smp_to_cpu[1],
        (unsigned)d.smp_to_cpu[2], (unsigned)d.smp_to_cpu[3],
        (unsigned long long)d.wram_fnv1a64, (unsigned long long)d.vram_fnv1a64,
        (unsigned long long)d.cgram_fnv1a64, (unsigned long long)d.oam_fnv1a64,
        (unsigned long long)d.published_frame_fnv1a64,
        (unsigned long long)d.pcm_fnv1a64,
        (unsigned long long)d.scpu_completed_cycles,
        (unsigned long long)d.ssmp_cycles,
        (unsigned)d.bus_stop, (unsigned)d.ppu_stop, (unsigned)d.apu_stop,
        (unsigned)d.scheduler_stop, (unsigned)d.sdsp_stop,
        (unsigned)d.bus_failure_address, (unsigned)d.scpu_failure_address,
        (unsigned)d.scpu_failure_context_key,
        d.scpu_failure_reason[0] ? d.scpu_failure_reason : "none");
    (void)fprintf(file,
        "bus_stop_name=%s\r\nppu_stop_name=%s\r\napu_stop_name=%s\r\n"
        "scheduler_stop_name=%s\r\n"
        "bus_failure_value=%02X\r\nscheduler_failure_clock=%llu\r\n"
        "scheduler_failure_raster=%u:%u\r\n"
        "ssmp_A=%02X\r\nssmp_X=%02X\r\nssmp_Y=%02X\r\nssmp_SP=%02X\r\n"
        "ssmp_PSW=%02X\r\nssmp_active=%u\r\nssmp_active_pc=%04X\r\n"
        "ssmp_instructions=%llu\r\n"
        "apu_phase=%u\r\napu_uploaded_bytes=%u\r\napu_epoch=%u\r\n"
        "apu_upload_address=%04X\r\napu_static_entry_pc=%04X\r\n"
        "apu_static_entry_master_clock=%llu\r\napu_static_entry_smp_cycle=%llu\r\n"
        "scheduler_field=%u\r\nscheduler_irq_flag=%u\r\nscheduler_irq_line=%u\r\n"
        "scheduler_autojoy_active=%u\r\nscheduler_dma_pending_mask=%02X\r\n"
        "scheduler_hdma_enable_mask=%02X\r\nscheduler_event_count=%llu\r\n"
        "scheduler_event_digest=%016llX\r\n"
        "dma_active_channel=%u\r\ndma_servicing=%u\r\ndma_hdma_enable=%02X\r\n"
        "dma_transfer_bytes=%llu\r\ndma_transfer_master_clocks=%llu\r\n"
        "ppu_vram_address=%04X\r\nppu_cgram_address=%02X\r\n"
        "ppu_cgram_second=%u\r\nppu_oam_address=%04X\r\nppu_oam_write_pending=%u\r\n"
        "input_live_pad=%04X,%04X\r\ninput_serial_shift=%04X,%04X\r\n"
        "input_auto_result=%04X,%04X,%04X,%04X\r\n"
        "input_strobes=%u,%u,%u\r\ninput_report_sequence=%llu\r\n"
        "sdsp_phase=%u\r\nsdsp_active_voice_mask=%02X\r\nsdsp_echo_pointer=%04X\r\n",
        tp_bus_stop_name(d.bus_stop), tp_bus_stop_name(d.ppu_stop),
        tp_bus_stop_name(d.apu_stop), tp_scheduler_stop_name(d.scheduler_stop),
        (unsigned)d.bus_failure_value,
        (unsigned long long)d.scheduler_failure_clock,
        (unsigned)d.scheduler_failure_scanline,
        (unsigned)d.scheduler_failure_hclock,
        (unsigned)d.ssmp_a, (unsigned)d.ssmp_x, (unsigned)d.ssmp_y,
        (unsigned)d.ssmp_sp, (unsigned)d.ssmp_psw, (unsigned)d.ssmp_active,
        (unsigned)d.ssmp_active_pc, (unsigned long long)d.ssmp_instructions,
        (unsigned)d.apu_phase, (unsigned)d.apu_uploaded_bytes,
        (unsigned)d.apu_epoch, (unsigned)d.apu_upload_address,
        (unsigned)d.apu_static_entry_pc,
        (unsigned long long)d.apu_static_entry_master_clock,
        (unsigned long long)d.apu_static_entry_smp_cycle,
        (unsigned)d.scheduler_field, (unsigned)d.scheduler_irq_flag,
        (unsigned)d.scheduler_irq_line, (unsigned)d.scheduler_autojoy_active,
        (unsigned)d.scheduler_dma_pending_mask,
        (unsigned)d.scheduler_hdma_enable_mask,
        (unsigned long long)d.scheduler_event_count,
        (unsigned long long)d.scheduler_event_digest,
        (unsigned)d.dma_active_channel, (unsigned)d.dma_servicing,
        (unsigned)d.dma_hdma_enable,
        (unsigned long long)d.dma_transfer_bytes,
        (unsigned long long)d.dma_transfer_master_clocks,
        (unsigned)d.ppu_vram_address, (unsigned)d.ppu_cgram_address,
        (unsigned)d.ppu_cgram_second, (unsigned)d.ppu_oam_address,
        (unsigned)d.ppu_oam_write_pending,
        (unsigned)d.input_live_pad[0], (unsigned)d.input_live_pad[1],
        (unsigned)d.input_serial_shift[0], (unsigned)d.input_serial_shift[1],
        (unsigned)d.input_auto_result[0], (unsigned)d.input_auto_result[1],
        (unsigned)d.input_auto_result[2], (unsigned)d.input_auto_result[3],
        (unsigned)d.input_cpu_strobe, (unsigned)d.input_auto_strobe,
        (unsigned)d.input_effective_strobe,
        (unsigned long long)d.input_report_sequence,
        (unsigned)d.sdsp_phase, (unsigned)d.sdsp_active_voice_mask,
        (unsigned)d.sdsp_echo_pointer);
    (void)fprintf(file, "recent_scpu_trace_count=%u\r\n", (unsigned)d.trace_count);
    for (trace_index = 0u; trace_index < d.trace_count; ++trace_index) {
        const TPMachineTraceEntry *entry = &d.trace[trace_index];
        (void)fprintf(file,
            "trace[%02u]=clock:%llu address:%06X context:%08X "
            "A:%04X X:%04X Y:%04X S:%04X D:%04X DBR:%02X P:%02X E:%u\r\n",
            (unsigned)trace_index, (unsigned long long)entry->master_clock,
            (unsigned)entry->address, (unsigned)entry->context_key,
            (unsigned)entry->a, (unsigned)entry->x, (unsigned)entry->y,
            (unsigned)entry->s, (unsigned)entry->d, (unsigned)entry->dbr,
            (unsigned)entry->p, (unsigned)entry->e);
    }
    if (fclose(file) != 0) { set_error(error, cap, "Unable to finish the diagnostic log."); return 0; }
    set_error(error, cap, "");
    return 1;
}
int jungle_recomp_write_diagnostic_log(const JungleStrikeRecomp *i, const char *p,
    const char *s, char *e, size_t c) { (void)s; return write_diagnostics(i, p, "wb", NULL, e, c); }
int jungle_recomp_append_diagnostic_log(const JungleStrikeRecomp *i, const char *p,
    const char *t, char *e, size_t c) { return write_diagnostics(i, p, "ab", t, e, c); }
