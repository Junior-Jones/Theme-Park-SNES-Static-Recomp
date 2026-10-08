#include "theme_park_bus.h"
#include "theme_park_scheduler.h"
#include "theme_park_v09_timing.h"

#include <string.h>

static int tp_system_bank(uint8_t bank) {
    return bank <= 0x3Fu || (bank >= 0x80u && bank <= 0xBFu);
}

static uint32_t tp_lorom_offset(uint8_t bank, uint16_t local) {
    /* The exact 1 MiB board exposes 32 physical 32 KiB blocks. A15 and the
       address lines above physical A19 are not cartridge-ROM address inputs. */
    return ((uint32_t)(bank & 0x1Fu) << 15u) | (uint32_t)(local & 0x7FFFu);
}

static int tp_wram_known(const TPBus *bus, uint32_t offset) {
    return (bus->wram_known[offset >> 3u] & (uint8_t)(1u << (offset & 7u))) != 0u;
}

static void tp_set_wram_known(TPBus *bus, uint32_t offset) {
    bus->wram_known[offset >> 3u] = (uint8_t)(bus->wram_known[offset >> 3u] |
                                              (uint8_t)(1u << (offset & 7u)));
}

static TPBusStop tp_fail(TPBus *bus, TPBusStop reason, uint32_t address, uint8_t value) {
    if (bus != NULL) {
        bus->failure.reason = reason;
        bus->failure.address = address & 0xFFFFFFu;
        bus->failure.value = value;
    }
    return reason;
}

const char *tp_bus_region_name(TPBusRegion region) {
    static const char *const names[TP_BUS_REGION_COUNT] = {
        "OPEN_BUS", "WRAM", "ROM", "PPU", "APUIO", "WRAM_PORT",
        "INPUT", "CPU_IO", "DMA"
    };
    return region < TP_BUS_REGION_COUNT ? names[region] : "INVALID";
}

const char *tp_bus_stop_name(TPBusStop stop) {
    static const char *const names[] = {
        "OK", "ARGUMENT", "WRONG_ROM", "MAPPING", "UNKNOWN_WRAM",
        "UNKNOWN_OPEN_BUS", "PPU_UNAVAILABLE", "APUIO_UNAVAILABLE",
        "INPUT_UNAVAILABLE", "TIMING_UNAVAILABLE", "DMA_UNAVAILABLE",
        "CODE_GUARD"
    };
    return (unsigned)stop < sizeof(names) / sizeof(names[0]) ? names[stop] : "INVALID";
}

TPBusMapping tp_bus_map(uint32_t address) {
    TPBusMapping out = { TP_BUS_OPEN, 0u, 1u, 0u };
    if (address > 0xFFFFFFu) {
        out.mapped = 0u;
        return out;
    }
    const uint32_t a = address & 0xFFFFFFu;
    const uint8_t bank = (uint8_t)(a >> 16u);
    const uint16_t local = (uint16_t)a;
    if (bank == 0x7Eu || bank == 0x7Fu) {
        out.region = TP_BUS_WRAM;
        out.physical_offset = ((uint32_t)(bank - 0x7Eu) << 16u) | local;
        out.writable = 1u;
        return out;
    }
    if (tp_system_bank(bank)) {
        if (local < 0x2000u) {
            out.region = TP_BUS_WRAM;
            out.physical_offset = local;
            out.writable = 1u;
            return out;
        }
        if (local >= 0x2100u && local <= 0x213Fu) {
            out.region = TP_BUS_PPU; out.writable = (uint8_t)(local <= 0x2133u); return out;
        }
        if (local >= 0x2140u && local <= 0x217Fu) {
            out.region = TP_BUS_APUIO; out.writable = 1u; return out;
        }
        if (local >= 0x2180u && local <= 0x2183u) {
            out.region = TP_BUS_WRAM_PORT; out.writable = 1u; return out;
        }
        if (local == 0x4016u || local == 0x4017u) {
            out.region = TP_BUS_INPUT; out.writable = (uint8_t)(local == 0x4016u); return out;
        }
        if (local >= 0x4200u && local <= 0x421Fu) {
            out.region = TP_BUS_CPU_IO; out.writable = (uint8_t)(local <= 0x420Du); return out;
        }
        if (local >= 0x4300u && local <= 0x437Fu) {
            out.region = TP_BUS_DMA; out.writable = 1u; return out;
        }
        if (local >= 0x8000u) {
            out.region = TP_BUS_ROM;
            out.physical_offset = tp_lorom_offset(bank, local);
            return out;
        }
        return out;
    }
    /* Zero-SRAM, no-coprocessor Theme Park board: cartridge windows in the
       non-system banks are ROM mirrors, except the dedicated WRAM banks above. */
    out.region = TP_BUS_ROM;
    out.physical_offset = tp_lorom_offset(bank, local);
    return out;
}

