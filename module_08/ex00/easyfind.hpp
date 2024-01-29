
#ifndef EASYFINDER_HPP
# define EASYFINDER_HPP

#include <exception>
#include <vector>
#include <iterator>

template <typename T>
int easyfind(T& container, int i)
{
    for (typename T::iterator it = container.begin(); it != container.end(); it++){
        if (*it == i)
            return (*it);
    }
    throw std::exception();
}

#endif