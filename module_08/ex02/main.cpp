
#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "and now the og" << std::endl;

    std::list<int> mmstack;
    mmstack.push_back(5);
    mmstack.push_back(17);
    std::cout << mmstack.back() << std::endl;
    mmstack.pop_back();
    std::cout << mmstack.size() << std::endl;
    mmstack.push_back(3);
    mmstack.push_back(5);
    mmstack.push_back(737);
    mmstack.push_back(0);
    std::list<int>::iterator iit = mmstack.begin();
    std::list<int>::iterator iite = mmstack.end();
    ++iit;
    --iit;
    while (iit != iite)
    {
        std::cout << *iit << std::endl;
        ++iit;
    }
    return (0);
}