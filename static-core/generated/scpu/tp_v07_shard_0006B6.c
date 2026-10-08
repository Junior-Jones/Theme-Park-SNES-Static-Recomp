/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0006B6(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x0035B003u: {
            TP_STATIC_GUARD(0x06B600u, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB602u, 0x0035B013u, 2u);
        }

        case 0x0035B013u: {
            TP_STATIC_GUARD(0x06B602u, 0x22u, 0x0Au, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x05u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Au, 0x00276853u, 8u);
        }

        case 0x0035B033u: {
            TP_STATIC_GUARD(0x06B606u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB608u, 0x0035B043u, 3u);
        }

        case 0x0035B043u: {
            TP_STATIC_GUARD(0x06B608u, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB60Bu, 0x0035B05Bu, 4u);
        }

        case 0x0035B05Bu: {
            TP_STATIC_GUARD(0x06B60Bu, 0x09u, 0x20u);
            const uint8_t value = (uint8_t)(cpu->a | 0x20u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB60Du, 0x0035B06Bu, 2u);
        }

        case 0x0035B06Bu: {
            TP_STATIC_GUARD(0x06B60Du, 0x8Du, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1F64u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xB610u, 0x0035B083u, 4u);
        }

        case 0x0035B083u: {
            TP_STATIC_GUARD(0x06B610u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB612u, 0x0035B093u, 3u);
        }

        case 0x0035B093u: {
            TP_STATIC_GUARD(0x06B612u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x06u, 0xB614u, 0x0035B0A2u, 3u);
        }

        case 0x0035B0A2u: {
            TP_STATIC_GUARD(0x06B614u, 0x22u, 0xFAu, 0xB4u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x17u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xB4FAu, 0x0025A7D2u, 8u);
        }

        case 0x0035B0C0u: {
            TP_STATIC_GUARD(0x06B618u, 0x82u, 0x21u, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E0u, 4u);
        }

        case 0x0035B0DBu: {
            TP_STATIC_GUARD(0x06B61Bu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB61Du, 0x0035B0EBu, 3u);
        }

        case 0x0035B0EBu: {
            TP_STATIC_GUARD(0x06B61Du, 0xC9u, 0x2Au);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x2Au;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB61Fu, 0x0035B0FBu, 2u);
        }

        case 0x0035B0FBu: {
            TP_STATIC_GUARD(0x06B61Fu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB624u;
                if (tp_scpu_expect_next(cpu, 0x0035B123u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB621u, 0x0035B10Bu, 2u);
        }

        case 0x0035B10Bu: {
            TP_STATIC_GUARD(0x06B621u, 0x82u, 0x42u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xB666u, 0x0035B333u, 4u);
        }

        case 0x0035B123u: {
            TP_STATIC_GUARD(0x06B624u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB626u, 0x0035B133u, 3u);
        }

        case 0x0035B133u: {
            TP_STATIC_GUARD(0x06B626u, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB629u, 0x0035B14Bu, 4u);
        }

        case 0x0035B14Bu: {
            TP_STATIC_GUARD(0x06B629u, 0x29u, 0x40u);
            const uint8_t value = (uint8_t)(cpu->a & 0x40u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB62Bu, 0x0035B15Bu, 2u);
        }

        case 0x0035B15Bu: {
            TP_STATIC_GUARD(0x06B62Bu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB630u;
                if (tp_scpu_expect_next(cpu, 0x0035B183u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB62Du, 0x0035B16Bu, 2u);
        }

        case 0x0035B16Bu: {
            TP_STATIC_GUARD(0x06B62Du, 0x82u, 0x03u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xB633u, 0x0035B19Bu, 4u);
        }

        case 0x0035B183u: {
            TP_STATIC_GUARD(0x06B630u, 0x82u, 0x09u, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E3u, 4u);
        }

        case 0x0035B19Bu: {
            TP_STATIC_GUARD(0x06B633u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB635u, 0x0035B1ABu, 3u);
        }

        case 0x0035B1ABu: {
            TP_STATIC_GUARD(0x06B635u, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB638u, 0x0035B1C3u, 4u);
        }

        case 0x0035B1C3u: {
            TP_STATIC_GUARD(0x06B638u, 0x29u, 0x40u);
            const uint8_t value = (uint8_t)(cpu->a & 0x40u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB63Au, 0x0035B1D3u, 2u);
        }

        case 0x0035B1D3u: {
            TP_STATIC_GUARD(0x06B63Au, 0xF0u, 0x0Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB64Bu;
                if (tp_scpu_expect_next(cpu, 0x0035B25Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB63Cu, 0x0035B1E3u, 2u);
        }

        case 0x0035B1E3u: {
            TP_STATIC_GUARD(0x06B63Cu, 0xA9u, 0x07u);
            const uint8_t value = 0x07u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB63Eu, 0x0035B1F3u, 2u);
        }

        case 0x0035B1F3u: {
            TP_STATIC_GUARD(0x06B63Eu, 0x22u, 0x0Au, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x41u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Au, 0x00276853u, 8u);
        }

        case 0x0035B213u: {
            TP_STATIC_GUARD(0x06B642u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB644u, 0x0035B223u, 3u);
        }

        case 0x0035B223u: {
            TP_STATIC_GUARD(0x06B644u, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB647u, 0x0035B23Bu, 4u);
        }

        case 0x0035B23Bu: {
            TP_STATIC_GUARD(0x06B647u, 0x29u, 0x3Fu);
            const uint8_t value = (uint8_t)(cpu->a & 0x3Fu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB649u, 0x0035B24Bu, 2u);
        }

        case 0x0035B24Bu: {
            TP_STATIC_GUARD(0x06B649u, 0x80u, 0x0Du);
            TP_STATIC_EXIT(0x06u, 0xB658u, 0x0035B2C3u, 3u);
        }

        case 0x0035B25Bu: {
            TP_STATIC_GUARD(0x06B64Bu, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB64Du, 0x0035B26Bu, 2u);
        }

        case 0x0035B26Bu: {
            TP_STATIC_GUARD(0x06B64Du, 0x22u, 0x0Au, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x50u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Au, 0x00276853u, 8u);
        }

        case 0x0035B28Bu: {
            TP_STATIC_GUARD(0x06B651u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB653u, 0x0035B29Bu, 3u);
        }

        case 0x0035B29Bu: {
            TP_STATIC_GUARD(0x06B653u, 0xADu, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F64u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB656u, 0x0035B2B3u, 4u);
        }

        case 0x0035B2B3u: {
            TP_STATIC_GUARD(0x06B656u, 0x09u, 0x40u);
            const uint8_t value = (uint8_t)(cpu->a | 0x40u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB658u, 0x0035B2C3u, 2u);
        }

        case 0x0035B2C3u: {
            TP_STATIC_GUARD(0x06B658u, 0x8Du, 0x64u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1F64u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xB65Bu, 0x0035B2DBu, 4u);
        }

        case 0x0035B2DBu: {
            TP_STATIC_GUARD(0x06B65Bu, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB65Du, 0x0035B2EBu, 3u);
        }

        case 0x0035B2EBu: {
            TP_STATIC_GUARD(0x06B65Du, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x06u, 0xB65Fu, 0x0035B2FAu, 3u);
        }

        case 0x0035B2FAu: {
            TP_STATIC_GUARD(0x06B65Fu, 0x22u, 0xFAu, 0xB4u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x62u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xB4FAu, 0x0025A7D2u, 8u);
        }

        case 0x0035B318u: {
            TP_STATIC_GUARD(0x06B663u, 0x82u, 0xD6u, 0x01u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E0u, 4u);
        }

        case 0x0035B333u: {
            TP_STATIC_GUARD(0x06B666u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB668u, 0x0035B343u, 3u);
        }

        case 0x0035B343u: {
            TP_STATIC_GUARD(0x06B668u, 0xC9u, 0x20u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x20u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB66Au, 0x0035B353u, 2u);
        }

        case 0x0035B353u: {
            TP_STATIC_GUARD(0x06B66Au, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB66Fu;
                if (tp_scpu_expect_next(cpu, 0x0035B37Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB66Cu, 0x0035B363u, 2u);
        }

        case 0x0035B363u: {
            TP_STATIC_GUARD(0x06B66Cu, 0x82u, 0x9Fu, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xB70Eu, 0x0035B873u, 4u);
        }

        case 0x0035B37Bu: {
            TP_STATIC_GUARD(0x06B66Fu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xB671u, 0x0035B388u, 3u);
        }

        case 0x0035B388u: {
            TP_STATIC_GUARD(0x06B671u, 0xADu, 0x34u, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1434u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB674u, 0x0035B3A0u, 5u);
        }

        case 0x0035B3A0u: {
            TP_STATIC_GUARD(0x06B674u, 0x22u, 0x9Du, 0xC2u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x77u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC29Du, 0x000614E8u, 8u);
        }

        case 0x0035B3C1u: {
            TP_STATIC_GUARD(0x06B678u, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xB67Bu, 0x0035B3D9u, 5u);
        }

        case 0x0035B3D9u: {
            TP_STATIC_GUARD(0x06B67Bu, 0x8Eu, 0x66u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0066u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xB67Eu, 0x0035B3F1u, 4u);
        }

        case 0x0035B3F1u: {
            TP_STATIC_GUARD(0x06B67Eu, 0xA0u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB680u, 0x0035B401u, 2u);
        }

        case 0x0035B401u: {
            TP_STATIC_GUARD(0x06B680u, 0xB7u, 0x64u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x64u);
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
            cpu->pbr = 0x06u;
            cpu->pc = 0xB682u;
            if (tp_scpu_expect_next(cpu, 0x0035B411u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0035B411u: {
            TP_STATIC_GUARD(0x06B682u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB685u, 0x0035B429u, 3u);
        }

        case 0x0035B429u: {
            TP_STATIC_GUARD(0x06B685u, 0xC9u, 0x04u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0004u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB688u, 0x0035B441u, 3u);
        }

        case 0x0035B441u: {
            TP_STATIC_GUARD(0x06B688u, 0xD0u, 0x59u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB6E3u;
                if (tp_scpu_expect_next(cpu, 0x0035B719u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB68Au, 0x0035B451u, 2u);
        }

        case 0x0035B451u: {
            TP_STATIC_GUARD(0x06B68Au, 0xA0u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB68Cu, 0x0035B461u, 2u);
        }

        case 0x0035B461u: {
            TP_STATIC_GUARD(0x06B68Cu, 0xB7u, 0x64u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x64u);
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
            cpu->pbr = 0x06u;
            cpu->pc = 0xB68Eu;
            if (tp_scpu_expect_next(cpu, 0x0035B471u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0035B471u: {
            TP_STATIC_GUARD(0x06B68Eu, 0xC9u, 0x03u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0003u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB691u, 0x0035B489u, 3u);
        }

        case 0x0035B489u: {
            TP_STATIC_GUARD(0x06B691u, 0xF0u, 0x50u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB6E3u;
                if (tp_scpu_expect_next(cpu, 0x0035B719u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB693u, 0x0035B499u, 2u);
        }

        case 0x0035B499u: {
            TP_STATIC_GUARD(0x06B693u, 0xC9u, 0x3Fu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x003Fu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB696u, 0x0035B4B1u, 3u);
        }

        case 0x0035B4B1u: {
            TP_STATIC_GUARD(0x06B696u, 0xF0u, 0x4Bu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB6E3u;
                if (tp_scpu_expect_next(cpu, 0x0035B719u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB698u, 0x0035B4C1u, 2u);
        }

        case 0x0035B4C1u: {
            TP_STATIC_GUARD(0x06B698u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB69Au, 0x0035B4D3u, 3u);
        }

        case 0x0035B4D3u: {
            TP_STATIC_GUARD(0x06B69Au, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB69Du, 0x0035B4EBu, 4u);
        }

        case 0x0035B4EBu: {
            TP_STATIC_GUARD(0x06B69Du, 0xC9u, 0x01u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x01u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB69Fu, 0x0035B4FBu, 2u);
        }

        case 0x0035B4FBu: {
            TP_STATIC_GUARD(0x06B69Fu, 0xF0u, 0x07u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB6A8u;
                if (tp_scpu_expect_next(cpu, 0x0035B543u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB6A1u, 0x0035B50Bu, 2u);
        }

        case 0x0035B50Bu: {
            TP_STATIC_GUARD(0x06B6A1u, 0xADu, 0x46u, 0x07u);
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
            TP_STATIC_EXIT(0x06u, 0xB6A4u, 0x0035B523u, 4u);
        }

        case 0x0035B523u: {
            TP_STATIC_GUARD(0x06B6A4u, 0xC9u, 0x10u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x10u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB6A6u, 0x0035B533u, 2u);
        }

        case 0x0035B533u: {
            TP_STATIC_GUARD(0x06B6A6u, 0xD0u, 0x15u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB6BDu;
                if (tp_scpu_expect_next(cpu, 0x0035B5EBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB6A8u, 0x0035B543u, 2u);
        }

        case 0x0035B543u: {
            TP_STATIC_GUARD(0x06B6A8u, 0xADu, 0x51u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1951u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB6ABu, 0x0035B55Bu, 4u);
        }

        case 0x0035B55Bu: {
            TP_STATIC_GUARD(0x06B6ABu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB6B0u;
                if (tp_scpu_expect_next(cpu, 0x0035B583u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB6ADu, 0x0035B56Bu, 2u);
        }

        case 0x0035B56Bu: {
            TP_STATIC_GUARD(0x06B6ADu, 0x82u, 0x8Cu, 0x01u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E3u, 4u);
        }

        case 0x0035B583u: {
            TP_STATIC_GUARD(0x06B6B0u, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB6B2u, 0x0035B593u, 2u);
        }

        case 0x0035B593u: {
            TP_STATIC_GUARD(0x06B6B2u, 0x22u, 0x0Au, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB5u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Au, 0x00276853u, 8u);
        }

        case 0x0035B5B3u: {
            TP_STATIC_GUARD(0x06B6B6u, 0x22u, 0xB5u, 0xBBu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB9u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBBB5u, 0x0035DDABu, 8u);
        }

        case 0x0035B5D0u: {
            TP_STATIC_GUARD(0x06B6BAu, 0x82u, 0x7Fu, 0x01u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E0u, 4u);
        }

        case 0x0035B5EBu: {
            TP_STATIC_GUARD(0x06B6BDu, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB6C0u, 0x0035B603u, 4u);
        }

        case 0x0035B603u: {
            TP_STATIC_GUARD(0x06B6C0u, 0xC9u, 0x02u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x02u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB6C2u, 0x0035B613u, 2u);
        }

        case 0x0035B613u: {
            TP_STATIC_GUARD(0x06B6C2u, 0xF0u, 0x07u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB6CBu;
                if (tp_scpu_expect_next(cpu, 0x0035B65Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB6C4u, 0x0035B623u, 2u);
        }

        case 0x0035B623u: {
            TP_STATIC_GUARD(0x06B6C4u, 0xADu, 0x46u, 0x07u);
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
            TP_STATIC_EXIT(0x06u, 0xB6C7u, 0x0035B63Bu, 4u);
        }

        case 0x0035B63Bu: {
            TP_STATIC_GUARD(0x06B6C7u, 0xC9u, 0x20u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x20u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB6C9u, 0x0035B64Bu, 2u);
        }

        case 0x0035B64Bu: {
            TP_STATIC_GUARD(0x06B6C9u, 0xD0u, 0x18u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB6E3u;
                if (tp_scpu_expect_next(cpu, 0x0035B71Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB6CBu, 0x0035B65Bu, 2u);
        }

        case 0x0035B65Bu: {
            TP_STATIC_GUARD(0x06B6CBu, 0xADu, 0x51u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1951u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB6CEu, 0x0035B673u, 4u);
        }

        case 0x0035B673u: {
            TP_STATIC_GUARD(0x06B6CEu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB6D3u;
                if (tp_scpu_expect_next(cpu, 0x0035B69Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB6D0u, 0x0035B683u, 2u);
        }

        case 0x0035B683u: {
            TP_STATIC_GUARD(0x06B6D0u, 0x82u, 0x69u, 0x01u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E3u, 4u);
        }

        case 0x0035B69Bu: {
            TP_STATIC_GUARD(0x06B6D3u, 0xA9u, 0x07u);
            const uint8_t value = 0x07u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB6D5u, 0x0035B6ABu, 2u);
        }

        case 0x0035B6ABu: {
            TP_STATIC_GUARD(0x06B6D5u, 0x22u, 0x0Au, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xD8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED0Au, 0x00276853u, 8u);
        }

        case 0x0035B6CBu: {
            TP_STATIC_GUARD(0x06B6D9u, 0x9Cu, 0x51u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1951u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xB6DCu, 0x0035B6E3u, 4u);
        }

        case 0x0035B6E3u: {
            TP_STATIC_GUARD(0x06B6DCu, 0x22u, 0xF9u, 0xBBu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDFu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBBF9u, 0x0035DFCBu, 8u);
        }

        case 0x0035B700u: {
            TP_STATIC_GUARD(0x06B6E0u, 0x82u, 0x59u, 0x01u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E0u, 4u);
        }

        case 0x0035B719u: {
            TP_STATIC_GUARD(0x06B6E3u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB6E5u, 0x0035B72Bu, 3u);
        }

        case 0x0035B71Bu: {
            TP_STATIC_GUARD(0x06B6E3u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xB6E5u, 0x0035B72Bu, 3u);
        }

        case 0x0035B72Bu: {
            TP_STATIC_GUARD(0x06B6E5u, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB6E8u, 0x0035B743u, 4u);
        }

        case 0x0035B743u: {
            TP_STATIC_GUARD(0x06B6E8u, 0xC9u, 0x40u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x40u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB6EAu, 0x0035B753u, 2u);
        }

        case 0x0035B753u: {
            TP_STATIC_GUARD(0x06B6EAu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB6EFu;
                if (tp_scpu_expect_next(cpu, 0x0035B77Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB6ECu, 0x0035B763u, 2u);
        }

        case 0x0035B763u: {
            TP_STATIC_GUARD(0x06B6ECu, 0x82u, 0x4Du, 0x01u);
            TP_STATIC_EXIT(0x06u, 0xB83Cu, 0x0035C1E3u, 4u);
        }

        case 0x0035B77Bu: {
            TP_STATIC_GUARD(0x06B6EFu, 0xADu, 0x51u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1951u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB6F2u, 0x0035B793u, 4u);
        }

        case 0x0035B793u: {
            TP_STATIC_GUARD(0x06B6F2u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xB6F7u;
                if (tp_scpu_expect_next(cpu, 0x0035B7BBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xB6F4u, 0x0035B7A3u, 2u);
        }

        case 0x0035B7A3u: {
            TP_STATIC_GUARD(0x06B6F4u, 0x82u, 0x5Eu, 0xF5u);
            TP_STATIC_EXIT(0x06u, 0xAC55u, 0x003562ABu, 4u);
        }

        case 0x0035B7BBu: {
            TP_STATIC_GUARD(0x06B6F7u, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB6F9u, 0x0035B7CBu, 2u);
        }

        case 0x0035B7CBu: {
            TP_STATIC_GUARD(0x06B6F9u, 0x22u, 0x14u, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xFCu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED14u, 0x002768A3u, 8u);
        }

        case 0x0035B7EBu: {
            TP_STATIC_GUARD(0x06B6FDu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xB6FFu, 0x0035B7F8u, 3u);
        }

        case 0x0035B7F8u: {
            TP_STATIC_GUARD(0x06B6FFu, 0xA9u, 0x11u, 0x00u);
            const uint16_t value = 0x0011u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xB702u, 0x0035B810u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
