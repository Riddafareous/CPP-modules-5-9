
#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "<One variable at a time, no more no less" << std::endl;
    else{
        std::string str(argv[1]);
        ScalarConverter::converter(str);
    }
    return (0);
}