#include <cstdio>


struct complex {
	double re, im;
};

template <typename T>
auto Sum(T &a, T &b)
{
	return (a + b);
}

template <typename T>
auto Mul(T &a, T &b)
{
	return (a * b);
}

template <typename T>
auto Div(T &a, T &b)
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
	int ai = 0, bi = 1;
	double ad = 10.0, bd = 11.0;
	complex c1 = {11, 13};
	complex c2 = {17, 19};


	printf("ai = %d, bi = %d\n", ai, bi);
	int si = Sum(&ai, &bi);
	int mi = Mul(&ai, &bi);
	int di = Div(&ai, &bi);
	printf("ci = %d \t mi = %d \t di = %d\n", si, mi, di);

	printf("ad = %lf, bd = %lf\n", ad, bd);
	double sd = Sum(&ad, &bd);
	double md = Mul(&ad, &bd);
	double dd = Div(&ad, &bd);
	printf("cd = %lf \t mlf = %lf \t dd = %lf\n", sd, md, dd);

	complex sc = Sum(c1, c2);
	complex mc = Mul(c1, c2);
	complex dc = Div(c1, c2);
	printf("sc = %f + i * %f\tmc = %f + i * %f\tdc = %f + i * %f\t\n", sc.re, sc.im, mc.re, mc.im, dc.re, dc.im);

	return 0;
}