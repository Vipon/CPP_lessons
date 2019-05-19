#include "Stack.h"
#include <cstdint>
#include <cstdio>
// #include <cstring>
#include <iostream>


Stack::Stack (size_t size) {
	stack = new uint64_t[size];
	this->size = size;
	this->cur = 0;
}

Stack::~Stack() {
	delete [] stack;
}

bool Stack::isFull()  {
	return (cur == size);
}

bool Stack::isEmpty() {
	return (cur == 0);
}

void Stack::push(uint64_t dat) {
	if (isFull()) {
		uint64_t *ST0 = stack;
		stack = new uint64_t[size * 2];
		memcpy(stack, ST0, (size * sizeof(uint64_t)));
		size = 2 * size;
		delete [] ST0;
	}

	stack[cur++] = dat;
}

uint64_t Stack::pop() {
	if (isEmpty()) {
		std::cout << "Sorry, stack is empty" << std::endl;
		abort();
}

	return (stack[--cur]);
}

void Stack::dump() {
	if (isEmpty()) {
		return;
	}

	size_t i = 0;
	for (i = 0; i < cur; i++) {
		std::cout << stack[i] << std::endl;
	}
}  