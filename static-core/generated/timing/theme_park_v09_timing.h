#ifndef THEME_PARK_V09_TIMING_H
#define THEME_PARK_V09_TIMING_H
#include <stddef.h>
#include <stdint.h>
#define TP_TIMING_DIRECT_LOW_PRE 0x00000001u
#define TP_TIMING_INDEX_DYNAMIC_PRE_DATA 0x00000002u
#define TP_TIMING_BRANCH_TAKEN_POST 0x00000004u
#define TP_TIMING_BRANCH_PAGE_POST 0x00000008u
#define TP_TIMING_JSL_DEFERRED_BANK_FETCH 0x00000010u
#define TP_TIMING_STACK_PUSH_PRE 0x00000020u
#define TP_TIMING_STACK_PULL_PRE2 0x00000040u
#define TP_TIMING_RETURN_POST 0x00000080u
#define TP_TIMING_IMPLIED_PRE 0x00000100u
#define TP_TIMING_EXTRA_IMPLIED_PRE 0x00000200u
#define TP_TIMING_STATUS_PRE 0x00000400u
#define TP_TIMING_BRANCH_ALWAYS_POST 0x00000800u
#define TP_TIMING_RELLONG_PRE 0x00001000u
#define TP_TIMING_RMW_INTERMEDIATE 0x00002000u
#define TP_TIMING_INDEX_FIXED_PRE_DATA 0x00004000u
typedef struct TPScpuTimingPlan {
    uint32_t key, address, operand, flags;
    uint8_t opcode, length, pointer_reads, base_cycles;
} TPScpuTimingPlan;
const TPScpuTimingPlan *tp_v09_timing_plan(uint32_t key);
size_t tp_v09_timing_plan_count(void);
#endif
