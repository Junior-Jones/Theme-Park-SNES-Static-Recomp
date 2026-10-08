/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0004AD(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00256809u: {
            TP_STATIC_GUARD(0x04AD01u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0xAD03u, 0x00256819u, 3u);
        }

        case 0x00256819u: {
            TP_STATIC_GUARD(0x04AD03u, 0xAEu, 0xD1u, 0x06u);
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
            TP_STATIC_EXIT(0x04u, 0xAD06u, 0x00256831u, 4u);
        }

        case 0x00256831u: {
            TP_STATIC_GUARD(0x04AD06u, 0x8Eu, 0x94u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0794u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xAD09u, 0x00256849u, 4u);
        }

        case 0x00256849u: {
            TP_STATIC_GUARD(0x04AD09u, 0x22u, 0xD6u, 0xD8u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xADu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Cu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xD8D6u, 0x0026C6B1u, 8u);
        }

        case 0x00256868u: {
            TP_STATIC_GUARD(0x04AD0Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xAD0Fu, 0x00256878u, 3u);
        }

        case 0x00256878u: {
            TP_STATIC_GUARD(0x04AD0Fu, 0xADu, 0xA2u, 0x07u);
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
            TP_STATIC_EXIT(0x04u, 0xAD12u, 0x00256890u, 5u);
        }

        case 0x00256890u: {
            TP_STATIC_GUARD(0x04AD12u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD13u, 0x00256898u, 3u);
        }

        case 0x00256898u: {
            TP_STATIC_GUARD(0x04AD13u, 0x8Du, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07A2u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xAD16u, 0x002568B0u, 5u);
        }

        case 0x002568B0u: {
            TP_STATIC_GUARD(0x04AD16u, 0xA9u, 0x19u, 0x00u);
            const uint16_t value = 0x0019u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD19u, 0x002568C8u, 3u);
        }

        case 0x002568C8u: {
            TP_STATIC_GUARD(0x04AD19u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xAD1Au, 0x002568D0u, 2u);
        }

        case 0x002568D0u: {
            TP_STATIC_GUARD(0x04AD1Au, 0xEDu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xAD1Du, 0x002568E8u, 5u);
        }

        case 0x002568E8u: {
            TP_STATIC_GUARD(0x04AD1Du, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD1Eu, 0x002568F0u, 3u);
        }

        case 0x002568F0u: {
            TP_STATIC_GUARD(0x04AD1Eu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xAD21u, 0x00256908u, 5u);
        }

        case 0x00256908u: {
            TP_STATIC_GUARD(0x04AD21u, 0xA9u, 0x16u, 0x00u);
            const uint16_t value = 0x0016u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD24u, 0x00256920u, 3u);
        }

        case 0x00256920u: {
            TP_STATIC_GUARD(0x04AD24u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xAD27u, 0x00256938u, 5u);
        }

        case 0x00256938u: {
            TP_STATIC_GUARD(0x04AD27u, 0x22u, 0x3Cu, 0xA3u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xADu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x2Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA33Cu, 0x003519E0u, 8u);
        }

        case 0x00256958u: {
            TP_STATIC_GUARD(0x04AD2Bu, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xAD2Du, 0x0025696Au, 3u);
        }

        case 0x0025696Au: {
            TP_STATIC_GUARD(0x04AD2Du, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x04u, 0xAD2Fu, 0x0025697Au, 3u);
        }

        case 0x0025697Au: {
            TP_STATIC_GUARD(0x04AD2Fu, 0xA0u, 0x1Au, 0x00u);
            const uint16_t value = 0x001Au;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD32u, 0x00256992u, 3u);
        }

        case 0x00256992u: {
            TP_STATIC_GUARD(0x04AD32u, 0xB7u, 0x1Cu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x1Cu);
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
            cpu->pbr = 0x04u;
            cpu->pc = 0xAD34u;
            if (tp_scpu_expect_next(cpu, 0x002569A2u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x002569A2u: {
            TP_STATIC_GUARD(0x04AD34u, 0xC9u, 0x00u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x00u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD36u, 0x002569B2u, 2u);
        }

        case 0x002569B2u: {
            TP_STATIC_GUARD(0x04AD36u, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xAD3Eu;
                if (tp_scpu_expect_next(cpu, 0x002569F2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xAD38u, 0x002569C2u, 2u);
        }

        case 0x002569C2u: {
            TP_STATIC_GUARD(0x04AD38u, 0xA0u, 0xDCu, 0x00u);
            const uint16_t value = 0x00DCu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD3Bu, 0x002569DAu, 3u);
        }

        case 0x002569DAu: {
            TP_STATIC_GUARD(0x04AD3Bu, 0x82u, 0x35u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xAD73u, 0x00256B9Au, 4u);
        }

        case 0x002569F2u: {
            TP_STATIC_GUARD(0x04AD3Eu, 0xC9u, 0x01u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x01u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD40u, 0x00256A02u, 2u);
        }

        case 0x00256A02u: {
            TP_STATIC_GUARD(0x04AD40u, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xAD48u;
                if (tp_scpu_expect_next(cpu, 0x00256A42u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xAD42u, 0x00256A12u, 2u);
        }

        case 0x00256A12u: {
            TP_STATIC_GUARD(0x04AD42u, 0xA0u, 0xDDu, 0x00u);
            const uint16_t value = 0x00DDu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD45u, 0x00256A2Au, 3u);
        }

        case 0x00256A2Au: {
            TP_STATIC_GUARD(0x04AD45u, 0x82u, 0x2Bu, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xAD73u, 0x00256B9Au, 4u);
        }

        case 0x00256A42u: {
            TP_STATIC_GUARD(0x04AD48u, 0xC9u, 0x02u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x02u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD4Au, 0x00256A52u, 2u);
        }

        case 0x00256A52u: {
            TP_STATIC_GUARD(0x04AD4Au, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xAD52u;
                if (tp_scpu_expect_next(cpu, 0x00256A92u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xAD4Cu, 0x00256A62u, 2u);
        }

        case 0x00256A62u: {
            TP_STATIC_GUARD(0x04AD4Cu, 0xA0u, 0xDEu, 0x00u);
            const uint16_t value = 0x00DEu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD4Fu, 0x00256A7Au, 3u);
        }

        case 0x00256A7Au: {
            TP_STATIC_GUARD(0x04AD4Fu, 0x82u, 0x21u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xAD73u, 0x00256B9Au, 4u);
        }

        case 0x00256A92u: {
            TP_STATIC_GUARD(0x04AD52u, 0xC9u, 0x03u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x03u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD54u, 0x00256AA2u, 2u);
        }

        case 0x00256AA2u: {
            TP_STATIC_GUARD(0x04AD54u, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xAD5Cu;
                if (tp_scpu_expect_next(cpu, 0x00256AE2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xAD56u, 0x00256AB2u, 2u);
        }

        case 0x00256AB2u: {
            TP_STATIC_GUARD(0x04AD56u, 0xA0u, 0xDFu, 0x00u);
            const uint16_t value = 0x00DFu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD59u, 0x00256ACAu, 3u);
        }

        case 0x00256ACAu: {
            TP_STATIC_GUARD(0x04AD59u, 0x82u, 0x17u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xAD73u, 0x00256B9Au, 4u);
        }

        case 0x00256AE2u: {
            TP_STATIC_GUARD(0x04AD5Cu, 0xC9u, 0x04u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x04u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD5Eu, 0x00256AF2u, 2u);
        }

        case 0x00256AF2u: {
            TP_STATIC_GUARD(0x04AD5Eu, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xAD66u;
                if (tp_scpu_expect_next(cpu, 0x00256B32u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xAD60u, 0x00256B02u, 2u);
        }

        case 0x00256B02u: {
            TP_STATIC_GUARD(0x04AD60u, 0xA0u, 0xE0u, 0x00u);
            const uint16_t value = 0x00E0u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD63u, 0x00256B1Au, 3u);
        }

        case 0x00256B1Au: {
            TP_STATIC_GUARD(0x04AD63u, 0x82u, 0x0Du, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xAD73u, 0x00256B9Au, 4u);
        }

        case 0x00256B32u: {
            TP_STATIC_GUARD(0x04AD66u, 0xC9u, 0x05u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x05u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD68u, 0x00256B42u, 2u);
        }

        case 0x00256B42u: {
            TP_STATIC_GUARD(0x04AD68u, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xAD70u;
                if (tp_scpu_expect_next(cpu, 0x00256B82u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xAD6Au, 0x00256B52u, 2u);
        }

        case 0x00256B52u: {
            TP_STATIC_GUARD(0x04AD6Au, 0xA0u, 0xE1u, 0x00u);
            const uint16_t value = 0x00E1u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD6Du, 0x00256B6Au, 3u);
        }

        case 0x00256B6Au: {
            TP_STATIC_GUARD(0x04AD6Du, 0x82u, 0x03u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xAD73u, 0x00256B9Au, 4u);
        }

        case 0x00256B82u: {
            TP_STATIC_GUARD(0x04AD70u, 0xA0u, 0x1Du, 0x01u);
            const uint16_t value = 0x011Du;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD73u, 0x00256B9Au, 3u);
        }

        case 0x00256B9Au: {
            TP_STATIC_GUARD(0x04AD73u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xAD75u, 0x00256BA8u, 3u);
        }

        case 0x00256BA8u: {
            TP_STATIC_GUARD(0x04AD75u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD76u, 0x00256BB0u, 2u);
        }

        case 0x00256BB0u: {
            TP_STATIC_GUARD(0x04AD76u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD77u, 0x00256BB8u, 3u);
        }

        case 0x00256BB8u: {
            TP_STATIC_GUARD(0x04AD77u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD78u, 0x00256BC0u, 2u);
        }

        case 0x00256BC0u: {
            TP_STATIC_GUARD(0x04AD78u, 0xB7u, 0x22u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x22u);
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
            cpu->pbr = 0x04u;
            cpu->pc = 0xAD7Au;
            if (tp_scpu_expect_next(cpu, 0x00256BD0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00256BD0u: {
            TP_STATIC_GUARD(0x04AD7Au, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xAD7Du, 0x00256BE8u, 5u);
        }

        case 0x00256BE8u: {
            TP_STATIC_GUARD(0x04AD7Du, 0xAEu, 0xD1u, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06D1u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD80u, 0x00256C00u, 5u);
        }

        case 0x00256C00u: {
            TP_STATIC_GUARD(0x04AD80u, 0x8Eu, 0x94u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0794u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xAD83u, 0x00256C18u, 5u);
        }

        case 0x00256C18u: {
            TP_STATIC_GUARD(0x04AD83u, 0xADu, 0xA2u, 0x07u);
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
            TP_STATIC_EXIT(0x04u, 0xAD86u, 0x00256C30u, 5u);
        }

        case 0x00256C30u: {
            TP_STATIC_GUARD(0x04AD86u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD87u, 0x00256C38u, 3u);
        }

        case 0x00256C38u: {
            TP_STATIC_GUARD(0x04AD87u, 0x8Du, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07A2u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xAD8Au, 0x00256C50u, 5u);
        }

        case 0x00256C50u: {
            TP_STATIC_GUARD(0x04AD8Au, 0xA9u, 0x0Fu, 0x00u);
            const uint16_t value = 0x000Fu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD8Du, 0x00256C68u, 3u);
        }

        case 0x00256C68u: {
            TP_STATIC_GUARD(0x04AD8Du, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xAD8Eu, 0x00256C70u, 2u);
        }

        case 0x00256C70u: {
            TP_STATIC_GUARD(0x04AD8Eu, 0xEDu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xAD91u, 0x00256C88u, 5u);
        }

        case 0x00256C88u: {
            TP_STATIC_GUARD(0x04AD91u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD92u, 0x00256C90u, 3u);
        }

        case 0x00256C90u: {
            TP_STATIC_GUARD(0x04AD92u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xAD95u, 0x00256CA8u, 5u);
        }

        case 0x00256CA8u: {
            TP_STATIC_GUARD(0x04AD95u, 0xA9u, 0x16u, 0x00u);
            const uint16_t value = 0x0016u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD98u, 0x00256CC0u, 3u);
        }

        case 0x00256CC0u: {
            TP_STATIC_GUARD(0x04AD98u, 0x1Au);
            cpu->a = (uint16_t)(cpu->a + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAD99u, 0x00256CC8u, 3u);
        }

        case 0x00256CC8u: {
            TP_STATIC_GUARD(0x04AD99u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xAD9Cu, 0x00256CE0u, 5u);
        }

        case 0x00256CE0u: {
            TP_STATIC_GUARD(0x04AD9Cu, 0x82u, 0x13u, 0x05u);
            TP_STATIC_EXIT(0x04u, 0xB2B2u, 0x00259590u, 4u);
        }

        case 0x00256CF9u: {
            TP_STATIC_GUARD(0x04AD9Fu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xADA1u, 0x00256D09u, 3u);
        }

        case 0x00256D09u: {
            TP_STATIC_GUARD(0x04ADA1u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0xADA3u, 0x00256D19u, 3u);
        }

        case 0x00256D19u: {
            TP_STATIC_GUARD(0x04ADA3u, 0xC9u, 0x87u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0087u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xADA6u, 0x00256D31u, 3u);
        }

        case 0x00256D31u: {
            TP_STATIC_GUARD(0x04ADA6u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xADABu;
                if (tp_scpu_expect_next(cpu, 0x00256D59u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xADA8u, 0x00256D41u, 2u);
        }

        case 0x00256D41u: {
            TP_STATIC_GUARD(0x04ADA8u, 0x82u, 0x8Au, 0x02u);
            TP_STATIC_EXIT(0x04u, 0xB035u, 0x002581A9u, 4u);
        }

        case 0x00256D59u: {
            TP_STATIC_GUARD(0x04ADABu, 0x22u, 0x9Fu, 0xC4u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xADu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xAEu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xC49Fu, 0x006624F9u, 8u);
        }

        case 0x00256D78u: {
            TP_STATIC_GUARD(0x04ADAFu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xADB1u, 0x00256D89u, 3u);
        }

        case 0x00256D89u: {
            TP_STATIC_GUARD(0x04ADB1u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0xADB3u, 0x00256D99u, 3u);
        }

        case 0x00256D99u: {
            TP_STATIC_GUARD(0x04ADB3u, 0xA0u, 0x1Au);
            const uint8_t value = 0x1Au;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xADB5u, 0x00256DA9u, 2u);
        }

        case 0x00256DA9u: {
            TP_STATIC_GUARD(0x04ADB5u, 0xB7u, 0x49u);
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
            cpu->pbr = 0x04u;
            cpu->pc = 0xADB7u;
            if (tp_scpu_expect_next(cpu, 0x00256DB9u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00256DB9u: {
            TP_STATIC_GUARD(0x04ADB7u, 0x22u, 0x50u, 0xC3u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xADu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBAu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC350u, 0x00061A81u, 8u);
        }

        case 0x00256DD9u: {
            TP_STATIC_GUARD(0x04ADBBu, 0x8Du, 0x1Cu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x001Cu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xADBEu, 0x00256DF1u, 5u);
        }

        case 0x00256DF1u: {
            TP_STATIC_GUARD(0x04ADBEu, 0x8Eu, 0x1Eu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x001Eu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xADC1u, 0x00256E09u, 4u);
        }

        case 0x00256E09u: {
            TP_STATIC_GUARD(0x04ADC1u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xADC3u, 0x00256E18u, 3u);
        }

        case 0x00256E18u: {
            TP_STATIC_GUARD(0x04ADC3u, 0xA9u, 0x99u, 0x00u);
            const uint16_t value = 0x0099u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xADC6u, 0x00256E30u, 3u);
        }

        case 0x00256E30u: {
            TP_STATIC_GUARD(0x04ADC6u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xADC9u, 0x00256E48u, 5u);
        }

        case 0x00256E48u: {
            TP_STATIC_GUARD(0x04ADC9u, 0x22u, 0x8Au, 0x8Au, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xADu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCCu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0x8A8Au, 0x00345450u, 8u);
        }

        case 0x00256E68u: {
            TP_STATIC_GUARD(0x04ADCDu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xADCFu, 0x00256E79u, 3u);
        }

        case 0x00256E79u: {
            TP_STATIC_GUARD(0x04ADCFu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0xADD1u, 0x00256E89u, 3u);
        }

        case 0x00256E89u: {
            TP_STATIC_GUARD(0x04ADD1u, 0xADu, 0xA2u, 0x07u);
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
            TP_STATIC_EXIT(0x04u, 0xADD4u, 0x00256EA1u, 5u);
        }

        case 0x00256EA1u: {
            TP_STATIC_GUARD(0x04ADD4u, 0xAEu, 0xA4u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A4u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xADD7u, 0x00256EB9u, 4u);
        }

        case 0x00256EB9u: {
            TP_STATIC_GUARD(0x04ADD7u, 0x8Du, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0016u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xADDAu, 0x00256ED1u, 5u);
        }

        case 0x00256ED1u: {
            TP_STATIC_GUARD(0x04ADDAu, 0x8Eu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xADDDu, 0x00256EE9u, 4u);
        }

        case 0x00256EE9u: {
            TP_STATIC_GUARD(0x04ADDDu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xADDFu, 0x00256EF8u, 3u);
        }

        case 0x00256EF8u: {
            TP_STATIC_GUARD(0x04ADDFu, 0xA0u, 0x25u, 0x00u);
            const uint16_t value = 0x0025u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xADE2u, 0x00256F10u, 3u);
        }

        case 0x00256F10u: {
            TP_STATIC_GUARD(0x04ADE2u, 0xB7u, 0x1Cu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x1Cu);
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
            cpu->pbr = 0x04u;
            cpu->pc = 0xADE4u;
            if (tp_scpu_expect_next(cpu, 0x00256F20u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00256F20u: {
            TP_STATIC_GUARD(0x04ADE4u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xADE7u, 0x00256F38u, 3u);
        }

        case 0x00256F38u: {
            TP_STATIC_GUARD(0x04ADE7u, 0xA2u, 0x0Au, 0x00u);
            const uint16_t value = 0x000Au;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xADEAu, 0x00256F50u, 3u);
        }

        case 0x00256F50u: {
            TP_STATIC_GUARD(0x04ADEAu, 0x22u, 0x9Eu, 0xA5u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xADu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEDu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA59Eu, 0x00352CF0u, 8u);
        }

        case 0x00256F70u: {
            TP_STATIC_GUARD(0x04ADEEu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xADF1u, 0x00256F88u, 5u);
        }

        case 0x00256F88u: {
            TP_STATIC_GUARD(0x04ADF1u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xADF2u, 0x00256F90u, 3u);
        }

        case 0x00256F90u: {
            TP_STATIC_GUARD(0x04ADF2u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xADF3u, 0x00256F98u, 2u);
        }

        case 0x00256F98u: {
            TP_STATIC_GUARD(0x04ADF3u, 0xADu, 0xDEu, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06DEu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xADF6u, 0x00256FB0u, 5u);
        }

        case 0x00256FB0u: {
            TP_STATIC_GUARD(0x04ADF6u, 0x8Du, 0x22u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0022u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xADF9u, 0x00256FC8u, 5u);
        }

        case 0x00256FC8u: {
            TP_STATIC_GUARD(0x04ADF9u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xADFBu, 0x00256FDAu, 3u);
        }

        case 0x00256FDAu: {
            TP_STATIC_GUARD(0x04ADFBu, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x04u, 0xADFDu, 0x00256FEAu, 3u);
        }

        case 0x00256FEAu: {
            TP_STATIC_GUARD(0x04ADFDu, 0xADu, 0xE0u, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06E0u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xAE00u, 0x00257002u, 4u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
