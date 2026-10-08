/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_00009E(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x0004F008u: {
            TP_STATIC_GUARD(0x009E01u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E02u, 0x0004F010u, 4u);
        }

        case 0x0004F010u: {
            TP_STATIC_GUARD(0x009E02u, 0xADu, 0x9Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x079Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E05u, 0x0004F028u, 5u);
        }

        case 0x0004F028u: {
            TP_STATIC_GUARD(0x009E05u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E06u, 0x0004F030u, 4u);
        }

        case 0x0004F030u: {
            TP_STATIC_GUARD(0x009E06u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x9E08u, 0x0004F041u, 3u);
        }

        case 0x0004F041u: {
            TP_STATIC_GUARD(0x009E08u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0x9E0Au, 0x0004F051u, 3u);
        }

        case 0x0004F051u: {
            TP_STATIC_GUARD(0x009E0Au, 0xADu, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0016u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E0Du, 0x0004F069u, 5u);
        }

        case 0x0004F069u: {
            TP_STATIC_GUARD(0x009E0Du, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E0Eu, 0x0004F071u, 4u);
        }

        case 0x0004F071u: {
            TP_STATIC_GUARD(0x009E0Eu, 0xAEu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E11u, 0x0004F089u, 4u);
        }

        case 0x0004F089u: {
            TP_STATIC_GUARD(0x009E11u, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E12u, 0x0004F091u, 3u);
        }

        case 0x0004F091u: {
            TP_STATIC_GUARD(0x009E12u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x9E14u, 0x0004F0A1u, 3u);
        }

        case 0x0004F0A1u: {
            TP_STATIC_GUARD(0x009E14u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0x9E16u, 0x0004F0B1u, 3u);
        }

        case 0x0004F0B1u: {
            TP_STATIC_GUARD(0x009E16u, 0xADu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E19u, 0x0004F0C9u, 5u);
        }

        case 0x0004F0C9u: {
            TP_STATIC_GUARD(0x009E19u, 0x8Du, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0016u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E1Cu, 0x0004F0E1u, 5u);
        }

        case 0x0004F0E1u: {
            TP_STATIC_GUARD(0x009E1Cu, 0xAEu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E1Fu, 0x0004F0F9u, 4u);
        }

        case 0x0004F0F9u: {
            TP_STATIC_GUARD(0x009E1Fu, 0x8Eu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E22u, 0x0004F111u, 4u);
        }

        case 0x0004F111u: {
            TP_STATIC_GUARD(0x009E22u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x9E24u, 0x0004F123u, 3u);
        }

        case 0x0004F123u: {
            TP_STATIC_GUARD(0x009E24u, 0xADu, 0xC4u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1FC4u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E27u, 0x0004F13Bu, 4u);
        }

        case 0x0004F13Bu: {
            TP_STATIC_GUARD(0x009E27u, 0xD0u, 0x09u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9E32u;
                if (tp_scpu_expect_next(cpu, 0x0004F193u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9E29u, 0x0004F14Bu, 2u);
        }

        case 0x0004F14Bu: {
            TP_STATIC_GUARD(0x009E29u, 0xA0u, 0x03u);
            const uint8_t value = 0x03u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E2Bu, 0x0004F15Bu, 2u);
        }

        case 0x0004F15Bu: {
            TP_STATIC_GUARD(0x009E2Bu, 0xB7u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
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
            cpu->pbr = 0x00u;
            cpu->pc = 0x9E2Du;
            if (tp_scpu_expect_next(cpu, 0x0004F16Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0004F16Bu: {
            TP_STATIC_GUARD(0x009E2Du, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9E32u;
                if (tp_scpu_expect_next(cpu, 0x0004F193u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9E2Fu, 0x0004F17Bu, 2u);
        }

        case 0x0004F17Bu: {
            TP_STATIC_GUARD(0x009E2Fu, 0x8Du, 0x8Cu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E32u, 0x0004F193u, 4u);
        }

        case 0x0004F193u: {
            TP_STATIC_GUARD(0x009E32u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x9E34u, 0x0004F1A3u, 3u);
        }

        case 0x0004F1A3u: {
            TP_STATIC_GUARD(0x009E34u, 0xA0u, 0x10u);
            const uint8_t value = 0x10u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E36u, 0x0004F1B3u, 2u);
        }

        case 0x0004F1B3u: {
            TP_STATIC_GUARD(0x009E36u, 0xB7u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
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
            cpu->pbr = 0x00u;
            cpu->pc = 0x9E38u;
            if (tp_scpu_expect_next(cpu, 0x0004F1C3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0004F1C3u: {
            TP_STATIC_GUARD(0x009E38u, 0xC9u, 0x12u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x12u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E3Au, 0x0004F1D3u, 2u);
        }

        case 0x0004F1D3u: {
            TP_STATIC_GUARD(0x009E3Au, 0xD0u, 0x7Au);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9EB6u;
                if (tp_scpu_expect_next(cpu, 0x0004F5B3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9E3Cu, 0x0004F1E3u, 2u);
        }

        case 0x0004F1E3u: {
            TP_STATIC_GUARD(0x009E3Cu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x9E3Eu, 0x0004F1F3u, 3u);
        }

        case 0x0004F1F3u: {
            TP_STATIC_GUARD(0x009E3Eu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0x9E40u, 0x0004F201u, 3u);
        }

        case 0x0004F201u: {
            TP_STATIC_GUARD(0x009E40u, 0xA0u, 0x0Bu);
            const uint8_t value = 0x0Bu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E42u, 0x0004F211u, 2u);
        }

        case 0x0004F211u: {
            TP_STATIC_GUARD(0x009E42u, 0xB7u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
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
            cpu->pbr = 0x00u;
            cpu->pc = 0x9E44u;
            if (tp_scpu_expect_next(cpu, 0x0004F221u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0004F221u: {
            TP_STATIC_GUARD(0x009E44u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E47u, 0x0004F239u, 3u);
        }

        case 0x0004F239u: {
            TP_STATIC_GUARD(0x009E47u, 0x8Du, 0x58u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0758u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E4Au, 0x0004F251u, 5u);
        }

        case 0x0004F251u: {
            TP_STATIC_GUARD(0x009E4Au, 0xA0u, 0x0Du);
            const uint8_t value = 0x0Du;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E4Cu, 0x0004F261u, 2u);
        }

        case 0x0004F261u: {
            TP_STATIC_GUARD(0x009E4Cu, 0xB7u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
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
            cpu->pbr = 0x00u;
            cpu->pc = 0x9E4Eu;
            if (tp_scpu_expect_next(cpu, 0x0004F271u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0004F271u: {
            TP_STATIC_GUARD(0x009E4Eu, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E51u, 0x0004F289u, 3u);
        }

        case 0x0004F289u: {
            TP_STATIC_GUARD(0x009E51u, 0x8Du, 0x5Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x075Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E54u, 0x0004F2A1u, 5u);
        }

        case 0x0004F2A1u: {
            TP_STATIC_GUARD(0x009E54u, 0xADu, 0x5Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x075Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E57u, 0x0004F2B9u, 5u);
        }

        case 0x0004F2B9u: {
            TP_STATIC_GUARD(0x009E57u, 0xA2u, 0x40u);
            const uint8_t value = 0x40u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E59u, 0x0004F2C9u, 2u);
        }

        case 0x0004F2C9u: {
            TP_STATIC_GUARD(0x009E59u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x9E5Bu, 0x0004F2DBu, 3u);
        }

        case 0x0004F2DBu: {
            TP_STATIC_GUARD(0x009E5Bu, 0x8Du, 0x1Bu, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x211Bu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E5Eu, 0x0004F2F3u, 4u);
        }

        case 0x0004F2F3u: {
            TP_STATIC_GUARD(0x009E5Eu, 0xEBu);
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->a & 0x00FFu) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->a & 0x00FFu) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E5Fu, 0x0004F2FBu, 3u);
        }

        case 0x0004F2FBu: {
            TP_STATIC_GUARD(0x009E5Fu, 0x8Du, 0x1Bu, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x211Bu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E62u, 0x0004F313u, 4u);
        }

        case 0x0004F313u: {
            TP_STATIC_GUARD(0x009E62u, 0x8Eu, 0x1Cu, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x211Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E65u, 0x0004F32Bu, 4u);
        }

        case 0x0004F32Bu: {
            TP_STATIC_GUARD(0x009E65u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x9E67u, 0x0004F33Bu, 3u);
        }

        case 0x0004F33Bu: {
            TP_STATIC_GUARD(0x009E67u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0x9E69u, 0x0004F349u, 3u);
        }

        case 0x0004F349u: {
            TP_STATIC_GUARD(0x009E69u, 0xADu, 0x34u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x2134u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E6Cu, 0x0004F361u, 5u);
        }

        case 0x0004F361u: {
            TP_STATIC_GUARD(0x009E6Cu, 0xAEu, 0x36u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x2136u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E6Fu, 0x0004F379u, 4u);
        }

        case 0x0004F379u: {
            TP_STATIC_GUARD(0x009E6Fu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x00u, 0x9E70u, 0x0004F381u, 2u);
        }

        case 0x0004F381u: {
            TP_STATIC_GUARD(0x009E70u, 0x6Du, 0x58u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0758u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E73u, 0x0004F399u, 5u);
        }

        case 0x0004F399u: {
            TP_STATIC_GUARD(0x009E73u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0x9E75u, 0x0004F3A8u, 3u);
        }

        case 0x0004F3A8u: {
            TP_STATIC_GUARD(0x009E75u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E76u, 0x0004F3B0u, 2u);
        }

        case 0x0004F3B0u: {
            TP_STATIC_GUARD(0x009E76u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E77u, 0x0004F3B8u, 2u);
        }

        case 0x0004F3B8u: {
            TP_STATIC_GUARD(0x009E77u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E78u, 0x0004F3C0u, 3u);
        }

        case 0x0004F3C0u: {
            TP_STATIC_GUARD(0x009E78u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E79u, 0x0004F3C8u, 3u);
        }

        case 0x0004F3C8u: {
            TP_STATIC_GUARD(0x009E79u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E7Au, 0x0004F3D0u, 2u);
        }

        case 0x0004F3D0u: {
            TP_STATIC_GUARD(0x009E7Au, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x00u, 0x9E7Bu, 0x0004F3D8u, 2u);
        }

        case 0x0004F3D8u: {
            TP_STATIC_GUARD(0x009E7Bu, 0x6Du, 0x4Fu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x004Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E7Eu, 0x0004F3F0u, 5u);
        }

        case 0x0004F3F0u: {
            TP_STATIC_GUARD(0x009E7Eu, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E81u, 0x0004F408u, 5u);
        }

        case 0x0004F408u: {
            TP_STATIC_GUARD(0x009E81u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x9E83u, 0x0004F41Bu, 3u);
        }

        case 0x0004F41Bu: {
            TP_STATIC_GUARD(0x009E83u, 0xADu, 0x51u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0051u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E86u, 0x0004F433u, 4u);
        }

        case 0x0004F433u: {
            TP_STATIC_GUARD(0x009E86u, 0x8Du, 0x66u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0066u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9E89u, 0x0004F44Bu, 4u);
        }

        case 0x0004F44Bu: {
            TP_STATIC_GUARD(0x009E89u, 0xA0u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E8Bu, 0x0004F45Bu, 2u);
        }

        case 0x0004F45Bu: {
            TP_STATIC_GUARD(0x009E8Bu, 0xB7u, 0x64u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x64u);
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
            cpu->pbr = 0x00u;
            cpu->pc = 0x9E8Du;
            if (tp_scpu_expect_next(cpu, 0x0004F46Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0004F46Bu: {
            TP_STATIC_GUARD(0x009E8Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0x9E8Fu, 0x0004F478u, 3u);
        }

        case 0x0004F478u: {
            TP_STATIC_GUARD(0x009E8Fu, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E92u, 0x0004F490u, 3u);
        }

        case 0x0004F490u: {
            TP_STATIC_GUARD(0x009E92u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E93u, 0x0004F498u, 2u);
        }

        case 0x0004F498u: {
            TP_STATIC_GUARD(0x009E93u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E94u, 0x0004F4A0u, 2u);
        }

        case 0x0004F4A0u: {
            TP_STATIC_GUARD(0x009E94u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E95u, 0x0004F4A8u, 3u);
        }

        case 0x0004F4A8u: {
            TP_STATIC_GUARD(0x009E95u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E96u, 0x0004F4B0u, 3u);
        }

        case 0x0004F4B0u: {
            TP_STATIC_GUARD(0x009E96u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E97u, 0x0004F4B8u, 2u);
        }

        case 0x0004F4B8u: {
            TP_STATIC_GUARD(0x009E97u, 0xBBu);
            cpu->x = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E98u, 0x0004F4C0u, 2u);
        }

        case 0x0004F4C0u: {
            TP_STATIC_GUARD(0x009E98u, 0xBFu, 0xB7u, 0x88u, 0x01u);
            const uint32_t address = (0x0188B7u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E9Cu, 0x0004F4E0u, 6u);
        }

        case 0x0004F4E0u: {
            TP_STATIC_GUARD(0x009E9Cu, 0xC9u, 0x40u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0040u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9E9Fu, 0x0004F4F8u, 3u);
        }

        case 0x0004F4F8u: {
            TP_STATIC_GUARD(0x009E9Fu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9EA4u;
                if (tp_scpu_expect_next(cpu, 0x0004F520u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9EA1u, 0x0004F508u, 2u);
        }

        case 0x0004F508u: {
            TP_STATIC_GUARD(0x009EA1u, 0x82u, 0x9Eu, 0x02u);
            TP_STATIC_EXIT(0x00u, 0xA142u, 0x00050A10u, 4u);
        }

        case 0x0004F520u: {
            TP_STATIC_GUARD(0x009EA4u, 0x20u, 0x6Fu, 0xA1u);
            if (tp_scpu_push8(cpu, bus, 0x9Eu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA6u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA16Fu, 0x00050B78u, 6u);
        }

        case 0x0004F523u: {
            TP_STATIC_GUARD(0x009EA4u, 0x20u, 0x6Fu, 0xA1u);
            if (tp_scpu_push8(cpu, bus, 0x9Eu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA6u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA16Fu, 0x00050B7Bu, 6u);
        }

        case 0x0004F53Bu: {
            TP_STATIC_GUARD(0x009EA7u, 0xADu, 0x98u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0798u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9EAAu, 0x0004F553u, 4u);
        }

        case 0x0004F553u: {
            TP_STATIC_GUARD(0x009EAAu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x00u, 0x9EABu, 0x0004F55Bu, 2u);
        }

        case 0x0004F55Bu: {
            TP_STATIC_GUARD(0x009EABu, 0xE9u, 0x04u);
            if (tp_scpu_sbc(cpu, 0x04u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9EADu, 0x0004F56Bu, 2u);
        }

        case 0x0004F56Bu: {
            TP_STATIC_GUARD(0x009EADu, 0x8Du, 0x98u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0798u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9EB0u, 0x0004F583u, 4u);
        }

        case 0x0004F583u: {
            TP_STATIC_GUARD(0x009EB0u, 0x8Du, 0x63u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0763u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9EB3u, 0x0004F59Bu, 4u);
        }

        case 0x0004F59Bu: {
            TP_STATIC_GUARD(0x009EB3u, 0x82u, 0x7Bu, 0x00u);
            TP_STATIC_EXIT(0x00u, 0x9F31u, 0x0004F98Bu, 4u);
        }

        case 0x0004F5B3u: {
            TP_STATIC_GUARD(0x009EB6u, 0xC9u, 0x36u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x36u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9EB8u, 0x0004F5C3u, 2u);
        }

        case 0x0004F5C3u: {
            TP_STATIC_GUARD(0x009EB8u, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9EC0u;
                if (tp_scpu_expect_next(cpu, 0x0004F603u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9EBAu, 0x0004F5D3u, 2u);
        }

        case 0x0004F5D3u: {
            TP_STATIC_GUARD(0x009EBAu, 0x82u, 0xE7u, 0xFFu);
            TP_STATIC_EXIT(0x00u, 0x9EA4u, 0x0004F523u, 4u);
        }

        case 0x0004F603u: {
            TP_STATIC_GUARD(0x009EC0u, 0xC9u, 0x18u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x18u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9EC2u, 0x0004F613u, 2u);
        }

        case 0x0004F613u: {
            TP_STATIC_GUARD(0x009EC2u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9EC7u;
                if (tp_scpu_expect_next(cpu, 0x0004F63Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9EC4u, 0x0004F623u, 2u);
        }

        case 0x0004F623u: {
            TP_STATIC_GUARD(0x009EC4u, 0x82u, 0x67u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0x9F2Eu, 0x0004F973u, 4u);
        }

        case 0x0004F63Bu: {
            TP_STATIC_GUARD(0x009EC7u, 0xC9u, 0x1Au);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x1Au;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9EC9u, 0x0004F64Bu, 2u);
        }

        case 0x0004F64Bu: {
            TP_STATIC_GUARD(0x009EC9u, 0xF0u, 0x63u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9ECBu, 0x0004F65Bu, 2u);
        }

        case 0x0004F65Bu: {
            TP_STATIC_GUARD(0x009ECBu, 0xC9u, 0x14u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x14u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9ECDu, 0x0004F66Bu, 2u);
        }

        case 0x0004F66Bu: {
            TP_STATIC_GUARD(0x009ECDu, 0xF0u, 0x5Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9ECFu, 0x0004F67Bu, 2u);
        }

        case 0x0004F67Bu: {
            TP_STATIC_GUARD(0x009ECFu, 0xC9u, 0x02u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x02u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9ED1u, 0x0004F68Bu, 2u);
        }

        case 0x0004F68Bu: {
            TP_STATIC_GUARD(0x009ED1u, 0xF0u, 0x5Bu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9ED3u, 0x0004F69Bu, 2u);
        }

        case 0x0004F69Bu: {
            TP_STATIC_GUARD(0x009ED3u, 0xC9u, 0x04u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x04u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9ED5u, 0x0004F6ABu, 2u);
        }

        case 0x0004F6ABu: {
            TP_STATIC_GUARD(0x009ED5u, 0xF0u, 0x57u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9ED7u, 0x0004F6BBu, 2u);
        }

        case 0x0004F6BBu: {
            TP_STATIC_GUARD(0x009ED7u, 0xC9u, 0x06u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x06u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9ED9u, 0x0004F6CBu, 2u);
        }

        case 0x0004F6CBu: {
            TP_STATIC_GUARD(0x009ED9u, 0xF0u, 0x53u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9EDBu, 0x0004F6DBu, 2u);
        }

        case 0x0004F6DBu: {
            TP_STATIC_GUARD(0x009EDBu, 0xC9u, 0x08u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x08u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9EDDu, 0x0004F6EBu, 2u);
        }

        case 0x0004F6EBu: {
            TP_STATIC_GUARD(0x009EDDu, 0xF0u, 0x4Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9EDFu, 0x0004F6FBu, 2u);
        }

        case 0x0004F6FBu: {
            TP_STATIC_GUARD(0x009EDFu, 0xC9u, 0x0Au);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x0Au;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9EE1u, 0x0004F70Bu, 2u);
        }

        case 0x0004F70Bu: {
            TP_STATIC_GUARD(0x009EE1u, 0xF0u, 0x4Bu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9EE3u, 0x0004F71Bu, 2u);
        }

        case 0x0004F71Bu: {
            TP_STATIC_GUARD(0x009EE3u, 0xC9u, 0x10u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x10u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9EE5u, 0x0004F72Bu, 2u);
        }

        case 0x0004F72Bu: {
            TP_STATIC_GUARD(0x009EE5u, 0xF0u, 0x47u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9EE7u, 0x0004F73Bu, 2u);
        }

        case 0x0004F73Bu: {
            TP_STATIC_GUARD(0x009EE7u, 0xC9u, 0x1Eu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x1Eu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9EE9u, 0x0004F74Bu, 2u);
        }

        case 0x0004F74Bu: {
            TP_STATIC_GUARD(0x009EE9u, 0xF0u, 0x43u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9EEBu, 0x0004F75Bu, 2u);
        }

        case 0x0004F75Bu: {
            TP_STATIC_GUARD(0x009EEBu, 0xC9u, 0x20u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x20u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9EEDu, 0x0004F76Bu, 2u);
        }

        case 0x0004F76Bu: {
            TP_STATIC_GUARD(0x009EEDu, 0xF0u, 0x3Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9EEFu, 0x0004F77Bu, 2u);
        }

        case 0x0004F77Bu: {
            TP_STATIC_GUARD(0x009EEFu, 0xC9u, 0x22u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x22u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9EF1u, 0x0004F78Bu, 2u);
        }

        case 0x0004F78Bu: {
            TP_STATIC_GUARD(0x009EF1u, 0xF0u, 0x3Bu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9EF3u, 0x0004F79Bu, 2u);
        }

        case 0x0004F79Bu: {
            TP_STATIC_GUARD(0x009EF3u, 0xC9u, 0x0Cu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x0Cu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9EF5u, 0x0004F7ABu, 2u);
        }

        case 0x0004F7ABu: {
            TP_STATIC_GUARD(0x009EF5u, 0xF0u, 0x37u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9EF7u, 0x0004F7BBu, 2u);
        }

        case 0x0004F7BBu: {
            TP_STATIC_GUARD(0x009EF7u, 0xC9u, 0x2Cu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x2Cu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9EF9u, 0x0004F7CBu, 2u);
        }

        case 0x0004F7CBu: {
            TP_STATIC_GUARD(0x009EF9u, 0xF0u, 0x33u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9EFBu, 0x0004F7DBu, 2u);
        }

        case 0x0004F7DBu: {
            TP_STATIC_GUARD(0x009EFBu, 0xC9u, 0x28u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x28u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9EFDu, 0x0004F7EBu, 2u);
        }

        case 0x0004F7EBu: {
            TP_STATIC_GUARD(0x009EFDu, 0xF0u, 0x2Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9F2Eu;
                if (tp_scpu_expect_next(cpu, 0x0004F973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x9EFFu, 0x0004F7FBu, 2u);
        }

        case 0x0004F7FBu: {
            TP_STATIC_GUARD(0x009EFFu, 0xC9u, 0x2Au);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x2Au;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9F01u, 0x0004F80Bu, 2u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
