#ifndef __STACK_H
#define __STACK_H
// #include <iostream>
#include <cstdint>


class Stack
{
public:
	
	Stack(size_t size = 9);
	~Stack();

	void push(uint32_t val);
	uint32_t pop();

	int isFull();
	int isEmpty();
	void dump();

private:
	
	uint32_t *stack;
	size_t size;
	size_t cur;

};

#endif // __STACK_H