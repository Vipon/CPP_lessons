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
		return false;
	}

	return true;
}

bool Stack::isEmpty()
{
	if (head == 0)
	{
		return false;
	}

	return true;
}

uint64_t Stack::pop()
{
	if (isEmpty() == false)
	{
		abort();
	}

	return stack[--head];
}

bool Stack::push(uint64_t top)
{
	if (isFull() == false)
	{
		uint64_t* buf = new uint64_t[size];
		for (size_t i = 0; i < size; i++)
		{
			buf[i] = stack[i];
		}
		delete[] stack;
		stack = new uint64_t[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			stack[i] = buf[i];
		}
	}

	stack[head++] = top;

	return true;
}

void Stack::dump()
{
	if (isEmpty() == false)
	{
		std::cout << "Stack is empty" << std::endl;
		return;
	}

	std::cout << "here is your stack:" << std::endl;

	for (size_t i = 0; i < head; i++)
	{
		std::cout << stack[i] << std::endl;
	}

	return;
}

