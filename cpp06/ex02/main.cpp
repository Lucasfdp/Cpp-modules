#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // ── Test generate + both identify overloads ───────────────────────────────
    for (int i = 0; i < 10; ++i)
    {
        Base* obj = generate();

        std::cout << "pointer identify:   ";
        identify(obj);

        std::cout << "reference identify: ";
        identify(*obj);

        std::cout << "---" << std::endl;

        delete obj;
    }

    // ── Manual tests with known types ─────────────────────────────────────────
    std::cout << "\n-- Manual tests --" << std::endl;

    A a;
    B b;
    C c;

    identify(&a); // A
    identify(&b); // B
    identify(&c); // C

    identify(a);  // A
    identify(b);  // B
    identify(c);  // C

    return 0;
}