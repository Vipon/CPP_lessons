#include "Stack.h"
#include <iostream>
#include <ostream>
#include <cstdio>
#include <cstdlib> 

using namespace std;

Stack::Stack(int size)
{
	value = new int[size];
	this->size = size;
	head = 0;
}

void Stack::push(int data)
{
	value[head] = data;
	head++;
}

int Stack::pop()
{
	return value[--head];
}

void Stack::dump()
{
	int i = 0;
	for(i = 0; i < head; ++i)
		cout << i << " element: "<< value[i] << endl;
}

bool Stack::isFull()
{
	if (head == size - 1)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Stack::isEmpty()
{
	if (head == 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

