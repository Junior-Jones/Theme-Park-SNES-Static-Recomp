/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000C9E(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x0064F012u: {
            TP_STATIC_GUARD(0x0C9E02u, 0x29u, 0x80u);
            const uint8_t value = (uint8_t)(cpu->a & 0x80u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E04u, 0x0064F022u, 2u);
        }

        case 0x0064F022u: {
            TP_STATIC_GUARD(0x0C9E04u, 0xD0u, 0x0Au);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9E10u;
                if (tp_scpu_expect_next(cpu, 0x0064F082u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9E06u, 0x0064F032u, 2u);
        }

        case 0x0064F032u: {
            TP_STATIC_GUARD(0x0C9E06u, 0xADu, 0x0Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Du;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E09u, 0x0064F04Au, 4u);
        }

        case 0x0064F04Au: {
            TP_STATIC_GUARD(0x0C9E09u, 0x29u, 0x7Fu);
            const uint8_t value = (uint8_t)(cpu->a & 0x7Fu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E0Bu, 0x0064F05Au, 2u);
        }

        case 0x0064F05Au: {
            TP_STATIC_GUARD(0x0C9E0Bu, 0x8Du, 0x0Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Du) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9E0Eu, 0x0064F072u, 4u);
        }

        case 0x0064F072u: {
            TP_STATIC_GUARD(0x0C9E0Eu, 0x80u, 0x19u);
            TP_STATIC_EXIT(0x0Cu, 0x9E29u, 0x0064F14Au, 3u);
        }

        case 0x0064F082u: {
            TP_STATIC_GUARD(0x0C9E10u, 0xADu, 0x0Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Du;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E13u, 0x0064F09Au, 4u);
        }

        case 0x0064F09Au: {
            TP_STATIC_GUARD(0x0C9E13u, 0x29u, 0x80u);
            const uint8_t value = (uint8_t)(cpu->a & 0x80u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E15u, 0x0064F0AAu, 2u);
        }

        case 0x0064F0AAu: {
            TP_STATIC_GUARD(0x0C9E15u, 0xF0u, 0x0Au);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9E21u;
                if (tp_scpu_expect_next(cpu, 0x0064F10Au) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9E17u, 0x0064F0BAu, 2u);
        }

        case 0x0064F0BAu: {
            TP_STATIC_GUARD(0x0C9E17u, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x0Cu, 0x9E1Au, 0x0064F0D2u, 4u);
        }

        case 0x0064F0D2u: {
            TP_STATIC_GUARD(0x0C9E1Au, 0x29u, 0x7Fu);
            const uint8_t value = (uint8_t)(cpu->a & 0x7Fu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E1Cu, 0x0064F0E2u, 2u);
        }

        case 0x0064F0E2u: {
            TP_STATIC_GUARD(0x0C9E1Cu, 0x8Du, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0747u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9E1Fu, 0x0064F0FAu, 4u);
        }

        case 0x0064F0FAu: {
            TP_STATIC_GUARD(0x0C9E1Fu, 0x80u, 0x08u);
            TP_STATIC_EXIT(0x0Cu, 0x9E29u, 0x0064F14Au, 3u);
        }

        case 0x0064F10Au: {
            TP_STATIC_GUARD(0x0C9E21u, 0xADu, 0x0Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Du;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E24u, 0x0064F122u, 4u);
        }

        case 0x0064F122u: {
            TP_STATIC_GUARD(0x0C9E24u, 0x09u, 0x80u);
            const uint8_t value = (uint8_t)(cpu->a | 0x80u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E26u, 0x0064F132u, 2u);
        }

        case 0x0064F132u: {
            TP_STATIC_GUARD(0x0C9E26u, 0x8Du, 0x0Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Du) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9E29u, 0x0064F14Au, 4u);
        }

        case 0x0064F14Au: {
            TP_STATIC_GUARD(0x0C9E29u, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x0Cu, 0x9E2Cu, 0x0064F162u, 4u);
        }

        case 0x0064F162u: {
            TP_STATIC_GUARD(0x0C9E2Cu, 0x29u, 0x10u);
            const uint8_t value = (uint8_t)(cpu->a & 0x10u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E2Eu, 0x0064F172u, 2u);
        }

        case 0x0064F172u: {
            TP_STATIC_GUARD(0x0C9E2Eu, 0xD0u, 0x0Au);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9E3Au;
                if (tp_scpu_expect_next(cpu, 0x0064F1D2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9E30u, 0x0064F182u, 2u);
        }

        case 0x0064F182u: {
            TP_STATIC_GUARD(0x0C9E30u, 0xADu, 0x0Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Du;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E33u, 0x0064F19Au, 4u);
        }

        case 0x0064F19Au: {
            TP_STATIC_GUARD(0x0C9E33u, 0x29u, 0xEFu);
            const uint8_t value = (uint8_t)(cpu->a & 0xEFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E35u, 0x0064F1AAu, 2u);
        }

        case 0x0064F1AAu: {
            TP_STATIC_GUARD(0x0C9E35u, 0x8Du, 0x0Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Du) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9E38u, 0x0064F1C2u, 4u);
        }

        case 0x0064F1C2u: {
            TP_STATIC_GUARD(0x0C9E38u, 0x80u, 0x19u);
            TP_STATIC_EXIT(0x0Cu, 0x9E53u, 0x0064F29Au, 3u);
        }

        case 0x0064F1D2u: {
            TP_STATIC_GUARD(0x0C9E3Au, 0xADu, 0x0Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Du;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E3Du, 0x0064F1EAu, 4u);
        }

        case 0x0064F1EAu: {
            TP_STATIC_GUARD(0x0C9E3Du, 0x29u, 0x10u);
            const uint8_t value = (uint8_t)(cpu->a & 0x10u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E3Fu, 0x0064F1FAu, 2u);
        }

        case 0x0064F1FAu: {
            TP_STATIC_GUARD(0x0C9E3Fu, 0xF0u, 0x0Au);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9E4Bu;
                if (tp_scpu_expect_next(cpu, 0x0064F25Au) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9E41u, 0x0064F20Au, 2u);
        }

        case 0x0064F20Au: {
            TP_STATIC_GUARD(0x0C9E41u, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x0Cu, 0x9E44u, 0x0064F222u, 4u);
        }

        case 0x0064F222u: {
            TP_STATIC_GUARD(0x0C9E44u, 0x29u, 0xEFu);
            const uint8_t value = (uint8_t)(cpu->a & 0xEFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E46u, 0x0064F232u, 2u);
        }

        case 0x0064F232u: {
            TP_STATIC_GUARD(0x0C9E46u, 0x8Du, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0747u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9E49u, 0x0064F24Au, 4u);
        }

        case 0x0064F24Au: {
            TP_STATIC_GUARD(0x0C9E49u, 0x80u, 0x08u);
            TP_STATIC_EXIT(0x0Cu, 0x9E53u, 0x0064F29Au, 3u);
        }

        case 0x0064F25Au: {
            TP_STATIC_GUARD(0x0C9E4Bu, 0xADu, 0x0Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Du;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E4Eu, 0x0064F272u, 4u);
        }

        case 0x0064F272u: {
            TP_STATIC_GUARD(0x0C9E4Eu, 0x09u, 0x10u);
            const uint8_t value = (uint8_t)(cpu->a | 0x10u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E50u, 0x0064F282u, 2u);
        }

        case 0x0064F282u: {
            TP_STATIC_GUARD(0x0C9E50u, 0x8Du, 0x0Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Du) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9E53u, 0x0064F29Au, 4u);
        }

        case 0x0064F29Au: {
            TP_STATIC_GUARD(0x0C9E53u, 0xADu, 0x46u, 0x07u);
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
            TP_STATIC_EXIT(0x0Cu, 0x9E56u, 0x0064F2B2u, 4u);
        }

        case 0x0064F2B2u: {
            TP_STATIC_GUARD(0x0C9E56u, 0x29u, 0x80u);
            const uint8_t value = (uint8_t)(cpu->a & 0x80u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E58u, 0x0064F2C2u, 2u);
        }

        case 0x0064F2C2u: {
            TP_STATIC_GUARD(0x0C9E58u, 0xD0u, 0x0Au);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9E64u;
                if (tp_scpu_expect_next(cpu, 0x0064F322u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9E5Au, 0x0064F2D2u, 2u);
        }

        case 0x0064F2D2u: {
            TP_STATIC_GUARD(0x0C9E5Au, 0xADu, 0x0Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E5Du, 0x0064F2EAu, 4u);
        }

        case 0x0064F2EAu: {
            TP_STATIC_GUARD(0x0C9E5Du, 0x29u, 0x7Fu);
            const uint8_t value = (uint8_t)(cpu->a & 0x7Fu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E5Fu, 0x0064F2FAu, 2u);
        }

        case 0x0064F2FAu: {
            TP_STATIC_GUARD(0x0C9E5Fu, 0x8Du, 0x0Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9E62u, 0x0064F312u, 4u);
        }

        case 0x0064F312u: {
            TP_STATIC_GUARD(0x0C9E62u, 0x80u, 0x19u);
            TP_STATIC_EXIT(0x0Cu, 0x9E7Du, 0x0064F3EAu, 3u);
        }

        case 0x0064F322u: {
            TP_STATIC_GUARD(0x0C9E64u, 0xADu, 0x0Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E67u, 0x0064F33Au, 4u);
        }

        case 0x0064F33Au: {
            TP_STATIC_GUARD(0x0C9E67u, 0x29u, 0x80u);
            const uint8_t value = (uint8_t)(cpu->a & 0x80u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E69u, 0x0064F34Au, 2u);
        }

        case 0x0064F34Au: {
            TP_STATIC_GUARD(0x0C9E69u, 0xF0u, 0x0Au);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9E75u;
                if (tp_scpu_expect_next(cpu, 0x0064F3AAu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9E6Bu, 0x0064F35Au, 2u);
        }

        case 0x0064F35Au: {
            TP_STATIC_GUARD(0x0C9E6Bu, 0xADu, 0x46u, 0x07u);
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
            TP_STATIC_EXIT(0x0Cu, 0x9E6Eu, 0x0064F372u, 4u);
        }

        case 0x0064F372u: {
            TP_STATIC_GUARD(0x0C9E6Eu, 0x29u, 0x7Fu);
            const uint8_t value = (uint8_t)(cpu->a & 0x7Fu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E70u, 0x0064F382u, 2u);
        }

        case 0x0064F382u: {
            TP_STATIC_GUARD(0x0C9E70u, 0x8Du, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0746u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9E73u, 0x0064F39Au, 4u);
        }

        case 0x0064F39Au: {
            TP_STATIC_GUARD(0x0C9E73u, 0x80u, 0x08u);
            TP_STATIC_EXIT(0x0Cu, 0x9E7Du, 0x0064F3EAu, 3u);
        }

        case 0x0064F3AAu: {
            TP_STATIC_GUARD(0x0C9E75u, 0xADu, 0x0Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E78u, 0x0064F3C2u, 4u);
        }

        case 0x0064F3C2u: {
            TP_STATIC_GUARD(0x0C9E78u, 0x09u, 0x80u);
            const uint8_t value = (uint8_t)(cpu->a | 0x80u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E7Au, 0x0064F3D2u, 2u);
        }

        case 0x0064F3D2u: {
            TP_STATIC_GUARD(0x0C9E7Au, 0x8Du, 0x0Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9E7Du, 0x0064F3EAu, 4u);
        }

        case 0x0064F3EAu: {
            TP_STATIC_GUARD(0x0C9E7Du, 0xADu, 0x46u, 0x07u);
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
            TP_STATIC_EXIT(0x0Cu, 0x9E80u, 0x0064F402u, 4u);
        }

        case 0x0064F402u: {
            TP_STATIC_GUARD(0x0C9E80u, 0x29u, 0x40u);
            const uint8_t value = (uint8_t)(cpu->a & 0x40u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E82u, 0x0064F412u, 2u);
        }

        case 0x0064F412u: {
            TP_STATIC_GUARD(0x0C9E82u, 0xD0u, 0x0Au);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9E8Eu;
                if (tp_scpu_expect_next(cpu, 0x0064F472u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9E84u, 0x0064F422u, 2u);
        }

        case 0x0064F422u: {
            TP_STATIC_GUARD(0x0C9E84u, 0xADu, 0x0Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E87u, 0x0064F43Au, 4u);
        }

        case 0x0064F43Au: {
            TP_STATIC_GUARD(0x0C9E87u, 0x29u, 0xBFu);
            const uint8_t value = (uint8_t)(cpu->a & 0xBFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E89u, 0x0064F44Au, 2u);
        }

        case 0x0064F44Au: {
            TP_STATIC_GUARD(0x0C9E89u, 0x8Du, 0x0Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9E8Cu, 0x0064F462u, 4u);
        }

        case 0x0064F462u: {
            TP_STATIC_GUARD(0x0C9E8Cu, 0x80u, 0x19u);
            TP_STATIC_EXIT(0x0Cu, 0x9EA7u, 0x0064F53Au, 3u);
        }

        case 0x0064F472u: {
            TP_STATIC_GUARD(0x0C9E8Eu, 0xADu, 0x0Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E91u, 0x0064F48Au, 4u);
        }

        case 0x0064F48Au: {
            TP_STATIC_GUARD(0x0C9E91u, 0x29u, 0x40u);
            const uint8_t value = (uint8_t)(cpu->a & 0x40u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E93u, 0x0064F49Au, 2u);
        }

        case 0x0064F49Au: {
            TP_STATIC_GUARD(0x0C9E93u, 0xF0u, 0x0Au);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9E9Fu;
                if (tp_scpu_expect_next(cpu, 0x0064F4FAu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9E95u, 0x0064F4AAu, 2u);
        }

        case 0x0064F4AAu: {
            TP_STATIC_GUARD(0x0C9E95u, 0xADu, 0x46u, 0x07u);
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
            TP_STATIC_EXIT(0x0Cu, 0x9E98u, 0x0064F4C2u, 4u);
        }

        case 0x0064F4C2u: {
            TP_STATIC_GUARD(0x0C9E98u, 0x29u, 0xBFu);
            const uint8_t value = (uint8_t)(cpu->a & 0xBFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9E9Au, 0x0064F4D2u, 2u);
        }

        case 0x0064F4D2u: {
            TP_STATIC_GUARD(0x0C9E9Au, 0x8Du, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0746u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9E9Du, 0x0064F4EAu, 4u);
        }

        case 0x0064F4EAu: {
            TP_STATIC_GUARD(0x0C9E9Du, 0x80u, 0x08u);
            TP_STATIC_EXIT(0x0Cu, 0x9EA7u, 0x0064F53Au, 3u);
        }

        case 0x0064F4FAu: {
            TP_STATIC_GUARD(0x0C9E9Fu, 0xADu, 0x0Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9EA2u, 0x0064F512u, 4u);
        }

        case 0x0064F512u: {
            TP_STATIC_GUARD(0x0C9EA2u, 0x09u, 0x40u);
            const uint8_t value = (uint8_t)(cpu->a | 0x40u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9EA4u, 0x0064F522u, 2u);
        }

        case 0x0064F522u: {
            TP_STATIC_GUARD(0x0C9EA4u, 0x8Du, 0x0Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9EA7u, 0x0064F53Au, 4u);
        }

        case 0x0064F53Au: {
            TP_STATIC_GUARD(0x0C9EA7u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x9EA9u, 0x0064F54Bu, 3u);
        }

        case 0x0064F54Bu: {
            TP_STATIC_GUARD(0x0C9EA9u, 0xADu, 0xC4u, 0x1Fu);
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
            TP_STATIC_EXIT(0x0Cu, 0x9EACu, 0x0064F563u, 4u);
        }

        case 0x0064F563u: {
            TP_STATIC_GUARD(0x0C9EACu, 0xF0u, 0x45u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9EF3u;
                if (tp_scpu_expect_next(cpu, 0x0064F79Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9EAEu, 0x0064F573u, 2u);
        }

        case 0x0064F573u: {
            TP_STATIC_GUARD(0x0C9EAEu, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x0Cu, 0x9EB1u, 0x0064F58Bu, 4u);
        }

        case 0x0064F58Bu: {
            TP_STATIC_GUARD(0x0C9EB1u, 0x29u, 0x0Fu);
            const uint8_t value = (uint8_t)(cpu->a & 0x0Fu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9EB3u, 0x0064F59Bu, 2u);
        }

        case 0x0064F59Bu: {
            TP_STATIC_GUARD(0x0C9EB3u, 0xD0u, 0x08u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9EBDu;
                if (tp_scpu_expect_next(cpu, 0x0064F5EBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9EB5u, 0x0064F5ABu, 2u);
        }

        case 0x0064F5ABu: {
            TP_STATIC_GUARD(0x0C9EB5u, 0x9Cu, 0xF4u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18F4u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9EB8u, 0x0064F5C3u, 4u);
        }

        case 0x0064F5C3u: {
            TP_STATIC_GUARD(0x0C9EB8u, 0x9Cu, 0xF3u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18F3u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9EBBu, 0x0064F5DBu, 4u);
        }

        case 0x0064F5DBu: {
            TP_STATIC_GUARD(0x0C9EBBu, 0x80u, 0x36u);
            TP_STATIC_EXIT(0x0Cu, 0x9EF3u, 0x0064F79Bu, 3u);
        }

        case 0x0064F5EBu: {
            TP_STATIC_GUARD(0x0C9EBDu, 0xADu, 0xF4u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18F4u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9EC0u, 0x0064F603u, 4u);
        }

        case 0x0064F603u: {
            TP_STATIC_GUARD(0x0C9EC0u, 0xCDu, 0xF3u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18F3u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9EC3u, 0x0064F61Bu, 4u);
        }

        case 0x0064F61Bu: {
            TP_STATIC_GUARD(0x0C9EC3u, 0x90u, 0x24u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9EE9u;
                if (tp_scpu_expect_next(cpu, 0x0064F74Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9EC5u, 0x0064F62Bu, 2u);
        }

        case 0x0064F62Bu: {
            TP_STATIC_GUARD(0x0C9EC5u, 0x9Cu, 0xF4u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18F4u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9EC8u, 0x0064F643u, 4u);
        }

        case 0x0064F643u: {
            TP_STATIC_GUARD(0x0C9EC8u, 0xADu, 0xF3u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18F3u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9ECBu, 0x0064F65Bu, 4u);
        }

        case 0x0064F65Bu: {
            TP_STATIC_GUARD(0x0C9ECBu, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9ED4u;
                if (tp_scpu_expect_next(cpu, 0x0064F6A3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9ECDu, 0x0064F66Bu, 2u);
        }

        case 0x0064F66Bu: {
            TP_STATIC_GUARD(0x0C9ECDu, 0xA9u, 0x0Fu);
            const uint8_t value = 0x0Fu;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9ECFu, 0x0064F67Bu, 2u);
        }

        case 0x0064F67Bu: {
            TP_STATIC_GUARD(0x0C9ECFu, 0x8Du, 0xF3u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18F3u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9ED2u, 0x0064F693u, 4u);
        }

        case 0x0064F693u: {
            TP_STATIC_GUARD(0x0C9ED2u, 0x80u, 0x62u);
            TP_STATIC_EXIT(0x0Cu, 0x9F36u, 0x0064F9B3u, 3u);
        }

        case 0x0064F6A3u: {
            TP_STATIC_GUARD(0x0C9ED4u, 0xADu, 0x0Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Au;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9ED7u, 0x0064F6BBu, 4u);
        }

        case 0x0064F6BBu: {
            TP_STATIC_GUARD(0x0C9ED7u, 0xC9u, 0xB4u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0xB4u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9ED9u, 0x0064F6CBu, 2u);
        }

        case 0x0064F6CBu: {
            TP_STATIC_GUARD(0x0C9ED9u, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9EE2u;
                if (tp_scpu_expect_next(cpu, 0x0064F713u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9EDBu, 0x0064F6DBu, 2u);
        }

        case 0x0064F6DBu: {
            TP_STATIC_GUARD(0x0C9EDBu, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9EDDu, 0x0064F6EBu, 2u);
        }

        case 0x0064F6EBu: {
            TP_STATIC_GUARD(0x0C9EDDu, 0x8Du, 0xF3u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18F3u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9EE0u, 0x0064F703u, 4u);
        }

        case 0x0064F703u: {
            TP_STATIC_GUARD(0x0C9EE0u, 0x80u, 0x54u);
            TP_STATIC_EXIT(0x0Cu, 0x9F36u, 0x0064F9B3u, 3u);
        }

        case 0x0064F713u: {
            TP_STATIC_GUARD(0x0C9EE2u, 0xA9u, 0x03u);
            const uint8_t value = 0x03u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9EE4u, 0x0064F723u, 2u);
        }

        case 0x0064F723u: {
            TP_STATIC_GUARD(0x0C9EE4u, 0x8Du, 0xF3u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18F3u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9EE7u, 0x0064F73Bu, 4u);
        }

        case 0x0064F73Bu: {
            TP_STATIC_GUARD(0x0C9EE7u, 0x80u, 0x4Du);
            TP_STATIC_EXIT(0x0Cu, 0x9F36u, 0x0064F9B3u, 3u);
        }

        case 0x0064F74Bu: {
            TP_STATIC_GUARD(0x0C9EE9u, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x0Cu, 0x9EECu, 0x0064F763u, 4u);
        }

        case 0x0064F763u: {
            TP_STATIC_GUARD(0x0C9EECu, 0x29u, 0xF0u);
            const uint8_t value = (uint8_t)(cpu->a & 0xF0u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9EEEu, 0x0064F773u, 2u);
        }

        case 0x0064F773u: {
            TP_STATIC_GUARD(0x0C9EEEu, 0x8Du, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0747u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9EF1u, 0x0064F78Bu, 4u);
        }

        case 0x0064F78Bu: {
            TP_STATIC_GUARD(0x0C9EF1u, 0x80u, 0x43u);
            TP_STATIC_EXIT(0x0Cu, 0x9F36u, 0x0064F9B3u, 3u);
        }

        case 0x0064F79Bu: {
            TP_STATIC_GUARD(0x0C9EF3u, 0xADu, 0x42u, 0x1Fu);
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
            TP_STATIC_EXIT(0x0Cu, 0x9EF6u, 0x0064F7B3u, 4u);
        }

        case 0x0064F7B3u: {
            TP_STATIC_GUARD(0x0C9EF6u, 0xD0u, 0x3Eu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9F36u;
                if (tp_scpu_expect_next(cpu, 0x0064F9B3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9EF8u, 0x0064F7C3u, 2u);
        }

        case 0x0064F7C3u: {
            TP_STATIC_GUARD(0x0C9EF8u, 0xADu, 0x46u, 0x07u);
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
            TP_STATIC_EXIT(0x0Cu, 0x9EFBu, 0x0064F7DBu, 4u);
        }

        case 0x0064F7DBu: {
            TP_STATIC_GUARD(0x0C9EFBu, 0x29u, 0x30u);
            const uint8_t value = (uint8_t)(cpu->a & 0x30u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9EFDu, 0x0064F7EBu, 2u);
        }

        case 0x0064F7EBu: {
            TP_STATIC_GUARD(0x0C9EFDu, 0xD0u, 0x08u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9F07u;
                if (tp_scpu_expect_next(cpu, 0x0064F83Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x9EFFu, 0x0064F7FBu, 2u);
        }

        case 0x0064F7FBu: {
            TP_STATIC_GUARD(0x0C9EFFu, 0x9Cu, 0xF5u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18F5u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9F02u, 0x0064F813u, 4u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
