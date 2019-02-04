#include <cstdlib>
#include <cstring>

void cswapi(int *a, int *b)
{
	if (a == NULL || b == NULL)
		return;

	int t = 0;
	t = *a;
	*a = *b;
	*b = t;
}


void cswapd(double *a, double *b)
{
	if (a == NULL || b == NULL)
		return;

	double t = 0;
	t = *a;
	*a = *b;
	*b = t;
}


void cswap(void *a, void *b, size_t size)
{
	if (a == NULL || b == NULL)
		return;

	void *t = malloc(size);
	if (t == NULL)
		return;

	memcpy(t, a, size);
	memcpy(a, b, size);
	memcpy(b, t, size);

	free(t);
}

/*
void swap(int *a, int *b)
{
	if (a == NULL || b == NULL)
		return;

	int t = 0;
	t = *a;
	*a = *b;
	*b = t;
}


void swap(double *a, double *b)
{
	if (a == NULL || b == NULL)
		return;

	double t = 0;
	t = *a;
	*a = *b;
	*b = t;
} 
*/

//template <class T> // C++03
template <typename T> // C++11
void swapP(T *a, T *b)
{
	if (a == NULL || b == NULL)
		return;

	T t = *a;
	*a = *b;
	*b = t;
}

struct section {
	double start;
	double end;
};


template <> void swapP<section>(section *a, section *b)
{
	if (a == NULL || b == NULL)
		return;

	section t = {};
	t.start = a->start;
	t.end = a->end;
	a->start = b->start;
	a->end = b->end;
	b->start = t.start;
	b->end = t.end;
}


template <typename T> // C++11
void swap(T &a, T &b)
{
	if (&a == NULL || &b == NULL)
		return;

	T t = a;
	a = b;
	b = t;
}


template <typename T0, typename T1>
//auto Sum(T0 &a, T1 &b) -> decltype(a + b) // C++11
auto Sum(T0 &a, T1 &b) // C++14
{
	decltype(a + b) c = (a + b); // C++11
	return c; 
}


template <typename T0, typename T1>
//auto Sum(T0 &a, T1 &b) -> decltype(a + b) // C++11
auto Fib(T0 &val0, T0 &val1, T1 &num) // C++14
{
	if (num == 1)
		return val0 + val1;

	return Fib(val1, val0 + val1, --num);
}

#include <cstdio>

int main()
{
	int a = 0;
	int b = -1;
	int &c = a;

	printf("a = %d\t\t\tc = %d\n", a, c);
	printf("*a = %p\t*c = %p\n", &a, &c);
	a = 100;
	printf("a = %d\t\t\tc = %d\n", a, c);
	c = 1000;
	printf("a = %d\t\tc = %d\n", a, c);
	return 0;
}