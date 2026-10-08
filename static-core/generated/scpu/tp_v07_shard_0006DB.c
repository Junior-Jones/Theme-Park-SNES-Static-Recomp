/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0006DB(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x0036D800u: {
            TP_STATIC_GUARD(0x06DB00u, 0x8Du, 0xBAu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07BAu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDB03u, 0x0036D818u, 5u);
        }

        case 0x0036D818u: {
            TP_STATIC_GUARD(0x06DB03u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB04u, 0x0036D820u, 3u);
        }

        case 0x0036D820u: {
            TP_STATIC_GUARD(0x06DB04u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB05u, 0x0036D828u, 2u);
        }

        case 0x0036D828u: {
            TP_STATIC_GUARD(0x06DB05u, 0xB7u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
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
            cpu->pc = 0xDB07u;
            if (tp_scpu_expect_next(cpu, 0x0036D838u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036D838u: {
            TP_STATIC_GUARD(0x06DB07u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDB0Au, 0x0036D850u, 5u);
        }

        case 0x0036D850u: {
            TP_STATIC_GUARD(0x06DB0Au, 0xAEu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB0Du, 0x0036D868u, 5u);
        }

        case 0x0036D868u: {
            TP_STATIC_GUARD(0x06DB0Du, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDB10u, 0x0036D880u, 5u);
        }

        case 0x0036D880u: {
            TP_STATIC_GUARD(0x06DB10u, 0x22u, 0x80u, 0xE1u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDBu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x13u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE180u, 0x00370C00u, 8u);
        }

        case 0x0036D8A1u: {
            TP_STATIC_GUARD(0x06DB14u, 0x82u, 0xA3u, 0x04u);
            TP_STATIC_EXIT(0x06u, 0xDFBAu, 0x0036FDD1u, 4u);
        }

        case 0x0036D8B8u: {
            TP_STATIC_GUARD(0x06DB17u, 0xC9u, 0x0Au, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Au;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB1Au, 0x0036D8D0u, 3u);
        }

        case 0x0036D8D0u: {
            TP_STATIC_GUARD(0x06DB1Au, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDB1Fu;
                if (tp_scpu_expect_next(cpu, 0x0036D8F8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDB1Cu, 0x0036D8E0u, 2u);
        }

        case 0x0036D8E0u: {
            TP_STATIC_GUARD(0x06DB1Cu, 0x82u, 0xC3u, 0x04u);
            TP_STATIC_EXIT(0x06u, 0xDFE2u, 0x0036FF10u, 4u);
        }

        case 0x0036D8F8u: {
            TP_STATIC_GUARD(0x06DB1Fu, 0xA9u, 0x39u, 0x00u);
            const uint16_t value = 0x0039u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB22u, 0x0036D910u, 3u);
        }

        case 0x0036D910u: {
            TP_STATIC_GUARD(0x06DB22u, 0x8Du, 0xBAu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07BAu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDB25u, 0x0036D928u, 5u);
        }

        case 0x0036D928u: {
            TP_STATIC_GUARD(0x06DB25u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB26u, 0x0036D930u, 3u);
        }

        case 0x0036D930u: {
            TP_STATIC_GUARD(0x06DB26u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB27u, 0x0036D938u, 2u);
        }

        case 0x0036D938u: {
            TP_STATIC_GUARD(0x06DB27u, 0xB7u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
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
            cpu->pc = 0xDB29u;
            if (tp_scpu_expect_next(cpu, 0x0036D948u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036D948u: {
            TP_STATIC_GUARD(0x06DB29u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDB2Cu, 0x0036D960u, 5u);
        }

        case 0x0036D960u: {
            TP_STATIC_GUARD(0x06DB2Cu, 0xAEu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB2Fu, 0x0036D978u, 5u);
        }

        case 0x0036D978u: {
            TP_STATIC_GUARD(0x06DB2Fu, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDB32u, 0x0036D990u, 5u);
        }

        case 0x0036D990u: {
            TP_STATIC_GUARD(0x06DB32u, 0x22u, 0x80u, 0xE1u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDBu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x35u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE180u, 0x00370C00u, 8u);
        }

        case 0x0036D9B1u: {
            TP_STATIC_GUARD(0x06DB36u, 0x82u, 0x81u, 0x04u);
            TP_STATIC_EXIT(0x06u, 0xDFBAu, 0x0036FDD1u, 4u);
        }

        case 0x0036D9CBu: {
            TP_STATIC_GUARD(0x06DB39u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xDB3Bu, 0x0036D9D8u, 3u);
        }

        case 0x0036D9D8u: {
            TP_STATIC_GUARD(0x06DB3Bu, 0xADu, 0xBCu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07BCu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB3Eu, 0x0036D9F0u, 5u);
        }

        case 0x0036D9F0u: {
            TP_STATIC_GUARD(0x06DB3Eu, 0xC9u, 0x01u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0001u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB41u, 0x0036DA08u, 3u);
        }

        case 0x0036DA08u: {
            TP_STATIC_GUARD(0x06DB41u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDB46u;
                if (tp_scpu_expect_next(cpu, 0x0036DA30u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDB43u, 0x0036DA18u, 2u);
        }

        case 0x0036DA18u: {
            TP_STATIC_GUARD(0x06DB43u, 0x82u, 0x9Cu, 0x04u);
            TP_STATIC_EXIT(0x06u, 0xDFE2u, 0x0036FF10u, 4u);
        }

        case 0x0036DA30u: {
            TP_STATIC_GUARD(0x06DB46u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xDB48u, 0x0036DA42u, 3u);
        }

        case 0x0036DA42u: {
            TP_STATIC_GUARD(0x06DB48u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x06u, 0xDB4Au, 0x0036DA52u, 3u);
        }

        case 0x0036DA52u: {
            TP_STATIC_GUARD(0x06DB4Au, 0xA0u, 0x18u, 0x00u);
            const uint16_t value = 0x0018u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB4Du, 0x0036DA6Au, 3u);
        }

        case 0x0036DA6Au: {
            TP_STATIC_GUARD(0x06DB4Du, 0xB7u, 0x5Bu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x5Bu);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = (((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address & 0xFFFFFFu, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x06u;
            cpu->pc = 0xDB4Fu;
            if (tp_scpu_expect_next(cpu, 0x0036DA7Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036DA7Au: {
            TP_STATIC_GUARD(0x06DB4Fu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDB54u;
                if (tp_scpu_expect_next(cpu, 0x0036DAA2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDB51u, 0x0036DA8Au, 2u);
        }

        case 0x0036DA8Au: {
            TP_STATIC_GUARD(0x06DB51u, 0x82u, 0x11u, 0x03u);
            TP_STATIC_EXIT(0x06u, 0xDE65u, 0x0036F32Au, 4u);
        }

        case 0x0036DAA2u: {
            TP_STATIC_GUARD(0x06DB54u, 0xA0u, 0x62u, 0x00u);
            const uint16_t value = 0x0062u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB57u, 0x0036DABAu, 3u);
        }

        case 0x0036DABAu: {
            TP_STATIC_GUARD(0x06DB57u, 0xB7u, 0x5Bu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x5Bu);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = (((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address & 0xFFFFFFu, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x06u;
            cpu->pc = 0xDB59u;
            if (tp_scpu_expect_next(cpu, 0x0036DACAu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036DACAu: {
            TP_STATIC_GUARD(0x06DB59u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDB5Eu;
                if (tp_scpu_expect_next(cpu, 0x0036DAF2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDB5Bu, 0x0036DADAu, 2u);
        }

        case 0x0036DADAu: {
            TP_STATIC_GUARD(0x06DB5Bu, 0x82u, 0x07u, 0x03u);
            TP_STATIC_EXIT(0x06u, 0xDE65u, 0x0036F32Au, 4u);
        }

        case 0x0036DAF2u: {
            TP_STATIC_GUARD(0x06DB5Eu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xDB60u, 0x0036DB00u, 3u);
        }

        case 0x0036DB00u: {
            TP_STATIC_GUARD(0x06DB60u, 0xADu, 0xBCu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07BCu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB63u, 0x0036DB18u, 5u);
        }

        case 0x0036DB18u: {
            TP_STATIC_GUARD(0x06DB63u, 0xC9u, 0x09u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0009u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB66u, 0x0036DB30u, 3u);
        }

        case 0x0036DB30u: {
            TP_STATIC_GUARD(0x06DB66u, 0xD0u, 0x10u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDB78u;
                if (tp_scpu_expect_next(cpu, 0x0036DBC0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDB68u, 0x0036DB40u, 2u);
        }

        case 0x0036DB40u: {
            TP_STATIC_GUARD(0x06DB68u, 0xA0u, 0x1Du, 0x00u);
            const uint16_t value = 0x001Du;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB6Bu, 0x0036DB58u, 3u);
        }

        case 0x0036DB58u: {
            TP_STATIC_GUARD(0x06DB6Bu, 0xB7u, 0x5Bu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x5Bu);
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
            cpu->pc = 0xDB6Du;
            if (tp_scpu_expect_next(cpu, 0x0036DB68u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036DB68u: {
            TP_STATIC_GUARD(0x06DB6Du, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDB75u;
                if (tp_scpu_expect_next(cpu, 0x0036DBA8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDB6Fu, 0x0036DB78u, 2u);
        }

        case 0x0036DB78u: {
            TP_STATIC_GUARD(0x06DB6Fu, 0xA9u, 0x09u, 0x00u);
            const uint16_t value = 0x0009u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB72u, 0x0036DB90u, 3u);
        }

        case 0x0036DB90u: {
            TP_STATIC_GUARD(0x06DB72u, 0x82u, 0x9Bu, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xDE10u, 0x0036F080u, 4u);
        }

        case 0x0036DBA8u: {
            TP_STATIC_GUARD(0x06DB75u, 0x82u, 0x6Au, 0x04u);
            TP_STATIC_EXIT(0x06u, 0xDFE2u, 0x0036FF10u, 4u);
        }

        case 0x0036DBC0u: {
            TP_STATIC_GUARD(0x06DB78u, 0xC9u, 0x0Au, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Au;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB7Bu, 0x0036DBD8u, 3u);
        }

        case 0x0036DBD8u: {
            TP_STATIC_GUARD(0x06DB7Bu, 0xD0u, 0x11u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDB8Eu;
                if (tp_scpu_expect_next(cpu, 0x0036DC70u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDB7Du, 0x0036DBE8u, 2u);
        }

        case 0x0036DBE8u: {
            TP_STATIC_GUARD(0x06DB7Du, 0xADu, 0xD7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18D7u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB80u, 0x0036DC00u, 5u);
        }

        case 0x0036DC00u: {
            TP_STATIC_GUARD(0x06DB80u, 0xC9u, 0x0Au, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Au;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB83u, 0x0036DC18u, 3u);
        }

        case 0x0036DC18u: {
            TP_STATIC_GUARD(0x06DB83u, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDB8Bu;
                if (tp_scpu_expect_next(cpu, 0x0036DC58u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDB85u, 0x0036DC28u, 2u);
        }

        case 0x0036DC28u: {
            TP_STATIC_GUARD(0x06DB85u, 0xA9u, 0x0Au, 0x00u);
            const uint16_t value = 0x000Au;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB88u, 0x0036DC40u, 3u);
        }

        case 0x0036DC40u: {
            TP_STATIC_GUARD(0x06DB88u, 0x82u, 0x85u, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xDE10u, 0x0036F080u, 4u);
        }

        case 0x0036DC58u: {
            TP_STATIC_GUARD(0x06DB8Bu, 0x82u, 0x54u, 0x04u);
            TP_STATIC_EXIT(0x06u, 0xDFE2u, 0x0036FF10u, 4u);
        }

        case 0x0036DC70u: {
            TP_STATIC_GUARD(0x06DB8Eu, 0xC9u, 0x0Bu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Bu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB91u, 0x0036DC88u, 3u);
        }

        case 0x0036DC88u: {
            TP_STATIC_GUARD(0x06DB91u, 0xD0u, 0x11u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDBA4u;
                if (tp_scpu_expect_next(cpu, 0x0036DD20u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDB93u, 0x0036DC98u, 2u);
        }

        case 0x0036DC98u: {
            TP_STATIC_GUARD(0x06DB93u, 0xADu, 0xD7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18D7u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB96u, 0x0036DCB0u, 5u);
        }

        case 0x0036DCB0u: {
            TP_STATIC_GUARD(0x06DB96u, 0xC9u, 0x09u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0009u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB99u, 0x0036DCC8u, 3u);
        }

        case 0x0036DCC8u: {
            TP_STATIC_GUARD(0x06DB99u, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDBA1u;
                if (tp_scpu_expect_next(cpu, 0x0036DD08u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDB9Bu, 0x0036DCD8u, 2u);
        }

        case 0x0036DCD8u: {
            TP_STATIC_GUARD(0x06DB9Bu, 0xA9u, 0x0Bu, 0x00u);
            const uint16_t value = 0x000Bu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB9Eu, 0x0036DCF0u, 3u);
        }

        case 0x0036DCF0u: {
            TP_STATIC_GUARD(0x06DB9Eu, 0x82u, 0x6Fu, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xDE10u, 0x0036F080u, 4u);
        }

        case 0x0036DD08u: {
            TP_STATIC_GUARD(0x06DBA1u, 0x82u, 0x3Eu, 0x04u);
            TP_STATIC_EXIT(0x06u, 0xDFE2u, 0x0036FF10u, 4u);
        }

        case 0x0036DD20u: {
            TP_STATIC_GUARD(0x06DBA4u, 0xC9u, 0x0Cu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Cu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBA7u, 0x0036DD38u, 3u);
        }

        case 0x0036DD38u: {
            TP_STATIC_GUARD(0x06DBA7u, 0xD0u, 0x11u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDBBAu;
                if (tp_scpu_expect_next(cpu, 0x0036DDD0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDBA9u, 0x0036DD48u, 2u);
        }

        case 0x0036DD48u: {
            TP_STATIC_GUARD(0x06DBA9u, 0xADu, 0xD7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18D7u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBACu, 0x0036DD60u, 5u);
        }

        case 0x0036DD60u: {
            TP_STATIC_GUARD(0x06DBACu, 0xC9u, 0x08u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBAFu, 0x0036DD78u, 3u);
        }

        case 0x0036DD78u: {
            TP_STATIC_GUARD(0x06DBAFu, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDBB7u;
                if (tp_scpu_expect_next(cpu, 0x0036DDB8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDBB1u, 0x0036DD88u, 2u);
        }

        case 0x0036DD88u: {
            TP_STATIC_GUARD(0x06DBB1u, 0xA9u, 0x0Cu, 0x00u);
            const uint16_t value = 0x000Cu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBB4u, 0x0036DDA0u, 3u);
        }

        case 0x0036DDA0u: {
            TP_STATIC_GUARD(0x06DBB4u, 0x82u, 0x59u, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xDE10u, 0x0036F080u, 4u);
        }

        case 0x0036DDB8u: {
            TP_STATIC_GUARD(0x06DBB7u, 0x82u, 0x28u, 0x04u);
            TP_STATIC_EXIT(0x06u, 0xDFE2u, 0x0036FF10u, 4u);
        }

        case 0x0036DDD0u: {
            TP_STATIC_GUARD(0x06DBBAu, 0xC9u, 0x0Du, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Du;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBBDu, 0x0036DDE8u, 3u);
        }

        case 0x0036DDE8u: {
            TP_STATIC_GUARD(0x06DBBDu, 0xD0u, 0x11u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDBD0u;
                if (tp_scpu_expect_next(cpu, 0x0036DE80u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDBBFu, 0x0036DDF8u, 2u);
        }

        case 0x0036DDF8u: {
            TP_STATIC_GUARD(0x06DBBFu, 0xADu, 0xD7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18D7u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBC2u, 0x0036DE10u, 5u);
        }

        case 0x0036DE10u: {
            TP_STATIC_GUARD(0x06DBC2u, 0xC9u, 0x07u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0007u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBC5u, 0x0036DE28u, 3u);
        }

        case 0x0036DE28u: {
            TP_STATIC_GUARD(0x06DBC5u, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDBCDu;
                if (tp_scpu_expect_next(cpu, 0x0036DE68u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDBC7u, 0x0036DE38u, 2u);
        }

        case 0x0036DE38u: {
            TP_STATIC_GUARD(0x06DBC7u, 0xA9u, 0x0Du, 0x00u);
            const uint16_t value = 0x000Du;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBCAu, 0x0036DE50u, 3u);
        }

        case 0x0036DE50u: {
            TP_STATIC_GUARD(0x06DBCAu, 0x82u, 0x43u, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xDE10u, 0x0036F080u, 4u);
        }

        case 0x0036DE68u: {
            TP_STATIC_GUARD(0x06DBCDu, 0x82u, 0x12u, 0x04u);
            TP_STATIC_EXIT(0x06u, 0xDFE2u, 0x0036FF10u, 4u);
        }

        case 0x0036DE80u: {
            TP_STATIC_GUARD(0x06DBD0u, 0xC9u, 0x16u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0016u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBD3u, 0x0036DE98u, 3u);
        }

        case 0x0036DE98u: {
            TP_STATIC_GUARD(0x06DBD3u, 0xD0u, 0x11u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDBE6u;
                if (tp_scpu_expect_next(cpu, 0x0036DF30u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDBD5u, 0x0036DEA8u, 2u);
        }

        case 0x0036DEA8u: {
            TP_STATIC_GUARD(0x06DBD5u, 0xADu, 0xD7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18D7u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBD8u, 0x0036DEC0u, 5u);
        }

        case 0x0036DEC0u: {
            TP_STATIC_GUARD(0x06DBD8u, 0xC9u, 0x06u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0006u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBDBu, 0x0036DED8u, 3u);
        }

        case 0x0036DED8u: {
            TP_STATIC_GUARD(0x06DBDBu, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDBE3u;
                if (tp_scpu_expect_next(cpu, 0x0036DF18u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDBDDu, 0x0036DEE8u, 2u);
        }

        case 0x0036DEE8u: {
            TP_STATIC_GUARD(0x06DBDDu, 0xA9u, 0x16u, 0x00u);
            const uint16_t value = 0x0016u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBE0u, 0x0036DF00u, 3u);
        }

        case 0x0036DF00u: {
            TP_STATIC_GUARD(0x06DBE0u, 0x82u, 0x2Du, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xDE10u, 0x0036F080u, 4u);
        }

        case 0x0036DF18u: {
            TP_STATIC_GUARD(0x06DBE3u, 0x82u, 0xFCu, 0x03u);
            TP_STATIC_EXIT(0x06u, 0xDFE2u, 0x0036FF10u, 4u);
        }

        case 0x0036DF30u: {
            TP_STATIC_GUARD(0x06DBE6u, 0xC9u, 0x15u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0015u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBE9u, 0x0036DF48u, 3u);
        }

        case 0x0036DF48u: {
            TP_STATIC_GUARD(0x06DBE9u, 0xD0u, 0x11u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDBFCu;
                if (tp_scpu_expect_next(cpu, 0x0036DFE0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDBEBu, 0x0036DF58u, 2u);
        }

        case 0x0036DF58u: {
            TP_STATIC_GUARD(0x06DBEBu, 0xADu, 0xD7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18D7u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBEEu, 0x0036DF70u, 5u);
        }

        case 0x0036DF70u: {
            TP_STATIC_GUARD(0x06DBEEu, 0xC9u, 0x05u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0005u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBF1u, 0x0036DF88u, 3u);
        }

        case 0x0036DF88u: {
            TP_STATIC_GUARD(0x06DBF1u, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDBF9u;
                if (tp_scpu_expect_next(cpu, 0x0036DFC8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDBF3u, 0x0036DF98u, 2u);
        }

        case 0x0036DF98u: {
            TP_STATIC_GUARD(0x06DBF3u, 0xA9u, 0x15u, 0x00u);
            const uint16_t value = 0x0015u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBF6u, 0x0036DFB0u, 3u);
        }

        case 0x0036DFB0u: {
            TP_STATIC_GUARD(0x06DBF6u, 0x82u, 0x17u, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xDE10u, 0x0036F080u, 4u);
        }

        case 0x0036DFC8u: {
            TP_STATIC_GUARD(0x06DBF9u, 0x82u, 0xE6u, 0x03u);
            TP_STATIC_EXIT(0x06u, 0xDFE2u, 0x0036FF10u, 4u);
        }

        case 0x0036DFE0u: {
            TP_STATIC_GUARD(0x06DBFCu, 0xC9u, 0x17u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0017u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDBFFu, 0x0036DFF8u, 3u);
        }

        case 0x0036DFF8u: {
            TP_STATIC_GUARD(0x06DBFFu, 0xD0u, 0x11u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDC12u;
                if (tp_scpu_expect_next(cpu, 0x0036E090u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDC01u, 0x0036E008u, 2u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
