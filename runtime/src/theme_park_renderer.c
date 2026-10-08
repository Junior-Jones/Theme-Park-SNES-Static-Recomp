#include "theme_park_ppu.h"

#include <string.h>

typedef struct TPPixel {
    uint16_t color;
    uint8_t palette, priority, layer, obj_palette, transparent;
} TPPixel;

typedef struct TPObject {
    uint16_t x;
    uint8_t y, tile, name, palette, priority, hflip, vflip, width, height;
} TPObject;

static int known(const uint8_t *map, uint32_t address) {
    return (map[address >> 3u] & (uint8_t)(1u << (address & 7u))) != 0u;
}

static void mark(uint8_t *map, uint32_t address) {
    map[address >> 3u] |= (uint8_t)(1u << (address & 7u));
}

static int vr8(const TPPpu *p, uint32_t address, uint8_t *value) {
    address &= 0xFFFFu;
    if (!known(p->vram_known, address)) return 0;
    *value = p->vram[address]; return 1;
}

static int vr16(const TPPpu *p, uint32_t address, uint16_t *value) {
    uint8_t lo, hi;
    if (!vr8(p, address, &lo) || !vr8(p, address + 1u, &hi)) return 0;
    *value = (uint16_t)(lo | ((uint16_t)hi << 8u)); return 1;
}

static int cg(const TPPpu *p, unsigned index, uint16_t *value) {
    uint32_t address = (uint32_t)(index & 255u) << 1u;
    if (!known(p->cgram_known, address) || !known(p->cgram_known, address + 1u)) return 0;
    *value = (uint16_t)((p->cgram[address] | ((uint16_t)p->cgram[address + 1u] << 8u)) & 0x7FFFu);
    return 1;
}

static uint16_t brightness(uint16_t color, unsigned level) {
    unsigned r = color & 31u, g = (color >> 5u) & 31u, b = (color >> 10u) & 31u;
    return (uint16_t)((r * level / 15u) | ((g * level / 15u) << 5u) |
                      ((b * level / 15u) << 10u));
}

static unsigned bpp(unsigned mode, unsigned layer) {
    if (mode == 2u) return layer < 2u ? 4u : 0u;
    if (mode == 3u) return layer == 0u ? 8u : layer == 1u ? 4u : 0u;
    return 0u;
}

static uint8_t bg_priority(unsigned layer, unsigned high) {
    static const uint8_t priority[2][2] = {{3u, 9u}, {1u, 7u}};
    return priority[layer][high != 0u];
}

static uint8_t obj_priority(unsigned priority) {
    static const uint8_t rank[4] = {2u, 4u, 6u, 8u};
    return rank[priority & 3u];
}

static int map_entry(const TPPpu *p, unsigned layer, unsigned world_x,
                     unsigned world_y, unsigned tile_size, uint16_t *entry) {
    uint8_t sc = p->registers[7u + layer];
    unsigned width = (sc & 1u) != 0u ? 64u : 32u;
    unsigned height = (sc & 2u) != 0u ? 64u : 32u;
    unsigned tile_x = (world_x % (width * tile_size)) / tile_size;
    unsigned tile_y = (world_y % (height * tile_size)) / tile_size;
    unsigned screen = (tile_y >> 5u) * (width == 64u ? 2u : 1u) + (tile_x >> 5u);
    uint32_t base = (uint32_t)(sc & 0xFCu) << 9u;
    uint32_t address = base + screen * 0x800u +
        (((tile_y & 31u) * 32u + (tile_x & 31u)) << 1u);
    return vr16(p, address, entry);
}

static int opt_word(const TPPpu *p, unsigned sample_x, unsigned row_y, uint16_t *word) {
    unsigned tile_size = (p->registers[5] & 0x40u) != 0u ? 16u : 8u;
    unsigned wx = (sample_x & ~7u) + (p->bg_hofs[2] & ~7u);
    unsigned wy = row_y + p->bg_vofs[2];
    return map_entry(p, 2u, wx, wy, tile_size, word);
}

