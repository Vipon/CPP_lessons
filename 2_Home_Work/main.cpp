#include "Stack.h"
#include <iostream>

int main()
{
	size_t size = 10;
	Stack st;
	size_t i = 0;

	for (i = 0; i < (size + 1); i++) {
		st.push(((i + 1) * 10));
	}

	std::cout << "STACK DUMP: \n";
	st.dump();
	std::cout << "STACK POP: \n"; 
	uint64_t value = 0;

	for (i = 0; i < (size + 1); i++) {
		value = st.pop();
		std::cout << value << std::endl;
	}

	return 0;
}