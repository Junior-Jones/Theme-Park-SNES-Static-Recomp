/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000E82(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x0074100Bu: {
            TP_STATIC_GUARD(0x0E8201u, 0xA5u, 0x05u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x05u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8203u;
            if (tp_scpu_expect_next(cpu, 0x0074101Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0074101Bu: {
            TP_STATIC_GUARD(0x0E8203u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x05u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00741033u: {
            TP_STATIC_GUARD(0x0E8206u, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            TP_STATIC_EXIT(0x0Eu, 0x8207u, 0x00741038u, 4u);
        }

        case 0x00741038u: {
            TP_STATIC_GUARD(0x0E8207u, 0x6Bu);
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
                case 0x00040C00u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00741040u: {
            TP_STATIC_GUARD(0x0E8208u, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8209u, 0x00741048u, 3u);
        }

        case 0x00741048u: {
            TP_STATIC_GUARD(0x0E8209u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x820Bu, 0x0074105Bu, 3u);
        }

        case 0x0074105Bu: {
            TP_STATIC_GUARD(0x0E820Bu, 0xA9u, 0x13u);
            const uint8_t value = 0x13u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x820Du, 0x0074106Bu, 2u);
        }

        case 0x0074106Bu: {
            TP_STATIC_GUARD(0x0E820Du, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Fu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00741083u: {
            TP_STATIC_GUARD(0x0E8210u, 0xA5u, 0x04u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x04u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8212u;
            if (tp_scpu_expect_next(cpu, 0x00741093u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741093u: {
            TP_STATIC_GUARD(0x0E8212u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x14u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x007410ABu: {
            TP_STATIC_GUARD(0x0E8215u, 0xA5u, 0x05u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x05u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8217u;
            if (tp_scpu_expect_next(cpu, 0x007410BBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007410BBu: {
            TP_STATIC_GUARD(0x0E8217u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x19u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x007410D3u: {
            TP_STATIC_GUARD(0x0E821Au, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x821Cu, 0x007410E3u, 2u);
        }

        case 0x007410E3u: {
            TP_STATIC_GUARD(0x0E821Cu, 0x85u, 0x10u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x10u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x821Eu;
            if (tp_scpu_expect_next(cpu, 0x007410F3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007410F3u: {
            TP_STATIC_GUARD(0x0E821Eu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Eu, 0x8220u, 0x00741100u, 3u);
        }

        case 0x00741100u: {
            TP_STATIC_GUARD(0x0E8220u, 0xA5u, 0x04u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x04u);
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8222u;
            if (tp_scpu_expect_next(cpu, 0x00741110u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741110u: {
            TP_STATIC_GUARD(0x0E8222u, 0x85u, 0x11u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x11u);
            if (tp_scpu_write16(cpu, bus, address, (uint16_t)cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8224u;
            if (tp_scpu_expect_next(cpu, 0x00741120u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741120u: {
            TP_STATIC_GUARD(0x0E8224u, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            TP_STATIC_EXIT(0x0Eu, 0x8225u, 0x00741128u, 4u);
        }

        case 0x00741128u: {
            TP_STATIC_GUARD(0x0E8225u, 0x6Bu);
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
                case 0x00040CC0u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00741131u: {
            TP_STATIC_GUARD(0x0E8226u, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8227u, 0x00741139u, 3u);
        }

        case 0x00741139u: {
            TP_STATIC_GUARD(0x0E8227u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x8229u, 0x0074114Bu, 3u);
        }

        case 0x0074114Bu: {
            TP_STATIC_GUARD(0x0E8229u, 0xA9u, 0x12u);
            const uint8_t value = 0x12u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x822Bu, 0x0074115Bu, 2u);
        }

        case 0x0074115Bu: {
            TP_STATIC_GUARD(0x0E822Bu, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x2Du) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00741173u: {
            TP_STATIC_GUARD(0x0E822Eu, 0xA5u, 0x04u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x04u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8230u;
            if (tp_scpu_expect_next(cpu, 0x00741183u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741183u: {
            TP_STATIC_GUARD(0x0E8230u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x32u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x0074119Bu: {
            TP_STATIC_GUARD(0x0E8233u, 0xA5u, 0x05u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x05u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8235u;
            if (tp_scpu_expect_next(cpu, 0x007411ABu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007411ABu: {
            TP_STATIC_GUARD(0x0E8235u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x37u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x007411C3u: {
            TP_STATIC_GUARD(0x0E8238u, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x823Au, 0x007411D3u, 2u);
        }

        case 0x007411D3u: {
            TP_STATIC_GUARD(0x0E823Au, 0x85u, 0x10u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x10u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x823Cu;
            if (tp_scpu_expect_next(cpu, 0x007411E3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007411E3u: {
            TP_STATIC_GUARD(0x0E823Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Eu, 0x823Eu, 0x007411F0u, 3u);
        }

        case 0x007411F0u: {
            TP_STATIC_GUARD(0x0E823Eu, 0xA5u, 0x04u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x04u);
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8240u;
            if (tp_scpu_expect_next(cpu, 0x00741200u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741200u: {
            TP_STATIC_GUARD(0x0E8240u, 0x85u, 0x11u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x11u);
            if (tp_scpu_write16(cpu, bus, address, (uint16_t)cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8242u;
            if (tp_scpu_expect_next(cpu, 0x00741210u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741210u: {
            TP_STATIC_GUARD(0x0E8242u, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            TP_STATIC_EXIT(0x0Eu, 0x8243u, 0x00741219u, 4u);
        }

        case 0x00741219u: {
            TP_STATIC_GUARD(0x0E8243u, 0x6Bu);
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
                case 0x00644069u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00741223u: {
            TP_STATIC_GUARD(0x0E8244u, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8245u, 0x0074122Bu, 3u);
        }

        case 0x0074122Bu: {
            TP_STATIC_GUARD(0x0E8245u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x8247u, 0x0074123Bu, 3u);
        }

        case 0x0074123Bu: {
            TP_STATIC_GUARD(0x0E8247u, 0x85u, 0x15u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x15u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8249u;
            if (tp_scpu_expect_next(cpu, 0x0074124Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0074124Bu: {
            TP_STATIC_GUARD(0x0E8249u, 0x8Fu, 0x42u, 0x21u, 0x00u);
            const uint32_t address = 0x002142u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x824Du, 0x0074126Bu, 5u);
        }

        case 0x0074126Bu: {
            TP_STATIC_GUARD(0x0E824Du, 0xA9u, 0x60u);
            const uint8_t value = 0x60u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x824Fu, 0x0074127Bu, 2u);
        }

        case 0x0074127Bu: {
            TP_STATIC_GUARD(0x0E824Fu, 0x85u, 0x13u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x13u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8251u;
            if (tp_scpu_expect_next(cpu, 0x0074128Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0074128Bu: {
            TP_STATIC_GUARD(0x0E8251u, 0xA9u, 0xEAu);
            const uint8_t value = 0xEAu;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8253u, 0x0074129Bu, 2u);
        }

        case 0x0074129Bu: {
            TP_STATIC_GUARD(0x0E8253u, 0x85u, 0x14u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x14u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8255u;
            if (tp_scpu_expect_next(cpu, 0x007412ABu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007412ABu: {
            TP_STATIC_GUARD(0x0E8255u, 0xA5u, 0x06u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x06u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8257u;
            if (tp_scpu_expect_next(cpu, 0x007412BBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007412BBu: {
            TP_STATIC_GUARD(0x0E8257u, 0x3Au);
            const uint8_t value = (uint8_t)((cpu->a - 1u) & 0x00FFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8258u, 0x007412C3u, 2u);
        }

        case 0x007412C3u: {
            TP_STATIC_GUARD(0x0E8258u, 0x85u, 0x06u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x06u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x825Au;
            if (tp_scpu_expect_next(cpu, 0x007412D3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007412D3u: {
            TP_STATIC_GUARD(0x0E825Au, 0x8Fu, 0x40u, 0x21u, 0x00u);
            const uint32_t address = 0x002140u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x825Eu, 0x007412F3u, 5u);
        }

        case 0x007412F3u: {
            TP_STATIC_GUARD(0x0E825Eu, 0xC6u, 0x13u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x13u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            value = (uint8_t)(value - 1u);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8260u;
            if (tp_scpu_expect_next(cpu, 0x00741303u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 5u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741303u: {
            TP_STATIC_GUARD(0x0E8260u, 0xD0u, 0x08u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x826Au;
                if (tp_scpu_expect_next(cpu, 0x00741353u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x8262u, 0x00741313u, 2u);
        }

        case 0x00741313u: {
            TP_STATIC_GUARD(0x0E8262u, 0xC6u, 0x14u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x14u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            value = (uint8_t)(value - 1u);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8264u;
            if (tp_scpu_expect_next(cpu, 0x00741323u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 5u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741323u: {
            TP_STATIC_GUARD(0x0E8264u, 0xD0u, 0x04u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x826Au;
                if (tp_scpu_expect_next(cpu, 0x00741353u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x8266u, 0x00741333u, 2u);
        }

        case 0x00741333u: {
            TP_STATIC_GUARD(0x0E8266u, 0xA5u, 0x15u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x15u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8268u;
            if (tp_scpu_expect_next(cpu, 0x00741343u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741343u: {
            TP_STATIC_GUARD(0x0E8268u, 0x80u, 0xDFu);
            TP_STATIC_EXIT(0x0Eu, 0x8249u, 0x0074124Bu, 3u);
        }

        case 0x00741353u: {
            TP_STATIC_GUARD(0x0E826Au, 0xCFu, 0x41u, 0x21u, 0x00u);
            const uint32_t address = 0x002141u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x826Eu, 0x00741373u, 5u);
        }

        case 0x00741373u: {
            TP_STATIC_GUARD(0x0E826Eu, 0xD0u, 0xEEu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x825Eu;
                if (tp_scpu_expect_next(cpu, 0x007412F3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x8270u, 0x00741383u, 2u);
        }

        case 0x00741383u: {
            TP_STATIC_GUARD(0x0E8270u, 0xCFu, 0x41u, 0x21u, 0x00u);
            const uint32_t address = 0x002141u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8274u, 0x007413A3u, 5u);
        }

        case 0x007413A3u: {
            TP_STATIC_GUARD(0x0E8274u, 0xD0u, 0xE8u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x825Eu;
                if (tp_scpu_expect_next(cpu, 0x007412F3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x8276u, 0x007413B3u, 2u);
        }

        case 0x007413B3u: {
            TP_STATIC_GUARD(0x0E8276u, 0xFAu);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8277u, 0x007413BBu, 4u);
        }

        case 0x007413BBu: {
            TP_STATIC_GUARD(0x0E8277u, 0x60u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            switch (tp_scpu_context_key(cpu)) {
                case 0x007403E3u:
                case 0x0074040Bu:
                case 0x00740433u:
                case 0x0074045Bu:
                case 0x00740483u:
                case 0x0074069Bu:
                case 0x0074074Bu:
                case 0x0074076Bu:
                case 0x0074078Bu:
                case 0x007407DBu:
                case 0x00740833u:
                case 0x00740853u:
                case 0x00740A3Bu:
                case 0x00740A5Bu:
                case 0x00740BDBu:
                case 0x00740C1Bu:
                case 0x00740C5Bu:
                case 0x00740C9Bu:
                case 0x00740CCBu:
                case 0x00740CFBu:
                case 0x00740D2Bu:
                case 0x00740D5Bu:
                case 0x00740E7Bu:
                case 0x00740EA3u:
                case 0x00740ECBu:
                case 0x00740EF3u:
                case 0x00740F1Bu:
                case 0x00740F43u:
                case 0x00740F6Bu:
                case 0x00740F93u:
                case 0x00740FE3u:
                case 0x0074100Bu:
                case 0x00741033u:
                case 0x00741083u:
                case 0x007410ABu:
                case 0x007410D3u:
                case 0x00741173u:
                case 0x0074119Bu:
                case 0x007411C3u:
                case 0x00741413u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            }
        }

        case 0x007413C0u: {
            TP_STATIC_GUARD(0x0E8278u, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8279u, 0x007413C8u, 3u);
        }

        case 0x007413C3u: {
            TP_STATIC_GUARD(0x0E8278u, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8279u, 0x007413CBu, 3u);
        }

        case 0x007413C8u: {
            TP_STATIC_GUARD(0x0E8279u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x827Bu, 0x007413DBu, 3u);
        }

        case 0x007413CBu: {
            TP_STATIC_GUARD(0x0E8279u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x827Bu, 0x007413DBu, 3u);
        }

        case 0x007413DBu: {
            TP_STATIC_GUARD(0x0E827Bu, 0xA0u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x827Du, 0x007413EBu, 2u);
        }

        case 0x007413EBu: {
            TP_STATIC_GUARD(0x0E827Du, 0xB7u, 0x00u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x00u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = (((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address & 0xFFFFFFu, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x827Fu;
            if (tp_scpu_expect_next(cpu, 0x007413FBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007413FBu: {
            TP_STATIC_GUARD(0x0E827Fu, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00741413u: {
            TP_STATIC_GUARD(0x0E8282u, 0xE6u, 0x00u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x00u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            value = (uint8_t)(value + 1u);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8284u;
            if (tp_scpu_expect_next(cpu, 0x00741423u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 5u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741423u: {
            TP_STATIC_GUARD(0x0E8284u, 0xD0u, 0x0Au);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x8290u;
                if (tp_scpu_expect_next(cpu, 0x00741483u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x8286u, 0x00741433u, 2u);
        }

        case 0x00741433u: {
            TP_STATIC_GUARD(0x0E8286u, 0xE6u, 0x01u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x01u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            value = (uint8_t)(value + 1u);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8288u;
            if (tp_scpu_expect_next(cpu, 0x00741443u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 5u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741443u: {
            TP_STATIC_GUARD(0x0E8288u, 0x30u, 0x06u);
            if ((cpu->p & TP_P_N) != 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x8290u;
                if (tp_scpu_expect_next(cpu, 0x00741483u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x828Au, 0x00741453u, 2u);
        }

        case 0x00741453u: {
            TP_STATIC_GUARD(0x0E828Au, 0xA9u, 0x80u);
            const uint8_t value = 0x80u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x828Cu, 0x00741463u, 2u);
        }

        case 0x00741463u: {
            TP_STATIC_GUARD(0x0E828Cu, 0x85u, 0x01u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x01u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x828Eu;
            if (tp_scpu_expect_next(cpu, 0x00741473u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741473u: {
            TP_STATIC_GUARD(0x0E828Eu, 0xE6u, 0x02u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x02u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            value = (uint8_t)(value + 1u);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8290u;
            if (tp_scpu_expect_next(cpu, 0x00741483u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 5u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741483u: {
            TP_STATIC_GUARD(0x0E8290u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x0Eu, 0x8291u, 0x0074148Bu, 2u);
        }

        case 0x0074148Bu: {
            TP_STATIC_GUARD(0x0E8291u, 0xA5u, 0x04u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x04u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8293u;
            if (tp_scpu_expect_next(cpu, 0x0074149Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0074149Bu: {
            TP_STATIC_GUARD(0x0E8293u, 0xE9u, 0x01u);
            if (tp_scpu_sbc(cpu, 0x01u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8295u, 0x007414ABu, 2u);
        }

        case 0x007414ABu: {
            TP_STATIC_GUARD(0x0E8295u, 0x85u, 0x04u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x04u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8297u;
            if (tp_scpu_expect_next(cpu, 0x007414BBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007414BBu: {
            TP_STATIC_GUARD(0x0E8297u, 0xA5u, 0x05u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x05u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8299u;
            if (tp_scpu_expect_next(cpu, 0x007414CBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007414CBu: {
            TP_STATIC_GUARD(0x0E8299u, 0xE9u, 0x00u);
            if (tp_scpu_sbc(cpu, 0x00u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x829Bu, 0x007414DBu, 2u);
        }

        case 0x007414DBu: {
            TP_STATIC_GUARD(0x0E829Bu, 0x85u, 0x05u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x05u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x829Du;
            if (tp_scpu_expect_next(cpu, 0x007414EBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007414EBu: {
            TP_STATIC_GUARD(0x0E829Du, 0x05u, 0x04u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x04u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            value = (uint8_t)((cpu->a & 0x00FFu) | value);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x829Fu;
            if (tp_scpu_expect_next(cpu, 0x007414FBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007414FBu: {
            TP_STATIC_GUARD(0x0E829Fu, 0xD0u, 0xDCu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x827Du;
                if (tp_scpu_expect_next(cpu, 0x007413EBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x82A1u, 0x0074150Bu, 2u);
        }

        case 0x0074150Bu: {
            TP_STATIC_GUARD(0x0E82A1u, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x82A2u;
            switch (tp_scpu_context_key(cpu)) {
                case 0x00741510u:
                case 0x00741513u:
                    return tp_scpu_finish(cpu, bus, 4u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_SUCCESSOR_CONTEXT");
            }
        }

        case 0x00741510u: {
            TP_STATIC_GUARD(0x0E82A2u, 0x60u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            switch (tp_scpu_context_key(cpu)) {
                case 0x00740660u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            }
        }

        case 0x00741513u: {
            TP_STATIC_GUARD(0x0E82A2u, 0x60u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            switch (tp_scpu_context_key(cpu)) {
                case 0x007405C3u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            }
        }

        case 0x00741518u: {
            TP_STATIC_GUARD(0x0E82A3u, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x82A4u, 0x00741520u, 3u);
        }

        case 0x00741520u: {
            TP_STATIC_GUARD(0x0E82A4u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Eu, 0x82A6u, 0x00741530u, 3u);
        }

        case 0x00741530u: {
            TP_STATIC_GUARD(0x0E82A6u, 0xA0u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82A9u, 0x00741548u, 3u);
        }

        case 0x00741548u: {
            TP_STATIC_GUARD(0x0E82A9u, 0xA9u, 0xAAu, 0xBBu);
            const uint16_t value = 0xBBAAu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82ACu, 0x00741560u, 3u);
        }

        case 0x00741560u: {
            TP_STATIC_GUARD(0x0E82ACu, 0xCFu, 0x40u, 0x21u, 0x00u);
            const uint32_t address = 0x002140u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82B0u, 0x00741580u, 6u);
        }

        case 0x00741580u: {
            TP_STATIC_GUARD(0x0E82B0u, 0xD0u, 0xFAu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x82ACu;
                if (tp_scpu_expect_next(cpu, 0x00741560u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x82B2u, 0x00741590u, 2u);
        }

        case 0x00741590u: {
            TP_STATIC_GUARD(0x0E82B2u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x82B4u, 0x007415A2u, 3u);
        }

        case 0x007415A2u: {
            TP_STATIC_GUARD(0x0E82B4u, 0xA9u, 0xCCu);
            const uint8_t value = 0xCCu;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82B6u, 0x007415B2u, 2u);
        }

        case 0x007415B2u: {
            TP_STATIC_GUARD(0x0E82B6u, 0x80u, 0x29u);
            TP_STATIC_EXIT(0x0Eu, 0x82E1u, 0x0074170Au, 3u);
        }

        case 0x007415C2u: {
            TP_STATIC_GUARD(0x0E82B8u, 0xB7u, 0x00u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x00u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = (((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address & 0xFFFFFFu, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x82BAu;
            if (tp_scpu_expect_next(cpu, 0x007415D2u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x007415D2u: {
            TP_STATIC_GUARD(0x0E82BAu, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82BBu, 0x007415DAu, 2u);
        }

        case 0x007415DAu: {
            TP_STATIC_GUARD(0x0E82BBu, 0xEBu);
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->a & 0x00FFu) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->a & 0x00FFu) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82BCu, 0x007415E2u, 3u);
        }

        case 0x007415E2u: {
            TP_STATIC_GUARD(0x0E82BCu, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82BEu, 0x007415F2u, 2u);
        }

        case 0x007415F2u: {
            TP_STATIC_GUARD(0x0E82BEu, 0x80u, 0x0Cu);
            TP_STATIC_EXIT(0x0Eu, 0x82CCu, 0x00741662u, 3u);
        }

        case 0x00741602u: {
            TP_STATIC_GUARD(0x0E82C0u, 0xEBu);
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->a & 0x00FFu) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->a & 0x00FFu) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82C1u, 0x0074160Au, 3u);
        }

        case 0x0074160Au: {
            TP_STATIC_GUARD(0x0E82C1u, 0xB7u, 0x00u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x00u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = (((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address & 0xFFFFFFu, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x82C3u;
            if (tp_scpu_expect_next(cpu, 0x0074161Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0074161Au: {
            TP_STATIC_GUARD(0x0E82C3u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82C4u, 0x00741622u, 2u);
        }

        case 0x00741622u: {
            TP_STATIC_GUARD(0x0E82C4u, 0xEBu);
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->a & 0x00FFu) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->a & 0x00FFu) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82C5u, 0x0074162Au, 3u);
        }

        case 0x0074162Au: {
            TP_STATIC_GUARD(0x0E82C5u, 0xCFu, 0x40u, 0x21u, 0x00u);
            const uint32_t address = 0x002140u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82C9u, 0x0074164Au, 5u);
        }

        case 0x0074164Au: {
            TP_STATIC_GUARD(0x0E82C9u, 0xD0u, 0xFAu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x82C5u;
                if (tp_scpu_expect_next(cpu, 0x0074162Au) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x82CBu, 0x0074165Au, 2u);
        }

        case 0x0074165Au: {
            TP_STATIC_GUARD(0x0E82CBu, 0x1Au);
            const uint8_t value = (uint8_t)((cpu->a + 1u) & 0x00FFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82CCu, 0x00741662u, 2u);
        }

        case 0x00741662u: {
            TP_STATIC_GUARD(0x0E82CCu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x0Eu, 0x82CEu, 0x00741670u, 3u);
        }

        case 0x00741670u: {
            TP_STATIC_GUARD(0x0E82CEu, 0x8Fu, 0x40u, 0x21u, 0x00u);
            const uint32_t address = 0x002140u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x82D2u, 0x00741690u, 6u);
        }

        case 0x00741690u: {
            TP_STATIC_GUARD(0x0E82D2u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x82D4u, 0x007416A2u, 3u);
        }

        case 0x007416A2u: {
            TP_STATIC_GUARD(0x0E82D4u, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82D5u, 0x007416AAu, 2u);
        }

        case 0x007416AAu: {
            TP_STATIC_GUARD(0x0E82D5u, 0xD0u, 0xE9u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x82C0u;
                if (tp_scpu_expect_next(cpu, 0x00741602u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x82D7u, 0x007416BAu, 2u);
        }

        case 0x007416BAu: {
            TP_STATIC_GUARD(0x0E82D7u, 0xCFu, 0x40u, 0x21u, 0x00u);
            const uint32_t address = 0x002140u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82DBu, 0x007416DAu, 5u);
        }

        case 0x007416DAu: {
            TP_STATIC_GUARD(0x0E82DBu, 0xD0u, 0xFAu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x82D7u;
                if (tp_scpu_expect_next(cpu, 0x007416BAu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x82DDu, 0x007416EAu, 2u);
        }

        case 0x007416EAu: {
            TP_STATIC_GUARD(0x0E82DDu, 0x69u, 0x03u);
            if (tp_scpu_adc(cpu, 0x03u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x82DFu, 0x007416FAu, 2u);
        }

        case 0x007416FAu: {
            TP_STATIC_GUARD(0x0E82DFu, 0xF0u, 0xFCu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x82DDu;
                if (tp_scpu_expect_next(cpu, 0x007416EAu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x82E1u, 0x0074170Au, 2u);
        }

        case 0x0074170Au: {
            TP_STATIC_GUARD(0x0E82E1u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x82E2u, 0x00741712u, 3u);
        }

        case 0x00741712u: {
            TP_STATIC_GUARD(0x0E82E2u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x0Eu, 0x82E4u, 0x00741720u, 3u);
        }

        case 0x00741720u: {
            TP_STATIC_GUARD(0x0E82E4u, 0xB7u, 0x00u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x00u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = (((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address & 0xFFFFFFu, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x82E6u;
            if (tp_scpu_expect_next(cpu, 0x00741730u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741730u: {
            TP_STATIC_GUARD(0x0E82E6u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82E7u, 0x00741738u, 2u);
        }

        case 0x00741738u: {
            TP_STATIC_GUARD(0x0E82E7u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82E8u, 0x00741740u, 2u);
        }

        case 0x00741740u: {
            TP_STATIC_GUARD(0x0E82E8u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82E9u, 0x00741748u, 2u);
        }

        case 0x00741748u: {
            TP_STATIC_GUARD(0x0E82E9u, 0xB7u, 0x00u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x00u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = (((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address & 0xFFFFFFu, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x82EBu;
            if (tp_scpu_expect_next(cpu, 0x00741758u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00741758u: {
            TP_STATIC_GUARD(0x0E82EBu, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82ECu, 0x00741760u, 2u);
        }

        case 0x00741760u: {
            TP_STATIC_GUARD(0x0E82ECu, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82EDu, 0x00741768u, 2u);
        }

        case 0x00741768u: {
            TP_STATIC_GUARD(0x0E82EDu, 0x8Fu, 0x42u, 0x21u, 0x00u);
            const uint32_t address = 0x002142u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x82F1u, 0x00741788u, 6u);
        }

        case 0x00741788u: {
            TP_STATIC_GUARD(0x0E82F1u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x82F3u, 0x0074179Au, 3u);
        }

        case 0x0074179Au: {
            TP_STATIC_GUARD(0x0E82F3u, 0xE0u, 0x01u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0001u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82F6u, 0x007417B2u, 3u);
        }

        case 0x007417B2u: {
            TP_STATIC_GUARD(0x0E82F6u, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82F8u, 0x007417C2u, 2u);
        }

        case 0x007417C2u: {
            TP_STATIC_GUARD(0x0E82F8u, 0x2Au);
            const uint8_t old_value = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t value = (uint8_t)((old_value << 1u) | ((cpu->p & TP_P_C) != 0u ? 1u : 0u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x82F9u, 0x007417CAu, 2u);
        }

        case 0x007417CAu: {
            TP_STATIC_GUARD(0x0E82F9u, 0x8Fu, 0x41u, 0x21u, 0x00u);
            const uint32_t address = 0x002141u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x82FDu, 0x007417EAu, 5u);
        }

        case 0x007417EAu: {
            TP_STATIC_GUARD(0x0E82FDu, 0x69u, 0x7Fu);
            if (tp_scpu_adc(cpu, 0x7Fu, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x82FFu, 0x007417FAu, 2u);
        }

        case 0x007417FAu: {
            TP_STATIC_GUARD(0x0E82FFu, 0x68u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8300u, 0x00741802u, 4u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
