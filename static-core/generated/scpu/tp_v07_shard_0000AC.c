/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0000AC(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00056008u: {
            TP_STATIC_GUARD(0x00AC01u, 0x22u, 0x3Cu, 0x99u, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x04u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0x993Cu, 0x0034C9E0u, 8u);
        }

        case 0x00056029u: {
            TP_STATIC_GUARD(0x00AC05u, 0x22u, 0xE7u, 0xFAu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x08u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xFAE7u, 0x0067D739u, 8u);
        }

        case 0x00056049u: {
            TP_STATIC_GUARD(0x00AC09u, 0x4Cu, 0x46u, 0xACu);
            TP_STATIC_EXIT(0x00u, 0xAC46u, 0x00056231u, 3u);
        }

        case 0x00056060u: {
            TP_STATIC_GUARD(0x00AC0Cu, 0xC9u, 0x78u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0078u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC0Fu, 0x00056078u, 3u);
        }

        case 0x00056078u: {
            TP_STATIC_GUARD(0x00AC0Fu, 0xF0u, 0x11u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC22u;
                if (tp_scpu_expect_next(cpu, 0x00056110u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC11u, 0x00056088u, 2u);
        }

        case 0x00056088u: {
            TP_STATIC_GUARD(0x00AC11u, 0xC9u, 0x7Au, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x007Au;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC14u, 0x000560A0u, 3u);
        }

        case 0x000560A0u: {
            TP_STATIC_GUARD(0x00AC14u, 0xF0u, 0x0Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC22u;
                if (tp_scpu_expect_next(cpu, 0x00056110u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC16u, 0x000560B0u, 2u);
        }

        case 0x000560B0u: {
            TP_STATIC_GUARD(0x00AC16u, 0xC9u, 0x87u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0087u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC19u, 0x000560C8u, 3u);
        }

        case 0x000560C8u: {
            TP_STATIC_GUARD(0x00AC19u, 0xF0u, 0x07u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC22u;
                if (tp_scpu_expect_next(cpu, 0x00056110u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC1Bu, 0x000560D8u, 2u);
        }

        case 0x000560D8u: {
            TP_STATIC_GUARD(0x00AC1Bu, 0xC9u, 0x80u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0080u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC1Eu, 0x000560F0u, 3u);
        }

        case 0x000560F0u: {
            TP_STATIC_GUARD(0x00AC1Eu, 0xF0u, 0x02u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC22u;
                if (tp_scpu_expect_next(cpu, 0x00056110u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC20u, 0x00056100u, 2u);
        }

        case 0x00056100u: {
            TP_STATIC_GUARD(0x00AC20u, 0xD0u, 0x15u);
            if (!((cpu->p & TP_P_Z) == 0u))
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "PROVED_BRANCH_STATUS_VIOLATION");
            TP_STATIC_EXIT(0x00u, 0xAC37u, 0x000561B8u, 3u);
        }

        case 0x00056110u: {
            TP_STATIC_GUARD(0x00AC22u, 0x22u, 0x68u, 0xA8u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x25u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xA868u, 0x00254340u, 8u);
        }

        case 0x00056131u: {
            TP_STATIC_GUARD(0x00AC26u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAC28u, 0x00056143u, 3u);
        }

        case 0x00056143u: {
            TP_STATIC_GUARD(0x00AC28u, 0xAEu, 0x0Au, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x080Au;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC2Bu, 0x0005615Bu, 4u);
        }

        case 0x0005615Bu: {
            TP_STATIC_GUARD(0x00AC2Bu, 0xE0u, 0x08u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x08u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC2Du, 0x0005616Bu, 2u);
        }

        case 0x0005616Bu: {
            TP_STATIC_GUARD(0x00AC2Du, 0xD0u, 0x05u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC34u;
                if (tp_scpu_expect_next(cpu, 0x000561A3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC2Fu, 0x0005617Bu, 2u);
        }

        case 0x0005617Bu: {
            TP_STATIC_GUARD(0x00AC2Fu, 0xA2u, 0x00u);
            const uint8_t value = 0x00u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC31u, 0x0005618Bu, 2u);
        }

        case 0x0005618Bu: {
            TP_STATIC_GUARD(0x00AC31u, 0x8Eu, 0x0Au, 0x08u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x080Au;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAC34u, 0x000561A3u, 4u);
        }

        case 0x000561A3u: {
            TP_STATIC_GUARD(0x00AC34u, 0x4Cu, 0x46u, 0xACu);
            TP_STATIC_EXIT(0x00u, 0xAC46u, 0x00056233u, 3u);
        }

        case 0x000561B8u: {
            TP_STATIC_GUARD(0x00AC37u, 0xC9u, 0x9Cu, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x009Cu;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC3Au, 0x000561D0u, 3u);
        }

        case 0x000561D0u: {
            TP_STATIC_GUARD(0x00AC3Au, 0xF0u, 0x02u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC3Eu;
                if (tp_scpu_expect_next(cpu, 0x000561F0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC3Cu, 0x000561E0u, 2u);
        }

        case 0x000561E0u: {
            TP_STATIC_GUARD(0x00AC3Cu, 0xD0u, 0x08u);
            if (!((cpu->p & TP_P_Z) == 0u))
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "PROVED_BRANCH_STATUS_VIOLATION");
            TP_STATIC_EXIT(0x00u, 0xAC46u, 0x00056230u, 3u);
        }

        case 0x000561F0u: {
            TP_STATIC_GUARD(0x00AC3Eu, 0x22u, 0xFEu, 0xB2u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x41u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xB2FEu, 0x002597F0u, 8u);
        }

        case 0x00056211u: {
            TP_STATIC_GUARD(0x00AC42u, 0x22u, 0xE7u, 0xFAu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x45u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xFAE7u, 0x0067D739u, 8u);
        }

        case 0x00056230u: {
            TP_STATIC_GUARD(0x00AC46u, 0x20u, 0x64u, 0xC0u);
            if (tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x48u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC064u, 0x00060320u, 6u);
        }

        case 0x00056231u: {
            TP_STATIC_GUARD(0x00AC46u, 0x20u, 0x64u, 0xC0u);
            if (tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x48u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC064u, 0x00060321u, 6u);
        }

        case 0x00056233u: {
            TP_STATIC_GUARD(0x00AC46u, 0x20u, 0x64u, 0xC0u);
            if (tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x48u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC064u, 0x00060323u, 6u);
        }

        case 0x00056248u: {
            TP_STATIC_GUARD(0x00AC49u, 0x22u, 0xE7u, 0xFAu, 0x0Cu);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x4Cu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x0Cu, 0xFAE7u, 0x0067D738u, 8u);
        }

        case 0x00056268u: {
            TP_STATIC_GUARD(0x00AC4Du, 0x22u, 0x86u, 0xACu, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x50u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAC86u, 0x00056430u, 8u);
        }

        case 0x0005628Bu: {
            TP_STATIC_GUARD(0x00AC51u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAC53u, 0x0005629Bu, 3u);
        }

        case 0x0005629Bu: {
            TP_STATIC_GUARD(0x00AC53u, 0xADu, 0x0Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x070Au;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC56u, 0x000562B3u, 4u);
        }

        case 0x000562B3u: {
            TP_STATIC_GUARD(0x00AC56u, 0xD0u, 0x1Bu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC73u;
                if (tp_scpu_expect_next(cpu, 0x0005639Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC58u, 0x000562C3u, 2u);
        }

        case 0x000562C3u: {
            TP_STATIC_GUARD(0x00AC58u, 0xADu, 0x29u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0729u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC5Bu, 0x000562DBu, 4u);
        }

        case 0x000562DBu: {
            TP_STATIC_GUARD(0x00AC5Bu, 0xF0u, 0x16u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC73u;
                if (tp_scpu_expect_next(cpu, 0x0005639Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC5Du, 0x000562EBu, 2u);
        }

        case 0x000562EBu: {
            TP_STATIC_GUARD(0x00AC5Du, 0x30u, 0x14u);
            if ((cpu->p & TP_P_N) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC73u;
                if (tp_scpu_expect_next(cpu, 0x0005639Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC5Fu, 0x000562FBu, 2u);
        }

        case 0x000562FBu: {
            TP_STATIC_GUARD(0x00AC5Fu, 0xADu, 0xE7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18E7u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC62u, 0x00056313u, 4u);
        }

        case 0x00056313u: {
            TP_STATIC_GUARD(0x00AC62u, 0xD0u, 0x0Cu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC70u;
                if (tp_scpu_expect_next(cpu, 0x00056383u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC64u, 0x00056323u, 2u);
        }

        case 0x00056323u: {
            TP_STATIC_GUARD(0x00AC64u, 0xADu, 0x11u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0711u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC67u, 0x0005633Bu, 4u);
        }

        case 0x0005633Bu: {
            TP_STATIC_GUARD(0x00AC67u, 0xD0u, 0x0Au);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC73u;
                if (tp_scpu_expect_next(cpu, 0x0005639Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC69u, 0x0005634Bu, 2u);
        }

        case 0x0005634Bu: {
            TP_STATIC_GUARD(0x00AC69u, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC6Bu, 0x0005635Bu, 2u);
        }

        case 0x0005635Bu: {
            TP_STATIC_GUARD(0x00AC6Bu, 0x8Du, 0x0Fu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x070Fu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAC6Eu, 0x00056373u, 4u);
        }

        case 0x00056373u: {
            TP_STATIC_GUARD(0x00AC6Eu, 0x80u, 0x03u);
            TP_STATIC_EXIT(0x00u, 0xAC73u, 0x0005639Bu, 3u);
        }

        case 0x00056383u: {
            TP_STATIC_GUARD(0x00AC70u, 0xCEu, 0xE7u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18E7u;
            uint8_t old_value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &old_value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            const uint8_t value = (uint8_t)(old_value - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            if (tp_scpu_write8(cpu, bus, address, value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAC73u, 0x0005639Bu, 6u);
        }

        case 0x0005639Bu: {
            TP_STATIC_GUARD(0x00AC73u, 0x4Cu, 0xDFu, 0xA8u);
            TP_STATIC_EXIT(0x00u, 0xA8DFu, 0x000546FBu, 3u);
        }

        case 0x000563B8u: {
            TP_STATIC_GUARD(0x00AC77u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xAC79u, 0x000563C8u, 3u);
        }

        case 0x000563C8u: {
            TP_STATIC_GUARD(0x00AC79u, 0x22u, 0xEAu, 0xBCu, 0x06u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x7Cu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x06u, 0xBCEAu, 0x0035E750u, 8u);
        }

        case 0x000563E8u: {
            TP_STATIC_GUARD(0x00AC7Du, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAC7Fu, 0x000563FAu, 3u);
        }

        case 0x000563FAu: {
            TP_STATIC_GUARD(0x00AC7Fu, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x00u, 0xAC81u, 0x0005640Au, 3u);
        }

        case 0x0005640Au: {
            TP_STATIC_GUARD(0x00AC81u, 0x60u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            switch (tp_scpu_context_key(cpu)) {
                case 0x0005463Au:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            }
        }

        case 0x00056410u: {
            TP_STATIC_GUARD(0x00AC82u, 0x20u, 0xFAu, 0x89u);
            if (tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x84u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x89FAu, 0x00044FD0u, 6u);
        }

        case 0x00056412u: {
            TP_STATIC_GUARD(0x00AC82u, 0x20u, 0xFAu, 0x89u);
            if (tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x84u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x89FAu, 0x00044FD2u, 6u);
        }

        case 0x00056413u: {
            TP_STATIC_GUARD(0x00AC82u, 0x20u, 0xFAu, 0x89u);
            if (tp_scpu_push8(cpu, bus, 0xACu) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x84u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x89FAu, 0x00044FD3u, 6u);
        }

        case 0x00056429u: {
            TP_STATIC_GUARD(0x00AC85u, 0x6Bu);
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
                case 0x000553A1u:
                case 0x00055A31u:
                case 0x003CB691u:
                case 0x00659A91u:
                case 0x0067B2F1u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x00056430u: {
            TP_STATIC_GUARD(0x00AC86u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAC88u, 0x00056443u, 3u);
        }

        case 0x00056433u: {
            TP_STATIC_GUARD(0x00AC86u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAC88u, 0x00056443u, 3u);
        }

        case 0x00056443u: {
            TP_STATIC_GUARD(0x00AC88u, 0xADu, 0xA9u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07A9u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC8Bu, 0x0005645Bu, 4u);
        }

        case 0x0005645Bu: {
            TP_STATIC_GUARD(0x00AC8Bu, 0xF0u, 0x08u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xAC95u;
                if (tp_scpu_expect_next(cpu, 0x000564ABu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC8Du, 0x0005646Bu, 2u);
        }

        case 0x0005646Bu: {
            TP_STATIC_GUARD(0x00AC8Du, 0x9Cu, 0xA9u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07A9u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAC90u, 0x00056483u, 4u);
        }

        case 0x00056483u: {
            TP_STATIC_GUARD(0x00AC90u, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC92u, 0x00056493u, 2u);
        }

        case 0x00056493u: {
            TP_STATIC_GUARD(0x00AC92u, 0x8Du, 0x48u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0748u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAC95u, 0x000564ABu, 4u);
        }

        case 0x000564ABu: {
            TP_STATIC_GUARD(0x00AC95u, 0xADu, 0xAAu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07AAu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAC98u, 0x000564C3u, 4u);
        }

        case 0x000564C3u: {
            TP_STATIC_GUARD(0x00AC98u, 0xF0u, 0x0Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xACA6u;
                if (tp_scpu_expect_next(cpu, 0x00056533u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xAC9Au, 0x000564D3u, 2u);
        }

        case 0x000564D3u: {
            TP_STATIC_GUARD(0x00AC9Au, 0x9Cu, 0xAAu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07AAu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xAC9Du, 0x000564EBu, 4u);
        }

        case 0x000564EBu: {
            TP_STATIC_GUARD(0x00AC9Du, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xAC9Fu, 0x000564FBu, 3u);
        }

        case 0x000564FBu: {
            TP_STATIC_GUARD(0x00AC9Fu, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xACA1u, 0x0005650Bu, 2u);
        }

        case 0x0005650Bu: {
            TP_STATIC_GUARD(0x00ACA1u, 0x8Du, 0x4Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x074Au) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xACA4u, 0x00056523u, 4u);
        }

        case 0x00056523u: {
            TP_STATIC_GUARD(0x00ACA4u, 0x80u, 0x0Cu);
            TP_STATIC_EXIT(0x00u, 0xACB2u, 0x00056593u, 3u);
        }

        case 0x00056533u: {
            TP_STATIC_GUARD(0x00ACA6u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xACA8u, 0x00056543u, 3u);
        }

        case 0x00056543u: {
            TP_STATIC_GUARD(0x00ACA8u, 0xADu, 0x4Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x074Cu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xACABu, 0x0005655Bu, 4u);
        }

        case 0x0005655Bu: {
            TP_STATIC_GUARD(0x00ACABu, 0xF0u, 0x05u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xACB2u;
                if (tp_scpu_expect_next(cpu, 0x00056593u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xACADu, 0x0005656Bu, 2u);
        }

        case 0x0005656Bu: {
            TP_STATIC_GUARD(0x00ACADu, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xACAFu, 0x0005657Bu, 2u);
        }

        case 0x0005657Bu: {
            TP_STATIC_GUARD(0x00ACAFu, 0x8Du, 0x4Bu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x074Bu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xACB2u, 0x00056593u, 4u);
        }

        case 0x00056593u: {
            TP_STATIC_GUARD(0x00ACB2u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xACB4u, 0x000565A3u, 3u);
        }

        case 0x000565A3u: {
            TP_STATIC_GUARD(0x00ACB4u, 0xADu, 0xABu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07ABu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xACB7u, 0x000565BBu, 4u);
        }

        case 0x000565BBu: {
            TP_STATIC_GUARD(0x00ACB7u, 0xF0u, 0x43u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xACFCu;
                if (tp_scpu_expect_next(cpu, 0x000567E3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xACB9u, 0x000565CBu, 2u);
        }

        case 0x000565CBu: {
            TP_STATIC_GUARD(0x00ACB9u, 0xAEu, 0xFBu, 0x16u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x16FBu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xACBCu, 0x000565E3u, 4u);
        }

        case 0x000565E3u: {
            TP_STATIC_GUARD(0x00ACBCu, 0xF0u, 0x3Bu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xACF9u;
                if (tp_scpu_expect_next(cpu, 0x000567CBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xACBEu, 0x000565F3u, 2u);
        }

        case 0x000565F3u: {
            TP_STATIC_GUARD(0x00ACBEu, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xACC0u, 0x00056603u, 2u);
        }

        case 0x00056603u: {
            TP_STATIC_GUARD(0x00ACC0u, 0x8Du, 0xAFu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07AFu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xACC3u, 0x0005661Bu, 4u);
        }

        case 0x0005661Bu: {
            TP_STATIC_GUARD(0x00ACC3u, 0xADu, 0xFBu, 0x16u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x16FBu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xACC6u, 0x00056633u, 4u);
        }

        case 0x00056633u: {
            TP_STATIC_GUARD(0x00ACC6u, 0xF0u, 0x31u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xACF9u;
                if (tp_scpu_expect_next(cpu, 0x000567CBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xACC8u, 0x00056643u, 2u);
        }

        case 0x00056643u: {
            TP_STATIC_GUARD(0x00ACC8u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x00u, 0xACC9u, 0x0005664Bu, 2u);
        }

        case 0x0005664Bu: {
            TP_STATIC_GUARD(0x00ACC9u, 0xE9u, 0x04u);
            if (tp_scpu_sbc(cpu, 0x04u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xACCBu, 0x0005665Bu, 2u);
        }

        case 0x0005665Bu: {
            TP_STATIC_GUARD(0x00ACCBu, 0x8Du, 0xFBu, 0x16u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x16FBu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xACCEu, 0x00056673u, 4u);
        }

        case 0x00056673u: {
            TP_STATIC_GUARD(0x00ACCEu, 0xAAu);
            cpu->x = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->x) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xACCFu, 0x0005667Bu, 2u);
        }

        case 0x0005667Bu: {
            TP_STATIC_GUARD(0x00ACCFu, 0xACu, 0xAEu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07AEu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xACD2u, 0x00056693u, 4u);
        }

        case 0x00056693u: {
            TP_STATIC_GUARD(0x00ACD2u, 0xBDu, 0x5Bu, 0x16u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x165Bu + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x00u;
            cpu->pc = 0xACD5u;
            if (tp_scpu_expect_next(cpu, 0x000566ABu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + (((0x5Bu + (cpu->x & 0x00FFu)) > 0x00FFu) ? 1u : 0u));
        }

        case 0x000566ABu: {
            TP_STATIC_GUARD(0x00ACD5u, 0x99u, 0x3Fu, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x143Fu + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xACD8u, 0x000566C3u, 5u);
        }

        case 0x000566C3u: {
            TP_STATIC_GUARD(0x00ACD8u, 0xBDu, 0x5Cu, 0x16u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x165Cu + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x00u;
            cpu->pc = 0xACDBu;
            if (tp_scpu_expect_next(cpu, 0x000566DBu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + (((0x5Cu + (cpu->x & 0x00FFu)) > 0x00FFu) ? 1u : 0u));
        }

        case 0x000566DBu: {
            TP_STATIC_GUARD(0x00ACDBu, 0x99u, 0x40u, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1440u + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xACDEu, 0x000566F3u, 5u);
        }

        case 0x000566F3u: {
            TP_STATIC_GUARD(0x00ACDEu, 0xBDu, 0x5Du, 0x16u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x165Du + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x00u;
            cpu->pc = 0xACE1u;
            if (tp_scpu_expect_next(cpu, 0x0005670Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + (((0x5Du + (cpu->x & 0x00FFu)) > 0x00FFu) ? 1u : 0u));
        }

        case 0x0005670Bu: {
            TP_STATIC_GUARD(0x00ACE1u, 0x99u, 0x41u, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1441u + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xACE4u, 0x00056723u, 5u);
        }

        case 0x00056723u: {
            TP_STATIC_GUARD(0x00ACE4u, 0xBDu, 0x5Eu, 0x16u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x165Eu + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            cpu->pbr = 0x00u;
            cpu->pc = 0xACE7u;
            if (tp_scpu_expect_next(cpu, 0x0005673Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            return tp_scpu_finish(cpu, bus, 4u + (((0x5Eu + (cpu->x & 0x00FFu)) > 0x00FFu) ? 1u : 0u));
        }

        case 0x0005673Bu: {
            TP_STATIC_GUARD(0x00ACE7u, 0x99u, 0x42u, 0x14u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1442u + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xACEAu, 0x00056753u, 5u);
        }

        case 0x00056753u: {
            TP_STATIC_GUARD(0x00ACEAu, 0xADu, 0xAEu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07AEu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xACEDu, 0x0005676Bu, 4u);
        }

        case 0x0005676Bu: {
            TP_STATIC_GUARD(0x00ACEDu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x00u, 0xACEEu, 0x00056773u, 2u);
        }

        case 0x00056773u: {
            TP_STATIC_GUARD(0x00ACEEu, 0x69u, 0x04u);
            if (tp_scpu_adc(cpu, 0x04u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xACF0u, 0x00056783u, 2u);
        }

        case 0x00056783u: {
            TP_STATIC_GUARD(0x00ACF0u, 0xC9u, 0x30u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x30u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xACF2u, 0x00056793u, 2u);
        }

        case 0x00056793u: {
            TP_STATIC_GUARD(0x00ACF2u, 0xB0u, 0xCFu);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xACC3u;
                if (tp_scpu_expect_next(cpu, 0x0005661Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xACF4u, 0x000567A3u, 2u);
        }

        case 0x000567A3u: {
            TP_STATIC_GUARD(0x00ACF4u, 0x8Du, 0xAEu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07AEu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xACF7u, 0x000567BBu, 4u);
        }

        case 0x000567BBu: {
            TP_STATIC_GUARD(0x00ACF7u, 0x80u, 0xCAu);
            TP_STATIC_EXIT(0x00u, 0xACC3u, 0x0005661Bu, 3u);
        }

        case 0x000567CBu: {
            TP_STATIC_GUARD(0x00ACF9u, 0x9Cu, 0xAFu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07AFu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xACFCu, 0x000567E3u, 4u);
        }

        case 0x000567E3u: {
            TP_STATIC_GUARD(0x00ACFCu, 0x9Cu, 0xABu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07ABu) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xACFFu, 0x000567FBu, 4u);
        }

        case 0x000567FBu: {
            TP_STATIC_GUARD(0x00ACFFu, 0xA9u, 0x01u);
            const uint8_t value = 0x01u;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xAD01u, 0x0005680Bu, 2u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
