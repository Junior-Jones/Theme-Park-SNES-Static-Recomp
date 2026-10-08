/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000C8B(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00645802u: {
            TP_STATIC_GUARD(0x0C8B00u, 0xA2u, 0xC0u, 0x0Eu);
            const uint16_t value = 0x0EC0u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B03u, 0x0064581Au, 3u);
        }

        case 0x0064581Au: {
            TP_STATIC_GUARD(0x0C8B03u, 0x8Eu, 0x45u, 0x43u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4345u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B06u, 0x00645832u, 5u);
        }

        case 0x00645832u: {
            TP_STATIC_GUARD(0x0C8B06u, 0xA9u, 0x10u);
            const uint8_t value = 0x10u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B08u, 0x00645842u, 2u);
        }

        case 0x00645842u: {
            TP_STATIC_GUARD(0x0C8B08u, 0x8Du, 0x0Bu, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x420Bu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B0Bu, 0x0064585Au, 4u);
        }

        case 0x0064585Au: {
            TP_STATIC_GUARD(0x0C8B0Bu, 0x22u, 0x00u, 0x80u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x0Eu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8000u, 0x00640002u, 8u);
        }

        case 0x0064587Au: {
            TP_STATIC_GUARD(0x0C8B0Fu, 0x22u, 0x43u, 0x86u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x12u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8643u, 0x0064321Au, 8u);
        }

        case 0x0064589Au: {
            TP_STATIC_GUARD(0x0C8B13u, 0x22u, 0x09u, 0x82u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8209u, 0x0004104Au, 8u);
        }

        case 0x006458BBu: {
            TP_STATIC_GUARD(0x0C8B17u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8B19u, 0x006458CBu, 3u);
        }

        case 0x006458CBu: {
            TP_STATIC_GUARD(0x0C8B19u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x0Cu, 0x8B1Bu, 0x006458D9u, 3u);
        }

        case 0x006458D9u: {
            TP_STATIC_GUARD(0x0C8B1Bu, 0xAEu, 0x34u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0034u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B1Eu, 0x006458F1u, 4u);
        }

        case 0x006458F1u: {
            TP_STATIC_GUARD(0x0C8B1Eu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8B23u;
                if (tp_scpu_expect_next(cpu, 0x00645919u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8B20u, 0x00645901u, 2u);
        }

        case 0x00645901u: {
            TP_STATIC_GUARD(0x0C8B20u, 0x82u, 0x92u, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x8BB5u, 0x00645DA9u, 4u);
        }

        case 0x00645919u: {
            TP_STATIC_GUARD(0x0C8B23u, 0xA2u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B25u, 0x00645929u, 2u);
        }

        case 0x00645929u: {
            TP_STATIC_GUARD(0x0C8B25u, 0x8Eu, 0x55u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1955u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B28u, 0x00645941u, 4u);
        }

        case 0x00645941u: {
            TP_STATIC_GUARD(0x0C8B28u, 0xA9u, 0x89u, 0xBEu);
            const uint16_t value = 0xBE89u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B2Bu, 0x00645959u, 3u);
        }

        case 0x00645959u: {
            TP_STATIC_GUARD(0x0C8B2Bu, 0xA2u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B2Du, 0x00645969u, 2u);
        }

        case 0x00645969u: {
            TP_STATIC_GUARD(0x0C8B2Du, 0x22u, 0x68u, 0x82u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x30u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x8268u, 0x003C1341u, 8u);
        }

        case 0x00645989u: {
            TP_STATIC_GUARD(0x0C8B31u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8B33u, 0x00645999u, 3u);
        }

        case 0x00645999u: {
            TP_STATIC_GUARD(0x0C8B33u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x0Cu, 0x8B35u, 0x006459A9u, 3u);
        }

        case 0x006459A9u: {
            TP_STATIC_GUARD(0x0C8B35u, 0xA2u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B37u, 0x006459B9u, 2u);
        }

        case 0x006459B9u: {
            TP_STATIC_GUARD(0x0C8B37u, 0x8Eu, 0xEBu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18EBu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B3Au, 0x006459D1u, 4u);
        }

        case 0x006459D1u: {
            TP_STATIC_GUARD(0x0C8B3Au, 0xA9u, 0xFEu, 0xA3u);
            const uint16_t value = 0xA3FEu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B3Du, 0x006459E9u, 3u);
        }

        case 0x006459E9u: {
            TP_STATIC_GUARD(0x0C8B3Du, 0x8Du, 0xDBu, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x06DBu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B40u, 0x00645A01u, 5u);
        }

        case 0x00645A01u: {
            TP_STATIC_GUARD(0x0C8B40u, 0xA2u, 0x0Bu);
            const uint8_t value = 0x0Bu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B42u, 0x00645A11u, 2u);
        }

        case 0x00645A11u: {
            TP_STATIC_GUARD(0x0C8B42u, 0x8Eu, 0xDDu, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06DDu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B45u, 0x00645A29u, 4u);
        }

        case 0x00645A29u: {
            TP_STATIC_GUARD(0x0C8B45u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8B47u, 0x00645A39u, 3u);
        }

        case 0x00645A39u: {
            TP_STATIC_GUARD(0x0C8B47u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x0Cu, 0x8B49u, 0x00645A49u, 3u);
        }

        case 0x00645A49u: {
            TP_STATIC_GUARD(0x0C8B49u, 0x9Cu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0415u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B4Cu, 0x00645A61u, 5u);
        }

        case 0x00645A61u: {
            TP_STATIC_GUARD(0x0C8B4Cu, 0xAEu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B4Fu, 0x00645A79u, 4u);
        }

        case 0x00645A79u: {
            TP_STATIC_GUARD(0x0C8B4Fu, 0xBFu, 0xC8u, 0xD9u, 0x01u);
            const uint32_t address = (0x01D9C8u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B53u, 0x00645A99u, 6u);
        }

        case 0x00645A99u: {
            TP_STATIC_GUARD(0x0C8B53u, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B56u, 0x00645AB1u, 3u);
        }

        case 0x00645AB1u: {
            TP_STATIC_GUARD(0x0C8B56u, 0xA8u);
            cpu->y = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->y) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B57u, 0x00645AB9u, 2u);
        }

        case 0x00645AB9u: {
            TP_STATIC_GUARD(0x0C8B57u, 0xADu, 0x15u, 0x04u);
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
            TP_STATIC_EXIT(0x0Cu, 0x8B5Au, 0x00645AD1u, 5u);
        }

        case 0x00645AD1u: {
            TP_STATIC_GUARD(0x0C8B5Au, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B5Bu, 0x00645AD9u, 3u);
        }

        case 0x00645AD9u: {
            TP_STATIC_GUARD(0x0C8B5Bu, 0xAAu);
            cpu->x = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B5Cu, 0x00645AE1u, 2u);
        }

        case 0x00645AE1u: {
            TP_STATIC_GUARD(0x0C8B5Cu, 0xBFu, 0xD0u, 0xD9u, 0x01u);
            const uint32_t address = (0x01D9D0u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B60u, 0x00645B01u, 6u);
        }

        case 0x00645B01u: {
            TP_STATIC_GUARD(0x0C8B60u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B63u, 0x00645B19u, 5u);
        }

        case 0x00645B19u: {
            TP_STATIC_GUARD(0x0C8B63u, 0xBFu, 0xE0u, 0xD9u, 0x01u);
            const uint32_t address = (0x01D9E0u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B67u, 0x00645B39u, 6u);
        }

        case 0x00645B39u: {
            TP_STATIC_GUARD(0x0C8B67u, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B6Au, 0x00645B51u, 5u);
        }

        case 0x00645B51u: {
            TP_STATIC_GUARD(0x0C8B6Au, 0xADu, 0xDBu, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06DBu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B6Du, 0x00645B69u, 5u);
        }

        case 0x00645B69u: {
            TP_STATIC_GUARD(0x0C8B6Du, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B70u, 0x00645B81u, 5u);
        }

        case 0x00645B81u: {
            TP_STATIC_GUARD(0x0C8B70u, 0xAEu, 0xDDu, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06DDu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B73u, 0x00645B99u, 4u);
        }

        case 0x00645B99u: {
            TP_STATIC_GUARD(0x0C8B73u, 0x8Eu, 0x66u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0066u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B76u, 0x00645BB1u, 4u);
        }

        case 0x00645BB1u: {
            TP_STATIC_GUARD(0x0C8B76u, 0xB7u, 0x64u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x64u);
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
            cpu->pbr = 0x0Cu;
            cpu->pc = 0x8B78u;
            if (tp_scpu_expect_next(cpu, 0x00645BC1u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x00645BC1u: {
            TP_STATIC_GUARD(0x0C8B78u, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B7Bu, 0x00645BD9u, 5u);
        }

        case 0x00645BD9u: {
            TP_STATIC_GUARD(0x0C8B7Bu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8B7Du, 0x00645BE9u, 3u);
        }

        case 0x00645BE9u: {
            TP_STATIC_GUARD(0x0C8B7Du, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x0Cu, 0x8B7Fu, 0x00645BF9u, 3u);
        }

        case 0x00645BF9u: {
            TP_STATIC_GUARD(0x0C8B7Fu, 0xAEu, 0xDDu, 0x06u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x06DDu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B82u, 0x00645C11u, 4u);
        }

        case 0x00645C11u: {
            TP_STATIC_GUARD(0x0C8B82u, 0x8Eu, 0x94u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0794u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B85u, 0x00645C29u, 4u);
        }

        case 0x00645C29u: {
            TP_STATIC_GUARD(0x0C8B85u, 0xA9u, 0x20u, 0x00u);
            const uint16_t value = 0x0020u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8B88u, 0x00645C41u, 3u);
        }

        case 0x00645C41u: {
            TP_STATIC_GUARD(0x0C8B88u, 0x8Du, 0x96u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0796u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8B8Bu, 0x00645C59u, 5u);
        }

        case 0x00645C59u: {
            TP_STATIC_GUARD(0x0C8B8Bu, 0x22u, 0xAFu, 0xDDu, 0x01u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Eu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x01u, 0xDDAFu, 0x000EED79u, 8u);
        }

        case 0x00645C79u: {
            TP_STATIC_GUARD(0x0C8B8Fu, 0x22u, 0x17u, 0xA4u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x92u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xA417u, 0x003520B9u, 8u);
        }

        case 0x00645C99u: {
            TP_STATIC_GUARD(0x0C8B93u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8B95u, 0x00645CA9u, 3u);
        }

        case 0x00645CA9u: {
            TP_STATIC_GUARD(0x0C8B95u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x0Cu, 0x8B97u, 0x00645CB9u, 3u);
        }

        case 0x00645CB9u: {
            TP_STATIC_GUARD(0x0C8B97u, 0xEEu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
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
            TP_STATIC_EXIT(0x0Cu, 0x8B9Au, 0x00645CD1u, 8u);
        }

        case 0x00645CD1u: {
            TP_STATIC_GUARD(0x0C8B9Au, 0xADu, 0x15u, 0x04u);
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
            TP_STATIC_EXIT(0x0Cu, 0x8B9Du, 0x00645CE9u, 5u);
        }

        case 0x00645CE9u: {
            TP_STATIC_GUARD(0x0C8B9Du, 0xC9u, 0x08u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8BA0u, 0x00645D01u, 3u);
        }

        case 0x00645D01u: {
            TP_STATIC_GUARD(0x0C8BA0u, 0xD0u, 0xAAu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8B4Cu;
                if (tp_scpu_expect_next(cpu, 0x00645A61u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8BA2u, 0x00645D11u, 2u);
        }

        case 0x00645D11u: {
            TP_STATIC_GUARD(0x0C8BA2u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8BA4u, 0x00645D23u, 3u);
        }

        case 0x00645D23u: {
            TP_STATIC_GUARD(0x0C8BA4u, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8BA6u, 0x00645D33u, 2u);
        }

        case 0x00645D33u: {
            TP_STATIC_GUARD(0x0C8BA6u, 0x8Du, 0x4Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x074Au) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8BA9u, 0x00645D4Bu, 4u);
        }

        case 0x00645D4Bu: {
            TP_STATIC_GUARD(0x0C8BA9u, 0x22u, 0x42u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8542u, 0x00642A13u, 8u);
        }

        case 0x00645D6Bu: {
            TP_STATIC_GUARD(0x0C8BADu, 0x22u, 0x67u, 0x81u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8167u, 0x00040B3Bu, 8u);
        }

        case 0x00645D8Bu: {
            TP_STATIC_GUARD(0x0C8BB1u, 0x22u, 0xEAu, 0x80u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB4u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80EAu, 0x00040753u, 8u);
        }

        case 0x00645DA9u: {
            TP_STATIC_GUARD(0x0C8BB5u, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C1u, 8u);
        }

        case 0x00645DCBu: {
            TP_STATIC_GUARD(0x0C8BB9u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8BBBu, 0x00645DDBu, 3u);
        }

        case 0x00645DDBu: {
            TP_STATIC_GUARD(0x0C8BBBu, 0xAEu, 0x34u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0034u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8BBEu, 0x00645DF3u, 4u);
        }

        case 0x00645DF3u: {
            TP_STATIC_GUARD(0x0C8BBEu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8BC3u;
                if (tp_scpu_expect_next(cpu, 0x00645E1Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8BC0u, 0x00645E03u, 2u);
        }

        case 0x00645E03u: {
            TP_STATIC_GUARD(0x0C8BC0u, 0x82u, 0x07u, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x8BCAu, 0x00645E53u, 4u);
        }

        case 0x00645E1Bu: {
            TP_STATIC_GUARD(0x0C8BC3u, 0xE0u, 0x02u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x02u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8BC5u, 0x00645E2Bu, 2u);
        }

        case 0x00645E2Bu: {
            TP_STATIC_GUARD(0x0C8BC5u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8BCAu;
                if (tp_scpu_expect_next(cpu, 0x00645E53u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8BC7u, 0x00645E3Bu, 2u);
        }

        case 0x00645E3Bu: {
            TP_STATIC_GUARD(0x0C8BC7u, 0x82u, 0xACu, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x8C76u, 0x006463B3u, 4u);
        }

        case 0x00645E53u: {
            TP_STATIC_GUARD(0x0C8BCAu, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xCDu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C3u, 8u);
        }

        case 0x00645E73u: {
            TP_STATIC_GUARD(0x0C8BCEu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8BD0u, 0x00645E83u, 3u);
        }

        case 0x00645E83u: {
            TP_STATIC_GUARD(0x0C8BD0u, 0xAEu, 0x34u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0034u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8BD3u, 0x00645E9Bu, 4u);
        }

        case 0x00645E9Bu: {
            TP_STATIC_GUARD(0x0C8BD3u, 0xE0u, 0x02u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x02u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8BD5u, 0x00645EABu, 2u);
        }

        case 0x00645EABu: {
            TP_STATIC_GUARD(0x0C8BD5u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8BDAu;
                if (tp_scpu_expect_next(cpu, 0x00645ED3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8BD7u, 0x00645EBBu, 2u);
        }

        case 0x00645EBBu: {
            TP_STATIC_GUARD(0x0C8BD7u, 0x82u, 0x9Cu, 0x00u);
            TP_STATIC_EXIT(0x0Cu, 0x8C76u, 0x006463B3u, 4u);
        }

        case 0x00645ED3u: {
            TP_STATIC_GUARD(0x0C8BDAu, 0x22u, 0x7Eu, 0x8Cu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDDu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8C7Eu, 0x006463F3u, 8u);
        }

        case 0x00645EF3u: {
            TP_STATIC_GUARD(0x0C8BDEu, 0x22u, 0x1Du, 0x80u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE1u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x801Du, 0x003C00EBu, 8u);
        }

        case 0x00645F12u: {
            TP_STATIC_GUARD(0x0C8BE2u, 0x22u, 0xA4u, 0x8Cu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE5u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8CA4u, 0x00646522u, 8u);
        }

        case 0x00645F32u: {
            TP_STATIC_GUARD(0x0C8BE6u, 0x22u, 0x01u, 0x8Du, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE9u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8D01u, 0x0064680Au, 8u);
        }

        case 0x00645F51u: {
            TP_STATIC_GUARD(0x0C8BEAu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x0Cu, 0x8BECu, 0x00645F60u, 3u);
        }

        case 0x00645F60u: {
            TP_STATIC_GUARD(0x0C8BECu, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8BEFu, 0x00645F78u, 3u);
        }

        case 0x00645F78u: {
            TP_STATIC_GUARD(0x0C8BEFu, 0xA0u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8BF2u, 0x00645F90u, 3u);
        }

        case 0x00645F90u: {
            TP_STATIC_GUARD(0x0C8BF2u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8BF3u, 0x00645F98u, 2u);
        }

        case 0x00645F98u: {
            TP_STATIC_GUARD(0x0C8BF3u, 0x9Fu, 0x00u, 0x6Eu, 0x7Eu);
            const uint32_t address = (0x7E6E00u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8BF7u, 0x00645FB8u, 6u);
        }

        case 0x00645FB8u: {
            TP_STATIC_GUARD(0x0C8BF7u, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8BF8u, 0x00645FC0u, 2u);
        }

        case 0x00645FC0u: {
            TP_STATIC_GUARD(0x0C8BF8u, 0xE8u);
            cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8BF9u, 0x00645FC8u, 2u);
        }

        case 0x00645FC8u: {
            TP_STATIC_GUARD(0x0C8BF9u, 0xC8u);
            cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8BFAu, 0x00645FD0u, 2u);
        }

        case 0x00645FD0u: {
            TP_STATIC_GUARD(0x0C8BFAu, 0xC0u, 0x80u, 0x03u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0380u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x0Cu, 0x8BFDu, 0x00645FE8u, 3u);
        }

        case 0x00645FE8u: {
            TP_STATIC_GUARD(0x0C8BFDu, 0xD0u, 0xF3u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x0Cu;
                cpu->pc = 0x8BF2u;
                if (tp_scpu_expect_next(cpu, 0x00645F90u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x0Cu, 0x8BFFu, 0x00645FF8u, 2u);
        }

        case 0x00645FF8u: {
            TP_STATIC_GUARD(0x0C8BFFu, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x0Cu, 0x8C01u, 0x0064600Au, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
