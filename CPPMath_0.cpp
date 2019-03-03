#include <cstdlib>
#include <cstdio>



template <typename T>
T Sum (T a, T b) {
		T c = a + b;
		return c;
}
template <typename T>
T Sub (T a, T b) {
	T c = a - b;
	return c;
}

template <typename T>
auto Mul (T a, T b) {
	T c = a * b;
	return c;
}

template <typename T>
auto Div (T a, T b) {
	return a/b;
}

int main () {

	float a; 
	float b;
	
	scanf ("%f", &a);
	scanf ("%f", &b);
	
	int sum = Sum (a, b);
	printf ("%df\n", sum);

	int sub = Sub (a, b);
	printf ("%d\n", sub);

	double mul = Mul (a, b);
	printf ("%f\n", mul);

	float div = Div (a, b);
	printf ("%f\n", div);
	return 0;
}

