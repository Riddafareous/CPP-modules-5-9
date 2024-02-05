#include "PmergeMe.hpp"

int main(int argc, char **argv){
    if (argc <= 2){
        std::cout << "Please provide sequence of positive integers" << std::endl;
        return (1);
    }

    PmergeMe merger;
    merger.theMerge(argc, argv);
    
    return (0);
}