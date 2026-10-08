/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_00078C(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x003C6010u: {
            TP_STATIC_GUARD(0x078C02u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C05u, 0x003C6028u, 3u);
        }

        case 0x003C6028u: {
            TP_STATIC_GUARD(0x078C05u, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8C08u, 0x003C6040u, 5u);
        }

        case 0x003C6040u: {
            TP_STATIC_GUARD(0x078C08u, 0x22u, 0x51u, 0xF3u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Cu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xF351u, 0x00079A88u, 8u);
        }

        case 0x003C6060u: {
            TP_STATIC_GUARD(0x078C0Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x8C0Eu, 0x003C6070u, 3u);
        }

        case 0x003C6070u: {
            TP_STATIC_GUARD(0x078C0Eu, 0xADu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C11u, 0x003C6088u, 5u);
        }

        case 0x003C6088u: {
            TP_STATIC_GUARD(0x078C11u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8C17u;
                if (tp_scpu_expect_next(cpu, 0x003C60B8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8C13u, 0x003C6098u, 2u);
        }

        case 0x003C6098u: {
            TP_STATIC_GUARD(0x078C13u, 0x22u, 0x36u, 0xCDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Cu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xCD36u, 0x002669B0u, 8u);
        }

        case 0x003C60B8u: {
            TP_STATIC_GUARD(0x078C17u, 0x82u, 0xA5u, 0x03u);
            TP_STATIC_EXIT(0x07u, 0x8FBFu, 0x003C7DF8u, 4u);
        }

        case 0x003C60B9u: {
            TP_STATIC_GUARD(0x078C17u, 0x82u, 0xA5u, 0x03u);
            TP_STATIC_EXIT(0x07u, 0x8FBFu, 0x003C7DF9u, 4u);
        }

        case 0x003C60D0u: {
            TP_STATIC_GUARD(0x078C1Au, 0xC9u, 0x05u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0005u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C1Du, 0x003C60E8u, 3u);
        }

        case 0x003C60E8u: {
            TP_STATIC_GUARD(0x078C1Du, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8C22u;
                if (tp_scpu_expect_next(cpu, 0x003C6110u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8C1Fu, 0x003C60F8u, 2u);
        }

        case 0x003C60F8u: {
            TP_STATIC_GUARD(0x078C1Fu, 0x82u, 0xF7u, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x8D19u, 0x003C68C8u, 4u);
        }

        case 0x003C6110u: {
            TP_STATIC_GUARD(0x078C22u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x8C24u, 0x003C6121u, 3u);
        }

        case 0x003C6121u: {
            TP_STATIC_GUARD(0x078C24u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x07u, 0x8C26u, 0x003C6131u, 3u);
        }

        case 0x003C6131u: {
            TP_STATIC_GUARD(0x078C26u, 0x9Cu, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8C29u, 0x003C6149u, 5u);
        }

        case 0x003C6149u: {
            TP_STATIC_GUARD(0x078C29u, 0xA2u, 0x14u);
            const uint8_t value = 0x14u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C2Bu, 0x003C6159u, 2u);
        }

        case 0x003C6159u: {
            TP_STATIC_GUARD(0x078C2Bu, 0xA0u, 0x0Au);
            const uint8_t value = 0x0Au;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C2Du, 0x003C6169u, 2u);
        }

        case 0x003C6169u: {
            TP_STATIC_GUARD(0x078C2Du, 0xBDu, 0x4Du, 0x17u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x174Du + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x07u;
            cpu->pc = 0x8C30u;
            if (tp_scpu_expect_next(cpu, 0x003C6181u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 5u + (((0x4Du + (cpu->x & 0x00FFu)) > 0x00FFu) ? 1u : 0u));
        }

        case 0x003C6181u: {
            TP_STATIC_GUARD(0x078C30u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8C35u;
                if (tp_scpu_expect_next(cpu, 0x003C61A9u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8C32u, 0x003C6191u, 2u);
        }

        case 0x003C6191u: {
            TP_STATIC_GUARD(0x078C32u, 0xEEu, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0064u;
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
            TP_STATIC_EXIT(0x07u, 0x8C35u, 0x003C61A9u, 8u);
        }

        case 0x003C61A9u: {
            TP_STATIC_GUARD(0x078C35u, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C36u, 0x003C61B1u, 2u);
        }

        case 0x003C61B1u: {
            TP_STATIC_GUARD(0x078C36u, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C37u, 0x003C61B9u, 2u);
        }

        case 0x003C61B9u: {
            TP_STATIC_GUARD(0x078C37u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C38u, 0x003C61C1u, 2u);
        }

        case 0x003C61C1u: {
            TP_STATIC_GUARD(0x078C38u, 0x10u, 0xF3u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8C2Du;
                if (tp_scpu_expect_next(cpu, 0x003C6169u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8C3Au, 0x003C61D1u, 2u);
        }

        case 0x003C61D1u: {
            TP_STATIC_GUARD(0x078C3Au, 0xADu, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0064u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C3Du, 0x003C61E9u, 5u);
        }

        case 0x003C61E9u: {
            TP_STATIC_GUARD(0x078C3Du, 0xC9u, 0x04u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0004u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C40u, 0x003C6201u, 3u);
        }

        case 0x003C6201u: {
            TP_STATIC_GUARD(0x078C40u, 0xB0u, 0x03u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8C45u;
                if (tp_scpu_expect_next(cpu, 0x003C6229u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8C42u, 0x003C6211u, 2u);
        }

        case 0x003C6211u: {
            TP_STATIC_GUARD(0x078C42u, 0x4Cu, 0xBFu, 0x8Fu);
            TP_STATIC_EXIT(0x07u, 0x8FBFu, 0x003C7DF9u, 3u);
        }

        case 0x003C6229u: {
            TP_STATIC_GUARD(0x078C45u, 0xA2u, 0x14u);
            const uint8_t value = 0x14u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C47u, 0x003C6239u, 2u);
        }

        case 0x003C6239u: {
            TP_STATIC_GUARD(0x078C47u, 0xA0u, 0x0Au);
            const uint8_t value = 0x0Au;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C49u, 0x003C6249u, 2u);
        }

        case 0x003C6249u: {
            TP_STATIC_GUARD(0x078C49u, 0xBDu, 0x4Du, 0x17u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x174Du + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x07u;
            cpu->pc = 0x8C4Cu;
            if (tp_scpu_expect_next(cpu, 0x003C6261u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 5u + (((0x4Du + (cpu->x & 0x00FFu)) > 0x00FFu) ? 1u : 0u));
        }

        case 0x003C6261u: {
            TP_STATIC_GUARD(0x078C4Cu, 0xF0u, 0x08u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8C56u;
                if (tp_scpu_expect_next(cpu, 0x003C62B1u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8C4Eu, 0x003C6271u, 2u);
        }

        case 0x003C6271u: {
            TP_STATIC_GUARD(0x078C4Eu, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C4Fu, 0x003C6279u, 2u);
        }

        case 0x003C6279u: {
            TP_STATIC_GUARD(0x078C4Fu, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C50u, 0x003C6281u, 2u);
        }

        case 0x003C6281u: {
            TP_STATIC_GUARD(0x078C50u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C51u, 0x003C6289u, 2u);
        }

        case 0x003C6289u: {
            TP_STATIC_GUARD(0x078C51u, 0x10u, 0xF6u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8C49u;
                if (tp_scpu_expect_next(cpu, 0x003C6249u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8C53u, 0x003C6299u, 2u);
        }

        case 0x003C6299u: {
            TP_STATIC_GUARD(0x078C53u, 0x82u, 0x69u, 0x03u);
            TP_STATIC_EXIT(0x07u, 0x8FBFu, 0x003C7DF9u, 4u);
        }

        case 0x003C62B1u: {
            TP_STATIC_GUARD(0x078C56u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x8C58u, 0x003C62C3u, 3u);
        }

        case 0x003C62C3u: {
            TP_STATIC_GUARD(0x078C58u, 0xAEu, 0x14u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0814u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C5Bu, 0x003C62DBu, 4u);
        }

        case 0x003C62DBu: {
            TP_STATIC_GUARD(0x078C5Bu, 0xBFu, 0x3Du, 0xCCu, 0x01u);
            const uint32_t address = (0x01CC3Du + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C5Fu, 0x003C62FBu, 5u);
        }

        case 0x003C62FBu: {
            TP_STATIC_GUARD(0x078C5Fu, 0x8Du, 0xF7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18F7u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8C62u, 0x003C6313u, 4u);
        }

        case 0x003C6313u: {
            TP_STATIC_GUARD(0x078C62u, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C64u, 0x003C6323u, 2u);
        }

        case 0x003C6323u: {
            TP_STATIC_GUARD(0x078C64u, 0x8Du, 0xF8u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18F8u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8C67u, 0x003C633Bu, 4u);
        }

        case 0x003C633Bu: {
            TP_STATIC_GUARD(0x078C67u, 0x98u);
            const uint8_t value = (uint8_t)(cpu->y & 0x00FFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C68u, 0x003C6343u, 2u);
        }

        case 0x003C6343u: {
            TP_STATIC_GUARD(0x078C68u, 0x0Au);
            const uint8_t old_value = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t value = (uint8_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C69u, 0x003C634Bu, 2u);
        }

        case 0x003C634Bu: {
            TP_STATIC_GUARD(0x078C69u, 0xAAu);
            cpu->x = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C6Au, 0x003C6353u, 2u);
        }

        case 0x003C6353u: {
            TP_STATIC_GUARD(0x078C6Au, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x8C6Cu, 0x003C6360u, 3u);
        }

        case 0x003C6360u: {
            TP_STATIC_GUARD(0x078C6Cu, 0xBFu, 0xF6u, 0x86u, 0x00u);
            const uint32_t address = (0x0086F6u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C70u, 0x003C6380u, 6u);
        }

        case 0x003C6380u: {
            TP_STATIC_GUARD(0x078C70u, 0x8Du, 0x6Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x076Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8C73u, 0x003C6398u, 5u);
        }

        case 0x003C6398u: {
            TP_STATIC_GUARD(0x078C73u, 0xBFu, 0x14u, 0x87u, 0x00u);
            const uint32_t address = (0x008714u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C77u, 0x003C63B8u, 6u);
        }

        case 0x003C63B8u: {
            TP_STATIC_GUARD(0x078C77u, 0x8Du, 0xF9u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18F9u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8C7Au, 0x003C63D0u, 5u);
        }

        case 0x003C63D0u: {
            TP_STATIC_GUARD(0x078C7Au, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x8C7Cu, 0x003C63E3u, 3u);
        }

        case 0x003C63E3u: {
            TP_STATIC_GUARD(0x078C7Cu, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C7Eu, 0x003C63F3u, 2u);
        }

        case 0x003C63F3u: {
            TP_STATIC_GUARD(0x078C7Eu, 0x8Du, 0xFBu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18FBu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8C81u, 0x003C640Bu, 4u);
        }

        case 0x003C640Bu: {
            TP_STATIC_GUARD(0x078C81u, 0xADu, 0x54u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0754u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C84u, 0x003C6423u, 4u);
        }

        case 0x003C6423u: {
            TP_STATIC_GUARD(0x078C84u, 0x8Du, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0400u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8C87u, 0x003C643Bu, 4u);
        }

        case 0x003C643Bu: {
            TP_STATIC_GUARD(0x078C87u, 0xADu, 0x55u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0755u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C8Au, 0x003C6453u, 4u);
        }

        case 0x003C6453u: {
            TP_STATIC_GUARD(0x078C8Au, 0x8Du, 0x01u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0401u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8C8Du, 0x003C646Bu, 4u);
        }

        case 0x003C646Bu: {
            TP_STATIC_GUARD(0x078C8Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x8C8Fu, 0x003C6478u, 3u);
        }

        case 0x003C6478u: {
            TP_STATIC_GUARD(0x078C8Fu, 0xAEu, 0x14u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0814u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C92u, 0x003C6490u, 5u);
        }

        case 0x003C6490u: {
            TP_STATIC_GUARD(0x078C92u, 0xBFu, 0x3Du, 0xCCu, 0x01u);
            const uint32_t address = (0x01CC3Du + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C96u, 0x003C64B0u, 6u);
        }

        case 0x003C64B0u: {
            TP_STATIC_GUARD(0x078C96u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C99u, 0x003C64C8u, 3u);
        }

        case 0x003C64C8u: {
            TP_STATIC_GUARD(0x078C99u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8C9Cu, 0x003C64E0u, 5u);
        }

        case 0x003C64E0u: {
            TP_STATIC_GUARD(0x078C9Cu, 0xACu, 0x14u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0814u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8C9Fu, 0x003C64F8u, 5u);
        }

        case 0x003C64F8u: {
            TP_STATIC_GUARD(0x078C9Fu, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CA0u, 0x003C6500u, 2u);
        }

        case 0x003C6500u: {
            TP_STATIC_GUARD(0x078CA0u, 0xA9u, 0x30u, 0x00u);
            const uint16_t value = 0x0030u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CA3u, 0x003C6518u, 3u);
        }

        case 0x003C6518u: {
            TP_STATIC_GUARD(0x078CA3u, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Cu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA6u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x003C6538u: {
            TP_STATIC_GUARD(0x078CA7u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CA8u, 0x003C6540u, 2u);
        }

        case 0x003C6540u: {
            TP_STATIC_GUARD(0x078CA8u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x07u, 0x8CA9u, 0x003C6548u, 2u);
        }

        case 0x003C6548u: {
            TP_STATIC_GUARD(0x078CA9u, 0x69u, 0x14u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0014u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8CACu, 0x003C6560u, 3u);
        }

        case 0x003C6560u: {
            TP_STATIC_GUARD(0x078CACu, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CADu, 0x003C6568u, 2u);
        }

        case 0x003C6568u: {
            TP_STATIC_GUARD(0x078CADu, 0xB9u, 0x4Du, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x084Du + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CB0u, 0x003C6580u, 6u);
        }

        case 0x003C6580u: {
            TP_STATIC_GUARD(0x078CB0u, 0xC9u, 0x20u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0020u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CB3u, 0x003C6598u, 3u);
        }

        case 0x003C6598u: {
            TP_STATIC_GUARD(0x078CB3u, 0xD0u, 0x1Bu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8CD0u;
                if (tp_scpu_expect_next(cpu, 0x003C6680u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8CB5u, 0x003C65A8u, 2u);
        }

        case 0x003C65A8u: {
            TP_STATIC_GUARD(0x078CB5u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x8CB7u, 0x003C65BBu, 3u);
        }

        case 0x003C65BBu: {
            TP_STATIC_GUARD(0x078CB7u, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CBAu, 0x003C65D3u, 4u);
        }

        case 0x003C65D3u: {
            TP_STATIC_GUARD(0x078CBAu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0x8CBBu, 0x003C65DBu, 2u);
        }

        case 0x003C65DBu: {
            TP_STATIC_GUARD(0x078CBBu, 0xE9u, 0x02u);
            if (tp_scpu_sbc(cpu, 0x02u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8CBDu, 0x003C65EBu, 2u);
        }

        case 0x003C65EBu: {
            TP_STATIC_GUARD(0x078CBDu, 0x8Du, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0400u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8CC0u, 0x003C6603u, 4u);
        }

        case 0x003C6603u: {
            TP_STATIC_GUARD(0x078CC0u, 0xADu, 0x01u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0401u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CC3u, 0x003C661Bu, 4u);
        }

        case 0x003C661Bu: {
            TP_STATIC_GUARD(0x078CC3u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0x8CC4u, 0x003C6623u, 2u);
        }

        case 0x003C6623u: {
            TP_STATIC_GUARD(0x078CC4u, 0xE9u, 0x01u);
            if (tp_scpu_sbc(cpu, 0x01u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8CC6u, 0x003C6633u, 2u);
        }

        case 0x003C6633u: {
            TP_STATIC_GUARD(0x078CC6u, 0x8Du, 0x01u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0401u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8CC9u, 0x003C664Bu, 4u);
        }

        case 0x003C664Bu: {
            TP_STATIC_GUARD(0x078CC9u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x8CCBu, 0x003C6658u, 3u);
        }

        case 0x003C6658u: {
            TP_STATIC_GUARD(0x078CCBu, 0xA2u, 0x02u, 0x00u);
            const uint16_t value = 0x0002u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CCEu, 0x003C6670u, 3u);
        }

        case 0x003C6670u: {
            TP_STATIC_GUARD(0x078CCEu, 0x80u, 0x30u);
            TP_STATIC_EXIT(0x07u, 0x8D00u, 0x003C6800u, 3u);
        }

        case 0x003C6680u: {
            TP_STATIC_GUARD(0x078CD0u, 0xC9u, 0x04u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0004u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CD3u, 0x003C6698u, 3u);
        }

        case 0x003C6698u: {
            TP_STATIC_GUARD(0x078CD3u, 0xF0u, 0x0Au);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8CDFu;
                if (tp_scpu_expect_next(cpu, 0x003C66F8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8CD5u, 0x003C66A8u, 2u);
        }

        case 0x003C66A8u: {
            TP_STATIC_GUARD(0x078CD5u, 0xC9u, 0x06u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0006u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CD8u, 0x003C66C0u, 3u);
        }

        case 0x003C66C0u: {
            TP_STATIC_GUARD(0x078CD8u, 0xF0u, 0x05u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8CDFu;
                if (tp_scpu_expect_next(cpu, 0x003C66F8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8CDAu, 0x003C66D0u, 2u);
        }

        case 0x003C66D0u: {
            TP_STATIC_GUARD(0x078CDAu, 0xC9u, 0x1Eu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x001Eu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CDDu, 0x003C66E8u, 3u);
        }

        case 0x003C66E8u: {
            TP_STATIC_GUARD(0x078CDDu, 0xD0u, 0x08u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x8CE7u;
                if (tp_scpu_expect_next(cpu, 0x003C6738u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x8CDFu, 0x003C66F8u, 2u);
        }

        case 0x003C66F8u: {
            TP_STATIC_GUARD(0x078CDFu, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CE2u, 0x003C6710u, 3u);
        }

        case 0x003C6710u: {
            TP_STATIC_GUARD(0x078CE2u, 0xA9u, 0xFDu, 0xFFu);
            const uint16_t value = 0xFFFDu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CE5u, 0x003C6728u, 3u);
        }

        case 0x003C6728u: {
            TP_STATIC_GUARD(0x078CE5u, 0x80u, 0x1Cu);
            TP_STATIC_EXIT(0x07u, 0x8D03u, 0x003C6818u, 3u);
        }

        case 0x003C6738u: {
            TP_STATIC_GUARD(0x078CE7u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x8CE9u, 0x003C674Bu, 3u);
        }

        case 0x003C674Bu: {
            TP_STATIC_GUARD(0x078CE9u, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CECu, 0x003C6763u, 4u);
        }

        case 0x003C6763u: {
            TP_STATIC_GUARD(0x078CECu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0x8CEDu, 0x003C676Bu, 2u);
        }

        case 0x003C676Bu: {
            TP_STATIC_GUARD(0x078CEDu, 0xE9u, 0x01u);
            if (tp_scpu_sbc(cpu, 0x01u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8CEFu, 0x003C677Bu, 2u);
        }

        case 0x003C677Bu: {
            TP_STATIC_GUARD(0x078CEFu, 0x8Du, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0400u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8CF2u, 0x003C6793u, 4u);
        }

        case 0x003C6793u: {
            TP_STATIC_GUARD(0x078CF2u, 0xADu, 0x01u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0401u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8CF5u, 0x003C67ABu, 4u);
        }

        case 0x003C67ABu: {
            TP_STATIC_GUARD(0x078CF5u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0x8CF6u, 0x003C67B3u, 2u);
        }

        case 0x003C67B3u: {
            TP_STATIC_GUARD(0x078CF6u, 0xE9u, 0x01u);
            if (tp_scpu_sbc(cpu, 0x01u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8CF8u, 0x003C67C3u, 2u);
        }

        case 0x003C67C3u: {
            TP_STATIC_GUARD(0x078CF8u, 0x8Du, 0x01u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0401u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8CFBu, 0x003C67DBu, 4u);
        }

        case 0x003C67DBu: {
            TP_STATIC_GUARD(0x078CFBu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x8CFDu, 0x003C67E8u, 3u);
        }

        case 0x003C67E8u: {
            TP_STATIC_GUARD(0x078CFDu, 0xA2u, 0xFFu, 0xFFu);
            const uint16_t value = 0xFFFFu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x8D00u, 0x003C6800u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
