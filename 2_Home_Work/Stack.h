#ifndef __STACK_H
#define __STACK_H

class Stack {

public:
	Stack (size_t size);
	~Stack();
	void Push (uint64_t val);
	uint64_t Pop ();
	void dump();
	bool isEmpty();
	bool isFull();


private:
	uint64_t *stack;
	size_t size;
	size_t head;
	
}

#endif //__STACK_H