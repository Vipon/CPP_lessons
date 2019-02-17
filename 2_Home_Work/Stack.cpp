#include "Stack.h"
#include <cstdlib>
#include <iostream>

Stack::Stack (size_t size)
{
	stack = new uint64_t[size];
	this->size = size;
	this->head = 0;
}


Stack::~Stack()
{
	delete [] stack;
}


int Stack::isFull() 
{
	int error = 0;

	if (head == size) {
		error = 1;
	}
	else {
		error = 0;
	};

	return error;
}


int Stack::isEmpty()
{
	int error = 0;

	if (head == 0) {
		error = 1;
	}
	else {
		error = 0;
	}

	return error;
}


void Stack::push(uint64_t val)
{
	if (isFull() == 1) {
		uint64_t *temp = (uint64_t*)realloc(stack, ((++size) * sizeof(uint64_t)));

		if (temp == nullptr) {
			size--;
			abort();
		}

		stack = temp;
	}

	stack[(head++)] = val;
}


uint64_t Stack::pop()
{
	if (isEmpty() == 1) {
		abort();
	}

	uint64_t val = stack[(head - 1)];
	stack[(--head)] = 0;
	return val;
}


void Stack::dump()
{
	if (isEmpty() == 1) {
		return;
	}

	size_t i = 0;
	for (i = 0; i < head; i++) {
		std::cout << stack[i] << std::endl;
	}
}