#include "Stack.h"
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>


Stack::Stack (size_t size) {
	stack = new uint64_t[size];
	this->size = size;
	this->head = 0;
}

Stack::~Stack() {
	delete [] stack;
}

bool Stack::isFull()  {
	return (head == size);
}

bool Stack::isEmpty() {
	return (head == 0);
}

void Stack::push(uint64_t value) {
	if (isFull()) {
		uint64_t *save = stack;
		stack = new uint64_t[size * 2];
		memcpy(stack, save, (size * sizeof(uint64_t)));
		size = 2 * size;
		delete [] save;
	}

	stack[(head++)] = value;
}

uint64_t Stack::pop() {
	if (isEmpty()) {
		std::cout << "Stack is empty" << std::endl;
		return 0;
	}

	uint64_t value = stack[(head - 1)];
	stack[(--head)] = 0;
	return value;
}

void Stack::dump() {
	if (isEmpty()) {
		return;
	}

	size_t i = 0;
	for (i = 0; i < head; i++) {
		std::cout << stack[i] << std::endl;
	}
} 