# CPP04 — Subtype Polymorphism, Abstract Classes, and Interfaces

CPP04 moves from "inheritance as code reuse" (CPP03) to inheritance as the mechanism for **polymorphism** — treating different concrete types uniformly through a shared base pointer or reference, and drawing a sharp line between classes meant to be instantiated and classes meant only to define a contract.

## EX00 — Animal, Dog, Cat: True Polymorphism

### What it does

`Animal` is a base class with a virtual `makeSound()`, and `Dog`/`Cat` each override it with their own sound. The exercise's payoff is creating an array of `Animal*` where some pointers actually point to `Dog`s and some to `Cat`s, and calling `makeSound()` on each through the base pointer.

### Core concept: virtual functions and dynamic dispatch

```cpp
class Animal {
public:
    virtual void makeSound() const;
};
```

Without `virtual`, calling `makeSound()` through an `Animal*` would always run `Animal`'s own version, regardless of what the pointer actually points to — this is called *static* (compile-time) binding. Marking it `virtual` switches to *dynamic* (runtime) binding: the actual object's type determines which override runs, decided through the object's vtable at the moment of the call. This single keyword is what makes `Animal* a = new Dog(); a->makeSound();` print the dog's sound rather than a generic one.

### `WrongAnimal`/`WrongCat`: the contrast case

The exercise deliberately includes a second, near-identical pair of classes where the sound-making method is **not** virtual, so the difference is directly observable: calling it through a `WrongAnimal*` that points to a `WrongCat` prints the wrong (base class) sound, demonstrating exactly what virtual dispatch fixes.

## EX01 — Deep Copy and the Brain

### What it does

Adds a `Brain` member (holding an array of ideas) to `Dog` and `Cat`, and requires that copying a `Dog` or `Cat` also copies its `Brain` — not just the pointer to it.

### Core concept: deep vs shallow copy

If `Dog`'s copy constructor simply copies a `Brain*` member as-is, two `Dog`s end up sharing one `Brain` — modifying one's ideas would silently change the other's, and destroying either one would leave the other holding a dangling pointer. The fix is a deep copy: `Dog`'s copy constructor and assignment operator explicitly `new` a fresh `Brain` and copy its contents, rather than copying the pointer.

This is the same lesson as the Orthodox Canonical Form in CPP02, applied to a class that now owns heap-allocated members: any class managing its own dynamic memory must define copy semantics explicitly, or risk exactly this kind of aliasing bug.

## EX02 — Abstract Classes

### What it does

`Animal` becomes `AAbstractAnimal`-style — `makeSound()` is declared **pure virtual**, so `Animal` itself can no longer be instantiated, only `Dog` and `Cat` can.

### Core concept: pure virtual functions

```cpp
virtual void makeSound() const = 0;
```

The `= 0` marks the function as having no implementation in this class, which makes the class **abstract**: `new Animal()` becomes a compile error. This is the language enforcing a design intent that was only a convention before — `Animal` was never meant to represent a real animal on its own, only to describe what any animal *must* be able to do. Every concrete subclass is now required to provide its own `makeSound()`, or it too remains abstract.

## EX03 — Interfaces, Composition, and the Materia System

### What it does

Builds a small "Final Fantasy"-style game system: `ICharacter` and `IMateriaSource` are pure interfaces, `AMateria` is an abstract base for spells/items, `Cure` and `Ice` are concrete materia, `Character` holds up to 4 materia in an inventory, and `MateriaSource` can create new instances of registered materia types on demand.

### Core concept: interfaces via pure abstract classes

`ICharacter` declares only pure virtual functions and has no data or implementation at all — this is C++'s way of expressing an "interface" (as opposed to `AMateria`, which is abstract but still provides shared implementation, like storing the `_type` string). The distinction matters: an interface says "any class that implements this can be used here," with zero shared code; an abstract base class says "here is some shared behavior, plus a contract for what subclasses must still fill in."

### Core concept: the prototype pattern (`clone()`)

```cpp
virtual AMateria* clone() const = 0;
```

Because materia objects are polymorphic (`AMateria*` might really be a `Cure` or an `Ice`), copying one correctly — say, when a `Character` equips a fresh instance of a type held by `MateriaSource` — can't be done with a plain copy constructor call, since the caller often only has a base pointer and doesn't know the concrete type. `clone()` solves this: each concrete class implements it to `new` a correctly-typed copy of itself, and callers can create correct copies through nothing but the base interface, without ever needing to know which concrete type they're holding.

### Composition alongside inheritance

`Character` doesn't inherit from `AMateria` — it *holds* an array of `AMateria*`. This is the module's clearest example of composition ("has-a") used deliberately alongside inheritance ("is-a"): a `Character` isn't a kind of materia, it *owns* materia, and ownership brings its own responsibility — `Character`'s destructor must delete each equipped materia, and `unequip` must hand ownership back cleanly rather than leaking or double-freeing.

## The Throughline

Each exercise removes one more piece of "you could get away with a shortcut here" from the previous one: EX00 shows why `virtual` matters, EX01 shows why copying needs to be explicit once heap ownership is involved, EX02 makes the "this class is only ever a contract" idea enforceable by the compiler, and EX03 combines interfaces, abstract classes, and composition into one system where each tool is used for the part of the design it actually fits.
