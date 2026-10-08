/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000C87(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00643808u: {
            TP_STATIC_GUARD(0x0C8701u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8704u, 0x00643820u, 3u);
        }

        case 0x00643820u: {
            TP_STATIC_GUARD(0x0C8704u, 0x8Du, 0x55u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1855u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8707u, 0x00643838u, 5u);
        }

        case 0x00643838u: {
            TP_STATIC_GUARD(0x0C8707u, 0xA9u, 0x02u, 0x00u);
            const uint16_t value = 0x0002u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x870Au, 0x00643850u, 3u);
        }

        case 0x00643850u: {
            TP_STATIC_GUARD(0x0C870Au, 0x8Du, 0x57u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1857u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x870Du, 0x00643868u, 5u);
        }

        case 0x00643868u: {
            TP_STATIC_GUARD(0x0C870Du, 0x9Cu, 0x1Au, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x081Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8710u, 0x00643880u, 5u);
        }

        case 0x00643880u: {
            TP_STATIC_GUARD(0x0C8710u, 0x9Cu, 0xBCu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07BCu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8713u, 0x00643898u, 5u);
        }

        case 0x00643898u: {
            TP_STATIC_GUARD(0x0C8713u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x8715u, 0x006438A8u, 3u);
        }

        case 0x006438A8u: {
            TP_STATIC_GUARD(0x0C8715u, 0x9Cu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0415u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8718u, 0x006438C0u, 5u);
        }

        case 0x006438C0u: {
            TP_STATIC_GUARD(0x0C8718u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x871Au, 0x006438D0u, 3u);
        }

        case 0x006438C2u: {
            TP_STATIC_GUARD(0x0C8718u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x871Au, 0x006438D0u, 3u);
        }

        case 0x006438D0u: {
            TP_STATIC_GUARD(0x0C871Au, 0xACu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x871Du, 0x006438E8u, 5u);
        }

        case 0x006438E8u: {
            TP_STATIC_GUARD(0x0C871Du, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x871Eu, 0x006438F0u, 2u);
        }

        case 0x006438F0u: {
            TP_STATIC_GUARD(0x0C871Eu, 0xA9u, 0x1Au, 0x00u);
            const uint16_t value = 0x001Au;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8721u, 0x00643908u, 3u);
        }

        case 0x00643908u: {
            TP_STATIC_GUARD(0x0C8721u, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x87u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x24u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x00643928u: {
            TP_STATIC_GUARD(0x0C8725u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8726u, 0x00643930u, 2u);
        }

        case 0x00643930u: {
            TP_STATIC_GUARD(0x0C8726u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8728u, 0x00643942u, 3u);
        }

        case 0x00643942u: {
            TP_STATIC_GUARD(0x0C8728u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x0Cu, 0x872Au, 0x00643952u, 3u);
        }

        case 0x00643952u: {
            TP_STATIC_GUARD(0x0C872Au, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x872Bu, 0x0064395Au, 2u);
        }

        case 0x0064395Au: {
            TP_STATIC_GUARD(0x0C872Bu, 0xBFu, 0xCEu, 0xC8u, 0x01u);
            const uint32_t address = (0x01C8CEu + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x872Fu, 0x0064397Au, 5u);
        }

        case 0x0064397Au: {
            TP_STATIC_GUARD(0x0C872Fu, 0xC9u, 0x00u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x00u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8731u, 0x0064398Au, 2u);
        }

        case 0x0064398Au: {
            TP_STATIC_GUARD(0x0C8731u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8736u;
                if (tp_scpu_expect_next(cpu, 0x006439B2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8733u, 0x0064399Au, 2u);
        }

        case 0x0064399Au: {
            TP_STATIC_GUARD(0x0C8733u, 0x82u, 0x12u, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x8748u, 0x00643A42u, 4u);
        }

        case 0x006439B2u: {
            TP_STATIC_GUARD(0x0C8736u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8738u, 0x006439C2u, 3u);
        }

        case 0x006439C2u: {
            TP_STATIC_GUARD(0x0C8738u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x0Cu, 0x873Au, 0x006439D2u, 3u);
        }

        case 0x006439D2u: {
            TP_STATIC_GUARD(0x0C873Au, 0xACu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x873Du, 0x006439EAu, 5u);
        }

        case 0x006439EAu: {
            TP_STATIC_GUARD(0x0C873Du, 0xA9u, 0xFFu);
            const uint8_t value = 0xFFu;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x873Fu, 0x006439FAu, 2u);
        }

        case 0x006439FAu: {
            TP_STATIC_GUARD(0x0C873Fu, 0x99u, 0x2Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x072Au + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8742u, 0x00643A12u, 5u);
        }

        case 0x00643A12u: {
            TP_STATIC_GUARD(0x0C8742u, 0xEEu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8745u, 0x00643A2Au, 6u);
        }

        case 0x00643A2Au: {
            TP_STATIC_GUARD(0x0C8745u, 0x82u, 0xD0u, 0xFFu);
            TP_STATIC_EXIT(0x0Cu, 0x8718u, 0x006438C2u, 4u);
        }

        case 0x00643A42u: {
            TP_STATIC_GUARD(0x0C8748u, 0x6Bu);
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
                case 0x0064589Au:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00643A4Bu: {
            TP_STATIC_GUARD(0x0C8749u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x874Bu, 0x00643A58u, 3u);
        }

        case 0x00643A58u: {
            TP_STATIC_GUARD(0x0C874Bu, 0xADu, 0x10u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0010u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x874Eu, 0x00643A70u, 5u);
        }

        case 0x00643A70u: {
            TP_STATIC_GUARD(0x0C874Eu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8753u;
                if (tp_scpu_expect_next(cpu, 0x00643A98u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8750u, 0x00643A80u, 2u);
        }

        case 0x00643A80u: {
            TP_STATIC_GUARD(0x0C8750u, 0x82u, 0x9Au, 0x01u);
            TP_STATIC_EXIT(0x0Cu, 0x88EDu, 0x00644768u, 4u);
        }

        case 0x00643A98u: {
            TP_STATIC_GUARD(0x0C8753u, 0x22u, 0x01u, 0x89u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x87u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x56u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8901u, 0x00644808u, 8u);
        }

        case 0x00643ABBu: {
            TP_STATIC_GUARD(0x0C8757u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x8759u, 0x00643AC8u, 3u);
        }

        case 0x00643AC8u: {
            TP_STATIC_GUARD(0x0C8759u, 0x9Cu, 0x8Du, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x875Cu, 0x00643AE0u, 5u);
        }

        case 0x00643AE0u: {
            TP_STATIC_GUARD(0x0C875Cu, 0xA9u, 0x07u, 0x00u);
            const uint16_t value = 0x0007u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x875Fu, 0x00643AF8u, 3u);
        }

        case 0x00643AF8u: {
            TP_STATIC_GUARD(0x0C875Fu, 0x22u, 0x18u, 0x80u, 0x0Eu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x87u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x62u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8018u, 0x007400C0u, 8u);
        }

        case 0x00643B18u: {
            TP_STATIC_GUARD(0x0C8763u, 0x22u, 0xFBu, 0x88u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x87u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x66u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88FBu, 0x006447D8u, 8u);
        }

        case 0x00643B38u: {
            TP_STATIC_GUARD(0x0C8767u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x8769u, 0x00643B48u, 3u);
        }

        case 0x00643B3Bu: {
            TP_STATIC_GUARD(0x0C8767u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x8769u, 0x00643B48u, 3u);
        }

        case 0x00643B48u: {
            TP_STATIC_GUARD(0x0C8769u, 0xADu, 0x10u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0010u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x876Cu, 0x00643B60u, 5u);
        }

        case 0x00643B60u: {
            TP_STATIC_GUARD(0x0C876Cu, 0xF0u, 0x21u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x878Fu;
                if (tp_scpu_expect_next(cpu, 0x00643C78u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x876Eu, 0x00643B70u, 2u);
        }

        case 0x00643B70u: {
            TP_STATIC_GUARD(0x0C876Eu, 0x22u, 0x01u, 0x89u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x87u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x71u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8901u, 0x00644808u, 8u);
        }

        case 0x00643B93u: {
            TP_STATIC_GUARD(0x0C8772u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8774u, 0x00643BA3u, 3u);
        }

        case 0x00643BA3u: {
            TP_STATIC_GUARD(0x0C8774u, 0xA2u, 0xFAu);
            const uint8_t value = 0xFAu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8776u, 0x00643BB3u, 2u);
        }

        case 0x00643BB3u: {
            TP_STATIC_GUARD(0x0C8776u, 0x8Eu, 0x0Eu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x000Eu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8779u, 0x00643BCBu, 4u);
        }

        case 0x00643BCBu: {
            TP_STATIC_GUARD(0x0C8779u, 0x22u, 0x0Cu, 0x80u, 0x0Eu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x87u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x7Cu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x800Cu, 0x00740063u, 8u);
        }

        case 0x00643BEBu: {
            TP_STATIC_GUARD(0x0C877Du, 0x22u, 0x0Cu, 0x80u, 0x0Eu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x87u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x800Cu, 0x00740063u, 8u);
        }

        case 0x00643C0Bu: {
            TP_STATIC_GUARD(0x0C8781u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8783u, 0x00643C1Bu, 3u);
        }

        case 0x00643C1Bu: {
            TP_STATIC_GUARD(0x0C8783u, 0xA2u, 0x04u);
            const uint8_t value = 0x04u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8785u, 0x00643C2Bu, 2u);
        }

        case 0x00643C2Bu: {
            TP_STATIC_GUARD(0x0C8785u, 0x8Eu, 0x0Eu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x000Eu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8788u, 0x00643C43u, 4u);
        }

        case 0x00643C43u: {
            TP_STATIC_GUARD(0x0C8788u, 0x22u, 0xFBu, 0x88u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x87u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88FBu, 0x006447DBu, 8u);
        }

        case 0x00643C63u: {
            TP_STATIC_GUARD(0x0C878Cu, 0x82u, 0x5Eu, 0x01u);
            TP_STATIC_EXIT(0x0Cu, 0x88EDu, 0x0064476Bu, 4u);
        }

        case 0x00643C78u: {
            TP_STATIC_GUARD(0x0C878Fu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8791u, 0x00643C8Bu, 3u);
        }

        case 0x00643C8Bu: {
            TP_STATIC_GUARD(0x0C8791u, 0xADu, 0xEBu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18EBu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8794u, 0x00643CA3u, 4u);
        }

        case 0x00643CA3u: {
            TP_STATIC_GUARD(0x0C8794u, 0xD0u, 0x05u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x879Bu;
                if (tp_scpu_expect_next(cpu, 0x00643CDBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8796u, 0x00643CB3u, 2u);
        }

        case 0x00643CB3u: {
            TP_STATIC_GUARD(0x0C8796u, 0xA9u, 0x14u);
            const uint8_t value = 0x14u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8798u, 0x00643CC3u, 2u);
        }

        case 0x00643CC3u: {
            TP_STATIC_GUARD(0x0C8798u, 0x8Du, 0x88u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1888u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x879Bu, 0x00643CDBu, 4u);
        }

        case 0x00643CDBu: {
            TP_STATIC_GUARD(0x0C879Bu, 0xADu, 0x90u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1890u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x879Eu, 0x00643CF3u, 4u);
        }

        case 0x00643CF3u: {
            TP_STATIC_GUARD(0x0C879Eu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x87A3u;
                if (tp_scpu_expect_next(cpu, 0x00643D1Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x87A0u, 0x00643D03u, 2u);
        }

        case 0x00643D03u: {
            TP_STATIC_GUARD(0x0C87A0u, 0x8Du, 0x8Cu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x87A3u, 0x00643D1Bu, 4u);
        }

        case 0x00643D1Bu: {
            TP_STATIC_GUARD(0x0C87A3u, 0x9Cu, 0x8Bu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Bu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x87A6u, 0x00643D33u, 4u);
        }

        case 0x00643D33u: {
            TP_STATIC_GUARD(0x0C87A6u, 0xADu, 0x8Bu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x188Bu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87A9u, 0x00643D4Bu, 4u);
        }

        case 0x00643D4Bu: {
            TP_STATIC_GUARD(0x0C87A9u, 0xADu, 0x88u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1888u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87ACu, 0x00643D63u, 4u);
        }

        case 0x00643D63u: {
            TP_STATIC_GUARD(0x0C87ACu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x87B1u;
                if (tp_scpu_expect_next(cpu, 0x00643D8Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x87AEu, 0x00643D73u, 2u);
        }

        case 0x00643D73u: {
            TP_STATIC_GUARD(0x0C87AEu, 0x82u, 0xB7u, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x8868u, 0x00644343u, 4u);
        }

        case 0x00643D8Bu: {
            TP_STATIC_GUARD(0x0C87B1u, 0x10u, 0x03u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x87B6u;
                if (tp_scpu_expect_next(cpu, 0x00643DB3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x87B3u, 0x00643D9Bu, 2u);
        }

        case 0x00643D9Bu: {
            TP_STATIC_GUARD(0x0C87B3u, 0x4Cu, 0x63u, 0x88u);
            TP_STATIC_EXIT(0x0Cu, 0x8863u, 0x0064431Bu, 3u);
        }

        case 0x00643DB3u: {
            TP_STATIC_GUARD(0x0C87B6u, 0xCDu, 0x89u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1889u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87B9u, 0x00643DCBu, 4u);
        }

        case 0x00643DCBu: {
            TP_STATIC_GUARD(0x0C87B9u, 0xD0u, 0x0Au);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x87C5u;
                if (tp_scpu_expect_next(cpu, 0x00643E2Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x87BBu, 0x00643DDBu, 2u);
        }

        case 0x00643DDBu: {
            TP_STATIC_GUARD(0x0C87BBu, 0xADu, 0x8Au, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x188Au;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87BEu, 0x00643DF3u, 4u);
        }

        case 0x00643DF3u: {
            TP_STATIC_GUARD(0x0C87BEu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x87C3u;
                if (tp_scpu_expect_next(cpu, 0x00643E1Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x87C0u, 0x00643E03u, 2u);
        }

        case 0x00643E03u: {
            TP_STATIC_GUARD(0x0C87C0u, 0x82u, 0xA5u, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x8868u, 0x00644343u, 4u);
        }

        case 0x00643E1Bu: {
            TP_STATIC_GUARD(0x0C87C3u, 0x80u, 0x4Fu);
            TP_STATIC_EXIT(0x0Cu, 0x8814u, 0x006440A3u, 3u);
        }

        case 0x00643E2Bu: {
            TP_STATIC_GUARD(0x0C87C5u, 0xADu, 0x8Au, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x188Au;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87C8u, 0x00643E43u, 4u);
        }

        case 0x00643E43u: {
            TP_STATIC_GUARD(0x0C87C8u, 0xD0u, 0x68u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8832u;
                if (tp_scpu_expect_next(cpu, 0x00644193u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x87CAu, 0x00643E53u, 2u);
        }

        case 0x00643E53u: {
            TP_STATIC_GUARD(0x0C87CAu, 0xADu, 0x88u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1888u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87CDu, 0x00643E6Bu, 4u);
        }

        case 0x00643E6Bu: {
            TP_STATIC_GUARD(0x0C87CDu, 0x8Du, 0x89u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1889u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x87D0u, 0x00643E83u, 4u);
        }

        case 0x00643E83u: {
            TP_STATIC_GUARD(0x0C87D0u, 0x22u, 0x01u, 0x89u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x87u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xD3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8901u, 0x0064480Bu, 8u);
        }

        case 0x00643EA3u: {
            TP_STATIC_GUARD(0x0C87D4u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x87D6u, 0x00643EB0u, 3u);
        }

        case 0x00643EB0u: {
            TP_STATIC_GUARD(0x0C87D6u, 0xA9u, 0x07u, 0x00u);
            const uint16_t value = 0x0007u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87D9u, 0x00643EC8u, 3u);
        }

        case 0x00643EC8u: {
            TP_STATIC_GUARD(0x0C87D9u, 0x22u, 0x18u, 0x80u, 0x0Eu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x87u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDCu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8018u, 0x007400C0u, 8u);
        }

        case 0x00643EE8u: {
            TP_STATIC_GUARD(0x0C87DDu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x87DFu, 0x00643EF8u, 3u);
        }

        case 0x00643EF8u: {
            TP_STATIC_GUARD(0x0C87DFu, 0x9Cu, 0x8Du, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x87E2u, 0x00643F10u, 5u);
        }

        case 0x00643F10u: {
            TP_STATIC_GUARD(0x0C87E2u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x87E4u, 0x00643F21u, 3u);
        }

        case 0x00643F21u: {
            TP_STATIC_GUARD(0x0C87E4u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x0Cu, 0x87E6u, 0x00643F31u, 3u);
        }

        case 0x00643F31u: {
            TP_STATIC_GUARD(0x0C87E6u, 0xADu, 0x88u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1888u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87E9u, 0x00643F49u, 5u);
        }

        case 0x00643F49u: {
            TP_STATIC_GUARD(0x0C87E9u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87ECu, 0x00643F61u, 3u);
        }

        case 0x00643F61u: {
            TP_STATIC_GUARD(0x0C87ECu, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87EDu, 0x00643F69u, 3u);
        }

        case 0x00643F69u: {
            TP_STATIC_GUARD(0x0C87EDu, 0xAAu);
            cpu->x = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87EEu, 0x00643F71u, 2u);
        }

        case 0x00643F71u: {
            TP_STATIC_GUARD(0x0C87EEu, 0xBFu, 0x2Bu, 0x91u, 0x05u);
            const uint32_t address = (0x05912Bu + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87F2u, 0x00643F91u, 6u);
        }

        case 0x00643F91u: {
            TP_STATIC_GUARD(0x0C87F2u, 0x8Du, 0x04u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0004u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x87F5u, 0x00643FA9u, 5u);
        }

        case 0x00643FA9u: {
            TP_STATIC_GUARD(0x0C87F5u, 0x8Au);
            cpu->a = cpu->x;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87F6u, 0x00643FB1u, 2u);
        }

        case 0x00643FB1u: {
            TP_STATIC_GUARD(0x0C87F6u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87F9u, 0x00643FC9u, 3u);
        }

        case 0x00643FC9u: {
            TP_STATIC_GUARD(0x0C87F9u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87FAu, 0x00643FD1u, 3u);
        }

        case 0x00643FD1u: {
            TP_STATIC_GUARD(0x0C87FAu, 0xAAu);
            cpu->x = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87FBu, 0x00643FD9u, 2u);
        }

        case 0x00643FD9u: {
            TP_STATIC_GUARD(0x0C87FBu, 0xBFu, 0x55u, 0x91u, 0x05u);
            const uint32_t address = (0x059155u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x87FFu, 0x00643FF9u, 6u);
        }

        case 0x00643FF9u: {
            TP_STATIC_GUARD(0x0C87FFu, 0x8Du, 0x00u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0000u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8802u, 0x00644011u, 5u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
