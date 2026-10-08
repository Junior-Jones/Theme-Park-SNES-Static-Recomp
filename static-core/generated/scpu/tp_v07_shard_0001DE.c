/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0001DE(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x000EF011u: {
            TP_STATIC_GUARD(0x01DE02u, 0x6Bu);
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
                case 0x000EDB71u:
                case 0x000EE4D9u:
                case 0x000F0439u:
                case 0x000F1669u:
                case 0x000F3CA9u:
                case 0x000F4AE9u:
                case 0x000F5031u:
                case 0x000F5B21u:
                case 0x000F5D21u:
                case 0x000F62B1u:
                case 0x000F6CC9u:
                case 0x000F6F99u:
                case 0x000F7219u:
                case 0x000F80E1u:
                case 0x000F8FA1u:
                case 0x000F91A1u:
                case 0x000F97E9u:
                case 0x000FA1E9u:
                case 0x000FA611u:
                case 0x000FA7D9u:
                case 0x000FAD19u:
                case 0x000FAFC1u:
                case 0x000FB201u:
                case 0x000FB819u:
                case 0x0034D8C9u:
                case 0x0034DCE9u:
                case 0x0034E009u:
                case 0x0034E379u:
                case 0x0034E931u:
                case 0x0034EC81u:
                case 0x0034F079u:
                case 0x0034F3E9u:
                case 0x0034F6F1u:
                case 0x0034F9F9u:
                case 0x0034FD31u:
                case 0x00350041u:
                case 0x00350351u:
                case 0x00350599u:
                case 0x00350CD9u:
                case 0x00350F29u:
                case 0x003514E9u:
                case 0x0035DF61u:
                case 0x0035E239u:
                case 0x0037D809u:
                case 0x0037DEA9u:
                case 0x00645C79u:
                case 0x0066C0A1u:
                case 0x0066C2B1u:
                case 0x0066F451u:
                case 0x0066F5C1u:
                case 0x0066F731u:
                case 0x0066FB31u:
                case 0x0066FDB9u:
                case 0x0066FF41u:
                case 0x006701C9u:
                case 0x00670BA1u:
                case 0x00671891u:
                case 0x00671A89u:
                case 0x00671C81u:
                case 0x00671E79u:
                case 0x006755A1u:
                case 0x006756F1u:
                case 0x00675841u:
                case 0x006763B1u:
                case 0x00676619u:
                case 0x00676881u:
                case 0x00676C31u:
                case 0x00677239u:
                case 0x00677499u:
                case 0x00677721u:
                case 0x00677B61u:
                case 0x00677CF1u:
                case 0x00677E81u:
                case 0x00678959u:
                case 0x00678C21u:
                case 0x00678DF1u:
                case 0x00678FB1u:
                case 0x0067CD19u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x000EF01Au: {
            TP_STATIC_GUARD(0x01DE03u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xDE05u, 0x000EF028u, 3u);
        }

        case 0x000EF01Bu: {
            TP_STATIC_GUARD(0x01DE03u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xDE05u, 0x000EF028u, 3u);
        }

        case 0x000EF028u: {
            TP_STATIC_GUARD(0x01DE05u, 0xADu, 0x0Bu, 0x04u);
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
            TP_STATIC_EXIT(0x01u, 0xDE08u, 0x000EF040u, 5u);
        }

        case 0x000EF040u: {
            TP_STATIC_GUARD(0x01DE08u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE09u, 0x000EF048u, 4u);
        }

        case 0x000EF048u: {
            TP_STATIC_GUARD(0x01DE09u, 0xADu, 0x0Du, 0x04u);
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
            TP_STATIC_EXIT(0x01u, 0xDE0Cu, 0x000EF060u, 5u);
        }

        case 0x000EF060u: {
            TP_STATIC_GUARD(0x01DE0Cu, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE0Du, 0x000EF068u, 4u);
        }

        case 0x000EF068u: {
            TP_STATIC_GUARD(0x01DE0Du, 0xADu, 0x0Fu, 0x04u);
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
            TP_STATIC_EXIT(0x01u, 0xDE10u, 0x000EF080u, 5u);
        }

        case 0x000EF080u: {
            TP_STATIC_GUARD(0x01DE10u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE11u, 0x000EF088u, 4u);
        }

        case 0x000EF088u: {
            TP_STATIC_GUARD(0x01DE11u, 0xADu, 0x11u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0411u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE14u, 0x000EF0A0u, 5u);
        }

        case 0x000EF0A0u: {
            TP_STATIC_GUARD(0x01DE14u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE15u, 0x000EF0A8u, 4u);
        }

        case 0x000EF0A8u: {
            TP_STATIC_GUARD(0x01DE15u, 0xADu, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0413u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE18u, 0x000EF0C0u, 5u);
        }

        case 0x000EF0C0u: {
            TP_STATIC_GUARD(0x01DE18u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE19u, 0x000EF0C8u, 4u);
        }

        case 0x000EF0C8u: {
            TP_STATIC_GUARD(0x01DE19u, 0xADu, 0x15u, 0x04u);
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
            TP_STATIC_EXIT(0x01u, 0xDE1Cu, 0x000EF0E0u, 5u);
        }

        case 0x000EF0E0u: {
            TP_STATIC_GUARD(0x01DE1Cu, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE1Du, 0x000EF0E8u, 4u);
        }

        case 0x000EF0E8u: {
            TP_STATIC_GUARD(0x01DE1Du, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xDE1Fu, 0x000EF0F9u, 3u);
        }

        case 0x000EF0F9u: {
            TP_STATIC_GUARD(0x01DE1Fu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x01u, 0xDE21u, 0x000EF109u, 3u);
        }

        case 0x000EF109u: {
            TP_STATIC_GUARD(0x01DE21u, 0xADu, 0x16u, 0x00u);
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
            TP_STATIC_EXIT(0x01u, 0xDE24u, 0x000EF121u, 5u);
        }

        case 0x000EF121u: {
            TP_STATIC_GUARD(0x01DE24u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE25u, 0x000EF129u, 4u);
        }

        case 0x000EF129u: {
            TP_STATIC_GUARD(0x01DE25u, 0xAEu, 0x18u, 0x00u);
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
            TP_STATIC_EXIT(0x01u, 0xDE28u, 0x000EF141u, 4u);
        }

        case 0x000EF141u: {
            TP_STATIC_GUARD(0x01DE28u, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE29u, 0x000EF149u, 3u);
        }

        case 0x000EF149u: {
            TP_STATIC_GUARD(0x01DE29u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xDE2Bu, 0x000EF159u, 3u);
        }

        case 0x000EF159u: {
            TP_STATIC_GUARD(0x01DE2Bu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x01u, 0xDE2Du, 0x000EF169u, 3u);
        }

        case 0x000EF169u: {
            TP_STATIC_GUARD(0x01DE2Du, 0xADu, 0xD2u, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06D2u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE30u, 0x000EF181u, 5u);
        }

        case 0x000EF181u: {
            TP_STATIC_GUARD(0x01DE30u, 0x8Du, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0016u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE33u, 0x000EF199u, 5u);
        }

        case 0x000EF199u: {
            TP_STATIC_GUARD(0x01DE33u, 0xAEu, 0xD4u, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06D4u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE36u, 0x000EF1B1u, 4u);
        }

        case 0x000EF1B1u: {
            TP_STATIC_GUARD(0x01DE36u, 0x8Eu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE39u, 0x000EF1C9u, 4u);
        }

        case 0x000EF1C9u: {
            TP_STATIC_GUARD(0x01DE39u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xDE3Bu, 0x000EF1D8u, 3u);
        }

        case 0x000EF1D8u: {
            TP_STATIC_GUARD(0x01DE3Bu, 0x9Cu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0415u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE3Eu, 0x000EF1F0u, 5u);
        }

        case 0x000EF1F0u: {
            TP_STATIC_GUARD(0x01DE3Eu, 0x9Cu, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0413u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE41u, 0x000EF208u, 5u);
        }

        case 0x000EF208u: {
            TP_STATIC_GUARD(0x01DE41u, 0xA9u, 0x77u, 0x00u);
            const uint16_t value = 0x0077u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE44u, 0x000EF220u, 3u);
        }

        case 0x000EF220u: {
            TP_STATIC_GUARD(0x01DE44u, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE47u, 0x000EF238u, 5u);
        }

        case 0x000EF238u: {
            TP_STATIC_GUARD(0x01DE47u, 0xA9u, 0x27u, 0x00u);
            const uint16_t value = 0x0027u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE4Au, 0x000EF250u, 3u);
        }

        case 0x000EF250u: {
            TP_STATIC_GUARD(0x01DE4Au, 0x8Du, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE4Du, 0x000EF268u, 5u);
        }

        case 0x000EF268u: {
            TP_STATIC_GUARD(0x01DE4Du, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x50u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C0u, 8u);
        }

        case 0x000EF28Bu: {
            TP_STATIC_GUARD(0x01DE51u, 0x22u, 0x83u, 0xE1u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x54u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xE183u, 0x00670C1Bu, 8u);
        }

        case 0x000EF2AAu: {
            TP_STATIC_GUARD(0x01DE55u, 0x22u, 0xC8u, 0x82u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x58u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x82C8u, 0x003C1642u, 8u);
        }

        case 0x000EF2C8u: {
            TP_STATIC_GUARD(0x01DE59u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xDE5Bu, 0x000EF2DBu, 3u);
        }

        case 0x000EF2DBu: {
            TP_STATIC_GUARD(0x01DE5Bu, 0xA9u, 0xF0u);
            const uint8_t value = 0xF0u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE5Du, 0x000EF2EBu, 2u);
        }

        case 0x000EF2EBu: {
            TP_STATIC_GUARD(0x01DE5Du, 0x8Du, 0x30u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0430u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE60u, 0x000EF303u, 4u);
        }

        case 0x000EF303u: {
            TP_STATIC_GUARD(0x01DE60u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xDE62u, 0x000EF310u, 3u);
        }

        case 0x000EF310u: {
            TP_STATIC_GUARD(0x01DE62u, 0xA2u, 0xFCu, 0x01u);
            const uint16_t value = 0x01FCu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE65u, 0x000EF328u, 3u);
        }

        case 0x000EF328u: {
            TP_STATIC_GUARD(0x01DE65u, 0xA0u, 0x7Fu, 0x00u);
            const uint16_t value = 0x007Fu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE68u, 0x000EF340u, 3u);
        }

        case 0x000EF340u: {
            TP_STATIC_GUARD(0x01DE68u, 0xA9u, 0x00u, 0xF0u);
            const uint16_t value = 0xF000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE6Bu, 0x000EF358u, 3u);
        }

        case 0x000EF358u: {
            TP_STATIC_GUARD(0x01DE6Bu, 0x9Du, 0x2Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x042Fu + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE6Eu, 0x000EF370u, 6u);
        }

        case 0x000EF370u: {
            TP_STATIC_GUARD(0x01DE6Eu, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE6Fu, 0x000EF378u, 2u);
        }

        case 0x000EF378u: {
            TP_STATIC_GUARD(0x01DE6Fu, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE70u, 0x000EF380u, 2u);
        }

        case 0x000EF380u: {
            TP_STATIC_GUARD(0x01DE70u, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE71u, 0x000EF388u, 2u);
        }

        case 0x000EF388u: {
            TP_STATIC_GUARD(0x01DE71u, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE72u, 0x000EF390u, 2u);
        }

        case 0x000EF390u: {
            TP_STATIC_GUARD(0x01DE72u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE73u, 0x000EF398u, 2u);
        }

        case 0x000EF398u: {
            TP_STATIC_GUARD(0x01DE73u, 0xD0u, 0xF3u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xDE68u;
                if (tp_scpu_expect_next(cpu, 0x000EF340u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xDE75u, 0x000EF3A8u, 2u);
        }

        case 0x000EF3A8u: {
            TP_STATIC_GUARD(0x01DE75u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xDE77u, 0x000EF3B8u, 3u);
        }

        case 0x000EF3B8u: {
            TP_STATIC_GUARD(0x01DE77u, 0xA9u, 0x77u, 0x27u);
            const uint16_t value = 0x2777u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE7Au, 0x000EF3D0u, 3u);
        }

        case 0x000EF3D0u: {
            TP_STATIC_GUARD(0x01DE7Au, 0x8Du, 0x2Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x042Fu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE7Du, 0x000EF3E8u, 5u);
        }

        case 0x000EF3E8u: {
            TP_STATIC_GUARD(0x01DE7Du, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xDE7Fu, 0x000EF3FBu, 3u);
        }

        case 0x000EF3FBu: {
            TP_STATIC_GUARD(0x01DE7Fu, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE81u, 0x000EF40Bu, 2u);
        }

        case 0x000EF40Bu: {
            TP_STATIC_GUARD(0x01DE81u, 0x8Du, 0x4Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x074Du) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE84u, 0x000EF423u, 4u);
        }

        case 0x000EF423u: {
            TP_STATIC_GUARD(0x01DE84u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xDE86u, 0x000EF433u, 3u);
        }

        case 0x000EF433u: {
            TP_STATIC_GUARD(0x01DE86u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x01u, 0xDE88u, 0x000EF441u, 3u);
        }

        case 0x000EF441u: {
            TP_STATIC_GUARD(0x01DE88u, 0xA9u, 0x20u, 0xAFu);
            const uint16_t value = 0xAF20u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE8Bu, 0x000EF459u, 3u);
        }

        case 0x000EF459u: {
            TP_STATIC_GUARD(0x01DE8Bu, 0xA2u, 0x1Au);
            const uint8_t value = 0x1Au;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE8Du, 0x000EF469u, 2u);
        }

        case 0x000EF469u: {
            TP_STATIC_GUARD(0x01DE8Du, 0x22u, 0x68u, 0x82u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x90u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8268u, 0x003C1341u, 8u);
        }

        case 0x000EF489u: {
            TP_STATIC_GUARD(0x01DE91u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xDE93u, 0x000EF499u, 3u);
        }

        case 0x000EF499u: {
            TP_STATIC_GUARD(0x01DE93u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x01u, 0xDE95u, 0x000EF4A9u, 3u);
        }

        case 0x000EF4A9u: {
            TP_STATIC_GUARD(0x01DE95u, 0xA9u, 0xC0u, 0xBCu);
            const uint16_t value = 0xBCC0u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE98u, 0x000EF4C1u, 3u);
        }

        case 0x000EF4C1u: {
            TP_STATIC_GUARD(0x01DE98u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDE9Bu, 0x000EF4D9u, 5u);
        }

        case 0x000EF4D9u: {
            TP_STATIC_GUARD(0x01DE9Bu, 0xA2u, 0x19u);
            const uint8_t value = 0x19u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDE9Du, 0x000EF4E9u, 2u);
        }

        case 0x000EF4E9u: {
            TP_STATIC_GUARD(0x01DE9Du, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDEA0u, 0x000EF501u, 4u);
        }

        case 0x000EF501u: {
            TP_STATIC_GUARD(0x01DEA0u, 0xA9u, 0xC0u, 0xB5u);
            const uint16_t value = 0xB5C0u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDEA3u, 0x000EF519u, 3u);
        }

        case 0x000EF519u: {
            TP_STATIC_GUARD(0x01DEA3u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDEA6u, 0x000EF531u, 5u);
        }

        case 0x000EF531u: {
            TP_STATIC_GUARD(0x01DEA6u, 0xA2u, 0x19u);
            const uint8_t value = 0x19u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDEA8u, 0x000EF541u, 2u);
        }

        case 0x000EF541u: {
            TP_STATIC_GUARD(0x01DEA8u, 0x8Eu, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0790u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDEABu, 0x000EF559u, 4u);
        }

        case 0x000EF559u: {
            TP_STATIC_GUARD(0x01DEABu, 0x22u, 0xFCu, 0xE1u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xAEu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xE1FCu, 0x00670FE1u, 8u);
        }

        case 0x000EF579u: {
            TP_STATIC_GUARD(0x01DEAFu, 0x22u, 0x70u, 0xE1u, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB2u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE170u, 0x000F0B81u, 8u);
        }

        case 0x000EF598u: {
            TP_STATIC_GUARD(0x01DEB3u, 0x22u, 0xF0u, 0xE8u, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB6u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE8F0u, 0x000F4780u, 8u);
        }

        case 0x000EF5B8u: {
            TP_STATIC_GUARD(0x01DEB7u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xDEB9u, 0x000EF5CBu, 3u);
        }

        case 0x000EF5CBu: {
            TP_STATIC_GUARD(0x01DEB9u, 0xADu, 0x4Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x074Au;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDEBCu, 0x000EF5E3u, 4u);
        }

        case 0x000EF5E3u: {
            TP_STATIC_GUARD(0x01DEBCu, 0xD0u, 0xFBu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xDEB9u;
                if (tp_scpu_expect_next(cpu, 0x000EF5CBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xDEBEu, 0x000EF5F3u, 2u);
        }

        case 0x000EF5F3u: {
            TP_STATIC_GUARD(0x01DEBEu, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDEC0u, 0x000EF603u, 2u);
        }

        case 0x000EF603u: {
            TP_STATIC_GUARD(0x01DEC0u, 0x8Du, 0x4Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x074Au) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDEC3u, 0x000EF61Bu, 4u);
        }

        case 0x000EF61Bu: {
            TP_STATIC_GUARD(0x01DEC3u, 0x22u, 0x42u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC6u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8542u, 0x00642A13u, 8u);
        }

        case 0x000EF63Bu: {
            TP_STATIC_GUARD(0x01DEC7u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xDEC9u, 0x000EF64Bu, 3u);
        }

        case 0x000EF64Bu: {
            TP_STATIC_GUARD(0x01DEC9u, 0x9Cu, 0x4Fu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x074Fu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDECCu, 0x000EF663u, 4u);
        }

        case 0x000EF663u: {
            TP_STATIC_GUARD(0x01DECCu, 0xADu, 0x4Fu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x074Fu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDECFu, 0x000EF67Bu, 4u);
        }

        case 0x000EF67Bu: {
            TP_STATIC_GUARD(0x01DECFu, 0xF0u, 0xFBu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xDECCu;
                if (tp_scpu_expect_next(cpu, 0x000EF663u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xDED1u, 0x000EF68Bu, 2u);
        }

        case 0x000EF68Bu: {
            TP_STATIC_GUARD(0x01DED1u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xDED3u, 0x000EF698u, 3u);
        }

        case 0x000EF698u: {
            TP_STATIC_GUARD(0x01DED3u, 0xAEu, 0x44u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0744u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDED6u, 0x000EF6B0u, 5u);
        }

        case 0x000EF6B0u: {
            TP_STATIC_GUARD(0x01DED6u, 0x8Eu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0746u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDED9u, 0x000EF6C8u, 5u);
        }

        case 0x000EF6C8u: {
            TP_STATIC_GUARD(0x01DED9u, 0x22u, 0x98u, 0x9Du, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDCu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9D98u, 0x0064ECC0u, 8u);
        }

        case 0x000EF6EBu: {
            TP_STATIC_GUARD(0x01DEDDu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xDEDFu, 0x000EF6F8u, 3u);
        }

        case 0x000EF6F8u: {
            TP_STATIC_GUARD(0x01DEDFu, 0xADu, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0413u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDEE2u, 0x000EF710u, 5u);
        }

        case 0x000EF710u: {
            TP_STATIC_GUARD(0x01DEE2u, 0xF0u, 0x5Bu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xDF3Fu;
                if (tp_scpu_expect_next(cpu, 0x000EF9F8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xDEE4u, 0x000EF720u, 2u);
        }

        case 0x000EF720u: {
            TP_STATIC_GUARD(0x01DEE4u, 0xADu, 0x0Bu, 0x04u);
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
            TP_STATIC_EXIT(0x01u, 0xDEE7u, 0x000EF738u, 5u);
        }

        case 0x000EF738u: {
            TP_STATIC_GUARD(0x01DEE7u, 0xCDu, 0x0Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDEEAu, 0x000EF750u, 5u);
        }

        case 0x000EF750u: {
            TP_STATIC_GUARD(0x01DEEAu, 0xF0u, 0x17u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xDF03u;
                if (tp_scpu_expect_next(cpu, 0x000EF818u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xDEECu, 0x000EF760u, 2u);
        }

        case 0x000EF760u: {
            TP_STATIC_GUARD(0x01DEECu, 0xB0u, 0x05u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xDEF3u;
                if (tp_scpu_expect_next(cpu, 0x000EF798u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xDEEEu, 0x000EF770u, 2u);
        }

        case 0x000EF770u: {
            TP_STATIC_GUARD(0x01DEEEu, 0xA9u, 0x04u, 0x00u);
            const uint16_t value = 0x0004u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDEF1u, 0x000EF788u, 3u);
        }

        case 0x000EF788u: {
            TP_STATIC_GUARD(0x01DEF1u, 0x80u, 0x03u);
            TP_STATIC_EXIT(0x01u, 0xDEF6u, 0x000EF7B0u, 3u);
        }

        case 0x000EF798u: {
            TP_STATIC_GUARD(0x01DEF3u, 0xA9u, 0xFCu, 0xFFu);
            const uint16_t value = 0xFFFCu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xDEF6u, 0x000EF7B0u, 3u);
        }

        case 0x000EF7B0u: {
            TP_STATIC_GUARD(0x01DEF6u, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDEF9u, 0x000EF7C8u, 5u);
        }

        case 0x000EF7C8u: {
            TP_STATIC_GUARD(0x01DEF9u, 0xADu, 0x0Bu, 0x04u);
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
            TP_STATIC_EXIT(0x01u, 0xDEFCu, 0x000EF7E0u, 5u);
        }

        case 0x000EF7E0u: {
            TP_STATIC_GUARD(0x01DEFCu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xDEFDu, 0x000EF7E8u, 2u);
        }

        case 0x000EF7E8u: {
            TP_STATIC_GUARD(0x01DEFDu, 0x6Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0064u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDF00u, 0x000EF800u, 5u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
