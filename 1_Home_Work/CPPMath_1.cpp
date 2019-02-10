#include <cstdio>


struct Complex {
	double Re;
	double Im;
};


template <typename T>

T Sum(T &a, T &b) 
{
	return (a + b);
}


template <> Complex Sum<Complex>(Complex &a, Complex &b)
{
	Complex res = {};
	res.Re = a.Re + b.Re;
	res.Im = a.Im + b.Im;
	return res;
}


template <typename T>

T Sub(T &a, T &b) 
{
	return (a - b);
}


template <> Complex Sub<Complex>(Complex &a, Complex &b)
{
	Complex res = {};
	res.Re = a.Re - b.Re;
	res.Im = a.Im - b.Im;
	return res;
}


template <typename T>

T Mul(T &a, T &b) 
{
	return (a * b);
}


template <> Complex Mul<Complex>(Complex &a, Complex &b)
{
	Complex res = {};
	res.Re = (a.Re * b.Re) - (a.Im * b.Im);
	res.Im = (a.Re * b.Im) + (b.Re * a.Im);
	return res;
}


template <typename T>

T Div(T &a, T &b) 
{
	return (a / b);
}


template <> Complex Div<Complex>(Complex &a, Complex &b)
{
	Complex res = {};
	res.Re = ((a.Re * b.Re) + (a.Im * b.Im)) / ((b.Re * b.Re) + (b.Im * b.Im));
	res.Im = ((b.Re * a.Im) - (a.Re * b.Im)) / ((b.Re * b.Re) + (b.Im * b.Im));
	return res;
}


int main()
{
	int a = 27;
	int b = 7;
	int res = 0;
	printf("int\n");
	res = Sum(a, b);
	printf("Sum = %d\n", res);
	res = Sub(a, b);
	printf("Sub = %d\n", res);
	res = Mul(a, b);
	printf("Mul = %d\n", res);
	res = Div(a, b);
	printf("Div = %d\n", res);
	printf("Complex\n");
	Complex c = {10, 10};
	Complex d = {2, 2};
	Complex res_comp = {};
	res_comp = Sum(c, d);
	printf("Sum: Re = %f, Im = %f\n", res_comp.Re, res_comp.Im);
	res_comp = Sub(c, d);
	printf("Sub: Re = %f, Im = %f\n", res_comp.Re, res_comp.Im);
	res_comp = Mul(c, d);
	printf("Mul: Re = %f, Im = %f\n", res_comp.Re, res_comp.Im);
	res_comp = Div(c, d);
	printf("Div: Re = %f, Im = %f\n", res_comp.Re, res_comp.Im);
	return 0;
}