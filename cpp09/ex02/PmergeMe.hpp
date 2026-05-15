#pragma once

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();

	void sort(int argc, char** argv);

private:
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

	std::vector<int> _vec;
	std::deque<int>  _deq;

	// vector pipeline
	void sortVector();
	void insertionSortVector(std::vector<int>& main, std::vector<int>& pend);
	int  binarySearchVector(const std::vector<int>& main, int val, int size) const;

	// deque pipeline
	void sortDeque();
	void insertionSortDeque(std::deque<int>& main, std::deque<int>& pend);
	int  binarySearchDeque(const std::deque<int>& main, int val, int size) const;

	// shared
	std::vector<int> jacobsthal(int n) const;
	void             parseInput(int argc, char** argv);
	void             printSequence(const std::string& label, const std::vector<int>& seq) const;
};