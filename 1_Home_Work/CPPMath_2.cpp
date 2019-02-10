#include <cstdio>
#include <cstdint>
#include <cstdlib> 


struct Complex {
    double Re;
    double Im;
};

void print_complex(Complex a) {
    printf("%lf + i*%lf", a.Re, a.Im);
}

template <typename T0, typename T1>
 auto Mul(T0 &a, T1 &b) {
    return (a * b);
}

template <> auto Mul<Complex>(Complex &a, Complex &b) {
    Complex c = {};

    c.Re = a.Re * b.Re - a.Im * b.Im;
    c.Im = a.Re * b.Im + a.Im * b.Re;

    return c;
}

template <> auto Mul<Complex>(Complex &a, double &b) {
    Complex c = {};

    c.Re = a.Re * b;
    c.Im = a.Im * b;

    return c;
}

template <> auto Mul<double>(double &a, Complex &b) {
    Complex c = {};

    c.Re = b.Re * a;
    c.Im = b.Im * a;

    return c;
}

int main()
{
    double dVal1 = 2.0, dVal2 = 3.0;
    Complex CVal1 = { 1, 2 }, CVal2 = { 3, 9 };

    printf("Mul(dVal1, dVal2) %lf\n", Mul(dVal1, dVal2));

    printf("Mul(CVal1, CVal2) ");
    print_complex(Mul(CVal1, CVal2));
    printf("\n");

    printf("Mul(CVal1, CVal2) ");
    print_complex(Mul(CVal1, dVal1));
    printf("\n");

    printf("Mul(CVal1, CVal2) ");
    print_complex(Mul(dVal1, CVal2));
    printf("\n");

    return 0;
}