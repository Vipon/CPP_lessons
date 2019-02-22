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
	int si = Sum(&ai, &bi);
	int mi = Mul(&ai, &bi);
	int di = Div(&ai, &bi);
	printf("ci = %d \t mi = %d \t di = %d\n", si, mi, di);

	printf("ad = %lf, bd = %lf\n", ad, bd);
	double sd = Sum(&ad, &bd);
	double md = Mul(&ad, &bd);
	double dd = Div(&ad, &bd);
	printf("cd = %lf \t mlf = %lf \t dd = %lf\n", sd, md, dd);

	return 0;
}