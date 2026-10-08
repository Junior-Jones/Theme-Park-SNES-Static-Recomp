/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000582(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x002C1009u: {
            TP_STATIC_GUARD(0x058201u, 0xC9u, 0x08u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8204u, 0x002C1021u, 3u);
        }

        case 0x002C1021u: {
            TP_STATIC_GUARD(0x058204u, 0xD0u, 0x3Eu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8244u;
                if (tp_scpu_expect_next(cpu, 0x002C1221u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x8206u, 0x002C1031u, 2u);
        }

        case 0x002C1031u: {
            TP_STATIC_GUARD(0x058206u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x05u, 0x8208u, 0x002C1041u, 3u);
        }

        case 0x002C1041u: {
            TP_STATIC_GUARD(0x058208u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x05u, 0x820Au, 0x002C1051u, 3u);
        }

        case 0x002C1051u: {
            TP_STATIC_GUARD(0x05820Au, 0xAEu, 0x3Cu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x003Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x820Du, 0x002C1069u, 4u);
        }

        case 0x002C1069u: {
            TP_STATIC_GUARD(0x05820Du, 0x8Eu, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0790u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x8210u, 0x002C1081u, 4u);
        }

        case 0x002C1081u: {
            TP_STATIC_GUARD(0x058210u, 0x8Eu, 0x66u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0066u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x8213u, 0x002C1099u, 4u);
        }

        case 0x002C1099u: {
            TP_STATIC_GUARD(0x058213u, 0xADu, 0x8Eu, 0x07u);
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
            TP_STATIC_EXIT(0x05u, 0x8216u, 0x002C10B1u, 5u);
        }

        case 0x002C10B1u: {
            TP_STATIC_GUARD(0x058216u, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x8219u, 0x002C10C9u, 5u);
        }

        case 0x002C10C9u: {
            TP_STATIC_GUARD(0x058219u, 0xA0u, 0x10u);
            const uint8_t value = 0x10u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x821Bu, 0x002C10D9u, 2u);
        }

        case 0x002C10D9u: {
            TP_STATIC_GUARD(0x05821Bu, 0xB7u, 0x64u);
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
            cpu->pc = 0x821Du;
            if (tp_scpu_expect_next(cpu, 0x002C10E9u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x002C10E9u: {
            TP_STATIC_GUARD(0x05821Du, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8220u, 0x002C1101u, 3u);
        }

        case 0x002C1101u: {
            TP_STATIC_GUARD(0x058220u, 0xC9u, 0x08u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8223u, 0x002C1119u, 3u);
        }

        case 0x002C1119u: {
            TP_STATIC_GUARD(0x058223u, 0xD0u, 0x1Fu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8244u;
                if (tp_scpu_expect_next(cpu, 0x002C1221u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x8225u, 0x002C1129u, 2u);
        }

        case 0x002C1129u: {
            TP_STATIC_GUARD(0x058225u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x05u, 0x8227u, 0x002C1139u, 3u);
        }

        case 0x002C1139u: {
            TP_STATIC_GUARD(0x058227u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x05u, 0x8229u, 0x002C1149u, 3u);
        }

        case 0x002C1149u: {
            TP_STATIC_GUARD(0x058229u, 0xADu, 0x49u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0049u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x822Cu, 0x002C1161u, 5u);
        }

        case 0x002C1161u: {
            TP_STATIC_GUARD(0x05822Cu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x822Fu, 0x002C1179u, 5u);
        }

        case 0x002C1179u: {
            TP_STATIC_GUARD(0x05822Fu, 0xAEu, 0x4Bu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x004Bu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8232u, 0x002C1191u, 4u);
        }

        case 0x002C1191u: {
            TP_STATIC_GUARD(0x058232u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x8235u, 0x002C11A9u, 4u);
        }

        case 0x002C11A9u: {
            TP_STATIC_GUARD(0x058235u, 0x22u, 0x48u, 0xE6u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x38u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xE648u, 0x003F3241u, 8u);
        }

        case 0x002C11C9u: {
            TP_STATIC_GUARD(0x058239u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x05u, 0x823Bu, 0x002C11DBu, 3u);
        }

        case 0x002C11DBu: {
            TP_STATIC_GUARD(0x05823Bu, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x823Du, 0x002C11EBu, 2u);
        }

        case 0x002C11EBu: {
            TP_STATIC_GUARD(0x05823Du, 0x22u, 0x9Eu, 0x90u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x40u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x909Eu, 0x006484F3u, 8u);
        }

        case 0x002C120Bu: {
            TP_STATIC_GUARD(0x058241u, 0x82u, 0xC1u, 0x00u);
            TP_STATIC_EXIT(0x05u, 0x8305u, 0x002C182Bu, 4u);
        }

        case 0x002C1220u: {
            TP_STATIC_GUARD(0x058244u, 0x82u, 0xBEu, 0x00u);
            TP_STATIC_EXIT(0x05u, 0x8305u, 0x002C1828u, 4u);
        }

        case 0x002C1221u: {
            TP_STATIC_GUARD(0x058244u, 0x82u, 0xBEu, 0x00u);
            TP_STATIC_EXIT(0x05u, 0x8305u, 0x002C1829u, 4u);
        }

        case 0x002C1222u: {
            TP_STATIC_GUARD(0x058244u, 0x82u, 0xBEu, 0x00u);
            TP_STATIC_EXIT(0x05u, 0x8305u, 0x002C182Au, 4u);
        }

        case 0x002C123Bu: {
            TP_STATIC_GUARD(0x058247u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x05u, 0x8249u, 0x002C124Bu, 3u);
        }

        case 0x002C124Bu: {
            TP_STATIC_GUARD(0x058249u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x05u, 0x824Bu, 0x002C1259u, 3u);
        }

        case 0x002C1259u: {
            TP_STATIC_GUARD(0x05824Bu, 0xADu, 0x49u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0049u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x824Eu, 0x002C1271u, 5u);
        }

        case 0x002C1271u: {
            TP_STATIC_GUARD(0x05824Eu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x05u, 0x824Fu, 0x002C1279u, 2u);
        }

        case 0x002C1279u: {
            TP_STATIC_GUARD(0x05824Fu, 0xEDu, 0x3Au, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x003Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x8252u, 0x002C1291u, 5u);
        }

        case 0x002C1291u: {
            TP_STATIC_GUARD(0x058252u, 0xA2u, 0x93u);
            const uint8_t value = 0x93u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8254u, 0x002C12A1u, 2u);
        }

        case 0x002C12A1u: {
            TP_STATIC_GUARD(0x058254u, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8257u, 0x002C12B9u, 3u);
        }

        case 0x002C12B9u: {
            TP_STATIC_GUARD(0x058257u, 0xF0u, 0x1Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8275u;
                if (tp_scpu_expect_next(cpu, 0x002C13A9u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x8259u, 0x002C12C9u, 2u);
        }

        case 0x002C12C9u: {
            TP_STATIC_GUARD(0x058259u, 0xE0u, 0x00u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x00u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x825Bu, 0x002C12D9u, 2u);
        }

        case 0x002C12D9u: {
            TP_STATIC_GUARD(0x05825Bu, 0xF0u, 0x18u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8275u;
                if (tp_scpu_expect_next(cpu, 0x002C13A9u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x825Du, 0x002C12E9u, 2u);
        }

        case 0x002C12E9u: {
            TP_STATIC_GUARD(0x05825Du, 0x8Du, 0x04u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4204u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x8260u, 0x002C1301u, 5u);
        }

        case 0x002C1301u: {
            TP_STATIC_GUARD(0x058260u, 0x8Eu, 0x06u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4206u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x8263u, 0x002C1319u, 4u);
        }

        case 0x002C1319u: {
            TP_STATIC_GUARD(0x058263u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x8264u, 0x002C1321u, 2u);
        }

        case 0x002C1321u: {
            TP_STATIC_GUARD(0x058264u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x8265u, 0x002C1329u, 2u);
        }

        case 0x002C1329u: {
            TP_STATIC_GUARD(0x058265u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x8266u, 0x002C1331u, 2u);
        }

        case 0x002C1331u: {
            TP_STATIC_GUARD(0x058266u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x8267u, 0x002C1339u, 2u);
        }

        case 0x002C1339u: {
            TP_STATIC_GUARD(0x058267u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x8268u, 0x002C1341u, 2u);
        }

        case 0x002C1341u: {
            TP_STATIC_GUARD(0x058268u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x8269u, 0x002C1349u, 2u);
        }

        case 0x002C1349u: {
            TP_STATIC_GUARD(0x058269u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x826Au, 0x002C1351u, 2u);
        }

        case 0x002C1351u: {
            TP_STATIC_GUARD(0x05826Au, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x826Bu, 0x002C1359u, 2u);
        }

        case 0x002C1359u: {
            TP_STATIC_GUARD(0x05826Bu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x05u, 0x826Du, 0x002C1368u, 3u);
        }

        case 0x002C1368u: {
            TP_STATIC_GUARD(0x05826Du, 0xADu, 0x14u, 0x42u);
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
            TP_STATIC_EXIT(0x05u, 0x8270u, 0x002C1380u, 5u);
        }

        case 0x002C1380u: {
            TP_STATIC_GUARD(0x058270u, 0xAEu, 0x16u, 0x42u);
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
            TP_STATIC_EXIT(0x05u, 0x8273u, 0x002C1398u, 5u);
        }

        case 0x002C1398u: {
            TP_STATIC_GUARD(0x058273u, 0x80u, 0x06u);
            TP_STATIC_EXIT(0x05u, 0x827Bu, 0x002C13D8u, 3u);
        }

        case 0x002C13A9u: {
            TP_STATIC_GUARD(0x058275u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x05u, 0x8277u, 0x002C13B8u, 3u);
        }

        case 0x002C13B8u: {
            TP_STATIC_GUARD(0x058277u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x827Au, 0x002C13D0u, 3u);
        }

        case 0x002C13D0u: {
            TP_STATIC_GUARD(0x05827Au, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x827Bu, 0x002C13D8u, 2u);
        }

        case 0x002C13D8u: {
            TP_STATIC_GUARD(0x05827Bu, 0x8Du, 0x34u, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1434u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x827Eu, 0x002C13F0u, 5u);
        }

        case 0x002C13F0u: {
            TP_STATIC_GUARD(0x05827Eu, 0xA9u, 0x08u, 0x00u);
            const uint16_t value = 0x0008u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x8281u, 0x002C1408u, 3u);
        }

        case 0x002C1408u: {
            TP_STATIC_GUARD(0x058281u, 0x22u, 0x9Eu, 0x90u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x84u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x909Eu, 0x006484F0u, 8u);
        }

        case 0x002C142Bu: {
            TP_STATIC_GUARD(0x058285u, 0x22u, 0x29u, 0x95u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9529u, 0x003CA94Bu, 8u);
        }

        case 0x002C144Bu: {
            TP_STATIC_GUARD(0x058289u, 0x80u, 0x7Au);
            TP_STATIC_EXIT(0x05u, 0x8305u, 0x002C182Bu, 3u);
        }

        case 0x002C145Bu: {
            TP_STATIC_GUARD(0x05828Bu, 0xC9u, 0x0Au);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x0Au;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x828Du, 0x002C146Bu, 2u);
        }

        case 0x002C146Bu: {
            TP_STATIC_GUARD(0x05828Du, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8292u;
                if (tp_scpu_expect_next(cpu, 0x002C1493u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x828Fu, 0x002C147Bu, 2u);
        }

        case 0x002C147Bu: {
            TP_STATIC_GUARD(0x05828Fu, 0x82u, 0x73u, 0x00u);
            TP_STATIC_EXIT(0x05u, 0x8305u, 0x002C182Bu, 4u);
        }

        case 0x002C1493u: {
            TP_STATIC_GUARD(0x058292u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x05u, 0x8294u, 0x002C14A0u, 3u);
        }

        case 0x002C14A0u: {
            TP_STATIC_GUARD(0x058294u, 0xADu, 0x96u, 0x07u);
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
            TP_STATIC_EXIT(0x05u, 0x8297u, 0x002C14B8u, 5u);
        }

        case 0x002C14B8u: {
            TP_STATIC_GUARD(0x058297u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x829Au, 0x002C14D0u, 3u);
        }

        case 0x002C14D0u: {
            TP_STATIC_GUARD(0x05829Au, 0xC9u, 0x06u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0006u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x829Du, 0x002C14E8u, 3u);
        }

        case 0x002C14E8u: {
            TP_STATIC_GUARD(0x05829Du, 0x90u, 0x64u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8303u;
                if (tp_scpu_expect_next(cpu, 0x002C1818u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x829Fu, 0x002C14F8u, 2u);
        }

        case 0x002C14F8u: {
            TP_STATIC_GUARD(0x05829Fu, 0xC9u, 0x09u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0009u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82A2u, 0x002C1510u, 3u);
        }

        case 0x002C1510u: {
            TP_STATIC_GUARD(0x0582A2u, 0xB0u, 0x5Fu);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8303u;
                if (tp_scpu_expect_next(cpu, 0x002C1818u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x82A4u, 0x002C1520u, 2u);
        }

        case 0x002C1520u: {
            TP_STATIC_GUARD(0x0582A4u, 0xADu, 0x9Au, 0x07u);
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
            TP_STATIC_EXIT(0x05u, 0x82A7u, 0x002C1538u, 5u);
        }

        case 0x002C1538u: {
            TP_STATIC_GUARD(0x0582A7u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82AAu, 0x002C1550u, 3u);
        }

        case 0x002C1550u: {
            TP_STATIC_GUARD(0x0582AAu, 0xC9u, 0x07u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0007u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82ADu, 0x002C1568u, 3u);
        }

        case 0x002C1568u: {
            TP_STATIC_GUARD(0x0582ADu, 0x90u, 0x54u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8303u;
                if (tp_scpu_expect_next(cpu, 0x002C1818u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x82AFu, 0x002C1578u, 2u);
        }

        case 0x002C1578u: {
            TP_STATIC_GUARD(0x0582AFu, 0xC9u, 0x09u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0009u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82B2u, 0x002C1590u, 3u);
        }

        case 0x002C1590u: {
            TP_STATIC_GUARD(0x0582B2u, 0xB0u, 0x4Fu);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8303u;
                if (tp_scpu_expect_next(cpu, 0x002C1818u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x82B4u, 0x002C15A0u, 2u);
        }

        case 0x002C15A0u: {
            TP_STATIC_GUARD(0x0582B4u, 0xADu, 0x0Au, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x080Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82B7u, 0x002C15B8u, 5u);
        }

        case 0x002C15B8u: {
            TP_STATIC_GUARD(0x0582B7u, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82BAu, 0x002C15D0u, 3u);
        }

        case 0x002C15D0u: {
            TP_STATIC_GUARD(0x0582BAu, 0xF0u, 0x05u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x82C1u;
                if (tp_scpu_expect_next(cpu, 0x002C1608u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x82BCu, 0x002C15E0u, 2u);
        }

        case 0x002C15E0u: {
            TP_STATIC_GUARD(0x0582BCu, 0xC9u, 0x08u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82BFu, 0x002C15F8u, 3u);
        }

        case 0x002C15F8u: {
            TP_STATIC_GUARD(0x0582BFu, 0xD0u, 0x42u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x8303u;
                if (tp_scpu_expect_next(cpu, 0x002C1818u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x82C1u, 0x002C1608u, 2u);
        }

        case 0x002C1608u: {
            TP_STATIC_GUARD(0x0582C1u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x05u, 0x82C3u, 0x002C1619u, 3u);
        }

        case 0x002C1619u: {
            TP_STATIC_GUARD(0x0582C3u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x05u, 0x82C5u, 0x002C1629u, 3u);
        }

        case 0x002C1629u: {
            TP_STATIC_GUARD(0x0582C5u, 0xADu, 0x49u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0049u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82C8u, 0x002C1641u, 5u);
        }

        case 0x002C1641u: {
            TP_STATIC_GUARD(0x0582C8u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x05u, 0x82C9u, 0x002C1649u, 2u);
        }

        case 0x002C1649u: {
            TP_STATIC_GUARD(0x0582C9u, 0xEDu, 0x3Au, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x003Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x82CCu, 0x002C1661u, 5u);
        }

        case 0x002C1661u: {
            TP_STATIC_GUARD(0x0582CCu, 0xA2u, 0x93u);
            const uint8_t value = 0x93u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82CEu, 0x002C1671u, 2u);
        }

        case 0x002C1671u: {
            TP_STATIC_GUARD(0x0582CEu, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82D1u, 0x002C1689u, 3u);
        }

        case 0x002C1689u: {
            TP_STATIC_GUARD(0x0582D1u, 0xF0u, 0x1Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x82EFu;
                if (tp_scpu_expect_next(cpu, 0x002C1779u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x82D3u, 0x002C1699u, 2u);
        }

        case 0x002C1699u: {
            TP_STATIC_GUARD(0x0582D3u, 0xE0u, 0x00u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x00u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82D5u, 0x002C16A9u, 2u);
        }

        case 0x002C16A9u: {
            TP_STATIC_GUARD(0x0582D5u, 0xF0u, 0x18u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x05u;
                cpu->pc = 0x82EFu;
                if (tp_scpu_expect_next(cpu, 0x002C1779u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x05u, 0x82D7u, 0x002C16B9u, 2u);
        }

        case 0x002C16B9u: {
            TP_STATIC_GUARD(0x0582D7u, 0x8Du, 0x04u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4204u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x82DAu, 0x002C16D1u, 5u);
        }

        case 0x002C16D1u: {
            TP_STATIC_GUARD(0x0582DAu, 0x8Eu, 0x06u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4206u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x82DDu, 0x002C16E9u, 4u);
        }

        case 0x002C16E9u: {
            TP_STATIC_GUARD(0x0582DDu, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x82DEu, 0x002C16F1u, 2u);
        }

        case 0x002C16F1u: {
            TP_STATIC_GUARD(0x0582DEu, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x82DFu, 0x002C16F9u, 2u);
        }

        case 0x002C16F9u: {
            TP_STATIC_GUARD(0x0582DFu, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x82E0u, 0x002C1701u, 2u);
        }

        case 0x002C1701u: {
            TP_STATIC_GUARD(0x0582E0u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x82E1u, 0x002C1709u, 2u);
        }

        case 0x002C1709u: {
            TP_STATIC_GUARD(0x0582E1u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x82E2u, 0x002C1711u, 2u);
        }

        case 0x002C1711u: {
            TP_STATIC_GUARD(0x0582E2u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x82E3u, 0x002C1719u, 2u);
        }

        case 0x002C1719u: {
            TP_STATIC_GUARD(0x0582E3u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x82E4u, 0x002C1721u, 2u);
        }

        case 0x002C1721u: {
            TP_STATIC_GUARD(0x0582E4u, 0xEAu);
            TP_STATIC_EXIT(0x05u, 0x82E5u, 0x002C1729u, 2u);
        }

        case 0x002C1729u: {
            TP_STATIC_GUARD(0x0582E5u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x05u, 0x82E7u, 0x002C1738u, 3u);
        }

        case 0x002C1738u: {
            TP_STATIC_GUARD(0x0582E7u, 0xADu, 0x14u, 0x42u);
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
            TP_STATIC_EXIT(0x05u, 0x82EAu, 0x002C1750u, 5u);
        }

        case 0x002C1750u: {
            TP_STATIC_GUARD(0x0582EAu, 0xAEu, 0x16u, 0x42u);
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
            TP_STATIC_EXIT(0x05u, 0x82EDu, 0x002C1768u, 5u);
        }

        case 0x002C1768u: {
            TP_STATIC_GUARD(0x0582EDu, 0x80u, 0x06u);
            TP_STATIC_EXIT(0x05u, 0x82F5u, 0x002C17A8u, 3u);
        }

        case 0x002C1779u: {
            TP_STATIC_GUARD(0x0582EFu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x05u, 0x82F1u, 0x002C1788u, 3u);
        }

        case 0x002C1788u: {
            TP_STATIC_GUARD(0x0582F1u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82F4u, 0x002C17A0u, 3u);
        }

        case 0x002C17A0u: {
            TP_STATIC_GUARD(0x0582F4u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82F5u, 0x002C17A8u, 2u);
        }

        case 0x002C17A8u: {
            TP_STATIC_GUARD(0x0582F5u, 0x8Du, 0x34u, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1434u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x05u, 0x82F8u, 0x002C17C0u, 5u);
        }

        case 0x002C17C0u: {
            TP_STATIC_GUARD(0x0582F8u, 0xA9u, 0x08u, 0x00u);
            const uint16_t value = 0x0008u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x05u, 0x82FBu, 0x002C17D8u, 3u);
        }

        case 0x002C17D8u: {
            TP_STATIC_GUARD(0x0582FBu, 0x22u, 0x9Eu, 0x90u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x82u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xFEu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x909Eu, 0x006484F0u, 8u);
        }

        case 0x002C17FBu: {
            TP_STATIC_GUARD(0x0582FFu, 0x22u, 0x29u, 0x95u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x83u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x02u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9529u, 0x003CA94Bu, 8u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
