#ifndef __STACK_H
#define __STACK_H

#include <cstdint>
#include <cstddef>

class Stack {

public:
	Stack (size_t size = 5);
	~Stack();
	void push (uint64_t val);
	uint64_t pop ();
	void dump();
	bool isEmpty();
	bool isFull();


private:
	uint64_t *stack;
	size_t size;
	size_t head;
	
};

#endif //__STACK_H