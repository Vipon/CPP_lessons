#include <cstdio>

using namespace std;

struct Complex {
	double Re;
	double Im;
};

template <typename T0, typename T1>
auto Mul (T0 &a, T1 &b) {
	return (a * b);
}

template <> auto Mul<double, Complex> (double &scal, Complex &comp) {
	Complex ans = {};
	ans.Re = comp.Re * scal;
	ans.Im = comp.Im * scal;
	return ans;
}

template <> auto Mul<Complex, double> (Complex &comp, double &scalar) {
	Complex ans = {};
	ans.Re = comp.Re * scal;
	ans.Im = comp.Im * scal;
	return ans;
}

template <> auto Mul<Complex, Complex> (Complex &a, Complex &b) {
	Complex ans = {};
	ans.Re = (a.Re * b.Re) - (a.Im * b.Im);
	ans.Im = (a.Re * b.Im) + (b.Re * a.Im);
	return ans;
}


int main() {
	int a = 18;
	int b = 4;
	printf("It is int now\n");
	printf("Mul = %d\n", Mul(a, b));

	double scal = 5;
	Complex c = {12, 5};
	Complex d = {2, 3};
	Complex ans = {};
	ans = Mul(c, d);
	printf("Mul Complex * Complex: Re = %f, Im = %f\n", ans.Re, ans.Im);
	printf("Complex: Re = %f, Im = %f; scalar = %f\n", c.Re, c.Im, scal);
	ans = Mul(c, scal);
	printf("Mul Complex * scalar: Re = %f, Im = %f\n", ans.Re, ans.Im);
	ans = Mul(scal, c);
	printf("Mul scalar * Complex: Re = %f, Im = %f\n", ans.Re, ans.Im);
	return 0;
} 