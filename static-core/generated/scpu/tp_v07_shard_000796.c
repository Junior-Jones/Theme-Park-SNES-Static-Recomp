/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000796(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x003CB000u: {
            TP_STATIC_GUARD(0x079600u, 0x9Cu, 0xF1u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18F1u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9603u, 0x003CB018u, 5u);
        }

        case 0x003CB018u: {
            TP_STATIC_GUARD(0x079603u, 0x8Eu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0746u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9606u, 0x003CB030u, 5u);
        }

        case 0x003CB030u: {
            TP_STATIC_GUARD(0x079606u, 0x9Cu, 0x44u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0744u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9609u, 0x003CB048u, 5u);
        }

        case 0x003CB048u: {
            TP_STATIC_GUARD(0x079609u, 0x22u, 0x98u, 0x9Du, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x96u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Cu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x9D98u, 0x0064ECC0u, 8u);
        }

        case 0x003CB06Bu: {
            TP_STATIC_GUARD(0x07960Du, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x960Fu, 0x003CB07Bu, 3u);
        }

        case 0x003CB07Bu: {
            TP_STATIC_GUARD(0x07960Fu, 0xADu, 0xCBu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07CBu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9612u, 0x003CB093u, 4u);
        }

        case 0x003CB093u: {
            TP_STATIC_GUARD(0x079612u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9617u;
                if (tp_scpu_expect_next(cpu, 0x003CB0BBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9614u, 0x003CB0A3u, 2u);
        }

        case 0x003CB0A3u: {
            TP_STATIC_GUARD(0x079614u, 0x82u, 0x07u, 0x01u);
            TP_STATIC_EXIT(0x07u, 0x971Eu, 0x003CB8F3u, 4u);
        }

        case 0x003CB0BBu: {
            TP_STATIC_GUARD(0x079617u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x9619u, 0x003CB0CBu, 3u);
        }

        case 0x003CB0CBu: {
            TP_STATIC_GUARD(0x079619u, 0xADu, 0x46u, 0x07u);
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
            TP_STATIC_EXIT(0x07u, 0x961Cu, 0x003CB0E3u, 4u);
        }

        case 0x003CB0E3u: {
            TP_STATIC_GUARD(0x07961Cu, 0x29u, 0x80u);
            const uint8_t value = (uint8_t)(cpu->a & 0x80u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x961Eu, 0x003CB0F3u, 2u);
        }

        case 0x003CB0F3u: {
            TP_STATIC_GUARD(0x07961Eu, 0xF0u, 0x16u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9636u;
                if (tp_scpu_expect_next(cpu, 0x003CB1B3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9620u, 0x003CB103u, 2u);
        }

        case 0x003CB103u: {
            TP_STATIC_GUARD(0x079620u, 0xADu, 0x56u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1956u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9623u, 0x003CB11Bu, 4u);
        }

        case 0x003CB11Bu: {
            TP_STATIC_GUARD(0x079623u, 0xD0u, 0x14u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9639u;
                if (tp_scpu_expect_next(cpu, 0x003CB1CBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9625u, 0x003CB12Bu, 2u);
        }

        case 0x003CB12Bu: {
            TP_STATIC_GUARD(0x079625u, 0xA9u, 0x80u);
            const uint8_t value = 0x80u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9627u, 0x003CB13Bu, 2u);
        }

        case 0x003CB13Bu: {
            TP_STATIC_GUARD(0x079627u, 0x8Du, 0x56u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1956u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x962Au, 0x003CB153u, 4u);
        }

        case 0x003CB153u: {
            TP_STATIC_GUARD(0x07962Au, 0xAEu, 0x57u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1857u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x962Du, 0x003CB16Bu, 4u);
        }

        case 0x003CB16Bu: {
            TP_STATIC_GUARD(0x07962Du, 0xBFu, 0x10u, 0x91u, 0x05u);
            const uint32_t address = (0x059110u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9631u, 0x003CB18Bu, 5u);
        }

        case 0x003CB18Bu: {
            TP_STATIC_GUARD(0x079631u, 0x8Du, 0x57u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1857u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9634u, 0x003CB1A3u, 4u);
        }

        case 0x003CB1A3u: {
            TP_STATIC_GUARD(0x079634u, 0x80u, 0x03u);
            TP_STATIC_EXIT(0x07u, 0x9639u, 0x003CB1CBu, 3u);
        }

        case 0x003CB1B3u: {
            TP_STATIC_GUARD(0x079636u, 0x9Cu, 0x56u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1956u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9639u, 0x003CB1CBu, 4u);
        }

        case 0x003CB1CBu: {
            TP_STATIC_GUARD(0x079639u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x963Bu, 0x003CB1DBu, 3u);
        }

        case 0x003CB1DBu: {
            TP_STATIC_GUARD(0x07963Bu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x07u, 0x963Du, 0x003CB1E9u, 3u);
        }

        case 0x003CB1E9u: {
            TP_STATIC_GUARD(0x07963Du, 0xAEu, 0xBEu, 0x07u);
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
            TP_STATIC_EXIT(0x07u, 0x9640u, 0x003CB201u, 4u);
        }

        case 0x003CB201u: {
            TP_STATIC_GUARD(0x079640u, 0xE0u, 0x02u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x02u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9642u, 0x003CB211u, 2u);
        }

        case 0x003CB211u: {
            TP_STATIC_GUARD(0x079642u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9647u;
                if (tp_scpu_expect_next(cpu, 0x003CB239u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9644u, 0x003CB221u, 2u);
        }

        case 0x003CB221u: {
            TP_STATIC_GUARD(0x079644u, 0x82u, 0x1Cu, 0x01u);
            TP_STATIC_EXIT(0x07u, 0x9763u, 0x003CBB19u, 4u);
        }

        case 0x003CB239u: {
            TP_STATIC_GUARD(0x079647u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x9649u, 0x003CB24Bu, 3u);
        }

        case 0x003CB24Bu: {
            TP_STATIC_GUARD(0x079649u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x07u, 0x964Bu, 0x003CB25Au, 3u);
        }

        case 0x003CB25Au: {
            TP_STATIC_GUARD(0x07964Bu, 0x9Cu, 0x28u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1928u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x964Eu, 0x003CB272u, 4u);
        }

        case 0x003CB272u: {
            TP_STATIC_GUARD(0x07964Eu, 0xADu, 0x42u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F42u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9651u, 0x003CB28Au, 4u);
        }

        case 0x003CB28Au: {
            TP_STATIC_GUARD(0x079651u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9656u;
                if (tp_scpu_expect_next(cpu, 0x003CB2B2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9653u, 0x003CB29Au, 2u);
        }

        case 0x003CB29Au: {
            TP_STATIC_GUARD(0x079653u, 0x82u, 0xFBu, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x9751u, 0x003CBA8Au, 4u);
        }

        case 0x003CB2B2u: {
            TP_STATIC_GUARD(0x079656u, 0xADu, 0xC4u, 0x1Fu);
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
            TP_STATIC_EXIT(0x07u, 0x9659u, 0x003CB2CAu, 4u);
        }

        case 0x003CB2CAu: {
            TP_STATIC_GUARD(0x079659u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x965Eu;
                if (tp_scpu_expect_next(cpu, 0x003CB2F2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x965Bu, 0x003CB2DAu, 2u);
        }

        case 0x003CB2DAu: {
            TP_STATIC_GUARD(0x07965Bu, 0x82u, 0xF3u, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x9751u, 0x003CBA8Au, 4u);
        }

        case 0x003CB2F2u: {
            TP_STATIC_GUARD(0x07965Eu, 0xADu, 0x0Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Eu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9661u, 0x003CB30Au, 4u);
        }

        case 0x003CB30Au: {
            TP_STATIC_GUARD(0x079661u, 0xC9u, 0x0Fu);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x0Fu;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9663u, 0x003CB31Au, 2u);
        }

        case 0x003CB31Au: {
            TP_STATIC_GUARD(0x079663u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9668u;
                if (tp_scpu_expect_next(cpu, 0x003CB342u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9665u, 0x003CB32Au, 2u);
        }

        case 0x003CB32Au: {
            TP_STATIC_GUARD(0x079665u, 0x82u, 0xE9u, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x9751u, 0x003CBA8Au, 4u);
        }

        case 0x003CB342u: {
            TP_STATIC_GUARD(0x079668u, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x07u, 0x966Bu, 0x003CB35Au, 4u);
        }

        case 0x003CB35Au: {
            TP_STATIC_GUARD(0x07966Bu, 0x29u, 0x20u);
            const uint8_t value = (uint8_t)(cpu->a & 0x20u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x966Du, 0x003CB36Au, 2u);
        }

        case 0x003CB36Au: {
            TP_STATIC_GUARD(0x07966Du, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9672u;
                if (tp_scpu_expect_next(cpu, 0x003CB392u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x966Fu, 0x003CB37Au, 2u);
        }

        case 0x003CB37Au: {
            TP_STATIC_GUARD(0x07966Fu, 0x82u, 0xACu, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x971Eu, 0x003CB8F2u, 4u);
        }

        case 0x003CB392u: {
            TP_STATIC_GUARD(0x079672u, 0xADu, 0x46u, 0x07u);
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
            TP_STATIC_EXIT(0x07u, 0x9675u, 0x003CB3AAu, 4u);
        }

        case 0x003CB3AAu: {
            TP_STATIC_GUARD(0x079675u, 0x29u, 0x80u);
            const uint8_t value = (uint8_t)(cpu->a & 0x80u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9677u, 0x003CB3BAu, 2u);
        }

        case 0x003CB3BAu: {
            TP_STATIC_GUARD(0x079677u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x967Cu;
                if (tp_scpu_expect_next(cpu, 0x003CB3E2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9679u, 0x003CB3CAu, 2u);
        }

        case 0x003CB3CAu: {
            TP_STATIC_GUARD(0x079679u, 0x82u, 0xA2u, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x971Eu, 0x003CB8F2u, 4u);
        }

        case 0x003CB3E2u: {
            TP_STATIC_GUARD(0x07967Cu, 0xADu, 0x47u, 0x07u);
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
            TP_STATIC_EXIT(0x07u, 0x967Fu, 0x003CB3FAu, 4u);
        }

        case 0x003CB3FAu: {
            TP_STATIC_GUARD(0x07967Fu, 0xC9u, 0x08u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x08u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9681u, 0x003CB40Au, 2u);
        }

        case 0x003CB40Au: {
            TP_STATIC_GUARD(0x079681u, 0xD0u, 0x04u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9687u;
                if (tp_scpu_expect_next(cpu, 0x003CB43Au) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9683u, 0x003CB41Au, 2u);
        }

        case 0x003CB41Au: {
            TP_STATIC_GUARD(0x079683u, 0xA9u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9685u, 0x003CB42Au, 2u);
        }

        case 0x003CB42Au: {
            TP_STATIC_GUARD(0x079685u, 0x80u, 0x75u);
            TP_STATIC_EXIT(0x07u, 0x96FCu, 0x003CB7E2u, 3u);
        }

        case 0x003CB43Au: {
            TP_STATIC_GUARD(0x079687u, 0xC9u, 0x01u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x01u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9689u, 0x003CB44Au, 2u);
        }

        case 0x003CB44Au: {
            TP_STATIC_GUARD(0x079689u, 0xD0u, 0x04u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x968Fu;
                if (tp_scpu_expect_next(cpu, 0x003CB47Au) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x968Bu, 0x003CB45Au, 2u);
        }

        case 0x003CB45Au: {
            TP_STATIC_GUARD(0x07968Bu, 0xA9u, 0x03u);
            const uint8_t value = 0x03u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x968Du, 0x003CB46Au, 2u);
        }

        case 0x003CB46Au: {
            TP_STATIC_GUARD(0x07968Du, 0x80u, 0x6Du);
            TP_STATIC_EXIT(0x07u, 0x96FCu, 0x003CB7E2u, 3u);
        }

        case 0x003CB47Au: {
            TP_STATIC_GUARD(0x07968Fu, 0xC9u, 0x04u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x04u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9691u, 0x003CB48Au, 2u);
        }

        case 0x003CB48Au: {
            TP_STATIC_GUARD(0x079691u, 0xD0u, 0x04u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9697u;
                if (tp_scpu_expect_next(cpu, 0x003CB4BAu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9693u, 0x003CB49Au, 2u);
        }

        case 0x003CB49Au: {
            TP_STATIC_GUARD(0x079693u, 0xA9u, 0x04u);
            const uint8_t value = 0x04u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9695u, 0x003CB4AAu, 2u);
        }

        case 0x003CB4AAu: {
            TP_STATIC_GUARD(0x079695u, 0x80u, 0x65u);
            TP_STATIC_EXIT(0x07u, 0x96FCu, 0x003CB7E2u, 3u);
        }

        case 0x003CB4BAu: {
            TP_STATIC_GUARD(0x079697u, 0xC9u, 0x02u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x02u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9699u, 0x003CB4CAu, 2u);
        }

        case 0x003CB4CAu: {
            TP_STATIC_GUARD(0x079699u, 0xD0u, 0x04u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x969Fu;
                if (tp_scpu_expect_next(cpu, 0x003CB4FAu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x969Bu, 0x003CB4DAu, 2u);
        }

        case 0x003CB4DAu: {
            TP_STATIC_GUARD(0x07969Bu, 0xA9u, 0x05u);
            const uint8_t value = 0x05u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x969Du, 0x003CB4EAu, 2u);
        }

        case 0x003CB4EAu: {
            TP_STATIC_GUARD(0x07969Du, 0x80u, 0x5Du);
            TP_STATIC_EXIT(0x07u, 0x96FCu, 0x003CB7E2u, 3u);
        }

        case 0x003CB4FAu: {
            TP_STATIC_GUARD(0x07969Fu, 0xADu, 0x46u, 0x07u);
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
            TP_STATIC_EXIT(0x07u, 0x96A2u, 0x003CB512u, 4u);
        }

        case 0x003CB512u: {
            TP_STATIC_GUARD(0x0796A2u, 0xC9u, 0xA0u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0xA0u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x96A4u, 0x003CB522u, 2u);
        }

        case 0x003CB522u: {
            TP_STATIC_GUARD(0x0796A4u, 0xD0u, 0x19u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x96BFu;
                if (tp_scpu_expect_next(cpu, 0x003CB5FAu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x96A6u, 0x003CB532u, 2u);
        }

        case 0x003CB532u: {
            TP_STATIC_GUARD(0x0796A6u, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x96A8u, 0x003CB542u, 2u);
        }

        case 0x003CB542u: {
            TP_STATIC_GUARD(0x0796A8u, 0x8Du, 0x28u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1928u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x96ABu, 0x003CB55Au, 4u);
        }

        case 0x003CB55Au: {
            TP_STATIC_GUARD(0x0796ABu, 0x8Du, 0xC4u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1FC4u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x96AEu, 0x003CB572u, 4u);
        }

        case 0x003CB572u: {
            TP_STATIC_GUARD(0x0796AEu, 0x9Cu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0746u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x96B1u, 0x003CB58Au, 4u);
        }

        case 0x003CB58Au: {
            TP_STATIC_GUARD(0x0796B1u, 0x9Cu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0747u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x96B4u, 0x003CB5A2u, 4u);
        }

        case 0x003CB5A2u: {
            TP_STATIC_GUARD(0x0796B4u, 0x22u, 0x61u, 0x95u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x96u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB7u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9561u, 0x003CAB0Au, 8u);
        }

        case 0x003CB5C0u: {
            TP_STATIC_GUARD(0x0796B8u, 0x22u, 0x73u, 0xE3u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x96u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE373u, 0x00271B98u, 8u);
        }

        case 0x003CB5C3u: {
            TP_STATIC_GUARD(0x0796B8u, 0x22u, 0x73u, 0xE3u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x96u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE373u, 0x00271B9Bu, 8u);
        }

        case 0x003CB5E0u: {
            TP_STATIC_GUARD(0x0796BCu, 0x82u, 0xAFu, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x976Eu, 0x003CBB70u, 4u);
        }

        case 0x003CB5FAu: {
            TP_STATIC_GUARD(0x0796BFu, 0xC9u, 0x90u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x90u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x96C1u, 0x003CB60Au, 2u);
        }

        case 0x003CB60Au: {
            TP_STATIC_GUARD(0x0796C1u, 0xD0u, 0x31u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x96F4u;
                if (tp_scpu_expect_next(cpu, 0x003CB7A2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x96C3u, 0x003CB61Au, 2u);
        }

        case 0x003CB61Au: {
            TP_STATIC_GUARD(0x0796C3u, 0xA2u, 0x08u, 0x00u);
            const uint16_t value = 0x0008u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x96C6u, 0x003CB632u, 3u);
        }

        case 0x003CB632u: {
            TP_STATIC_GUARD(0x0796C6u, 0x8Eu, 0x0Au, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x080Au;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x96C9u, 0x003CB64Au, 5u);
        }

        case 0x003CB64Au: {
            TP_STATIC_GUARD(0x0796C9u, 0xA9u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x96CBu, 0x003CB65Au, 2u);
        }

        case 0x003CB65Au: {
            TP_STATIC_GUARD(0x0796CBu, 0x8Du, 0x4Cu, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x084Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x96CEu, 0x003CB672u, 4u);
        }

        case 0x003CB672u: {
            TP_STATIC_GUARD(0x0796CEu, 0x22u, 0x82u, 0xACu, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x96u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xD1u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAC82u, 0x00056412u, 8u);
        }

        case 0x003CB691u: {
            TP_STATIC_GUARD(0x0796D2u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x96D4u, 0x003CB6A3u, 3u);
        }

        case 0x003CB6A3u: {
            TP_STATIC_GUARD(0x0796D4u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x07u, 0x96D6u, 0x003CB6B2u, 3u);
        }

        case 0x003CB6B2u: {
            TP_STATIC_GUARD(0x0796D6u, 0xADu, 0x34u, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1434u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x96D9u, 0x003CB6CAu, 4u);
        }

        case 0x003CB6CAu: {
            TP_STATIC_GUARD(0x0796D9u, 0xF0u, 0x19u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x96F4u;
                if (tp_scpu_expect_next(cpu, 0x003CB7A2u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x96DBu, 0x003CB6DAu, 2u);
        }

        case 0x003CB6DAu: {
            TP_STATIC_GUARD(0x0796DBu, 0xA9u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x96DDu, 0x003CB6EAu, 2u);
        }

        case 0x003CB6EAu: {
            TP_STATIC_GUARD(0x0796DDu, 0x8Du, 0x28u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1928u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x96E0u, 0x003CB702u, 4u);
        }

        case 0x003CB702u: {
            TP_STATIC_GUARD(0x0796E0u, 0x8Du, 0xC4u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1FC4u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x96E3u, 0x003CB71Au, 4u);
        }

        case 0x003CB71Au: {
            TP_STATIC_GUARD(0x0796E3u, 0x9Cu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0746u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x96E6u, 0x003CB732u, 4u);
        }

        case 0x003CB732u: {
            TP_STATIC_GUARD(0x0796E6u, 0x9Cu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0747u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x96E9u, 0x003CB74Au, 4u);
        }

        case 0x003CB74Au: {
            TP_STATIC_GUARD(0x0796E9u, 0x22u, 0x61u, 0x95u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x96u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xECu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9561u, 0x003CAB0Au, 8u);
        }

        case 0x003CB768u: {
            TP_STATIC_GUARD(0x0796EDu, 0x22u, 0x73u, 0xE3u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x96u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE373u, 0x00271B98u, 8u);
        }

        case 0x003CB76Bu: {
            TP_STATIC_GUARD(0x0796EDu, 0x22u, 0x73u, 0xE3u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x96u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xF0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xE373u, 0x00271B9Bu, 8u);
        }

        case 0x003CB788u: {
            TP_STATIC_GUARD(0x0796F1u, 0x82u, 0x7Au, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x976Eu, 0x003CBB70u, 4u);
        }

        case 0x003CB7A2u: {
            TP_STATIC_GUARD(0x0796F4u, 0x9Cu, 0x0Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x96F7u, 0x003CB7BAu, 4u);
        }

        case 0x003CB7BAu: {
            TP_STATIC_GUARD(0x0796F7u, 0x9Cu, 0x0Du, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Du) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x96FAu, 0x003CB7D2u, 4u);
        }

        case 0x003CB7D2u: {
            TP_STATIC_GUARD(0x0796FAu, 0x80u, 0x14u);
            TP_STATIC_EXIT(0x07u, 0x9710u, 0x003CB882u, 3u);
        }

        case 0x003CB7E2u: {
            TP_STATIC_GUARD(0x0796FCu, 0x8Du, 0x72u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1872u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x96FFu, 0x003CB7FAu, 4u);
        }

        case 0x003CB7FAu: {
            TP_STATIC_GUARD(0x0796FFu, 0x8Du, 0x06u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1906u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9702u, 0x003CB812u, 4u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
