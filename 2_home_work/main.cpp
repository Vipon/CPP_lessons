#include "Stack.h"
#include <cstdio>
#include <cstdlib> 
#include <iostream>

int main()
{
	Stack st(5);
	std::cout << st.isFull() << std::endl;
	std::cout << st.isEmpty() << std::endl;
	int i = 0;
	while (i < 5)
	{
		st.push(i++);
	}
	st.dump();
	std::cout << st.isFull() << std::endl;
	st.~Stack();
	std::cout << st.isFull() << std::endl;
	std::cout << st.isEmpty() << std::endl;
	return 0;
}