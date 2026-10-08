/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000C88(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00644011u: {
            TP_STATIC_GUARD(0x0C8802u, 0xBFu, 0x57u, 0x91u, 0x05u);
            const uint32_t address = (0x059157u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8806u, 0x00644031u, 6u);
        }

        case 0x00644031u: {
            TP_STATIC_GUARD(0x0C8806u, 0x8Du, 0x02u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0002u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8809u, 0x00644049u, 5u);
        }

        case 0x00644049u: {
            TP_STATIC_GUARD(0x0C8809u, 0x22u, 0x2Au, 0x80u, 0x0Eu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Cu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x802Au, 0x00740151u, 8u);
        }

        case 0x00644069u: {
            TP_STATIC_GUARD(0x0C880Du, 0x22u, 0xFBu, 0x88u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x10u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88FBu, 0x006447D9u, 8u);
        }

        case 0x0064408Bu: {
            TP_STATIC_GUARD(0x0C8811u, 0x82u, 0xD9u, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x88EDu, 0x0064476Bu, 4u);
        }

        case 0x006440A3u: {
            TP_STATIC_GUARD(0x0C8814u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8816u, 0x006440B3u, 3u);
        }

        case 0x006440B3u: {
            TP_STATIC_GUARD(0x0C8816u, 0xA9u, 0xFFu);
            const uint8_t value = 0xFFu;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8818u, 0x006440C3u, 2u);
        }

        case 0x006440C3u: {
            TP_STATIC_GUARD(0x0C8818u, 0x8Du, 0x8Au, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Au) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x881Bu, 0x006440DBu, 4u);
        }

        case 0x006440DBu: {
            TP_STATIC_GUARD(0x0C881Bu, 0x22u, 0x01u, 0x89u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x1Eu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8901u, 0x0064480Bu, 8u);
        }

        case 0x006440FBu: {
            TP_STATIC_GUARD(0x0C881Fu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x8821u, 0x00644108u, 3u);
        }

        case 0x00644108u: {
            TP_STATIC_GUARD(0x0C8821u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8824u, 0x00644120u, 3u);
        }

        case 0x00644120u: {
            TP_STATIC_GUARD(0x0C8824u, 0xA2u, 0x0Bu, 0x00u);
            const uint16_t value = 0x000Bu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8827u, 0x00644138u, 3u);
        }

        case 0x00644138u: {
            TP_STATIC_GUARD(0x0C8827u, 0x22u, 0x06u, 0x80u, 0x0Eu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x2Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8006u, 0x00740030u, 8u);
        }

        case 0x00644158u: {
            TP_STATIC_GUARD(0x0C882Bu, 0x22u, 0xFBu, 0x88u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x2Eu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88FBu, 0x006447D8u, 8u);
        }

        case 0x0064417Bu: {
            TP_STATIC_GUARD(0x0C882Fu, 0x82u, 0xBBu, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x88EDu, 0x0064476Bu, 4u);
        }

        case 0x00644193u: {
            TP_STATIC_GUARD(0x0C8832u, 0x30u, 0x14u);
            if ((cpu->p & TP_P_N) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8848u;
                if (tp_scpu_expect_next(cpu, 0x00644243u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8834u, 0x006441A3u, 2u);
        }

        case 0x006441A3u: {
            TP_STATIC_GUARD(0x0C8834u, 0x3Au);
            const uint8_t value = (uint8_t)((cpu->a - 1u) & 0x00FFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8835u, 0x006441ABu, 2u);
        }

        case 0x006441ABu: {
            TP_STATIC_GUARD(0x0C8835u, 0x8Du, 0x8Au, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Au) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8838u, 0x006441C3u, 4u);
        }

        case 0x006441C3u: {
            TP_STATIC_GUARD(0x0C8838u, 0xD0u, 0x2Eu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8868u;
                if (tp_scpu_expect_next(cpu, 0x00644343u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x883Au, 0x006441D3u, 2u);
        }

        case 0x006441D3u: {
            TP_STATIC_GUARD(0x0C883Au, 0x22u, 0x01u, 0x89u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x3Du) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8901u, 0x0064480Bu, 8u);
        }

        case 0x006441F3u: {
            TP_STATIC_GUARD(0x0C883Eu, 0x22u, 0x09u, 0x80u, 0x0Eu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x41u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8009u, 0x0074004Bu, 8u);
        }

        case 0x00644213u: {
            TP_STATIC_GUARD(0x0C8842u, 0x22u, 0xFBu, 0x88u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x45u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88FBu, 0x006447DBu, 8u);
        }

        case 0x00644233u: {
            TP_STATIC_GUARD(0x0C8846u, 0x80u, 0x20u);
            TP_STATIC_EXIT(0x0Cu, 0x8868u, 0x00644343u, 3u);
        }

        case 0x00644243u: {
            TP_STATIC_GUARD(0x0C8848u, 0x22u, 0x01u, 0x89u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x4Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8901u, 0x0064480Bu, 8u);
        }

        case 0x00644263u: {
            TP_STATIC_GUARD(0x0C884Cu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x884Eu, 0x00644273u, 3u);
        }

        case 0x00644273u: {
            TP_STATIC_GUARD(0x0C884Eu, 0xA9u, 0x06u);
            const uint8_t value = 0x06u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8850u, 0x00644283u, 2u);
        }

        case 0x00644283u: {
            TP_STATIC_GUARD(0x0C8850u, 0x8Du, 0x8Au, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Au) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8853u, 0x0064429Bu, 4u);
        }

        case 0x0064429Bu: {
            TP_STATIC_GUARD(0x0C8853u, 0xA9u, 0x06u);
            const uint8_t value = 0x06u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8855u, 0x006442ABu, 2u);
        }

        case 0x006442ABu: {
            TP_STATIC_GUARD(0x0C8855u, 0xA0u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8857u, 0x006442BBu, 2u);
        }

        case 0x006442BBu: {
            TP_STATIC_GUARD(0x0C8857u, 0xA2u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8859u, 0x006442CBu, 2u);
        }

        case 0x006442CBu: {
            TP_STATIC_GUARD(0x0C8859u, 0x22u, 0x21u, 0x80u, 0x0Eu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x5Cu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8021u, 0x0074010Bu, 8u);
        }

        case 0x006442EBu: {
            TP_STATIC_GUARD(0x0C885Du, 0x22u, 0xFBu, 0x88u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x60u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88FBu, 0x006447DBu, 8u);
        }

        case 0x0064430Bu: {
            TP_STATIC_GUARD(0x0C8861u, 0x80u, 0x05u);
            TP_STATIC_EXIT(0x0Cu, 0x8868u, 0x00644343u, 3u);
        }

        case 0x0064431Bu: {
            TP_STATIC_GUARD(0x0C8863u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8865u, 0x0064432Bu, 3u);
        }

        case 0x0064432Bu: {
            TP_STATIC_GUARD(0x0C8865u, 0x9Cu, 0x8Au, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Au) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8868u, 0x00644343u, 4u);
        }

        case 0x00644343u: {
            TP_STATIC_GUARD(0x0C8868u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x886Au, 0x00644350u, 3u);
        }

        case 0x00644350u: {
            TP_STATIC_GUARD(0x0C886Au, 0xADu, 0x8Du, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x188Du;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x886Du, 0x00644368u, 5u);
        }

        case 0x00644368u: {
            TP_STATIC_GUARD(0x0C886Du, 0xF0u, 0x24u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8893u;
                if (tp_scpu_expect_next(cpu, 0x00644498u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x886Fu, 0x00644378u, 2u);
        }

        case 0x00644378u: {
            TP_STATIC_GUARD(0x0C886Fu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8871u, 0x0064438Bu, 3u);
        }

        case 0x0064438Bu: {
            TP_STATIC_GUARD(0x0C8871u, 0xADu, 0x43u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x2143u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8874u, 0x006443A3u, 4u);
        }

        case 0x006443A3u: {
            TP_STATIC_GUARD(0x0C8874u, 0x29u, 0x80u);
            const uint8_t value = (uint8_t)(cpu->a & 0x80u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8876u, 0x006443B3u, 2u);
        }

        case 0x006443B3u: {
            TP_STATIC_GUARD(0x0C8876u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x887Bu;
                if (tp_scpu_expect_next(cpu, 0x006443DBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8878u, 0x006443C3u, 2u);
        }

        case 0x006443C3u: {
            TP_STATIC_GUARD(0x0C8878u, 0x82u, 0x72u, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x88EDu, 0x0064476Bu, 4u);
        }

        case 0x006443DBu: {
            TP_STATIC_GUARD(0x0C887Bu, 0x22u, 0x01u, 0x89u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x7Eu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8901u, 0x0064480Bu, 8u);
        }

        case 0x006443FBu: {
            TP_STATIC_GUARD(0x0C887Fu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x8881u, 0x00644408u, 3u);
        }

        case 0x00644408u: {
            TP_STATIC_GUARD(0x0C8881u, 0xA9u, 0x07u, 0x00u);
            const uint16_t value = 0x0007u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8884u, 0x00644420u, 3u);
        }

        case 0x00644420u: {
            TP_STATIC_GUARD(0x0C8884u, 0x22u, 0x18u, 0x80u, 0x0Eu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x87u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8018u, 0x007400C0u, 8u);
        }

        case 0x00644440u: {
            TP_STATIC_GUARD(0x0C8888u, 0x22u, 0xFBu, 0x88u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88FBu, 0x006447D8u, 8u);
        }

        case 0x00644463u: {
            TP_STATIC_GUARD(0x0C888Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x888Eu, 0x00644470u, 3u);
        }

        case 0x00644470u: {
            TP_STATIC_GUARD(0x0C888Eu, 0x9Cu, 0x8Du, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8891u, 0x00644488u, 5u);
        }

        case 0x00644488u: {
            TP_STATIC_GUARD(0x0C8891u, 0x80u, 0x5Au);
            TP_STATIC_EXIT(0x0Cu, 0x88EDu, 0x00644768u, 3u);
        }

        case 0x00644498u: {
            TP_STATIC_GUARD(0x0C8893u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8895u, 0x006444ABu, 3u);
        }

        case 0x006444ABu: {
            TP_STATIC_GUARD(0x0C8895u, 0xADu, 0x8Cu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x188Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8898u, 0x006444C3u, 4u);
        }

        case 0x006444C3u: {
            TP_STATIC_GUARD(0x0C8898u, 0xF0u, 0x53u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x88EDu;
                if (tp_scpu_expect_next(cpu, 0x0064476Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x889Au, 0x006444D3u, 2u);
        }

        case 0x006444D3u: {
            TP_STATIC_GUARD(0x0C889Au, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x889Cu, 0x006444E0u, 3u);
        }

        case 0x006444E0u: {
            TP_STATIC_GUARD(0x0C889Cu, 0xA9u, 0x14u, 0x00u);
            const uint16_t value = 0x0014u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x889Fu, 0x006444F8u, 3u);
        }

        case 0x006444F8u: {
            TP_STATIC_GUARD(0x0C889Fu, 0x8Du, 0x8Du, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88A2u, 0x00644510u, 5u);
        }

        case 0x00644510u: {
            TP_STATIC_GUARD(0x0C88A2u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x88A4u, 0x00644523u, 3u);
        }

        case 0x00644523u: {
            TP_STATIC_GUARD(0x0C88A4u, 0xADu, 0x8Cu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x188Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x88A7u, 0x0064453Bu, 4u);
        }

        case 0x0064453Bu: {
            TP_STATIC_GUARD(0x0C88A7u, 0xCDu, 0x8Fu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x188Fu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x88AAu, 0x00644553u, 4u);
        }

        case 0x00644553u: {
            TP_STATIC_GUARD(0x0C88AAu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x88AFu;
                if (tp_scpu_expect_next(cpu, 0x0064457Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x88ACu, 0x00644563u, 2u);
        }

        case 0x00644563u: {
            TP_STATIC_GUARD(0x0C88ACu, 0x8Du, 0x8Fu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Fu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88AFu, 0x0064457Bu, 4u);
        }

        case 0x0064457Bu: {
            TP_STATIC_GUARD(0x0C88AFu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x88B1u, 0x0064458Bu, 3u);
        }

        case 0x0064458Bu: {
            TP_STATIC_GUARD(0x0C88B1u, 0xADu, 0x8Cu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x188Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x88B4u, 0x006445A3u, 4u);
        }

        case 0x006445A3u: {
            TP_STATIC_GUARD(0x0C88B4u, 0xCDu, 0x90u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1890u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x88B7u, 0x006445BBu, 4u);
        }

        case 0x006445BBu: {
            TP_STATIC_GUARD(0x0C88B7u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x88BCu;
                if (tp_scpu_expect_next(cpu, 0x006445E3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x88B9u, 0x006445CBu, 2u);
        }

        case 0x006445CBu: {
            TP_STATIC_GUARD(0x0C88B9u, 0x9Cu, 0x90u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1890u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88BCu, 0x006445E3u, 4u);
        }

        case 0x006445E3u: {
            TP_STATIC_GUARD(0x0C88BCu, 0x22u, 0x01u, 0x89u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBFu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8901u, 0x0064480Bu, 8u);
        }

        case 0x00644603u: {
            TP_STATIC_GUARD(0x0C88C0u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x88C2u, 0x00644613u, 3u);
        }

        case 0x00644613u: {
            TP_STATIC_GUARD(0x0C88C2u, 0xA9u, 0x07u);
            const uint8_t value = 0x07u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x88C4u, 0x00644623u, 2u);
        }

        case 0x00644623u: {
            TP_STATIC_GUARD(0x0C88C4u, 0x8Du, 0x08u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0008u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88C7u, 0x0064463Bu, 4u);
        }

        case 0x0064463Bu: {
            TP_STATIC_GUARD(0x0C88C7u, 0xADu, 0x8Cu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x188Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x88CAu, 0x00644653u, 4u);
        }

        case 0x00644653u: {
            TP_STATIC_GUARD(0x0C88CAu, 0x3Au);
            const uint8_t value = (uint8_t)((cpu->a - 1u) & 0x00FFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x88CBu, 0x0064465Bu, 2u);
        }

        case 0x0064465Bu: {
            TP_STATIC_GUARD(0x0C88CBu, 0x8Du, 0x07u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0007u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88CEu, 0x00644673u, 4u);
        }

        case 0x00644673u: {
            TP_STATIC_GUARD(0x0C88CEu, 0xA9u, 0x7Fu);
            const uint8_t value = 0x7Fu;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x88D0u, 0x00644683u, 2u);
        }

        case 0x00644683u: {
            TP_STATIC_GUARD(0x0C88D0u, 0x8Du, 0x09u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0009u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88D3u, 0x0064469Bu, 4u);
        }

        case 0x0064469Bu: {
            TP_STATIC_GUARD(0x0C88D3u, 0x8Du, 0x0Au, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x000Au) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88D6u, 0x006446B3u, 4u);
        }

        case 0x006446B3u: {
            TP_STATIC_GUARD(0x0C88D6u, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x88D8u, 0x006446C3u, 2u);
        }

        case 0x006446C3u: {
            TP_STATIC_GUARD(0x0C88D8u, 0x8Du, 0x0Bu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x000Bu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88DBu, 0x006446DBu, 4u);
        }

        case 0x006446DBu: {
            TP_STATIC_GUARD(0x0C88DBu, 0xA9u, 0x03u);
            const uint8_t value = 0x03u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x88DDu, 0x006446EBu, 2u);
        }

        case 0x006446EBu: {
            TP_STATIC_GUARD(0x0C88DDu, 0x8Du, 0x0Cu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x000Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88E0u, 0x00644703u, 4u);
        }

        case 0x00644703u: {
            TP_STATIC_GUARD(0x0C88E0u, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x88E2u, 0x00644713u, 2u);
        }

        case 0x00644713u: {
            TP_STATIC_GUARD(0x0C88E2u, 0x8Du, 0x0Du, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x000Du) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88E5u, 0x0064472Bu, 4u);
        }

        case 0x0064472Bu: {
            TP_STATIC_GUARD(0x0C88E5u, 0x22u, 0x12u, 0x80u, 0x0Eu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Eu, 0x8012u, 0x00740093u, 8u);
        }

        case 0x0064474Bu: {
            TP_STATIC_GUARD(0x0C88E9u, 0x22u, 0xFBu, 0x88u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x88u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xECu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88FBu, 0x006447DBu, 8u);
        }

        case 0x00644768u: {
            TP_STATIC_GUARD(0x0C88EDu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x88EFu, 0x0064477Bu, 3u);
        }

        case 0x0064476Bu: {
            TP_STATIC_GUARD(0x0C88EDu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x88EFu, 0x0064477Bu, 3u);
        }

        case 0x0064477Bu: {
            TP_STATIC_GUARD(0x0C88EFu, 0x9Cu, 0x8Cu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x188Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88F2u, 0x00644793u, 4u);
        }

        case 0x00644793u: {
            TP_STATIC_GUARD(0x0C88F2u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x88F4u, 0x006447A3u, 3u);
        }

        case 0x006447A3u: {
            TP_STATIC_GUARD(0x0C88F4u, 0x9Cu, 0x92u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1892u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88F7u, 0x006447BBu, 4u);
        }

        case 0x006447BBu: {
            TP_STATIC_GUARD(0x0C88F7u, 0x9Cu, 0xD4u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18D4u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x88FAu, 0x006447D3u, 4u);
        }

        case 0x006447D3u: {
            TP_STATIC_GUARD(0x0C88FAu, 0x6Bu);
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
                case 0x0005721Bu:
                case 0x000573ABu:
                case 0x0005753Bu:
                case 0x000576CBu:
                case 0x00057B1Bu:
                case 0x00057F83u:
                case 0x000582FBu:
                case 0x000587CBu:
                case 0x00058A03u:
                case 0x000EE7ABu:
                case 0x000F05FBu:
                case 0x000F080Bu:
                case 0x000F094Bu:
                case 0x000F4E3Bu:
                case 0x000F6933u:
                case 0x000F6D43u:
                case 0x000F7F33u:
                case 0x000F8213u:
                case 0x000F9E6Bu:
                case 0x000FA263u:
                case 0x000FA2E3u:
                case 0x000FAB0Bu:
                case 0x000FADCBu:
                case 0x000FB53Bu:
                case 0x000FB8CBu:
                case 0x0027689Bu:
                case 0x002768EBu:
                case 0x003CAF23u:
                case 0x00642993u:
                case 0x00646393u:
                case 0x0067078Bu:
                case 0x00676283u:
                case 0x00676A23u:
                case 0x00676ADBu:
                case 0x00676D83u:
                case 0x006772D3u:
                case 0x0077AB23u:
                case 0x0077AB8Bu:
                case 0x0077AC23u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x006447D8u: {
            TP_STATIC_GUARD(0x0C88FBu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x88FDu, 0x006447EBu, 3u);
        }

        case 0x006447D9u: {
            TP_STATIC_GUARD(0x0C88FBu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x88FDu, 0x006447EBu, 3u);
        }

        case 0x006447DBu: {
            TP_STATIC_GUARD(0x0C88FBu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x88FDu, 0x006447EBu, 3u);
        }

        case 0x006447EBu: {
            TP_STATIC_GUARD(0x0C88FDu, 0x9Cu, 0xD4u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18D4u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8900u, 0x00644803u, 4u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
