#include "simpleClass.h"
#include <cstdio>

simpleClass::simpleClass(int val)
{
	this->a = val;
}

void simpleClass::print()
{
	printf("a = %d\n", this->a);
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