#include "recursiveTemplate.h"
#include <iostream>

int main()
{
    recursiveTemplate<int> rT0(0);
    std::cout << rT0;

    recursiveTemplate<recursiveTemplate<int>> rT1(rT0);
    std::cout << rT1;

    recursiveTemplate<recursiveTemplate<recursiveTemplate<int>>> rT2(rT1);
    std::cout << rT2;

    recursiveTemplate<recursiveTemplate<recursiveTemplate<recursiveTemplate<int>>>> rT3(rT2);
    std::cout << rT3;
    return 0;
}
