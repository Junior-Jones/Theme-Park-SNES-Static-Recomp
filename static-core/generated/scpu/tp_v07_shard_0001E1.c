/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0001E1(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x000F080Bu: {
            TP_STATIC_GUARD(0x01E101u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xE103u, 0x000F081Bu, 3u);
        }

        case 0x000F081Bu: {
            TP_STATIC_GUARD(0x01E103u, 0xADu, 0x4Au, 0x07u);
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
            TP_STATIC_EXIT(0x01u, 0xE106u, 0x000F0833u, 4u);
        }

        case 0x000F0833u: {
            TP_STATIC_GUARD(0x01E106u, 0xD0u, 0xFBu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xE103u;
                if (tp_scpu_expect_next(cpu, 0x000F081Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xE108u, 0x000F0843u, 2u);
        }

        case 0x000F0843u: {
            TP_STATIC_GUARD(0x01E108u, 0x22u, 0x3Fu, 0x98u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x983Fu, 0x0004C1FBu, 8u);
        }

        case 0x000F0860u: {
            TP_STATIC_GUARD(0x01E10Cu, 0x22u, 0x70u, 0xE1u, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Fu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE170u, 0x000F0B80u, 8u);
        }

        case 0x000F0880u: {
            TP_STATIC_GUARD(0x01E110u, 0x22u, 0xF0u, 0xE8u, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x13u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE8F0u, 0x000F4780u, 8u);
        }

        case 0x000F08A0u: {
            TP_STATIC_GUARD(0x01E114u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xE116u, 0x000F08B3u, 3u);
        }

        case 0x000F08B3u: {
            TP_STATIC_GUARD(0x01E116u, 0xA9u, 0x13u);
            const uint8_t value = 0x13u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE118u, 0x000F08C3u, 2u);
        }

        case 0x000F08C3u: {
            TP_STATIC_GUARD(0x01E118u, 0x8Du, 0x2Cu, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x212Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE11Bu, 0x000F08DBu, 4u);
        }

        case 0x000F08DBu: {
            TP_STATIC_GUARD(0x01E11Bu, 0x82u, 0xA9u, 0xFDu);
            TP_STATIC_EXIT(0x01u, 0xDEC7u, 0x000EF63Bu, 4u);
        }

        case 0x000F08F3u: {
            TP_STATIC_GUARD(0x01E11Eu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xE120u, 0x000F0903u, 3u);
        }

        case 0x000F0903u: {
            TP_STATIC_GUARD(0x01E120u, 0xA9u, 0x0Cu);
            const uint8_t value = 0x0Cu;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE122u, 0x000F0913u, 2u);
        }

        case 0x000F0913u: {
            TP_STATIC_GUARD(0x01E122u, 0x8Du, 0x8Cu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE125u, 0x000F092Bu, 4u);
        }

        case 0x000F092Bu: {
            TP_STATIC_GUARD(0x01E125u, 0x22u, 0x49u, 0x87u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x28u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8749u, 0x00643A4Bu, 8u);
        }

        case 0x000F094Bu: {
            TP_STATIC_GUARD(0x01E129u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xE12Bu, 0x000F095Bu, 3u);
        }

        case 0x000F095Bu: {
            TP_STATIC_GUARD(0x01E12Bu, 0xA9u, 0x0Fu);
            const uint8_t value = 0x0Fu;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE12Du, 0x000F096Bu, 2u);
        }

        case 0x000F096Bu: {
            TP_STATIC_GUARD(0x01E12Du, 0x8Du, 0x0Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Eu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE130u, 0x000F0983u, 4u);
        }

        case 0x000F0983u: {
            TP_STATIC_GUARD(0x01E130u, 0xA9u, 0xFFu);
            const uint8_t value = 0xFFu;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE132u, 0x000F0993u, 2u);
        }

        case 0x000F0993u: {
            TP_STATIC_GUARD(0x01E132u, 0x8Du, 0x0Fu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Fu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE135u, 0x000F09ABu, 4u);
        }

        case 0x000F09ABu: {
            TP_STATIC_GUARD(0x01E135u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xE137u, 0x000F09BBu, 3u);
        }

        case 0x000F09BBu: {
            TP_STATIC_GUARD(0x01E137u, 0xADu, 0x0Fu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Fu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE13Au, 0x000F09D3u, 4u);
        }

        case 0x000F09D3u: {
            TP_STATIC_GUARD(0x01E13Au, 0xD0u, 0xFBu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xE137u;
                if (tp_scpu_expect_next(cpu, 0x000F09BBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xE13Cu, 0x000F09E3u, 2u);
        }

        case 0x000F09E3u: {
            TP_STATIC_GUARD(0x01E13Cu, 0xA9u, 0x13u);
            const uint8_t value = 0x13u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE13Eu, 0x000F09F3u, 2u);
        }

        case 0x000F09F3u: {
            TP_STATIC_GUARD(0x01E13Eu, 0x8Du, 0x2Cu, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x212Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE141u, 0x000F0A0Bu, 4u);
        }

        case 0x000F0A0Bu: {
            TP_STATIC_GUARD(0x01E141u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE143u, 0x000F0A18u, 3u);
        }

        case 0x000F0A18u: {
            TP_STATIC_GUARD(0x01E143u, 0xA9u, 0xFFu, 0xFFu);
            const uint16_t value = 0xFFFFu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE146u, 0x000F0A30u, 3u);
        }

        case 0x000F0A30u: {
            TP_STATIC_GUARD(0x01E146u, 0x8Du, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07A2u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE149u, 0x000F0A48u, 5u);
        }

        case 0x000F0A48u: {
            TP_STATIC_GUARD(0x01E149u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xE14Bu, 0x000F0A59u, 3u);
        }

        case 0x000F0A59u: {
            TP_STATIC_GUARD(0x01E14Bu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x01u, 0xE14Du, 0x000F0A69u, 3u);
        }

        case 0x000F0A69u: {
            TP_STATIC_GUARD(0x01E14Du, 0xFAu);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE14Eu, 0x000F0A71u, 4u);
        }

        case 0x000F0A71u: {
            TP_STATIC_GUARD(0x01E14Eu, 0x8Eu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE151u, 0x000F0A89u, 4u);
        }

        case 0x000F0A89u: {
            TP_STATIC_GUARD(0x01E151u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE152u, 0x000F0A91u, 5u);
        }

        case 0x000F0A91u: {
            TP_STATIC_GUARD(0x01E152u, 0x8Du, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0016u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE155u, 0x000F0AA9u, 5u);
        }

        case 0x000F0AA9u: {
            TP_STATIC_GUARD(0x01E155u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE157u, 0x000F0AB8u, 3u);
        }

        case 0x000F0AB8u: {
            TP_STATIC_GUARD(0x01E157u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE158u, 0x000F0AC0u, 5u);
        }

        case 0x000F0AC0u: {
            TP_STATIC_GUARD(0x01E158u, 0x8Du, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0415u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE15Bu, 0x000F0AD8u, 5u);
        }

        case 0x000F0AD8u: {
            TP_STATIC_GUARD(0x01E15Bu, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE15Cu, 0x000F0AE0u, 5u);
        }

        case 0x000F0AE0u: {
            TP_STATIC_GUARD(0x01E15Cu, 0x8Du, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0413u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE15Fu, 0x000F0AF8u, 5u);
        }

        case 0x000F0AF8u: {
            TP_STATIC_GUARD(0x01E15Fu, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE160u, 0x000F0B00u, 5u);
        }

        case 0x000F0B00u: {
            TP_STATIC_GUARD(0x01E160u, 0x8Du, 0x11u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0411u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE163u, 0x000F0B18u, 5u);
        }

        case 0x000F0B18u: {
            TP_STATIC_GUARD(0x01E163u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE164u, 0x000F0B20u, 5u);
        }

        case 0x000F0B20u: {
            TP_STATIC_GUARD(0x01E164u, 0x8Du, 0x0Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Fu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE167u, 0x000F0B38u, 5u);
        }

        case 0x000F0B38u: {
            TP_STATIC_GUARD(0x01E167u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE168u, 0x000F0B40u, 5u);
        }

        case 0x000F0B40u: {
            TP_STATIC_GUARD(0x01E168u, 0x8Du, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE16Bu, 0x000F0B58u, 5u);
        }

        case 0x000F0B58u: {
            TP_STATIC_GUARD(0x01E16Bu, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE16Cu, 0x000F0B60u, 5u);
        }

        case 0x000F0B60u: {
            TP_STATIC_GUARD(0x01E16Cu, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE16Fu, 0x000F0B78u, 5u);
        }

        case 0x000F0B78u: {
            TP_STATIC_GUARD(0x01E16Fu, 0x6Bu);
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
                case 0x000ED420u:
                case 0x000FBCD0u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x000F0B80u: {
            TP_STATIC_GUARD(0x01E170u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE172u, 0x000F0B90u, 3u);
        }

        case 0x000F0B81u: {
            TP_STATIC_GUARD(0x01E170u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE172u, 0x000F0B90u, 3u);
        }

        case 0x000F0B90u: {
            TP_STATIC_GUARD(0x01E172u, 0xADu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE175u, 0x000F0BA8u, 5u);
        }

        case 0x000F0BA8u: {
            TP_STATIC_GUARD(0x01E175u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE176u, 0x000F0BB0u, 4u);
        }

        case 0x000F0BB0u: {
            TP_STATIC_GUARD(0x01E176u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xE178u, 0x000F0BC1u, 3u);
        }

        case 0x000F0BC1u: {
            TP_STATIC_GUARD(0x01E178u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x01u, 0xE17Au, 0x000F0BD1u, 3u);
        }

        case 0x000F0BD1u: {
            TP_STATIC_GUARD(0x01E17Au, 0xADu, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0016u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE17Du, 0x000F0BE9u, 5u);
        }

        case 0x000F0BE9u: {
            TP_STATIC_GUARD(0x01E17Du, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE17Eu, 0x000F0BF1u, 4u);
        }

        case 0x000F0BF1u: {
            TP_STATIC_GUARD(0x01E17Eu, 0xAEu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE181u, 0x000F0C09u, 4u);
        }

        case 0x000F0C09u: {
            TP_STATIC_GUARD(0x01E181u, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE182u, 0x000F0C11u, 3u);
        }

        case 0x000F0C11u: {
            TP_STATIC_GUARD(0x01E182u, 0xADu, 0x19u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0019u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE185u, 0x000F0C29u, 5u);
        }

        case 0x000F0C29u: {
            TP_STATIC_GUARD(0x01E185u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE186u, 0x000F0C31u, 4u);
        }

        case 0x000F0C31u: {
            TP_STATIC_GUARD(0x01E186u, 0xAEu, 0x1Bu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x001Bu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE189u, 0x000F0C49u, 4u);
        }

        case 0x000F0C49u: {
            TP_STATIC_GUARD(0x01E189u, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE18Au, 0x000F0C51u, 3u);
        }

        case 0x000F0C51u: {
            TP_STATIC_GUARD(0x01E18Au, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xE18Cu, 0x000F0C61u, 3u);
        }

        case 0x000F0C61u: {
            TP_STATIC_GUARD(0x01E18Cu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x01u, 0xE18Eu, 0x000F0C71u, 3u);
        }

        case 0x000F0C71u: {
            TP_STATIC_GUARD(0x01E18Eu, 0xA9u, 0x00u, 0x6Eu);
            const uint16_t value = 0x6E00u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE191u, 0x000F0C89u, 3u);
        }

        case 0x000F0C89u: {
            TP_STATIC_GUARD(0x01E191u, 0x8Du, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0016u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE194u, 0x000F0CA1u, 5u);
        }

        case 0x000F0CA1u: {
            TP_STATIC_GUARD(0x01E194u, 0xA2u, 0x7Eu);
            const uint8_t value = 0x7Eu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE196u, 0x000F0CB1u, 2u);
        }

        case 0x000F0CB1u: {
            TP_STATIC_GUARD(0x01E196u, 0x8Eu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE199u, 0x000F0CC9u, 4u);
        }

        case 0x000F0CC9u: {
            TP_STATIC_GUARD(0x01E199u, 0x9Cu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0415u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE19Cu, 0x000F0CE1u, 5u);
        }

        case 0x000F0CE0u: {
            TP_STATIC_GUARD(0x01E19Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE19Eu, 0x000F0CF0u, 3u);
        }

        case 0x000F0CE1u: {
            TP_STATIC_GUARD(0x01E19Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE19Eu, 0x000F0CF0u, 3u);
        }

        case 0x000F0CF0u: {
            TP_STATIC_GUARD(0x01E19Eu, 0xACu, 0x15u, 0x04u);
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
            TP_STATIC_EXIT(0x01u, 0xE1A1u, 0x000F0D08u, 5u);
        }

        case 0x000F0D08u: {
            TP_STATIC_GUARD(0x01E1A1u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1A2u, 0x000F0D10u, 2u);
        }

        case 0x000F0D10u: {
            TP_STATIC_GUARD(0x01E1A2u, 0xA9u, 0x1Au, 0x00u);
            const uint16_t value = 0x001Au;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1A5u, 0x000F0D28u, 3u);
        }

        case 0x000F0D28u: {
            TP_STATIC_GUARD(0x01E1A5u, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x000F0D48u: {
            TP_STATIC_GUARD(0x01E1A9u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1AAu, 0x000F0D50u, 2u);
        }

        case 0x000F0D50u: {
            TP_STATIC_GUARD(0x01E1AAu, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1ABu, 0x000F0D58u, 2u);
        }

        case 0x000F0D58u: {
            TP_STATIC_GUARD(0x01E1ABu, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xE1ADu, 0x000F0D6Au, 3u);
        }

        case 0x000F0D6Au: {
            TP_STATIC_GUARD(0x01E1ADu, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x01u, 0xE1AFu, 0x000F0D7Au, 3u);
        }

        case 0x000F0D7Au: {
            TP_STATIC_GUARD(0x01E1AFu, 0xBFu, 0xCEu, 0xC8u, 0x01u);
            const uint32_t address = (0x01C8CEu + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1B3u, 0x000F0D9Au, 5u);
        }

        case 0x000F0D9Au: {
            TP_STATIC_GUARD(0x01E1B3u, 0x29u, 0xFFu);
            const uint8_t value = (uint8_t)(cpu->a & 0xFFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1B5u, 0x000F0DAAu, 2u);
        }

        case 0x000F0DAAu: {
            TP_STATIC_GUARD(0x01E1B5u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xE1BAu;
                if (tp_scpu_expect_next(cpu, 0x000F0DD2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xE1B7u, 0x000F0DBAu, 2u);
        }

        case 0x000F0DBAu: {
            TP_STATIC_GUARD(0x01E1B7u, 0x82u, 0x7Eu, 0x00u);
            TP_STATIC_EXIT(0x01u, 0xE238u, 0x000F11C2u, 4u);
        }

        case 0x000F0DD2u: {
            TP_STATIC_GUARD(0x01E1BAu, 0xACu, 0x15u, 0x04u);
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
            TP_STATIC_EXIT(0x01u, 0xE1BDu, 0x000F0DEAu, 5u);
        }

        case 0x000F0DEAu: {
            TP_STATIC_GUARD(0x01E1BDu, 0xB9u, 0x2Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x072Au + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1C0u, 0x000F0E02u, 5u);
        }

        case 0x000F0E02u: {
            TP_STATIC_GUARD(0x01E1C0u, 0x30u, 0x16u);
            if ((cpu->p & TP_P_N) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xE1D8u;
                if (tp_scpu_expect_next(cpu, 0x000F0EC2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xE1C2u, 0x000F0E12u, 2u);
        }

        case 0x000F0E12u: {
            TP_STATIC_GUARD(0x01E1C2u, 0xF0u, 0x0Au);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xE1CEu;
                if (tp_scpu_expect_next(cpu, 0x000F0E72u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xE1C4u, 0x000F0E22u, 2u);
        }

        case 0x000F0E22u: {
            TP_STATIC_GUARD(0x01E1C4u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE1C6u, 0x000F0E30u, 3u);
        }

        case 0x000F0E30u: {
            TP_STATIC_GUARD(0x01E1C6u, 0xA9u, 0x00u, 0x38u);
            const uint16_t value = 0x3800u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1C9u, 0x000F0E48u, 3u);
        }

        case 0x000F0E48u: {
            TP_STATIC_GUARD(0x01E1C9u, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE1CCu, 0x000F0E60u, 5u);
        }

        case 0x000F0E60u: {
            TP_STATIC_GUARD(0x01E1CCu, 0x80u, 0x4Eu);
            TP_STATIC_EXIT(0x01u, 0xE21Cu, 0x000F10E0u, 3u);
        }

        case 0x000F0E72u: {
            TP_STATIC_GUARD(0x01E1CEu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE1D0u, 0x000F0E80u, 3u);
        }

        case 0x000F0E80u: {
            TP_STATIC_GUARD(0x01E1D0u, 0xA9u, 0x00u, 0x3Cu);
            const uint16_t value = 0x3C00u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1D3u, 0x000F0E98u, 3u);
        }

        case 0x000F0E98u: {
            TP_STATIC_GUARD(0x01E1D3u, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE1D6u, 0x000F0EB0u, 5u);
        }

        case 0x000F0EB0u: {
            TP_STATIC_GUARD(0x01E1D6u, 0x80u, 0x44u);
            TP_STATIC_EXIT(0x01u, 0xE21Cu, 0x000F10E0u, 3u);
        }

        case 0x000F0EC2u: {
            TP_STATIC_GUARD(0x01E1D8u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE1DAu, 0x000F0ED0u, 3u);
        }

        case 0x000F0ED0u: {
            TP_STATIC_GUARD(0x01E1DAu, 0xA9u, 0xA0u, 0x86u);
            const uint16_t value = 0x86A0u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1DDu, 0x000F0EE8u, 3u);
        }

        case 0x000F0EE8u: {
            TP_STATIC_GUARD(0x01E1DDu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE1E0u, 0x000F0F00u, 5u);
        }

        case 0x000F0F00u: {
            TP_STATIC_GUARD(0x01E1E0u, 0xA9u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1E3u, 0x000F0F18u, 3u);
        }

        case 0x000F0F18u: {
            TP_STATIC_GUARD(0x01E1E3u, 0x8Du, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Cu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE1E6u, 0x000F0F30u, 5u);
        }

        case 0x000F0F30u: {
            TP_STATIC_GUARD(0x01E1E6u, 0xBFu, 0xCFu, 0xC8u, 0x01u);
            const uint32_t address = (0x01C8CFu + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1EAu, 0x000F0F50u, 6u);
        }

        case 0x000F0F50u: {
            TP_STATIC_GUARD(0x01E1EAu, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE1EDu, 0x000F0F68u, 5u);
        }

        case 0x000F0F68u: {
            TP_STATIC_GUARD(0x01E1EDu, 0x9Cu, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0790u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE1F0u, 0x000F0F80u, 5u);
        }

        case 0x000F0F80u: {
            TP_STATIC_GUARD(0x01E1F0u, 0x22u, 0x9Au, 0xFAu, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFA9Au, 0x003FD4D0u, 8u);
        }

        case 0x000F0FA0u: {
            TP_STATIC_GUARD(0x01E1F4u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE1F6u, 0x000F0FB0u, 3u);
        }

        case 0x000F0FB0u: {
            TP_STATIC_GUARD(0x01E1F6u, 0xA0u, 0x0Cu, 0x00u);
            const uint16_t value = 0x000Cu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1F9u, 0x000F0FC8u, 3u);
        }

        case 0x000F0FC8u: {
            TP_STATIC_GUARD(0x01E1F9u, 0xB7u, 0x58u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x58u);
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
            cpu->pbr = 0x01u;
            cpu->pc = 0xE1FBu;
            if (tp_scpu_expect_next(cpu, 0x000F0FD8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x000F0FD8u: {
            TP_STATIC_GUARD(0x01E1FBu, 0xCDu, 0xA4u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A4u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE1FEu, 0x000F0FF0u, 5u);
        }

        case 0x000F0FF0u: {
            TP_STATIC_GUARD(0x01E1FEu, 0x90u, 0x16u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xE216u;
                if (tp_scpu_expect_next(cpu, 0x000F10B0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xE200u, 0x000F1000u, 2u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
