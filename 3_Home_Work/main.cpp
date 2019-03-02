#include "Vector.h"
#include <iostream>


int main()
{
	double crd1[3] = {1, 2, 3};
	Vector a(static_cast<double *>(crd1), 3);
	Vector b(static_cast<double *>(crd1), 3);
	std::cout << a << '\n';
	a *= 5;
	std::cout << a << '\n';
	std::cin >> b;
	std::cout << b << '\n';
	a += b;
	std::cout << a << '\n';
	a += b;
	std::cout << a << '\n';
	a -= b;
	std::cout << a << '\n';
	return 0;
}