#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	// --- vector ---
	std::cout << "=== std::vector ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(42);
	vec.push_back(7);
	vec.push_back(99);
	vec.push_back(3);

	try {
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "Found 42 at index "
				<< std::distance(vec.begin(), it) << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		easyfind(vec, 100);
	} catch (std::exception &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	// --- list ---
	std::cout << "\n=== std::list ===" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	try {
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		easyfind(lst, 999);
	} catch (std::exception &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	// --- deque ---
	std::cout << "\n=== std::deque ===" << std::endl;
	std::deque<int> dq;
	dq.push_back(5);
	dq.push_back(15);
	dq.push_back(25);

	try {
		std::deque<int>::iterator it = easyfind(dq, 5);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
