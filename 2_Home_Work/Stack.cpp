#include <cstdint>
#include <cstdio>
#include <iostream>


#include "Stack.h"

Stack::Stack(){
	STACK = new uint64_t[1];
	size = 1;
	head = 0;
}


Stack::~Stack(){
	delete [] STACK;
}


bool Stack::isFull(){
	return (head == size);
}


bool Stack::isEmpty(){
	return (head ==0);
}


void Stack::push(uint64_t entry){
	if(isFull()){
		auto repository = new uint64_t[++size];

		for (size_t i = 0; i < size; i++)
		{
			repository[i] = STACK[i];
		}
		delete [] STACK;
		STACK = repository;
	}

	STACK[head++] = entry;
}


uint64_t Stack::pop(){
	if(isEmpty()){
	std::cout << "The stack is empty" << std::endl;
	abort();
	}
	return STACK[--head];
}


void Stack::dump(){
	if(isEmpty()){
		std::cout << "The stack is empty" << std::endl;
		return;
	}

	for (size_t i = 0; i < head; ++i)
	{
		std::cout << STACK[i] << std::endl;
	}
}

