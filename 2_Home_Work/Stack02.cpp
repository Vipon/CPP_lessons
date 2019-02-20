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
	delete[] stack;
}

 bool Stack::isFull()
{
	if (head == size)
	{
		return (1==1);
	}

	return (1==2);
}

bool Stack::isEmpty()
{
	if (head == 0)
	{
		return (1==1);
	}

	return (1==2);
}

uint64_t Stack::pop()
{
	if (isEmpty())
	{
		abort();
	}

	return stack[--head];
}

bool Stack::push(uint64_t top)
{
	if (isFull())
	{
		auto buf = new uint64_t[2 * size];
		size = size * 2;
		for (size_t i = 0; i < size; i++)
		{
			buf[i] = stack[i];
		}
		delete[] stack;
		stack = buf;
	}

	stack[head++] = top;

	return (1==1);
}

void Stack::dump()
{
	if (isEmpty())
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

