/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0004ED(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00276808u: {
            TP_STATIC_GUARD(0x04ED01u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xED02u, 0x00276810u, 3u);
        }

        case 0x00276810u: {
            TP_STATIC_GUARD(0x04ED02u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xED03u, 0x00276818u, 2u);
        }

        case 0x00276818u: {
            TP_STATIC_GUARD(0x04ED03u, 0xADu, 0x62u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F62u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xED06u, 0x00276830u, 5u);
        }

        case 0x00276830u: {
            TP_STATIC_GUARD(0x04ED06u, 0x9Du, 0x07u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1907u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED09u, 0x00276848u, 6u);
        }

        case 0x00276848u: {
            TP_STATIC_GUARD(0x04ED09u, 0x6Bu);
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
                case 0x00270DE8u:
                case 0x00270EE0u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00276850u: {
            TP_STATIC_GUARD(0x04ED0Au, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xED0Cu, 0x00276863u, 3u);
        }

        case 0x00276851u: {
            TP_STATIC_GUARD(0x04ED0Au, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xED0Cu, 0x00276863u, 3u);
        }

        case 0x00276852u: {
            TP_STATIC_GUARD(0x04ED0Au, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xED0Cu, 0x00276863u, 3u);
        }

        case 0x00276853u: {
            TP_STATIC_GUARD(0x04ED0Au, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xED0Cu, 0x00276863u, 3u);
        }

        case 0x00276863u: {
            TP_STATIC_GUARD(0x04ED0Cu, 0x8Du, 0x8Cu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Fu, 0x0027687Bu, 4u);
        }

        case 0x0027687Bu: {
            TP_STATIC_GUARD(0x04ED0Fu, 0x22u, 0x49u, 0x87u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEDu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x12u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8749u, 0x00643A4Bu, 8u);
        }

        case 0x0027689Bu: {
            TP_STATIC_GUARD(0x04ED13u, 0x6Bu);
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
                case 0x00043F73u:
                case 0x00059E1Bu:
                case 0x0005B08Bu:
                case 0x0005B7B3u:
                case 0x0005CC4Bu:
                case 0x0005DDC3u:
                case 0x0005F613u:
                case 0x0005FD53u:
                case 0x0007BCA3u:
                case 0x0007C053u:
                case 0x0007DB53u:
                case 0x0007E183u:
                case 0x002411E3u:
                case 0x0026848Bu:
                case 0x0026F4EBu:
                case 0x0026F89Bu:
                case 0x0026F9DBu:
                case 0x00271F6Bu:
                case 0x002720CBu:
                case 0x002729A3u:
                case 0x00272C53u:
                case 0x00273043u:
                case 0x002734DBu:
                case 0x00273DDBu:
                case 0x00273FFBu:
                case 0x00274283u:
                case 0x00274553u:
                case 0x00274733u:
                case 0x002747DBu:
                case 0x003568DBu:
                case 0x00356B5Bu:
                case 0x00356DDBu:
                case 0x00356F6Bu:
                case 0x0035720Bu:
                case 0x00357483u:
                case 0x003576FBu:
                case 0x0035788Bu:
                case 0x0035883Bu:
                case 0x003589FBu:
                case 0x00358CBBu:
                case 0x00358F43u:
                case 0x00359203u:
                case 0x0035948Bu:
                case 0x00359763u:
                case 0x00359A03u:
                case 0x00359E5Bu:
                case 0x0035A293u:
                case 0x0035A403u:
                case 0x0035A47Bu:
                case 0x0035A65Bu:
                case 0x0035A6D3u:
                case 0x0035A8B3u:
                case 0x0035A92Bu:
                case 0x0035AB0Bu:
                case 0x0035AB83u:
                case 0x0035AD63u:
                case 0x0035ADDBu:
                case 0x0035AFBBu:
                case 0x0035B033u:
                case 0x0035B213u:
                case 0x0035B28Bu:
                case 0x0035B5B3u:
                case 0x0035B6CBu:
                case 0x0035B98Bu:
                case 0x0035BABBu:
                case 0x003C9EDBu:
                case 0x003CB843u:
                case 0x003CC8E3u:
                case 0x003CE963u:
                case 0x003CECBBu:
                case 0x003CEE3Bu:
                case 0x003CF7FBu:
                case 0x00650633u:
                case 0x00659C3Bu:
                case 0x0067D153u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x002768A0u: {
            TP_STATIC_GUARD(0x04ED14u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xED16u, 0x002768B3u, 3u);
        }

        case 0x002768A2u: {
            TP_STATIC_GUARD(0x04ED14u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xED16u, 0x002768B3u, 3u);
        }

        case 0x002768A3u: {
            TP_STATIC_GUARD(0x04ED14u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xED16u, 0x002768B3u, 3u);
        }

        case 0x002768B3u: {
            TP_STATIC_GUARD(0x04ED16u, 0x8Du, 0x8Cu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED19u, 0x002768CBu, 4u);
        }

        case 0x002768CBu: {
            TP_STATIC_GUARD(0x04ED19u, 0x22u, 0x49u, 0x87u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEDu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x1Cu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8749u, 0x00643A4Bu, 8u);
        }

        case 0x002768EBu: {
            TP_STATIC_GUARD(0x04ED1Du, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xED1Fu, 0x002768FBu, 3u);
        }

        case 0x002768FBu: {
            TP_STATIC_GUARD(0x04ED1Fu, 0x9Cu, 0x4Fu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x074Fu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED22u, 0x00276913u, 4u);
        }

        case 0x00276913u: {
            TP_STATIC_GUARD(0x04ED22u, 0xADu, 0x4Fu, 0x07u);
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
            TP_STATIC_EXIT(0x04u, 0xED25u, 0x0027692Bu, 4u);
        }

        case 0x0027692Bu: {
            TP_STATIC_GUARD(0x04ED25u, 0xC9u, 0x05u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x05u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xED27u, 0x0027693Bu, 2u);
        }

        case 0x0027693Bu: {
            TP_STATIC_GUARD(0x04ED27u, 0x90u, 0xF9u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xED22u;
                if (tp_scpu_expect_next(cpu, 0x00276913u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xED29u, 0x0027694Bu, 2u);
        }

        case 0x0027694Bu: {
            TP_STATIC_GUARD(0x04ED29u, 0x6Bu);
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
                case 0x0007960Bu:
                case 0x0007FC13u:
                case 0x000EE843u:
                case 0x000EE9EBu:
                case 0x00251A3Bu:
                case 0x0026F72Bu:
                case 0x0026F78Bu:
                case 0x002721A3u:
                case 0x002723A3u:
                case 0x002725A3u:
                case 0x002727A3u:
                case 0x0027396Bu:
                case 0x00273A13u:
                case 0x002754B3u:
                case 0x00276993u:
                case 0x002C04CBu:
                case 0x002C052Bu:
                case 0x003562DBu:
                case 0x003579B3u:
                case 0x003585A3u:
                case 0x0035B7EBu:
                case 0x0035BBB3u:
                case 0x003CB983u:
                case 0x003CB9F3u:
                case 0x00648573u:
                case 0x00669D73u:
                case 0x0077ACFBu:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00276950u: {
            TP_STATIC_GUARD(0x04ED2Au, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xED2Cu, 0x00276963u, 3u);
        }

        case 0x00276952u: {
            TP_STATIC_GUARD(0x04ED2Au, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xED2Cu, 0x00276963u, 3u);
        }

        case 0x00276953u: {
            TP_STATIC_GUARD(0x04ED2Au, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xED2Cu, 0x00276963u, 3u);
        }

        case 0x00276963u: {
            TP_STATIC_GUARD(0x04ED2Cu, 0xA9u, 0x0Du);
            const uint8_t value = 0x0Du;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xED2Eu, 0x00276973u, 2u);
        }

        case 0x00276973u: {
            TP_STATIC_GUARD(0x04ED2Eu, 0x22u, 0x14u, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEDu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x31u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED14u, 0x002768A3u, 8u);
        }

        case 0x00276993u: {
            TP_STATIC_GUARD(0x04ED32u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xED34u, 0x002769A0u, 3u);
        }

        case 0x002769A0u: {
            TP_STATIC_GUARD(0x04ED34u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xED37u, 0x002769B8u, 3u);
        }

        case 0x002769B8u: {
            TP_STATIC_GUARD(0x04ED37u, 0x6Bu);
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
                case 0x00079958u:
                case 0x0007A4E0u:
                case 0x0007FC40u:
                case 0x00241DE0u:
                case 0x00242668u:
                case 0x00250178u:
                case 0x002509A0u:
                case 0x002684B8u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
