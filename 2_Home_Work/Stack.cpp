#include <cstdlib>
#include <cstdbool>
#include <cstring>
#include <iostream>
#include "Stack.h"

Stack::Stack(size_t stack_size)
{
    El_of_stack = new double[stack_size];
    size = stack_size;
    head = 0;
};

Stack::Stack(const Stack& s):

    size(s.size),
    head(s.head),
    El_of_stack(new double [size])
{
    memcpy(this->El_of_stack, s.El_of_stack, size*sizeof(double));
}

Stack::~Stack()
{
    delete [] El_of_stack;
}

bool Stack::is_full()const
{
    if (head == size)
    {
        return true;
    }
    return false;
}

bool Stack::is_empty()const
{
    if (head == 0)
    {
        return true;
    }
    return false;
}

void Stack::push(const double& val)
{
    if (Stack::is_full())
    {
        abort();
    }
    El_of_stack[head++] = val;
};

double Stack::pop()
{
    if (is_empty())
    {
        abort();
    }
    return El_of_stack[--head];
}

void Stack::dump()const
{
    std::cout << "Begining\n";
    for (int i = head - 1; i > -1 ; i--)
    {
        std::cout << El_of_stack[i] << std::endl;
    }
    std::cout << "end\n";
}