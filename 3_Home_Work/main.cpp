#include "Quaternion.h"
#include <cstdlib>
#include <iostream>

void testing_of_constructor_of_copy(Quaternion a)
{
    a = a + 1;
    std::cout <<"a + 1 = " << a << std::endl;
}

int main()
{
    Quaternion a;
    std::cout <<"a = " << a << std::endl;
    testing_of_constructor_of_copy(a);
    std::cout <<"a = " << a << std::endl;
    Quaternion b;
    std::cout <<"Enter quaternion b:" << std::endl;
    std::cin >> b;
    std::cout <<"b = " << b << std::endl;
    Quaternion q1(1, 1, 1, 1);
    Quaternion q2(1, 1, 1, 1);
    double r = 2;
    std::cout <<"q1 = " << q1 << std::endl;
    std::cout <<"q2 = " << q2 << std::endl;
    std::cout <<"r = " << r << std::endl;
    std::cout <<"a = " << a << std::endl;
    a = q1;
    std::cout <<"a = q1 -> a = " << a << std::endl;
    a += q1;
    std::cout <<"a += q1 -> a = " << a << std::endl;
    std::cout <<"q1 + q2 = " << q1 + q2 << std::endl;
    std::cout <<"q1 + r = " << q1 + r << std::endl;
    std::cout <<"r + q1 = " << r + q1 << std::endl;
    std::cout <<"q1 * q2 = " << q1 * q2 << std::endl;
    std::cout <<"q1 * r = " << q1 * r << std::endl;
    std::cout <<"r * q1 = " << r * q1 << std::endl;
    return 0;
}