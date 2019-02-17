#include "Stack02.h"
#include <cstdio>
#include <iostream>

int main()
{
	size_t size = 10;
	Stack st(size);

	for (size_t i = 0; i < size; i++)
	{
		st.push(i*i);
	}

	std::cout << "U see? \n";
	st.dump();
	std::cout << "pop " << st.pop() << "\n" << "and push 5 " << std::endl;
	st.push(5);
	std::cout << "pop again " << st.pop() << std::endl;
	
	return 0;
}