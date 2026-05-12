#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <climits>

class Span
{
public:
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void        addNumber(int n);
    int         shortestSpan() const;
    int         longestSpan() const;

    // Range-based add
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        for (Iterator it = begin; it != end; ++it)
            addNumber(*it);
    }

private:
    unsigned int        _max;
    std::vector<int>    _data;

    Span(); // not allowed without size
};

#endif
