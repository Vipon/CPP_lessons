#include "Array.h"
#include <iostream>

int main()
{
    Array <int, 10> A;
    std::cin >> A;
    std::cout << A;
    std::cin >> A[3];
    auto it = A.begin();
    for (int i = 0; i < 3; ++i){
        ++it;
    }
    std::cout << *it;
    return 0;
}
