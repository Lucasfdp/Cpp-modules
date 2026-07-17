# CPP07 — Templates

CPP07 introduces templates: writing code once that works across any type, checked and instantiated at compile time, as an alternative to the runtime polymorphism used in CPP04.

## EX00 — Function Templates

### What it does

Implements generic `swap`, `min`, and `max` functions that work on any comparable type.

### Core concept: function templates

```cpp
template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
```

Rather than writing `swap(int&, int&)`, `swap(std::string&, std::string&)`, and so on for every type that might need swapping, a template lets the compiler generate the correct version for whatever type `T` turns out to be, at the point it's actually called. This only compiles for types that support the operations the template body uses — `swap` needs a copy constructor and assignment, `min`/`max` need `operator<`/`operator>` — so a template is a contract enforced by the compiler at instantiation time rather than something checked at runtime.

This is a fundamentally different kind of polymorphism from CPP04's virtual functions: virtual dispatch picks behavior at *runtime* based on an object's actual type behind a shared base class; templates pick (generate) behavior at *compile time* based on whatever type is used at the call site, with no base class or inheritance relationship required at all.

## EX01 — `iter`: A Template Taking a Function

### What it does

```cpp
template <typename T, typename F>
void iter(T* array, const size_t len, F func)
```

Applies a given function `func` to every element of an array of arbitrary type `T`, for an arbitrary array length.

### Core concept: templates parameterized on more than one type

`iter` takes two independent template parameters: `T` (the element type) and `F` (the type of the callable applied to each element). `F` can be a plain function pointer, a function object, or (in later C++ standards) a lambda — the template doesn't care, as long as it can be called with one `T` argument. This is the same idea as the standard library's own algorithms (`std::for_each`, `std::transform`), which are themselves templates over both a container's element type and an arbitrary callable.

## EX02 — The `Array` Template Class

### What it does

A generic, fixed-size, bounds-checked array container: `Array<T>`, constructible with a given size, supporting `operator[]` (both mutable and `const`), `size()`, and following the Orthodox Canonical Form.

### Core concept: class templates

```cpp
template <typename T>
class Array
{
    T*           _data;
    unsigned int _size;
public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    T&       operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
};
```

Unlike a function template, a class template must have every member function defined in terms of the same template parameter `T`, and — because template code isn't compiled until it's instantiated for a specific type — the implementation typically lives in a separate `.tpp` file included at the bottom of the header, rather than in a normal `.cpp` file. This is why `Array.hpp` ends with `#include "Array.tpp"`: the compiler needs to see the full template definition, not just a declaration, everywhere `Array<T>` is used.

### Bounds checking

`operator[]` validates the index and throws `std::out_of_range` (from `<stdexcept>`) rather than allowing undefined behavior on an invalid access — the same exception-based safety net introduced conceptually in CPP05, now protecting a container instead of a business object.

### `const`-correctness across two overloads

Providing both `T& operator[](unsigned int)` and `const T& operator[](unsigned int) const` means `Array<T>` behaves correctly whether it's held by a mutable reference or a `const` one — a `const Array<T>&` can still read elements, just not modify them through the returned reference. This mirrors the `min`/`max` overload pattern from CPP02's `Fixed` class, applied here to indexing instead of comparison.

## Why Templates, After Polymorphism

Having just spent CPP03–CPP05 on inheritance-based polymorphism, CPP07 makes the contrast explicit: templates solve "the same logic, many types" without needing those types to share a common base class or any runtime type information at all. The cost is that template code is instantiated per type at compile time (so more generated code, and compiler errors that only appear once a template is actually used with a given type), while the benefit is zero runtime overhead and no requirement that unrelated types share an inheritance hierarchy just to be usable with the same function.
