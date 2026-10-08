/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0000AA(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00055002u: {
            TP_STATIC_GUARD(0x00AA00u, 0xAEu, 0xC1u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07C1u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA03u, 0x0005501Au, 5u);
        }

        case 0x0005501Au: {
            TP_STATIC_GUARD(0x00AA03u, 0xBFu, 0xD7u, 0x90u, 0x05u);
            const uint32_t address = (0x0590D7u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA07u, 0x0005503Au, 5u);
        }

        case 0x0005503Au: {
            TP_STATIC_GUARD(0x00AA07u, 0x10u, 0x08u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAA11u;
                if (tp_scpu_expect_next(cpu, 0x0005508Au) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAA09u, 0x0005504Au, 2u);
        }

        case 0x0005504Au: {
            TP_STATIC_GUARD(0x00AA09u, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA0Cu, 0x00055062u, 3u);
        }

        case 0x00055062u: {
            TP_STATIC_GUARD(0x00AA0Cu, 0x8Eu, 0xC1u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07C1u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAA0Fu, 0x0005507Au, 5u);
        }

        case 0x0005507Au: {
            TP_STATIC_GUARD(0x00AA0Fu, 0x80u, 0xF2u);
            TP_STATIC_EXIT(0x00u, 0xAA03u, 0x0005501Au, 3u);
        }

        case 0x0005508Au: {
            TP_STATIC_GUARD(0x00AA11u, 0xCDu, 0x54u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0754u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA14u, 0x000550A2u, 4u);
        }

        case 0x000550A2u: {
            TP_STATIC_GUARD(0x00AA14u, 0xB0u, 0x0Au);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAA20u;
                if (tp_scpu_expect_next(cpu, 0x00055102u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAA16u, 0x000550B2u, 2u);
        }

        case 0x000550B2u: {
            TP_STATIC_GUARD(0x00AA16u, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x00u, 0xAA19u, 0x000550CAu, 4u);
        }

        case 0x000550CAu: {
            TP_STATIC_GUARD(0x00AA19u, 0x09u, 0x02u);
            const uint8_t value = (uint8_t)(cpu->a | 0x02u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA1Bu, 0x000550DAu, 2u);
        }

        case 0x000550DAu: {
            TP_STATIC_GUARD(0x00AA1Bu, 0x8Du, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0747u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAA1Eu, 0x000550F2u, 4u);
        }

        case 0x000550F2u: {
            TP_STATIC_GUARD(0x00AA1Eu, 0x80u, 0x0Au);
            TP_STATIC_EXIT(0x00u, 0xAA2Au, 0x00055152u, 3u);
        }

        case 0x00055102u: {
            TP_STATIC_GUARD(0x00AA20u, 0xF0u, 0x08u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAA2Au;
                if (tp_scpu_expect_next(cpu, 0x00055152u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAA22u, 0x00055112u, 2u);
        }

        case 0x00055112u: {
            TP_STATIC_GUARD(0x00AA22u, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x00u, 0xAA25u, 0x0005512Au, 4u);
        }

        case 0x0005512Au: {
            TP_STATIC_GUARD(0x00AA25u, 0x09u, 0x01u);
            const uint8_t value = (uint8_t)(cpu->a | 0x01u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA27u, 0x0005513Au, 2u);
        }

        case 0x0005513Au: {
            TP_STATIC_GUARD(0x00AA27u, 0x8Du, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0747u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAA2Au, 0x00055152u, 4u);
        }

        case 0x00055152u: {
            TP_STATIC_GUARD(0x00AA2Au, 0xBFu, 0xD8u, 0x90u, 0x05u);
            const uint32_t address = (0x0590D8u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA2Eu, 0x00055172u, 5u);
        }

        case 0x00055172u: {
            TP_STATIC_GUARD(0x00AA2Eu, 0xCDu, 0x55u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0755u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA31u, 0x0005518Au, 4u);
        }

        case 0x0005518Au: {
            TP_STATIC_GUARD(0x00AA31u, 0xB0u, 0x0Au);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAA3Du;
                if (tp_scpu_expect_next(cpu, 0x000551EAu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAA33u, 0x0005519Au, 2u);
        }

        case 0x0005519Au: {
            TP_STATIC_GUARD(0x00AA33u, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x00u, 0xAA36u, 0x000551B2u, 4u);
        }

        case 0x000551B2u: {
            TP_STATIC_GUARD(0x00AA36u, 0x09u, 0x08u);
            const uint8_t value = (uint8_t)(cpu->a | 0x08u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA38u, 0x000551C2u, 2u);
        }

        case 0x000551C2u: {
            TP_STATIC_GUARD(0x00AA38u, 0x8Du, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0747u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAA3Bu, 0x000551DAu, 4u);
        }

        case 0x000551DAu: {
            TP_STATIC_GUARD(0x00AA3Bu, 0x80u, 0x23u);
            TP_STATIC_EXIT(0x00u, 0xAA60u, 0x00055302u, 3u);
        }

        case 0x000551EAu: {
            TP_STATIC_GUARD(0x00AA3Du, 0xF0u, 0x0Au);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAA49u;
                if (tp_scpu_expect_next(cpu, 0x0005524Au) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAA3Fu, 0x000551FAu, 2u);
        }

        case 0x000551FAu: {
            TP_STATIC_GUARD(0x00AA3Fu, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x00u, 0xAA42u, 0x00055212u, 4u);
        }

        case 0x00055212u: {
            TP_STATIC_GUARD(0x00AA42u, 0x09u, 0x04u);
            const uint8_t value = (uint8_t)(cpu->a | 0x04u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA44u, 0x00055222u, 2u);
        }

        case 0x00055222u: {
            TP_STATIC_GUARD(0x00AA44u, 0x8Du, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0747u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAA47u, 0x0005523Au, 4u);
        }

        case 0x0005523Au: {
            TP_STATIC_GUARD(0x00AA47u, 0x80u, 0x17u);
            TP_STATIC_EXIT(0x00u, 0xAA60u, 0x00055302u, 3u);
        }

        case 0x0005524Au: {
            TP_STATIC_GUARD(0x00AA49u, 0xBFu, 0xD7u, 0x90u, 0x05u);
            const uint32_t address = (0x0590D7u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA4Du, 0x0005526Au, 5u);
        }

        case 0x0005526Au: {
            TP_STATIC_GUARD(0x00AA4Du, 0xCDu, 0x54u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0754u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA50u, 0x00055282u, 4u);
        }

        case 0x00055282u: {
            TP_STATIC_GUARD(0x00AA50u, 0xD0u, 0x0Eu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAA60u;
                if (tp_scpu_expect_next(cpu, 0x00055302u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAA52u, 0x00055292u, 2u);
        }

        case 0x00055292u: {
            TP_STATIC_GUARD(0x00AA52u, 0xA2u, 0x5Au, 0x00u);
            const uint16_t value = 0x005Au;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA55u, 0x000552AAu, 3u);
        }

        case 0x000552AAu: {
            TP_STATIC_GUARD(0x00AA55u, 0x8Eu, 0xBFu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07BFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAA58u, 0x000552C2u, 5u);
        }

        case 0x000552C2u: {
            TP_STATIC_GUARD(0x00AA58u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xAA5Au, 0x000552D0u, 3u);
        }

        case 0x000552D0u: {
            TP_STATIC_GUARD(0x00AA5Au, 0xEEu, 0xC1u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07C1u;
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
            TP_STATIC_EXIT(0x00u, 0xAA5Du, 0x000552E8u, 8u);
        }

        case 0x000552E8u: {
            TP_STATIC_GUARD(0x00AA5Du, 0xEEu, 0xC1u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07C1u;
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
            TP_STATIC_EXIT(0x00u, 0xAA60u, 0x00055300u, 8u);
        }

        case 0x00055300u: {
            TP_STATIC_GUARD(0x00AA60u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAA62u, 0x00055313u, 3u);
        }

        case 0x00055301u: {
            TP_STATIC_GUARD(0x00AA60u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAA62u, 0x00055313u, 3u);
        }

        case 0x00055302u: {
            TP_STATIC_GUARD(0x00AA60u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAA62u, 0x00055313u, 3u);
        }

        case 0x00055303u: {
            TP_STATIC_GUARD(0x00AA60u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAA62u, 0x00055313u, 3u);
        }

        case 0x00055313u: {
            TP_STATIC_GUARD(0x00AA62u, 0xADu, 0x0Au, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x080Au;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA65u, 0x0005532Bu, 4u);
        }

        case 0x0005532Bu: {
            TP_STATIC_GUARD(0x00AA65u, 0xC9u, 0x11u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x11u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA67u, 0x0005533Bu, 2u);
        }

        case 0x0005533Bu: {
            TP_STATIC_GUARD(0x00AA67u, 0xD0u, 0x15u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAA7Eu;
                if (tp_scpu_expect_next(cpu, 0x000553F3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAA69u, 0x0005534Bu, 2u);
        }

        case 0x0005534Bu: {
            TP_STATIC_GUARD(0x00AA69u, 0xADu, 0x0Eu, 0x07u);
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
            TP_STATIC_EXIT(0x00u, 0xAA6Cu, 0x00055363u, 4u);
        }

        case 0x00055363u: {
            TP_STATIC_GUARD(0x00AA6Cu, 0xC9u, 0x0Fu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x0Fu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA6Eu, 0x00055373u, 2u);
        }

        case 0x00055373u: {
            TP_STATIC_GUARD(0x00AA6Eu, 0xF0u, 0x07u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAA77u;
                if (tp_scpu_expect_next(cpu, 0x000553BBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAA70u, 0x00055383u, 2u);
        }

        case 0x00055383u: {
            TP_STATIC_GUARD(0x00AA70u, 0x22u, 0x82u, 0xACu, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xAAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x73u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAC82u, 0x00056413u, 8u);
        }

        case 0x000553A1u: {
            TP_STATIC_GUARD(0x00AA74u, 0x82u, 0xCFu, 0x01u);
            TP_STATIC_EXIT(0x00u, 0xAC46u, 0x00056231u, 4u);
        }

        case 0x000553BBu: {
            TP_STATIC_GUARD(0x00AA77u, 0x22u, 0x8Cu, 0xB1u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xAAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x7Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xB18Cu, 0x00658C63u, 8u);
        }

        case 0x000553D9u: {
            TP_STATIC_GUARD(0x00AA7Bu, 0x82u, 0xC8u, 0x01u);
            TP_STATIC_EXIT(0x00u, 0xAC46u, 0x00056231u, 4u);
        }

        case 0x000553F3u: {
            TP_STATIC_GUARD(0x00AA7Eu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAA80u, 0x00055403u, 3u);
        }

        case 0x00055403u: {
            TP_STATIC_GUARD(0x00AA80u, 0xADu, 0x42u, 0x1Fu);
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
            TP_STATIC_EXIT(0x00u, 0xAA83u, 0x0005541Bu, 4u);
        }

        case 0x0005541Bu: {
            TP_STATIC_GUARD(0x00AA83u, 0xD0u, 0x3Fu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAAC4u;
                if (tp_scpu_expect_next(cpu, 0x00055623u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAA85u, 0x0005542Bu, 2u);
        }

        case 0x0005542Bu: {
            TP_STATIC_GUARD(0x00AA85u, 0xADu, 0xC4u, 0x1Fu);
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
            TP_STATIC_EXIT(0x00u, 0xAA88u, 0x00055443u, 4u);
        }

        case 0x00055443u: {
            TP_STATIC_GUARD(0x00AA88u, 0xD0u, 0x3Au);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAAC4u;
                if (tp_scpu_expect_next(cpu, 0x00055623u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAA8Au, 0x00055453u, 2u);
        }

        case 0x00055453u: {
            TP_STATIC_GUARD(0x00AA8Au, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x00u, 0xAA8Du, 0x0005546Bu, 4u);
        }

        case 0x0005546Bu: {
            TP_STATIC_GUARD(0x00AA8Du, 0x29u, 0x0Fu);
            const uint8_t value = (uint8_t)(cpu->a & 0x0Fu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA8Fu, 0x0005547Bu, 2u);
        }

        case 0x0005547Bu: {
            TP_STATIC_GUARD(0x00AA8Fu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAA94u;
                if (tp_scpu_expect_next(cpu, 0x000554A3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAA91u, 0x0005548Bu, 2u);
        }

        case 0x0005548Bu: {
            TP_STATIC_GUARD(0x00AA91u, 0x82u, 0x90u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xAB24u, 0x00055923u, 4u);
        }

        case 0x000554A3u: {
            TP_STATIC_GUARD(0x00AA94u, 0xADu, 0x4Bu, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x194Bu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAA97u, 0x000554BBu, 4u);
        }

        case 0x000554BBu: {
            TP_STATIC_GUARD(0x00AA97u, 0x9Cu, 0x4Bu, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x194Bu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAA9Au, 0x000554D3u, 4u);
        }

        case 0x000554D3u: {
            TP_STATIC_GUARD(0x00AA9Au, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAA9Fu;
                if (tp_scpu_expect_next(cpu, 0x000554FBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAA9Cu, 0x000554E3u, 2u);
        }

        case 0x000554E3u: {
            TP_STATIC_GUARD(0x00AA9Cu, 0x82u, 0x85u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xAB24u, 0x00055923u, 4u);
        }

        case 0x000554FBu: {
            TP_STATIC_GUARD(0x00AA9Fu, 0xADu, 0xE7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18E7u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAAA2u, 0x00055513u, 4u);
        }

        case 0x00055513u: {
            TP_STATIC_GUARD(0x00AAA2u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAAA7u;
                if (tp_scpu_expect_next(cpu, 0x0005553Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAAA4u, 0x00055523u, 2u);
        }

        case 0x00055523u: {
            TP_STATIC_GUARD(0x00AAA4u, 0x82u, 0x7Du, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xAB24u, 0x00055923u, 4u);
        }

        case 0x0005553Bu: {
            TP_STATIC_GUARD(0x00AAA7u, 0xADu, 0xC4u, 0x1Fu);
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
            TP_STATIC_EXIT(0x00u, 0xAAAAu, 0x00055553u, 4u);
        }

        case 0x00055553u: {
            TP_STATIC_GUARD(0x00AAAAu, 0xD0u, 0x78u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB24u;
                if (tp_scpu_expect_next(cpu, 0x00055923u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAAACu, 0x00055563u, 2u);
        }

        case 0x00055563u: {
            TP_STATIC_GUARD(0x00AAACu, 0xADu, 0x11u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0711u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAAAFu, 0x0005557Bu, 4u);
        }

        case 0x0005557Bu: {
            TP_STATIC_GUARD(0x00AAAFu, 0xD0u, 0x73u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB24u;
                if (tp_scpu_expect_next(cpu, 0x00055923u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAAB1u, 0x0005558Bu, 2u);
        }

        case 0x0005558Bu: {
            TP_STATIC_GUARD(0x00AAB1u, 0xADu, 0x46u, 0x07u);
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
            TP_STATIC_EXIT(0x00u, 0xAAB4u, 0x000555A3u, 4u);
        }

        case 0x000555A3u: {
            TP_STATIC_GUARD(0x00AAB4u, 0x29u, 0x40u);
            const uint8_t value = (uint8_t)(cpu->a & 0x40u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAAB6u, 0x000555B3u, 2u);
        }

        case 0x000555B3u: {
            TP_STATIC_GUARD(0x00AAB6u, 0xD0u, 0x6Cu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB24u;
                if (tp_scpu_expect_next(cpu, 0x00055923u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAAB8u, 0x000555C3u, 2u);
        }

        case 0x000555C3u: {
            TP_STATIC_GUARD(0x00AAB8u, 0xADu, 0x72u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1872u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAABBu, 0x000555DBu, 4u);
        }

        case 0x000555DBu: {
            TP_STATIC_GUARD(0x00AABBu, 0xD0u, 0x67u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB24u;
                if (tp_scpu_expect_next(cpu, 0x00055923u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAABDu, 0x000555EBu, 2u);
        }

        case 0x000555EBu: {
            TP_STATIC_GUARD(0x00AABDu, 0xADu, 0x0Eu, 0x07u);
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
            TP_STATIC_EXIT(0x00u, 0xAAC0u, 0x00055603u, 4u);
        }

        case 0x00055603u: {
            TP_STATIC_GUARD(0x00AAC0u, 0xC9u, 0x0Fu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x0Fu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAAC2u, 0x00055613u, 2u);
        }

        case 0x00055613u: {
            TP_STATIC_GUARD(0x00AAC2u, 0xD0u, 0x60u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB24u;
                if (tp_scpu_expect_next(cpu, 0x00055923u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAAC4u, 0x00055623u, 2u);
        }

        case 0x00055623u: {
            TP_STATIC_GUARD(0x00AAC4u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAAC6u, 0x00055633u, 3u);
        }

        case 0x00055633u: {
            TP_STATIC_GUARD(0x00AAC6u, 0xADu, 0xCBu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18CBu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAAC9u, 0x0005564Bu, 4u);
        }

        case 0x0005564Bu: {
            TP_STATIC_GUARD(0x00AAC9u, 0xC9u, 0x03u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x03u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAACBu, 0x0005565Bu, 2u);
        }

        case 0x0005565Bu: {
            TP_STATIC_GUARD(0x00AACBu, 0xD0u, 0x04u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAAD1u;
                if (tp_scpu_expect_next(cpu, 0x0005568Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAACDu, 0x0005566Bu, 2u);
        }

        case 0x0005566Bu: {
            TP_STATIC_GUARD(0x00AACDu, 0xA9u, 0x05u);
            const uint8_t value = 0x05u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAACFu, 0x0005567Bu, 2u);
        }

        case 0x0005567Bu: {
            TP_STATIC_GUARD(0x00AACFu, 0x80u, 0x06u);
            TP_STATIC_EXIT(0x00u, 0xAAD7u, 0x000556BBu, 3u);
        }

        case 0x0005568Bu: {
            TP_STATIC_GUARD(0x00AAD1u, 0xC9u, 0x04u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x04u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAAD3u, 0x0005569Bu, 2u);
        }

        case 0x0005569Bu: {
            TP_STATIC_GUARD(0x00AAD3u, 0xD0u, 0x02u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAAD7u;
                if (tp_scpu_expect_next(cpu, 0x000556BBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAAD5u, 0x000556ABu, 2u);
        }

        case 0x000556ABu: {
            TP_STATIC_GUARD(0x00AAD5u, 0xA9u, 0x09u);
            const uint8_t value = 0x09u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAAD7u, 0x000556BBu, 2u);
        }

        case 0x000556BBu: {
            TP_STATIC_GUARD(0x00AAD7u, 0x8Du, 0xCCu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18CCu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAADAu, 0x000556D3u, 4u);
        }

        case 0x000556D3u: {
            TP_STATIC_GUARD(0x00AADAu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAADCu, 0x000556E3u, 3u);
        }

        case 0x000556E3u: {
            TP_STATIC_GUARD(0x00AADCu, 0xADu, 0x44u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0744u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAADFu, 0x000556FBu, 4u);
        }

        case 0x000556FBu: {
            TP_STATIC_GUARD(0x00AADFu, 0x29u, 0x40u);
            const uint8_t value = (uint8_t)(cpu->a & 0x40u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAAE1u, 0x0005570Bu, 2u);
        }

        case 0x0005570Bu: {
            TP_STATIC_GUARD(0x00AAE1u, 0xD0u, 0x41u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAB24u;
                if (tp_scpu_expect_next(cpu, 0x00055923u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAAE3u, 0x0005571Bu, 2u);
        }

        case 0x0005571Bu: {
            TP_STATIC_GUARD(0x00AAE3u, 0x22u, 0xC3u, 0xC5u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xAAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE6u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xC5C3u, 0x00262E1Bu, 8u);
        }

        case 0x00055739u: {
            TP_STATIC_GUARD(0x00AAE7u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAAE9u, 0x0005574Bu, 3u);
        }

        case 0x0005574Bu: {
            TP_STATIC_GUARD(0x00AAE9u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAAEBu, 0x0005575Bu, 3u);
        }

        case 0x0005575Bu: {
            TP_STATIC_GUARD(0x00AAEBu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xAAEDu, 0x00055769u, 3u);
        }

        case 0x00055769u: {
            TP_STATIC_GUARD(0x00AAEDu, 0xADu, 0x3Au, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x003Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAAF0u, 0x00055781u, 5u);
        }

        case 0x00055781u: {
            TP_STATIC_GUARD(0x00AAF0u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x00u, 0xAAF1u, 0x00055789u, 2u);
        }

        case 0x00055789u: {
            TP_STATIC_GUARD(0x00AAF1u, 0x69u, 0x93u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0093u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAAF4u, 0x000557A1u, 3u);
        }

        case 0x000557A1u: {
            TP_STATIC_GUARD(0x00AAF4u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAAF7u, 0x000557B9u, 5u);
        }

        case 0x000557B9u: {
            TP_STATIC_GUARD(0x00AAF7u, 0xAEu, 0x3Cu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x003Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAAFAu, 0x000557D1u, 4u);
        }

        case 0x000557D1u: {
            TP_STATIC_GUARD(0x00AAFAu, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAAFDu, 0x000557E9u, 4u);
        }

        case 0x000557E9u: {
            TP_STATIC_GUARD(0x00AAFDu, 0xA9u, 0x8Eu, 0x8Fu);
            const uint16_t value = 0x8F8Eu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAB00u, 0x00055801u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
