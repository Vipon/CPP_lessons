#include "vArray.h"
#include <iostream>
#include <cstddef>
#include <exception>

int main() {
try {
    vArray<int> a, b;
    std::cin >> a;
    std::cin >> b;

    std::cout << a << std::endl << b << std::endl;
    a += b;

    std::cout << a << std::endl;
    auto c = a + b;
    std::cout << c[1000];
} catch (std::exception error) {
    std::cout << error.what();
    exit (1);
};
    return 0;
}