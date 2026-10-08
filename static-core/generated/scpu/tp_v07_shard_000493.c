/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000493(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00249809u: {
            TP_STATIC_GUARD(0x049301u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x9304u, 0x00249821u, 5u);
        }

        case 0x00249821u: {
            TP_STATIC_GUARD(0x049304u, 0xAEu, 0x1Bu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x001Bu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x9307u, 0x00249839u, 4u);
        }

        case 0x00249839u: {
            TP_STATIC_GUARD(0x049307u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x930Au, 0x00249851u, 4u);
        }

        case 0x00249851u: {
            TP_STATIC_GUARD(0x04930Au, 0xADu, 0x0Bu, 0x04u);
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
            TP_STATIC_EXIT(0x04u, 0x930Du, 0x00249869u, 5u);
        }

        case 0x00249869u: {
            TP_STATIC_GUARD(0x04930Du, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x9310u, 0x00249881u, 5u);
        }

        case 0x00249881u: {
            TP_STATIC_GUARD(0x049310u, 0xADu, 0x0Du, 0x04u);
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
            TP_STATIC_EXIT(0x04u, 0x9313u, 0x00249899u, 5u);
        }

        case 0x00249899u: {
            TP_STATIC_GUARD(0x049313u, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x9316u, 0x002498B1u, 5u);
        }

        case 0x002498B1u: {
            TP_STATIC_GUARD(0x049316u, 0x22u, 0x09u, 0x88u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x93u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x19u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8809u, 0x003C4049u, 8u);
        }

        case 0x002498D0u: {
            TP_STATIC_GUARD(0x04931Au, 0x82u, 0x8Fu, 0x00u);
            TP_STATIC_EXIT(0x04u, 0x93ACu, 0x00249D60u, 4u);
        }

        case 0x002498E9u: {
            TP_STATIC_GUARD(0x04931Du, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x931Fu, 0x002498F9u, 3u);
        }

        case 0x002498F9u: {
            TP_STATIC_GUARD(0x04931Fu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0x9321u, 0x00249909u, 3u);
        }

        case 0x00249909u: {
            TP_STATIC_GUARD(0x049321u, 0xA0u, 0x3Bu);
            const uint8_t value = 0x3Bu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x9323u, 0x00249919u, 2u);
        }

        case 0x00249919u: {
            TP_STATIC_GUARD(0x049323u, 0xB7u, 0x1Cu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x1Cu);
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
            cpu->pbr = 0x04u;
            cpu->pc = 0x9325u;
            if (tp_scpu_expect_next(cpu, 0x00249929u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00249929u: {
            TP_STATIC_GUARD(0x049325u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0x932Au;
                if (tp_scpu_expect_next(cpu, 0x00249951u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0x9327u, 0x00249939u, 2u);
        }

        case 0x00249939u: {
            TP_STATIC_GUARD(0x049327u, 0x82u, 0x82u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0x93ACu, 0x00249D61u, 4u);
        }

        case 0x00249951u: {
            TP_STATIC_GUARD(0x04932Au, 0xADu, 0x30u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F30u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x932Du, 0x00249969u, 5u);
        }

        case 0x00249969u: {
            TP_STATIC_GUARD(0x04932Du, 0xA0u, 0x41u);
            const uint8_t value = 0x41u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x932Fu, 0x00249979u, 2u);
        }

        case 0x00249979u: {
            TP_STATIC_GUARD(0x04932Fu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x04u, 0x9330u, 0x00249981u, 2u);
        }

        case 0x00249981u: {
            TP_STATIC_GUARD(0x049330u, 0xF7u, 0x1Cu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x1Cu);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x04u;
            cpu->pc = 0x9332u;
            if (tp_scpu_expect_next(cpu, 0x00249991u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00249991u: {
            TP_STATIC_GUARD(0x049332u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x9335u, 0x002499A9u, 5u);
        }

        case 0x002499A9u: {
            TP_STATIC_GUARD(0x049335u, 0xADu, 0x32u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1F32u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x9338u, 0x002499C1u, 5u);
        }

        case 0x002499C1u: {
            TP_STATIC_GUARD(0x049338u, 0xA0u, 0x43u);
            const uint8_t value = 0x43u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x933Au, 0x002499D1u, 2u);
        }

        case 0x002499D1u: {
            TP_STATIC_GUARD(0x04933Au, 0xF7u, 0x1Cu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x1Cu);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x04u;
            cpu->pc = 0x933Cu;
            if (tp_scpu_expect_next(cpu, 0x002499E1u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x002499E1u: {
            TP_STATIC_GUARD(0x04933Cu, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x933Fu, 0x002499F9u, 5u);
        }

        case 0x002499F9u: {
            TP_STATIC_GUARD(0x04933Fu, 0x10u, 0x03u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0x9344u;
                if (tp_scpu_expect_next(cpu, 0x00249A21u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0x9341u, 0x00249A09u, 2u);
        }

        case 0x00249A09u: {
            TP_STATIC_GUARD(0x049341u, 0x4Cu, 0xACu, 0x93u);
            TP_STATIC_EXIT(0x04u, 0x93ACu, 0x00249D61u, 3u);
        }

        case 0x00249A21u: {
            TP_STATIC_GUARD(0x049344u, 0xD0u, 0x08u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0x934Eu;
                if (tp_scpu_expect_next(cpu, 0x00249A71u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0x9346u, 0x00249A31u, 2u);
        }

        case 0x00249A31u: {
            TP_STATIC_GUARD(0x049346u, 0xADu, 0x8Au, 0x07u);
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
            TP_STATIC_EXIT(0x04u, 0x9349u, 0x00249A49u, 5u);
        }

        case 0x00249A49u: {
            TP_STATIC_GUARD(0x049349u, 0xC9u, 0xFAu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x00FAu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x934Cu, 0x00249A61u, 3u);
        }

        case 0x00249A61u: {
            TP_STATIC_GUARD(0x04934Cu, 0x90u, 0x5Eu);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0x93ACu;
                if (tp_scpu_expect_next(cpu, 0x00249D61u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0x934Eu, 0x00249A71u, 2u);
        }

        case 0x00249A71u: {
            TP_STATIC_GUARD(0x04934Eu, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x9351u, 0x00249A89u, 3u);
        }

        case 0x00249A89u: {
            TP_STATIC_GUARD(0x049351u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x9354u, 0x00249AA1u, 5u);
        }

        case 0x00249AA1u: {
            TP_STATIC_GUARD(0x049354u, 0xA0u, 0x3Bu);
            const uint8_t value = 0x3Bu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x9356u, 0x00249AB1u, 2u);
        }

        case 0x00249AB1u: {
            TP_STATIC_GUARD(0x049356u, 0xB7u, 0x1Cu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x1Cu);
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
            cpu->pbr = 0x04u;
            cpu->pc = 0x9358u;
            if (tp_scpu_expect_next(cpu, 0x00249AC1u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00249AC1u: {
            TP_STATIC_GUARD(0x049358u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0x935Au, 0x00249AD0u, 3u);
        }

        case 0x00249AD0u: {
            TP_STATIC_GUARD(0x04935Au, 0xA2u, 0x64u, 0x00u);
            const uint16_t value = 0x0064u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x935Du, 0x00249AE8u, 3u);
        }

        case 0x00249AE8u: {
            TP_STATIC_GUARD(0x04935Du, 0x22u, 0x6Bu, 0xFAu, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x93u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x60u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFA6Bu, 0x003FD358u, 8u);
        }

        case 0x00249B08u: {
            TP_STATIC_GUARD(0x049361u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x9363u, 0x00249B19u, 3u);
        }

        case 0x00249B19u: {
            TP_STATIC_GUARD(0x049363u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0x9365u, 0x00249B29u, 3u);
        }

        case 0x00249B29u: {
            TP_STATIC_GUARD(0x049365u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x9368u, 0x00249B41u, 3u);
        }

        case 0x00249B41u: {
            TP_STATIC_GUARD(0x049368u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x04u, 0x9369u, 0x00249B49u, 2u);
        }

        case 0x00249B49u: {
            TP_STATIC_GUARD(0x049369u, 0xEDu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x936Cu, 0x00249B61u, 5u);
        }

        case 0x00249B61u: {
            TP_STATIC_GUARD(0x04936Cu, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x936Fu, 0x00249B79u, 5u);
        }

        case 0x00249B79u: {
            TP_STATIC_GUARD(0x04936Fu, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x9372u, 0x00249B91u, 3u);
        }

        case 0x00249B91u: {
            TP_STATIC_GUARD(0x049372u, 0xEDu, 0xA4u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A4u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x9375u, 0x00249BA9u, 5u);
        }

        case 0x00249BA9u: {
            TP_STATIC_GUARD(0x049375u, 0x8Du, 0x90u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0790u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x9378u, 0x00249BC1u, 5u);
        }

        case 0x00249BC1u: {
            TP_STATIC_GUARD(0x049378u, 0x22u, 0xB9u, 0x9Fu, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x93u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x7Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9FB9u, 0x003CFDC9u, 8u);
        }

        case 0x00249BE3u: {
            TP_STATIC_GUARD(0x04937Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0x937Eu, 0x00249BF0u, 3u);
        }

        case 0x00249BF0u: {
            TP_STATIC_GUARD(0x04937Eu, 0xA0u, 0x3Bu, 0x00u);
            const uint16_t value = 0x003Bu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x9381u, 0x00249C08u, 3u);
        }

        case 0x00249C08u: {
            TP_STATIC_GUARD(0x049381u, 0xB7u, 0x1Cu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x1Cu);
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
            cpu->pbr = 0x04u;
            cpu->pc = 0x9383u;
            if (tp_scpu_expect_next(cpu, 0x00249C18u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00249C18u: {
            TP_STATIC_GUARD(0x049383u, 0xA2u, 0x64u, 0x00u);
            const uint16_t value = 0x0064u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x9386u, 0x00249C30u, 3u);
        }

        case 0x00249C30u: {
            TP_STATIC_GUARD(0x049386u, 0x22u, 0x6Bu, 0xFAu, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x93u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x89u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0xFA6Bu, 0x003FD358u, 8u);
        }

        case 0x00249C50u: {
            TP_STATIC_GUARD(0x04938Au, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x938Cu, 0x00249C61u, 3u);
        }

        case 0x00249C61u: {
            TP_STATIC_GUARD(0x04938Cu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0x938Eu, 0x00249C71u, 3u);
        }

        case 0x00249C71u: {
            TP_STATIC_GUARD(0x04938Eu, 0xA0u, 0x0Eu);
            const uint8_t value = 0x0Eu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x9390u, 0x00249C81u, 2u);
        }

        case 0x00249C81u: {
            TP_STATIC_GUARD(0x049390u, 0xB7u, 0x58u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x58u);
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
            cpu->pbr = 0x04u;
            cpu->pc = 0x9392u;
            if (tp_scpu_expect_next(cpu, 0x00249C91u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00249C91u: {
            TP_STATIC_GUARD(0x049392u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x04u, 0x9393u, 0x00249C99u, 2u);
        }

        case 0x00249C99u: {
            TP_STATIC_GUARD(0x049393u, 0xEDu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x9396u, 0x00249CB1u, 5u);
        }

        case 0x00249CB1u: {
            TP_STATIC_GUARD(0x049396u, 0x97u, 0x58u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x58u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x04u;
            cpu->pc = 0x9398u;
            if (tp_scpu_expect_next(cpu, 0x00249CC1u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00249CC1u: {
            TP_STATIC_GUARD(0x049398u, 0xA0u, 0x10u);
            const uint8_t value = 0x10u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x939Au, 0x00249CD1u, 2u);
        }

        case 0x00249CD1u: {
            TP_STATIC_GUARD(0x04939Au, 0xB7u, 0x58u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x58u);
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
            cpu->pbr = 0x04u;
            cpu->pc = 0x939Cu;
            if (tp_scpu_expect_next(cpu, 0x00249CE1u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00249CE1u: {
            TP_STATIC_GUARD(0x04939Cu, 0xEDu, 0xA4u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A4u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x939Fu, 0x00249CF9u, 5u);
        }

        case 0x00249CF9u: {
            TP_STATIC_GUARD(0x04939Fu, 0x97u, 0x58u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x58u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x04u;
            cpu->pc = 0x93A1u;
            if (tp_scpu_expect_next(cpu, 0x00249D09u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00249D09u: {
            TP_STATIC_GUARD(0x0493A1u, 0xA0u, 0x3Bu);
            const uint8_t value = 0x3Bu;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93A3u, 0x00249D19u, 2u);
        }

        case 0x00249D19u: {
            TP_STATIC_GUARD(0x0493A3u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93A6u, 0x00249D31u, 3u);
        }

        case 0x00249D31u: {
            TP_STATIC_GUARD(0x0493A6u, 0x97u, 0x1Cu);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x1Cu);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x04u;
            cpu->pc = 0x93A8u;
            if (tp_scpu_expect_next(cpu, 0x00249D41u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00249D41u: {
            TP_STATIC_GUARD(0x0493A8u, 0x22u, 0x39u, 0xB1u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x93u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xABu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xB139u, 0x006589C9u, 8u);
        }

        case 0x00249D60u: {
            TP_STATIC_GUARD(0x0493ACu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0x93AEu, 0x00249D70u, 3u);
        }

        case 0x00249D61u: {
            TP_STATIC_GUARD(0x0493ACu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0x93AEu, 0x00249D70u, 3u);
        }

        case 0x00249D70u: {
            TP_STATIC_GUARD(0x0493AEu, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93AFu, 0x00249D78u, 5u);
        }

        case 0x00249D78u: {
            TP_STATIC_GUARD(0x0493AFu, 0x8Du, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93B2u, 0x00249D90u, 5u);
        }

        case 0x00249D90u: {
            TP_STATIC_GUARD(0x0493B2u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93B3u, 0x00249D98u, 5u);
        }

        case 0x00249D98u: {
            TP_STATIC_GUARD(0x0493B3u, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93B6u, 0x00249DB0u, 5u);
        }

        case 0x00249DB0u: {
            TP_STATIC_GUARD(0x0493B6u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93B7u, 0x00249DB8u, 5u);
        }

        case 0x00249DB8u: {
            TP_STATIC_GUARD(0x0493B7u, 0x8Du, 0x19u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0419u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93BAu, 0x00249DD0u, 5u);
        }

        case 0x00249DD0u: {
            TP_STATIC_GUARD(0x0493BAu, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93BBu, 0x00249DD8u, 5u);
        }

        case 0x00249DD8u: {
            TP_STATIC_GUARD(0x0493BBu, 0x8Du, 0x17u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0417u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93BEu, 0x00249DF0u, 5u);
        }

        case 0x00249DF0u: {
            TP_STATIC_GUARD(0x0493BEu, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93BFu, 0x00249DF8u, 5u);
        }

        case 0x00249DF8u: {
            TP_STATIC_GUARD(0x0493BFu, 0x8Du, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0415u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93C2u, 0x00249E10u, 5u);
        }

        case 0x00249E10u: {
            TP_STATIC_GUARD(0x0493C2u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x93C4u, 0x00249E21u, 3u);
        }

        case 0x00249E21u: {
            TP_STATIC_GUARD(0x0493C4u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0x93C6u, 0x00249E31u, 3u);
        }

        case 0x00249E31u: {
            TP_STATIC_GUARD(0x0493C6u, 0xFAu);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93C7u, 0x00249E39u, 4u);
        }

        case 0x00249E39u: {
            TP_STATIC_GUARD(0x0493C7u, 0x8Eu, 0x48u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0048u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93CAu, 0x00249E51u, 4u);
        }

        case 0x00249E51u: {
            TP_STATIC_GUARD(0x0493CAu, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93CBu, 0x00249E59u, 5u);
        }

        case 0x00249E59u: {
            TP_STATIC_GUARD(0x0493CBu, 0x8Du, 0x46u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0046u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93CEu, 0x00249E71u, 5u);
        }

        case 0x00249E71u: {
            TP_STATIC_GUARD(0x0493CEu, 0xFAu);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93CFu, 0x00249E79u, 4u);
        }

        case 0x00249E79u: {
            TP_STATIC_GUARD(0x0493CFu, 0x8Eu, 0x1Eu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x001Eu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93D2u, 0x00249E91u, 4u);
        }

        case 0x00249E91u: {
            TP_STATIC_GUARD(0x0493D2u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93D3u, 0x00249E99u, 5u);
        }

        case 0x00249E99u: {
            TP_STATIC_GUARD(0x0493D3u, 0x8Du, 0x1Cu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x001Cu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93D6u, 0x00249EB1u, 5u);
        }

        case 0x00249EB1u: {
            TP_STATIC_GUARD(0x0493D6u, 0xFAu);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93D7u, 0x00249EB9u, 4u);
        }

        case 0x00249EB9u: {
            TP_STATIC_GUARD(0x0493D7u, 0x8Eu, 0x1Bu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x001Bu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93DAu, 0x00249ED1u, 4u);
        }

        case 0x00249ED1u: {
            TP_STATIC_GUARD(0x0493DAu, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93DBu, 0x00249ED9u, 5u);
        }

        case 0x00249ED9u: {
            TP_STATIC_GUARD(0x0493DBu, 0x8Du, 0x19u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0019u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93DEu, 0x00249EF1u, 5u);
        }

        case 0x00249EF1u: {
            TP_STATIC_GUARD(0x0493DEu, 0xFAu);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93DFu, 0x00249EF9u, 4u);
        }

        case 0x00249EF9u: {
            TP_STATIC_GUARD(0x0493DFu, 0x8Eu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93E2u, 0x00249F11u, 4u);
        }

        case 0x00249F11u: {
            TP_STATIC_GUARD(0x0493E2u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93E3u, 0x00249F19u, 5u);
        }

        case 0x00249F19u: {
            TP_STATIC_GUARD(0x0493E3u, 0x8Du, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0016u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93E6u, 0x00249F31u, 5u);
        }

        case 0x00249F31u: {
            TP_STATIC_GUARD(0x0493E6u, 0x6Bu);
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
                case 0x000665F9u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00249F3Bu: {
            TP_STATIC_GUARD(0x0493E7u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0x93E9u, 0x00249F4Bu, 3u);
        }

        case 0x00249F4Bu: {
            TP_STATIC_GUARD(0x0493E9u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0x93EBu, 0x00249F59u, 3u);
        }

        case 0x00249F59u: {
            TP_STATIC_GUARD(0x0493EBu, 0xADu, 0x16u, 0x00u);
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
            TP_STATIC_EXIT(0x04u, 0x93EEu, 0x00249F71u, 5u);
        }

        case 0x00249F71u: {
            TP_STATIC_GUARD(0x0493EEu, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93EFu, 0x00249F79u, 4u);
        }

        case 0x00249F79u: {
            TP_STATIC_GUARD(0x0493EFu, 0xAEu, 0x18u, 0x00u);
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
            TP_STATIC_EXIT(0x04u, 0x93F2u, 0x00249F91u, 4u);
        }

        case 0x00249F91u: {
            TP_STATIC_GUARD(0x0493F2u, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93F3u, 0x00249F99u, 3u);
        }

        case 0x00249F99u: {
            TP_STATIC_GUARD(0x0493F3u, 0xADu, 0x19u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0019u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93F6u, 0x00249FB1u, 5u);
        }

        case 0x00249FB1u: {
            TP_STATIC_GUARD(0x0493F6u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93F7u, 0x00249FB9u, 4u);
        }

        case 0x00249FB9u: {
            TP_STATIC_GUARD(0x0493F7u, 0xAEu, 0x1Bu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x001Bu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93FAu, 0x00249FD1u, 4u);
        }

        case 0x00249FD1u: {
            TP_STATIC_GUARD(0x0493FAu, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93FBu, 0x00249FD9u, 3u);
        }

        case 0x00249FD9u: {
            TP_STATIC_GUARD(0x0493FBu, 0xADu, 0x1Cu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x001Cu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x93FEu, 0x00249FF1u, 5u);
        }

        case 0x00249FF1u: {
            TP_STATIC_GUARD(0x0493FEu, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x93FFu, 0x00249FF9u, 4u);
        }

        case 0x00249FF9u: {
            TP_STATIC_GUARD(0x0493FFu, 0xAEu, 0x1Eu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x001Eu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0x9402u, 0x0024A011u, 4u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
