#include "Varray.h"
#include <iostream>

int main()
{
    Varray <int> A(5);
    std::cin >> A;
    std::cout << A;
    std::cin >> A[3];
    auto it = A.begin();
    for (int i = 0; i < 3; ++i){
        ++it;
    }
    std::cout << *it << std::endl;
    A.relength(10);
    A[5] = 10;
    A[6] = 223;
    A[7] = 8282;
    A[8] = 8;
    A[9] = 93;
    std::cout << A;
    A.relength(7);
    std::cout << A;
    return 0;
}
