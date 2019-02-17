#include <cstdio>

struct Complex {
	double Re;
	double Im;
};

template <typename T0, typename T1>
auto Mul(T0& a, T1& b)
{
	return a * b;
}

template <> auto Mul<double, Complex>(double &a, Complex &b)
{
	Complex res = {};
	res.Re = a * b.Re;
	res.Im = b.Im * a;
	return res;
}

template <> auto Mul<Complex, double>(Complex &a, double &b)
{
	Complex res = {};
	res.Re = a.Re * b;
	res.Im = b * a.Im;
	return res;
}

template <> auto Mul<Complex>(Complex &a, Complex &b)
{
	Complex res = {};
	res.Re = a.Re * b.Re - a.Im * b.Im;
	res.Im = a.Im * b.Re + b.Im * a.Re;
	return res;
}

int main()
{
	int a = 5;
	int b = 17;

	printf("a = %d ; b = %d \n", a, b);

	printf("a * b = %d \n", Mul(a, b));

	double scal = 7;
	Complex comp = { 5, -4 };

	printf("scal = %f ; comp = Re %f + Im %f \n", scal, comp.Re, comp.Im);

	printf("scal * comp = Re %f + Im %f \n", Mul(scal, comp).Re, Mul(scal, comp).Im);
	printf("comp * scal = Re %f + Im %f \n", Mul(comp, scal).Re, Mul(comp, scal).Im);
	printf("comp * comp = Re %f + Im %f \n", Mul(comp, comp).Re, Mul(comp, comp).Im);
	
	return 0;
}
