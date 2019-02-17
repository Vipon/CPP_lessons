#ifndef STACK02_H
#define STACK02_H

#include <cstdint>


class Stack {
public:
	Stack(size_t size);
	~Stack();

	int push(uint64_t top);
	uint64_t pop();
	int isFull();
	int isEmpty();
	void dump();

private:
	uint64_t* stack;
	size_t size;
	size_t head;
};

#endif /*STACK02_H*/
