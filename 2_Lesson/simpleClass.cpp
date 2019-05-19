#include "simpleClass.h"
#include <iostream>

simpleClass::simpleClass(int val)
{
    this->a = val;
}

void simpleClass::print()
{
    std::cout << "a = " << this->a << std::endl;
}

simpleClass::simpleClass(simpleClass& sc)
{
    a = sc.a;
}

int main()
{
    simpleClass my1; // == my1();
    my1.print();

    simpleClass my2(100);
    my2.print();
    return 0;
}