#ifndef __STACK_H
#define __STACK_H

#include <cstdint>
#include <cstddef>

class Stack {

public:
	Stack (size_t size = 9);
	~Stack();
	void push (uint32_t dat);
	uint64_t pop ();
	void dump();
	bool isEmpty();
	bool isFull();


private:
	uint32_t *stack;
	size_t size;
	size_t cur;

};

#endif //__STACK_H 
