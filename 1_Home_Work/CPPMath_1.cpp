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

template <typename T>
T Sum(T &a, T &b) {
    return (a + b);
}

template <> Complex Sum<Complex>(Complex &a, Complex &b) {
    Complex c = {};
   
    c.Re = a.Re + b.Re;
    c.Im = a.Im + b.Im;

    return c;
}

template <typename T>
T Sub(T &a, T &b) {
    return (a - b);
}

template <> Complex Sub<Complex>(Complex &a, Complex &b) {
    Complex c = {};

    c.Re = a.Re - b.Re;
    c.Im = a.Im - b.Im;

    return c;
}

template <typename T>
T Mul(T &a, T &b) {
    return (a * b);
}

template <> Complex Mul<Complex>(Complex &a, Complex &b) {
    Complex c = {};

    c.Re = a.Re * b.Re - a.Im * b.Im;
    c.Im = a.Re * b.Im + a.Im * b.Re;

    return c;
}

template <typename T>
T Div(T &a, T &b) {
    return (a / b);
}

template <> Complex Div<Complex>(Complex &a, Complex &b) {
    Complex c = {};

    c.Re = (a.Re * b.Re + a.Im * b.Im) / (b.Re * b.Re + b.Im * b.Im);
    c.Im = (a.Im * b.Re - a.Re * b.Im) / (b.Re * b.Re + b.Im * b.Im);

    return c;
}


int main()
{
    uint32_t a32 = 6, b32 = 4;
    printf("Sum(a32, b32) %d\n", Sum(a32, b32));
    printf("Sub(a32, b32) %d\n", Sub(a32, b32));
    printf("Mul(a32, b32) %d\n", Mul(a32, b32));
    printf("Div(a32, b32) %d\n", Div(a32, b32));

    double dVal1 = 2.0, dVal2 = 3.0;

    printf("Sum(dVal1, dVal2) %lf\n", Sum(dVal1, dVal2));
    printf("Sub(dVal1, dVal2) %lf\n", Sub(dVal1, dVal2));
    printf("Mul(dVal1, dVal2) %lf\n", Mul(dVal1, dVal2));
    printf("Div(dVal1, dVal2) %lf\n", Div(dVal1, dVal2));

    Complex CVal1 = { 1, 2 }, CVal2 = { 3, 9 };

    printf("Sum(CVal1, CVal2) ");
    print_complex(Sum(CVal1, CVal2));
    printf("\n");

    printf("Sub(CVal1, CVal2) ");
    print_complex(Sub(CVal1, CVal2));
    printf("\n");

    printf("Mul(CVal1, CVal2) ");
    print_complex(Mul(CVal1, CVal2));
    printf("\n");

    printf("Div(CVal1, CVal2) ");
    print_complex(Div(CVal1, CVal2));
    printf("\n");

    return 0;
}