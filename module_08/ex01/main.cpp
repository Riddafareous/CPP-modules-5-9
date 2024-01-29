
#include "Span.hpp"
#include <iostream>

int main(void)
{
    try
    {
        Span sp = Span(20);
        sp.addNumber(9);
        sp.addNumber(2);
        sp.addNumber(34);
        sp.addNumber(-1);
        sp.addNumber(78);
        sp.addNumber(7);
        sp.addNumber(8);
        sp.addNumber(9);
        sp.addNumber(18);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::vector<int> vec;
        vec.push_back(19);
        vec.push_back(19896);
        vec.push_back(2);
        vec.push_back(6);
        vec.push_back(227);
        vec.push_back(98);
        vec.push_back(100);
        vec.push_back(34);
        vec.push_back(191);
        sp.addRange(vec.begin(), vec.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "except that " << e.what() << '\n';
    }
    return (0);
}