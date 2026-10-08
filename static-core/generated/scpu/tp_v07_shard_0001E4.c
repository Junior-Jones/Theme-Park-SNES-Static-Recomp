/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0001E4(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x000F2009u: {
            TP_STATIC_GUARD(0x01E401u, 0xA9u, 0x16u, 0xFFu);
            const uint16_t value = 0xFF16u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE404u, 0x000F2021u, 3u);
        }

        case 0x000F2021u: {
            TP_STATIC_GUARD(0x01E404u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE407u, 0x000F2039u, 5u);
        }

        case 0x000F2039u: {
            TP_STATIC_GUARD(0x01E407u, 0xA2u, 0x0Cu);
            const uint8_t value = 0x0Cu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE409u, 0x000F2049u, 2u);
        }

        case 0x000F2049u: {
            TP_STATIC_GUARD(0x01E409u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE40Cu, 0x000F2061u, 4u);
        }

        case 0x000F2061u: {
            TP_STATIC_GUARD(0x01E40Cu, 0x22u, 0xDCu, 0xE8u, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Fu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE8DCu, 0x000F46E1u, 8u);
        }

        case 0x000F2081u: {
            TP_STATIC_GUARD(0x01E410u, 0x82u, 0x72u, 0x02u);
            TP_STATIC_EXIT(0x01u, 0xE685u, 0x000F3429u, 4u);
        }

        case 0x000F209Bu: {
            TP_STATIC_GUARD(0x01E413u, 0xC9u, 0x05u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x05u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE415u, 0x000F20ABu, 2u);
        }

        case 0x000F20ABu: {
            TP_STATIC_GUARD(0x01E415u, 0xD0u, 0x41u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xE458u;
                if (tp_scpu_expect_next(cpu, 0x000F22C3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xE417u, 0x000F20BBu, 2u);
        }

        case 0x000F20BBu: {
            TP_STATIC_GUARD(0x01E417u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE419u, 0x000F20C8u, 3u);
        }

        case 0x000F20C8u: {
            TP_STATIC_GUARD(0x01E419u, 0xA0u, 0x07u, 0x00u);
            const uint16_t value = 0x0007u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE41Cu, 0x000F20E0u, 3u);
        }

        case 0x000F20E0u: {
            TP_STATIC_GUARD(0x01E41Cu, 0xB7u, 0x16u);
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
            cpu->pbr = 0x01u;
            cpu->pc = 0xE41Eu;
            if (tp_scpu_expect_next(cpu, 0x000F20F0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x000F20F0u: {
            TP_STATIC_GUARD(0x01E41Eu, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE421u, 0x000F2108u, 5u);
        }

        case 0x000F2108u: {
            TP_STATIC_GUARD(0x01E421u, 0x9Cu, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0790u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE424u, 0x000F2120u, 5u);
        }

        case 0x000F2120u: {
            TP_STATIC_GUARD(0x01E424u, 0xA9u, 0xA0u, 0x86u);
            const uint16_t value = 0x86A0u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE427u, 0x000F2138u, 3u);
        }

        case 0x000F2138u: {
            TP_STATIC_GUARD(0x01E427u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE42Au, 0x000F2150u, 5u);
        }

        case 0x000F2150u: {
            TP_STATIC_GUARD(0x01E42Au, 0xA9u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE42Du, 0x000F2168u, 3u);
        }

        case 0x000F2168u: {
            TP_STATIC_GUARD(0x01E42Du, 0x8Du, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Cu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE430u, 0x000F2180u, 5u);
        }

        case 0x000F2180u: {
            TP_STATIC_GUARD(0x01E430u, 0x22u, 0x9Au, 0xFAu, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x33u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFA9Au, 0x003FD4D0u, 8u);
        }

        case 0x000F21A0u: {
            TP_STATIC_GUARD(0x01E434u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE436u, 0x000F21B0u, 3u);
        }

        case 0x000F21B0u: {
            TP_STATIC_GUARD(0x01E436u, 0xADu, 0xA2u, 0x07u);
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
            TP_STATIC_EXIT(0x01u, 0xE439u, 0x000F21C8u, 5u);
        }

        case 0x000F21C8u: {
            TP_STATIC_GUARD(0x01E439u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE43Cu, 0x000F21E0u, 5u);
        }

        case 0x000F21E0u: {
            TP_STATIC_GUARD(0x01E43Cu, 0xADu, 0xA4u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A4u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE43Fu, 0x000F21F8u, 5u);
        }

        case 0x000F21F8u: {
            TP_STATIC_GUARD(0x01E43Fu, 0x8Du, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0790u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE442u, 0x000F2210u, 5u);
        }

        case 0x000F2210u: {
            TP_STATIC_GUARD(0x01E442u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xE444u, 0x000F2221u, 3u);
        }

        case 0x000F2221u: {
            TP_STATIC_GUARD(0x01E444u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x01u, 0xE446u, 0x000F2231u, 3u);
        }

        case 0x000F2231u: {
            TP_STATIC_GUARD(0x01E446u, 0xA9u, 0x16u, 0xFFu);
            const uint16_t value = 0xFF16u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE449u, 0x000F2249u, 3u);
        }

        case 0x000F2249u: {
            TP_STATIC_GUARD(0x01E449u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE44Cu, 0x000F2261u, 5u);
        }

        case 0x000F2261u: {
            TP_STATIC_GUARD(0x01E44Cu, 0xA2u, 0x0Cu);
            const uint8_t value = 0x0Cu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE44Eu, 0x000F2271u, 2u);
        }

        case 0x000F2271u: {
            TP_STATIC_GUARD(0x01E44Eu, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE451u, 0x000F2289u, 4u);
        }

        case 0x000F2289u: {
            TP_STATIC_GUARD(0x01E451u, 0x22u, 0xDCu, 0xE8u, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x54u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE8DCu, 0x000F46E1u, 8u);
        }

        case 0x000F22A9u: {
            TP_STATIC_GUARD(0x01E455u, 0x82u, 0x2Du, 0x02u);
            TP_STATIC_EXIT(0x01u, 0xE685u, 0x000F3429u, 4u);
        }

        case 0x000F22C3u: {
            TP_STATIC_GUARD(0x01E458u, 0xC9u, 0x06u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x06u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE45Au, 0x000F22D3u, 2u);
        }

        case 0x000F22D3u: {
            TP_STATIC_GUARD(0x01E45Au, 0xD0u, 0x4Fu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xE4ABu;
                if (tp_scpu_expect_next(cpu, 0x000F255Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xE45Cu, 0x000F22E3u, 2u);
        }

        case 0x000F22E3u: {
            TP_STATIC_GUARD(0x01E45Cu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xE45Eu, 0x000F22F3u, 3u);
        }

        case 0x000F22F3u: {
            TP_STATIC_GUARD(0x01E45Eu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x01u, 0xE460u, 0x000F2301u, 3u);
        }

        case 0x000F2301u: {
            TP_STATIC_GUARD(0x01E460u, 0xA9u, 0x0Fu, 0xFFu);
            const uint16_t value = 0xFF0Fu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE463u, 0x000F2319u, 3u);
        }

        case 0x000F2319u: {
            TP_STATIC_GUARD(0x01E463u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE466u, 0x000F2331u, 5u);
        }

        case 0x000F2331u: {
            TP_STATIC_GUARD(0x01E466u, 0xA2u, 0x0Cu);
            const uint8_t value = 0x0Cu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE468u, 0x000F2341u, 2u);
        }

        case 0x000F2341u: {
            TP_STATIC_GUARD(0x01E468u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE46Bu, 0x000F2359u, 4u);
        }

        case 0x000F2359u: {
            TP_STATIC_GUARD(0x01E46Bu, 0xA0u, 0x09u);
            const uint8_t value = 0x09u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE46Du, 0x000F2369u, 2u);
        }

        case 0x000F2369u: {
            TP_STATIC_GUARD(0x01E46Du, 0xB7u, 0x16u);
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
            cpu->pbr = 0x01u;
            cpu->pc = 0xE46Fu;
            if (tp_scpu_expect_next(cpu, 0x000F2379u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x000F2379u: {
            TP_STATIC_GUARD(0x01E46Fu, 0xA2u, 0x64u);
            const uint8_t value = 0x64u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE471u, 0x000F2389u, 2u);
        }

        case 0x000F2389u: {
            TP_STATIC_GUARD(0x01E471u, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE474u, 0x000F23A1u, 3u);
        }

        case 0x000F23A1u: {
            TP_STATIC_GUARD(0x01E474u, 0xF0u, 0x1Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xE492u;
                if (tp_scpu_expect_next(cpu, 0x000F2491u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xE476u, 0x000F23B1u, 2u);
        }

        case 0x000F23B1u: {
            TP_STATIC_GUARD(0x01E476u, 0xE0u, 0x00u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x00u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE478u, 0x000F23C1u, 2u);
        }

        case 0x000F23C1u: {
            TP_STATIC_GUARD(0x01E478u, 0xF0u, 0x18u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xE492u;
                if (tp_scpu_expect_next(cpu, 0x000F2491u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xE47Au, 0x000F23D1u, 2u);
        }

        case 0x000F23D1u: {
            TP_STATIC_GUARD(0x01E47Au, 0x8Du, 0x04u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4204u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE47Du, 0x000F23E9u, 5u);
        }

        case 0x000F23E9u: {
            TP_STATIC_GUARD(0x01E47Du, 0x8Eu, 0x06u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4206u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE480u, 0x000F2401u, 4u);
        }

        case 0x000F2401u: {
            TP_STATIC_GUARD(0x01E480u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE481u, 0x000F2409u, 2u);
        }

        case 0x000F2409u: {
            TP_STATIC_GUARD(0x01E481u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE482u, 0x000F2411u, 2u);
        }

        case 0x000F2411u: {
            TP_STATIC_GUARD(0x01E482u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE483u, 0x000F2419u, 2u);
        }

        case 0x000F2419u: {
            TP_STATIC_GUARD(0x01E483u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE484u, 0x000F2421u, 2u);
        }

        case 0x000F2421u: {
            TP_STATIC_GUARD(0x01E484u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE485u, 0x000F2429u, 2u);
        }

        case 0x000F2429u: {
            TP_STATIC_GUARD(0x01E485u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE486u, 0x000F2431u, 2u);
        }

        case 0x000F2431u: {
            TP_STATIC_GUARD(0x01E486u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE487u, 0x000F2439u, 2u);
        }

        case 0x000F2439u: {
            TP_STATIC_GUARD(0x01E487u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE488u, 0x000F2441u, 2u);
        }

        case 0x000F2441u: {
            TP_STATIC_GUARD(0x01E488u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE48Au, 0x000F2450u, 3u);
        }

        case 0x000F2450u: {
            TP_STATIC_GUARD(0x01E48Au, 0xADu, 0x14u, 0x42u);
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
            TP_STATIC_EXIT(0x01u, 0xE48Du, 0x000F2468u, 5u);
        }

        case 0x000F2468u: {
            TP_STATIC_GUARD(0x01E48Du, 0xAEu, 0x16u, 0x42u);
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
            TP_STATIC_EXIT(0x01u, 0xE490u, 0x000F2480u, 5u);
        }

        case 0x000F2480u: {
            TP_STATIC_GUARD(0x01E490u, 0x80u, 0x06u);
            TP_STATIC_EXIT(0x01u, 0xE498u, 0x000F24C0u, 3u);
        }

        case 0x000F2491u: {
            TP_STATIC_GUARD(0x01E492u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE494u, 0x000F24A0u, 3u);
        }

        case 0x000F24A0u: {
            TP_STATIC_GUARD(0x01E494u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE497u, 0x000F24B8u, 3u);
        }

        case 0x000F24B8u: {
            TP_STATIC_GUARD(0x01E497u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE498u, 0x000F24C0u, 2u);
        }

        case 0x000F24C0u: {
            TP_STATIC_GUARD(0x01E498u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE49Bu, 0x000F24D8u, 5u);
        }

        case 0x000F24D8u: {
            TP_STATIC_GUARD(0x01E49Bu, 0x8Eu, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0792u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE49Eu, 0x000F24F0u, 5u);
        }

        case 0x000F24F0u: {
            TP_STATIC_GUARD(0x01E49Eu, 0x9Cu, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0790u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE4A1u, 0x000F2508u, 5u);
        }

        case 0x000F2508u: {
            TP_STATIC_GUARD(0x01E4A1u, 0x9Cu, 0x94u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0794u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE4A4u, 0x000F2520u, 5u);
        }

        case 0x000F2520u: {
            TP_STATIC_GUARD(0x01E4A4u, 0x22u, 0xDCu, 0xE8u, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA7u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE8DCu, 0x000F46E0u, 8u);
        }

        case 0x000F2541u: {
            TP_STATIC_GUARD(0x01E4A8u, 0x82u, 0xDAu, 0x01u);
            TP_STATIC_EXIT(0x01u, 0xE685u, 0x000F3429u, 4u);
        }

        case 0x000F255Bu: {
            TP_STATIC_GUARD(0x01E4ABu, 0xC9u, 0x07u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x07u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE4ADu, 0x000F256Bu, 2u);
        }

        case 0x000F256Bu: {
            TP_STATIC_GUARD(0x01E4ADu, 0xD0u, 0x4Fu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xE4FEu;
                if (tp_scpu_expect_next(cpu, 0x000F27F3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xE4AFu, 0x000F257Bu, 2u);
        }

        case 0x000F257Bu: {
            TP_STATIC_GUARD(0x01E4AFu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xE4B1u, 0x000F258Bu, 3u);
        }

        case 0x000F258Bu: {
            TP_STATIC_GUARD(0x01E4B1u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x01u, 0xE4B3u, 0x000F2599u, 3u);
        }

        case 0x000F2599u: {
            TP_STATIC_GUARD(0x01E4B3u, 0xA9u, 0x0Fu, 0xFFu);
            const uint16_t value = 0xFF0Fu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE4B6u, 0x000F25B1u, 3u);
        }

        case 0x000F25B1u: {
            TP_STATIC_GUARD(0x01E4B6u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE4B9u, 0x000F25C9u, 5u);
        }

        case 0x000F25C9u: {
            TP_STATIC_GUARD(0x01E4B9u, 0xA2u, 0x0Cu);
            const uint8_t value = 0x0Cu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE4BBu, 0x000F25D9u, 2u);
        }

        case 0x000F25D9u: {
            TP_STATIC_GUARD(0x01E4BBu, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE4BEu, 0x000F25F1u, 4u);
        }

        case 0x000F25F1u: {
            TP_STATIC_GUARD(0x01E4BEu, 0xA0u, 0x0Bu);
            const uint8_t value = 0x0Bu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE4C0u, 0x000F2601u, 2u);
        }

        case 0x000F2601u: {
            TP_STATIC_GUARD(0x01E4C0u, 0xB7u, 0x16u);
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
            cpu->pbr = 0x01u;
            cpu->pc = 0xE4C2u;
            if (tp_scpu_expect_next(cpu, 0x000F2611u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x000F2611u: {
            TP_STATIC_GUARD(0x01E4C2u, 0xA2u, 0x64u);
            const uint8_t value = 0x64u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE4C4u, 0x000F2621u, 2u);
        }

        case 0x000F2621u: {
            TP_STATIC_GUARD(0x01E4C4u, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE4C7u, 0x000F2639u, 3u);
        }

        case 0x000F2639u: {
            TP_STATIC_GUARD(0x01E4C7u, 0xF0u, 0x1Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xE4E5u;
                if (tp_scpu_expect_next(cpu, 0x000F2729u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xE4C9u, 0x000F2649u, 2u);
        }

        case 0x000F2649u: {
            TP_STATIC_GUARD(0x01E4C9u, 0xE0u, 0x00u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x00u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE4CBu, 0x000F2659u, 2u);
        }

        case 0x000F2659u: {
            TP_STATIC_GUARD(0x01E4CBu, 0xF0u, 0x18u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xE4E5u;
                if (tp_scpu_expect_next(cpu, 0x000F2729u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xE4CDu, 0x000F2669u, 2u);
        }

        case 0x000F2669u: {
            TP_STATIC_GUARD(0x01E4CDu, 0x8Du, 0x04u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4204u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE4D0u, 0x000F2681u, 5u);
        }

        case 0x000F2681u: {
            TP_STATIC_GUARD(0x01E4D0u, 0x8Eu, 0x06u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4206u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE4D3u, 0x000F2699u, 4u);
        }

        case 0x000F2699u: {
            TP_STATIC_GUARD(0x01E4D3u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE4D4u, 0x000F26A1u, 2u);
        }

        case 0x000F26A1u: {
            TP_STATIC_GUARD(0x01E4D4u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE4D5u, 0x000F26A9u, 2u);
        }

        case 0x000F26A9u: {
            TP_STATIC_GUARD(0x01E4D5u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE4D6u, 0x000F26B1u, 2u);
        }

        case 0x000F26B1u: {
            TP_STATIC_GUARD(0x01E4D6u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE4D7u, 0x000F26B9u, 2u);
        }

        case 0x000F26B9u: {
            TP_STATIC_GUARD(0x01E4D7u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE4D8u, 0x000F26C1u, 2u);
        }

        case 0x000F26C1u: {
            TP_STATIC_GUARD(0x01E4D8u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE4D9u, 0x000F26C9u, 2u);
        }

        case 0x000F26C9u: {
            TP_STATIC_GUARD(0x01E4D9u, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE4DAu, 0x000F26D1u, 2u);
        }

        case 0x000F26D1u: {
            TP_STATIC_GUARD(0x01E4DAu, 0xEAu);
            TP_STATIC_EXIT(0x01u, 0xE4DBu, 0x000F26D9u, 2u);
        }

        case 0x000F26D9u: {
            TP_STATIC_GUARD(0x01E4DBu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE4DDu, 0x000F26E8u, 3u);
        }

        case 0x000F26E8u: {
            TP_STATIC_GUARD(0x01E4DDu, 0xADu, 0x14u, 0x42u);
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
            TP_STATIC_EXIT(0x01u, 0xE4E0u, 0x000F2700u, 5u);
        }

        case 0x000F2700u: {
            TP_STATIC_GUARD(0x01E4E0u, 0xAEu, 0x16u, 0x42u);
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
            TP_STATIC_EXIT(0x01u, 0xE4E3u, 0x000F2718u, 5u);
        }

        case 0x000F2718u: {
            TP_STATIC_GUARD(0x01E4E3u, 0x80u, 0x06u);
            TP_STATIC_EXIT(0x01u, 0xE4EBu, 0x000F2758u, 3u);
        }

        case 0x000F2729u: {
            TP_STATIC_GUARD(0x01E4E5u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xE4E7u, 0x000F2738u, 3u);
        }

        case 0x000F2738u: {
            TP_STATIC_GUARD(0x01E4E7u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE4EAu, 0x000F2750u, 3u);
        }

        case 0x000F2750u: {
            TP_STATIC_GUARD(0x01E4EAu, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE4EBu, 0x000F2758u, 2u);
        }

        case 0x000F2758u: {
            TP_STATIC_GUARD(0x01E4EBu, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE4EEu, 0x000F2770u, 5u);
        }

        case 0x000F2770u: {
            TP_STATIC_GUARD(0x01E4EEu, 0x8Eu, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0792u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE4F1u, 0x000F2788u, 5u);
        }

        case 0x000F2788u: {
            TP_STATIC_GUARD(0x01E4F1u, 0x9Cu, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0790u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE4F4u, 0x000F27A0u, 5u);
        }

        case 0x000F27A0u: {
            TP_STATIC_GUARD(0x01E4F4u, 0x9Cu, 0x94u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0794u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE4F7u, 0x000F27B8u, 5u);
        }

        case 0x000F27B8u: {
            TP_STATIC_GUARD(0x01E4F7u, 0x22u, 0xDCu, 0xE8u, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE4u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xFAu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xE8DCu, 0x000F46E0u, 8u);
        }

        case 0x000F27D9u: {
            TP_STATIC_GUARD(0x01E4FBu, 0x82u, 0x87u, 0x01u);
            TP_STATIC_EXIT(0x01u, 0xE685u, 0x000F3429u, 4u);
        }

        case 0x000F27F3u: {
            TP_STATIC_GUARD(0x01E4FEu, 0xC9u, 0x08u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x08u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xE500u, 0x000F2803u, 2u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
