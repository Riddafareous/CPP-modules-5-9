
#include "easyfind.hpp"
#include <iostream>

int main(void)
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(22);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(10);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);

    try
    {
        std::cout << easyfind(vec, 7) << std::endl;
        std::cout << easyfind(vec, 22) << std::endl;
        std::cout << easyfind(vec, 78) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "not found" << std::endl;
    }
    
}