static int apply_mode2_offset(const TPPpu *p, unsigned layer, unsigned sx,
                              unsigned sy, unsigned *wx, unsigned *wy) {
    uint16_t horizontal, vertical;
    unsigned enable = 1u << (13u + layer);
    if (!opt_word(p, sx, 0u, &horizontal) || !opt_word(p, sx, 8u, &vertical)) return 0;
    if ((horizontal & enable) != 0u)
        *wx = sx + (horizontal & 0xFFF8u) + (p->bg_hofs[layer] & 7u);
    if ((vertical & enable) != 0u) *wy = sy + vertical;
    return 1;
}

static int bg_pixel(const TPPpu *p, unsigned layer, unsigned x, unsigned y, TPPixel *pixel) {
    unsigned mode = p->registers[5] & 7u, depth = bpp(mode, layer);
    unsigned sx = x, sy = y, mosaic = (p->registers[6] >> 4u) + 1u;
    unsigned tile_size, wx, wy, px, py, bit, plane;
    uint8_t nba, value, color = 0u;
    uint16_t entry, palette_color;
    uint32_t char_base, row;
    memset(pixel, 0, sizeof(*pixel)); pixel->transparent = 1u;
    if (depth == 0u) return 1;
    if ((p->registers[6] & (1u << layer)) != 0u && mosaic > 1u) {
        sx -= sx % mosaic; sy -= sy % mosaic;
    }
    tile_size = (p->registers[5] & (uint8_t)(0x10u << layer)) != 0u ? 16u : 8u;
    wx = sx + p->bg_hofs[layer]; wy = sy + p->bg_vofs[layer];
    if (mode == 2u && !apply_mode2_offset(p, layer, sx, sy, &wx, &wy)) return 0;
    if (!map_entry(p, layer, wx, wy, tile_size, &entry)) return 0;
    px = wx % tile_size; py = wy % tile_size;
    if ((entry & 0x4000u) != 0u) px = tile_size - 1u - px;
    if ((entry & 0x8000u) != 0u) py = tile_size - 1u - py;
    nba = p->registers[0x0Bu];
    char_base = (uint32_t)(layer != 0u ? nba >> 4u : nba & 15u) << 13u;
    if (tile_size == 16u) {
        entry = (uint16_t)((entry & 0xFC00u) |
            (((entry & 0x03FFu) + (px >> 3u) + ((py >> 3u) << 4u)) & 0x03FFu));
        px &= 7u; py &= 7u;
    }
    row = char_base + (uint32_t)(entry & 0x03FFu) * (depth * 8u) + py * 2u;
    bit = 7u - px;
    for (plane = 0u; plane < depth; ++plane) {
        if (!vr8(p, row + (plane >> 1u) * 16u + (plane & 1u), &value)) return 0;
        color |= (uint8_t)(((value >> bit) & 1u) << plane);
    }
    if (color == 0u) return 1;
    pixel->transparent = 0u; pixel->layer = (uint8_t)layer;
    pixel->priority = bg_priority(layer, (entry >> 13u) & 1u);
    if (depth == 4u) pixel->palette = (uint8_t)((((entry >> 10u) & 7u) << 4u) | color);
    else pixel->palette = color;
    if (!cg(p, pixel->palette, &palette_color)) return 0;
    pixel->color = palette_color;
    return 1;
}

static int oam_byte(const TPPpu *p, unsigned address, uint8_t *value) {
    if (address >= TP_PPU_OAM_BYTES || !known(p->oam_known, address)) return 0;
    *value = p->oam[address]; return 1;
}

static int decode_object(const TPPpu *p, unsigned index, TPObject *object) {
    uint8_t x, y, tile, attr, high;
    unsigned pair;
    if (!oam_byte(p,index*4u,&x)||!oam_byte(p,index*4u+1u,&y)||
        !oam_byte(p,index*4u+2u,&tile)||!oam_byte(p,index*4u+3u,&attr)||
        !oam_byte(p,512u+index/4u,&high)) return 0;
    pair = (high >> ((index & 3u) * 2u)) & 3u;
    object->x = (uint16_t)(x | ((pair & 1u) << 8u));
    object->y = (uint8_t)(y + 1u); object->tile = tile; object->name = attr & 1u;
    object->palette = (attr >> 1u) & 7u; object->priority = (attr >> 4u) & 3u;
    object->hflip = (attr >> 6u) & 1u; object->vflip = attr >> 7u;
    /* Theme Park's proved OBSEL domain is size selector zero: 8x8 or 16x16. */
    object->width = object->height = (pair & 2u) != 0u ? 16u : 8u;
    return 1;
}

