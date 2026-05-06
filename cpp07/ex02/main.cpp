#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    // --- Default constructor ---
    std::cout << "=== Default constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;

    // --- Constructor with size (default initialization) ---
    std::cout << "\n=== Constructor with size ===" << std::endl;
    Array<int> ints(5);
    std::cout << "ints.size() = " << ints.size() << std::endl;
    for (unsigned int i = 0; i < ints.size(); i++)
        std::cout << "ints[" << i << "] = " << ints[i] << std::endl;

    // --- Fill and access ---
    std::cout << "\n=== Fill and access ===" << std::endl;
    for (unsigned int i = 0; i < ints.size(); i++)
        ints[i] = i * 10;
    for (unsigned int i = 0; i < ints.size(); i++)
        std::cout << "ints[" << i << "] = " << ints[i] << std::endl;

    // --- Copy constructor - modifying copy doesn't affect original ---
    std::cout << "\n=== Copy constructor ===" << std::endl;
    Array<int> copy(ints);
    copy[0] = 999;
    std::cout << "After setting copy[0] = 999:" << std::endl;
    std::cout << "ints[0] = " << ints[0] << " (should be 0)" << std::endl;
    std::cout << "copy[0] = " << copy[0] << " (should be 999)" << std::endl;

    // --- Assignment operator - modifying original doesn't affect copy ---
    std::cout << "\n=== Assignment operator ===" << std::endl;
    Array<int> assigned;
    assigned = ints;
    ints[1] = 888;
    std::cout << "After setting ints[1] = 888:" << std::endl;
    std::cout << "ints[1]     = " << ints[1]     << " (should be 888)" << std::endl;
    std::cout << "assigned[1] = " << assigned[1] << " (should be 10)"  << std::endl;

    // --- Out of bounds exception ---
    std::cout << "\n=== Out of bounds ===" << std::endl;
    try
    {
        std::cout << ints[100] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    // --- Works with other types ---
    std::cout << "\n=== std::string array ===" << std::endl;
    Array<std::string> words(3);
    words[0] = "hello";
    words[1] = "world";
    words[2] = "templates";
    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << "words[" << i << "] = " << words[i] << std::endl;

    // --- const array access ---
    std::cout << "\n=== const array ===" << std::endl;
    const Array<int> constArr(ints);
    std::cout << "constArr[0] = " << constArr[0] << std::endl;
    try
    {
        std::cout << constArr[999] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}