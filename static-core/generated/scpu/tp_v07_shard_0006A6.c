/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0006A6(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00353009u: {
            TP_STATIC_GUARD(0x06A601u, 0xCDu, 0x0Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA604u, 0x00353021u, 5u);
        }

        case 0x00353021u: {
            TP_STATIC_GUARD(0x06A604u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA609u;
                if (tp_scpu_expect_next(cpu, 0x00353049u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA606u, 0x00353031u, 2u);
        }

        case 0x00353031u: {
            TP_STATIC_GUARD(0x06A606u, 0x82u, 0xC0u, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xA8C9u, 0x00354649u, 4u);
        }

        case 0x00353049u: {
            TP_STATIC_GUARD(0x06A609u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xA60Bu, 0x00353058u, 3u);
        }

        case 0x00353058u: {
            TP_STATIC_GUARD(0x06A60Bu, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA60Eu, 0x00353070u, 3u);
        }

        case 0x00353070u: {
            TP_STATIC_GUARD(0x06A60Eu, 0x22u, 0x86u, 0xBCu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x11u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBC86u, 0x0035E430u, 8u);
        }

        case 0x00353091u: {
            TP_STATIC_GUARD(0x06A612u, 0x8Du, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0016u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA615u, 0x003530A9u, 5u);
        }

        case 0x003530A9u: {
            TP_STATIC_GUARD(0x06A615u, 0x8Eu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA618u, 0x003530C1u, 4u);
        }

        case 0x003530C0u: {
            TP_STATIC_GUARD(0x06A618u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xA61Au, 0x003530D0u, 3u);
        }

        case 0x003530C1u: {
            TP_STATIC_GUARD(0x06A618u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xA61Au, 0x003530D0u, 3u);
        }

        case 0x003530D0u: {
            TP_STATIC_GUARD(0x06A61Au, 0xADu, 0x3Au, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x143Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA61Du, 0x003530E8u, 5u);
        }

        case 0x003530E8u: {
            TP_STATIC_GUARD(0x06A61Du, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA620u, 0x00353100u, 3u);
        }

        case 0x00353100u: {
            TP_STATIC_GUARD(0x06A620u, 0x22u, 0x86u, 0xBCu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x23u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBC86u, 0x0035E430u, 8u);
        }

        case 0x00353121u: {
            TP_STATIC_GUARD(0x06A624u, 0xCDu, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0016u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA627u, 0x00353139u, 5u);
        }

        case 0x00353139u: {
            TP_STATIC_GUARD(0x06A627u, 0xF0u, 0x02u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA62Bu;
                if (tp_scpu_expect_next(cpu, 0x00353159u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA629u, 0x00353149u, 2u);
        }

        case 0x00353149u: {
            TP_STATIC_GUARD(0x06A629u, 0xB0u, 0x03u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA62Eu;
                if (tp_scpu_expect_next(cpu, 0x00353171u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA62Bu, 0x00353159u, 2u);
        }

        case 0x00353159u: {
            TP_STATIC_GUARD(0x06A62Bu, 0x82u, 0x9Bu, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xA8C9u, 0x00354649u, 4u);
        }

        case 0x00353171u: {
            TP_STATIC_GUARD(0x06A62Eu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xA630u, 0x00353183u, 3u);
        }

        case 0x00353183u: {
            TP_STATIC_GUARD(0x06A630u, 0xA0u, 0x09u);
            const uint8_t value = 0x09u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA632u, 0x00353193u, 2u);
        }

        case 0x00353193u: {
            TP_STATIC_GUARD(0x06A632u, 0xB7u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
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
            cpu->pc = 0xA634u;
            if (tp_scpu_expect_next(cpu, 0x003531A3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003531A3u: {
            TP_STATIC_GUARD(0x06A634u, 0xC9u, 0x01u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x01u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA636u, 0x003531B3u, 2u);
        }

        case 0x003531B3u: {
            TP_STATIC_GUARD(0x06A636u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA63Bu;
                if (tp_scpu_expect_next(cpu, 0x003531DBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA638u, 0x003531C3u, 2u);
        }

        case 0x003531C3u: {
            TP_STATIC_GUARD(0x06A638u, 0x82u, 0x6Au, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xA8A5u, 0x0035452Bu, 4u);
        }

        case 0x003531DBu: {
            TP_STATIC_GUARD(0x06A63Bu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xA63Du, 0x003531EBu, 3u);
        }

        case 0x003531EBu: {
            TP_STATIC_GUARD(0x06A63Du, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x06u, 0xA63Fu, 0x003531F9u, 3u);
        }

        case 0x003531F9u: {
            TP_STATIC_GUARD(0x06A63Fu, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA642u, 0x00353211u, 3u);
        }

        case 0x00353211u: {
            TP_STATIC_GUARD(0x06A642u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xA644u, 0x00353223u, 3u);
        }

        case 0x00353223u: {
            TP_STATIC_GUARD(0x06A644u, 0xA0u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA646u, 0x00353233u, 2u);
        }

        case 0x00353233u: {
            TP_STATIC_GUARD(0x06A646u, 0xB7u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
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
            cpu->pc = 0xA648u;
            if (tp_scpu_expect_next(cpu, 0x00353243u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00353243u: {
            TP_STATIC_GUARD(0x06A648u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xA64Au, 0x00353250u, 3u);
        }

        case 0x00353250u: {
            TP_STATIC_GUARD(0x06A64Au, 0x22u, 0xA0u, 0xBCu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x4Du) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBCA0u, 0x0035E500u, 8u);
        }

        case 0x00353271u: {
            TP_STATIC_GUARD(0x06A64Eu, 0x8Du, 0x19u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0019u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA651u, 0x00353289u, 5u);
        }

        case 0x00353289u: {
            TP_STATIC_GUARD(0x06A651u, 0x8Eu, 0x1Bu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x001Bu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA654u, 0x003532A1u, 4u);
        }

        case 0x003532A1u: {
            TP_STATIC_GUARD(0x06A654u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA657u, 0x003532B9u, 3u);
        }

        case 0x003532B9u: {
            TP_STATIC_GUARD(0x06A657u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xA659u, 0x003532CBu, 3u);
        }

        case 0x003532CBu: {
            TP_STATIC_GUARD(0x06A659u, 0xA0u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA65Bu, 0x003532DBu, 2u);
        }

        case 0x003532DBu: {
            TP_STATIC_GUARD(0x06A65Bu, 0xB7u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
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
            cpu->pc = 0xA65Du;
            if (tp_scpu_expect_next(cpu, 0x003532EBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003532EBu: {
            TP_STATIC_GUARD(0x06A65Du, 0xC9u, 0x17u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x17u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA65Fu, 0x003532FBu, 2u);
        }

        case 0x003532FBu: {
            TP_STATIC_GUARD(0x06A65Fu, 0xF0u, 0x4Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA6ADu;
                if (tp_scpu_expect_next(cpu, 0x0035356Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA661u, 0x0035330Bu, 2u);
        }

        case 0x0035330Bu: {
            TP_STATIC_GUARD(0x06A661u, 0xC9u, 0x10u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x10u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA663u, 0x0035331Bu, 2u);
        }

        case 0x0035331Bu: {
            TP_STATIC_GUARD(0x06A663u, 0xF0u, 0x48u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA6ADu;
                if (tp_scpu_expect_next(cpu, 0x0035356Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA665u, 0x0035332Bu, 2u);
        }

        case 0x0035332Bu: {
            TP_STATIC_GUARD(0x06A665u, 0xC9u, 0x16u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x16u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA667u, 0x0035333Bu, 2u);
        }

        case 0x0035333Bu: {
            TP_STATIC_GUARD(0x06A667u, 0xF0u, 0x44u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA6ADu;
                if (tp_scpu_expect_next(cpu, 0x0035356Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA669u, 0x0035334Bu, 2u);
        }

        case 0x0035334Bu: {
            TP_STATIC_GUARD(0x06A669u, 0xC9u, 0x22u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x22u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA66Bu, 0x0035335Bu, 2u);
        }

        case 0x0035335Bu: {
            TP_STATIC_GUARD(0x06A66Bu, 0xF0u, 0x40u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA6ADu;
                if (tp_scpu_expect_next(cpu, 0x0035356Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA66Du, 0x0035336Bu, 2u);
        }

        case 0x0035336Bu: {
            TP_STATIC_GUARD(0x06A66Du, 0xC9u, 0x1Fu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x1Fu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA66Fu, 0x0035337Bu, 2u);
        }

        case 0x0035337Bu: {
            TP_STATIC_GUARD(0x06A66Fu, 0xF0u, 0x3Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA6ADu;
                if (tp_scpu_expect_next(cpu, 0x0035356Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA671u, 0x0035338Bu, 2u);
        }

        case 0x0035338Bu: {
            TP_STATIC_GUARD(0x06A671u, 0xC9u, 0x1Du);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x1Du;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA673u, 0x0035339Bu, 2u);
        }

        case 0x0035339Bu: {
            TP_STATIC_GUARD(0x06A673u, 0xF0u, 0x38u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA6ADu;
                if (tp_scpu_expect_next(cpu, 0x0035356Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA675u, 0x003533ABu, 2u);
        }

        case 0x003533ABu: {
            TP_STATIC_GUARD(0x06A675u, 0xC9u, 0x24u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x24u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA677u, 0x003533BBu, 2u);
        }

        case 0x003533BBu: {
            TP_STATIC_GUARD(0x06A677u, 0xF0u, 0x34u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA6ADu;
                if (tp_scpu_expect_next(cpu, 0x0035356Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA679u, 0x003533CBu, 2u);
        }

        case 0x003533CBu: {
            TP_STATIC_GUARD(0x06A679u, 0xC9u, 0x05u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x05u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA67Bu, 0x003533DBu, 2u);
        }

        case 0x003533DBu: {
            TP_STATIC_GUARD(0x06A67Bu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA680u;
                if (tp_scpu_expect_next(cpu, 0x00353403u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA67Du, 0x003533EBu, 2u);
        }

        case 0x003533EBu: {
            TP_STATIC_GUARD(0x06A67Du, 0x82u, 0x30u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xA6B0u, 0x00353583u, 4u);
        }

        case 0x00353403u: {
            TP_STATIC_GUARD(0x06A680u, 0xC9u, 0x25u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x25u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA682u, 0x00353413u, 2u);
        }

        case 0x00353413u: {
            TP_STATIC_GUARD(0x06A682u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA687u;
                if (tp_scpu_expect_next(cpu, 0x0035343Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA684u, 0x00353423u, 2u);
        }

        case 0x00353423u: {
            TP_STATIC_GUARD(0x06A684u, 0x82u, 0x64u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xA6EBu, 0x0035375Bu, 4u);
        }

        case 0x0035343Bu: {
            TP_STATIC_GUARD(0x06A687u, 0xC9u, 0x26u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x26u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA689u, 0x0035344Bu, 2u);
        }

        case 0x0035344Bu: {
            TP_STATIC_GUARD(0x06A689u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA68Eu;
                if (tp_scpu_expect_next(cpu, 0x00353473u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA68Bu, 0x0035345Bu, 2u);
        }

        case 0x0035345Bu: {
            TP_STATIC_GUARD(0x06A68Bu, 0x82u, 0xD1u, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xA75Fu, 0x00353AFBu, 4u);
        }

        case 0x00353473u: {
            TP_STATIC_GUARD(0x06A68Eu, 0xC9u, 0x27u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x27u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA690u, 0x00353483u, 2u);
        }

        case 0x00353483u: {
            TP_STATIC_GUARD(0x06A690u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA695u;
                if (tp_scpu_expect_next(cpu, 0x003534ABu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA692u, 0x00353493u, 2u);
        }

        case 0x00353493u: {
            TP_STATIC_GUARD(0x06A692u, 0x82u, 0x05u, 0x01u);
            TP_STATIC_EXIT(0x06u, 0xA79Au, 0x00353CD3u, 4u);
        }

        case 0x003534ABu: {
            TP_STATIC_GUARD(0x06A695u, 0xC9u, 0x28u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x28u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA697u, 0x003534BBu, 2u);
        }

        case 0x003534BBu: {
            TP_STATIC_GUARD(0x06A697u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA69Cu;
                if (tp_scpu_expect_next(cpu, 0x003534E3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA699u, 0x003534CBu, 2u);
        }

        case 0x003534CBu: {
            TP_STATIC_GUARD(0x06A699u, 0x82u, 0x39u, 0x01u);
            TP_STATIC_EXIT(0x06u, 0xA7D5u, 0x00353EABu, 4u);
        }

        case 0x003534E3u: {
            TP_STATIC_GUARD(0x06A69Cu, 0xC9u, 0x29u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x29u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA69Eu, 0x003534F3u, 2u);
        }

        case 0x003534F3u: {
            TP_STATIC_GUARD(0x06A69Eu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA6A3u;
                if (tp_scpu_expect_next(cpu, 0x0035351Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA6A0u, 0x00353503u, 2u);
        }

        case 0x00353503u: {
            TP_STATIC_GUARD(0x06A6A0u, 0x82u, 0x6Du, 0x01u);
            TP_STATIC_EXIT(0x06u, 0xA810u, 0x00354083u, 4u);
        }

        case 0x0035351Bu: {
            TP_STATIC_GUARD(0x06A6A3u, 0xC9u, 0x2Au);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x2Au;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA6A5u, 0x0035352Bu, 2u);
        }

        case 0x0035352Bu: {
            TP_STATIC_GUARD(0x06A6A5u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xA6AAu;
                if (tp_scpu_expect_next(cpu, 0x00353553u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xA6A7u, 0x0035353Bu, 2u);
        }

        case 0x0035353Bu: {
            TP_STATIC_GUARD(0x06A6A7u, 0x82u, 0x7Au, 0x00u);
            TP_STATIC_EXIT(0x06u, 0xA724u, 0x00353923u, 4u);
        }

        case 0x00353553u: {
            TP_STATIC_GUARD(0x06A6AAu, 0x82u, 0x9Eu, 0x01u);
            TP_STATIC_EXIT(0x06u, 0xA84Bu, 0x0035425Bu, 4u);
        }

        case 0x0035356Bu: {
            TP_STATIC_GUARD(0x06A6ADu, 0x82u, 0x0Au, 0x02u);
            TP_STATIC_EXIT(0x06u, 0xA8BAu, 0x003545D3u, 4u);
        }

        case 0x00353583u: {
            TP_STATIC_GUARD(0x06A6B0u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xA6B2u, 0x00353593u, 3u);
        }

        case 0x00353593u: {
            TP_STATIC_GUARD(0x06A6B2u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x06u, 0xA6B4u, 0x003535A1u, 3u);
        }

        case 0x003535A1u: {
            TP_STATIC_GUARD(0x06A6B4u, 0xADu, 0xCFu, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06CFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA6B7u, 0x003535B9u, 5u);
        }

        case 0x003535B9u: {
            TP_STATIC_GUARD(0x06A6B7u, 0x8Du, 0x1Fu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x001Fu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA6BAu, 0x003535D1u, 5u);
        }

        case 0x003535D1u: {
            TP_STATIC_GUARD(0x06A6BAu, 0xAEu, 0xD1u, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06D1u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA6BDu, 0x003535E9u, 4u);
        }

        case 0x003535E9u: {
            TP_STATIC_GUARD(0x06A6BDu, 0x8Eu, 0x21u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0021u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA6C0u, 0x00353601u, 4u);
        }

        case 0x00353601u: {
            TP_STATIC_GUARD(0x06A6C0u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xA6C2u, 0x00353610u, 3u);
        }

        case 0x00353610u: {
            TP_STATIC_GUARD(0x06A6C2u, 0xA9u, 0x06u, 0x01u);
            const uint16_t value = 0x0106u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA6C5u, 0x00353628u, 3u);
        }

        case 0x00353628u: {
            TP_STATIC_GUARD(0x06A6C5u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA6C6u, 0x00353630u, 3u);
        }

        case 0x00353630u: {
            TP_STATIC_GUARD(0x06A6C6u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA6C7u, 0x00353638u, 2u);
        }

        case 0x00353638u: {
            TP_STATIC_GUARD(0x06A6C7u, 0xB7u, 0x1Fu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x1Fu);
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
            cpu->pc = 0xA6C9u;
            if (tp_scpu_expect_next(cpu, 0x00353648u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00353648u: {
            TP_STATIC_GUARD(0x06A6C9u, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA6CCu, 0x00353660u, 5u);
        }

        case 0x00353660u: {
            TP_STATIC_GUARD(0x06A6CCu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xA6CEu, 0x00353671u, 3u);
        }

        case 0x00353671u: {
            TP_STATIC_GUARD(0x06A6CEu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x06u, 0xA6D0u, 0x00353681u, 3u);
        }

        case 0x00353681u: {
            TP_STATIC_GUARD(0x06A6D0u, 0xAEu, 0x21u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0021u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA6D3u, 0x00353699u, 4u);
        }

        case 0x00353699u: {
            TP_STATIC_GUARD(0x06A6D3u, 0x8Eu, 0x94u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0794u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA6D6u, 0x003536B1u, 4u);
        }

        case 0x003536B1u: {
            TP_STATIC_GUARD(0x06A6D6u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xA6D8u, 0x003536C0u, 3u);
        }

        case 0x003536C0u: {
            TP_STATIC_GUARD(0x06A6D8u, 0xA9u, 0x02u, 0x00u);
            const uint16_t value = 0x0002u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA6DBu, 0x003536D8u, 3u);
        }

        case 0x003536D8u: {
            TP_STATIC_GUARD(0x06A6DBu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA6DEu, 0x003536F0u, 5u);
        }

        case 0x003536F0u: {
            TP_STATIC_GUARD(0x06A6DEu, 0xA9u, 0x05u, 0x00u);
            const uint16_t value = 0x0005u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA6E1u, 0x00353708u, 3u);
        }

        case 0x00353708u: {
            TP_STATIC_GUARD(0x06A6E1u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA6E4u, 0x00353720u, 5u);
        }

        case 0x00353720u: {
            TP_STATIC_GUARD(0x06A6E4u, 0x22u, 0x3Cu, 0xA3u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA6u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE7u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA33Cu, 0x003519E0u, 8u);
        }

        case 0x00353740u: {
            TP_STATIC_GUARD(0x06A6E8u, 0x82u, 0xCFu, 0x01u);
            TP_STATIC_EXIT(0x06u, 0xA8BAu, 0x003545D0u, 4u);
        }

        case 0x0035375Bu: {
            TP_STATIC_GUARD(0x06A6EBu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xA6EDu, 0x0035376Bu, 3u);
        }

        case 0x0035376Bu: {
            TP_STATIC_GUARD(0x06A6EDu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x06u, 0xA6EFu, 0x00353779u, 3u);
        }

        case 0x00353779u: {
            TP_STATIC_GUARD(0x06A6EFu, 0xADu, 0xCFu, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06CFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA6F2u, 0x00353791u, 5u);
        }

        case 0x00353791u: {
            TP_STATIC_GUARD(0x06A6F2u, 0x8Du, 0x1Fu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x001Fu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA6F5u, 0x003537A9u, 5u);
        }

        case 0x003537A9u: {
            TP_STATIC_GUARD(0x06A6F5u, 0xAEu, 0xD1u, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06D1u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA6F8u, 0x003537C1u, 4u);
        }

        case 0x003537C1u: {
            TP_STATIC_GUARD(0x06A6F8u, 0x8Eu, 0x21u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0021u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA6FBu, 0x003537D9u, 4u);
        }

        case 0x003537D9u: {
            TP_STATIC_GUARD(0x06A6FBu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xA6FDu, 0x003537E8u, 3u);
        }

        case 0x003537E8u: {
            TP_STATIC_GUARD(0x06A6FDu, 0xA9u, 0x05u, 0x01u);
            const uint16_t value = 0x0105u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xA700u, 0x00353800u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
