/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000C8D(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00646802u: {
            TP_STATIC_GUARD(0x0C8D00u, 0x6Bu);
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
                case 0x00645F32u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x0064680Au: {
            TP_STATIC_GUARD(0x0C8D01u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8D03u, 0x0064681Bu, 3u);
        }

        case 0x0064681Bu: {
            TP_STATIC_GUARD(0x0C8D03u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x0Cu, 0x8D05u, 0x00646829u, 3u);
        }

        case 0x00646829u: {
            TP_STATIC_GUARD(0x0C8D05u, 0xA0u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D07u, 0x00646839u, 2u);
        }

        case 0x00646839u: {
            TP_STATIC_GUARD(0x0C8D07u, 0x8Cu, 0x21u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x2121u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->y & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D0Au, 0x00646851u, 4u);
        }

        case 0x00646851u: {
            TP_STATIC_GUARD(0x0C8D0Au, 0x8Cu, 0x0Bu, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x420Bu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->y & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D0Du, 0x00646869u, 4u);
        }

        case 0x00646869u: {
            TP_STATIC_GUARD(0x0C8D0Du, 0xA0u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D0Fu, 0x00646879u, 2u);
        }

        case 0x00646879u: {
            TP_STATIC_GUARD(0x0C8D0Fu, 0x8Cu, 0x40u, 0x43u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4340u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->y & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D12u, 0x00646891u, 4u);
        }

        case 0x00646891u: {
            TP_STATIC_GUARD(0x0C8D12u, 0xA0u, 0x22u);
            const uint8_t value = 0x22u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D14u, 0x006468A1u, 2u);
        }

        case 0x006468A1u: {
            TP_STATIC_GUARD(0x0C8D14u, 0x8Cu, 0x41u, 0x43u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4341u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->y & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D17u, 0x006468B9u, 4u);
        }

        case 0x006468B9u: {
            TP_STATIC_GUARD(0x0C8D17u, 0xA9u, 0x00u, 0xE0u);
            const uint16_t value = 0xE000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D1Au, 0x006468D1u, 3u);
        }

        case 0x006468D1u: {
            TP_STATIC_GUARD(0x0C8D1Au, 0xA2u, 0x1Cu);
            const uint8_t value = 0x1Cu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D1Cu, 0x006468E1u, 2u);
        }

        case 0x006468E1u: {
            TP_STATIC_GUARD(0x0C8D1Cu, 0x8Du, 0x42u, 0x43u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4342u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D1Fu, 0x006468F9u, 5u);
        }

        case 0x006468F9u: {
            TP_STATIC_GUARD(0x0C8D1Fu, 0x8Eu, 0x44u, 0x43u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4344u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D22u, 0x00646911u, 4u);
        }

        case 0x00646911u: {
            TP_STATIC_GUARD(0x0C8D22u, 0xA9u, 0x00u, 0x02u);
            const uint16_t value = 0x0200u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D25u, 0x00646929u, 3u);
        }

        case 0x00646929u: {
            TP_STATIC_GUARD(0x0C8D25u, 0x8Du, 0x45u, 0x43u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4345u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D28u, 0x00646941u, 5u);
        }

        case 0x00646941u: {
            TP_STATIC_GUARD(0x0C8D28u, 0xA0u, 0x10u);
            const uint8_t value = 0x10u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D2Au, 0x00646951u, 2u);
        }

        case 0x00646951u: {
            TP_STATIC_GUARD(0x0C8D2Au, 0x8Cu, 0x0Bu, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x420Bu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->y & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D2Du, 0x00646969u, 4u);
        }

        case 0x00646969u: {
            TP_STATIC_GUARD(0x0C8D2Du, 0x6Bu);
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
                case 0x00645F51u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00646972u: {
            TP_STATIC_GUARD(0x0C8D2Eu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x8D30u, 0x00646980u, 3u);
        }

        case 0x00646980u: {
            TP_STATIC_GUARD(0x0C8D30u, 0xADu, 0x0Bu, 0x04u);
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
            TP_STATIC_EXIT(0x0Cu, 0x8D33u, 0x00646998u, 5u);
        }

        case 0x00646998u: {
            TP_STATIC_GUARD(0x0C8D33u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D34u, 0x006469A0u, 4u);
        }

        case 0x006469A0u: {
            TP_STATIC_GUARD(0x0C8D34u, 0xADu, 0x0Du, 0x04u);
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
            TP_STATIC_EXIT(0x0Cu, 0x8D37u, 0x006469B8u, 5u);
        }

        case 0x006469B8u: {
            TP_STATIC_GUARD(0x0C8D37u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D38u, 0x006469C0u, 4u);
        }

        case 0x006469C0u: {
            TP_STATIC_GUARD(0x0C8D38u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x8D3Au, 0x006469D0u, 3u);
        }

        case 0x006469D0u: {
            TP_STATIC_GUARD(0x0C8D3Au, 0xADu, 0x67u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0767u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D3Du, 0x006469E8u, 5u);
        }

        case 0x006469E8u: {
            TP_STATIC_GUARD(0x0C8D3Du, 0xC9u, 0x14u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0014u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D40u, 0x00646A00u, 3u);
        }

        case 0x00646A00u: {
            TP_STATIC_GUARD(0x0C8D40u, 0x90u, 0x03u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8D45u;
                if (tp_scpu_expect_next(cpu, 0x00646A28u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8D42u, 0x00646A10u, 2u);
        }

        case 0x00646A10u: {
            TP_STATIC_GUARD(0x0C8D42u, 0xA9u, 0x14u, 0x00u);
            const uint16_t value = 0x0014u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D45u, 0x00646A28u, 3u);
        }

        case 0x00646A28u: {
            TP_STATIC_GUARD(0x0C8D45u, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D48u, 0x00646A40u, 3u);
        }

        case 0x00646A40u: {
            TP_STATIC_GUARD(0x0C8D48u, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D4Bu, 0x00646A58u, 5u);
        }

        case 0x00646A58u: {
            TP_STATIC_GUARD(0x0C8D4Bu, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D4Cu, 0x00646A60u, 3u);
        }

        case 0x00646A60u: {
            TP_STATIC_GUARD(0x0C8D4Cu, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D4Du, 0x00646A68u, 3u);
        }

        case 0x00646A68u: {
            TP_STATIC_GUARD(0x0C8D4Du, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D4Eu, 0x00646A70u, 3u);
        }

        case 0x00646A70u: {
            TP_STATIC_GUARD(0x0C8D4Eu, 0x8Du, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D51u, 0x00646A88u, 5u);
        }

        case 0x00646A88u: {
            TP_STATIC_GUARD(0x0C8D51u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D52u, 0x00646A90u, 2u);
        }

        case 0x00646A90u: {
            TP_STATIC_GUARD(0x0C8D52u, 0xF0u, 0x5Du);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8DB1u;
                if (tp_scpu_expect_next(cpu, 0x00646D88u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8D54u, 0x00646AA0u, 2u);
        }

        case 0x00646AA0u: {
            TP_STATIC_GUARD(0x0C8D54u, 0x9Cu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0415u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D57u, 0x00646AB8u, 5u);
        }

        case 0x00646AB8u: {
            TP_STATIC_GUARD(0x0C8D57u, 0xBFu, 0xB1u, 0xBEu, 0x7Eu);
            const uint32_t address = (0x7EBEB1u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D5Bu, 0x00646AD8u, 6u);
        }

        case 0x00646AD8u: {
            TP_STATIC_GUARD(0x0C8D5Bu, 0xE0u, 0x08u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D5Eu, 0x00646AF0u, 3u);
        }

        case 0x00646AF0u: {
            TP_STATIC_GUARD(0x0C8D5Eu, 0xB0u, 0x08u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8D68u;
                if (tp_scpu_expect_next(cpu, 0x00646B40u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8D60u, 0x00646B00u, 2u);
        }

        case 0x00646B00u: {
            TP_STATIC_GUARD(0x0C8D60u, 0x29u, 0xC0u, 0xC0u);
            cpu->a = (uint16_t)(cpu->a & 0xC0C0u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D63u, 0x00646B18u, 3u);
        }

        case 0x00646B18u: {
            TP_STATIC_GUARD(0x0C8D63u, 0x09u, 0x00u, 0x3Fu);
            cpu->a = (uint16_t)(cpu->a | 0x3F00u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D66u, 0x00646B30u, 3u);
        }

        case 0x00646B30u: {
            TP_STATIC_GUARD(0x0C8D66u, 0x80u, 0x10u);
            TP_STATIC_EXIT(0x0Cu, 0x8D78u, 0x00646BC0u, 3u);
        }

        case 0x00646B40u: {
            TP_STATIC_GUARD(0x0C8D68u, 0xE0u, 0x40u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0040u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D6Bu, 0x00646B58u, 3u);
        }

        case 0x00646B58u: {
            TP_STATIC_GUARD(0x0C8D6Bu, 0x90u, 0x08u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8D75u;
                if (tp_scpu_expect_next(cpu, 0x00646BA8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8D6Du, 0x00646B68u, 2u);
        }

        case 0x00646B68u: {
            TP_STATIC_GUARD(0x0C8D6Du, 0x29u, 0x0Fu, 0x0Fu);
            cpu->a = (uint16_t)(cpu->a & 0x0F0Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D70u, 0x00646B80u, 3u);
        }

        case 0x00646B80u: {
            TP_STATIC_GUARD(0x0C8D70u, 0x09u, 0x00u, 0xF0u);
            cpu->a = (uint16_t)(cpu->a | 0xF000u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D73u, 0x00646B98u, 3u);
        }

        case 0x00646B98u: {
            TP_STATIC_GUARD(0x0C8D73u, 0x80u, 0x03u);
            TP_STATIC_EXIT(0x0Cu, 0x8D78u, 0x00646BC0u, 3u);
        }

        case 0x00646BA8u: {
            TP_STATIC_GUARD(0x0C8D75u, 0xA9u, 0x00u, 0xFFu);
            const uint16_t value = 0xFF00u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D78u, 0x00646BC0u, 3u);
        }

        case 0x00646BC0u: {
            TP_STATIC_GUARD(0x0C8D78u, 0x9Fu, 0xB1u, 0xBEu, 0x7Eu);
            const uint32_t address = (0x7EBEB1u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D7Cu, 0x00646BE0u, 6u);
        }

        case 0x00646BE0u: {
            TP_STATIC_GUARD(0x0C8D7Cu, 0xBFu, 0xC1u, 0xBEu, 0x7Eu);
            const uint32_t address = (0x7EBEC1u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D80u, 0x00646C00u, 6u);
        }

        case 0x00646C00u: {
            TP_STATIC_GUARD(0x0C8D80u, 0xE0u, 0x08u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D83u, 0x00646C18u, 3u);
        }

        case 0x00646C18u: {
            TP_STATIC_GUARD(0x0C8D83u, 0xB0u, 0x05u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8D8Au;
                if (tp_scpu_expect_next(cpu, 0x00646C50u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8D85u, 0x00646C28u, 2u);
        }

        case 0x00646C28u: {
            TP_STATIC_GUARD(0x0C8D85u, 0x29u, 0xC0u, 0xC0u);
            cpu->a = (uint16_t)(cpu->a & 0xC0C0u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D88u, 0x00646C40u, 3u);
        }

        case 0x00646C40u: {
            TP_STATIC_GUARD(0x0C8D88u, 0x80u, 0x0Du);
            TP_STATIC_EXIT(0x0Cu, 0x8D97u, 0x00646CB8u, 3u);
        }

        case 0x00646C50u: {
            TP_STATIC_GUARD(0x0C8D8Au, 0xE0u, 0x40u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0040u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D8Du, 0x00646C68u, 3u);
        }

        case 0x00646C68u: {
            TP_STATIC_GUARD(0x0C8D8Du, 0x90u, 0x05u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8D94u;
                if (tp_scpu_expect_next(cpu, 0x00646CA0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8D8Fu, 0x00646C78u, 2u);
        }

        case 0x00646C78u: {
            TP_STATIC_GUARD(0x0C8D8Fu, 0x29u, 0x0Fu, 0x0Fu);
            cpu->a = (uint16_t)(cpu->a & 0x0F0Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D92u, 0x00646C90u, 3u);
        }

        case 0x00646C90u: {
            TP_STATIC_GUARD(0x0C8D92u, 0x80u, 0x03u);
            TP_STATIC_EXIT(0x0Cu, 0x8D97u, 0x00646CB8u, 3u);
        }

        case 0x00646CA0u: {
            TP_STATIC_GUARD(0x0C8D94u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D97u, 0x00646CB8u, 3u);
        }

        case 0x00646CB8u: {
            TP_STATIC_GUARD(0x0C8D97u, 0x9Fu, 0xC1u, 0xBEu, 0x7Eu);
            const uint32_t address = (0x7EBEC1u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D9Bu, 0x00646CD8u, 6u);
        }

        case 0x00646CD8u: {
            TP_STATIC_GUARD(0x0C8D9Bu, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D9Cu, 0x00646CE0u, 2u);
        }

        case 0x00646CE0u: {
            TP_STATIC_GUARD(0x0C8D9Cu, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8D9Du, 0x00646CE8u, 2u);
        }

        case 0x00646CE8u: {
            TP_STATIC_GUARD(0x0C8D9Du, 0xEEu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
            uint16_t old_value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(old_value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED ||
                tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8DA0u, 0x00646D00u, 8u);
        }

        case 0x00646D00u: {
            TP_STATIC_GUARD(0x0C8DA0u, 0xADu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DA3u, 0x00646D18u, 5u);
        }

        case 0x00646D18u: {
            TP_STATIC_GUARD(0x0C8DA3u, 0xC9u, 0x04u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0004u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DA6u, 0x00646D30u, 3u);
        }

        case 0x00646D30u: {
            TP_STATIC_GUARD(0x0C8DA6u, 0xD0u, 0xAFu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8D57u;
                if (tp_scpu_expect_next(cpu, 0x00646AB8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8DA8u, 0x00646D40u, 2u);
        }

        case 0x00646D40u: {
            TP_STATIC_GUARD(0x0C8DA8u, 0x8Au);
            cpu->a = cpu->x;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DA9u, 0x00646D48u, 2u);
        }

        case 0x00646D48u: {
            TP_STATIC_GUARD(0x0C8DA9u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x8DAAu, 0x00646D50u, 2u);
        }

        case 0x00646D50u: {
            TP_STATIC_GUARD(0x0C8DAAu, 0x69u, 0x18u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0018u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8DADu, 0x00646D68u, 3u);
        }

        case 0x00646D68u: {
            TP_STATIC_GUARD(0x0C8DADu, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DAEu, 0x00646D70u, 2u);
        }

        case 0x00646D70u: {
            TP_STATIC_GUARD(0x0C8DAEu, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DAFu, 0x00646D78u, 2u);
        }

        case 0x00646D78u: {
            TP_STATIC_GUARD(0x0C8DAFu, 0xD0u, 0xA3u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8D54u;
                if (tp_scpu_expect_next(cpu, 0x00646AA0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8DB1u, 0x00646D88u, 2u);
        }

        case 0x00646D88u: {
            TP_STATIC_GUARD(0x0C8DB1u, 0xA9u, 0x03u, 0x00u);
            const uint16_t value = 0x0003u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DB4u, 0x00646DA0u, 3u);
        }

        case 0x00646DA0u: {
            TP_STATIC_GUARD(0x0C8DB4u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x8DB5u, 0x00646DA8u, 2u);
        }

        case 0x00646DA8u: {
            TP_STATIC_GUARD(0x0C8DB5u, 0xEDu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8DB8u, 0x00646DC0u, 5u);
        }

        case 0x00646DC0u: {
            TP_STATIC_GUARD(0x0C8DB8u, 0xF0u, 0x5Eu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8E18u;
                if (tp_scpu_expect_next(cpu, 0x006470C0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8DBAu, 0x00646DD0u, 2u);
        }

        case 0x00646DD0u: {
            TP_STATIC_GUARD(0x0C8DBAu, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DBBu, 0x00646DD8u, 2u);
        }

        case 0x00646DD8u: {
            TP_STATIC_GUARD(0x0C8DBBu, 0x9Cu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0415u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8DBEu, 0x00646DF0u, 5u);
        }

        case 0x00646DF0u: {
            TP_STATIC_GUARD(0x0C8DBEu, 0xBFu, 0xB1u, 0xBEu, 0x7Eu);
            const uint32_t address = (0x7EBEB1u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DC2u, 0x00646E10u, 6u);
        }

        case 0x00646E10u: {
            TP_STATIC_GUARD(0x0C8DC2u, 0xE0u, 0x08u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DC5u, 0x00646E28u, 3u);
        }

        case 0x00646E28u: {
            TP_STATIC_GUARD(0x0C8DC5u, 0xB0u, 0x08u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8DCFu;
                if (tp_scpu_expect_next(cpu, 0x00646E78u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8DC7u, 0x00646E38u, 2u);
        }

        case 0x00646E38u: {
            TP_STATIC_GUARD(0x0C8DC7u, 0x29u, 0xC0u, 0xC0u);
            cpu->a = (uint16_t)(cpu->a & 0xC0C0u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DCAu, 0x00646E50u, 3u);
        }

        case 0x00646E50u: {
            TP_STATIC_GUARD(0x0C8DCAu, 0x09u, 0x3Fu, 0x00u);
            cpu->a = (uint16_t)(cpu->a | 0x003Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DCDu, 0x00646E68u, 3u);
        }

        case 0x00646E68u: {
            TP_STATIC_GUARD(0x0C8DCDu, 0x80u, 0x10u);
            TP_STATIC_EXIT(0x0Cu, 0x8DDFu, 0x00646EF8u, 3u);
        }

        case 0x00646E78u: {
            TP_STATIC_GUARD(0x0C8DCFu, 0xE0u, 0x40u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0040u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DD2u, 0x00646E90u, 3u);
        }

        case 0x00646E90u: {
            TP_STATIC_GUARD(0x0C8DD2u, 0x90u, 0x08u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8DDCu;
                if (tp_scpu_expect_next(cpu, 0x00646EE0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8DD4u, 0x00646EA0u, 2u);
        }

        case 0x00646EA0u: {
            TP_STATIC_GUARD(0x0C8DD4u, 0x29u, 0x0Fu, 0x0Fu);
            cpu->a = (uint16_t)(cpu->a & 0x0F0Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DD7u, 0x00646EB8u, 3u);
        }

        case 0x00646EB8u: {
            TP_STATIC_GUARD(0x0C8DD7u, 0x09u, 0xF0u, 0x00u);
            cpu->a = (uint16_t)(cpu->a | 0x00F0u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DDAu, 0x00646ED0u, 3u);
        }

        case 0x00646ED0u: {
            TP_STATIC_GUARD(0x0C8DDAu, 0x80u, 0x03u);
            TP_STATIC_EXIT(0x0Cu, 0x8DDFu, 0x00646EF8u, 3u);
        }

        case 0x00646EE0u: {
            TP_STATIC_GUARD(0x0C8DDCu, 0xA9u, 0xFFu, 0x00u);
            const uint16_t value = 0x00FFu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DDFu, 0x00646EF8u, 3u);
        }

        case 0x00646EF8u: {
            TP_STATIC_GUARD(0x0C8DDFu, 0x9Fu, 0xB1u, 0xBEu, 0x7Eu);
            const uint32_t address = (0x7EBEB1u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8DE3u, 0x00646F18u, 6u);
        }

        case 0x00646F18u: {
            TP_STATIC_GUARD(0x0C8DE3u, 0xBFu, 0xC1u, 0xBEu, 0x7Eu);
            const uint32_t address = (0x7EBEC1u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DE7u, 0x00646F38u, 6u);
        }

        case 0x00646F38u: {
            TP_STATIC_GUARD(0x0C8DE7u, 0xE0u, 0x08u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DEAu, 0x00646F50u, 3u);
        }

        case 0x00646F50u: {
            TP_STATIC_GUARD(0x0C8DEAu, 0xB0u, 0x05u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8DF1u;
                if (tp_scpu_expect_next(cpu, 0x00646F88u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8DECu, 0x00646F60u, 2u);
        }

        case 0x00646F60u: {
            TP_STATIC_GUARD(0x0C8DECu, 0x29u, 0xC0u, 0xC0u);
            cpu->a = (uint16_t)(cpu->a & 0xC0C0u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DEFu, 0x00646F78u, 3u);
        }

        case 0x00646F78u: {
            TP_STATIC_GUARD(0x0C8DEFu, 0x80u, 0x0Du);
            TP_STATIC_EXIT(0x0Cu, 0x8DFEu, 0x00646FF0u, 3u);
        }

        case 0x00646F88u: {
            TP_STATIC_GUARD(0x0C8DF1u, 0xE0u, 0x40u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0040u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DF4u, 0x00646FA0u, 3u);
        }

        case 0x00646FA0u: {
            TP_STATIC_GUARD(0x0C8DF4u, 0x90u, 0x05u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8DFBu;
                if (tp_scpu_expect_next(cpu, 0x00646FD8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8DF6u, 0x00646FB0u, 2u);
        }

        case 0x00646FB0u: {
            TP_STATIC_GUARD(0x0C8DF6u, 0x29u, 0x0Fu, 0x0Fu);
            cpu->a = (uint16_t)(cpu->a & 0x0F0Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DF9u, 0x00646FC8u, 3u);
        }

        case 0x00646FC8u: {
            TP_STATIC_GUARD(0x0C8DF9u, 0x80u, 0x03u);
            TP_STATIC_EXIT(0x0Cu, 0x8DFEu, 0x00646FF0u, 3u);
        }

        case 0x00646FD8u: {
            TP_STATIC_GUARD(0x0C8DFBu, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8DFEu, 0x00646FF0u, 3u);
        }

        case 0x00646FF0u: {
            TP_STATIC_GUARD(0x0C8DFEu, 0x9Fu, 0xC1u, 0xBEu, 0x7Eu);
            const uint32_t address = (0x7EBEC1u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8E02u, 0x00647010u, 6u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
