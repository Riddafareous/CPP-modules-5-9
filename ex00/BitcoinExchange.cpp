
#include <fstream>
#include <iostream>
#include "BitcoinExchange.hpp"

static std::string& strTrim(std::string& str){
    std::string whitespace = " \t\n\r";

    str.erase(str.find_last_not_of(whitespace) + 1);
    str.erase(0, str.find_last_not_of(whitespace));
    return (str);
}

Btc::Btc() {
    int i = 0;
    this->_flag = 1;
    std::ifstream file("./data.csv");
    if (file.is_open() == false){
        this->_flag = 0;
        return;
    }
    std::string line;
    while(std::getline(file, line)){
        if (i == 0){
            i = 1;
            continue;
        }
        size_t pos = line.find(',');
        if (pos == std::string::npos){
            std::cerr << "Error: Invalid Parameter" << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        double value;
        try
        {
            value = std::stod(line.substr(pos + 1));
        } catch (std::exception &e) {
            (void)e;
            std::cerr << "Error: unreadable value" << std::endl;
            continue;
        }
        this->setData(date, value);
    }
    file.close();
}

Btc::Btc(const Btc& other){
    *this = other;
}

Btc::~Btc() {}

Btc& Btc::operator=(const Btc& other){
    this->_data = other._data;
    return (*this);
}

void Btc::setData(std::string date, float value){
    this->_data.insert(std::make_pair(date, value));
}

std::map<std::string, float> Btc::getData(){
    return (this->_data);
}

std::vector<std::string> Btc::splitString(std::string str, char del){
    std::vector<std::string> substrings;
    std::string substr = "";
    for (size_t i = 0; i < str.length(); i++){
        if (str[i] != del){
            substr += str[i];
        }
        else{
            substrings.push_back(substr);
            while (str[i] == del && str[i + 1] == del)
                i++;
            substr = "";
        }
    }
    substrings.push_back(substr);
    return (substrings);
}

void Btc::readInput(std::string inputPath){
    int i = 0;
    std::ifstream newFile(inputPath);
    if (newFile.is_open() == false){
        this->_flag = -1;
        return;
    }
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(newFile, line)){
        if (i == 0){
            i = 1;
            continue;
        }
        lines = this->splitString(line, '|');
        if (lines[1].length() == 0 || lines.size() < 2){
            std::cout << "Error: Invalid input: " << lines[0] << std::endl;
            continue; 
        }
        std::map<std::string, float>::iterator itr = this->_data.upper_bound((lines[0]));

        if (itr != this->_data.end()){
            std::pair<std::string, float> p = *(itr);
            try
            {
                if (std::stod(lines[1]) > 1000)
                    std::cout << "Error: number too large" << std::endl;
                else if (std::stod(lines[1]) < 0)
                    std::cout << "Error: negative number" << std::endl;
                else
                    std::cout << lines[0] << " -> " << lines[1] << " = " << std::stod(lines[1]) * p.second << std::endl;
            } catch (const std::exception &e) {
                (void)e;
                std::cout << "Error: Input not a number" << std::endl;
                continue;
            }
        }
    }
    newFile.close();
}