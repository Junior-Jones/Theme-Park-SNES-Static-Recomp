/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0004E1(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00270800u: {
            TP_STATIC_GUARD(0x04E100u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE102u, 0x00270813u, 3u);
        }

        case 0x00270813u: {
            TP_STATIC_GUARD(0x04E102u, 0x9Cu, 0x4Cu, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x084Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE105u, 0x0027082Bu, 4u);
        }

        case 0x0027082Bu: {
            TP_STATIC_GUARD(0x04E105u, 0x22u, 0x1Du, 0xFCu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x08u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xFC1Du, 0x0037E0EBu, 8u);
        }

        case 0x00270848u: {
            TP_STATIC_GUARD(0x04E109u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE10Eu;
                if (tp_scpu_expect_next(cpu, 0x00270870u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE10Bu, 0x00270858u, 2u);
        }

        case 0x00270858u: {
            TP_STATIC_GUARD(0x04E10Bu, 0x82u, 0xD1u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE1DFu, 0x00270EF8u, 4u);
        }

        case 0x00270870u: {
            TP_STATIC_GUARD(0x04E10Eu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE110u, 0x00270880u, 3u);
        }

        case 0x00270880u: {
            TP_STATIC_GUARD(0x04E110u, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE113u, 0x00270898u, 5u);
        }

        case 0x00270898u: {
            TP_STATIC_GUARD(0x04E113u, 0x29u, 0x01u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0001u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE116u, 0x002708B0u, 3u);
        }

        case 0x002708B0u: {
            TP_STATIC_GUARD(0x04E116u, 0xF0u, 0x3Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE157u;
                if (tp_scpu_expect_next(cpu, 0x00270AB8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE118u, 0x002708C0u, 2u);
        }

        case 0x002708C0u: {
            TP_STATIC_GUARD(0x04E118u, 0xA0u, 0x9Eu, 0x01u);
            const uint16_t value = 0x019Eu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE11Bu, 0x002708D8u, 3u);
        }

        case 0x002708D8u: {
            TP_STATIC_GUARD(0x04E11Bu, 0xB9u, 0x12u, 0x1Bu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1B12u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE11Eu, 0x002708F0u, 6u);
        }

        case 0x002708F0u: {
            TP_STATIC_GUARD(0x04E11Eu, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE11Fu, 0x002708F8u, 2u);
        }

        case 0x002708F8u: {
            TP_STATIC_GUARD(0x04E11Fu, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE120u, 0x00270900u, 2u);
        }

        case 0x00270900u: {
            TP_STATIC_GUARD(0x04E120u, 0xA9u, 0x03u, 0x00u);
            const uint16_t value = 0x0003u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE123u, 0x00270918u, 3u);
        }

        case 0x00270918u: {
            TP_STATIC_GUARD(0x04E123u, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x26u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x00270938u: {
            TP_STATIC_GUARD(0x04E127u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE128u, 0x00270940u, 2u);
        }

        case 0x00270940u: {
            TP_STATIC_GUARD(0x04E128u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xE129u, 0x00270948u, 2u);
        }

        case 0x00270948u: {
            TP_STATIC_GUARD(0x04E129u, 0x69u, 0x01u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0001u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE12Cu, 0x00270960u, 3u);
        }

        case 0x00270960u: {
            TP_STATIC_GUARD(0x04E12Cu, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE12Du, 0x00270968u, 2u);
        }

        case 0x00270968u: {
            TP_STATIC_GUARD(0x04E12Du, 0xBFu, 0x56u, 0xD3u, 0x01u);
            const uint32_t address = (0x01D356u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE131u, 0x00270988u, 6u);
        }

        case 0x00270988u: {
            TP_STATIC_GUARD(0x04E131u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE134u, 0x002709A0u, 3u);
        }

        case 0x002709A0u: {
            TP_STATIC_GUARD(0x04E134u, 0x3Au);
            cpu->a = (uint16_t)(cpu->a - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE135u, 0x002709A8u, 3u);
        }

        case 0x002709A8u: {
            TP_STATIC_GUARD(0x04E135u, 0xCDu, 0x60u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F60u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE138u, 0x002709C0u, 5u);
        }

        case 0x002709C0u: {
            TP_STATIC_GUARD(0x04E138u, 0xF0u, 0x02u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE13Cu;
                if (tp_scpu_expect_next(cpu, 0x002709E0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE13Au, 0x002709D0u, 2u);
        }

        case 0x002709D0u: {
            TP_STATIC_GUARD(0x04E13Au, 0xB0u, 0x03u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE13Fu;
                if (tp_scpu_expect_next(cpu, 0x002709F8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE13Cu, 0x002709E0u, 2u);
        }

        case 0x002709E0u: {
            TP_STATIC_GUARD(0x04E13Cu, 0x82u, 0xA0u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE1DFu, 0x00270EF8u, 4u);
        }

        case 0x002709F8u: {
            TP_STATIC_GUARD(0x04E13Fu, 0xEEu, 0x60u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F60u;
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
            TP_STATIC_EXIT(0x04u, 0xE142u, 0x00270A10u, 8u);
        }

        case 0x00270A10u: {
            TP_STATIC_GUARD(0x04E142u, 0x22u, 0xA0u, 0xFCu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x45u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xFCA0u, 0x0037E500u, 8u);
        }

        case 0x00270A32u: {
            TP_STATIC_GUARD(0x04E146u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE148u, 0x00270A40u, 3u);
        }

        case 0x00270A40u: {
            TP_STATIC_GUARD(0x04E148u, 0x10u, 0x06u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE150u;
                if (tp_scpu_expect_next(cpu, 0x00270A80u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE14Au, 0x00270A50u, 2u);
        }

        case 0x00270A50u: {
            TP_STATIC_GUARD(0x04E14Au, 0xCEu, 0x60u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F60u;
            uint16_t old_value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED ||
                tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE14Du, 0x00270A68u, 8u);
        }

        case 0x00270A68u: {
            TP_STATIC_GUARD(0x04E14Du, 0x82u, 0x8Fu, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE1DFu, 0x00270EF8u, 4u);
        }

        case 0x00270A80u: {
            TP_STATIC_GUARD(0x04E150u, 0x22u, 0xE8u, 0xECu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x53u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xECE8u, 0x00276740u, 8u);
        }

        case 0x00270AA0u: {
            TP_STATIC_GUARD(0x04E154u, 0x82u, 0x88u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE1DFu, 0x00270EF8u, 4u);
        }

        case 0x00270AB8u: {
            TP_STATIC_GUARD(0x04E157u, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE15Au, 0x00270AD0u, 5u);
        }

        case 0x00270AD0u: {
            TP_STATIC_GUARD(0x04E15Au, 0x29u, 0x02u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0002u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE15Du, 0x00270AE8u, 3u);
        }

        case 0x00270AE8u: {
            TP_STATIC_GUARD(0x04E15Du, 0xF0u, 0x1Au);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE179u;
                if (tp_scpu_expect_next(cpu, 0x00270BC8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE15Fu, 0x00270AF8u, 2u);
        }

        case 0x00270AF8u: {
            TP_STATIC_GUARD(0x04E15Fu, 0xADu, 0x60u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F60u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE162u, 0x00270B10u, 5u);
        }

        case 0x00270B10u: {
            TP_STATIC_GUARD(0x04E162u, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE165u, 0x00270B28u, 3u);
        }

        case 0x00270B28u: {
            TP_STATIC_GUARD(0x04E165u, 0xF0u, 0x02u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE169u;
                if (tp_scpu_expect_next(cpu, 0x00270B48u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE167u, 0x00270B38u, 2u);
        }

        case 0x00270B38u: {
            TP_STATIC_GUARD(0x04E167u, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE16Fu;
                if (tp_scpu_expect_next(cpu, 0x00270B78u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE169u, 0x00270B48u, 2u);
        }

        case 0x00270B48u: {
            TP_STATIC_GUARD(0x04E169u, 0x82u, 0x73u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE1DFu, 0x00270EF8u, 4u);
        }

        case 0x00270B78u: {
            TP_STATIC_GUARD(0x04E16Fu, 0xCEu, 0x60u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F60u;
            uint16_t old_value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED ||
                tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE172u, 0x00270B90u, 8u);
        }

        case 0x00270B90u: {
            TP_STATIC_GUARD(0x04E172u, 0x22u, 0xE8u, 0xECu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x75u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xECE8u, 0x00276740u, 8u);
        }

        case 0x00270BB0u: {
            TP_STATIC_GUARD(0x04E176u, 0x82u, 0x66u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE1DFu, 0x00270EF8u, 4u);
        }

        case 0x00270BC8u: {
            TP_STATIC_GUARD(0x04E179u, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE17Cu, 0x00270BE0u, 5u);
        }

        case 0x00270BE0u: {
            TP_STATIC_GUARD(0x04E17Cu, 0x29u, 0x04u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0004u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE17Fu, 0x00270BF8u, 3u);
        }

        case 0x00270BF8u: {
            TP_STATIC_GUARD(0x04E17Fu, 0xF0u, 0x3Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE1C0u;
                if (tp_scpu_expect_next(cpu, 0x00270E00u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE181u, 0x00270C08u, 2u);
        }

        case 0x00270C08u: {
            TP_STATIC_GUARD(0x04E181u, 0xA0u, 0x9Eu, 0x01u);
            const uint16_t value = 0x019Eu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE184u, 0x00270C20u, 3u);
        }

        case 0x00270C20u: {
            TP_STATIC_GUARD(0x04E184u, 0xB9u, 0x12u, 0x1Bu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1B12u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE187u, 0x00270C38u, 6u);
        }

        case 0x00270C38u: {
            TP_STATIC_GUARD(0x04E187u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE188u, 0x00270C40u, 2u);
        }

        case 0x00270C40u: {
            TP_STATIC_GUARD(0x04E188u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE189u, 0x00270C48u, 2u);
        }

        case 0x00270C48u: {
            TP_STATIC_GUARD(0x04E189u, 0xA9u, 0x03u, 0x00u);
            const uint16_t value = 0x0003u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE18Cu, 0x00270C60u, 3u);
        }

        case 0x00270C60u: {
            TP_STATIC_GUARD(0x04E18Cu, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Fu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x00270C80u: {
            TP_STATIC_GUARD(0x04E190u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE191u, 0x00270C88u, 2u);
        }

        case 0x00270C88u: {
            TP_STATIC_GUARD(0x04E191u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xE192u, 0x00270C90u, 2u);
        }

        case 0x00270C90u: {
            TP_STATIC_GUARD(0x04E192u, 0x69u, 0x02u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0002u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE195u, 0x00270CA8u, 3u);
        }

        case 0x00270CA8u: {
            TP_STATIC_GUARD(0x04E195u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE196u, 0x00270CB0u, 2u);
        }

        case 0x00270CB0u: {
            TP_STATIC_GUARD(0x04E196u, 0xBFu, 0x56u, 0xD3u, 0x01u);
            const uint32_t address = (0x01D356u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE19Au, 0x00270CD0u, 6u);
        }

        case 0x00270CD0u: {
            TP_STATIC_GUARD(0x04E19Au, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE19Du, 0x00270CE8u, 3u);
        }

        case 0x00270CE8u: {
            TP_STATIC_GUARD(0x04E19Du, 0x3Au);
            cpu->a = (uint16_t)(cpu->a - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE19Eu, 0x00270CF0u, 3u);
        }

        case 0x00270CF0u: {
            TP_STATIC_GUARD(0x04E19Eu, 0xCDu, 0x62u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F62u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1A1u, 0x00270D08u, 5u);
        }

        case 0x00270D08u: {
            TP_STATIC_GUARD(0x04E1A1u, 0xF0u, 0x02u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE1A5u;
                if (tp_scpu_expect_next(cpu, 0x00270D28u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE1A3u, 0x00270D18u, 2u);
        }

        case 0x00270D18u: {
            TP_STATIC_GUARD(0x04E1A3u, 0xB0u, 0x03u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE1A8u;
                if (tp_scpu_expect_next(cpu, 0x00270D40u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE1A5u, 0x00270D28u, 2u);
        }

        case 0x00270D28u: {
            TP_STATIC_GUARD(0x04E1A5u, 0x82u, 0x37u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE1DFu, 0x00270EF8u, 4u);
        }

        case 0x00270D40u: {
            TP_STATIC_GUARD(0x04E1A8u, 0xEEu, 0x62u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F62u;
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
            TP_STATIC_EXIT(0x04u, 0xE1ABu, 0x00270D58u, 8u);
        }

        case 0x00270D58u: {
            TP_STATIC_GUARD(0x04E1ABu, 0x22u, 0xA0u, 0xFCu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xAEu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xFCA0u, 0x0037E500u, 8u);
        }

        case 0x00270D7Au: {
            TP_STATIC_GUARD(0x04E1AFu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE1B1u, 0x00270D88u, 3u);
        }

        case 0x00270D88u: {
            TP_STATIC_GUARD(0x04E1B1u, 0x10u, 0x06u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE1B9u;
                if (tp_scpu_expect_next(cpu, 0x00270DC8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE1B3u, 0x00270D98u, 2u);
        }

        case 0x00270D98u: {
            TP_STATIC_GUARD(0x04E1B3u, 0xCEu, 0x62u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F62u;
            uint16_t old_value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED ||
                tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE1B6u, 0x00270DB0u, 8u);
        }

        case 0x00270DB0u: {
            TP_STATIC_GUARD(0x04E1B6u, 0x82u, 0x26u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE1DFu, 0x00270EF8u, 4u);
        }

        case 0x00270DC8u: {
            TP_STATIC_GUARD(0x04E1B9u, 0x22u, 0xF9u, 0xECu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBCu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xECF9u, 0x002767C8u, 8u);
        }

        case 0x00270DE8u: {
            TP_STATIC_GUARD(0x04E1BDu, 0x82u, 0x1Fu, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE1DFu, 0x00270EF8u, 4u);
        }

        case 0x00270E00u: {
            TP_STATIC_GUARD(0x04E1C0u, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1C3u, 0x00270E18u, 5u);
        }

        case 0x00270E18u: {
            TP_STATIC_GUARD(0x04E1C3u, 0x29u, 0x08u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0008u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1C6u, 0x00270E30u, 3u);
        }

        case 0x00270E30u: {
            TP_STATIC_GUARD(0x04E1C6u, 0xF0u, 0x17u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE1DFu;
                if (tp_scpu_expect_next(cpu, 0x00270EF8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE1C8u, 0x00270E40u, 2u);
        }

        case 0x00270E40u: {
            TP_STATIC_GUARD(0x04E1C8u, 0xADu, 0x62u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F62u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1CBu, 0x00270E58u, 5u);
        }

        case 0x00270E58u: {
            TP_STATIC_GUARD(0x04E1CBu, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1CEu, 0x00270E70u, 3u);
        }

        case 0x00270E70u: {
            TP_STATIC_GUARD(0x04E1CEu, 0xF0u, 0x02u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE1D2u;
                if (tp_scpu_expect_next(cpu, 0x00270E90u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE1D0u, 0x00270E80u, 2u);
        }

        case 0x00270E80u: {
            TP_STATIC_GUARD(0x04E1D0u, 0xB0u, 0x03u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE1D5u;
                if (tp_scpu_expect_next(cpu, 0x00270EA8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE1D2u, 0x00270E90u, 2u);
        }

        case 0x00270E90u: {
            TP_STATIC_GUARD(0x04E1D2u, 0x82u, 0x0Au, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE1DFu, 0x00270EF8u, 4u);
        }

        case 0x00270EA8u: {
            TP_STATIC_GUARD(0x04E1D5u, 0xCEu, 0x62u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F62u;
            uint16_t old_value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED ||
                tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE1D8u, 0x00270EC0u, 8u);
        }

        case 0x00270EC0u: {
            TP_STATIC_GUARD(0x04E1D8u, 0x22u, 0xF9u, 0xECu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xECF9u, 0x002767C8u, 8u);
        }

        case 0x00270EE0u: {
            TP_STATIC_GUARD(0x04E1DCu, 0x82u, 0x00u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xE1DFu, 0x00270EF8u, 4u);
        }

        case 0x00270EF8u: {
            TP_STATIC_GUARD(0x04E1DFu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE1E1u, 0x00270F08u, 3u);
        }

        case 0x00270F08u: {
            TP_STATIC_GUARD(0x04E1E1u, 0xA0u, 0x9Eu, 0x01u);
            const uint16_t value = 0x019Eu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1E4u, 0x00270F20u, 3u);
        }

        case 0x00270F20u: {
            TP_STATIC_GUARD(0x04E1E4u, 0xB9u, 0x12u, 0x1Bu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1B12u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1E7u, 0x00270F38u, 6u);
        }

        case 0x00270F38u: {
            TP_STATIC_GUARD(0x04E1E7u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1E8u, 0x00270F40u, 2u);
        }

        case 0x00270F40u: {
            TP_STATIC_GUARD(0x04E1E8u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1E9u, 0x00270F48u, 2u);
        }

        case 0x00270F48u: {
            TP_STATIC_GUARD(0x04E1E9u, 0xA9u, 0x03u, 0x00u);
            const uint16_t value = 0x0003u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1ECu, 0x00270F60u, 3u);
        }

        case 0x00270F60u: {
            TP_STATIC_GUARD(0x04E1ECu, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEFu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x00270F80u: {
            TP_STATIC_GUARD(0x04E1F0u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1F1u, 0x00270F88u, 2u);
        }

        case 0x00270F88u: {
            TP_STATIC_GUARD(0x04E1F1u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xE1F2u, 0x00270F90u, 2u);
        }

        case 0x00270F90u: {
            TP_STATIC_GUARD(0x04E1F2u, 0x69u, 0x01u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0001u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE1F5u, 0x00270FA8u, 3u);
        }

        case 0x00270FA8u: {
            TP_STATIC_GUARD(0x04E1F5u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1F6u, 0x00270FB0u, 2u);
        }

        case 0x00270FB0u: {
            TP_STATIC_GUARD(0x04E1F6u, 0xBFu, 0x56u, 0xD3u, 0x01u);
            const uint32_t address = (0x01D356u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1FAu, 0x00270FD0u, 6u);
        }

        case 0x00270FD0u: {
            TP_STATIC_GUARD(0x04E1FAu, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE1FDu, 0x00270FE8u, 3u);
        }

        case 0x00270FE8u: {
            TP_STATIC_GUARD(0x04E1FDu, 0xAEu, 0x62u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F62u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE200u, 0x00271000u, 5u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
