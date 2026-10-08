/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000EF5(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x0077A80Bu: {
            TP_STATIC_GUARD(0x0EF501u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x0Eu, 0xF503u, 0x0077A819u, 3u);
        }

        case 0x0077A819u: {
            TP_STATIC_GUARD(0x0EF503u, 0xA9u, 0x00u, 0xE2u);
            const uint16_t value = 0xE200u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF506u, 0x0077A831u, 3u);
        }

        case 0x0077A831u: {
            TP_STATIC_GUARD(0x0EF506u, 0xA2u, 0x1Cu);
            const uint8_t value = 0x1Cu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF508u, 0x0077A841u, 2u);
        }

        case 0x0077A841u: {
            TP_STATIC_GUARD(0x0EF508u, 0x22u, 0x68u, 0x82u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8268u, 0x003C1341u, 8u);
        }

        case 0x0077A861u: {
            TP_STATIC_GUARD(0x0EF50Cu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0xF50Eu, 0x0077A871u, 3u);
        }

        case 0x0077A871u: {
            TP_STATIC_GUARD(0x0EF50Eu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x0Eu, 0xF510u, 0x0077A881u, 3u);
        }

        case 0x0077A881u: {
            TP_STATIC_GUARD(0x0EF510u, 0xA9u, 0xE0u, 0xB9u);
            const uint16_t value = 0xB9E0u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF513u, 0x0077A899u, 3u);
        }

        case 0x0077A899u: {
            TP_STATIC_GUARD(0x0EF513u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF516u, 0x0077A8B1u, 5u);
        }

        case 0x0077A8B1u: {
            TP_STATIC_GUARD(0x0EF516u, 0xA2u, 0x1Eu);
            const uint8_t value = 0x1Eu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF518u, 0x0077A8C1u, 2u);
        }

        case 0x0077A8C1u: {
            TP_STATIC_GUARD(0x0EF518u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF51Bu, 0x0077A8D9u, 4u);
        }

        case 0x0077A8D9u: {
            TP_STATIC_GUARD(0x0EF51Bu, 0xA9u, 0x09u, 0xF1u);
            const uint16_t value = 0xF109u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF51Eu, 0x0077A8F1u, 3u);
        }

        case 0x0077A8F1u: {
            TP_STATIC_GUARD(0x0EF51Eu, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF521u, 0x0077A909u, 5u);
        }

        case 0x0077A909u: {
            TP_STATIC_GUARD(0x0EF521u, 0xA2u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF523u, 0x0077A919u, 2u);
        }

        case 0x0077A919u: {
            TP_STATIC_GUARD(0x0EF523u, 0x8Eu, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0790u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF526u, 0x0077A931u, 4u);
        }

        case 0x0077A931u: {
            TP_STATIC_GUARD(0x0EF526u, 0x22u, 0xFCu, 0xE1u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x29u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xE1FCu, 0x00670FE1u, 8u);
        }

        case 0x0077A951u: {
            TP_STATIC_GUARD(0x0EF52Au, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0xF52Cu, 0x0077A961u, 3u);
        }

        case 0x0077A961u: {
            TP_STATIC_GUARD(0x0EF52Cu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x0Eu, 0xF52Eu, 0x0077A971u, 3u);
        }

        case 0x0077A971u: {
            TP_STATIC_GUARD(0x0EF52Eu, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF531u, 0x0077A989u, 3u);
        }

        case 0x0077A989u: {
            TP_STATIC_GUARD(0x0EF531u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF534u, 0x0077A9A1u, 5u);
        }

        case 0x0077A9A1u: {
            TP_STATIC_GUARD(0x0EF534u, 0xA2u, 0x1Eu);
            const uint8_t value = 0x1Eu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF536u, 0x0077A9B1u, 2u);
        }

        case 0x0077A9B1u: {
            TP_STATIC_GUARD(0x0EF536u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF539u, 0x0077A9C9u, 4u);
        }

        case 0x0077A9C9u: {
            TP_STATIC_GUARD(0x0EF539u, 0xA9u, 0x09u, 0xEAu);
            const uint16_t value = 0xEA09u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF53Cu, 0x0077A9E1u, 3u);
        }

        case 0x0077A9E1u: {
            TP_STATIC_GUARD(0x0EF53Cu, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF53Fu, 0x0077A9F9u, 5u);
        }

        case 0x0077A9F9u: {
            TP_STATIC_GUARD(0x0EF53Fu, 0xA2u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF541u, 0x0077AA09u, 2u);
        }

        case 0x0077AA09u: {
            TP_STATIC_GUARD(0x0EF541u, 0x8Eu, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0790u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF544u, 0x0077AA21u, 4u);
        }

        case 0x0077AA21u: {
            TP_STATIC_GUARD(0x0EF544u, 0x22u, 0xC2u, 0xE2u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x47u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xE2C2u, 0x00671611u, 8u);
        }

        case 0x0077AA41u: {
            TP_STATIC_GUARD(0x0EF548u, 0x22u, 0x42u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x4Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8542u, 0x00642A11u, 8u);
        }

        case 0x0077AA63u: {
            TP_STATIC_GUARD(0x0EF54Cu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0xF54Eu, 0x0077AA73u, 3u);
        }

        case 0x0077AA73u: {
            TP_STATIC_GUARD(0x0EF54Eu, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF550u, 0x0077AA83u, 2u);
        }

        case 0x0077AA83u: {
            TP_STATIC_GUARD(0x0EF550u, 0x8Du, 0xEBu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18EBu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF553u, 0x0077AA9Bu, 4u);
        }

        case 0x0077AA9Bu: {
            TP_STATIC_GUARD(0x0EF553u, 0x9Cu, 0x50u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0750u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF556u, 0x0077AAB3u, 4u);
        }

        case 0x0077AAB3u: {
            TP_STATIC_GUARD(0x0EF556u, 0xADu, 0x50u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0750u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF559u, 0x0077AACBu, 4u);
        }

        case 0x0077AACBu: {
            TP_STATIC_GUARD(0x0EF559u, 0xF0u, 0xFBu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0xF556u;
                if (tp_scpu_expect_next(cpu, 0x0077AAB3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0xF55Bu, 0x0077AADBu, 2u);
        }

        case 0x0077AADBu: {
            TP_STATIC_GUARD(0x0EF55Bu, 0xA9u, 0x13u);
            const uint8_t value = 0x13u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF55Du, 0x0077AAEBu, 2u);
        }

        case 0x0077AAEBu: {
            TP_STATIC_GUARD(0x0EF55Du, 0x8Du, 0x88u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1888u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF560u, 0x0077AB03u, 4u);
        }

        case 0x0077AB03u: {
            TP_STATIC_GUARD(0x0EF560u, 0x22u, 0x67u, 0x87u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x63u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8767u, 0x00643B3Bu, 8u);
        }

        case 0x0077AB23u: {
            TP_STATIC_GUARD(0x0EF564u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0xF566u, 0x0077AB33u, 3u);
        }

        case 0x0077AB33u: {
            TP_STATIC_GUARD(0x0EF566u, 0xADu, 0x89u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1889u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF569u, 0x0077AB4Bu, 4u);
        }

        case 0x0077AB4Bu: {
            TP_STATIC_GUARD(0x0EF569u, 0xC9u, 0x13u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x13u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF56Bu, 0x0077AB5Bu, 2u);
        }

        case 0x0077AB5Bu: {
            TP_STATIC_GUARD(0x0EF56Bu, 0xD0u, 0xE6u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0xF553u;
                if (tp_scpu_expect_next(cpu, 0x0077AA9Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0xF56Du, 0x0077AB6Bu, 2u);
        }

        case 0x0077AB6Bu: {
            TP_STATIC_GUARD(0x0EF56Du, 0x22u, 0x67u, 0x87u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x70u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8767u, 0x00643B3Bu, 8u);
        }

        case 0x0077AB8Bu: {
            TP_STATIC_GUARD(0x0EF571u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0xF573u, 0x0077AB9Bu, 3u);
        }

        case 0x0077AB9Bu: {
            TP_STATIC_GUARD(0x0EF573u, 0x9Cu, 0x50u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0750u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF576u, 0x0077ABB3u, 4u);
        }

        case 0x0077ABB3u: {
            TP_STATIC_GUARD(0x0EF576u, 0xADu, 0x50u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0750u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF579u, 0x0077ABCBu, 4u);
        }

        case 0x0077ABCBu: {
            TP_STATIC_GUARD(0x0EF579u, 0xF0u, 0xFBu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0xF576u;
                if (tp_scpu_expect_next(cpu, 0x0077ABB3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0xF57Bu, 0x0077ABDBu, 2u);
        }

        case 0x0077ABDBu: {
            TP_STATIC_GUARD(0x0EF57Bu, 0xADu, 0x10u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0010u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF57Eu, 0x0077ABF3u, 4u);
        }

        case 0x0077ABF3u: {
            TP_STATIC_GUARD(0x0EF57Eu, 0xD0u, 0xEDu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0xF56Du;
                if (tp_scpu_expect_next(cpu, 0x0077AB6Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0xF580u, 0x0077AC03u, 2u);
        }

        case 0x0077AC03u: {
            TP_STATIC_GUARD(0x0EF580u, 0x22u, 0x67u, 0x87u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x83u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8767u, 0x00643B3Bu, 8u);
        }

        case 0x0077AC23u: {
            TP_STATIC_GUARD(0x0EF584u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Eu, 0xF586u, 0x0077AC30u, 3u);
        }

        case 0x0077AC30u: {
            TP_STATIC_GUARD(0x0EF586u, 0xADu, 0x44u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0744u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF589u, 0x0077AC48u, 5u);
        }

        case 0x0077AC48u: {
            TP_STATIC_GUARD(0x0EF589u, 0x8Du, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0746u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF58Cu, 0x0077AC60u, 5u);
        }

        case 0x0077AC60u: {
            TP_STATIC_GUARD(0x0EF58Cu, 0x22u, 0x98u, 0x9Du, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Fu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9D98u, 0x0064ECC0u, 8u);
        }

        case 0x0077AC83u: {
            TP_STATIC_GUARD(0x0EF590u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0xF592u, 0x0077AC93u, 3u);
        }

        case 0x0077AC93u: {
            TP_STATIC_GUARD(0x0EF592u, 0xADu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0746u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF595u, 0x0077ACABu, 4u);
        }

        case 0x0077ACABu: {
            TP_STATIC_GUARD(0x0EF595u, 0xC9u, 0x40u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x40u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF597u, 0x0077ACBBu, 2u);
        }

        case 0x0077ACBBu: {
            TP_STATIC_GUARD(0x0EF597u, 0xD0u, 0xEBu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0xF584u;
                if (tp_scpu_expect_next(cpu, 0x0077AC23u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0xF599u, 0x0077ACCBu, 2u);
        }

        case 0x0077ACCBu: {
            TP_STATIC_GUARD(0x0EF599u, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF59Bu, 0x0077ACDBu, 2u);
        }

        case 0x0077ACDBu: {
            TP_STATIC_GUARD(0x0EF59Bu, 0x22u, 0x14u, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x9Eu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED14u, 0x002768A3u, 8u);
        }

        case 0x0077ACFBu: {
            TP_STATIC_GUARD(0x0EF59Fu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Eu, 0xF5A1u, 0x0077AD0Bu, 3u);
        }

        case 0x0077AD0Bu: {
            TP_STATIC_GUARD(0x0EF5A1u, 0xA2u, 0x3Cu);
            const uint8_t value = 0x3Cu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF5A3u, 0x0077AD1Bu, 2u);
        }

        case 0x0077AD1Bu: {
            TP_STATIC_GUARD(0x0EF5A3u, 0x9Cu, 0x4Fu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x074Fu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF5A6u, 0x0077AD33u, 4u);
        }

        case 0x0077AD33u: {
            TP_STATIC_GUARD(0x0EF5A6u, 0xADu, 0x4Fu, 0x07u);
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
            TP_STATIC_EXIT(0x0Eu, 0xF5A9u, 0x0077AD4Bu, 4u);
        }

        case 0x0077AD4Bu: {
            TP_STATIC_GUARD(0x0EF5A9u, 0xF0u, 0xFBu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0xF5A6u;
                if (tp_scpu_expect_next(cpu, 0x0077AD33u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0xF5ABu, 0x0077AD5Bu, 2u);
        }

        case 0x0077AD5Bu: {
            TP_STATIC_GUARD(0x0EF5ABu, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0xF5ACu, 0x0077AD63u, 2u);
        }

        case 0x0077AD63u: {
            TP_STATIC_GUARD(0x0EF5ACu, 0xD0u, 0xF5u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0xF5A3u;
                if (tp_scpu_expect_next(cpu, 0x0077AD1Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0xF5AEu, 0x0077AD73u, 2u);
        }

        case 0x0077AD73u: {
            TP_STATIC_GUARD(0x0EF5AEu, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF5u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB1u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C3u, 8u);
        }

        case 0x0077AD93u: {
            TP_STATIC_GUARD(0x0EF5B2u, 0x6Bu);
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
                case 0x00054E0Bu:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
