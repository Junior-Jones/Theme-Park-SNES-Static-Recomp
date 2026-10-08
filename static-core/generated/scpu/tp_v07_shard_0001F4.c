/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0001F4(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x000FA013u: {
            TP_STATIC_GUARD(0x01F402u, 0xC9u, 0x80u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x80u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF404u, 0x000FA023u, 2u);
        }

        case 0x000FA023u: {
            TP_STATIC_GUARD(0x01F404u, 0xD0u, 0x46u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF44Cu;
                if (tp_scpu_expect_next(cpu, 0x000FA263u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF406u, 0x000FA033u, 2u);
        }

        case 0x000FA033u: {
            TP_STATIC_GUARD(0x01F406u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xF408u, 0x000FA040u, 3u);
        }

        case 0x000FA040u: {
            TP_STATIC_GUARD(0x01F408u, 0xADu, 0x0Fu, 0x04u);
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
            TP_STATIC_EXIT(0x01u, 0xF40Bu, 0x000FA058u, 5u);
        }

        case 0x000FA058u: {
            TP_STATIC_GUARD(0x01F40Bu, 0xF0u, 0x3Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF44Cu;
                if (tp_scpu_expect_next(cpu, 0x000FA260u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF40Du, 0x000FA068u, 2u);
        }

        case 0x000FA068u: {
            TP_STATIC_GUARD(0x01F40Du, 0xCEu, 0x0Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Fu;
            uint16_t old_value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED ||
                tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF410u, 0x000FA080u, 8u);
        }

        case 0x000FA080u: {
            TP_STATIC_GUARD(0x01F410u, 0xACu, 0x0Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF413u, 0x000FA098u, 5u);
        }

        case 0x000FA098u: {
            TP_STATIC_GUARD(0x01F413u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF416u, 0x000FA0B0u, 3u);
        }

        case 0x000FA0B0u: {
            TP_STATIC_GUARD(0x01F416u, 0x99u, 0xB7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18B7u + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF419u, 0x000FA0C8u, 6u);
        }

        case 0x000FA0C8u: {
            TP_STATIC_GUARD(0x01F419u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xF41Bu, 0x000FA0D8u, 3u);
        }

        case 0x000FA0D8u: {
            TP_STATIC_GUARD(0x01F41Bu, 0xA9u, 0xCEu, 0xF0u);
            const uint16_t value = 0xF0CEu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF41Eu, 0x000FA0F0u, 3u);
        }

        case 0x000FA0F0u: {
            TP_STATIC_GUARD(0x01F41Eu, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF421u, 0x000FA108u, 5u);
        }

        case 0x000FA108u: {
            TP_STATIC_GUARD(0x01F421u, 0xA2u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF424u, 0x000FA120u, 3u);
        }

        case 0x000FA120u: {
            TP_STATIC_GUARD(0x01F424u, 0x8Eu, 0x94u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0794u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF427u, 0x000FA138u, 5u);
        }

        case 0x000FA138u: {
            TP_STATIC_GUARD(0x01F427u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF42Au, 0x000FA150u, 3u);
        }

        case 0x000FA150u: {
            TP_STATIC_GUARD(0x01F42Au, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF42Du, 0x000FA168u, 5u);
        }

        case 0x000FA168u: {
            TP_STATIC_GUARD(0x01F42Du, 0xA9u, 0x14u, 0x00u);
            const uint16_t value = 0x0014u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF430u, 0x000FA180u, 3u);
        }

        case 0x000FA180u: {
            TP_STATIC_GUARD(0x01F430u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF433u, 0x000FA198u, 5u);
        }

        case 0x000FA198u: {
            TP_STATIC_GUARD(0x01F433u, 0xA9u, 0x20u, 0x00u);
            const uint16_t value = 0x0020u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF436u, 0x000FA1B0u, 3u);
        }

        case 0x000FA1B0u: {
            TP_STATIC_GUARD(0x01F436u, 0x8Du, 0x96u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0796u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF439u, 0x000FA1C8u, 5u);
        }

        case 0x000FA1C8u: {
            TP_STATIC_GUARD(0x01F439u, 0x22u, 0xAFu, 0xDDu, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x3Cu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDDAFu, 0x000EED78u, 8u);
        }

        case 0x000FA1E9u: {
            TP_STATIC_GUARD(0x01F43Du, 0x22u, 0x3Cu, 0xA3u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x40u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA33Cu, 0x003519E1u, 8u);
        }

        case 0x000FA208u: {
            TP_STATIC_GUARD(0x01F441u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xF443u, 0x000FA21Bu, 3u);
        }

        case 0x000FA21Bu: {
            TP_STATIC_GUARD(0x01F443u, 0xA9u, 0x07u);
            const uint8_t value = 0x07u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF445u, 0x000FA22Bu, 2u);
        }

        case 0x000FA22Bu: {
            TP_STATIC_GUARD(0x01F445u, 0x8Du, 0x8Cu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF448u, 0x000FA243u, 4u);
        }

        case 0x000FA243u: {
            TP_STATIC_GUARD(0x01F448u, 0x22u, 0x49u, 0x87u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x4Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8749u, 0x00643A4Bu, 8u);
        }

        case 0x000FA260u: {
            TP_STATIC_GUARD(0x01F44Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xF44Eu, 0x000FA270u, 3u);
        }

        case 0x000FA263u: {
            TP_STATIC_GUARD(0x01F44Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xF44Eu, 0x000FA270u, 3u);
        }

        case 0x000FA270u: {
            TP_STATIC_GUARD(0x01F44Eu, 0x82u, 0x33u, 0xFEu);
            TP_STATIC_EXIT(0x01u, 0xF284u, 0x000F9420u, 4u);
        }

        case 0x000FA28Bu: {
            TP_STATIC_GUARD(0x01F451u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xF453u, 0x000FA29Bu, 3u);
        }

        case 0x000FA29Bu: {
            TP_STATIC_GUARD(0x01F453u, 0xA9u, 0x06u);
            const uint8_t value = 0x06u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF455u, 0x000FA2ABu, 2u);
        }

        case 0x000FA2ABu: {
            TP_STATIC_GUARD(0x01F455u, 0x8Du, 0x8Cu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF458u, 0x000FA2C3u, 4u);
        }

        case 0x000FA2C3u: {
            TP_STATIC_GUARD(0x01F458u, 0x22u, 0x49u, 0x87u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x5Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8749u, 0x00643A4Bu, 8u);
        }

        case 0x000FA2E3u: {
            TP_STATIC_GUARD(0x01F45Cu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xF45Eu, 0x000FA2F3u, 3u);
        }

        case 0x000FA2F3u: {
            TP_STATIC_GUARD(0x01F45Eu, 0xA2u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF460u, 0x000FA303u, 2u);
        }

        case 0x000FA303u: {
            TP_STATIC_GUARD(0x01F460u, 0xBDu, 0xB7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18B7u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x01u;
            cpu->pc = 0xF463u;
            if (tp_scpu_expect_next(cpu, 0x000FA31Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + (((0xB7u + (cpu->x & 0x00FFu)) > 0x00FFu) ? 1u : 0u));
        }

        case 0x000FA31Bu: {
            TP_STATIC_GUARD(0x01F463u, 0xF0u, 0x0Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF471u;
                if (tp_scpu_expect_next(cpu, 0x000FA38Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF465u, 0x000FA32Bu, 2u);
        }

        case 0x000FA32Bu: {
            TP_STATIC_GUARD(0x01F465u, 0xBDu, 0xB7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18B7u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x01u;
            cpu->pc = 0xF468u;
            if (tp_scpu_expect_next(cpu, 0x000FA343u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + (((0xB7u + (cpu->x & 0x00FFu)) > 0x00FFu) ? 1u : 0u));
        }

        case 0x000FA343u: {
            TP_STATIC_GUARD(0x01F468u, 0x9Fu, 0x15u, 0x07u, 0x00u);
            const uint32_t address = (0x000715u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF46Cu, 0x000FA363u, 5u);
        }

        case 0x000FA363u: {
            TP_STATIC_GUARD(0x01F46Cu, 0xF0u, 0x2Au);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF498u;
                if (tp_scpu_expect_next(cpu, 0x000FA4C3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF46Eu, 0x000FA373u, 2u);
        }

        case 0x000FA373u: {
            TP_STATIC_GUARD(0x01F46Eu, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF46Fu, 0x000FA37Bu, 2u);
        }

        case 0x000FA37Bu: {
            TP_STATIC_GUARD(0x01F46Fu, 0x80u, 0xF4u);
            TP_STATIC_EXIT(0x01u, 0xF465u, 0x000FA32Bu, 3u);
        }

        case 0x000FA38Bu: {
            TP_STATIC_GUARD(0x01F471u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xF473u, 0x000FA39Bu, 3u);
        }

        case 0x000FA39Bu: {
            TP_STATIC_GUARD(0x01F473u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x01u, 0xF475u, 0x000FA3A9u, 3u);
        }

        case 0x000FA3A9u: {
            TP_STATIC_GUARD(0x01F475u, 0xADu, 0xD5u, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06D5u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF478u, 0x000FA3C1u, 5u);
        }

        case 0x000FA3C1u: {
            TP_STATIC_GUARD(0x01F478u, 0xAEu, 0xD7u, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06D7u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF47Bu, 0x000FA3D9u, 4u);
        }

        case 0x000FA3D9u: {
            TP_STATIC_GUARD(0x01F47Bu, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF47Eu, 0x000FA3F1u, 5u);
        }

        case 0x000FA3F1u: {
            TP_STATIC_GUARD(0x01F47Eu, 0x8Eu, 0x66u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0066u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF481u, 0x000FA409u, 4u);
        }

        case 0x000FA409u: {
            TP_STATIC_GUARD(0x01F481u, 0xA7u, 0x64u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x64u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x01u;
            cpu->pc = 0xF483u;
            if (tp_scpu_expect_next(cpu, 0x000FA419u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x000FA419u: {
            TP_STATIC_GUARD(0x01F483u, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF486u, 0x000FA431u, 5u);
        }

        case 0x000FA431u: {
            TP_STATIC_GUARD(0x01F486u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xF488u, 0x000FA443u, 3u);
        }

        case 0x000FA443u: {
            TP_STATIC_GUARD(0x01F488u, 0xA0u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF48Au, 0x000FA453u, 2u);
        }

        case 0x000FA453u: {
            TP_STATIC_GUARD(0x01F48Au, 0xA2u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF48Cu, 0x000FA463u, 2u);
        }

        case 0x000FA463u: {
            TP_STATIC_GUARD(0x01F48Cu, 0xB7u, 0x64u);
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
            cpu->pbr = 0x01u;
            cpu->pc = 0xF48Eu;
            if (tp_scpu_expect_next(cpu, 0x000FA473u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x000FA473u: {
            TP_STATIC_GUARD(0x01F48Eu, 0x9Fu, 0x15u, 0x07u, 0x00u);
            const uint32_t address = (0x000715u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF492u, 0x000FA493u, 5u);
        }

        case 0x000FA493u: {
            TP_STATIC_GUARD(0x01F492u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF498u;
                if (tp_scpu_expect_next(cpu, 0x000FA4C3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF494u, 0x000FA4A3u, 2u);
        }

        case 0x000FA4A3u: {
            TP_STATIC_GUARD(0x01F494u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF495u, 0x000FA4ABu, 2u);
        }

        case 0x000FA4ABu: {
            TP_STATIC_GUARD(0x01F495u, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF496u, 0x000FA4B3u, 2u);
        }

        case 0x000FA4B3u: {
            TP_STATIC_GUARD(0x01F496u, 0x80u, 0xF4u);
            TP_STATIC_EXIT(0x01u, 0xF48Cu, 0x000FA463u, 3u);
        }

        case 0x000FA4C3u: {
            TP_STATIC_GUARD(0x01F498u, 0x22u, 0x3Fu, 0x98u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x9Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x983Fu, 0x0004C1FBu, 8u);
        }

        case 0x000FA4E0u: {
            TP_STATIC_GUARD(0x01F49Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xF49Eu, 0x000FA4F0u, 3u);
        }

        case 0x000FA4F0u: {
            TP_STATIC_GUARD(0x01F49Eu, 0xA0u, 0x14u, 0x01u);
            const uint16_t value = 0x0114u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF4A1u, 0x000FA508u, 3u);
        }

        case 0x000FA508u: {
            TP_STATIC_GUARD(0x01F4A1u, 0xB7u, 0x16u);
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
            cpu->pbr = 0x01u;
            cpu->pc = 0xF4A3u;
            if (tp_scpu_expect_next(cpu, 0x000FA518u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x000FA518u: {
            TP_STATIC_GUARD(0x01F4A3u, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF4A6u, 0x000FA530u, 5u);
        }

        case 0x000FA530u: {
            TP_STATIC_GUARD(0x01F4A6u, 0xAEu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF4A9u, 0x000FA548u, 5u);
        }

        case 0x000FA548u: {
            TP_STATIC_GUARD(0x01F4A9u, 0x8Eu, 0x94u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0794u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF4ACu, 0x000FA560u, 5u);
        }

        case 0x000FA560u: {
            TP_STATIC_GUARD(0x01F4ACu, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF4AFu, 0x000FA578u, 3u);
        }

        case 0x000FA578u: {
            TP_STATIC_GUARD(0x01F4AFu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF4B2u, 0x000FA590u, 5u);
        }

        case 0x000FA590u: {
            TP_STATIC_GUARD(0x01F4B2u, 0xA9u, 0x0Bu, 0x00u);
            const uint16_t value = 0x000Bu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF4B5u, 0x000FA5A8u, 3u);
        }

        case 0x000FA5A8u: {
            TP_STATIC_GUARD(0x01F4B5u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF4B8u, 0x000FA5C0u, 5u);
        }

        case 0x000FA5C0u: {
            TP_STATIC_GUARD(0x01F4B8u, 0xA9u, 0x20u, 0x00u);
            const uint16_t value = 0x0020u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF4BBu, 0x000FA5D8u, 3u);
        }

        case 0x000FA5D8u: {
            TP_STATIC_GUARD(0x01F4BBu, 0x8Du, 0x96u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0796u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF4BEu, 0x000FA5F0u, 5u);
        }

        case 0x000FA5F0u: {
            TP_STATIC_GUARD(0x01F4BEu, 0x22u, 0xAFu, 0xDDu, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDDAFu, 0x000EED78u, 8u);
        }

        case 0x000FA611u: {
            TP_STATIC_GUARD(0x01F4C2u, 0x22u, 0x3Cu, 0xA3u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC5u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA33Cu, 0x003519E1u, 8u);
        }

        case 0x000FA630u: {
            TP_STATIC_GUARD(0x01F4C6u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xF4C8u, 0x000FA640u, 3u);
        }

        case 0x000FA640u: {
            TP_STATIC_GUARD(0x01F4C8u, 0xA9u, 0x00u, 0x30u);
            const uint16_t value = 0x3000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF4CBu, 0x000FA658u, 3u);
        }

        case 0x000FA658u: {
            TP_STATIC_GUARD(0x01F4CBu, 0x8Du, 0x96u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0796u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF4CEu, 0x000FA670u, 5u);
        }

        case 0x000FA670u: {
            TP_STATIC_GUARD(0x01F4CEu, 0x22u, 0x4Au, 0xA3u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xD1u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA34Au, 0x00351A50u, 8u);
        }

        case 0x000FA690u: {
            TP_STATIC_GUARD(0x01F4D2u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xF4D4u, 0x000FA6A0u, 3u);
        }

        case 0x000FA6A0u: {
            TP_STATIC_GUARD(0x01F4D4u, 0x9Cu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF4D7u, 0x000FA6B8u, 5u);
        }

        case 0x000FA6B8u: {
            TP_STATIC_GUARD(0x01F4D7u, 0xA0u, 0x16u, 0x01u);
            const uint16_t value = 0x0116u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF4DAu, 0x000FA6D0u, 3u);
        }

        case 0x000FA6D0u: {
            TP_STATIC_GUARD(0x01F4DAu, 0xB7u, 0x16u);
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
            cpu->pbr = 0x01u;
            cpu->pc = 0xF4DCu;
            if (tp_scpu_expect_next(cpu, 0x000FA6E0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x000FA6E0u: {
            TP_STATIC_GUARD(0x01F4DCu, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF4DFu, 0x000FA6F8u, 5u);
        }

        case 0x000FA6F8u: {
            TP_STATIC_GUARD(0x01F4DFu, 0xAEu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF4E2u, 0x000FA710u, 5u);
        }

        case 0x000FA710u: {
            TP_STATIC_GUARD(0x01F4E2u, 0x8Eu, 0x94u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0794u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF4E5u, 0x000FA728u, 5u);
        }

        case 0x000FA728u: {
            TP_STATIC_GUARD(0x01F4E5u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF4E8u, 0x000FA740u, 3u);
        }

        case 0x000FA740u: {
            TP_STATIC_GUARD(0x01F4E8u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF4EBu, 0x000FA758u, 5u);
        }

        case 0x000FA758u: {
            TP_STATIC_GUARD(0x01F4EBu, 0xA9u, 0x0Eu, 0x00u);
            const uint16_t value = 0x000Eu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF4EEu, 0x000FA770u, 3u);
        }

        case 0x000FA770u: {
            TP_STATIC_GUARD(0x01F4EEu, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF4F1u, 0x000FA788u, 5u);
        }

        case 0x000FA788u: {
            TP_STATIC_GUARD(0x01F4F1u, 0xA9u, 0x20u, 0x00u);
            const uint16_t value = 0x0020u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF4F4u, 0x000FA7A0u, 3u);
        }

        case 0x000FA7A0u: {
            TP_STATIC_GUARD(0x01F4F4u, 0x8Du, 0x96u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0796u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF4F7u, 0x000FA7B8u, 5u);
        }

        case 0x000FA7B8u: {
            TP_STATIC_GUARD(0x01F4F7u, 0x22u, 0xAFu, 0xDDu, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xFAu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDDAFu, 0x000EED78u, 8u);
        }

        case 0x000FA7D9u: {
            TP_STATIC_GUARD(0x01F4FBu, 0x22u, 0x3Cu, 0xA3u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xFEu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA33Cu, 0x003519E1u, 8u);
        }

        case 0x000FA7F8u: {
            TP_STATIC_GUARD(0x01F4FFu, 0x22u, 0xFBu, 0xF1u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x02u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xF1FBu, 0x00678FD8u, 8u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
