/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0001F3(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x000F9808u: {
            TP_STATIC_GUARD(0x01F301u, 0x22u, 0xFBu, 0xF1u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF3u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x04u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xF1FBu, 0x00678FD8u, 8u);
        }

        case 0x000F982Bu: {
            TP_STATIC_GUARD(0x01F305u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xF307u, 0x000F983Bu, 3u);
        }

        case 0x000F983Bu: {
            TP_STATIC_GUARD(0x01F307u, 0xADu, 0x4Au, 0x07u);
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
            TP_STATIC_EXIT(0x01u, 0xF30Au, 0x000F9853u, 4u);
        }

        case 0x000F9853u: {
            TP_STATIC_GUARD(0x01F30Au, 0xD0u, 0xFBu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF307u;
                if (tp_scpu_expect_next(cpu, 0x000F983Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF30Cu, 0x000F9863u, 2u);
        }

        case 0x000F9863u: {
            TP_STATIC_GUARD(0x01F30Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xF30Eu, 0x000F9870u, 3u);
        }

        case 0x000F9870u: {
            TP_STATIC_GUARD(0x01F30Eu, 0xAEu, 0x44u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0744u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF311u, 0x000F9888u, 5u);
        }

        case 0x000F9888u: {
            TP_STATIC_GUARD(0x01F311u, 0x8Eu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0746u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF314u, 0x000F98A0u, 5u);
        }

        case 0x000F98A0u: {
            TP_STATIC_GUARD(0x01F314u, 0x22u, 0x98u, 0x9Du, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF3u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x17u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9D98u, 0x0064ECC0u, 8u);
        }

        case 0x000F98C3u: {
            TP_STATIC_GUARD(0x01F318u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xF31Au, 0x000F98D3u, 3u);
        }

        case 0x000F98D3u: {
            TP_STATIC_GUARD(0x01F31Au, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF31Du, 0x000F98EBu, 4u);
        }

        case 0x000F98EBu: {
            TP_STATIC_GUARD(0x01F31Du, 0x29u, 0x08u);
            const uint8_t value = (uint8_t)(cpu->a & 0x08u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF31Fu, 0x000F98FBu, 2u);
        }

        case 0x000F98FBu: {
            TP_STATIC_GUARD(0x01F31Fu, 0xF0u, 0x22u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF343u;
                if (tp_scpu_expect_next(cpu, 0x000F9A1Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF321u, 0x000F990Bu, 2u);
        }

        case 0x000F990Bu: {
            TP_STATIC_GUARD(0x01F321u, 0xADu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF324u, 0x000F9923u, 4u);
        }

        case 0x000F9923u: {
            TP_STATIC_GUARD(0x01F324u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF329u;
                if (tp_scpu_expect_next(cpu, 0x000F994Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF326u, 0x000F9933u, 2u);
        }

        case 0x000F9933u: {
            TP_STATIC_GUARD(0x01F326u, 0x82u, 0x90u, 0x00u);
            TP_STATIC_EXIT(0x01u, 0xF3B9u, 0x000F9DCBu, 4u);
        }

        case 0x000F994Bu: {
            TP_STATIC_GUARD(0x01F329u, 0xCEu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF32Cu, 0x000F9963u, 6u);
        }

        case 0x000F9963u: {
            TP_STATIC_GUARD(0x01F32Cu, 0xADu, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0413u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF32Fu, 0x000F997Bu, 4u);
        }

        case 0x000F997Bu: {
            TP_STATIC_GUARD(0x01F32Fu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xF330u, 0x000F9983u, 2u);
        }

        case 0x000F9983u: {
            TP_STATIC_GUARD(0x01F330u, 0xE9u, 0x09u);
            if (tp_scpu_sbc(cpu, 0x09u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF332u, 0x000F9993u, 2u);
        }

        case 0x000F9993u: {
            TP_STATIC_GUARD(0x01F332u, 0x8Du, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0413u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF335u, 0x000F99ABu, 4u);
        }

        case 0x000F99ABu: {
            TP_STATIC_GUARD(0x01F335u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xF337u, 0x000F99B8u, 3u);
        }

        case 0x000F99B8u: {
            TP_STATIC_GUARD(0x01F337u, 0xADu, 0x2Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF33Au, 0x000F99D0u, 5u);
        }

        case 0x000F99D0u: {
            TP_STATIC_GUARD(0x01F33Au, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xF33Bu, 0x000F99D8u, 2u);
        }

        case 0x000F99D8u: {
            TP_STATIC_GUARD(0x01F33Bu, 0xE9u, 0x00u, 0x10u);
            if (tp_scpu_sbc(cpu, 0x1000u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF33Eu, 0x000F99F0u, 3u);
        }

        case 0x000F99F0u: {
            TP_STATIC_GUARD(0x01F33Eu, 0x8Du, 0x11u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0411u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF341u, 0x000F9A08u, 5u);
        }

        case 0x000F9A08u: {
            TP_STATIC_GUARD(0x01F341u, 0x80u, 0x76u);
            TP_STATIC_EXIT(0x01u, 0xF3B9u, 0x000F9DC8u, 3u);
        }

        case 0x000F9A1Bu: {
            TP_STATIC_GUARD(0x01F343u, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF346u, 0x000F9A33u, 4u);
        }

        case 0x000F9A33u: {
            TP_STATIC_GUARD(0x01F346u, 0x29u, 0x04u);
            const uint8_t value = (uint8_t)(cpu->a & 0x04u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF348u, 0x000F9A43u, 2u);
        }

        case 0x000F9A43u: {
            TP_STATIC_GUARD(0x01F348u, 0xF0u, 0x21u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF36Bu;
                if (tp_scpu_expect_next(cpu, 0x000F9B5Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF34Au, 0x000F9A53u, 2u);
        }

        case 0x000F9A53u: {
            TP_STATIC_GUARD(0x01F34Au, 0xADu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF34Du, 0x000F9A6Bu, 4u);
        }

        case 0x000F9A6Bu: {
            TP_STATIC_GUARD(0x01F34Du, 0xC9u, 0x02u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x02u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF34Fu, 0x000F9A7Bu, 2u);
        }

        case 0x000F9A7Bu: {
            TP_STATIC_GUARD(0x01F34Fu, 0xF0u, 0x68u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF3B9u;
                if (tp_scpu_expect_next(cpu, 0x000F9DCBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF351u, 0x000F9A8Bu, 2u);
        }

        case 0x000F9A8Bu: {
            TP_STATIC_GUARD(0x01F351u, 0xEEu, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Bu;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF354u, 0x000F9AA3u, 6u);
        }

        case 0x000F9AA3u: {
            TP_STATIC_GUARD(0x01F354u, 0xADu, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0413u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF357u, 0x000F9ABBu, 4u);
        }

        case 0x000F9ABBu: {
            TP_STATIC_GUARD(0x01F357u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xF358u, 0x000F9AC3u, 2u);
        }

        case 0x000F9AC3u: {
            TP_STATIC_GUARD(0x01F358u, 0x69u, 0x09u);
            if (tp_scpu_adc(cpu, 0x09u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF35Au, 0x000F9AD3u, 2u);
        }

        case 0x000F9AD3u: {
            TP_STATIC_GUARD(0x01F35Au, 0x8Du, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0413u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF35Du, 0x000F9AEBu, 4u);
        }

        case 0x000F9AEBu: {
            TP_STATIC_GUARD(0x01F35Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xF35Fu, 0x000F9AF8u, 3u);
        }

        case 0x000F9AF8u: {
            TP_STATIC_GUARD(0x01F35Fu, 0xADu, 0x2Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF362u, 0x000F9B10u, 5u);
        }

        case 0x000F9B10u: {
            TP_STATIC_GUARD(0x01F362u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xF363u, 0x000F9B18u, 2u);
        }

        case 0x000F9B18u: {
            TP_STATIC_GUARD(0x01F363u, 0x69u, 0x00u, 0x10u);
            if (tp_scpu_adc(cpu, 0x1000u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF366u, 0x000F9B30u, 3u);
        }

        case 0x000F9B30u: {
            TP_STATIC_GUARD(0x01F366u, 0x8Du, 0x11u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0411u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF369u, 0x000F9B48u, 5u);
        }

        case 0x000F9B48u: {
            TP_STATIC_GUARD(0x01F369u, 0x80u, 0x4Eu);
            TP_STATIC_EXIT(0x01u, 0xF3B9u, 0x000F9DC8u, 3u);
        }

        case 0x000F9B5Bu: {
            TP_STATIC_GUARD(0x01F36Bu, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF36Eu, 0x000F9B73u, 4u);
        }

        case 0x000F9B73u: {
            TP_STATIC_GUARD(0x01F36Eu, 0x29u, 0x02u);
            const uint8_t value = (uint8_t)(cpu->a & 0x02u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF370u, 0x000F9B83u, 2u);
        }

        case 0x000F9B83u: {
            TP_STATIC_GUARD(0x01F370u, 0xF0u, 0x1Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF391u;
                if (tp_scpu_expect_next(cpu, 0x000F9C8Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF372u, 0x000F9B93u, 2u);
        }

        case 0x000F9B93u: {
            TP_STATIC_GUARD(0x01F372u, 0xADu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF375u, 0x000F9BABu, 4u);
        }

        case 0x000F9BABu: {
            TP_STATIC_GUARD(0x01F375u, 0xF0u, 0x42u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF3B9u;
                if (tp_scpu_expect_next(cpu, 0x000F9DCBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF377u, 0x000F9BBBu, 2u);
        }

        case 0x000F9BBBu: {
            TP_STATIC_GUARD(0x01F377u, 0xCEu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF37Au, 0x000F9BD3u, 6u);
        }

        case 0x000F9BD3u: {
            TP_STATIC_GUARD(0x01F37Au, 0xADu, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0413u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF37Du, 0x000F9BEBu, 4u);
        }

        case 0x000F9BEBu: {
            TP_STATIC_GUARD(0x01F37Du, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xF37Eu, 0x000F9BF3u, 2u);
        }

        case 0x000F9BF3u: {
            TP_STATIC_GUARD(0x01F37Eu, 0xE9u, 0x01u);
            if (tp_scpu_sbc(cpu, 0x01u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF380u, 0x000F9C03u, 2u);
        }

        case 0x000F9C03u: {
            TP_STATIC_GUARD(0x01F380u, 0x8Du, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0413u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF383u, 0x000F9C1Bu, 4u);
        }

        case 0x000F9C1Bu: {
            TP_STATIC_GUARD(0x01F383u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xF385u, 0x000F9C28u, 3u);
        }

        case 0x000F9C28u: {
            TP_STATIC_GUARD(0x01F385u, 0xADu, 0x2Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF388u, 0x000F9C40u, 5u);
        }

        case 0x000F9C40u: {
            TP_STATIC_GUARD(0x01F388u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xF389u, 0x000F9C48u, 2u);
        }

        case 0x000F9C48u: {
            TP_STATIC_GUARD(0x01F389u, 0xE9u, 0x10u, 0x00u);
            if (tp_scpu_sbc(cpu, 0x0010u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF38Cu, 0x000F9C60u, 3u);
        }

        case 0x000F9C60u: {
            TP_STATIC_GUARD(0x01F38Cu, 0x8Du, 0x11u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0411u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF38Fu, 0x000F9C78u, 5u);
        }

        case 0x000F9C78u: {
            TP_STATIC_GUARD(0x01F38Fu, 0x80u, 0x28u);
            TP_STATIC_EXIT(0x01u, 0xF3B9u, 0x000F9DC8u, 3u);
        }

        case 0x000F9C8Bu: {
            TP_STATIC_GUARD(0x01F391u, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF394u, 0x000F9CA3u, 4u);
        }

        case 0x000F9CA3u: {
            TP_STATIC_GUARD(0x01F394u, 0x29u, 0x01u);
            const uint8_t value = (uint8_t)(cpu->a & 0x01u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF396u, 0x000F9CB3u, 2u);
        }

        case 0x000F9CB3u: {
            TP_STATIC_GUARD(0x01F396u, 0xF0u, 0x21u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF3B9u;
                if (tp_scpu_expect_next(cpu, 0x000F9DCBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF398u, 0x000F9CC3u, 2u);
        }

        case 0x000F9CC3u: {
            TP_STATIC_GUARD(0x01F398u, 0xADu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF39Bu, 0x000F9CDBu, 4u);
        }

        case 0x000F9CDBu: {
            TP_STATIC_GUARD(0x01F39Bu, 0xC9u, 0x08u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x08u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF39Du, 0x000F9CEBu, 2u);
        }

        case 0x000F9CEBu: {
            TP_STATIC_GUARD(0x01F39Du, 0xF0u, 0x1Au);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF3B9u;
                if (tp_scpu_expect_next(cpu, 0x000F9DCBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF39Fu, 0x000F9CFBu, 2u);
        }

        case 0x000F9CFBu: {
            TP_STATIC_GUARD(0x01F39Fu, 0xEEu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF3A2u, 0x000F9D13u, 6u);
        }

        case 0x000F9D13u: {
            TP_STATIC_GUARD(0x01F3A2u, 0xADu, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0413u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3A5u, 0x000F9D2Bu, 4u);
        }

        case 0x000F9D2Bu: {
            TP_STATIC_GUARD(0x01F3A5u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xF3A6u, 0x000F9D33u, 2u);
        }

        case 0x000F9D33u: {
            TP_STATIC_GUARD(0x01F3A6u, 0x69u, 0x01u);
            if (tp_scpu_adc(cpu, 0x01u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF3A8u, 0x000F9D43u, 2u);
        }

        case 0x000F9D43u: {
            TP_STATIC_GUARD(0x01F3A8u, 0x8Du, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0413u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF3ABu, 0x000F9D5Bu, 4u);
        }

        case 0x000F9D5Bu: {
            TP_STATIC_GUARD(0x01F3ABu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xF3ADu, 0x000F9D68u, 3u);
        }

        case 0x000F9D68u: {
            TP_STATIC_GUARD(0x01F3ADu, 0xADu, 0x2Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3B0u, 0x000F9D80u, 5u);
        }

        case 0x000F9D80u: {
            TP_STATIC_GUARD(0x01F3B0u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x01u, 0xF3B1u, 0x000F9D88u, 2u);
        }

        case 0x000F9D88u: {
            TP_STATIC_GUARD(0x01F3B1u, 0x69u, 0x10u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0010u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF3B4u, 0x000F9DA0u, 3u);
        }

        case 0x000F9DA0u: {
            TP_STATIC_GUARD(0x01F3B4u, 0x8Du, 0x11u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0411u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF3B7u, 0x000F9DB8u, 5u);
        }

        case 0x000F9DB8u: {
            TP_STATIC_GUARD(0x01F3B7u, 0x80u, 0x00u);
            TP_STATIC_EXIT(0x01u, 0xF3B9u, 0x000F9DC8u, 3u);
        }

        case 0x000F9DC8u: {
            TP_STATIC_GUARD(0x01F3B9u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xF3BBu, 0x000F9DDBu, 3u);
        }

        case 0x000F9DCBu: {
            TP_STATIC_GUARD(0x01F3B9u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xF3BBu, 0x000F9DDBu, 3u);
        }

        case 0x000F9DDBu: {
            TP_STATIC_GUARD(0x01F3BBu, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3BEu, 0x000F9DF3u, 4u);
        }

        case 0x000F9DF3u: {
            TP_STATIC_GUARD(0x01F3BEu, 0xC9u, 0x40u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x40u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3C0u, 0x000F9E03u, 2u);
        }

        case 0x000F9E03u: {
            TP_STATIC_GUARD(0x01F3C0u, 0xD0u, 0x34u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF3F6u;
                if (tp_scpu_expect_next(cpu, 0x000F9FB3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF3C2u, 0x000F9E13u, 2u);
        }

        case 0x000F9E13u: {
            TP_STATIC_GUARD(0x01F3C2u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xF3C4u, 0x000F9E23u, 3u);
        }

        case 0x000F9E23u: {
            TP_STATIC_GUARD(0x01F3C4u, 0xA9u, 0x0Au);
            const uint8_t value = 0x0Au;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3C6u, 0x000F9E33u, 2u);
        }

        case 0x000F9E33u: {
            TP_STATIC_GUARD(0x01F3C6u, 0x8Du, 0x8Cu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF3C9u, 0x000F9E4Bu, 4u);
        }

        case 0x000F9E4Bu: {
            TP_STATIC_GUARD(0x01F3C9u, 0x22u, 0x49u, 0x87u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF3u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCCu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8749u, 0x00643A4Bu, 8u);
        }

        case 0x000F9E6Bu: {
            TP_STATIC_GUARD(0x01F3CDu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xF3CFu, 0x000F9E7Bu, 3u);
        }

        case 0x000F9E7Bu: {
            TP_STATIC_GUARD(0x01F3CFu, 0xAEu, 0x13u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0413u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3D2u, 0x000F9E93u, 4u);
        }

        case 0x000F9E93u: {
            TP_STATIC_GUARD(0x01F3D2u, 0xBFu, 0xF7u, 0xF7u, 0x01u);
            const uint32_t address = (0x01F7F7u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3D6u, 0x000F9EB3u, 5u);
        }

        case 0x000F9EB3u: {
            TP_STATIC_GUARD(0x01F3D6u, 0xACu, 0x0Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Fu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3D9u, 0x000F9ECBu, 4u);
        }

        case 0x000F9ECBu: {
            TP_STATIC_GUARD(0x01F3D9u, 0xC0u, 0x0Au);
            const uint8_t left = (uint8_t)(cpu->y & 0x00FFu);
            const uint8_t right = 0x0Au;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3DBu, 0x000F9EDBu, 2u);
        }

        case 0x000F9EDBu: {
            TP_STATIC_GUARD(0x01F3DBu, 0x90u, 0x01u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF3DEu;
                if (tp_scpu_expect_next(cpu, 0x000F9EF3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF3DDu, 0x000F9EEBu, 2u);
        }

        case 0x000F9EEBu: {
            TP_STATIC_GUARD(0x01F3DDu, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3DEu, 0x000F9EF3u, 2u);
        }

        case 0x000F9EF3u: {
            TP_STATIC_GUARD(0x01F3DEu, 0x99u, 0xB7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18B7u + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF3E1u, 0x000F9F0Bu, 5u);
        }

        case 0x000F9F0Bu: {
            TP_STATIC_GUARD(0x01F3E1u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3E2u, 0x000F9F13u, 2u);
        }

        case 0x000F9F13u: {
            TP_STATIC_GUARD(0x01F3E2u, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3E4u, 0x000F9F23u, 2u);
        }

        case 0x000F9F23u: {
            TP_STATIC_GUARD(0x01F3E4u, 0x99u, 0xB7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18B7u + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xF3E7u, 0x000F9F3Bu, 5u);
        }

        case 0x000F9F3Bu: {
            TP_STATIC_GUARD(0x01F3E7u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x01u, 0xF3E9u, 0x000F9F48u, 3u);
        }

        case 0x000F9F48u: {
            TP_STATIC_GUARD(0x01F3E9u, 0xADu, 0x0Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3ECu, 0x000F9F60u, 5u);
        }

        case 0x000F9F60u: {
            TP_STATIC_GUARD(0x01F3ECu, 0xC9u, 0x0Au, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Au;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3EFu, 0x000F9F78u, 3u);
        }

        case 0x000F9F78u: {
            TP_STATIC_GUARD(0x01F3EFu, 0xB0u, 0x03u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF3F4u;
                if (tp_scpu_expect_next(cpu, 0x000F9FA0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF3F1u, 0x000F9F88u, 2u);
        }

        case 0x000F9F88u: {
            TP_STATIC_GUARD(0x01F3F1u, 0xEEu, 0x0Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Fu;
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
            TP_STATIC_EXIT(0x01u, 0xF3F4u, 0x000F9FA0u, 8u);
        }

        case 0x000F9FA0u: {
            TP_STATIC_GUARD(0x01F3F4u, 0x80u, 0x56u);
            TP_STATIC_EXIT(0x01u, 0xF44Cu, 0x000FA260u, 3u);
        }

        case 0x000F9FB3u: {
            TP_STATIC_GUARD(0x01F3F6u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x01u, 0xF3F8u, 0x000F9FC3u, 3u);
        }

        case 0x000F9FC3u: {
            TP_STATIC_GUARD(0x01F3F8u, 0xADu, 0x46u, 0x07u);
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
            TP_STATIC_EXIT(0x01u, 0xF3FBu, 0x000F9FDBu, 4u);
        }

        case 0x000F9FDBu: {
            TP_STATIC_GUARD(0x01F3FBu, 0xC9u, 0x40u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x40u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF3FDu, 0x000F9FEBu, 2u);
        }

        case 0x000F9FEBu: {
            TP_STATIC_GUARD(0x01F3FDu, 0xF0u, 0x52u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x01u;
                cpu->pc = 0xF451u;
                if (tp_scpu_expect_next(cpu, 0x000FA28Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x01u, 0xF3FFu, 0x000F9FFBu, 2u);
        }

        case 0x000F9FFBu: {
            TP_STATIC_GUARD(0x01F3FFu, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x01u, 0xF402u, 0x000FA013u, 4u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
