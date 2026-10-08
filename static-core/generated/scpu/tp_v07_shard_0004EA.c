/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0004EA(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00275008u: {
            TP_STATIC_GUARD(0x04EA01u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEA04u, 0x00275020u, 5u);
        }

        case 0x00275020u: {
            TP_STATIC_GUARD(0x04EA04u, 0x22u, 0x18u, 0x85u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x07u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0x8518u, 0x003428C0u, 8u);
        }

        case 0x00275040u: {
            TP_STATIC_GUARD(0x04EA08u, 0x82u, 0x8Fu, 0x01u);
            TP_STATIC_EXIT(0x04u, 0xEB9Au, 0x00275CD0u, 4u);
        }

        case 0x00275059u: {
            TP_STATIC_GUARD(0x04EA0Bu, 0xC9u, 0x04u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0004u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEA0Eu, 0x00275071u, 3u);
        }

        case 0x00275071u: {
            TP_STATIC_GUARD(0x04EA0Eu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xEA13u;
                if (tp_scpu_expect_next(cpu, 0x00275099u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xEA10u, 0x00275081u, 2u);
        }

        case 0x00275081u: {
            TP_STATIC_GUARD(0x04EA10u, 0x82u, 0x23u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xEA36u, 0x002751B1u, 4u);
        }

        case 0x00275099u: {
            TP_STATIC_GUARD(0x04EA13u, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C1u, 8u);
        }

        case 0x002750BBu: {
            TP_STATIC_GUARD(0x04EA17u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xEA19u, 0x002750CBu, 3u);
        }

        case 0x002750CBu: {
            TP_STATIC_GUARD(0x04EA19u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x04u, 0xEA1Bu, 0x002750DAu, 3u);
        }

        case 0x002750DAu: {
            TP_STATIC_GUARD(0x04EA1Bu, 0x9Cu, 0x6Cu, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1F6Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEA1Eu, 0x002750F2u, 4u);
        }

        case 0x002750F2u: {
            TP_STATIC_GUARD(0x04EA1Eu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xEA20u, 0x00275100u, 3u);
        }

        case 0x00275100u: {
            TP_STATIC_GUARD(0x04EA20u, 0x9Cu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEA23u, 0x00275118u, 5u);
        }

        case 0x00275118u: {
            TP_STATIC_GUARD(0x04EA23u, 0x22u, 0x28u, 0xBAu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x26u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBA28u, 0x0035D140u, 8u);
        }

        case 0x00275139u: {
            TP_STATIC_GUARD(0x04EA27u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xEA29u, 0x00275148u, 3u);
        }

        case 0x00275148u: {
            TP_STATIC_GUARD(0x04EA29u, 0xA9u, 0x09u, 0x00u);
            const uint16_t value = 0x0009u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEA2Cu, 0x00275160u, 3u);
        }

        case 0x00275160u: {
            TP_STATIC_GUARD(0x04EA2Cu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEA2Fu, 0x00275178u, 5u);
        }

        case 0x00275178u: {
            TP_STATIC_GUARD(0x04EA2Fu, 0x22u, 0x18u, 0x85u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x32u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0x8518u, 0x003428C0u, 8u);
        }

        case 0x00275198u: {
            TP_STATIC_GUARD(0x04EA33u, 0x82u, 0x64u, 0x01u);
            TP_STATIC_EXIT(0x04u, 0xEB9Au, 0x00275CD0u, 4u);
        }

        case 0x002751B1u: {
            TP_STATIC_GUARD(0x04EA36u, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x39u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C1u, 8u);
        }

        case 0x002751D3u: {
            TP_STATIC_GUARD(0x04EA3Au, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xEA3Cu, 0x002751E3u, 3u);
        }

        case 0x002751E3u: {
            TP_STATIC_GUARD(0x04EA3Cu, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x04u, 0xEA3Eu, 0x002751F2u, 3u);
        }

        case 0x002751F2u: {
            TP_STATIC_GUARD(0x04EA3Eu, 0x9Cu, 0x6Cu, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1F6Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEA41u, 0x0027520Au, 4u);
        }

        case 0x0027520Au: {
            TP_STATIC_GUARD(0x04EA41u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xEA43u, 0x00275218u, 3u);
        }

        case 0x00275218u: {
            TP_STATIC_GUARD(0x04EA43u, 0x9Cu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEA46u, 0x00275230u, 5u);
        }

        case 0x00275230u: {
            TP_STATIC_GUARD(0x04EA46u, 0x22u, 0x28u, 0xBAu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x49u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBA28u, 0x0035D140u, 8u);
        }

        case 0x00275251u: {
            TP_STATIC_GUARD(0x04EA4Au, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xEA4Cu, 0x00275260u, 3u);
        }

        case 0x00275260u: {
            TP_STATIC_GUARD(0x04EA4Cu, 0xA9u, 0x0Fu, 0x00u);
            const uint16_t value = 0x000Fu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEA4Fu, 0x00275278u, 3u);
        }

        case 0x00275278u: {
            TP_STATIC_GUARD(0x04EA4Fu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEA52u, 0x00275290u, 5u);
        }

        case 0x00275290u: {
            TP_STATIC_GUARD(0x04EA52u, 0x22u, 0x18u, 0x85u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x55u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0x8518u, 0x003428C0u, 8u);
        }

        case 0x002752B0u: {
            TP_STATIC_GUARD(0x04EA56u, 0x82u, 0x41u, 0x01u);
            TP_STATIC_EXIT(0x04u, 0xEB9Au, 0x00275CD0u, 4u);
        }

        case 0x002752C8u: {
            TP_STATIC_GUARD(0x04EA59u, 0xC9u, 0x04u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0004u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEA5Cu, 0x002752E0u, 3u);
        }

        case 0x002752E0u: {
            TP_STATIC_GUARD(0x04EA5Cu, 0xD0u, 0x23u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xEA81u;
                if (tp_scpu_expect_next(cpu, 0x00275408u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xEA5Eu, 0x002752F0u, 2u);
        }

        case 0x002752F0u: {
            TP_STATIC_GUARD(0x04EA5Eu, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x61u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C0u, 8u);
        }

        case 0x00275313u: {
            TP_STATIC_GUARD(0x04EA62u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xEA64u, 0x00275323u, 3u);
        }

        case 0x00275323u: {
            TP_STATIC_GUARD(0x04EA64u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x04u, 0xEA66u, 0x00275332u, 3u);
        }

        case 0x00275332u: {
            TP_STATIC_GUARD(0x04EA66u, 0x9Cu, 0x6Cu, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1F6Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEA69u, 0x0027534Au, 4u);
        }

        case 0x0027534Au: {
            TP_STATIC_GUARD(0x04EA69u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xEA6Bu, 0x00275358u, 3u);
        }

        case 0x00275358u: {
            TP_STATIC_GUARD(0x04EA6Bu, 0x9Cu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEA6Eu, 0x00275370u, 5u);
        }

        case 0x00275370u: {
            TP_STATIC_GUARD(0x04EA6Eu, 0x22u, 0x28u, 0xBAu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x71u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBA28u, 0x0035D140u, 8u);
        }

        case 0x00275391u: {
            TP_STATIC_GUARD(0x04EA72u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xEA74u, 0x002753A0u, 3u);
        }

        case 0x002753A0u: {
            TP_STATIC_GUARD(0x04EA74u, 0xA9u, 0x08u, 0x00u);
            const uint16_t value = 0x0008u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEA77u, 0x002753B8u, 3u);
        }

        case 0x002753B8u: {
            TP_STATIC_GUARD(0x04EA77u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEA7Au, 0x002753D0u, 5u);
        }

        case 0x002753D0u: {
            TP_STATIC_GUARD(0x04EA7Au, 0x22u, 0x18u, 0x85u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x7Du) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0x8518u, 0x003428C0u, 8u);
        }

        case 0x002753F0u: {
            TP_STATIC_GUARD(0x04EA7Eu, 0x82u, 0x19u, 0x01u);
            TP_STATIC_EXIT(0x04u, 0xEB9Au, 0x00275CD0u, 4u);
        }

        case 0x00275408u: {
            TP_STATIC_GUARD(0x04EA81u, 0x82u, 0x2Eu, 0x01u);
            TP_STATIC_EXIT(0x04u, 0xEBB2u, 0x00275D90u, 4u);
        }

        case 0x00275420u: {
            TP_STATIC_GUARD(0x04EA84u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xEA86u, 0x00275430u, 3u);
        }

        case 0x00275430u: {
            TP_STATIC_GUARD(0x04EA86u, 0xC9u, 0x0Du, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Du;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEA89u, 0x00275448u, 3u);
        }

        case 0x00275448u: {
            TP_STATIC_GUARD(0x04EA89u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xEA8Eu;
                if (tp_scpu_expect_next(cpu, 0x00275470u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xEA8Bu, 0x00275458u, 2u);
        }

        case 0x00275458u: {
            TP_STATIC_GUARD(0x04EA8Bu, 0x82u, 0x2Bu, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xEAB9u, 0x002755C8u, 4u);
        }

        case 0x00275470u: {
            TP_STATIC_GUARD(0x04EA8Eu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xEA90u, 0x00275483u, 3u);
        }

        case 0x00275473u: {
            TP_STATIC_GUARD(0x04EA8Eu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xEA90u, 0x00275483u, 3u);
        }

        case 0x00275483u: {
            TP_STATIC_GUARD(0x04EA90u, 0xA9u, 0x08u);
            const uint8_t value = 0x08u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEA92u, 0x00275493u, 2u);
        }

        case 0x00275493u: {
            TP_STATIC_GUARD(0x04EA92u, 0x22u, 0x14u, 0xEDu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x95u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xED14u, 0x002768A3u, 8u);
        }

        case 0x002754B3u: {
            TP_STATIC_GUARD(0x04EA96u, 0x22u, 0x18u, 0x85u, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x99u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0x8518u, 0x006428C3u, 8u);
        }

        case 0x002754D3u: {
            TP_STATIC_GUARD(0x04EA9Au, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xEA9Cu, 0x002754E3u, 3u);
        }

        case 0x002754E3u: {
            TP_STATIC_GUARD(0x04EA9Cu, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x04u, 0xEA9Eu, 0x002754F2u, 3u);
        }

        case 0x002754F2u: {
            TP_STATIC_GUARD(0x04EA9Eu, 0x9Cu, 0x6Cu, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1F6Cu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEAA1u, 0x0027550Au, 4u);
        }

        case 0x0027550Au: {
            TP_STATIC_GUARD(0x04EAA1u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xEAA3u, 0x00275518u, 3u);
        }

        case 0x00275518u: {
            TP_STATIC_GUARD(0x04EAA3u, 0x9Cu, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEAA6u, 0x00275530u, 5u);
        }

        case 0x00275530u: {
            TP_STATIC_GUARD(0x04EAA6u, 0x22u, 0x28u, 0xBAu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA9u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBA28u, 0x0035D140u, 8u);
        }

        case 0x00275551u: {
            TP_STATIC_GUARD(0x04EAAAu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xEAACu, 0x00275560u, 3u);
        }

        case 0x00275560u: {
            TP_STATIC_GUARD(0x04EAACu, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEAAFu, 0x00275578u, 3u);
        }

        case 0x00275578u: {
            TP_STATIC_GUARD(0x04EAAFu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEAB2u, 0x00275590u, 5u);
        }

        case 0x00275590u: {
            TP_STATIC_GUARD(0x04EAB2u, 0x22u, 0x18u, 0x85u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xEAu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB5u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0x8518u, 0x003428C0u, 8u);
        }

        case 0x002755B0u: {
            TP_STATIC_GUARD(0x04EAB6u, 0x82u, 0xE1u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xEB9Au, 0x00275CD0u, 4u);
        }

        case 0x002755C8u: {
            TP_STATIC_GUARD(0x04EAB9u, 0xC9u, 0x1Cu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x001Cu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEABCu, 0x002755E0u, 3u);
        }

        case 0x002755E0u: {
            TP_STATIC_GUARD(0x04EABCu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xEAC1u;
                if (tp_scpu_expect_next(cpu, 0x00275608u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xEABEu, 0x002755F0u, 2u);
        }

        case 0x002755F0u: {
            TP_STATIC_GUARD(0x04EABEu, 0x82u, 0xC3u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xEB84u, 0x00275C20u, 4u);
        }

        case 0x00275608u: {
            TP_STATIC_GUARD(0x04EAC1u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xEAC3u, 0x00275618u, 3u);
        }

        case 0x00275618u: {
            TP_STATIC_GUARD(0x04EAC3u, 0xADu, 0x0Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEAC6u, 0x00275630u, 5u);
        }

        case 0x00275630u: {
            TP_STATIC_GUARD(0x04EAC6u, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEAC9u, 0x00275648u, 3u);
        }

        case 0x00275648u: {
            TP_STATIC_GUARD(0x04EAC9u, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xEACEu;
                if (tp_scpu_expect_next(cpu, 0x00275670u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xEACBu, 0x00275658u, 2u);
        }

        case 0x00275658u: {
            TP_STATIC_GUARD(0x04EACBu, 0x82u, 0xB6u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xEB84u, 0x00275C20u, 4u);
        }

        case 0x00275670u: {
            TP_STATIC_GUARD(0x04EACEu, 0xADu, 0x0Au, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x080Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEAD1u, 0x00275688u, 5u);
        }

        case 0x00275688u: {
            TP_STATIC_GUARD(0x04EAD1u, 0xC9u, 0x05u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0005u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEAD4u, 0x002756A0u, 3u);
        }

        case 0x002756A0u: {
            TP_STATIC_GUARD(0x04EAD4u, 0xD0u, 0x18u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xEAEEu;
                if (tp_scpu_expect_next(cpu, 0x00275770u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xEAD6u, 0x002756B0u, 2u);
        }

        case 0x002756B0u: {
            TP_STATIC_GUARD(0x04EAD6u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xEAD8u, 0x002756C2u, 3u);
        }

        case 0x002756C2u: {
            TP_STATIC_GUARD(0x04EAD8u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x04u, 0xEADAu, 0x002756D2u, 3u);
        }

        case 0x002756D2u: {
            TP_STATIC_GUARD(0x04EADAu, 0xA9u, 0x0Au);
            const uint8_t value = 0x0Au;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEADCu, 0x002756E2u, 2u);
        }

        case 0x002756E2u: {
            TP_STATIC_GUARD(0x04EADCu, 0x8Du, 0xD7u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07D7u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEADFu, 0x002756FAu, 4u);
        }

        case 0x002756FAu: {
            TP_STATIC_GUARD(0x04EADFu, 0xAEu, 0x08u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0808u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEAE2u, 0x00275712u, 5u);
        }

        case 0x00275712u: {
            TP_STATIC_GUARD(0x04EAE2u, 0x8Eu, 0xD8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07D8u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEAE5u, 0x0027572Au, 5u);
        }

        case 0x0027572Au: {
            TP_STATIC_GUARD(0x04EAE5u, 0xAEu, 0x14u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0814u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEAE8u, 0x00275742u, 5u);
        }

        case 0x00275742u: {
            TP_STATIC_GUARD(0x04EAE8u, 0x8Eu, 0xDAu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07DAu;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEAEBu, 0x0027575Au, 5u);
        }

        case 0x0027575Au: {
            TP_STATIC_GUARD(0x04EAEBu, 0x82u, 0x96u, 0x00u);
            TP_STATIC_EXIT(0x04u, 0xEB84u, 0x00275C22u, 4u);
        }

        case 0x00275770u: {
            TP_STATIC_GUARD(0x04EAEEu, 0xC9u, 0x06u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0006u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEAF1u, 0x00275788u, 3u);
        }

        case 0x00275788u: {
            TP_STATIC_GUARD(0x04EAF1u, 0xD0u, 0x12u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x04u;
                cpu->pc = 0xEB05u;
                if (tp_scpu_expect_next(cpu, 0x00275828u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x04u, 0xEAF3u, 0x00275798u, 2u);
        }

        case 0x00275798u: {
            TP_STATIC_GUARD(0x04EAF3u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xEAF5u, 0x002757AAu, 3u);
        }

        case 0x002757AAu: {
            TP_STATIC_GUARD(0x04EAF5u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x04u, 0xEAF7u, 0x002757BAu, 3u);
        }

        case 0x002757BAu: {
            TP_STATIC_GUARD(0x04EAF7u, 0xA9u, 0x0Cu);
            const uint8_t value = 0x0Cu;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEAF9u, 0x002757CAu, 2u);
        }

        case 0x002757CAu: {
            TP_STATIC_GUARD(0x04EAF9u, 0x8Du, 0xD7u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07D7u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEAFCu, 0x002757E2u, 4u);
        }

        case 0x002757E2u: {
            TP_STATIC_GUARD(0x04EAFCu, 0xAEu, 0x08u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0808u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xEAFFu, 0x002757FAu, 5u);
        }

        case 0x002757FAu: {
            TP_STATIC_GUARD(0x04EAFFu, 0x8Eu, 0xD8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07D8u;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xEB02u, 0x00275812u, 5u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
