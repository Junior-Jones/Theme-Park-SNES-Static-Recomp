#include "theme_park_dma.h"

#include <string.h>

static const uint8_t tp_dma_count[8] = { 1u, 2u, 2u, 4u, 4u, 4u, 2u, 4u };
static const uint8_t tp_dma_offset[8][4] = {
    { 0u, 0u, 0u, 0u }, { 0u, 1u, 0u, 1u },
    { 0u, 0u, 0u, 0u }, { 0u, 0u, 1u, 1u },
    { 0u, 1u, 2u, 3u }, { 0u, 1u, 0u, 1u },
    { 0u, 0u, 0u, 0u }, { 0u, 0u, 1u, 1u }
};

static TPBusStop tp_dma_hdma_init(TPDma *dma, uint8_t mask, int nested);
static TPBusStop tp_dma_hdma_line(TPDma *dma, uint8_t mask, int nested);
static TPBusStop tp_dma_service_nested_hdma(TPDma *dma);

static int tp_dma_system_bank(uint8_t bank) {
    return bank <= 0x3Fu || (bank >= 0x80u && bank <= 0xBFu);
}

static int tp_dma_is_wram(uint32_t address) {
    const uint8_t bank = (uint8_t)(address >> 16u);
    const uint16_t offset = (uint16_t)address;
    return bank == 0x7Eu || bank == 0x7Fu ||
           (tp_dma_system_bank(bank) && offset <= 0x1FFFu);
}

static int tp_dma_a_bus_forbidden(uint32_t address) {
    const uint8_t bank = (uint8_t)(address >> 16u);
    const uint16_t offset = (uint16_t)address;
    return tp_dma_system_bank(bank) &&
           ((offset >= 0x2100u && offset <= 0x21FFu) ||
            offset == 0x420Bu || offset == 0x420Cu ||
            (offset >= 0x4300u && offset <= 0x437Fu));
}

static TPBusStop tp_dma_advance(TPDma *dma, uint32_t clocks) {
    if (dma == NULL || dma->scheduler == NULL) return TP_BUS_STOP_DMA_UNAVAILABLE;
    if (tp_scheduler_advance_dma(dma->scheduler, clocks) != TP_SCHEDULER_OK) {
        dma->failure = TP_BUS_STOP_TIMING_UNAVAILABLE;
        return dma->failure;
    }
    dma->transfer_master_clocks += clocks;
    return TP_BUS_OK;
}

static TPBusStop tp_dma_read_a(TPDma *dma, uint32_t address, uint8_t *value) {
    TPBusStop result = tp_dma_advance(dma, 4u);
    if (result != TP_BUS_OK) return result;
    if (tp_dma_a_bus_forbidden(address)) {
        if (!dma->bus->open_bus_known) return TP_BUS_STOP_UNKNOWN_OPEN_BUS;
        *value = dma->bus->open_bus;
        return TP_BUS_OK;
    }
    return tp_bus_read8(dma->bus, address, value);
}

static TPBusStop tp_dma_write_a(TPDma *dma, uint32_t address, uint8_t value) {
    TPBusStop result = tp_dma_advance(dma, 4u);
    if (result != TP_BUS_OK) return result;
    if (!tp_dma_a_bus_forbidden(address)) result = tp_bus_write8(dma->bus, address, value);
    if (result != TP_BUS_OK) return result;
    dma->bus->open_bus = value;
    dma->bus->open_bus_known = 1u;
    return result;
}

static TPBusStop tp_dma_read_b(TPDma *dma, uint16_t address, uint8_t *value) {
    TPBusStop result = tp_dma_advance(dma, 4u);
    if (result != TP_BUS_OK) return result;
    return tp_bus_read8(dma->bus, address, value);
}

static TPBusStop tp_dma_write_b(TPDma *dma, uint16_t address, uint8_t value) {
    TPBusStop result = tp_dma_advance(dma, 4u);
    if (result != TP_BUS_OK) return result;
    return tp_bus_write8(dma->bus, address, value);
}

