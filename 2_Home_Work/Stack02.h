#ifndef STACK02_H
#define STACK02_H

#include <cstdint>
using namespace std;

class Stack {
public:
	Stack(size_t size);
	~Stack();
	
	void push(uint64_t top);
	uint64_t pop();
	bool isFull();
	bool isEmpty();
	void dump();


private:
	uint64_t* stack;
	size_t head;
	size_t size;
};

#endif /*STACK02_H*/
