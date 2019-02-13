#include <cstdio>
#include "testNamespace.h"

void Test0::test0()
{
	printf("namespace test0\n");

}

void Test1::test0()
{
	printf("namespace test1\n");
	
}

void test0() 
{
	printf("Global\n");
}

int main()
{
	Test0::test0();
	Test1::test0();
	test0();
	return 0;
}
