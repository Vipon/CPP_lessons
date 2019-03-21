#include "Stack.h"
#include <iostream>

int main() {

	size_t size = 5;
	Stack St(size);

	St.pop();
	St.push(5);
	St.push(8);
	St.push(2);

	St.dump();

	St.push(12);
	St.push(3);
	St.push(4);
	uint64_t a = St.pop();
	std::cout << a << std::endl;
	return 0;
}