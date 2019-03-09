#include "Stack.h"
#include <cstdbool>
#include <cstdlib>
#include <cstring>
#include <iostream>

Stack::Stack(size_t stack_size)
{
    size = stack_size;
    head = 0;
    El_of_stack = new double[stack_size];
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
    return(head == size);
}

bool Stack::is_empty()const
{
    return(head == 0);
}

void Stack::push(const double& val)
{
    if (Stack::is_full())
    {
        auto New_El_of_stack = new double[++size];
        memcpy(New_El_of_stack, El_of_stack, size*sizeof(double));
        delete [] El_of_stack;
        El_of_stack = New_El_of_stack;
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
    for (size_t i = head - 1; i + 1 > 0 ; i--)
    {
        std::cout << El_of_stack[i] << std::endl;
    }
    std::cout << "end\n";
}