# CPP01 — Memory, Pointers, and References

CPP01 is where C++'s two ways of indirectly referring to an object — pointers and references — get pulled apart and examined, alongside the two lifetimes an object can have: the stack and the heap.

## EX00–EX01 — Zombies: Stack vs Heap

### What it does

Creates `Zombie` objects three different ways: on the stack (`newZombie`-less local variable), on the heap with `new` (`newZombie`), and via a function that returns a stack-allocated zombie by value (`randomChump`). EX01 extends this to a *horde* of zombies allocated in a single block.

### Core concept: `new` / `delete` and object lifetime

- A **stack-allocated** object (`Zombie z("Bob")`) is destroyed automatically when it goes out of scope — its destructor runs without any explicit action.
- A **heap-allocated** object (`Zombie* z = new Zombie("Bob")`) lives until `delete z` is called explicitly. Forgetting to call `delete` is a memory leak — the object's memory is never reclaimed.
- `randomChump` returns a `Zombie` **by value** from a function, which is deliberately contrasted with `newZombie`, which returns a `Zombie*`. This distinction — "who owns this object, and who's responsible for freeing it?" — is the running theme of the whole exercise.

### The horde (`zombieHorde`)

Allocating an *array* of heap objects with `new Zombie[n]` requires the matching `delete[]` (not `delete`) to free it correctly — using the wrong form of `delete` on an array is undefined behavior. This is the first place array-form `new`/`delete` shows up.

## EX02–EX03 — References and Pointers

### What it does

EX02 walks through the difference between printing a value directly, through a pointer, and through a reference. EX03 (`HumanA`, `HumanB`, `Weapon`) builds a small scenario where a `Weapon` is held by two different `Human` classes — one that stores it as a reference, one that stores it as a pointer.

### Core concept: pointer vs reference

| | Pointer | Reference |
|---|---|---|
| Can be reassigned to refer elsewhere | Yes | No — bound once, forever |
| Can be null | Yes | No — must refer to a valid object |
| Needs dereferencing to access the object | Yes (`*ptr`, `ptr->`) | No — used exactly like the original object |
| Must be initialized at declaration | No | Yes |

`HumanA` takes its `Weapon` as a reference in its constructor, meaning it must be given a valid weapon at construction and can never be reassigned to a different one afterward. `HumanB` takes a `Weapon*`, meaning it can be constructed without a weapon (`NULL`) and have one assigned later with `setWeapon`. Neither is "more correct" — the choice communicates intent: a reference says "this always has one," a pointer says "this might not have one yet, or might change."

## EX04 — File to File

### What it does

Reads a file, replaces every occurrence of one string with another, and writes the result to a new file, given the filenames and strings as command-line arguments.

### Core concepts

- **File streams** (`std::ifstream`, `std::ofstream`) as the C++ replacement for C's `FILE*`/`fopen`/`fclose`, with RAII-style cleanup (the file closes automatically when the stream object goes out of scope).
- **String searching and replacement** using `std::string::find` and substring operations, reinforcing that `std::string` — not manual `char*` buffers — is the default tool for text manipulation in C++.

## EX05–EX06 — Harl: Switch and Function Pointers

### What it does

`Harl` is a class with one method per complaint level (`DEBUG`, `INFO`, `WARNING`, `ERROR`, and an `UNKNOWN` catch-all). Given a level as a string, it should print that level's message and every level *above* it in severity.

### Core concept: `switch` vs an array of member function pointers

EX05 typically implements this with a `switch` statement dispatching on an `enum Level`, falling through each case to print every subsequent level's message.

EX06 replaces that dispatch with an **array of pointers to member functions**:

```cpp
void (Harl::*funcs[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
(this->*funcs[level])();
```

This is the first appearance of member function pointers, which have unusual syntax (`&Harl::debug` to take the address, `this->*funcs[i]` to call through it) precisely because a member function needs an object (`this`) to be called on — it isn't a free-standing address the way a plain function pointer is. Structuring the dispatch this way avoids `switch`/`if` fallthrough logic entirely and makes adding a new level a matter of extending the array.
