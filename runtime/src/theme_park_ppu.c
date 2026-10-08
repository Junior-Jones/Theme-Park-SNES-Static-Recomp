#include "theme_park_ppu.h"

#include <string.h>

static int tp_known(const uint8_t *map, uint32_t address) {
    return (map[address >> 3u] & (uint8_t)(1u << (address & 7u))) != 0u;
}

static void tp_mark(uint8_t *map, uint32_t address) {
    map[address >> 3u] |= (uint8_t)(1u << (address & 7u));
}

static int tp_ppu_memory_accessible(const TPPpu *p) {
    return p->forced_blank != 0u || p->scheduler == NULL ||
           p->scheduler->scanline >= p->scheduler->vblank_start_scanline ||
           p->scheduler->hclock < 4u || p->scheduler->hclock > 1096u;
}

static uint16_t tp_vram_mapped(const TPPpu *p) {
    uint16_t a = p->vram_address;
    switch (p->vram_remap & 3u) {
        case 1u: return (uint16_t)((a & 0xFF00u) | ((a & 0x001Fu) << 3u) |
                                  ((a >> 5u) & 7u));
        case 2u: return (uint16_t)((a & 0xFE00u) | ((a & 0x003Fu) << 3u) |
                                  ((a >> 6u) & 7u));
        case 3u: return (uint16_t)((a & 0xFC00u) | ((a & 0x007Fu) << 3u) |
                                  ((a >> 7u) & 7u));
        default: return a;
    }
}

static void tp_vram_advance(TPPpu *p) {
    p->vram_address = (uint16_t)((p->vram_address + p->vram_increment) & 0x7FFFu);
}

static void tp_vram_reload(TPPpu *p) {
    const uint32_t a = (uint32_t)tp_vram_mapped(p) << 1u;
    p->vram_read_buffer_known = (uint8_t)(tp_known(p->vram_known, a) &&
        tp_known(p->vram_known, (a + 1u) & 0xFFFFu));
    if (p->vram_read_buffer_known)
        p->vram_read_buffer = (uint16_t)(p->vram[a] |
            ((uint16_t)p->vram[(a + 1u) & 0xFFFFu] << 8u));
}

static uint16_t tp_oam_physical(uint16_t address) {
    return address < 512u ? address : (uint16_t)(0x200u | (address & 0x1Fu));
}

static int32_t tp_mode7_product(const TPPpu *p) {
    return (int32_t)(int16_t)p->mode7[0] * (int32_t)(int8_t)(p->mode7[1] >> 8u);
}

static void tp_scroll_write(TPPpu *p, unsigned layer, int vertical, uint8_t value) {
    if (vertical) {
        p->bg_vofs[layer] = (uint16_t)((((uint16_t)value << 8u) | p->scroll_latch) & 0x03FFu);
        p->scroll_latch = value;
    } else {
        p->bg_hofs[layer] = (uint16_t)((((uint16_t)value << 8u) |
            (p->scroll_latch & 0xF8u) | (p->hscroll_latch & 7u)) & 0x03FFu);
        p->scroll_latch = value;
        p->hscroll_latch = value;
    }
}

static void tp_ppu_control_reset(TPPpu *p) {
    memset(p->registers, 0, sizeof(p->registers));
    memset(p->bg_hofs, 0, sizeof(p->bg_hofs));
    memset(p->bg_vofs, 0, sizeof(p->bg_vofs));
    memset(p->mode7, 0, sizeof(p->mode7));
    p->forced_blank = 1u;
    p->brightness = 0u;
    p->registers[0] = 0x80u;
    p->vram_increment = 1u;
    p->vram_address = p->vram_read_buffer = p->oam_reload_address = p->oam_address = 0u;
    p->fixed_color = 0u;
    p->vram_remap = p->vram_increment_on_high = p->vram_read_buffer_known = 0u;
    p->oam_write_latch = p->oam_write_pending = 0u;
    p->cgram_address = p->cgram_latch = p->cgram_second = 0u;
    p->scroll_latch = p->hscroll_latch = p->mode7_latch = 0u;
    p->counter_latched = p->hcounter_second = p->vcounter_second = 0u;
    p->latched_hcounter = p->latched_vcounter = 0u;
    p->ppu1_open_bus = p->ppu2_open_bus = 0u;
    p->ppu1_open_bus_known = p->ppu2_open_bus_known = 0u;
    p->overscan = p->interlace = 0u;
    memset(p->work_known, 0, sizeof(p->work_known));
    p->obj_line_ready = p->obj_range_over = p->obj_time_over = 0u;
    p->frame_published_this_vblank = 0u;
    p->failure = TP_BUS_OK;
    tp_scheduler_set_display(p->scheduler, 0, 0);
}

