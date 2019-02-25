#ifndef Stack_h
#define Stack_h

#include <cstdint>

class Stack
{
public:
	Stack();
	~Stack();

	bool isFull();
	bool isEmpty();

	void push (uint64_t entry);
	uint64_t pop ();

	void dump();

private:
	uint64_t* STACK;
	size_t head;
	size_t size;	
	
};


#endif