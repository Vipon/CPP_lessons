#include "Matrix.h"
#include <vector>
#include <iostream>

int main()
{
    Matrix <int> A(3), B(3), C(3);
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

    std::vector <int> arr = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix <int> E(arr, 3);
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
