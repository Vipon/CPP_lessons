#include <cstdio>
#include <cstdint>


template <typename T0, typename T1>
auto Sum(T0 &a, T1 &b)
{
    return (a + b);
}

template <typename T0, typename T1>
auto Sub(T0 &a, T1 &b)
{
    return (a - b);
}

template <typename T0, typename T1>
auto Mul(T0 &a, T1 &b)
{
    return (a * b);
}

template <typename T0, typename T1>
auto Div(T0 &a, T1 &b)
{
    return (a / b);
}


int main()
{
    uint32_t a32 = 6, b32 = 4;
    printf("Sum(a32, b32) %d\n", Sum(a32, b32));
    printf("Sub(a32, b32) %d\n", Sub(a32, b32));
    printf("Mul(a32, b32) %d\n", Mul(a32, b32));
    printf("Div(a32, b32) %d\n", Div(a32, b32));

    double dVal = 2.0;
    printf("Sum(a32, dVal) %lf\n", Sum(a32, dVal));
    printf("Sub(a32, dVal) %lf\n", Sub(a32, dVal));
    printf("Mul(a32, dVal) %lf\n", Mul(a32, dVal));
    printf("Div(a32, dVal) %lf\n", Div(a32, dVal));

    getchar();
    return 0;
}