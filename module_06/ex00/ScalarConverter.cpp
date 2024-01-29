
#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    return (*this);
}

ScalarConverter::~ScalarConverter(void){}


void ScalarConverter::converter(const std::string& var){
    const char *str = var.c_str();
    double val = atof(str);
    if (val > 31 && val < 127)
        std::cout << "Char: " << static_cast<char>(val) << std::endl;
    else
        std::cout << "Char not displayable" << std::endl;
    std::cout << "Int: " << static_cast<int>(val) << std::endl;
    std::cout << "Float: " << static_cast<float>(val) << std::endl;
    std::cout << "Double: " << val << std::endl;
}