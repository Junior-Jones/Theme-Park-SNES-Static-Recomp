/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0007C5(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x003E2808u: {
            TP_STATIC_GUARD(0x07C501u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xC506u;
                if (tp_scpu_expect_next(cpu, 0x003E2830u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xC503u, 0x003E2818u, 2u);
        }

        case 0x003E2818u: {
            TP_STATIC_GUARD(0x07C503u, 0x82u, 0x5Du, 0x03u);
            TP_STATIC_EXIT(0x07u, 0xC863u, 0x003E4318u, 4u);
        }

        case 0x003E2830u: {
            TP_STATIC_GUARD(0x07C506u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xC508u, 0x003E2843u, 3u);
        }

        case 0x003E2843u: {
            TP_STATIC_GUARD(0x07C508u, 0xADu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC50Bu, 0x003E285Bu, 4u);
        }

        case 0x003E285Bu: {
            TP_STATIC_GUARD(0x07C50Bu, 0xD0u, 0x0Du);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xC51Au;
                if (tp_scpu_expect_next(cpu, 0x003E28D3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xC50Du, 0x003E286Bu, 2u);
        }

        case 0x003E286Bu: {
            TP_STATIC_GUARD(0x07C50Du, 0xADu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC510u, 0x003E2883u, 4u);
        }

        case 0x003E2883u: {
            TP_STATIC_GUARD(0x07C510u, 0xD0u, 0x08u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xC51Au;
                if (tp_scpu_expect_next(cpu, 0x003E28D3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xC512u, 0x003E2893u, 2u);
        }

        case 0x003E2893u: {
            TP_STATIC_GUARD(0x07C512u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0xC514u, 0x003E28A0u, 3u);
        }

        case 0x003E28A0u: {
            TP_STATIC_GUARD(0x07C514u, 0xA9u, 0xFEu, 0xFFu);
            const uint16_t value = 0xFFFEu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC517u, 0x003E28B8u, 3u);
        }

        case 0x003E28B8u: {
            TP_STATIC_GUARD(0x07C517u, 0x82u, 0x51u, 0x03u);
            TP_STATIC_EXIT(0x07u, 0xC86Bu, 0x003E4358u, 4u);
        }

        case 0x003E28D3u: {
            TP_STATIC_GUARD(0x07C51Au, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0xC51Cu, 0x003E28E0u, 3u);
        }

        case 0x003E28E0u: {
            TP_STATIC_GUARD(0x07C51Cu, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC51Fu, 0x003E28F8u, 5u);
        }

        case 0x003E28F8u: {
            TP_STATIC_GUARD(0x07C51Fu, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC522u, 0x003E2910u, 3u);
        }

        case 0x003E2910u: {
            TP_STATIC_GUARD(0x07C522u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC523u, 0x003E2918u, 2u);
        }

        case 0x003E2918u: {
            TP_STATIC_GUARD(0x07C523u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC524u, 0x003E2920u, 2u);
        }

        case 0x003E2920u: {
            TP_STATIC_GUARD(0x07C524u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC525u, 0x003E2928u, 3u);
        }

        case 0x003E2928u: {
            TP_STATIC_GUARD(0x07C525u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC526u, 0x003E2930u, 2u);
        }

        case 0x003E2930u: {
            TP_STATIC_GUARD(0x07C526u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC527u, 0x003E2938u, 2u);
        }

        case 0x003E2938u: {
            TP_STATIC_GUARD(0x07C527u, 0xBFu, 0x19u, 0x8Eu, 0x01u);
            const uint32_t address = (0x018E19u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC52Bu, 0x003E2958u, 6u);
        }

        case 0x003E2958u: {
            TP_STATIC_GUARD(0x07C52Bu, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC52Cu, 0x003E2960u, 2u);
        }

        case 0x003E2960u: {
            TP_STATIC_GUARD(0x07C52Cu, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC52Du, 0x003E2968u, 2u);
        }

        case 0x003E2968u: {
            TP_STATIC_GUARD(0x07C52Du, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC52Eu, 0x003E2970u, 3u);
        }

        case 0x003E2970u: {
            TP_STATIC_GUARD(0x07C52Eu, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC52Fu, 0x003E2978u, 3u);
        }

        case 0x003E2978u: {
            TP_STATIC_GUARD(0x07C52Fu, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC530u, 0x003E2980u, 2u);
        }

        case 0x003E2980u: {
            TP_STATIC_GUARD(0x07C530u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xC531u, 0x003E2988u, 2u);
        }

        case 0x003E2988u: {
            TP_STATIC_GUARD(0x07C531u, 0x6Du, 0x46u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0046u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC534u, 0x003E29A0u, 5u);
        }

        case 0x003E29A0u: {
            TP_STATIC_GUARD(0x07C534u, 0x8Du, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0016u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC537u, 0x003E29B8u, 5u);
        }

        case 0x003E29B8u: {
            TP_STATIC_GUARD(0x07C537u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xC539u, 0x003E29CBu, 3u);
        }

        case 0x003E29CBu: {
            TP_STATIC_GUARD(0x07C539u, 0xADu, 0x48u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0048u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC53Cu, 0x003E29E3u, 4u);
        }

        case 0x003E29E3u: {
            TP_STATIC_GUARD(0x07C53Cu, 0x8Du, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0018u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC53Fu, 0x003E29FBu, 4u);
        }

        case 0x003E29F8u: {
            TP_STATIC_GUARD(0x07C53Fu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xC541u, 0x003E2A09u, 3u);
        }

        case 0x003E29FBu: {
            TP_STATIC_GUARD(0x07C53Fu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xC541u, 0x003E2A0Bu, 3u);
        }

        case 0x003E2A09u: {
            TP_STATIC_GUARD(0x07C541u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x07u, 0xC543u, 0x003E2A19u, 3u);
        }

        case 0x003E2A0Bu: {
            TP_STATIC_GUARD(0x07C541u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x07u, 0xC543u, 0x003E2A19u, 3u);
        }

        case 0x003E2A19u: {
            TP_STATIC_GUARD(0x07C543u, 0xA0u, 0x57u);
            const uint8_t value = 0x57u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC545u, 0x003E2A29u, 2u);
        }

        case 0x003E2A29u: {
            TP_STATIC_GUARD(0x07C545u, 0xB7u, 0x19u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x19u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xC547u;
            if (tp_scpu_expect_next(cpu, 0x003E2A39u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003E2A39u: {
            TP_STATIC_GUARD(0x07C547u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC54Au, 0x003E2A51u, 3u);
        }

        case 0x003E2A51u: {
            TP_STATIC_GUARD(0x07C54Au, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC54Du, 0x003E2A69u, 5u);
        }

        case 0x003E2A69u: {
            TP_STATIC_GUARD(0x07C54Du, 0xADu, 0x16u, 0x00u);
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
            TP_STATIC_EXIT(0x07u, 0xC550u, 0x003E2A81u, 5u);
        }

        case 0x003E2A81u: {
            TP_STATIC_GUARD(0x07C550u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xC551u, 0x003E2A89u, 2u);
        }

        case 0x003E2A89u: {
            TP_STATIC_GUARD(0x07C551u, 0xEDu, 0x4Fu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x004Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC554u, 0x003E2AA1u, 5u);
        }

        case 0x003E2AA1u: {
            TP_STATIC_GUARD(0x07C554u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC555u, 0x003E2AA9u, 3u);
        }

        case 0x003E2AA9u: {
            TP_STATIC_GUARD(0x07C555u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC556u, 0x003E2AB1u, 3u);
        }

        case 0x003E2AB1u: {
            TP_STATIC_GUARD(0x07C556u, 0xA2u, 0x40u);
            const uint8_t value = 0x40u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC558u, 0x003E2AC1u, 2u);
        }

        case 0x003E2AC1u: {
            TP_STATIC_GUARD(0x07C558u, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC55Bu, 0x003E2AD9u, 3u);
        }

        case 0x003E2AD9u: {
            TP_STATIC_GUARD(0x07C55Bu, 0xF0u, 0x1Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xC579u;
                if (tp_scpu_expect_next(cpu, 0x003E2BC9u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xC55Du, 0x003E2AE9u, 2u);
        }

        case 0x003E2AE9u: {
            TP_STATIC_GUARD(0x07C55Du, 0xE0u, 0x00u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x00u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC55Fu, 0x003E2AF9u, 2u);
        }

        case 0x003E2AF9u: {
            TP_STATIC_GUARD(0x07C55Fu, 0xF0u, 0x18u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xC579u;
                if (tp_scpu_expect_next(cpu, 0x003E2BC9u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xC561u, 0x003E2B09u, 2u);
        }

        case 0x003E2B09u: {
            TP_STATIC_GUARD(0x07C561u, 0x8Du, 0x04u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4204u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC564u, 0x003E2B21u, 5u);
        }

        case 0x003E2B21u: {
            TP_STATIC_GUARD(0x07C564u, 0x8Eu, 0x06u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4206u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC567u, 0x003E2B39u, 4u);
        }

        case 0x003E2B39u: {
            TP_STATIC_GUARD(0x07C567u, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC568u, 0x003E2B41u, 2u);
        }

        case 0x003E2B41u: {
            TP_STATIC_GUARD(0x07C568u, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC569u, 0x003E2B49u, 2u);
        }

        case 0x003E2B49u: {
            TP_STATIC_GUARD(0x07C569u, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC56Au, 0x003E2B51u, 2u);
        }

        case 0x003E2B51u: {
            TP_STATIC_GUARD(0x07C56Au, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC56Bu, 0x003E2B59u, 2u);
        }

        case 0x003E2B59u: {
            TP_STATIC_GUARD(0x07C56Bu, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC56Cu, 0x003E2B61u, 2u);
        }

        case 0x003E2B61u: {
            TP_STATIC_GUARD(0x07C56Cu, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC56Du, 0x003E2B69u, 2u);
        }

        case 0x003E2B69u: {
            TP_STATIC_GUARD(0x07C56Du, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC56Eu, 0x003E2B71u, 2u);
        }

        case 0x003E2B71u: {
            TP_STATIC_GUARD(0x07C56Eu, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC56Fu, 0x003E2B79u, 2u);
        }

        case 0x003E2B79u: {
            TP_STATIC_GUARD(0x07C56Fu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0xC571u, 0x003E2B88u, 3u);
        }

        case 0x003E2B88u: {
            TP_STATIC_GUARD(0x07C571u, 0xADu, 0x14u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4214u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC574u, 0x003E2BA0u, 5u);
        }

        case 0x003E2BA0u: {
            TP_STATIC_GUARD(0x07C574u, 0xAEu, 0x16u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4216u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC577u, 0x003E2BB8u, 5u);
        }

        case 0x003E2BB8u: {
            TP_STATIC_GUARD(0x07C577u, 0x80u, 0x06u);
            TP_STATIC_EXIT(0x07u, 0xC57Fu, 0x003E2BF8u, 3u);
        }

        case 0x003E2BC9u: {
            TP_STATIC_GUARD(0x07C579u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0xC57Bu, 0x003E2BD8u, 3u);
        }

        case 0x003E2BD8u: {
            TP_STATIC_GUARD(0x07C57Bu, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC57Eu, 0x003E2BF0u, 3u);
        }

        case 0x003E2BF0u: {
            TP_STATIC_GUARD(0x07C57Eu, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC57Fu, 0x003E2BF8u, 2u);
        }

        case 0x003E2BF8u: {
            TP_STATIC_GUARD(0x07C57Fu, 0x8Au);
            cpu->a = cpu->x;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC580u, 0x003E2C00u, 2u);
        }

        case 0x003E2C00u: {
            TP_STATIC_GUARD(0x07C580u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xC581u, 0x003E2C08u, 2u);
        }

        case 0x003E2C08u: {
            TP_STATIC_GUARD(0x07C581u, 0xEDu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC584u, 0x003E2C20u, 5u);
        }

        case 0x003E2C20u: {
            TP_STATIC_GUARD(0x07C584u, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC587u, 0x003E2C38u, 5u);
        }

        case 0x003E2C38u: {
            TP_STATIC_GUARD(0x07C587u, 0x10u, 0x07u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xC590u;
                if (tp_scpu_expect_next(cpu, 0x003E2C80u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xC589u, 0x003E2C48u, 2u);
        }

        case 0x003E2C48u: {
            TP_STATIC_GUARD(0x07C589u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xC58Au, 0x003E2C50u, 2u);
        }

        case 0x003E2C50u: {
            TP_STATIC_GUARD(0x07C58Au, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC58Du, 0x003E2C68u, 3u);
        }

        case 0x003E2C68u: {
            TP_STATIC_GUARD(0x07C58Du, 0xEDu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC590u, 0x003E2C80u, 5u);
        }

        case 0x003E2C80u: {
            TP_STATIC_GUARD(0x07C590u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC593u, 0x003E2C98u, 5u);
        }

        case 0x003E2C98u: {
            TP_STATIC_GUARD(0x07C593u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xC595u, 0x003E2CA9u, 3u);
        }

        case 0x003E2CA9u: {
            TP_STATIC_GUARD(0x07C595u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x07u, 0xC597u, 0x003E2CB9u, 3u);
        }

        case 0x003E2CB9u: {
            TP_STATIC_GUARD(0x07C597u, 0xA0u, 0x58u);
            const uint8_t value = 0x58u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC599u, 0x003E2CC9u, 2u);
        }

        case 0x003E2CC9u: {
            TP_STATIC_GUARD(0x07C599u, 0xB7u, 0x19u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x19u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xC59Bu;
            if (tp_scpu_expect_next(cpu, 0x003E2CD9u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003E2CD9u: {
            TP_STATIC_GUARD(0x07C59Bu, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC59Eu, 0x003E2CF1u, 3u);
        }

        case 0x003E2CF1u: {
            TP_STATIC_GUARD(0x07C59Eu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC5A1u, 0x003E2D09u, 5u);
        }

        case 0x003E2D09u: {
            TP_STATIC_GUARD(0x07C5A1u, 0xADu, 0x16u, 0x00u);
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
            TP_STATIC_EXIT(0x07u, 0xC5A4u, 0x003E2D21u, 5u);
        }

        case 0x003E2D21u: {
            TP_STATIC_GUARD(0x07C5A4u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xC5A5u, 0x003E2D29u, 2u);
        }

        case 0x003E2D29u: {
            TP_STATIC_GUARD(0x07C5A5u, 0xEDu, 0x4Fu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x004Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC5A8u, 0x003E2D41u, 5u);
        }

        case 0x003E2D41u: {
            TP_STATIC_GUARD(0x07C5A8u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5A9u, 0x003E2D49u, 3u);
        }

        case 0x003E2D49u: {
            TP_STATIC_GUARD(0x07C5A9u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5AAu, 0x003E2D51u, 3u);
        }

        case 0x003E2D51u: {
            TP_STATIC_GUARD(0x07C5AAu, 0xA2u, 0x40u);
            const uint8_t value = 0x40u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5ACu, 0x003E2D61u, 2u);
        }

        case 0x003E2D61u: {
            TP_STATIC_GUARD(0x07C5ACu, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5AFu, 0x003E2D79u, 3u);
        }

        case 0x003E2D79u: {
            TP_STATIC_GUARD(0x07C5AFu, 0xF0u, 0x1Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xC5CDu;
                if (tp_scpu_expect_next(cpu, 0x003E2E69u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xC5B1u, 0x003E2D89u, 2u);
        }

        case 0x003E2D89u: {
            TP_STATIC_GUARD(0x07C5B1u, 0xE0u, 0x00u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x00u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5B3u, 0x003E2D99u, 2u);
        }

        case 0x003E2D99u: {
            TP_STATIC_GUARD(0x07C5B3u, 0xF0u, 0x18u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xC5CDu;
                if (tp_scpu_expect_next(cpu, 0x003E2E69u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xC5B5u, 0x003E2DA9u, 2u);
        }

        case 0x003E2DA9u: {
            TP_STATIC_GUARD(0x07C5B5u, 0x8Du, 0x04u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4204u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC5B8u, 0x003E2DC1u, 5u);
        }

        case 0x003E2DC1u: {
            TP_STATIC_GUARD(0x07C5B8u, 0x8Eu, 0x06u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4206u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC5BBu, 0x003E2DD9u, 4u);
        }

        case 0x003E2DD9u: {
            TP_STATIC_GUARD(0x07C5BBu, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC5BCu, 0x003E2DE1u, 2u);
        }

        case 0x003E2DE1u: {
            TP_STATIC_GUARD(0x07C5BCu, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC5BDu, 0x003E2DE9u, 2u);
        }

        case 0x003E2DE9u: {
            TP_STATIC_GUARD(0x07C5BDu, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC5BEu, 0x003E2DF1u, 2u);
        }

        case 0x003E2DF1u: {
            TP_STATIC_GUARD(0x07C5BEu, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC5BFu, 0x003E2DF9u, 2u);
        }

        case 0x003E2DF9u: {
            TP_STATIC_GUARD(0x07C5BFu, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC5C0u, 0x003E2E01u, 2u);
        }

        case 0x003E2E01u: {
            TP_STATIC_GUARD(0x07C5C0u, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC5C1u, 0x003E2E09u, 2u);
        }

        case 0x003E2E09u: {
            TP_STATIC_GUARD(0x07C5C1u, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC5C2u, 0x003E2E11u, 2u);
        }

        case 0x003E2E11u: {
            TP_STATIC_GUARD(0x07C5C2u, 0xEAu);
            TP_STATIC_EXIT(0x07u, 0xC5C3u, 0x003E2E19u, 2u);
        }

        case 0x003E2E19u: {
            TP_STATIC_GUARD(0x07C5C3u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0xC5C5u, 0x003E2E28u, 3u);
        }

        case 0x003E2E28u: {
            TP_STATIC_GUARD(0x07C5C5u, 0xADu, 0x14u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4214u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5C8u, 0x003E2E40u, 5u);
        }

        case 0x003E2E40u: {
            TP_STATIC_GUARD(0x07C5C8u, 0xAEu, 0x16u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4216u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5CBu, 0x003E2E58u, 5u);
        }

        case 0x003E2E58u: {
            TP_STATIC_GUARD(0x07C5CBu, 0x80u, 0x06u);
            TP_STATIC_EXIT(0x07u, 0xC5D3u, 0x003E2E98u, 3u);
        }

        case 0x003E2E69u: {
            TP_STATIC_GUARD(0x07C5CDu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0xC5CFu, 0x003E2E78u, 3u);
        }

        case 0x003E2E78u: {
            TP_STATIC_GUARD(0x07C5CFu, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5D2u, 0x003E2E90u, 3u);
        }

        case 0x003E2E90u: {
            TP_STATIC_GUARD(0x07C5D2u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5D3u, 0x003E2E98u, 2u);
        }

        case 0x003E2E98u: {
            TP_STATIC_GUARD(0x07C5D3u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xC5D4u, 0x003E2EA0u, 2u);
        }

        case 0x003E2EA0u: {
            TP_STATIC_GUARD(0x07C5D4u, 0xEDu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC5D7u, 0x003E2EB8u, 5u);
        }

        case 0x003E2EB8u: {
            TP_STATIC_GUARD(0x07C5D7u, 0x8Du, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC5DAu, 0x003E2ED0u, 5u);
        }

        case 0x003E2ED0u: {
            TP_STATIC_GUARD(0x07C5DAu, 0x10u, 0x07u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xC5E3u;
                if (tp_scpu_expect_next(cpu, 0x003E2F18u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xC5DCu, 0x003E2EE0u, 2u);
        }

        case 0x003E2EE0u: {
            TP_STATIC_GUARD(0x07C5DCu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xC5DDu, 0x003E2EE8u, 2u);
        }

        case 0x003E2EE8u: {
            TP_STATIC_GUARD(0x07C5DDu, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5E0u, 0x003E2F00u, 3u);
        }

        case 0x003E2F00u: {
            TP_STATIC_GUARD(0x07C5E0u, 0xEDu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xC5E3u, 0x003E2F18u, 5u);
        }

        case 0x003E2F18u: {
            TP_STATIC_GUARD(0x07C5E3u, 0xCDu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Eu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5E6u, 0x003E2F30u, 5u);
        }

        case 0x003E2F30u: {
            TP_STATIC_GUARD(0x07C5E6u, 0xB0u, 0x11u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xC5F9u;
                if (tp_scpu_expect_next(cpu, 0x003E2FC8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xC5E8u, 0x003E2F40u, 2u);
        }

        case 0x003E2F40u: {
            TP_STATIC_GUARD(0x07C5E8u, 0xADu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5EBu, 0x003E2F58u, 5u);
        }

        case 0x003E2F58u: {
            TP_STATIC_GUARD(0x07C5EBu, 0xF0u, 0x07u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xC5F4u;
                if (tp_scpu_expect_next(cpu, 0x003E2FA0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xC5EDu, 0x003E2F68u, 2u);
        }

        case 0x003E2F68u: {
            TP_STATIC_GUARD(0x07C5EDu, 0x30u, 0x05u);
            if ((cpu->p & TP_P_N) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xC5F4u;
                if (tp_scpu_expect_next(cpu, 0x003E2FA0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xC5EFu, 0x003E2F78u, 2u);
        }

        case 0x003E2F78u: {
            TP_STATIC_GUARD(0x07C5EFu, 0xA0u, 0x03u, 0x00u);
            const uint16_t value = 0x0003u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5F2u, 0x003E2F90u, 3u);
        }

        case 0x003E2F90u: {
            TP_STATIC_GUARD(0x07C5F2u, 0x80u, 0x03u);
            TP_STATIC_EXIT(0x07u, 0xC5F7u, 0x003E2FB8u, 3u);
        }

        case 0x003E2FA0u: {
            TP_STATIC_GUARD(0x07C5F4u, 0xA0u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5F7u, 0x003E2FB8u, 3u);
        }

        case 0x003E2FB8u: {
            TP_STATIC_GUARD(0x07C5F7u, 0x80u, 0x14u);
            TP_STATIC_EXIT(0x07u, 0xC60Du, 0x003E3068u, 3u);
        }

        case 0x003E2FC8u: {
            TP_STATIC_GUARD(0x07C5F9u, 0xADu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC5FCu, 0x003E2FE0u, 5u);
        }

        case 0x003E2FE0u: {
            TP_STATIC_GUARD(0x07C5FCu, 0xF0u, 0x23u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xC621u;
                if (tp_scpu_expect_next(cpu, 0x003E3108u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xC5FEu, 0x003E2FF0u, 2u);
        }

        case 0x003E2FF0u: {
            TP_STATIC_GUARD(0x07C5FEu, 0xADu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xC601u, 0x003E3008u, 5u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
