#include <cstdio>


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

int main()
{
	int ai = 0, bi = 1, si, mi, di;
	double ad = 10.0, bd = 11.0, sd, md, dd;


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

	return 0;
}