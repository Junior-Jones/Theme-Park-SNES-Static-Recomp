"""Theme Park 04C reset-rooted exact direct-flow discovery.

This analyser never executes instructions and never promotes a target from a
trace.  It follows only source-encoded direct control flow while carrying the
minimum decode identity PBR:PC:E:M:X.  Unproved state/target transitions stop
at a named frontier for their owning later milestone.
"""
from __future__ import annotations

from collections import defaultdict, deque
from dataclasses import dataclass, field

from analysis.w65c816.decoder import decode


@dataclass(frozen=True, order=True)
class Context:
    pbr: int
    pc: int
    e: int
    m: int
    x: int

    @property
    def key(self) -> str:
        return f"{self.pbr:02X}:{self.pc:04X}:{self.e}:{self.m}:{self.x}"


@dataclass(frozen=True)
class Edge:
    source: Context
    kind: str
    target: Context


@dataclass(frozen=True)
class Frontier:
    source: Context
    kind: str
    detail: str
    owner: str


@dataclass(frozen=True)
class Discovery:
    contexts: tuple[Context, ...]
    raw_by_context: dict[Context, bytes]
    mnemonic_by_context: dict[Context, str]
    mode_by_context: dict[Context, str]
    edges: tuple[Edge, ...]
    frontiers: tuple[Frontier, ...]
    origins: dict[Context, tuple[str, ...]]
    carry_facts: dict[Context, tuple[str, ...]]
    zero_facts: dict[Context, tuple[str, ...]] = field(default_factory=dict)
    interrupt_disable_facts: dict[Context, tuple[str, ...]] = field(default_factory=dict)
    nmi_enable_facts: dict[Context, tuple[str, ...]] = field(default_factory=dict)


CONDITIONAL_BRANCHES = frozenset(("BCC", "BCS", "BEQ", "BMI", "BNE", "BPL", "BVC", "BVS"))
RETURNS = frozenset(("RTS", "RTL", "RTI"))
INDIRECT_CONTROL_MODES = frozenset(("ABS_IND", "ABS_IND_LONG", "ABS_X_IND"))


def cpu_to_rom_offset(pbr: int, pc: int) -> int:
    if not 0 <= pbr <= 0xFF or not 0 <= pc <= 0xFFFF:
        raise ValueError("CPU address outside domain")
    physical_bank = pbr & 0x7F
    if pc < 0x8000 or physical_bank >= 0x20:
        raise ValueError("CPU address is outside canonical Theme Park LoROM")
    return physical_bank * 0x8000 + (pc & 0x7FFF)


def _signed(value: int, bits: int) -> int:
    sign = 1 << (bits - 1)
    return value - (1 << bits) if value & sign else value


def _next(context: Context, length: int, *, e: int | None = None,
          m: int | None = None, x: int | None = None) -> Context:
    return Context(context.pbr, (context.pc + length) & 0xFFFF,
                   context.e if e is None else e,
                   context.m if m is None else m,
                   context.x if x is None else x)


def _target(context: Context, pc: int, *, pbr: int | None = None) -> Context:
    return Context(context.pbr if pbr is None else pbr, pc & 0xFFFF,
                   context.e, context.m, context.x)


