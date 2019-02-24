#ifndef STACK
#define STACK

#include <cstdlib>
#include <cstdbool>

class Stack
{
private:
    size_t size;
    size_t head;
    double* El_of_stack; //This is array of stack's elements
public:
    Stack(size_t stack_size);// constructor
    Stack(const Stack& s);// constructor of copy
    void push(const double& val);
    double pop();
    bool is_full()const;
    bool is_empty()const;
    void dump()const;
    ~Stack();
};

#endif