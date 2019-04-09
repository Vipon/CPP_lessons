#include "stack.h"

//  Explicit creation class Stack<double, 50> from template.
template class Stack<double, 50>;

//  Template specialization
/*
template <> class Stack<double, 100>
{
    // methods and fields
};
*/

//  Partial template specialization
//  Template specialization
/*
template <typename Type> class Stack<Type, 100>
{
    // methods and fields
};

template <size_t Num> class Stack<float, Num>
{
    // methods and fields
};

*/


int main()
{
    //  Implicit creation class Stack<int, 300> from template.
    Stack<int, 300> iStack300;

    return 0;
}
