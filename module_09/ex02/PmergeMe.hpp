
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <list>
#include <deque>
#include <iostream>
#include <ctime>

class PmergeMe
{
    public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);

    void    theMerge(int argc, char **argv);
    void    sortMergeDeque(std::deque<int>& input);
    void    sortMergeList(std::list<int>& input);
    template <typename T>
    void displaySequence(const T& container){
        typename T::const_iterator itr;
        for (itr = container.begin(); itr != container.end(); itr++)
            std::cout << *itr << " ";
        std::cout << std::endl;
    }
};



#endif