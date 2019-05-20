#include "Stack.h"
#include <iostream>

int main () 
{
	size_t size = 13;
	Stack S1(size);

	S1.push(25);
	S1.pop();
	S1.pop(); //should be abort
	S1.push(137);
	S1.push(42);
	S1.push(26);
	S1.dump(); //printout
	uint32_t IP = S1.pop();
	std::cout << IP << std::endl;

	return 0; // fantastic

}

	
