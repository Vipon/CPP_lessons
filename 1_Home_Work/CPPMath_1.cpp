#include <cstdio>

using namespace std;

struct Complex {
	double Re;
	double Im;
};

template <typename T> //general template for every type
T Sum (T &a, T &b) {
	return (a + b);
}

template <> Complex Sum<Complex> (Complex &a, Complex &b) { //explicit specialization for complex
	Complex ans = {};
	ans.Re = a.Re + b.Re;
	ans.Im = a.Im + b.Im;
	return ans;
}

template <typename T>
T Sub (T &a, T &b) {
	return (a - b);
}

template <> Complex Sub<Complex> (Complex &a, Complex &b)
{
	Complex ans = {};
	ans.Re = a.Re - b.Re;
	ans.Im = a.Im - b.Im;
	return ans;
}

template <typename T>
T Mul (T &a, T &b) {
	return (a * b);
}

template <> Complex Mul<Complex> (Complex &a, Complex &b)
{
	Complex ans = {};
	ans.Re = (a.Re * b.Re) - (a.Im * b.Im);
	ans.Im = (a.Re * b.Im) + (b.Re * a.Im);
	return ans;
}


template <typename T>
T Div (T &a, T &b) {
	return (a / b);
}

template <> Complex Div<Complex> (Complex &a, Complex &b)
{
	Complex ans = {};
	ans.Re = ((a.Re * b.Re) + (a.Im * b.Im)) / ((b.Re * b.Re) + (b.Im * b.Im));
	ans.Im = ((b.Re * a.Im) - (a.Re * b.Im)) / ((b.Re * b.Re) + (b.Im * b.Im));
	return ans;
}


int main() {
	int a = 18;
	int b = 4;
	int ans = 0;
	printf("It is int now\n");
	printf("Sum = %d\n", Sum(a, b));
	printf("Sub = %d\n", Sub(a, b));
	printf("Mul = %d\n", Mul(a, b));
	printf("Div = %d\n", Div(a, b));

	printf("It is complex now\n");
	Complex c = {12, 5};
	Complex d = {2, 3};
	Complex ans_c = {};
	ans_c = Sum(c, d);
	printf("Sum: Re = %f, Im = %f\n", ans_c.Re, ans_c.Im);
	ans_c = Sub(c, d);
	printf("Sub: Re = %f, Im = %f\n", ans_c.Re, ans_c.Im);
	ans_c = Mul(c, d);
	printf("Mul: Re = %f, Im = %f\n", ans_c.Re, ans_c.Im);
	ans_c = Div(c, d);
	printf("Div: Re = %f, Im = %f\n", ans_c.Re, ans_c.Im);
	return 0;
} 