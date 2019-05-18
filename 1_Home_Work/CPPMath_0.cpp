#include <iostream>

template <typename T>
T Sum (const T *a, const T *b)
{
	return (a + b);
}

template <typename T>
T Sub (const T a, const T b)
{
	return (a - b);
}

template <typename T>
T Mul (const T a, const T b)
{
	return (a * b);
}

template <typename T>
T Div (const T a, const T b)
{
	return (a / b);
}

int main ()
{
	int q = 7;
	int w = 2;
	float e = 1.37;
	float r = 22.02;

	std::cout << "int:" << std::endl;
	std::cout << "Sum = " << Sum (q, w) << std::endl;
	std::cout << "Sub = " << Sub (q, w) << std::endl;
	std::cout << "Mul = " << Mul (q, w) << std::endl;
	std::cout << "Div = " << Div (q, w) << std::endl;

	std::cout << "float:" << std::endl;
	std::cout << "Sum = " << Sum (e, r) << std::endl;
	std::cout << "Sub = " << Sub (e, r) << std::endl;
	std::cout << "Mul = " << Mul (e, r) << std::endl;
	std::cout << "Div = " << Div (e, r) << std::endl;

	return 0;

}

