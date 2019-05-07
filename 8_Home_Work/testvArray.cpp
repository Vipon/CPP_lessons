#include "vArray.h"

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
} catch;
    return 0;
}