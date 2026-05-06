#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const& x)
{
    std::cout << x << "\n";
}

template <typename T>
void increment(T& x)
{
    ++x;
}

void printDoubled(double const& x)
{
    std::cout << x * 2 << "\n";
}

int main()
{
    // --- int array (non-const) ---
    int nums[] = {1, 2, 3, 4, 5};
    std::size_t numsLen = sizeof(nums) / sizeof(nums[0]);

    std::cout << "=== int array before increment ===" << std::endl;
    ::iter(nums, numsLen, print<int>);

    ::iter(nums, numsLen, increment<int>);

    std::cout << "=== int array after increment ===" << std::endl;
    ::iter(nums, numsLen, print<int>);

    // --- const int array ---
    const int consts[] = {10, 20, 30};
    std::size_t constsLen = sizeof(consts) / sizeof(consts[0]);

    std::cout << "=== const int array ===" << std::endl;
    ::iter(consts, constsLen, print<int>);

    // --- std::string array ---
    std::string words[] = {"hello", "world", "templates"};
    std::size_t wordsLen = sizeof(words) / sizeof(words[0]);

    std::cout << "=== string array ===" << std::endl;
    ::iter(words, wordsLen, print<std::string>);

    // --- plain function as third parameter ---
    std::cout << "=== doubles printed doubled ===" << std::endl;
    double doubles[] = {1.1, 2.2, 3.3};
    std::size_t doublesLen = sizeof(doubles) / sizeof(doubles[0]);
    ::iter(doubles, doublesLen, printDoubled);

    return 0;
}