#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
	// --- Subject example ---
	std::cout << "=== Subject example ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl; // 2
		std::cout << "Longest:  " << sp.longestSpan()  << std::endl; // 14
	}

	// --- Overflow exception ---
	std::cout << "\n=== Overflow exception ===" << std::endl;
	{
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		try {
			sp.addNumber(4);
		} catch (std::exception &e) {
			std::cerr << "Expected: " << e.what() << std::endl;
		}
	}

	// --- Too few elements ---
	std::cout << "\n=== Too few elements ===" << std::endl;
	{
		Span sp(1);
		sp.addNumber(42);
		try {
			sp.shortestSpan();
		} catch (std::exception &e) {
			std::cerr << "Expected: " << e.what() << std::endl;
		}
		try {
			sp.longestSpan();
		} catch (std::exception &e) {
			std::cerr << "Expected: " << e.what() << std::endl;
		}
	}

	// --- Large test with addRange ---
	std::cout << "\n=== 10,000 random numbers via addRange ===" << std::endl;
	{
		std::srand(42);
		const unsigned int N = 10000;
		Span sp(N);

		std::vector<int> src;
		src.reserve(N);
		for (unsigned int i = 0; i < N; ++i)
			src.push_back(std::rand());

		sp.addRange(src.begin(), src.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan()  << std::endl;
	}

	return 0;
}
