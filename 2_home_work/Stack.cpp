#include "Stack.h"
#include <cstdio>
#include <cstdlib> 
#include <iostream>

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
	{
		cout << i << " element: "<< value[i] << endl;
	}
}

bool Stack::isFull()
{
	return (head == size - 1);
}
bool Stack::isEmpty()
{
	return (head == 0);
}

