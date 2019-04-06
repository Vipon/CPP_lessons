#include "Stack.h"
#include <cstdio>
#include <cstdlib> 
#include <iostream>

Stack::Stack(int size)
{
	value = new int[size];
	this->size = size;
	head = 0;
}

Stack::~Stack()
{
	head = 0;
	delete [] value;
}

void Stack::push(int data)
{
	if(isFull())
	{
		std::cout<<"Stack is full."<<std::endl;
		return;
	}
	value[head] = data;
	head++;	
}

int Stack::pop()
{
	if(isEmpty())
	{
		std::cout<<"Stack is empty."<<std::endl;
		return 0;
	}
	return value[--head];
}

void Stack::dump()
{
	int i = 0;
	for(i = 0; i < head; ++i)
	{
		std::cout << i << " element: "<< value[i] << std::endl;
	}
}

bool Stack::isFull()
{
	return (head == size);
}
bool Stack::isEmpty()
{
	return (head == 0);
}

