#include "Stack.h"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>


Stack::Stack (size_t size) {
	stack = new uint32_t[size];
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

void Stack::push(uint32_t data) {
	if (isFull()) {
		uint32_t *buffer = stack;
		stack = new uint32_t[size * 2];
		memcpy(stack, buffer, (size * sizeof(uint32_t)));
		size = 2 * size;
		delete [] buffer;
	}

	stack[(cur++)] = data;
}

uint64_t Stack::pop() {
	if (isEmpty()) {
		abort();
	}

	uint32_t data = stack[(cur - 1)];
	stack[(--cur)] = 0;
	return data;
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
