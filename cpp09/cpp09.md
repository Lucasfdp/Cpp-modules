# CPP09 — STL in Practice

CPP09 pulls together everything learned about the STL and applies it to three self-contained, algorithm-heavy programs. Each exercise is chosen to highlight a container or algorithmic idea that the STL is particularly good at expressing cleanly.

## EX00 — Bitcoin Exchange

### What it does

Reads a CSV database of Bitcoin exchange rates indexed by date, then reads a second input file of `date | value` lines. For each line, it multiplies the value by the exchange rate on that date and prints the result. If the exact date isn't in the database, it uses the closest date *before* it — never a later one.

### Container: `std::map<std::string, double>`

A map is the natural fit here because it:

- stores key/value pairs and keeps keys sorted automatically,
- gives logarithmic-time lookup,
- and — critically — because dates are stored as `YYYY-MM-DD` strings, plain lexicographical string comparison already matches chronological order (`"2011-01-04" > "2011-01-03"`). No custom date-comparison object is needed.

### The key algorithm: `lower_bound`

```cpp
std::map<std::string, double>::const_iterator it = _db.lower_bound(date);
```

`lower_bound` returns an iterator to the first element **>=** the given key. That gives three cases to handle:

1. **Exact match** — use `it->second` directly.
2. **No exact match** — step back one element (`--it`) to get the closest *lower* date.
3. **Date before the database's earliest entry** — `lower_bound` returns `begin()`, which cannot be decremented (doing so is undefined behavior), so this case has to be detected and handled before attempting `--it`.

### Parsing and validation

Each input line is split on `|`, trimmed, and validated in two independent steps:

- **Date validation**: correct length and `-` placement, digits only, month in 1–12, day in a sane range (the implementation doesn't attempt full leap-year-aware validation, which is a reasonable, explicitly-scoped simplification).
- **Value validation**: must be numeric, must be positive, and must not exceed 1000 — with distinct error messages for "not a positive number" and "too large a number."

`atoi`/`atof` are avoided in favor of manual, checked parsing, since they can't distinguish a genuinely invalid string from a valid `0`.

## EX01 — Reverse Polish Notation

### What it does

Evaluates an RPN expression such as `"8 9 * 9 -"`, where operands are single digits and the supported operators are `+ - * /`, evaluated with no operator precedence or parentheses.

### Container: `std::stack<double>`

RPN evaluation is inherently a LIFO process, which makes `std::stack` a direct match rather than a workaround:

```
tokens: 8 9 *
push 8
push 9
pop 9, pop 8
compute 8 * 9
push result
```

### Algorithm

For each token:

- if it's a number, push it;
- if it's an operator, pop the top two values (`b` then `a`), compute `a OP b`, and push the result.

Order matters because subtraction and division aren't commutative — popping gives the operands in reverse order, so the calculation must be `a OP b`, not `b OP a`.

### Error handling

The implementation rejects malformed expressions explicitly: invalid tokens, not enough operands for an operator (e.g. `"1 +"`), division by zero (e.g. `"1 0 /"`), and leftover operands at the end (e.g. `"1 2 3 +"` — a valid expression must reduce to exactly one value on the stack).

Internally, `std::stack` defaults to a `std::deque` as its underlying container, giving O(1) push/pop/top.

## EX02 — PmergeMe (Ford-Johnson Merge-Insertion Sort)

### What it does

Implements the Ford-Johnson (merge-insertion) sort algorithm on a sequence of positive integers, using **two different containers** so their performance can be compared, and demonstrates it can handle a few thousand elements.

Containers used: `std::vector<int>` and `std::deque<int>`.

### The Ford-Johnson idea

The algorithm minimizes the number of comparisons needed to fully sort a sequence by:

1. pairing up elements,
2. sorting within each pair,
3. sending the larger of each pair ("winners") into a *main chain*,
4. sending the smaller of each pair ("losers") into a *pending chain*,
5. sorting the main chain,
6. and inserting the pending elements back into the main chain one at a time, using **binary search**, in an order controlled by the **Jacobsthal sequence** (`0, 1, 1, 3, 5, 11, 21, ...`), which is chosen specifically because it minimizes the total number of comparisons needed across all insertions.
7. Any leftover unpaired element ("straggler," when the input count is odd) is handled separately at the end.

### Implementation notes

The main chain itself is sorted with `std::sort` rather than a fully recursive merge-insertion step — a deliberate, documented simplification. The rest of the pipeline (pairing, winner/loser separation, Jacobsthal-ordered insertion, binary search) follows the Ford-Johnson structure faithfully.

### Why vector vs deque

- **`std::vector`** stores elements contiguously, which is cache-friendly and generally faster for iteration and random access in practice.
- **`std::deque`** uses segmented memory with efficient insertion at both ends, giving a genuinely different performance profile to compare against.
- Binary search for insertion position is O(log n) either way, but the actual insertion (shifting elements) is O(n) for both containers — the *pattern* of memory access is what differs, which is exactly what the timing comparison (measured with `clock()`, converted to microseconds) is meant to reveal.

## Recurring STL Concepts Across This Module

- **`std::map`** is implemented internally as a balanced binary search tree (typically red-black), giving ordered iteration and O(log n) lookup/insertion.
- **`std::vector`** gives O(1) random access thanks to contiguous storage.
- **`std::stack`** is a container *adaptor* — it doesn't implement its own storage, it wraps another container (`std::deque` by default) and restricts the interface to LIFO operations.
- Choosing the right container is a trade-off between memory layout, the operations actually needed, and the complexity guarantees that matter for the problem at hand.
