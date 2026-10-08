/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0004FB(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x0027D800u: {
            TP_STATIC_GUARD(0x04FB00u, 0xE9u, 0x00u, 0xE1u);
            if (tp_scpu_sbc(cpu, 0xE100u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB03u, 0x0027D818u, 3u);
        }

        case 0x0027D818u: {
            TP_STATIC_GUARD(0x04FB03u, 0x8Du, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0400u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB06u, 0x0027D830u, 5u);
        }

        case 0x0027D830u: {
            TP_STATIC_GUARD(0x04FB06u, 0xADu, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0402u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB09u, 0x0027D848u, 5u);
        }

        case 0x0027D848u: {
            TP_STATIC_GUARD(0x04FB09u, 0xE9u, 0xF5u, 0x05u);
            if (tp_scpu_sbc(cpu, 0x05F5u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB0Cu, 0x0027D860u, 3u);
        }

        case 0x0027D860u: {
            TP_STATIC_GUARD(0x04FB0Cu, 0x8Du, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0402u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB0Fu, 0x0027D878u, 5u);
        }

        case 0x0027D878u: {
            TP_STATIC_GUARD(0x04FB0Fu, 0xEEu, 0x1Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x041Bu;
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
            TP_STATIC_EXIT(0x04u, 0xFB12u, 0x0027D890u, 8u);
        }

        case 0x0027D890u: {
            TP_STATIC_GUARD(0x04FB12u, 0x80u, 0xD4u);
            TP_STATIC_EXIT(0x04u, 0xFAE8u, 0x0027D740u, 3u);
        }

        case 0x0027D8A0u: {
            TP_STATIC_GUARD(0x04FB14u, 0xADu, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0402u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB17u, 0x0027D8B8u, 5u);
        }

        case 0x0027D8B8u: {
            TP_STATIC_GUARD(0x04FB17u, 0xC9u, 0x98u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0098u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB1Au, 0x0027D8D0u, 3u);
        }

        case 0x0027D8D0u: {
            TP_STATIC_GUARD(0x04FB1Au, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFB20u;
                if (tp_scpu_expect_next(cpu, 0x0027D900u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFB1Cu, 0x0027D8E0u, 2u);
        }

        case 0x0027D8E0u: {
            TP_STATIC_GUARD(0x04FB1Cu, 0xB0u, 0x0Au);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFB28u;
                if (tp_scpu_expect_next(cpu, 0x0027D940u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFB1Eu, 0x0027D8F0u, 2u);
        }

        case 0x0027D8F0u: {
            TP_STATIC_GUARD(0x04FB1Eu, 0x90u, 0x20u);
            if (!((cpu->p & TP_P_C) == 0u))
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "PROVED_BRANCH_STATUS_VIOLATION");
            TP_STATIC_EXIT(0x04u, 0xFB40u, 0x0027DA00u, 3u);
        }

        case 0x0027D900u: {
            TP_STATIC_GUARD(0x04FB20u, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB23u, 0x0027D918u, 5u);
        }

        case 0x0027D918u: {
            TP_STATIC_GUARD(0x04FB23u, 0xC9u, 0x80u, 0x96u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x9680u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB26u, 0x0027D930u, 3u);
        }

        case 0x0027D930u: {
            TP_STATIC_GUARD(0x04FB26u, 0x90u, 0x18u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFB40u;
                if (tp_scpu_expect_next(cpu, 0x0027DA00u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFB28u, 0x0027D940u, 2u);
        }

        case 0x0027D940u: {
            TP_STATIC_GUARD(0x04FB28u, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB2Bu, 0x0027D958u, 5u);
        }

        case 0x0027D958u: {
            TP_STATIC_GUARD(0x04FB2Bu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xFB2Cu, 0x0027D960u, 2u);
        }

        case 0x0027D960u: {
            TP_STATIC_GUARD(0x04FB2Cu, 0xE9u, 0x80u, 0x96u);
            if (tp_scpu_sbc(cpu, 0x9680u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB2Fu, 0x0027D978u, 3u);
        }

        case 0x0027D978u: {
            TP_STATIC_GUARD(0x04FB2Fu, 0x8Du, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0400u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB32u, 0x0027D990u, 5u);
        }

        case 0x0027D990u: {
            TP_STATIC_GUARD(0x04FB32u, 0xADu, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0402u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB35u, 0x0027D9A8u, 5u);
        }

        case 0x0027D9A8u: {
            TP_STATIC_GUARD(0x04FB35u, 0xE9u, 0x98u, 0x00u);
            if (tp_scpu_sbc(cpu, 0x0098u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB38u, 0x0027D9C0u, 3u);
        }

        case 0x0027D9C0u: {
            TP_STATIC_GUARD(0x04FB38u, 0x8Du, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0402u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB3Bu, 0x0027D9D8u, 5u);
        }

        case 0x0027D9D8u: {
            TP_STATIC_GUARD(0x04FB3Bu, 0xEEu, 0x19u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0419u;
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
            TP_STATIC_EXIT(0x04u, 0xFB3Eu, 0x0027D9F0u, 8u);
        }

        case 0x0027D9F0u: {
            TP_STATIC_GUARD(0x04FB3Eu, 0x80u, 0xD4u);
            TP_STATIC_EXIT(0x04u, 0xFB14u, 0x0027D8A0u, 3u);
        }

        case 0x0027DA00u: {
            TP_STATIC_GUARD(0x04FB40u, 0xADu, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0402u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB43u, 0x0027DA18u, 5u);
        }

        case 0x0027DA18u: {
            TP_STATIC_GUARD(0x04FB43u, 0xC9u, 0x0Fu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Fu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB46u, 0x0027DA30u, 3u);
        }

        case 0x0027DA30u: {
            TP_STATIC_GUARD(0x04FB46u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFB4Cu;
                if (tp_scpu_expect_next(cpu, 0x0027DA60u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFB48u, 0x0027DA40u, 2u);
        }

        case 0x0027DA40u: {
            TP_STATIC_GUARD(0x04FB48u, 0xB0u, 0x0Au);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFB54u;
                if (tp_scpu_expect_next(cpu, 0x0027DAA0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFB4Au, 0x0027DA50u, 2u);
        }

        case 0x0027DA50u: {
            TP_STATIC_GUARD(0x04FB4Au, 0x90u, 0x20u);
            if (!((cpu->p & TP_P_C) == 0u))
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "PROVED_BRANCH_STATUS_VIOLATION");
            TP_STATIC_EXIT(0x04u, 0xFB6Cu, 0x0027DB60u, 3u);
        }

        case 0x0027DA60u: {
            TP_STATIC_GUARD(0x04FB4Cu, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB4Fu, 0x0027DA78u, 5u);
        }

        case 0x0027DA78u: {
            TP_STATIC_GUARD(0x04FB4Fu, 0xC9u, 0x40u, 0x42u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x4240u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB52u, 0x0027DA90u, 3u);
        }

        case 0x0027DA90u: {
            TP_STATIC_GUARD(0x04FB52u, 0x90u, 0x18u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFB6Cu;
                if (tp_scpu_expect_next(cpu, 0x0027DB60u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFB54u, 0x0027DAA0u, 2u);
        }

        case 0x0027DAA0u: {
            TP_STATIC_GUARD(0x04FB54u, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB57u, 0x0027DAB8u, 5u);
        }

        case 0x0027DAB8u: {
            TP_STATIC_GUARD(0x04FB57u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xFB58u, 0x0027DAC0u, 2u);
        }

        case 0x0027DAC0u: {
            TP_STATIC_GUARD(0x04FB58u, 0xE9u, 0x40u, 0x42u);
            if (tp_scpu_sbc(cpu, 0x4240u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB5Bu, 0x0027DAD8u, 3u);
        }

        case 0x0027DAD8u: {
            TP_STATIC_GUARD(0x04FB5Bu, 0x8Du, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0400u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB5Eu, 0x0027DAF0u, 5u);
        }

        case 0x0027DAF0u: {
            TP_STATIC_GUARD(0x04FB5Eu, 0xADu, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0402u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB61u, 0x0027DB08u, 5u);
        }

        case 0x0027DB08u: {
            TP_STATIC_GUARD(0x04FB61u, 0xE9u, 0x0Fu, 0x00u);
            if (tp_scpu_sbc(cpu, 0x000Fu, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB64u, 0x0027DB20u, 3u);
        }

        case 0x0027DB20u: {
            TP_STATIC_GUARD(0x04FB64u, 0x8Du, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0402u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB67u, 0x0027DB38u, 5u);
        }

        case 0x0027DB38u: {
            TP_STATIC_GUARD(0x04FB67u, 0xEEu, 0x17u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0417u;
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
            TP_STATIC_EXIT(0x04u, 0xFB6Au, 0x0027DB50u, 8u);
        }

        case 0x0027DB50u: {
            TP_STATIC_GUARD(0x04FB6Au, 0x80u, 0xD4u);
            TP_STATIC_EXIT(0x04u, 0xFB40u, 0x0027DA00u, 3u);
        }

        case 0x0027DB60u: {
            TP_STATIC_GUARD(0x04FB6Cu, 0xADu, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0402u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB6Fu, 0x0027DB78u, 5u);
        }

        case 0x0027DB78u: {
            TP_STATIC_GUARD(0x04FB6Fu, 0xC9u, 0x01u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0001u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB72u, 0x0027DB90u, 3u);
        }

        case 0x0027DB90u: {
            TP_STATIC_GUARD(0x04FB72u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFB78u;
                if (tp_scpu_expect_next(cpu, 0x0027DBC0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFB74u, 0x0027DBA0u, 2u);
        }

        case 0x0027DBA0u: {
            TP_STATIC_GUARD(0x04FB74u, 0xB0u, 0x0Au);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFB80u;
                if (tp_scpu_expect_next(cpu, 0x0027DC00u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFB76u, 0x0027DBB0u, 2u);
        }

        case 0x0027DBB0u: {
            TP_STATIC_GUARD(0x04FB76u, 0x90u, 0x20u);
            if (!((cpu->p & TP_P_C) == 0u))
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "PROVED_BRANCH_STATUS_VIOLATION");
            TP_STATIC_EXIT(0x04u, 0xFB98u, 0x0027DCC0u, 3u);
        }

        case 0x0027DBC0u: {
            TP_STATIC_GUARD(0x04FB78u, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB7Bu, 0x0027DBD8u, 5u);
        }

        case 0x0027DBD8u: {
            TP_STATIC_GUARD(0x04FB7Bu, 0xC9u, 0xA0u, 0x86u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x86A0u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB7Eu, 0x0027DBF0u, 3u);
        }

        case 0x0027DBF0u: {
            TP_STATIC_GUARD(0x04FB7Eu, 0x90u, 0x18u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFB98u;
                if (tp_scpu_expect_next(cpu, 0x0027DCC0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFB80u, 0x0027DC00u, 2u);
        }

        case 0x0027DC00u: {
            TP_STATIC_GUARD(0x04FB80u, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB83u, 0x0027DC18u, 5u);
        }

        case 0x0027DC18u: {
            TP_STATIC_GUARD(0x04FB83u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xFB84u, 0x0027DC20u, 2u);
        }

        case 0x0027DC20u: {
            TP_STATIC_GUARD(0x04FB84u, 0xE9u, 0xA0u, 0x86u);
            if (tp_scpu_sbc(cpu, 0x86A0u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB87u, 0x0027DC38u, 3u);
        }

        case 0x0027DC38u: {
            TP_STATIC_GUARD(0x04FB87u, 0x8Du, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0400u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB8Au, 0x0027DC50u, 5u);
        }

        case 0x0027DC50u: {
            TP_STATIC_GUARD(0x04FB8Au, 0xADu, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0402u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB8Du, 0x0027DC68u, 5u);
        }

        case 0x0027DC68u: {
            TP_STATIC_GUARD(0x04FB8Du, 0xE9u, 0x01u, 0x00u);
            if (tp_scpu_sbc(cpu, 0x0001u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB90u, 0x0027DC80u, 3u);
        }

        case 0x0027DC80u: {
            TP_STATIC_GUARD(0x04FB90u, 0x8Du, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0402u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFB93u, 0x0027DC98u, 5u);
        }

        case 0x0027DC98u: {
            TP_STATIC_GUARD(0x04FB93u, 0xEEu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
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
            TP_STATIC_EXIT(0x04u, 0xFB96u, 0x0027DCB0u, 8u);
        }

        case 0x0027DCB0u: {
            TP_STATIC_GUARD(0x04FB96u, 0x80u, 0xD4u);
            TP_STATIC_EXIT(0x04u, 0xFB6Cu, 0x0027DB60u, 3u);
        }

        case 0x0027DCC0u: {
            TP_STATIC_GUARD(0x04FB98u, 0xADu, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0402u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB9Bu, 0x0027DCD8u, 5u);
        }

        case 0x0027DCD8u: {
            TP_STATIC_GUARD(0x04FB9Bu, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFB9Eu, 0x0027DCF0u, 3u);
        }

        case 0x0027DCF0u: {
            TP_STATIC_GUARD(0x04FB9Eu, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFBA4u;
                if (tp_scpu_expect_next(cpu, 0x0027DD20u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFBA0u, 0x0027DD00u, 2u);
        }

        case 0x0027DD00u: {
            TP_STATIC_GUARD(0x04FBA0u, 0xB0u, 0x0Au);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFBACu;
                if (tp_scpu_expect_next(cpu, 0x0027DD60u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFBA2u, 0x0027DD10u, 2u);
        }

        case 0x0027DD10u: {
            TP_STATIC_GUARD(0x04FBA2u, 0x90u, 0x20u);
            if (!((cpu->p & TP_P_C) == 0u))
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "PROVED_BRANCH_STATUS_VIOLATION");
            TP_STATIC_EXIT(0x04u, 0xFBC4u, 0x0027DE20u, 3u);
        }

        case 0x0027DD20u: {
            TP_STATIC_GUARD(0x04FBA4u, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFBA7u, 0x0027DD38u, 5u);
        }

        case 0x0027DD38u: {
            TP_STATIC_GUARD(0x04FBA7u, 0xC9u, 0x10u, 0x27u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x2710u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFBAAu, 0x0027DD50u, 3u);
        }

        case 0x0027DD50u: {
            TP_STATIC_GUARD(0x04FBAAu, 0x90u, 0x18u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFBC4u;
                if (tp_scpu_expect_next(cpu, 0x0027DE20u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFBACu, 0x0027DD60u, 2u);
        }

        case 0x0027DD60u: {
            TP_STATIC_GUARD(0x04FBACu, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFBAFu, 0x0027DD78u, 5u);
        }

        case 0x0027DD78u: {
            TP_STATIC_GUARD(0x04FBAFu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xFBB0u, 0x0027DD80u, 2u);
        }

        case 0x0027DD80u: {
            TP_STATIC_GUARD(0x04FBB0u, 0xE9u, 0x10u, 0x27u);
            if (tp_scpu_sbc(cpu, 0x2710u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFBB3u, 0x0027DD98u, 3u);
        }

        case 0x0027DD98u: {
            TP_STATIC_GUARD(0x04FBB3u, 0x8Du, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0400u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFBB6u, 0x0027DDB0u, 5u);
        }

        case 0x0027DDB0u: {
            TP_STATIC_GUARD(0x04FBB6u, 0xADu, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0402u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFBB9u, 0x0027DDC8u, 5u);
        }

        case 0x0027DDC8u: {
            TP_STATIC_GUARD(0x04FBB9u, 0xE9u, 0x00u, 0x00u);
            if (tp_scpu_sbc(cpu, 0x0000u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFBBCu, 0x0027DDE0u, 3u);
        }

        case 0x0027DDE0u: {
            TP_STATIC_GUARD(0x04FBBCu, 0x8Du, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0402u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFBBFu, 0x0027DDF8u, 5u);
        }

        case 0x0027DDF8u: {
            TP_STATIC_GUARD(0x04FBBFu, 0xEEu, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0413u;
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
            TP_STATIC_EXIT(0x04u, 0xFBC2u, 0x0027DE10u, 8u);
        }

        case 0x0027DE10u: {
            TP_STATIC_GUARD(0x04FBC2u, 0x80u, 0xD4u);
            TP_STATIC_EXIT(0x04u, 0xFB98u, 0x0027DCC0u, 3u);
        }

        case 0x0027DE20u: {
            TP_STATIC_GUARD(0x04FBC4u, 0xADu, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0402u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFBC7u, 0x0027DE38u, 5u);
        }

        case 0x0027DE38u: {
            TP_STATIC_GUARD(0x04FBC7u, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFBCAu, 0x0027DE50u, 3u);
        }

        case 0x0027DE50u: {
            TP_STATIC_GUARD(0x04FBCAu, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFBD0u;
                if (tp_scpu_expect_next(cpu, 0x0027DE80u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFBCCu, 0x0027DE60u, 2u);
        }

        case 0x0027DE60u: {
            TP_STATIC_GUARD(0x04FBCCu, 0xB0u, 0x0Au);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFBD8u;
                if (tp_scpu_expect_next(cpu, 0x0027DEC0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFBCEu, 0x0027DE70u, 2u);
        }

        case 0x0027DE70u: {
            TP_STATIC_GUARD(0x04FBCEu, 0x90u, 0x20u);
            if (!((cpu->p & TP_P_C) == 0u))
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "PROVED_BRANCH_STATUS_VIOLATION");
            TP_STATIC_EXIT(0x04u, 0xFBF0u, 0x0027DF80u, 3u);
        }

        case 0x0027DE80u: {
            TP_STATIC_GUARD(0x04FBD0u, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFBD3u, 0x0027DE98u, 5u);
        }

        case 0x0027DE98u: {
            TP_STATIC_GUARD(0x04FBD3u, 0xC9u, 0xE8u, 0x03u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x03E8u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFBD6u, 0x0027DEB0u, 3u);
        }

        case 0x0027DEB0u: {
            TP_STATIC_GUARD(0x04FBD6u, 0x90u, 0x18u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFBF0u;
                if (tp_scpu_expect_next(cpu, 0x0027DF80u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFBD8u, 0x0027DEC0u, 2u);
        }

        case 0x0027DEC0u: {
            TP_STATIC_GUARD(0x04FBD8u, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFBDBu, 0x0027DED8u, 5u);
        }

        case 0x0027DED8u: {
            TP_STATIC_GUARD(0x04FBDBu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xFBDCu, 0x0027DEE0u, 2u);
        }

        case 0x0027DEE0u: {
            TP_STATIC_GUARD(0x04FBDCu, 0xE9u, 0xE8u, 0x03u);
            if (tp_scpu_sbc(cpu, 0x03E8u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFBDFu, 0x0027DEF8u, 3u);
        }

        case 0x0027DEF8u: {
            TP_STATIC_GUARD(0x04FBDFu, 0x8Du, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0400u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFBE2u, 0x0027DF10u, 5u);
        }

        case 0x0027DF10u: {
            TP_STATIC_GUARD(0x04FBE2u, 0xADu, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0402u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFBE5u, 0x0027DF28u, 5u);
        }

        case 0x0027DF28u: {
            TP_STATIC_GUARD(0x04FBE5u, 0xE9u, 0x00u, 0x00u);
            if (tp_scpu_sbc(cpu, 0x0000u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFBE8u, 0x0027DF40u, 3u);
        }

        case 0x0027DF40u: {
            TP_STATIC_GUARD(0x04FBE8u, 0x8Du, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0402u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xFBEBu, 0x0027DF58u, 5u);
        }

        case 0x0027DF58u: {
            TP_STATIC_GUARD(0x04FBEBu, 0xEEu, 0x11u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0411u;
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
            TP_STATIC_EXIT(0x04u, 0xFBEEu, 0x0027DF70u, 8u);
        }

        case 0x0027DF70u: {
            TP_STATIC_GUARD(0x04FBEEu, 0x80u, 0xD4u);
            TP_STATIC_EXIT(0x04u, 0xFBC4u, 0x0027DE20u, 3u);
        }

        case 0x0027DF80u: {
            TP_STATIC_GUARD(0x04FBF0u, 0xADu, 0x02u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0402u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFBF3u, 0x0027DF98u, 5u);
        }

        case 0x0027DF98u: {
            TP_STATIC_GUARD(0x04FBF3u, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFBF6u, 0x0027DFB0u, 3u);
        }

        case 0x0027DFB0u: {
            TP_STATIC_GUARD(0x04FBF6u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFBFCu;
                if (tp_scpu_expect_next(cpu, 0x0027DFE0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFBF8u, 0x0027DFC0u, 2u);
        }

        case 0x0027DFC0u: {
            TP_STATIC_GUARD(0x04FBF8u, 0xB0u, 0x0Au);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xFC04u;
                if (tp_scpu_expect_next(cpu, 0x0027E020u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xFBFAu, 0x0027DFD0u, 2u);
        }

        case 0x0027DFD0u: {
            TP_STATIC_GUARD(0x04FBFAu, 0x90u, 0x20u);
            if (!((cpu->p & TP_P_C) == 0u))
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "PROVED_BRANCH_STATUS_VIOLATION");
            TP_STATIC_EXIT(0x04u, 0xFC1Cu, 0x0027E0E0u, 3u);
        }

        case 0x0027DFE0u: {
            TP_STATIC_GUARD(0x04FBFCu, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFBFFu, 0x0027DFF8u, 5u);
        }

        case 0x0027DFF8u: {
            TP_STATIC_GUARD(0x04FBFFu, 0xC9u, 0x64u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0064u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xFC02u, 0x0027E010u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
