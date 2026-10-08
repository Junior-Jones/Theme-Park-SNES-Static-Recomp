/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0006BE(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x0035F012u: {
            TP_STATIC_GUARD(0x06BE02u, 0x9Cu, 0xB3u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07B3u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE05u, 0x0035F02Au, 4u);
        }

        case 0x0035F02Au: {
            TP_STATIC_GUARD(0x06BE05u, 0x9Cu, 0xB0u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07B0u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE08u, 0x0035F042u, 4u);
        }

        case 0x0035F042u: {
            TP_STATIC_GUARD(0x06BE08u, 0x9Cu, 0xB1u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07B1u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE0Bu, 0x0035F05Au, 4u);
        }

        case 0x0035F05Au: {
            TP_STATIC_GUARD(0x06BE0Bu, 0x9Cu, 0x53u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0753u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE0Eu, 0x0035F072u, 4u);
        }

        case 0x0035F072u: {
            TP_STATIC_GUARD(0x06BE0Eu, 0x9Cu, 0x5Bu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x185Bu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE11u, 0x0035F08Au, 4u);
        }

        case 0x0035F08Au: {
            TP_STATIC_GUARD(0x06BE11u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xBE13u, 0x0035F098u, 3u);
        }

        case 0x0035F098u: {
            TP_STATIC_GUARD(0x06BE13u, 0x9Cu, 0xDBu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18DBu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE16u, 0x0035F0B0u, 5u);
        }

        case 0x0035F0B0u: {
            TP_STATIC_GUARD(0x06BE16u, 0x9Cu, 0xD9u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18D9u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE19u, 0x0035F0C8u, 5u);
        }

        case 0x0035F0C8u: {
            TP_STATIC_GUARD(0x06BE19u, 0x9Cu, 0xDDu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18DDu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE1Cu, 0x0035F0E0u, 5u);
        }

        case 0x0035F0E0u: {
            TP_STATIC_GUARD(0x06BE1Cu, 0xA9u, 0x0Bu, 0x00u);
            const uint16_t value = 0x000Bu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE1Fu, 0x0035F0F8u, 3u);
        }

        case 0x0035F0F8u: {
            TP_STATIC_GUARD(0x06BE1Fu, 0x8Du, 0xD7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18D7u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE22u, 0x0035F110u, 5u);
        }

        case 0x0035F110u: {
            TP_STATIC_GUARD(0x06BE22u, 0xA9u, 0xB4u, 0x00u);
            const uint16_t value = 0x00B4u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE25u, 0x0035F128u, 3u);
        }

        case 0x0035F128u: {
            TP_STATIC_GUARD(0x06BE25u, 0x8Du, 0x0Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE28u, 0x0035F140u, 5u);
        }

        case 0x0035F140u: {
            TP_STATIC_GUARD(0x06BE28u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE2Bu, 0x0035F158u, 3u);
        }

        case 0x0035F158u: {
            TP_STATIC_GUARD(0x06BE2Bu, 0x8Du, 0x55u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1855u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE2Eu, 0x0035F170u, 5u);
        }

        case 0x0035F170u: {
            TP_STATIC_GUARD(0x06BE2Eu, 0xA9u, 0x02u, 0x00u);
            const uint16_t value = 0x0002u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE31u, 0x0035F188u, 3u);
        }

        case 0x0035F188u: {
            TP_STATIC_GUARD(0x06BE31u, 0x8Du, 0x57u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1857u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE34u, 0x0035F1A0u, 5u);
        }

        case 0x0035F1A0u: {
            TP_STATIC_GUARD(0x06BE34u, 0x9Cu, 0x1Au, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x081Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE37u, 0x0035F1B8u, 5u);
        }

        case 0x0035F1B8u: {
            TP_STATIC_GUARD(0x06BE37u, 0x9Cu, 0xBCu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07BCu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE3Au, 0x0035F1D0u, 5u);
        }

        case 0x0035F1D0u: {
            TP_STATIC_GUARD(0x06BE3Au, 0xA9u, 0xE8u, 0x03u);
            const uint16_t value = 0x03E8u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE3Du, 0x0035F1E8u, 3u);
        }

        case 0x0035F1E8u: {
            TP_STATIC_GUARD(0x06BE3Du, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE40u, 0x0035F200u, 3u);
        }

        case 0x0035F200u: {
            TP_STATIC_GUARD(0x06BE40u, 0x8Du, 0xB8u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1FB8u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE43u, 0x0035F218u, 5u);
        }

        case 0x0035F218u: {
            TP_STATIC_GUARD(0x06BE43u, 0x8Eu, 0xBAu, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1FBAu;
            if (tp_scpu_write16(cpu, bus, address, cpu->x) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE46u, 0x0035F230u, 5u);
        }

        case 0x0035F230u: {
            TP_STATIC_GUARD(0x06BE46u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xBE48u, 0x0035F241u, 3u);
        }

        case 0x0035F241u: {
            TP_STATIC_GUARD(0x06BE48u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x06u, 0xBE4Au, 0x0035F251u, 3u);
        }

        case 0x0035F251u: {
            TP_STATIC_GUARD(0x06BE4Au, 0xADu, 0x4Fu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x004Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE4Du, 0x0035F269u, 5u);
        }

        case 0x0035F269u: {
            TP_STATIC_GUARD(0x06BE4Du, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE50u, 0x0035F281u, 5u);
        }

        case 0x0035F281u: {
            TP_STATIC_GUARD(0x06BE50u, 0xAEu, 0x51u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0051u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE53u, 0x0035F299u, 4u);
        }

        case 0x0035F299u: {
            TP_STATIC_GUARD(0x06BE53u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE56u, 0x0035F2B1u, 4u);
        }

        case 0x0035F2B1u: {
            TP_STATIC_GUARD(0x06BE56u, 0x9Cu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE59u, 0x0035F2C9u, 5u);
        }

        case 0x0035F2C9u: {
            TP_STATIC_GUARD(0x06BE59u, 0xA9u, 0x00u, 0x40u);
            const uint16_t value = 0x4000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE5Cu, 0x0035F2E1u, 3u);
        }

        case 0x0035F2E1u: {
            TP_STATIC_GUARD(0x06BE5Cu, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE5Fu, 0x0035F2F9u, 5u);
        }

        case 0x0035F2F9u: {
            TP_STATIC_GUARD(0x06BE5Fu, 0x22u, 0x55u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x62u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8055u, 0x002402A9u, 8u);
        }

        case 0x0035F319u: {
            TP_STATIC_GUARD(0x06BE63u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xBE65u, 0x0035F329u, 3u);
        }

        case 0x0035F329u: {
            TP_STATIC_GUARD(0x06BE65u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x06u, 0xBE67u, 0x0035F339u, 3u);
        }

        case 0x0035F339u: {
            TP_STATIC_GUARD(0x06BE67u, 0xADu, 0x3Au, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x003Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE6Au, 0x0035F351u, 5u);
        }

        case 0x0035F351u: {
            TP_STATIC_GUARD(0x06BE6Au, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE6Du, 0x0035F369u, 5u);
        }

        case 0x0035F369u: {
            TP_STATIC_GUARD(0x06BE6Du, 0xAEu, 0x3Cu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x003Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE70u, 0x0035F381u, 4u);
        }

        case 0x0035F381u: {
            TP_STATIC_GUARD(0x06BE70u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE73u, 0x0035F399u, 4u);
        }

        case 0x0035F399u: {
            TP_STATIC_GUARD(0x06BE73u, 0x9Cu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE76u, 0x0035F3B1u, 5u);
        }

        case 0x0035F3B1u: {
            TP_STATIC_GUARD(0x06BE76u, 0xA9u, 0x8Eu, 0x8Fu);
            const uint16_t value = 0x8F8Eu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE79u, 0x0035F3C9u, 3u);
        }

        case 0x0035F3C9u: {
            TP_STATIC_GUARD(0x06BE79u, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE7Cu, 0x0035F3E1u, 5u);
        }

        case 0x0035F3E1u: {
            TP_STATIC_GUARD(0x06BE7Cu, 0x22u, 0x55u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x7Fu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8055u, 0x002402A9u, 8u);
        }

        case 0x0035F401u: {
            TP_STATIC_GUARD(0x06BE80u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xBE82u, 0x0035F411u, 3u);
        }

        case 0x0035F411u: {
            TP_STATIC_GUARD(0x06BE82u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x06u, 0xBE84u, 0x0035F421u, 3u);
        }

        case 0x0035F421u: {
            TP_STATIC_GUARD(0x06BE84u, 0xA9u, 0xC7u, 0xA6u);
            const uint16_t value = 0xA6C7u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE87u, 0x0035F439u, 3u);
        }

        case 0x0035F439u: {
            TP_STATIC_GUARD(0x06BE87u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE8Au, 0x0035F451u, 5u);
        }

        case 0x0035F451u: {
            TP_STATIC_GUARD(0x06BE8Au, 0xA2u, 0x7Eu);
            const uint8_t value = 0x7Eu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE8Cu, 0x0035F461u, 2u);
        }

        case 0x0035F461u: {
            TP_STATIC_GUARD(0x06BE8Cu, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE8Fu, 0x0035F479u, 4u);
        }

        case 0x0035F479u: {
            TP_STATIC_GUARD(0x06BE8Fu, 0x9Cu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE92u, 0x0035F491u, 5u);
        }

        case 0x0035F491u: {
            TP_STATIC_GUARD(0x06BE92u, 0xA9u, 0xB0u, 0x04u);
            const uint16_t value = 0x04B0u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBE95u, 0x0035F4A9u, 3u);
        }

        case 0x0035F4A9u: {
            TP_STATIC_GUARD(0x06BE95u, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBE98u, 0x0035F4C1u, 5u);
        }

        case 0x0035F4C1u: {
            TP_STATIC_GUARD(0x06BE98u, 0x22u, 0x55u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x9Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8055u, 0x002402A9u, 8u);
        }

        case 0x0035F4E1u: {
            TP_STATIC_GUARD(0x06BE9Cu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xBE9Eu, 0x0035F4F1u, 3u);
        }

        case 0x0035F4F1u: {
            TP_STATIC_GUARD(0x06BE9Eu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x06u, 0xBEA0u, 0x0035F501u, 3u);
        }

        case 0x0035F501u: {
            TP_STATIC_GUARD(0x06BEA0u, 0xA9u, 0x8Eu, 0xA5u);
            const uint16_t value = 0xA58Eu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEA3u, 0x0035F519u, 3u);
        }

        case 0x0035F519u: {
            TP_STATIC_GUARD(0x06BEA3u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBEA6u, 0x0035F531u, 5u);
        }

        case 0x0035F531u: {
            TP_STATIC_GUARD(0x06BEA6u, 0xA2u, 0x7Eu);
            const uint8_t value = 0x7Eu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEA8u, 0x0035F541u, 2u);
        }

        case 0x0035F541u: {
            TP_STATIC_GUARD(0x06BEA8u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBEABu, 0x0035F559u, 4u);
        }

        case 0x0035F559u: {
            TP_STATIC_GUARD(0x06BEABu, 0x9Cu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBEAEu, 0x0035F571u, 5u);
        }

        case 0x0035F571u: {
            TP_STATIC_GUARD(0x06BEAEu, 0xA9u, 0x39u, 0x01u);
            const uint16_t value = 0x0139u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEB1u, 0x0035F589u, 3u);
        }

        case 0x0035F589u: {
            TP_STATIC_GUARD(0x06BEB1u, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBEB4u, 0x0035F5A1u, 5u);
        }

        case 0x0035F5A1u: {
            TP_STATIC_GUARD(0x06BEB4u, 0x22u, 0x55u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB7u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8055u, 0x002402A9u, 8u);
        }

        case 0x0035F5C1u: {
            TP_STATIC_GUARD(0x06BEB8u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xBEBAu, 0x0035F5D1u, 3u);
        }

        case 0x0035F5D1u: {
            TP_STATIC_GUARD(0x06BEBAu, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x06u, 0xBEBCu, 0x0035F5E1u, 3u);
        }

        case 0x0035F5E1u: {
            TP_STATIC_GUARD(0x06BEBCu, 0xA9u, 0x00u, 0x89u);
            const uint16_t value = 0x8900u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEBFu, 0x0035F5F9u, 3u);
        }

        case 0x0035F5F9u: {
            TP_STATIC_GUARD(0x06BEBFu, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBEC2u, 0x0035F611u, 5u);
        }

        case 0x0035F611u: {
            TP_STATIC_GUARD(0x06BEC2u, 0xA2u, 0x7Eu);
            const uint8_t value = 0x7Eu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEC4u, 0x0035F621u, 2u);
        }

        case 0x0035F621u: {
            TP_STATIC_GUARD(0x06BEC4u, 0x8Eu, 0x8Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Cu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBEC7u, 0x0035F639u, 4u);
        }

        case 0x0035F639u: {
            TP_STATIC_GUARD(0x06BEC7u, 0x9Cu, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBECAu, 0x0035F651u, 5u);
        }

        case 0x0035F651u: {
            TP_STATIC_GUARD(0x06BECAu, 0xA9u, 0xE8u, 0x12u);
            const uint16_t value = 0x12E8u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBECDu, 0x0035F669u, 3u);
        }

        case 0x0035F669u: {
            TP_STATIC_GUARD(0x06BECDu, 0x8Du, 0x92u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0792u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBED0u, 0x0035F681u, 5u);
        }

        case 0x0035F681u: {
            TP_STATIC_GUARD(0x06BED0u, 0x22u, 0x55u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBEu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xD3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x8055u, 0x002402A9u, 8u);
        }

        case 0x0035F6A1u: {
            TP_STATIC_GUARD(0x06BED4u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xBED6u, 0x0035F6B3u, 3u);
        }

        case 0x0035F6B3u: {
            TP_STATIC_GUARD(0x06BED6u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x06u, 0xBED8u, 0x0035F6C2u, 3u);
        }

        case 0x0035F6C2u: {
            TP_STATIC_GUARD(0x06BED8u, 0xA2u, 0xFFu, 0x05u);
            const uint16_t value = 0x05FFu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEDBu, 0x0035F6DAu, 3u);
        }

        case 0x0035F6DAu: {
            TP_STATIC_GUARD(0x06BEDBu, 0xBFu, 0x00u, 0x80u, 0x01u);
            const uint32_t address = (0x018000u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEDFu, 0x0035F6FAu, 5u);
        }

        case 0x0035F6FAu: {
            TP_STATIC_GUARD(0x06BEDFu, 0x9Du, 0x4Du, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x084Du + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBEE2u, 0x0035F712u, 5u);
        }

        case 0x0035F712u: {
            TP_STATIC_GUARD(0x06BEE2u, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEE3u, 0x0035F71Au, 2u);
        }

        case 0x0035F71Au: {
            TP_STATIC_GUARD(0x06BEE3u, 0x10u, 0xF6u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xBEDBu;
                if (tp_scpu_expect_next(cpu, 0x0035F6DAu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xBEE5u, 0x0035F72Au, 2u);
        }

        case 0x0035F72Au: {
            TP_STATIC_GUARD(0x06BEE5u, 0xA2u, 0x96u, 0x02u);
            const uint16_t value = 0x0296u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEE8u, 0x0035F742u, 3u);
        }

        case 0x0035F742u: {
            TP_STATIC_GUARD(0x06BEE8u, 0xBFu, 0xD0u, 0x85u, 0x01u);
            const uint32_t address = (0x0185D0u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEECu, 0x0035F762u, 5u);
        }

        case 0x0035F762u: {
            TP_STATIC_GUARD(0x06BEECu, 0x9Du, 0x4Du, 0x0Eu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0E4Du + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBEEFu, 0x0035F77Au, 5u);
        }

        case 0x0035F77Au: {
            TP_STATIC_GUARD(0x06BEEFu, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEF0u, 0x0035F782u, 2u);
        }

        case 0x0035F782u: {
            TP_STATIC_GUARD(0x06BEF0u, 0x10u, 0xF6u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xBEE8u;
                if (tp_scpu_expect_next(cpu, 0x0035F742u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xBEF2u, 0x0035F792u, 2u);
        }

        case 0x0035F792u: {
            TP_STATIC_GUARD(0x06BEF2u, 0xA2u, 0xFFu, 0x02u);
            const uint16_t value = 0x02FFu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEF5u, 0x0035F7AAu, 3u);
        }

        case 0x0035F7AAu: {
            TP_STATIC_GUARD(0x06BEF5u, 0xBFu, 0x4Cu, 0x8Fu, 0x01u);
            const uint32_t address = (0x018F4Cu + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEF9u, 0x0035F7CAu, 5u);
        }

        case 0x0035F7CAu: {
            TP_STATIC_GUARD(0x06BEF9u, 0x9Du, 0xE4u, 0x10u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x10E4u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBEFCu, 0x0035F7E2u, 5u);
        }

        case 0x0035F7E2u: {
            TP_STATIC_GUARD(0x06BEFCu, 0xCAu);
            cpu->x = (uint16_t)((cpu->x - 1u) & 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xBEFDu, 0x0035F7EAu, 2u);
        }

        case 0x0035F7EAu: {
            TP_STATIC_GUARD(0x06BEFDu, 0x10u, 0xF6u);
            if ((cpu->p & TP_P_N) == 0u) {
                cpu->pbr = 0x06u;
                cpu->pc = 0xBEF5u;
                if (tp_scpu_expect_next(cpu, 0x0035F7AAu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x06u, 0xBEFFu, 0x0035F7FAu, 2u);
        }

        case 0x0035F7FAu: {
            TP_STATIC_GUARD(0x06BEFFu, 0x22u, 0x9Fu, 0x83u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xBFu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x02u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0x839Fu, 0x00341CFAu, 8u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
