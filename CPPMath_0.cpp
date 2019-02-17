#include <iostream>

template <typename T>
T Sum (const T a, const T b)
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
	int i = 12;
	int j = 5;
	float a = 3.14;
	float b = 2.0;

	std::cout << "int:" << std::endl;
	std::cout << "Sum = " << Sum (i, j) << std::endl;
	std::cout << "Sub = " << Sub (i, j) << std::endl;
	std::cout << "Mul = " << Mul (i, j) << std::endl;
	std::cout << "Div = " << Div (i, j) << std::endl;

	std::cout << "float:" << std::endl;
	std::cout << "Sum = " << Sum (a, b) << std::endl;
	std::cout << "Sub = " << Sub (a, b) << std::endl;
	std::cout << "Mul = " << Mul (a, b) << std::endl;
	std::cout << "Div = " << Div (a, b) << std::endl;

	return 0;

}
