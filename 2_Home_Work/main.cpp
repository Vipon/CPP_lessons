#include "Stack.h"

int main()
{
	size_t size = 7;
	Stack st(size);
	size_t i = 0;

	for (i = 0; i < size; i++) {
		st.push(((i + 1) * 10));
	}

	std::cout << "STACK DUMP: \n";
	st.dump();
	std::cout << "STACK POP: \n"; 
	uint64_t value = 0;

	for (i = 0; i < size; i++) {
		value = st.pop();
		std::cout << value << std::endl;
	}

	return 0;
}