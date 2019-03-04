#include <cstdlib>
#include <cstring>
#include <cstdio>

struct Complex 
{
	float re;
	float im;
};

template <typename T>

T Sum(T &a, T &b) 
{
	return a + b;
}


template <> Complex Sum<Complex>(Complex &a, Complex &b)
{
	Complex SuM = {};
	SuM.re = a.re + b.re;
	SuM.im = a.im + b.im;
	return SuM;
}

template <typename T>
T Sub(T &a, T &b)
{
	return a - b;
}

template <> Complex Sub<Complex>(Complex &a, Complex &b)
{
	Complex SuB = {};
	SuB.re = a.re - b.re;
	SuB.im = a.im - b.im;
	return SuB;
}

template <typename T>
T Mul(T &a, T &b)
{
	return a*b;
}

template <> Complex Mul<Complex>(Complex &a, Complex &b)
{
	Complex MuL = {};
	MuL.re = a.re*b.re - a.im*b.im;
	MuL.im = a.re*b.im + a.im*b.re;
	return MuL;
}

template <typename T>
T Div(T &a, T &b)
{
	return a/b;
}

template <> Complex Div<Complex>(Complex &a, Complex &b)
{
	 Complex DiV = {};
	 DiV.re = (a.re*b.re + a.im*b.im)/(b.re*b.re + b.im*b.im);
	 DiV.im = (a.im*b.re - a.re*b.im)/(b.re*b.re + b.im*b.im);
	 return DiV;
}

int main()
{
	int a = 12;
	int b = 3;
	Complex z = {1.7, 8.5};
	Complex w = {6.1, 4.9};
	Complex sum = Sum(z,w);
	Complex sub = Sub(z,w);
	Complex mul = Mul(z,w);
	Complex div = Div(z,w);
	printf("a + b: %d;\n", Sum(a, b)); 
	printf("a - b: %d;\n", Sub(a, b)); 
	printf("a*b: %d;\n", Mul(a, b)); 
	printf("a/b: %d;\n", Div(a, b)); 
	printf("sum.re: %f; sum.im: %f;\n", sum.re, sum.im);
	printf("sub.re: %f; sub.im: %f;\n", sub.re, sub.im);
	printf("mul.re: %f; mul.im: %f;\n", mul.re, mul.im);
	printf("div.re: %f; div.im: %f;\n", div.re, div.im);
	return 0;
}
