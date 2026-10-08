/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000098(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x0004C1F9u: {
            TP_STATIC_GUARD(0x00983Fu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0x9841u, 0x0004C208u, 3u);
        }

        case 0x0004C1FBu: {
            TP_STATIC_GUARD(0x00983Fu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0x9841u, 0x0004C208u, 3u);
        }

        case 0x0004C208u: {
            TP_STATIC_GUARD(0x009841u, 0xA2u, 0x60u, 0x06u);
            const uint16_t value = 0x0660u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9844u, 0x0004C220u, 3u);
        }

        case 0x0004C220u: {
            TP_STATIC_GUARD(0x009844u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x00u, 0x9845u, 0x0004C228u, 2u);
        }

        case 0x0004C228u: {
            TP_STATIC_GUARD(0x009845u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9848u, 0x0004C240u, 3u);
        }

        case 0x0004C240u: {
            TP_STATIC_GUARD(0x009848u, 0x9Fu, 0x00u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E00u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x984Cu, 0x0004C260u, 6u);
        }

        case 0x0004C260u: {
            TP_STATIC_GUARD(0x00984Cu, 0x9Fu, 0x02u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E02u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9850u, 0x0004C280u, 6u);
        }

        case 0x0004C280u: {
            TP_STATIC_GUARD(0x009850u, 0x9Fu, 0x04u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E04u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9854u, 0x0004C2A0u, 6u);
        }

        case 0x0004C2A0u: {
            TP_STATIC_GUARD(0x009854u, 0x9Fu, 0x06u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E06u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9858u, 0x0004C2C0u, 6u);
        }

        case 0x0004C2C0u: {
            TP_STATIC_GUARD(0x009858u, 0x9Fu, 0x08u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E08u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x985Cu, 0x0004C2E0u, 6u);
        }

        case 0x0004C2E0u: {
            TP_STATIC_GUARD(0x00985Cu, 0x9Fu, 0x0Au, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E0Au + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9860u, 0x0004C300u, 6u);
        }

        case 0x0004C300u: {
            TP_STATIC_GUARD(0x009860u, 0x9Fu, 0x0Cu, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E0Cu + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9864u, 0x0004C320u, 6u);
        }

        case 0x0004C320u: {
            TP_STATIC_GUARD(0x009864u, 0x9Fu, 0x0Eu, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E0Eu + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9868u, 0x0004C340u, 6u);
        }

        case 0x0004C340u: {
            TP_STATIC_GUARD(0x009868u, 0x9Fu, 0x10u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E10u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x986Cu, 0x0004C360u, 6u);
        }

        case 0x0004C360u: {
            TP_STATIC_GUARD(0x00986Cu, 0x9Fu, 0x12u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E12u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9870u, 0x0004C380u, 6u);
        }

        case 0x0004C380u: {
            TP_STATIC_GUARD(0x009870u, 0x9Fu, 0x14u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E14u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9874u, 0x0004C3A0u, 6u);
        }

        case 0x0004C3A0u: {
            TP_STATIC_GUARD(0x009874u, 0x9Fu, 0x16u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E16u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9878u, 0x0004C3C0u, 6u);
        }

        case 0x0004C3C0u: {
            TP_STATIC_GUARD(0x009878u, 0x9Fu, 0x18u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E18u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x987Cu, 0x0004C3E0u, 6u);
        }

        case 0x0004C3E0u: {
            TP_STATIC_GUARD(0x00987Cu, 0x9Fu, 0x1Au, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E1Au + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9880u, 0x0004C400u, 6u);
        }

        case 0x0004C400u: {
            TP_STATIC_GUARD(0x009880u, 0x9Fu, 0x1Cu, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E1Cu + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9884u, 0x0004C420u, 6u);
        }

        case 0x0004C420u: {
            TP_STATIC_GUARD(0x009884u, 0x9Fu, 0x1Eu, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E1Eu + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9888u, 0x0004C440u, 6u);
        }

        case 0x0004C440u: {
            TP_STATIC_GUARD(0x009888u, 0x8Au);
            cpu->a = cpu->x;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x9889u, 0x0004C448u, 2u);
        }

        case 0x0004C448u: {
            TP_STATIC_GUARD(0x009889u, 0xE9u, 0x20u, 0x00u);
            if (tp_scpu_sbc(cpu, 0x0020u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x988Cu, 0x0004C460u, 3u);
        }

        case 0x0004C460u: {
            TP_STATIC_GUARD(0x00988Cu, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x988Du, 0x0004C468u, 2u);
        }

        case 0x0004C468u: {
            TP_STATIC_GUARD(0x00988Du, 0x10u, 0xB6u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x9845u;
                if (tp_scpu_expect_next(cpu, 0x0004C228u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x988Fu, 0x0004C478u, 2u);
        }

        case 0x0004C478u: {
            TP_STATIC_GUARD(0x00988Fu, 0x6Bu);
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
                case 0x00046168u:
                case 0x000EEA40u:
                case 0x000F0860u:
                case 0x000F4E90u:
                case 0x000F54A8u:
                case 0x000F5990u:
                case 0x000F82A8u:
                case 0x000F8E70u:
                case 0x000FA4E0u:
                case 0x000FAE90u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x0004C480u: {
            TP_STATIC_GUARD(0x009890u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x9892u, 0x0004C493u, 3u);
        }

        case 0x0004C493u: {
            TP_STATIC_GUARD(0x009892u, 0x8Eu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Eu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9895u, 0x0004C4ABu, 4u);
        }

        case 0x0004C4ABu: {
            TP_STATIC_GUARD(0x009895u, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9898u, 0x0004C4C3u, 4u);
        }

        case 0x0004C4C3u: {
            TP_STATIC_GUARD(0x009898u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x989Au, 0x0004C4D3u, 3u);
        }

        case 0x0004C4D3u: {
            TP_STATIC_GUARD(0x00989Au, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0x989Cu, 0x0004C4E1u, 3u);
        }

        case 0x0004C4E1u: {
            TP_STATIC_GUARD(0x00989Cu, 0xADu, 0x25u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0025u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x989Fu, 0x0004C4F9u, 5u);
        }

        case 0x0004C4F9u: {
            TP_STATIC_GUARD(0x00989Fu, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98A0u, 0x0004C501u, 4u);
        }

        case 0x0004C501u: {
            TP_STATIC_GUARD(0x0098A0u, 0xAEu, 0x27u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0027u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x98A3u, 0x0004C519u, 4u);
        }

        case 0x0004C519u: {
            TP_STATIC_GUARD(0x0098A3u, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98A4u, 0x0004C521u, 3u);
        }

        case 0x0004C521u: {
            TP_STATIC_GUARD(0x0098A4u, 0xADu, 0x49u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0049u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x98A7u, 0x0004C539u, 5u);
        }

        case 0x0004C539u: {
            TP_STATIC_GUARD(0x0098A7u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98A8u, 0x0004C541u, 4u);
        }

        case 0x0004C541u: {
            TP_STATIC_GUARD(0x0098A8u, 0xAEu, 0x4Bu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x004Bu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x98ABu, 0x0004C559u, 4u);
        }

        case 0x0004C559u: {
            TP_STATIC_GUARD(0x0098ABu, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98ACu, 0x0004C561u, 3u);
        }

        case 0x0004C561u: {
            TP_STATIC_GUARD(0x0098ACu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0x98AEu, 0x0004C570u, 3u);
        }

        case 0x0004C570u: {
            TP_STATIC_GUARD(0x0098AEu, 0xADu, 0x0Bu, 0x04u);
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
            TP_STATIC_EXIT(0x00u, 0x98B1u, 0x0004C588u, 5u);
        }

        case 0x0004C588u: {
            TP_STATIC_GUARD(0x0098B1u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98B2u, 0x0004C590u, 4u);
        }

        case 0x0004C590u: {
            TP_STATIC_GUARD(0x0098B2u, 0xADu, 0x0Du, 0x04u);
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
            TP_STATIC_EXIT(0x00u, 0x98B5u, 0x0004C5A8u, 5u);
        }

        case 0x0004C5A8u: {
            TP_STATIC_GUARD(0x0098B5u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98B6u, 0x0004C5B0u, 4u);
        }

        case 0x0004C5B0u: {
            TP_STATIC_GUARD(0x0098B6u, 0xADu, 0x0Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x98B9u, 0x0004C5C8u, 5u);
        }

        case 0x0004C5C8u: {
            TP_STATIC_GUARD(0x0098B9u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98BAu, 0x0004C5D0u, 4u);
        }

        case 0x0004C5D0u: {
            TP_STATIC_GUARD(0x0098BAu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x98BCu, 0x0004C5E3u, 3u);
        }

        case 0x0004C5E3u: {
            TP_STATIC_GUARD(0x0098BCu, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x98BFu, 0x0004C5FBu, 4u);
        }

        case 0x0004C5FBu: {
            TP_STATIC_GUARD(0x0098BFu, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98C0u, 0x0004C603u, 3u);
        }

        case 0x0004C603u: {
            TP_STATIC_GUARD(0x0098C0u, 0xADu, 0x01u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0401u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x98C3u, 0x0004C61Bu, 4u);
        }

        case 0x0004C61Bu: {
            TP_STATIC_GUARD(0x0098C3u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98C4u, 0x0004C623u, 3u);
        }

        case 0x0004C623u: {
            TP_STATIC_GUARD(0x0098C4u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x98C6u, 0x0004C633u, 3u);
        }

        case 0x0004C633u: {
            TP_STATIC_GUARD(0x0098C6u, 0xAEu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Eu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x98C9u, 0x0004C64Bu, 4u);
        }

        case 0x0004C64Bu: {
            TP_STATIC_GUARD(0x0098C9u, 0x8Eu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98CCu, 0x0004C663u, 4u);
        }

        case 0x0004C663u: {
            TP_STATIC_GUARD(0x0098CCu, 0xADu, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0792u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x98CFu, 0x0004C67Bu, 4u);
        }

        case 0x0004C67Bu: {
            TP_STATIC_GUARD(0x0098CFu, 0x8Du, 0x0Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Fu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98D2u, 0x0004C693u, 4u);
        }

        case 0x0004C693u: {
            TP_STATIC_GUARD(0x0098D2u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0x98D4u, 0x0004C6A0u, 3u);
        }

        case 0x0004C6A0u: {
            TP_STATIC_GUARD(0x0098D4u, 0xADu, 0x8Au, 0x07u);
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
            TP_STATIC_EXIT(0x00u, 0x98D7u, 0x0004C6B8u, 5u);
        }

        case 0x0004C6B8u: {
            TP_STATIC_GUARD(0x0098D7u, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98DAu, 0x0004C6D0u, 5u);
        }

        case 0x0004C6D0u: {
            TP_STATIC_GUARD(0x0098DAu, 0x8Du, 0x6Bu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x076Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98DDu, 0x0004C6E8u, 5u);
        }

        case 0x0004C6E8u: {
            TP_STATIC_GUARD(0x0098DDu, 0x8Du, 0xA9u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18A9u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98E0u, 0x0004C700u, 5u);
        }

        case 0x0004C700u: {
            TP_STATIC_GUARD(0x0098E0u, 0x9Cu, 0x6Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x076Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98E3u, 0x0004C718u, 5u);
        }

        case 0x0004C718u: {
            TP_STATIC_GUARD(0x0098E3u, 0xADu, 0x0Bu, 0x04u);
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
            TP_STATIC_EXIT(0x00u, 0x98E6u, 0x0004C730u, 5u);
        }

        case 0x0004C730u: {
            TP_STATIC_GUARD(0x0098E6u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x98EBu;
                if (tp_scpu_expect_next(cpu, 0x0004C758u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x98E8u, 0x0004C740u, 2u);
        }

        case 0x0004C740u: {
            TP_STATIC_GUARD(0x0098E8u, 0x82u, 0x07u, 0x03u);
            TP_STATIC_EXIT(0x00u, 0x9BF2u, 0x0004DF90u, 4u);
        }

        case 0x0004C758u: {
            TP_STATIC_GUARD(0x0098EBu, 0x10u, 0x03u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0x98F0u;
                if (tp_scpu_expect_next(cpu, 0x0004C780u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0x98EDu, 0x0004C768u, 2u);
        }

        case 0x0004C768u: {
            TP_STATIC_GUARD(0x0098EDu, 0x4Cu, 0xE0u, 0x9Au);
            TP_STATIC_EXIT(0x00u, 0x9AE0u, 0x0004D700u, 3u);
        }

        case 0x0004C780u: {
            TP_STATIC_GUARD(0x0098F0u, 0xADu, 0x0Bu, 0x04u);
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
            TP_STATIC_EXIT(0x00u, 0x98F3u, 0x0004C798u, 5u);
        }

        case 0x0004C798u: {
            TP_STATIC_GUARD(0x0098F3u, 0x20u, 0x85u, 0xC2u);
            if (tp_scpu_push8(cpu, bus, 0x98u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF5u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC285u, 0x00061428u, 6u);
        }

        case 0x0004C7B1u: {
            TP_STATIC_GUARD(0x0098F6u, 0x8Du, 0x49u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0049u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98F9u, 0x0004C7C9u, 5u);
        }

        case 0x0004C7C9u: {
            TP_STATIC_GUARD(0x0098F9u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98FCu, 0x0004C7E1u, 5u);
        }

        case 0x0004C7E1u: {
            TP_STATIC_GUARD(0x0098FCu, 0x8Eu, 0x4Bu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x004Bu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x98FFu, 0x0004C7F9u, 4u);
        }

        case 0x0004C7F9u: {
            TP_STATIC_GUARD(0x0098FFu, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x9902u, 0x0004C811u, 4u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
