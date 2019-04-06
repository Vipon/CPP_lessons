#ifndef _STACK_H
#define _STACK_H

class Stack
{
	public:
		Stack(int size = 0);
		~Stack();
		void push(int data);
		int pop();
		bool isFull();
		bool isEmpty();
		void dump();
	private:
		int* value;
		int head;
		int size;
};

#endif// _STACK_H