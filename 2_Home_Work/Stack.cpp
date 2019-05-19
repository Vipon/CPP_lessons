
#include "Stack.h" 

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstring>


/*constructor and destructor*/
Stack::Stack (size_t size)  
{
	stack = new uint32_t[size];
	this->size = size;
	this->cur = 0;
};

Stack::~Stack() 
{
	delete [] stack;
}


/*is full and is empty*/
int Stack::isFull() 
{
	return (cur == size);
}

int Stack::isEmpty() 
{
	return (cur == 0);
}


/*push and pop*/
void Stack::push(uint32_t dat) 
{
	if (isFull()) 
	{
		uint32_t st_0 = stack;
		stack = new uint32_t[2*size];
		memcpy(stack, st_0, (size*sizeof(uint32_t)));
		size = 2*size;
		delete [] st_0;
	}

	stack[cur++] = dat;
}

uint32_t Stack::pop()
{
	if (isEmpty()) 
	{
		abort();
	}

	uint32_t dat = stack [cur-1];
	stack[--cur] = 0;
	return dat;
}


/* printout */
void Stack::dump() 
{
	if (isEmpty()) 
	{
		return;
	}

	size_t i = 0;
	for (i = 0; i < cur; i++)
	{
		std::cout<< stack[i] << std::endl;
	}
}
