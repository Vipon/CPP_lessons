#include "Stack.h"
#include <cstdio>
#include <cstdlib> 
#include <iostream>

int main()
{
	Stack st(5);
	int i = 0;
	while (i < 5)
	{
		st.push(i++);
	}
	st.dump();
	std::cout << st.isFull() << std::endl;
	st.~Stack();
	return 0;
}