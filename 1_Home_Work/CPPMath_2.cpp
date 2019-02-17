#include <cstdlib>
#include <iostream>

struct Complex
{
    double Re;
    double Im;
};

template <typename Type0, typename Type1>
auto Sum(Type0& a, Type1& b)
{
    return a + b;
}

template <> auto Sum<Complex, Complex>(Complex &a, Complex &b)
{
    Complex z = {};
    z.Re = a.Re + b.Re;
    z.Im = a.Im + b.Im;
    return z;
}

template <typename Type0, typename Type1>
auto Sub(Type0& a, Type1& b)
{
    return a - b;
}

template <> auto Sub<Complex, Complex> (Complex &a, Complex &b)
{
    Complex z = {};
    z.Re = a.Re - b.Re;
    z.Im = a.Im - b.Im;
    return z;
}

template <typename Type0, typename Type1>
auto Mul(Type0& a, Type1& b)
{
    return a * b;
}

template <> auto Mul<Complex, Complex> (Complex &a, Complex &b)
{
    Complex z = {};
    z.Re = a.Re * b.Re - a.Im * b.Im;
    z.Im = a.Re * b.Im + a.Im * b.Re;
    return z;
}

template <> auto Mul<double, Complex>(double &scalar, Complex &comp)
{
    Complex z = {};
    z.Re = comp.Re * scalar;
    z.Im = comp.Im * scalar;
    return z;
}

template <> auto Mul<Complex, double>(Complex &comp, double &scalar)
{
    Complex z = {};
    z.Re = comp.Re * scalar;
    z.Im = comp.Im * scalar;
    return z;
}

template <typename Type0, typename Type1>
auto Div(Type0& a, Type1& b)
{
    if (b == 0)
    {
        return 0;
    }
    return a/b;
}

template <> auto Div <Complex, Complex> (Complex &a, Complex &b)
{
    Complex z = {};
    z.Re = (a.Re * b.Re + a.Im * b.Im)/(b.Re * b.Re + b.Im * b.Im);
    z.Im = (a.Im * b.Re - a.Re * b.Im)/(b.Re * b.Re + b.Im * b.Im);
    return z;
}

int main()
{
    int a = 4;
    int b = 2;
    double c = 5.1;
    double d = 2;
    double scalar = 2;
    Complex z1 = {};
    Complex z2 = {};
    z1.Re = 1;
    z1.Im = 1;
    z2.Re = 2;
    z2.Im = 2;
    std::cout << "First values:\n";
    std::cout <<"a = " << a << "\n";
    std::cout <<"b = " << b << "\n";
    std::cout <<"c = " << c << "\n";
    std::cout <<"d = " << d << "\n";
    std::cout <<"z1.Re = " << z1.Re << "\n";
    std::cout <<"z1.Im = " << z1.Im << "\n";
    std::cout <<"z2.Re = " << z2.Re << "\n";
    std::cout <<"z2.Im = " << z2.Im << "\n";
    std::cout << "Sum(a, b) =" << Sum(a, b) <<"\n";
    std::cout << "Sum(c, d) =" << Sum(c, d) <<"\n";
    std::cout << "Sum(z1, z2).Re =" << Sum(z1, z2).Re <<"\n";
    std::cout << "Sum(z1, z2).Im =" << Sum(z1, z2).Im <<"\n";
    std::cout << "Sub(a, b) =" << Sub(a, b) <<"\n";
    std::cout << "Sub(c, d) =" << Sub(c, d) <<"\n";
    std::cout << "Sub(z1, z2).Re =" << Sub(z1, z2).Re <<"\n";
    std::cout << "Sub(z1, z2).Im =" << Sub(z1, z2).Im <<"\n";
    std::cout << "Mul(a, b) =" << Mul(a, b) <<"\n";
    std::cout << "Mul(c, d) =" << Mul(c, d) <<"\n";
    std::cout << "Mul(z1, z2).Re =" << Mul(z1, z2).Re <<"\n";
    std::cout << "Mul(z1, z2).Im =" << Mul(z1, z2).Im <<"\n";
    std::cout << "Mul(scalar, z2).Im =" << Mul(scalar, z2).Im <<"\n";
    std::cout << "Mul(scalar, z2).Re =" << Mul(scalar, z2).Re <<"\n";
    std::cout << "Mul(z2, scalar).Im =" << Mul(z2, scalar).Im <<"\n";
    std::cout << "Mul(z2, scalar).Re =" << Mul(z2, scalar).Re <<"\n";
    std::cout << "Div(a, b) =" << Div(a, b) <<"\n";
    std::cout << "Div(z1, z2).Re =" << Div(z1, z2).Re <<"\n";
    std::cout << "Div(z1, z2).Im =" << Div(z1, z2).Im <<"\n";//:)
    return 0;
}