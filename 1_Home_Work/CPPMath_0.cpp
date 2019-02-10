#include <cstdio>

template <typename T>

auto Sum(T &a, T &b) 
{
	return (a + b);
}


template <typename T>

auto Sub(T &a, T &b) 
{
	return (a - b);
}


template <typename T>

auto Mul(T &a, T &b) 
{
	return (a * b);
}


template <typename T>

auto Div(T &a, T &b) 
{
	return (a / b);
}


int main()
{
	int a = 27;
	int b = 7;
	int res = 0;
	res = Sum(a, b);
	printf("Sum = %d\n", res);
	res = Sub(a, b);
	printf("Sub = %d\n", res);
	res = Mul(a, b);
	printf("Mul = %d\n", res);
	res = Div(a, b);
	printf("Div = %d\n", res);
	return 0;
}