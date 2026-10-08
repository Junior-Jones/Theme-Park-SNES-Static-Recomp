/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000E83(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00741802u: {
            TP_STATIC_GUARD(0x0E8300u, 0x8Fu, 0x40u, 0x21u, 0x00u);
            const uint32_t address = 0x002140u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8304u, 0x00741822u, 5u);
        }

        case 0x00741822u: {
            TP_STATIC_GUARD(0x0E8304u, 0xE0u, 0x01u, 0x00u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x0001u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x8307u, 0x0074183Au, 3u);
        }

        case 0x0074183Au: {
            TP_STATIC_GUARD(0x0E8307u, 0x90u, 0x08u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x8311u;
                if (tp_scpu_expect_next(cpu, 0x0074188Au) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x8309u, 0x0074184Au, 2u);
        }

        case 0x0074184Au: {
            TP_STATIC_GUARD(0x0E8309u, 0xCFu, 0x40u, 0x21u, 0x00u);
            const uint32_t address = 0x002140u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Eu, 0x830Du, 0x0074186Au, 5u);
        }

        case 0x0074186Au: {
            TP_STATIC_GUARD(0x0E830Du, 0xD0u, 0xFAu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x8309u;
                if (tp_scpu_expect_next(cpu, 0x0074184Au) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x830Fu, 0x0074187Au, 2u);
        }

        case 0x0074187Au: {
            TP_STATIC_GUARD(0x0E830Fu, 0x70u, 0xA7u);
            if ((cpu->p & TP_P_V) != 0u) {
                cpu->pbr = 0x0Eu;
                cpu->pc = 0x82B8u;
                if (tp_scpu_expect_next(cpu, 0x007415C2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Eu, 0x8311u, 0x0074188Au, 2u);
        }

        case 0x0074188Au: {
            TP_STATIC_GUARD(0x0E8311u, 0x28u);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & TP_P_X) != 0u) { cpu->x &= 0x00FFu; cpu->y &= 0x00FFu; }
            TP_STATIC_EXIT(0x0Eu, 0x8312u, 0x00741890u, 4u);
        }

        case 0x00741890u: {
            TP_STATIC_GUARD(0x0E8312u, 0x60u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            switch (tp_scpu_context_key(cpu)) {
                case 0x00740258u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            }
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
