#include <cstdio>


struct Complex {
	double Re;
	double Im;
};


template <typename T0, typename T1>
auto Mul (T0 &a, T1 &b)
{
	return (a * b);
}


template <> auto Mul<double, Complex>(double &scalar, Complex &comp)
{
	Complex res = {};
	res.Re = comp.Re * scalar;
	res.Im = comp.Im * scalar;
	return res;
}


template <> auto Mul<Complex, double>(Complex &comp, double &scalar)
{
	Complex res = {};
	res.Re = comp.Re * scalar;
	res.Im = comp.Im * scalar;
	return res;
}


template <> auto Mul<Complex, Complex>(Complex &a, Complex &b)
{
	Complex res = {};
	res.Re = (a.Re * b.Re) - (a.Im * b.Im);
	res.Im = (a.Re * b.Im) + (b.Re * a.Im);
	return res;
}


int main()
{
	int num = 5;
	int num2 = 3;
	double sc = 5;
	sc = Mul(num, sc);
	printf("Mul int * double = %f\n", sc);
	num2 = Mul(num, num2);
	printf("Mul int * int = %d\n", num2);
	Complex c = {10, 10};
	Complex d = {2, 2};
	Complex res_comp = {};
	res_comp = Mul(c, d);
	printf("Mul Complex * Complex: Re = %f, Im = %f\n", res_comp.Re, res_comp.Im);
	printf("Complex: Re = %f, Im = %f; scalar = %f\n", c.Re, c.Im, sc);
	res_comp = Mul(c, sc);
	printf("Mul Complex * scalar: Re = %f, Im = %f\n", res_comp.Re, res_comp.Im);
	res_comp = Mul(sc, c);
	printf("Mul scalar * Complex: Re = %f, Im = %f\n", res_comp.Re, res_comp.Im);
	return 0;
}