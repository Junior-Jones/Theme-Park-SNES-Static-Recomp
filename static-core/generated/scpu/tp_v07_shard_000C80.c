/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000C80(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00640002u: {
            TP_STATIC_GUARD(0x0C8000u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8002u, 0x00640012u, 3u);
        }

        case 0x00640012u: {
            TP_STATIC_GUARD(0x0C8002u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x0Cu, 0x8004u, 0x00640022u, 3u);
        }

        case 0x00640022u: {
            TP_STATIC_GUARD(0x0C8004u, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8006u, 0x00640032u, 2u);
        }

        case 0x00640032u: {
            TP_STATIC_GUARD(0x0C8006u, 0x8Du, 0x0Cu, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x420Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8009u, 0x0064004Au, 4u);
        }

        case 0x0064004Au: {
            TP_STATIC_GUARD(0x0C8009u, 0xA9u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x800Bu, 0x0064005Au, 2u);
        }

        case 0x0064005Au: {
            TP_STATIC_GUARD(0x0C800Bu, 0x8Du, 0x00u, 0x43u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4300u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x800Eu, 0x00640072u, 4u);
        }

        case 0x00640072u: {
            TP_STATIC_GUARD(0x0C800Eu, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8010u, 0x00640082u, 2u);
        }

        case 0x00640082u: {
            TP_STATIC_GUARD(0x0C8010u, 0x8Du, 0x04u, 0x43u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4304u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8013u, 0x0064009Au, 4u);
        }

        case 0x0064009Au: {
            TP_STATIC_GUARD(0x0C8013u, 0xA9u, 0x0Fu);
            const uint8_t value = 0x0Fu;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8015u, 0x006400AAu, 2u);
        }

        case 0x006400AAu: {
            TP_STATIC_GUARD(0x0C8015u, 0x8Du, 0x01u, 0x43u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4301u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8018u, 0x006400C2u, 4u);
        }

        case 0x006400C2u: {
            TP_STATIC_GUARD(0x0C8018u, 0xA2u, 0x4Du, 0x85u);
            const uint16_t value = 0x854Du;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x801Bu, 0x006400DAu, 3u);
        }

        case 0x006400DAu: {
            TP_STATIC_GUARD(0x0C801Bu, 0x8Eu, 0x02u, 0x43u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4302u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x801Eu, 0x006400F2u, 5u);
        }

        case 0x006400F2u: {
            TP_STATIC_GUARD(0x0C801Eu, 0x6Bu);
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
                case 0x0064587Au:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x006400FBu: {
            TP_STATIC_GUARD(0x0C801Fu, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8021u, 0x0064010Bu, 3u);
        }

        case 0x0064010Bu: {
            TP_STATIC_GUARD(0x0C8021u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x0Cu, 0x8023u, 0x0064011Au, 3u);
        }

        case 0x0064011Au: {
            TP_STATIC_GUARD(0x0C8023u, 0xA2u, 0x00u, 0x10u);
            const uint16_t value = 0x1000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8026u, 0x00640132u, 3u);
        }

        case 0x00640132u: {
            TP_STATIC_GUARD(0x0C8026u, 0x8Eu, 0x2Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Du;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8029u, 0x0064014Au, 5u);
        }

        case 0x0064014Au: {
            TP_STATIC_GUARD(0x0C8029u, 0xADu, 0xAFu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07AFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x802Cu, 0x00640162u, 4u);
        }

        case 0x00640162u: {
            TP_STATIC_GUARD(0x0C802Cu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8031u;
                if (tp_scpu_expect_next(cpu, 0x0064018Au) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x802Eu, 0x00640172u, 2u);
        }

        case 0x00640172u: {
            TP_STATIC_GUARD(0x0C802Eu, 0x82u, 0x82u, 0x02u);
            TP_STATIC_EXIT(0x0Cu, 0x82B3u, 0x0064159Au, 4u);
        }

        case 0x0064018Au: {
            TP_STATIC_GUARD(0x0C8031u, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8034u, 0x006401A2u, 3u);
        }

        case 0x006401A2u: {
            TP_STATIC_GUARD(0x0C8034u, 0x8Eu, 0x25u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0425u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8037u, 0x006401BAu, 5u);
        }

        case 0x006401BAu: {
            TP_STATIC_GUARD(0x0C8037u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8039u, 0x006401CBu, 3u);
        }

        case 0x006401CBu: {
            TP_STATIC_GUARD(0x0C8039u, 0xACu, 0xAEu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07AEu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x803Cu, 0x006401E3u, 4u);
        }

        case 0x006401E3u: {
            TP_STATIC_GUARD(0x0C803Cu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8041u;
                if (tp_scpu_expect_next(cpu, 0x0064020Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x803Eu, 0x006401F3u, 2u);
        }

        case 0x006401F3u: {
            TP_STATIC_GUARD(0x0C803Eu, 0x82u, 0x72u, 0x02u);
            TP_STATIC_EXIT(0x0Cu, 0x82B3u, 0x0064159Bu, 4u);
        }

        case 0x0064020Bu: {
            TP_STATIC_GUARD(0x0C8041u, 0xA9u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8043u, 0x0064021Bu, 2u);
        }

        case 0x0064021Bu: {
            TP_STATIC_GUARD(0x0C8043u, 0x8Du, 0xF0u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18F0u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8046u, 0x00640233u, 4u);
        }

        case 0x00640233u: {
            TP_STATIC_GUARD(0x0C8046u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8047u, 0x0064023Bu, 2u);
        }

        case 0x0064023Bu: {
            TP_STATIC_GUARD(0x0C8047u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8048u, 0x00640243u, 2u);
        }

        case 0x00640243u: {
            TP_STATIC_GUARD(0x0C8048u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8049u, 0x0064024Bu, 2u);
        }

        case 0x0064024Bu: {
            TP_STATIC_GUARD(0x0C8049u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x804Au, 0x00640253u, 2u);
        }

        case 0x00640253u: {
            TP_STATIC_GUARD(0x0C804Au, 0xB9u, 0x3Fu, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x143Fu + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x0Cu;
            cpu->pc = 0x804Du;
            if (tp_scpu_expect_next(cpu, 0x0064026Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + (((0x3Fu + (cpu->y & 0x00FFu)) > 0x00FFu) ? 1u : 0u));
        }

        case 0x0064026Bu: {
            TP_STATIC_GUARD(0x0C804Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x804Fu, 0x00640278u, 3u);
        }

        case 0x00640278u: {
            TP_STATIC_GUARD(0x0C804Fu, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8052u, 0x00640290u, 3u);
        }

        case 0x00640290u: {
            TP_STATIC_GUARD(0x0C8052u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8053u, 0x00640298u, 3u);
        }

        case 0x00640298u: {
            TP_STATIC_GUARD(0x0C8053u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8054u, 0x006402A0u, 3u);
        }

        case 0x006402A0u: {
            TP_STATIC_GUARD(0x0C8054u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8055u, 0x006402A8u, 3u);
        }

        case 0x006402A8u: {
            TP_STATIC_GUARD(0x0C8055u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8056u, 0x006402B0u, 3u);
        }

        case 0x006402B0u: {
            TP_STATIC_GUARD(0x0C8056u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8057u, 0x006402B8u, 2u);
        }

        case 0x006402B8u: {
            TP_STATIC_GUARD(0x0C8057u, 0xBFu, 0xCCu, 0x88u, 0x05u);
            const uint32_t address = (0x0588CCu + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x805Bu, 0x006402D8u, 6u);
        }

        case 0x006402D8u: {
            TP_STATIC_GUARD(0x0C805Bu, 0xC9u, 0xA1u, 0x05u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x05A1u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x805Eu, 0x006402F0u, 3u);
        }

        case 0x006402F0u: {
            TP_STATIC_GUARD(0x0C805Eu, 0x90u, 0x03u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8063u;
                if (tp_scpu_expect_next(cpu, 0x00640318u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8060u, 0x00640300u, 2u);
        }

        case 0x00640300u: {
            TP_STATIC_GUARD(0x0C8060u, 0xA9u, 0xA0u, 0x05u);
            const uint16_t value = 0x05A0u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8063u, 0x00640318u, 3u);
        }

        case 0x00640318u: {
            TP_STATIC_GUARD(0x0C8063u, 0x8Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0421u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8066u, 0x00640330u, 5u);
        }

        case 0x00640330u: {
            TP_STATIC_GUARD(0x0C8066u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x8067u, 0x00640338u, 2u);
        }

        case 0x00640338u: {
            TP_STATIC_GUARD(0x0C8067u, 0x6Du, 0x25u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0425u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x806Au, 0x00640350u, 5u);
        }

        case 0x00640350u: {
            TP_STATIC_GUARD(0x0C806Au, 0xCDu, 0x2Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Du;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x806Du, 0x00640368u, 5u);
        }

        case 0x00640368u: {
            TP_STATIC_GUARD(0x0C806Du, 0x90u, 0x03u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8072u;
                if (tp_scpu_expect_next(cpu, 0x00640390u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x806Fu, 0x00640378u, 2u);
        }

        case 0x00640378u: {
            TP_STATIC_GUARD(0x0C806Fu, 0x4Cu, 0xB3u, 0x82u);
            TP_STATIC_EXIT(0x0Cu, 0x82B3u, 0x00641598u, 3u);
        }

        case 0x00640390u: {
            TP_STATIC_GUARD(0x0C8072u, 0x8Du, 0x25u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0425u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8075u, 0x006403A8u, 5u);
        }

        case 0x006403A8u: {
            TP_STATIC_GUARD(0x0C8075u, 0xB9u, 0x41u, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1441u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8078u, 0x006403C0u, 6u);
        }

        case 0x006403C0u: {
            TP_STATIC_GUARD(0x0C8078u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x8079u, 0x006403C8u, 2u);
        }

        case 0x006403C8u: {
            TP_STATIC_GUARD(0x0C8079u, 0x69u, 0x00u, 0x20u);
            if (tp_scpu_adc(cpu, 0x2000u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x807Cu, 0x006403E0u, 3u);
        }

        case 0x006403E0u: {
            TP_STATIC_GUARD(0x0C807Cu, 0x8Du, 0x23u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0423u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x807Fu, 0x006403F8u, 5u);
        }

        case 0x006403F8u: {
            TP_STATIC_GUARD(0x0C807Fu, 0xB9u, 0x40u, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1440u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8082u, 0x00640410u, 6u);
        }

        case 0x00640410u: {
            TP_STATIC_GUARD(0x0C8082u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8085u, 0x00640428u, 3u);
        }

        case 0x00640428u: {
            TP_STATIC_GUARD(0x0C8085u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8086u, 0x00640430u, 2u);
        }

        case 0x00640430u: {
            TP_STATIC_GUARD(0x0C8086u, 0xBFu, 0xCEu, 0x88u, 0x05u);
            const uint32_t address = (0x0588CEu + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x808Au, 0x00640450u, 6u);
        }

        case 0x00640450u: {
            TP_STATIC_GUARD(0x0C808Au, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x808Bu, 0x00640458u, 2u);
        }

        case 0x00640458u: {
            TP_STATIC_GUARD(0x0C808Bu, 0x69u, 0x00u, 0x80u);
            if (tp_scpu_adc(cpu, 0x8000u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x808Eu, 0x00640470u, 3u);
        }

        case 0x00640470u: {
            TP_STATIC_GUARD(0x0C808Eu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x808Fu, 0x00640478u, 2u);
        }

        case 0x00640478u: {
            TP_STATIC_GUARD(0x0C808Fu, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8092u, 0x00640490u, 5u);
        }

        case 0x00640490u: {
            TP_STATIC_GUARD(0x0C8092u, 0x9Cu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x042Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8095u, 0x006404A8u, 5u);
        }

        case 0x006404A8u: {
            TP_STATIC_GUARD(0x0C8095u, 0xC0u, 0x00u, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8098u, 0x006404C0u, 3u);
        }

        case 0x006404C0u: {
            TP_STATIC_GUARD(0x0C8098u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x809Du;
                if (tp_scpu_expect_next(cpu, 0x006404E8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x809Au, 0x006404D0u, 2u);
        }

        case 0x006404D0u: {
            TP_STATIC_GUARD(0x0C809Au, 0x82u, 0xB2u, 0x01u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x006404E8u: {
            TP_STATIC_GUARD(0x0C809Du, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x809Eu, 0x006404F0u, 2u);
        }

        case 0x006404F0u: {
            TP_STATIC_GUARD(0x0C809Eu, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x80A1u, 0x00640508u, 5u);
        }

        case 0x00640508u: {
            TP_STATIC_GUARD(0x0C80A1u, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x80A4u, 0x00640520u, 3u);
        }

        case 0x00640520u: {
            TP_STATIC_GUARD(0x0C80A4u, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x80ACu;
                if (tp_scpu_expect_next(cpu, 0x00640560u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x80A6u, 0x00640530u, 2u);
        }

        case 0x00640530u: {
            TP_STATIC_GUARD(0x0C80A6u, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x80A9u, 0x00640548u, 3u);
        }

        case 0x00640548u: {
            TP_STATIC_GUARD(0x0C80A9u, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x80ACu, 0x00640560u, 8u);
        }

        case 0x00640560u: {
            TP_STATIC_GUARD(0x0C80ACu, 0xC0u, 0x01u, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0001u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x80AFu, 0x00640578u, 3u);
        }

        case 0x00640578u: {
            TP_STATIC_GUARD(0x0C80AFu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x80B4u;
                if (tp_scpu_expect_next(cpu, 0x006405A0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x80B1u, 0x00640588u, 2u);
        }

        case 0x00640588u: {
            TP_STATIC_GUARD(0x0C80B1u, 0x82u, 0x9Bu, 0x01u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x006405A0u: {
            TP_STATIC_GUARD(0x0C80B4u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x80B5u, 0x006405A8u, 2u);
        }

        case 0x006405A8u: {
            TP_STATIC_GUARD(0x0C80B5u, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x80B8u, 0x006405C0u, 5u);
        }

        case 0x006405C0u: {
            TP_STATIC_GUARD(0x0C80B8u, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x80BBu, 0x006405D8u, 3u);
        }

        case 0x006405D8u: {
            TP_STATIC_GUARD(0x0C80BBu, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x80C3u;
                if (tp_scpu_expect_next(cpu, 0x00640618u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x80BDu, 0x006405E8u, 2u);
        }

        case 0x006405E8u: {
            TP_STATIC_GUARD(0x0C80BDu, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x80C0u, 0x00640600u, 3u);
        }

        case 0x00640600u: {
            TP_STATIC_GUARD(0x0C80C0u, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x80C3u, 0x00640618u, 8u);
        }

        case 0x00640618u: {
            TP_STATIC_GUARD(0x0C80C3u, 0xC0u, 0x02u, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0002u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x80C6u, 0x00640630u, 3u);
        }

        case 0x00640630u: {
            TP_STATIC_GUARD(0x0C80C6u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x80CBu;
                if (tp_scpu_expect_next(cpu, 0x00640658u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x80C8u, 0x00640640u, 2u);
        }

        case 0x00640640u: {
            TP_STATIC_GUARD(0x0C80C8u, 0x82u, 0x84u, 0x01u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x00640658u: {
            TP_STATIC_GUARD(0x0C80CBu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x80CCu, 0x00640660u, 2u);
        }

        case 0x00640660u: {
            TP_STATIC_GUARD(0x0C80CCu, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x80CFu, 0x00640678u, 5u);
        }

        case 0x00640678u: {
            TP_STATIC_GUARD(0x0C80CFu, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x80D2u, 0x00640690u, 3u);
        }

        case 0x00640690u: {
            TP_STATIC_GUARD(0x0C80D2u, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x80DAu;
                if (tp_scpu_expect_next(cpu, 0x006406D0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x80D4u, 0x006406A0u, 2u);
        }

        case 0x006406A0u: {
            TP_STATIC_GUARD(0x0C80D4u, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x80D7u, 0x006406B8u, 3u);
        }

        case 0x006406B8u: {
            TP_STATIC_GUARD(0x0C80D7u, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x80DAu, 0x006406D0u, 8u);
        }

        case 0x006406D0u: {
            TP_STATIC_GUARD(0x0C80DAu, 0xC0u, 0x03u, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0003u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x80DDu, 0x006406E8u, 3u);
        }

        case 0x006406E8u: {
            TP_STATIC_GUARD(0x0C80DDu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x80E2u;
                if (tp_scpu_expect_next(cpu, 0x00640710u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x80DFu, 0x006406F8u, 2u);
        }

        case 0x006406F8u: {
            TP_STATIC_GUARD(0x0C80DFu, 0x82u, 0x6Du, 0x01u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x00640710u: {
            TP_STATIC_GUARD(0x0C80E2u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x80E3u, 0x00640718u, 2u);
        }

        case 0x00640718u: {
            TP_STATIC_GUARD(0x0C80E3u, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x80E6u, 0x00640730u, 5u);
        }

        case 0x00640730u: {
            TP_STATIC_GUARD(0x0C80E6u, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x80E9u, 0x00640748u, 3u);
        }

        case 0x00640748u: {
            TP_STATIC_GUARD(0x0C80E9u, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x80F1u;
                if (tp_scpu_expect_next(cpu, 0x00640788u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x80EBu, 0x00640758u, 2u);
        }

        case 0x00640758u: {
            TP_STATIC_GUARD(0x0C80EBu, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x80EEu, 0x00640770u, 3u);
        }

        case 0x00640770u: {
            TP_STATIC_GUARD(0x0C80EEu, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x80F1u, 0x00640788u, 8u);
        }

        case 0x00640788u: {
            TP_STATIC_GUARD(0x0C80F1u, 0xC0u, 0x04u, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0004u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x80F4u, 0x006407A0u, 3u);
        }

        case 0x006407A0u: {
            TP_STATIC_GUARD(0x0C80F4u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x80F9u;
                if (tp_scpu_expect_next(cpu, 0x006407C8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x80F6u, 0x006407B0u, 2u);
        }

        case 0x006407B0u: {
            TP_STATIC_GUARD(0x0C80F6u, 0x82u, 0x56u, 0x01u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x006407C8u: {
            TP_STATIC_GUARD(0x0C80F9u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x80FAu, 0x006407D0u, 2u);
        }

        case 0x006407D0u: {
            TP_STATIC_GUARD(0x0C80FAu, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x80FDu, 0x006407E8u, 5u);
        }

        case 0x006407E8u: {
            TP_STATIC_GUARD(0x0C80FDu, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8100u, 0x00640800u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
