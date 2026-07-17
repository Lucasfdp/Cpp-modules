# CPP02 — Ad-hoc Polymorphism and Operator Overloading

CPP02 centers on one class, `Fixed`, built up across four exercises, that together demonstrate how to make a custom type behave like a built-in numeric type: constructible, comparable, printable, and arithmetic-capable through operator overloading.

## EX00 — The Orthodox Canonical Form

### What it does

Introduces `Fixed`, a fixed-point number class storing a value as a raw integer with a fixed number of fractional bits, and implements the four members every value-like C++98 class is expected to provide.

### Core concept: the Orthodox Canonical Form (OCF)

```cpp
Fixed();                          // default constructor
Fixed(const Fixed& other);        // copy constructor
Fixed& operator=(const Fixed& other); // copy assignment
~Fixed();                         // destructor
```

Any class that manages its own data (even something as simple as one `int`) should define these four explicitly rather than rely on the compiler-generated versions, so that copying and destruction behave predictably and are documented in the class's own interface. This form recurs in every class-based module from here on — `ClapTrap`, `Bureaucrat`, `AForm`, and so on all follow it.

### Fixed-point representation

Instead of storing a `float` directly, `Fixed` stores an `int` where the low 8 bits (`_fractBits = 8`) represent the fractional part. This is the same idea used in embedded systems and early graphics hardware that lacked floating-point units: a real-number value is represented as (rawInt) / 2^fractBits. Conversions to and from `int`/`float` (`toInt()`, `toFloat()`) do the necessary bit-shifting.

## EX01 — Fixed-Point Conversion Operators

### What it does

Adds constructors that build a `Fixed` from an `int` or a `float`, plus `toInt()`/`toFloat()` to go the other way, and overloads `<<` so a `Fixed` can be printed directly with `std::cout`.

### Core concept: converting constructors and stream operators

```cpp
Fixed(int num);
Fixed(float num);
std::ostream& operator<<(std::ostream& os, const Fixed& f);
```

Constructors that take a single argument act as *implicit conversions* unless marked `explicit` — a design point this module makes concrete by showing what it takes to make `Fixed x = 5;` and `std::cout << x;` both just work, the same way they would for a built-in type.

## EX02 — Comparison and Arithmetic Operators

### What it does

Extends `Fixed` with the full set of comparison operators (`>`, `<`, `>=`, `<=`, `==`, `!=`), arithmetic operators (`+`, `-`, `*`, `/`), pre/post increment and decrement, and static `min`/`max` helpers.

### Core concept: operator overloading

Each operator is a normal member function with special syntax:

```cpp
bool operator>(const Fixed& other) const;
Fixed operator+(const Fixed& other) const;
```

Two details matter here specifically:

- **Pre- vs post-increment** are distinguished purely by a dummy `int` parameter on the post-increment overload (`operator++(int)`), a C++ convention rather than a meaningful argument — and the two have different semantics: pre-increment returns the *new* value by reference, post-increment must save the *old* value and return it by copy, since the object it refers to has already changed.
- **`const`-correctness on overloads**: `min`/`max` are overloaded once for `Fixed&` and once for `const Fixed&`, so a `const Fixed` can still be passed to `min`/`max` without losing constness on the result — a pattern that shows up again anywhere a function needs to preserve the constness of its input.

## EX03 — BSP (Point-in-Triangle)

### What it does

Implements `bsp(Point a, Point b, Point c, Point point)`, which determines whether a given point lies inside the triangle formed by three other points, using `Fixed` for every coordinate instead of `float`/`double`.

### Core concept: applying a custom numeric type to a real algorithm

The point-in-triangle test works by computing the signed area (via cross products) of three sub-triangles formed by the query point and each edge of the triangle, and checking that all three have the same sign. Doing this arithmetic entirely in `Fixed` — rather than falling back to native floating-point types — is the payoff of the previous three exercises: if the operator overloads were done correctly, an algorithm like this can be written exactly as it would be with `float`, with no special-casing for the custom type.

This is the practical argument for operator overloading in general: once a type supports `+`, `-`, `*`, and comparisons, existing algorithms written in terms of those operators work on it unchanged.
