#include "RPN.hpp"
#include <iostream>

RPN::RPN(){}

RPN::RPN(const RPN& other){
    *this = other;
}

RPN::~RPN(){}

RPN& RPN::operator=(const RPN& other){
    this->_values = other._values;
    return (*this);
}

void RPN::calculate(std::string input){
    for (size_t i = 0; i < input.size(); i++){
        
        char c = input[i];
        if (c == ' ')
            continue;
        else if (isdigit(c) == true)
            _values.push((int)(c - '0'));
        else if (c == '+' && _values.size() >= 2){
            double a = _values.top();
            _values.pop();
            double b = _values.top();
            _values.pop();
            _values.push(a + b);
        }
        else if (c == '-' && _values.size() >= 2){
            double a = _values.top();
            _values.pop();
            double b = _values.top();
            _values.pop();
            _values.push(b - a);
        }
        else if (c == '*' && _values.size() >= 2){
            double a = _values.top();
            _values.pop();
            double b = _values.top();
            _values.pop();
            _values.push(a * b);
        }
        else if (c == '/' && _values.size() >= 2){
            double a = _values.top();
            _values.pop();
            double b = _values.top();
            _values.pop();
            _values.push(b / a);
        }
        else{
            std::cout << "Invalid input" << std::endl;
            return ;
        }
    }

    if (_values.size() == 1){
        double res = _values.top();
        _values.pop();
        std::cout << "Result: " << res << std::endl;
    }
    else
        std::cout << "Invalid input" << std::endl;
}