/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0000C1(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00060808u: {
            TP_STATIC_GUARD(0x00C101u, 0x22u, 0x53u, 0xBCu, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x04u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xBC53u, 0x0005E298u, 8u);
        }

        case 0x00060829u: {
            TP_STATIC_GUARD(0x00C105u, 0x82u, 0x24u, 0x01u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061161u, 4u);
        }

        case 0x00060843u: {
            TP_STATIC_GUARD(0x00C108u, 0xC9u, 0x08u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x08u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC10Au, 0x00060853u, 2u);
        }

        case 0x00060853u: {
            TP_STATIC_GUARD(0x00C10Au, 0xD0u, 0x21u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC12Du;
                if (tp_scpu_expect_next(cpu, 0x0006096Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC10Cu, 0x00060863u, 2u);
        }

        case 0x00060863u: {
            TP_STATIC_GUARD(0x00C10Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC10Eu, 0x00060870u, 3u);
        }

        case 0x00060870u: {
            TP_STATIC_GUARD(0x00C10Eu, 0xACu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC111u, 0x00060888u, 5u);
        }

        case 0x00060888u: {
            TP_STATIC_GUARD(0x00C111u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC112u, 0x00060890u, 2u);
        }

        case 0x00060890u: {
            TP_STATIC_GUARD(0x00C112u, 0xA9u, 0x0Eu, 0x00u);
            const uint16_t value = 0x000Eu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC115u, 0x000608A8u, 3u);
        }

        case 0x000608A8u: {
            TP_STATIC_GUARD(0x00C115u, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x18u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x000608C8u: {
            TP_STATIC_GUARD(0x00C119u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC11Au, 0x000608D0u, 2u);
        }

        case 0x000608D0u: {
            TP_STATIC_GUARD(0x00C11Au, 0xB9u, 0xD8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07D8u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC11Du, 0x000608E8u, 6u);
        }

        case 0x000608E8u: {
            TP_STATIC_GUARD(0x00C11Du, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC120u, 0x00060900u, 5u);
        }

        case 0x00060900u: {
            TP_STATIC_GUARD(0x00C120u, 0xA9u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC123u, 0x00060918u, 3u);
        }

        case 0x00060918u: {
            TP_STATIC_GUARD(0x00C123u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC126u, 0x00060930u, 5u);
        }

        case 0x00060930u: {
            TP_STATIC_GUARD(0x00C126u, 0x22u, 0xE3u, 0x9Au, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x29u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9AE3u, 0x003CD718u, 8u);
        }

        case 0x00060951u: {
            TP_STATIC_GUARD(0x00C12Au, 0x82u, 0xFFu, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061161u, 4u);
        }

        case 0x0006096Bu: {
            TP_STATIC_GUARD(0x00C12Du, 0xC9u, 0x0Au);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x0Au;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC12Fu, 0x0006097Bu, 2u);
        }

        case 0x0006097Bu: {
            TP_STATIC_GUARD(0x00C12Fu, 0xD0u, 0x15u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC146u;
                if (tp_scpu_expect_next(cpu, 0x00060A33u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC131u, 0x0006098Bu, 2u);
        }

        case 0x0006098Bu: {
            TP_STATIC_GUARD(0x00C131u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC133u, 0x00060998u, 3u);
        }

        case 0x00060998u: {
            TP_STATIC_GUARD(0x00C133u, 0xADu, 0xD8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07D8u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC136u, 0x000609B0u, 5u);
        }

        case 0x000609B0u: {
            TP_STATIC_GUARD(0x00C136u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC139u, 0x000609C8u, 5u);
        }

        case 0x000609C8u: {
            TP_STATIC_GUARD(0x00C139u, 0xADu, 0xDAu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07DAu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC13Cu, 0x000609E0u, 5u);
        }

        case 0x000609E0u: {
            TP_STATIC_GUARD(0x00C13Cu, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC13Fu, 0x000609F8u, 5u);
        }

        case 0x000609F8u: {
            TP_STATIC_GUARD(0x00C13Fu, 0x22u, 0x88u, 0x82u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x42u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8288u, 0x00241440u, 8u);
        }

        case 0x00060A19u: {
            TP_STATIC_GUARD(0x00C143u, 0x82u, 0xE6u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061161u, 4u);
        }

        case 0x00060A33u: {
            TP_STATIC_GUARD(0x00C146u, 0xC9u, 0x0Cu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x0Cu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC148u, 0x00060A43u, 2u);
        }

        case 0x00060A43u: {
            TP_STATIC_GUARD(0x00C148u, 0xD0u, 0x17u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC161u;
                if (tp_scpu_expect_next(cpu, 0x00060B0Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC14Au, 0x00060A53u, 2u);
        }

        case 0x00060A53u: {
            TP_STATIC_GUARD(0x00C14Au, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xC14Cu, 0x00060A63u, 3u);
        }

        case 0x00060A63u: {
            TP_STATIC_GUARD(0x00C14Cu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xC14Eu, 0x00060A71u, 3u);
        }

        case 0x00060A71u: {
            TP_STATIC_GUARD(0x00C14Eu, 0xAEu, 0xD6u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07D6u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC151u, 0x00060A89u, 4u);
        }

        case 0x00060A89u: {
            TP_STATIC_GUARD(0x00C151u, 0x8Eu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC154u, 0x00060AA1u, 4u);
        }

        case 0x00060AA1u: {
            TP_STATIC_GUARD(0x00C154u, 0xADu, 0xD8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07D8u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC157u, 0x00060AB9u, 5u);
        }

        case 0x00060AB9u: {
            TP_STATIC_GUARD(0x00C157u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC15Au, 0x00060AD1u, 5u);
        }

        case 0x00060AD1u: {
            TP_STATIC_GUARD(0x00C15Au, 0x22u, 0x7Au, 0x9Fu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x5Du) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x9F7Au, 0x0024FBD1u, 8u);
        }

        case 0x00060AF1u: {
            TP_STATIC_GUARD(0x00C15Eu, 0x82u, 0xCBu, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061161u, 4u);
        }

        case 0x00060B0Bu: {
            TP_STATIC_GUARD(0x00C161u, 0xC9u, 0x0Eu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x0Eu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC163u, 0x00060B1Bu, 2u);
        }

        case 0x00060B1Bu: {
            TP_STATIC_GUARD(0x00C163u, 0xD0u, 0x0Eu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC173u;
                if (tp_scpu_expect_next(cpu, 0x00060B9Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC165u, 0x00060B2Bu, 2u);
        }

        case 0x00060B2Bu: {
            TP_STATIC_GUARD(0x00C165u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC167u, 0x00060B38u, 3u);
        }

        case 0x00060B38u: {
            TP_STATIC_GUARD(0x00C167u, 0xADu, 0xD8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07D8u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC16Au, 0x00060B50u, 5u);
        }

        case 0x00060B50u: {
            TP_STATIC_GUARD(0x00C16Au, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC16Du, 0x00060B68u, 5u);
        }

        case 0x00060B68u: {
            TP_STATIC_GUARD(0x00C16Du, 0x20u, 0x98u, 0xF1u);
            if (tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x6Fu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xF198u, 0x00078CC0u, 6u);
        }

        case 0x00060B80u: {
            TP_STATIC_GUARD(0x00C170u, 0x82u, 0xB9u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061160u, 4u);
        }

        case 0x00060B9Bu: {
            TP_STATIC_GUARD(0x00C173u, 0xC9u, 0x10u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x10u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC175u, 0x00060BABu, 2u);
        }

        case 0x00060BABu: {
            TP_STATIC_GUARD(0x00C175u, 0xD0u, 0x14u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC18Bu;
                if (tp_scpu_expect_next(cpu, 0x00060C5Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC177u, 0x00060BBBu, 2u);
        }

        case 0x00060BBBu: {
            TP_STATIC_GUARD(0x00C177u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC179u, 0x00060BC8u, 3u);
        }

        case 0x00060BC8u: {
            TP_STATIC_GUARD(0x00C179u, 0xADu, 0xD8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07D8u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC17Cu, 0x00060BE0u, 5u);
        }

        case 0x00060BE0u: {
            TP_STATIC_GUARD(0x00C17Cu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC17Fu, 0x00060BF8u, 5u);
        }

        case 0x00060BF8u: {
            TP_STATIC_GUARD(0x00C17Fu, 0xADu, 0xDAu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07DAu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC182u, 0x00060C10u, 5u);
        }

        case 0x00060C10u: {
            TP_STATIC_GUARD(0x00C182u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC185u, 0x00060C28u, 5u);
        }

        case 0x00060C28u: {
            TP_STATIC_GUARD(0x00C185u, 0x20u, 0x58u, 0xFCu);
            if (tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x87u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xFC58u, 0x0007E2C0u, 6u);
        }

        case 0x00060C40u: {
            TP_STATIC_GUARD(0x00C188u, 0x82u, 0xA1u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061160u, 4u);
        }

        case 0x00060C5Bu: {
            TP_STATIC_GUARD(0x00C18Bu, 0xC9u, 0x12u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x12u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC18Du, 0x00060C6Bu, 2u);
        }

        case 0x00060C6Bu: {
            TP_STATIC_GUARD(0x00C18Du, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC196u;
                if (tp_scpu_expect_next(cpu, 0x00060CB3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC18Fu, 0x00060C7Bu, 2u);
        }

        case 0x00060C7Bu: {
            TP_STATIC_GUARD(0x00C18Fu, 0x22u, 0x5Bu, 0x9Fu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x92u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9F5Bu, 0x0064FADBu, 8u);
        }

        case 0x00060C98u: {
            TP_STATIC_GUARD(0x00C193u, 0x82u, 0x96u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061160u, 4u);
        }

        case 0x00060CB3u: {
            TP_STATIC_GUARD(0x00C196u, 0xC9u, 0x14u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x14u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC198u, 0x00060CC3u, 2u);
        }

        case 0x00060CC3u: {
            TP_STATIC_GUARD(0x00C198u, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC1A1u;
                if (tp_scpu_expect_next(cpu, 0x00060D0Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC19Au, 0x00060CD3u, 2u);
        }

        case 0x00060CD3u: {
            TP_STATIC_GUARD(0x00C19Au, 0x22u, 0xEBu, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x9Du) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80EBu, 0x0024075Bu, 8u);
        }

        case 0x00060CF0u: {
            TP_STATIC_GUARD(0x00C19Eu, 0x82u, 0x8Bu, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061160u, 4u);
        }

        case 0x00060D0Bu: {
            TP_STATIC_GUARD(0x00C1A1u, 0xC9u, 0x16u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x16u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1A3u, 0x00060D1Bu, 2u);
        }

        case 0x00060D1Bu: {
            TP_STATIC_GUARD(0x00C1A3u, 0xD0u, 0x1Bu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC1C0u;
                if (tp_scpu_expect_next(cpu, 0x00060E03u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC1A5u, 0x00060D2Bu, 2u);
        }

        case 0x00060D2Bu: {
            TP_STATIC_GUARD(0x00C1A5u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC1A7u, 0x00060D38u, 3u);
        }

        case 0x00060D38u: {
            TP_STATIC_GUARD(0x00C1A7u, 0xADu, 0xD8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07D8u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1AAu, 0x00060D50u, 5u);
        }

        case 0x00060D50u: {
            TP_STATIC_GUARD(0x00C1AAu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC1ADu, 0x00060D68u, 5u);
        }

        case 0x00060D68u: {
            TP_STATIC_GUARD(0x00C1ADu, 0xA9u, 0xB8u, 0x00u);
            const uint16_t value = 0x00B8u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1B0u, 0x00060D80u, 3u);
        }

        case 0x00060D80u: {
            TP_STATIC_GUARD(0x00C1B0u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC1B3u, 0x00060D98u, 5u);
        }

        case 0x00060D98u: {
            TP_STATIC_GUARD(0x00C1B3u, 0xA9u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1B6u, 0x00060DB0u, 3u);
        }

        case 0x00060DB0u: {
            TP_STATIC_GUARD(0x00C1B6u, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC1B9u, 0x00060DC8u, 5u);
        }

        case 0x00060DC8u: {
            TP_STATIC_GUARD(0x00C1B9u, 0x22u, 0x51u, 0xF3u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBCu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xF351u, 0x00079A88u, 8u);
        }

        case 0x00060DE8u: {
            TP_STATIC_GUARD(0x00C1BDu, 0x82u, 0x6Cu, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061160u, 4u);
        }

        case 0x00060E03u: {
            TP_STATIC_GUARD(0x00C1C0u, 0xC9u, 0x1Cu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x1Cu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1C2u, 0x00060E13u, 2u);
        }

        case 0x00060E13u: {
            TP_STATIC_GUARD(0x00C1C2u, 0xD0u, 0x0Eu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC1D2u;
                if (tp_scpu_expect_next(cpu, 0x00060E93u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC1C4u, 0x00060E23u, 2u);
        }

        case 0x00060E23u: {
            TP_STATIC_GUARD(0x00C1C4u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC1C6u, 0x00060E30u, 3u);
        }

        case 0x00060E30u: {
            TP_STATIC_GUARD(0x00C1C6u, 0xADu, 0xD8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07D8u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1C9u, 0x00060E48u, 5u);
        }

        case 0x00060E48u: {
            TP_STATIC_GUARD(0x00C1C9u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC1CCu, 0x00060E60u, 5u);
        }

        case 0x00060E60u: {
            TP_STATIC_GUARD(0x00C1CCu, 0x22u, 0xEFu, 0xF8u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCFu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xF8EFu, 0x0007C778u, 8u);
        }

        case 0x00060E81u: {
            TP_STATIC_GUARD(0x00C1D0u, 0x80u, 0x5Au);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061161u, 3u);
        }

        case 0x00060E93u: {
            TP_STATIC_GUARD(0x00C1D2u, 0xC9u, 0x1Eu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x1Eu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1D4u, 0x00060EA3u, 2u);
        }

        case 0x00060EA3u: {
            TP_STATIC_GUARD(0x00C1D4u, 0xD0u, 0x20u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC1F6u;
                if (tp_scpu_expect_next(cpu, 0x00060FB3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC1D6u, 0x00060EB3u, 2u);
        }

        case 0x00060EB3u: {
            TP_STATIC_GUARD(0x00C1D6u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC1D8u, 0x00060EC0u, 3u);
        }

        case 0x00060EC0u: {
            TP_STATIC_GUARD(0x00C1D8u, 0xACu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1DBu, 0x00060ED8u, 5u);
        }

        case 0x00060ED8u: {
            TP_STATIC_GUARD(0x00C1DBu, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1DCu, 0x00060EE0u, 2u);
        }

        case 0x00060EE0u: {
            TP_STATIC_GUARD(0x00C1DCu, 0xA9u, 0x0Eu, 0x00u);
            const uint16_t value = 0x000Eu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1DFu, 0x00060EF8u, 3u);
        }

        case 0x00060EF8u: {
            TP_STATIC_GUARD(0x00C1DFu, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE2u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x00060F18u: {
            TP_STATIC_GUARD(0x00C1E3u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1E4u, 0x00060F20u, 2u);
        }

        case 0x00060F20u: {
            TP_STATIC_GUARD(0x00C1E4u, 0xB9u, 0xD8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07D8u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1E7u, 0x00060F38u, 6u);
        }

        case 0x00060F38u: {
            TP_STATIC_GUARD(0x00C1E7u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC1EAu, 0x00060F50u, 5u);
        }

        case 0x00060F50u: {
            TP_STATIC_GUARD(0x00C1EAu, 0xA9u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1EDu, 0x00060F68u, 3u);
        }

        case 0x00060F68u: {
            TP_STATIC_GUARD(0x00C1EDu, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC1F0u, 0x00060F80u, 5u);
        }

        case 0x00060F80u: {
            TP_STATIC_GUARD(0x00C1F0u, 0x22u, 0x8Eu, 0x97u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x978Eu, 0x003CBC70u, 8u);
        }

        case 0x00060FA1u: {
            TP_STATIC_GUARD(0x00C1F4u, 0x80u, 0x36u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061161u, 3u);
        }

        case 0x00060FB3u: {
            TP_STATIC_GUARD(0x00C1F6u, 0xC9u, 0x20u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x20u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1F8u, 0x00060FC3u, 2u);
        }

        case 0x00060FC3u: {
            TP_STATIC_GUARD(0x00C1F8u, 0xD0u, 0x02u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC1FCu;
                if (tp_scpu_expect_next(cpu, 0x00060FE3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC1FAu, 0x00060FD3u, 2u);
        }

        case 0x00060FD3u: {
            TP_STATIC_GUARD(0x00C1FAu, 0x80u, 0x30u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061163u, 3u);
        }

        case 0x00060FE3u: {
            TP_STATIC_GUARD(0x00C1FCu, 0xC9u, 0x22u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x22u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC1FEu, 0x00060FF3u, 2u);
        }

        case 0x00060FF3u: {
            TP_STATIC_GUARD(0x00C1FEu, 0xD0u, 0x14u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC214u;
                if (tp_scpu_expect_next(cpu, 0x000610A3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC200u, 0x00061003u, 2u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
