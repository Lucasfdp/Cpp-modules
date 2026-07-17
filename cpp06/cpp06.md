# CPP06 — Type Conversion & Casts

CPP06 is about how C++ moves data between types safely and explicitly. It replaces the old, ambiguous C-style cast with four purpose-built operators, then applies that knowledge to two concrete problems: a generic scalar converter and a serialization/deserialization utility.

## EX00 — Scalar Converter

### The problem

Given a single string argument representing a `char`, an `int`, a `float`, or a `double` (including special values like `nan`, `+inf`, `-inf`), convert it to all four types and print the result of each conversion — or `impossible` / `non displayable` when a conversion doesn't make sense.

### Core concept: implicit vs explicit conversion

C++ performs many conversions implicitly (`int` → `double`, for instance), but converting between unrelated representations — a `char` to a `float`, a `double` to an `int` — requires explicit casts and careful bounds checking. This exercise forces you to reason about:

- **Range limits**: does the value fit in a `char` (0–127) or an `int` (`INT_MIN`–`INT_MAX`)?
- **Precision loss**: converting `float` → `int` truncates; converting `int` → `float` can lose precision for very large numbers.
- **Special floating-point values**: `nan`, `inf`, and `-inf` don't have a sensible integer or char representation at all.

### Static class design

`ScalarConverter` is implemented with a private constructor and only `static` members — it's a pure utility/namespace-like class. There's no reason to ever instantiate it, so instantiation is deliberately blocked. This is a common pattern for "toolbox" classes that just group related functions.

### Detecting the literal's type

The input is inspected as a string first:

- A single character that isn't a digit → `char` literal.
- Contains a `.` or is `nan`/`inf`/`-inf` with an `f` suffix → `float`.
- Contains a `.` without an `f` suffix, or is `nan`/`inf`/`-inf` → `double`.
- Otherwise, parses as an `int`.

Once the literal's "native" type is known, the value is converted to `double` internally and then displayed as each of the four target types using `static_cast`.

## EX01 — Serialization

### The problem

Convert a pointer to an integer-like value (`uintptr_t`) and back to the original pointer, proving that no data is lost in the round trip.

### Core concept: reinterpret_cast

This exercise exists specifically to demonstrate `reinterpret_cast` — the cast that treats a pointer's bit pattern as raw data rather than as a typed reference. `uintptr_t` (from `<cstdint>`) is guaranteed by the standard to be an integer type wide enough to hold a pointer without loss on the current platform, which makes it the correct vehicle for this exercise.

```cpp
uintptr_t serialize(Data* ptr);
Data*     deserialize(uintptr_t raw);
```

`serialize` reinterprets the pointer as an integer; `deserialize` reinterprets the integer back as a pointer. Because no bits are altered in between, `deserialize(serialize(ptr)) == ptr` always holds.

### Why not another cast?

- `static_cast` won't compile for pointer ↔ integer conversions of arbitrary width — it only allows conversions between related types.
- `const_cast` only changes const/volatile qualification.
- `dynamic_cast` requires polymorphic types and does runtime type checks — irrelevant here.

`reinterpret_cast` is the only tool designed for "treat these bits as something else."

## EX02 — Base / A / B Identification

### The problem

Given a `Base*` that actually points to a heap-allocated `A` or `B` (chosen at random at runtime), determine — using only the pointer/reference — which concrete type it really is.

### Core concept: dynamic_cast for runtime type identification

Because the real type is only known at runtime, `static_cast` cannot answer this safely — it would let you "cast" to the wrong type with no error, leading straight to undefined behavior the moment you dereference something invalid.

`dynamic_cast` requires the base class to be **polymorphic** (i.e., to declare at least one `virtual` function — a virtual destructor is enough). With that requirement satisfied, the two idiomatic checks are:

**Pointer form** — returns `NULL` on failure, so the check is trivial:

```cpp
if (A* a = dynamic_cast<A*>(base)) { /* it's an A */ }
else if (B* b = dynamic_cast<B*>(base)) { /* it's a B */ }
```

**Reference form** — there is no "null reference," so failure is signaled by throwing `std::bad_cast`, which must be caught:

```cpp
try {
    A& a = dynamic_cast<A&>(*base);
    // it's an A
} catch (std::bad_cast&) {
    // not an A
}
```

## The Four Casts, Compared

| Cast | Checked | When | Typical use |
|---|---|---|---|
| `static_cast` | Compile-time | Types are logically related | Numeric conversions, safe upcasting, known-safe downcasting |
| `dynamic_cast` | Runtime | Type is only known at runtime | Safe downcasting through a polymorphic hierarchy |
| `const_cast` | None | Only changes constness | Interfacing with poorly-const-annotated APIs |
| `reinterpret_cast` | None | Reinterpreting raw bits | Pointer ↔ integer, low-level/serialization tricks |

### Upcasting vs downcasting

- **Upcasting** (`Derived*` → `Base*`) is always safe — a derived object *is* a base object — and can be done implicitly or with `static_cast`.
- **Downcasting** (`Base*` → `Derived*`) is only safe when you actually know (or can verify) the real type, which is exactly what `dynamic_cast` verifies for you.

### Why C-style casts are avoided

`(int)value` or `(Derived*)basePtr` compiles to whichever of `static_cast`, `const_cast`, or `reinterpret_cast` happens to apply — silently, with no indication in the code of which one was actually used. Modern C++ prefers the explicit operators specifically so the *intent* of a conversion is visible at the call site, and so the compiler can catch mismatches that a C-style cast would silently paper over.
