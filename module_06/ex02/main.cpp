
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    for (int i = 0; i < 6; i++){
        Base *inst = generate();
        identify(inst);
        identify(*inst);
    }
}