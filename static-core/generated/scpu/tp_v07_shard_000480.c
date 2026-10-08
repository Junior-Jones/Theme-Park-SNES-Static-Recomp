/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000480(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00240003u: {
            TP_STATIC_GUARD(0x048000u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x8002u, 0x00240013u, 3u);
        }

        case 0x00240013u: {
            TP_STATIC_GUARD(0x048002u, 0xA9u, 0x80u);
            const uint8_t value = 0x80u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8004u, 0x00240023u, 2u);
        }

        case 0x00240023u: {
            TP_STATIC_GUARD(0x048004u, 0x8Du, 0x00u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x2100u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8007u, 0x0024003Bu, 4u);
        }

        case 0x0024003Bu: {
            TP_STATIC_GUARD(0x048007u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x8009u, 0x0024004Bu, 3u);
        }

        case 0x0024004Bu: {
            TP_STATIC_GUARD(0x048009u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x04u, 0x800Bu, 0x0024005Au, 3u);
        }

        case 0x0024005Au: {
            TP_STATIC_GUARD(0x04800Bu, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x800Eu, 0x00240072u, 3u);
        }

        case 0x00240072u: {
            TP_STATIC_GUARD(0x04800Eu, 0xBFu, 0xA9u, 0x91u, 0x05u);
            const uint32_t address = (0x0591A9u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8012u, 0x00240092u, 5u);
        }

        case 0x00240092u: {
            TP_STATIC_GUARD(0x048012u, 0xC9u, 0x4Du);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x4Du;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8014u, 0x002400A2u, 2u);
        }

        case 0x002400A2u: {
            TP_STATIC_GUARD(0x048014u, 0xF0u, 0x14u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0x802Au;
                if (tp_scpu_expect_next(cpu, 0x00240152u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0x8016u, 0x002400B2u, 2u);
        }

        case 0x002400B2u: {
            TP_STATIC_GUARD(0x048016u, 0xC9u, 0x58u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x58u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8018u, 0x002400C2u, 2u);
        }

        case 0x002400C2u: {
            TP_STATIC_GUARD(0x048018u, 0xF0u, 0x13u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0x802Du;
                if (tp_scpu_expect_next(cpu, 0x0024016Au) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0x801Au, 0x002400D2u, 2u);
        }

        case 0x002400D2u: {
            TP_STATIC_GUARD(0x04801Au, 0x9Du, 0x00u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x2100u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x801Du, 0x002400EAu, 5u);
        }

        case 0x002400EAu: {
            TP_STATIC_GUARD(0x04801Du, 0x9Du, 0x00u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x2100u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8020u, 0x00240102u, 5u);
        }

        case 0x00240102u: {
            TP_STATIC_GUARD(0x048020u, 0xBFu, 0xDEu, 0x91u, 0x05u);
            const uint32_t address = (0x0591DEu + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8024u, 0x00240122u, 5u);
        }

        case 0x00240122u: {
            TP_STATIC_GUARD(0x048024u, 0x9Du, 0x00u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x2100u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8027u, 0x0024013Au, 5u);
        }

        case 0x0024013Au: {
            TP_STATIC_GUARD(0x048027u, 0x9Du, 0x00u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x2100u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x802Au, 0x00240152u, 5u);
        }

        case 0x00240152u: {
            TP_STATIC_GUARD(0x04802Au, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x802Bu, 0x0024015Au, 2u);
        }

        case 0x0024015Au: {
            TP_STATIC_GUARD(0x04802Bu, 0x80u, 0xE1u);
            TP_STATIC_EXIT(0x04u, 0x800Eu, 0x00240072u, 3u);
        }

        case 0x0024016Au: {
            TP_STATIC_GUARD(0x04802Du, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x802Fu, 0x0024017Au, 3u);
        }

        case 0x0024017Au: {
            TP_STATIC_GUARD(0x04802Fu, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x04u, 0x8031u, 0x0024018Au, 3u);
        }

        case 0x0024018Au: {
            TP_STATIC_GUARD(0x048031u, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8034u, 0x002401A2u, 3u);
        }

        case 0x002401A2u: {
            TP_STATIC_GUARD(0x048034u, 0xBFu, 0x13u, 0x92u, 0x05u);
            const uint32_t address = (0x059213u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8038u, 0x002401C2u, 5u);
        }

        case 0x002401C2u: {
            TP_STATIC_GUARD(0x048038u, 0xC9u, 0x58u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x58u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x803Au, 0x002401D2u, 2u);
        }

        case 0x002401D2u: {
            TP_STATIC_GUARD(0x04803Au, 0xF0u, 0x09u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0x8045u;
                if (tp_scpu_expect_next(cpu, 0x0024022Au) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0x803Cu, 0x002401E2u, 2u);
        }

        case 0x002401E2u: {
            TP_STATIC_GUARD(0x04803Cu, 0x9Du, 0x00u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4200u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x803Fu, 0x002401FAu, 5u);
        }

        case 0x002401FAu: {
            TP_STATIC_GUARD(0x04803Fu, 0x9Du, 0x00u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4200u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8042u, 0x00240212u, 5u);
        }

        case 0x00240212u: {
            TP_STATIC_GUARD(0x048042u, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8043u, 0x0024021Au, 2u);
        }

        case 0x0024021Au: {
            TP_STATIC_GUARD(0x048043u, 0x80u, 0xEFu);
            TP_STATIC_EXIT(0x04u, 0x8034u, 0x002401A2u, 3u);
        }

        case 0x0024022Au: {
            TP_STATIC_GUARD(0x048045u, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8048u, 0x00240242u, 3u);
        }

        case 0x00240242u: {
            TP_STATIC_GUARD(0x048048u, 0x9Eu, 0x00u, 0x43u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4300u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x804Bu, 0x0024025Au, 5u);
        }

        case 0x0024025Au: {
            TP_STATIC_GUARD(0x04804Bu, 0x9Eu, 0x00u, 0x43u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4300u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x804Eu, 0x00240272u, 5u);
        }

        case 0x00240272u: {
            TP_STATIC_GUARD(0x04804Eu, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x804Fu, 0x0024027Au, 2u);
        }

        case 0x0024027Au: {
            TP_STATIC_GUARD(0x04804Fu, 0xE0u, 0x7Bu, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x007Bu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8052u, 0x00240292u, 3u);
        }

        case 0x00240292u: {
            TP_STATIC_GUARD(0x048052u, 0xD0u, 0xF4u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0x8048u;
                if (tp_scpu_expect_next(cpu, 0x00240242u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0x8054u, 0x002402A2u, 2u);
        }

        case 0x002402A2u: {
            TP_STATIC_GUARD(0x048054u, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x0004013Au:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x002402A8u: {
            TP_STATIC_GUARD(0x048055u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x8057u, 0x002402B9u, 3u);
        }

        case 0x002402A9u: {
            TP_STATIC_GUARD(0x048055u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x8057u, 0x002402B9u, 3u);
        }

        case 0x002402B9u: {
            TP_STATIC_GUARD(0x048057u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0x8059u, 0x002402C9u, 3u);
        }

        case 0x002402C9u: {
            TP_STATIC_GUARD(0x048059u, 0xADu, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0016u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x805Cu, 0x002402E1u, 5u);
        }

        case 0x002402E1u: {
            TP_STATIC_GUARD(0x04805Cu, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x805Du, 0x002402E9u, 4u);
        }

        case 0x002402E9u: {
            TP_STATIC_GUARD(0x04805Du, 0xAEu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8060u, 0x00240301u, 4u);
        }

        case 0x00240301u: {
            TP_STATIC_GUARD(0x048060u, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8061u, 0x00240309u, 3u);
        }

        case 0x00240309u: {
            TP_STATIC_GUARD(0x048061u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x8063u, 0x0024031Bu, 3u);
        }

        case 0x0024031Bu: {
            TP_STATIC_GUARD(0x048063u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x04u, 0x8065u, 0x0024032Au, 3u);
        }

        case 0x0024032Au: {
            TP_STATIC_GUARD(0x048065u, 0xAEu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8068u, 0x00240342u, 5u);
        }

        case 0x00240342u: {
            TP_STATIC_GUARD(0x048068u, 0x8Eu, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0016u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x806Bu, 0x0024035Au, 5u);
        }

        case 0x0024035Au: {
            TP_STATIC_GUARD(0x04806Bu, 0xADu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x806Eu, 0x00240372u, 4u);
        }

        case 0x00240372u: {
            TP_STATIC_GUARD(0x04806Eu, 0x8Du, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0018u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8071u, 0x0024038Au, 4u);
        }

        case 0x0024038Au: {
            TP_STATIC_GUARD(0x048071u, 0xADu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Eu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8074u, 0x002403A2u, 4u);
        }

        case 0x002403A2u: {
            TP_STATIC_GUARD(0x048074u, 0xACu, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0792u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8077u, 0x002403BAu, 5u);
        }

        case 0x002403BAu: {
            TP_STATIC_GUARD(0x048077u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8078u, 0x002403C2u, 2u);
        }

        case 0x002403C2u: {
            TP_STATIC_GUARD(0x048078u, 0x97u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x04u;
            cpu->pc = 0x807Au;
            if (tp_scpu_expect_next(cpu, 0x002403D2u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x002403D2u: {
            TP_STATIC_GUARD(0x04807Au, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x807Bu, 0x002403DAu, 2u);
        }

        case 0x002403DAu: {
            TP_STATIC_GUARD(0x04807Bu, 0xC0u, 0xFFu, 0xFFu);
            const uint16_t left = cpu->y;
            const uint16_t right = 0xFFFFu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x807Eu, 0x002403F2u, 3u);
        }

        case 0x002403F2u: {
            TP_STATIC_GUARD(0x04807Eu, 0xD0u, 0xF8u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0x8078u;
                if (tp_scpu_expect_next(cpu, 0x002403C2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0x8080u, 0x00240402u, 2u);
        }

        case 0x00240402u: {
            TP_STATIC_GUARD(0x048080u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x8082u, 0x00240413u, 3u);
        }

        case 0x00240413u: {
            TP_STATIC_GUARD(0x048082u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0x8084u, 0x00240421u, 3u);
        }

        case 0x00240421u: {
            TP_STATIC_GUARD(0x048084u, 0xFAu);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8085u, 0x00240429u, 4u);
        }

        case 0x00240429u: {
            TP_STATIC_GUARD(0x048085u, 0x8Eu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8088u, 0x00240441u, 4u);
        }

        case 0x00240441u: {
            TP_STATIC_GUARD(0x048088u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8089u, 0x00240449u, 5u);
        }

        case 0x00240449u: {
            TP_STATIC_GUARD(0x048089u, 0x8Du, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0016u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x808Cu, 0x00240461u, 5u);
        }

        case 0x00240461u: {
            TP_STATIC_GUARD(0x04808Cu, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x000402E1u:
                case 0x000403C1u:
                case 0x00040499u:
                case 0x000405A9u:
                case 0x000406B1u:
                case 0x00040831u:
                case 0x00040911u:
                case 0x000F8CB1u:
                case 0x000F8D91u:
                case 0x0025AA21u:
                case 0x0035F319u:
                case 0x0035F401u:
                case 0x0035F4E1u:
                case 0x0035F5C1u:
                case 0x0035F6A1u:
                case 0x003C3DE1u:
                case 0x00645681u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00240538u: {
            TP_STATIC_GUARD(0x0480A7u, 0xC9u, 0x00u, 0x01u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0100u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x80AAu, 0x00240550u, 3u);
        }

        case 0x00240539u: {
            TP_STATIC_GUARD(0x0480A7u, 0xC9u, 0x00u, 0x01u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0100u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x80AAu, 0x00240551u, 3u);
        }

        case 0x00240550u: {
            TP_STATIC_GUARD(0x0480AAu, 0xB0u, 0xFBu);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0x80A7u;
                if (tp_scpu_expect_next(cpu, 0x00240538u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0x80ACu, 0x00240560u, 2u);
        }

        case 0x00240551u: {
            TP_STATIC_GUARD(0x0480AAu, 0xB0u, 0xFBu);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0x80A7u;
                if (tp_scpu_expect_next(cpu, 0x00240539u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0x80ACu, 0x00240561u, 2u);
        }

        case 0x00240560u: {
            TP_STATIC_GUARD(0x0480ACu, 0x8Du, 0x61u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0761u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80AFu, 0x00240578u, 5u);
        }

        case 0x00240561u: {
            TP_STATIC_GUARD(0x0480ACu, 0x8Du, 0x61u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0761u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80AFu, 0x00240579u, 5u);
        }

        case 0x00240578u: {
            TP_STATIC_GUARD(0x0480AFu, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x80B0u, 0x00240580u, 2u);
        }

        case 0x00240579u: {
            TP_STATIC_GUARD(0x0480AFu, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x80B0u, 0x00240581u, 2u);
        }

        case 0x00240580u: {
            TP_STATIC_GUARD(0x0480B0u, 0x8Du, 0x5Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x075Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80B3u, 0x00240598u, 5u);
        }

        case 0x00240581u: {
            TP_STATIC_GUARD(0x0480B0u, 0x8Du, 0x5Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x075Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80B3u, 0x00240599u, 5u);
        }

        case 0x00240598u: {
            TP_STATIC_GUARD(0x0480B3u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x80B5u, 0x002405ABu, 3u);
        }

        case 0x00240599u: {
            TP_STATIC_GUARD(0x0480B3u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x80B5u, 0x002405ABu, 3u);
        }

        case 0x002405ABu: {
            TP_STATIC_GUARD(0x0480B5u, 0xAEu, 0x61u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0761u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x80B8u, 0x002405C3u, 4u);
        }

        case 0x002405C3u: {
            TP_STATIC_GUARD(0x0480B8u, 0x8Du, 0x02u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4202u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80BBu, 0x002405DBu, 4u);
        }

        case 0x002405DBu: {
            TP_STATIC_GUARD(0x0480BBu, 0x8Eu, 0x03u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4203u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80BEu, 0x002405F3u, 4u);
        }

        case 0x002405F3u: {
            TP_STATIC_GUARD(0x0480BEu, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0x80BFu, 0x002405FBu, 2u);
        }

        case 0x002405FBu: {
            TP_STATIC_GUARD(0x0480BFu, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0x80C0u, 0x00240603u, 2u);
        }

        case 0x00240603u: {
            TP_STATIC_GUARD(0x0480C0u, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0x80C1u, 0x0024060Bu, 2u);
        }

        case 0x0024060Bu: {
            TP_STATIC_GUARD(0x0480C1u, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0x80C2u, 0x00240613u, 2u);
        }

        case 0x00240613u: {
            TP_STATIC_GUARD(0x0480C2u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0x80C4u, 0x00240620u, 3u);
        }

        case 0x00240620u: {
            TP_STATIC_GUARD(0x0480C4u, 0xADu, 0x16u, 0x42u);
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
            TP_STATIC_EXIT(0x04u, 0x80C7u, 0x00240638u, 5u);
        }

        case 0x00240638u: {
            TP_STATIC_GUARD(0x0480C7u, 0x8Du, 0x5Fu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x075Fu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80CAu, 0x00240650u, 5u);
        }

        case 0x00240650u: {
            TP_STATIC_GUARD(0x0480CAu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x80CCu, 0x00240663u, 3u);
        }

        case 0x00240663u: {
            TP_STATIC_GUARD(0x0480CCu, 0xADu, 0x5Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x075Eu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x80CFu, 0x0024067Bu, 4u);
        }

        case 0x0024067Bu: {
            TP_STATIC_GUARD(0x0480CFu, 0xAEu, 0x61u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0761u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x80D2u, 0x00240693u, 4u);
        }

        case 0x00240693u: {
            TP_STATIC_GUARD(0x0480D2u, 0x8Du, 0x02u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4202u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80D5u, 0x002406ABu, 4u);
        }

        case 0x002406ABu: {
            TP_STATIC_GUARD(0x0480D5u, 0x8Eu, 0x03u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4203u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80D8u, 0x002406C3u, 4u);
        }

        case 0x002406C3u: {
            TP_STATIC_GUARD(0x0480D8u, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0x80D9u, 0x002406CBu, 2u);
        }

        case 0x002406CBu: {
            TP_STATIC_GUARD(0x0480D9u, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0x80DAu, 0x002406D3u, 2u);
        }

        case 0x002406D3u: {
            TP_STATIC_GUARD(0x0480DAu, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0x80DBu, 0x002406DBu, 2u);
        }

        case 0x002406DBu: {
            TP_STATIC_GUARD(0x0480DBu, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0x80DCu, 0x002406E3u, 2u);
        }

        case 0x002406E3u: {
            TP_STATIC_GUARD(0x0480DCu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0x80DEu, 0x002406F0u, 3u);
        }

        case 0x002406F0u: {
            TP_STATIC_GUARD(0x0480DEu, 0xADu, 0x16u, 0x42u);
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
            TP_STATIC_EXIT(0x04u, 0x80E1u, 0x00240708u, 5u);
        }

        case 0x00240708u: {
            TP_STATIC_GUARD(0x0480E1u, 0xEBu);
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->a & 0x00FFu) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->a & 0x00FFu) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x80E2u, 0x00240710u, 3u);
        }

        case 0x00240710u: {
            TP_STATIC_GUARD(0x0480E2u, 0x29u, 0x00u, 0xFFu);
            cpu->a = (uint16_t)(cpu->a & 0xFF00u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x80E5u, 0x00240728u, 3u);
        }

        case 0x00240728u: {
            TP_STATIC_GUARD(0x0480E5u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x04u, 0x80E6u, 0x00240730u, 2u);
        }

        case 0x00240730u: {
            TP_STATIC_GUARD(0x0480E6u, 0x6Du, 0x5Fu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x075Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80E9u, 0x00240748u, 5u);
        }

        case 0x00240748u: {
            TP_STATIC_GUARD(0x0480E9u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x80EAu, 0x00240750u, 2u);
        }

        case 0x00240750u: {
            TP_STATIC_GUARD(0x0480EAu, 0x6Bu);
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)cpu->s, &return_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            switch (tp_scpu_context_key(cpu)) {
                case 0x000512E0u:
                case 0x00054028u:
                case 0x000569C0u:
                case 0x00056B20u:
                case 0x00056BB0u:
                case 0x00059C28u:
                case 0x00060618u:
                case 0x00060770u:
                case 0x000608C8u:
                case 0x00060F18u:
                case 0x000611C8u:
                case 0x00061480u:
                case 0x00061540u:
                case 0x00061B58u:
                case 0x00063A60u:
                case 0x00063D58u:
                case 0x000686B0u:
                case 0x00068EA0u:
                case 0x00069AE0u:
                case 0x0006AFF8u:
                case 0x0006B968u:
                case 0x0006BF30u:
                case 0x0006C6E8u:
                case 0x0006DED0u:
                case 0x0006E248u:
                case 0x0006F8F0u:
                case 0x000704C8u:
                case 0x00070DA0u:
                case 0x00071100u:
                case 0x00072888u:
                case 0x00072F40u:
                case 0x000735E8u:
                case 0x00076220u:
                case 0x00076478u:
                case 0x00078F48u:
                case 0x00079118u:
                case 0x00079540u:
                case 0x000796A0u:
                case 0x00079838u:
                case 0x00079D38u:
                case 0x0007A030u:
                case 0x0007A2B8u:
                case 0x0007A668u:
                case 0x0007AAB8u:
                case 0x0007AD70u:
                case 0x0007AF78u:
                case 0x0007B238u:
                case 0x0007B308u:
                case 0x0007B5C8u:
                case 0x0007B6D0u:
                case 0x0007B8D0u:
                case 0x0007BB78u:
                case 0x0007BDD8u:
                case 0x0007C158u:
                case 0x0007C358u:
                case 0x0007C940u:
                case 0x0007CB28u:
                case 0x0007D058u:
                case 0x0007D140u:
                case 0x0007D1C8u:
                case 0x0007D810u:
                case 0x0007DA10u:
                case 0x0007E948u:
                case 0x0007EA88u:
                case 0x0007EE70u:
                case 0x0007F2F0u:
                case 0x0007F3C8u:
                case 0x0007F568u:
                case 0x0007F7A0u:
                case 0x000EFC00u:
                case 0x000EFEF0u:
                case 0x000F00E8u:
                case 0x000F06B8u:
                case 0x000F0D48u:
                case 0x000F3040u:
                case 0x000F3920u:
                case 0x000F4050u:
                case 0x000F4248u:
                case 0x000F4348u:
                case 0x000FBB98u:
                case 0x00241A28u:
                case 0x00241EA8u:
                case 0x002421B0u:
                case 0x00242908u:
                case 0x00243230u:
                case 0x00243428u:
                case 0x00243830u:
                case 0x00243E10u:
                case 0x00243FE8u:
                case 0x002452D0u:
                case 0x002453C0u:
                case 0x00245750u:
                case 0x00245EF8u:
                case 0x00246028u:
                case 0x00248D30u:
                case 0x0024B230u:
                case 0x0024FFC0u:
                case 0x002503E0u:
                case 0x00250B08u:
                case 0x00251138u:
                case 0x00251470u:
                case 0x00251BF8u:
                case 0x00252D38u:
                case 0x00263730u:
                case 0x00263FF8u:
                case 0x002670F8u:
                case 0x00267438u:
                case 0x00267B48u:
                case 0x00267D10u:
                case 0x00268140u:
                case 0x00268228u:
                case 0x00268A98u:
                case 0x00268CE8u:
                case 0x00268E70u:
                case 0x00268FF0u:
                case 0x002693F8u:
                case 0x00269880u:
                case 0x0026A040u:
                case 0x0026AA60u:
                case 0x0026ABC8u:
                case 0x00270938u:
                case 0x00270C80u:
                case 0x00270F80u:
                case 0x00271FD0u:
                case 0x002787B0u:
                case 0x002C0EA0u:
                case 0x002C1C28u:
                case 0x002C2100u:
                case 0x002FF0F8u:
                case 0x00342C48u:
                case 0x003494D8u:
                case 0x003495B8u:
                case 0x003496A8u:
                case 0x00349760u:
                case 0x00349818u:
                case 0x003498D0u:
                case 0x00349988u:
                case 0x00349A40u:
                case 0x00349AF8u:
                case 0x00349BB0u:
                case 0x00349C68u:
                case 0x00349E10u:
                case 0x00349EF0u:
                case 0x0034A020u:
                case 0x0034A0D8u:
                case 0x0034A190u:
                case 0x0034A248u:
                case 0x0034A300u:
                case 0x0034A3B8u:
                case 0x0034A470u:
                case 0x0034A528u:
                case 0x0034A6D0u:
                case 0x0034A7B0u:
                case 0x0034A8D8u:
                case 0x0034A990u:
                case 0x0034AA48u:
                case 0x0034AB00u:
                case 0x0034ABB8u:
                case 0x0034AC70u:
                case 0x0034AD28u:
                case 0x0034ADE0u:
                case 0x0034AE98u:
                case 0x0034B040u:
                case 0x0034B120u:
                case 0x0034B1D8u:
                case 0x0034B290u:
                case 0x0034B348u:
                case 0x0034B400u:
                case 0x0034B4B8u:
                case 0x0034B570u:
                case 0x0034B628u:
                case 0x0034B820u:
                case 0x0034B9B0u:
                case 0x0034BB40u:
                case 0x0034BCD0u:
                case 0x0034BEF8u:
                case 0x0034BFD0u:
                case 0x0034D080u:
                case 0x0034D400u:
                case 0x0034D4A8u:
                case 0x0034D6F0u:
                case 0x0034DA68u:
                case 0x0034DB10u:
                case 0x0034DD88u:
                case 0x0034DE40u:
                case 0x0034E0A8u:
                case 0x0034E150u:
                case 0x0034E420u:
                case 0x0034E4C8u:
                case 0x0034E5B8u:
                case 0x0034E660u:
                case 0x0034E9D0u:
                case 0x0034EA78u:
                case 0x0034ED98u:
                case 0x0034EE40u:
                case 0x0034F118u:
                case 0x0034F1C0u:
                case 0x0034F488u:
                case 0x0034F530u:
                case 0x0034F790u:
                case 0x0034F838u:
                case 0x0034FAB0u:
                case 0x0034FB58u:
                case 0x0034FDD0u:
                case 0x0034FE78u:
                case 0x003500E0u:
                case 0x00350188u:
                case 0x003503D8u:
                case 0x00350638u:
                case 0x003506E0u:
                case 0x00350B18u:
                case 0x00350D60u:
                case 0x00350FC8u:
                case 0x00351070u:
                case 0x00351328u:
                case 0x00351588u:
                case 0x00351630u:
                case 0x00357B28u:
                case 0x00357C28u:
                case 0x00357EA0u:
                case 0x00357FB8u:
                case 0x00358100u:
                case 0x003581D0u:
                case 0x00358320u:
                case 0x00358428u:
                case 0x0035E2F8u:
                case 0x0035E3B8u:
                case 0x0035E488u:
                case 0x0035E548u:
                case 0x00360298u:
                case 0x00360C08u:
                case 0x00360D00u:
                case 0x00360DE0u:
                case 0x00361470u:
                case 0x00361690u:
                case 0x0036B090u:
                case 0x00371FC0u:
                case 0x003743A8u:
                case 0x003746B0u:
                case 0x003749C0u:
                case 0x00374B50u:
                case 0x00374D88u:
                case 0x00374FD0u:
                case 0x00375238u:
                case 0x00375510u:
                case 0x00375680u:
                case 0x003758E8u:
                case 0x003763D0u:
                case 0x00376920u:
                case 0x00378450u:
                case 0x00378608u:
                case 0x00378750u:
                case 0x00378828u:
                case 0x00378900u:
                case 0x003789D8u:
                case 0x00378AB0u:
                case 0x00378CE8u:
                case 0x00378F28u:
                case 0x00379168u:
                case 0x00379350u:
                case 0x00379558u:
                case 0x003797C8u:
                case 0x003799C0u:
                case 0x00379B08u:
                case 0x0037A3B8u:
                case 0x0037A590u:
                case 0x0037A630u:
                case 0x0037A6E8u:
                case 0x0037A778u:
                case 0x0037A850u:
                case 0x0037A908u:
                case 0x0037A9E0u:
                case 0x0037AAD8u:
                case 0x0037ABF0u:
                case 0x0037ACA8u:
                case 0x0037AD80u:
                case 0x0037AE58u:
                case 0x0037B028u:
                case 0x0037B108u:
                case 0x0037B1E8u:
                case 0x0037B2A0u:
                case 0x0037B378u:
                case 0x0037B430u:
                case 0x0037B508u:
                case 0x0037B600u:
                case 0x0037B748u:
                case 0x0037B820u:
                case 0x0037B8F8u:
                case 0x0037BAC8u:
                case 0x0037BBA8u:
                case 0x0037BCD0u:
                case 0x0037BD88u:
                case 0x0037BE40u:
                case 0x0037BEF8u:
                case 0x0037BFD0u:
                case 0x0037C0C8u:
                case 0x0037C1E0u:
                case 0x0037C298u:
                case 0x0037C370u:
                case 0x0037C448u:
                case 0x0037C618u:
                case 0x0037C6E0u:
                case 0x0037C770u:
                case 0x0037C848u:
                case 0x0037C900u:
                case 0x0037C9D8u:
                case 0x0037CAD0u:
                case 0x0037CC18u:
                case 0x0037CCF0u:
                case 0x0037CDC8u:
                case 0x0037E588u:
                case 0x0037E6F0u:
                case 0x003C1208u:
                case 0x003C5B48u:
                case 0x003C6538u:
                case 0x003C6D30u:
                case 0x003C7008u:
                case 0x003C76B0u:
                case 0x003C79D0u:
                case 0x003C7AE8u:
                case 0x003CA0F0u:
                case 0x003CA450u:
                case 0x003D01C0u:
                case 0x003D02C8u:
                case 0x003D03B8u:
                case 0x003D04B0u:
                case 0x003D06B8u:
                case 0x003D0798u:
                case 0x003D0878u:
                case 0x003D0958u:
                case 0x003D35A8u:
                case 0x003D4D88u:
                case 0x003D6940u:
                case 0x003D7828u:
                case 0x003D7C28u:
                case 0x003D7FC8u:
                case 0x003D9B18u:
                case 0x003DA190u:
                case 0x003DBFA8u:
                case 0x003DC1D0u:
                case 0x003DC4A8u:
                case 0x003DC738u:
                case 0x003DC9B0u:
                case 0x003DCC38u:
                case 0x003DED70u:
                case 0x003E5628u:
                case 0x003E5BA8u:
                case 0x003E5F40u:
                case 0x003E6260u:
                case 0x003E6E88u:
                case 0x003E8038u:
                case 0x003E84C8u:
                case 0x003E9028u:
                case 0x003E9720u:
                case 0x003F4F38u:
                case 0x003F8D60u:
                case 0x00643928u:
                case 0x0064D438u:
                case 0x0064DCE0u:
                case 0x0064E870u:
                case 0x0064EB10u:
                case 0x00650DC8u:
                case 0x00650E80u:
                case 0x00654B88u:
                case 0x00655E28u:
                case 0x00656D88u:
                case 0x00657700u:
                case 0x00657E60u:
                case 0x0065AC28u:
                case 0x0065BAB8u:
                case 0x0065F4A0u:
                case 0x0065F750u:
                case 0x0065F998u:
                case 0x0065FAC8u:
                case 0x006606C8u:
                case 0x00661870u:
                case 0x00661CE0u:
                case 0x00661F68u:
                case 0x00662C88u:
                case 0x00662FC8u:
                case 0x00664EA0u:
                case 0x006652F0u:
                case 0x00665428u:
                case 0x00665700u:
                case 0x00665AD8u:
                case 0x00665F10u:
                case 0x00665FF8u:
                case 0x00666178u:
                case 0x00666260u:
                case 0x006668A0u:
                case 0x00666A28u:
                case 0x006670B0u:
                case 0x00667150u:
                case 0x006672C8u:
                case 0x00667368u:
                case 0x006674C8u:
                case 0x00667568u:
                case 0x006676C8u:
                case 0x00667768u:
                case 0x006678C8u:
                case 0x00667968u:
                case 0x00667AC8u:
                case 0x00667B68u:
                case 0x006687C8u:
                case 0x006688C0u:
                case 0x00669090u:
                case 0x00669680u:
                case 0x0066B550u:
                case 0x0066B680u:
                case 0x0066B8B0u:
                case 0x0066B9D8u:
                case 0x0066C378u:
                case 0x0066C630u:
                case 0x0066C980u:
                case 0x0066E8C0u:
                case 0x0066EA88u:
                case 0x0066EB38u:
                case 0x00672810u:
                case 0x00673318u:
                case 0x006734E0u:
                case 0x00673928u:
                case 0x00673DB0u:
                case 0x006741F8u:
                case 0x00674600u:
                case 0x00675AF0u:
                case 0x00678208u:
                case 0x0067B7F0u:
                case 0x0067E6C0u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x0024075Bu: {
            TP_STATIC_GUARD(0x0480EBu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0x80EDu, 0x00240768u, 3u);
        }

        case 0x00240768u: {
            TP_STATIC_GUARD(0x0480EDu, 0xADu, 0x0Bu, 0x04u);
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
            TP_STATIC_EXIT(0x04u, 0x80F0u, 0x00240780u, 5u);
        }

        case 0x00240780u: {
            TP_STATIC_GUARD(0x0480F0u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80F1u, 0x00240788u, 4u);
        }

        case 0x00240788u: {
            TP_STATIC_GUARD(0x0480F1u, 0xADu, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x80F4u, 0x002407A0u, 5u);
        }

        case 0x002407A0u: {
            TP_STATIC_GUARD(0x0480F4u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80F5u, 0x002407A8u, 4u);
        }

        case 0x002407A8u: {
            TP_STATIC_GUARD(0x0480F5u, 0xADu, 0x0Fu, 0x04u);
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
            TP_STATIC_EXIT(0x04u, 0x80F8u, 0x002407C0u, 5u);
        }

        case 0x002407C0u: {
            TP_STATIC_GUARD(0x0480F8u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80F9u, 0x002407C8u, 4u);
        }

        case 0x002407C8u: {
            TP_STATIC_GUARD(0x0480F9u, 0xADu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x80FCu, 0x002407E0u, 5u);
        }

        case 0x002407E0u: {
            TP_STATIC_GUARD(0x0480FCu, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80FDu, 0x002407E8u, 4u);
        }

        case 0x002407E8u: {
            TP_STATIC_GUARD(0x0480FDu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x80FFu, 0x002407FBu, 3u);
        }

        case 0x002407FBu: {
            TP_STATIC_GUARD(0x0480FFu, 0xADu, 0x00u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0400u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x8102u, 0x00240813u, 4u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
