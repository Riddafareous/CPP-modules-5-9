
#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class RPN
{
    private:
    std::stack<double> _values;

    public:
    RPN();
    RPN(const RPN& other);
    ~RPN();
    RPN& operator=(const RPN& other);

    void calculate(std::string input);
};

#endif