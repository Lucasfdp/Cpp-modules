#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

// ---- helper: run the subject test with MutantStack ----
static void testMutantStack()
{
    std::cout << "=== MutantStack ===" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;   // 17
    mstack.pop();
    std::cout << mstack.size() << std::endl;  // 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it  = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // Verify it's also copyable into a plain std::stack
    std::stack<int> s(mstack);
    (void)s;
}

// ---- same logic but with std::list ----
static void testList()
{
    std::cout << "\n=== std::list (same logic) ===" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;      // 17
    lst.pop_back();
    std::cout << lst.size() << std::endl;      // 1
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator it  = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

// ---- extra: reverse iterators & const ----
static void testExtras()
{
    std::cout << "\n=== Reverse iterators ===" << std::endl;
    MutantStack<int> ms;
    ms.push(1); ms.push(2); ms.push(3); ms.push(4); ms.push(5);

    MutantStack<int>::reverse_iterator rit  = ms.rbegin();
    MutantStack<int>::reverse_iterator rite = ms.rend();
    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    std::cout << "\n=== Const iterators ===" << std::endl;
    const MutantStack<int> cms(ms);
    MutantStack<int>::const_iterator cit  = cms.begin();
    MutantStack<int>::const_iterator cite = cms.end();
    while (cit != cite)
    {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;
}

int main()
{
    testMutantStack();
    testList();
    testExtras();
    return 0;
}
