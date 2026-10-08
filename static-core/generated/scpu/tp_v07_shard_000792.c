/* Generated direct Theme Park S-CPU authority; do not edit. */
#include "tp_v07_generated.h"
#include "tp_v18_compact.h"

TPScpuExecResult tp_v07_shard_000792(TPScpuState *cpu, const TPScpuBus *bus) {
    switch (tp_scpu_context_key(cpu)) {
        case 0x003C9000u: {
            TP_STATIC_GUARD(0x079200u, 0x8Du, 0x58u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0758u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9203u, 0x003C9018u, 5u);
        }

        case 0x003C9018u: {
            TP_STATIC_GUARD(0x079203u, 0xADu, 0x67u, 0x07u);
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
            TP_STATIC_EXIT(0x07u, 0x9206u, 0x003C9030u, 5u);
        }

        case 0x003C9030u: {
            TP_STATIC_GUARD(0x079206u, 0x38u);
            cpu->p = (uint8_t)(cpu->p | TP_P_C);
            TP_STATIC_EXIT(0x07u, 0x9207u, 0x003C9038u, 2u);
        }

        case 0x003C9038u: {
            TP_STATIC_GUARD(0x079207u, 0xEDu, 0x58u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0758u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_sbc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x920Au, 0x003C9050u, 5u);
        }

        case 0x003C9050u: {
            TP_STATIC_GUARD(0x07920Au, 0x8Du, 0x67u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0767u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x920Du, 0x003C9068u, 5u);
        }

        case 0x003C9068u: {
            TP_STATIC_GUARD(0x07920Du, 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            TP_STATIC_EXIT(0x07u, 0x920Eu, 0x003C9070u, 2u);
        }

        case 0x003C9070u: {
            TP_STATIC_GUARD(0x07920Eu, 0x6Du, 0x67u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0767u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9211u, 0x003C9088u, 5u);
        }

        case 0x003C9088u: {
            TP_STATIC_GUARD(0x079211u, 0x6Du, 0x0Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x040Fu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            if (tp_scpu_adc(cpu, value, 16u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9214u, 0x003C90A0u, 5u);
        }

        case 0x003C90A0u: {
            TP_STATIC_GUARD(0x079214u, 0x30u, 0x02u);
            if ((cpu->p & TP_P_N) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9218u;
                if (tp_scpu_expect_next(cpu, 0x003C90C0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9216u, 0x003C90B0u, 2u);
        }

        case 0x003C90B0u: {
            TP_STATIC_GUARD(0x079216u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x921Bu;
                if (tp_scpu_expect_next(cpu, 0x003C90D8u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9218u, 0x003C90C0u, 2u);
        }

        case 0x003C90C0u: {
            TP_STATIC_GUARD(0x079218u, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x921Bu, 0x003C90D8u, 3u);
        }

        case 0x003C90D8u: {
            TP_STATIC_GUARD(0x07921Bu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x921Du, 0x003C90E8u, 3u);
        }

        case 0x003C90E8u: {
            TP_STATIC_GUARD(0x07921Du, 0xA8u);
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->y) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x921Eu, 0x003C90F0u, 2u);
        }

        case 0x003C90F0u: {
            TP_STATIC_GUARD(0x07921Eu, 0xAEu, 0xC8u, 0x1Fu);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1FC8u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9221u, 0x003C9108u, 5u);
        }

        case 0x003C9108u: {
            TP_STATIC_GUARD(0x079221u, 0xE0u, 0x10u, 0x27u);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x2710u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9224u, 0x003C9120u, 3u);
        }

        case 0x003C9120u: {
            TP_STATIC_GUARD(0x079224u, 0xB0u, 0x0Eu);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9234u;
                if (tp_scpu_expect_next(cpu, 0x003C91A0u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9226u, 0x003C9130u, 2u);
        }

        case 0x003C9130u: {
            TP_STATIC_GUARD(0x079226u, 0xAFu, 0x22u, 0x95u, 0x05u);
            const uint32_t address = 0x059522u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x922Au, 0x003C9150u, 6u);
        }

        case 0x003C9150u: {
            TP_STATIC_GUARD(0x07922Au, 0xC0u, 0x08u, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0008u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x922Du, 0x003C9168u, 3u);
        }

        case 0x003C9168u: {
            TP_STATIC_GUARD(0x07922Du, 0x90u, 0x03u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9232u;
                if (tp_scpu_expect_next(cpu, 0x003C9190u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x922Fu, 0x003C9178u, 2u);
        }

        case 0x003C9178u: {
            TP_STATIC_GUARD(0x07922Fu, 0xA0u, 0x08u, 0x00u);
            const uint16_t value = 0x0008u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9232u, 0x003C9190u, 3u);
        }

        case 0x003C9190u: {
            TP_STATIC_GUARD(0x079232u, 0x80u, 0x17u);
            TP_STATIC_EXIT(0x07u, 0x924Bu, 0x003C9258u, 3u);
        }

        case 0x003C91A0u: {
            TP_STATIC_GUARD(0x079234u, 0xE0u, 0x20u, 0x4Eu);
            const uint16_t left = cpu->x;
            const uint16_t right = 0x4E20u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9237u, 0x003C91B8u, 3u);
        }

        case 0x003C91B8u: {
            TP_STATIC_GUARD(0x079237u, 0xB0u, 0x0Eu);
            if ((cpu->p & TP_P_C) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9247u;
                if (tp_scpu_expect_next(cpu, 0x003C9238u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9239u, 0x003C91C8u, 2u);
        }

        case 0x003C91C8u: {
            TP_STATIC_GUARD(0x079239u, 0xAFu, 0x24u, 0x95u, 0x05u);
            const uint32_t address = 0x059524u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x923Du, 0x003C91E8u, 6u);
        }

        case 0x003C91E8u: {
            TP_STATIC_GUARD(0x07923Du, 0xC0u, 0x10u, 0x00u);
            const uint16_t left = cpu->y;
            const uint16_t right = 0x0010u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9240u, 0x003C9200u, 3u);
        }

        case 0x003C9200u: {
            TP_STATIC_GUARD(0x079240u, 0x90u, 0x03u);
            if ((cpu->p & TP_P_C) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9245u;
                if (tp_scpu_expect_next(cpu, 0x003C9228u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9242u, 0x003C9210u, 2u);
        }

        case 0x003C9210u: {
            TP_STATIC_GUARD(0x079242u, 0xA0u, 0x10u, 0x00u);
            const uint16_t value = 0x0010u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9245u, 0x003C9228u, 3u);
        }

        case 0x003C9228u: {
            TP_STATIC_GUARD(0x079245u, 0x80u, 0x04u);
            TP_STATIC_EXIT(0x07u, 0x924Bu, 0x003C9258u, 3u);
        }

        case 0x003C9238u: {
            TP_STATIC_GUARD(0x079247u, 0xAFu, 0x26u, 0x95u, 0x05u);
            const uint32_t address = 0x059526u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x924Bu, 0x003C9258u, 6u);
        }

        case 0x003C9258u: {
            TP_STATIC_GUARD(0x07924Bu, 0x8Du, 0xE8u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18E8u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x924Eu, 0x003C9270u, 5u);
        }

        case 0x003C9270u: {
            TP_STATIC_GUARD(0x07924Eu, 0x98u);
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x924Fu, 0x003C9278u, 2u);
        }

        case 0x003C9278u: {
            TP_STATIC_GUARD(0x07924Fu, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9250u, 0x003C9280u, 3u);
        }

        case 0x003C9280u: {
            TP_STATIC_GUARD(0x079250u, 0x4Au);
            const uint16_t old_value = (uint16_t)(cpu->a & 0xFFFFu);
            const uint16_t value = (uint16_t)(old_value >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~TP_P_C);
            if ((old_value & 1u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9251u, 0x003C9288u, 3u);
        }

        case 0x003C9288u: {
            TP_STATIC_GUARD(0x079251u, 0x8Du, 0x67u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x0767u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9254u, 0x003C92A0u, 5u);
        }

        case 0x003C92A0u: {
            TP_STATIC_GUARD(0x079254u, 0x8Du, 0xE4u, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18E4u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9257u, 0x003C92B8u, 5u);
        }

        case 0x003C92B8u: {
            TP_STATIC_GUARD(0x079257u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x9259u, 0x003C92C8u, 3u);
        }

        case 0x003C92C8u: {
            TP_STATIC_GUARD(0x079259u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x925Au, 0x003C92D0u, 5u);
        }

        case 0x003C92D0u: {
            TP_STATIC_GUARD(0x07925Au, 0x8Du, 0x0Fu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Fu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x925Du, 0x003C92E8u, 5u);
        }

        case 0x003C92E8u: {
            TP_STATIC_GUARD(0x07925Du, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x925Eu, 0x003C92F0u, 5u);
        }

        case 0x003C92F0u: {
            TP_STATIC_GUARD(0x07925Eu, 0x8Du, 0x0Du, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Du) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9261u, 0x003C9308u, 5u);
        }

        case 0x003C9308u: {
            TP_STATIC_GUARD(0x079261u, 0x68u);
            uint8_t low = 0u, high = 0u;
            if (tp_scpu_pull8(cpu, bus, &low) != TP_SCPU_EXECUTED ||
                tp_scpu_pull8(cpu, bus, &high) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((uint16_t)low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(cpu->a) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9262u, 0x003C9310u, 5u);
        }

        case 0x003C9310u: {
            TP_STATIC_GUARD(0x079262u, 0x8Du, 0x0Bu, 0x04u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x040Bu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9265u, 0x003C9328u, 5u);
        }

        case 0x003C9328u: {
            TP_STATIC_GUARD(0x079265u, 0x6Bu);
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
                case 0x002631C8u:
                    return tp_scpu_finish(cpu, bus, 6u);
                default:
                    return tp_scpu_stop(cpu, tp_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            }
        }

        case 0x003C9332u: {
            TP_STATIC_GUARD(0x079266u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x9268u, 0x003C9343u, 3u);
        }

        case 0x003C9333u: {
            TP_STATIC_GUARD(0x079266u, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x9268u, 0x003C9343u, 3u);
        }

        case 0x003C9343u: {
            TP_STATIC_GUARD(0x079268u, 0xADu, 0xCBu, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x07CBu;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x926Bu, 0x003C935Bu, 4u);
        }

        case 0x003C935Bu: {
            TP_STATIC_GUARD(0x07926Bu, 0xF0u, 0x03u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9270u;
                if (tp_scpu_expect_next(cpu, 0x003C9383u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x926Du, 0x003C936Bu, 2u);
        }

        case 0x003C936Bu: {
            TP_STATIC_GUARD(0x07926Du, 0x82u, 0x97u, 0x01u);
            TP_STATIC_EXIT(0x07u, 0x9407u, 0x003CA03Bu, 4u);
        }

        case 0x003C9383u: {
            TP_STATIC_GUARD(0x079270u, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9273u, 0x003C939Bu, 4u);
        }

        case 0x003C939Bu: {
            TP_STATIC_GUARD(0x079273u, 0x29u, 0x20u);
            const uint8_t value = (uint8_t)(cpu->a & 0x20u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9275u, 0x003C93ABu, 2u);
        }

        case 0x003C93ABu: {
            TP_STATIC_GUARD(0x079275u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x927Au;
                if (tp_scpu_expect_next(cpu, 0x003C93D3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9277u, 0x003C93BBu, 2u);
        }

        case 0x003C93BBu: {
            TP_STATIC_GUARD(0x079277u, 0x82u, 0x8Du, 0x01u);
            TP_STATIC_EXIT(0x07u, 0x9407u, 0x003CA03Bu, 4u);
        }

        case 0x003C93D3u: {
            TP_STATIC_GUARD(0x07927Au, 0xADu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0746u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x927Du, 0x003C93EBu, 4u);
        }

        case 0x003C93EBu: {
            TP_STATIC_GUARD(0x07927Du, 0x29u, 0xF0u);
            const uint8_t value = (uint8_t)(cpu->a & 0xF0u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x927Fu, 0x003C93FBu, 2u);
        }

        case 0x003C93FBu: {
            TP_STATIC_GUARD(0x07927Fu, 0xD0u, 0x07u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9288u;
                if (tp_scpu_expect_next(cpu, 0x003C9443u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9281u, 0x003C940Bu, 2u);
        }

        case 0x003C940Bu: {
            TP_STATIC_GUARD(0x079281u, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9284u, 0x003C9423u, 4u);
        }

        case 0x003C9423u: {
            TP_STATIC_GUARD(0x079284u, 0x29u, 0xCFu);
            const uint8_t value = (uint8_t)(cpu->a & 0xCFu);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9286u, 0x003C9433u, 2u);
        }

        case 0x003C9433u: {
            TP_STATIC_GUARD(0x079286u, 0xF0u, 0x04u);
            if ((cpu->p & TP_P_Z) != 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x928Cu;
                if (tp_scpu_expect_next(cpu, 0x003C9463u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9288u, 0x003C9443u, 2u);
        }

        case 0x003C9443u: {
            TP_STATIC_GUARD(0x079288u, 0x22u, 0x61u, 0x95u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x92u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x8Bu) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9561u, 0x003CAB0Bu, 8u);
        }

        case 0x003C9460u: {
            TP_STATIC_GUARD(0x07928Cu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x928Eu, 0x003C9473u, 3u);
        }

        case 0x003C9463u: {
            TP_STATIC_GUARD(0x07928Cu, 0xE2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            if ((cpu->p & TP_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            TP_STATIC_EXIT(0x07u, 0x928Eu, 0x003C9473u, 3u);
        }

        case 0x003C9473u: {
            TP_STATIC_GUARD(0x07928Eu, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9291u, 0x003C948Bu, 4u);
        }

        case 0x003C948Bu: {
            TP_STATIC_GUARD(0x079291u, 0x29u, 0x80u);
            const uint8_t value = (uint8_t)(cpu->a & 0x80u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9293u, 0x003C949Bu, 2u);
        }

        case 0x003C949Bu: {
            TP_STATIC_GUARD(0x079293u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x9298u;
                if (tp_scpu_expect_next(cpu, 0x003C94C3u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x9295u, 0x003C94ABu, 2u);
        }

        case 0x003C94ABu: {
            TP_STATIC_GUARD(0x079295u, 0x82u, 0x07u, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x929Fu, 0x003C94FBu, 4u);
        }

        case 0x003C94C3u: {
            TP_STATIC_GUARD(0x079298u, 0xA2u, 0x20u);
            const uint8_t value = 0x20u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x929Au, 0x003C94D3u, 2u);
        }

        case 0x003C94D3u: {
            TP_STATIC_GUARD(0x07929Au, 0xA0u, 0x35u);
            const uint8_t value = 0x35u;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x929Cu, 0x003C94E3u, 2u);
        }

        case 0x003C94E3u: {
            TP_STATIC_GUARD(0x07929Cu, 0x82u, 0xFDu, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x939Cu, 0x003C9CE3u, 4u);
        }

        case 0x003C94FBu: {
            TP_STATIC_GUARD(0x07929Fu, 0xADu, 0x47u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0747u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92A2u, 0x003C9513u, 4u);
        }

        case 0x003C9513u: {
            TP_STATIC_GUARD(0x0792A2u, 0x29u, 0x40u);
            const uint8_t value = (uint8_t)(cpu->a & 0x40u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92A4u, 0x003C9523u, 2u);
        }

        case 0x003C9523u: {
            TP_STATIC_GUARD(0x0792A4u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x92A9u;
                if (tp_scpu_expect_next(cpu, 0x003C954Bu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x92A6u, 0x003C9533u, 2u);
        }

        case 0x003C9533u: {
            TP_STATIC_GUARD(0x0792A6u, 0x82u, 0x1Fu, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x92C8u, 0x003C9643u, 4u);
        }

        case 0x003C954Bu: {
            TP_STATIC_GUARD(0x0792A9u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x92ABu, 0x003C9558u, 3u);
        }

        case 0x003C9558u: {
            TP_STATIC_GUARD(0x0792ABu, 0xA9u, 0x00u, 0x00u);
            const uint16_t value = 0x0000u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92AEu, 0x003C9570u, 3u);
        }

        case 0x003C9570u: {
            TP_STATIC_GUARD(0x0792AEu, 0xACu, 0xFCu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x18FCu;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92B1u, 0x003C9588u, 5u);
        }

        case 0x003C9588u: {
            TP_STATIC_GUARD(0x0792B1u, 0xA2u, 0x08u, 0x00u);
            const uint16_t value = 0x0008u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92B4u, 0x003C95A0u, 3u);
        }

        case 0x003C95A0u: {
            TP_STATIC_GUARD(0x0792B4u, 0x22u, 0x08u, 0x94u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x92u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xB7u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9408u, 0x003CA040u, 8u);
        }

        case 0x003C95C0u: {
            TP_STATIC_GUARD(0x0792B8u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x92BAu, 0x003C95D0u, 3u);
        }

        case 0x003C95D0u: {
            TP_STATIC_GUARD(0x0792BAu, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92BDu, 0x003C95E8u, 3u);
        }

        case 0x003C95E8u: {
            TP_STATIC_GUARD(0x0792BDu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x92C2u;
                if (tp_scpu_expect_next(cpu, 0x003C9610u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x92BFu, 0x003C95F8u, 2u);
        }

        case 0x003C95F8u: {
            TP_STATIC_GUARD(0x0792BFu, 0x82u, 0x3Au, 0x01u);
            TP_STATIC_EXIT(0x07u, 0x93FCu, 0x003C9FE0u, 4u);
        }

        case 0x003C9610u: {
            TP_STATIC_GUARD(0x0792C2u, 0x8Du, 0xFCu, 0x18u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x18FCu) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x92C5u, 0x003C9628u, 5u);
        }

        case 0x003C9628u: {
            TP_STATIC_GUARD(0x0792C5u, 0x82u, 0xD4u, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x939Cu, 0x003C9CE0u, 4u);
        }

        case 0x003C9643u: {
            TP_STATIC_GUARD(0x0792C8u, 0xADu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0746u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92CBu, 0x003C965Bu, 4u);
        }

        case 0x003C965Bu: {
            TP_STATIC_GUARD(0x0792CBu, 0x29u, 0x40u);
            const uint8_t value = (uint8_t)(cpu->a & 0x40u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92CDu, 0x003C966Bu, 2u);
        }

        case 0x003C966Bu: {
            TP_STATIC_GUARD(0x0792CDu, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x92D2u;
                if (tp_scpu_expect_next(cpu, 0x003C9693u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x92CFu, 0x003C967Bu, 2u);
        }

        case 0x003C967Bu: {
            TP_STATIC_GUARD(0x0792CFu, 0x82u, 0x1Fu, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x92F1u, 0x003C978Bu, 4u);
        }

        case 0x003C9693u: {
            TP_STATIC_GUARD(0x0792D2u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x92D4u, 0x003C96A0u, 3u);
        }

        case 0x003C96A0u: {
            TP_STATIC_GUARD(0x0792D4u, 0xA9u, 0x01u, 0x00u);
            const uint16_t value = 0x0001u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92D7u, 0x003C96B8u, 3u);
        }

        case 0x003C96B8u: {
            TP_STATIC_GUARD(0x0792D7u, 0xACu, 0x00u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x1900u;
            uint16_t value = 0u;
            if (tp_scpu_read16(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92DAu, 0x003C96D0u, 5u);
        }

        case 0x003C96D0u: {
            TP_STATIC_GUARD(0x0792DAu, 0xA2u, 0x08u, 0x00u);
            const uint16_t value = 0x0008u;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92DDu, 0x003C96E8u, 3u);
        }

        case 0x003C96E8u: {
            TP_STATIC_GUARD(0x0792DDu, 0x22u, 0x08u, 0x94u, 0x07u);
            if (tp_scpu_push8(cpu, bus, cpu->pbr) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0x92u) != TP_SCPU_EXECUTED ||
                tp_scpu_push8(cpu, bus, 0xE0u) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x9408u, 0x003CA040u, 8u);
        }

        case 0x003C9708u: {
            TP_STATIC_GUARD(0x0792E1u, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x92E3u, 0x003C9718u, 3u);
        }

        case 0x003C9718u: {
            TP_STATIC_GUARD(0x0792E3u, 0xC9u, 0x00u, 0x00u);
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint16_t result = (uint16_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z | TP_P_C));
            if (left >= right) cpu->p = (uint8_t)(cpu->p | TP_P_C);
            if (result == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if ((result & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92E6u, 0x003C9730u, 3u);
        }

        case 0x003C9730u: {
            TP_STATIC_GUARD(0x0792E6u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x92EBu;
                if (tp_scpu_expect_next(cpu, 0x003C9758u) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x92E8u, 0x003C9740u, 2u);
        }

        case 0x003C9740u: {
            TP_STATIC_GUARD(0x0792E8u, 0x82u, 0x11u, 0x01u);
            TP_STATIC_EXIT(0x07u, 0x93FCu, 0x003C9FE0u, 4u);
        }

        case 0x003C9758u: {
            TP_STATIC_GUARD(0x0792EBu, 0x8Du, 0x00u, 0x19u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = (0x1900u) & 0xFFFFFFu;
            if (tp_scpu_write16(cpu, bus, address, cpu->a) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            TP_STATIC_EXIT(0x07u, 0x92EEu, 0x003C9770u, 5u);
        }

        case 0x003C9770u: {
            TP_STATIC_GUARD(0x0792EEu, 0x82u, 0xABu, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x939Cu, 0x003C9CE0u, 4u);
        }

        case 0x003C978Bu: {
            TP_STATIC_GUARD(0x0792F1u, 0xADu, 0x46u, 0x07u);
            if (cpu->dbr != 0u)
                return tp_scpu_stop(cpu, tp_scpu_address(cpu), "DBR_ZERO_PROOF_VIOLATION");
            const uint32_t address = 0x0746u;
            uint8_t value = 0u;
            if (tp_scpu_read8(cpu, bus, address, &value) != TP_SCPU_EXECUTED)
                return TP_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92F4u, 0x003C97A3u, 4u);
        }

        case 0x003C97A3u: {
            TP_STATIC_GUARD(0x0792F4u, 0x29u, 0x80u);
            const uint8_t value = (uint8_t)(cpu->a & 0x80u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint8_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint8_t)(value) & 0x80u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x92F6u, 0x003C97B3u, 2u);
        }

        case 0x003C97B3u: {
            TP_STATIC_GUARD(0x0792F6u, 0xD0u, 0x03u);
            if ((cpu->p & TP_P_Z) == 0u) {
                cpu->pbr = 0x07u;
                cpu->pc = 0x92FBu;
                if (tp_scpu_expect_next(cpu, 0x003C97DBu) != TP_SCPU_EXECUTED)
                    return TP_SCPU_STOPPED;
                return tp_scpu_finish(cpu, bus, 3u);
            }
            TP_STATIC_EXIT(0x07u, 0x92F8u, 0x003C97C3u, 2u);
        }

        case 0x003C97C3u: {
            TP_STATIC_GUARD(0x0792F8u, 0x82u, 0x1Fu, 0x00u);
            TP_STATIC_EXIT(0x07u, 0x931Au, 0x003C98D3u, 4u);
        }

        case 0x003C97DBu: {
            TP_STATIC_GUARD(0x0792FBu, 0xC2u, 0x30u);
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            TP_STATIC_EXIT(0x07u, 0x92FDu, 0x003C97E8u, 3u);
        }

        case 0x003C97E8u: {
            TP_STATIC_GUARD(0x0792FDu, 0xA9u, 0x02u, 0x00u);
            const uint16_t value = 0x0002u;
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(TP_P_N | TP_P_Z));
            if ((uint16_t)(value) == 0u) cpu->p = (uint8_t)(cpu->p | TP_P_Z);
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p = (uint8_t)(cpu->p | TP_P_N);
            TP_STATIC_EXIT(0x07u, 0x9300u, 0x003C9800u, 3u);
        }

        default: return TP_SCPU_NOT_MINE;
    }
}
