#include <cstdlib>
#include <cstdio>

template <typename T>
T Sum (T &a, T &b) {
		T c = a + b;
		return c;
}
template <typename T>
T Sub (T &a, T &b) {
	T c = a - b;
	return c;
}

template <typename T>
T Mul (T &a, T &b) {
	T c = a * b;
	return c;
}

template <typename T>
T Div (T &a, T &b) {
	return a/b;
}

struct Complex {
    double Re;
    double Im;
};


// explicitly specialization
template <> Complex Mul<Complex> (Complex &a, Complex &b)
{    

    Complex t = {};
    t.Re = (a.Re)*(b.Re) - (a.Im)*(b.Im);
    t.Im = (a.Re)*(b.Im) + (a.Im)*(b.Re);
    return (t);
}

template <> Complex Div<Complex> (Complex &a, Complex &b)
{    

	Complex t = {};
	t.Re = ((a.Re)*(b.Re)+(a.Im)*(b.Im))/((b.Re)*(b.Re)+(b.Im)*(b.Im));
	t.Im = ((a.Im)*(b.Re)-(a.Re)*(b.Im))/((b.Re)*(b.Re)+(b.Im)*(b.Im));
	
	return (t);
}

template <> Complex Sum<Complex> (Complex &a, Complex &b)
{
	Complex t = {};
	t.Re = a.Re + b.Re;
	t.Im = a.Im + b.Im;
	return (t);

}	

template <> Complex Sub<Complex> (Complex &a, Complex &b)
{
	Complex t = {};
	t.Re = a.Re - b.Re;
	t.Im = a.Im - b.Im;
	return (t);

}	

int main () {
	Complex a = {1, 5};
	Complex b ={3, 8};
	Complex c= Sum(a, b);
	printf ("SUM Re =  ");
	printf ("%f", c.Re);
	printf (" ");
	printf("Im = ");
	printf("%f\n", c.Im );

	Complex d= Sub(a, b);
	printf ("SUB Re =  ");
	printf ("%f", d.Re);
	printf (" ");
	printf("Im = ");
	printf("%f\n", d.Im );

	Complex e= Mul(a, b);
	printf ("MUL Re =  ");
	printf ("%f", e.Re);
	printf (" ");
	printf("Im = ");
	printf("%f\n", e.Im );

	Complex f= Div(a, b);
	printf ("DIV Re =  ");
	printf ("%f", f.Re);
	printf (" ");
	printf("Im = ");
	printf("%f\n", f.Im );

}