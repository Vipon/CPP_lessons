#include "testNamespace.h"
#include <iostream>


void Test0::test0()
{
	std::cout << "test0 namespace\n";

}


void Test1::test0()
{
	std::cout << "test1 namespace\n";

}


void test0()
{
	std::cout << "global namespace\n"  ;
}


int main()
{
	Test0::test0();
	Test1::test0();
	test0();
	return 0;
}
