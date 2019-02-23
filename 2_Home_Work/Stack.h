#ifndef STACK
#define STACK

#include <cstddef> 

enum ERRORS {
    OUT_OF_MEMORY = -103,
    STACK_UNDERFLOW,
    OK = 0
};

extern int error;

class Stack {

public:
    Stack(size_t size = 0);
    ~Stack() {};

    void dump();
    int push(int value);
    int pop();
    int isFull();
    int isEmpty();

private:
    int *data;
    size_t top;
    const size_t size;
};

#endif