unsigned tp_bus_access_clocks(const TPBus *bus, uint32_t address) {
    const uint32_t a = address & 0xFFFFFFu;
    const uint8_t bank_class = (uint8_t)(a >> 22u);
    const uint8_t page = (uint8_t)(a >> 8u);
    const int fast = bus != NULL && (bus->memsel & 1u) != 0u;
    if (bank_class == 1u) return 8u;
    if (bank_class == 3u) return fast ? 6u : 8u;
    if (page <= 0x1Fu) return 8u;
    if (page <= 0x3Fu) return 6u;
    if (page == 0x40u || page == 0x41u) return 12u;
    if (page <= 0x5Fu) return 6u;
    if (page <= 0x7Fu) return 8u;
    return bank_class == 0u ? 8u : fast ? 6u : 8u;
}

static void tp_clear_accounting(TPBus *bus) {
    bus->access_clock_sum = 0u;
    bus->read_count = 0u;
    bus->write_count = 0u;
    bus->math_cpu_cycles_advanced = 0u;
    memset(bus->region_read_count, 0, sizeof(bus->region_read_count));
    memset(bus->region_write_count, 0, sizeof(bus->region_write_count));
}

TPBusStop tp_bus_power_on(TPBus *bus, const uint8_t *rom, size_t rom_size,
                          TPBusPorts ports) {
    return tp_bus_power_on_profile(bus, rom, rom_size, ports,
                                   TP_POWER_ON_STRICT_UNKNOWN);
}

TPBusStop tp_bus_power_on_profile(TPBus *bus, const uint8_t *rom,
                                  size_t rom_size, TPBusPorts ports,
                                  TPPowerOnProfile profile) {
    if (bus == NULL || rom == NULL) return TP_BUS_STOP_ARGUMENT;
    if (rom_size != TP_BUS_ROM_SIZE) return TP_BUS_STOP_WRONG_ROM;
    if (profile != TP_POWER_ON_STRICT_UNKNOWN &&
        profile != TP_POWER_ON_DETERMINISTIC_ZERO_WRAM_V1)
        return TP_BUS_STOP_ARGUMENT;
    memset(bus, 0, sizeof(*bus));
    bus->rom = rom;
    bus->rom_size = rom_size;
    bus->ports = ports;
    bus->power_on_profile = profile;
    /* Representative bytes are zero, but all WRAM and MDR bits start unknown.
       Production may not convert this deterministic representation into a claim
       that physical power-on RAM is zero. */
    if (profile == TP_POWER_ON_DETERMINISTIC_ZERO_WRAM_V1) {
        memset(bus->wram, 0, sizeof(bus->wram));
        memset(bus->wram_known, 0xFF, sizeof(bus->wram_known));
    }
    bus->wrio = 0xFFu;
    bus->htime = 0x01FFu;
    bus->vtime = 0x01FFu;
    bus->math.multiplicand = 0xFFu;
    bus->math.dividend = 0xFFFFu;
    return TP_BUS_OK;
}

TPBusStop tp_bus_sample_reset_vector(const TPBus *bus, uint16_t *vector) {
    uint8_t lo;
    uint8_t hi;
    if (bus == NULL || vector == NULL) return TP_BUS_STOP_ARGUMENT;
    if (tp_bus_peek8(bus, 0x00FFFCu, &lo) != TP_BUS_OK ||
        tp_bus_peek8(bus, 0x00FFFDu, &hi) != TP_BUS_OK) return TP_BUS_STOP_MAPPING;
    *vector = (uint16_t)(lo | ((uint16_t)hi << 8u));
    return TP_BUS_OK;
}

TPBusStop tp_bus_reset(TPBus *bus, TPScpuState *cpu) {
    uint16_t vector;
    TPBusStop result;
    if (bus == NULL || cpu == NULL) return TP_BUS_STOP_ARGUMENT;
    result = tp_bus_sample_reset_vector(bus, &vector);
    if (result != TP_BUS_OK) return tp_fail(bus, result, 0x00FFFCu, 0u);
    /* RESET is not power-on: WRAM/knownness, MDR, WRIO, timer latches, MEMSEL,
       WMADD and an in-flight math operation remain. NMITIMEN enable state resets. */
    bus->nmitimen = 0u;
    bus->failure.reason = TP_BUS_OK;
    tp_clear_accounting(bus);
    /* RESET establishes control state; it does not invent power-on values for
       A/X/Y or the low byte of S. Entering emulation mode truncates X and Y. */
    cpu->x &= 0x00FFu;
    cpu->y &= 0x00FFu;
    cpu->s = (uint16_t)(0x0100u | (cpu->s & 0x00FFu));
    cpu->d = 0u;
    cpu->dbr = 0u;
    cpu->pbr = 0u;
    cpu->pc = vector;
    cpu->p = (uint8_t)((cpu->p | TP_P_I | TP_P_M | TP_P_X) & (uint8_t)~TP_P_D);
    cpu->e = 1u;
    cpu->waiting = 0u;
    cpu->stopped = 0u;
    cpu->completed_cycles = 0u;
    memset(&cpu->failure, 0, sizeof(cpu->failure));
    return TP_BUS_OK;
}

