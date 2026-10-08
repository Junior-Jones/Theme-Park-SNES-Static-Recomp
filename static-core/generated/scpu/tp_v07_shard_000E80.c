/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000E80(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00740003u: {
            TP_STATIC_GUARD(0x0E8000u, 0x4Cu, 0x39u, 0x80u);
            TP_STATIC_EXIT(0x0Eu, 0x8039u, 0x007401CBu, 3u);
        }

        case 0x00740030u: {
            TP_STATIC_GUARD(0x0E8006u, 0x4Cu, 0xDFu, 0x80u);
            TP_STATIC_EXIT(0x0Eu, 0x80DFu, 0x007406F8u, 3u);
        }

        case 0x0074004Bu: {
            TP_STATIC_GUARD(0x0E8009u, 0x4Cu, 0xF3u, 0x80u);
            TP_STATIC_EXIT(0x0Eu, 0x80F3u, 0x0074079Bu, 3u);
        }

        case 0x00740060u: {
            TP_STATIC_GUARD(0x0E800Cu, 0x4Cu, 0x9Cu, 0x80u);
            TP_STATIC_EXIT(0x0Eu, 0x809Cu, 0x007404E0u, 3u);
        }

        case 0x00740063u: {
            TP_STATIC_GUARD(0x0E800Cu, 0x4Cu, 0x9Cu, 0x80u);
            TP_STATIC_EXIT(0x0Eu, 0x809Cu, 0x007404E3u, 3u);
        }

        case 0x00740078u: {
            TP_STATIC_GUARD(0x0E800Fu, 0x4Cu, 0x6Bu, 0x81u);
            TP_STATIC_EXIT(0x0Eu, 0x816Bu, 0x00740B58u, 3u);
        }

        case 0x00740093u: {
            TP_STATIC_GUARD(0x0E8012u, 0x4Cu, 0xC7u, 0x81u);
            TP_STATIC_EXIT(0x0Eu, 0x81C7u, 0x00740E3Bu, 3u);
        }

        case 0x007400C0u: {
            TP_STATIC_GUARD(0x0E8018u, 0x4Cu, 0xFDu, 0x80u);
            TP_STATIC_EXIT(0x0Eu, 0x80FDu, 0x007407E8u, 3u);
        }

        case 0x0074010Bu: {
            TP_STATIC_GUARD(0x0E8021u, 0x4Cu, 0x3Eu, 0x81u);
            TP_STATIC_EXIT(0x0Eu, 0x813Eu, 0x007409F3u, 3u);
        }

        case 0x00740138u: {
            TP_STATIC_GUARD(0x0E8027u, 0x4Cu, 0xF4u, 0x81u);
            TP_STATIC_EXIT(0x0Eu, 0x81F4u, 0x00740FA0u, 3u);
        }

        case 0x00740151u: {
            TP_STATIC_GUARD(0x0E802Au, 0x4Cu, 0x26u, 0x82u);
            TP_STATIC_EXIT(0x0Eu, 0x8226u, 0x00741131u, 3u);
        }

        case 0x00740168u: {
            TP_STATIC_GUARD(0x0E802Du, 0x4Cu, 0x08u, 0x82u);
            TP_STATIC_EXIT(0x0Eu, 0x8208u, 0x00741040u, 3u);
        }

        case 0x007401CBu: {
            TP_STATIC_GUARD(0x0E8039u, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x803Au, 0x007401D3u, 3u);
        }

        case 0x007401D3u: {
            TP_STATIC_GUARD(0x0E803Au, 0x78u);
            cpu->p = (uint8_t)(cpu->p | TP_P_I);
            TP_STATIC_EXIT(0x0Eu, 0x803Bu, 0x007401DBu, 2u);
        }

        case 0x007401DBu: {
            TP_STATIC_GUARD(0x0E803Bu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x803Du, 0x007401EBu, 3u);
        }

        case 0x007401EBu: {
            TP_STATIC_GUARD(0x0E803Du, 0x4Bu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x803Eu, 0x007401F3u, 3u);
        }

        case 0x007401F3u: {
            TP_STATIC_GUARD(0x0E803Eu, 0x68u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x803Fu, 0x007401FBu, 4u);
        }

        case 0x007401FBu: {
            TP_STATIC_GUARD(0x0E803Fu, 0x85u, 0x02u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x02u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8041u;
            if (tp_scpu_expect_next(cpu, 0x0074020Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0074020Bu: {
            TP_STATIC_GUARD(0x0E8041u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Eu, 0x8043u, 0x00740218u, 3u);
        }

        case 0x00740218u: {
            TP_STATIC_GUARD(0x0E8043u, 0xA9u, 0x13u, 0x83u);
            const uint16_t value = 0x8313u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8046u, 0x00740230u, 3u);
        }

        case 0x00740230u: {
            TP_STATIC_GUARD(0x0E8046u, 0x85u, 0x00u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x00u);
            if (tp_scpu_write16(cpu, bus, address, (uint16_t)cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8048u;
            if (tp_scpu_expect_next(cpu, 0x00740240u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740240u: {
            TP_STATIC_GUARD(0x0E8048u, 0x20u, 0xA3u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x4Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x82A3u, 0x00741518u, 6u);
        }

        case 0x00740258u: {
            TP_STATIC_GUARD(0x0E804Bu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x804Du, 0x0074026Bu, 3u);
        }

        case 0x0074026Bu: {
            TP_STATIC_GUARD(0x0E804Du, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x804Fu, 0x0074027Bu, 2u);
        }

        case 0x0074027Bu: {
            TP_STATIC_GUARD(0x0E804Fu, 0x85u, 0x06u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x06u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8051u;
            if (tp_scpu_expect_next(cpu, 0x0074028Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0074028Bu: {
            TP_STATIC_GUARD(0x0E8051u, 0xAFu, 0x43u, 0x21u, 0x00u);
            const uint32_t address = 0x002143u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8055u, 0x007402ABu, 5u);
        }

        case 0x007402ABu: {
            TP_STATIC_GUARD(0x0E8055u, 0xC9u, 0x46u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x46u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8057u, 0x007402BBu, 2u);
        }

        case 0x007402BBu: {
            TP_STATIC_GUARD(0x0E8057u, 0xD0u, 0xF8u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x8051u;
                if (tp_scpu_expect_next(cpu, 0x0074028Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x8059u, 0x007402CBu, 2u);
        }

        case 0x007402CBu: {
            TP_STATIC_GUARD(0x0E8059u, 0xAFu, 0x41u, 0x21u, 0x00u);
            const uint32_t address = 0x002141u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x805Du, 0x007402EBu, 5u);
        }

        case 0x007402EBu: {
            TP_STATIC_GUARD(0x0E805Du, 0xC9u, 0x55u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x55u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x805Fu, 0x007402FBu, 2u);
        }

        case 0x007402FBu: {
            TP_STATIC_GUARD(0x0E805Fu, 0xD0u, 0xF0u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x8051u;
                if (tp_scpu_expect_next(cpu, 0x0074028Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x8061u, 0x0074030Bu, 2u);
        }

        case 0x0074030Bu: {
            TP_STATIC_GUARD(0x0E8061u, 0xAFu, 0x42u, 0x21u, 0x00u);
            const uint32_t address = 0x002142u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8065u, 0x0074032Bu, 5u);
        }

        case 0x0074032Bu: {
            TP_STATIC_GUARD(0x0E8065u, 0xC9u, 0x43u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x43u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8067u, 0x0074033Bu, 2u);
        }

        case 0x0074033Bu: {
            TP_STATIC_GUARD(0x0E8067u, 0xD0u, 0xE8u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x8051u;
                if (tp_scpu_expect_next(cpu, 0x0074028Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x8069u, 0x0074034Bu, 2u);
        }

        case 0x0074034Bu: {
            TP_STATIC_GUARD(0x0E8069u, 0xA9u, 0x4Bu);
            const uint8_t value = 0x4Bu;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x806Bu, 0x0074035Bu, 2u);
        }

        case 0x0074035Bu: {
            TP_STATIC_GUARD(0x0E806Bu, 0x8Fu, 0x40u, 0x21u, 0x00u);
            const uint32_t address = 0x002140u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x806Fu, 0x0074037Bu, 5u);
        }

        case 0x0074037Bu: {
            TP_STATIC_GUARD(0x0E806Fu, 0xCFu, 0x43u, 0x21u, 0x00u);
            const uint32_t address = 0x002143u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8073u, 0x0074039Bu, 5u);
        }

        case 0x0074039Bu: {
            TP_STATIC_GUARD(0x0E8073u, 0xD0u, 0xF4u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x8069u;
                if (tp_scpu_expect_next(cpu, 0x0074034Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x8075u, 0x007403ABu, 2u);
        }

        case 0x007403ABu: {
            TP_STATIC_GUARD(0x0E8075u, 0x85u, 0x06u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x06u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8077u;
            if (tp_scpu_expect_next(cpu, 0x007403BBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007403BBu: {
            TP_STATIC_GUARD(0x0E8077u, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8079u, 0x007403CBu, 2u);
        }

        case 0x007403CBu: {
            TP_STATIC_GUARD(0x0E8079u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x7Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x007403E3u: {
            TP_STATIC_GUARD(0x0E807Cu, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x807Eu, 0x007403F3u, 2u);
        }

        case 0x007403F3u: {
            TP_STATIC_GUARD(0x0E807Eu, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x0074040Bu: {
            TP_STATIC_GUARD(0x0E8081u, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8083u, 0x0074041Bu, 2u);
        }

        case 0x0074041Bu: {
            TP_STATIC_GUARD(0x0E8083u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x85u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740433u: {
            TP_STATIC_GUARD(0x0E8086u, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8088u, 0x00740443u, 2u);
        }

        case 0x00740443u: {
            TP_STATIC_GUARD(0x0E8088u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x0074045Bu: {
            TP_STATIC_GUARD(0x0E808Bu, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x808Du, 0x0074046Bu, 2u);
        }

        case 0x0074046Bu: {
            TP_STATIC_GUARD(0x0E808Du, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Fu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740483u: {
            TP_STATIC_GUARD(0x0E8090u, 0x64u, 0x10u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x10u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(0u & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8092u;
            if (tp_scpu_expect_next(cpu, 0x00740493u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740493u: {
            TP_STATIC_GUARD(0x0E8092u, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            TP_STATIC_EXIT(0x0Eu, 0x8093u, 0x0074049Bu, 4u);
        }

        case 0x0074049Bu: {
            TP_STATIC_GUARD(0x0E8093u, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x00040B33u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x007404E0u: {
            TP_STATIC_GUARD(0x0E809Cu, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x809Du, 0x007404E8u, 3u);
        }

        case 0x007404E3u: {
            TP_STATIC_GUARD(0x0E809Cu, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x809Du, 0x007404EBu, 3u);
        }

        case 0x007404E8u: {
            TP_STATIC_GUARD(0x0E809Du, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x809Fu, 0x007404FBu, 3u);
        }

        case 0x007404EBu: {
            TP_STATIC_GUARD(0x0E809Du, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x809Fu, 0x007404FBu, 3u);
        }

        case 0x007404FBu: {
            TP_STATIC_GUARD(0x0E809Fu, 0xA5u, 0x10u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x10u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80A1u;
            if (tp_scpu_expect_next(cpu, 0x0074050Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0074050Bu: {
            TP_STATIC_GUARD(0x0E80A1u, 0xF0u, 0x2Bu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x80CEu;
                if (tp_scpu_expect_next(cpu, 0x00740673u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x80A3u, 0x0074051Bu, 2u);
        }

        case 0x0074051Bu: {
            TP_STATIC_GUARD(0x0E80A3u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Eu, 0x80A5u, 0x00740528u, 3u);
        }

        case 0x00740528u: {
            TP_STATIC_GUARD(0x0E80A5u, 0xA5u, 0x11u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x11u);
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80A7u;
            if (tp_scpu_expect_next(cpu, 0x00740538u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740538u: {
            TP_STATIC_GUARD(0x0E80A7u, 0xF0u, 0x11u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x80BAu;
                if (tp_scpu_expect_next(cpu, 0x007405D0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x80A9u, 0x00740548u, 2u);
        }

        case 0x00740548u: {
            TP_STATIC_GUARD(0x0E80A9u, 0xC5u, 0x0Eu);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x0Eu);
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80ABu;
            if (tp_scpu_expect_next(cpu, 0x00740558u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740558u: {
            TP_STATIC_GUARD(0x0E80ABu, 0x10u, 0x13u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x80C0u;
                if (tp_scpu_expect_next(cpu, 0x00740600u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x80ADu, 0x00740568u, 2u);
        }

        case 0x00740568u: {
            TP_STATIC_GUARD(0x0E80ADu, 0xA5u, 0x11u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x11u);
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80AFu;
            if (tp_scpu_expect_next(cpu, 0x00740578u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740578u: {
            TP_STATIC_GUARD(0x0E80AFu, 0x85u, 0x04u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x04u);
            if (tp_scpu_write16(cpu, bus, address, (uint16_t)cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80B1u;
            if (tp_scpu_expect_next(cpu, 0x00740588u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740588u: {
            TP_STATIC_GUARD(0x0E80B1u, 0x64u, 0x11u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x11u);
            if (tp_scpu_write16(cpu, bus, address, (uint16_t)0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80B3u;
            if (tp_scpu_expect_next(cpu, 0x00740598u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740598u: {
            TP_STATIC_GUARD(0x0E80B3u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x80B5u, 0x007405ABu, 3u);
        }

        case 0x007405ABu: {
            TP_STATIC_GUARD(0x0E80B5u, 0x20u, 0x78u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB7u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8278u, 0x007413C3u, 6u);
        }

        case 0x007405C3u: {
            TP_STATIC_GUARD(0x0E80B8u, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80B9u;
            switch (tp_scpu_context_key(cpu)) {
                case 0x007405C8u:
                case 0x007405CBu:
                    return tp_scpu_finish(cpu, bus, 4u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_SUCCESSOR_CONTEXT");
            }
        }

        case 0x007405C8u: {
            TP_STATIC_GUARD(0x0E80B9u, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x00040CE0u:
                case 0x00040E10u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x007405CBu: {
            TP_STATIC_GUARD(0x0E80B9u, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x00041C6Bu:
                case 0x00643BEBu:
                case 0x00643C0Bu:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x007405D0u: {
            TP_STATIC_GUARD(0x0E80BAu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x80BCu, 0x007405E3u, 3u);
        }

        case 0x007405E3u: {
            TP_STATIC_GUARD(0x0E80BCu, 0x64u, 0x10u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x10u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(0u & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80BEu;
            if (tp_scpu_expect_next(cpu, 0x007405F3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007405F3u: {
            TP_STATIC_GUARD(0x0E80BEu, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80BFu;
            switch (tp_scpu_context_key(cpu)) {
                case 0x007405F8u:
                case 0x007405FBu:
                    return tp_scpu_finish(cpu, bus, 4u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_SUCCESSOR_CONTEXT");
            }
        }

        case 0x007405F8u: {
            TP_STATIC_GUARD(0x0E80BFu, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x00040CE0u:
                case 0x00040E10u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x007405FBu: {
            TP_STATIC_GUARD(0x0E80BFu, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x00041C6Bu:
                case 0x00643BEBu:
                case 0x00643C0Bu:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00740600u: {
            TP_STATIC_GUARD(0x0E80C0u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x0Eu, 0x80C1u, 0x00740608u, 2u);
        }

        case 0x00740608u: {
            TP_STATIC_GUARD(0x0E80C1u, 0xE5u, 0x0Eu);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x0Eu);
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80C3u;
            if (tp_scpu_expect_next(cpu, 0x00740618u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740618u: {
            TP_STATIC_GUARD(0x0E80C3u, 0x85u, 0x11u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x11u);
            if (tp_scpu_write16(cpu, bus, address, (uint16_t)cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80C5u;
            if (tp_scpu_expect_next(cpu, 0x00740628u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740628u: {
            TP_STATIC_GUARD(0x0E80C5u, 0xA5u, 0x0Eu);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x0Eu);
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80C7u;
            if (tp_scpu_expect_next(cpu, 0x00740638u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740638u: {
            TP_STATIC_GUARD(0x0E80C7u, 0x85u, 0x04u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x04u);
            if (tp_scpu_write16(cpu, bus, address, (uint16_t)cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80C9u;
            if (tp_scpu_expect_next(cpu, 0x00740648u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740648u: {
            TP_STATIC_GUARD(0x0E80C9u, 0x20u, 0x78u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8278u, 0x007413C0u, 6u);
        }

        case 0x00740660u: {
            TP_STATIC_GUARD(0x0E80CCu, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80CDu;
            switch (tp_scpu_context_key(cpu)) {
                case 0x00740668u:
                case 0x0074066Bu:
                    return tp_scpu_finish(cpu, bus, 4u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_SUCCESSOR_CONTEXT");
            }
        }

        case 0x00740668u: {
            TP_STATIC_GUARD(0x0E80CDu, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x00040CE0u:
                case 0x00040E10u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x0074066Bu: {
            TP_STATIC_GUARD(0x0E80CDu, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x00041C6Bu:
                case 0x00643BEBu:
                case 0x00643C0Bu:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00740673u: {
            TP_STATIC_GUARD(0x0E80CEu, 0xA9u, 0x04u);
            const uint8_t value = 0x04u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x80D0u, 0x00740683u, 2u);
        }

        case 0x00740683u: {
            TP_STATIC_GUARD(0x0E80D0u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xD2u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x0074069Bu: {
            TP_STATIC_GUARD(0x0E80D3u, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x80D4u;
            switch (tp_scpu_context_key(cpu)) {
                case 0x007406A0u:
                case 0x007406A3u:
                    return tp_scpu_finish(cpu, bus, 4u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_SUCCESSOR_CONTEXT");
            }
        }

        case 0x007406A0u: {
            TP_STATIC_GUARD(0x0E80D4u, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x00040CE0u:
                case 0x00040E10u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x007406A3u: {
            TP_STATIC_GUARD(0x0E80D4u, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x00041C6Bu:
                case 0x00643BEBu:
                case 0x00643C0Bu:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x007406F8u: {
            TP_STATIC_GUARD(0x0E80DFu, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x80E0u, 0x00740700u, 3u);
        }

        case 0x00740700u: {
            TP_STATIC_GUARD(0x0E80E0u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x80E2u, 0x00740713u, 3u);
        }

        case 0x00740713u: {
            TP_STATIC_GUARD(0x0E80E2u, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x80E3u, 0x0074071Bu, 3u);
        }

        case 0x0074071Bu: {
            TP_STATIC_GUARD(0x0E80E3u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x80E4u, 0x00740723u, 3u);
        }

        case 0x00740723u: {
            TP_STATIC_GUARD(0x0E80E4u, 0xA9u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x80E6u, 0x00740733u, 2u);
        }

        case 0x00740733u: {
            TP_STATIC_GUARD(0x0E80E6u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x0074074Bu: {
            TP_STATIC_GUARD(0x0E80E9u, 0x68u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x80EAu, 0x00740753u, 4u);
        }

        case 0x00740753u: {
            TP_STATIC_GUARD(0x0E80EAu, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xECu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x0074076Bu: {
            TP_STATIC_GUARD(0x0E80EDu, 0x68u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x80EEu, 0x00740773u, 4u);
        }

        case 0x00740773u: {
            TP_STATIC_GUARD(0x0E80EEu, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x0074078Bu: {
            TP_STATIC_GUARD(0x0E80F1u, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            TP_STATIC_EXIT(0x0Eu, 0x80F2u, 0x00740790u, 4u);
        }

        case 0x00740790u: {
            TP_STATIC_GUARD(0x0E80F2u, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x00644158u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x0074079Bu: {
            TP_STATIC_GUARD(0x0E80F3u, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x80F4u, 0x007407A3u, 3u);
        }

        case 0x007407A3u: {
            TP_STATIC_GUARD(0x0E80F4u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x80F6u, 0x007407B3u, 3u);
        }

        case 0x007407B3u: {
            TP_STATIC_GUARD(0x0E80F6u, 0xA9u, 0x03u);
            const uint8_t value = 0x03u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x80F8u, 0x007407C3u, 2u);
        }

        case 0x007407C3u: {
            TP_STATIC_GUARD(0x0E80F8u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xFAu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x007407DBu: {
            TP_STATIC_GUARD(0x0E80FBu, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            TP_STATIC_EXIT(0x0Eu, 0x80FCu, 0x007407E3u, 4u);
        }

        case 0x007407E3u: {
            TP_STATIC_GUARD(0x0E80FCu, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x00644213u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x007407E8u: {
            TP_STATIC_GUARD(0x0E80FDu, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x80FEu, 0x007407F0u, 3u);
        }

        case 0x007407F0u: {
            TP_STATIC_GUARD(0x0E80FEu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x8100u, 0x00740803u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
