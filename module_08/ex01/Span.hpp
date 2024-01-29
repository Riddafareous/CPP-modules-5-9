
#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <vector>

class Span
{
    private:
    std::vector<int> _nums;
    unsigned int _n;

    public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int num);
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);
};



#endif