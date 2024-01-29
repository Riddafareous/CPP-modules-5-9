
#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data data;
    Data* n_data;

    data.name = "Bobert";
    data.social_credit = 98;

    n_data = Serializer::deserialize(Serializer::serialize(&data));
    std::cout << "Name: " << n_data->name << " Credit: " << n_data->social_credit << std::endl;

    return (0);
}