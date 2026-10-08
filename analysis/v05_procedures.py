"""Finite interprocedural summaries for Theme Park 05C control-flow proof."""
from __future__ import annotations

from collections import defaultdict, deque
from dataclasses import dataclass

from analysis.v04_contexts import (CONDITIONAL_BRANCHES, INDIRECT_CONTROL_MODES, Context,
                                    Discovery, Edge, Frontier, _next, _signed, _target,
                                    cpu_to_rom_offset)
from analysis.w65c816.decoder import decode


@dataclass(frozen=True, order=True)
class Procedure:
    entry: Context
    return_class: str


@dataclass(frozen=True, order=True)
class Continuation:
    address: Context
    caller: Procedure
    call_source: Context
    caller_status_stack: tuple[tuple[str, int, int, int | None, int | None, int | None], ...]
    caller_stack_delta: int


def discover_summarized(rom: bytes, roots: dict[Context, tuple[str, ...]],
                        software_vectors: dict[tuple[str, int], int],
                        root_return_classes: dict[Context, str] | None = None,
                        root_interrupt_disable: dict[Context, int | None] | None = None,
                        root_nmi_enabled: dict[Context, int | None] | None = None,
                        nmi_enable_writes: dict[Context, int] | None = None,
                        proof_sink: list[dict[str, str]] | None = None) -> Discovery:
    """Compute a monotone procedure/return fixed point without call-depth caps."""
    root_return_classes = root_return_classes or {}
    root_interrupt_disable = root_interrupt_disable or {}
    root_nmi_enabled = root_nmi_enabled or {}
    nmi_enable_writes = nmi_enable_writes or {}
    root_procedures = {
        context: Procedure(context, root_return_classes.get(context, "ROOT"))
        for context in roots
    }
    asynchronous_roots = {
        procedure for context, procedure in root_procedures.items()
        if root_return_classes.get(context) == "RTI"
    }
    queue = deque((context, None, None, root_interrupt_disable.get(context),
                   root_nmi_enabled.get(context),
                   root_procedures[context], (), 0)
                  for context in sorted(roots))
    seen = set()
    origins: dict[Context, set[str]] = defaultdict(set)
    for context, values in roots.items():
        origins[context].update(values)
    raw_by_context: dict[Context, bytes] = {}
    mnemonic_by_context: dict[Context, str] = {}
    mode_by_context: dict[Context, str] = {}
    carry_facts: dict[Context, set[int | None]] = defaultdict(set)
    zero_facts: dict[Context, set[int | None]] = defaultdict(set)
    interrupt_disable_facts: dict[Context, set[int | None]] = defaultdict(set)
    nmi_enable_facts: dict[Context, set[int | None]] = defaultdict(set)
    edges: set[Edge] = set()
    frontiers: set[Frontier] = set()
    continuations: dict[Procedure, set[Continuation]] = defaultdict(set)
    return_summaries: dict[
        Procedure, set[tuple[Context, int | None, int | None, int | None, int | None]]
    ] = defaultdict(set)
    return_proof_rows: set[tuple[Context, Context, Context, Context, str]] = set()

    def enqueue(source: Context, kind: str, target: Context, carry: int | None,
                zero: int | None, interrupt_disable: int | None,
                nmi_enabled: int | None, procedure: Procedure,
                status_stack: tuple[tuple[str, int, int, int | None, int | None, int | None], ...],
                stack_delta: int) -> None:
        try:
            cpu_to_rom_offset(target.pbr, target.pc)
        except ValueError as error:
            frontiers.add(Frontier(source, "FETCH_OUTSIDE_CANONICAL_ROM",
                                   f"{target.key}:{error}", "08C"))
            return
        edges.add(Edge(source, kind, target))
        origins[target].add(f"{kind}:{source.key}")
        state = (target, carry, zero, interrupt_disable, nmi_enabled,
                 procedure, status_stack, stack_delta)
        if state not in seen:
            queue.append(state)

    def publish_return(source: Context, procedure: Procedure, carry: int | None,
                       zero: int | None, interrupt_disable: int | None,
                       nmi_enabled: int | None) -> None:
        summary = (source, carry, zero, interrupt_disable, nmi_enabled)
        if summary in return_summaries[procedure]:
            return
        return_summaries[procedure].add(summary)
        for continuation in sorted(
                continuations[procedure],
                key=lambda row: (row.address, row.caller, row.call_source,
                                 repr(row.caller_status_stack),
                                 row.caller_stack_delta)):
            target = Context(continuation.address.pbr, continuation.address.pc,
                             source.e, source.m, source.x)
            enqueue(source, "RETURN_PROVED", target, carry, zero, interrupt_disable,
                    nmi_enabled, continuation.caller,
                    continuation.caller_status_stack, continuation.caller_stack_delta)
            return_proof_rows.add((continuation.call_source, procedure.entry, source,
                                   target, procedure.return_class))

    def register_call(source: Context, target: Context, continuation_address: Context,
                      expected: str, carry: int | None, zero: int | None,
                      interrupt_disable: int | None,
                      nmi_enabled: int | None,
                      caller: Procedure,
                      caller_status_stack: tuple[
                          tuple[str, int, int, int | None, int | None, int | None], ...
                      ],
                      caller_stack_delta: int) -> None:
        callee = Procedure(target, expected)
        continuation = Continuation(continuation_address, caller, source, caller_status_stack,
                                    caller_stack_delta)
        is_new = continuation not in continuations[callee]
        continuations[callee].add(continuation)
        enqueue(source, "DIRECT_CALL", target, carry, zero, interrupt_disable,
                nmi_enabled, callee, (), 0)
        if is_new:
            for return_source, returned_carry, returned_zero, returned_i, returned_nmi in sorted(
                    return_summaries[callee],
                    key=lambda row: (row[0], -1 if row[1] is None else row[1],
                                     -1 if row[2] is None else row[2],
                                     -1 if row[3] is None else row[3],
                                     -1 if row[4] is None else row[4])):
                returned = Context(continuation_address.pbr, continuation_address.pc,
                                   return_source.e, return_source.m, return_source.x)
                enqueue(return_source, "RETURN_PROVED", returned, returned_carry,
                        returned_zero, returned_i, returned_nmi, caller,
                        caller_status_stack, caller_stack_delta)
                return_proof_rows.add((source, callee.entry, return_source, returned,
                                       callee.return_class))

    while queue:
        context, carry_in, zero_in, interrupt_disable_in, nmi_enabled_in, procedure, status_stack, stack_delta = queue.popleft()
        state_key = (context, carry_in, zero_in, interrupt_disable_in, nmi_enabled_in,
                     procedure, status_stack, stack_delta)
        if state_key in seen:
            continue
        seen.add(state_key)
        carry_facts[context].add(carry_in)
        zero_facts[context].add(zero_in)
        interrupt_disable_facts[context].add(interrupt_disable_in)
        nmi_enable_facts[context].add(nmi_enabled_in)
        try:
            offset = cpu_to_rom_offset(context.pbr, context.pc)
            instruction = decode(rom[offset:offset + 4], e=context.e, m=context.m, x=context.x)
        except ValueError as error:
            frontiers.add(Frontier(context, "TRUNCATED_OR_UNMAPPED_FETCH", str(error), "08C"))
            continue
        raw_by_context[context] = instruction.raw
        mnemonic, mode = instruction.opcode.mnemonic, instruction.opcode.mode
        mnemonic_by_context[context], mode_by_context[context] = mnemonic, mode
        length = len(instruction.raw)
        fallthrough = _next(context, length)

        carry_out = carry_in
        if mnemonic == "CLC": carry_out = 0
        elif mnemonic == "SEC": carry_out = 1
        elif mnemonic == "REP" and instruction.operand & 1: carry_out = 0
        elif mnemonic == "SEP" and instruction.operand & 1: carry_out = 1
        elif mnemonic in ("ADC", "SBC", "CMP", "CPX", "CPY", "ASL", "LSR", "ROL", "ROR"):
            carry_out = None

        zero_out = zero_in
        nz_writers = {
            "ORA", "AND", "EOR", "ADC", "SBC", "CMP", "CPX", "CPY", "BIT", "TSB", "TRB",
            "ASL", "LSR", "ROL", "ROR", "INC", "DEC", "LDA", "LDX", "LDY",
            "PLA", "PLX", "PLY", "PLB", "PLD", "TAX", "TAY", "TXA", "TYA", "TSX",
            "TXY", "TYX", "TCD", "TDC", "TSC", "INX", "INY", "DEX", "DEY", "XBA",
        }
        if mnemonic in nz_writers:
            zero_out = None
        if mnemonic in ("LDA", "LDX", "LDY") and mode in ("IMM_M", "IMM_X"):
            zero_out = 1 if instruction.operand == 0 else 0
        elif mnemonic == "AND" and mode == "IMM_M" and instruction.operand == 0:
            zero_out = 1
        elif mnemonic == "BIT" and mode == "IMM_M" and instruction.operand == 0:
            zero_out = 1
        elif mnemonic == "REP" and instruction.operand & 0x02:
            zero_out = 0
        elif mnemonic == "SEP" and instruction.operand & 0x02:
            zero_out = 1

        interrupt_disable_out = interrupt_disable_in
        if mnemonic == "CLI":
            interrupt_disable_out = 0
        elif mnemonic == "SEI":
            interrupt_disable_out = 1
        elif mnemonic == "REP" and instruction.operand & 0x04:
            interrupt_disable_out = 0
        elif mnemonic == "SEP" and instruction.operand & 0x04:
            interrupt_disable_out = 1

        nmi_enabled_out = nmi_enable_writes.get(context, nmi_enabled_in)

        stack_out = status_stack
        delta_out = stack_delta
        if mnemonic == "PHP":
            stack_out = status_stack + (("STATUS", context.m, context.x, carry_in, zero_in,
                                         interrupt_disable_in),)
            delta_out += 1
        else:
            push_counts = {"PHA": 1 if context.m else 2, "PHX": 1 if context.x else 2,
                           "PHY": 1 if context.x else 2, "PHB": 1, "PHK": 1, "PHD": 2,
                           "PEA": 2, "PEI": 2, "PER": 2}
            pull_counts = {"PLA": 1 if context.m else 2, "PLX": 1 if context.x else 2,
                           "PLY": 1 if context.x else 2, "PLB": 1, "PLD": 2}
            if mnemonic in push_counts:
                count = push_counts[mnemonic]
                delta_out += count
                if any(token[0] == "STATUS" for token in status_stack):
                    stack_out += tuple(("DATA", 0, 0, None, None, None) for _ in range(count))
            elif mnemonic in pull_counts:
                count = pull_counts[mnemonic]
                if stack_delta < count:
                    frontiers.add(Frontier(context, "STACK_PROVENANCE_EXHAUSTED",
                                           f"{mnemonic}:need={count};local_delta={stack_delta}", "05C"))
                    continue
                delta_out -= count
                if any(token[0] == "STATUS" for token in status_stack):
                    if len(status_stack) < count:
                        frontiers.add(Frontier(context, "STATUS_PROVENANCE_EXHAUSTED",
                                               f"{mnemonic}:need={count};known={len(status_stack)}", "05C"))
                        continue
                    stack_out = status_stack[:-count]

        def go(kind: str, target: Context, carry: int | None = carry_out,
               zero: int | None = zero_out,
               interrupt_disable: int | None = interrupt_disable_out,
               nmi_enabled: int | None = nmi_enabled_out,
               stack=stack_out, delta=delta_out, proc=procedure) -> None:
            enqueue(context, kind, target, carry, zero, interrupt_disable,
                    nmi_enabled, proc, stack, delta)

        if mnemonic in CONDITIONAL_BRANCHES:
            target = _target(context, fallthrough.pc + _signed(instruction.operand, 8))
            if mnemonic in ("BCC", "BCS"):
                taken_carry = 0 if mnemonic == "BCC" else 1
                if carry_in is None or carry_in == taken_carry:
                    go("BRANCH_TAKEN", target, taken_carry)
                if carry_in is None or carry_in != taken_carry:
                    go("BRANCH_NOT_TAKEN", fallthrough, 1 - taken_carry)
            elif mnemonic in ("BEQ", "BNE"):
                taken_zero = 1 if mnemonic == "BEQ" else 0
                if zero_in is None or zero_in == taken_zero:
                    go("BRANCH_TAKEN", target, zero=taken_zero)
                if zero_in is None or zero_in != taken_zero:
                    go("BRANCH_NOT_TAKEN", fallthrough, zero=1 - taken_zero)
            else:
                go("BRANCH_TAKEN", target)
                go("BRANCH_NOT_TAKEN", fallthrough)
        elif mnemonic in ("BRA", "BRL"):
            bits = 8 if mnemonic == "BRA" else 16
            go("BRANCH_ALWAYS", _target(context, fallthrough.pc + _signed(instruction.operand, bits)))
        elif mnemonic in ("JMP", "JML"):
            if mode in INDIRECT_CONTROL_MODES:
                frontiers.add(Frontier(context, "INDIRECT_JUMP_TARGET", mode, "05C"))
            elif mode == "ABSL_JUMP":
                go("DIRECT_JUMP", _target(context, instruction.operand & 0xFFFF,
                                           pbr=(instruction.operand >> 16) & 0xFF))
            else: go("DIRECT_JUMP", _target(context, instruction.operand))
        elif mnemonic in ("JSR", "JSL"):
            if mode == "ABS_X_IND":
                frontiers.add(Frontier(context, "INDIRECT_CALL_TARGET", mode, "05C"))
            else:
                bank = context.pbr if mnemonic == "JSR" else (instruction.operand >> 16) & 0xFF
                target = _target(context, instruction.operand & 0xFFFF, pbr=bank)
                register_call(context, target, fallthrough, "RTS" if mnemonic == "JSR" else "RTL",
                              carry_out, zero_out, interrupt_disable_out,
                              nmi_enabled_out, procedure, stack_out, delta_out)
        elif mnemonic in ("RTS", "RTL", "RTI"):
            if mnemonic != procedure.return_class:
                frontiers.add(Frontier(context, "RETURN_CLASS_OR_ROOT",
                                       f"expected={procedure.return_class};actual={mnemonic}", "05C"))
            elif status_stack or stack_delta:
                frontiers.add(Frontier(context, "RETURN_WITH_LIVE_STATUS_PROOF",
                                       f"status_bytes={len(status_stack)};local_delta={stack_delta}", "05C"))
            elif procedure in asynchronous_roots:
                frontiers.add(Frontier(
                    context, "ASYNC_RTI_REENTRY_SET_OPEN",
                    "requires source-proved interrupt-enable phase and interrupted-context set",
                    "05C"))
            else:
                publish_return(context, procedure, carry_out, zero_out,
                               interrupt_disable_out, nmi_enabled_out)
        elif mnemonic in ("BRK", "COP"):
            vector = software_vectors[(mnemonic, context.e)]
            target = _target(context, vector, pbr=0)
            register_call(context, target, fallthrough, "RTI", carry_out, zero_out,
                          1, nmi_enabled_out, procedure, stack_out, delta_out)
        elif mnemonic == "WAI": frontiers.add(Frontier(context, "WAI_WAKE_REENTRY", "RESET/ABORT/NMI/IRQ", "05C"))
        elif mnemonic == "STP": frontiers.add(Frontier(context, "STP_RESET_ONLY", "RESET", "05C"))
        elif mnemonic == "XCE":
            if carry_in is None: frontiers.add(Frontier(context, "XCE_CARRY_PROVENANCE", fallthrough.key, "05C"))
            else:
                new_e = carry_in
                go("FALLTHROUGH_XCE_PROVED", _next(context, length, e=new_e,
                                                     m=1 if new_e else context.m,
                                                     x=1 if new_e else context.x), context.e)
        elif mnemonic == "PLP":
            if status_stack and status_stack[-1][0] == "STATUS":
                _, saved_m, saved_x, saved_carry, saved_zero, saved_i = status_stack[-1]
                if context.e: saved_m = saved_x = 1
                go("FALLTHROUGH_PLP_PROVED", _next(context, length, m=saved_m, x=saved_x),
                   saved_carry, saved_zero, saved_i, nmi_enabled_out,
                   status_stack[:-1], stack_delta - 1)
            else: frontiers.add(Frontier(context, "PULLED_STATUS_WIDTH", fallthrough.key, "05C"))
        elif mnemonic in ("TXS", "TCS") and procedure.return_class != "ROOT":
            frontiers.add(Frontier(context, "STACK_POINTER_REPLACEMENT",
                                   f"{mnemonic}:requires source-specific stack theorem", "05C"))
        elif mnemonic in ("REP", "SEP"):
            if context.e: go("FALLTHROUGH_STATUS", _next(context, length, e=1, m=1, x=1))
            else:
                m, x = context.m, context.x
                if mnemonic == "REP":
                    if instruction.operand & 0x20: m = 0
                    if instruction.operand & 0x10: x = 0
                else:
                    if instruction.operand & 0x20: m = 1
                    if instruction.operand & 0x10: x = 1
                go("FALLTHROUGH_STATUS", _next(context, length, m=m, x=x))
        elif mnemonic in ("MVN", "MVP"):
            go("BLOCK_MOVE_REPEAT", context); go("BLOCK_MOVE_COMPLETE", fallthrough)
        else: go("FALLTHROUGH", fallthrough)

    contexts = tuple(sorted(raw_by_context))
    if proof_sink is not None:
        proof_sink.extend({
            "call_source": call_source.key,
            "callee_entry": callee_entry.key,
            "return_source": return_source.key,
            "continuation": continuation.key,
            "return_class": return_class,
        } for call_source, callee_entry, return_source, continuation, return_class
          in sorted(return_proof_rows))

    return Discovery(contexts, raw_by_context, mnemonic_by_context, mode_by_context,
                     tuple(sorted(edges, key=lambda row: (row.source, row.kind, row.target))),
                     tuple(sorted(frontiers, key=lambda row: (row.source, row.kind, row.detail, row.owner))),
                     {c: tuple(sorted(origins[c])) for c in contexts},
                     {c: tuple("UNKNOWN" if value is None else str(value)
                               for value in sorted(carry_facts[c], key=lambda value: -1 if value is None else value))
                      for c in contexts},
                     {c: tuple("UNKNOWN" if value is None else str(value)
                               for value in sorted(zero_facts[c], key=lambda value: -1 if value is None else value))
                      for c in contexts},
                     {c: tuple("UNKNOWN" if value is None else str(value)
                               for value in sorted(interrupt_disable_facts[c],
                                                   key=lambda value: -1 if value is None else value))
                      for c in contexts},
                     {c: tuple("UNKNOWN" if value is None else str(value)
                               for value in sorted(nmi_enable_facts[c],
                                                   key=lambda value: -1 if value is None else value))
                      for c in contexts})
