#include "Stack02.h"
#include <cstdio>
#include <iostream>

Stack::Stack(size_t size)
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
	if (stack == nullptr)
	{
		return -1;
	}

	if (head == size)
	{
		return 1;
	}

	return 0;
}

int Stack::isEmpty()
{
	if (stack == nullptr)
	{
		return -1;
	}

	if (head == 0)
	{
		return 1;
	}

	return 0;
}

uint64_t Stack::pop()
{
	if ((isEmpty() == -1) || (isEmpty() == 1))
	{
		abort();
	}

	return stack[--head];
}

int Stack::push(uint64_t top)
{
	if ((isFull() == -1)||(isFull() == 1))
	{
		return isFull();
	}

	stack[head++] = top;

	return isFull();
}

void Stack::dump()
{
	if (isEmpty() == -1)
	{
		std::cout << "Stack does not exist" << std::endl;
		return;
	}

	if (isEmpty() == 1)
	{
		std::cout << "Stack is empty" << std::endl;
		return;
	}

	std::cout << "here is your stack:" << std::endl;

	for (size_t i = 0; i < head; i++)
	{
		std::cout << stack[i] << std::endl;
	}
}

