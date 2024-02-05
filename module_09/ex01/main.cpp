
#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2){
        std::cout << "Please provide desired expression as one string" << std::endl;
        return (-1);
    }
    
    std::string expression = argv[1];
    RPN rpn;
    rpn.calculate(expression);
    
    return (0);
}