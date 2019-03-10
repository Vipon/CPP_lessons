#include "Stack02.h"
#include <cstdio>
#include <iostream>

Stack::Stack()
{
	stack = new int[10];
	this->size = 10;
	this->head = 0;
}

Stack::~Stack()
{
	delete[] stack;
}

 bool Stack::isFull()
{
	 return head == size;
}

bool Stack::isEmpty()
{
	return head == 0;
}

int Stack::pop()
{
	if (isEmpty())
	{
		abort();
	}

	return stack[--head];
}

void Stack::push(int top)
{
	if (isFull())
	{
		auto buf = new int[2 * size];
		size = size * 2;
		for (size_t i = 0; i < size; i++)
		{
			buf[i] = stack[i];
		}
		delete[] stack;
		stack = buf;
	}

	stack[head++] = top;
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