TPBusStop tp_bus_peek8(const TPBus *bus, uint32_t address, uint8_t *value) {
    const TPBusMapping map = tp_bus_map(address);
    if (bus == NULL || value == NULL) return TP_BUS_STOP_ARGUMENT;
    if (!map.mapped) return TP_BUS_STOP_MAPPING;
    if (map.region == TP_BUS_ROM) {
        if (bus->rom == NULL || bus->rom_size != TP_BUS_ROM_SIZE ||
            map.physical_offset >= bus->rom_size) return TP_BUS_STOP_MAPPING;
        *value = bus->rom[map.physical_offset];
        return TP_BUS_OK;
    }
    if (map.region == TP_BUS_WRAM) {
        if (!tp_wram_known(bus, map.physical_offset)) return TP_BUS_STOP_UNKNOWN_WRAM;
        *value = bus->wram[map.physical_offset];
        return TP_BUS_OK;
    }
    return TP_BUS_STOP_MAPPING;
}

static TPBusStop tp_port_read(TPBusPort port, TPBusStop missing,
                              uint16_t reg, uint8_t *value) {
    return port.read8 != NULL ? port.read8(port.opaque, reg, value) : missing;
}

static TPBusStop tp_port_write(TPBusPort port, TPBusStop missing,
                               uint16_t reg, uint8_t value) {
    return port.write8 != NULL ? port.write8(port.opaque, reg, value) : missing;
}

static TPBusStop tp_cpu_io_read(TPBus *bus, uint16_t reg, uint8_t *value) {
    switch (reg) {
        case 0x4210u: case 0x4211u: case 0x4212u: {
            uint8_t raw = 0u;
            TPBusStop result = tp_port_read(bus->ports.timing,
                                            TP_BUS_STOP_TIMING_UNAVAILABLE, reg, &raw);
            if (result != TP_BUS_OK) return result;
            if (reg == 0x4210u)
                *value = (uint8_t)((raw & 0x80u) | 0x02u | (bus->open_bus & 0x70u));
            else if (reg == 0x4211u)
                *value = (uint8_t)((raw & 0x80u) | (bus->open_bus & 0x7Fu));
            else
                *value = (uint8_t)((raw & 0xC1u) | (bus->open_bus & 0x3Eu));
            return TP_BUS_OK;
        }
        case 0x4213u: *value = bus->wrio; return TP_BUS_OK;
        case 0x4214u: *value = (uint8_t)bus->math.quotient; return TP_BUS_OK;
        case 0x4215u: *value = (uint8_t)(bus->math.quotient >> 8u); return TP_BUS_OK;
        case 0x4216u: *value = (uint8_t)bus->math.remainder_or_product; return TP_BUS_OK;
        case 0x4217u: *value = (uint8_t)(bus->math.remainder_or_product >> 8u); return TP_BUS_OK;
        case 0x4218u: case 0x4219u: case 0x421Au: case 0x421Bu:
        case 0x421Cu: case 0x421Du: case 0x421Eu: case 0x421Fu:
            return tp_port_read(bus->ports.input, TP_BUS_STOP_INPUT_UNAVAILABLE, reg, value);
        default:
            if (!bus->open_bus_known) return TP_BUS_STOP_UNKNOWN_OPEN_BUS;
            *value = bus->open_bus;
            return TP_BUS_OK;
    }
}