static TPBusStop tp_dma_copy_byte(TPDma *dma, uint32_t a, uint16_t b,
                                  int b_to_a) {
    uint8_t value;
    TPBusStop result;
    const int conflict = b == 0x2180u && tp_dma_is_wram(a);
    if (b_to_a) {
        if (conflict) {
            result = tp_dma_advance(dma, 4u);
            if (result == TP_BUS_OK) result = tp_dma_write_a(dma, a, 0xFFu);
        } else {
            result = tp_dma_read_b(dma, b, &value);
            if (result == TP_BUS_OK) result = tp_dma_write_a(dma, a, value);
        }
    } else if (conflict) {
        result = tp_dma_advance(dma, 8u);
    } else {
        result = tp_dma_read_a(dma, a, &value);
        if (result == TP_BUS_OK) result = tp_dma_write_b(dma, b, value);
    }
    if (result != TP_BUS_OK) { dma->failure = result; return result; }
    dma->transfer_bytes++;
    if (conflict) dma->wram_conflicts++;
    return TP_BUS_OK;
}

static TPBusStop tp_dma_table_read(TPDma *dma, uint32_t address, uint8_t *value) {
    TPBusStop result = tp_dma_read_a(dma, address, value);
    return result == TP_BUS_OK ? tp_dma_advance(dma, 4u) : result;
}

static TPBusStop tp_dma_sync_start(TPDma *dma) {
    const uint32_t clocks = 8u - (uint32_t)(dma->scheduler->master_clock & 7u);
    return tp_dma_advance(dma, clocks);
}

static TPBusStop tp_dma_sync_end(TPDma *dma) {
    uint32_t speed = dma->scheduler->cpu_cycle_clocks;
    uint32_t clocks;
    if (speed != 6u && speed != 8u && speed != 12u) speed = 8u;
    clocks = speed - (uint32_t)(dma->transfer_master_clocks % speed);
    return tp_dma_advance(dma, clocks);
}

static TPBusStop tp_dma_manual(TPDma *dma, uint8_t mask) {
    unsigned index;
    unsigned drain_guard;
    TPBusStop result = tp_dma_sync_start(dma);
    if (result != TP_BUS_OK) return result;
    result = tp_dma_advance(dma, 8u);
    if (result != TP_BUS_OK) return result;
    for (index = 0u; index < 8u; ++index) {
        TPDmaChannel *channel = &dma->channel[index];
        uint32_t phase = 0u;
        if ((mask & (uint8_t)(1u << index)) == 0u || channel->dma_active == 0u) continue;
        dma->active_channel = (uint8_t)index;
        result = tp_dma_advance(dma, 8u);
        if (result != TP_BUS_OK) return result;
        do {
            const uint8_t mode = (uint8_t)(channel->dmap & 7u);
            const uint32_t a = ((uint32_t)channel->a1b << 16u) | channel->a1t;
            const uint16_t b = (uint16_t)(0x2100u |
                (uint8_t)(channel->bbad + tp_dma_offset[mode][phase & 3u]));
            result = tp_dma_copy_byte(dma, a, b, (channel->dmap & 0x80u) != 0u);
            if (result != TP_BUS_OK) return result;
            result = tp_dma_service_nested_hdma(dma);
            if (result != TP_BUS_OK) return result;
            if ((channel->dmap & 0x08u) == 0u)
                channel->a1t = (uint16_t)(channel->a1t +
                    ((channel->dmap & 0x10u) != 0u ? UINT16_C(0xFFFF) : 1u));
            channel->das--;
            phase++;
        } while (channel->das != 0u && channel->dma_active != 0u);
        channel->dma_active = 0u;
    }
    for (drain_guard = 0u; drain_guard < 4u &&
         (dma->scheduler->hdma_line_pending != 0u ||
          dma->scheduler->hdma_init_pending != 0u); ++drain_guard) {
        result = tp_dma_service_nested_hdma(dma);
        if (result != TP_BUS_OK) return result;
    }
    if (dma->scheduler->hdma_line_pending != 0u ||
        dma->scheduler->hdma_init_pending != 0u) return TP_BUS_STOP_TIMING_UNAVAILABLE;
    dma->active_channel = 0xFFu;
    return tp_dma_sync_end(dma);
}

