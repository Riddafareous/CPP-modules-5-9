
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv){
    if (argc != 2){
        std::cerr << "Error: No File" << std::endl;
        return (-1);
    }

    Btc btc;
    btc.readInput(argv[1]);
}