static TPBusStop tp_cpu_io_write(TPBus *bus, uint16_t reg, uint8_t value) {
    switch (reg) {
        case 0x4200u:
            bus->nmitimen = value;
            return tp_port_write(bus->ports.timing, TP_BUS_STOP_TIMING_UNAVAILABLE, reg, value);
        case 0x4201u: bus->wrio = value; return TP_BUS_OK;
        case 0x4202u: bus->math.multiplicand = value; return TP_BUS_OK;
        case 0x4203u:
            bus->math.remainder_or_product = 0u;
            if (bus->math.multiply_cycles_remaining == 0u &&
                bus->math.divide_cycles_remaining == 0u) {
                bus->math.multiplier = value;
                bus->math.quotient = (uint16_t)(((uint16_t)value << 8u) |
                                                bus->math.multiplicand);
                bus->math.shift = value;
                bus->math.multiply_cycles_remaining = 8u;
            }
            return TP_BUS_OK;
        case 0x4204u:
            bus->math.dividend = (uint16_t)((bus->math.dividend & 0xFF00u) | value);
            return TP_BUS_OK;
        case 0x4205u:
            bus->math.dividend = (uint16_t)((bus->math.dividend & 0x00FFu) |
                                            ((uint16_t)value << 8u));
            return TP_BUS_OK;
        case 0x4206u:
            bus->math.remainder_or_product = bus->math.dividend;
            if (bus->math.multiply_cycles_remaining == 0u &&
                bus->math.divide_cycles_remaining == 0u) {
                bus->math.divisor = value;
                bus->math.shift = (uint32_t)value << 16u;
                bus->math.divide_cycles_remaining = 16u;
            }
            return TP_BUS_OK;
        case 0x4207u:
            bus->htime = (uint16_t)((bus->htime & 0x100u) | value);
            return tp_port_write(bus->ports.timing, TP_BUS_STOP_TIMING_UNAVAILABLE, reg, value);
        case 0x4208u:
            bus->htime = (uint16_t)((bus->htime & 0x0FFu) | ((uint16_t)(value & 1u) << 8u));
            return tp_port_write(bus->ports.timing, TP_BUS_STOP_TIMING_UNAVAILABLE, reg, value);
        case 0x4209u:
            bus->vtime = (uint16_t)((bus->vtime & 0x100u) | value);
            return tp_port_write(bus->ports.timing, TP_BUS_STOP_TIMING_UNAVAILABLE, reg, value);
        case 0x420Au:
            bus->vtime = (uint16_t)((bus->vtime & 0x0FFu) | ((uint16_t)(value & 1u) << 8u));
            return tp_port_write(bus->ports.timing, TP_BUS_STOP_TIMING_UNAVAILABLE, reg, value);
        case 0x420Bu: case 0x420Cu: {
            TPBusStop timing = tp_port_write(bus->ports.timing,
                                             TP_BUS_STOP_TIMING_UNAVAILABLE, reg, value);
            if (timing != TP_BUS_OK) return timing;
            return tp_port_write(bus->ports.dma, TP_BUS_STOP_DMA_UNAVAILABLE, reg, value);
        }
        case 0x420Du: bus->memsel = (uint8_t)(value & 1u); return TP_BUS_OK;
        default: return TP_BUS_OK;
    }
}

static void tp_math_cycle(TPBusMath *math) {
    if (math->multiply_cycles_remaining != 0u) {
        math->multiply_cycles_remaining--;
        if ((math->quotient & 1u) != 0u)
            math->remainder_or_product = (uint16_t)(math->remainder_or_product +
                                                     (uint16_t)math->shift);
        math->shift <<= 1u;
        math->quotient >>= 1u;
    }
    if (math->divide_cycles_remaining != 0u) {
        math->divide_cycles_remaining--;
        math->shift >>= 1u;
        math->quotient = (uint16_t)(math->quotient << 1u);
        if ((uint32_t)math->remainder_or_product >= math->shift) {
            math->remainder_or_product = (uint16_t)((uint32_t)math->remainder_or_product -
                                                    math->shift);
            math->quotient = (uint16_t)(math->quotient | 1u);
        }
    }
}

void tp_bus_advance_cpu_cycles(TPBus *bus, unsigned cycles) {
    if (bus == NULL) return;
    while (cycles-- != 0u) {
        tp_math_cycle(&bus->math);
        bus->math_cpu_cycles_advanced++;
    }
}

