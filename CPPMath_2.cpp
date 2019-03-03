#include <cstdlib>
#include <cstdio>

struct complex {
public:
    double Re;
    double Im;
};



template <typename T0, typename T1>
//auto Sum(T0 &a, T1 &b) -> decltype(a + b) // C++11
auto Mul(T0 &a, T1 &b) // C++14
{
	return a*b;
}

template <> auto Mul<complex, double> (complex &a, double &sc)
{
	 complex com ={};
	 com.Re = (a.Re)*sc;
	 com.Im = (a.Im)*sc;
	 return (com);

}

template <> auto Mul<double, complex> ( double &sc, complex &a)
{
	 complex com ={};
	 com.Re = (a.Re)*sc;
	 com.Im = (a.Im)*sc;
	 return (com);

}

template <>  auto Mul<complex, complex> (complex &a, complex &b)
{    

    complex t = {};
    t.Re = (a.Re)*(b.Re) - (a.Im)*(b.Im);
    t.Im = (a.Re)*(b.Im) + (a.Im)*(b.Re);
    return (t);
}

int main () 
{
	int q = 5;
	double w = 5.87;
	double e = Mul (q, w);
	printf ("%f", e);
	complex m= {2, 6};
	complex d = Mul (q, m);
	printf ("%f\n", d.Re);
	printf("%f\n", d.Im);
	return 0;

}