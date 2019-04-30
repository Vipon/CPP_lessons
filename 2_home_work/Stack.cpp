#include "Stack.h"
#include <cstdio>
#include <cstdlib> 
#include <iostream>

int error = 0;

Stack::Stack(int size)
{
	error = 0;
	value = new int[size];
	this->size = size;
	head = 0;
}

Stack::~Stack()
{
	error = 0;
	head = 0;
	delete [] value;
}

int Stack::push(int data)
{
	error = 0;
	if(isFull())
	{
		std::cout<<"Stack is full."<<std::endl;
		error = 1;
		return error;
	}
	value[head] = data;
	head++;	
	return data;
}

int Stack::pop()
{
	error = 0;
	if(isEmpty())
	{
		std::cout<<"Stack is empty."<<std::endl;
		error = 1;
		return error;
	}
	return value[--head];
}

void Stack::dump()
{
	error = 0;
	int i = 0;
	for(i = 0; i < head; ++i)
	{
		std::cout << i << " element: "<< value[i] << std::endl;
	}
}

bool Stack::isFull()
{
	error = 0;
	return (head == size);
}
bool Stack::isEmpty()
{
	error = 0;
	return (head == 0);
}