TPBusStop tp_bus_read8(TPBus *bus, uint32_t address, uint8_t *value) {
    const uint32_t a = address & 0xFFFFFFu;
    const uint16_t reg = (uint16_t)a;
    const TPBusMapping map = tp_bus_map(address);
    TPBusStop result = TP_BUS_OK;
    uint8_t v = 0u;
    int updates_mdr = 0;
    if (bus == NULL || value == NULL) return TP_BUS_STOP_ARGUMENT;
    if (!map.mapped) return tp_fail(bus, TP_BUS_STOP_MAPPING, address, 0u);
    bus->access_clock_sum += tp_bus_access_clocks(bus, a);
    bus->read_count++;
    bus->region_read_count[map.region]++;
    switch (map.region) {
        case TP_BUS_WRAM:
            if (!tp_wram_known(bus, map.physical_offset)) result = TP_BUS_STOP_UNKNOWN_WRAM;
            else { v = bus->wram[map.physical_offset]; updates_mdr = 1; }
            break;
        case TP_BUS_ROM:
            if (bus->rom == NULL || map.physical_offset >= bus->rom_size) result = TP_BUS_STOP_MAPPING;
            else { v = bus->rom[map.physical_offset]; updates_mdr = 1; }
            break;
        case TP_BUS_PPU:
            result = tp_port_read(bus->ports.ppu, TP_BUS_STOP_PPU_UNAVAILABLE, reg, &v);
            updates_mdr = 1;
            break;
        case TP_BUS_APUIO:
            result = tp_port_read(bus->ports.apuio, TP_BUS_STOP_APUIO_UNAVAILABLE,
                                  (uint16_t)(0x2140u | (reg & 3u)), &v);
            updates_mdr = 1;
            break;
        case TP_BUS_WRAM_PORT:
            if (reg != 0x2180u) {
                if (!bus->open_bus_known) result = TP_BUS_STOP_UNKNOWN_OPEN_BUS;
                else v = bus->open_bus;
            } else if (!tp_wram_known(bus, bus->wram_port_address)) {
                result = TP_BUS_STOP_UNKNOWN_WRAM;
            } else {
                v = bus->wram[bus->wram_port_address];
                bus->wram_port_address = (bus->wram_port_address + 1u) & 0x1FFFFu;
            }
            updates_mdr = 1;
            break;
        case TP_BUS_INPUT:
            result = tp_port_read(bus->ports.input, TP_BUS_STOP_INPUT_UNAVAILABLE, reg, &v);
            break;
        case TP_BUS_CPU_IO:
            result = tp_cpu_io_read(bus, reg, &v);
            break;
        case TP_BUS_DMA:
            result = tp_port_read(bus->ports.dma, TP_BUS_STOP_DMA_UNAVAILABLE, reg, &v);
            break;
        case TP_BUS_OPEN:
        default:
            if (!bus->open_bus_known) result = TP_BUS_STOP_UNKNOWN_OPEN_BUS;
            else v = bus->open_bus;
            updates_mdr = 1;
            break;
    }
    if (result != TP_BUS_OK) return tp_fail(bus, result, a, 0u);
    if (updates_mdr) { bus->open_bus = v; bus->open_bus_known = 1u; }
    *value = v;
    return TP_BUS_OK;
}

TPBusStop tp_bus_write8(TPBus *bus, uint32_t address, uint8_t value) {
    const uint32_t a = address & 0xFFFFFFu;
    const uint16_t reg = (uint16_t)a;
    const TPBusMapping map = tp_bus_map(address);
    TPBusStop result = TP_BUS_OK;
    int updates_mdr = 0;
    if (bus == NULL) return TP_BUS_STOP_ARGUMENT;
    if (!map.mapped) return tp_fail(bus, TP_BUS_STOP_MAPPING, address, value);
    bus->access_clock_sum += tp_bus_access_clocks(bus, a);
    bus->write_count++;
    bus->region_write_count[map.region]++;
    switch (map.region) {
        case TP_BUS_WRAM:
            bus->wram[map.physical_offset] = value;
            tp_set_wram_known(bus, map.physical_offset);
            updates_mdr = 1;
            break;
        case TP_BUS_ROM:
            updates_mdr = 1; /* Read-only cartridge ignores the write. */
            break;
        case TP_BUS_PPU:
            result = tp_port_write(bus->ports.ppu, TP_BUS_STOP_PPU_UNAVAILABLE, reg, value);
            updates_mdr = 1;
            break;
        case TP_BUS_APUIO:
            result = tp_port_write(bus->ports.apuio, TP_BUS_STOP_APUIO_UNAVAILABLE,
                                   (uint16_t)(0x2140u | (reg & 3u)), value);
            updates_mdr = 1;
            break;
        case TP_BUS_WRAM_PORT:
            if (reg == 0x2180u) {
                bus->wram[bus->wram_port_address] = value;
                tp_set_wram_known(bus, bus->wram_port_address);
                bus->wram_port_address = (bus->wram_port_address + 1u) & 0x1FFFFu;
            } else if (reg == 0x2181u) {
                bus->wram_port_address = (bus->wram_port_address & 0x1FF00u) | value;
            } else if (reg == 0x2182u) {
                bus->wram_port_address = (bus->wram_port_address & 0x100FFu) |
                                         ((uint32_t)value << 8u);
            } else {
                bus->wram_port_address = (bus->wram_port_address & 0x0FFFFu) |
                                         ((uint32_t)(value & 1u) << 16u);
            }
            updates_mdr = 1;
            break;
        case TP_BUS_INPUT:
            result = reg == 0x4016u
                ? tp_port_write(bus->ports.input, TP_BUS_STOP_INPUT_UNAVAILABLE, reg, value)
                : TP_BUS_OK;
            break;
        case TP_BUS_CPU_IO:
            result = tp_cpu_io_write(bus, reg, value);
            break;
        case TP_BUS_DMA:
            result = tp_port_write(bus->ports.dma, TP_BUS_STOP_DMA_UNAVAILABLE, reg, value);
            break;
        case TP_BUS_OPEN:
        default:
            updates_mdr = 1;
            break;
    }
    if (result != TP_BUS_OK) return tp_fail(bus, result, a, value);
    if (updates_mdr) { bus->open_bus = value; bus->open_bus_known = 1u; }
    return TP_BUS_OK;
}

