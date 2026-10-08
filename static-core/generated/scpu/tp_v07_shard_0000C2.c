/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_0000C2(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x00061003u: {
            TP_STATIC_GUARD(0x00C200u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC202u, 0x00061010u, 3u);
        }

        case 0x00061010u: {
            TP_STATIC_GUARD(0x00C202u, 0xADu, 0xD8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07D8u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC205u, 0x00061028u, 5u);
        }

        case 0x00061028u: {
            TP_STATIC_GUARD(0x00C205u, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC208u, 0x00061040u, 5u);
        }

        case 0x00061040u: {
            TP_STATIC_GUARD(0x00C208u, 0xADu, 0xDAu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07DAu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC20Bu, 0x00061058u, 5u);
        }

        case 0x00061058u: {
            TP_STATIC_GUARD(0x00C20Bu, 0x8Du, 0x8Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC20Eu, 0x00061070u, 5u);
        }

        case 0x00061070u: {
            TP_STATIC_GUARD(0x00C20Eu, 0x22u, 0xCDu, 0xCEu, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC2u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x11u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0xCECDu, 0x00267668u, 8u);
        }

        case 0x00061091u: {
            TP_STATIC_GUARD(0x00C212u, 0x80u, 0x18u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061161u, 3u);
        }

        case 0x000610A3u: {
            TP_STATIC_GUARD(0x00C214u, 0xC9u, 0x24u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x24u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC216u, 0x000610B3u, 2u);
        }

        case 0x000610B3u: {
            TP_STATIC_GUARD(0x00C216u, 0xD0u, 0x0Eu);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC226u;
                if (tp_scpu_expect_next(cpu, 0x00061133u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC218u, 0x000610C3u, 2u);
        }

        case 0x000610C3u: {
            TP_STATIC_GUARD(0x00C218u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC21Au, 0x000610D0u, 3u);
        }

        case 0x000610D0u: {
            TP_STATIC_GUARD(0x00C21Au, 0xADu, 0xD8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07D8u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC21Du, 0x000610E8u, 5u);
        }

        case 0x000610E8u: {
            TP_STATIC_GUARD(0x00C21Du, 0x8Du, 0x8Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x078Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC220u, 0x00061100u, 5u);
        }

        case 0x00061100u: {
            TP_STATIC_GUARD(0x00C220u, 0x22u, 0x32u, 0x87u, 0x00u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC2u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x23u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0x8732u, 0x00043990u, 8u);
        }

        case 0x00061121u: {
            TP_STATIC_GUARD(0x00C224u, 0x80u, 0x06u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061161u, 3u);
        }

        case 0x00061133u: {
            TP_STATIC_GUARD(0x00C226u, 0xC9u, 0x26u);
            const uint8_t left = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t right = 0x26u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC228u, 0x00061143u, 2u);
        }

        case 0x00061143u: {
            TP_STATIC_GUARD(0x00C228u, 0xD0u, 0x02u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC22Cu;
                if (tp_scpu_expect_next(cpu, 0x00061163u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC22Au, 0x00061153u, 2u);
        }

        case 0x00061153u: {
            TP_STATIC_GUARD(0x00C22Au, 0x80u, 0x00u);
            TP_STATIC_EXIT(0x00u, 0xC22Cu, 0x00061163u, 3u);
        }

        case 0x00061160u: {
            TP_STATIC_GUARD(0x00C22Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC22Eu, 0x00061170u, 3u);
        }

        case 0x00061161u: {
            TP_STATIC_GUARD(0x00C22Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC22Eu, 0x00061170u, 3u);
        }

        case 0x00061163u: {
            TP_STATIC_GUARD(0x00C22Cu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC22Eu, 0x00061170u, 3u);
        }

        case 0x00061170u: {
            TP_STATIC_GUARD(0x00C22Eu, 0xACu, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0415u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC231u, 0x00061188u, 5u);
        }

        case 0x00061188u: {
            TP_STATIC_GUARD(0x00C231u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC232u, 0x00061190u, 2u);
        }

        case 0x00061190u: {
            TP_STATIC_GUARD(0x00C232u, 0xA9u, 0x0Eu, 0x00u);
            const uint16_t value = 0x000Eu;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC235u, 0x000611A8u, 3u);
        }

        case 0x000611A8u: {
            TP_STATIC_GUARD(0x00C235u, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC2u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x38u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x000611C8u: {
            TP_STATIC_GUARD(0x00C239u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC23Au, 0x000611D0u, 2u);
        }

        case 0x000611D0u: {
            TP_STATIC_GUARD(0x00C23Au, 0xE2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xC23Cu, 0x000611E2u, 3u);
        }

        case 0x000611E2u: {
            TP_STATIC_GUARD(0x00C23Cu, 0xC2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            TP_STATIC_EXIT(0x00u, 0xC23Eu, 0x000611F2u, 3u);
        }

        case 0x000611F2u: {
            TP_STATIC_GUARD(0x00C23Eu, 0xBBu);
            cpu->x = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC23Fu, 0x000611FAu, 2u);
        }

        case 0x000611FAu: {
            TP_STATIC_GUARD(0x00C23Fu, 0x9Eu, 0xD7u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07D7u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC242u, 0x00061212u, 5u);
        }

        case 0x00061212u: {
            TP_STATIC_GUARD(0x00C242u, 0x9Eu, 0xD8u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x07D8u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, 0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC245u, 0x0006122Au, 5u);
        }

        case 0x0006122Au: {
            TP_STATIC_GUARD(0x00C245u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC247u, 0x00061238u, 3u);
        }

        case 0x00061238u: {
            TP_STATIC_GUARD(0x00C247u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC248u, 0x00061240u, 5u);
        }

        case 0x00061240u: {
            TP_STATIC_GUARD(0x00C248u, 0x8Du, 0x80u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0780u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC24Bu, 0x00061258u, 5u);
        }

        case 0x00061258u: {
            TP_STATIC_GUARD(0x00C24Bu, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC24Cu, 0x00061260u, 5u);
        }

        case 0x00061260u: {
            TP_STATIC_GUARD(0x00C24Cu, 0x8Du, 0x7Eu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x077Eu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC24Fu, 0x00061278u, 5u);
        }

        case 0x00061278u: {
            TP_STATIC_GUARD(0x00C24Fu, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC250u, 0x00061280u, 5u);
        }

        case 0x00061280u: {
            TP_STATIC_GUARD(0x00C250u, 0x8Du, 0x7Cu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x077Cu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC253u, 0x00061298u, 5u);
        }

        case 0x00061298u: {
            TP_STATIC_GUARD(0x00C253u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC254u, 0x000612A0u, 5u);
        }

        case 0x000612A0u: {
            TP_STATIC_GUARD(0x00C254u, 0x8Du, 0x7Au, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x077Au) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC257u, 0x000612B8u, 5u);
        }

        case 0x000612B8u: {
            TP_STATIC_GUARD(0x00C257u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC258u, 0x000612C0u, 5u);
        }

        case 0x000612C0u: {
            TP_STATIC_GUARD(0x00C258u, 0x8Du, 0x15u, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0415u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC25Bu, 0x000612D8u, 5u);
        }

        case 0x000612D8u: {
            TP_STATIC_GUARD(0x00C25Bu, 0x60u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            switch (tp_scpu_context_key(cpu)) {
                case 0x00056248u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            }
        }

        case 0x000612E3u: {
            TP_STATIC_GUARD(0x00C25Cu, 0xA2u, 0x18u);
            const uint8_t value = 0x18u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC25Eu, 0x000612F3u, 2u);
        }

        case 0x000612F3u: {
            TP_STATIC_GUARD(0x00C25Eu, 0x8Du, 0x02u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4202u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC261u, 0x0006130Bu, 4u);
        }

        case 0x0006130Bu: {
            TP_STATIC_GUARD(0x00C261u, 0x8Eu, 0x03u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4203u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC264u, 0x00061323u, 4u);
        }

        case 0x00061323u: {
            TP_STATIC_GUARD(0x00C264u, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC265u, 0x0006132Bu, 2u);
        }

        case 0x0006132Bu: {
            TP_STATIC_GUARD(0x00C265u, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC266u, 0x00061333u, 2u);
        }

        case 0x00061333u: {
            TP_STATIC_GUARD(0x00C266u, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC267u, 0x0006133Bu, 2u);
        }

        case 0x0006133Bu: {
            TP_STATIC_GUARD(0x00C267u, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC268u, 0x00061343u, 2u);
        }

        case 0x00061343u: {
            TP_STATIC_GUARD(0x00C268u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC26Au, 0x00061350u, 3u);
        }

        case 0x00061350u: {
            TP_STATIC_GUARD(0x00C26Au, 0xADu, 0x16u, 0x42u);
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
            TP_STATIC_EXIT(0x00u, 0xC26Du, 0x00061368u, 5u);
        }

        case 0x00061368u: {
            TP_STATIC_GUARD(0x00C26Du, 0xEBu);
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(cpu->a & 0x00FFu) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(cpu->a & 0x00FFu) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC26Eu, 0x00061370u, 3u);
        }

        case 0x00061370u: {
            TP_STATIC_GUARD(0x00C26Eu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xC270u, 0x00061383u, 3u);
        }

        case 0x00061383u: {
            TP_STATIC_GUARD(0x00C270u, 0x8Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0064u) & 0xFFFFFFu;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->a & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC273u, 0x0006139Bu, 4u);
        }

        case 0x0006139Bu: {
            TP_STATIC_GUARD(0x00C273u, 0x98u);
            const uint8_t value = (uint8_t)(cpu->y & 0x00FFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC274u, 0x000613A3u, 2u);
        }

        case 0x000613A3u: {
            TP_STATIC_GUARD(0x00C274u, 0x4Au);
            const uint8_t old_value = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t value = (uint8_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC275u, 0x000613ABu, 2u);
        }

        case 0x000613ABu: {
            TP_STATIC_GUARD(0x00C275u, 0x4Au);
            const uint8_t old_value = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t value = (uint8_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC276u, 0x000613B3u, 2u);
        }

        case 0x000613B3u: {
            TP_STATIC_GUARD(0x00C276u, 0x4Au);
            const uint8_t old_value = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t value = (uint8_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC277u, 0x000613BBu, 2u);
        }

        case 0x000613BBu: {
            TP_STATIC_GUARD(0x00C277u, 0x4Au);
            const uint8_t old_value = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t value = (uint8_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC278u, 0x000613C3u, 2u);
        }

        case 0x000613C3u: {
            TP_STATIC_GUARD(0x00C278u, 0x4Au);
            const uint8_t old_value = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t value = (uint8_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC279u, 0x000613CBu, 2u);
        }

        case 0x000613CBu: {
            TP_STATIC_GUARD(0x00C279u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x00u, 0xC27Au, 0x000613D3u, 2u);
        }

        case 0x000613D3u: {
            TP_STATIC_GUARD(0x00C27Au, 0x6Du, 0x64u, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0064u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC27Du, 0x000613EBu, 4u);
        }

        case 0x000613EBu: {
            TP_STATIC_GUARD(0x00C27Du, 0x69u, 0x03u);
            if (tp_scpu_adc(cpu, 0x03u, 8u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC27Fu, 0x000613FBu, 2u);
        }

        case 0x000613FBu: {
            TP_STATIC_GUARD(0x00C27Fu, 0x60u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            switch (tp_scpu_context_key(cpu)) {
                case 0x00050BF3u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            }
        }

        case 0x00061403u: {
            TP_STATIC_GUARD(0x00C280u, 0x4Au);
            const uint8_t old_value = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t value = (uint8_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC281u, 0x0006140Bu, 2u);
        }

        case 0x0006140Bu: {
            TP_STATIC_GUARD(0x00C281u, 0x4Au);
            const uint8_t old_value = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t value = (uint8_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC282u, 0x00061413u, 2u);
        }

        case 0x00061413u: {
            TP_STATIC_GUARD(0x00C282u, 0x4Au);
            const uint8_t old_value = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t value = (uint8_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC283u, 0x0006141Bu, 2u);
        }

        case 0x0006141Bu: {
            TP_STATIC_GUARD(0x00C283u, 0x4Au);
            const uint8_t old_value = (uint8_t)(cpu->a & 0x00FFu);
            const uint8_t value = (uint8_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC284u, 0x00061423u, 2u);
        }

        case 0x00061423u: {
            TP_STATIC_GUARD(0x00C284u, 0x60u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            switch (tp_scpu_context_key(cpu)) {
                case 0x00050C5Bu:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            }
        }

        case 0x00061428u: {
            TP_STATIC_GUARD(0x00C285u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC287u, 0x00061438u, 3u);
        }

        case 0x00061438u: {
            TP_STATIC_GUARD(0x00C287u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC288u, 0x00061440u, 2u);
        }

        case 0x00061440u: {
            TP_STATIC_GUARD(0x00C288u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC289u, 0x00061448u, 2u);
        }

        case 0x00061448u: {
            TP_STATIC_GUARD(0x00C289u, 0xA9u, 0x93u, 0x00u);
            const uint16_t value = 0x0093u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC28Cu, 0x00061460u, 3u);
        }

        case 0x00061460u: {
            TP_STATIC_GUARD(0x00C28Cu, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC2u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Fu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x00061480u: {
            TP_STATIC_GUARD(0x00C290u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC291u, 0x00061488u, 2u);
        }

        case 0x00061488u: {
            TP_STATIC_GUARD(0x00C291u, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x00u, 0xC292u, 0x00061490u, 2u);
        }

        case 0x00061490u: {
            TP_STATIC_GUARD(0x00C292u, 0x6Du, 0x3Au, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x003Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC295u, 0x000614A8u, 5u);
        }

        case 0x000614A8u: {
            TP_STATIC_GUARD(0x00C295u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xC297u, 0x000614B9u, 3u);
        }

        case 0x000614B9u: {
            TP_STATIC_GUARD(0x00C297u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xC299u, 0x000614C9u, 3u);
        }

        case 0x000614C9u: {
            TP_STATIC_GUARD(0x00C299u, 0xAEu, 0x3Cu, 0x00u);
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
            TP_STATIC_EXIT(0x00u, 0xC29Cu, 0x000614E1u, 4u);
        }

        case 0x000614E1u: {
            TP_STATIC_GUARD(0x00C29Cu, 0x60u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            switch (tp_scpu_context_key(cpu)) {
                case 0x00043C61u:
                case 0x0004C7B1u:
                case 0x00054331u:
                case 0x000544D1u:
                case 0x0006A0D9u:
                case 0x0006A399u:
                case 0x0006A4F9u:
                case 0x0006B609u:
                case 0x0006B729u:
                case 0x00071A79u:
                case 0x00072961u:
                case 0x00072D19u:
                case 0x00073D99u:
                case 0x00073F69u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            }
        }

        case 0x000614E8u: {
            TP_STATIC_GUARD(0x00C29Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC29Fu, 0x000614F8u, 3u);
        }

        case 0x000614E9u: {
            TP_STATIC_GUARD(0x00C29Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC29Fu, 0x000614F8u, 3u);
        }

        case 0x000614EBu: {
            TP_STATIC_GUARD(0x00C29Du, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC29Fu, 0x000614F8u, 3u);
        }

        case 0x000614F8u: {
            TP_STATIC_GUARD(0x00C29Fu, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2A0u, 0x00061500u, 2u);
        }

        case 0x00061500u: {
            TP_STATIC_GUARD(0x00C2A0u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2A1u, 0x00061508u, 2u);
        }

        case 0x00061508u: {
            TP_STATIC_GUARD(0x00C2A1u, 0xA9u, 0x93u, 0x00u);
            const uint16_t value = 0x0093u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2A4u, 0x00061520u, 3u);
        }

        case 0x00061520u: {
            TP_STATIC_GUARD(0x00C2A4u, 0x22u, 0xA7u, 0x80u, 0x04u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xC2u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xA7u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x04u, 0x80A7u, 0x00240538u, 8u);
        }

        case 0x00061540u: {
            TP_STATIC_GUARD(0x00C2A8u, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2A9u, 0x00061548u, 2u);
        }

        case 0x00061548u: {
            TP_STATIC_GUARD(0x00C2A9u, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2AAu, 0x00061550u, 2u);
        }

        case 0x00061550u: {
            TP_STATIC_GUARD(0x00C2AAu, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x00u, 0xC2ABu, 0x00061558u, 2u);
        }

        case 0x00061558u: {
            TP_STATIC_GUARD(0x00C2ABu, 0x6Du, 0x3Au, 0x00u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x003Au;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC2AEu, 0x00061570u, 5u);
        }

        case 0x00061570u: {
            TP_STATIC_GUARD(0x00C2AEu, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xC2B0u, 0x00061581u, 3u);
        }

        case 0x00061581u: {
            TP_STATIC_GUARD(0x00C2B0u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xC2B2u, 0x00061591u, 3u);
        }

        case 0x00061591u: {
            TP_STATIC_GUARD(0x00C2B2u, 0xAEu, 0x3Cu, 0x00u);
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
            TP_STATIC_EXIT(0x00u, 0xC2B5u, 0x000615A9u, 4u);
        }

        case 0x000615A9u: {
            TP_STATIC_GUARD(0x00C2B5u, 0x6Bu);
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
                case 0x00044169u:
                case 0x00044369u:
                case 0x00044769u:
                case 0x000578B9u:
                case 0x00057D51u:
                case 0x000580E1u:
                case 0x00058689u:
                case 0x00247F29u:
                case 0x00249529u:
                case 0x0024A2E9u:
                case 0x0024B939u:
                case 0x0024CAC9u:
                case 0x0024CF11u:
                case 0x0024E321u:
                case 0x0024E5E1u:
                case 0x0024EC19u:
                case 0x00254661u:
                case 0x00272DD1u:
                case 0x002732D1u:
                case 0x00273681u:
                case 0x00273C91u:
                case 0x002743C9u:
                case 0x00274861u:
                case 0x002761B1u:
                case 0x002763E1u:
                case 0x00276489u:
                case 0x00277751u:
                case 0x00277AB9u:
                case 0x00279B19u:
                case 0x002FF1C9u:
                case 0x00340321u:
                case 0x00344521u:
                case 0x00344781u:
                case 0x00344991u:
                case 0x00356731u:
                case 0x003569D1u:
                case 0x00356C51u:
                case 0x003570F9u:
                case 0x00357301u:
                case 0x00357579u:
                case 0x00358B69u:
                case 0x00358DE1u:
                case 0x003590B1u:
                case 0x00359329u:
                case 0x003595F9u:
                case 0x00359889u:
                case 0x0035B3C1u:
                case 0x0035BC09u:
                case 0x0035BE31u:
                case 0x0035C329u:
                case 0x00368149u:
                case 0x003687B9u:
                case 0x00369361u:
                case 0x00374069u:
                case 0x003C2E89u:
                case 0x003C3631u:
                case 0x003C3769u:
                case 0x003C38E1u:
                case 0x003C39C9u:
                case 0x003C5289u:
                case 0x003C5389u:
                case 0x003C9BD9u:
                case 0x003CABC1u:
                case 0x003D1C09u:
                case 0x003D2571u:
                case 0x003E6AC1u:
                case 0x003E7121u:
                case 0x003E8AB1u:
                case 0x003E95F1u:
                case 0x003F0159u:
                case 0x003F0E79u:
                case 0x003F10B9u:
                case 0x003F34C9u:
                case 0x003F4591u:
                case 0x003FDF51u:
                case 0x003FE289u:
                case 0x003FED29u:
                case 0x00649DF1u:
                case 0x00649F21u:
                case 0x00654DE1u:
                case 0x00654EE9u:
                case 0x00655811u:
                case 0x00655919u:
                case 0x00658D79u:
                case 0x00659D89u:
                case 0x0065C399u:
                case 0x0065C6A9u:
                case 0x00661391u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x000615B0u: {
            TP_STATIC_GUARD(0x00C2B6u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xC2B8u, 0x000615C1u, 3u);
        }

        case 0x000615C1u: {
            TP_STATIC_GUARD(0x00C2B8u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xC2BAu, 0x000615D1u, 3u);
        }

        case 0x000615D1u: {
            TP_STATIC_GUARD(0x00C2BAu, 0xA2u, 0x93u);
            const uint8_t value = 0x93u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2BCu, 0x000615E1u, 2u);
        }

        case 0x000615E1u: {
            TP_STATIC_GUARD(0x00C2BCu, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2BFu, 0x000615F9u, 3u);
        }

        case 0x000615F9u: {
            TP_STATIC_GUARD(0x00C2BFu, 0xF0u, 0x1Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC2DDu;
                if (tp_scpu_expect_next(cpu, 0x000616E9u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC2C1u, 0x00061609u, 2u);
        }

        case 0x00061609u: {
            TP_STATIC_GUARD(0x00C2C1u, 0xE0u, 0x00u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x00u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2C3u, 0x00061619u, 2u);
        }

        case 0x00061619u: {
            TP_STATIC_GUARD(0x00C2C3u, 0xF0u, 0x18u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC2DDu;
                if (tp_scpu_expect_next(cpu, 0x000616E9u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC2C5u, 0x00061629u, 2u);
        }

        case 0x00061629u: {
            TP_STATIC_GUARD(0x00C2C5u, 0x8Du, 0x04u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4204u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC2C8u, 0x00061641u, 5u);
        }

        case 0x00061641u: {
            TP_STATIC_GUARD(0x00C2C8u, 0x8Eu, 0x06u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4206u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC2CBu, 0x00061659u, 4u);
        }

        case 0x00061659u: {
            TP_STATIC_GUARD(0x00C2CBu, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2CCu, 0x00061661u, 2u);
        }

        case 0x00061661u: {
            TP_STATIC_GUARD(0x00C2CCu, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2CDu, 0x00061669u, 2u);
        }

        case 0x00061669u: {
            TP_STATIC_GUARD(0x00C2CDu, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2CEu, 0x00061671u, 2u);
        }

        case 0x00061671u: {
            TP_STATIC_GUARD(0x00C2CEu, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2CFu, 0x00061679u, 2u);
        }

        case 0x00061679u: {
            TP_STATIC_GUARD(0x00C2CFu, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2D0u, 0x00061681u, 2u);
        }

        case 0x00061681u: {
            TP_STATIC_GUARD(0x00C2D0u, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2D1u, 0x00061689u, 2u);
        }

        case 0x00061689u: {
            TP_STATIC_GUARD(0x00C2D1u, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2D2u, 0x00061691u, 2u);
        }

        case 0x00061691u: {
            TP_STATIC_GUARD(0x00C2D2u, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2D3u, 0x00061699u, 2u);
        }

        case 0x00061699u: {
            TP_STATIC_GUARD(0x00C2D3u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC2D5u, 0x000616A8u, 3u);
        }

        case 0x000616A8u: {
            TP_STATIC_GUARD(0x00C2D5u, 0xADu, 0x14u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4214u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2D8u, 0x000616C0u, 5u);
        }

        case 0x000616C0u: {
            TP_STATIC_GUARD(0x00C2D8u, 0xAEu, 0x16u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4216u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2DBu, 0x000616D8u, 5u);
        }

        case 0x000616D8u: {
            TP_STATIC_GUARD(0x00C2DBu, 0x80u, 0x06u);
            TP_STATIC_EXIT(0x00u, 0xC2E3u, 0x00061718u, 3u);
        }

        case 0x000616E9u: {
            TP_STATIC_GUARD(0x00C2DDu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x00u, 0xC2DFu, 0x000616F8u, 3u);
        }

        case 0x000616F8u: {
            TP_STATIC_GUARD(0x00C2DFu, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2E2u, 0x00061710u, 3u);
        }

        case 0x00061710u: {
            TP_STATIC_GUARD(0x00C2E2u, 0xAAu);
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->x) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2E3u, 0x00061718u, 2u);
        }

        case 0x00061718u: {
            TP_STATIC_GUARD(0x00C2E3u, 0x60u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            switch (tp_scpu_context_key(cpu)) {
                case 0x0006AC08u:
                case 0x00070298u:
                case 0x00070318u:
                case 0x00071CC0u:
                case 0x000783F8u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            }
        }

        case 0x00061720u: {
            TP_STATIC_GUARD(0x00C2E4u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xC2E6u, 0x00061731u, 3u);
        }

        case 0x00061721u: {
            TP_STATIC_GUARD(0x00C2E4u, 0xE2u, 0x10u);
            cpu->p = (uint8_t)(cpu->p | 0x10u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x00u, 0xC2E6u, 0x00061731u, 3u);
        }

        case 0x00061731u: {
            TP_STATIC_GUARD(0x00C2E6u, 0xC2u, 0x20u);
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            TP_STATIC_EXIT(0x00u, 0xC2E8u, 0x00061741u, 3u);
        }

        case 0x00061741u: {
            TP_STATIC_GUARD(0x00C2E8u, 0xA2u, 0x93u);
            const uint8_t value = 0x93u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2EAu, 0x00061751u, 2u);
        }

        case 0x00061751u: {
            TP_STATIC_GUARD(0x00C2EAu, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2EDu, 0x00061769u, 3u);
        }

        case 0x00061769u: {
            TP_STATIC_GUARD(0x00C2EDu, 0xF0u, 0x1Cu);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC30Bu;
                if (tp_scpu_expect_next(cpu, 0x00061859u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC2EFu, 0x00061779u, 2u);
        }

        case 0x00061779u: {
            TP_STATIC_GUARD(0x00C2EFu, 0xE0u, 0x00u);
            const uint8_t left = (uint8_t)(cpu->x & 0x00FFu);
            const uint8_t right = 0x00u;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x00u, 0xC2F1u, 0x00061789u, 2u);
        }

        case 0x00061789u: {
            TP_STATIC_GUARD(0x00C2F1u, 0xF0u, 0x18u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x00u;
                cpu->pc = 0xC30Bu;
                if (tp_scpu_expect_next(cpu, 0x00061859u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x00u, 0xC2F3u, 0x00061799u, 2u);
        }

        case 0x00061799u: {
            TP_STATIC_GUARD(0x00C2F3u, 0x8Du, 0x04u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x4204u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC2F6u, 0x000617B1u, 5u);
        }

        case 0x000617B1u: {
            TP_STATIC_GUARD(0x00C2F6u, 0x8Eu, 0x06u, 0x42u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x4206u;
            if (tp_scpu_write8(cpu, bus, address, (uint8_t)(cpu->x & 0x00FFu)) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x00u, 0xC2F9u, 0x000617C9u, 4u);
        }

        case 0x000617C9u: {
            TP_STATIC_GUARD(0x00C2F9u, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2FAu, 0x000617D1u, 2u);
        }

        case 0x000617D1u: {
            TP_STATIC_GUARD(0x00C2FAu, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2FBu, 0x000617D9u, 2u);
        }

        case 0x000617D9u: {
            TP_STATIC_GUARD(0x00C2FBu, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2FCu, 0x000617E1u, 2u);
        }

        case 0x000617E1u: {
            TP_STATIC_GUARD(0x00C2FCu, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2FDu, 0x000617E9u, 2u);
        }

        case 0x000617E9u: {
            TP_STATIC_GUARD(0x00C2FDu, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2FEu, 0x000617F1u, 2u);
        }

        case 0x000617F1u: {
            TP_STATIC_GUARD(0x00C2FEu, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC2FFu, 0x000617F9u, 2u);
        }

        case 0x000617F9u: {
            TP_STATIC_GUARD(0x00C2FFu, 0xEAu);
            TP_STATIC_EXIT(0x00u, 0xC300u, 0x00061801u, 2u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
