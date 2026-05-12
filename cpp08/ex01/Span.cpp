#include "Span.hpp"

Span::Span(unsigned int n) : _max(n) {}

Span::Span(const Span &other) : _max(other._max), _data(other._data) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other) {
        _max  = other._max;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (_data.size() >= _max)
        throw std::overflow_error("Span is full: cannot add more numbers");
    _data.push_back(n);
}

int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::logic_error("Not enough numbers to compute a span");

    std::vector<int> sorted(_data);
    std::sort(sorted.begin(), sorted.end());

    int shortest = INT_MAX;
    for (std::size_t i = 1; i < sorted.size(); ++i)
    {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::logic_error("Not enough numbers to compute a span");

    int minVal = *std::min_element(_data.begin(), _data.end());
    int maxVal = *std::max_element(_data.begin(), _data.end());
    return maxVal - minVal;
}
