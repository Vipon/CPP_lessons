#include <cstdio>

struct complex {
	double re, im;
};

template <typename T0, typename T1>
auto Mul (T0 &a, T1 &b)
{
	return (a * b);
}

template <> auto Mul<int, complex>(int &scalar, complex &comp)
{
	complex ans ={};

	ans.re = comp.re * scalar;
	ans.im = comp.im * scalar;


	return ans;
}

template <> auto Mul<double, complex>(double &scalar, complex &comp)
{
	complex ans ={};

	ans.re = comp.re * scalar;
	ans.im = comp.im * scalar;


	return ans;
}


template <> auto Mul<complex, double>(complex &comp, double &scalar)
{
	complex ans ={};

	ans.re = comp.re * scalar;
	ans.im = comp.im * scalar;


	return ans;
}


template <> auto Mul<complex, complex>(complex &comp1, complex &comp2)
{
	complex ans ={};

	ans.re = (comp1.re * comp2.re) - (comp1.im * comp2.im);
	ans.im = (comp1.re * comp2.im) + (comp1.im * comp2.re);


	return ans;
}

int main()
{
	int a = 23;
	double b = 29;
	complex c = {11, 13};
	complex d = {17,19};

	double ab = Mul(a, b);
	complex ac = Mul(a, c);
	complex bc = Mul(b, c);
	complex cd = Mul(c, d);

	printf("ab = %f\n", ab);
	printf("ac = %f + i * %f\n", ac.re, ac.im);
	printf("bc = %f + i * %f\n", bc.re, bc.im);
	printf("cd = %f + i * %f\n", cd.re, cd.im);
}