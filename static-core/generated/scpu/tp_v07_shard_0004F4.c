/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0004F4(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x0027A00Bu: {
            TP_STATIC_GUARD(0x04F401u, 0x8Fu, 0xC7u, 0xA6u, 0x7Eu);
            const uint32_t address = 0x7EA6C7u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF405u, 0x0027A02Bu, 5u);
        }

        case 0x0027A02Bu: {
            TP_STATIC_GUARD(0x04F405u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xF407u, 0x0027A03Bu, 3u);
        }

        case 0x0027A03Bu: {
            TP_STATIC_GUARD(0x04F407u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0xF409u, 0x0027A049u, 3u);
        }

        case 0x0027A049u: {
            TP_STATIC_GUARD(0x04F409u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF40Cu, 0x0027A061u, 3u);
        }

        case 0x0027A061u: {
            TP_STATIC_GUARD(0x04F40Cu, 0x8Fu, 0x90u, 0xA5u, 0x7Eu);
            const uint32_t address = 0x7EA590u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF410u, 0x0027A081u, 6u);
        }

        case 0x0027A081u: {
            TP_STATIC_GUARD(0x04F410u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xF412u, 0x0027A093u, 3u);
        }

        case 0x0027A093u: {
            TP_STATIC_GUARD(0x04F412u, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF414u, 0x0027A0A3u, 2u);
        }

        case 0x0027A0A3u: {
            TP_STATIC_GUARD(0x04F414u, 0x8Fu, 0xEAu, 0x9Bu, 0x7Eu);
            const uint32_t address = 0x7E9BEAu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF418u, 0x0027A0C3u, 5u);
        }

        case 0x0027A0C3u: {
            TP_STATIC_GUARD(0x04F418u, 0x8Fu, 0xEBu, 0x9Bu, 0x7Eu);
            const uint32_t address = 0x7E9BEBu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF41Cu, 0x0027A0E3u, 5u);
        }

        case 0x0027A0E3u: {
            TP_STATIC_GUARD(0x04F41Cu, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF41Eu, 0x0027A0F3u, 2u);
        }

        case 0x0027A0F3u: {
            TP_STATIC_GUARD(0x04F41Eu, 0x8Fu, 0x18u, 0x89u, 0x7Eu);
            const uint32_t address = 0x7E8918u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF422u, 0x0027A113u, 5u);
        }

        case 0x0027A113u: {
            TP_STATIC_GUARD(0x04F422u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xF424u, 0x0027A123u, 3u);
        }

        case 0x0027A123u: {
            TP_STATIC_GUARD(0x04F424u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0xF426u, 0x0027A131u, 3u);
        }

        case 0x0027A131u: {
            TP_STATIC_GUARD(0x04F426u, 0xAFu, 0x29u, 0x1Fu, 0x00u);
            const uint32_t address = 0x001F29u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF42Au, 0x0027A151u, 6u);
        }

        case 0x0027A151u: {
            TP_STATIC_GUARD(0x04F42Au, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF42Du, 0x0027A169u, 3u);
        }

        case 0x0027A169u: {
            TP_STATIC_GUARD(0x04F42Du, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF42Eu, 0x0027A171u, 3u);
        }

        case 0x0027A171u: {
            TP_STATIC_GUARD(0x04F42Eu, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF42Fu, 0x0027A179u, 3u);
        }

        case 0x0027A179u: {
            TP_STATIC_GUARD(0x04F42Fu, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF430u, 0x0027A181u, 3u);
        }

        case 0x0027A181u: {
            TP_STATIC_GUARD(0x04F430u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF431u, 0x0027A189u, 3u);
        }

        case 0x0027A189u: {
            TP_STATIC_GUARD(0x04F431u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF432u, 0x0027A191u, 3u);
        }

        case 0x0027A191u: {
            TP_STATIC_GUARD(0x04F432u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF433u, 0x0027A199u, 3u);
        }

        case 0x0027A199u: {
            TP_STATIC_GUARD(0x04F433u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xF434u, 0x0027A1A1u, 2u);
        }

        case 0x0027A1A1u: {
            TP_STATIC_GUARD(0x04F434u, 0x69u, 0xC8u, 0x00u);
            if (tp_scpu_adc(cpu, 0x00C8u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF437u, 0x0027A1B9u, 3u);
        }

        case 0x0027A1B9u: {
            TP_STATIC_GUARD(0x04F437u, 0x8Fu, 0x00u, 0x89u, 0x7Eu);
            const uint32_t address = 0x7E8900u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF43Bu, 0x0027A1D9u, 6u);
        }

        case 0x0027A1D9u: {
            TP_STATIC_GUARD(0x04F43Bu, 0xADu, 0x67u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0767u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF43Eu, 0x0027A1F1u, 5u);
        }

        case 0x0027A1F1u: {
            TP_STATIC_GUARD(0x04F43Eu, 0x29u, 0xFFu, 0x00u);
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF441u, 0x0027A209u, 3u);
        }

        case 0x0027A209u: {
            TP_STATIC_GUARD(0x04F441u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF442u, 0x0027A211u, 3u);
        }

        case 0x0027A211u: {
            TP_STATIC_GUARD(0x04F442u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF443u, 0x0027A219u, 3u);
        }

        case 0x0027A219u: {
            TP_STATIC_GUARD(0x04F443u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF444u, 0x0027A221u, 3u);
        }

        case 0x0027A221u: {
            TP_STATIC_GUARD(0x04F444u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF445u, 0x0027A229u, 3u);
        }

        case 0x0027A229u: {
            TP_STATIC_GUARD(0x04F445u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF446u, 0x0027A231u, 3u);
        }

        case 0x0027A231u: {
            TP_STATIC_GUARD(0x04F446u, 0x0Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF447u, 0x0027A239u, 3u);
        }

        case 0x0027A239u: {
            TP_STATIC_GUARD(0x04F447u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF44Au, 0x0027A251u, 5u);
        }

        case 0x0027A251u: {
            TP_STATIC_GUARD(0x04F44Au, 0xA9u, 0x38u, 0xFFu);
            const uint16_t value = 0xFF38u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF44Du, 0x0027A269u, 3u);
        }

        case 0x0027A269u: {
            TP_STATIC_GUARD(0x04F44Du, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xF44Eu, 0x0027A271u, 2u);
        }

        case 0x0027A271u: {
            TP_STATIC_GUARD(0x04F44Eu, 0x6Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x078Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF451u, 0x0027A289u, 5u);
        }

        case 0x0027A289u: {
            TP_STATIC_GUARD(0x04F451u, 0x8Fu, 0x02u, 0x89u, 0x7Eu);
            const uint32_t address = 0x7E8902u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF455u, 0x0027A2A9u, 6u);
        }

        case 0x0027A2A9u: {
            TP_STATIC_GUARD(0x04F455u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xF457u, 0x0027A2BBu, 3u);
        }

        case 0x0027A2BBu: {
            TP_STATIC_GUARD(0x04F457u, 0xA9u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF459u, 0x0027A2CBu, 2u);
        }

        case 0x0027A2CBu: {
            TP_STATIC_GUARD(0x04F459u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xF45Au, 0x0027A2D3u, 2u);
        }

        case 0x0027A2D3u: {
            TP_STATIC_GUARD(0x04F45Au, 0xEFu, 0x2Au, 0x1Fu, 0x00u);
            const uint32_t address = 0x001F2Au;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF45Eu, 0x0027A2F3u, 5u);
        }

        case 0x0027A2F3u: {
            TP_STATIC_GUARD(0x04F45Eu, 0xA2u, 0x28u);
            const uint8_t value = 0x28u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF460u, 0x0027A303u, 2u);
        }

        case 0x0027A303u: {
            TP_STATIC_GUARD(0x04F460u, 0x8Du, 0x02u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4202u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF463u, 0x0027A31Bu, 4u);
        }

        case 0x0027A31Bu: {
            TP_STATIC_GUARD(0x04F463u, 0x8Eu, 0x03u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4203u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF466u, 0x0027A333u, 4u);
        }

        case 0x0027A333u: {
            TP_STATIC_GUARD(0x04F466u, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0xF467u, 0x0027A33Bu, 2u);
        }

        case 0x0027A33Bu: {
            TP_STATIC_GUARD(0x04F467u, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0xF468u, 0x0027A343u, 2u);
        }

        case 0x0027A343u: {
            TP_STATIC_GUARD(0x04F468u, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0xF469u, 0x0027A34Bu, 2u);
        }

        case 0x0027A34Bu: {
            TP_STATIC_GUARD(0x04F469u, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0xF46Au, 0x0027A353u, 2u);
        }

        case 0x0027A353u: {
            TP_STATIC_GUARD(0x04F46Au, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xF46Cu, 0x0027A360u, 3u);
        }

        case 0x0027A360u: {
            TP_STATIC_GUARD(0x04F46Cu, 0xADu, 0x16u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4216u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF46Fu, 0x0027A378u, 5u);
        }

        case 0x0027A378u: {
            TP_STATIC_GUARD(0x04F46Fu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xF470u, 0x0027A380u, 2u);
        }

        case 0x0027A380u: {
            TP_STATIC_GUARD(0x04F470u, 0x69u, 0x64u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0064u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF473u, 0x0027A398u, 3u);
        }

        case 0x0027A398u: {
            TP_STATIC_GUARD(0x04F473u, 0x8Fu, 0x04u, 0x89u, 0x7Eu);
            const uint32_t address = 0x7E8904u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF477u, 0x0027A3B8u, 6u);
        }

        case 0x0027A3B8u: {
            TP_STATIC_GUARD(0x04F477u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xF479u, 0x0027A3CBu, 3u);
        }

        case 0x0027A3CBu: {
            TP_STATIC_GUARD(0x04F479u, 0xA9u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF47Bu, 0x0027A3DBu, 2u);
        }

        case 0x0027A3DBu: {
            TP_STATIC_GUARD(0x04F47Bu, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xF47Cu, 0x0027A3E3u, 2u);
        }

        case 0x0027A3E3u: {
            TP_STATIC_GUARD(0x04F47Cu, 0xEFu, 0x2Au, 0x1Fu, 0x00u);
            const uint32_t address = 0x001F2Au;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF480u, 0x0027A403u, 5u);
        }

        case 0x0027A403u: {
            TP_STATIC_GUARD(0x04F480u, 0xA2u, 0x0Fu);
            const uint8_t value = 0x0Fu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF482u, 0x0027A413u, 2u);
        }

        case 0x0027A413u: {
            TP_STATIC_GUARD(0x04F482u, 0x8Du, 0x02u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4202u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF485u, 0x0027A42Bu, 4u);
        }

        case 0x0027A42Bu: {
            TP_STATIC_GUARD(0x04F485u, 0x8Eu, 0x03u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4203u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF488u, 0x0027A443u, 4u);
        }

        case 0x0027A443u: {
            TP_STATIC_GUARD(0x04F488u, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0xF489u, 0x0027A44Bu, 2u);
        }

        case 0x0027A44Bu: {
            TP_STATIC_GUARD(0x04F489u, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0xF48Au, 0x0027A453u, 2u);
        }

        case 0x0027A453u: {
            TP_STATIC_GUARD(0x04F48Au, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0xF48Bu, 0x0027A45Bu, 2u);
        }

        case 0x0027A45Bu: {
            TP_STATIC_GUARD(0x04F48Bu, 0xEAu);
            TP_STATIC_EXIT(0x04u, 0xF48Cu, 0x0027A463u, 2u);
        }

        case 0x0027A463u: {
            TP_STATIC_GUARD(0x04F48Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xF48Eu, 0x0027A470u, 3u);
        }

        case 0x0027A470u: {
            TP_STATIC_GUARD(0x04F48Eu, 0xADu, 0x16u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4216u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF491u, 0x0027A488u, 5u);
        }

        case 0x0027A488u: {
            TP_STATIC_GUARD(0x04F491u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xF492u, 0x0027A490u, 2u);
        }

        case 0x0027A490u: {
            TP_STATIC_GUARD(0x04F492u, 0x69u, 0x19u, 0x00u);
            if (tp_scpu_adc(cpu, 0x0019u, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF495u, 0x0027A4A8u, 3u);
        }

        case 0x0027A4A8u: {
            TP_STATIC_GUARD(0x04F495u, 0x8Fu, 0x06u, 0x89u, 0x7Eu);
            const uint32_t address = 0x7E8906u;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF499u, 0x0027A4C8u, 6u);
        }

        case 0x0027A4C8u: {
            TP_STATIC_GUARD(0x04F499u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xF49Bu, 0x0027A4DBu, 3u);
        }

        case 0x0027A4DBu: {
            TP_STATIC_GUARD(0x04F49Bu, 0xA9u, 0x10u);
            const uint8_t value = 0x10u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF49Du, 0x0027A4EBu, 2u);
        }

        case 0x0027A4EBu: {
            TP_STATIC_GUARD(0x04F49Du, 0x8Fu, 0x0Au, 0x89u, 0x7Eu);
            const uint32_t address = 0x7E890Au;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF4A1u, 0x0027A50Bu, 5u);
        }

        case 0x0027A50Bu: {
            TP_STATIC_GUARD(0x04F4A1u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xF4A3u, 0x0027A518u, 3u);
        }

        case 0x0027A518u: {
            TP_STATIC_GUARD(0x04F4A3u, 0xA9u, 0x80u, 0x00u);
            const uint16_t value = 0x0080u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4A6u, 0x0027A530u, 3u);
        }

        case 0x0027A530u: {
            TP_STATIC_GUARD(0x04F4A6u, 0x8Fu, 0x0Bu, 0x89u, 0x7Eu);
            const uint32_t address = 0x7E890Bu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF4AAu, 0x0027A550u, 6u);
        }

        case 0x0027A550u: {
            TP_STATIC_GUARD(0x04F4AAu, 0xA9u, 0x0Au, 0x00u);
            const uint16_t value = 0x000Au;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4ADu, 0x0027A568u, 3u);
        }

        case 0x0027A568u: {
            TP_STATIC_GUARD(0x04F4ADu, 0x8Fu, 0x0Du, 0x89u, 0x7Eu);
            const uint32_t address = 0x7E890Du;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF4B1u, 0x0027A588u, 6u);
        }

        case 0x0027A588u: {
            TP_STATIC_GUARD(0x04F4B1u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xF4B3u, 0x0027A599u, 3u);
        }

        case 0x0027A599u: {
            TP_STATIC_GUARD(0x04F4B3u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x04u, 0xF4B5u, 0x0027A5A9u, 3u);
        }

        case 0x0027A5A9u: {
            TP_STATIC_GUARD(0x04F4B5u, 0xA9u, 0xC7u, 0xA6u);
            const uint16_t value = 0xA6C7u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4B8u, 0x0027A5C1u, 3u);
        }

        case 0x0027A5C1u: {
            TP_STATIC_GUARD(0x04F4B8u, 0x8Du, 0x16u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0016u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF4BBu, 0x0027A5D9u, 5u);
        }

        case 0x0027A5D9u: {
            TP_STATIC_GUARD(0x04F4BBu, 0xA2u, 0x7Eu);
            const uint8_t value = 0x7Eu;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4BDu, 0x0027A5E9u, 2u);
        }

        case 0x0027A5E9u: {
            TP_STATIC_GUARD(0x04F4BDu, 0x8Eu, 0x18u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0018u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF4C0u, 0x0027A601u, 4u);
        }

        case 0x0027A601u: {
            TP_STATIC_GUARD(0x04F4C0u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xF4C2u, 0x0027A613u, 3u);
        }

        case 0x0027A613u: {
            TP_STATIC_GUARD(0x04F4C2u, 0xA0u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4C4u, 0x0027A623u, 2u);
        }

        case 0x0027A623u: {
            TP_STATIC_GUARD(0x04F4C4u, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4C6u, 0x0027A633u, 2u);
        }

        case 0x0027A633u: {
            TP_STATIC_GUARD(0x04F4C6u, 0x97u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x04u;
            cpu->pc = 0xF4C8u;
            if (tp_scpu_expect_next(cpu, 0x0027A643u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0027A643u: {
            TP_STATIC_GUARD(0x04F4C8u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xF4CAu, 0x0027A650u, 3u);
        }

        case 0x0027A650u: {
            TP_STATIC_GUARD(0x04F4CAu, 0xA0u, 0x03u, 0x00u);
            const uint16_t value = 0x0003u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4CDu, 0x0027A668u, 3u);
        }

        case 0x0027A668u: {
            TP_STATIC_GUARD(0x04F4CDu, 0xA9u, 0xA0u, 0x86u);
            const uint16_t value = 0x86A0u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4D0u, 0x0027A680u, 3u);
        }

        case 0x0027A680u: {
            TP_STATIC_GUARD(0x04F4D0u, 0x97u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x04u;
            cpu->pc = 0xF4D2u;
            if (tp_scpu_expect_next(cpu, 0x0027A690u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0027A690u: {
            TP_STATIC_GUARD(0x04F4D2u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xF4D4u, 0x0027A6A3u, 3u);
        }

        case 0x0027A6A3u: {
            TP_STATIC_GUARD(0x04F4D4u, 0xA0u, 0x05u);
            const uint8_t value = 0x05u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4D6u, 0x0027A6B3u, 2u);
        }

        case 0x0027A6B3u: {
            TP_STATIC_GUARD(0x04F4D6u, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4D8u, 0x0027A6C3u, 2u);
        }

        case 0x0027A6C3u: {
            TP_STATIC_GUARD(0x04F4D8u, 0x97u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x04u;
            cpu->pc = 0xF4DAu;
            if (tp_scpu_expect_next(cpu, 0x0027A6D3u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0027A6D3u: {
            TP_STATIC_GUARD(0x04F4DAu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xF4DCu, 0x0027A6E0u, 3u);
        }

        case 0x0027A6E0u: {
            TP_STATIC_GUARD(0x04F4DCu, 0xA0u, 0x07u, 0x00u);
            const uint16_t value = 0x0007u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4DFu, 0x0027A6F8u, 3u);
        }

        case 0x0027A6F8u: {
            TP_STATIC_GUARD(0x04F4DFu, 0xA9u, 0x50u, 0xC3u);
            const uint16_t value = 0xC350u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4E2u, 0x0027A710u, 3u);
        }

        case 0x0027A710u: {
            TP_STATIC_GUARD(0x04F4E2u, 0x97u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x04u;
            cpu->pc = 0xF4E4u;
            if (tp_scpu_expect_next(cpu, 0x0027A720u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0027A720u: {
            TP_STATIC_GUARD(0x04F4E4u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x04u, 0xF4E6u, 0x0027A733u, 3u);
        }

        case 0x0027A733u: {
            TP_STATIC_GUARD(0x04F4E6u, 0xA0u, 0x09u);
            const uint8_t value = 0x09u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4E8u, 0x0027A743u, 2u);
        }

        case 0x0027A743u: {
            TP_STATIC_GUARD(0x04F4E8u, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4EAu, 0x0027A753u, 2u);
        }

        case 0x0027A753u: {
            TP_STATIC_GUARD(0x04F4EAu, 0x97u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x04u;
            cpu->pc = 0xF4ECu;
            if (tp_scpu_expect_next(cpu, 0x0027A763u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0027A763u: {
            TP_STATIC_GUARD(0x04F4ECu, 0xA9u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4EEu, 0x0027A773u, 2u);
        }

        case 0x0027A773u: {
            TP_STATIC_GUARD(0x04F4EEu, 0xA0u, 0x02u);
            const uint8_t value = 0x02u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4F0u, 0x0027A783u, 2u);
        }

        case 0x0027A783u: {
            TP_STATIC_GUARD(0x04F4F0u, 0x97u, 0x16u);
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            const uint16_t pointer = (uint16_t)(cpu->d + 0x16u);
            if (tp_scpu_read8(cpu, bus, (uint32_t)pointer, &pointer_low) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 1u), &pointer_high) != TP_SCPU_EXECUTED ||
                tp_scpu_read8(cpu, bus, (uint32_t)(uint16_t)(pointer + 2u), &pointer_bank) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) |
                ((uint32_t)pointer_high << 8u) | pointer_low) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pbr = 0x04u;
            cpu->pc = 0xF4F2u;
            if (tp_scpu_expect_next(cpu, 0x0027A793u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 6u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0027A793u: {
            TP_STATIC_GUARD(0x04F4F2u, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x04u, 0xF4F4u, 0x0027A7A3u, 2u);
        }

        case 0x0027A7A3u: {
            TP_STATIC_GUARD(0x04F4F4u, 0x8Du, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0415u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF4F7u, 0x0027A7BBu, 4u);
        }

        case 0x0027A7BBu: {
            TP_STATIC_GUARD(0x04F4F7u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x04u, 0xF4F9u, 0x0027A7C8u, 3u);
        }

        case 0x0027A7C8u: {
            TP_STATIC_GUARD(0x04F4F9u, 0xADu, 0x16u, 0x00u);
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
            TP_STATIC_EXIT(0x04u, 0xF4FCu, 0x0027A7E0u, 5u);
        }

        case 0x0027A7E0u: {
            TP_STATIC_GUARD(0x04F4FCu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x04u, 0xF4FDu, 0x0027A7E8u, 2u);
        }

        case 0x0027A7E8u: {
            TP_STATIC_GUARD(0x04F4FDu, 0x69u, 0x3Cu, 0x00u);
            if (tp_scpu_adc(cpu, 0x003Cu, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xF500u, 0x0027A800u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
