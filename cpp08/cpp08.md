# CPP08 — STL Containers, Iterators, and Algorithms

CPP08 moves from writing generic containers by hand (CPP07's `Array`) to using and extending the STL's own containers and algorithms — the payoff of understanding templates: the standard library's containers are themselves templates, and now they're usable directly.

## EX00 — `easyfind`: Templates + Algorithms + Iterators

### What it does

```cpp
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return it;
}
```

Finds the first occurrence of an integer in any STL container that supports iteration, throwing if it isn't present.

### Core concepts

- **Genericity over container type**: `easyfind` is templated on `T` itself (the container type), not just the element type — so the exact same function works on a `std::vector<int>`, a `std::list<int>`, or a `std::deque<int>` without modification, as long as `T` exposes `begin()`, `end()`, and `T::iterator`.
- **`typename` disambiguation**: `typename T::iterator` is required because the compiler can't otherwise know whether `T::iterator` names a type or a value when `T` is a template parameter — this is one of the more subtle syntax rules templates introduce.
- **`std::find`**: rather than writing a manual loop, this exercise is the first direct use of a standard algorithm operating through iterators, which is the general STL pattern: algorithms don't know about specific containers, only about the iterator interface they expose.

## EX01 — Span: Containers, Ranges, and Iterator Templates

### What it does

`Span` stores up to `N` integers and computes the shortest and longest span (absolute difference) between any two of them, either added one at a time or from an iterator range.

### Core concepts

- **`std::vector<int>` as internal storage**, replacing a manually-managed array. `Span` gets dynamic growth, safe copying, and bounds-aware access for free by composing a `vector` rather than reimplementing its behavior.
- **A templated member function accepting any iterator range**:

```cpp
template <typename Iterator>
void addRange(Iterator begin, Iterator end)
{
    for (Iterator it = begin; it != end; ++it)
        addNumber(*it);
}
```

  This lets `Span` absorb a range from *any* source — another `Span`, a `std::list`, a plain array, a `std::vector` — without `Span` needing to know or care what container the range came from. This is the iterator abstraction doing its job: the algorithm (here, just appending) is written once, against the iterator interface, and works everywhere that interface is available.

- **`std::sort` + linear scan** for computing shortest/longest span: sorting first turns "find the closest pair" into "check adjacent elements," an O(n log n) approach that reuses a standard algorithm instead of writing a custom O(n²) comparison of every pair.

## EX02 — MutantStack: Extending an Adaptor

### What it does

`std::stack` deliberately hides its underlying container and exposes only `push`/`pop`/`top` — no iteration. `MutantStack` inherits from `std::stack` and adds iterator support, so a stack's contents can be inspected without popping them.

### Core concept: container adaptors and their protected internals

```cpp
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    typedef typename Container::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end();   }
    // ... const_iterator, reverse_iterator, const_reverse_iterator similarly
};
```

`std::stack` is a **container adaptor**, not a container itself — it doesn't store data directly, it wraps another container (by default `std::deque`) and restricts the interface to LIFO operations. Critically, that underlying container is stored as a `protected` member named `c`, which is exactly what makes this exercise possible: a class publicly inheriting from `std::stack` can reach into `this->c` and expose its `begin()`/`end()` directly, turning a deliberately restricted adaptor into a fully iterable one.

### Why this is a meaningful exercise, not just a trick

It demonstrates that the STL's "restricted interface" containers aren't sealed — their restrictions are a design choice enforced through access control (`protected`, not `private`), and inheritance is the sanctioned way to build a variant with a wider interface when that's genuinely what's needed, rather than reimplementing a stack from scratch.

## The Common Thread

All three exercises lean on the same idea from different angles: STL containers and algorithms are connected by the **iterator** interface, not by inheritance or by knowing each other's concrete types. `easyfind` writes one algorithm against any container's iterators; `Span::addRange` accepts iterators from any source; `MutantStack` exposes iterators that were there all along, just hidden behind `protected`. Understanding iterators as the seam between "generic algorithm" and "specific container" is the point of the whole module.
