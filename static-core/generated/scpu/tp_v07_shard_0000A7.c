/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0000A7(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00053810u: {
            TP_STATIC_GUARD(0x00A702u, 0xA2u, 0x00u, 0x20u);
            const uint16_t value = 0x2000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA705u, 0x00053828u, 3u);
        }

        case 0x00053828u: {
            TP_STATIC_GUARD(0x00A705u, 0x8Eu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA708u, 0x00053840u, 5u);
        }

        case 0x00053840u: {
            TP_STATIC_GUARD(0x00A708u, 0x29u, 0xF8u, 0xFFu);
            cpu->a = (uint16_t)(cpu->a & 0xFFF8u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA70Bu, 0x00053858u, 3u);
        }

        case 0x00053858u: {
            TP_STATIC_GUARD(0x00A70Bu, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA70Cu, 0x00053860u, 3u);
        }

        case 0x00053860u: {
            TP_STATIC_GUARD(0x00A70Cu, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA70Du, 0x00053868u, 3u);
        }

        case 0x00053868u: {
            TP_STATIC_GUARD(0x00A70Du, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA70Eu, 0x00053870u, 3u);
        }

        case 0x00053870u: {
            TP_STATIC_GUARD(0x00A70Eu, 0x8Du, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA711u, 0x00053888u, 5u);
        }

        case 0x00053888u: {
            TP_STATIC_GUARD(0x00A711u, 0xADu, 0x0Bu, 0x04u);
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
            TP_STATIC_EXIT(0x00u, 0xA714u, 0x000538A0u, 5u);
        }

        case 0x000538A0u: {
            TP_STATIC_GUARD(0x00A714u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA715u, 0x000538A8u, 3u);
        }

        case 0x000538A8u: {
            TP_STATIC_GUARD(0x00A715u, 0x29u, 0xFCu, 0xFFu);
            cpu->a = (uint16_t)(cpu->a & 0xFFFCu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA718u, 0x000538C0u, 3u);
        }

        case 0x000538C0u: {
            TP_STATIC_GUARD(0x00A718u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA719u, 0x000538C8u, 3u);
        }

        case 0x000538C8u: {
            TP_STATIC_GUARD(0x00A719u, 0x6Du, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Du;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA71Cu, 0x000538E0u, 5u);
        }

        case 0x000538E0u: {
            TP_STATIC_GUARD(0x00A71Cu, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA71Du, 0x000538E8u, 2u);
        }

        case 0x000538E8u: {
            TP_STATIC_GUARD(0x00A71Du, 0xBFu, 0x00u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E00u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA721u, 0x00053908u, 6u);
        }

        case 0x00053908u: {
            TP_STATIC_GUARD(0x00A721u, 0x29u, 0xFFu, 0x01u);
            cpu->a = (uint16_t)(cpu->a & 0x01FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA724u, 0x00053920u, 3u);
        }

        case 0x00053920u: {
            TP_STATIC_GUARD(0x00A724u, 0x8Eu, 0x60u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1960u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA727u, 0x00053938u, 5u);
        }

        case 0x00053938u: {
            TP_STATIC_GUARD(0x00A727u, 0x8Du, 0x5Eu, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x195Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA72Au, 0x00053950u, 5u);
        }

        case 0x00053950u: {
            TP_STATIC_GUARD(0x00A72Au, 0xD0u, 0x2Au);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA756u;
                if (tp_scpu_expect_next(cpu, 0x00053AB0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA72Cu, 0x00053960u, 2u);
        }

        case 0x00053960u: {
            TP_STATIC_GUARD(0x00A72Cu, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA72Du, 0x00053968u, 2u);
        }

        case 0x00053968u: {
            TP_STATIC_GUARD(0x00A72Du, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA72Eu, 0x00053970u, 2u);
        }

        case 0x00053970u: {
            TP_STATIC_GUARD(0x00A72Eu, 0x8Eu, 0x60u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1960u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA731u, 0x00053988u, 5u);
        }

        case 0x00053988u: {
            TP_STATIC_GUARD(0x00A731u, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA732u, 0x00053990u, 2u);
        }

        case 0x00053990u: {
            TP_STATIC_GUARD(0x00A732u, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA733u, 0x00053998u, 2u);
        }

        case 0x00053998u: {
            TP_STATIC_GUARD(0x00A733u, 0xBFu, 0x02u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E02u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA737u, 0x000539B8u, 6u);
        }

        case 0x000539B8u: {
            TP_STATIC_GUARD(0x00A737u, 0x29u, 0xFFu, 0x01u);
            cpu->a = (uint16_t)(cpu->a & 0x01FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA73Au, 0x000539D0u, 3u);
        }

        case 0x000539D0u: {
            TP_STATIC_GUARD(0x00A73Au, 0x8Du, 0x5Eu, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x195Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA73Du, 0x000539E8u, 5u);
        }

        case 0x000539E8u: {
            TP_STATIC_GUARD(0x00A73Du, 0xD0u, 0x17u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA756u;
                if (tp_scpu_expect_next(cpu, 0x00053AB0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA73Fu, 0x000539F8u, 2u);
        }

        case 0x000539F8u: {
            TP_STATIC_GUARD(0x00A73Fu, 0xBFu, 0x00u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E00u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA743u, 0x00053A18u, 6u);
        }

        case 0x00053A18u: {
            TP_STATIC_GUARD(0x00A743u, 0x1Fu, 0x02u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E02u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA747u, 0x00053A38u, 6u);
        }

        case 0x00053A38u: {
            TP_STATIC_GUARD(0x00A747u, 0x29u, 0x00u, 0x80u);
            cpu->a = (uint16_t)(cpu->a & 0x8000u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA74Au, 0x00053A50u, 3u);
        }

        case 0x00053A50u: {
            TP_STATIC_GUARD(0x00A74Au, 0xF0u, 0x0Du);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA759u;
                if (tp_scpu_expect_next(cpu, 0x00053AC8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA74Cu, 0x00053A60u, 2u);
        }

        case 0x00053A60u: {
            TP_STATIC_GUARD(0x00A74Cu, 0xBFu, 0xC0u, 0x6Du, 0x7Eu);
            const uint32_t address = (0x7E6DC0u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA750u, 0x00053A80u, 6u);
        }

        case 0x00053A80u: {
            TP_STATIC_GUARD(0x00A750u, 0x29u, 0xFFu, 0x01u);
            cpu->a = (uint16_t)(cpu->a & 0x01FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA753u, 0x00053A98u, 3u);
        }

        case 0x00053A98u: {
            TP_STATIC_GUARD(0x00A753u, 0x8Du, 0x5Eu, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x195Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA756u, 0x00053AB0u, 5u);
        }

        case 0x00053AB0u: {
            TP_STATIC_GUARD(0x00A756u, 0x9Cu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07A2u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA759u, 0x00053AC8u, 5u);
        }

        case 0x00053AC8u: {
            TP_STATIC_GUARD(0x00A759u, 0xFAu);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA75Au, 0x00053AD0u, 5u);
        }

        case 0x00053AD0u: {
            TP_STATIC_GUARD(0x00A75Au, 0x80u, 0x39u);
            TP_STATIC_EXIT(0x00u, 0xA795u, 0x00053CA8u, 3u);
        }

        case 0x00053AE0u: {
            TP_STATIC_GUARD(0x00A75Cu, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA75Du, 0x00053AE8u, 4u);
        }

        case 0x00053AE8u: {
            TP_STATIC_GUARD(0x00A75Du, 0xA2u, 0x00u, 0x20u);
            const uint16_t value = 0x2000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA760u, 0x00053B00u, 3u);
        }

        case 0x00053B00u: {
            TP_STATIC_GUARD(0x00A760u, 0x8Eu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA763u, 0x00053B18u, 5u);
        }

        case 0x00053B18u: {
            TP_STATIC_GUARD(0x00A763u, 0xADu, 0x5Eu, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x195Eu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA766u, 0x00053B30u, 5u);
        }

        case 0x00053B30u: {
            TP_STATIC_GUARD(0x00A766u, 0xF0u, 0x2Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA794u;
                if (tp_scpu_expect_next(cpu, 0x00053CA0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA768u, 0x00053B40u, 2u);
        }

        case 0x00053B40u: {
            TP_STATIC_GUARD(0x00A768u, 0xAEu, 0x60u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1960u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA76Bu, 0x00053B58u, 5u);
        }

        case 0x00053B58u: {
            TP_STATIC_GUARD(0x00A76Bu, 0xBFu, 0xC0u, 0x6Du, 0x7Eu);
            const uint32_t address = (0x7E6DC0u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA76Fu, 0x00053B78u, 6u);
        }

        case 0x00053B78u: {
            TP_STATIC_GUARD(0x00A76Fu, 0x29u, 0xFFu, 0x01u);
            cpu->a = (uint16_t)(cpu->a & 0x01FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA772u, 0x00053B90u, 3u);
        }

        case 0x00053B90u: {
            TP_STATIC_GUARD(0x00A772u, 0xC9u, 0xA2u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x00A2u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA775u, 0x00053BA8u, 3u);
        }

        case 0x00053BA8u: {
            TP_STATIC_GUARD(0x00A775u, 0x90u, 0x05u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA77Cu;
                if (tp_scpu_expect_next(cpu, 0x00053BE0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA777u, 0x00053BB8u, 2u);
        }

        case 0x00053BB8u: {
            TP_STATIC_GUARD(0x00A777u, 0xC9u, 0x50u, 0x01u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0150u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA77Au, 0x00053BD0u, 3u);
        }

        case 0x00053BD0u: {
            TP_STATIC_GUARD(0x00A77Au, 0x90u, 0x15u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA791u;
                if (tp_scpu_expect_next(cpu, 0x00053C88u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA77Cu, 0x00053BE0u, 2u);
        }

        case 0x00053BE0u: {
            TP_STATIC_GUARD(0x00A77Cu, 0x8Du, 0x60u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1960u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA77Fu, 0x00053BF8u, 5u);
        }

        case 0x00053BF8u: {
            TP_STATIC_GUARD(0x00A77Fu, 0xCDu, 0x5Eu, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x195Eu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA782u, 0x00053C10u, 5u);
        }

        case 0x00053C10u: {
            TP_STATIC_GUARD(0x00A782u, 0xF0u, 0x0Du);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA791u;
                if (tp_scpu_expect_next(cpu, 0x00053C88u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA784u, 0x00053C20u, 2u);
        }

        case 0x00053C20u: {
            TP_STATIC_GUARD(0x00A784u, 0xB0u, 0x0Eu);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA794u;
                if (tp_scpu_expect_next(cpu, 0x00053CA0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA786u, 0x00053C30u, 2u);
        }

        case 0x00053C30u: {
            TP_STATIC_GUARD(0x00A786u, 0xADu, 0x5Eu, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x195Eu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA789u, 0x00053C48u, 5u);
        }

        case 0x00053C48u: {
            TP_STATIC_GUARD(0x00A789u, 0xEDu, 0x60u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1960u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA78Cu, 0x00053C60u, 5u);
        }

        case 0x00053C60u: {
            TP_STATIC_GUARD(0x00A78Cu, 0xC9u, 0x0Au, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Au;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA78Fu, 0x00053C78u, 3u);
        }

        case 0x00053C78u: {
            TP_STATIC_GUARD(0x00A78Fu, 0xB0u, 0x03u);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA794u;
                if (tp_scpu_expect_next(cpu, 0x00053CA0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA791u, 0x00053C88u, 2u);
        }

        case 0x00053C88u: {
            TP_STATIC_GUARD(0x00A791u, 0x9Cu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07A2u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA794u, 0x00053CA0u, 5u);
        }

        case 0x00053CA0u: {
            TP_STATIC_GUARD(0x00A794u, 0xFAu);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA795u, 0x00053CA8u, 5u);
        }

        case 0x00053CA8u: {
            TP_STATIC_GUARD(0x00A795u, 0xA9u, 0xFFu, 0xCFu);
            const uint16_t value = 0xCFFFu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA798u, 0x00053CC0u, 3u);
        }

        case 0x00053CC0u: {
            TP_STATIC_GUARD(0x00A798u, 0x39u, 0x31u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0431u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA79Bu, 0x00053CD8u, 6u);
        }

        case 0x00053CD8u: {
            TP_STATIC_GUARD(0x00A79Bu, 0x99u, 0x31u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0431u + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA79Eu, 0x00053CF0u, 6u);
        }

        case 0x00053CF0u: {
            TP_STATIC_GUARD(0x00A79Eu, 0xB9u, 0x31u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0431u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7A1u, 0x00053D08u, 6u);
        }

        case 0x00053D08u: {
            TP_STATIC_GUARD(0x00A7A1u, 0xC9u, 0x06u, 0x06u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0606u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7A4u, 0x00053D20u, 3u);
        }

        case 0x00053D20u: {
            TP_STATIC_GUARD(0x00A7A4u, 0xF0u, 0x09u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA7AFu;
                if (tp_scpu_expect_next(cpu, 0x00053D78u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA7A6u, 0x00053D30u, 2u);
        }

        case 0x00053D30u: {
            TP_STATIC_GUARD(0x00A7A6u, 0xADu, 0xA2u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A2u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7A9u, 0x00053D48u, 5u);
        }

        case 0x00053D48u: {
            TP_STATIC_GUARD(0x00A7A9u, 0x19u, 0x31u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0431u + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7ACu, 0x00053D60u, 6u);
        }

        case 0x00053D60u: {
            TP_STATIC_GUARD(0x00A7ACu, 0x99u, 0x31u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0431u + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA7AFu, 0x00053D78u, 6u);
        }

        case 0x00053D78u: {
            TP_STATIC_GUARD(0x00A7AFu, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7B0u, 0x00053D80u, 2u);
        }

        case 0x00053D80u: {
            TP_STATIC_GUARD(0x00A7B0u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7B1u, 0x00053D88u, 2u);
        }

        case 0x00053D88u: {
            TP_STATIC_GUARD(0x00A7B1u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7B2u, 0x00053D90u, 2u);
        }

        case 0x00053D90u: {
            TP_STATIC_GUARD(0x00A7B2u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7B3u, 0x00053D98u, 2u);
        }

        case 0x00053D98u: {
            TP_STATIC_GUARD(0x00A7B3u, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7B4u, 0x00053DA0u, 2u);
        }

        case 0x00053DA0u: {
            TP_STATIC_GUARD(0x00A7B4u, 0xECu, 0x69u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0769u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->x;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7B7u, 0x00053DB8u, 5u);
        }

        case 0x00053DB8u: {
            TP_STATIC_GUARD(0x00A7B7u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA7BCu;
                if (tp_scpu_expect_next(cpu, 0x00053DE0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA7B9u, 0x00053DC8u, 2u);
        }

        case 0x00053DC8u: {
            TP_STATIC_GUARD(0x00A7B9u, 0x82u, 0x1Cu, 0xFFu);
            TP_STATIC_EXIT(0x00u, 0xA6D8u, 0x000536C0u, 4u);
        }

        case 0x00053DE0u: {
            TP_STATIC_GUARD(0x00A7BCu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xA7BEu, 0x00053DF0u, 3u);
        }

        case 0x00053DF0u: {
            TP_STATIC_GUARD(0x00A7BEu, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7BFu, 0x00053DF8u, 5u);
        }

        case 0x00053DF8u: {
            TP_STATIC_GUARD(0x00A7BFu, 0x8Du, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA7C2u, 0x00053E10u, 5u);
        }

        case 0x00053E10u: {
            TP_STATIC_GUARD(0x00A7C2u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7C3u, 0x00053E18u, 5u);
        }

        case 0x00053E18u: {
            TP_STATIC_GUARD(0x00A7C3u, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA7C6u, 0x00053E30u, 5u);
        }

        case 0x00053E30u: {
            TP_STATIC_GUARD(0x00A7C6u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xA7C8u, 0x00053E41u, 3u);
        }

        case 0x00053E41u: {
            TP_STATIC_GUARD(0x00A7C8u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xA7CAu, 0x00053E51u, 3u);
        }

        case 0x00053E51u: {
            TP_STATIC_GUARD(0x00A7CAu, 0xA2u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7CCu, 0x00053E61u, 2u);
        }

        case 0x00053E61u: {
            TP_STATIC_GUARD(0x00A7CCu, 0xBDu, 0x4Du, 0x17u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x174Du + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x00u;
            cpu->pc = 0xA7CFu;
            if (tp_scpu_expect_next(cpu, 0x00053E79u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 5u + (((0x4Du + (cpu->x & 0x00FFu)) > 0x00FFu) ? 1u : 0u));
        }

        case 0x00053E79u: {
            TP_STATIC_GUARD(0x00A7CFu, 0xF0u, 0x4Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA820u;
                if (tp_scpu_expect_next(cpu, 0x00054101u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA7D1u, 0x00053E89u, 2u);
        }

        case 0x00053E89u: {
            TP_STATIC_GUARD(0x00A7D1u, 0xC9u, 0x66u, 0x06u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0666u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7D4u, 0x00053EA1u, 3u);
        }

        case 0x00053EA1u: {
            TP_STATIC_GUARD(0x00A7D4u, 0xF0u, 0x4Au);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA820u;
                if (tp_scpu_expect_next(cpu, 0x00054101u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA7D6u, 0x00053EB1u, 2u);
        }

        case 0x00053EB1u: {
            TP_STATIC_GUARD(0x00A7D6u, 0xACu, 0x89u, 0x17u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1789u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7D9u, 0x00053EC9u, 4u);
        }

        case 0x00053EC9u: {
            TP_STATIC_GUARD(0x00A7D9u, 0xF0u, 0x09u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA7E4u;
                if (tp_scpu_expect_next(cpu, 0x00053F21u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA7DBu, 0x00053ED9u, 2u);
        }

        case 0x00053ED9u: {
            TP_STATIC_GUARD(0x00A7DBu, 0xD9u, 0xFBu, 0x16u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x16FBu + (uint32_t)cpu->y) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= value) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x00u;
            cpu->pc = 0xA7DEu;
            if (tp_scpu_expect_next(cpu, 0x00053EF1u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 5u + (((0xFBu + (cpu->y & 0x00FFu)) > 0x00FFu) ? 1u : 0u));
        }

        case 0x00053EF1u: {
            TP_STATIC_GUARD(0x00A7DEu, 0xF0u, 0x40u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA820u;
                if (tp_scpu_expect_next(cpu, 0x00054101u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA7E0u, 0x00053F01u, 2u);
        }

        case 0x00053F01u: {
            TP_STATIC_GUARD(0x00A7E0u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7E1u, 0x00053F09u, 2u);
        }

        case 0x00053F09u: {
            TP_STATIC_GUARD(0x00A7E1u, 0x88u);
            cpu->y = (uint16_t)((cpu->y - 1u) & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7E2u, 0x00053F11u, 2u);
        }

        case 0x00053F11u: {
            TP_STATIC_GUARD(0x00A7E2u, 0xD0u, 0xF7u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA7DBu;
                if (tp_scpu_expect_next(cpu, 0x00053ED9u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA7E4u, 0x00053F21u, 2u);
        }

        case 0x00053F21u: {
            TP_STATIC_GUARD(0x00A7E4u, 0xC9u, 0x00u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7E7u, 0x00053F39u, 3u);
        }

        case 0x00053F39u: {
            TP_STATIC_GUARD(0x00A7E7u, 0x90u, 0x05u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA7EEu;
                if (tp_scpu_expect_next(cpu, 0x00053F71u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA7E9u, 0x00053F49u, 2u);
        }

        case 0x00053F49u: {
            TP_STATIC_GUARD(0x00A7E9u, 0xBDu, 0x6Bu, 0x17u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x176Bu + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x00u;
            cpu->pc = 0xA7ECu;
            if (tp_scpu_expect_next(cpu, 0x00053F61u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 5u + (((0x6Bu + (cpu->x & 0x00FFu)) > 0x00FFu) ? 1u : 0u));
        }

        case 0x00053F61u: {
            TP_STATIC_GUARD(0x00A7ECu, 0xF0u, 0x29u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA817u;
                if (tp_scpu_expect_next(cpu, 0x000540B9u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA7EEu, 0x00053F71u, 2u);
        }

        case 0x00053F71u: {
            TP_STATIC_GUARD(0x00A7EEu, 0xC9u, 0x30u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8030u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7F1u, 0x00053F89u, 3u);
        }

        case 0x00053F89u: {
            TP_STATIC_GUARD(0x00A7F1u, 0xF0u, 0x24u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA817u;
                if (tp_scpu_expect_next(cpu, 0x000540B9u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA7F3u, 0x00053F99u, 2u);
        }

        case 0x00053F99u: {
            TP_STATIC_GUARD(0x00A7F3u, 0xC9u, 0x04u, 0x80u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x8004u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7F6u, 0x00053FB1u, 3u);
        }

        case 0x00053FB1u: {
            TP_STATIC_GUARD(0x00A7F6u, 0xF0u, 0x1Fu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xA817u;
                if (tp_scpu_expect_next(cpu, 0x000540B9u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xA7F8u, 0x00053FC1u, 2u);
        }

        case 0x00053FC1u: {
            TP_STATIC_GUARD(0x00A7F8u, 0x5Au);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->y & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA7F9u, 0x00053FC9u, 3u);
        }

        case 0x00053FC9u: {
            TP_STATIC_GUARD(0x00A7F9u, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA7FAu, 0x00053FD1u, 3u);
        }

        case 0x00053FD1u: {
            TP_STATIC_GUARD(0x00A7FAu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xA7FCu, 0x00053FE0u, 3u);
        }

        case 0x00053FE0u: {
            TP_STATIC_GUARD(0x00A7FCu, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7FDu, 0x00053FE8u, 2u);
        }

        case 0x00053FE8u: {
            TP_STATIC_GUARD(0x00A7FDu, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA7FEu, 0x00053FF0u, 2u);
        }

        case 0x00053FF0u: {
            TP_STATIC_GUARD(0x00A7FEu, 0xA9u, 0x93u, 0x00u);
            const uint16_t value = 0x0093u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xA801u, 0x00054008u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