def discover_direct(rom: bytes, roots: dict[Context, tuple[str, ...]],
                    software_vectors: dict[tuple[str, int], int], *, close_returns: bool = False,
                    diagnostic_state_limit: int | None = None) -> Discovery:
    # Each frame is (exact continuation, required return mnemonic, callee entry).
    # Data-stack tokens model only bytes pushed/pulled by explicit instructions;
    # call return frames remain in the separate exact call stack.
    queue = deque((context, None, (), ()) for context in sorted(roots))
    origins: dict[Context, set[str]] = defaultdict(set)
    for context, values in roots.items():
        origins[context].update(values)
    seen_states: set[tuple[Context, int | None, tuple[tuple[Context, str, Context], ...],
                           tuple[tuple[str, int, int, int | None], ...]]] = set()
    carry_facts: dict[Context, set[int | None]] = defaultdict(set)
    raw_by_context: dict[Context, bytes] = {}
    mnemonic_by_context: dict[Context, str] = {}
    mode_by_context: dict[Context, str] = {}
    edges: set[Edge] = set()
    frontiers: set[Frontier] = set()

    active_stack: tuple[tuple[Context, str, Context], ...] = ()
    active_data_stack: tuple[tuple[str, int, int, int | None], ...] = ()

    def admit(source: Context, kind: str, target: Context, carry: int | None,
              stack: tuple[tuple[Context, str, Context], ...] | None = None,
              data_stack: tuple[tuple[str, int, int, int | None], ...] | None = None) -> None:
        try:
            cpu_to_rom_offset(target.pbr, target.pc)
        except ValueError as error:
            frontiers.add(Frontier(source, "FETCH_OUTSIDE_CANONICAL_ROM",
                                   f"{target.key}:{error}", "08C"))
            return
        edge = Edge(source, kind, target)
        edges.add(edge)
        origins[target].add(f"{kind}:{source.key}")
        next_stack = active_stack if stack is None else stack
        next_data_stack = active_data_stack if data_stack is None else data_stack
        if (target, carry, next_stack, next_data_stack) not in seen_states:
            queue.append((target, carry, next_stack, next_data_stack))

    while queue:
        context, carry_in, call_stack, data_stack = queue.popleft()
        active_stack = call_stack
        active_data_stack = data_stack
        if (context, carry_in, call_stack, data_stack) in seen_states:
            continue
        seen_states.add((context, carry_in, call_stack, data_stack))
        if diagnostic_state_limit is not None and len(seen_states) >= diagnostic_state_limit:
            raise RuntimeError(f"diagnostic state limit at {context.key}; call_depth={len(call_stack)}; "
                               f"calls={[frame[2].key for frame in call_stack]}; "
                               f"data_stack={[token[0] for token in data_stack]}; queued={len(queue)}")
        carry_facts[context].add(carry_in)
        try:
            offset = cpu_to_rom_offset(context.pbr, context.pc)
        except ValueError as error:
            frontiers.add(Frontier(context, "FETCH_OUTSIDE_CANONICAL_ROM", str(error), "08C"))
            continue
        try:
            instruction = decode(rom[offset:offset + 4], e=context.e, m=context.m, x=context.x)
        except ValueError as error:
            frontiers.add(Frontier(context, "TRUNCATED_OR_UNMAPPED_FETCH", str(error), "08C"))
            continue
        raw_by_context[context] = instruction.raw
        mnemonic = instruction.opcode.mnemonic
        mode = instruction.opcode.mode
        mnemonic_by_context[context] = mnemonic
        mode_by_context[context] = mode
        length = len(instruction.raw)
        fallthrough = _next(context, length)
        carry_out = carry_in
        if mnemonic == "CLC":
            carry_out = 0
        elif mnemonic == "SEC":
            carry_out = 1
        elif mnemonic == "REP" and instruction.operand & 0x01:
            carry_out = 0
        elif mnemonic == "SEP" and instruction.operand & 0x01:
            carry_out = 1
        elif mnemonic in ("ADC", "SBC", "CMP", "CPX", "CPY", "ASL", "LSR", "ROL", "ROR"):
            carry_out = None

        data_out = data_stack
        if mnemonic == "PHP":
            data_out = data_stack + (("STATUS", context.m, context.x, carry_in),)
        else:
            push_counts = {
                "PHA": 1 if context.m else 2, "PHX": 1 if context.x else 2,
                "PHY": 1 if context.x else 2, "PHB": 1, "PHK": 1, "PHD": 2,
                "PEA": 2, "PEI": 2, "PER": 2,
            }
            pull_counts = {
                "PLA": 1 if context.m else 2, "PLX": 1 if context.x else 2,
                "PLY": 1 if context.x else 2, "PLB": 1, "PLD": 2,
            }
            if mnemonic in push_counts:
                # Unknown base-stack data is irrelevant until a PHP creates a
                # status-restoration theorem.  Track byte depth only above a
                # live saved-status token, keeping this proof state finite and
                # outside the runtime context identity.
                if any(token[0] == "STATUS" for token in data_stack):
                    data_out = data_stack + tuple(("DATA", 0, 0, None) for _ in range(push_counts[mnemonic]))
            elif mnemonic in pull_counts:
                count = pull_counts[mnemonic]
                if not any(token[0] == "STATUS" for token in data_stack):
                    data_out = data_stack
                elif len(data_stack) < count:
                    frontiers.add(Frontier(context, "STACK_PROVENANCE_EXHAUSTED",
                                           f"{mnemonic}:need={count};known={len(data_stack)}", "05C"))
                    continue
                data_out = data_stack[:-count]

        # Make the instruction's explicit stack effect the default propagated
        # value for all ordinary successors emitted below.
        active_data_stack = data_out

        if mnemonic in CONDITIONAL_BRANCHES:
            target = _target(context, fallthrough.pc + _signed(instruction.operand, 8))
            taken_carry, not_taken_carry = carry_out, carry_out
            if mnemonic == "BCC":
                taken_carry, not_taken_carry = 0, 1
            elif mnemonic == "BCS":
                taken_carry, not_taken_carry = 1, 0
            admit(context, "BRANCH_TAKEN", target, taken_carry)
            admit(context, "BRANCH_NOT_TAKEN", fallthrough, not_taken_carry)
        elif mnemonic in ("BRA", "BRL"):
            bits = 8 if mnemonic == "BRA" else 16
            admit(context, "BRANCH_ALWAYS", _target(context, fallthrough.pc + _signed(instruction.operand, bits)), carry_out)
        elif mnemonic in ("JMP", "JML"):
            if mode in INDIRECT_CONTROL_MODES:
                frontiers.add(Frontier(context, "INDIRECT_JUMP_TARGET", mode, "05C"))
            elif mode == "ABSL_JUMP":
                admit(context, "DIRECT_JUMP", _target(context, instruction.operand & 0xFFFF,
                                                        pbr=(instruction.operand >> 16) & 0xFF), carry_out)
            else:
                admit(context, "DIRECT_JUMP", _target(context, instruction.operand), carry_out)
        elif mnemonic in ("JSR", "JSL"):
            if mode == "ABS_X_IND":
                frontiers.add(Frontier(context, "INDIRECT_CALL_TARGET", mode, "05C"))
            else:
                target_bank = context.pbr if mnemonic == "JSR" else (instruction.operand >> 16) & 0xFF
                target = _target(context, instruction.operand & 0xFFFF, pbr=target_bank)
                if close_returns:
                    if any(frame[2] == target for frame in call_stack):
                        frontiers.add(Frontier(context, "RECURSIVE_CALL_FAMILY", target.key, "05C"))
                    else:
                        expected = "RTS" if mnemonic == "JSR" else "RTL"
                        admit(context, "DIRECT_CALL", target, carry_out,
                              call_stack + ((fallthrough, expected, target),))
                else:
                    admit(context, "DIRECT_CALL", target, carry_out)
            if not close_returns:
                frontiers.add(Frontier(context, "RETURN_CONTINUATION", fallthrough.key, "05C"))
        elif mnemonic in RETURNS:
            if close_returns and mnemonic in ("RTS", "RTL") and call_stack:
                continuation, expected, _ = call_stack[-1]
                if mnemonic == expected:
                    admit(context, "RETURN_PROVED", continuation, carry_out, call_stack[:-1])
                else:
                    frontiers.add(Frontier(context, "RETURN_CLASS_MISMATCH",
                                           f"expected={expected};actual={mnemonic}", "05C"))
            else:
                frontiers.add(Frontier(context, "RETURN_OR_REENTRY", mnemonic, "05C"))
        elif mnemonic in ("BRK", "COP"):
            vector = software_vectors[(mnemonic, context.e)]
            admit(context, f"{mnemonic}_VECTOR", _target(context, vector, pbr=0), carry_out)
        elif mnemonic == "WAI":
            frontiers.add(Frontier(context, "WAI_WAKE_REENTRY", "RESET/ABORT/NMI/IRQ", "05C"))
        elif mnemonic == "STP":
            frontiers.add(Frontier(context, "STP_RESET_ONLY", "RESET", "05C"))
        elif mnemonic == "XCE":
            if carry_in is None:
                frontiers.add(Frontier(context, "XCE_CARRY_PROVENANCE", fallthrough.key, "04C"))
            else:
                new_e = carry_in
                new_m = 1 if new_e else context.m
                new_x = 1 if new_e else context.x
                admit(context, "FALLTHROUGH_XCE_PROVED", _next(context, length, e=new_e, m=new_m, x=new_x), context.e)
        elif mnemonic == "PLP":
            if close_returns and data_stack and data_stack[-1][0] == "STATUS":
                _, saved_m, saved_x, saved_carry = data_stack[-1]
                if context.e:
                    saved_m = saved_x = 1
                admit(context, "FALLTHROUGH_PLP_PROVED",
                      _next(context, length, m=saved_m, x=saved_x), saved_carry,
                      data_stack=data_stack[:-1])
            else:
                frontiers.add(Frontier(context, "PULLED_STATUS_WIDTH", fallthrough.key, "05C"))
        elif mnemonic in ("REP", "SEP"):
            if context.e:
                admit(context, "FALLTHROUGH_STATUS", _next(context, length, e=1, m=1, x=1), carry_out)
            else:
                m, x = context.m, context.x
                if mnemonic == "REP":
                    m = 0 if instruction.operand & 0x20 else m
                    x = 0 if instruction.operand & 0x10 else x
                else:
                    m = 1 if instruction.operand & 0x20 else m
                    x = 1 if instruction.operand & 0x10 else x
                admit(context, "FALLTHROUGH_STATUS", _next(context, length, m=m, x=x), carry_out)
        elif mnemonic in ("MVN", "MVP"):
            admit(context, "BLOCK_MOVE_REPEAT", context, carry_out)
            admit(context, "BLOCK_MOVE_COMPLETE", fallthrough, carry_out)
        else:
            admit(context, "FALLTHROUGH", fallthrough, carry_out)

    contexts = tuple(sorted(raw_by_context))
    return Discovery(
        contexts, raw_by_context, mnemonic_by_context, mode_by_context,
        tuple(sorted(edges, key=lambda row: (row.source, row.kind, row.target))),
        tuple(sorted(frontiers, key=lambda row: (row.source, row.kind, row.detail, row.owner))),
        {context: tuple(sorted(origins[context])) for context in sorted(origins) if context in raw_by_context},
        {context: tuple("UNKNOWN" if value is None else str(value)
                        for value in sorted(carry_facts[context], key=lambda value: -1 if value is None else value))
         for context in sorted(carry_facts) if context in raw_by_context},
    )


def byte_conflicts(discovery: Discovery) -> tuple[tuple[int, tuple[str, ...]], ...]:
    owners: dict[int, dict[int, set[str]]] = defaultdict(lambda: defaultdict(set))
    for context in discovery.contexts:
        start = cpu_to_rom_offset(context.pbr, context.pc)
        for offset in range(start, start + len(discovery.raw_by_context[context])):
            owners[offset][start].add(context.key)
    return tuple(
        (offset, tuple(sorted(context for starts in values.values() for context in starts)))
        for offset, values in sorted(owners.items()) if len(values) > 1
    )