static int tp_timing_advance_cycle(TPBus *bus, uint32_t clocks) {
    if (bus->scheduler == NULL ||
        tp_scheduler_advance_cpu_cycle(bus->scheduler, clocks) != TP_SCHEDULER_OK) {
        tp_fail(bus, TP_BUS_STOP_TIMING_UNAVAILABLE, 0u, 0u);
        return 0;
    }
    tp_math_cycle(&bus->math);
    bus->math_cpu_cycles_advanced++;
    bus->timing_cpu_cycles++;
    return 1;
}

static int tp_timing_idle(TPBus *bus) {
    return tp_timing_advance_cycle(bus, 6u);
}

static int tp_timed_read(TPBus *bus, uint32_t address, uint8_t *value) {
    const uint32_t clocks = tp_bus_access_clocks(bus, address);
    if (bus->scheduler == NULL ||
        tp_scheduler_cpu_cycle_boundary(bus->scheduler) != TP_SCHEDULER_OK ||
        tp_scheduler_advance_cpu(bus->scheduler, clocks - 4u) != TP_SCHEDULER_OK) {
        tp_fail(bus, TP_BUS_STOP_TIMING_UNAVAILABLE, address, 0u);
        return 0;
    }
    /* $4202-$4206 arithmetic advances once per S-CPU bus cycle.  Advance
       before sampling the data bus so a result completing on this cycle is
       visible to reads of $4214-$4217. */
    tp_math_cycle(&bus->math);
    bus->math_cpu_cycles_advanced++;
    if (tp_bus_read8(bus, address, value) != TP_BUS_OK) return 0;
    if (tp_scheduler_advance_cpu(bus->scheduler, 4u) != TP_SCHEDULER_OK) {
        tp_fail(bus, TP_BUS_STOP_TIMING_UNAVAILABLE, address, 0u);
        return 0;
    }
    bus->timing_cpu_cycles++;
    return 1;
}

static int tp_timed_write(TPBus *bus, uint32_t address, uint8_t value) {
    const uint32_t clocks = tp_bus_access_clocks(bus, address);
    if (bus->scheduler == NULL ||
        tp_scheduler_advance_cpu_cycle(bus->scheduler, clocks) != TP_SCHEDULER_OK) {
        tp_fail(bus, TP_BUS_STOP_TIMING_UNAVAILABLE, address, value);
        return 0;
    }
    /* Advance an already-running operation before committing this cycle's
       write.  A write to $4203/$4206 starts the new operation after the
       triggering bus cycle, matching the following-cycle latency contract. */
    tp_math_cycle(&bus->math);
    bus->math_cpu_cycles_advanced++;
    if (tp_bus_write8(bus, address, value) != TP_BUS_OK) return 0;
    bus->timing_cpu_cycles++;
    return 1;
}

static int tp_branch_taken(uint8_t opcode, uint8_t p) {
    switch (opcode) {
        case 0x10u: return (p & TP_P_N) == 0u;
        case 0x30u: return (p & TP_P_N) != 0u;
        case 0x50u: return (p & TP_P_V) == 0u;
        case 0x70u: return (p & TP_P_V) != 0u;
        case 0x90u: return (p & TP_P_C) == 0u;
        case 0xB0u: return (p & TP_P_C) != 0u;
        case 0xD0u: return (p & TP_P_Z) == 0u;
        case 0xF0u: return (p & TP_P_Z) != 0u;
        default: return 0;
    }
}

static int tp_index_cross(const TPBus *bus, const TPScpuTimingPlan *plan) {
    uint16_t base;
    uint16_t index;
    if (plan->opcode == 0xB9u || plan->opcode == 0xBEu || plan->opcode == 0x99u) {
        base = (uint16_t)plan->operand; index = bus->timing_before.y;
    } else if (plan->opcode == 0xB1u && bus->timing_pointer_seen >= 2u) {
        base = (uint16_t)(bus->timing_pointer_low |
                          ((uint16_t)bus->timing_pointer_high << 8u));
        index = bus->timing_before.y;
    } else {
        base = (uint16_t)plan->operand; index = bus->timing_before.x;
    }
    return (base & 0xFF00u) != ((uint16_t)(base + index) & 0xFF00u);
}