static int prepare_objects(TPPpu *p, unsigned y) {
    TPObject objects[32];
    unsigned count = 0u, tiles = 0u, scan, first = 0u;
    memset(p->obj_palette, 0, sizeof(p->obj_palette));
    memset(p->obj_priority, 0, sizeof(p->obj_priority));
    p->obj_range_over = p->obj_time_over = 0u;
    if ((p->registers[3] & 0x80u) != 0u) first = (p->oam_address >> 2u) & 127u;
    for (scan = 0u; scan < 128u; ++scan) {
        TPObject object; unsigned index = (first + scan) & 127u;
        uint8_t line;
        if (!decode_object(p, index, &object)) return 0;
        line = (uint8_t)((y + 1u - object.y) & 255u);
        if ((object.x <= 256u || (uint32_t)object.x + object.width - 1u >= 512u) &&
            line < object.height) {
            if (count == 32u) { p->obj_range_over = 1u; break; }
            if (object.vflip) line = (uint8_t)(object.height - 1u - line);
            objects[count++] = object;
            objects[count-1u].y = line;
        }
    }
    while (count != 0u) {
        TPObject object = objects[--count];
        unsigned tile_x, tile_count = object.width >> 3u;
        for (tile_x = 0u; tile_x < tile_count; ++tile_x) {
            unsigned tile_screen_x = (object.x + tile_x * 8u) & 511u;
            unsigned logical_x = object.hflip ? tile_count - 1u - tile_x : tile_x;
            unsigned base = (p->registers[1] & 7u) << 13u;
            unsigned tile = ((object.tile & 0xF0u) + (((unsigned)object.y >> 3u) << 4u) +
                             ((object.tile + logical_x) & 15u)) & 255u;
            unsigned row = object.y & 7u, px;
            uint16_t p01, p23;
            uint32_t address;
            if (object.x != 256u && tile_screen_x >= 256u && tile_screen_x + 7u < 512u)
                continue;
            if (object.name) base += (1u + ((p->registers[1] >> 3u) & 3u)) << 12u;
            address = (base + tile * 32u + row * 2u) & 0xFFFFu;
            if (!vr16(p,address,&p01)||!vr16(p,address+16u,&p23)) return 0;
            if (++tiles > 34u) { p->obj_time_over = 1u; return 1; }
            for (px = 0u; px < 8u; ++px) {
                unsigned screen_x = (object.x + tile_x * 8u + px) & 511u;
                unsigned bit = object.hflip ? px : 7u - px;
                uint8_t color = (uint8_t)(((p01 >> bit) & 1u) | (((p01 >> (bit+8u)) & 1u) << 1u) |
                    (((p23 >> bit) & 1u) << 2u) | (((p23 >> (bit+8u)) & 1u) << 3u));
                if (screen_x < 256u && color != 0u) {
                    p->obj_palette[screen_x] = (uint8_t)(128u + object.palette * 16u + color);
                    p->obj_priority[screen_x] = object.priority;
                }
            }
        }
    }
    p->obj_line = (uint16_t)y; p->obj_line_ready = 1u; return 1;
}

static int render_pixel(TPPpu *p, unsigned x, unsigned y, uint16_t *color) {
    TPPixel best; unsigned layer, mode = p->registers[5] & 7u;
    uint8_t main = p->registers[0x2Cu] & 0x1Fu;
    memset(&best, 0, sizeof(best)); best.layer = 5u;
    if (p->forced_blank != 0u || p->brightness == 0u) { *color = 0u; return 1; }
    if (mode != 2u && mode != 3u) return 0;
    if (!cg(p, 0u, &best.color)) return 0;
    for (layer = 0u; layer < 2u; ++layer) {
        TPPixel candidate;
        if ((main & (1u << layer)) == 0u) continue;
        if (!bg_pixel(p, layer, x, y, &candidate)) return 0;
        if (!candidate.transparent && candidate.priority > best.priority) best = candidate;
    }
    if ((main & 0x10u) != 0u && p->obj_palette[x] != 0u) {
        uint8_t rank = obj_priority(p->obj_priority[x]);
        if (rank > best.priority) {
            if (!cg(p, p->obj_palette[x], &best.color)) return 0;
            best.priority = rank; best.layer = 4u;
        }
    }
    /* Theme Park reaches no $2131 writer and no subscreen-enable writer.  The
       reset-zero owner therefore selects no color math in the 14C domain. */
    *color = brightness(best.color, p->brightness); return 1;
}

