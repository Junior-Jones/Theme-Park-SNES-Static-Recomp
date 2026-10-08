/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_00078B(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x003C5800u: {
            TP_STATIC_GUARD(0x078B00u, 0xADu, 0x08u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0808u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B03u, 0x003C5818u, 5u);
        }

        case 0x003C5818u: {
            TP_STATIC_GUARD(0x078B03u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8B06u, 0x003C5830u, 5u);
        }

        case 0x003C5830u: {
            TP_STATIC_GUARD(0x078B06u, 0x9Cu, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8B09u, 0x003C5848u, 5u);
        }

        case 0x003C5848u: {
            TP_STATIC_GUARD(0x078B09u, 0x22u, 0x0Du, 0xB4u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Cu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xB40Du, 0x0005A068u, 8u);
        }

        case 0x003C5868u: {
            TP_STATIC_GUARD(0x078B0Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x8B0Fu, 0x003C5878u, 3u);
        }

        case 0x003C5878u: {
            TP_STATIC_GUARD(0x078B0Fu, 0xADu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B12u, 0x003C5890u, 5u);
        }

        case 0x003C5890u: {
            TP_STATIC_GUARD(0x078B12u, 0xD0u, 0x23u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8B37u;
                if (tp_scpu_expect_next(cpu, 0x003C59B8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8B14u, 0x003C58A0u, 2u);
        }

        case 0x003C58A0u: {
            TP_STATIC_GUARD(0x078B14u, 0xADu, 0x08u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0808u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B17u, 0x003C58B8u, 5u);
        }

        case 0x003C58B8u: {
            TP_STATIC_GUARD(0x078B17u, 0x8Du, 0x76u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0776u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8B1Au, 0x003C58D0u, 5u);
        }

        case 0x003C58D0u: {
            TP_STATIC_GUARD(0x078B1Au, 0x22u, 0x36u, 0x95u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x1Du) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9536u, 0x003CA9B0u, 8u);
        }

        case 0x003C58F0u: {
            TP_STATIC_GUARD(0x078B1Eu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x8B20u, 0x003C5900u, 3u);
        }

        case 0x003C5900u: {
            TP_STATIC_GUARD(0x078B20u, 0xA0u, 0x02u, 0x00u);
            const uint16_t value = 0x0002u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B23u, 0x003C5918u, 3u);
        }

        case 0x003C5918u: {
            TP_STATIC_GUARD(0x078B23u, 0xB7u, 0x43u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x43u);
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
            cpu->pc = 0x8B25u;
            if (tp_scpu_expect_next(cpu, 0x003C5928u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003C5928u: {
            TP_STATIC_GUARD(0x078B25u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B28u, 0x003C5940u, 3u);
        }

        case 0x003C5940u: {
            TP_STATIC_GUARD(0x078B28u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B29u, 0x003C5948u, 2u);
        }

        case 0x003C5948u: {
            TP_STATIC_GUARD(0x078B29u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B2Au, 0x003C5950u, 2u);
        }

        case 0x003C5950u: {
            TP_STATIC_GUARD(0x078B2Au, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B2Bu, 0x003C5958u, 3u);
        }

        case 0x003C5958u: {
            TP_STATIC_GUARD(0x078B2Bu, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B2Cu, 0x003C5960u, 3u);
        }

        case 0x003C5960u: {
            TP_STATIC_GUARD(0x078B2Cu, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B2Du, 0x003C5968u, 2u);
        }

        case 0x003C5968u: {
            TP_STATIC_GUARD(0x078B2Du, 0xBBu);
            cpu->x = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B2Eu, 0x003C5970u, 2u);
        }

        case 0x003C5970u: {
            TP_STATIC_GUARD(0x078B2Eu, 0xBFu, 0xB7u, 0x88u, 0x01u);
            const uint32_t address = (0x0188B7u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B32u, 0x003C5990u, 6u);
        }

        case 0x003C5990u: {
            TP_STATIC_GUARD(0x078B32u, 0x29u, 0x02u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0002u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B35u, 0x003C59A8u, 3u);
        }

        case 0x003C59A8u: {
            TP_STATIC_GUARD(0x078B35u, 0xF0u, 0x1Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8B56u;
                if (tp_scpu_expect_next(cpu, 0x003C5AB0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8B37u, 0x003C59B8u, 2u);
        }

        case 0x003C59B8u: {
            TP_STATIC_GUARD(0x078B37u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x8B39u, 0x003C59CBu, 3u);
        }

        case 0x003C59CBu: {
            TP_STATIC_GUARD(0x078B39u, 0xAEu, 0xEDu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18EDu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B3Cu, 0x003C59E3u, 4u);
        }

        case 0x003C59E3u: {
            TP_STATIC_GUARD(0x078B3Cu, 0xE0u, 0x04u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x04u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B3Eu, 0x003C59F3u, 2u);
        }

        case 0x003C59F3u: {
            TP_STATIC_GUARD(0x078B3Eu, 0x90u, 0x0Du);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8B4Du;
                if (tp_scpu_expect_next(cpu, 0x003C5A6Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8B40u, 0x003C5A03u, 2u);
        }

        case 0x003C5A03u: {
            TP_STATIC_GUARD(0x078B40u, 0x8Au);
            const uint8_t value = (uint8_t)(cpu->x & 0x00FFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B41u, 0x003C5A0Bu, 2u);
        }

        case 0x003C5A0Bu: {
            TP_STATIC_GUARD(0x078B41u, 0x29u, 0x03u);
            const uint8_t value = (uint8_t)(cpu->a & 0x03u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B43u, 0x003C5A1Bu, 2u);
        }

        case 0x003C5A1Bu: {
            TP_STATIC_GUARD(0x078B43u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x07u, 0x8B44u, 0x003C5A23u, 2u);
        }

        case 0x003C5A23u: {
            TP_STATIC_GUARD(0x078B44u, 0x69u, 0x36u);
            if (tp_scpu_adc(cpu, 0x36u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8B46u, 0x003C5A33u, 2u);
        }

        case 0x003C5A33u: {
            TP_STATIC_GUARD(0x078B46u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x8B48u, 0x003C5A40u, 3u);
        }

        case 0x003C5A40u: {
            TP_STATIC_GUARD(0x078B48u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B4Bu, 0x003C5A58u, 3u);
        }

        case 0x003C5A58u: {
            TP_STATIC_GUARD(0x078B4Bu, 0x80u, 0x05u);
            TP_STATIC_EXIT(0x07u, 0x8B52u, 0x003C5A90u, 3u);
        }

        case 0x003C5A6Bu: {
            TP_STATIC_GUARD(0x078B4Du, 0xADu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B50u, 0x003C5A83u, 4u);
        }

        case 0x003C5A83u: {
            TP_STATIC_GUARD(0x078B50u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8B56u;
                if (tp_scpu_expect_next(cpu, 0x003C5AB3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8B52u, 0x003C5A93u, 2u);
        }

        case 0x003C5A90u: {
            TP_STATIC_GUARD(0x078B52u, 0x22u, 0xC6u, 0x8Fu, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x55u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8FC6u, 0x003C7E30u, 8u);
        }

        case 0x003C5A93u: {
            TP_STATIC_GUARD(0x078B52u, 0x22u, 0xC6u, 0x8Fu, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x55u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8FC6u, 0x003C7E33u, 8u);
        }

        case 0x003C5AB0u: {
            TP_STATIC_GUARD(0x078B56u, 0x82u, 0x66u, 0x04u);
            TP_STATIC_EXIT(0x07u, 0x8FBFu, 0x003C7DF8u, 4u);
        }

        case 0x003C5AB3u: {
            TP_STATIC_GUARD(0x078B56u, 0x82u, 0x66u, 0x04u);
            TP_STATIC_EXIT(0x07u, 0x8FBFu, 0x003C7DFBu, 4u);
        }

        case 0x003C5AC8u: {
            TP_STATIC_GUARD(0x078B59u, 0xC9u, 0x01u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0001u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B5Cu, 0x003C5AE0u, 3u);
        }

        case 0x003C5AE0u: {
            TP_STATIC_GUARD(0x078B5Cu, 0xD0u, 0x2Du);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8B8Bu;
                if (tp_scpu_expect_next(cpu, 0x003C5C58u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8B5Eu, 0x003C5AF0u, 2u);
        }

        case 0x003C5AF0u: {
            TP_STATIC_GUARD(0x078B5Eu, 0xACu, 0x18u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0818u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B61u, 0x003C5B08u, 5u);
        }

        case 0x003C5B08u: {
            TP_STATIC_GUARD(0x078B61u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B62u, 0x003C5B10u, 2u);
        }

        case 0x003C5B10u: {
            TP_STATIC_GUARD(0x078B62u, 0xA9u, 0x18u, 0x00u);
            const uint16_t value = 0x0018u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B65u, 0x003C5B28u, 3u);
        }

        case 0x003C5B28u: {
            TP_STATIC_GUARD(0x078B65u, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x68u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x003C5B48u: {
            TP_STATIC_GUARD(0x078B69u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B6Au, 0x003C5B50u, 2u);
        }

        case 0x003C5B50u: {
            TP_STATIC_GUARD(0x078B6Au, 0xB9u, 0xE8u, 0x10u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x10E8u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B6Du, 0x003C5B68u, 6u);
        }

        case 0x003C5B68u: {
            TP_STATIC_GUARD(0x078B6Du, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8B70u, 0x003C5B80u, 5u);
        }

        case 0x003C5B80u: {
            TP_STATIC_GUARD(0x078B70u, 0xADu, 0x08u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0808u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B73u, 0x003C5B98u, 5u);
        }

        case 0x003C5B98u: {
            TP_STATIC_GUARD(0x078B73u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8B76u, 0x003C5BB0u, 5u);
        }

        case 0x003C5BB0u: {
            TP_STATIC_GUARD(0x078B76u, 0x9Cu, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8B79u, 0x003C5BC8u, 5u);
        }

        case 0x003C5BC8u: {
            TP_STATIC_GUARD(0x078B79u, 0x22u, 0x3Eu, 0xB2u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x7Cu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xB23Eu, 0x000591F0u, 8u);
        }

        case 0x003C5BEBu: {
            TP_STATIC_GUARD(0x078B7Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x8B7Fu, 0x003C5BF8u, 3u);
        }

        case 0x003C5BF8u: {
            TP_STATIC_GUARD(0x078B7Fu, 0xADu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B82u, 0x003C5C10u, 5u);
        }

        case 0x003C5C10u: {
            TP_STATIC_GUARD(0x078B82u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8B88u;
                if (tp_scpu_expect_next(cpu, 0x003C5C40u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8B84u, 0x003C5C20u, 2u);
        }

        case 0x003C5C20u: {
            TP_STATIC_GUARD(0x078B84u, 0x22u, 0xC6u, 0x8Fu, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x87u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8FC6u, 0x003C7E30u, 8u);
        }

        case 0x003C5C40u: {
            TP_STATIC_GUARD(0x078B88u, 0x82u, 0x34u, 0x04u);
            TP_STATIC_EXIT(0x07u, 0x8FBFu, 0x003C7DF8u, 4u);
        }

        case 0x003C5C58u: {
            TP_STATIC_GUARD(0x078B8Bu, 0xC9u, 0x03u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0003u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B8Eu, 0x003C5C70u, 3u);
        }

        case 0x003C5C70u: {
            TP_STATIC_GUARD(0x078B8Eu, 0xD0u, 0x21u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8BB1u;
                if (tp_scpu_expect_next(cpu, 0x003C5D88u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8B90u, 0x003C5C80u, 2u);
        }

        case 0x003C5C80u: {
            TP_STATIC_GUARD(0x078B90u, 0xA9u, 0x79u, 0x00u);
            const uint16_t value = 0x0079u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B93u, 0x003C5C98u, 3u);
        }

        case 0x003C5C98u: {
            TP_STATIC_GUARD(0x078B93u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8B96u, 0x003C5CB0u, 5u);
        }

        case 0x003C5CB0u: {
            TP_STATIC_GUARD(0x078B96u, 0xADu, 0x08u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0808u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8B99u, 0x003C5CC8u, 5u);
        }

        case 0x003C5CC8u: {
            TP_STATIC_GUARD(0x078B99u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8B9Cu, 0x003C5CE0u, 5u);
        }

        case 0x003C5CE0u: {
            TP_STATIC_GUARD(0x078B9Cu, 0x9Cu, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8B9Fu, 0x003C5CF8u, 5u);
        }

        case 0x003C5CF8u: {
            TP_STATIC_GUARD(0x078B9Fu, 0x22u, 0x53u, 0xBCu, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA2u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xBC53u, 0x0005E298u, 8u);
        }

        case 0x003C5D19u: {
            TP_STATIC_GUARD(0x078BA3u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x8BA5u, 0x003C5D28u, 3u);
        }

        case 0x003C5D28u: {
            TP_STATIC_GUARD(0x078BA5u, 0xADu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8BA8u, 0x003C5D40u, 5u);
        }

        case 0x003C5D40u: {
            TP_STATIC_GUARD(0x078BA8u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8BAEu;
                if (tp_scpu_expect_next(cpu, 0x003C5D70u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8BAAu, 0x003C5D50u, 2u);
        }

        case 0x003C5D50u: {
            TP_STATIC_GUARD(0x078BAAu, 0x22u, 0xC6u, 0x8Fu, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xADu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8FC6u, 0x003C7E30u, 8u);
        }

        case 0x003C5D70u: {
            TP_STATIC_GUARD(0x078BAEu, 0x82u, 0x0Eu, 0x04u);
            TP_STATIC_EXIT(0x07u, 0x8FBFu, 0x003C7DF8u, 4u);
        }

        case 0x003C5D88u: {
            TP_STATIC_GUARD(0x078BB1u, 0xC9u, 0x04u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0004u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8BB4u, 0x003C5DA0u, 3u);
        }

        case 0x003C5DA0u: {
            TP_STATIC_GUARD(0x078BB4u, 0xD0u, 0x1Bu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8BD1u;
                if (tp_scpu_expect_next(cpu, 0x003C5E88u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8BB6u, 0x003C5DB0u, 2u);
        }

        case 0x003C5DB0u: {
            TP_STATIC_GUARD(0x078BB6u, 0xADu, 0x08u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0808u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8BB9u, 0x003C5DC8u, 5u);
        }

        case 0x003C5DC8u: {
            TP_STATIC_GUARD(0x078BB9u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8BBCu, 0x003C5DE0u, 5u);
        }

        case 0x003C5DE0u: {
            TP_STATIC_GUARD(0x078BBCu, 0x9Cu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8BBFu, 0x003C5DF8u, 5u);
        }

        case 0x003C5DF8u: {
            TP_STATIC_GUARD(0x078BBFu, 0x22u, 0xE3u, 0x9Au, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC2u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9AE3u, 0x003CD718u, 8u);
        }

        case 0x003C5E19u: {
            TP_STATIC_GUARD(0x078BC3u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x8BC5u, 0x003C5E28u, 3u);
        }

        case 0x003C5E28u: {
            TP_STATIC_GUARD(0x078BC5u, 0xADu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8BC8u, 0x003C5E40u, 5u);
        }

        case 0x003C5E40u: {
            TP_STATIC_GUARD(0x078BC8u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8BCEu;
                if (tp_scpu_expect_next(cpu, 0x003C5E70u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8BCAu, 0x003C5E50u, 2u);
        }

        case 0x003C5E50u: {
            TP_STATIC_GUARD(0x078BCAu, 0x22u, 0xC6u, 0x8Fu, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCDu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8FC6u, 0x003C7E30u, 8u);
        }

        case 0x003C5E70u: {
            TP_STATIC_GUARD(0x078BCEu, 0x82u, 0xEEu, 0x03u);
            TP_STATIC_EXIT(0x07u, 0x8FBFu, 0x003C7DF8u, 4u);
        }

        case 0x003C5E88u: {
            TP_STATIC_GUARD(0x078BD1u, 0xC9u, 0x10u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0010u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8BD4u, 0x003C5EA0u, 3u);
        }

        case 0x003C5EA0u: {
            TP_STATIC_GUARD(0x078BD4u, 0xD0u, 0x1Bu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8BF1u;
                if (tp_scpu_expect_next(cpu, 0x003C5F88u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8BD6u, 0x003C5EB0u, 2u);
        }

        case 0x003C5EB0u: {
            TP_STATIC_GUARD(0x078BD6u, 0xADu, 0x08u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0808u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8BD9u, 0x003C5EC8u, 5u);
        }

        case 0x003C5EC8u: {
            TP_STATIC_GUARD(0x078BD9u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8BDCu, 0x003C5EE0u, 5u);
        }

        case 0x003C5EE0u: {
            TP_STATIC_GUARD(0x078BDCu, 0x9Cu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8BDFu, 0x003C5EF8u, 5u);
        }

        case 0x003C5EF8u: {
            TP_STATIC_GUARD(0x078BDFu, 0x22u, 0x8Eu, 0x97u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE2u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x978Eu, 0x003CBC70u, 8u);
        }

        case 0x003C5F19u: {
            TP_STATIC_GUARD(0x078BE3u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x8BE5u, 0x003C5F28u, 3u);
        }

        case 0x003C5F28u: {
            TP_STATIC_GUARD(0x078BE5u, 0xADu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8BE8u, 0x003C5F40u, 5u);
        }

        case 0x003C5F40u: {
            TP_STATIC_GUARD(0x078BE8u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8BEEu;
                if (tp_scpu_expect_next(cpu, 0x003C5F70u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8BEAu, 0x003C5F50u, 2u);
        }

        case 0x003C5F50u: {
            TP_STATIC_GUARD(0x078BEAu, 0x22u, 0xC6u, 0x8Fu, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEDu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8FC6u, 0x003C7E30u, 8u);
        }

        case 0x003C5F70u: {
            TP_STATIC_GUARD(0x078BEEu, 0x82u, 0xCEu, 0x03u);
            TP_STATIC_EXIT(0x07u, 0x8FBFu, 0x003C7DF8u, 4u);
        }

        case 0x003C5F88u: {
            TP_STATIC_GUARD(0x078BF1u, 0xC9u, 0x0Cu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Cu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8BF4u, 0x003C5FA0u, 3u);
        }

        case 0x003C5FA0u: {
            TP_STATIC_GUARD(0x078BF4u, 0xD0u, 0x24u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8C1Au;
                if (tp_scpu_expect_next(cpu, 0x003C60D0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8BF6u, 0x003C5FB0u, 2u);
        }

        case 0x003C5FB0u: {
            TP_STATIC_GUARD(0x078BF6u, 0xADu, 0x08u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0808u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8BF9u, 0x003C5FC8u, 5u);
        }

        case 0x003C5FC8u: {
            TP_STATIC_GUARD(0x078BF9u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8BFCu, 0x003C5FE0u, 5u);
        }

        case 0x003C5FE0u: {
            TP_STATIC_GUARD(0x078BFCu, 0xA9u, 0xB8u, 0x00u);
            const uint16_t value = 0x00B8u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8BFFu, 0x003C5FF8u, 3u);
        }

        case 0x003C5FF8u: {
            TP_STATIC_GUARD(0x078BFFu, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8C02u, 0x003C6010u, 5u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