static int tp_timing_before_access(TPBus *bus, int is_write) {
    const TPScpuTimingPlan *plan = (const TPScpuTimingPlan *)bus->active_timing_plan;
    const uint32_t flags = plan->flags;
    if (!bus->timing_pre_access_done) {
        if ((flags & TP_TIMING_DIRECT_LOW_PRE) != 0u &&
            (bus->timing_before.d & 0x00FFu) != 0u && !tp_timing_idle(bus)) return 0;
        bus->timing_pre_access_done = 1u;
    }
    if (!bus->timing_pre_stack_done) {
        if (is_write && (flags & TP_TIMING_STACK_PUSH_PRE) != 0u) {
            if (!tp_timing_idle(bus)) return 0;
            bus->timing_pre_stack_done = 1u;
        } else if (!is_write && (flags & TP_TIMING_STACK_PULL_PRE2) != 0u) {
            if (!tp_timing_idle(bus) || !tp_timing_idle(bus)) return 0;
            bus->timing_pre_stack_done = 1u;
        }
    }
    if (!bus->timing_index_done &&
        bus->timing_read_count >= plan->pointer_reads) {
        if ((flags & TP_TIMING_INDEX_FIXED_PRE_DATA) != 0u && !tp_timing_idle(bus)) return 0;
        if ((flags & TP_TIMING_INDEX_DYNAMIC_PRE_DATA) != 0u &&
            tp_index_cross(bus, plan) && !tp_timing_idle(bus)) return 0;
        bus->timing_index_done = 1u;
    }
    if (is_write && !bus->timing_rmw_done &&
        (flags & TP_TIMING_RMW_INTERMEDIATE) != 0u) {
        if (!tp_timing_idle(bus)) return 0;
        bus->timing_rmw_done = 1u;
    }
    return 1;
}

static int tp_scpu_guard_adapter(void *opaque, const TPScpuState *cpu,
                                 uint32_t address, const uint8_t *expected,
                                 size_t count) {
    TPBus *bus = (TPBus *)opaque;
    const TPScpuTimingPlan *plan = tp_v09_timing_plan(tp_scpu_context_key(cpu));
    size_t index;
    if (plan == NULL || plan->address != (address & 0xFFFFFFu) ||
        plan->length != count || plan->opcode != expected[0]) {
        tp_fail(bus, TP_BUS_STOP_TIMING_UNAVAILABLE, address, expected[0]);
        return 0;
    }
    bus->active_timing_plan = plan;
    bus->timing_before = *cpu;
    bus->timing_cpu_cycles = 0u;
    bus->timing_read_count = bus->timing_write_count = 0u;
    bus->timing_pointer_seen = bus->timing_pre_access_done = 0u;
    bus->timing_pre_stack_done = bus->timing_index_done = 0u;
    bus->timing_rmw_done = bus->timing_jsl_done = 0u;
    bus->timing_active = 1u;
    for (index = 0u; index < count; ++index) {
        uint8_t value = 0u;
        const uint32_t fetch = (address & 0xFF0000u) |
                               ((address + (uint32_t)index) & 0xFFFFu);
        if ((plan->flags & TP_TIMING_JSL_DEFERRED_BANK_FETCH) != 0u && index == 3u) {
            if (tp_bus_peek8(bus, fetch, &value) != TP_BUS_OK) return 0;
        } else if (!tp_timed_read(bus, fetch, &value)) return 0;
        if (value != expected[index]) {
            tp_fail(bus, TP_BUS_STOP_CODE_GUARD, fetch, value);
            return 0;
        }
    }
    if ((plan->flags & TP_TIMING_IMPLIED_PRE) != 0u && !tp_timing_idle(bus)) return 0;
    if ((plan->flags & TP_TIMING_EXTRA_IMPLIED_PRE) != 0u && !tp_timing_idle(bus)) return 0;
    if ((plan->flags & TP_TIMING_STATUS_PRE) != 0u && !tp_timing_idle(bus)) return 0;
    if ((plan->flags & TP_TIMING_RELLONG_PRE) != 0u && !tp_timing_idle(bus)) return 0;
    return 1;
}

static int tp_scpu_read_adapter(void *opaque, const TPScpuState *cpu,
                                uint32_t address, uint8_t *value) {
    TPBus *bus = (TPBus *)opaque;
    const TPScpuTimingPlan *plan = (const TPScpuTimingPlan *)bus->active_timing_plan;
    (void)cpu;
    if (!bus->timing_active || !tp_timing_before_access(bus, 0) ||
        !tp_timed_read(bus, address, value)) return 0;
    if (bus->timing_read_count < plan->pointer_reads) {
        if (bus->timing_pointer_seen == 0u) bus->timing_pointer_low = *value;
        else if (bus->timing_pointer_seen == 1u) bus->timing_pointer_high = *value;
        bus->timing_pointer_seen++;
    }
    bus->timing_read_count++;
    return 1;
}

