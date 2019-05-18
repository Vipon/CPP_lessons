#include <iostream>

struct Complex {
	float Im;
	float Re;
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
	return (a*b);
}

template <typename T>
T Div (T &a, T &b)
{
	return (a/b);
}

template <> Complex Sum<Complex> (Complex &a, Complex &b)
{
	Complex Sum {};
	Sum.Im = a.Im + b.Im;
	Sum.Re = a.Re + b.Re; 
	return Sum;
}

template <> Complex Sub<Complex> (Complex &a, Complex &b)
{
	Complex Sub {};
	Sub.Im = a.Im - b.Im;
	Sub.Re = a.Re - b.Re; 
	return Sub;
}
template <> Complex Mul<Complex> (Complex &a, Complex &b)
{
	Complex Mul {};
	Mul.Im = a.Re * b.Im + a.Im * b.Re;
	Mul.Re = a.Re * b.Re - a.Im * b.Im; 
	return Mul;
}
template <> Complex Div<Complex> (Complex &a, Complex &b)
{
	Complex Div {};
	Div.Im = (a.Im * b.Re - a.Re * b.Im) / (b.Re * b.Re + b.Im * b.Im);
	Div.Re = (a.Re * b.Re + a.Im * b.Im) / (b.Re * b.Re + b.Im * b.Im);
	return Div;
}


int main ()
{
	Complex a {};
	Complex b {};
	a.Im = 20;
	b.Im = 22;
	a.Re = 3;
	b.Re = 5;
	int c = 13;
	int d = 12;
	float n = 1.37;
	float m = 22.02;

	std::cout << "int:" << std::endl;
	std::cout << "Sum = " << Sum (c, d) << std::endl;
	std::cout << "Sub = " << Sub (c, d) << std::endl;
	std::cout << "Mul = " << Mul (c, d) << std::endl;
	std::cout << "Div = " << Div (c, d) << std::endl;

	std::cout << "float:" << std::endl;
	std::cout << "Sum = " << Sum (n, m) << std::endl;
	std::cout << "Sub = " << Sub (n, m) << std::endl;
	std::cout << "Mul = " << Mul (n, m) << std::endl;
	std::cout << "Div = " << Div (n, m) << std::endl;


	std::cout << "Complex:" << std::endl;
	std::cout << "Sum = " << Sum(a, b).Re << " + i * ("<< Sum(a, b).Im << ")" << std::endl;
	std::cout << "Sub = " << Sub(a, b).Re << " + i * ("<< Sub(a, b).Im << ")" << std::endl;
	std::cout << "Mul = " << Mul(a, b).Re << " + i * ("<< Mul(a, b).Im << ")" << std::endl;
	std::cout << "Div = " << Div(a, b).Re << " + i * ("<< Div(a, b).Im << ")" << std::endl;

	return 0;
}