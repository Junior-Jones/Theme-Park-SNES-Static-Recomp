/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0000AB(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00055801u: {
            TP_STATIC_GUARD(0x00AB00u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAB03u, 0x00055819u, 5u);
        }

        case 0x00055819u: {
            TP_STATIC_GUARD(0x00AB03u, 0xA2u, 0x7Fu);
            const uint8_t value = 0x7Fu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB05u, 0x00055829u, 2u);
        }

        case 0x00055829u: {
            TP_STATIC_GUARD(0x00AB05u, 0x8Eu, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0790u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAB08u, 0x00055841u, 4u);
        }

        case 0x00055841u: {
            TP_STATIC_GUARD(0x00AB08u, 0x20u, 0x51u, 0xC8u);
            if (tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC851u, 0x00064289u, 6u);
        }

        case 0x00055859u: {
            TP_STATIC_GUARD(0x00AB0Bu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xAB0Du, 0x00055868u, 3u);
        }

        case 0x00055868u: {
            TP_STATIC_GUARD(0x00AB0Du, 0xAEu, 0x44u, 0x07u);
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
            TP_STATIC_EXIT(0x00u, 0xAB10u, 0x00055880u, 5u);
        }

        case 0x00055880u: {
            TP_STATIC_GUARD(0x00AB10u, 0xD0u, 0x12u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB24u;
                if (tp_scpu_expect_next(cpu, 0x00055920u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAB12u, 0x00055890u, 2u);
        }

        case 0x00055890u: {
            TP_STATIC_GUARD(0x00AB12u, 0xAEu, 0xF1u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18F1u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB15u, 0x000558A8u, 5u);
        }

        case 0x000558A8u: {
            TP_STATIC_GUARD(0x00AB15u, 0xD0u, 0x0Du);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB24u;
                if (tp_scpu_expect_next(cpu, 0x00055920u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAB17u, 0x000558B8u, 2u);
        }

        case 0x000558B8u: {
            TP_STATIC_GUARD(0x00AB17u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAB19u, 0x000558CBu, 3u);
        }

        case 0x000558CBu: {
            TP_STATIC_GUARD(0x00AB19u, 0xCEu, 0xCCu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18CCu;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAB1Cu, 0x000558E3u, 6u);
        }

        case 0x000558E3u: {
            TP_STATIC_GUARD(0x00AB1Cu, 0xADu, 0xCCu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18CCu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB1Fu, 0x000558FBu, 4u);
        }

        case 0x000558FBu: {
            TP_STATIC_GUARD(0x00AB1Fu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB24u;
                if (tp_scpu_expect_next(cpu, 0x00055923u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAB21u, 0x0005590Bu, 2u);
        }

        case 0x0005590Bu: {
            TP_STATIC_GUARD(0x00AB21u, 0x82u, 0xB6u, 0xFFu);
            TP_STATIC_EXIT(0x00u, 0xAADAu, 0x000556D3u, 4u);
        }

        case 0x00055920u: {
            TP_STATIC_GUARD(0x00AB24u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xAB26u, 0x00055930u, 3u);
        }

        case 0x00055923u: {
            TP_STATIC_GUARD(0x00AB24u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xAB26u, 0x00055930u, 3u);
        }

        case 0x00055930u: {
            TP_STATIC_GUARD(0x00AB26u, 0xADu, 0x0Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB29u, 0x00055948u, 5u);
        }

        case 0x00055948u: {
            TP_STATIC_GUARD(0x00AB29u, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB2Cu, 0x00055960u, 3u);
        }

        case 0x00055960u: {
            TP_STATIC_GUARD(0x00AB2Cu, 0xF0u, 0x08u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB36u;
                if (tp_scpu_expect_next(cpu, 0x000559B0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAB2Eu, 0x00055970u, 2u);
        }

        case 0x00055970u: {
            TP_STATIC_GUARD(0x00AB2Eu, 0xC9u, 0x4Au, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x004Au;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB31u, 0x00055988u, 3u);
        }

        case 0x00055988u: {
            TP_STATIC_GUARD(0x00AB31u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB36u;
                if (tp_scpu_expect_next(cpu, 0x000559B0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAB33u, 0x00055998u, 2u);
        }

        case 0x00055998u: {
            TP_STATIC_GUARD(0x00AB33u, 0x82u, 0x9Au, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xABD0u, 0x00055E80u, 4u);
        }

        case 0x000559B0u: {
            TP_STATIC_GUARD(0x00AB36u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAB38u, 0x000559C3u, 3u);
        }

        case 0x000559C3u: {
            TP_STATIC_GUARD(0x00AB38u, 0xADu, 0x44u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F44u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB3Bu, 0x000559DBu, 4u);
        }

        case 0x000559DBu: {
            TP_STATIC_GUARD(0x00AB3Bu, 0xD0u, 0x09u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB46u;
                if (tp_scpu_expect_next(cpu, 0x00055A33u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAB3Du, 0x000559EBu, 2u);
        }

        case 0x000559EBu: {
            TP_STATIC_GUARD(0x00AB3Du, 0xADu, 0x5Au, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F5Au;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB40u, 0x00055A03u, 4u);
        }

        case 0x00055A03u: {
            TP_STATIC_GUARD(0x00AB40u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB46u;
                if (tp_scpu_expect_next(cpu, 0x00055A33u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAB42u, 0x00055A13u, 2u);
        }

        case 0x00055A13u: {
            TP_STATIC_GUARD(0x00AB42u, 0x22u, 0x82u, 0xACu, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x45u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAC82u, 0x00056413u, 8u);
        }

        case 0x00055A31u: {
            TP_STATIC_GUARD(0x00AB46u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xAB48u, 0x00055A40u, 3u);
        }

        case 0x00055A33u: {
            TP_STATIC_GUARD(0x00AB46u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xAB48u, 0x00055A40u, 3u);
        }

        case 0x00055A40u: {
            TP_STATIC_GUARD(0x00AB48u, 0xA9u, 0x02u, 0x00u);
            const uint16_t value = 0x0002u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB4Bu, 0x00055A58u, 3u);
        }

        case 0x00055A58u: {
            TP_STATIC_GUARD(0x00AB4Bu, 0x8Du, 0xEEu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18EEu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAB4Eu, 0x00055A70u, 5u);
        }

        case 0x00055A70u: {
            TP_STATIC_GUARD(0x00AB4Eu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAB50u, 0x00055A83u, 3u);
        }

        case 0x00055A83u: {
            TP_STATIC_GUARD(0x00AB50u, 0xADu, 0x42u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F42u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB53u, 0x00055A9Bu, 4u);
        }

        case 0x00055A9Bu: {
            TP_STATIC_GUARD(0x00AB53u, 0xD0u, 0x11u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB66u;
                if (tp_scpu_expect_next(cpu, 0x00055B33u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAB55u, 0x00055AABu, 2u);
        }

        case 0x00055AABu: {
            TP_STATIC_GUARD(0x00AB55u, 0xADu, 0xC4u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1FC4u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB58u, 0x00055AC3u, 4u);
        }

        case 0x00055AC3u: {
            TP_STATIC_GUARD(0x00AB58u, 0xD0u, 0x0Cu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB66u;
                if (tp_scpu_expect_next(cpu, 0x00055B33u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAB5Au, 0x00055AD3u, 2u);
        }

        case 0x00055AD3u: {
            TP_STATIC_GUARD(0x00AB5Au, 0x22u, 0xE7u, 0xFAu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x5Du) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xFAE7u, 0x0067D73Bu, 8u);
        }

        case 0x00055AF3u: {
            TP_STATIC_GUARD(0x00AB5Eu, 0x22u, 0x9Eu, 0xDAu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x61u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA9Eu, 0x0036D4F3u, 8u);
        }

        case 0x00055B10u: {
            TP_STATIC_GUARD(0x00AB62u, 0x22u, 0xE7u, 0xFAu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x65u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xFAE7u, 0x0067D738u, 8u);
        }

        case 0x00055B13u: {
            TP_STATIC_GUARD(0x00AB62u, 0x22u, 0xE7u, 0xFAu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x65u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xFAE7u, 0x0067D73Bu, 8u);
        }

        case 0x00055B30u: {
            TP_STATIC_GUARD(0x00AB66u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xAB68u, 0x00055B40u, 3u);
        }

        case 0x00055B33u: {
            TP_STATIC_GUARD(0x00AB66u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xAB68u, 0x00055B40u, 3u);
        }

        case 0x00055B40u: {
            TP_STATIC_GUARD(0x00AB68u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB6Bu, 0x00055B58u, 3u);
        }

        case 0x00055B58u: {
            TP_STATIC_GUARD(0x00AB6Bu, 0x8Du, 0xEEu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18EEu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAB6Eu, 0x00055B70u, 5u);
        }

        case 0x00055B70u: {
            TP_STATIC_GUARD(0x00AB6Eu, 0x22u, 0xE7u, 0xFAu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x71u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xFAE7u, 0x0067D738u, 8u);
        }

        case 0x00055B90u: {
            TP_STATIC_GUARD(0x00AB72u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xAB74u, 0x00055BA0u, 3u);
        }

        case 0x00055BA0u: {
            TP_STATIC_GUARD(0x00AB74u, 0xADu, 0x42u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F42u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB77u, 0x00055BB8u, 5u);
        }

        case 0x00055BB8u: {
            TP_STATIC_GUARD(0x00AB77u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB7Au, 0x00055BD0u, 3u);
        }

        case 0x00055BD0u: {
            TP_STATIC_GUARD(0x00AB7Au, 0xC9u, 0x01u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0001u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB7Du, 0x00055BE8u, 3u);
        }

        case 0x00055BE8u: {
            TP_STATIC_GUARD(0x00AB7Du, 0xD0u, 0x04u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB83u;
                if (tp_scpu_expect_next(cpu, 0x00055C18u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAB7Fu, 0x00055BF8u, 2u);
        }

        case 0x00055BF8u: {
            TP_STATIC_GUARD(0x00AB7Fu, 0x22u, 0x98u, 0xE2u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE298u, 0x003714C0u, 8u);
        }

        case 0x00055C18u: {
            TP_STATIC_GUARD(0x00AB83u, 0x22u, 0xB2u, 0xD3u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x86u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xD3B2u, 0x00269D90u, 8u);
        }

        case 0x00055C19u: {
            TP_STATIC_GUARD(0x00AB83u, 0x22u, 0xB2u, 0xD3u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x86u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xD3B2u, 0x00269D91u, 8u);
        }

        case 0x00055C38u: {
            TP_STATIC_GUARD(0x00AB87u, 0x22u, 0xE7u, 0xFAu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xFAE7u, 0x0067D738u, 8u);
        }

        case 0x00055C58u: {
            TP_STATIC_GUARD(0x00AB8Bu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xAB8Du, 0x00055C68u, 3u);
        }

        case 0x00055C68u: {
            TP_STATIC_GUARD(0x00AB8Du, 0xADu, 0x0Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB90u, 0x00055C80u, 5u);
        }

        case 0x00055C80u: {
            TP_STATIC_GUARD(0x00AB90u, 0xC9u, 0x4Au, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x004Au;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB93u, 0x00055C98u, 3u);
        }

        case 0x00055C98u: {
            TP_STATIC_GUARD(0x00AB93u, 0xD0u, 0x18u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xABADu;
                if (tp_scpu_expect_next(cpu, 0x00055D68u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAB95u, 0x00055CA8u, 2u);
        }

        case 0x00055CA8u: {
            TP_STATIC_GUARD(0x00AB95u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAB97u, 0x00055CB9u, 3u);
        }

        case 0x00055CB9u: {
            TP_STATIC_GUARD(0x00AB97u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xAB99u, 0x00055CC9u, 3u);
        }

        case 0x00055CC9u: {
            TP_STATIC_GUARD(0x00AB99u, 0xADu, 0x87u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0787u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB9Cu, 0x00055CE1u, 5u);
        }

        case 0x00055CE1u: {
            TP_STATIC_GUARD(0x00AB9Cu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAB9Fu, 0x00055CF9u, 5u);
        }

        case 0x00055CF9u: {
            TP_STATIC_GUARD(0x00AB9Fu, 0xAEu, 0x89u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0789u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xABA2u, 0x00055D11u, 4u);
        }

        case 0x00055D11u: {
            TP_STATIC_GUARD(0x00ABA2u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xABA5u, 0x00055D29u, 4u);
        }

        case 0x00055D29u: {
            TP_STATIC_GUARD(0x00ABA5u, 0x22u, 0xF8u, 0xB3u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xB3F8u, 0x00659FC1u, 8u);
        }

        case 0x00055D49u: {
            TP_STATIC_GUARD(0x00ABA9u, 0x22u, 0xE7u, 0xFAu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xFAE7u, 0x0067D739u, 8u);
        }

        case 0x00055D68u: {
            TP_STATIC_GUARD(0x00ABADu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xABAFu, 0x00055D7Bu, 3u);
        }

        case 0x00055D69u: {
            TP_STATIC_GUARD(0x00ABADu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xABAFu, 0x00055D7Bu, 3u);
        }

        case 0x00055D7Bu: {
            TP_STATIC_GUARD(0x00ABAFu, 0xADu, 0x6Fu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x076Fu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xABB2u, 0x00055D93u, 4u);
        }

        case 0x00055D93u: {
            TP_STATIC_GUARD(0x00ABB2u, 0xD0u, 0x0Du);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xABC1u;
                if (tp_scpu_expect_next(cpu, 0x00055E0Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xABB4u, 0x00055DA3u, 2u);
        }

        case 0x00055DA3u: {
            TP_STATIC_GUARD(0x00ABB4u, 0xADu, 0x0Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Eu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xABB7u, 0x00055DBBu, 4u);
        }

        case 0x00055DBBu: {
            TP_STATIC_GUARD(0x00ABB7u, 0xC9u, 0x0Fu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x0Fu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xABB9u, 0x00055DCBu, 2u);
        }

        case 0x00055DCBu: {
            TP_STATIC_GUARD(0x00ABB9u, 0xD0u, 0x0Au);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xABC5u;
                if (tp_scpu_expect_next(cpu, 0x00055E2Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xABBBu, 0x00055DDBu, 2u);
        }

        case 0x00055DDBu: {
            TP_STATIC_GUARD(0x00ABBBu, 0x22u, 0x0Eu, 0xDEu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBEu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xDE0Eu, 0x0026F073u, 8u);
        }

        case 0x00055DF8u: {
            TP_STATIC_GUARD(0x00ABBFu, 0x80u, 0x04u);
            TP_STATIC_EXIT(0x00u, 0xABC5u, 0x00055E28u, 3u);
        }

        case 0x00055E0Bu: {
            TP_STATIC_GUARD(0x00ABC1u, 0x22u, 0x00u, 0x80u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC4u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0x8000u, 0x00340003u, 8u);
        }

        case 0x00055E28u: {
            TP_STATIC_GUARD(0x00ABC5u, 0x22u, 0x3Fu, 0xC6u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xC63Fu, 0x006631F8u, 8u);
        }

        case 0x00055E2Au: {
            TP_STATIC_GUARD(0x00ABC5u, 0x22u, 0x3Fu, 0xC6u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xC63Fu, 0x006631FAu, 8u);
        }

        case 0x00055E2Bu: {
            TP_STATIC_GUARD(0x00ABC5u, 0x22u, 0x3Fu, 0xC6u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xC63Fu, 0x006631FBu, 8u);
        }

        case 0x00055E48u: {
            TP_STATIC_GUARD(0x00ABC9u, 0x22u, 0xE7u, 0xFAu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCCu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xFAE7u, 0x0067D738u, 8u);
        }

        case 0x00055E49u: {
            TP_STATIC_GUARD(0x00ABC9u, 0x22u, 0xE7u, 0xFAu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCCu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xFAE7u, 0x0067D739u, 8u);
        }

        case 0x00055E68u: {
            TP_STATIC_GUARD(0x00ABCDu, 0x4Cu, 0x46u, 0xACu);
            TP_STATIC_EXIT(0x00u, 0xAC46u, 0x00056230u, 3u);
        }

        case 0x00055E69u: {
            TP_STATIC_GUARD(0x00ABCDu, 0x4Cu, 0x46u, 0xACu);
            TP_STATIC_EXIT(0x00u, 0xAC46u, 0x00056231u, 3u);
        }

        case 0x00055E80u: {
            TP_STATIC_GUARD(0x00ABD0u, 0xC9u, 0x0Au, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Au;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xABD3u, 0x00055E98u, 3u);
        }

        case 0x00055E98u: {
            TP_STATIC_GUARD(0x00ABD3u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xABD8u;
                if (tp_scpu_expect_next(cpu, 0x00055EC0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xABD5u, 0x00055EA8u, 2u);
        }

        case 0x00055EA8u: {
            TP_STATIC_GUARD(0x00ABD5u, 0x4Cu, 0x46u, 0xACu);
            TP_STATIC_EXIT(0x00u, 0xAC46u, 0x00056230u, 3u);
        }

        case 0x00055EC0u: {
            TP_STATIC_GUARD(0x00ABD8u, 0xC9u, 0x50u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0050u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xABDBu, 0x00055ED8u, 3u);
        }

        case 0x00055ED8u: {
            TP_STATIC_GUARD(0x00ABDBu, 0xF0u, 0x05u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xABE2u;
                if (tp_scpu_expect_next(cpu, 0x00055F10u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xABDDu, 0x00055EE8u, 2u);
        }

        case 0x00055EE8u: {
            TP_STATIC_GUARD(0x00ABDDu, 0xC9u, 0xB4u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x00B4u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xABE0u, 0x00055F00u, 3u);
        }

        case 0x00055F00u: {
            TP_STATIC_GUARD(0x00ABE0u, 0xD0u, 0x0Bu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xABEDu;
                if (tp_scpu_expect_next(cpu, 0x00055F68u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xABE2u, 0x00055F10u, 2u);
        }

        case 0x00055F10u: {
            TP_STATIC_GUARD(0x00ABE2u, 0x22u, 0x4Eu, 0xDAu, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE5u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDA4Eu, 0x000ED270u, 8u);
        }

        case 0x00055F33u: {
            TP_STATIC_GUARD(0x00ABE6u, 0x22u, 0xE7u, 0xFAu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE9u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xFAE7u, 0x0067D73Bu, 8u);
        }

        case 0x00055F53u: {
            TP_STATIC_GUARD(0x00ABEAu, 0x4Cu, 0x46u, 0xACu);
            TP_STATIC_EXIT(0x00u, 0xAC46u, 0x00056233u, 3u);
        }

        case 0x00055F68u: {
            TP_STATIC_GUARD(0x00ABEDu, 0xC9u, 0x9Au, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x009Au;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xABF0u, 0x00055F80u, 3u);
        }

        case 0x00055F80u: {
            TP_STATIC_GUARD(0x00ABF0u, 0xF0u, 0x0Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC01u;
                if (tp_scpu_expect_next(cpu, 0x00056008u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xABF2u, 0x00055F90u, 2u);
        }

        case 0x00055F90u: {
            TP_STATIC_GUARD(0x00ABF2u, 0xC9u, 0x9Eu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x009Eu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xABF5u, 0x00055FA8u, 3u);
        }

        case 0x00055FA8u: {
            TP_STATIC_GUARD(0x00ABF5u, 0xF0u, 0x0Au);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC01u;
                if (tp_scpu_expect_next(cpu, 0x00056008u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xABF7u, 0x00055FB8u, 2u);
        }

        case 0x00055FB8u: {
            TP_STATIC_GUARD(0x00ABF7u, 0xC9u, 0xA0u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x00A0u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xABFAu, 0x00055FD0u, 3u);
        }

        case 0x00055FD0u: {
            TP_STATIC_GUARD(0x00ABFAu, 0xF0u, 0x05u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC01u;
                if (tp_scpu_expect_next(cpu, 0x00056008u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xABFCu, 0x00055FE0u, 2u);
        }

        case 0x00055FE0u: {
            TP_STATIC_GUARD(0x00ABFCu, 0xC9u, 0xA2u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x00A2u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xABFFu, 0x00055FF8u, 3u);
        }

        case 0x00055FF8u: {
            TP_STATIC_GUARD(0x00ABFFu, 0xD0u, 0x0Bu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC0Cu;
                if (tp_scpu_expect_next(cpu, 0x00056060u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC01u, 0x00056008u, 2u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
