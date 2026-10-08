/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0001EC(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x000F600Bu: {
            TP_STATIC_GUARD(0x01EC01u, 0x8Du, 0x2Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x042Fu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC04u, 0x000F6023u, 4u);
        }

        case 0x000F6023u: {
            TP_STATIC_GUARD(0x01EC04u, 0xADu, 0x30u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0430u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC07u, 0x000F603Bu, 4u);
        }

        case 0x000F603Bu: {
            TP_STATIC_GUARD(0x01EC07u, 0xCDu, 0x12u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0412u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC0Au, 0x000F6053u, 4u);
        }

        case 0x000F6053u: {
            TP_STATIC_GUARD(0x01EC0Au, 0xF0u, 0x10u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xEC1Cu;
                if (tp_scpu_expect_next(cpu, 0x000F60E3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xEC0Cu, 0x000F6063u, 2u);
        }

        case 0x000F6063u: {
            TP_STATIC_GUARD(0x01EC0Cu, 0xB0u, 0x08u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xEC16u;
                if (tp_scpu_expect_next(cpu, 0x000F60B3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xEC0Eu, 0x000F6073u, 2u);
        }

        case 0x000F6073u: {
            TP_STATIC_GUARD(0x01EC0Eu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xEC0Fu, 0x000F607Bu, 2u);
        }

        case 0x000F607Bu: {
            TP_STATIC_GUARD(0x01EC0Fu, 0x69u, 0x04u);
            if (tp_scpu_adc(cpu, 0x04u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC11u, 0x000F608Bu, 2u);
        }

        case 0x000F608Bu: {
            TP_STATIC_GUARD(0x01EC11u, 0x8Du, 0x30u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0430u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC14u, 0x000F60A3u, 4u);
        }

        case 0x000F60A3u: {
            TP_STATIC_GUARD(0x01EC14u, 0x80u, 0x06u);
            TP_STATIC_EXIT(0x01u, 0xEC1Cu, 0x000F60E3u, 3u);
        }

        case 0x000F60B3u: {
            TP_STATIC_GUARD(0x01EC16u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xEC17u, 0x000F60BBu, 2u);
        }

        case 0x000F60BBu: {
            TP_STATIC_GUARD(0x01EC17u, 0xE9u, 0x04u);
            if (tp_scpu_sbc(cpu, 0x04u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC19u, 0x000F60CBu, 2u);
        }

        case 0x000F60CBu: {
            TP_STATIC_GUARD(0x01EC19u, 0x8Du, 0x30u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0430u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC1Cu, 0x000F60E3u, 4u);
        }

        case 0x000F60E3u: {
            TP_STATIC_GUARD(0x01EC1Cu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xEC1Eu, 0x000F60F3u, 3u);
        }

        case 0x000F60F3u: {
            TP_STATIC_GUARD(0x01EC1Eu, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC20u, 0x000F6103u, 2u);
        }

        case 0x000F6103u: {
            TP_STATIC_GUARD(0x01EC20u, 0x8Du, 0x4Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x074Du) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC23u, 0x000F611Bu, 4u);
        }

        case 0x000F611Bu: {
            TP_STATIC_GUARD(0x01EC23u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xEC25u, 0x000F6128u, 3u);
        }

        case 0x000F6128u: {
            TP_STATIC_GUARD(0x01EC25u, 0xADu, 0x2Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC28u, 0x000F6140u, 5u);
        }

        case 0x000F6140u: {
            TP_STATIC_GUARD(0x01EC28u, 0xCDu, 0x11u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0411u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC2Bu, 0x000F6158u, 5u);
        }

        case 0x000F6158u: {
            TP_STATIC_GUARD(0x01EC2Bu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xEC30u;
                if (tp_scpu_expect_next(cpu, 0x000F6180u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xEC2Du, 0x000F6168u, 2u);
        }

        case 0x000F6168u: {
            TP_STATIC_GUARD(0x01EC2Du, 0x82u, 0xB2u, 0xFFu);
            TP_STATIC_EXIT(0x01u, 0xEBE2u, 0x000F5F10u, 4u);
        }

        case 0x000F6180u: {
            TP_STATIC_GUARD(0x01EC30u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xEC32u, 0x000F6193u, 3u);
        }

        case 0x000F6193u: {
            TP_STATIC_GUARD(0x01EC32u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xEC34u, 0x000F61A0u, 3u);
        }

        case 0x000F61A0u: {
            TP_STATIC_GUARD(0x01EC34u, 0xA9u, 0xB7u, 0x18u);
            const uint16_t value = 0x18B7u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC37u, 0x000F61B8u, 3u);
        }

        case 0x000F61B8u: {
            TP_STATIC_GUARD(0x01EC37u, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC3Au, 0x000F61D0u, 5u);
        }

        case 0x000F61D0u: {
            TP_STATIC_GUARD(0x01EC3Au, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC3Du, 0x000F61E8u, 3u);
        }

        case 0x000F61E8u: {
            TP_STATIC_GUARD(0x01EC3Du, 0x8Eu, 0x94u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0794u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC40u, 0x000F6200u, 5u);
        }

        case 0x000F6200u: {
            TP_STATIC_GUARD(0x01EC40u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC43u, 0x000F6218u, 3u);
        }

        case 0x000F6218u: {
            TP_STATIC_GUARD(0x01EC43u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC46u, 0x000F6230u, 5u);
        }

        case 0x000F6230u: {
            TP_STATIC_GUARD(0x01EC46u, 0xA9u, 0x14u, 0x00u);
            const uint16_t value = 0x0014u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC49u, 0x000F6248u, 3u);
        }

        case 0x000F6248u: {
            TP_STATIC_GUARD(0x01EC49u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC4Cu, 0x000F6260u, 5u);
        }

        case 0x000F6260u: {
            TP_STATIC_GUARD(0x01EC4Cu, 0xA9u, 0x20u, 0x00u);
            const uint16_t value = 0x0020u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC4Fu, 0x000F6278u, 3u);
        }

        case 0x000F6278u: {
            TP_STATIC_GUARD(0x01EC4Fu, 0x8Du, 0x96u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0796u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC52u, 0x000F6290u, 5u);
        }

        case 0x000F6290u: {
            TP_STATIC_GUARD(0x01EC52u, 0x22u, 0xAFu, 0xDDu, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xECu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x55u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDDAFu, 0x000EED78u, 8u);
        }

        case 0x000F62B1u: {
            TP_STATIC_GUARD(0x01EC56u, 0x22u, 0x3Cu, 0xA3u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xECu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x59u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA33Cu, 0x003519E1u, 8u);
        }

        case 0x000F62D0u: {
            TP_STATIC_GUARD(0x01EC5Au, 0x22u, 0xFBu, 0xF1u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xECu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x5Du) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xF1FBu, 0x00678FD8u, 8u);
        }

        case 0x000F62F3u: {
            TP_STATIC_GUARD(0x01EC5Eu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xEC60u, 0x000F6303u, 3u);
        }

        case 0x000F6303u: {
            TP_STATIC_GUARD(0x01EC60u, 0xADu, 0x4Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x074Au;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC63u, 0x000F631Bu, 4u);
        }

        case 0x000F631Bu: {
            TP_STATIC_GUARD(0x01EC63u, 0xD0u, 0xFBu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xEC60u;
                if (tp_scpu_expect_next(cpu, 0x000F6303u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xEC65u, 0x000F632Bu, 2u);
        }

        case 0x000F632Bu: {
            TP_STATIC_GUARD(0x01EC65u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xEC67u, 0x000F6338u, 3u);
        }

        case 0x000F6338u: {
            TP_STATIC_GUARD(0x01EC67u, 0xAEu, 0x44u, 0x07u);
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
            TP_STATIC_EXIT(0x01u, 0xEC6Au, 0x000F6350u, 5u);
        }

        case 0x000F6350u: {
            TP_STATIC_GUARD(0x01EC6Au, 0x8Eu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0746u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC6Du, 0x000F6368u, 5u);
        }

        case 0x000F6368u: {
            TP_STATIC_GUARD(0x01EC6Du, 0x22u, 0x98u, 0x9Du, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xECu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x70u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9D98u, 0x0064ECC0u, 8u);
        }

        case 0x000F638Bu: {
            TP_STATIC_GUARD(0x01EC71u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xEC73u, 0x000F639Bu, 3u);
        }

        case 0x000F639Bu: {
            TP_STATIC_GUARD(0x01EC73u, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x01u, 0xEC76u, 0x000F63B3u, 4u);
        }

        case 0x000F63B3u: {
            TP_STATIC_GUARD(0x01EC76u, 0x29u, 0x08u);
            const uint8_t value = (uint8_t)(cpu->a & 0x08u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC78u, 0x000F63C3u, 2u);
        }

        case 0x000F63C3u: {
            TP_STATIC_GUARD(0x01EC78u, 0xF0u, 0x22u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xEC9Cu;
                if (tp_scpu_expect_next(cpu, 0x000F64E3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xEC7Au, 0x000F63D3u, 2u);
        }

        case 0x000F63D3u: {
            TP_STATIC_GUARD(0x01EC7Au, 0xADu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC7Du, 0x000F63EBu, 4u);
        }

        case 0x000F63EBu: {
            TP_STATIC_GUARD(0x01EC7Du, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xEC82u;
                if (tp_scpu_expect_next(cpu, 0x000F6413u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xEC7Fu, 0x000F63FBu, 2u);
        }

        case 0x000F63FBu: {
            TP_STATIC_GUARD(0x01EC7Fu, 0x82u, 0x90u, 0x00u);
            TP_STATIC_EXIT(0x01u, 0xED12u, 0x000F6893u, 4u);
        }

        case 0x000F6413u: {
            TP_STATIC_GUARD(0x01EC82u, 0xCEu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC85u, 0x000F642Bu, 6u);
        }

        case 0x000F642Bu: {
            TP_STATIC_GUARD(0x01EC85u, 0xADu, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0413u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC88u, 0x000F6443u, 4u);
        }

        case 0x000F6443u: {
            TP_STATIC_GUARD(0x01EC88u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xEC89u, 0x000F644Bu, 2u);
        }

        case 0x000F644Bu: {
            TP_STATIC_GUARD(0x01EC89u, 0xE9u, 0x08u);
            if (tp_scpu_sbc(cpu, 0x08u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC8Bu, 0x000F645Bu, 2u);
        }

        case 0x000F645Bu: {
            TP_STATIC_GUARD(0x01EC8Bu, 0x8Du, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0413u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC8Eu, 0x000F6473u, 4u);
        }

        case 0x000F6473u: {
            TP_STATIC_GUARD(0x01EC8Eu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xEC90u, 0x000F6480u, 3u);
        }

        case 0x000F6480u: {
            TP_STATIC_GUARD(0x01EC90u, 0xADu, 0x2Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xEC93u, 0x000F6498u, 5u);
        }

        case 0x000F6498u: {
            TP_STATIC_GUARD(0x01EC93u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xEC94u, 0x000F64A0u, 2u);
        }

        case 0x000F64A0u: {
            TP_STATIC_GUARD(0x01EC94u, 0xE9u, 0x00u, 0x10u);
            if (tp_scpu_sbc(cpu, 0x1000u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC97u, 0x000F64B8u, 3u);
        }

        case 0x000F64B8u: {
            TP_STATIC_GUARD(0x01EC97u, 0x8Du, 0x11u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0411u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xEC9Au, 0x000F64D0u, 5u);
        }

        case 0x000F64D0u: {
            TP_STATIC_GUARD(0x01EC9Au, 0x80u, 0x76u);
            TP_STATIC_EXIT(0x01u, 0xED12u, 0x000F6890u, 3u);
        }

        case 0x000F64E3u: {
            TP_STATIC_GUARD(0x01EC9Cu, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x01u, 0xEC9Fu, 0x000F64FBu, 4u);
        }

        case 0x000F64FBu: {
            TP_STATIC_GUARD(0x01EC9Fu, 0x29u, 0x04u);
            const uint8_t value = (uint8_t)(cpu->a & 0x04u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xECA1u, 0x000F650Bu, 2u);
        }

        case 0x000F650Bu: {
            TP_STATIC_GUARD(0x01ECA1u, 0xF0u, 0x21u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xECC4u;
                if (tp_scpu_expect_next(cpu, 0x000F6623u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xECA3u, 0x000F651Bu, 2u);
        }

        case 0x000F651Bu: {
            TP_STATIC_GUARD(0x01ECA3u, 0xADu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xECA6u, 0x000F6533u, 4u);
        }

        case 0x000F6533u: {
            TP_STATIC_GUARD(0x01ECA6u, 0xC9u, 0x03u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x03u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xECA8u, 0x000F6543u, 2u);
        }

        case 0x000F6543u: {
            TP_STATIC_GUARD(0x01ECA8u, 0xF0u, 0x68u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xED12u;
                if (tp_scpu_expect_next(cpu, 0x000F6893u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xECAAu, 0x000F6553u, 2u);
        }

        case 0x000F6553u: {
            TP_STATIC_GUARD(0x01ECAAu, 0xEEu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xECADu, 0x000F656Bu, 6u);
        }

        case 0x000F656Bu: {
            TP_STATIC_GUARD(0x01ECADu, 0xADu, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0413u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xECB0u, 0x000F6583u, 4u);
        }

        case 0x000F6583u: {
            TP_STATIC_GUARD(0x01ECB0u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xECB1u, 0x000F658Bu, 2u);
        }

        case 0x000F658Bu: {
            TP_STATIC_GUARD(0x01ECB1u, 0x69u, 0x08u);
            if (tp_scpu_adc(cpu, 0x08u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xECB3u, 0x000F659Bu, 2u);
        }

        case 0x000F659Bu: {
            TP_STATIC_GUARD(0x01ECB3u, 0x8Du, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0413u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xECB6u, 0x000F65B3u, 4u);
        }

        case 0x000F65B3u: {
            TP_STATIC_GUARD(0x01ECB6u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xECB8u, 0x000F65C0u, 3u);
        }

        case 0x000F65C0u: {
            TP_STATIC_GUARD(0x01ECB8u, 0xADu, 0x2Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xECBBu, 0x000F65D8u, 5u);
        }

        case 0x000F65D8u: {
            TP_STATIC_GUARD(0x01ECBBu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xECBCu, 0x000F65E0u, 2u);
        }

        case 0x000F65E0u: {
            TP_STATIC_GUARD(0x01ECBCu, 0x69u, 0x00u, 0x10u);
            if (tp_scpu_adc(cpu, 0x1000u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xECBFu, 0x000F65F8u, 3u);
        }

        case 0x000F65F8u: {
            TP_STATIC_GUARD(0x01ECBFu, 0x8Du, 0x11u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0411u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xECC2u, 0x000F6610u, 5u);
        }

        case 0x000F6610u: {
            TP_STATIC_GUARD(0x01ECC2u, 0x80u, 0x4Eu);
            TP_STATIC_EXIT(0x01u, 0xED12u, 0x000F6890u, 3u);
        }

        case 0x000F6623u: {
            TP_STATIC_GUARD(0x01ECC4u, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x01u, 0xECC7u, 0x000F663Bu, 4u);
        }

        case 0x000F663Bu: {
            TP_STATIC_GUARD(0x01ECC7u, 0x29u, 0x02u);
            const uint8_t value = (uint8_t)(cpu->a & 0x02u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xECC9u, 0x000F664Bu, 2u);
        }

        case 0x000F664Bu: {
            TP_STATIC_GUARD(0x01ECC9u, 0xF0u, 0x1Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xECEAu;
                if (tp_scpu_expect_next(cpu, 0x000F6753u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xECCBu, 0x000F665Bu, 2u);
        }

        case 0x000F665Bu: {
            TP_STATIC_GUARD(0x01ECCBu, 0xADu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xECCEu, 0x000F6673u, 4u);
        }

        case 0x000F6673u: {
            TP_STATIC_GUARD(0x01ECCEu, 0xF0u, 0x42u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xED12u;
                if (tp_scpu_expect_next(cpu, 0x000F6893u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xECD0u, 0x000F6683u, 2u);
        }

        case 0x000F6683u: {
            TP_STATIC_GUARD(0x01ECD0u, 0xCEu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xECD3u, 0x000F669Bu, 6u);
        }

        case 0x000F669Bu: {
            TP_STATIC_GUARD(0x01ECD3u, 0xADu, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0413u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xECD6u, 0x000F66B3u, 4u);
        }

        case 0x000F66B3u: {
            TP_STATIC_GUARD(0x01ECD6u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xECD7u, 0x000F66BBu, 2u);
        }

        case 0x000F66BBu: {
            TP_STATIC_GUARD(0x01ECD7u, 0xE9u, 0x01u);
            if (tp_scpu_sbc(cpu, 0x01u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xECD9u, 0x000F66CBu, 2u);
        }

        case 0x000F66CBu: {
            TP_STATIC_GUARD(0x01ECD9u, 0x8Du, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0413u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xECDCu, 0x000F66E3u, 4u);
        }

        case 0x000F66E3u: {
            TP_STATIC_GUARD(0x01ECDCu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xECDEu, 0x000F66F0u, 3u);
        }

        case 0x000F66F0u: {
            TP_STATIC_GUARD(0x01ECDEu, 0xADu, 0x2Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xECE1u, 0x000F6708u, 5u);
        }

        case 0x000F6708u: {
            TP_STATIC_GUARD(0x01ECE1u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xECE2u, 0x000F6710u, 2u);
        }

        case 0x000F6710u: {
            TP_STATIC_GUARD(0x01ECE2u, 0xE9u, 0x10u, 0x00u);
            if (tp_scpu_sbc(cpu, 0x0010u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xECE5u, 0x000F6728u, 3u);
        }

        case 0x000F6728u: {
            TP_STATIC_GUARD(0x01ECE5u, 0x8Du, 0x11u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0411u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xECE8u, 0x000F6740u, 5u);
        }

        case 0x000F6740u: {
            TP_STATIC_GUARD(0x01ECE8u, 0x80u, 0x28u);
            TP_STATIC_EXIT(0x01u, 0xED12u, 0x000F6890u, 3u);
        }

        case 0x000F6753u: {
            TP_STATIC_GUARD(0x01ECEAu, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x01u, 0xECEDu, 0x000F676Bu, 4u);
        }

        case 0x000F676Bu: {
            TP_STATIC_GUARD(0x01ECEDu, 0x29u, 0x01u);
            const uint8_t value = (uint8_t)(cpu->a & 0x01u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xECEFu, 0x000F677Bu, 2u);
        }

        case 0x000F677Bu: {
            TP_STATIC_GUARD(0x01ECEFu, 0xF0u, 0x21u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xED12u;
                if (tp_scpu_expect_next(cpu, 0x000F6893u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xECF1u, 0x000F678Bu, 2u);
        }

        case 0x000F678Bu: {
            TP_STATIC_GUARD(0x01ECF1u, 0xADu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xECF4u, 0x000F67A3u, 4u);
        }

        case 0x000F67A3u: {
            TP_STATIC_GUARD(0x01ECF4u, 0xC9u, 0x07u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x07u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xECF6u, 0x000F67B3u, 2u);
        }

        case 0x000F67B3u: {
            TP_STATIC_GUARD(0x01ECF6u, 0xF0u, 0x1Au);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xED12u;
                if (tp_scpu_expect_next(cpu, 0x000F6893u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xECF8u, 0x000F67C3u, 2u);
        }

        case 0x000F67C3u: {
            TP_STATIC_GUARD(0x01ECF8u, 0xEEu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xECFBu, 0x000F67DBu, 6u);
        }

        case 0x000F67DBu: {
            TP_STATIC_GUARD(0x01ECFBu, 0xADu, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0413u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xECFEu, 0x000F67F3u, 4u);
        }

        case 0x000F67F3u: {
            TP_STATIC_GUARD(0x01ECFEu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xECFFu, 0x000F67FBu, 2u);
        }

        case 0x000F67FBu: {
            TP_STATIC_GUARD(0x01ECFFu, 0x69u, 0x01u);
            if (tp_scpu_adc(cpu, 0x01u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xED01u, 0x000F680Bu, 2u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
