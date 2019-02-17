#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include <cstdint>

class Stack {

public:
	Stack(size_t size);
	~Stack();

	int isFull(); //returns 1 if stack is full, else 0.
	int isEmpty(); //returns 1 if stack is emty, else 0.
	void push(uint64_t val);
	uint64_t pop();
	void dump();

private:
	uint64_t* stack;
	size_t size;
	size_t head; //number of the next element

};


#endif //__STACK_H