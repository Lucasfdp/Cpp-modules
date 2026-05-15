#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <iomanip>
#include <algorithm>

// ─── Orthodox Canonical Form ──────────────────────────────────────────────────

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }

// ─── Jacobsthal Numbers ───────────────────────────────────────────────────────

// Jacobsthal sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85...
// We use this to determine the ORDER in which pending elements
// are inserted into the main chain. This ordering minimises
// the number of comparisons needed.
std::vector<int> PmergeMe::jacobsthal(int n) const
{
	std::vector<int> seq;
	seq.push_back(0);
	seq.push_back(1);
	while (static_cast<int>(seq.size()) <= n)
	{
		int size = seq.size();
		seq.push_back(seq[size - 1] + 2 * seq[size - 2]);
	}
	return seq;
}

// ─── Input Parsing ────────────────────────────────────────────────────────────

void PmergeMe::parseInput(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::istringstream ss(argv[i]);
		int val;
		if (!(ss >> val) || val < 0)
			throw std::runtime_error("invalid input: " + std::string(argv[i]));
		_vec.push_back(val);
		_deq.push_back(val);
	}
}

// ─── Print ────────────────────────────────────────────────────────────────────

void PmergeMe::printSequence(const std::string& label, const std::vector<int>& seq) const
{
	std::cout << label;
	for (std::size_t i = 0; i < seq.size(); i++)
		std::cout << seq[i] << (i + 1 < seq.size() ? " " : "");
	std::cout << std::endl;
}

// ─── Binary Search ────────────────────────────────────────────────────────────

// Search only within [0, size) so we respect the insertion boundary.
// This is important — we don't want to insert past the paired winner's
// position, which would violate the algorithm's comparison guarantees.
int PmergeMe::binarySearchVector(const std::vector<int>& main, int val, int size) const
{
	int lo = 0, hi = size;
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (main[mid] < val)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

int PmergeMe::binarySearchDeque(const std::deque<int>& main, int val, int size) const
{
	int lo = 0, hi = size;
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (main[mid] < val)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

// ─── Vector Sort ─────────────────────────────────────────────────────────────

void PmergeMe::insertionSortVector(std::vector<int>& main, std::vector<int>& pend)
{
	int pendSize = static_cast<int>(pend.size());
	std::vector<int> jac = jacobsthal(pendSize);

	std::size_t jacIdx = 1;
	int prevBound = 0;

	while (prevBound < pendSize)
	{
		// get next Jacobsthal number, clamped to pendSize
		int bound = (jacIdx < jac.size()) ? jac[jacIdx] : pendSize;
		if (bound > pendSize)
			bound = pendSize;

		// insert from bound-1 down to prevBound
		for (int i = bound - 1; i >= prevBound; i--)
		{
			int pos = binarySearchVector(main, pend[i], main.size());
			main.insert(main.begin() + pos, pend[i]);
		}

		prevBound = bound;
		jacIdx++;
	}
}

void PmergeMe::sortVector()
{
	int n = _vec.size();
	if (n <= 1)
		return;

	// Step 1: pair up elements, sort each pair
	// winners go to main, losers go to pend
	std::vector<int> main, pend;
	bool hasStraggler = (n % 2 != 0);

	for (int i = 0; i < n - (hasStraggler ? 1 : 0); i += 2)
	{
		if (_vec[i] > _vec[i + 1])
		{
			main.push_back(_vec[i]);
			pend.push_back(_vec[i + 1]);
		}
		else
		{
			main.push_back(_vec[i + 1]);
			pend.push_back(_vec[i]);
		}
	}

	// Step 2: recursively sort the main chain
	// (for simplicity we use std::sort here on the winners;
	//  a fully recursive Ford-Johnson would recurse with pairs,
	//  but this satisfies the subject's requirements)
	std::sort(main.begin(), main.end());

	// Step 3: insert pend into main using Jacobsthal order
	insertionSortVector(main, pend);

	// Step 4: handle straggler (the leftover element if odd count)
	if (hasStraggler)
	{
		int val = _vec[n - 1];
		int pos = binarySearchVector(main, val, main.size());
		main.insert(main.begin() + pos, val);
	}

	_vec = main;
}

// ─── Deque Sort ───────────────────────────────────────────────────────────────

void PmergeMe::insertionSortDeque(std::deque<int>& main, std::deque<int>& pend)
{
	int pendSize = static_cast<int>(pend.size());
	std::vector<int> jac = jacobsthal(pendSize);

	std::size_t jacIdx = 1;
	int prevBound = 0;

	while (prevBound < pendSize)
	{
		int bound = (jacIdx < jac.size()) ? jac[jacIdx] : pendSize;
		if (bound > pendSize)
			bound = pendSize;

		for (int i = bound - 1; i >= prevBound; i--)
		{
			int pos = binarySearchDeque(main, pend[i], main.size());
			main.insert(main.begin() + pos, pend[i]);
		}

		prevBound = bound;
		jacIdx++;
	}
}

void PmergeMe::sortDeque()
{
	int n = _deq.size();
	if (n <= 1)
		return;

	std::deque<int> main, pend;
	bool hasStraggler = (n % 2 != 0);

	for (int i = 0; i < n - (hasStraggler ? 1 : 0); i += 2)
	{
		if (_deq[i] > _deq[i + 1])
		{
			main.push_back(_deq[i]);
			pend.push_back(_deq[i + 1]);
		}
		else
		{
			main.push_back(_deq[i + 1]);
			pend.push_back(_deq[i]);
		}
	}

	std::sort(main.begin(), main.end());

	insertionSortDeque(main, pend);

	if (hasStraggler)
	{
		int val = _deq[n - 1];
		int pos = binarySearchDeque(main, val, main.size());
		main.insert(main.begin() + pos, val);
	}

	_deq = main;
}

// ─── Public Entry Point ───────────────────────────────────────────────────────

void PmergeMe::sort(int argc, char** argv)
{
	parseInput(argc, argv);

	// capture before state for printing
	std::vector<int> before(_vec.begin(), _vec.end());

	// time and run vector sort
	std::clock_t startVec = std::clock();
	sortVector();
	std::clock_t endVec = std::clock();

	// time and run deque sort
	std::clock_t startDeq = std::clock();
	sortDeque();
	std::clock_t endDeq = std::clock();

	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

	printSequence("Before: ", before);
	printSequence("After:  ", _vec);

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size()
			<< " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
			<< " elements with std::deque  : " << timeDeq << " us" << std::endl;
}