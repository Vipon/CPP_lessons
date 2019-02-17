#include <cstdio>

struct Complex {
	double Re;
	double Im;
};

template <typename T>
T Sum(T& a, T& b)
{
	return a + b;
}

template <> Complex Sum<Complex>(Complex &a, Complex &b)
{
	Complex res = {};
	res.Re = a.Re + b.Re;
	res.Im = a.Im + b.Im;
	return res;
}

template <typename T>
T Sub(T& a, T& b)
{
	return a - b;
}

template <> Complex Sub<Complex>(Complex &a, Complex &b)
{
	Complex res = {};
	res.Re = a.Re - b.Re;
	res.Im = a.Im - b.Im;
	return res;
}

template <typename T>
T Mul(T& a, T& b)
{
	return a * b;
}

template <> Complex Mul<Complex>(Complex &a, Complex &b)
{
	Complex res = {};
	res.Re = a.Re * b.Re - a.Im * b.Im;
	res.Im = a.Im * b.Re + b.Im * a.Re;
	return res;
}

template <typename T>
T Div(T& a, T& b)
{
	return a / b;
}

template <> Complex Div<Complex>(Complex &a, Complex &b)
{
	Complex res = {};
	res.Re = (a.Re * b.Re + a.Im * b.Im)/(b.Re*b.Re + a.Im*a.Im);
	res.Im = (a.Im * b.Re - b.Im * a.Re)/(b.Re*b.Re + a.Im*a.Im);
	return res;
}

int main()
{
	int a = 151;
	int b = 34;

	printf("a = %d ; b = %d \n", a, b);

	printf("a + b = %d \n", Sum(a, b));
	printf("a - b = %d \n", Sub(a, b));
	printf("a * b = %d \n", Mul(a, b));
	printf("a / b = %d \n", Div(a, b));

	Complex c = { 15, 3 };
	Complex d = { 15, -3 };

	printf("c = Re %f + Im %f ; d = Re %f + Im %f \n", c.Re, c.Im, d.Re, d.Im);

	printf("c + d = Re %f + Im %f \n", Sum(c, d).Re, Sum(c, d).Im);
	printf("c - d = Re %f + Im %f \n", Sub(c, d).Re, Sub(c, d).Im);
	printf("c * d = Re %f + Im %f \n", Mul(c, d).Re, Mul(c, d).Im);
	printf("c / d = Re %f + Im %f \n", Div(c, d).Re, Div(c, d).Im);

	return 0;
}