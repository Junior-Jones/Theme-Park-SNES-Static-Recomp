/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000581(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x002C0800u: {
            TP_STATIC_GUARD(0x058100u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8101u, 0x002C0808u, 2u);
        }

        case 0x002C0808u: {
            TP_STATIC_GUARD(0x058101u, 0x8Du, 0x34u, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1434u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x8104u, 0x002C0820u, 5u);
        }

        case 0x002C0820u: {
            TP_STATIC_GUARD(0x058104u, 0xA9u, 0x08u, 0x00u);
            const uint16_t value = 0x0008u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8107u, 0x002C0838u, 3u);
        }

        case 0x002C0838u: {
            TP_STATIC_GUARD(0x058107u, 0x22u, 0x9Eu, 0x90u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x909Eu, 0x006484F0u, 8u);
        }

        case 0x002C085Bu: {
            TP_STATIC_GUARD(0x05810Bu, 0x22u, 0x29u, 0x95u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Eu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9529u, 0x003CA94Bu, 8u);
        }

        case 0x002C087Bu: {
            TP_STATIC_GUARD(0x05810Fu, 0x82u, 0xF3u, 0x01u);
            TP_STATIC_EXIT(0x05u, 0x8305u, 0x002C182Bu, 4u);
        }

        case 0x002C0893u: {
            TP_STATIC_GUARD(0x058112u, 0xC9u, 0x04u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x04u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8114u, 0x002C08A3u, 2u);
        }

        case 0x002C08A3u: {
            TP_STATIC_GUARD(0x058114u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8119u;
                if (tp_scpu_expect_next(cpu, 0x002C08CBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x8116u, 0x002C08B3u, 2u);
        }

        case 0x002C08B3u: {
            TP_STATIC_GUARD(0x058116u, 0x82u, 0x72u, 0x01u);
            TP_STATIC_EXIT(0x05u, 0x828Bu, 0x002C145Bu, 4u);
        }

        case 0x002C08CBu: {
            TP_STATIC_GUARD(0x058119u, 0xA0u, 0x10u);
            const uint8_t value = 0x10u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x811Bu, 0x002C08DBu, 2u);
        }

        case 0x002C08DBu: {
            TP_STATIC_GUARD(0x05811Bu, 0xB7u, 0x49u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x49u);
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
            cpu->pbr = 0x05u;
            cpu->pc = 0x811Du;
            if (tp_scpu_expect_next(cpu, 0x002C08EBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x002C08EBu: {
            TP_STATIC_GUARD(0x05811Du, 0xC9u, 0x04u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x04u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x811Fu, 0x002C08FBu, 2u);
        }

        case 0x002C08FBu: {
            TP_STATIC_GUARD(0x05811Fu, 0xF0u, 0x08u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8129u;
                if (tp_scpu_expect_next(cpu, 0x002C094Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x8121u, 0x002C090Bu, 2u);
        }

        case 0x002C090Bu: {
            TP_STATIC_GUARD(0x058121u, 0xC9u, 0x1Eu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x1Eu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8123u, 0x002C091Bu, 2u);
        }

        case 0x002C091Bu: {
            TP_STATIC_GUARD(0x058123u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8129u;
                if (tp_scpu_expect_next(cpu, 0x002C094Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x8125u, 0x002C092Bu, 2u);
        }

        case 0x002C092Bu: {
            TP_STATIC_GUARD(0x058125u, 0xC9u, 0x06u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x06u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8127u, 0x002C093Bu, 2u);
        }

        case 0x002C093Bu: {
            TP_STATIC_GUARD(0x058127u, 0xD0u, 0x30u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8159u;
                if (tp_scpu_expect_next(cpu, 0x002C0ACBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x8129u, 0x002C094Bu, 2u);
        }

        case 0x002C094Bu: {
            TP_STATIC_GUARD(0x058129u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x05u, 0x812Bu, 0x002C0958u, 3u);
        }

        case 0x002C0958u: {
            TP_STATIC_GUARD(0x05812Bu, 0xADu, 0x96u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0796u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x812Eu, 0x002C0970u, 5u);
        }

        case 0x002C0970u: {
            TP_STATIC_GUARD(0x05812Eu, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8131u, 0x002C0988u, 3u);
        }

        case 0x002C0988u: {
            TP_STATIC_GUARD(0x058131u, 0xC9u, 0x07u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0007u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8134u, 0x002C09A0u, 3u);
        }

        case 0x002C09A0u: {
            TP_STATIC_GUARD(0x058134u, 0xB0u, 0x03u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8139u;
                if (tp_scpu_expect_next(cpu, 0x002C09C8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x8136u, 0x002C09B0u, 2u);
        }

        case 0x002C09B0u: {
            TP_STATIC_GUARD(0x058136u, 0x4Cu, 0x44u, 0x82u);
            TP_STATIC_EXIT(0x05u, 0x8244u, 0x002C1220u, 3u);
        }

        case 0x002C09C8u: {
            TP_STATIC_GUARD(0x058139u, 0xC9u, 0x09u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0009u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x813Cu, 0x002C09E0u, 3u);
        }

        case 0x002C09E0u: {
            TP_STATIC_GUARD(0x05813Cu, 0x90u, 0x03u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8141u;
                if (tp_scpu_expect_next(cpu, 0x002C0A08u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x813Eu, 0x002C09F0u, 2u);
        }

        case 0x002C09F0u: {
            TP_STATIC_GUARD(0x05813Eu, 0x4Cu, 0x44u, 0x82u);
            TP_STATIC_EXIT(0x05u, 0x8244u, 0x002C1220u, 3u);
        }

        case 0x002C0A08u: {
            TP_STATIC_GUARD(0x058141u, 0xADu, 0x9Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x079Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8144u, 0x002C0A20u, 5u);
        }

        case 0x002C0A20u: {
            TP_STATIC_GUARD(0x058144u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8147u, 0x002C0A38u, 3u);
        }

        case 0x002C0A38u: {
            TP_STATIC_GUARD(0x058147u, 0xC9u, 0x07u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0007u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x814Au, 0x002C0A50u, 3u);
        }

        case 0x002C0A50u: {
            TP_STATIC_GUARD(0x05814Au, 0xB0u, 0x03u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x814Fu;
                if (tp_scpu_expect_next(cpu, 0x002C0A78u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x814Cu, 0x002C0A60u, 2u);
        }

        case 0x002C0A60u: {
            TP_STATIC_GUARD(0x05814Cu, 0x4Cu, 0x44u, 0x82u);
            TP_STATIC_EXIT(0x05u, 0x8244u, 0x002C1220u, 3u);
        }

        case 0x002C0A78u: {
            TP_STATIC_GUARD(0x05814Fu, 0xC9u, 0x09u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0009u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8152u, 0x002C0A90u, 3u);
        }

        case 0x002C0A90u: {
            TP_STATIC_GUARD(0x058152u, 0x90u, 0x03u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8157u;
                if (tp_scpu_expect_next(cpu, 0x002C0AB8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x8154u, 0x002C0AA0u, 2u);
        }

        case 0x002C0AA0u: {
            TP_STATIC_GUARD(0x058154u, 0x4Cu, 0x44u, 0x82u);
            TP_STATIC_EXIT(0x05u, 0x8244u, 0x002C1220u, 3u);
        }

        case 0x002C0AB8u: {
            TP_STATIC_GUARD(0x058157u, 0x80u, 0x2Eu);
            TP_STATIC_EXIT(0x05u, 0x8187u, 0x002C0C38u, 3u);
        }

        case 0x002C0ACBu: {
            TP_STATIC_GUARD(0x058159u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x05u, 0x815Bu, 0x002C0AD8u, 3u);
        }

        case 0x002C0AD8u: {
            TP_STATIC_GUARD(0x05815Bu, 0xADu, 0x96u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0796u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x815Eu, 0x002C0AF0u, 5u);
        }

        case 0x002C0AF0u: {
            TP_STATIC_GUARD(0x05815Eu, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8161u, 0x002C0B08u, 3u);
        }

        case 0x002C0B08u: {
            TP_STATIC_GUARD(0x058161u, 0xC9u, 0x07u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0007u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8164u, 0x002C0B20u, 3u);
        }

        case 0x002C0B20u: {
            TP_STATIC_GUARD(0x058164u, 0xB0u, 0x03u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8169u;
                if (tp_scpu_expect_next(cpu, 0x002C0B48u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x8166u, 0x002C0B30u, 2u);
        }

        case 0x002C0B30u: {
            TP_STATIC_GUARD(0x058166u, 0x4Cu, 0x44u, 0x82u);
            TP_STATIC_EXIT(0x05u, 0x8244u, 0x002C1220u, 3u);
        }

        case 0x002C0B48u: {
            TP_STATIC_GUARD(0x058169u, 0xC9u, 0x0Au, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Au;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x816Cu, 0x002C0B60u, 3u);
        }

        case 0x002C0B60u: {
            TP_STATIC_GUARD(0x05816Cu, 0x90u, 0x03u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8171u;
                if (tp_scpu_expect_next(cpu, 0x002C0B88u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x816Eu, 0x002C0B70u, 2u);
        }

        case 0x002C0B70u: {
            TP_STATIC_GUARD(0x05816Eu, 0x4Cu, 0x44u, 0x82u);
            TP_STATIC_EXIT(0x05u, 0x8244u, 0x002C1220u, 3u);
        }

        case 0x002C0B88u: {
            TP_STATIC_GUARD(0x058171u, 0xADu, 0x9Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x079Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8174u, 0x002C0BA0u, 5u);
        }

        case 0x002C0BA0u: {
            TP_STATIC_GUARD(0x058174u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8177u, 0x002C0BB8u, 3u);
        }

        case 0x002C0BB8u: {
            TP_STATIC_GUARD(0x058177u, 0xC9u, 0x06u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0006u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x817Au, 0x002C0BD0u, 3u);
        }

        case 0x002C0BD0u: {
            TP_STATIC_GUARD(0x05817Au, 0xB0u, 0x03u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x817Fu;
                if (tp_scpu_expect_next(cpu, 0x002C0BF8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x817Cu, 0x002C0BE0u, 2u);
        }

        case 0x002C0BE0u: {
            TP_STATIC_GUARD(0x05817Cu, 0x4Cu, 0x44u, 0x82u);
            TP_STATIC_EXIT(0x05u, 0x8244u, 0x002C1220u, 3u);
        }

        case 0x002C0BF8u: {
            TP_STATIC_GUARD(0x05817Fu, 0xC9u, 0x0Au, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Au;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8182u, 0x002C0C10u, 3u);
        }

        case 0x002C0C10u: {
            TP_STATIC_GUARD(0x058182u, 0x90u, 0x03u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8187u;
                if (tp_scpu_expect_next(cpu, 0x002C0C38u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x8184u, 0x002C0C20u, 2u);
        }

        case 0x002C0C20u: {
            TP_STATIC_GUARD(0x058184u, 0x4Cu, 0x44u, 0x82u);
            TP_STATIC_EXIT(0x05u, 0x8244u, 0x002C1220u, 3u);
        }

        case 0x002C0C38u: {
            TP_STATIC_GUARD(0x058187u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x05u, 0x8189u, 0x002C0C49u, 3u);
        }

        case 0x002C0C49u: {
            TP_STATIC_GUARD(0x058189u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x05u, 0x818Bu, 0x002C0C59u, 3u);
        }

        case 0x002C0C59u: {
            TP_STATIC_GUARD(0x05818Bu, 0xA0u, 0x1Au);
            const uint8_t value = 0x1Au;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x818Du, 0x002C0C69u, 2u);
        }

        case 0x002C0C69u: {
            TP_STATIC_GUARD(0x05818Du, 0xB7u, 0x49u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x49u);
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
            cpu->pbr = 0x05u;
            cpu->pc = 0x818Fu;
            if (tp_scpu_expect_next(cpu, 0x002C0C79u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x002C0C79u: {
            TP_STATIC_GUARD(0x05818Fu, 0xA2u, 0x30u);
            const uint8_t value = 0x30u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8191u, 0x002C0C89u, 2u);
        }

        case 0x002C0C89u: {
            TP_STATIC_GUARD(0x058191u, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8194u, 0x002C0CA1u, 3u);
        }

        case 0x002C0CA1u: {
            TP_STATIC_GUARD(0x058194u, 0xF0u, 0x1Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x81B2u;
                if (tp_scpu_expect_next(cpu, 0x002C0D91u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x8196u, 0x002C0CB1u, 2u);
        }

        case 0x002C0CB1u: {
            TP_STATIC_GUARD(0x058196u, 0xE0u, 0x00u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x00u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8198u, 0x002C0CC1u, 2u);
        }

        case 0x002C0CC1u: {
            TP_STATIC_GUARD(0x058198u, 0xF0u, 0x18u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x81B2u;
                if (tp_scpu_expect_next(cpu, 0x002C0D91u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x819Au, 0x002C0CD1u, 2u);
        }

        case 0x002C0CD1u: {
            TP_STATIC_GUARD(0x05819Au, 0x8Du, 0x04u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4204u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x819Du, 0x002C0CE9u, 5u);
        }

        case 0x002C0CE9u: {
            TP_STATIC_GUARD(0x05819Du, 0x8Eu, 0x06u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4206u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x81A0u, 0x002C0D01u, 4u);
        }

        case 0x002C0D01u: {
            TP_STATIC_GUARD(0x0581A0u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x81A1u, 0x002C0D09u, 2u);
        }

        case 0x002C0D09u: {
            TP_STATIC_GUARD(0x0581A1u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x81A2u, 0x002C0D11u, 2u);
        }

        case 0x002C0D11u: {
            TP_STATIC_GUARD(0x0581A2u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x81A3u, 0x002C0D19u, 2u);
        }

        case 0x002C0D19u: {
            TP_STATIC_GUARD(0x0581A3u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x81A4u, 0x002C0D21u, 2u);
        }

        case 0x002C0D21u: {
            TP_STATIC_GUARD(0x0581A4u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x81A5u, 0x002C0D29u, 2u);
        }

        case 0x002C0D29u: {
            TP_STATIC_GUARD(0x0581A5u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x81A6u, 0x002C0D31u, 2u);
        }

        case 0x002C0D31u: {
            TP_STATIC_GUARD(0x0581A6u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x81A7u, 0x002C0D39u, 2u);
        }

        case 0x002C0D39u: {
            TP_STATIC_GUARD(0x0581A7u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x81A8u, 0x002C0D41u, 2u);
        }

        case 0x002C0D41u: {
            TP_STATIC_GUARD(0x0581A8u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x05u, 0x81AAu, 0x002C0D50u, 3u);
        }

        case 0x002C0D50u: {
            TP_STATIC_GUARD(0x0581AAu, 0xADu, 0x14u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4214u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81ADu, 0x002C0D68u, 5u);
        }

        case 0x002C0D68u: {
            TP_STATIC_GUARD(0x0581ADu, 0xAEu, 0x16u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4216u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81B0u, 0x002C0D80u, 5u);
        }

        case 0x002C0D80u: {
            TP_STATIC_GUARD(0x0581B0u, 0x80u, 0x06u);
            TP_STATIC_EXIT(0x05u, 0x81B8u, 0x002C0DC0u, 3u);
        }

        case 0x002C0D91u: {
            TP_STATIC_GUARD(0x0581B2u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x05u, 0x81B4u, 0x002C0DA0u, 3u);
        }

        case 0x002C0DA0u: {
            TP_STATIC_GUARD(0x0581B4u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81B7u, 0x002C0DB8u, 3u);
        }

        case 0x002C0DB8u: {
            TP_STATIC_GUARD(0x0581B7u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81B8u, 0x002C0DC0u, 2u);
        }

        case 0x002C0DC0u: {
            TP_STATIC_GUARD(0x0581B8u, 0x8Du, 0x14u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0814u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x81BBu, 0x002C0DD8u, 5u);
        }

        case 0x002C0DD8u: {
            TP_STATIC_GUARD(0x0581BBu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x05u, 0x81BDu, 0x002C0DEBu, 3u);
        }

        case 0x002C0DEBu: {
            TP_STATIC_GUARD(0x0581BDu, 0xADu, 0x0Au, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x080Au;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81C0u, 0x002C0E03u, 4u);
        }

        case 0x002C0E03u: {
            TP_STATIC_GUARD(0x0581C0u, 0xC9u, 0x15u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x15u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81C2u, 0x002C0E13u, 2u);
        }

        case 0x002C0E13u: {
            TP_STATIC_GUARD(0x0581C2u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x81C7u;
                if (tp_scpu_expect_next(cpu, 0x002C0E3Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x81C4u, 0x002C0E23u, 2u);
        }

        case 0x002C0E23u: {
            TP_STATIC_GUARD(0x0581C4u, 0x82u, 0x80u, 0x00u);
            TP_STATIC_EXIT(0x05u, 0x8247u, 0x002C123Bu, 4u);
        }

        case 0x002C0E3Bu: {
            TP_STATIC_GUARD(0x0581C7u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x05u, 0x81C9u, 0x002C0E48u, 3u);
        }

        case 0x002C0E48u: {
            TP_STATIC_GUARD(0x0581C9u, 0xACu, 0x34u, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1434u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81CCu, 0x002C0E60u, 5u);
        }

        case 0x002C0E60u: {
            TP_STATIC_GUARD(0x0581CCu, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81CDu, 0x002C0E68u, 2u);
        }

        case 0x002C0E68u: {
            TP_STATIC_GUARD(0x0581CDu, 0xA9u, 0x93u, 0x00u);
            const uint16_t value = 0x0093u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81D0u, 0x002C0E80u, 3u);
        }

        case 0x002C0E80u: {
            TP_STATIC_GUARD(0x0581D0u, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xD3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x002C0EA0u: {
            TP_STATIC_GUARD(0x0581D4u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81D5u, 0x002C0EA8u, 2u);
        }

        case 0x002C0EA8u: {
            TP_STATIC_GUARD(0x0581D5u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81D6u, 0x002C0EB0u, 2u);
        }

        case 0x002C0EB0u: {
            TP_STATIC_GUARD(0x0581D6u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x05u, 0x81D7u, 0x002C0EB8u, 2u);
        }

        case 0x002C0EB8u: {
            TP_STATIC_GUARD(0x0581D7u, 0x6Du, 0x3Au, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x003Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x81DAu, 0x002C0ED0u, 5u);
        }

        case 0x002C0ED0u: {
            TP_STATIC_GUARD(0x0581DAu, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x81DDu, 0x002C0EE8u, 5u);
        }

        case 0x002C0EE8u: {
            TP_STATIC_GUARD(0x0581DDu, 0xBFu, 0x08u, 0x00u, 0x7Fu);
            const uint32_t address = (0x7F0008u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81E1u, 0x002C0F08u, 6u);
        }

        case 0x002C0F08u: {
            TP_STATIC_GUARD(0x0581E1u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x05u, 0x81E3u, 0x002C0F1Au, 3u);
        }

        case 0x002C0F1Au: {
            TP_STATIC_GUARD(0x0581E3u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x05u, 0x81E5u, 0x002C0F2Au, 3u);
        }

        case 0x002C0F2Au: {
            TP_STATIC_GUARD(0x0581E5u, 0xC9u, 0x08u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x08u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81E7u, 0x002C0F3Au, 2u);
        }

        case 0x002C0F3Au: {
            TP_STATIC_GUARD(0x0581E7u, 0xD0u, 0x5Bu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8244u;
                if (tp_scpu_expect_next(cpu, 0x002C1222u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x81E9u, 0x002C0F4Au, 2u);
        }

        case 0x002C0F4Au: {
            TP_STATIC_GUARD(0x0581E9u, 0xBFu, 0x5Au, 0x00u, 0x7Fu);
            const uint32_t address = (0x7F005Au + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81EDu, 0x002C0F6Au, 5u);
        }

        case 0x002C0F6Au: {
            TP_STATIC_GUARD(0x0581EDu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x05u, 0x81EFu, 0x002C0F78u, 3u);
        }

        case 0x002C0F78u: {
            TP_STATIC_GUARD(0x0581EFu, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81F2u, 0x002C0F90u, 3u);
        }

        case 0x002C0F90u: {
            TP_STATIC_GUARD(0x0581F2u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81F3u, 0x002C0F98u, 2u);
        }

        case 0x002C0F98u: {
            TP_STATIC_GUARD(0x0581F3u, 0x22u, 0x63u, 0xC3u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x81u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF6u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC363u, 0x00061B18u, 8u);
        }

        case 0x002C0FB9u: {
            TP_STATIC_GUARD(0x0581F7u, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x81FAu, 0x002C0FD1u, 5u);
        }

        case 0x002C0FD1u: {
            TP_STATIC_GUARD(0x0581FAu, 0x8Eu, 0x66u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0066u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x81FDu, 0x002C0FE9u, 4u);
        }

        case 0x002C0FE9u: {
            TP_STATIC_GUARD(0x0581FDu, 0xA0u, 0x0Au);
            const uint8_t value = 0x0Au;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x81FFu, 0x002C0FF9u, 2u);
        }

        case 0x002C0FF9u: {
            TP_STATIC_GUARD(0x0581FFu, 0xB7u, 0x64u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x64u);
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
            cpu->pbr = 0x05u;
            cpu->pc = 0x8201u;
            if (tp_scpu_expect_next(cpu, 0x002C1009u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