void tp_ppu_power_on(TPPpu *p, TPScheduler *scheduler) {
    if (p == NULL) return;
    memset(p, 0, sizeof(*p));
    p->scheduler = scheduler;
    tp_ppu_control_reset(p);
}

void tp_ppu_reset(TPPpu *p) {
    if (p == NULL) return;
    /* RESET reinitializes port/latch state but does not invent cleared PPU RAM. */
    tp_ppu_control_reset(p);
}

TPBusStop tp_ppu_bus_write(void *opaque, uint16_t reg, uint8_t value) {
    TPPpu *p = (TPPpu *)opaque;
    uint32_t a;
    unsigned n;
    if (p == NULL || reg < 0x2100u || reg > 0x213Fu)
        return TP_BUS_STOP_PPU_UNAVAILABLE;
    p->register_writes[reg - 0x2100u]++;
    if (reg <= 0x2133u) p->registers[reg - 0x2100u] = value;
    p->ppu1_open_bus = value; p->ppu1_open_bus_known = 1u;
    switch (reg) {
        case 0x2100u: p->forced_blank = (uint8_t)(value >> 7u); p->brightness = value & 15u; break;
        case 0x2101u: break;
        case 0x2102u: p->oam_reload_address = (uint16_t)((p->oam_reload_address & 0x100u) | value); p->oam_address = (uint16_t)(p->oam_reload_address << 1u); p->oam_write_pending = 0u; break;
        case 0x2103u: p->oam_reload_address = (uint16_t)((p->oam_reload_address & 0xFFu) | ((uint16_t)(value & 1u) << 8u)); p->oam_address = (uint16_t)(p->oam_reload_address << 1u); p->oam_write_pending = 0u; break;
        case 0x2104u:
            if (!tp_ppu_memory_accessible(p)) return p->failure = TP_BUS_STOP_PPU_UNAVAILABLE;
            a = tp_oam_physical(p->oam_address);
            if (p->oam_address < 512u && (p->oam_address & 1u) == 0u) {
                p->oam_write_latch = value; p->oam_write_pending = 1u;
            } else if (p->oam_address < 512u) {
                p->oam[a - 1u] = p->oam_write_latch; tp_mark(p->oam_known, a - 1u);
                p->oam[a] = value; tp_mark(p->oam_known, a); p->storage_writes += 2u;
                p->oam_write_pending = 0u;
            } else {
                p->oam[a] = value; tp_mark(p->oam_known, a); p->storage_writes++;
            }
            p->oam_address = (uint16_t)((p->oam_address + 1u) & 0x03FFu); break;
        case 0x2105u: case 0x2106u: case 0x2107u: case 0x2108u:
        case 0x2109u: case 0x210Au: case 0x210Bu: case 0x210Cu: break;
        case 0x210Du: p->mode7[4] = (uint16_t)(((uint16_t)value << 8u) | p->mode7_latch); p->mode7_latch = value; tp_scroll_write(p, 0u, 0, value); break;
        case 0x210Eu: p->mode7[5] = (uint16_t)(((uint16_t)value << 8u) | p->mode7_latch); p->mode7_latch = value; tp_scroll_write(p, 0u, 1, value); break;
        case 0x210Fu: case 0x2111u: tp_scroll_write(p, (reg - 0x210Fu) / 2u + 1u, 0, value); break;
        case 0x2110u: case 0x2112u: tp_scroll_write(p, (reg - 0x2110u) / 2u + 1u, 1, value); break;
        case 0x2113u: tp_scroll_write(p, 3u, 0, value); break;
        case 0x2114u: tp_scroll_write(p, 3u, 1, value); break;
        case 0x2115u:
            p->vram_increment = (value & 3u) == 0u ? 1u : (value & 3u) == 1u ? 32u : 128u;
            p->vram_remap = (uint8_t)((value >> 2u) & 3u); p->vram_increment_on_high = (uint8_t)(value >> 7u); break;
        case 0x2116u: p->vram_address = (uint16_t)((p->vram_address & 0xFF00u) | value); tp_vram_reload(p); break;
        case 0x2117u: p->vram_address = (uint16_t)((p->vram_address & 0x00FFu) | ((uint16_t)(value & 0x7Fu) << 8u)); tp_vram_reload(p); break;
        case 0x2118u: case 0x2119u:
            if (!tp_ppu_memory_accessible(p)) return p->failure = TP_BUS_STOP_PPU_UNAVAILABLE;
            a = (((uint32_t)tp_vram_mapped(p) << 1u) + (reg & 1u)) & 0xFFFFu;
            p->vram[a] = value; tp_mark(p->vram_known, a); p->storage_writes++;
            if (((reg == 0x2119u) ? 1u : 0u) == p->vram_increment_on_high)
                tp_vram_advance(p);
            break;
        case 0x211Au: break;
        case 0x211Bu: case 0x211Cu: case 0x211Du: case 0x211Eu:
            n = reg - 0x211Bu; p->mode7[n] = (uint16_t)(((uint16_t)value << 8u) | p->mode7_latch); p->mode7_latch = value; break;
        case 0x211Fu: p->mode7[4] = (uint16_t)(((uint16_t)value << 8u) | p->mode7_latch); p->mode7_latch = value; break;
        case 0x2120u: p->mode7[5] = (uint16_t)(((uint16_t)value << 8u) | p->mode7_latch); p->mode7_latch = value; break;
        case 0x2121u: p->cgram_address = value; p->cgram_second = 0u; break;
        case 0x2122u:
            if (!p->cgram_second) { p->cgram_latch = value; p->cgram_second = 1u; break; }
            if (!tp_ppu_memory_accessible(p)) return p->failure = TP_BUS_STOP_PPU_UNAVAILABLE;
            a = (uint32_t)p->cgram_address << 1u;
            p->cgram[a] = p->cgram_latch; p->cgram[a + 1u] = value & 0x7Fu;
            tp_mark(p->cgram_known, a); tp_mark(p->cgram_known, a + 1u); p->storage_writes += 2u;
            p->cgram_address++; p->cgram_second = 0u; break;
        case 0x2132u:
            if (value & 0x20u) p->fixed_color = (uint16_t)((p->fixed_color & 0x7FE0u) | (value & 0x1Fu));
            if (value & 0x40u) p->fixed_color = (uint16_t)((p->fixed_color & 0x7C1Fu) | ((uint16_t)(value & 0x1Fu) << 5u));
            if (value & 0x80u)
                p->fixed_color = (uint16_t)((p->fixed_color & 0x03FFu) |
                    ((uint16_t)(value & 0x1Fu) << 10u));
            break;
        case 0x2133u:
            p->overscan = (uint8_t)((value >> 2u) & 1u); p->interlace = value & 1u;
            tp_scheduler_set_display(p->scheduler, p->overscan, p->interlace); break;
        default: break;
    }
    return TP_BUS_OK;
}

