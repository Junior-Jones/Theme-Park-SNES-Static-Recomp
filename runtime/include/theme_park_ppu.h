#ifndef THEME_PARK_PPU_H
#define THEME_PARK_PPU_H

#include <stdint.h>

#include "theme_park_bus.h"
#include "theme_park_scheduler.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TP_PPU_VRAM_BYTES 65536u
#define TP_PPU_CGRAM_BYTES 512u
#define TP_PPU_OAM_BYTES 544u
#define TP_FRAME_WIDTH 256u
#define TP_FRAME_MAX_HEIGHT 239u
#define TP_FRAME_PIXELS (TP_FRAME_WIDTH * TP_FRAME_MAX_HEIGHT)

typedef struct TPPpu {
    TPScheduler *scheduler;
    uint8_t registers[0x40];
    uint8_t vram[TP_PPU_VRAM_BYTES];
    uint8_t vram_known[TP_PPU_VRAM_BYTES / 8u];
    uint8_t cgram[TP_PPU_CGRAM_BYTES];
    uint8_t cgram_known[TP_PPU_CGRAM_BYTES / 8u];
    uint8_t oam[TP_PPU_OAM_BYTES];
    uint8_t oam_known[(TP_PPU_OAM_BYTES + 7u) / 8u];
    uint16_t bg_hofs[4], bg_vofs[4];
    uint16_t mode7[6];
    uint16_t vram_address, vram_read_buffer;
    uint16_t oam_reload_address, oam_address;
    uint16_t fixed_color;
    uint8_t vram_increment, vram_remap, vram_increment_on_high;
    uint8_t vram_read_buffer_known;
    uint8_t oam_write_latch, oam_write_pending;
    uint8_t cgram_address, cgram_latch, cgram_second;
    uint8_t scroll_latch, hscroll_latch, mode7_latch;
    uint8_t counter_latched, hcounter_second, vcounter_second;
    uint16_t latched_hcounter, latched_vcounter;
    uint8_t ppu1_open_bus, ppu2_open_bus;
    uint8_t ppu1_open_bus_known, ppu2_open_bus_known;
    uint8_t forced_blank, brightness, overscan, interlace;
    uint64_t register_reads[0x40], register_writes[0x40];
    uint64_t storage_reads, storage_writes;
    uint16_t work_frame[TP_FRAME_PIXELS];
    uint16_t published_frame[TP_FRAME_PIXELS];
    uint8_t work_known[(TP_FRAME_PIXELS + 7u) / 8u];
    uint8_t published_known[(TP_FRAME_PIXELS + 7u) / 8u];
    uint8_t obj_palette[TP_FRAME_WIDTH], obj_priority[TP_FRAME_WIDTH];
    uint8_t obj_line_ready, obj_range_over, obj_time_over;
    uint16_t obj_line;
    uint16_t published_height;
    uint64_t published_sequence, rendered_pixels, known_pixels, unknown_pixels;
    uint8_t frame_ready, frame_published_this_vblank;
    TPBusStop failure;
} TPPpu;

void tp_ppu_power_on(TPPpu *ppu, TPScheduler *scheduler);
void tp_ppu_reset(TPPpu *ppu);
TPBusStop tp_ppu_bus_read(void *opaque, uint16_t reg, uint8_t *value);
TPBusStop tp_ppu_bus_write(void *opaque, uint16_t reg, uint8_t value);
TPSchedulerStop tp_ppu_raster_edge(void *opaque, uint64_t master_clock,
                                   uint16_t scanline, uint16_t hclock);
int tp_ppu_read_published_frame(const TPPpu *ppu, uint16_t *pixels,
                                uint8_t *known, uint32_t pixel_capacity,
                                uint16_t *width, uint16_t *height,
                                uint64_t *sequence);

#ifdef __cplusplus
}
#endif

#endif
