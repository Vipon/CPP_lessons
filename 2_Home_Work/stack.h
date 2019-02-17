#ifndef STACK
#define STACK

#define MAX 20
#define MULTI 2

class Stack {

public:
    Stack(size_t size = 0);
    ~Stack() {};

    void dump();
    void push(int value);
    int pop();
    bool isFull();
    bool isEmpty();

private:
    int *data;
    size_t top;
    const size_t size;
};

#endif
