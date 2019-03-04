#include "Matrix.h"
#include <cstdlib>
#include <cstring>
#include <iostream> 

int main()
{
    uint16_t crd1[9] = { 1, 2, 3,
                         1, 2, 3,
                         1, 2, 3 };
    uint16_t crd2[9] = { 0, 0, 0,
                         1, 4, 6,
                         1, 3, 3 };
    Mat a(crd2, 9);
    Mat b(9);

    b = a;
    std::cout << b << '\n';
    std::cin >> b;
    std::cout << b << '\n';

    getchar(); getchar();
    return 0;
}