
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>

struct Data
{
    std::string name;
    int social_credit;
};

class Serializer
{
    private:
    Serializer();
    Serializer(const Serializer& other);
    ~Serializer();
    Serializer& operator=(const Serializer& other);

    public:

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif