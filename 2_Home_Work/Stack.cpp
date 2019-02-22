#include "Stack.h"
#include <cstring>
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


bool Stack::isFull() 
{
	if (head == size) {
		return true;
	}

	return false;
}


bool Stack::isEmpty()
{
	if (head == 0) {
		return true;
	}
	
	return false; 
}


void Stack::push(uint64_t val)
{
	if (isFull() == 1) {
		uint64_t* temp = stack;
		stack = new uint64_t[size * 2];
		memcpy(stack, temp, (size * sizeof(uint64_t)));
		size *= 2;
		delete [] temp;
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