static TPBusStop tp_dma_hdma_init(TPDma *dma, uint8_t mask, int nested) {
    unsigned index;
    TPBusStop result = TP_BUS_OK;
    if (!nested) result = tp_dma_sync_start(dma);
    if (result != TP_BUS_OK) return result;
    result = tp_dma_advance(dma, 8u);
    if (result != TP_BUS_OK) return result;
    for (index = 0u; index < 8u; ++index) {
        TPDmaChannel *channel = &dma->channel[index];
        uint8_t low, high;
        channel->hdma_finished = 0u;
        channel->hdma_do_transfer = 1u;
        if ((mask & (uint8_t)(1u << index)) == 0u) continue;
        channel->a2a = channel->a1t;
        channel->dma_active = 0u;
        result = tp_dma_table_read(dma, ((uint32_t)channel->a1b << 16u) | channel->a2a, &channel->ntrl);
        if (result != TP_BUS_OK) return result;
        channel->a2a++;
        if (channel->ntrl == 0u) channel->hdma_finished = 1u;
        if ((channel->dmap & 0x40u) != 0u) {
            result = tp_dma_table_read(dma, ((uint32_t)channel->a1b << 16u) | channel->a2a++, &low);
            if (result != TP_BUS_OK) return result;
            if (channel->hdma_finished == 0u) {
                result = tp_dma_table_read(dma, ((uint32_t)channel->a1b << 16u) | channel->a2a++, &high);
                if (result != TP_BUS_OK) return result;
                channel->das = (uint16_t)(low | ((uint16_t)high << 8u));
            } else channel->das = (uint16_t)((uint16_t)low << 8u);
        }
    }
    return nested ? TP_BUS_OK : tp_dma_sync_end(dma);
}

static int tp_dma_last_hdma(const TPDma *dma, unsigned index, uint8_t mask) {
    for (++index; index < 8u; ++index)
        if ((mask & (uint8_t)(1u << index)) != 0u &&
            dma->channel[index].hdma_finished == 0u) return 0;
    return 1;
}

static TPBusStop tp_dma_hdma_line(TPDma *dma, uint8_t mask, int nested) {
    unsigned index;
    TPBusStop result = TP_BUS_OK;
    if (!nested) result = tp_dma_sync_start(dma);
    if (result != TP_BUS_OK) return result;
    result = tp_dma_advance(dma, 8u);
    if (result != TP_BUS_OK) return result;
    for (index = 0u; index < 8u; ++index) {
        TPDmaChannel *channel = &dma->channel[index];
        unsigned byte;
        const uint8_t mode = (uint8_t)(channel->dmap & 7u);
        if ((mask & (uint8_t)(1u << index)) == 0u || channel->hdma_finished != 0u ||
            channel->hdma_do_transfer == 0u) continue;
        dma->active_channel = (uint8_t)(0x80u | index);
        for (byte = 0u; byte < tp_dma_count[mode]; ++byte) {
            uint32_t a;
            const uint16_t b = (uint16_t)(0x2100u |
                (uint8_t)(channel->bbad + tp_dma_offset[mode][byte]));
            if ((channel->dmap & 0x40u) != 0u) {
                a = ((uint32_t)channel->dasb << 16u) | channel->das++;
            } else {
                a = ((uint32_t)channel->a1b << 16u) | channel->a2a++;
            }
            result = tp_dma_copy_byte(dma, a, b, (channel->dmap & 0x80u) != 0u);
            if (result != TP_BUS_OK) return result;
        }
    }
    for (index = 0u; index < 8u; ++index) {
        TPDmaChannel *channel = &dma->channel[index];
        uint8_t next, low, high;
        if ((mask & (uint8_t)(1u << index)) == 0u || channel->hdma_finished != 0u) continue;
        channel->ntrl--;
        channel->hdma_do_transfer = (uint8_t)((channel->ntrl & 0x80u) != 0u);
        if ((channel->ntrl & 0x7Fu) != 0u) continue;
        result = tp_dma_table_read(dma, ((uint32_t)channel->a1b << 16u) | channel->a2a++, &next);
        if (result != TP_BUS_OK) return result;
        channel->ntrl = next;
        if ((channel->dmap & 0x40u) != 0u) {
            if (next == 0u && tp_dma_last_hdma(dma, index, mask)) {
                result = tp_dma_table_read(dma, ((uint32_t)channel->a1b << 16u) | channel->a2a++, &high);
                if (result != TP_BUS_OK) return result;
                channel->das = (uint16_t)((uint16_t)high << 8u);
            } else {
                result = tp_dma_table_read(dma, ((uint32_t)channel->a1b << 16u) | channel->a2a++, &low);
                if (result != TP_BUS_OK) return result;
                result = tp_dma_table_read(dma, ((uint32_t)channel->a1b << 16u) | channel->a2a++, &high);
                if (result != TP_BUS_OK) return result;
                channel->das = (uint16_t)(low | ((uint16_t)high << 8u));
            }
        }
        if (next == 0u) channel->hdma_finished = 1u;
        channel->hdma_do_transfer = 1u;
    }
    dma->active_channel = 0xFFu;
    return nested ? TP_BUS_OK : tp_dma_sync_end(dma);
}

