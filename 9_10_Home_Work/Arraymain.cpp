#include "Array.h"
#include <algorithm>
#include <iostream>

int main()
{
    Array <int, 5> A;
    std::cin >> A;
    std::cout << A;
    std::reverse(A.begin(), A.end());
    std::cout << A << std::endl;
    std::sort(A.begin(), A.end());
    std::cout << A << std::endl;
    std::iter_swap(A.begin(), --A.end());
    std::cout << A << std::endl;
    return 0;
}
