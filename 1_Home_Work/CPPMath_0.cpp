#include <iostream>

using namespace std;

template <typename T>
T Sum (T& a, T& b){
	return a + b;
}

template <typename T>
T Sub (T& a, T& b){
	return a - b;
}

template <typename T>
T Mul (T& a, T& b){
	return a * b;
}

template <typename T>
T Div (T& a, T&b){
	return a / b;
}


int  main() {

	int a = 15;
	int b = 7;
	double c = 3.1;
	double d = 2.2;

	printf ("%d\n",Sum (a, b));
	printf ("%d\n",Sub (a, b));
	printf ("%d\n",Mul (a, b));
	printf ("%d\n",Div (a, b));

	printf ("%f\n",Sum (c, d));
	printf ("%f\n",Sub(c, d));
	printf ("%f\n",Mul (c, d));
	printf ("%f\n",Div (c, d));


	return 0;
}