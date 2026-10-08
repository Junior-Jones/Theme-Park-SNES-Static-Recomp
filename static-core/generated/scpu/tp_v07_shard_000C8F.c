/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000C8F(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00647800u: {
            TP_STATIC_GUARD(0x0C8F00u, 0x90u, 0x05u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8F07u;
                if (tp_scpu_expect_next(cpu, 0x00647838u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8F02u, 0x00647810u, 2u);
        }

        case 0x00647810u: {
            TP_STATIC_GUARD(0x0C8F02u, 0x29u, 0x0Fu, 0x0Fu);
            cpu->a = (uint16_t)(cpu->a & 0x0F0Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F05u, 0x00647828u, 3u);
        }

        case 0x00647828u: {
            TP_STATIC_GUARD(0x0C8F05u, 0x80u, 0x03u);
            TP_STATIC_EXIT(0x0Cu, 0x8F0Au, 0x00647850u, 3u);
        }

        case 0x00647838u: {
            TP_STATIC_GUARD(0x0C8F07u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F0Au, 0x00647850u, 3u);
        }

        case 0x00647850u: {
            TP_STATIC_GUARD(0x0C8F0Au, 0x9Fu, 0x11u, 0xBFu, 0x7Eu);
            const uint32_t address = (0x7EBF11u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8F0Eu, 0x00647870u, 6u);
        }

        case 0x00647870u: {
            TP_STATIC_GUARD(0x0C8F0Eu, 0x9Fu, 0x69u, 0xBFu, 0x7Eu);
            const uint32_t address = (0x7EBF69u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8F12u, 0x00647890u, 6u);
        }

        case 0x00647890u: {
            TP_STATIC_GUARD(0x0C8F12u, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F13u, 0x00647898u, 2u);
        }

        case 0x00647898u: {
            TP_STATIC_GUARD(0x0C8F13u, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F14u, 0x006478A0u, 2u);
        }

        case 0x006478A0u: {
            TP_STATIC_GUARD(0x0C8F14u, 0xEEu, 0x15u, 0x04u);
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
            TP_STATIC_EXIT(0x0Cu, 0x8F17u, 0x006478B8u, 8u);
        }

        case 0x006478B8u: {
            TP_STATIC_GUARD(0x0C8F17u, 0xADu, 0x15u, 0x04u);
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
            TP_STATIC_EXIT(0x0Cu, 0x8F1Au, 0x006478D0u, 5u);
        }

        case 0x006478D0u: {
            TP_STATIC_GUARD(0x0C8F1Au, 0xC9u, 0x04u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0004u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F1Du, 0x006478E8u, 3u);
        }

        case 0x006478E8u: {
            TP_STATIC_GUARD(0x0C8F1Du, 0xD0u, 0xA7u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8EC6u;
                if (tp_scpu_expect_next(cpu, 0x00647630u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8F1Fu, 0x006478F8u, 2u);
        }

        case 0x006478F8u: {
            TP_STATIC_GUARD(0x0C8F1Fu, 0x8Au);
            cpu->a = cpu->x;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F20u, 0x00647900u, 2u);
        }

        case 0x00647900u: {
            TP_STATIC_GUARD(0x0C8F20u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x8F21u, 0x00647908u, 2u);
        }

        case 0x00647908u: {
            TP_STATIC_GUARD(0x0C8F21u, 0x69u, 0x18u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0018u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8F24u, 0x00647920u, 3u);
        }

        case 0x00647920u: {
            TP_STATIC_GUARD(0x0C8F24u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F25u, 0x00647928u, 2u);
        }

        case 0x00647928u: {
            TP_STATIC_GUARD(0x0C8F25u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F26u, 0x00647930u, 2u);
        }

        case 0x00647930u: {
            TP_STATIC_GUARD(0x0C8F26u, 0xD0u, 0x9Bu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8EC3u;
                if (tp_scpu_expect_next(cpu, 0x00647618u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8F28u, 0x00647940u, 2u);
        }

        case 0x00647940u: {
            TP_STATIC_GUARD(0x0C8F28u, 0xA9u, 0x03u, 0x00u);
            const uint16_t value = 0x0003u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F2Bu, 0x00647958u, 3u);
        }

        case 0x00647958u: {
            TP_STATIC_GUARD(0x0C8F2Bu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x8F2Cu, 0x00647960u, 2u);
        }

        case 0x00647960u: {
            TP_STATIC_GUARD(0x0C8F2Cu, 0xEDu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8F2Fu, 0x00647978u, 5u);
        }

        case 0x00647978u: {
            TP_STATIC_GUARD(0x0C8F2Fu, 0xF0u, 0x66u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8F97u;
                if (tp_scpu_expect_next(cpu, 0x00647CB8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8F31u, 0x00647988u, 2u);
        }

        case 0x00647988u: {
            TP_STATIC_GUARD(0x0C8F31u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F32u, 0x00647990u, 2u);
        }

        case 0x00647990u: {
            TP_STATIC_GUARD(0x0C8F32u, 0x9Cu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0415u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8F35u, 0x006479A8u, 5u);
        }

        case 0x006479A8u: {
            TP_STATIC_GUARD(0x0C8F35u, 0xBFu, 0x21u, 0xBFu, 0x7Eu);
            const uint32_t address = (0x7EBF21u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F39u, 0x006479C8u, 6u);
        }

        case 0x006479C8u: {
            TP_STATIC_GUARD(0x0C8F39u, 0xE0u, 0x08u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F3Cu, 0x006479E0u, 3u);
        }

        case 0x006479E0u: {
            TP_STATIC_GUARD(0x0C8F3Cu, 0xB0u, 0x08u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8F46u;
                if (tp_scpu_expect_next(cpu, 0x00647A30u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8F3Eu, 0x006479F0u, 2u);
        }

        case 0x006479F0u: {
            TP_STATIC_GUARD(0x0C8F3Eu, 0x29u, 0xC0u, 0xC0u);
            cpu->a = (uint16_t)(cpu->a & 0xC0C0u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F41u, 0x00647A08u, 3u);
        }

        case 0x00647A08u: {
            TP_STATIC_GUARD(0x0C8F41u, 0x09u, 0x3Fu, 0x00u);
            cpu->a = (uint16_t)(cpu->a | 0x003Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F44u, 0x00647A20u, 3u);
        }

        case 0x00647A20u: {
            TP_STATIC_GUARD(0x0C8F44u, 0x80u, 0x10u);
            TP_STATIC_EXIT(0x0Cu, 0x8F56u, 0x00647AB0u, 3u);
        }

        case 0x00647A30u: {
            TP_STATIC_GUARD(0x0C8F46u, 0xE0u, 0x40u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0040u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F49u, 0x00647A48u, 3u);
        }

        case 0x00647A48u: {
            TP_STATIC_GUARD(0x0C8F49u, 0x90u, 0x08u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8F53u;
                if (tp_scpu_expect_next(cpu, 0x00647A98u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8F4Bu, 0x00647A58u, 2u);
        }

        case 0x00647A58u: {
            TP_STATIC_GUARD(0x0C8F4Bu, 0x29u, 0x0Fu, 0x0Fu);
            cpu->a = (uint16_t)(cpu->a & 0x0F0Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F4Eu, 0x00647A70u, 3u);
        }

        case 0x00647A70u: {
            TP_STATIC_GUARD(0x0C8F4Eu, 0x09u, 0xF0u, 0x00u);
            cpu->a = (uint16_t)(cpu->a | 0x00F0u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F51u, 0x00647A88u, 3u);
        }

        case 0x00647A88u: {
            TP_STATIC_GUARD(0x0C8F51u, 0x80u, 0x03u);
            TP_STATIC_EXIT(0x0Cu, 0x8F56u, 0x00647AB0u, 3u);
        }

        case 0x00647A98u: {
            TP_STATIC_GUARD(0x0C8F53u, 0xA9u, 0xFFu, 0x00u);
            const uint16_t value = 0x00FFu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F56u, 0x00647AB0u, 3u);
        }

        case 0x00647AB0u: {
            TP_STATIC_GUARD(0x0C8F56u, 0x9Fu, 0x21u, 0xBFu, 0x7Eu);
            const uint32_t address = (0x7EBF21u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8F5Au, 0x00647AD0u, 6u);
        }

        case 0x00647AD0u: {
            TP_STATIC_GUARD(0x0C8F5Au, 0x9Fu, 0x79u, 0xBFu, 0x7Eu);
            const uint32_t address = (0x7EBF79u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8F5Eu, 0x00647AF0u, 6u);
        }

        case 0x00647AF0u: {
            TP_STATIC_GUARD(0x0C8F5Eu, 0xBFu, 0x11u, 0xBFu, 0x7Eu);
            const uint32_t address = (0x7EBF11u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F62u, 0x00647B10u, 6u);
        }

        case 0x00647B10u: {
            TP_STATIC_GUARD(0x0C8F62u, 0xE0u, 0x08u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F65u, 0x00647B28u, 3u);
        }

        case 0x00647B28u: {
            TP_STATIC_GUARD(0x0C8F65u, 0xB0u, 0x05u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8F6Cu;
                if (tp_scpu_expect_next(cpu, 0x00647B60u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8F67u, 0x00647B38u, 2u);
        }

        case 0x00647B38u: {
            TP_STATIC_GUARD(0x0C8F67u, 0x29u, 0xC0u, 0xC0u);
            cpu->a = (uint16_t)(cpu->a & 0xC0C0u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F6Au, 0x00647B50u, 3u);
        }

        case 0x00647B50u: {
            TP_STATIC_GUARD(0x0C8F6Au, 0x80u, 0x0Du);
            TP_STATIC_EXIT(0x0Cu, 0x8F79u, 0x00647BC8u, 3u);
        }

        case 0x00647B60u: {
            TP_STATIC_GUARD(0x0C8F6Cu, 0xE0u, 0x40u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0040u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F6Fu, 0x00647B78u, 3u);
        }

        case 0x00647B78u: {
            TP_STATIC_GUARD(0x0C8F6Fu, 0x90u, 0x05u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8F76u;
                if (tp_scpu_expect_next(cpu, 0x00647BB0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8F71u, 0x00647B88u, 2u);
        }

        case 0x00647B88u: {
            TP_STATIC_GUARD(0x0C8F71u, 0x29u, 0x0Fu, 0x0Fu);
            cpu->a = (uint16_t)(cpu->a & 0x0F0Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F74u, 0x00647BA0u, 3u);
        }

        case 0x00647BA0u: {
            TP_STATIC_GUARD(0x0C8F74u, 0x80u, 0x03u);
            TP_STATIC_EXIT(0x0Cu, 0x8F79u, 0x00647BC8u, 3u);
        }

        case 0x00647BB0u: {
            TP_STATIC_GUARD(0x0C8F76u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F79u, 0x00647BC8u, 3u);
        }

        case 0x00647BC8u: {
            TP_STATIC_GUARD(0x0C8F79u, 0x9Fu, 0x11u, 0xBFu, 0x7Eu);
            const uint32_t address = (0x7EBF11u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8F7Du, 0x00647BE8u, 6u);
        }

        case 0x00647BE8u: {
            TP_STATIC_GUARD(0x0C8F7Du, 0x9Fu, 0x69u, 0xBFu, 0x7Eu);
            const uint32_t address = (0x7EBF69u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8F81u, 0x00647C08u, 6u);
        }

        case 0x00647C08u: {
            TP_STATIC_GUARD(0x0C8F81u, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F82u, 0x00647C10u, 2u);
        }

        case 0x00647C10u: {
            TP_STATIC_GUARD(0x0C8F82u, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F83u, 0x00647C18u, 2u);
        }

        case 0x00647C18u: {
            TP_STATIC_GUARD(0x0C8F83u, 0xEEu, 0x15u, 0x04u);
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
            TP_STATIC_EXIT(0x0Cu, 0x8F86u, 0x00647C30u, 8u);
        }

        case 0x00647C30u: {
            TP_STATIC_GUARD(0x0C8F86u, 0xADu, 0x15u, 0x04u);
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
            TP_STATIC_EXIT(0x0Cu, 0x8F89u, 0x00647C48u, 5u);
        }

        case 0x00647C48u: {
            TP_STATIC_GUARD(0x0C8F89u, 0xC9u, 0x04u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0004u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F8Cu, 0x00647C60u, 3u);
        }

        case 0x00647C60u: {
            TP_STATIC_GUARD(0x0C8F8Cu, 0xD0u, 0xA7u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8F35u;
                if (tp_scpu_expect_next(cpu, 0x006479A8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8F8Eu, 0x00647C70u, 2u);
        }

        case 0x00647C70u: {
            TP_STATIC_GUARD(0x0C8F8Eu, 0x8Au);
            cpu->a = cpu->x;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F8Fu, 0x00647C78u, 2u);
        }

        case 0x00647C78u: {
            TP_STATIC_GUARD(0x0C8F8Fu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x8F90u, 0x00647C80u, 2u);
        }

        case 0x00647C80u: {
            TP_STATIC_GUARD(0x0C8F90u, 0x69u, 0x18u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0018u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8F93u, 0x00647C98u, 3u);
        }

        case 0x00647C98u: {
            TP_STATIC_GUARD(0x0C8F93u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F94u, 0x00647CA0u, 2u);
        }

        case 0x00647CA0u: {
            TP_STATIC_GUARD(0x0C8F94u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F95u, 0x00647CA8u, 2u);
        }

        case 0x00647CA8u: {
            TP_STATIC_GUARD(0x0C8F95u, 0xD0u, 0x9Bu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8F32u;
                if (tp_scpu_expect_next(cpu, 0x00647990u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8F97u, 0x00647CB8u, 2u);
        }

        case 0x00647CB8u: {
            TP_STATIC_GUARD(0x0C8F97u, 0xADu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F9Au, 0x00647CD0u, 5u);
        }

        case 0x00647CD0u: {
            TP_STATIC_GUARD(0x0C8F9Au, 0x29u, 0x07u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0007u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F9Du, 0x00647CE8u, 3u);
        }

        case 0x00647CE8u: {
            TP_STATIC_GUARD(0x0C8F9Du, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F9Eu, 0x00647CF0u, 3u);
        }

        case 0x00647CF0u: {
            TP_STATIC_GUARD(0x0C8F9Eu, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8F9Fu, 0x00647CF8u, 2u);
        }

        case 0x00647CF8u: {
            TP_STATIC_GUARD(0x0C8F9Fu, 0xBFu, 0x2Cu, 0x92u, 0x05u);
            const uint32_t address = (0x05922Cu + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FA3u, 0x00647D18u, 6u);
        }

        case 0x00647D18u: {
            TP_STATIC_GUARD(0x0C8FA3u, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8FA6u, 0x00647D30u, 5u);
        }

        case 0x00647D30u: {
            TP_STATIC_GUARD(0x0C8FA6u, 0xADu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FA9u, 0x00647D48u, 5u);
        }

        case 0x00647D48u: {
            TP_STATIC_GUARD(0x0C8FA9u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FAAu, 0x00647D50u, 3u);
        }

        case 0x00647D50u: {
            TP_STATIC_GUARD(0x0C8FAAu, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FABu, 0x00647D58u, 3u);
        }

        case 0x00647D58u: {
            TP_STATIC_GUARD(0x0C8FABu, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FACu, 0x00647D60u, 3u);
        }

        case 0x00647D60u: {
            TP_STATIC_GUARD(0x0C8FACu, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FADu, 0x00647D68u, 3u);
        }

        case 0x00647D68u: {
            TP_STATIC_GUARD(0x0C8FADu, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FAEu, 0x00647D70u, 3u);
        }

        case 0x00647D70u: {
            TP_STATIC_GUARD(0x0C8FAEu, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FAFu, 0x00647D78u, 2u);
        }

        case 0x00647D78u: {
            TP_STATIC_GUARD(0x0C8FAFu, 0x9Cu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0415u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8FB2u, 0x00647D90u, 5u);
        }

        case 0x00647D90u: {
            TP_STATIC_GUARD(0x0C8FB2u, 0xADu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FB5u, 0x00647DA8u, 5u);
        }

        case 0x00647DA8u: {
            TP_STATIC_GUARD(0x0C8FB5u, 0xE0u, 0x08u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FB8u, 0x00647DC0u, 3u);
        }

        case 0x00647DC0u: {
            TP_STATIC_GUARD(0x0C8FB8u, 0xB0u, 0x12u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8FCCu;
                if (tp_scpu_expect_next(cpu, 0x00647E60u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8FBAu, 0x00647DD0u, 2u);
        }

        case 0x00647DD0u: {
            TP_STATIC_GUARD(0x0C8FBAu, 0x29u, 0x3Fu, 0x3Fu);
            cpu->a = (uint16_t)(cpu->a & 0x3F3Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FBDu, 0x00647DE8u, 3u);
        }

        case 0x00647DE8u: {
            TP_STATIC_GUARD(0x0C8FBDu, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8FC0u, 0x00647E00u, 5u);
        }

        case 0x00647E00u: {
            TP_STATIC_GUARD(0x0C8FC0u, 0xBFu, 0x21u, 0xBFu, 0x7Eu);
            const uint32_t address = (0x7EBF21u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FC4u, 0x00647E20u, 6u);
        }

        case 0x00647E20u: {
            TP_STATIC_GUARD(0x0C8FC4u, 0x29u, 0xC0u, 0xC0u);
            cpu->a = (uint16_t)(cpu->a & 0xC0C0u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FC7u, 0x00647E38u, 3u);
        }

        case 0x00647E38u: {
            TP_STATIC_GUARD(0x0C8FC7u, 0x0Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0064u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FCAu, 0x00647E50u, 5u);
        }

        case 0x00647E50u: {
            TP_STATIC_GUARD(0x0C8FCAu, 0x80u, 0x17u);
            TP_STATIC_EXIT(0x0Cu, 0x8FE3u, 0x00647F18u, 3u);
        }

        case 0x00647E60u: {
            TP_STATIC_GUARD(0x0C8FCCu, 0xE0u, 0x40u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0040u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FCFu, 0x00647E78u, 3u);
        }

        case 0x00647E78u: {
            TP_STATIC_GUARD(0x0C8FCFu, 0x90u, 0x12u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8FE3u;
                if (tp_scpu_expect_next(cpu, 0x00647F18u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8FD1u, 0x00647E88u, 2u);
        }

        case 0x00647E88u: {
            TP_STATIC_GUARD(0x0C8FD1u, 0x29u, 0xF0u, 0xF0u);
            cpu->a = (uint16_t)(cpu->a & 0xF0F0u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FD4u, 0x00647EA0u, 3u);
        }

        case 0x00647EA0u: {
            TP_STATIC_GUARD(0x0C8FD4u, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8FD7u, 0x00647EB8u, 5u);
        }

        case 0x00647EB8u: {
            TP_STATIC_GUARD(0x0C8FD7u, 0xBFu, 0x21u, 0xBFu, 0x7Eu);
            const uint32_t address = (0x7EBF21u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FDBu, 0x00647ED8u, 6u);
        }

        case 0x00647ED8u: {
            TP_STATIC_GUARD(0x0C8FDBu, 0x29u, 0x0Fu, 0x0Fu);
            cpu->a = (uint16_t)(cpu->a & 0x0F0Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FDEu, 0x00647EF0u, 3u);
        }

        case 0x00647EF0u: {
            TP_STATIC_GUARD(0x0C8FDEu, 0x0Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0064u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FE1u, 0x00647F08u, 5u);
        }

        case 0x00647F08u: {
            TP_STATIC_GUARD(0x0C8FE1u, 0x80u, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x8FE3u, 0x00647F18u, 3u);
        }

        case 0x00647F18u: {
            TP_STATIC_GUARD(0x0C8FE3u, 0x9Fu, 0x21u, 0xBFu, 0x7Eu);
            const uint32_t address = (0x7EBF21u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8FE7u, 0x00647F38u, 6u);
        }

        case 0x00647F38u: {
            TP_STATIC_GUARD(0x0C8FE7u, 0x9Fu, 0x79u, 0xBFu, 0x7Eu);
            const uint32_t address = (0x7EBF79u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8FEBu, 0x00647F58u, 6u);
        }

        case 0x00647F58u: {
            TP_STATIC_GUARD(0x0C8FEBu, 0xBFu, 0x11u, 0xBFu, 0x7Eu);
            const uint32_t address = (0x7EBF11u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FEFu, 0x00647F78u, 6u);
        }

        case 0x00647F78u: {
            TP_STATIC_GUARD(0x0C8FEFu, 0xE0u, 0x08u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FF2u, 0x00647F90u, 3u);
        }

        case 0x00647F90u: {
            TP_STATIC_GUARD(0x0C8FF2u, 0xB0u, 0x05u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8FF9u;
                if (tp_scpu_expect_next(cpu, 0x00647FC8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8FF4u, 0x00647FA0u, 2u);
        }

        case 0x00647FA0u: {
            TP_STATIC_GUARD(0x0C8FF4u, 0x29u, 0xC0u, 0xC0u);
            cpu->a = (uint16_t)(cpu->a & 0xC0C0u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FF7u, 0x00647FB8u, 3u);
        }

        case 0x00647FB8u: {
            TP_STATIC_GUARD(0x0C8FF7u, 0x80u, 0x0Au);
            TP_STATIC_EXIT(0x0Cu, 0x9003u, 0x00648018u, 3u);
        }

        case 0x00647FC8u: {
            TP_STATIC_GUARD(0x0C8FF9u, 0xE0u, 0x40u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0040u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8FFCu, 0x00647FE0u, 3u);
        }

        case 0x00647FE0u: {
            TP_STATIC_GUARD(0x0C8FFCu, 0x90u, 0x05u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x9003u;
                if (tp_scpu_expect_next(cpu, 0x00648018u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8FFEu, 0x00647FF0u, 2u);
        }

        case 0x00647FF0u: {
            TP_STATIC_GUARD(0x0C8FFEu, 0x29u, 0x0Fu, 0x0Fu);
            cpu->a = (uint16_t)(cpu->a & 0x0F0Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x9001u, 0x00648008u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
