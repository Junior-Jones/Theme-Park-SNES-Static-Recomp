/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0006B5(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x0035A80Bu: {
            TP_STATIC_GUARD(0x06B501u, 0x82u, 0x03u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xB507u, 0x0035A83Bu, 4u);
        }

        case 0x0035A823u: {
            TP_STATIC_GUARD(0x06B504u, 0x82u, 0x35u, 0x03u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E3u, 4u);
        }

        case 0x0035A83Bu: {
            TP_STATIC_GUARD(0x06B507u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB509u, 0x0035A84Bu, 3u);
        }

        case 0x0035A84Bu: {
            TP_STATIC_GUARD(0x06B509u, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB50Cu, 0x0035A863u, 4u);
        }

        case 0x0035A863u: {
            TP_STATIC_GUARD(0x06B50Cu, 0x29u, 0x04u);
            const uint8_t value = (uint8_t)(cpu->a & 0x04u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB50Eu, 0x0035A873u, 2u);
        }

        case 0x0035A873u: {
            TP_STATIC_GUARD(0x06B50Eu, 0xF0u, 0x0Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB51Fu;
                if (tp_scpu_expect_next(cpu, 0x0035A8FBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB510u, 0x0035A883u, 2u);
        }

        case 0x0035A883u: {
            TP_STATIC_GUARD(0x06B510u, 0xA9u, 0x07u);
            const uint8_t value = 0x07u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB512u, 0x0035A893u, 2u);
        }

        case 0x0035A893u: {
            TP_STATIC_GUARD(0x06B512u, 0x22u, 0x0Au, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x15u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Au, 0x00276853u, 8u);
        }

        case 0x0035A8B3u: {
            TP_STATIC_GUARD(0x06B516u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB518u, 0x0035A8C3u, 3u);
        }

        case 0x0035A8C3u: {
            TP_STATIC_GUARD(0x06B518u, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB51Bu, 0x0035A8DBu, 4u);
        }

        case 0x0035A8DBu: {
            TP_STATIC_GUARD(0x06B51Bu, 0x29u, 0x7Bu);
            const uint8_t value = (uint8_t)(cpu->a & 0x7Bu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB51Du, 0x0035A8EBu, 2u);
        }

        case 0x0035A8EBu: {
            TP_STATIC_GUARD(0x06B51Du, 0x80u, 0x0Du);
            TP_STATIC_EXIT(0x06u, 0xB52Cu, 0x0035A963u, 3u);
        }

        case 0x0035A8FBu: {
            TP_STATIC_GUARD(0x06B51Fu, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB521u, 0x0035A90Bu, 2u);
        }

        case 0x0035A90Bu: {
            TP_STATIC_GUARD(0x06B521u, 0x22u, 0x0Au, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x24u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Au, 0x00276853u, 8u);
        }

        case 0x0035A92Bu: {
            TP_STATIC_GUARD(0x06B525u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB527u, 0x0035A93Bu, 3u);
        }

        case 0x0035A93Bu: {
            TP_STATIC_GUARD(0x06B527u, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB52Au, 0x0035A953u, 4u);
        }

        case 0x0035A953u: {
            TP_STATIC_GUARD(0x06B52Au, 0x09u, 0x04u);
            const uint8_t value = (uint8_t)(cpu->a | 0x04u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB52Cu, 0x0035A963u, 2u);
        }

        case 0x0035A963u: {
            TP_STATIC_GUARD(0x06B52Cu, 0x8Du, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1F64u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xB52Fu, 0x0035A97Bu, 4u);
        }

        case 0x0035A97Bu: {
            TP_STATIC_GUARD(0x06B52Fu, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB531u, 0x0035A98Bu, 3u);
        }

        case 0x0035A98Bu: {
            TP_STATIC_GUARD(0x06B531u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x06u, 0xB533u, 0x0035A99Au, 3u);
        }

        case 0x0035A99Au: {
            TP_STATIC_GUARD(0x06B533u, 0x22u, 0xFAu, 0xB4u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x36u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xB4FAu, 0x0025A7D2u, 8u);
        }

        case 0x0035A9B8u: {
            TP_STATIC_GUARD(0x06B537u, 0x82u, 0x02u, 0x03u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E0u, 4u);
        }

        case 0x0035A9D3u: {
            TP_STATIC_GUARD(0x06B53Au, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB53Cu, 0x0035A9E3u, 3u);
        }

        case 0x0035A9E3u: {
            TP_STATIC_GUARD(0x06B53Cu, 0xC9u, 0x27u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x27u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB53Eu, 0x0035A9F3u, 2u);
        }

        case 0x0035A9F3u: {
            TP_STATIC_GUARD(0x06B53Eu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB543u;
                if (tp_scpu_expect_next(cpu, 0x0035AA1Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB540u, 0x0035AA03u, 2u);
        }

        case 0x0035AA03u: {
            TP_STATIC_GUARD(0x06B540u, 0x82u, 0x42u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xB585u, 0x0035AC2Bu, 4u);
        }

        case 0x0035AA1Bu: {
            TP_STATIC_GUARD(0x06B543u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB545u, 0x0035AA2Bu, 3u);
        }

        case 0x0035AA2Bu: {
            TP_STATIC_GUARD(0x06B545u, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB548u, 0x0035AA43u, 4u);
        }

        case 0x0035AA43u: {
            TP_STATIC_GUARD(0x06B548u, 0x29u, 0x40u);
            const uint8_t value = (uint8_t)(cpu->a & 0x40u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB54Au, 0x0035AA53u, 2u);
        }

        case 0x0035AA53u: {
            TP_STATIC_GUARD(0x06B54Au, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB54Fu;
                if (tp_scpu_expect_next(cpu, 0x0035AA7Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB54Cu, 0x0035AA63u, 2u);
        }

        case 0x0035AA63u: {
            TP_STATIC_GUARD(0x06B54Cu, 0x82u, 0x03u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xB552u, 0x0035AA93u, 4u);
        }

        case 0x0035AA7Bu: {
            TP_STATIC_GUARD(0x06B54Fu, 0x82u, 0xEAu, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E3u, 4u);
        }

        case 0x0035AA93u: {
            TP_STATIC_GUARD(0x06B552u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB554u, 0x0035AAA3u, 3u);
        }

        case 0x0035AAA3u: {
            TP_STATIC_GUARD(0x06B554u, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB557u, 0x0035AABBu, 4u);
        }

        case 0x0035AABBu: {
            TP_STATIC_GUARD(0x06B557u, 0x29u, 0x08u);
            const uint8_t value = (uint8_t)(cpu->a & 0x08u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB559u, 0x0035AACBu, 2u);
        }

        case 0x0035AACBu: {
            TP_STATIC_GUARD(0x06B559u, 0xF0u, 0x0Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB56Au;
                if (tp_scpu_expect_next(cpu, 0x0035AB53u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB55Bu, 0x0035AADBu, 2u);
        }

        case 0x0035AADBu: {
            TP_STATIC_GUARD(0x06B55Bu, 0xA9u, 0x07u);
            const uint8_t value = 0x07u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB55Du, 0x0035AAEBu, 2u);
        }

        case 0x0035AAEBu: {
            TP_STATIC_GUARD(0x06B55Du, 0x22u, 0x0Au, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x60u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Au, 0x00276853u, 8u);
        }

        case 0x0035AB0Bu: {
            TP_STATIC_GUARD(0x06B561u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB563u, 0x0035AB1Bu, 3u);
        }

        case 0x0035AB1Bu: {
            TP_STATIC_GUARD(0x06B563u, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB566u, 0x0035AB33u, 4u);
        }

        case 0x0035AB33u: {
            TP_STATIC_GUARD(0x06B566u, 0x29u, 0x77u);
            const uint8_t value = (uint8_t)(cpu->a & 0x77u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB568u, 0x0035AB43u, 2u);
        }

        case 0x0035AB43u: {
            TP_STATIC_GUARD(0x06B568u, 0x80u, 0x0Du);
            TP_STATIC_EXIT(0x06u, 0xB577u, 0x0035ABBBu, 3u);
        }

        case 0x0035AB53u: {
            TP_STATIC_GUARD(0x06B56Au, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB56Cu, 0x0035AB63u, 2u);
        }

        case 0x0035AB63u: {
            TP_STATIC_GUARD(0x06B56Cu, 0x22u, 0x0Au, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x6Fu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Au, 0x00276853u, 8u);
        }

        case 0x0035AB83u: {
            TP_STATIC_GUARD(0x06B570u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB572u, 0x0035AB93u, 3u);
        }

        case 0x0035AB93u: {
            TP_STATIC_GUARD(0x06B572u, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB575u, 0x0035ABABu, 4u);
        }

        case 0x0035ABABu: {
            TP_STATIC_GUARD(0x06B575u, 0x09u, 0x08u);
            const uint8_t value = (uint8_t)(cpu->a | 0x08u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB577u, 0x0035ABBBu, 2u);
        }

        case 0x0035ABBBu: {
            TP_STATIC_GUARD(0x06B577u, 0x8Du, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1F64u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xB57Au, 0x0035ABD3u, 4u);
        }

        case 0x0035ABD3u: {
            TP_STATIC_GUARD(0x06B57Au, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB57Cu, 0x0035ABE3u, 3u);
        }

        case 0x0035ABE3u: {
            TP_STATIC_GUARD(0x06B57Cu, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x06u, 0xB57Eu, 0x0035ABF2u, 3u);
        }

        case 0x0035ABF2u: {
            TP_STATIC_GUARD(0x06B57Eu, 0x22u, 0xFAu, 0xB4u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xB4FAu, 0x0025A7D2u, 8u);
        }

        case 0x0035AC10u: {
            TP_STATIC_GUARD(0x06B582u, 0x82u, 0xB7u, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E0u, 4u);
        }

        case 0x0035AC2Bu: {
            TP_STATIC_GUARD(0x06B585u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB587u, 0x0035AC3Bu, 3u);
        }

        case 0x0035AC3Bu: {
            TP_STATIC_GUARD(0x06B587u, 0xC9u, 0x28u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x28u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB589u, 0x0035AC4Bu, 2u);
        }

        case 0x0035AC4Bu: {
            TP_STATIC_GUARD(0x06B589u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB58Eu;
                if (tp_scpu_expect_next(cpu, 0x0035AC73u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB58Bu, 0x0035AC5Bu, 2u);
        }

        case 0x0035AC5Bu: {
            TP_STATIC_GUARD(0x06B58Bu, 0x82u, 0x42u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xB5D0u, 0x0035AE83u, 4u);
        }

        case 0x0035AC73u: {
            TP_STATIC_GUARD(0x06B58Eu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB590u, 0x0035AC83u, 3u);
        }

        case 0x0035AC83u: {
            TP_STATIC_GUARD(0x06B590u, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB593u, 0x0035AC9Bu, 4u);
        }

        case 0x0035AC9Bu: {
            TP_STATIC_GUARD(0x06B593u, 0x29u, 0x40u);
            const uint8_t value = (uint8_t)(cpu->a & 0x40u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB595u, 0x0035ACABu, 2u);
        }

        case 0x0035ACABu: {
            TP_STATIC_GUARD(0x06B595u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB59Au;
                if (tp_scpu_expect_next(cpu, 0x0035ACD3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB597u, 0x0035ACBBu, 2u);
        }

        case 0x0035ACBBu: {
            TP_STATIC_GUARD(0x06B597u, 0x82u, 0x03u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xB59Du, 0x0035ACEBu, 4u);
        }

        case 0x0035ACD3u: {
            TP_STATIC_GUARD(0x06B59Au, 0x82u, 0x9Fu, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E3u, 4u);
        }

        case 0x0035ACEBu: {
            TP_STATIC_GUARD(0x06B59Du, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB59Fu, 0x0035ACFBu, 3u);
        }

        case 0x0035ACFBu: {
            TP_STATIC_GUARD(0x06B59Fu, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5A2u, 0x0035AD13u, 4u);
        }

        case 0x0035AD13u: {
            TP_STATIC_GUARD(0x06B5A2u, 0x29u, 0x10u);
            const uint8_t value = (uint8_t)(cpu->a & 0x10u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5A4u, 0x0035AD23u, 2u);
        }

        case 0x0035AD23u: {
            TP_STATIC_GUARD(0x06B5A4u, 0xF0u, 0x0Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB5B5u;
                if (tp_scpu_expect_next(cpu, 0x0035ADABu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB5A6u, 0x0035AD33u, 2u);
        }

        case 0x0035AD33u: {
            TP_STATIC_GUARD(0x06B5A6u, 0xA9u, 0x07u);
            const uint8_t value = 0x07u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5A8u, 0x0035AD43u, 2u);
        }

        case 0x0035AD43u: {
            TP_STATIC_GUARD(0x06B5A8u, 0x22u, 0x0Au, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Au, 0x00276853u, 8u);
        }

        case 0x0035AD63u: {
            TP_STATIC_GUARD(0x06B5ACu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB5AEu, 0x0035AD73u, 3u);
        }

        case 0x0035AD73u: {
            TP_STATIC_GUARD(0x06B5AEu, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5B1u, 0x0035AD8Bu, 4u);
        }

        case 0x0035AD8Bu: {
            TP_STATIC_GUARD(0x06B5B1u, 0x29u, 0x6Fu);
            const uint8_t value = (uint8_t)(cpu->a & 0x6Fu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5B3u, 0x0035AD9Bu, 2u);
        }

        case 0x0035AD9Bu: {
            TP_STATIC_GUARD(0x06B5B3u, 0x80u, 0x0Du);
            TP_STATIC_EXIT(0x06u, 0xB5C2u, 0x0035AE13u, 3u);
        }

        case 0x0035ADABu: {
            TP_STATIC_GUARD(0x06B5B5u, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5B7u, 0x0035ADBBu, 2u);
        }

        case 0x0035ADBBu: {
            TP_STATIC_GUARD(0x06B5B7u, 0x22u, 0x0Au, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBAu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Au, 0x00276853u, 8u);
        }

        case 0x0035ADDBu: {
            TP_STATIC_GUARD(0x06B5BBu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB5BDu, 0x0035ADEBu, 3u);
        }

        case 0x0035ADEBu: {
            TP_STATIC_GUARD(0x06B5BDu, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5C0u, 0x0035AE03u, 4u);
        }

        case 0x0035AE03u: {
            TP_STATIC_GUARD(0x06B5C0u, 0x09u, 0x10u);
            const uint8_t value = (uint8_t)(cpu->a | 0x10u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5C2u, 0x0035AE13u, 2u);
        }

        case 0x0035AE13u: {
            TP_STATIC_GUARD(0x06B5C2u, 0x8Du, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1F64u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xB5C5u, 0x0035AE2Bu, 4u);
        }

        case 0x0035AE2Bu: {
            TP_STATIC_GUARD(0x06B5C5u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB5C7u, 0x0035AE3Bu, 3u);
        }

        case 0x0035AE3Bu: {
            TP_STATIC_GUARD(0x06B5C7u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x06u, 0xB5C9u, 0x0035AE4Au, 3u);
        }

        case 0x0035AE4Au: {
            TP_STATIC_GUARD(0x06B5C9u, 0x22u, 0xFAu, 0xB4u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCCu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xB4FAu, 0x0025A7D2u, 8u);
        }

        case 0x0035AE68u: {
            TP_STATIC_GUARD(0x06B5CDu, 0x82u, 0x6Cu, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E0u, 4u);
        }

        case 0x0035AE83u: {
            TP_STATIC_GUARD(0x06B5D0u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB5D2u, 0x0035AE93u, 3u);
        }

        case 0x0035AE93u: {
            TP_STATIC_GUARD(0x06B5D2u, 0xC9u, 0x29u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x29u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5D4u, 0x0035AEA3u, 2u);
        }

        case 0x0035AEA3u: {
            TP_STATIC_GUARD(0x06B5D4u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB5D9u;
                if (tp_scpu_expect_next(cpu, 0x0035AECBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB5D6u, 0x0035AEB3u, 2u);
        }

        case 0x0035AEB3u: {
            TP_STATIC_GUARD(0x06B5D6u, 0x82u, 0x42u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xB61Bu, 0x0035B0DBu, 4u);
        }

        case 0x0035AECBu: {
            TP_STATIC_GUARD(0x06B5D9u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB5DBu, 0x0035AEDBu, 3u);
        }

        case 0x0035AEDBu: {
            TP_STATIC_GUARD(0x06B5DBu, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5DEu, 0x0035AEF3u, 4u);
        }

        case 0x0035AEF3u: {
            TP_STATIC_GUARD(0x06B5DEu, 0x29u, 0x40u);
            const uint8_t value = (uint8_t)(cpu->a & 0x40u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5E0u, 0x0035AF03u, 2u);
        }

        case 0x0035AF03u: {
            TP_STATIC_GUARD(0x06B5E0u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB5E5u;
                if (tp_scpu_expect_next(cpu, 0x0035AF2Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB5E2u, 0x0035AF13u, 2u);
        }

        case 0x0035AF13u: {
            TP_STATIC_GUARD(0x06B5E2u, 0x82u, 0x03u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xB5E8u, 0x0035AF43u, 4u);
        }

        case 0x0035AF2Bu: {
            TP_STATIC_GUARD(0x06B5E5u, 0x82u, 0x54u, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E3u, 4u);
        }

        case 0x0035AF43u: {
            TP_STATIC_GUARD(0x06B5E8u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB5EAu, 0x0035AF53u, 3u);
        }

        case 0x0035AF53u: {
            TP_STATIC_GUARD(0x06B5EAu, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5EDu, 0x0035AF6Bu, 4u);
        }

        case 0x0035AF6Bu: {
            TP_STATIC_GUARD(0x06B5EDu, 0x29u, 0x20u);
            const uint8_t value = (uint8_t)(cpu->a & 0x20u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5EFu, 0x0035AF7Bu, 2u);
        }

        case 0x0035AF7Bu: {
            TP_STATIC_GUARD(0x06B5EFu, 0xF0u, 0x0Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB600u;
                if (tp_scpu_expect_next(cpu, 0x0035B003u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB5F1u, 0x0035AF8Bu, 2u);
        }

        case 0x0035AF8Bu: {
            TP_STATIC_GUARD(0x06B5F1u, 0xA9u, 0x07u);
            const uint8_t value = 0x07u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5F3u, 0x0035AF9Bu, 2u);
        }

        case 0x0035AF9Bu: {
            TP_STATIC_GUARD(0x06B5F3u, 0x22u, 0x0Au, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF6u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Au, 0x00276853u, 8u);
        }

        case 0x0035AFBBu: {
            TP_STATIC_GUARD(0x06B5F7u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB5F9u, 0x0035AFCBu, 3u);
        }

        case 0x0035AFCBu: {
            TP_STATIC_GUARD(0x06B5F9u, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5FCu, 0x0035AFE3u, 4u);
        }

        case 0x0035AFE3u: {
            TP_STATIC_GUARD(0x06B5FCu, 0x29u, 0x5Fu);
            const uint8_t value = (uint8_t)(cpu->a & 0x5Fu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB5FEu, 0x0035AFF3u, 2u);
        }

        case 0x0035AFF3u: {
            TP_STATIC_GUARD(0x06B5FEu, 0x80u, 0x0Du);
            TP_STATIC_EXIT(0x06u, 0xB60Du, 0x0035B06Bu, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
