#include "Stack.h"

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
	if (head == size) {
		return 1;
	}
	else {
		return 0;
	};
}


int Stack::isEmpty()
{
	if (head == 0) {
		return 1;
	}
	else {
		return 0;
	}
}


void Stack::push(uint64_t val)
{
	if (isFull() == 1) {
		abort();
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