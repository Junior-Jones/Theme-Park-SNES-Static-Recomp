/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0006C0(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00360009u: {
            TP_STATIC_GUARD(0x06C001u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x06u, 0xC003u, 0x00360019u, 3u);
        }

        case 0x00360019u: {
            TP_STATIC_GUARD(0x06C003u, 0xADu, 0x16u, 0x00u);
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
            TP_STATIC_EXIT(0x06u, 0xC006u, 0x00360031u, 5u);
        }

        case 0x00360031u: {
            TP_STATIC_GUARD(0x06C006u, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC007u, 0x00360039u, 4u);
        }

        case 0x00360039u: {
            TP_STATIC_GUARD(0x06C007u, 0xAEu, 0x18u, 0x00u);
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
            TP_STATIC_EXIT(0x06u, 0xC00Au, 0x00360051u, 4u);
        }

        case 0x00360051u: {
            TP_STATIC_GUARD(0x06C00Au, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC00Bu, 0x00360059u, 3u);
        }

        case 0x00360059u: {
            TP_STATIC_GUARD(0x06C00Bu, 0xADu, 0x19u, 0x00u);
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
            TP_STATIC_EXIT(0x06u, 0xC00Eu, 0x00360071u, 5u);
        }

        case 0x00360071u: {
            TP_STATIC_GUARD(0x06C00Eu, 0x48u);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a >> 8u)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC00Fu, 0x00360079u, 4u);
        }

        case 0x00360079u: {
            TP_STATIC_GUARD(0x06C00Fu, 0xAEu, 0x1Bu, 0x00u);
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
            TP_STATIC_EXIT(0x06u, 0xC012u, 0x00360091u, 4u);
        }

        case 0x00360091u: {
            TP_STATIC_GUARD(0x06C012u, 0xDAu);
            if (tp_scpu_push8(cpu, bus, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC013u, 0x00360099u, 3u);
        }

        case 0x00360099u: {
            TP_STATIC_GUARD(0x06C013u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xC015u, 0x003600A8u, 3u);
        }

        case 0x003600A8u: {
            TP_STATIC_GUARD(0x06C015u, 0xADu, 0x8Au, 0x07u);
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
            TP_STATIC_EXIT(0x06u, 0xC018u, 0x003600C0u, 5u);
        }

        case 0x003600C0u: {
            TP_STATIC_GUARD(0x06C018u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC01Bu, 0x003600D8u, 3u);
        }

        case 0x003600D8u: {
            TP_STATIC_GUARD(0x06C01Bu, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC01Eu, 0x003600F0u, 5u);
        }

        case 0x003600F0u: {
            TP_STATIC_GUARD(0x06C01Eu, 0x8Du, 0x06u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0806u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC021u, 0x00360108u, 5u);
        }

        case 0x00360108u: {
            TP_STATIC_GUARD(0x06C021u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xC023u, 0x00360119u, 3u);
        }

        case 0x00360119u: {
            TP_STATIC_GUARD(0x06C023u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x06u, 0xC025u, 0x00360129u, 3u);
        }

        case 0x00360129u: {
            TP_STATIC_GUARD(0x06C025u, 0xA9u, 0xE8u, 0x9Bu);
            const uint16_t value = 0x9BE8u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC028u, 0x00360141u, 3u);
        }

        case 0x00360141u: {
            TP_STATIC_GUARD(0x06C028u, 0xA2u, 0x7Eu);
            const uint8_t value = 0x7Eu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC02Au, 0x00360151u, 2u);
        }

        case 0x00360151u: {
            TP_STATIC_GUARD(0x06C02Au, 0x8Du, 0x5Eu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x005Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC02Du, 0x00360169u, 5u);
        }

        case 0x00360169u: {
            TP_STATIC_GUARD(0x06C02Du, 0x8Eu, 0x60u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0060u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC030u, 0x00360181u, 4u);
        }

        case 0x00360181u: {
            TP_STATIC_GUARD(0x06C030u, 0xA9u, 0x8Eu, 0xA5u);
            const uint16_t value = 0xA58Eu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC033u, 0x00360199u, 3u);
        }

        case 0x00360199u: {
            TP_STATIC_GUARD(0x06C033u, 0xA2u, 0x7Eu);
            const uint8_t value = 0x7Eu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC035u, 0x003601A9u, 2u);
        }

        case 0x003601A9u: {
            TP_STATIC_GUARD(0x06C035u, 0x8Du, 0x58u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0058u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC038u, 0x003601C1u, 5u);
        }

        case 0x003601C1u: {
            TP_STATIC_GUARD(0x06C038u, 0x8Eu, 0x5Au, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x005Au;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC03Bu, 0x003601D9u, 4u);
        }

        case 0x003601D9u: {
            TP_STATIC_GUARD(0x06C03Bu, 0xA9u, 0x00u, 0x89u);
            const uint16_t value = 0x8900u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC03Eu, 0x003601F1u, 3u);
        }

        case 0x003601F1u: {
            TP_STATIC_GUARD(0x06C03Eu, 0xA2u, 0x7Eu);
            const uint8_t value = 0x7Eu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC040u, 0x00360201u, 2u);
        }

        case 0x00360201u: {
            TP_STATIC_GUARD(0x06C040u, 0x8Du, 0x5Bu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x005Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC043u, 0x00360219u, 5u);
        }

        case 0x00360219u: {
            TP_STATIC_GUARD(0x06C043u, 0x8Eu, 0x5Du, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x005Du;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC046u, 0x00360231u, 4u);
        }

        case 0x00360231u: {
            TP_STATIC_GUARD(0x06C046u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xC048u, 0x00360240u, 3u);
        }

        case 0x00360240u: {
            TP_STATIC_GUARD(0x06C048u, 0xACu, 0x06u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0806u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC04Bu, 0x00360258u, 5u);
        }

        case 0x00360258u: {
            TP_STATIC_GUARD(0x06C04Bu, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC04Cu, 0x00360260u, 2u);
        }

        case 0x00360260u: {
            TP_STATIC_GUARD(0x06C04Cu, 0xA9u, 0x0Eu, 0x00u);
            const uint16_t value = 0x000Eu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC04Fu, 0x00360278u, 3u);
        }

        case 0x00360278u: {
            TP_STATIC_GUARD(0x06C04Fu, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC0u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x52u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x00360298u: {
            TP_STATIC_GUARD(0x06C053u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC054u, 0x003602A0u, 2u);
        }

        case 0x003602A0u: {
            TP_STATIC_GUARD(0x06C054u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x06u, 0xC055u, 0x003602A8u, 2u);
        }

        case 0x003602A8u: {
            TP_STATIC_GUARD(0x06C055u, 0x69u, 0x08u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0008u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC058u, 0x003602C0u, 3u);
        }

        case 0x003602C0u: {
            TP_STATIC_GUARD(0x06C058u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC059u, 0x003602C8u, 2u);
        }

        case 0x003602C8u: {
            TP_STATIC_GUARD(0x06C059u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xC05Bu, 0x003602DAu, 3u);
        }

        case 0x003602DAu: {
            TP_STATIC_GUARD(0x06C05Bu, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x06u, 0xC05Du, 0x003602EAu, 3u);
        }

        case 0x003602EAu: {
            TP_STATIC_GUARD(0x06C05Du, 0xADu, 0x06u, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0806u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC060u, 0x00360302u, 4u);
        }

        case 0x00360302u: {
            TP_STATIC_GUARD(0x06C060u, 0x9Fu, 0xCEu, 0x07u, 0x00u);
            const uint32_t address = (0x0007CEu + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC064u, 0x00360322u, 5u);
        }

        case 0x00360322u: {
            TP_STATIC_GUARD(0x06C064u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xC066u, 0x00360330u, 3u);
        }

        case 0x00360330u: {
            TP_STATIC_GUARD(0x06C066u, 0xA2u, 0x5Cu, 0x00u);
            const uint16_t value = 0x005Cu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC069u, 0x00360348u, 3u);
        }

        case 0x00360348u: {
            TP_STATIC_GUARD(0x06C069u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC06Cu, 0x00360360u, 3u);
        }

        case 0x00360360u: {
            TP_STATIC_GUARD(0x06C06Cu, 0x9Fu, 0x00u, 0x89u, 0x7Eu);
            const uint32_t address = (0x7E8900u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC070u, 0x00360380u, 6u);
        }

        case 0x00360380u: {
            TP_STATIC_GUARD(0x06C070u, 0xA2u, 0x5Eu, 0x00u);
            const uint16_t value = 0x005Eu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC073u, 0x00360398u, 3u);
        }

        case 0x00360398u: {
            TP_STATIC_GUARD(0x06C073u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC076u, 0x003603B0u, 3u);
        }

        case 0x003603B0u: {
            TP_STATIC_GUARD(0x06C076u, 0x9Fu, 0x00u, 0x89u, 0x7Eu);
            const uint32_t address = (0x7E8900u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC07Au, 0x003603D0u, 6u);
        }

        case 0x003603D0u: {
            TP_STATIC_GUARD(0x06C07Au, 0xA2u, 0x1Du, 0x00u);
            const uint16_t value = 0x001Du;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC07Du, 0x003603E8u, 3u);
        }

        case 0x003603E8u: {
            TP_STATIC_GUARD(0x06C07Du, 0xA9u, 0x32u, 0x00u);
            const uint16_t value = 0x0032u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC080u, 0x00360400u, 3u);
        }

        case 0x00360400u: {
            TP_STATIC_GUARD(0x06C080u, 0x9Fu, 0x00u, 0x89u, 0x7Eu);
            const uint32_t address = (0x7E8900u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC084u, 0x00360420u, 6u);
        }

        case 0x00360420u: {
            TP_STATIC_GUARD(0x06C084u, 0xA2u, 0x1Du, 0x00u);
            const uint16_t value = 0x001Du;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC087u, 0x00360438u, 3u);
        }

        case 0x00360438u: {
            TP_STATIC_GUARD(0x06C087u, 0xBFu, 0x00u, 0x89u, 0x7Eu);
            const uint32_t address = (0x7E8900u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC08Bu, 0x00360458u, 6u);
        }

        case 0x00360458u: {
            TP_STATIC_GUARD(0x06C08Bu, 0xA2u, 0x79u, 0x01u);
            const uint16_t value = 0x0179u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC08Eu, 0x00360470u, 3u);
        }

        case 0x00360470u: {
            TP_STATIC_GUARD(0x06C08Eu, 0x9Fu, 0xE8u, 0x9Bu, 0x7Eu);
            const uint32_t address = (0x7E9BE8u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC092u, 0x00360490u, 6u);
        }

        case 0x00360490u: {
            TP_STATIC_GUARD(0x06C092u, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xC094u, 0x003604A2u, 3u);
        }

        case 0x003604A2u: {
            TP_STATIC_GUARD(0x06C094u, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x06u, 0xC096u, 0x003604B2u, 3u);
        }

        case 0x003604B2u: {
            TP_STATIC_GUARD(0x06C096u, 0xA2u, 0x5Fu, 0x04u);
            const uint16_t value = 0x045Fu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC099u, 0x003604CAu, 3u);
        }

        case 0x003604CAu: {
            TP_STATIC_GUARD(0x06C099u, 0xA9u, 0x40u);
            const uint8_t value = 0x40u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC09Bu, 0x003604DAu, 2u);
        }

        case 0x003604DAu: {
            TP_STATIC_GUARD(0x06C09Bu, 0x9Fu, 0xE8u, 0x9Bu, 0x7Eu);
            const uint32_t address = (0x7E9BE8u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC09Fu, 0x003604FAu, 5u);
        }

        case 0x003604FAu: {
            TP_STATIC_GUARD(0x06C09Fu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xC0A1u, 0x00360508u, 3u);
        }

        case 0x00360508u: {
            TP_STATIC_GUARD(0x06C0A1u, 0xA2u, 0x60u, 0x04u);
            const uint16_t value = 0x0460u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0A4u, 0x00360520u, 3u);
        }

        case 0x00360520u: {
            TP_STATIC_GUARD(0x06C0A4u, 0xA9u, 0x14u, 0x00u);
            const uint16_t value = 0x0014u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0A7u, 0x00360538u, 3u);
        }

        case 0x00360538u: {
            TP_STATIC_GUARD(0x06C0A7u, 0x9Fu, 0xE8u, 0x9Bu, 0x7Eu);
            const uint32_t address = (0x7E9BE8u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC0ABu, 0x00360558u, 6u);
        }

        case 0x00360558u: {
            TP_STATIC_GUARD(0x06C0ABu, 0xA2u, 0xB0u, 0x00u);
            const uint16_t value = 0x00B0u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0AEu, 0x00360570u, 3u);
        }

        case 0x00360570u: {
            TP_STATIC_GUARD(0x06C0AEu, 0xBFu, 0x00u, 0x89u, 0x7Eu);
            const uint32_t address = (0x7E8900u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0B2u, 0x00360590u, 6u);
        }

        case 0x00360590u: {
            TP_STATIC_GUARD(0x06C0B2u, 0xA2u, 0x8Du, 0x04u);
            const uint16_t value = 0x048Du;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0B5u, 0x003605A8u, 3u);
        }

        case 0x003605A8u: {
            TP_STATIC_GUARD(0x06C0B5u, 0x9Fu, 0xE8u, 0x9Bu, 0x7Eu);
            const uint32_t address = (0x7E9BE8u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC0B9u, 0x003605C8u, 6u);
        }

        case 0x003605C8u: {
            TP_STATIC_GUARD(0x06C0B9u, 0xA2u, 0xACu, 0x00u);
            const uint16_t value = 0x00ACu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0BCu, 0x003605E0u, 3u);
        }

        case 0x003605E0u: {
            TP_STATIC_GUARD(0x06C0BCu, 0xBFu, 0x00u, 0x89u, 0x7Eu);
            const uint32_t address = (0x7E8900u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0C0u, 0x00360600u, 6u);
        }

        case 0x00360600u: {
            TP_STATIC_GUARD(0x06C0C0u, 0xA2u, 0x8Fu, 0x04u);
            const uint16_t value = 0x048Fu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0C3u, 0x00360618u, 3u);
        }

        case 0x00360618u: {
            TP_STATIC_GUARD(0x06C0C3u, 0x9Fu, 0xE8u, 0x9Bu, 0x7Eu);
            const uint32_t address = (0x7E9BE8u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC0C7u, 0x00360638u, 6u);
        }

        case 0x00360638u: {
            TP_STATIC_GUARD(0x06C0C7u, 0xA2u, 0xB4u, 0x00u);
            const uint16_t value = 0x00B4u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0CAu, 0x00360650u, 3u);
        }

        case 0x00360650u: {
            TP_STATIC_GUARD(0x06C0CAu, 0xBFu, 0x00u, 0x89u, 0x7Eu);
            const uint32_t address = (0x7E8900u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0CEu, 0x00360670u, 6u);
        }

        case 0x00360670u: {
            TP_STATIC_GUARD(0x06C0CEu, 0xA2u, 0x8Bu, 0x04u);
            const uint16_t value = 0x048Bu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0D1u, 0x00360688u, 3u);
        }

        case 0x00360688u: {
            TP_STATIC_GUARD(0x06C0D1u, 0x9Fu, 0xE8u, 0x9Bu, 0x7Eu);
            const uint32_t address = (0x7E9BE8u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC0D5u, 0x003606A8u, 6u);
        }

        case 0x003606A8u: {
            TP_STATIC_GUARD(0x06C0D5u, 0xA2u, 0xF0u, 0x00u);
            const uint16_t value = 0x00F0u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0D8u, 0x003606C0u, 3u);
        }

        case 0x003606C0u: {
            TP_STATIC_GUARD(0x06C0D8u, 0xA9u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0DBu, 0x003606D8u, 3u);
        }

        case 0x003606D8u: {
            TP_STATIC_GUARD(0x06C0DBu, 0x9Fu, 0x00u, 0x89u, 0x7Eu);
            const uint32_t address = (0x7E8900u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC0DFu, 0x003606F8u, 6u);
        }

        case 0x003606F8u: {
            TP_STATIC_GUARD(0x06C0DFu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x06u, 0xC0E1u, 0x00360708u, 3u);
        }

        case 0x00360708u: {
            TP_STATIC_GUARD(0x06C0E1u, 0xA2u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0E4u, 0x00360720u, 3u);
        }

        case 0x00360720u: {
            TP_STATIC_GUARD(0x06C0E4u, 0xA9u, 0xC8u, 0x00u);
            const uint16_t value = 0x00C8u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0E7u, 0x00360738u, 3u);
        }

        case 0x00360738u: {
            TP_STATIC_GUARD(0x06C0E7u, 0x9Fu, 0x00u, 0x89u, 0x7Eu);
            const uint32_t address = (0x7E8900u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC0EBu, 0x00360758u, 6u);
        }

        case 0x00360758u: {
            TP_STATIC_GUARD(0x06C0EBu, 0xA2u, 0x02u, 0x00u);
            const uint16_t value = 0x0002u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0EEu, 0x00360770u, 3u);
        }

        case 0x00360770u: {
            TP_STATIC_GUARD(0x06C0EEu, 0xA9u, 0x9Cu, 0xFFu);
            const uint16_t value = 0xFF9Cu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0F1u, 0x00360788u, 3u);
        }

        case 0x00360788u: {
            TP_STATIC_GUARD(0x06C0F1u, 0x9Fu, 0x00u, 0x89u, 0x7Eu);
            const uint32_t address = (0x7E8900u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC0F5u, 0x003607A8u, 6u);
        }

        case 0x003607A8u: {
            TP_STATIC_GUARD(0x06C0F5u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x06u, 0xC0F7u, 0x003607B9u, 3u);
        }

        case 0x003607B9u: {
            TP_STATIC_GUARD(0x06C0F7u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x06u, 0xC0F9u, 0x003607C9u, 3u);
        }

        case 0x003607C9u: {
            TP_STATIC_GUARD(0x06C0F9u, 0xFAu);
            uint8_t value = 0u;
            if (tp_scpu_pull8(cpu, bus, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0FAu, 0x003607D1u, 4u);
        }

        case 0x003607D1u: {
            TP_STATIC_GUARD(0x06C0FAu, 0x8Eu, 0x1Bu, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x001Bu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC0FDu, 0x003607E9u, 4u);
        }

        case 0x003607E9u: {
            TP_STATIC_GUARD(0x06C0FDu, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x06u, 0xC0FEu, 0x003607F1u, 5u);
        }

        case 0x003607F1u: {
            TP_STATIC_GUARD(0x06C0FEu, 0x8Du, 0x19u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0019u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xC101u, 0x00360809u, 5u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
