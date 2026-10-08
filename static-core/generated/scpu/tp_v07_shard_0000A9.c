/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0000A9(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00054803u: {
            TP_STATIC_GUARD(0x00A900u, 0xD0u, 0xFBu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA8FDu;
                if (tp_scpu_expect_next(cpu, 0x000547EBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA902u, 0x00054813u, 2u);
        }

        case 0x00054813u: {
            TP_STATIC_GUARD(0x00A902u, 0xADu, 0x4Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x074Au;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA905u, 0x0005482Bu, 4u);
        }

        case 0x0005482Bu: {
            TP_STATIC_GUARD(0x00A905u, 0xD0u, 0xF6u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA8FDu;
                if (tp_scpu_expect_next(cpu, 0x000547EBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA907u, 0x0005483Bu, 2u);
        }

        case 0x0005483Bu: {
            TP_STATIC_GUARD(0x00A907u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xA909u, 0x00054848u, 3u);
        }

        case 0x00054848u: {
            TP_STATIC_GUARD(0x00A909u, 0x22u, 0xF0u, 0xEBu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA9u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Cu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xEBF0u, 0x00375F80u, 8u);
        }

        case 0x00054868u: {
            TP_STATIC_GUARD(0x00A90Du, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA90Fu, 0x0005487Bu, 3u);
        }

        case 0x0005487Bu: {
            TP_STATIC_GUARD(0x00A90Fu, 0x9Cu, 0x72u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1872u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA912u, 0x00054893u, 4u);
        }

        case 0x00054893u: {
            TP_STATIC_GUARD(0x00A912u, 0xADu, 0x11u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0711u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA915u, 0x000548ABu, 4u);
        }

        case 0x000548ABu: {
            TP_STATIC_GUARD(0x00A915u, 0xD0u, 0x12u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA929u;
                if (tp_scpu_expect_next(cpu, 0x0005494Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA917u, 0x000548BBu, 2u);
        }

        case 0x000548BBu: {
            TP_STATIC_GUARD(0x00A917u, 0x22u, 0x31u, 0xF7u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA9u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x1Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xF731u, 0x0067B98Bu, 8u);
        }

        case 0x000548D8u: {
            TP_STATIC_GUARD(0x00A91Bu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA91Du, 0x000548EBu, 3u);
        }

        case 0x000548D9u: {
            TP_STATIC_GUARD(0x00A91Bu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA91Du, 0x000548EBu, 3u);
        }

        case 0x000548EBu: {
            TP_STATIC_GUARD(0x00A91Du, 0xADu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA920u, 0x00054903u, 4u);
        }

        case 0x00054903u: {
            TP_STATIC_GUARD(0x00A920u, 0xF0u, 0x0Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA92Eu;
                if (tp_scpu_expect_next(cpu, 0x00054973u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA922u, 0x00054913u, 2u);
        }

        case 0x00054913u: {
            TP_STATIC_GUARD(0x00A922u, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA924u, 0x00054923u, 2u);
        }

        case 0x00054923u: {
            TP_STATIC_GUARD(0x00A924u, 0x8Du, 0x4Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x074Eu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA927u, 0x0005493Bu, 4u);
        }

        case 0x0005493Bu: {
            TP_STATIC_GUARD(0x00A927u, 0x80u, 0x05u);
            TP_STATIC_EXIT(0x00u, 0xA92Eu, 0x00054973u, 3u);
        }

        case 0x0005494Bu: {
            TP_STATIC_GUARD(0x00A929u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA92Bu, 0x0005495Bu, 3u);
        }

        case 0x0005495Bu: {
            TP_STATIC_GUARD(0x00A92Bu, 0xCEu, 0x11u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0711u;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA92Eu, 0x00054973u, 6u);
        }

        case 0x00054973u: {
            TP_STATIC_GUARD(0x00A92Eu, 0x22u, 0xB5u, 0x95u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA9u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x31u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x95B5u, 0x003CADABu, 8u);
        }

        case 0x00054993u: {
            TP_STATIC_GUARD(0x00A932u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA934u, 0x000549A3u, 3u);
        }

        case 0x000549A3u: {
            TP_STATIC_GUARD(0x00A934u, 0xADu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA937u, 0x000549BBu, 4u);
        }

        case 0x000549BBu: {
            TP_STATIC_GUARD(0x00A937u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA93Cu;
                if (tp_scpu_expect_next(cpu, 0x000549E3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA939u, 0x000549CBu, 2u);
        }

        case 0x000549CBu: {
            TP_STATIC_GUARD(0x00A939u, 0x82u, 0xA3u, 0xFFu);
            TP_STATIC_EXIT(0x00u, 0xA8DFu, 0x000546FBu, 4u);
        }

        case 0x000549E3u: {
            TP_STATIC_GUARD(0x00A93Cu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA93Eu, 0x000549F3u, 3u);
        }

        case 0x000549F3u: {
            TP_STATIC_GUARD(0x00A93Eu, 0xADu, 0xC4u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1FC4u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA941u, 0x00054A0Bu, 4u);
        }

        case 0x00054A0Bu: {
            TP_STATIC_GUARD(0x00A941u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA946u;
                if (tp_scpu_expect_next(cpu, 0x00054A33u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA943u, 0x00054A1Bu, 2u);
        }

        case 0x00054A1Bu: {
            TP_STATIC_GUARD(0x00A943u, 0x82u, 0xDEu, 0x01u);
            TP_STATIC_EXIT(0x00u, 0xAB24u, 0x00055923u, 4u);
        }

        case 0x00054A33u: {
            TP_STATIC_GUARD(0x00A946u, 0x22u, 0x1Fu, 0x83u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA9u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x49u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x831Fu, 0x006418FBu, 8u);
        }

        case 0x00054A53u: {
            TP_STATIC_GUARD(0x00A94Au, 0x22u, 0xF2u, 0xD8u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA9u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x4Du) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xD8F2u, 0x003EC793u, 8u);
        }

        case 0x00054A71u: {
            TP_STATIC_GUARD(0x00A94Eu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA950u, 0x00054A81u, 3u);
        }

        case 0x00054A81u: {
            TP_STATIC_GUARD(0x00A950u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xA952u, 0x00054A91u, 3u);
        }

        case 0x00054A91u: {
            TP_STATIC_GUARD(0x00A952u, 0xADu, 0x42u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0742u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA955u, 0x00054AA9u, 5u);
        }

        case 0x00054AA9u: {
            TP_STATIC_GUARD(0x00A955u, 0x29u, 0x03u, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x0003u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA958u, 0x00054AC1u, 3u);
        }

        case 0x00054AC1u: {
            TP_STATIC_GUARD(0x00A958u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA959u, 0x00054AC9u, 3u);
        }

        case 0x00054AC9u: {
            TP_STATIC_GUARD(0x00A959u, 0xAAu);
            cpu->x = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA95Au, 0x00054AD1u, 2u);
        }

        case 0x00054AD1u: {
            TP_STATIC_GUARD(0x00A95Au, 0xBFu, 0x48u, 0xDAu, 0x01u);
            const uint32_t address = (0x01DA48u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA95Eu, 0x00054AF1u, 6u);
        }

        case 0x00054AF1u: {
            TP_STATIC_GUARD(0x00A95Eu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA961u, 0x00054B09u, 5u);
        }

        case 0x00054B09u: {
            TP_STATIC_GUARD(0x00A961u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xA963u, 0x00054B18u, 3u);
        }

        case 0x00054B18u: {
            TP_STATIC_GUARD(0x00A963u, 0xA0u, 0x62u, 0x00u);
            const uint16_t value = 0x0062u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA966u, 0x00054B30u, 3u);
        }

        case 0x00054B30u: {
            TP_STATIC_GUARD(0x00A966u, 0xB7u, 0x5Bu);
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
            cpu->pbr = 0x00u;
            cpu->pc = 0xA968u;
            if (tp_scpu_expect_next(cpu, 0x00054B40u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00054B40u: {
            TP_STATIC_GUARD(0x00A968u, 0xC9u, 0x17u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0017u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA96Bu, 0x00054B58u, 3u);
        }

        case 0x00054B58u: {
            TP_STATIC_GUARD(0x00A96Bu, 0x90u, 0x03u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA970u;
                if (tp_scpu_expect_next(cpu, 0x00054B80u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA96Du, 0x00054B68u, 2u);
        }

        case 0x00054B68u: {
            TP_STATIC_GUARD(0x00A96Du, 0xA9u, 0x17u, 0x00u);
            const uint16_t value = 0x0017u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA970u, 0x00054B80u, 3u);
        }

        case 0x00054B80u: {
            TP_STATIC_GUARD(0x00A970u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA972u, 0x00054B91u, 3u);
        }

        case 0x00054B91u: {
            TP_STATIC_GUARD(0x00A972u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xA974u, 0x00054BA1u, 3u);
        }

        case 0x00054BA1u: {
            TP_STATIC_GUARD(0x00A974u, 0xAAu);
            cpu->x = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA975u, 0x00054BA9u, 2u);
        }

        case 0x00054BA9u: {
            TP_STATIC_GUARD(0x00A975u, 0xADu, 0x8Au, 0x07u);
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
            TP_STATIC_EXIT(0x00u, 0xA978u, 0x00054BC1u, 5u);
        }

        case 0x00054BC1u: {
            TP_STATIC_GUARD(0x00A978u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA97Au, 0x00054BD3u, 3u);
        }

        case 0x00054BD3u: {
            TP_STATIC_GUARD(0x00A97Au, 0x8Du, 0x1Bu, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x211Bu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA97Du, 0x00054BEBu, 4u);
        }

        case 0x00054BEBu: {
            TP_STATIC_GUARD(0x00A97Du, 0xEBu);
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->a & 0x00FFu) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->a & 0x00FFu) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA97Eu, 0x00054BF3u, 3u);
        }

        case 0x00054BF3u: {
            TP_STATIC_GUARD(0x00A97Eu, 0x8Du, 0x1Bu, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x211Bu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA981u, 0x00054C0Bu, 4u);
        }

        case 0x00054C0Bu: {
            TP_STATIC_GUARD(0x00A981u, 0x8Eu, 0x1Cu, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x211Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA984u, 0x00054C23u, 4u);
        }

        case 0x00054C23u: {
            TP_STATIC_GUARD(0x00A984u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA986u, 0x00054C33u, 3u);
        }

        case 0x00054C33u: {
            TP_STATIC_GUARD(0x00A986u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xA988u, 0x00054C41u, 3u);
        }

        case 0x00054C41u: {
            TP_STATIC_GUARD(0x00A988u, 0xADu, 0x34u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x2134u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA98Bu, 0x00054C59u, 5u);
        }

        case 0x00054C59u: {
            TP_STATIC_GUARD(0x00A98Bu, 0xAEu, 0x36u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x2136u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA98Eu, 0x00054C71u, 4u);
        }

        case 0x00054C71u: {
            TP_STATIC_GUARD(0x00A98Eu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA990u, 0x00054C81u, 3u);
        }

        case 0x00054C81u: {
            TP_STATIC_GUARD(0x00A990u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xA992u, 0x00054C91u, 3u);
        }

        case 0x00054C91u: {
            TP_STATIC_GUARD(0x00A992u, 0x8Du, 0x53u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1853u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA995u, 0x00054CA9u, 5u);
        }

        case 0x00054CA9u: {
            TP_STATIC_GUARD(0x00A995u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA997u, 0x00054CB9u, 3u);
        }

        case 0x00054CB9u: {
            TP_STATIC_GUARD(0x00A997u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xA999u, 0x00054CC9u, 3u);
        }

        case 0x00054CC9u: {
            TP_STATIC_GUARD(0x00A999u, 0xAEu, 0xBEu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07BEu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA99Cu, 0x00054CE1u, 4u);
        }

        case 0x00054CE1u: {
            TP_STATIC_GUARD(0x00A99Cu, 0xE0u, 0x02u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x02u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA99Eu, 0x00054CF1u, 2u);
        }

        case 0x00054CF1u: {
            TP_STATIC_GUARD(0x00A99Eu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA9A3u;
                if (tp_scpu_expect_next(cpu, 0x00054D19u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA9A0u, 0x00054D01u, 2u);
        }

        case 0x00054D01u: {
            TP_STATIC_GUARD(0x00A9A0u, 0x82u, 0x10u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xA9B3u, 0x00054D99u, 4u);
        }

        case 0x00054D19u: {
            TP_STATIC_GUARD(0x00A9A3u, 0xADu, 0xFAu, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06FAu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA9A6u, 0x00054D31u, 5u);
        }

        case 0x00054D31u: {
            TP_STATIC_GUARD(0x00A9A6u, 0xC9u, 0x0Fu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Fu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA9A9u, 0x00054D49u, 3u);
        }

        case 0x00054D49u: {
            TP_STATIC_GUARD(0x00A9A9u, 0xB0u, 0x03u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA9AEu;
                if (tp_scpu_expect_next(cpu, 0x00054D71u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA9ABu, 0x00054D59u, 2u);
        }

        case 0x00054D59u: {
            TP_STATIC_GUARD(0x00A9ABu, 0x4Cu, 0xB3u, 0xA9u);
            TP_STATIC_EXIT(0x00u, 0xA9B3u, 0x00054D99u, 3u);
        }

        case 0x00054D71u: {
            TP_STATIC_GUARD(0x00A9AEu, 0xADu, 0x46u, 0x07u);
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
            TP_STATIC_EXIT(0x00u, 0xA9B1u, 0x00054D89u, 5u);
        }

        case 0x00054D89u: {
            TP_STATIC_GUARD(0x00A9B1u, 0xD0u, 0x0Eu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA9C1u;
                if (tp_scpu_expect_next(cpu, 0x00054E09u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA9B3u, 0x00054D99u, 2u);
        }

        case 0x00054D99u: {
            TP_STATIC_GUARD(0x00A9B3u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xA9B5u, 0x00054DA8u, 3u);
        }

        case 0x00054DA8u: {
            TP_STATIC_GUARD(0x00A9B5u, 0xADu, 0xD1u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18D1u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA9B8u, 0x00054DC0u, 5u);
        }

        case 0x00054DC0u: {
            TP_STATIC_GUARD(0x00A9B8u, 0xC9u, 0x02u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0002u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA9BBu, 0x00054DD8u, 3u);
        }

        case 0x00054DD8u: {
            TP_STATIC_GUARD(0x00A9BBu, 0xD0u, 0x17u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA9D4u;
                if (tp_scpu_expect_next(cpu, 0x00054EA0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA9BDu, 0x00054DE8u, 2u);
        }

        case 0x00054DE8u: {
            TP_STATIC_GUARD(0x00A9BDu, 0x22u, 0xC1u, 0xF4u, 0x0Eu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA9u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0xF4C1u, 0x0077A608u, 8u);
        }

        case 0x00054E09u: {
            TP_STATIC_GUARD(0x00A9C1u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA9C3u, 0x00054E1Bu, 3u);
        }

        case 0x00054E0Bu: {
            TP_STATIC_GUARD(0x00A9C1u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA9C3u, 0x00054E1Bu, 3u);
        }

        case 0x00054E1Bu: {
            TP_STATIC_GUARD(0x00A9C3u, 0xA9u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA9C5u, 0x00054E2Bu, 2u);
        }

        case 0x00054E2Bu: {
            TP_STATIC_GUARD(0x00A9C5u, 0x8Du, 0x34u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0034u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA9C8u, 0x00054E43u, 4u);
        }

        case 0x00054E41u: {
            TP_STATIC_GUARD(0x00A9C8u, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA9u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C1u, 8u);
        }

        case 0x00054E43u: {
            TP_STATIC_GUARD(0x00A9C8u, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA9u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C3u, 8u);
        }

        case 0x00054E63u: {
            TP_STATIC_GUARD(0x00A9CCu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA9CEu, 0x00054E73u, 3u);
        }

        case 0x00054E73u: {
            TP_STATIC_GUARD(0x00A9CEu, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA9D0u, 0x00054E83u, 2u);
        }

        case 0x00054E83u: {
            TP_STATIC_GUARD(0x00A9D0u, 0x8Du, 0x00u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4200u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA9D3u, 0x00054E9Bu, 4u);
        }

        case 0x00054E9Bu: {
            TP_STATIC_GUARD(0x00A9D3u, 0x60u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            switch (tp_scpu_context_key(cpu)) {
                case 0x0004073Bu:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            }
        }

        case 0x00054EA0u: {
            TP_STATIC_GUARD(0x00A9D4u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA9D6u, 0x00054EB3u, 3u);
        }

        case 0x00054EB3u: {
            TP_STATIC_GUARD(0x00A9D6u, 0xAEu, 0xBEu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07BEu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA9D9u, 0x00054ECBu, 4u);
        }

        case 0x00054ECBu: {
            TP_STATIC_GUARD(0x00A9D9u, 0xE0u, 0x02u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x02u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA9DBu, 0x00054EDBu, 2u);
        }

        case 0x00054EDBu: {
            TP_STATIC_GUARD(0x00A9DBu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA9E0u;
                if (tp_scpu_expect_next(cpu, 0x00054F03u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA9DDu, 0x00054EEBu, 2u);
        }

        case 0x00054EEBu: {
            TP_STATIC_GUARD(0x00A9DDu, 0x82u, 0x80u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xAA60u, 0x00055303u, 4u);
        }

        case 0x00054F03u: {
            TP_STATIC_GUARD(0x00A9E0u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA9E2u, 0x00054F13u, 3u);
        }

        case 0x00054F13u: {
            TP_STATIC_GUARD(0x00A9E2u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xA9E4u, 0x00054F21u, 3u);
        }

        case 0x00054F21u: {
            TP_STATIC_GUARD(0x00A9E4u, 0xEEu, 0xFAu, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06FAu;
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
            TP_STATIC_EXIT(0x00u, 0xA9E7u, 0x00054F39u, 8u);
        }

        case 0x00054F39u: {
            TP_STATIC_GUARD(0x00A9E7u, 0xADu, 0xFAu, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06FAu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA9EAu, 0x00054F51u, 5u);
        }

        case 0x00054F51u: {
            TP_STATIC_GUARD(0x00A9EAu, 0xC9u, 0x84u, 0x03u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0384u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA9EDu, 0x00054F69u, 3u);
        }

        case 0x00054F69u: {
            TP_STATIC_GUARD(0x00A9EDu, 0xB0u, 0xD9u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA9C8u;
                if (tp_scpu_expect_next(cpu, 0x00054E41u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA9EFu, 0x00054F79u, 2u);
        }

        case 0x00054F79u: {
            TP_STATIC_GUARD(0x00A9EFu, 0x9Cu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0746u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA9F2u, 0x00054F91u, 5u);
        }

        case 0x00054F91u: {
            TP_STATIC_GUARD(0x00A9F2u, 0xADu, 0xBFu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07BFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA9F5u, 0x00054FA9u, 5u);
        }

        case 0x00054FA9u: {
            TP_STATIC_GUARD(0x00A9F5u, 0xF0u, 0x05u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA9FCu;
                if (tp_scpu_expect_next(cpu, 0x00054FE1u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA9F7u, 0x00054FB9u, 2u);
        }

        case 0x00054FB9u: {
            TP_STATIC_GUARD(0x00A9F7u, 0xCEu, 0xBFu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07BFu;
            uint16_t old_value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(value >> 8u)) != TP_SCPU_EXECUTED ||
                tp_scpu_write8(cpu, bus, address, (uint8_t)(value & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA9FAu, 0x00054FD1u, 8u);
        }

        case 0x00054FD1u: {
            TP_STATIC_GUARD(0x00A9FAu, 0x80u, 0x64u);
            TP_STATIC_EXIT(0x00u, 0xAA60u, 0x00055301u, 3u);
        }

        case 0x00054FE1u: {
            TP_STATIC_GUARD(0x00A9FCu, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA9FEu, 0x00054FF3u, 3u);
        }

        case 0x00054FF3u: {
            TP_STATIC_GUARD(0x00A9FEu, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x00u, 0xAA00u, 0x00055002u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
