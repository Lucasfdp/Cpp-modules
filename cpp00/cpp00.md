# CPP00 — Getting Comfortable with C++

CPP00 is the transition point from C to C++: the same low-level control, but with classes, streams, and stricter typing layered on top. The three exercises each isolate one piece of that transition.

## EX00 — Megaphone

### What it does

Takes command-line arguments (or, if none are given, reads from standard input) and prints them back in uppercase.

### Core concepts

- **`<iostream>` streams**: `std::cout` replaces `printf`, and this exercise is the first place `std::cin`/`getline` shows up as the idiomatic way to read input, instead of C's `scanf`/`fgets`.
- **`std::string`**: arguments and input lines are handled as `std::string` rather than raw `char*`, which removes manual buffer-size management and null-terminator bookkeeping.
- **Character transformation**: converting to uppercase touches on the `<cctype>` style helpers (`toupper`), applied character by character across a string.

This exercise has no classes yet — it exists purely to get comfortable with C++'s I/O idioms before object-oriented syntax is introduced.

## EX01 — PhoneBook

### What it does

A command-line phonebook that can add up to 8 contacts and search/display them, built from two classes: `Contact` (the data) and `PhoneBook` (the storage and interaction logic).

### Core concepts

- **Class basics**: separating the *data holder* (`Contact` — first name, last name, nickname, phone number, darkest secret) from the *manager* (`PhoneBook` — a fixed-size array of contacts, an add/search interface).
- **Encapsulation**: `Contact`'s fields are accessed through the class's own methods rather than manipulated directly from `main`, establishing the private-data-plus-public-interface pattern that the rest of the modules build on.
- **Fixed-size internal storage**: `PhoneBook` overwrites the oldest entry once 8 contacts are reached (a circular-buffer-like behavior), which is a deliberate constraint of the exercise rather than a real-world design choice — it exists to force explicit index management before the STL containers (introduced much later, in CPP08–09) take that job over.
- **Formatted display**: contact rows are printed in fixed-width columns and truncated with a `.` when they overflow the column width, which is a first practical use of `<iomanip>` (`std::setw`).

## EX02 — Account (static members)

### What it does

Implements a `Account` class representing a bank account, where the class as a whole tracks aggregate statistics — total number of accounts, total amount across all accounts, number of deposits, number of withdrawals — in addition to each individual account's own balance.

### Core concept: `static` members

This is the exercise's central idea: some data belongs to the *class itself*, not to any one instance.

```cpp
static int getNbAccounts(void);
static int getTotalAmount(void);
```

A `static` member variable has exactly one copy shared by every instance of the class, updated automatically whenever any account is created, deposited into, or withdrawn from. A `static` member *function* can be called without an instance (`Account::getNbAccounts()`) and can only access other static members — it has no `this`, because it isn't tied to any particular object.

### Why this matters

This is the first time the module distinguishes **per-object state** (an individual account's balance) from **per-class state** (how many accounts exist in total). That distinction — and the discipline of updating shared counters correctly inside constructors and mutating methods — is the same pattern later used for things like tracking total HP across a monster hierarchy or counting live objects for leak-checking.

### Supporting concepts

- **Member initializer lists**: `Account`'s constructor initializes its fields directly rather than assigning to them in the body, which matters more once `const` members show up in later modules.
- **`const` member functions**: methods that only report status (`checkAmount`, `displayStatus`) are marked `const`, documenting that they don't modify the account — the first hint of the const-correctness discipline that becomes strict later on.
