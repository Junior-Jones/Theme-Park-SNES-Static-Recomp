/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000C81(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00640800u: {
            TP_STATIC_GUARD(0x0C8100u, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8108u;
                if (tp_scpu_expect_next(cpu, 0x00640840u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8102u, 0x00640810u, 2u);
        }

        case 0x00640810u: {
            TP_STATIC_GUARD(0x0C8102u, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8105u, 0x00640828u, 3u);
        }

        case 0x00640828u: {
            TP_STATIC_GUARD(0x0C8105u, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x8108u, 0x00640840u, 8u);
        }

        case 0x00640840u: {
            TP_STATIC_GUARD(0x0C8108u, 0xC0u, 0x05u, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0005u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x810Bu, 0x00640858u, 3u);
        }

        case 0x00640858u: {
            TP_STATIC_GUARD(0x0C810Bu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8110u;
                if (tp_scpu_expect_next(cpu, 0x00640880u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x810Du, 0x00640868u, 2u);
        }

        case 0x00640868u: {
            TP_STATIC_GUARD(0x0C810Du, 0x82u, 0x3Fu, 0x01u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x00640880u: {
            TP_STATIC_GUARD(0x0C8110u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x8111u, 0x00640888u, 2u);
        }

        case 0x00640888u: {
            TP_STATIC_GUARD(0x0C8111u, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8114u, 0x006408A0u, 5u);
        }

        case 0x006408A0u: {
            TP_STATIC_GUARD(0x0C8114u, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8117u, 0x006408B8u, 3u);
        }

        case 0x006408B8u: {
            TP_STATIC_GUARD(0x0C8117u, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x811Fu;
                if (tp_scpu_expect_next(cpu, 0x006408F8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8119u, 0x006408C8u, 2u);
        }

        case 0x006408C8u: {
            TP_STATIC_GUARD(0x0C8119u, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x811Cu, 0x006408E0u, 3u);
        }

        case 0x006408E0u: {
            TP_STATIC_GUARD(0x0C811Cu, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x811Fu, 0x006408F8u, 8u);
        }

        case 0x006408F8u: {
            TP_STATIC_GUARD(0x0C811Fu, 0xC0u, 0x06u, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0006u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8122u, 0x00640910u, 3u);
        }

        case 0x00640910u: {
            TP_STATIC_GUARD(0x0C8122u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8127u;
                if (tp_scpu_expect_next(cpu, 0x00640938u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8124u, 0x00640920u, 2u);
        }

        case 0x00640920u: {
            TP_STATIC_GUARD(0x0C8124u, 0x82u, 0x28u, 0x01u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x00640938u: {
            TP_STATIC_GUARD(0x0C8127u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x8128u, 0x00640940u, 2u);
        }

        case 0x00640940u: {
            TP_STATIC_GUARD(0x0C8128u, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x812Bu, 0x00640958u, 5u);
        }

        case 0x00640958u: {
            TP_STATIC_GUARD(0x0C812Bu, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x812Eu, 0x00640970u, 3u);
        }

        case 0x00640970u: {
            TP_STATIC_GUARD(0x0C812Eu, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8136u;
                if (tp_scpu_expect_next(cpu, 0x006409B0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8130u, 0x00640980u, 2u);
        }

        case 0x00640980u: {
            TP_STATIC_GUARD(0x0C8130u, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8133u, 0x00640998u, 3u);
        }

        case 0x00640998u: {
            TP_STATIC_GUARD(0x0C8133u, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x8136u, 0x006409B0u, 8u);
        }

        case 0x006409B0u: {
            TP_STATIC_GUARD(0x0C8136u, 0xC0u, 0x07u, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0007u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8139u, 0x006409C8u, 3u);
        }

        case 0x006409C8u: {
            TP_STATIC_GUARD(0x0C8139u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x813Eu;
                if (tp_scpu_expect_next(cpu, 0x006409F0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x813Bu, 0x006409D8u, 2u);
        }

        case 0x006409D8u: {
            TP_STATIC_GUARD(0x0C813Bu, 0x82u, 0x11u, 0x01u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x006409F0u: {
            TP_STATIC_GUARD(0x0C813Eu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x813Fu, 0x006409F8u, 2u);
        }

        case 0x006409F8u: {
            TP_STATIC_GUARD(0x0C813Fu, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8142u, 0x00640A10u, 5u);
        }

        case 0x00640A10u: {
            TP_STATIC_GUARD(0x0C8142u, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8145u, 0x00640A28u, 3u);
        }

        case 0x00640A28u: {
            TP_STATIC_GUARD(0x0C8145u, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x814Du;
                if (tp_scpu_expect_next(cpu, 0x00640A68u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8147u, 0x00640A38u, 2u);
        }

        case 0x00640A38u: {
            TP_STATIC_GUARD(0x0C8147u, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x814Au, 0x00640A50u, 3u);
        }

        case 0x00640A50u: {
            TP_STATIC_GUARD(0x0C814Au, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x814Du, 0x00640A68u, 8u);
        }

        case 0x00640A68u: {
            TP_STATIC_GUARD(0x0C814Du, 0xC0u, 0x08u, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8150u, 0x00640A80u, 3u);
        }

        case 0x00640A80u: {
            TP_STATIC_GUARD(0x0C8150u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8155u;
                if (tp_scpu_expect_next(cpu, 0x00640AA8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8152u, 0x00640A90u, 2u);
        }

        case 0x00640A90u: {
            TP_STATIC_GUARD(0x0C8152u, 0x82u, 0xFAu, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x00640AA8u: {
            TP_STATIC_GUARD(0x0C8155u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x8156u, 0x00640AB0u, 2u);
        }

        case 0x00640AB0u: {
            TP_STATIC_GUARD(0x0C8156u, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8159u, 0x00640AC8u, 5u);
        }

        case 0x00640AC8u: {
            TP_STATIC_GUARD(0x0C8159u, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x815Cu, 0x00640AE0u, 3u);
        }

        case 0x00640AE0u: {
            TP_STATIC_GUARD(0x0C815Cu, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8164u;
                if (tp_scpu_expect_next(cpu, 0x00640B20u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x815Eu, 0x00640AF0u, 2u);
        }

        case 0x00640AF0u: {
            TP_STATIC_GUARD(0x0C815Eu, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8161u, 0x00640B08u, 3u);
        }

        case 0x00640B08u: {
            TP_STATIC_GUARD(0x0C8161u, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x8164u, 0x00640B20u, 8u);
        }

        case 0x00640B20u: {
            TP_STATIC_GUARD(0x0C8164u, 0xC0u, 0x09u, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0009u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8167u, 0x00640B38u, 3u);
        }

        case 0x00640B38u: {
            TP_STATIC_GUARD(0x0C8167u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x816Cu;
                if (tp_scpu_expect_next(cpu, 0x00640B60u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8169u, 0x00640B48u, 2u);
        }

        case 0x00640B48u: {
            TP_STATIC_GUARD(0x0C8169u, 0x82u, 0xE3u, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x00640B60u: {
            TP_STATIC_GUARD(0x0C816Cu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x816Du, 0x00640B68u, 2u);
        }

        case 0x00640B68u: {
            TP_STATIC_GUARD(0x0C816Du, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8170u, 0x00640B80u, 5u);
        }

        case 0x00640B80u: {
            TP_STATIC_GUARD(0x0C8170u, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8173u, 0x00640B98u, 3u);
        }

        case 0x00640B98u: {
            TP_STATIC_GUARD(0x0C8173u, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x817Bu;
                if (tp_scpu_expect_next(cpu, 0x00640BD8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8175u, 0x00640BA8u, 2u);
        }

        case 0x00640BA8u: {
            TP_STATIC_GUARD(0x0C8175u, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8178u, 0x00640BC0u, 3u);
        }

        case 0x00640BC0u: {
            TP_STATIC_GUARD(0x0C8178u, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x817Bu, 0x00640BD8u, 8u);
        }

        case 0x00640BD8u: {
            TP_STATIC_GUARD(0x0C817Bu, 0xC0u, 0x0Au, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x000Au;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x817Eu, 0x00640BF0u, 3u);
        }

        case 0x00640BF0u: {
            TP_STATIC_GUARD(0x0C817Eu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8183u;
                if (tp_scpu_expect_next(cpu, 0x00640C18u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8180u, 0x00640C00u, 2u);
        }

        case 0x00640C00u: {
            TP_STATIC_GUARD(0x0C8180u, 0x82u, 0xCCu, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x00640C18u: {
            TP_STATIC_GUARD(0x0C8183u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x8184u, 0x00640C20u, 2u);
        }

        case 0x00640C20u: {
            TP_STATIC_GUARD(0x0C8184u, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8187u, 0x00640C38u, 5u);
        }

        case 0x00640C38u: {
            TP_STATIC_GUARD(0x0C8187u, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x818Au, 0x00640C50u, 3u);
        }

        case 0x00640C50u: {
            TP_STATIC_GUARD(0x0C818Au, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8192u;
                if (tp_scpu_expect_next(cpu, 0x00640C90u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x818Cu, 0x00640C60u, 2u);
        }

        case 0x00640C60u: {
            TP_STATIC_GUARD(0x0C818Cu, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x818Fu, 0x00640C78u, 3u);
        }

        case 0x00640C78u: {
            TP_STATIC_GUARD(0x0C818Fu, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x8192u, 0x00640C90u, 8u);
        }

        case 0x00640C90u: {
            TP_STATIC_GUARD(0x0C8192u, 0xC0u, 0x0Bu, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x000Bu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8195u, 0x00640CA8u, 3u);
        }

        case 0x00640CA8u: {
            TP_STATIC_GUARD(0x0C8195u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x819Au;
                if (tp_scpu_expect_next(cpu, 0x00640CD0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8197u, 0x00640CB8u, 2u);
        }

        case 0x00640CB8u: {
            TP_STATIC_GUARD(0x0C8197u, 0x82u, 0xB5u, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x00640CD0u: {
            TP_STATIC_GUARD(0x0C819Au, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x819Bu, 0x00640CD8u, 2u);
        }

        case 0x00640CD8u: {
            TP_STATIC_GUARD(0x0C819Bu, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x819Eu, 0x00640CF0u, 5u);
        }

        case 0x00640CF0u: {
            TP_STATIC_GUARD(0x0C819Eu, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81A1u, 0x00640D08u, 3u);
        }

        case 0x00640D08u: {
            TP_STATIC_GUARD(0x0C81A1u, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x81A9u;
                if (tp_scpu_expect_next(cpu, 0x00640D48u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x81A3u, 0x00640D18u, 2u);
        }

        case 0x00640D18u: {
            TP_STATIC_GUARD(0x0C81A3u, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81A6u, 0x00640D30u, 3u);
        }

        case 0x00640D30u: {
            TP_STATIC_GUARD(0x0C81A6u, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x81A9u, 0x00640D48u, 8u);
        }

        case 0x00640D48u: {
            TP_STATIC_GUARD(0x0C81A9u, 0xC0u, 0x0Cu, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x000Cu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81ACu, 0x00640D60u, 3u);
        }

        case 0x00640D60u: {
            TP_STATIC_GUARD(0x0C81ACu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x81B1u;
                if (tp_scpu_expect_next(cpu, 0x00640D88u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x81AEu, 0x00640D70u, 2u);
        }

        case 0x00640D70u: {
            TP_STATIC_GUARD(0x0C81AEu, 0x82u, 0x9Eu, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x00640D88u: {
            TP_STATIC_GUARD(0x0C81B1u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x81B2u, 0x00640D90u, 2u);
        }

        case 0x00640D90u: {
            TP_STATIC_GUARD(0x0C81B2u, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x81B5u, 0x00640DA8u, 5u);
        }

        case 0x00640DA8u: {
            TP_STATIC_GUARD(0x0C81B5u, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81B8u, 0x00640DC0u, 3u);
        }

        case 0x00640DC0u: {
            TP_STATIC_GUARD(0x0C81B8u, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x81C0u;
                if (tp_scpu_expect_next(cpu, 0x00640E00u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x81BAu, 0x00640DD0u, 2u);
        }

        case 0x00640DD0u: {
            TP_STATIC_GUARD(0x0C81BAu, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81BDu, 0x00640DE8u, 3u);
        }

        case 0x00640DE8u: {
            TP_STATIC_GUARD(0x0C81BDu, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x81C0u, 0x00640E00u, 8u);
        }

        case 0x00640E00u: {
            TP_STATIC_GUARD(0x0C81C0u, 0xC0u, 0x0Du, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x000Du;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81C3u, 0x00640E18u, 3u);
        }

        case 0x00640E18u: {
            TP_STATIC_GUARD(0x0C81C3u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x81C8u;
                if (tp_scpu_expect_next(cpu, 0x00640E40u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x81C5u, 0x00640E28u, 2u);
        }

        case 0x00640E28u: {
            TP_STATIC_GUARD(0x0C81C5u, 0x82u, 0x87u, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x824Fu, 0x00641278u, 4u);
        }

        case 0x00640E40u: {
            TP_STATIC_GUARD(0x0C81C8u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x81C9u, 0x00640E48u, 2u);
        }

        case 0x00640E48u: {
            TP_STATIC_GUARD(0x0C81C9u, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x81CCu, 0x00640E60u, 5u);
        }

        case 0x00640E60u: {
            TP_STATIC_GUARD(0x0C81CCu, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81CFu, 0x00640E78u, 3u);
        }

        case 0x00640E78u: {
            TP_STATIC_GUARD(0x0C81CFu, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x81D7u;
                if (tp_scpu_expect_next(cpu, 0x00640EB8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x81D1u, 0x00640E88u, 2u);
        }

        case 0x00640E88u: {
            TP_STATIC_GUARD(0x0C81D1u, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81D4u, 0x00640EA0u, 3u);
        }

        case 0x00640EA0u: {
            TP_STATIC_GUARD(0x0C81D4u, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x81D7u, 0x00640EB8u, 8u);
        }

        case 0x00640EB8u: {
            TP_STATIC_GUARD(0x0C81D7u, 0xC0u, 0x0Eu, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x000Eu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81DAu, 0x00640ED0u, 3u);
        }

        case 0x00640ED0u: {
            TP_STATIC_GUARD(0x0C81DAu, 0xF0u, 0x73u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x824Fu;
                if (tp_scpu_expect_next(cpu, 0x00641278u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x81DCu, 0x00640EE0u, 2u);
        }

        case 0x00640EE0u: {
            TP_STATIC_GUARD(0x0C81DCu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x81DDu, 0x00640EE8u, 2u);
        }

        case 0x00640EE8u: {
            TP_STATIC_GUARD(0x0C81DDu, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x81E0u, 0x00640F00u, 5u);
        }

        case 0x00640F00u: {
            TP_STATIC_GUARD(0x0C81E0u, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81E3u, 0x00640F18u, 3u);
        }

        case 0x00640F18u: {
            TP_STATIC_GUARD(0x0C81E3u, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x81EBu;
                if (tp_scpu_expect_next(cpu, 0x00640F58u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x81E5u, 0x00640F28u, 2u);
        }

        case 0x00640F28u: {
            TP_STATIC_GUARD(0x0C81E5u, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81E8u, 0x00640F40u, 3u);
        }

        case 0x00640F40u: {
            TP_STATIC_GUARD(0x0C81E8u, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x81EBu, 0x00640F58u, 8u);
        }

        case 0x00640F58u: {
            TP_STATIC_GUARD(0x0C81EBu, 0xC0u, 0x0Fu, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x000Fu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81EEu, 0x00640F70u, 3u);
        }

        case 0x00640F70u: {
            TP_STATIC_GUARD(0x0C81EEu, 0xF0u, 0x5Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x824Fu;
                if (tp_scpu_expect_next(cpu, 0x00641278u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x81F0u, 0x00640F80u, 2u);
        }

        case 0x00640F80u: {
            TP_STATIC_GUARD(0x0C81F0u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x0Cu, 0x81F1u, 0x00640F88u, 2u);
        }

        case 0x00640F88u: {
            TP_STATIC_GUARD(0x0C81F1u, 0x6Du, 0x21u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0421u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x81F4u, 0x00640FA0u, 5u);
        }

        case 0x00640FA0u: {
            TP_STATIC_GUARD(0x0C81F4u, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81F7u, 0x00640FB8u, 3u);
        }

        case 0x00640FB8u: {
            TP_STATIC_GUARD(0x0C81F7u, 0xB0u, 0x06u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x81FFu;
                if (tp_scpu_expect_next(cpu, 0x00640FF8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x81F9u, 0x00640FC8u, 2u);
        }

        case 0x00640FC8u: {
            TP_STATIC_GUARD(0x0C81F9u, 0xA9u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x81FCu, 0x00640FE0u, 3u);
        }

        case 0x00640FE0u: {
            TP_STATIC_GUARD(0x0C81FCu, 0xEEu, 0x2Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x042Bu;
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
            TP_STATIC_EXIT(0x0Cu, 0x81FFu, 0x00640FF8u, 8u);
        }

        case 0x00640FF8u: {
            TP_STATIC_GUARD(0x0C81FFu, 0xC0u, 0x10u, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0010u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8202u, 0x00641010u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
