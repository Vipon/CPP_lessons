#include <cstdlib>
#include <cstring>
#include <cstdio>

template <typename T>
T Sum(T a, T b)
{
	return a + b;
}

template <typename T>
T Sub(T a, T b)
{
	return a - b;
}

template <typename T>
T Mul(T a, T b)
{
	return a*b;
}

template <typename T>
T Div(T a, T b)
{
	return a/b;
}

int main()
{
	int a = 12;
	int b = 3;
	printf("%d\n", Sum(a, b)); 
	printf("%d\n", Sub(a, b));
	printf("%d\n", Mul(a, b));
	printf("%d\n", Div(a, b));
	return 0;
}