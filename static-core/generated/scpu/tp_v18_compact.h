/* Compile-time factoring only; expanded statements retain original order. */
#define TP_STATIC_GUARD(address, ...) \
    static const uint8_t expected_bytes[] = { __VA_ARGS__ }; \
    if (tp_scpu_guard_code(cpu, bus, address, expected_bytes, sizeof(expected_bytes)) != TP_SCPU_EXECUTED) \
        return TP_SCPU_STOPPED
#define TP_STATIC_EXIT(bank, pc_value, next_key, cycles) \
    cpu->pbr = bank; \
    cpu->pc = pc_value; \
    if (tp_scpu_expect_next(cpu, next_key) != TP_SCPU_EXECUTED) \
        return TP_SCPU_STOPPED; \
    return tp_scpu_finish(cpu, bus, cycles)
