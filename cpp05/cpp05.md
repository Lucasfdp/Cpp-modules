# CPP05 — Exceptions

CPP05 introduces exception handling as C++'s mechanism for reporting and reacting to error conditions, built around a small office-bureaucracy simulation: `Bureaucrat`s with grades, and `Form`s that require a signature and a matching grade to execute.

## EX00 — Bureaucrat and Grade Bounds

### What it does

A `Bureaucrat` has a name and a grade from 1 (highest) to 150 (lowest). Constructing one outside that range must fail cleanly rather than silently producing an invalid object.

### Core concept: exceptions instead of error codes or crashes

```cpp
class GradeTooHighException : public std::exception {
    const char* what() const throw();
};
```

Rather than returning a special error value or letting a constructor silently store an invalid grade, `Bureaucrat` throws a custom exception type — defined as a nested class deriving from `std::exception` — the moment an invalid grade is detected. Deriving from `std::exception` and overriding `what()` means the exception integrates with any code that catches the standard exception hierarchy, while still being specific enough (`GradeTooHighException` vs `GradeTooLowException`) for calling code to distinguish the failure if it wants to.

### Why a constructor needs to be able to fail

A constructor has no return value to signal failure with — throwing is the only way for a constructor to refuse to produce a half-formed object. Catching the exception at the call site (`try { Bureaucrat b(200); } catch (std::exception& e) { ... }`) is what makes it possible to keep the invalid object from ever existing at all.

## EX01 — Form: A Second Class, A Second Set of Rules

### What it does

Introduces `Form`, which has its own required grades — one to sign it, one to execute it — and its own pair of exceptions (`GradeTooHighException`/`GradeTooLowException`) distinct from `Bureaucrat`'s. A `Bureaucrat` can sign a `Form` only if their grade is high enough (numerically low enough); signing sets an internal `_signed` flag.

### Core concept: exceptions as part of a class's interface

Each class defines its own exceptions rather than sharing one generic error type, which makes `try`/`catch` blocks self-documenting about *what* failed and *where*: catching `Form::GradeTooLowException` versus `Bureaucrat::GradeTooLowException` tells you immediately which object's constraint was violated, even though the underlying idea (a grade being out of bounds) is the same in both classes.

## EX02 — Abstract Forms and Concrete Subtypes

### What it does

`Form` becomes `AForm`, an abstract base with a pure virtual `ex_action()`, and three concrete subclasses are introduced — `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm` — each with its own required grades and its own action performed on execution.

### Core concept: combining polymorphism with exceptions

```cpp
virtual void ex_action() const = 0;
void execute(const Bureaucrat& b) const; // checks _signed and grade, then calls ex_action()
```

`execute()` lives in `AForm` and is shared by every subclass: it checks that the form is signed and that the executing `Bureaucrat`'s grade is sufficient, throwing `NotSignedException` or a grade exception if not — and only calls the pure virtual `ex_action()` once those checks pass. This is the same base-class-defines-the-contract idea from CPP04's abstract classes, now applied specifically to guard a dangerous operation behind a validation step that every subclass gets for free, without duplicating the validation logic in each one.

## EX03 — Intern: A Simple Factory

### What it does

`Intern` has one job: given a form's name as a string and a target, produce the correct concrete `AForm` subclass — without the caller needing to know which concrete class exists for which name.

### Core concept: the factory pattern

```cpp
static AForm *makeShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }
// ... one such function per form type

AForm *Intern::makeForm(const std::string& type, const std::string& target)
{
    const std::string names[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    AForm *(*makers[3])(const std::string&) = { makeShrubbery, makeRobotomy, makePresidential };
    // match `type` against `names`, call the corresponding maker
}
```

Instead of a chain of `if (type == "...") return new X(...); else if (...) return new Y(...);`, the implementation pairs each form name with a small factory function and looks the match up in parallel arrays. This keeps `makeForm` itself free of type-specific logic — adding a new form type means adding one static function and one array entry, not editing a growing `if`/`else` chain. It also demonstrates function pointers used for dispatch, an idea first introduced in CPP01 with `Harl`'s member-function-pointer array, now applied to free functions.

### Tying it together

`Intern::makeForm` returns `AForm*`, so the object it hands back can be signed and executed through the same polymorphic interface as any other form — the caller never needs to know, or care, which of the three concrete types it actually received. This is the payoff of the whole module: exceptions handle "did something go wrong" at each stage (construction, signing, execution), while polymorphism handles "which concrete behavior actually runs," and the factory in `Intern` is what connects a plain string to the right concrete object in the first place.
