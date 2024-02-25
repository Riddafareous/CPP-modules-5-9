
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <vector>

class Btc
{
    private:
    std::map <std::string, float> _data;
    int _flag;

    public:
    Btc();
    Btc(const Btc& other);
    ~Btc();
    Btc& operator=(const Btc& other);

    void setData(std::string date, float value);
    void readInput(std::string path);

    std::map<std::string, float> getData();
    std::vector<std::string> splitString(std::string str, char del);
};



#endif