TPBusStop tp_ppu_bus_read(void *opaque, uint16_t reg, uint8_t *value) {
    TPPpu *p = (TPPpu *)opaque;
    uint32_t a;
    uint8_t v;
    int32_t product;
    if (p == NULL || value == NULL || reg < 0x2100u || reg > 0x213Fu)
        return TP_BUS_STOP_PPU_UNAVAILABLE;
    p->register_reads[reg - 0x2100u]++;
    switch (reg) {
        case 0x2134u: case 0x2135u: case 0x2136u:
            product = tp_mode7_product(p); v = (uint8_t)((uint32_t)product >> (8u * (reg - 0x2134u))); break;
        case 0x2137u:
            p->latched_hcounter = p->scheduler ? p->scheduler->h_counter : 0u;
            p->latched_vcounter = p->scheduler ? p->scheduler->v_counter : 0u;
            p->counter_latched = 1u; p->hcounter_second = p->vcounter_second = 0u;
            if (!p->ppu1_open_bus_known) return p->failure = TP_BUS_STOP_PPU_UNAVAILABLE;
            v = p->ppu1_open_bus; break;
        case 0x2138u:
            if (!tp_ppu_memory_accessible(p)) return p->failure = TP_BUS_STOP_PPU_UNAVAILABLE;
            a = tp_oam_physical(p->oam_address); if (!tp_known(p->oam_known, a)) return p->failure = TP_BUS_STOP_PPU_UNAVAILABLE;
            v = p->oam[a]; p->oam_address = (uint16_t)((p->oam_address + 1u) & 0x03FFu); p->storage_reads++; break;
        case 0x2139u: case 0x213Au:
            if (!tp_ppu_memory_accessible(p) || !p->vram_read_buffer_known) return p->failure = TP_BUS_STOP_PPU_UNAVAILABLE;
            v = reg == 0x2139u ? (uint8_t)p->vram_read_buffer : (uint8_t)(p->vram_read_buffer >> 8u);
            if (((reg == 0x213Au) ? 1u : 0u) == p->vram_increment_on_high) {
                tp_vram_advance(p);
                tp_vram_reload(p);
            }
            p->storage_reads++; break;
        case 0x213Bu:
            if (!tp_ppu_memory_accessible(p)) return p->failure = TP_BUS_STOP_PPU_UNAVAILABLE;
            a = ((uint32_t)p->cgram_address << 1u) | p->cgram_second;
            if (!tp_known(p->cgram_known, a)) return p->failure = TP_BUS_STOP_PPU_UNAVAILABLE;
            v = p->cgram[a]; if (p->cgram_second) { v &= 0x7Fu; p->cgram_address++; } p->cgram_second ^= 1u; p->storage_reads++; break;
        case 0x213Cu:
            if (!p->counter_latched) { p->latched_hcounter = p->scheduler ? p->scheduler->h_counter : 0u; }
            v = p->hcounter_second ? (uint8_t)((p->latched_hcounter >> 8u) & 1u) : (uint8_t)p->latched_hcounter; p->hcounter_second ^= 1u; break;
        case 0x213Du:
            if (!p->counter_latched) { p->latched_vcounter = p->scheduler ? p->scheduler->v_counter : 0u; }
            v = p->vcounter_second ? (uint8_t)((p->latched_vcounter >> 8u) & 1u) : (uint8_t)p->latched_vcounter; p->vcounter_second ^= 1u; break;
        case 0x213Eu: v = (uint8_t)(1u | (p->obj_time_over ? 0x40u : 0u) |
                                    (p->obj_range_over ? 0x80u : 0u)); break;
        case 0x213Fu:
            v = (uint8_t)(0x13u | (p->scheduler && p->scheduler->field ? 0x80u : 0u) |
                          (p->counter_latched ? 0x40u : 0u)); p->counter_latched = 0u; p->hcounter_second = p->vcounter_second = 0u; break;
        default:
            if (!p->ppu1_open_bus_known) return p->failure = TP_BUS_STOP_PPU_UNAVAILABLE;
            v = p->ppu1_open_bus; break;
    }
    if (reg <= 0x213Au) { p->ppu1_open_bus = v; p->ppu1_open_bus_known = 1u; }
    else { p->ppu2_open_bus = v; p->ppu2_open_bus_known = 1u; }
    *value = v;
    return TP_BUS_OK;
}
