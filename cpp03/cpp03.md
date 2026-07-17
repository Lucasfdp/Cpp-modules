# CPP03 — Inheritance

CPP03 introduces inheritance through a single running example — `ClapTrap` and its increasingly specialized subclasses — building up from a single class to a full diamond-shaped hierarchy.

## EX00 — ClapTrap

### What it does

A base class representing a robot with hit points, energy points, and attack damage, with `attack`, `takeDamage`, and `beRepaired` methods and a `showStatus` reporting method.

### Core concept: the foundation before subclassing

`ClapTrap` is written as a complete, independent class first — following the Orthodox Canonical Form established in CPP02 — with `attack` marked `virtual`. Marking it virtual here, before any subclass exists yet, is what makes overriding it later actually replace its behavior polymorphically rather than just shadow the name.

## EX01 — ScavTrap

### What it does

`ScavTrap` inherits from `ClapTrap`, with its own stats and its own `attack` message, plus a `guardGate` method unique to it.

### Core concept: single inheritance and constructor chaining

```cpp
class ScavTrap : public ClapTrap { ... };
```

The key discipline here is **construction/destruction order**: a derived class's constructor must initialize its base class first (explicitly, via the member-initializer list, or implicitly via the base's default constructor), and destructors run in the opposite order — most-derived first, then up through each base. Overriding `attack` while keeping `takeDamage`/`beRepaired` inherited unchanged demonstrates that inheritance is selective: a subclass only needs to override what's actually different.

## EX02 — FragTrap

### What it does

A second subclass of `ClapTrap`, siblings with `ScavTrap`, with its own stats and a unique `highFivesGuys` method.

### Core concept: multiple independent subclasses of one base

With two siblings now sharing a base, the exercise reinforces that inheritance models an *is-a* relationship in more than one direction from the same root — both `ScavTrap` and `FragTrap` *are* `ClapTrap`s, but are not related to each other. This sets up the actual point of the module, which arrives in EX03.

## EX03 — DiamondTrap and the Diamond Problem

### What it does

`DiamondTrap` inherits from **both** `ScavTrap` and `FragTrap` — which each, independently, inherit from `ClapTrap`. Without any special handling, this creates two separate `ClapTrap` sub-objects inside one `DiamondTrap`, which is both wasteful and ambiguous (which `ClapTrap`'s `_hitPoints` does `DiamondTrap` mean?).

```cpp
class ScavTrap : virtual public ClapTrap { ... };
class FragTrap : virtual public ClapTrap { ... };
class DiamondTrap : public ScavTrap, public FragTrap { ... };
```

### Core concept: virtual inheritance

Declaring the inheritance from `ClapTrap` as `virtual` in **both** `ScavTrap` and `FragTrap` tells the compiler to share a single `ClapTrap` sub-object between them, no matter how many paths lead to it. `DiamondTrap` ends up with exactly one `_hitPoints`, one `_energyPoints`, one `_attackDamage` — inherited once, unambiguously.

This has a real consequence for construction: with virtual inheritance, the *most-derived* class (`DiamondTrap`) becomes directly responsible for initializing the virtual base (`ClapTrap`), even though it doesn't inherit from it directly — `ScavTrap`'s and `FragTrap`'s own attempts to initialize `ClapTrap` are bypassed at construction time. This is precisely why the diamond problem is a genuine language-design issue, and why `virtual` inheritance exists as a distinct, deliberate opt-in rather than the default behavior for multiple inheritance.

### Resolving name collisions

`ScavTrap` and `FragTrap` both override `attack` (or provide their own versions of shared members), so `DiamondTrap` must explicitly decide which one to expose — commonly by overriding the method itself and choosing which parent's implementation to call (e.g. `FragTrap::attack(target)` for damage, but `ScavTrap`'s or `ClapTrap`'s `whoAmI` for identity, per the exercise's own rules). Left unresolved, calling an ambiguous inherited method is a compile error, not a runtime one — the compiler refuses to guess.

## Why This Progression Matters

Building the hierarchy incrementally — one base, then two independent single-inheritance subclasses, then a multiple-inheritance merge of those two — isolates each new idea:

1. EX00–EX01: what inheritance *is* (a subclass reuses and extends a base).
2. EX02: that inheritance can branch into independent subclasses.
3. EX03: what happens when those branches *rejoin*, and why C++ requires `virtual` inheritance to make that rejoining well-defined rather than duplicated or ambiguous.
