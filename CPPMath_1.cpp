#include <iostream>

struct Complex {
	float im;
	float re;
};


template <typename T>
T Sum (T &a, T &b)
{
	return (a + b);
}

template <typename T>
T Sub (T &a, T &b)
{
	return (a - b);
}

template <typename T>
T Mul (T &a, T &b)
{
	return (a * b);
}

template <typename T>
T Div (T &a, T &b)
{
	return (a / b);
}

template <> Complex Sum<Complex> (Complex &a, Complex &b)
{
	Complex sum;
	sum.im = a.im + b.im;
	sum.re = a.re + b.re; 
	return sum;
}

template <> Complex Sub<Complex> (Complex &a, Complex &b)
{
	Complex sub;
	sub.im = a.im - b.im;
	sub.re = a.re - b.re; 
	return sub;
}
template <> Complex Mul<Complex> (Complex &a, Complex &b)
{
	Complex mul;
	mul.im = a.re * b.im + a.im * b.re;
	mul.re = a.re * b.re - a.im * b.im; 
	return mul;
}
template <> Complex Div<Complex> (Complex &a, Complex &b)
{
	Complex div;
	div.im = (a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im);
	div.re = (a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im);
	return div;
}


int main ()
{
	Complex a,b;
	a.im = 10;
	b.im = 15;
	a.re = 3;
	b.re = 2;
	int i = 12;
	int j = 5;
	float n = 3.14;
	float m = 2.0;

	std::cout << "int:" << std::endl;
	std::cout << "Sum = " << Sum (i, j) << std::endl;
	std::cout << "Sub = " << Sub (i, j) << std::endl;
	std::cout << "Mul = " << Mul (i, j) << std::endl;
	std::cout << "Div = " << Div (i, j) << std::endl;

	std::cout << "float:" << std::endl;
	std::cout << "Sum = " << Sum (n, m) << std::endl;
	std::cout << "Sub = " << Sub (n, m) << std::endl;
	std::cout << "Mul = " << Mul (n, m) << std::endl;
	std::cout << "Div = " << Div (n, m) << std::endl;


	std::cout << "Complex:" << std::endl;
	std::cout << "Sum = " << Sum(a, b).re << " + i * ("<< Sum(a, b).im << ")" << std::endl;
	std::cout << "Sub = " << Sub(a, b).re << " + i * ("<< Sub(a, b).im << ")" << std::endl;
	std::cout << "Mul = " << Mul(a, b).re << " + i * ("<< Mul(a, b).im << ")" << std::endl;
	std::cout << "Div = " << Div(a, b).re << " + i * ("<< Div(a, b).im << ")" << std::endl;

	return 0;
}
