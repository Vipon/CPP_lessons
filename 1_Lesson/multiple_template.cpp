#include <cstdio>
#include <cstdint>


template <typename T0, typename T1>
//auto Sum(T0 &a, T1 &b) -> decltype(a + b) // C++11
auto Sum(T0 &a, T1 &b) // C++14
{
    //decltype(a + b) c = (a + b); // C++11
    return (a + b);
}


template <typename T0, typename T1>
//auto Sum(T0 &a, T1 &b) -> decltype(a + b) // C++11
auto Fib(T0 &val0, T0 &val1, T1 &num) // C++14
{
    if (num == 1)
        return val0 + val1;

    decltype(val0 + val1) val3 = val0 + val1;
    return Fib(val1, val3, --num);
}


int main()
{
    uint32_t a32 = 1, b32 = 1;
    printf("Sum(a32, b32) %d\n", Sum(a32, b32));

    uint64_t a64 = 1, b64 = 1;
    printf("Sum(a64, b64) %lu\n", Sum(a64, b64));

    double dVal = 2.0;
    printf("Sum(a32, dVal) %lf\n", Sum(a32, dVal));

    size_t num = 10;
    printf("Fib(a64, b64, num) %lu\n", Fib(a64, b64, num));
    return 0;
}
