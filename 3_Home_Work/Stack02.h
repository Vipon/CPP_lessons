#ifndef STACK02_H
#define STACK02_H

#include <cstdint>
using namespace std;

class Stack {
public:
	Stack();
	~Stack();
	
	void push(int top);
	int pop();
	bool isFull();
	bool isEmpty();
	void dump();


private:
	int* stack;
	size_t head;
	size_t size;
};

#endif /*STACK02_H*/
