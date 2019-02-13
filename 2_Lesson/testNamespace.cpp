#include <cstdio>
#include "testNamespace.h"


void Test0::test0()
{
	printf("test0 namespace\n");

}


void Test1::test0()
{
	printf("test1 namespace\n");

}


void test0()
{
	printf("global namespace\n");
}


int main()
{
	Test0::test0();
	Test1::test0();
	test0();
	return 0;
}
