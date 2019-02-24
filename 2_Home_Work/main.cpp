#include "Stack.h"
#include <cstdlib>
#include <iostream>

void testing_of_constructor_of_copy(Stack st)
{
    std::cout << "It's copy:\n";
    std::cout << st.pop() << std::endl;
    st.dump();
}//It is'n mistake, this function must be in main.cpp

int main()
{
    Stack some_stack(3);
    if (some_stack.is_empty())
    {
        std::cout << "I'm empty:\n";
    }
    some_stack.push(1);
    some_stack.push(2);
    some_stack.push(3);
    if (some_stack.is_full())
    {
        std::cout << "I'm full:\n";
    }
    some_stack.dump();
    testing_of_constructor_of_copy(some_stack);
    some_stack.dump();
    std::cout << some_stack.pop()<< std::endl;
    std::cout << some_stack.pop()<< std::endl;
    std::cout << some_stack.pop()<< std::endl;
    some_stack.dump();
    return 0;
}