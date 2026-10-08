/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0004E4(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00272000u: {
            TP_STATIC_GUARD(0x04E400u, 0xB9u, 0x24u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0824u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE403u, 0x00272018u, 6u);
        }

        case 0x00272018u: {
            TP_STATIC_GUARD(0x04E403u, 0x8Du, 0x0Au, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x080Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE406u, 0x00272030u, 5u);
        }

        case 0x00272030u: {
            TP_STATIC_GUARD(0x04E406u, 0x82u, 0x7Bu, 0x07u);
            TP_STATIC_EXIT(0x04u, 0xEB84u, 0x00275C20u, 4u);
        }

        case 0x00272048u: {
            TP_STATIC_GUARD(0x04E409u, 0xC9u, 0x05u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0005u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE40Cu, 0x00272060u, 3u);
        }

        case 0x00272060u: {
            TP_STATIC_GUARD(0x04E40Cu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE411u;
                if (tp_scpu_expect_next(cpu, 0x00272088u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE40Eu, 0x00272070u, 2u);
        }

        case 0x00272070u: {
            TP_STATIC_GUARD(0x04E40Eu, 0x82u, 0x13u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE424u, 0x00272120u, 4u);
        }

        case 0x00272088u: {
            TP_STATIC_GUARD(0x04E411u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE413u, 0x0027209Bu, 3u);
        }

        case 0x0027209Bu: {
            TP_STATIC_GUARD(0x04E413u, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE415u, 0x002720ABu, 2u);
        }

        case 0x002720ABu: {
            TP_STATIC_GUARD(0x04E415u, 0x22u, 0x0Au, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x18u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Au, 0x00276853u, 8u);
        }

        case 0x002720CBu: {
            TP_STATIC_GUARD(0x04E419u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE41Bu, 0x002720D8u, 3u);
        }

        case 0x002720D8u: {
            TP_STATIC_GUARD(0x04E41Bu, 0xA9u, 0x03u, 0x00u);
            const uint16_t value = 0x0003u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE41Eu, 0x002720F0u, 3u);
        }

        case 0x002720F0u: {
            TP_STATIC_GUARD(0x04E41Eu, 0x8Du, 0x0Au, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x080Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE421u, 0x00272108u, 5u);
        }

        case 0x00272108u: {
            TP_STATIC_GUARD(0x04E421u, 0x82u, 0x60u, 0x07u);
            TP_STATIC_EXIT(0x04u, 0xEB84u, 0x00275C20u, 4u);
        }

        case 0x00272120u: {
            TP_STATIC_GUARD(0x04E424u, 0xC9u, 0x06u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0006u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE427u, 0x00272138u, 3u);
        }

        case 0x00272138u: {
            TP_STATIC_GUARD(0x04E427u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE42Cu;
                if (tp_scpu_expect_next(cpu, 0x00272160u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE429u, 0x00272148u, 2u);
        }

        case 0x00272148u: {
            TP_STATIC_GUARD(0x04E429u, 0x82u, 0x38u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE464u, 0x00272320u, 4u);
        }

        case 0x00272160u: {
            TP_STATIC_GUARD(0x04E42Cu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE42Eu, 0x00272173u, 3u);
        }

        case 0x00272173u: {
            TP_STATIC_GUARD(0x04E42Eu, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE430u, 0x00272183u, 2u);
        }

        case 0x00272183u: {
            TP_STATIC_GUARD(0x04E430u, 0x22u, 0x14u, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x33u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED14u, 0x002768A3u, 8u);
        }

        case 0x002721A3u: {
            TP_STATIC_GUARD(0x04E434u, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x37u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C3u, 8u);
        }

        case 0x002721C3u: {
            TP_STATIC_GUARD(0x04E438u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE43Au, 0x002721D3u, 3u);
        }

        case 0x002721D3u: {
            TP_STATIC_GUARD(0x04E43Au, 0x9Cu, 0x6Cu, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1F6Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE43Du, 0x002721EBu, 4u);
        }

        case 0x002721EBu: {
            TP_STATIC_GUARD(0x04E43Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE43Fu, 0x002721F8u, 3u);
        }

        case 0x002721F8u: {
            TP_STATIC_GUARD(0x04E43Fu, 0xA9u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE442u, 0x00272210u, 3u);
        }

        case 0x00272210u: {
            TP_STATIC_GUARD(0x04E442u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE445u, 0x00272228u, 5u);
        }

        case 0x00272228u: {
            TP_STATIC_GUARD(0x04E445u, 0x22u, 0x28u, 0xBAu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x48u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBA28u, 0x0035D140u, 8u);
        }

        case 0x00272249u: {
            TP_STATIC_GUARD(0x04E449u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE44Bu, 0x00272258u, 3u);
        }

        case 0x00272258u: {
            TP_STATIC_GUARD(0x04E44Bu, 0xA9u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE44Eu, 0x00272270u, 3u);
        }

        case 0x00272270u: {
            TP_STATIC_GUARD(0x04E44Eu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE451u, 0x00272288u, 5u);
        }

        case 0x00272288u: {
            TP_STATIC_GUARD(0x04E451u, 0x22u, 0x18u, 0x85u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x54u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0x8518u, 0x003428C0u, 8u);
        }

        case 0x002722A8u: {
            TP_STATIC_GUARD(0x04E455u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE457u, 0x002722B8u, 3u);
        }

        case 0x002722B8u: {
            TP_STATIC_GUARD(0x04E457u, 0xA9u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE45Au, 0x002722D0u, 3u);
        }

        case 0x002722D0u: {
            TP_STATIC_GUARD(0x04E45Au, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE45Du, 0x002722E8u, 5u);
        }

        case 0x002722E8u: {
            TP_STATIC_GUARD(0x04E45Du, 0x22u, 0x33u, 0xD9u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x60u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xD933u, 0x0026C998u, 8u);
        }

        case 0x00272308u: {
            TP_STATIC_GUARD(0x04E461u, 0x82u, 0x36u, 0x07u);
            TP_STATIC_EXIT(0x04u, 0xEB9Au, 0x00275CD0u, 4u);
        }

        case 0x00272320u: {
            TP_STATIC_GUARD(0x04E464u, 0xC9u, 0x07u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0007u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE467u, 0x00272338u, 3u);
        }

        case 0x00272338u: {
            TP_STATIC_GUARD(0x04E467u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE46Cu;
                if (tp_scpu_expect_next(cpu, 0x00272360u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE469u, 0x00272348u, 2u);
        }

        case 0x00272348u: {
            TP_STATIC_GUARD(0x04E469u, 0x82u, 0x38u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE4A4u, 0x00272520u, 4u);
        }

        case 0x00272360u: {
            TP_STATIC_GUARD(0x04E46Cu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE46Eu, 0x00272373u, 3u);
        }

        case 0x00272373u: {
            TP_STATIC_GUARD(0x04E46Eu, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE470u, 0x00272383u, 2u);
        }

        case 0x00272383u: {
            TP_STATIC_GUARD(0x04E470u, 0x22u, 0x14u, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x73u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED14u, 0x002768A3u, 8u);
        }

        case 0x002723A3u: {
            TP_STATIC_GUARD(0x04E474u, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x77u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C3u, 8u);
        }

        case 0x002723C3u: {
            TP_STATIC_GUARD(0x04E478u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE47Au, 0x002723D3u, 3u);
        }

        case 0x002723D3u: {
            TP_STATIC_GUARD(0x04E47Au, 0x9Cu, 0x6Cu, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1F6Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE47Du, 0x002723EBu, 4u);
        }

        case 0x002723EBu: {
            TP_STATIC_GUARD(0x04E47Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE47Fu, 0x002723F8u, 3u);
        }

        case 0x002723F8u: {
            TP_STATIC_GUARD(0x04E47Fu, 0xA9u, 0x02u, 0x00u);
            const uint16_t value = 0x0002u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE482u, 0x00272410u, 3u);
        }

        case 0x00272410u: {
            TP_STATIC_GUARD(0x04E482u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE485u, 0x00272428u, 5u);
        }

        case 0x00272428u: {
            TP_STATIC_GUARD(0x04E485u, 0x22u, 0x28u, 0xBAu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBA28u, 0x0035D140u, 8u);
        }

        case 0x00272449u: {
            TP_STATIC_GUARD(0x04E489u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE48Bu, 0x00272458u, 3u);
        }

        case 0x00272458u: {
            TP_STATIC_GUARD(0x04E48Bu, 0xA9u, 0x02u, 0x00u);
            const uint16_t value = 0x0002u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE48Eu, 0x00272470u, 3u);
        }

        case 0x00272470u: {
            TP_STATIC_GUARD(0x04E48Eu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE491u, 0x00272488u, 5u);
        }

        case 0x00272488u: {
            TP_STATIC_GUARD(0x04E491u, 0x22u, 0x18u, 0x85u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x94u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0x8518u, 0x003428C0u, 8u);
        }

        case 0x002724A8u: {
            TP_STATIC_GUARD(0x04E495u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE497u, 0x002724B8u, 3u);
        }

        case 0x002724B8u: {
            TP_STATIC_GUARD(0x04E497u, 0xA9u, 0x02u, 0x00u);
            const uint16_t value = 0x0002u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE49Au, 0x002724D0u, 3u);
        }

        case 0x002724D0u: {
            TP_STATIC_GUARD(0x04E49Au, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE49Du, 0x002724E8u, 5u);
        }

        case 0x002724E8u: {
            TP_STATIC_GUARD(0x04E49Du, 0x22u, 0x33u, 0xD9u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xD933u, 0x0026C998u, 8u);
        }

        case 0x00272508u: {
            TP_STATIC_GUARD(0x04E4A1u, 0x82u, 0xF6u, 0x06u);
            TP_STATIC_EXIT(0x04u, 0xEB9Au, 0x00275CD0u, 4u);
        }

        case 0x00272520u: {
            TP_STATIC_GUARD(0x04E4A4u, 0xC9u, 0x08u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE4A7u, 0x00272538u, 3u);
        }

        case 0x00272538u: {
            TP_STATIC_GUARD(0x04E4A7u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE4ACu;
                if (tp_scpu_expect_next(cpu, 0x00272560u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE4A9u, 0x00272548u, 2u);
        }

        case 0x00272548u: {
            TP_STATIC_GUARD(0x04E4A9u, 0x82u, 0x38u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE4E4u, 0x00272720u, 4u);
        }

        case 0x00272560u: {
            TP_STATIC_GUARD(0x04E4ACu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE4AEu, 0x00272573u, 3u);
        }

        case 0x00272573u: {
            TP_STATIC_GUARD(0x04E4AEu, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE4B0u, 0x00272583u, 2u);
        }

        case 0x00272583u: {
            TP_STATIC_GUARD(0x04E4B0u, 0x22u, 0x14u, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED14u, 0x002768A3u, 8u);
        }

        case 0x002725A3u: {
            TP_STATIC_GUARD(0x04E4B4u, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB7u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C3u, 8u);
        }

        case 0x002725C3u: {
            TP_STATIC_GUARD(0x04E4B8u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE4BAu, 0x002725D3u, 3u);
        }

        case 0x002725D3u: {
            TP_STATIC_GUARD(0x04E4BAu, 0x9Cu, 0x6Cu, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1F6Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE4BDu, 0x002725EBu, 4u);
        }

        case 0x002725EBu: {
            TP_STATIC_GUARD(0x04E4BDu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE4BFu, 0x002725F8u, 3u);
        }

        case 0x002725F8u: {
            TP_STATIC_GUARD(0x04E4BFu, 0xA9u, 0x04u, 0x00u);
            const uint16_t value = 0x0004u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE4C2u, 0x00272610u, 3u);
        }

        case 0x00272610u: {
            TP_STATIC_GUARD(0x04E4C2u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE4C5u, 0x00272628u, 5u);
        }

        case 0x00272628u: {
            TP_STATIC_GUARD(0x04E4C5u, 0x22u, 0x28u, 0xBAu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBA28u, 0x0035D140u, 8u);
        }

        case 0x00272649u: {
            TP_STATIC_GUARD(0x04E4C9u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE4CBu, 0x00272658u, 3u);
        }

        case 0x00272658u: {
            TP_STATIC_GUARD(0x04E4CBu, 0xA9u, 0x04u, 0x00u);
            const uint16_t value = 0x0004u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE4CEu, 0x00272670u, 3u);
        }

        case 0x00272670u: {
            TP_STATIC_GUARD(0x04E4CEu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE4D1u, 0x00272688u, 5u);
        }

        case 0x00272688u: {
            TP_STATIC_GUARD(0x04E4D1u, 0x22u, 0x18u, 0x85u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xD4u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0x8518u, 0x003428C0u, 8u);
        }

        case 0x002726A8u: {
            TP_STATIC_GUARD(0x04E4D5u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE4D7u, 0x002726B8u, 3u);
        }

        case 0x002726B8u: {
            TP_STATIC_GUARD(0x04E4D7u, 0xA9u, 0x04u, 0x00u);
            const uint16_t value = 0x0004u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE4DAu, 0x002726D0u, 3u);
        }

        case 0x002726D0u: {
            TP_STATIC_GUARD(0x04E4DAu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE4DDu, 0x002726E8u, 5u);
        }

        case 0x002726E8u: {
            TP_STATIC_GUARD(0x04E4DDu, 0x22u, 0x33u, 0xD9u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xD933u, 0x0026C998u, 8u);
        }

        case 0x00272708u: {
            TP_STATIC_GUARD(0x04E4E1u, 0x82u, 0xB6u, 0x06u);
            TP_STATIC_EXIT(0x04u, 0xEB9Au, 0x00275CD0u, 4u);
        }

        case 0x00272720u: {
            TP_STATIC_GUARD(0x04E4E4u, 0xC9u, 0x09u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0009u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE4E7u, 0x00272738u, 3u);
        }

        case 0x00272738u: {
            TP_STATIC_GUARD(0x04E4E7u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE4ECu;
                if (tp_scpu_expect_next(cpu, 0x00272760u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE4E9u, 0x00272748u, 2u);
        }

        case 0x00272748u: {
            TP_STATIC_GUARD(0x04E4E9u, 0x82u, 0x38u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE524u, 0x00272920u, 4u);
        }

        case 0x00272760u: {
            TP_STATIC_GUARD(0x04E4ECu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE4EEu, 0x00272773u, 3u);
        }

        case 0x00272773u: {
            TP_STATIC_GUARD(0x04E4EEu, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE4F0u, 0x00272783u, 2u);
        }

        case 0x00272783u: {
            TP_STATIC_GUARD(0x04E4F0u, 0x22u, 0x14u, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED14u, 0x002768A3u, 8u);
        }

        case 0x002727A3u: {
            TP_STATIC_GUARD(0x04E4F4u, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF7u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C3u, 8u);
        }

        case 0x002727C3u: {
            TP_STATIC_GUARD(0x04E4F8u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE4FAu, 0x002727D3u, 3u);
        }

        case 0x002727D3u: {
            TP_STATIC_GUARD(0x04E4FAu, 0x9Cu, 0x6Cu, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1F6Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE4FDu, 0x002727EBu, 4u);
        }

        case 0x002727EBu: {
            TP_STATIC_GUARD(0x04E4FDu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE4FFu, 0x002727F8u, 3u);
        }

        case 0x002727F8u: {
            TP_STATIC_GUARD(0x04E4FFu, 0xA9u, 0x03u, 0x00u);
            const uint16_t value = 0x0003u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE502u, 0x00272810u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
