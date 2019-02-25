#include "Matrix.h"
#include <array>
#include <iostream>

int main()
{
    Matrix <int,3> A, B, C;
    for (int i = 0; i < 9; ++i){
        A[{i / 3, i % 3}] = i * 2;
    }
    std::cout << A;
    std::cout << std::endl;

    B = A;
    B *= 3;
    std::cout << B;
    std::cout << std::endl;

    B -= A + A;
    std::cout << B;
    std::cout << std::endl;

    C = B + A;
    std::cout << C;
    std::cout << std::endl;

    C = B + (A * (-4));
    C = (A * (-4)) + B;
    std::cout << C;
    std::cout << std::endl;

    std::cout << A;
    std::cout << std::endl;

    std::array <int, 9> arr = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix <int, 3> E(arr);
    std::cout << E;
    std::cout << std::endl;

    A *= E;
    std::cout << A;
    std::cout << std::endl;

    B = A * (3 * E);
    std::cout << B;
    std::cout << std::endl;

    std::cin >> C;
    std::cout << C;
    return 0;
}