static int tp_scpu_write_adapter(void *opaque, const TPScpuState *cpu,
                                 uint32_t address, uint8_t value) {
    TPBus *bus = (TPBus *)opaque;
    const TPScpuTimingPlan *plan = (const TPScpuTimingPlan *)bus->active_timing_plan;
    (void)cpu;
    if (!bus->timing_active || !tp_timing_before_access(bus, 1) ||
        !tp_timed_write(bus, address, value)) return 0;
    bus->timing_write_count++;
    if ((plan->flags & TP_TIMING_JSL_DEFERRED_BANK_FETCH) != 0u &&
        !bus->timing_jsl_done && bus->timing_write_count == 1u) {
        uint8_t value_read = 0u;
        const uint32_t fetch = (plan->address & 0xFF0000u) |
                               ((plan->address + 3u) & 0xFFFFu);
        if (!tp_timing_idle(bus) || !tp_timed_read(bus, fetch, &value_read) ||
            value_read != (uint8_t)(plan->operand >> 16u)) return 0;
        bus->timing_jsl_done = 1u;
    }
    return 1;
}

static int tp_scpu_finish_adapter(void *opaque, const TPScpuState *cpu,
                                  uint32_t *cycles) {
    TPBus *bus = (TPBus *)opaque;
    const TPScpuTimingPlan *plan = (const TPScpuTimingPlan *)bus->active_timing_plan;
    uint32_t flags;
    uint32_t exact_cycles;
    int taken;
    if (!bus->timing_active || plan == NULL || cycles == NULL) return 0;
    flags = plan->flags;
    exact_cycles = plan->base_cycles;
    if ((flags & TP_TIMING_RETURN_POST) != 0u && !tp_timing_idle(bus)) return 0;
    if ((flags & TP_TIMING_BRANCH_ALWAYS_POST) != 0u && !tp_timing_idle(bus)) return 0;
    if ((flags & TP_TIMING_DIRECT_LOW_PRE) != 0u &&
        (bus->timing_before.d & 0x00FFu) != 0u) exact_cycles++;
    if ((flags & TP_TIMING_INDEX_DYNAMIC_PRE_DATA) != 0u &&
        tp_index_cross(bus, plan)) exact_cycles++;
    taken = tp_branch_taken(plan->opcode, bus->timing_before.p);
    if ((flags & TP_TIMING_BRANCH_TAKEN_POST) != 0u && taken) {
        const uint16_t sequential = (uint16_t)(bus->timing_before.pc + plan->length);
        const uint16_t target = (uint16_t)(sequential + (int8_t)plan->operand);
        if (!tp_timing_idle(bus)) return 0;
        exact_cycles++;
        if ((flags & TP_TIMING_BRANCH_PAGE_POST) != 0u && bus->timing_before.e != 0u &&
            (sequential & 0xFF00u) != (target & 0xFF00u)) {
            if (!tp_timing_idle(bus)) return 0;
            exact_cycles++;
        }
    }
    bus->timing_active = 0u;
    *cycles = exact_cycles;
    if (bus->timing_cpu_cycles != exact_cycles) {
        tp_fail(bus, TP_BUS_STOP_TIMING_UNAVAILABLE, plan->address,
                (uint8_t)bus->timing_cpu_cycles);
        return 0;
    }
    if (cpu->waiting != 0u) tp_scheduler_enter_wai(bus->scheduler);
    if (cpu->stopped != 0u) tp_scheduler_enter_stp(bus->scheduler);
    (void)cpu;
    return 1;
}

void tp_bus_bind_scheduler(TPBus *bus, TPScheduler *scheduler) {
    if (bus != NULL) bus->scheduler = scheduler;
}

TPBusStop tp_bus_cpu_internal_cycle(TPBus *bus) {
    if (bus == NULL) return TP_BUS_STOP_ARGUMENT;
    return tp_timing_idle(bus) ? TP_BUS_OK : bus->failure.reason;
}

TPBusStop tp_bus_cpu_read_cycle(TPBus *bus, uint32_t address, uint8_t *value) {
    if (bus == NULL || value == NULL) return TP_BUS_STOP_ARGUMENT;
    return tp_timed_read(bus, address, value) ? TP_BUS_OK : bus->failure.reason;
}

TPBusStop tp_bus_cpu_write_cycle(TPBus *bus, uint32_t address, uint8_t value) {
    if (bus == NULL) return TP_BUS_STOP_ARGUMENT;
    return tp_timed_write(bus, address, value) ? TP_BUS_OK : bus->failure.reason;
}

TPScpuBus tp_bus_scpu_view(TPBus *bus) {
    TPScpuBus out;
    out.opaque = bus;
    out.guard_code = tp_scpu_guard_adapter;
    out.read8 = tp_scpu_read_adapter;
    out.write8 = tp_scpu_write_adapter;
    out.finish_instruction = tp_scpu_finish_adapter;
    return out;
}
