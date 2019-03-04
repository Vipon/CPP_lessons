#include <cstdint>
#include <iostream>
#include <cstdlib>

#include "matrix.h"

int main()
{
	int n = 7;

	matrix A(2,2);
	matrix B(2,2);
	matrix C(2,2);

	std::cin >> A;
	std::cin >> B;
	std::cin >> C;

	std::cout << A * n<< '\n';
	std::cout << A + B << '\n';
	std::cout << B * C << '\n';
	return 0;
}