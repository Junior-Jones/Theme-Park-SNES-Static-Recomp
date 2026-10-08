/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0000CA(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00065013u: {
            TP_STATIC_GUARD(0x00CA02u, 0x29u, 0x01u);
            const uint8_t value = (uint8_t)(cpu->a & 0x01u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA04u, 0x00065023u, 2u);
        }

        case 0x00065023u: {
            TP_STATIC_GUARD(0x00CA04u, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xCA07u, 0x0006503Bu, 4u);
        }

        case 0x0006503Bu: {
            TP_STATIC_GUARD(0x00CA07u, 0xADu, 0x9Fu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x189Fu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA0Au, 0x00065053u, 4u);
        }

        case 0x00065053u: {
            TP_STATIC_GUARD(0x00CA0Au, 0x29u, 0x01u);
            const uint8_t value = (uint8_t)(cpu->a & 0x01u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA0Cu, 0x00065063u, 2u);
        }

        case 0x00065063u: {
            TP_STATIC_GUARD(0x00CA0Cu, 0x4Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0064u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            value = (uint8_t)((cpu->a & 0x00FFu) ^ value);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA0Fu, 0x0006507Bu, 4u);
        }

        case 0x0006507Bu: {
            TP_STATIC_GUARD(0x00CA0Fu, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA15u;
                if (tp_scpu_expect_next(cpu, 0x000650ABu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA11u, 0x0006508Bu, 2u);
        }

        case 0x0006508Bu: {
            TP_STATIC_GUARD(0x00CA11u, 0x22u, 0x35u, 0xC0u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x14u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xC035u, 0x006601ABu, 8u);
        }

        case 0x000650A8u: {
            TP_STATIC_GUARD(0x00CA15u, 0x82u, 0xCDu, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x00065728u, 4u);
        }

        case 0x000650ABu: {
            TP_STATIC_GUARD(0x00CA15u, 0x82u, 0xCDu, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x0006572Bu, 4u);
        }

        case 0x000650C3u: {
            TP_STATIC_GUARD(0x00CA18u, 0xC9u, 0x1Eu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x1Eu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA1Au, 0x000650D3u, 2u);
        }

        case 0x000650D3u: {
            TP_STATIC_GUARD(0x00CA1Au, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA23u;
                if (tp_scpu_expect_next(cpu, 0x0006511Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA1Cu, 0x000650E3u, 2u);
        }

        case 0x000650E3u: {
            TP_STATIC_GUARD(0x00CA1Cu, 0x22u, 0xA0u, 0xB0u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x1Fu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xB0A0u, 0x003D8503u, 8u);
        }

        case 0x00065101u: {
            TP_STATIC_GUARD(0x00CA20u, 0x82u, 0xC2u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x00065729u, 4u);
        }

        case 0x0006511Bu: {
            TP_STATIC_GUARD(0x00CA23u, 0xC9u, 0x22u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x22u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA25u, 0x0006512Bu, 2u);
        }

        case 0x0006512Bu: {
            TP_STATIC_GUARD(0x00CA25u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA2Au;
                if (tp_scpu_expect_next(cpu, 0x00065153u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA27u, 0x0006513Bu, 2u);
        }

        case 0x0006513Bu: {
            TP_STATIC_GUARD(0x00CA27u, 0x82u, 0xBBu, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x0006572Bu, 4u);
        }

        case 0x00065153u: {
            TP_STATIC_GUARD(0x00CA2Au, 0xC9u, 0x2Cu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x2Cu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA2Cu, 0x00065163u, 2u);
        }

        case 0x00065163u: {
            TP_STATIC_GUARD(0x00CA2Cu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA31u;
                if (tp_scpu_expect_next(cpu, 0x0006518Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA2Eu, 0x00065173u, 2u);
        }

        case 0x00065173u: {
            TP_STATIC_GUARD(0x00CA2Eu, 0x82u, 0xB4u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x0006572Bu, 4u);
        }

        case 0x0006518Bu: {
            TP_STATIC_GUARD(0x00CA31u, 0xC9u, 0x28u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x28u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA33u, 0x0006519Bu, 2u);
        }

        case 0x0006519Bu: {
            TP_STATIC_GUARD(0x00CA33u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA39u;
                if (tp_scpu_expect_next(cpu, 0x000651CBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA35u, 0x000651ABu, 2u);
        }

        case 0x000651ABu: {
            TP_STATIC_GUARD(0x00CA35u, 0xC9u, 0x2Au);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x2Au;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA37u, 0x000651BBu, 2u);
        }

        case 0x000651BBu: {
            TP_STATIC_GUARD(0x00CA37u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA3Cu;
                if (tp_scpu_expect_next(cpu, 0x000651E3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA39u, 0x000651CBu, 2u);
        }

        case 0x000651CBu: {
            TP_STATIC_GUARD(0x00CA39u, 0x82u, 0xA9u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x0006572Bu, 4u);
        }

        case 0x000651E3u: {
            TP_STATIC_GUARD(0x00CA3Cu, 0xC9u, 0x2Eu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x2Eu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA3Eu, 0x000651F3u, 2u);
        }

        case 0x000651F3u: {
            TP_STATIC_GUARD(0x00CA3Eu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA43u;
                if (tp_scpu_expect_next(cpu, 0x0006521Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA40u, 0x00065203u, 2u);
        }

        case 0x00065203u: {
            TP_STATIC_GUARD(0x00CA40u, 0x82u, 0xA2u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x0006572Bu, 4u);
        }

        case 0x0006521Bu: {
            TP_STATIC_GUARD(0x00CA43u, 0xC9u, 0x32u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x32u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA45u, 0x0006522Bu, 2u);
        }

        case 0x0006522Bu: {
            TP_STATIC_GUARD(0x00CA45u, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA4Eu;
                if (tp_scpu_expect_next(cpu, 0x00065273u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA47u, 0x0006523Bu, 2u);
        }

        case 0x0006523Bu: {
            TP_STATIC_GUARD(0x00CA47u, 0x22u, 0x13u, 0xFBu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x4Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xFB13u, 0x0067D89Bu, 8u);
        }

        case 0x00065259u: {
            TP_STATIC_GUARD(0x00CA4Bu, 0x82u, 0x97u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x00065729u, 4u);
        }

        case 0x00065273u: {
            TP_STATIC_GUARD(0x00CA4Eu, 0xC9u, 0x34u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x34u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA50u, 0x00065283u, 2u);
        }

        case 0x00065283u: {
            TP_STATIC_GUARD(0x00CA50u, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA59u;
                if (tp_scpu_expect_next(cpu, 0x000652CBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA52u, 0x00065293u, 2u);
        }

        case 0x00065293u: {
            TP_STATIC_GUARD(0x00CA52u, 0x22u, 0x7Fu, 0xA4u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x55u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xA47Fu, 0x003D23FBu, 8u);
        }

        case 0x000652B1u: {
            TP_STATIC_GUARD(0x00CA56u, 0x82u, 0x8Cu, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x00065729u, 4u);
        }

        case 0x000652CBu: {
            TP_STATIC_GUARD(0x00CA59u, 0xC9u, 0x36u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x36u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA5Bu, 0x000652DBu, 2u);
        }

        case 0x000652DBu: {
            TP_STATIC_GUARD(0x00CA5Bu, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA64u;
                if (tp_scpu_expect_next(cpu, 0x00065323u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA5Du, 0x000652EBu, 2u);
        }

        case 0x000652EBu: {
            TP_STATIC_GUARD(0x00CA5Du, 0x22u, 0x78u, 0xBAu, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x60u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xBA78u, 0x003DD3C3u, 8u);
        }

        case 0x00065309u: {
            TP_STATIC_GUARD(0x00CA61u, 0x82u, 0x81u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x00065729u, 4u);
        }

        case 0x00065323u: {
            TP_STATIC_GUARD(0x00CA64u, 0xC9u, 0x38u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x38u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA66u, 0x00065333u, 2u);
        }

        case 0x00065333u: {
            TP_STATIC_GUARD(0x00CA66u, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA6Fu;
                if (tp_scpu_expect_next(cpu, 0x0006537Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA68u, 0x00065343u, 2u);
        }

        case 0x00065343u: {
            TP_STATIC_GUARD(0x00CA68u, 0x22u, 0x01u, 0xEDu, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x6Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xED01u, 0x0007680Bu, 8u);
        }

        case 0x00065361u: {
            TP_STATIC_GUARD(0x00CA6Cu, 0x82u, 0x76u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x00065729u, 4u);
        }

        case 0x0006537Bu: {
            TP_STATIC_GUARD(0x00CA6Fu, 0xC9u, 0x3Au);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x3Au;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA71u, 0x0006538Bu, 2u);
        }

        case 0x0006538Bu: {
            TP_STATIC_GUARD(0x00CA71u, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA79u;
                if (tp_scpu_expect_next(cpu, 0x000653CBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA73u, 0x0006539Bu, 2u);
        }

        case 0x0006539Bu: {
            TP_STATIC_GUARD(0x00CA73u, 0x20u, 0x9Eu, 0xEEu);
            if (tp_scpu_push8(cpu, bus, 0xCAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x75u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xEE9Eu, 0x000774F3u, 6u);
        }

        case 0x000653B1u: {
            TP_STATIC_GUARD(0x00CA76u, 0x82u, 0x6Cu, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x00065729u, 4u);
        }

        case 0x000653CBu: {
            TP_STATIC_GUARD(0x00CA79u, 0xC9u, 0x3Cu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x3Cu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA7Bu, 0x000653DBu, 2u);
        }

        case 0x000653DBu: {
            TP_STATIC_GUARD(0x00CA7Bu, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA84u;
                if (tp_scpu_expect_next(cpu, 0x00065423u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA7Du, 0x000653EBu, 2u);
        }

        case 0x000653EBu: {
            TP_STATIC_GUARD(0x00CA7Du, 0x22u, 0x0Eu, 0xBEu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xBE0Eu, 0x0065F073u, 8u);
        }

        case 0x00065409u: {
            TP_STATIC_GUARD(0x00CA81u, 0x82u, 0x61u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x00065729u, 4u);
        }

        case 0x00065423u: {
            TP_STATIC_GUARD(0x00CA84u, 0xC9u, 0x3Eu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x3Eu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA86u, 0x00065433u, 2u);
        }

        case 0x00065433u: {
            TP_STATIC_GUARD(0x00CA86u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCA8Bu;
                if (tp_scpu_expect_next(cpu, 0x0006545Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA88u, 0x00065443u, 2u);
        }

        case 0x00065443u: {
            TP_STATIC_GUARD(0x00CA88u, 0x82u, 0x5Au, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x0006572Bu, 4u);
        }

        case 0x0006545Bu: {
            TP_STATIC_GUARD(0x00CA8Bu, 0xC9u, 0x40u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x40u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA8Du, 0x0006546Bu, 2u);
        }

        case 0x0006546Bu: {
            TP_STATIC_GUARD(0x00CA8Du, 0xD0u, 0x11u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCAA0u;
                if (tp_scpu_expect_next(cpu, 0x00065503u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCA8Fu, 0x0006547Bu, 2u);
        }

        case 0x0006547Bu: {
            TP_STATIC_GUARD(0x00CA8Fu, 0x22u, 0x70u, 0xADu, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x92u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xAD70u, 0x003D6B83u, 8u);
        }

        case 0x00065499u: {
            TP_STATIC_GUARD(0x00CA93u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xCA95u, 0x000654A8u, 3u);
        }

        case 0x000654A8u: {
            TP_STATIC_GUARD(0x00CA95u, 0xA0u, 0xA4u, 0x04u);
            const uint16_t value = 0x04A4u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA98u, 0x000654C0u, 3u);
        }

        case 0x000654C0u: {
            TP_STATIC_GUARD(0x00CA98u, 0xB7u, 0x5Eu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x5Eu);
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
            cpu->pbr = 0x00u;
            cpu->pc = 0xCA9Au;
            if (tp_scpu_expect_next(cpu, 0x000654D0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x000654D0u: {
            TP_STATIC_GUARD(0x00CA9Au, 0x1Au);
            cpu->a = (uint16_t)(cpu->a + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCA9Bu, 0x000654D8u, 3u);
        }

        case 0x000654D8u: {
            TP_STATIC_GUARD(0x00CA9Bu, 0x97u, 0x5Eu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x5Eu);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x00u;
            cpu->pc = 0xCA9Du;
            if (tp_scpu_expect_next(cpu, 0x000654E8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x000654E8u: {
            TP_STATIC_GUARD(0x00CA9Du, 0x82u, 0x45u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x00065728u, 4u);
        }

        case 0x00065503u: {
            TP_STATIC_GUARD(0x00CAA0u, 0xC9u, 0x42u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x42u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCAA2u, 0x00065513u, 2u);
        }

        case 0x00065513u: {
            TP_STATIC_GUARD(0x00CAA2u, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCAABu;
                if (tp_scpu_expect_next(cpu, 0x0006555Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCAA4u, 0x00065523u, 2u);
        }

        case 0x00065523u: {
            TP_STATIC_GUARD(0x00CAA4u, 0x22u, 0x1Fu, 0xA5u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA7u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xA51Fu, 0x002528FBu, 8u);
        }

        case 0x00065541u: {
            TP_STATIC_GUARD(0x00CAA8u, 0x82u, 0x3Au, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x00065729u, 4u);
        }

        case 0x0006555Bu: {
            TP_STATIC_GUARD(0x00CAABu, 0xC9u, 0x44u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x44u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCAADu, 0x0006556Bu, 2u);
        }

        case 0x0006556Bu: {
            TP_STATIC_GUARD(0x00CAADu, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCAB3u;
                if (tp_scpu_expect_next(cpu, 0x0006559Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCAAFu, 0x0006557Bu, 2u);
        }

        case 0x0006557Bu: {
            TP_STATIC_GUARD(0x00CAAFu, 0xC9u, 0x46u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x46u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCAB1u, 0x0006558Bu, 2u);
        }

        case 0x0006558Bu: {
            TP_STATIC_GUARD(0x00CAB1u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCAB6u;
                if (tp_scpu_expect_next(cpu, 0x000655B3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCAB3u, 0x0006559Bu, 2u);
        }

        case 0x0006559Bu: {
            TP_STATIC_GUARD(0x00CAB3u, 0x82u, 0x2Fu, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x0006572Bu, 4u);
        }

        case 0x000655B3u: {
            TP_STATIC_GUARD(0x00CAB6u, 0xC9u, 0x48u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x48u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCAB8u, 0x000655C3u, 2u);
        }

        case 0x000655C3u: {
            TP_STATIC_GUARD(0x00CAB8u, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCAC1u;
                if (tp_scpu_expect_next(cpu, 0x0006560Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCABAu, 0x000655D3u, 2u);
        }

        case 0x000655D3u: {
            TP_STATIC_GUARD(0x00CABAu, 0x22u, 0xBEu, 0xF2u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBDu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF2BEu, 0x002795F3u, 8u);
        }

        case 0x000655F1u: {
            TP_STATIC_GUARD(0x00CABEu, 0x82u, 0x24u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x00065729u, 4u);
        }

        case 0x0006560Bu: {
            TP_STATIC_GUARD(0x00CAC1u, 0xC9u, 0x52u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x52u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCAC3u, 0x0006561Bu, 2u);
        }

        case 0x0006561Bu: {
            TP_STATIC_GUARD(0x00CAC3u, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCACCu;
                if (tp_scpu_expect_next(cpu, 0x00065663u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCAC5u, 0x0006562Bu, 2u);
        }

        case 0x0006562Bu: {
            TP_STATIC_GUARD(0x00CAC5u, 0x22u, 0xE6u, 0xB7u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xB7E6u, 0x0065BF33u, 8u);
        }

        case 0x00065649u: {
            TP_STATIC_GUARD(0x00CAC9u, 0x82u, 0x19u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x00065729u, 4u);
        }

        case 0x00065663u: {
            TP_STATIC_GUARD(0x00CACCu, 0xC9u, 0x54u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x54u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCACEu, 0x00065673u, 2u);
        }

        case 0x00065673u: {
            TP_STATIC_GUARD(0x00CACEu, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCAD7u;
                if (tp_scpu_expect_next(cpu, 0x000656BBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCAD0u, 0x00065683u, 2u);
        }

        case 0x00065683u: {
            TP_STATIC_GUARD(0x00CAD0u, 0x22u, 0xE6u, 0xB7u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xD3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xB7E6u, 0x0065BF33u, 8u);
        }

        case 0x000656A1u: {
            TP_STATIC_GUARD(0x00CAD4u, 0x82u, 0x0Eu, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x00065729u, 4u);
        }

        case 0x000656BBu: {
            TP_STATIC_GUARD(0x00CAD7u, 0xC9u, 0x4Cu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x4Cu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCAD9u, 0x000656CBu, 2u);
        }

        case 0x000656CBu: {
            TP_STATIC_GUARD(0x00CAD9u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCADEu;
                if (tp_scpu_expect_next(cpu, 0x000656F3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCADBu, 0x000656DBu, 2u);
        }

        case 0x000656DBu: {
            TP_STATIC_GUARD(0x00CADBu, 0x82u, 0x07u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x0006572Bu, 4u);
        }

        case 0x000656F3u: {
            TP_STATIC_GUARD(0x00CADEu, 0xC9u, 0x4Eu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x4Eu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCAE0u, 0x00065703u, 2u);
        }

        case 0x00065703u: {
            TP_STATIC_GUARD(0x00CAE0u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCAE5u;
                if (tp_scpu_expect_next(cpu, 0x0006572Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCAE2u, 0x00065713u, 2u);
        }

        case 0x00065713u: {
            TP_STATIC_GUARD(0x00CAE2u, 0x82u, 0x00u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xCAE5u, 0x0006572Bu, 4u);
        }

        case 0x00065728u: {
            TP_STATIC_GUARD(0x00CAE5u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xCAE7u, 0x0006573Bu, 3u);
        }

        case 0x00065729u: {
            TP_STATIC_GUARD(0x00CAE5u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xCAE7u, 0x0006573Bu, 3u);
        }

        case 0x0006572Bu: {
            TP_STATIC_GUARD(0x00CAE5u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xCAE7u, 0x0006573Bu, 3u);
        }

        case 0x0006573Bu: {
            TP_STATIC_GUARD(0x00CAE7u, 0xA0u, 0x86u);
            const uint8_t value = 0x86u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCAE9u, 0x0006574Bu, 2u);
        }

        case 0x0006574Bu: {
            TP_STATIC_GUARD(0x00CAE9u, 0xB7u, 0x49u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x49u);
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
            cpu->pbr = 0x00u;
            cpu->pc = 0xCAEBu;
            if (tp_scpu_expect_next(cpu, 0x0006575Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0006575Bu: {
            TP_STATIC_GUARD(0x00CAEBu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCAF0u;
                if (tp_scpu_expect_next(cpu, 0x00065783u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCAEDu, 0x0006576Bu, 2u);
        }

        case 0x0006576Bu: {
            TP_STATIC_GUARD(0x00CAEDu, 0x3Au);
            const uint8_t value = (uint8_t)((cpu->a - 1u) & 0x00FFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCAEEu, 0x00065773u, 2u);
        }

        case 0x00065773u: {
            TP_STATIC_GUARD(0x00CAEEu, 0x97u, 0x49u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x49u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x00u;
            cpu->pc = 0xCAF0u;
            if (tp_scpu_expect_next(cpu, 0x00065783u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00065783u: {
            TP_STATIC_GUARD(0x00CAF0u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xCAF2u, 0x00065793u, 3u);
        }

        case 0x00065793u: {
            TP_STATIC_GUARD(0x00CAF2u, 0xA0u, 0x51u);
            const uint8_t value = 0x51u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCAF4u, 0x000657A3u, 2u);
        }

        case 0x000657A3u: {
            TP_STATIC_GUARD(0x00CAF4u, 0xB7u, 0x49u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x49u);
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
            cpu->pbr = 0x00u;
            cpu->pc = 0xCAF6u;
            if (tp_scpu_expect_next(cpu, 0x000657B3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x000657B3u: {
            TP_STATIC_GUARD(0x00CAF6u, 0xC9u, 0xFFu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0xFFu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCAF8u, 0x000657C3u, 2u);
        }

        case 0x000657C3u: {
            TP_STATIC_GUARD(0x00CAF8u, 0xF0u, 0x6Bu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xCB65u;
                if (tp_scpu_expect_next(cpu, 0x00065B2Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xCAFAu, 0x000657D3u, 2u);
        }

        case 0x000657D3u: {
            TP_STATIC_GUARD(0x00CAFAu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xCAFCu, 0x000657E3u, 3u);
        }

        case 0x000657E3u: {
            TP_STATIC_GUARD(0x00CAFCu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xCAFEu, 0x000657F1u, 3u);
        }

        case 0x000657F1u: {
            TP_STATIC_GUARD(0x00CAFEu, 0xA0u, 0x55u);
            const uint8_t value = 0x55u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xCB00u, 0x00065801u, 2u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
