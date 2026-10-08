/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0006E3(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00371800u: {
            TP_STATIC_GUARD(0x06E300u, 0xA9u, 0x04u, 0x00u);
            const uint16_t value = 0x0004u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE303u, 0x00371818u, 3u);
        }

        case 0x00371818u: {
            TP_STATIC_GUARD(0x06E303u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE306u, 0x00371830u, 5u);
        }

        case 0x00371830u: {
            TP_STATIC_GUARD(0x06E306u, 0x22u, 0x80u, 0xF3u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE3u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x09u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xF380u, 0x00679C00u, 8u);
        }

        case 0x00371850u: {
            TP_STATIC_GUARD(0x06E30Au, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xE30Cu, 0x00371862u, 3u);
        }

        case 0x00371862u: {
            TP_STATIC_GUARD(0x06E30Cu, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x06u, 0xE30Eu, 0x00371872u, 3u);
        }

        case 0x00371872u: {
            TP_STATIC_GUARD(0x06E30Eu, 0xA0u, 0x00u, 0x80u);
            const uint16_t value = 0x8000u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE311u, 0x0037188Au, 3u);
        }

        case 0x0037188Au: {
            TP_STATIC_GUARD(0x06E311u, 0x8Cu, 0x5Du, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x185Du;
            if (tp_scpu_write16(cpu, bus, address, cpu->y) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE314u, 0x003718A2u, 5u);
        }

        case 0x003718A2u: {
            TP_STATIC_GUARD(0x06E314u, 0xA9u, 0x1Du);
            const uint8_t value = 0x1Du;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE316u, 0x003718B2u, 2u);
        }

        case 0x003718B2u: {
            TP_STATIC_GUARD(0x06E316u, 0x8Du, 0x5Fu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x185Fu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE319u, 0x003718CAu, 4u);
        }

        case 0x003718CAu: {
            TP_STATIC_GUARD(0x06E319u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xE31Bu, 0x003718D8u, 3u);
        }

        case 0x003718D8u: {
            TP_STATIC_GUARD(0x06E31Bu, 0xA0u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE31Eu, 0x003718F0u, 3u);
        }

        case 0x003718F0u: {
            TP_STATIC_GUARD(0x06E31Eu, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE31Fu, 0x003718F8u, 2u);
        }

        case 0x003718F8u: {
            TP_STATIC_GUARD(0x06E31Fu, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE320u, 0x00371900u, 2u);
        }

        case 0x00371900u: {
            TP_STATIC_GUARD(0x06E320u, 0xC0u, 0x1Du, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x001Du;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE323u, 0x00371918u, 3u);
        }

        case 0x00371918u: {
            TP_STATIC_GUARD(0x06E323u, 0x90u, 0x05u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xE32Au;
                if (tp_scpu_expect_next(cpu, 0x00371950u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xE325u, 0x00371928u, 2u);
        }

        case 0x00371928u: {
            TP_STATIC_GUARD(0x06E325u, 0xA0u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE328u, 0x00371940u, 3u);
        }

        case 0x00371940u: {
            TP_STATIC_GUARD(0x06E328u, 0x80u, 0x08u);
            TP_STATIC_EXIT(0x06u, 0xE332u, 0x00371990u, 3u);
        }

        case 0x00371950u: {
            TP_STATIC_GUARD(0x06E32Au, 0xB9u, 0xF4u, 0x86u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x86F4u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE32Du, 0x00371968u, 6u);
        }

        case 0x00371968u: {
            TP_STATIC_GUARD(0x06E32Du, 0xCDu, 0x48u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F48u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE330u, 0x00371980u, 5u);
        }

        case 0x00371980u: {
            TP_STATIC_GUARD(0x06E330u, 0xD0u, 0xECu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xE31Eu;
                if (tp_scpu_expect_next(cpu, 0x003718F0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xE332u, 0x00371990u, 2u);
        }

        case 0x00371990u: {
            TP_STATIC_GUARD(0x06E332u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE333u, 0x00371998u, 2u);
        }

        case 0x00371998u: {
            TP_STATIC_GUARD(0x06E333u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE336u, 0x003719B0u, 3u);
        }

        case 0x003719B0u: {
            TP_STATIC_GUARD(0x06E336u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE337u, 0x003719B8u, 2u);
        }

        case 0x003719B8u: {
            TP_STATIC_GUARD(0x06E337u, 0xB9u, 0x12u, 0x87u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x8712u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE33Au, 0x003719D0u, 6u);
        }

        case 0x003719D0u: {
            TP_STATIC_GUARD(0x06E33Au, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x06u, 0xE33Bu, 0x003719D8u, 2u);
        }

        case 0x003719D8u: {
            TP_STATIC_GUARD(0x06E33Bu, 0x69u, 0x00u, 0x20u);
            if (tp_scpu_adc(cpu, 0x2000u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE33Eu, 0x003719F0u, 3u);
        }

        case 0x003719F0u: {
            TP_STATIC_GUARD(0x06E33Eu, 0x8Du, 0x61u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1861u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE341u, 0x00371A08u, 5u);
        }

        case 0x00371A08u: {
            TP_STATIC_GUARD(0x06E341u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xE343u, 0x00371A18u, 3u);
        }

        case 0x00371A18u: {
            TP_STATIC_GUARD(0x06E343u, 0xA0u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE346u, 0x00371A30u, 3u);
        }

        case 0x00371A30u: {
            TP_STATIC_GUARD(0x06E346u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE347u, 0x00371A38u, 2u);
        }

        case 0x00371A38u: {
            TP_STATIC_GUARD(0x06E347u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE348u, 0x00371A40u, 2u);
        }

        case 0x00371A40u: {
            TP_STATIC_GUARD(0x06E348u, 0xC0u, 0x1Du, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x001Du;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE34Bu, 0x00371A58u, 3u);
        }

        case 0x00371A58u: {
            TP_STATIC_GUARD(0x06E34Bu, 0x90u, 0x05u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xE352u;
                if (tp_scpu_expect_next(cpu, 0x00371A90u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xE34Du, 0x00371A68u, 2u);
        }

        case 0x00371A68u: {
            TP_STATIC_GUARD(0x06E34Du, 0xA0u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE350u, 0x00371A80u, 3u);
        }

        case 0x00371A80u: {
            TP_STATIC_GUARD(0x06E350u, 0x80u, 0x08u);
            TP_STATIC_EXIT(0x06u, 0xE35Au, 0x00371AD0u, 3u);
        }

        case 0x00371A90u: {
            TP_STATIC_GUARD(0x06E352u, 0xB9u, 0xF4u, 0x86u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x86F4u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE355u, 0x00371AA8u, 6u);
        }

        case 0x00371AA8u: {
            TP_STATIC_GUARD(0x06E355u, 0xCDu, 0x4Au, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F4Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE358u, 0x00371AC0u, 5u);
        }

        case 0x00371AC0u: {
            TP_STATIC_GUARD(0x06E358u, 0xD0u, 0xECu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xE346u;
                if (tp_scpu_expect_next(cpu, 0x00371A30u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xE35Au, 0x00371AD0u, 2u);
        }

        case 0x00371AD0u: {
            TP_STATIC_GUARD(0x06E35Au, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE35Bu, 0x00371AD8u, 2u);
        }

        case 0x00371AD8u: {
            TP_STATIC_GUARD(0x06E35Bu, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE35Eu, 0x00371AF0u, 3u);
        }

        case 0x00371AF0u: {
            TP_STATIC_GUARD(0x06E35Eu, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE35Fu, 0x00371AF8u, 2u);
        }

        case 0x00371AF8u: {
            TP_STATIC_GUARD(0x06E35Fu, 0xB9u, 0x12u, 0x87u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x8712u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE362u, 0x00371B10u, 6u);
        }

        case 0x00371B10u: {
            TP_STATIC_GUARD(0x06E362u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x06u, 0xE363u, 0x00371B18u, 2u);
        }

        case 0x00371B18u: {
            TP_STATIC_GUARD(0x06E363u, 0x69u, 0x00u, 0x20u);
            if (tp_scpu_adc(cpu, 0x2000u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE366u, 0x00371B30u, 3u);
        }

        case 0x00371B30u: {
            TP_STATIC_GUARD(0x06E366u, 0x8Du, 0x63u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1863u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE369u, 0x00371B48u, 5u);
        }

        case 0x00371B48u: {
            TP_STATIC_GUARD(0x06E369u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xE36Bu, 0x00371B5Bu, 3u);
        }

        case 0x00371B5Bu: {
            TP_STATIC_GUARD(0x06E36Bu, 0xA9u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE36Du, 0x00371B6Bu, 2u);
        }

        case 0x00371B6Bu: {
            TP_STATIC_GUARD(0x06E36Du, 0x8Du, 0x5Bu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x185Bu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE370u, 0x00371B83u, 4u);
        }

        case 0x00371B83u: {
            TP_STATIC_GUARD(0x06E370u, 0xADu, 0x5Bu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x185Bu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE373u, 0x00371B9Bu, 4u);
        }

        case 0x00371B9Bu: {
            TP_STATIC_GUARD(0x06E373u, 0xD0u, 0xFBu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xE370u;
                if (tp_scpu_expect_next(cpu, 0x00371B83u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xE375u, 0x00371BABu, 2u);
        }

        case 0x00371BABu: {
            TP_STATIC_GUARD(0x06E375u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xE377u, 0x00371BB8u, 3u);
        }

        case 0x00371BB8u: {
            TP_STATIC_GUARD(0x06E377u, 0xA0u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE37Au, 0x00371BD0u, 3u);
        }

        case 0x00371BD0u: {
            TP_STATIC_GUARD(0x06E37Au, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE37Bu, 0x00371BD8u, 2u);
        }

        case 0x00371BD8u: {
            TP_STATIC_GUARD(0x06E37Bu, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE37Cu, 0x00371BE0u, 2u);
        }

        case 0x00371BE0u: {
            TP_STATIC_GUARD(0x06E37Cu, 0xC0u, 0x1Du, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x001Du;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE37Fu, 0x00371BF8u, 3u);
        }

        case 0x00371BF8u: {
            TP_STATIC_GUARD(0x06E37Fu, 0x90u, 0x05u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xE386u;
                if (tp_scpu_expect_next(cpu, 0x00371C30u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xE381u, 0x00371C08u, 2u);
        }

        case 0x00371C08u: {
            TP_STATIC_GUARD(0x06E381u, 0xA0u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE384u, 0x00371C20u, 3u);
        }

        case 0x00371C20u: {
            TP_STATIC_GUARD(0x06E384u, 0x80u, 0x08u);
            TP_STATIC_EXIT(0x06u, 0xE38Eu, 0x00371C70u, 3u);
        }

        case 0x00371C30u: {
            TP_STATIC_GUARD(0x06E386u, 0xB9u, 0xF4u, 0x86u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x86F4u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE389u, 0x00371C48u, 6u);
        }

        case 0x00371C48u: {
            TP_STATIC_GUARD(0x06E389u, 0xCDu, 0x4Cu, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F4Cu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE38Cu, 0x00371C60u, 5u);
        }

        case 0x00371C60u: {
            TP_STATIC_GUARD(0x06E38Cu, 0xD0u, 0xECu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xE37Au;
                if (tp_scpu_expect_next(cpu, 0x00371BD0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xE38Eu, 0x00371C70u, 2u);
        }

        case 0x00371C70u: {
            TP_STATIC_GUARD(0x06E38Eu, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE38Fu, 0x00371C78u, 2u);
        }

        case 0x00371C78u: {
            TP_STATIC_GUARD(0x06E38Fu, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE392u, 0x00371C90u, 3u);
        }

        case 0x00371C90u: {
            TP_STATIC_GUARD(0x06E392u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE393u, 0x00371C98u, 2u);
        }

        case 0x00371C98u: {
            TP_STATIC_GUARD(0x06E393u, 0xB9u, 0x12u, 0x87u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x8712u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE396u, 0x00371CB0u, 6u);
        }

        case 0x00371CB0u: {
            TP_STATIC_GUARD(0x06E396u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x06u, 0xE397u, 0x00371CB8u, 2u);
        }

        case 0x00371CB8u: {
            TP_STATIC_GUARD(0x06E397u, 0x69u, 0x00u, 0x20u);
            if (tp_scpu_adc(cpu, 0x2000u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE39Au, 0x00371CD0u, 3u);
        }

        case 0x00371CD0u: {
            TP_STATIC_GUARD(0x06E39Au, 0x8Du, 0x61u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1861u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE39Du, 0x00371CE8u, 5u);
        }

        case 0x00371CE8u: {
            TP_STATIC_GUARD(0x06E39Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xE39Fu, 0x00371CF8u, 3u);
        }

        case 0x00371CF8u: {
            TP_STATIC_GUARD(0x06E39Fu, 0xA0u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3A2u, 0x00371D10u, 3u);
        }

        case 0x00371D10u: {
            TP_STATIC_GUARD(0x06E3A2u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3A3u, 0x00371D18u, 2u);
        }

        case 0x00371D18u: {
            TP_STATIC_GUARD(0x06E3A3u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3A4u, 0x00371D20u, 2u);
        }

        case 0x00371D20u: {
            TP_STATIC_GUARD(0x06E3A4u, 0xC0u, 0x1Du, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x001Du;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3A7u, 0x00371D38u, 3u);
        }

        case 0x00371D38u: {
            TP_STATIC_GUARD(0x06E3A7u, 0x90u, 0x05u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xE3AEu;
                if (tp_scpu_expect_next(cpu, 0x00371D70u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xE3A9u, 0x00371D48u, 2u);
        }

        case 0x00371D48u: {
            TP_STATIC_GUARD(0x06E3A9u, 0xA0u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3ACu, 0x00371D60u, 3u);
        }

        case 0x00371D60u: {
            TP_STATIC_GUARD(0x06E3ACu, 0x80u, 0x08u);
            TP_STATIC_EXIT(0x06u, 0xE3B6u, 0x00371DB0u, 3u);
        }

        case 0x00371D70u: {
            TP_STATIC_GUARD(0x06E3AEu, 0xB9u, 0xF4u, 0x86u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x86F4u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3B1u, 0x00371D88u, 6u);
        }

        case 0x00371D88u: {
            TP_STATIC_GUARD(0x06E3B1u, 0xCDu, 0x4Eu, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F4Eu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3B4u, 0x00371DA0u, 5u);
        }

        case 0x00371DA0u: {
            TP_STATIC_GUARD(0x06E3B4u, 0xD0u, 0xECu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xE3A2u;
                if (tp_scpu_expect_next(cpu, 0x00371D10u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xE3B6u, 0x00371DB0u, 2u);
        }

        case 0x00371DB0u: {
            TP_STATIC_GUARD(0x06E3B6u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3B7u, 0x00371DB8u, 2u);
        }

        case 0x00371DB8u: {
            TP_STATIC_GUARD(0x06E3B7u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3BAu, 0x00371DD0u, 3u);
        }

        case 0x00371DD0u: {
            TP_STATIC_GUARD(0x06E3BAu, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3BBu, 0x00371DD8u, 2u);
        }

        case 0x00371DD8u: {
            TP_STATIC_GUARD(0x06E3BBu, 0xB9u, 0x12u, 0x87u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x8712u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3BEu, 0x00371DF0u, 6u);
        }

        case 0x00371DF0u: {
            TP_STATIC_GUARD(0x06E3BEu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x06u, 0xE3BFu, 0x00371DF8u, 2u);
        }

        case 0x00371DF8u: {
            TP_STATIC_GUARD(0x06E3BFu, 0x69u, 0x00u, 0x20u);
            if (tp_scpu_adc(cpu, 0x2000u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE3C2u, 0x00371E10u, 3u);
        }

        case 0x00371E10u: {
            TP_STATIC_GUARD(0x06E3C2u, 0x8Du, 0x63u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1863u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE3C5u, 0x00371E28u, 5u);
        }

        case 0x00371E28u: {
            TP_STATIC_GUARD(0x06E3C5u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xE3C7u, 0x00371E3Bu, 3u);
        }

        case 0x00371E3Bu: {
            TP_STATIC_GUARD(0x06E3C7u, 0xA9u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3C9u, 0x00371E4Bu, 2u);
        }

        case 0x00371E4Bu: {
            TP_STATIC_GUARD(0x06E3C9u, 0x8Du, 0x5Bu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x185Bu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE3CCu, 0x00371E63u, 4u);
        }

        case 0x00371E63u: {
            TP_STATIC_GUARD(0x06E3CCu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xE3CEu, 0x00371E70u, 3u);
        }

        case 0x00371E70u: {
            TP_STATIC_GUARD(0x06E3CEu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xE3D0u, 0x00371E80u, 3u);
        }

        case 0x00371E80u: {
            TP_STATIC_GUARD(0x06E3D0u, 0xA9u, 0x04u, 0x00u);
            const uint16_t value = 0x0004u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3D3u, 0x00371E98u, 3u);
        }

        case 0x00371E98u: {
            TP_STATIC_GUARD(0x06E3D3u, 0x8Du, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0415u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE3D6u, 0x00371EB0u, 5u);
        }

        case 0x00371EB0u: {
            TP_STATIC_GUARD(0x06E3D6u, 0xADu, 0x15u, 0x04u);
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
            TP_STATIC_EXIT(0x06u, 0xE3D9u, 0x00371EC8u, 5u);
        }

        case 0x00371EC8u: {
            TP_STATIC_GUARD(0x06E3D9u, 0xC9u, 0x0Eu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Eu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3DCu, 0x00371EE0u, 3u);
        }

        case 0x00371EE0u: {
            TP_STATIC_GUARD(0x06E3DCu, 0xF0u, 0x02u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xE3E0u;
                if (tp_scpu_expect_next(cpu, 0x00371F00u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xE3DEu, 0x00371EF0u, 2u);
        }

        case 0x00371EF0u: {
            TP_STATIC_GUARD(0x06E3DEu, 0xB0u, 0x41u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xE421u;
                if (tp_scpu_expect_next(cpu, 0x00372108u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xE3E0u, 0x00371F00u, 2u);
        }

        case 0x00371F00u: {
            TP_STATIC_GUARD(0x06E3E0u, 0xC9u, 0x0Cu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Cu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3E3u, 0x00371F18u, 3u);
        }

        case 0x00371F18u: {
            TP_STATIC_GUARD(0x06E3E3u, 0xD0u, 0x06u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xE3EBu;
                if (tp_scpu_expect_next(cpu, 0x00371F58u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xE3E5u, 0x00371F28u, 2u);
        }

        case 0x00371F28u: {
            TP_STATIC_GUARD(0x06E3E5u, 0x22u, 0xD3u, 0xD9u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE3u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xD9D3u, 0x0036CE98u, 8u);
        }

        case 0x00371F48u: {
            TP_STATIC_GUARD(0x06E3E9u, 0x80u, 0x2Eu);
            TP_STATIC_EXIT(0x06u, 0xE419u, 0x003720C8u, 3u);
        }

        case 0x00371F58u: {
            TP_STATIC_GUARD(0x06E3EBu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xE3EDu, 0x00371F68u, 3u);
        }

        case 0x00371F68u: {
            TP_STATIC_GUARD(0x06E3EDu, 0xACu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3F0u, 0x00371F80u, 5u);
        }

        case 0x00371F80u: {
            TP_STATIC_GUARD(0x06E3F0u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3F1u, 0x00371F88u, 2u);
        }

        case 0x00371F88u: {
            TP_STATIC_GUARD(0x06E3F1u, 0xA9u, 0x0Au, 0x00u);
            const uint16_t value = 0x000Au;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3F4u, 0x00371FA0u, 3u);
        }

        case 0x00371FA0u: {
            TP_STATIC_GUARD(0x06E3F4u, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE3u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF7u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x00371FC0u: {
            TP_STATIC_GUARD(0x06E3F8u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3F9u, 0x00371FC8u, 2u);
        }

        case 0x00371FC8u: {
            TP_STATIC_GUARD(0x06E3F9u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3FAu, 0x00371FD0u, 2u);
        }

        case 0x00371FD0u: {
            TP_STATIC_GUARD(0x06E3FAu, 0xBFu, 0x61u, 0xCFu, 0x01u);
            const uint32_t address = (0x01CF61u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xE3FEu, 0x00371FF0u, 6u);
        }

        case 0x00371FF0u: {
            TP_STATIC_GUARD(0x06E3FEu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xE401u, 0x00372008u, 5u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
