
#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span(unsigned int N) : _n(N) {
    _nums.reserve(N);
    std::cout << "constructor called" << std::endl;
}

Span::Span(const Span& other){
    *this = other;
}

Span& Span::operator=(const Span& other){
    if (this != &other){
        _nums = other._nums;
        _n = other._n;
    }
    return (*this);
}

Span::~Span(){}

void Span::addNumber(int num){
    if (_nums.size() < _n){
        _nums.push_back(num);
        std::cout << "added " << num << std::endl;
    }
    else
        throw std::exception();
}

unsigned int Span::shortestSpan(void){
    if (_nums.size() < 2)
        throw std::exception();
    std::vector<int> copy = _nums;
    std::sort(copy.begin(), copy.end());
    int res = copy[1] - copy[0];
    for (unsigned int i = 1; i < copy.size() - 1; i++){
        if (copy[i + 1] - copy[i] < res)
            res = copy[i + 1] - copy[i];
    }
    return (res);
}

unsigned int Span::longestSpan(void){
     if (_nums.size() < 2)
        throw std::exception();
    std::vector<int> copy = _nums;
    std::sort(copy.begin(), copy.end());
    return (copy[copy.size() - 1] - copy[0]);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    for (std::vector<int>::iterator itr = begin; itr != end; itr++)
        addNumber(*itr);
}

