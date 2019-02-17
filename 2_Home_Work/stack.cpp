#include <cstdio>
#include <cstdlib> 
#include "stack.h"
#include <iostream>

char error = 0;

Stack::Stack(size_t maxsize):size(maxsize) {
    data = new int[size];
    top = 0;
}

void Stack::push(int value) {
    data[top] = value;
    top++;
}


int Stack::pop() {
    return data[--top];
}


void Stack::dump() {
    size_t i = 0;
    for (i; i < top; i++) {
        std::cout << data[i];
        std::cout << "   ";
    }
}


bool Stack::isFull() {
    if (top == size) {
        return true;
    }
    else
    {
        return false;
    }
}


bool Stack::isEmpty() {
    if (top == 0) {
        return true;
    }
    else
    {
        return false;
    }
}
