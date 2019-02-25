#include <iostream>

struct Complex {
	double im;
	double re;
};

template <typename T1, typename T2>
T1 Mul (T1 a, T2 b)
{
	return (a * b);
}
template <> double Mul<double, Complex>(double scalar, Complex comp)
{
	double mul;
	mul = scalar * ((comp.im) * (comp.im) + (comp.re) * (comp.re));
	return mul;
}

template <> Complex Mul<Complex, double>(Complex comp, double scalar)
{
	Complex mul {};
	mul.im = scalar * comp.im;
	mul.re = scalar * comp.re;
	return mul;
}

template <> Complex Mul<Complex, Complex>(Complex comp1, Complex comp2)
{
	Complex mul {};
	mul.im = comp1.re * comp2.im + comp1.im * comp2.re;
	mul.re = comp1.re * comp2.re - comp1.im * comp2.im; 
	return mul;
}

int main ()
{
	Complex a,b {};
	a.im = 10;
	b.im = 15;
	a.re = 3;
	b.re = 2;
	double n = 3.14;

	int i = 12;
	int j = 5;
	float e = 3.14;

	std::cout << "int * float = " << Mul(i, e) << std::endl;
	std::cout << "float * int = " << Mul(e, j) << std::endl;


	std::cout << "With Complex:" << std::endl;
	std::cout << "C C = " << Mul(a, b).re << " + i * ("<< Mul(a, b).im << ")" << std::endl;
	std::cout << "C d = " << Mul(a, n).re << " + i * ("<< Mul(a, n).im << ")" << std::endl;
	std::cout << "d C = " << Mul(n, b) << std::endl;

	return 0;
}