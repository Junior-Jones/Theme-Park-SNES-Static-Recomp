/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000080(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00040007u: {
            TP_STATIC_GUARD(0x008000u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x8002u, 0x00040017u, 3u);
        }

        case 0x00040017u: {
            TP_STATIC_GUARD(0x008002u, 0x9Cu, 0x0Bu, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x420Bu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8005u, 0x0004002Fu, 4u);
        }

        case 0x0004002Fu: {
            TP_STATIC_GUARD(0x008005u, 0x9Cu, 0x0Cu, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x420Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8008u, 0x00040047u, 4u);
        }

        case 0x00040047u: {
            TP_STATIC_GUARD(0x008008u, 0x9Cu, 0x00u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4200u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x800Bu, 0x0004005Fu, 4u);
        }

        case 0x0004005Fu: {
            TP_STATIC_GUARD(0x00800Bu, 0xA9u, 0x80u);
            const uint8_t value = 0x80u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x800Du, 0x0004006Fu, 2u);
        }

        case 0x0004006Fu: {
            TP_STATIC_GUARD(0x00800Du, 0x8Du, 0x00u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x2100u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8010u, 0x00040087u, 4u);
        }

        case 0x00040087u: {
            TP_STATIC_GUARD(0x008010u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x00u, 0x8011u, 0x0004008Fu, 2u);
        }

        case 0x0004008Fu: {
            TP_STATIC_GUARD(0x008011u, 0xFBu);
            if ((cpu->p & TP_P_C) != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "PROVED_XCE_CARRY_VIOLATION");
            const uint8_t old_e = cpu->e;
            const uint8_t old_c = (cpu->p & TP_P_C) != 0u ? 1u : 0u;
            cpu->p = old_e != 0u
                ? (uint8_t)(cpu->p | TP_P_C)
                : (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            cpu->e = old_c;
            if (cpu->e != 0u) {
                cpu->p = (uint8_t)(cpu->p | TP_P_M | TP_P_X);
                cpu->s = (uint16_t)(0x0100u | (cpu->s & 0x00FFu));
            }
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x8012u, 0x00040093u, 2u);
        }

        case 0x00040093u: {
            TP_STATIC_GUARD(0x008012u, 0x78u);
            cpu->p = (uint8_t)(cpu->p | TP_P_I);
            TP_STATIC_EXIT(0x00u, 0x8013u, 0x0004009Bu, 2u);
        }

        case 0x0004009Bu: {
            TP_STATIC_GUARD(0x008013u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0x8015u, 0x000400A8u, 3u);
        }

        case 0x000400A8u: {
            TP_STATIC_GUARD(0x008015u, 0xA2u, 0xFFu, 0x03u);
            const uint16_t value = 0x03FFu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x8018u, 0x000400C0u, 3u);
        }

        case 0x000400C0u: {
            TP_STATIC_GUARD(0x008018u, 0x9Au);
            cpu->s = cpu->x;
            TP_STATIC_EXIT(0x00u, 0x8019u, 0x000400C8u, 2u);
        }

        case 0x000400C8u: {
            TP_STATIC_GUARD(0x008019u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x801Cu, 0x000400E0u, 3u);
        }

        case 0x000400E0u: {
            TP_STATIC_GUARD(0x00801Cu, 0x5Bu);
            cpu->d = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->d) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->d) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x801Du, 0x000400E8u, 2u);
        }

        case 0x000400E8u: {
            TP_STATIC_GUARD(0x00801Du, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x801Fu, 0x000400FBu, 3u);
        }

        case 0x000400FBu: {
            TP_STATIC_GUARD(0x00801Fu, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x8021u, 0x0004010Bu, 2u);
        }

        case 0x0004010Bu: {
            TP_STATIC_GUARD(0x008021u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8022u, 0x00040113u, 3u);
        }

        case 0x00040113u: {
            TP_STATIC_GUARD(0x008022u, 0xABu);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->dbr = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x8023u, 0x0004011Bu, 4u);
        }

        case 0x0004011Bu: {
            TP_STATIC_GUARD(0x008023u, 0x22u, 0x00u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x26u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8000u, 0x00240003u, 8u);
        }

        case 0x0004013Au: {
            TP_STATIC_GUARD(0x008027u, 0x22u, 0xEEu, 0xFBu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x2Au) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xFBEEu, 0x0037DF72u, 8u);
        }

        case 0x0004015Au: {
            TP_STATIC_GUARD(0x00802Bu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x802Du, 0x0004016Bu, 3u);
        }

        case 0x0004016Bu: {
            TP_STATIC_GUARD(0x00802Du, 0xA9u, 0x80u);
            const uint8_t value = 0x80u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x802Fu, 0x0004017Bu, 2u);
        }

        case 0x0004017Bu: {
            TP_STATIC_GUARD(0x00802Fu, 0x8Du, 0x00u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x2100u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8032u, 0x00040193u, 4u);
        }

        case 0x00040193u: {
            TP_STATIC_GUARD(0x008032u, 0x22u, 0x62u, 0x81u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x35u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8162u, 0x00040B13u, 8u);
        }

        case 0x000401B3u: {
            TP_STATIC_GUARD(0x008036u, 0x22u, 0x01u, 0x89u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x39u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8901u, 0x0064480Bu, 8u);
        }

        case 0x000401D3u: {
            TP_STATIC_GUARD(0x00803Au, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x803Cu, 0x000401E3u, 3u);
        }

        case 0x000401E3u: {
            TP_STATIC_GUARD(0x00803Cu, 0xA9u, 0x80u);
            const uint8_t value = 0x80u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x803Eu, 0x000401F3u, 2u);
        }

        case 0x000401F3u: {
            TP_STATIC_GUARD(0x00803Eu, 0x8Du, 0x00u, 0x21u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x2100u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8041u, 0x0004020Bu, 4u);
        }

        case 0x0004020Bu: {
            TP_STATIC_GUARD(0x008041u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0x8043u, 0x00040218u, 3u);
        }

        case 0x00040218u: {
            TP_STATIC_GUARD(0x008043u, 0xA9u, 0x16u, 0x00u);
            const uint16_t value = 0x0016u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x8046u, 0x00040230u, 3u);
        }

        case 0x00040230u: {
            TP_STATIC_GUARD(0x008046u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8049u, 0x00040248u, 5u);
        }

        case 0x00040248u: {
            TP_STATIC_GUARD(0x008049u, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x804Cu, 0x00040260u, 3u);
        }

        case 0x00040260u: {
            TP_STATIC_GUARD(0x00804Cu, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x804Fu, 0x00040278u, 5u);
        }

        case 0x00040278u: {
            TP_STATIC_GUARD(0x00804Fu, 0x9Cu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8052u, 0x00040290u, 5u);
        }

        case 0x00040290u: {
            TP_STATIC_GUARD(0x008052u, 0xA9u, 0x24u, 0x00u);
            const uint16_t value = 0x0024u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x8055u, 0x000402A8u, 3u);
        }

        case 0x000402A8u: {
            TP_STATIC_GUARD(0x008055u, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8058u, 0x000402C0u, 5u);
        }

        case 0x000402C0u: {
            TP_STATIC_GUARD(0x008058u, 0x22u, 0x55u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x5Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8055u, 0x002402A8u, 8u);
        }

        case 0x000402E1u: {
            TP_STATIC_GUARD(0x00805Cu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x805Eu, 0x000402F1u, 3u);
        }

        case 0x000402F1u: {
            TP_STATIC_GUARD(0x00805Eu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0x8060u, 0x00040301u, 3u);
        }

        case 0x00040301u: {
            TP_STATIC_GUARD(0x008060u, 0xA9u, 0x00u, 0x04u);
            const uint16_t value = 0x0400u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x8063u, 0x00040319u, 3u);
        }

        case 0x00040319u: {
            TP_STATIC_GUARD(0x008063u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8066u, 0x00040331u, 5u);
        }

        case 0x00040331u: {
            TP_STATIC_GUARD(0x008066u, 0xA2u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x8068u, 0x00040341u, 2u);
        }

        case 0x00040341u: {
            TP_STATIC_GUARD(0x008068u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x806Bu, 0x00040359u, 4u);
        }

        case 0x00040359u: {
            TP_STATIC_GUARD(0x00806Bu, 0x9Cu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x806Eu, 0x00040371u, 5u);
        }

        case 0x00040371u: {
            TP_STATIC_GUARD(0x00806Eu, 0xA9u, 0x00u, 0x1Cu);
            const uint16_t value = 0x1C00u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x8071u, 0x00040389u, 3u);
        }

        case 0x00040389u: {
            TP_STATIC_GUARD(0x008071u, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8074u, 0x000403A1u, 5u);
        }

        case 0x000403A1u: {
            TP_STATIC_GUARD(0x008074u, 0x22u, 0x55u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x77u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8055u, 0x002402A9u, 8u);
        }

        case 0x000403C1u: {
            TP_STATIC_GUARD(0x008078u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0x807Au, 0x000403D0u, 3u);
        }

        case 0x000403D0u: {
            TP_STATIC_GUARD(0x00807Au, 0xA9u, 0x3Au, 0x00u);
            const uint16_t value = 0x003Au;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x807Du, 0x000403E8u, 3u);
        }

        case 0x000403E8u: {
            TP_STATIC_GUARD(0x00807Du, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8080u, 0x00040400u, 5u);
        }

        case 0x00040400u: {
            TP_STATIC_GUARD(0x008080u, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x8083u, 0x00040418u, 3u);
        }

        case 0x00040418u: {
            TP_STATIC_GUARD(0x008083u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8086u, 0x00040430u, 5u);
        }

        case 0x00040430u: {
            TP_STATIC_GUARD(0x008086u, 0x9Cu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8089u, 0x00040448u, 5u);
        }

        case 0x00040448u: {
            TP_STATIC_GUARD(0x008089u, 0xA9u, 0xC6u, 0x00u);
            const uint16_t value = 0x00C6u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x808Cu, 0x00040460u, 3u);
        }

        case 0x00040460u: {
            TP_STATIC_GUARD(0x00808Cu, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x808Fu, 0x00040478u, 5u);
        }

        case 0x00040478u: {
            TP_STATIC_GUARD(0x00808Fu, 0x22u, 0x55u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x92u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8055u, 0x002402A8u, 8u);
        }

        case 0x00040499u: {
            TP_STATIC_GUARD(0x008093u, 0x80u, 0x45u);
            TP_STATIC_EXIT(0x00u, 0x80DAu, 0x000406D1u, 3u);
        }

        case 0x000404ABu: {
            TP_STATIC_GUARD(0x008095u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x8097u, 0x000404BBu, 3u);
        }

        case 0x000404BBu: {
            TP_STATIC_GUARD(0x008097u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0x8099u, 0x000404C9u, 3u);
        }

        case 0x000404C9u: {
            TP_STATIC_GUARD(0x008099u, 0xAEu, 0xEBu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18EBu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x809Cu, 0x000404E1u, 4u);
        }

        case 0x000404E1u: {
            TP_STATIC_GUARD(0x00809Cu, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x809Du, 0x000404E9u, 3u);
        }

        case 0x000404E9u: {
            TP_STATIC_GUARD(0x00809Du, 0xA9u, 0x00u, 0x04u);
            const uint16_t value = 0x0400u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x80A0u, 0x00040501u, 3u);
        }

        case 0x00040501u: {
            TP_STATIC_GUARD(0x0080A0u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80A3u, 0x00040519u, 5u);
        }

        case 0x00040519u: {
            TP_STATIC_GUARD(0x0080A3u, 0xA2u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x80A5u, 0x00040529u, 2u);
        }

        case 0x00040529u: {
            TP_STATIC_GUARD(0x0080A5u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80A8u, 0x00040541u, 4u);
        }

        case 0x00040541u: {
            TP_STATIC_GUARD(0x0080A8u, 0x9Cu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80ABu, 0x00040559u, 5u);
        }

        case 0x00040559u: {
            TP_STATIC_GUARD(0x0080ABu, 0xA9u, 0x00u, 0x1Cu);
            const uint16_t value = 0x1C00u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x80AEu, 0x00040571u, 3u);
        }

        case 0x00040571u: {
            TP_STATIC_GUARD(0x0080AEu, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80B1u, 0x00040589u, 5u);
        }

        case 0x00040589u: {
            TP_STATIC_GUARD(0x0080B1u, 0x22u, 0x55u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB4u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8055u, 0x002402A9u, 8u);
        }

        case 0x000405A9u: {
            TP_STATIC_GUARD(0x0080B5u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x80B7u, 0x000405BBu, 3u);
        }

        case 0x000405BBu: {
            TP_STATIC_GUARD(0x0080B7u, 0xFAu);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x80B8u, 0x000405C3u, 4u);
        }

        case 0x000405C3u: {
            TP_STATIC_GUARD(0x0080B8u, 0x8Eu, 0xEBu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18EBu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80BBu, 0x000405DBu, 4u);
        }

        case 0x000405DBu: {
            TP_STATIC_GUARD(0x0080BBu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0x80BDu, 0x000405E8u, 3u);
        }

        case 0x000405E8u: {
            TP_STATIC_GUARD(0x0080BDu, 0xA9u, 0x3Au, 0x00u);
            const uint16_t value = 0x003Au;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x80C0u, 0x00040600u, 3u);
        }

        case 0x00040600u: {
            TP_STATIC_GUARD(0x0080C0u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80C3u, 0x00040618u, 5u);
        }

        case 0x00040618u: {
            TP_STATIC_GUARD(0x0080C3u, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x80C6u, 0x00040630u, 3u);
        }

        case 0x00040630u: {
            TP_STATIC_GUARD(0x0080C6u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80C9u, 0x00040648u, 5u);
        }

        case 0x00040648u: {
            TP_STATIC_GUARD(0x0080C9u, 0x9Cu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80CCu, 0x00040660u, 5u);
        }

        case 0x00040660u: {
            TP_STATIC_GUARD(0x0080CCu, 0xA9u, 0xC6u, 0x00u);
            const uint16_t value = 0x00C6u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x80CFu, 0x00040678u, 3u);
        }

        case 0x00040678u: {
            TP_STATIC_GUARD(0x0080CFu, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80D2u, 0x00040690u, 5u);
        }

        case 0x00040690u: {
            TP_STATIC_GUARD(0x0080D2u, 0x22u, 0x55u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xD5u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8055u, 0x002402A8u, 8u);
        }

        case 0x000406B1u: {
            TP_STATIC_GUARD(0x0080D6u, 0x22u, 0xEAu, 0x80u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xD9u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80EAu, 0x00040751u, 8u);
        }

        case 0x000406D1u: {
            TP_STATIC_GUARD(0x0080DAu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0x80DCu, 0x000406E0u, 3u);
        }

        case 0x000406E0u: {
            TP_STATIC_GUARD(0x0080DCu, 0x22u, 0x6Fu, 0x8Au, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xDFu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8A6Fu, 0x00645378u, 8u);
        }

        case 0x00040703u: {
            TP_STATIC_GUARD(0x0080E0u, 0x22u, 0xD2u, 0x81u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x81D2u, 0x00040E93u, 8u);
        }

        case 0x00040722u: {
            TP_STATIC_GUARD(0x0080E4u, 0x20u, 0xC2u, 0xA8u);
            if (tp_scpu_push8(cpu, bus, 0x80u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE6u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xA8C2u, 0x00054612u, 6u);
        }

        case 0x0004073Bu: {
            TP_STATIC_GUARD(0x0080E7u, 0x4Cu, 0x95u, 0x80u);
            TP_STATIC_EXIT(0x00u, 0x8095u, 0x000404ABu, 3u);
        }

        case 0x00040751u: {
            TP_STATIC_GUARD(0x0080EAu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x80ECu, 0x00040761u, 3u);
        }

        case 0x00040753u: {
            TP_STATIC_GUARD(0x0080EAu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0x80ECu, 0x00040763u, 3u);
        }

        case 0x00040761u: {
            TP_STATIC_GUARD(0x0080ECu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0x80EEu, 0x00040771u, 3u);
        }

        case 0x00040763u: {
            TP_STATIC_GUARD(0x0080ECu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0x80EEu, 0x00040771u, 3u);
        }

        case 0x00040771u: {
            TP_STATIC_GUARD(0x0080EEu, 0xA9u, 0x00u, 0x20u);
            const uint16_t value = 0x2000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x80F1u, 0x00040789u, 3u);
        }

        case 0x00040789u: {
            TP_STATIC_GUARD(0x0080F1u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80F4u, 0x000407A1u, 5u);
        }

        case 0x000407A1u: {
            TP_STATIC_GUARD(0x0080F4u, 0xA2u, 0x7Eu);
            const uint8_t value = 0x7Eu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x80F6u, 0x000407B1u, 2u);
        }

        case 0x000407B1u: {
            TP_STATIC_GUARD(0x0080F6u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80F9u, 0x000407C9u, 4u);
        }

        case 0x000407C9u: {
            TP_STATIC_GUARD(0x0080F9u, 0x9Cu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x80FCu, 0x000407E1u, 5u);
        }

        case 0x000407E1u: {
            TP_STATIC_GUARD(0x0080FCu, 0xA9u, 0xFFu, 0xDFu);
            const uint16_t value = 0xDFFFu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0x80FFu, 0x000407F9u, 3u);
        }

        case 0x000407F9u: {
            TP_STATIC_GUARD(0x0080FFu, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8102u, 0x00040811u, 5u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
