/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0006DA(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x0036D010u: {
            TP_STATIC_GUARD(0x06DA02u, 0x8Fu, 0x18u, 0x72u, 0x7Eu);
            const uint32_t address = 0x7E7218u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA06u, 0x0036D030u, 6u);
        }

        case 0x0036D030u: {
            TP_STATIC_GUARD(0x06DA06u, 0xA9u, 0x3Bu, 0x35u);
            const uint16_t value = 0x353Bu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA09u, 0x0036D048u, 3u);
        }

        case 0x0036D048u: {
            TP_STATIC_GUARD(0x06DA09u, 0x8Fu, 0x1Au, 0x72u, 0x7Eu);
            const uint32_t address = 0x7E721Au;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA0Du, 0x0036D068u, 6u);
        }

        case 0x0036D068u: {
            TP_STATIC_GUARD(0x06DA0Du, 0xA9u, 0x3Cu, 0x35u);
            const uint16_t value = 0x353Cu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA10u, 0x0036D080u, 3u);
        }

        case 0x0036D080u: {
            TP_STATIC_GUARD(0x06DA10u, 0x8Fu, 0x1Cu, 0x72u, 0x7Eu);
            const uint32_t address = 0x7E721Cu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA14u, 0x0036D0A0u, 6u);
        }

        case 0x0036D0A0u: {
            TP_STATIC_GUARD(0x06DA14u, 0xA0u, 0x8Eu, 0x00u);
            const uint16_t value = 0x008Eu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA17u, 0x0036D0B8u, 3u);
        }

        case 0x0036D0B8u: {
            TP_STATIC_GUARD(0x06DA17u, 0xB7u, 0x5Bu);
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
            cpu->pbr = 0x06u;
            cpu->pc = 0xDA19u;
            if (tp_scpu_expect_next(cpu, 0x0036D0C8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036D0C8u: {
            TP_STATIC_GUARD(0x06DA19u, 0x30u, 0x02u);
            if ((cpu->p & TP_P_N) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDA1Du;
                if (tp_scpu_expect_next(cpu, 0x0036D0E8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDA1Bu, 0x0036D0D8u, 2u);
        }

        case 0x0036D0D8u: {
            TP_STATIC_GUARD(0x06DA1Bu, 0x10u, 0x26u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDA43u;
                if (tp_scpu_expect_next(cpu, 0x0036D218u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDA1Du, 0x0036D0E8u, 2u);
        }

        case 0x0036D0E8u: {
            TP_STATIC_GUARD(0x06DA1Du, 0xA9u, 0xFFu, 0xFFu);
            const uint16_t value = 0xFFFFu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA20u, 0x0036D100u, 3u);
        }

        case 0x0036D100u: {
            TP_STATIC_GUARD(0x06DA20u, 0x8Du, 0x26u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1926u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA23u, 0x0036D118u, 5u);
        }

        case 0x0036D118u: {
            TP_STATIC_GUARD(0x06DA23u, 0xA9u, 0x49u, 0x2Du);
            const uint16_t value = 0x2D49u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA26u, 0x0036D130u, 3u);
        }

        case 0x0036D130u: {
            TP_STATIC_GUARD(0x06DA26u, 0x8Fu, 0x94u, 0x71u, 0x7Eu);
            const uint32_t address = 0x7E7194u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA2Au, 0x0036D150u, 6u);
        }

        case 0x0036D150u: {
            TP_STATIC_GUARD(0x06DA2Au, 0xA9u, 0x4Du, 0x2Du);
            const uint16_t value = 0x2D4Du;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA2Du, 0x0036D168u, 3u);
        }

        case 0x0036D168u: {
            TP_STATIC_GUARD(0x06DA2Du, 0x8Fu, 0x14u, 0x72u, 0x7Eu);
            const uint32_t address = 0x7E7214u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA31u, 0x0036D188u, 6u);
        }

        case 0x0036D188u: {
            TP_STATIC_GUARD(0x06DA31u, 0xA9u, 0x4Eu, 0x2Du);
            const uint16_t value = 0x2D4Eu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA34u, 0x0036D1A0u, 3u);
        }

        case 0x0036D1A0u: {
            TP_STATIC_GUARD(0x06DA34u, 0x8Fu, 0x16u, 0x72u, 0x7Eu);
            const uint32_t address = 0x7E7216u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA38u, 0x0036D1C0u, 6u);
        }

        case 0x0036D1C0u: {
            TP_STATIC_GUARD(0x06DA38u, 0xA9u, 0x4Au, 0x2Du);
            const uint16_t value = 0x2D4Au;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA3Bu, 0x0036D1D8u, 3u);
        }

        case 0x0036D1D8u: {
            TP_STATIC_GUARD(0x06DA3Bu, 0xA2u, 0x4Bu, 0x2Du);
            const uint16_t value = 0x2D4Bu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA3Eu, 0x0036D1F0u, 3u);
        }

        case 0x0036D1F0u: {
            TP_STATIC_GUARD(0x06DA3Eu, 0xA0u, 0x4Cu, 0x2Du);
            const uint16_t value = 0x2D4Cu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA41u, 0x0036D208u, 3u);
        }

        case 0x0036D208u: {
            TP_STATIC_GUARD(0x06DA41u, 0x80u, 0x4Cu);
            TP_STATIC_EXIT(0x06u, 0xDA8Fu, 0x0036D478u, 3u);
        }

        case 0x0036D218u: {
            TP_STATIC_GUARD(0x06DA43u, 0xC9u, 0xFEu, 0x01u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x01FEu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA46u, 0x0036D230u, 3u);
        }

        case 0x0036D230u: {
            TP_STATIC_GUARD(0x06DA46u, 0x90u, 0x23u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDA6Bu;
                if (tp_scpu_expect_next(cpu, 0x0036D358u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDA48u, 0x0036D240u, 2u);
        }

        case 0x0036D240u: {
            TP_STATIC_GUARD(0x06DA48u, 0x9Cu, 0x26u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1926u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA4Bu, 0x0036D258u, 5u);
        }

        case 0x0036D258u: {
            TP_STATIC_GUARD(0x06DA4Bu, 0xA9u, 0x3Du, 0x2Du);
            const uint16_t value = 0x2D3Du;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA4Eu, 0x0036D270u, 3u);
        }

        case 0x0036D270u: {
            TP_STATIC_GUARD(0x06DA4Eu, 0x8Fu, 0x94u, 0x71u, 0x7Eu);
            const uint32_t address = 0x7E7194u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA52u, 0x0036D290u, 6u);
        }

        case 0x0036D290u: {
            TP_STATIC_GUARD(0x06DA52u, 0xA9u, 0x41u, 0x2Du);
            const uint16_t value = 0x2D41u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA55u, 0x0036D2A8u, 3u);
        }

        case 0x0036D2A8u: {
            TP_STATIC_GUARD(0x06DA55u, 0x8Fu, 0x14u, 0x72u, 0x7Eu);
            const uint32_t address = 0x7E7214u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA59u, 0x0036D2C8u, 6u);
        }

        case 0x0036D2C8u: {
            TP_STATIC_GUARD(0x06DA59u, 0xA9u, 0x42u, 0x2Du);
            const uint16_t value = 0x2D42u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA5Cu, 0x0036D2E0u, 3u);
        }

        case 0x0036D2E0u: {
            TP_STATIC_GUARD(0x06DA5Cu, 0x8Fu, 0x16u, 0x72u, 0x7Eu);
            const uint32_t address = 0x7E7216u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA60u, 0x0036D300u, 6u);
        }

        case 0x0036D300u: {
            TP_STATIC_GUARD(0x06DA60u, 0xA9u, 0x3Eu, 0x2Du);
            const uint16_t value = 0x2D3Eu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA63u, 0x0036D318u, 3u);
        }

        case 0x0036D318u: {
            TP_STATIC_GUARD(0x06DA63u, 0xA2u, 0x3Fu, 0x2Du);
            const uint16_t value = 0x2D3Fu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA66u, 0x0036D330u, 3u);
        }

        case 0x0036D330u: {
            TP_STATIC_GUARD(0x06DA66u, 0xA0u, 0x40u, 0x2Du);
            const uint16_t value = 0x2D40u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA69u, 0x0036D348u, 3u);
        }

        case 0x0036D348u: {
            TP_STATIC_GUARD(0x06DA69u, 0x80u, 0x24u);
            TP_STATIC_EXIT(0x06u, 0xDA8Fu, 0x0036D478u, 3u);
        }

        case 0x0036D358u: {
            TP_STATIC_GUARD(0x06DA6Bu, 0xA9u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA6Eu, 0x0036D370u, 3u);
        }

        case 0x0036D370u: {
            TP_STATIC_GUARD(0x06DA6Eu, 0x8Du, 0x26u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1926u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA71u, 0x0036D388u, 5u);
        }

        case 0x0036D388u: {
            TP_STATIC_GUARD(0x06DA71u, 0xA9u, 0x43u, 0x2Du);
            const uint16_t value = 0x2D43u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA74u, 0x0036D3A0u, 3u);
        }

        case 0x0036D3A0u: {
            TP_STATIC_GUARD(0x06DA74u, 0x8Fu, 0x94u, 0x71u, 0x7Eu);
            const uint32_t address = 0x7E7194u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA78u, 0x0036D3C0u, 6u);
        }

        case 0x0036D3C0u: {
            TP_STATIC_GUARD(0x06DA78u, 0xA9u, 0x47u, 0x2Du);
            const uint16_t value = 0x2D47u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA7Bu, 0x0036D3D8u, 3u);
        }

        case 0x0036D3D8u: {
            TP_STATIC_GUARD(0x06DA7Bu, 0x8Fu, 0x14u, 0x72u, 0x7Eu);
            const uint32_t address = 0x7E7214u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA7Fu, 0x0036D3F8u, 6u);
        }

        case 0x0036D3F8u: {
            TP_STATIC_GUARD(0x06DA7Fu, 0xA9u, 0x48u, 0x2Du);
            const uint16_t value = 0x2D48u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA82u, 0x0036D410u, 3u);
        }

        case 0x0036D410u: {
            TP_STATIC_GUARD(0x06DA82u, 0x8Fu, 0x16u, 0x72u, 0x7Eu);
            const uint32_t address = 0x7E7216u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA86u, 0x0036D430u, 6u);
        }

        case 0x0036D430u: {
            TP_STATIC_GUARD(0x06DA86u, 0xA9u, 0x44u, 0x2Du);
            const uint16_t value = 0x2D44u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA89u, 0x0036D448u, 3u);
        }

        case 0x0036D448u: {
            TP_STATIC_GUARD(0x06DA89u, 0xA2u, 0x45u, 0x2Du);
            const uint16_t value = 0x2D45u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA8Cu, 0x0036D460u, 3u);
        }

        case 0x0036D460u: {
            TP_STATIC_GUARD(0x06DA8Cu, 0xA0u, 0x46u, 0x2Du);
            const uint16_t value = 0x2D46u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA8Fu, 0x0036D478u, 3u);
        }

        case 0x0036D478u: {
            TP_STATIC_GUARD(0x06DA8Fu, 0x8Fu, 0x96u, 0x71u, 0x7Eu);
            const uint32_t address = 0x7E7196u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA93u, 0x0036D498u, 6u);
        }

        case 0x0036D498u: {
            TP_STATIC_GUARD(0x06DA93u, 0x8Au);
            cpu->a = cpu->x;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA94u, 0x0036D4A0u, 2u);
        }

        case 0x0036D4A0u: {
            TP_STATIC_GUARD(0x06DA94u, 0x8Fu, 0xD4u, 0x71u, 0x7Eu);
            const uint32_t address = 0x7E71D4u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA98u, 0x0036D4C0u, 6u);
        }

        case 0x0036D4C0u: {
            TP_STATIC_GUARD(0x06DA98u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDA99u, 0x0036D4C8u, 2u);
        }

        case 0x0036D4C8u: {
            TP_STATIC_GUARD(0x06DA99u, 0x8Fu, 0xD6u, 0x71u, 0x7Eu);
            const uint32_t address = 0x7E71D6u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDA9Du, 0x0036D4E8u, 6u);
        }

        case 0x0036D4E8u: {
            TP_STATIC_GUARD(0x06DA9Du, 0x6Bu);
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
                case 0x00371F48u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x0036D4F3u: {
            TP_STATIC_GUARD(0x06DA9Eu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xDAA0u, 0x0036D503u, 3u);
        }

        case 0x0036D503u: {
            TP_STATIC_GUARD(0x06DAA0u, 0xADu, 0xB2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07B2u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDAA3u, 0x0036D51Bu, 4u);
        }

        case 0x0036D51Bu: {
            TP_STATIC_GUARD(0x06DAA3u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDAA8u;
                if (tp_scpu_expect_next(cpu, 0x0036D543u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDAA5u, 0x0036D52Bu, 2u);
        }

        case 0x0036D52Bu: {
            TP_STATIC_GUARD(0x06DAA5u, 0x82u, 0x5Eu, 0x05u);
            TP_STATIC_EXIT(0x06u, 0xE006u, 0x00370033u, 4u);
        }

        case 0x0036D543u: {
            TP_STATIC_GUARD(0x06DAA8u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xDAAAu, 0x0036D553u, 3u);
        }

        case 0x0036D553u: {
            TP_STATIC_GUARD(0x06DAAAu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x06u, 0xDAACu, 0x0036D561u, 3u);
        }

        case 0x0036D561u: {
            TP_STATIC_GUARD(0x06DAACu, 0xA0u, 0x1Du);
            const uint8_t value = 0x1Du;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDAAEu, 0x0036D571u, 2u);
        }

        case 0x0036D571u: {
            TP_STATIC_GUARD(0x06DAAEu, 0xB7u, 0x5Bu);
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
            cpu->pbr = 0x06u;
            cpu->pc = 0xDAB0u;
            if (tp_scpu_expect_next(cpu, 0x0036D581u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0036D581u: {
            TP_STATIC_GUARD(0x06DAB0u, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDAB3u, 0x0036D599u, 5u);
        }

        case 0x0036D599u: {
            TP_STATIC_GUARD(0x06DAB3u, 0xEEu, 0xBCu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07BCu;
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
            TP_STATIC_EXIT(0x06u, 0xDAB6u, 0x0036D5B1u, 8u);
        }

        case 0x0036D5B1u: {
            TP_STATIC_GUARD(0x06DAB6u, 0xADu, 0xB8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07B8u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDAB9u, 0x0036D5C9u, 5u);
        }

        case 0x0036D5C9u: {
            TP_STATIC_GUARD(0x06DAB9u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDABEu;
                if (tp_scpu_expect_next(cpu, 0x0036D5F1u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDABBu, 0x0036D5D9u, 2u);
        }

        case 0x0036D5D9u: {
            TP_STATIC_GUARD(0x06DABBu, 0xCEu, 0xB8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07B8u;
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
            TP_STATIC_EXIT(0x06u, 0xDABEu, 0x0036D5F1u, 8u);
        }

        case 0x0036D5F1u: {
            TP_STATIC_GUARD(0x06DABEu, 0xADu, 0xD8u, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06D8u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDAC1u, 0x0036D609u, 5u);
        }

        case 0x0036D609u: {
            TP_STATIC_GUARD(0x06DAC1u, 0xAEu, 0xDAu, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06DAu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDAC4u, 0x0036D621u, 4u);
        }

        case 0x0036D621u: {
            TP_STATIC_GUARD(0x06DAC4u, 0x8Du, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0016u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDAC7u, 0x0036D639u, 5u);
        }

        case 0x0036D639u: {
            TP_STATIC_GUARD(0x06DAC7u, 0x8Eu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDACAu, 0x0036D651u, 4u);
        }

        case 0x0036D651u: {
            TP_STATIC_GUARD(0x06DACAu, 0xADu, 0xB8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07B8u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDACDu, 0x0036D669u, 5u);
        }

        case 0x0036D669u: {
            TP_STATIC_GUARD(0x06DACDu, 0xF0u, 0x0Bu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDADAu;
                if (tp_scpu_expect_next(cpu, 0x0036D6D1u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDACFu, 0x0036D679u, 2u);
        }

        case 0x0036D679u: {
            TP_STATIC_GUARD(0x06DACFu, 0xADu, 0xBCu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07BCu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDAD2u, 0x0036D691u, 5u);
        }

        case 0x0036D691u: {
            TP_STATIC_GUARD(0x06DAD2u, 0xCDu, 0xBAu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07BAu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDAD5u, 0x0036D6A9u, 5u);
        }

        case 0x0036D6A9u: {
            TP_STATIC_GUARD(0x06DAD5u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDADAu;
                if (tp_scpu_expect_next(cpu, 0x0036D6D1u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDAD7u, 0x0036D6B9u, 2u);
        }

        case 0x0036D6B9u: {
            TP_STATIC_GUARD(0x06DAD7u, 0x82u, 0x08u, 0x05u);
            TP_STATIC_EXIT(0x06u, 0xDFE2u, 0x0036FF11u, 4u);
        }

        case 0x0036D6D1u: {
            TP_STATIC_GUARD(0x06DADAu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xDADCu, 0x0036D6E0u, 3u);
        }

        case 0x0036D6E0u: {
            TP_STATIC_GUARD(0x06DADCu, 0xADu, 0xBCu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07BCu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDADFu, 0x0036D6F8u, 5u);
        }

        case 0x0036D6F8u: {
            TP_STATIC_GUARD(0x06DADFu, 0xC9u, 0x22u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0022u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDAE2u, 0x0036D710u, 3u);
        }

        case 0x0036D710u: {
            TP_STATIC_GUARD(0x06DAE2u, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDAEAu;
                if (tp_scpu_expect_next(cpu, 0x0036D750u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDAE4u, 0x0036D720u, 2u);
        }

        case 0x0036D720u: {
            TP_STATIC_GUARD(0x06DAE4u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDAE7u, 0x0036D738u, 3u);
        }

        case 0x0036D738u: {
            TP_STATIC_GUARD(0x06DAE7u, 0x8Du, 0xBCu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07BCu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xDAEAu, 0x0036D750u, 5u);
        }

        case 0x0036D750u: {
            TP_STATIC_GUARD(0x06DAEAu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xDAECu, 0x0036D763u, 3u);
        }

        case 0x0036D763u: {
            TP_STATIC_GUARD(0x06DAECu, 0xADu, 0xBEu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07BEu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDAEFu, 0x0036D77Bu, 4u);
        }

        case 0x0036D77Bu: {
            TP_STATIC_GUARD(0x06DAEFu, 0xC9u, 0x02u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x02u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDAF1u, 0x0036D78Bu, 2u);
        }

        case 0x0036D78Bu: {
            TP_STATIC_GUARD(0x06DAF1u, 0xD0u, 0x46u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDB39u;
                if (tp_scpu_expect_next(cpu, 0x0036D9CBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDAF3u, 0x0036D79Bu, 2u);
        }

        case 0x0036D79Bu: {
            TP_STATIC_GUARD(0x06DAF3u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xDAF5u, 0x0036D7A8u, 3u);
        }

        case 0x0036D7A8u: {
            TP_STATIC_GUARD(0x06DAF5u, 0xADu, 0xBCu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07BCu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDAF8u, 0x0036D7C0u, 5u);
        }

        case 0x0036D7C0u: {
            TP_STATIC_GUARD(0x06DAF8u, 0xC9u, 0x01u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0001u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDAFBu, 0x0036D7D8u, 3u);
        }

        case 0x0036D7D8u: {
            TP_STATIC_GUARD(0x06DAFBu, 0xD0u, 0x1Au);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xDB17u;
                if (tp_scpu_expect_next(cpu, 0x0036D8B8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xDAFDu, 0x0036D7E8u, 2u);
        }

        case 0x0036D7E8u: {
            TP_STATIC_GUARD(0x06DAFDu, 0xA9u, 0x38u, 0x00u);
            const uint16_t value = 0x0038u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xDB00u, 0x0036D800u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
