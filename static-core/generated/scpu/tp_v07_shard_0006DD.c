/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0006DD(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x0036E800u: {
            TP_STATIC_GUARD(0x06DD00u, 0x82u, 0xDFu, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xDFE2u, 0x0036FF10u, 4u);
        }

        case 0x0036E818u: {
            TP_STATIC_GUARD(0x06DD03u, 0xC9u, 0x10u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0010u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD06u, 0x0036E830u, 3u);
        }

        case 0x0036E830u: {
            TP_STATIC_GUARD(0x06DD06u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDD0Bu;
                if (tp_scpu_expect_next(cpu, 0x0036E858u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDD08u, 0x0036E840u, 2u);
        }

        case 0x0036E840u: {
            TP_STATIC_GUARD(0x06DD08u, 0x82u, 0x9Fu, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xDDAAu, 0x0036ED50u, 4u);
        }

        case 0x0036E858u: {
            TP_STATIC_GUARD(0x06DD0Bu, 0xA0u, 0x0Cu, 0x00u);
            const uint16_t value = 0x000Cu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD0Eu, 0x0036E870u, 3u);
        }

        case 0x0036E870u: {
            TP_STATIC_GUARD(0x06DD0Eu, 0xB7u, 0x58u);
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
            cpu->pbr = 0x06u;
            cpu->pc = 0xDD10u;
            if (tp_scpu_expect_next(cpu, 0x0036E880u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036E880u: {
            TP_STATIC_GUARD(0x06DD10u, 0x30u, 0x12u);
            if ((cpu->p & TP_P_N) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDD24u;
                if (tp_scpu_expect_next(cpu, 0x0036E920u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDD12u, 0x0036E890u, 2u);
        }

        case 0x0036E890u: {
            TP_STATIC_GUARD(0x06DD12u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDD17u;
                if (tp_scpu_expect_next(cpu, 0x0036E8B8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDD14u, 0x0036E8A0u, 2u);
        }

        case 0x0036E8A0u: {
            TP_STATIC_GUARD(0x06DD14u, 0x82u, 0x90u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xDDA7u, 0x0036ED38u, 4u);
        }

        case 0x0036E8B8u: {
            TP_STATIC_GUARD(0x06DD17u, 0xA0u, 0x0Au, 0x00u);
            const uint16_t value = 0x000Au;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD1Au, 0x0036E8D0u, 3u);
        }

        case 0x0036E8D0u: {
            TP_STATIC_GUARD(0x06DD1Au, 0xB7u, 0x58u);
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
            cpu->pbr = 0x06u;
            cpu->pc = 0xDD1Cu;
            if (tp_scpu_expect_next(cpu, 0x0036E8E0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036E8E0u: {
            TP_STATIC_GUARD(0x06DD1Cu, 0xC9u, 0x88u, 0x13u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x1388u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD1Fu, 0x0036E8F8u, 3u);
        }

        case 0x0036E8F8u: {
            TP_STATIC_GUARD(0x06DD1Fu, 0x90u, 0x03u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDD24u;
                if (tp_scpu_expect_next(cpu, 0x0036E920u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDD21u, 0x0036E908u, 2u);
        }

        case 0x0036E908u: {
            TP_STATIC_GUARD(0x06DD21u, 0x4Cu, 0xA7u, 0xDDu);
            TP_STATIC_EXIT(0x06u, 0xDDA7u, 0x0036ED38u, 3u);
        }

        case 0x0036E920u: {
            TP_STATIC_GUARD(0x06DD24u, 0xA9u, 0xB8u, 0x0Bu);
            const uint16_t value = 0x0BB8u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD27u, 0x0036E938u, 3u);
        }

        case 0x0036E938u: {
            TP_STATIC_GUARD(0x06DD27u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDD2Au, 0x0036E950u, 5u);
        }

        case 0x0036E950u: {
            TP_STATIC_GUARD(0x06DD2Au, 0x9Cu, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0790u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDD2Du, 0x0036E968u, 5u);
        }

        case 0x0036E968u: {
            TP_STATIC_GUARD(0x06DD2Du, 0xADu, 0x30u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F30u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD30u, 0x0036E980u, 5u);
        }

        case 0x0036E980u: {
            TP_STATIC_GUARD(0x06DD30u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDD33u, 0x0036E998u, 5u);
        }

        case 0x0036E998u: {
            TP_STATIC_GUARD(0x06DD33u, 0xADu, 0x32u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F32u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD36u, 0x0036E9B0u, 5u);
        }

        case 0x0036E9B0u: {
            TP_STATIC_GUARD(0x06DD36u, 0x8Du, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Cu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDD39u, 0x0036E9C8u, 5u);
        }

        case 0x0036E9C8u: {
            TP_STATIC_GUARD(0x06DD39u, 0x22u, 0x7Eu, 0xF8u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDDu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x3Cu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xF87Eu, 0x003FC3F0u, 8u);
        }

        case 0x0036E9E8u: {
            TP_STATIC_GUARD(0x06DD3Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xDD3Fu, 0x0036E9F8u, 3u);
        }

        case 0x0036E9F8u: {
            TP_STATIC_GUARD(0x06DD3Fu, 0xADu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Eu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD42u, 0x0036EA10u, 5u);
        }

        case 0x0036EA10u: {
            TP_STATIC_GUARD(0x06DD42u, 0xF0u, 0x63u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDDA7u;
                if (tp_scpu_expect_next(cpu, 0x0036ED38u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDD44u, 0x0036EA20u, 2u);
        }

        case 0x0036EA20u: {
            TP_STATIC_GUARD(0x06DD44u, 0xA0u, 0x67u, 0x03u);
            const uint16_t value = 0x0367u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD47u, 0x0036EA38u, 3u);
        }

        case 0x0036EA38u: {
            TP_STATIC_GUARD(0x06DD47u, 0xB7u, 0x5Eu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x5Eu);
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
            cpu->pc = 0xDD49u;
            if (tp_scpu_expect_next(cpu, 0x0036EA48u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036EA48u: {
            TP_STATIC_GUARD(0x06DD49u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDD4Cu, 0x0036EA60u, 5u);
        }

        case 0x0036EA60u: {
            TP_STATIC_GUARD(0x06DD4Cu, 0xA0u, 0x69u, 0x03u);
            const uint16_t value = 0x0369u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD4Fu, 0x0036EA78u, 3u);
        }

        case 0x0036EA78u: {
            TP_STATIC_GUARD(0x06DD4Fu, 0xB7u, 0x5Eu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x5Eu);
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
            cpu->pc = 0xDD51u;
            if (tp_scpu_expect_next(cpu, 0x0036EA88u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036EA88u: {
            TP_STATIC_GUARD(0x06DD51u, 0x8Du, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Cu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDD54u, 0x0036EAA0u, 5u);
        }

        case 0x0036EAA0u: {
            TP_STATIC_GUARD(0x06DD54u, 0xA0u, 0xFBu, 0x03u);
            const uint16_t value = 0x03FBu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD57u, 0x0036EAB8u, 3u);
        }

        case 0x0036EAB8u: {
            TP_STATIC_GUARD(0x06DD57u, 0xB7u, 0x5Eu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x5Eu);
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
            cpu->pc = 0xDD59u;
            if (tp_scpu_expect_next(cpu, 0x0036EAC8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036EAC8u: {
            TP_STATIC_GUARD(0x06DD59u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDD5Cu, 0x0036EAE0u, 5u);
        }

        case 0x0036EAE0u: {
            TP_STATIC_GUARD(0x06DD5Cu, 0xA0u, 0xFDu, 0x03u);
            const uint16_t value = 0x03FDu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD5Fu, 0x0036EAF8u, 3u);
        }

        case 0x0036EAF8u: {
            TP_STATIC_GUARD(0x06DD5Fu, 0xB7u, 0x5Eu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x5Eu);
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
            cpu->pc = 0xDD61u;
            if (tp_scpu_expect_next(cpu, 0x0036EB08u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036EB08u: {
            TP_STATIC_GUARD(0x06DD61u, 0x8Du, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0790u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDD64u, 0x0036EB20u, 5u);
        }

        case 0x0036EB20u: {
            TP_STATIC_GUARD(0x06DD64u, 0xADu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD67u, 0x0036EB38u, 5u);
        }

        case 0x0036EB38u: {
            TP_STATIC_GUARD(0x06DD67u, 0xCDu, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0790u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD6Au, 0x0036EB50u, 5u);
        }

        case 0x0036EB50u: {
            TP_STATIC_GUARD(0x06DD6Au, 0x90u, 0x0Cu);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDD78u;
                if (tp_scpu_expect_next(cpu, 0x0036EBC0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDD6Cu, 0x0036EB60u, 2u);
        }

        case 0x0036EB60u: {
            TP_STATIC_GUARD(0x06DD6Cu, 0xF0u, 0x02u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDD70u;
                if (tp_scpu_expect_next(cpu, 0x0036EB80u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDD6Eu, 0x0036EB70u, 2u);
        }

        case 0x0036EB70u: {
            TP_STATIC_GUARD(0x06DD6Eu, 0xB0u, 0x37u);
            if (!((cpu->p & TP_P_C) != 0u))
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "PROVED_BRANCH_STATUS_VIOLATION");
            TP_STATIC_EXIT(0x06u, 0xDDA7u, 0x0036ED38u, 3u);
        }

        case 0x0036EB80u: {
            TP_STATIC_GUARD(0x06DD70u, 0xADu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD73u, 0x0036EB98u, 5u);
        }

        case 0x0036EB98u: {
            TP_STATIC_GUARD(0x06DD73u, 0xCDu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Eu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD76u, 0x0036EBB0u, 5u);
        }

        case 0x0036EBB0u: {
            TP_STATIC_GUARD(0x06DD76u, 0xB0u, 0x2Fu);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDDA7u;
                if (tp_scpu_expect_next(cpu, 0x0036ED38u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDD78u, 0x0036EBC0u, 2u);
        }

        case 0x0036EBC0u: {
            TP_STATIC_GUARD(0x06DD78u, 0xA0u, 0x12u, 0x00u);
            const uint16_t value = 0x0012u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD7Bu, 0x0036EBD8u, 3u);
        }

        case 0x0036EBD8u: {
            TP_STATIC_GUARD(0x06DD7Bu, 0xB7u, 0x58u);
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
            cpu->pbr = 0x06u;
            cpu->pc = 0xDD7Du;
            if (tp_scpu_expect_next(cpu, 0x0036EBE8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036EBE8u: {
            TP_STATIC_GUARD(0x06DD7Du, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x06u, 0xDD7Eu, 0x0036EBF0u, 2u);
        }

        case 0x0036EBF0u: {
            TP_STATIC_GUARD(0x06DD7Eu, 0x69u, 0x88u, 0x13u);
            if (tp_scpu_adc(cpu, 0x1388u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDD81u, 0x0036EC08u, 3u);
        }

        case 0x0036EC08u: {
            TP_STATIC_GUARD(0x06DD81u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDD84u, 0x0036EC20u, 5u);
        }

        case 0x0036EC20u: {
            TP_STATIC_GUARD(0x06DD84u, 0xA0u, 0x14u, 0x00u);
            const uint16_t value = 0x0014u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD87u, 0x0036EC38u, 3u);
        }

        case 0x0036EC38u: {
            TP_STATIC_GUARD(0x06DD87u, 0xB7u, 0x58u);
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
            cpu->pbr = 0x06u;
            cpu->pc = 0xDD89u;
            if (tp_scpu_expect_next(cpu, 0x0036EC48u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036EC48u: {
            TP_STATIC_GUARD(0x06DD89u, 0x69u, 0x00u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0000u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDD8Cu, 0x0036EC60u, 3u);
        }

        case 0x0036EC60u: {
            TP_STATIC_GUARD(0x06DD8Cu, 0x8Du, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Cu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDD8Fu, 0x0036EC78u, 5u);
        }

        case 0x0036EC78u: {
            TP_STATIC_GUARD(0x06DD8Fu, 0xCDu, 0xBAu, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1FBAu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD92u, 0x0036EC90u, 5u);
        }

        case 0x0036EC90u: {
            TP_STATIC_GUARD(0x06DD92u, 0x90u, 0x0Du);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDDA1u;
                if (tp_scpu_expect_next(cpu, 0x0036ED08u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDD94u, 0x0036ECA0u, 2u);
        }

        case 0x0036ECA0u: {
            TP_STATIC_GUARD(0x06DD94u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDD99u;
                if (tp_scpu_expect_next(cpu, 0x0036ECC8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDD96u, 0x0036ECB0u, 2u);
        }

        case 0x0036ECB0u: {
            TP_STATIC_GUARD(0x06DD96u, 0x82u, 0x0Eu, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xDDA7u, 0x0036ED38u, 4u);
        }

        case 0x0036ECC8u: {
            TP_STATIC_GUARD(0x06DD99u, 0xADu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD9Cu, 0x0036ECE0u, 5u);
        }

        case 0x0036ECE0u: {
            TP_STATIC_GUARD(0x06DD9Cu, 0xCDu, 0xB8u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1FB8u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDD9Fu, 0x0036ECF8u, 5u);
        }

        case 0x0036ECF8u: {
            TP_STATIC_GUARD(0x06DD9Fu, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDDA7u;
                if (tp_scpu_expect_next(cpu, 0x0036ED38u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDDA1u, 0x0036ED08u, 2u);
        }

        case 0x0036ED08u: {
            TP_STATIC_GUARD(0x06DDA1u, 0xA9u, 0x10u, 0x00u);
            const uint16_t value = 0x0010u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDDA4u, 0x0036ED20u, 3u);
        }

        case 0x0036ED20u: {
            TP_STATIC_GUARD(0x06DDA4u, 0x82u, 0x69u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xDE10u, 0x0036F080u, 4u);
        }

        case 0x0036ED38u: {
            TP_STATIC_GUARD(0x06DDA7u, 0x82u, 0x38u, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xDFE2u, 0x0036FF10u, 4u);
        }

        case 0x0036ED50u: {
            TP_STATIC_GUARD(0x06DDAAu, 0xC9u, 0x11u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0011u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDDADu, 0x0036ED68u, 3u);
        }

        case 0x0036ED68u: {
            TP_STATIC_GUARD(0x06DDADu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDDB2u;
                if (tp_scpu_expect_next(cpu, 0x0036ED90u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDDAFu, 0x0036ED78u, 2u);
        }

        case 0x0036ED78u: {
            TP_STATIC_GUARD(0x06DDAFu, 0x82u, 0x78u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xDE2Au, 0x0036F150u, 4u);
        }

        case 0x0036ED90u: {
            TP_STATIC_GUARD(0x06DDB2u, 0xA0u, 0x0Cu, 0x00u);
            const uint16_t value = 0x000Cu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDDB5u, 0x0036EDA8u, 3u);
        }

        case 0x0036EDA8u: {
            TP_STATIC_GUARD(0x06DDB5u, 0xB7u, 0x58u);
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
            cpu->pbr = 0x06u;
            cpu->pc = 0xDDB7u;
            if (tp_scpu_expect_next(cpu, 0x0036EDB8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036EDB8u: {
            TP_STATIC_GUARD(0x06DDB7u, 0x10u, 0x6Eu);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDE27u;
                if (tp_scpu_expect_next(cpu, 0x0036F138u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDDB9u, 0x0036EDC8u, 2u);
        }

        case 0x0036EDC8u: {
            TP_STATIC_GUARD(0x06DDB9u, 0xA0u, 0x14u, 0x00u);
            const uint16_t value = 0x0014u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDDBCu, 0x0036EDE0u, 3u);
        }

        case 0x0036EDE0u: {
            TP_STATIC_GUARD(0x06DDBCu, 0xB7u, 0x58u);
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
            cpu->pbr = 0x06u;
            cpu->pc = 0xDDBEu;
            if (tp_scpu_expect_next(cpu, 0x0036EDF0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036EDF0u: {
            TP_STATIC_GUARD(0x06DDBEu, 0xC9u, 0x01u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0001u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDDC1u, 0x0036EE08u, 3u);
        }

        case 0x0036EE08u: {
            TP_STATIC_GUARD(0x06DDC1u, 0xB0u, 0x64u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDE27u;
                if (tp_scpu_expect_next(cpu, 0x0036F138u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDDC3u, 0x0036EE18u, 2u);
        }

        case 0x0036EE18u: {
            TP_STATIC_GUARD(0x06DDC3u, 0x90u, 0x62u);
            if (!((cpu->p & TP_P_C) == 0u))
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "PROVED_BRANCH_STATUS_VIOLATION");
            TP_STATIC_EXIT(0x06u, 0xDE27u, 0x0036F138u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
