#ifndef THEME_PARK_BUS_H
#define THEME_PARK_BUS_H

#include <stddef.h>
#include <stdint.h>

#include "theme_park_scpu.h"

#ifdef __cplusplus
extern "C" {
#endif

struct TPScheduler;

#define TP_BUS_ROM_SIZE 0x100000u
#define TP_BUS_WRAM_SIZE 0x20000u
#define TP_BUS_ADDRESS_SPACE_SIZE 0x1000000u

typedef enum TPBusRegion {
    TP_BUS_OPEN = 0,
    TP_BUS_WRAM,
    TP_BUS_ROM,
    TP_BUS_PPU,
    TP_BUS_APUIO,
    TP_BUS_WRAM_PORT,
    TP_BUS_INPUT,
    TP_BUS_CPU_IO,
    TP_BUS_DMA,
    TP_BUS_REGION_COUNT
} TPBusRegion;

typedef enum TPBusStop {
    TP_BUS_OK = 0,
    TP_BUS_STOP_ARGUMENT,
    TP_BUS_STOP_WRONG_ROM,
    TP_BUS_STOP_MAPPING,
    TP_BUS_STOP_UNKNOWN_WRAM,
    TP_BUS_STOP_UNKNOWN_OPEN_BUS,
    TP_BUS_STOP_PPU_UNAVAILABLE,
    TP_BUS_STOP_APUIO_UNAVAILABLE,
    TP_BUS_STOP_INPUT_UNAVAILABLE,
    TP_BUS_STOP_TIMING_UNAVAILABLE,
    TP_BUS_STOP_DMA_UNAVAILABLE,
    TP_BUS_STOP_CODE_GUARD
} TPBusStop;

/* Project-selected validation policy for genuinely unspecified power-on WRAM.
 * STRICT_UNKNOWN is the production/source-authority default.  ZERO_WRAM_V1 is
 * an explicit reproducible hardware profile, not a claim about every SNES. */
typedef enum TPPowerOnProfile {
    TP_POWER_ON_STRICT_UNKNOWN = 0,
    TP_POWER_ON_DETERMINISTIC_ZERO_WRAM_V1 = 1
} TPPowerOnProfile;

typedef struct TPBusMapping {
    TPBusRegion region;
    uint32_t physical_offset;
    uint8_t mapped;
    uint8_t writable;
} TPBusMapping;

typedef TPBusStop (*TPBusReadPort)(void *opaque, uint16_t reg, uint8_t *value);
typedef TPBusStop (*TPBusWritePort)(void *opaque, uint16_t reg, uint8_t value);

typedef struct TPBusPort {
    void *opaque;
    TPBusReadPort read8;
    TPBusWritePort write8;
} TPBusPort;

typedef struct TPBusPorts {
    TPBusPort ppu;
    TPBusPort apuio;
    TPBusPort input;
    TPBusPort timing;
    TPBusPort dma;
} TPBusPorts;

typedef struct TPBusMath {
    uint8_t multiplicand;
    uint8_t multiplier;
    uint8_t divisor;
    uint16_t dividend;
    uint16_t quotient;
    uint16_t remainder_or_product;
    uint32_t shift;
    uint8_t multiply_cycles_remaining;
    uint8_t divide_cycles_remaining;
} TPBusMath;

typedef struct TPBusFailure {
    TPBusStop reason;
    uint32_t address;
    uint8_t value;
} TPBusFailure;

typedef struct TPBus {
    const uint8_t *rom;
    size_t rom_size;
    uint8_t wram[TP_BUS_WRAM_SIZE];
    uint8_t wram_known[TP_BUS_WRAM_SIZE / 8u];
    TPBusPorts ports;
    TPBusMath math;
    TPBusFailure failure;
    uint32_t wram_port_address;
    uint16_t htime;
    uint16_t vtime;
    uint8_t open_bus;
    uint8_t open_bus_known;
    uint8_t nmitimen;
    uint8_t wrio;
    uint8_t memsel;
    uint64_t access_clock_sum;
    uint64_t read_count;
    uint64_t write_count;
    uint64_t region_read_count[TP_BUS_REGION_COUNT];
    uint64_t region_write_count[TP_BUS_REGION_COUNT];
    uint64_t math_cpu_cycles_advanced;
    struct TPScheduler *scheduler;
    const void *active_timing_plan;
    TPScpuState timing_before;
    uint32_t timing_cpu_cycles;
    uint8_t timing_read_count;
    uint8_t timing_write_count;
    uint8_t timing_pointer_low;
    uint8_t timing_pointer_high;
    uint8_t timing_pointer_seen;
    uint8_t timing_pre_access_done;
    uint8_t timing_pre_stack_done;
    uint8_t timing_index_done;
    uint8_t timing_rmw_done;
    uint8_t timing_jsl_done;
    uint8_t timing_active;
    TPPowerOnProfile power_on_profile;
} TPBus;

const char *tp_bus_region_name(TPBusRegion region);
const char *tp_bus_stop_name(TPBusStop stop);
TPBusMapping tp_bus_map(uint32_t address);
unsigned tp_bus_access_clocks(const TPBus *bus, uint32_t address);
TPBusStop tp_bus_power_on(TPBus *bus, const uint8_t *rom, size_t rom_size,
                          TPBusPorts ports);
TPBusStop tp_bus_power_on_profile(TPBus *bus, const uint8_t *rom,
                                  size_t rom_size, TPBusPorts ports,
                                  TPPowerOnProfile profile);
TPBusStop tp_bus_reset(TPBus *bus, TPScpuState *cpu);
TPBusStop tp_bus_peek8(const TPBus *bus, uint32_t address, uint8_t *value);
TPBusStop tp_bus_read8(TPBus *bus, uint32_t address, uint8_t *value);
TPBusStop tp_bus_write8(TPBus *bus, uint32_t address, uint8_t value);
TPBusStop tp_bus_sample_reset_vector(const TPBus *bus, uint16_t *vector);
void tp_bus_advance_cpu_cycles(TPBus *bus, unsigned cycles);
void tp_bus_bind_scheduler(TPBus *bus, struct TPScheduler *scheduler);
TPBusStop tp_bus_cpu_internal_cycle(TPBus *bus);
TPBusStop tp_bus_cpu_read_cycle(TPBus *bus, uint32_t address, uint8_t *value);
TPBusStop tp_bus_cpu_write_cycle(TPBus *bus, uint32_t address, uint8_t value);
TPScpuBus tp_bus_scpu_view(TPBus *bus);

#ifdef __cplusplus
}
#endif

#endif
