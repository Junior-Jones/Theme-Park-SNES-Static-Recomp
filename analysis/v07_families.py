"""Procedure-family projection used by Theme Park 07C admission.

The projection deliberately does not follow a direct call into its callee and
does not follow an RTL/RTS edge back into a caller.  Instead a proved call is
connected to its finite, source-proved continuation.  This yields the exact
contexts owned by one procedure while retaining its internal branches.
"""
from __future__ import annotations

from collections import defaultdict, deque
from dataclasses import dataclass


@dataclass(frozen=True)
class ProcedureFamily:
    root: str
    contexts: tuple[str, ...]
    internal_edges: tuple[tuple[str, str, str], ...]
    call_sites: tuple[tuple[str, str], ...]
    return_relations: tuple[tuple[str, str, str], ...]


def _local_adjacency(
    edges: list[dict[str, str]], proofs: list[dict[str, str]]
) -> dict[str, set[str]]:
    adjacency: dict[str, set[str]] = defaultdict(set)
    for row in edges:
        if row["Kind"] not in ("DIRECT_CALL", "RETURN_PROVED"):
            adjacency[row["Source"]].add(row["Target"])
    # A call remains in its caller procedure by continuing only through the
    # exact return relation proved in 05C.  The callee is a separate family.
    for row in proofs:
        if row["Class"] == "RETURN_PROVED":
            adjacency[row["Producer"]].add(row["Target"])
    return adjacency


def derive_procedure_family(
    context_rows: list[dict[str, str]],
    edge_rows: list[dict[str, str]],
    proof_rows: list[dict[str, str]],
    root: str,
) -> ProcedureFamily:
    contexts = {row["Context"] for row in context_rows}
    if root not in contexts:
        raise ValueError(f"procedure root is not a proved exact context: {root}")
    adjacency = _local_adjacency(edge_rows, proof_rows)
    reached: set[str] = set()
    pending = deque((root,))
    while pending:
        context = pending.popleft()
        if context in reached:
            continue
        if context not in contexts:
            raise ValueError(f"procedure relation targets an unknown context: {context}")
        reached.add(context)
        pending.extend(sorted(adjacency.get(context, set()) - reached))

    internal_edges = sorted(
        (row["Source"], row["Kind"], row["Target"])
        for row in edge_rows
        if row["Source"] in reached
        and row["Target"] in reached
        and row["Kind"] not in ("DIRECT_CALL", "RETURN_PROVED")
    )
    direct_calls = {
        row["Producer"]: row["Target"]
        for row in proof_rows
        if row["Class"] == "DIRECT_CALL"
    }
    call_sites = sorted(
        (source, direct_calls[source]) for source in reached if source in direct_calls
    )
    returns = sorted(
        (row["Consumer"], row["Target"], row["Producer"])
        for row in proof_rows
        if row["Class"] == "RETURN_PROVED" and row["Callee_Entry"] == root
    )
    return ProcedureFamily(
        root=root,
        contexts=tuple(sorted(reached)),
        internal_edges=tuple(internal_edges),
        call_sites=tuple(call_sites),
        return_relations=tuple(returns),
    )
