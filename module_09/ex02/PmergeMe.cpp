#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other){
    *this = other;
}

PmergeMe::~PmergeMe(){}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
    return (*this);
}

void    PmergeMe::theMerge(int argc, char **argv){
    std::list<int> sequenceL;
    std::deque<int> sequenceD;

    for (int i = 1; i < argc; i++){
        int value = atoi(argv[i]);
        if (value <= 0){
            std::cout << "Invalid input" << std::endl;
            return ;
        }
        sequenceL.push_back(value);
        sequenceD.push_back(value);
    }
    std::cout << "Before: ";
    displaySequence(sequenceL);
    std::cout << std::endl;

    clock_t startL = clock();
    sortMergeList(sequenceL);
    clock_t endL = clock();
    double timeL = static_cast<double>(endL - startL) / CLOCKS_PER_SEC * 1000;

    clock_t startD = clock();
    sortMergeDeque(sequenceD);
    clock_t endD = clock();
    double timeD = static_cast<double>(endD - startD) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    displaySequence(sequenceL);
    std::cout << std::endl;

    std::cout << "Time to process a range of " << sequenceL.size() << " elements with std::deque: " << timeD << "us" << std::endl;
    std::cout << "Time to process a range of " << sequenceL.size() << " elements with std::list: " << timeL << "us" << std::endl;



}

void    PmergeMe::sortMergeDeque(std::deque<int>& input){
    std::deque<int>::iterator itr1, itr2;
    for (itr1 = input.begin() + 1; itr1 != input.end(); ++itr1){
        int temp = *itr1;
        itr2 = itr1;
        while(itr2 != input.begin() && *(std::prev(itr2)) > temp){
            *itr2 = *(std::prev(itr2));
            itr2--;
        }
        *itr2 = temp;
    }
}

void    PmergeMe::sortMergeList(std::list<int>& input){
    std::list<int>::iterator itr1, itr2;
    for (itr1 = ++input.begin(); itr1 != input.end(); ++itr1){
        int temp = *itr1;
        itr2 = itr1;
        while(itr2 != input.begin() && *(std::prev(itr2)) > temp){
            *itr2 = *(std::prev(itr2));
            itr2--;
        }
        *itr2 = temp;
    }
}