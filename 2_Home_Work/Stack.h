#ifndef __STACK_H
#define __STACK_H

#include <cstddef>
#include <cstdint>

class Stack {

public:
	Stack(size_t size = 10);
	~Stack();

	bool isFull(); //returns true if stack is full, else false.
	bool isEmpty(); //returns true if stack is emty, else false.
	void push(uint64_t val);
	uint64_t pop();
	void dump();

private:
	uint64_t* stack;
	size_t size;
	size_t head; //number of the next element

};


#endif //__STACK_H