static TPBusStop tp_dma_service_nested_hdma(TPDma *dma) {
    uint8_t mask;
    uint8_t saved_active;
    TPBusStop result;
    if (dma->scheduler->dma_start_delay != 0u) {
        dma->scheduler->dma_start_delay--;
        return TP_BUS_OK;
    }
    mask = dma->scheduler->hdma_enable_mask;
    saved_active = dma->active_channel;
    if (dma->scheduler->hdma_line_pending != 0u) {
        dma->scheduler->hdma_line_pending = 0u;
        result = tp_dma_hdma_line(dma, mask, 1);
        dma->active_channel = saved_active;
        return result;
    }
    if (dma->scheduler->hdma_init_pending != 0u) {
        dma->scheduler->hdma_init_pending = 0u;
        result = mask != 0u ? tp_dma_hdma_init(dma, mask, 1) : TP_BUS_OK;
        dma->active_channel = saved_active;
        return result;
    }
    return TP_BUS_OK;
}

void tp_dma_power_on(TPDma *dma, TPBus *bus, TPScheduler *scheduler) {
    unsigned index;
    if (dma == NULL) return;
    memset(dma, 0, sizeof(*dma));
    dma->bus = bus;
    dma->scheduler = scheduler;
    dma->active_channel = 0xFFu;
    for (index = 0u; index < 8u; ++index) {
        TPDmaChannel *channel = &dma->channel[index];
        channel->dmap = 0xFFu; channel->bbad = 0xFFu; channel->a1t = 0xFFFFu;
        channel->a1b = 0xFFu; channel->das = 0xFFFFu; channel->dasb = 0xFFu;
        channel->a2a = 0xFFFFu; channel->ntrl = 0xFFu; channel->unused = 0xFFu;
    }
}

void tp_dma_reset(TPDma *dma) {
    unsigned index;
    if (dma == NULL) return;
    dma->hdma_enable = 0u;
    dma->active_channel = 0xFFu;
    dma->servicing = 0u;
    dma->failure = TP_BUS_OK;
    for (index = 0u; index < 8u; ++index) dma->channel[index].dma_active = 0u;
}

