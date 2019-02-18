#include <cstdlib>
#include <iostream>

template <typename Type>
auto Sum(Type& a, Type& b)
{
    return a + b;
}

template <typename Type>
auto Sub(Type& a, Type& b)
{
    return a - b;
}

template <typename Type>
auto Mul(Type& a, Type& b)
{
    return a * b;
}

template <typename Type>
auto Div(Type& a, Type& b)
{
    if (b == 0)
    {
        return b;
    }
    return a / b;
}

int main()
{
    int a = 4;
    int b = 2;
    double c = 5.1;
    double d = 2;
    std::cout << "First values:\n";
    std::cout <<"a = " << a << "\n";
    std::cout <<"b = " << b << "\n";
    std::cout <<"c = " << c << "\n";
    std::cout <<"d = " << d << "\n";
    std::cout << "Sum(a, b) =" << Sum(a, b) <<"\n";
    std::cout << "Sum(c, d) =" << Sum(c, d) <<"\n";
    std::cout << "Sub(a, b) =" << Sub(a, b) <<"\n";
    std::cout << "Sub(c, d) =" << Sub(c, d) <<"\n";
    std::cout << "Mul(a, b) =" << Mul(a, b) <<"\n";
    std::cout << "Mul(c, d) =" << Mul(c, d) <<"\n";
    std::cout << "Div(a, b) =" << Div(a, b) <<"\n";
    std::cout << "Div(c, d) =" << Div(c, d) <<"\n";
    return 0;
}