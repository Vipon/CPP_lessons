#include <cstdio>


struct complex {
	double re;
	double im;
};

template <typename T>
T Sum(T &a, T &b)
{
	return (a + b);
}

template <typename T>
T Mul(T &a, T &b)
{
	return (a * b);
}

template <typename T>
T Div(T &a, T &b)
{
	return (a / b);
}

template <> complex Sum<complex>(complex &a, complex &b)
{
	complex ans = {};

	ans.re = a.re + b.re;
	ans.im = a.im + b.im;

	return ans;
}

template <> complex Mul<complex>(complex &a, complex &b)
{
	complex ans = {};

	ans.re = (a.re * b.re) - (a.im * b.im);
	ans.im = (a.re * b.im) + (a.im * b.re);

	return ans;
}

template <> complex Div<complex>(complex &a, complex &b)
{
	complex ans = {};

	ans.re = ((a.re * b.re) + (a.im * b.im)) / ((b.re * b.re) + (b.im * b.im));
	ans.im = ((b.re * a.im) - (a.re * b.im)) / ((b.re * b.re) + (b.im * b.im));

	return ans;
}



int main()
{
	int ai = 0, bi = 1, si, mi, di;
	double ad = 10.0, bd = 11.0, sd, md, dd;
	complex c1 = {11, 13};
	complex c2 = {17, 19};
	complex sc = {};
	complex mc = {};
	complex dc = {};


	printf("ai = %d, bi = %d\n", ai, bi);
	si = Sum(ai, bi);
	mi = Mul(ai, bi);
	di = Div(ai, bi);
	printf("ci = %d \t mi = %d \t di = %d\n", si, mi, di);

	printf("ad = %lf, bd = %lf\n", ad, bd);
	sd = Sum(ad, bd);
	md = Mul(ad, bd);
	dd = Div(ad, bd);
	printf("cd = %lf \t mlf = %lf \t dd = %lf\n", sd, md, dd);

	sc = Sum(c1, c2);
	mc = Mul(c1, c2);
	dc = Div(c1, c2);
	printf("sc = %f + i * %f\tmc = %f + i * %f\tdc = %f + i * %f\t\n", sc.re, sc.im, mc.re, mc.im, dc.re, dc.im);

	return 0;
}