TPSchedulerStop tp_ppu_raster_edge(void *opaque, uint64_t master_clock,
                                   uint16_t scanline, uint16_t hclock) {
    TPPpu *p = (TPPpu *)opaque;
    unsigned x, y; uint16_t color; uint32_t offset;
    (void)master_clock;
    if (p == NULL || p->scheduler == NULL) return TP_SCHEDULER_STOP_ARGUMENT;
    if (scanline == 0u && hclock == 4u) {
        memset(p->work_known, 0, sizeof(p->work_known));
        p->obj_line_ready = 0u; p->frame_published_this_vblank = 0u;
    }
    if (scanline == p->scheduler->vblank_start_scanline && hclock == 4u &&
        p->frame_published_this_vblank == 0u) {
        unsigned height = p->overscan != 0u ? 239u : 224u;
        memcpy(p->published_frame, p->work_frame, height * TP_FRAME_WIDTH * sizeof(uint16_t));
        memcpy(p->published_known, p->work_known, (height * TP_FRAME_WIDTH + 7u) / 8u);
        p->published_height = (uint16_t)height; p->published_sequence++;
        p->frame_ready = p->frame_published_this_vblank = 1u;
        return TP_SCHEDULER_OK;
    }
    if (scanline == 0u || scanline > (p->overscan != 0u ? 239u : 224u) ||
        hclock < 88u || hclock >= 1112u) return TP_SCHEDULER_OK;
    x = (hclock - 88u) >> 2u; y = scanline - 1u;
    if (x >= TP_FRAME_WIDTH) return TP_SCHEDULER_OK;
    if (x == 0u || p->obj_line_ready == 0u || p->obj_line != y) {
        if (p->forced_blank != 0u || p->brightness == 0u ||
            (p->registers[0x2Cu] & 0x10u) == 0u) {
            memset(p->obj_palette, 0, sizeof(p->obj_palette));
            memset(p->obj_priority, 0, sizeof(p->obj_priority));
            p->obj_line = (uint16_t)y; p->obj_line_ready = 1u;
        } else if (!prepare_objects(p, y)) {
            p->failure = TP_BUS_STOP_PPU_UNAVAILABLE; p->unknown_pixels++;
            return TP_SCHEDULER_STOP_DOMAIN_CALLBACK;
        }
    }
    offset = y * TP_FRAME_WIDTH + x;
    if (!render_pixel(p, x, y, &color)) {
        p->failure = TP_BUS_STOP_PPU_UNAVAILABLE; p->unknown_pixels++;
        return TP_SCHEDULER_STOP_DOMAIN_CALLBACK;
    }
    p->work_frame[offset] = color; mark(p->work_known, offset);
    p->rendered_pixels++; p->known_pixels++;
    return TP_SCHEDULER_OK;
}

int tp_ppu_read_published_frame(const TPPpu *p, uint16_t *pixels,
                                uint8_t *known_map, uint32_t capacity,
                                uint16_t *width, uint16_t *height,
                                uint64_t *sequence) {
    uint32_t count;
    if (p == NULL || pixels == NULL || known_map == NULL || width == NULL ||
        height == NULL || sequence == NULL || p->frame_ready == 0u) return 0;
    count = TP_FRAME_WIDTH * p->published_height;
    if (capacity < count) return 0;
    memcpy(pixels, p->published_frame, count * sizeof(uint16_t));
    memcpy(known_map, p->published_known, (count + 7u) / 8u);
    *width = TP_FRAME_WIDTH; *height = p->published_height;
    *sequence = p->published_sequence; return 1;
}
