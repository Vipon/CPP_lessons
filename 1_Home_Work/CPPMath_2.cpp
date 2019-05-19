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
template <> double Mul<double, Complex>(double a, Complex b)
{
	double mul;
	mul = a * ((b.im) * (b.im) + (b.re) * (b.re));
	return mul;
}

template <> Complex Mul<Complex, double>(Complex a, double b)
{
	Complex mul {};
	mul.im = b * a.im;
	mul.re = b * a.re;
	return mul;
}

template <> Complex Mul<Complex, Complex>(Complex a, Complex b)
{
	Complex mul {};
	mul.im = a.re * b.im + a.im * b.re;
	mul.re = a.re * b.re - a.im * b.im; 
	return mul;
}

int main ()
{
	Complex a {};
	Complex b {};
	a.im = 13;
	b.im = 15;
	a.re = 3;
	b.re = 5;
	double n = 1.37;

	int i = 17;
	int j = 5;
	float e = 1.28;

	std::cout << "int * float = " << Mul(i, e) << std::endl;
	std::cout << "float * int = " << Mul(e, j) << std::endl;


	std::cout << "With Complex:" << std::endl;
	std::cout << "complex*complex = " << Mul(a, b).re << " + i * ("<< Mul(a, b).im << ")" << std::endl;
	std::cout << "complex*double = " << Mul(a, n).re << " + i * ("<< Mul(a, n).im << ")" << std::endl;
	std::cout << "double*complex = " << Mul(n, b) << std::endl;

	return 0;
} 