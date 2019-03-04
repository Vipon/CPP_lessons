#include <cstdlib>
#include <cstring>
#include <cstdio>

struct Complex 
{
	float re;
	float im;
};

template <typename T1, typename T2>
auto Mul(T1 &a, T2 &b)
{
	return a*b;
}

template <> auto Mul<Complex, double>(Complex &comp, double &scalar)
{
	Complex MuL = {};
	MuL.re = scalar*comp.re;
	MuL.im = scalar*comp.im;
	return MuL;
}

template <> auto Mul<double, Complex>(double &scalar, Complex &comp)
{
	Complex MuL = {};
	MuL.re = scalar*comp.re;
	MuL.im = scalar*comp.im;
	return MuL;
}

template <> auto Mul<Complex, Complex>(Complex &a, Complex &b)
{
	Complex MuL = {};
	MuL.re = a.re*b.re - a.im*b.im;
	MuL.im = a.re*b.im + a.im*b.re;
	return MuL;
}

int main()
{
	double a = 3;
	int b = 12;
	Complex z = {1.7, 8.5};
	Complex w = {6.1, 4.9};
	Complex mul1 = Mul(z, w);
	Complex mul2 = Mul(z, a);
	Complex mul3 = Mul(a, z);
	printf("a*b: %f\n", Mul(a, b)); 
	printf("mul1.re: %f; mul1.im: %f;\n", mul1.re, mul1.im);
	printf("mul2.re: %f; mul2.im: %f;\n", mul2.re, mul2.im);
	printf("mul3.re: %f; mul3.im: %f;\n", mul3.re, mul3.im);
	return 0;
}
