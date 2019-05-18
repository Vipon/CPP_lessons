#include <iostream>

struct Complex {
	double iIm;
	double Re;
};

template <typename T1, typename T2>
T1 Mul (T1 *a, T2 *b)
{
	return (a * b);
}
template <> double Mul<double, Complex>(double a, Complex b)
{
	double Mul;
	Mul = a * ((b.Im) * (b.Im) + (b.Re) * (b.Re));
	return Mul;
}

template <> Complex Mul<Complex, double>(Complex a, double b)
{
	Complex Mul {};
	mul.Im = b * a.Im;
	mul.Re = b * a.Re;
	return Mul;
}

template <> Complex Mul<Complex, Complex>(Complex a, Complex b)
{
	Complex Mul {};
	Mul.Im = a.Re * b.Im + a.Im * b.Re;
	Mul.Re = a.Re * b.Re - a.Im * b.Im; 
	return Mul;
}

int main ()
{
	Complex a {};
	Complex b {};
	a.Im = 3;
	b.Im = 5;
	a.Re = 6;
	b.Re = 8;
	double l = 1.37;

	int c = 13;
	int d = 5;
	float e = 20.22;

	std::cout << "int * float = " << Mul(c, e) << std::endl;
	std::cout << "float * int = " << Mul(e, d) << std::endl;


	std::cout << "With Complex:" << std::endl;
	std::cout << "C C = " << Mul(a, b).Re << " + i * ("<< Mul(a, b).Im << ")" << std::endl;
	std::cout << "C d = " << Mul(a, l).Re << " + i * ("<< Mul(a, l).Im << ")" << std::endl;
	std::cout << "d C = " << Mul(l, b) << std::endl;

	return 0;
} 