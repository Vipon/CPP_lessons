#include "stack.h"

int main()
{
    Stack<> stDefault0;
    Stack<> stDefault1(stDefault0);

    // Default template arguments works as default function argument, so you
    // can't specify last parameter without previous.
    // Right
    Stack<double> dStack;
    Stack<long> lStack;
    // Wrong
    // Stack<10> defaultStack10;

    Stack<double, 1> dStack1;
    // Stack<double, 1> and Stack<double, 2000> are different classes, so we
    // can't do the follow line.
    // Wrong
    // Stack<double, 2000> dStack2000(dStack1);

    dStack.push(100);   // int -> double, because dStack have only method push(double&)
    dStack.push(100.5);
    lStack.push(100);
    lStack.push(100.6); // double -> long, because lStack have only method push(long&)

    return 0;
}