TPBusStop tp_dma_bus_read(void *opaque, uint16_t reg, uint8_t *value) {
    TPDma *dma = (TPDma *)opaque;
    TPDmaChannel *channel;
    uint8_t offset;
    if (dma == NULL || value == NULL || reg < 0x4300u || reg > 0x437Fu)
        return TP_BUS_STOP_DMA_UNAVAILABLE;
    channel = &dma->channel[(reg >> 4u) & 7u];
    offset = (uint8_t)(reg & 0x0Fu);
    switch (offset) {
        case 0u: *value = channel->dmap; break; case 1u: *value = channel->bbad; break;
        case 2u: *value = (uint8_t)channel->a1t; break; case 3u: *value = (uint8_t)(channel->a1t >> 8u); break;
        case 4u: *value = channel->a1b; break; case 5u: *value = (uint8_t)channel->das; break;
        case 6u: *value = (uint8_t)(channel->das >> 8u); break; case 7u: *value = channel->dasb; break;
        case 8u: *value = (uint8_t)channel->a2a; break; case 9u: *value = (uint8_t)(channel->a2a >> 8u); break;
        case 10u: *value = channel->ntrl; break;
        case 11u: case 15u: *value = channel->unused; break;
        default:
            if (!dma->bus->open_bus_known) return TP_BUS_STOP_UNKNOWN_OPEN_BUS;
            *value = dma->bus->open_bus;
            break;
    }
    return TP_BUS_OK;
}

TPBusStop tp_dma_bus_write(void *opaque, uint16_t reg, uint8_t value) {
    TPDma *dma = (TPDma *)opaque;
    TPDmaChannel *channel;
    uint8_t offset;
    unsigned index;
    if (dma == NULL) return TP_BUS_STOP_DMA_UNAVAILABLE;
    if (reg == 0x420Bu) {
        for (index = 0u; index < 8u; ++index)
            if ((value & (uint8_t)(1u << index)) != 0u) dma->channel[index].dma_active = 1u;
        return TP_BUS_OK;
    }
    if (reg == 0x420Cu) { dma->hdma_enable = value; return TP_BUS_OK; }
    if (reg < 0x4300u || reg > 0x437Fu) return TP_BUS_STOP_DMA_UNAVAILABLE;
    channel = &dma->channel[(reg >> 4u) & 7u];
    offset = (uint8_t)(reg & 0x0Fu);
    switch (offset) {
        case 0u: channel->dmap = value; break; case 1u: channel->bbad = value; break;
        case 2u: channel->a1t = (uint16_t)((channel->a1t & 0xFF00u) | value); break;
        case 3u: channel->a1t = (uint16_t)((channel->a1t & 0x00FFu) | ((uint16_t)value << 8u)); break;
        case 4u: channel->a1b = value; break;
        case 5u: channel->das = (uint16_t)((channel->das & 0xFF00u) | value); break;
        case 6u: channel->das = (uint16_t)((channel->das & 0x00FFu) | ((uint16_t)value << 8u)); break;
        case 7u: channel->dasb = value; break;
        case 8u: channel->a2a = (uint16_t)((channel->a2a & 0xFF00u) | value); break;
        case 9u: channel->a2a = (uint16_t)((channel->a2a & 0x00FFu) | ((uint16_t)value << 8u)); break;
        case 10u: channel->ntrl = value; break;
        case 11u: case 15u: channel->unused = value; break;
        default: break;
    }
    return TP_BUS_OK;
}

TPSchedulerStop tp_dma_scheduler_event(void *opaque, TPSchedulerDmaEvent event,
                                       uint8_t mask) {
    TPDma *dma = (TPDma *)opaque;
    TPBusStop result;
    if (dma == NULL || dma->servicing != 0u) return TP_SCHEDULER_STOP_DMA_UNAVAILABLE;
    dma->servicing = 1u;
    dma->transfer_master_clocks = 0u;
    if (event == TP_DMA_EVENT_MANUAL) result = tp_dma_manual(dma, mask);
    else if (event == TP_DMA_EVENT_HDMA_INIT) result = tp_dma_hdma_init(dma, mask, 0);
    else if (event == TP_DMA_EVENT_HDMA_LINE) result = tp_dma_hdma_line(dma, mask, 0);
    else result = TP_BUS_STOP_DMA_UNAVAILABLE;
    dma->servicing = 0u;
    if (result != TP_BUS_OK) { dma->failure = result; return TP_SCHEDULER_STOP_DMA_UNAVAILABLE; }
    dma->event_count++;
    return TP_SCHEDULER_OK;
}
