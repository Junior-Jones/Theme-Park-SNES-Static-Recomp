/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0007FE(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x003FF009u: {
            TP_STATIC_GUARD(0x07FE01u, 0xB7u, 0x16u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xFE03u;
            if (tp_scpu_expect_next(cpu, 0x003FF019u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF019u: {
            TP_STATIC_GUARD(0x07FE03u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE04u, 0x003FF021u, 3u);
        }

        case 0x003FF021u: {
            TP_STATIC_GUARD(0x07FE04u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE05u, 0x003FF029u, 3u);
        }

        case 0x003FF029u: {
            TP_STATIC_GUARD(0x07FE05u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE06u, 0x003FF031u, 3u);
        }

        case 0x003FF031u: {
            TP_STATIC_GUARD(0x07FE06u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE07u, 0x003FF039u, 3u);
        }

        case 0x003FF039u: {
            TP_STATIC_GUARD(0x07FE07u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE08u, 0x003FF041u, 3u);
        }

        case 0x003FF041u: {
            TP_STATIC_GUARD(0x07FE08u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE09u, 0x003FF049u, 3u);
        }

        case 0x003FF049u: {
            TP_STATIC_GUARD(0x07FE09u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE0Au, 0x003FF051u, 3u);
        }

        case 0x003FF051u: {
            TP_STATIC_GUARD(0x07FE0Au, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE0Du, 0x003FF069u, 5u);
        }

        case 0x003FF069u: {
            TP_STATIC_GUARD(0x07FE0Du, 0xA9u, 0x20u, 0x00u);
            const uint16_t value = 0x0020u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE10u, 0x003FF081u, 3u);
        }

        case 0x003FF081u: {
            TP_STATIC_GUARD(0x07FE10u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xFE11u, 0x003FF089u, 2u);
        }

        case 0x003FF089u: {
            TP_STATIC_GUARD(0x07FE11u, 0xEDu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE14u, 0x003FF0A1u, 5u);
        }

        case 0x003FF0A1u: {
            TP_STATIC_GUARD(0x07FE14u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE17u, 0x003FF0B9u, 5u);
        }

        case 0x003FF0B9u: {
            TP_STATIC_GUARD(0x07FE17u, 0xA0u, 0x72u);
            const uint8_t value = 0x72u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE19u, 0x003FF0C9u, 2u);
        }

        case 0x003FF0C9u: {
            TP_STATIC_GUARD(0x07FE19u, 0xB7u, 0x16u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xFE1Bu;
            if (tp_scpu_expect_next(cpu, 0x003FF0D9u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF0D9u: {
            TP_STATIC_GUARD(0x07FE1Bu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xFE1Cu, 0x003FF0E1u, 2u);
        }

        case 0x003FF0E1u: {
            TP_STATIC_GUARD(0x07FE1Cu, 0x6Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE1Fu, 0x003FF0F9u, 5u);
        }

        case 0x003FF0F9u: {
            TP_STATIC_GUARD(0x07FE1Fu, 0x97u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x07u;
            cpu->pc = 0xFE21u;
            if (tp_scpu_expect_next(cpu, 0x003FF109u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF109u: {
            TP_STATIC_GUARD(0x07FE21u, 0x22u, 0xDAu, 0x87u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xFEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x24u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x87DAu, 0x003C3ED1u, 8u);
        }

        case 0x003FF129u: {
            TP_STATIC_GUARD(0x07FE25u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xFE27u, 0x003FF139u, 3u);
        }

        case 0x003FF139u: {
            TP_STATIC_GUARD(0x07FE27u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x07u, 0xFE29u, 0x003FF149u, 3u);
        }

        case 0x003FF149u: {
            TP_STATIC_GUARD(0x07FE29u, 0x29u, 0x07u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0007u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE2Cu, 0x003FF161u, 3u);
        }

        case 0x003FF161u: {
            TP_STATIC_GUARD(0x07FE2Cu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE2Fu, 0x003FF179u, 5u);
        }

        case 0x003FF179u: {
            TP_STATIC_GUARD(0x07FE2Fu, 0xA9u, 0x04u, 0x00u);
            const uint16_t value = 0x0004u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE32u, 0x003FF191u, 3u);
        }

        case 0x003FF191u: {
            TP_STATIC_GUARD(0x07FE32u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xFE33u, 0x003FF199u, 2u);
        }

        case 0x003FF199u: {
            TP_STATIC_GUARD(0x07FE33u, 0xEDu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE36u, 0x003FF1B1u, 5u);
        }

        case 0x003FF1B1u: {
            TP_STATIC_GUARD(0x07FE36u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE39u, 0x003FF1C9u, 5u);
        }

        case 0x003FF1C9u: {
            TP_STATIC_GUARD(0x07FE39u, 0xA0u, 0x72u);
            const uint8_t value = 0x72u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE3Bu, 0x003FF1D9u, 2u);
        }

        case 0x003FF1D9u: {
            TP_STATIC_GUARD(0x07FE3Bu, 0xB7u, 0x16u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xFE3Du;
            if (tp_scpu_expect_next(cpu, 0x003FF1E9u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF1E9u: {
            TP_STATIC_GUARD(0x07FE3Du, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xFE3Eu, 0x003FF1F1u, 2u);
        }

        case 0x003FF1F1u: {
            TP_STATIC_GUARD(0x07FE3Eu, 0xEDu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE41u, 0x003FF209u, 5u);
        }

        case 0x003FF209u: {
            TP_STATIC_GUARD(0x07FE41u, 0x97u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x07u;
            cpu->pc = 0xFE43u;
            if (tp_scpu_expect_next(cpu, 0x003FF219u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF219u: {
            TP_STATIC_GUARD(0x07FE43u, 0xA0u, 0x82u);
            const uint8_t value = 0x82u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE45u, 0x003FF229u, 2u);
        }

        case 0x003FF229u: {
            TP_STATIC_GUARD(0x07FE45u, 0xB7u, 0x16u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xFE47u;
            if (tp_scpu_expect_next(cpu, 0x003FF239u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF239u: {
            TP_STATIC_GUARD(0x07FE47u, 0x29u, 0x03u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0003u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE4Au, 0x003FF251u, 3u);
        }

        case 0x003FF251u: {
            TP_STATIC_GUARD(0x07FE4Au, 0xD0u, 0x0Eu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xFE5Au;
                if (tp_scpu_expect_next(cpu, 0x003FF2D1u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xFE4Cu, 0x003FF261u, 2u);
        }

        case 0x003FF261u: {
            TP_STATIC_GUARD(0x07FE4Cu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xFE4Eu, 0x003FF271u, 3u);
        }

        case 0x003FF271u: {
            TP_STATIC_GUARD(0x07FE4Eu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x07u, 0xFE50u, 0x003FF281u, 3u);
        }

        case 0x003FF281u: {
            TP_STATIC_GUARD(0x07FE50u, 0xADu, 0x0Bu, 0x04u);
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
            TP_STATIC_EXIT(0x07u, 0xFE53u, 0x003FF299u, 5u);
        }

        case 0x003FF299u: {
            TP_STATIC_GUARD(0x07FE53u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xFE54u, 0x003FF2A1u, 2u);
        }

        case 0x003FF2A1u: {
            TP_STATIC_GUARD(0x07FE54u, 0x6Du, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE57u, 0x003FF2B9u, 5u);
        }

        case 0x003FF2B9u: {
            TP_STATIC_GUARD(0x07FE57u, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE5Au, 0x003FF2D1u, 5u);
        }

        case 0x003FF2D1u: {
            TP_STATIC_GUARD(0x07FE5Au, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xFE5Cu, 0x003FF2E3u, 3u);
        }

        case 0x003FF2D3u: {
            TP_STATIC_GUARD(0x07FE5Au, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xFE5Cu, 0x003FF2E3u, 3u);
        }

        case 0x003FF2E3u: {
            TP_STATIC_GUARD(0x07FE5Cu, 0xA0u, 0x10u);
            const uint8_t value = 0x10u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE5Eu, 0x003FF2F3u, 2u);
        }

        case 0x003FF2F3u: {
            TP_STATIC_GUARD(0x07FE5Eu, 0xB7u, 0x16u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xFE60u;
            if (tp_scpu_expect_next(cpu, 0x003FF303u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF303u: {
            TP_STATIC_GUARD(0x07FE60u, 0xC9u, 0x06u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x06u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE62u, 0x003FF313u, 2u);
        }

        case 0x003FF313u: {
            TP_STATIC_GUARD(0x07FE62u, 0xD0u, 0x59u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xFEBDu;
                if (tp_scpu_expect_next(cpu, 0x003FF5EBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xFE64u, 0x003FF323u, 2u);
        }

        case 0x003FF323u: {
            TP_STATIC_GUARD(0x07FE64u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xFE66u, 0x003FF333u, 3u);
        }

        case 0x003FF333u: {
            TP_STATIC_GUARD(0x07FE66u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x07u, 0xFE68u, 0x003FF341u, 3u);
        }

        case 0x003FF341u: {
            TP_STATIC_GUARD(0x07FE68u, 0xA0u, 0x55u);
            const uint8_t value = 0x55u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE6Au, 0x003FF351u, 2u);
        }

        case 0x003FF351u: {
            TP_STATIC_GUARD(0x07FE6Au, 0xB7u, 0x16u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xFE6Cu;
            if (tp_scpu_expect_next(cpu, 0x003FF361u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF361u: {
            TP_STATIC_GUARD(0x07FE6Cu, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE6Du, 0x003FF369u, 3u);
        }

        case 0x003FF369u: {
            TP_STATIC_GUARD(0x07FE6Du, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE6Eu, 0x003FF371u, 3u);
        }

        case 0x003FF371u: {
            TP_STATIC_GUARD(0x07FE6Eu, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE6Fu, 0x003FF379u, 3u);
        }

        case 0x003FF379u: {
            TP_STATIC_GUARD(0x07FE6Fu, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE70u, 0x003FF381u, 3u);
        }

        case 0x003FF381u: {
            TP_STATIC_GUARD(0x07FE70u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE71u, 0x003FF389u, 3u);
        }

        case 0x003FF389u: {
            TP_STATIC_GUARD(0x07FE71u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE72u, 0x003FF391u, 3u);
        }

        case 0x003FF391u: {
            TP_STATIC_GUARD(0x07FE72u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE73u, 0x003FF399u, 3u);
        }

        case 0x003FF399u: {
            TP_STATIC_GUARD(0x07FE73u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE76u, 0x003FF3B1u, 5u);
        }

        case 0x003FF3B1u: {
            TP_STATIC_GUARD(0x07FE76u, 0xA9u, 0xA8u, 0x00u);
            const uint16_t value = 0x00A8u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE79u, 0x003FF3C9u, 3u);
        }

        case 0x003FF3C9u: {
            TP_STATIC_GUARD(0x07FE79u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xFE7Au, 0x003FF3D1u, 2u);
        }

        case 0x003FF3D1u: {
            TP_STATIC_GUARD(0x07FE7Au, 0xEDu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE7Du, 0x003FF3E9u, 5u);
        }

        case 0x003FF3E9u: {
            TP_STATIC_GUARD(0x07FE7Du, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE80u, 0x003FF401u, 5u);
        }

        case 0x003FF401u: {
            TP_STATIC_GUARD(0x07FE80u, 0xA0u, 0x72u);
            const uint8_t value = 0x72u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE82u, 0x003FF411u, 2u);
        }

        case 0x003FF411u: {
            TP_STATIC_GUARD(0x07FE82u, 0xB7u, 0x16u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xFE84u;
            if (tp_scpu_expect_next(cpu, 0x003FF421u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF421u: {
            TP_STATIC_GUARD(0x07FE84u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xFE85u, 0x003FF429u, 2u);
        }

        case 0x003FF429u: {
            TP_STATIC_GUARD(0x07FE85u, 0x6Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE88u, 0x003FF441u, 5u);
        }

        case 0x003FF441u: {
            TP_STATIC_GUARD(0x07FE88u, 0x97u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x07u;
            cpu->pc = 0xFE8Au;
            if (tp_scpu_expect_next(cpu, 0x003FF451u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF451u: {
            TP_STATIC_GUARD(0x07FE8Au, 0x22u, 0xDAu, 0x87u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xFEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Du) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x87DAu, 0x003C3ED1u, 8u);
        }

        case 0x003FF471u: {
            TP_STATIC_GUARD(0x07FE8Eu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xFE90u, 0x003FF481u, 3u);
        }

        case 0x003FF481u: {
            TP_STATIC_GUARD(0x07FE90u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x07u, 0xFE92u, 0x003FF491u, 3u);
        }

        case 0x003FF491u: {
            TP_STATIC_GUARD(0x07FE92u, 0x29u, 0x0Fu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x000Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE95u, 0x003FF4A9u, 3u);
        }

        case 0x003FF4A9u: {
            TP_STATIC_GUARD(0x07FE95u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE98u, 0x003FF4C1u, 5u);
        }

        case 0x003FF4C1u: {
            TP_STATIC_GUARD(0x07FE98u, 0xA9u, 0x08u, 0x00u);
            const uint16_t value = 0x0008u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFE9Bu, 0x003FF4D9u, 3u);
        }

        case 0x003FF4D9u: {
            TP_STATIC_GUARD(0x07FE9Bu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xFE9Cu, 0x003FF4E1u, 2u);
        }

        case 0x003FF4E1u: {
            TP_STATIC_GUARD(0x07FE9Cu, 0xEDu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFE9Fu, 0x003FF4F9u, 5u);
        }

        case 0x003FF4F9u: {
            TP_STATIC_GUARD(0x07FE9Fu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFEA2u, 0x003FF511u, 5u);
        }

        case 0x003FF511u: {
            TP_STATIC_GUARD(0x07FEA2u, 0xA0u, 0x72u);
            const uint8_t value = 0x72u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFEA4u, 0x003FF521u, 2u);
        }

        case 0x003FF521u: {
            TP_STATIC_GUARD(0x07FEA4u, 0xB7u, 0x16u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xFEA6u;
            if (tp_scpu_expect_next(cpu, 0x003FF531u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF531u: {
            TP_STATIC_GUARD(0x07FEA6u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xFEA7u, 0x003FF539u, 2u);
        }

        case 0x003FF539u: {
            TP_STATIC_GUARD(0x07FEA7u, 0xEDu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFEAAu, 0x003FF551u, 5u);
        }

        case 0x003FF551u: {
            TP_STATIC_GUARD(0x07FEAAu, 0x97u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x07u;
            cpu->pc = 0xFEACu;
            if (tp_scpu_expect_next(cpu, 0x003FF561u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF561u: {
            TP_STATIC_GUARD(0x07FEACu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xFEAEu, 0x003FF571u, 3u);
        }

        case 0x003FF571u: {
            TP_STATIC_GUARD(0x07FEAEu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x07u, 0xFEB0u, 0x003FF581u, 3u);
        }

        case 0x003FF581u: {
            TP_STATIC_GUARD(0x07FEB0u, 0xADu, 0x0Bu, 0x04u);
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
            TP_STATIC_EXIT(0x07u, 0xFEB3u, 0x003FF599u, 5u);
        }

        case 0x003FF599u: {
            TP_STATIC_GUARD(0x07FEB3u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xFEB4u, 0x003FF5A1u, 2u);
        }

        case 0x003FF5A1u: {
            TP_STATIC_GUARD(0x07FEB4u, 0x69u, 0x02u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0002u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFEB7u, 0x003FF5B9u, 3u);
        }

        case 0x003FF5B9u: {
            TP_STATIC_GUARD(0x07FEB7u, 0x6Du, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFEBAu, 0x003FF5D1u, 5u);
        }

        case 0x003FF5D1u: {
            TP_STATIC_GUARD(0x07FEBAu, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFEBDu, 0x003FF5E9u, 5u);
        }

        case 0x003FF5E9u: {
            TP_STATIC_GUARD(0x07FEBDu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xFEBFu, 0x003FF5F9u, 3u);
        }

        case 0x003FF5EBu: {
            TP_STATIC_GUARD(0x07FEBDu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xFEBFu, 0x003FF5FBu, 3u);
        }

        case 0x003FF5F9u: {
            TP_STATIC_GUARD(0x07FEBFu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x07u, 0xFEC1u, 0x003FF609u, 3u);
        }

        case 0x003FF5FBu: {
            TP_STATIC_GUARD(0x07FEBFu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x07u, 0xFEC1u, 0x003FF609u, 3u);
        }

        case 0x003FF609u: {
            TP_STATIC_GUARD(0x07FEC1u, 0xA0u, 0x72u);
            const uint8_t value = 0x72u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFEC3u, 0x003FF619u, 2u);
        }

        case 0x003FF619u: {
            TP_STATIC_GUARD(0x07FEC3u, 0xB7u, 0x16u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xFEC5u;
            if (tp_scpu_expect_next(cpu, 0x003FF629u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF629u: {
            TP_STATIC_GUARD(0x07FEC5u, 0x30u, 0x23u);
            if ((cpu->p & TP_P_N) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xFEEAu;
                if (tp_scpu_expect_next(cpu, 0x003FF751u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xFEC7u, 0x003FF639u, 2u);
        }

        case 0x003FF639u: {
            TP_STATIC_GUARD(0x07FEC7u, 0xC9u, 0x40u, 0x1Fu);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x1F40u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFECAu, 0x003FF651u, 3u);
        }

        case 0x003FF651u: {
            TP_STATIC_GUARD(0x07FECAu, 0xF0u, 0x1Eu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xFEEAu;
                if (tp_scpu_expect_next(cpu, 0x003FF751u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xFECCu, 0x003FF661u, 2u);
        }

        case 0x003FF661u: {
            TP_STATIC_GUARD(0x07FECCu, 0x90u, 0x1Cu);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xFEEAu;
                if (tp_scpu_expect_next(cpu, 0x003FF751u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xFECEu, 0x003FF671u, 2u);
        }

        case 0x003FF671u: {
            TP_STATIC_GUARD(0x07FECEu, 0xA0u, 0x82u);
            const uint8_t value = 0x82u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFED0u, 0x003FF681u, 2u);
        }

        case 0x003FF681u: {
            TP_STATIC_GUARD(0x07FED0u, 0xB7u, 0x16u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xFED2u;
            if (tp_scpu_expect_next(cpu, 0x003FF691u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF691u: {
            TP_STATIC_GUARD(0x07FED2u, 0x29u, 0x03u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0003u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFED5u, 0x003FF6A9u, 3u);
        }

        case 0x003FF6A9u: {
            TP_STATIC_GUARD(0x07FED5u, 0xD0u, 0x13u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0xFEEAu;
                if (tp_scpu_expect_next(cpu, 0x003FF751u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0xFED7u, 0x003FF6B9u, 2u);
        }

        case 0x003FF6B9u: {
            TP_STATIC_GUARD(0x07FED7u, 0xA0u, 0x72u);
            const uint8_t value = 0x72u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFED9u, 0x003FF6C9u, 2u);
        }

        case 0x003FF6C9u: {
            TP_STATIC_GUARD(0x07FED9u, 0xB7u, 0x16u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xFEDBu;
            if (tp_scpu_expect_next(cpu, 0x003FF6D9u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF6D9u: {
            TP_STATIC_GUARD(0x07FEDBu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xFEDCu, 0x003FF6E1u, 2u);
        }

        case 0x003FF6E1u: {
            TP_STATIC_GUARD(0x07FEDCu, 0xE9u, 0x40u, 0x1Fu);
            if (tp_scpu_sbc(cpu, 0x1F40u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFEDFu, 0x003FF6F9u, 3u);
        }

        case 0x003FF6F9u: {
            TP_STATIC_GUARD(0x07FEDFu, 0xEBu);
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->a & 0x00FFu) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->a & 0x00FFu) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFEE0u, 0x003FF701u, 3u);
        }

        case 0x003FF701u: {
            TP_STATIC_GUARD(0x07FEE0u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFEE3u, 0x003FF719u, 3u);
        }

        case 0x003FF719u: {
            TP_STATIC_GUARD(0x07FEE3u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xFEE4u, 0x003FF721u, 2u);
        }

        case 0x003FF721u: {
            TP_STATIC_GUARD(0x07FEE4u, 0x6Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFEE7u, 0x003FF739u, 5u);
        }

        case 0x003FF739u: {
            TP_STATIC_GUARD(0x07FEE7u, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFEEAu, 0x003FF751u, 5u);
        }

        case 0x003FF751u: {
            TP_STATIC_GUARD(0x07FEEAu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xFEECu, 0x003FF761u, 3u);
        }

        case 0x003FF761u: {
            TP_STATIC_GUARD(0x07FEECu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x07u, 0xFEEEu, 0x003FF771u, 3u);
        }

        case 0x003FF771u: {
            TP_STATIC_GUARD(0x07FEEEu, 0xA0u, 0x55u);
            const uint8_t value = 0x55u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFEF0u, 0x003FF781u, 2u);
        }

        case 0x003FF781u: {
            TP_STATIC_GUARD(0x07FEF0u, 0xB7u, 0x16u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xFEF2u;
            if (tp_scpu_expect_next(cpu, 0x003FF791u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF791u: {
            TP_STATIC_GUARD(0x07FEF2u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0xFEF3u, 0x003FF799u, 2u);
        }

        case 0x003FF799u: {
            TP_STATIC_GUARD(0x07FEF3u, 0xEDu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFEF6u, 0x003FF7B1u, 5u);
        }

        case 0x003FF7B1u: {
            TP_STATIC_GUARD(0x07FEF6u, 0x97u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x07u;
            cpu->pc = 0xFEF8u;
            if (tp_scpu_expect_next(cpu, 0x003FF7C1u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF7C1u: {
            TP_STATIC_GUARD(0x07FEF8u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0xFEFAu, 0x003FF7D3u, 3u);
        }

        case 0x003FF7D3u: {
            TP_STATIC_GUARD(0x07FEFAu, 0xA0u, 0x71u);
            const uint8_t value = 0x71u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFEFCu, 0x003FF7E3u, 2u);
        }

        case 0x003FF7E3u: {
            TP_STATIC_GUARD(0x07FEFCu, 0xB7u, 0x16u);
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
            cpu->pbr = 0x07u;
            cpu->pc = 0xFEFEu;
            if (tp_scpu_expect_next(cpu, 0x003FF7F3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x003FF7F3u: {
            TP_STATIC_GUARD(0x07FEFEu, 0xA0u, 0x62u);
            const uint8_t value = 0x62u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0xFF00u, 0x003FF803u, 2u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
