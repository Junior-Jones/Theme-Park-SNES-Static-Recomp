/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000E81(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00740803u: {
            TP_STATIC_GUARD(0x0E8100u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8101u, 0x0074080Bu, 3u);
        }

        case 0x0074080Bu: {
            TP_STATIC_GUARD(0x0E8101u, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8103u, 0x0074081Bu, 2u);
        }

        case 0x0074081Bu: {
            TP_STATIC_GUARD(0x0E8103u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x05u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740833u: {
            TP_STATIC_GUARD(0x0E8106u, 0x68u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8107u, 0x0074083Bu, 4u);
        }

        case 0x0074083Bu: {
            TP_STATIC_GUARD(0x0E8107u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x09u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740853u: {
            TP_STATIC_GUARD(0x0E810Au, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            TP_STATIC_EXIT(0x0Eu, 0x810Bu, 0x00740858u, 4u);
        }

        case 0x00740858u: {
            TP_STATIC_GUARD(0x0E810Bu, 0x6Bu);
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
                case 0x00643B18u:
                case 0x00643EE8u:
                case 0x00644440u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x007409F3u: {
            TP_STATIC_GUARD(0x0E813Eu, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x813Fu, 0x007409FBu, 3u);
        }

        case 0x007409FBu: {
            TP_STATIC_GUARD(0x0E813Fu, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8140u, 0x00740A03u, 3u);
        }

        case 0x00740A03u: {
            TP_STATIC_GUARD(0x0E8140u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x8142u, 0x00740A13u, 3u);
        }

        case 0x00740A13u: {
            TP_STATIC_GUARD(0x0E8142u, 0xA9u, 0x0Bu);
            const uint8_t value = 0x0Bu;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8144u, 0x00740A23u, 2u);
        }

        case 0x00740A23u: {
            TP_STATIC_GUARD(0x0E8144u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x46u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740A3Bu: {
            TP_STATIC_GUARD(0x0E8147u, 0x68u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8148u, 0x00740A43u, 4u);
        }

        case 0x00740A43u: {
            TP_STATIC_GUARD(0x0E8148u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x4Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740A5Bu: {
            TP_STATIC_GUARD(0x0E814Bu, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            TP_STATIC_EXIT(0x0Eu, 0x814Cu, 0x00740A63u, 4u);
        }

        case 0x00740A63u: {
            TP_STATIC_GUARD(0x0E814Cu, 0x6Bu);
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
                case 0x006442EBu:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00740B58u: {
            TP_STATIC_GUARD(0x0E816Bu, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x816Cu, 0x00740B60u, 3u);
        }

        case 0x00740B60u: {
            TP_STATIC_GUARD(0x0E816Cu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x816Eu, 0x00740B73u, 3u);
        }

        case 0x00740B73u: {
            TP_STATIC_GUARD(0x0E816Eu, 0xC9u, 0x00u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x00u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8170u, 0x00740B83u, 2u);
        }

        case 0x00740B83u: {
            TP_STATIC_GUARD(0x0E8170u, 0xD0u, 0x04u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x8176u;
                if (tp_scpu_expect_next(cpu, 0x00740BB3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x8172u, 0x00740B93u, 2u);
        }

        case 0x00740B93u: {
            TP_STATIC_GUARD(0x0E8172u, 0xA9u, 0x14u);
            const uint8_t value = 0x14u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8174u, 0x00740BA3u, 2u);
        }

        case 0x00740BA3u: {
            TP_STATIC_GUARD(0x0E8174u, 0x80u, 0x02u);
            TP_STATIC_EXIT(0x0Eu, 0x8178u, 0x00740BC3u, 3u);
        }

        case 0x00740BB3u: {
            TP_STATIC_GUARD(0x0E8176u, 0xA9u, 0x05u);
            const uint8_t value = 0x05u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8178u, 0x00740BC3u, 2u);
        }

        case 0x00740BC3u: {
            TP_STATIC_GUARD(0x0E8178u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x7Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740BDBu: {
            TP_STATIC_GUARD(0x0E817Bu, 0xA0u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x817Du, 0x00740BEBu, 2u);
        }

        case 0x00740BEBu: {
            TP_STATIC_GUARD(0x0E817Du, 0xB7u, 0x00u);
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
            cpu->pc = 0x817Fu;
            if (tp_scpu_expect_next(cpu, 0x00740BFBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740BFBu: {
            TP_STATIC_GUARD(0x0E817Fu, 0xAAu);
            cpu->x = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8180u, 0x00740C03u, 2u);
        }

        case 0x00740C03u: {
            TP_STATIC_GUARD(0x0E8180u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740C1Bu: {
            TP_STATIC_GUARD(0x0E8183u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8184u, 0x00740C23u, 2u);
        }

        case 0x00740C23u: {
            TP_STATIC_GUARD(0x0E8184u, 0xB7u, 0x00u);
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
            cpu->pc = 0x8186u;
            if (tp_scpu_expect_next(cpu, 0x00740C33u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740C33u: {
            TP_STATIC_GUARD(0x0E8186u, 0x85u, 0x04u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x04u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8188u;
            if (tp_scpu_expect_next(cpu, 0x00740C43u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740C43u: {
            TP_STATIC_GUARD(0x0E8188u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740C5Bu: {
            TP_STATIC_GUARD(0x0E818Bu, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x818Cu, 0x00740C63u, 2u);
        }

        case 0x00740C63u: {
            TP_STATIC_GUARD(0x0E818Cu, 0xB7u, 0x00u);
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
            cpu->pc = 0x818Eu;
            if (tp_scpu_expect_next(cpu, 0x00740C73u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740C73u: {
            TP_STATIC_GUARD(0x0E818Eu, 0x85u, 0x05u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x05u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x8190u;
            if (tp_scpu_expect_next(cpu, 0x00740C83u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740C83u: {
            TP_STATIC_GUARD(0x0E8190u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x92u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740C9Bu: {
            TP_STATIC_GUARD(0x0E8193u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8194u, 0x00740CA3u, 2u);
        }

        case 0x00740CA3u: {
            TP_STATIC_GUARD(0x0E8194u, 0xB7u, 0x00u);
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
            cpu->pc = 0x8196u;
            if (tp_scpu_expect_next(cpu, 0x00740CB3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740CB3u: {
            TP_STATIC_GUARD(0x0E8196u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x98u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740CCBu: {
            TP_STATIC_GUARD(0x0E8199u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x819Au, 0x00740CD3u, 2u);
        }

        case 0x00740CD3u: {
            TP_STATIC_GUARD(0x0E819Au, 0xB7u, 0x00u);
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
            cpu->pc = 0x819Cu;
            if (tp_scpu_expect_next(cpu, 0x00740CE3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740CE3u: {
            TP_STATIC_GUARD(0x0E819Cu, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x9Eu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740CFBu: {
            TP_STATIC_GUARD(0x0E819Fu, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x81A0u, 0x00740D03u, 2u);
        }

        case 0x00740D03u: {
            TP_STATIC_GUARD(0x0E81A0u, 0xB7u, 0x00u);
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
            cpu->pc = 0x81A2u;
            if (tp_scpu_expect_next(cpu, 0x00740D13u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740D13u: {
            TP_STATIC_GUARD(0x0E81A2u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA4u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740D2Bu: {
            TP_STATIC_GUARD(0x0E81A5u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x81A6u, 0x00740D33u, 2u);
        }

        case 0x00740D33u: {
            TP_STATIC_GUARD(0x0E81A6u, 0xB7u, 0x00u);
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
            cpu->pc = 0x81A8u;
            if (tp_scpu_expect_next(cpu, 0x00740D43u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740D43u: {
            TP_STATIC_GUARD(0x0E81A8u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xAAu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740D5Bu: {
            TP_STATIC_GUARD(0x0E81ABu, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x81ACu, 0x00740D63u, 2u);
        }

        case 0x00740D63u: {
            TP_STATIC_GUARD(0x0E81ACu, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x81ADu, 0x00740D6Bu, 2u);
        }

        case 0x00740D6Bu: {
            TP_STATIC_GUARD(0x0E81ADu, 0xD0u, 0xE5u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x8194u;
                if (tp_scpu_expect_next(cpu, 0x00740CA3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x81AFu, 0x00740D7Bu, 2u);
        }

        case 0x00740D7Bu: {
            TP_STATIC_GUARD(0x0E81AFu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Eu, 0x81B0u, 0x00740D83u, 2u);
        }

        case 0x00740D83u: {
            TP_STATIC_GUARD(0x0E81B0u, 0x98u);
            const uint8_t value = (uint8_t)(cpu->y & 0x00FFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x81B1u, 0x00740D8Bu, 2u);
        }

        case 0x00740D8Bu: {
            TP_STATIC_GUARD(0x0E81B1u, 0x65u, 0x00u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x00u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81B3u;
            if (tp_scpu_expect_next(cpu, 0x00740D9Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740D9Bu: {
            TP_STATIC_GUARD(0x0E81B3u, 0x85u, 0x00u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x00u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81B5u;
            if (tp_scpu_expect_next(cpu, 0x00740DABu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740DABu: {
            TP_STATIC_GUARD(0x0E81B5u, 0xA5u, 0x01u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x01u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81B7u;
            if (tp_scpu_expect_next(cpu, 0x00740DBBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740DBBu: {
            TP_STATIC_GUARD(0x0E81B7u, 0x69u, 0x00u);
            if (tp_scpu_adc(cpu, 0x00u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x81B9u, 0x00740DCBu, 2u);
        }

        case 0x00740DCBu: {
            TP_STATIC_GUARD(0x0E81B9u, 0x85u, 0x01u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x01u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81BBu;
            if (tp_scpu_expect_next(cpu, 0x00740DDBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740DDBu: {
            TP_STATIC_GUARD(0x0E81BBu, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x81BDu, 0x00740DEBu, 2u);
        }

        case 0x00740DEBu: {
            TP_STATIC_GUARD(0x0E81BDu, 0x85u, 0x10u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x10u);
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81BFu;
            if (tp_scpu_expect_next(cpu, 0x00740DFBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740DFBu: {
            TP_STATIC_GUARD(0x0E81BFu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Eu, 0x81C1u, 0x00740E08u, 3u);
        }

        case 0x00740E08u: {
            TP_STATIC_GUARD(0x0E81C1u, 0xA5u, 0x04u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x04u);
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81C3u;
            if (tp_scpu_expect_next(cpu, 0x00740E18u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740E18u: {
            TP_STATIC_GUARD(0x0E81C3u, 0x85u, 0x11u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x11u);
            if (tp_scpu_write16(cpu, bus, address, (uint16_t)cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81C5u;
            if (tp_scpu_expect_next(cpu, 0x00740E28u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740E28u: {
            TP_STATIC_GUARD(0x0E81C5u, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            TP_STATIC_EXIT(0x0Eu, 0x81C6u, 0x00740E30u, 4u);
        }

        case 0x00740E30u: {
            TP_STATIC_GUARD(0x0E81C6u, 0x6Bu);
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
                case 0x00040DF0u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00740E3Bu: {
            TP_STATIC_GUARD(0x0E81C7u, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x81C8u, 0x00740E43u, 3u);
        }

        case 0x00740E43u: {
            TP_STATIC_GUARD(0x0E81C8u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x81CAu, 0x00740E53u, 3u);
        }

        case 0x00740E53u: {
            TP_STATIC_GUARD(0x0E81CAu, 0xA9u, 0x06u);
            const uint8_t value = 0x06u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x81CCu, 0x00740E63u, 2u);
        }

        case 0x00740E63u: {
            TP_STATIC_GUARD(0x0E81CCu, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCEu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740E7Bu: {
            TP_STATIC_GUARD(0x0E81CFu, 0xA5u, 0x08u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x08u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81D1u;
            if (tp_scpu_expect_next(cpu, 0x00740E8Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740E8Bu: {
            TP_STATIC_GUARD(0x0E81D1u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xD3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740EA3u: {
            TP_STATIC_GUARD(0x0E81D4u, 0xA5u, 0x0Du);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x0Du);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81D6u;
            if (tp_scpu_expect_next(cpu, 0x00740EB3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740EB3u: {
            TP_STATIC_GUARD(0x0E81D6u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xD8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740ECBu: {
            TP_STATIC_GUARD(0x0E81D9u, 0xA5u, 0x09u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x09u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81DBu;
            if (tp_scpu_expect_next(cpu, 0x00740EDBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740EDBu: {
            TP_STATIC_GUARD(0x0E81DBu, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDDu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740EF3u: {
            TP_STATIC_GUARD(0x0E81DEu, 0xA5u, 0x0Au);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x0Au);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81E0u;
            if (tp_scpu_expect_next(cpu, 0x00740F03u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740F03u: {
            TP_STATIC_GUARD(0x0E81E0u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE2u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740F1Bu: {
            TP_STATIC_GUARD(0x0E81E3u, 0xA5u, 0x0Bu);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x0Bu);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81E5u;
            if (tp_scpu_expect_next(cpu, 0x00740F2Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740F2Bu: {
            TP_STATIC_GUARD(0x0E81E5u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE7u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740F43u: {
            TP_STATIC_GUARD(0x0E81E8u, 0xA5u, 0x0Cu);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x0Cu);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81EAu;
            if (tp_scpu_expect_next(cpu, 0x00740F53u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740F53u: {
            TP_STATIC_GUARD(0x0E81EAu, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xECu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740F6Bu: {
            TP_STATIC_GUARD(0x0E81EDu, 0xA5u, 0x07u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x07u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81EFu;
            if (tp_scpu_expect_next(cpu, 0x00740F7Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740F7Bu: {
            TP_STATIC_GUARD(0x0E81EFu, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF1u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740F93u: {
            TP_STATIC_GUARD(0x0E81F2u, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            TP_STATIC_EXIT(0x0Eu, 0x81F3u, 0x00740F9Bu, 4u);
        }

        case 0x00740F9Bu: {
            TP_STATIC_GUARD(0x0E81F3u, 0x6Bu);
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
                case 0x0064474Bu:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00740FA0u: {
            TP_STATIC_GUARD(0x0E81F4u, 0x08u);
            if (tp_scpu_push8(cpu, bus, cpu->p) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x81F5u, 0x00740FA8u, 3u);
        }

        case 0x00740FA8u: {
            TP_STATIC_GUARD(0x0E81F5u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0x81F7u, 0x00740FBBu, 3u);
        }

        case 0x00740FBBu: {
            TP_STATIC_GUARD(0x0E81F7u, 0xA9u, 0x11u);
            const uint8_t value = 0x11u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x81F9u, 0x00740FCBu, 2u);
        }

        case 0x00740FCBu: {
            TP_STATIC_GUARD(0x0E81F9u, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xFBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        case 0x00740FE3u: {
            TP_STATIC_GUARD(0x0E81FCu, 0xA5u, 0x04u);
            const uint32_t address = (uint32_t)(uint16_t)(cpu->d + 0x04u);
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Eu;
            cpu->pc = 0x81FEu;
            if (tp_scpu_expect_next(cpu, 0x00740FF3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00740FF3u: {
            TP_STATIC_GUARD(0x0E81FEu, 0x20u, 0x44u, 0x82u);
            if (tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x00u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8244u, 0x00741223u, 6u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
