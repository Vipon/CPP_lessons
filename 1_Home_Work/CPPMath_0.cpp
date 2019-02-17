#include <cstdio>

template <typename T>
auto Sum(T& a, T& b)
{
	return a + b;
}

template <typename T>
auto Sub(T& a, T& b)
{
	return a - b;
}

template <typename T>
auto Mul(T& a, T& b)
{
	return a * b;
}

template <typename T>
auto Div(T& a, T& b)
{
	return a / b;
}

int main()
{
	int a = 151;
	int b = 34;

	printf("a + b = %d \n", Sum(a, b));
	printf("a - b = %d \n", Sub(a, b));
	printf("a * b = %d \n", Mul(a, b));
	printf("a / b = %d \n", Div(a, b));
	
	return 0;
}