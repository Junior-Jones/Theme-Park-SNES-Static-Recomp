/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0004E2(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00271000u: {
            TP_STATIC_GUARD(0x04E200u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE202u, 0x00271013u, 3u);
        }

        case 0x00271013u: {
            TP_STATIC_GUARD(0x04E202u, 0x8Du, 0x02u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4202u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE205u, 0x0027102Bu, 4u);
        }

        case 0x0027102Bu: {
            TP_STATIC_GUARD(0x04E205u, 0x8Eu, 0x03u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4203u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE208u, 0x00271043u, 4u);
        }

        case 0x00271043u: {
            TP_STATIC_GUARD(0x04E208u, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0xE209u, 0x0027104Bu, 2u);
        }

        case 0x0027104Bu: {
            TP_STATIC_GUARD(0x04E209u, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0xE20Au, 0x00271053u, 2u);
        }

        case 0x00271053u: {
            TP_STATIC_GUARD(0x04E20Au, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0xE20Bu, 0x0027105Bu, 2u);
        }

        case 0x0027105Bu: {
            TP_STATIC_GUARD(0x04E20Bu, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0xE20Cu, 0x00271063u, 2u);
        }

        case 0x00271063u: {
            TP_STATIC_GUARD(0x04E20Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE20Eu, 0x00271070u, 3u);
        }

        case 0x00271070u: {
            TP_STATIC_GUARD(0x04E20Eu, 0xADu, 0x16u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4216u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE211u, 0x00271088u, 5u);
        }

        case 0x00271088u: {
            TP_STATIC_GUARD(0x04E211u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE213u, 0x00271098u, 3u);
        }

        case 0x00271098u: {
            TP_STATIC_GUARD(0x04E213u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xE214u, 0x002710A0u, 2u);
        }

        case 0x002710A0u: {
            TP_STATIC_GUARD(0x04E214u, 0x6Du, 0x60u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F60u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE217u, 0x002710B8u, 5u);
        }

        case 0x002710B8u: {
            TP_STATIC_GUARD(0x04E217u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE218u, 0x002710C0u, 2u);
        }

        case 0x002710C0u: {
            TP_STATIC_GUARD(0x04E218u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE219u, 0x002710C8u, 2u);
        }

        case 0x002710C8u: {
            TP_STATIC_GUARD(0x04E219u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE21Au, 0x002710D0u, 3u);
        }

        case 0x002710D0u: {
            TP_STATIC_GUARD(0x04E21Au, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE21Bu, 0x002710D8u, 3u);
        }

        case 0x002710D8u: {
            TP_STATIC_GUARD(0x04E21Bu, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE21Cu, 0x002710E0u, 2u);
        }

        case 0x002710E0u: {
            TP_STATIC_GUARD(0x04E21Cu, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE21Du, 0x002710E8u, 2u);
        }

        case 0x002710E8u: {
            TP_STATIC_GUARD(0x04E21Du, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE21Fu, 0x002710FAu, 3u);
        }

        case 0x002710FAu: {
            TP_STATIC_GUARD(0x04E21Fu, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x04u, 0xE221u, 0x0027110Au, 3u);
        }

        case 0x0027110Au: {
            TP_STATIC_GUARD(0x04E221u, 0xBFu, 0xE3u, 0x1Cu, 0x00u);
            const uint32_t address = (0x001CE3u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE225u, 0x0027112Au, 5u);
        }

        case 0x0027112Au: {
            TP_STATIC_GUARD(0x04E225u, 0x8Du, 0x4Eu, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x194Eu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE228u, 0x00271142u, 4u);
        }

        case 0x00271142u: {
            TP_STATIC_GUARD(0x04E228u, 0xBFu, 0xE5u, 0x1Cu, 0x00u);
            const uint32_t address = (0x001CE5u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE22Cu, 0x00271162u, 5u);
        }

        case 0x00271162u: {
            TP_STATIC_GUARD(0x04E22Cu, 0x8Du, 0x4Fu, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x194Fu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE22Fu, 0x0027117Au, 4u);
        }

        case 0x0027117Au: {
            TP_STATIC_GUARD(0x04E22Fu, 0x82u, 0x38u, 0x01u);
            TP_STATIC_EXIT(0x04u, 0xE36Au, 0x00271B52u, 4u);
        }

        case 0x00271190u: {
            TP_STATIC_GUARD(0x04E232u, 0x22u, 0xE4u, 0xA1u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE2u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x35u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xA1E4u, 0x00650F20u, 8u);
        }

        case 0x002711B3u: {
            TP_STATIC_GUARD(0x04E236u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE238u, 0x002711C0u, 3u);
        }

        case 0x002711C0u: {
            TP_STATIC_GUARD(0x04E238u, 0xADu, 0x0Au, 0x08u);
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
            TP_STATIC_EXIT(0x04u, 0xE23Bu, 0x002711D8u, 5u);
        }

        case 0x002711D8u: {
            TP_STATIC_GUARD(0x04E23Bu, 0xC9u, 0x1Du, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x001Du;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE23Eu, 0x002711F0u, 3u);
        }

        case 0x002711F0u: {
            TP_STATIC_GUARD(0x04E23Eu, 0xD0u, 0x05u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE245u;
                if (tp_scpu_expect_next(cpu, 0x00271228u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE240u, 0x00271200u, 2u);
        }

        case 0x00271200u: {
            TP_STATIC_GUARD(0x04E240u, 0xA9u, 0x00u, 0x04u);
            const uint16_t value = 0x0400u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE243u, 0x00271218u, 3u);
        }

        case 0x00271218u: {
            TP_STATIC_GUARD(0x04E243u, 0x80u, 0x08u);
            TP_STATIC_EXIT(0x04u, 0xE24Du, 0x00271268u, 3u);
        }

        case 0x00271228u: {
            TP_STATIC_GUARD(0x04E245u, 0xC9u, 0x1Cu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x001Cu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE248u, 0x00271240u, 3u);
        }

        case 0x00271240u: {
            TP_STATIC_GUARD(0x04E248u, 0xD0u, 0x7Au);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE2C4u;
                if (tp_scpu_expect_next(cpu, 0x00271620u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE24Au, 0x00271250u, 2u);
        }

        case 0x00271250u: {
            TP_STATIC_GUARD(0x04E24Au, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE24Du, 0x00271268u, 3u);
        }

        case 0x00271268u: {
            TP_STATIC_GUARD(0x04E24Du, 0x8Du, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Cu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE250u, 0x00271280u, 5u);
        }

        case 0x00271280u: {
            TP_STATIC_GUARD(0x04E250u, 0x22u, 0xE9u, 0xA0u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE2u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x53u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xA0E9u, 0x00650748u, 8u);
        }

        case 0x002712A3u: {
            TP_STATIC_GUARD(0x04E254u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xE256u, 0x002712B0u, 3u);
        }

        case 0x002712B0u: {
            TP_STATIC_GUARD(0x04E256u, 0xADu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0746u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE259u, 0x002712C8u, 5u);
        }

        case 0x002712C8u: {
            TP_STATIC_GUARD(0x04E259u, 0x29u, 0x10u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0010u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE25Cu, 0x002712E0u, 3u);
        }

        case 0x002712E0u: {
            TP_STATIC_GUARD(0x04E25Cu, 0xF0u, 0x2Eu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE28Cu;
                if (tp_scpu_expect_next(cpu, 0x00271460u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE25Eu, 0x002712F0u, 2u);
        }

        case 0x002712F0u: {
            TP_STATIC_GUARD(0x04E25Eu, 0xADu, 0x57u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1857u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE261u, 0x00271308u, 5u);
        }

        case 0x00271308u: {
            TP_STATIC_GUARD(0x04E261u, 0x29u, 0x05u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0005u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE264u, 0x00271320u, 3u);
        }

        case 0x00271320u: {
            TP_STATIC_GUARD(0x04E264u, 0xF0u, 0x0Du);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE273u;
                if (tp_scpu_expect_next(cpu, 0x00271398u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE266u, 0x00271330u, 2u);
        }

        case 0x00271330u: {
            TP_STATIC_GUARD(0x04E266u, 0xADu, 0x55u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1855u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE269u, 0x00271348u, 5u);
        }

        case 0x00271348u: {
            TP_STATIC_GUARD(0x04E269u, 0xC9u, 0x01u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0001u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE26Cu, 0x00271360u, 3u);
        }

        case 0x00271360u: {
            TP_STATIC_GUARD(0x04E26Cu, 0xD0u, 0x05u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE273u;
                if (tp_scpu_expect_next(cpu, 0x00271398u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE26Eu, 0x00271370u, 2u);
        }

        case 0x00271370u: {
            TP_STATIC_GUARD(0x04E26Eu, 0xA9u, 0xFFu, 0xFFu);
            const uint16_t value = 0xFFFFu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE271u, 0x00271388u, 3u);
        }

        case 0x00271388u: {
            TP_STATIC_GUARD(0x04E271u, 0x80u, 0x14u);
            TP_STATIC_EXIT(0x04u, 0xE287u, 0x00271438u, 3u);
        }

        case 0x00271398u: {
            TP_STATIC_GUARD(0x04E273u, 0xADu, 0x55u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1855u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE276u, 0x002713B0u, 5u);
        }

        case 0x002713B0u: {
            TP_STATIC_GUARD(0x04E276u, 0x1Au);
            cpu->a = (uint16_t)(cpu->a + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE277u, 0x002713B8u, 3u);
        }

        case 0x002713B8u: {
            TP_STATIC_GUARD(0x04E277u, 0xC9u, 0x03u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0003u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE27Au, 0x002713D0u, 3u);
        }

        case 0x002713D0u: {
            TP_STATIC_GUARD(0x04E27Au, 0x90u, 0x03u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE27Fu;
                if (tp_scpu_expect_next(cpu, 0x002713F8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE27Cu, 0x002713E0u, 2u);
        }

        case 0x002713E0u: {
            TP_STATIC_GUARD(0x04E27Cu, 0xA9u, 0xFFu, 0xFFu);
            const uint16_t value = 0xFFFFu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE27Fu, 0x002713F8u, 3u);
        }

        case 0x002713F8u: {
            TP_STATIC_GUARD(0x04E27Fu, 0xC9u, 0x02u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0002u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE282u, 0x00271410u, 3u);
        }

        case 0x00271410u: {
            TP_STATIC_GUARD(0x04E282u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE287u;
                if (tp_scpu_expect_next(cpu, 0x00271438u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE284u, 0x00271420u, 2u);
        }

        case 0x00271420u: {
            TP_STATIC_GUARD(0x04E284u, 0xA9u, 0x05u, 0x00u);
            const uint16_t value = 0x0005u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE287u, 0x00271438u, 3u);
        }

        case 0x00271438u: {
            TP_STATIC_GUARD(0x04E287u, 0x8Du, 0x55u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1855u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE28Au, 0x00271450u, 5u);
        }

        case 0x00271450u: {
            TP_STATIC_GUARD(0x04E28Au, 0x80u, 0x79u);
            TP_STATIC_EXIT(0x04u, 0xE305u, 0x00271828u, 3u);
        }

        case 0x00271460u: {
            TP_STATIC_GUARD(0x04E28Cu, 0xADu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0746u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE28Fu, 0x00271478u, 5u);
        }

        case 0x00271478u: {
            TP_STATIC_GUARD(0x04E28Fu, 0x29u, 0x20u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0020u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE292u, 0x00271490u, 3u);
        }

        case 0x00271490u: {
            TP_STATIC_GUARD(0x04E292u, 0xF0u, 0x71u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE305u;
                if (tp_scpu_expect_next(cpu, 0x00271828u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE294u, 0x002714A0u, 2u);
        }

        case 0x002714A0u: {
            TP_STATIC_GUARD(0x04E294u, 0xADu, 0x57u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1857u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE297u, 0x002714B8u, 5u);
        }

        case 0x002714B8u: {
            TP_STATIC_GUARD(0x04E297u, 0x29u, 0x05u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0005u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE29Au, 0x002714D0u, 3u);
        }

        case 0x002714D0u: {
            TP_STATIC_GUARD(0x04E29Au, 0xF0u, 0x0Du);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE2A9u;
                if (tp_scpu_expect_next(cpu, 0x00271548u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE29Cu, 0x002714E0u, 2u);
        }

        case 0x002714E0u: {
            TP_STATIC_GUARD(0x04E29Cu, 0xADu, 0x55u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1855u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE29Fu, 0x002714F8u, 5u);
        }

        case 0x002714F8u: {
            TP_STATIC_GUARD(0x04E29Fu, 0xC9u, 0xFFu, 0xFFu);
            const uint16_t left = cpu->a;
            const uint16_t right = 0xFFFFu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2A2u, 0x00271510u, 3u);
        }

        case 0x00271510u: {
            TP_STATIC_GUARD(0x04E2A2u, 0xD0u, 0x05u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE2A9u;
                if (tp_scpu_expect_next(cpu, 0x00271548u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE2A4u, 0x00271520u, 2u);
        }

        case 0x00271520u: {
            TP_STATIC_GUARD(0x04E2A4u, 0xA9u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2A7u, 0x00271538u, 3u);
        }

        case 0x00271538u: {
            TP_STATIC_GUARD(0x04E2A7u, 0x80u, 0x16u);
            TP_STATIC_EXIT(0x04u, 0xE2BFu, 0x002715F8u, 3u);
        }

        case 0x00271548u: {
            TP_STATIC_GUARD(0x04E2A9u, 0xADu, 0x55u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1855u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2ACu, 0x00271560u, 5u);
        }

        case 0x00271560u: {
            TP_STATIC_GUARD(0x04E2ACu, 0x3Au);
            cpu->a = (uint16_t)(cpu->a - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2ADu, 0x00271568u, 3u);
        }

        case 0x00271568u: {
            TP_STATIC_GUARD(0x04E2ADu, 0x30u, 0x08u);
            if ((cpu->p & TP_P_N) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE2B7u;
                if (tp_scpu_expect_next(cpu, 0x002715B8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE2AFu, 0x00271578u, 2u);
        }

        case 0x00271578u: {
            TP_STATIC_GUARD(0x04E2AFu, 0xC9u, 0x02u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0002u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2B2u, 0x00271590u, 3u);
        }

        case 0x00271590u: {
            TP_STATIC_GUARD(0x04E2B2u, 0x90u, 0x03u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE2B7u;
                if (tp_scpu_expect_next(cpu, 0x002715B8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE2B4u, 0x002715A0u, 2u);
        }

        case 0x002715A0u: {
            TP_STATIC_GUARD(0x04E2B4u, 0xA9u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2B7u, 0x002715B8u, 3u);
        }

        case 0x002715B8u: {
            TP_STATIC_GUARD(0x04E2B7u, 0xC9u, 0xFEu, 0xFFu);
            const uint16_t left = cpu->a;
            const uint16_t right = 0xFFFEu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2BAu, 0x002715D0u, 3u);
        }

        case 0x002715D0u: {
            TP_STATIC_GUARD(0x04E2BAu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE2BFu;
                if (tp_scpu_expect_next(cpu, 0x002715F8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE2BCu, 0x002715E0u, 2u);
        }

        case 0x002715E0u: {
            TP_STATIC_GUARD(0x04E2BCu, 0xA9u, 0x05u, 0x00u);
            const uint16_t value = 0x0005u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2BFu, 0x002715F8u, 3u);
        }

        case 0x002715F8u: {
            TP_STATIC_GUARD(0x04E2BFu, 0x8Du, 0x55u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1855u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE2C2u, 0x00271610u, 5u);
        }

        case 0x00271610u: {
            TP_STATIC_GUARD(0x04E2C2u, 0x80u, 0x41u);
            TP_STATIC_EXIT(0x04u, 0xE305u, 0x00271828u, 3u);
        }

        case 0x00271620u: {
            TP_STATIC_GUARD(0x04E2C4u, 0xC9u, 0x02u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0002u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2C7u, 0x00271638u, 3u);
        }

        case 0x00271638u: {
            TP_STATIC_GUARD(0x04E2C7u, 0xD0u, 0x3Cu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE305u;
                if (tp_scpu_expect_next(cpu, 0x00271828u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE2C9u, 0x00271648u, 2u);
        }

        case 0x00271648u: {
            TP_STATIC_GUARD(0x04E2C9u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE2CBu, 0x0027165Bu, 3u);
        }

        case 0x0027165Bu: {
            TP_STATIC_GUARD(0x04E2CBu, 0xADu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0746u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2CEu, 0x00271673u, 4u);
        }

        case 0x00271673u: {
            TP_STATIC_GUARD(0x04E2CEu, 0x29u, 0x10u);
            const uint8_t value = (uint8_t)(cpu->a & 0x10u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2D0u, 0x00271683u, 2u);
        }

        case 0x00271683u: {
            TP_STATIC_GUARD(0x04E2D0u, 0xF0u, 0x16u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE2E8u;
                if (tp_scpu_expect_next(cpu, 0x00271743u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE2D2u, 0x00271693u, 2u);
        }

        case 0x00271693u: {
            TP_STATIC_GUARD(0x04E2D2u, 0xEEu, 0xEDu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18EDu;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE2D5u, 0x002716ABu, 6u);
        }

        case 0x002716ABu: {
            TP_STATIC_GUARD(0x04E2D5u, 0xADu, 0xEDu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18EDu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2D8u, 0x002716C3u, 4u);
        }

        case 0x002716C3u: {
            TP_STATIC_GUARD(0x04E2D8u, 0xC9u, 0x08u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x08u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2DAu, 0x002716D3u, 2u);
        }

        case 0x002716D3u: {
            TP_STATIC_GUARD(0x04E2DAu, 0x90u, 0x02u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE2DEu;
                if (tp_scpu_expect_next(cpu, 0x002716F3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE2DCu, 0x002716E3u, 2u);
        }

        case 0x002716E3u: {
            TP_STATIC_GUARD(0x04E2DCu, 0xA9u, 0x03u);
            const uint8_t value = 0x03u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2DEu, 0x002716F3u, 2u);
        }

        case 0x002716F3u: {
            TP_STATIC_GUARD(0x04E2DEu, 0x8Du, 0xEDu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18EDu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE2E1u, 0x0027170Bu, 4u);
        }

        case 0x0027170Bu: {
            TP_STATIC_GUARD(0x04E2E1u, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2E3u, 0x0027171Bu, 2u);
        }

        case 0x0027171Bu: {
            TP_STATIC_GUARD(0x04E2E3u, 0x8Du, 0x0Cu, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x080Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE2E6u, 0x00271733u, 4u);
        }

        case 0x00271733u: {
            TP_STATIC_GUARD(0x04E2E6u, 0x80u, 0x1Du);
            TP_STATIC_EXIT(0x04u, 0xE305u, 0x0027182Bu, 3u);
        }

        case 0x00271743u: {
            TP_STATIC_GUARD(0x04E2E8u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xE2EAu, 0x00271753u, 3u);
        }

        case 0x00271753u: {
            TP_STATIC_GUARD(0x04E2EAu, 0xADu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0746u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2EDu, 0x0027176Bu, 4u);
        }

        case 0x0027176Bu: {
            TP_STATIC_GUARD(0x04E2EDu, 0x29u, 0x20u);
            const uint8_t value = (uint8_t)(cpu->a & 0x20u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2EFu, 0x0027177Bu, 2u);
        }

        case 0x0027177Bu: {
            TP_STATIC_GUARD(0x04E2EFu, 0xF0u, 0x14u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE305u;
                if (tp_scpu_expect_next(cpu, 0x0027182Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE2F1u, 0x0027178Bu, 2u);
        }

        case 0x0027178Bu: {
            TP_STATIC_GUARD(0x04E2F1u, 0xCEu, 0xEDu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18EDu;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE2F4u, 0x002717A3u, 6u);
        }

        case 0x002717A3u: {
            TP_STATIC_GUARD(0x04E2F4u, 0xADu, 0xEDu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18EDu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2F7u, 0x002717BBu, 4u);
        }

        case 0x002717BBu: {
            TP_STATIC_GUARD(0x04E2F7u, 0xC9u, 0x03u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x03u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2F9u, 0x002717CBu, 2u);
        }

        case 0x002717CBu: {
            TP_STATIC_GUARD(0x04E2F9u, 0xB0u, 0x02u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xE2FDu;
                if (tp_scpu_expect_next(cpu, 0x002717EBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xE2FBu, 0x002717DBu, 2u);
        }

        case 0x002717DBu: {
            TP_STATIC_GUARD(0x04E2FBu, 0xA9u, 0x07u);
            const uint8_t value = 0x07u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xE2FDu, 0x002717EBu, 2u);
        }

        case 0x002717EBu: {
            TP_STATIC_GUARD(0x04E2FDu, 0x8Du, 0xEDu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18EDu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE300u, 0x00271803u, 4u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
