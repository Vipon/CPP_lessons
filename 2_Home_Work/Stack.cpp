#include "Stack.h"
#include <cstdio>
#include <cstdlib> 
#include <iostream>


Stack::Stack(size_t maxsize):size(maxsize), top(0), error(OK) {
    data = new int[size];
}


int Stack::push(int value) {
    if (top > value) {
        int *temp = new int[size * 2];

        for (int i = 0; i < size; ++i) {
            temp[i] = data[i];
        }
    
        delete[] data;
        data = temp;
        return OK;
    }

    data[top] = value;
    top++;
    return OK;
}


int Stack::pop() {
    if (top == 0) {
        error = STACK_UNDERFLOW;
        return STACK_UNDERFLOW;
    }

    return data[--top];
}


void Stack::dump() {
    size_t i;
    for (i = 0; i < top; i++) {
        std::cout << data[i];
        std::cout << "   ";
    }
}


bool Stack::isFull() {
    if (top == size) {
        return true;
    }
    return false;
}


bool Stack::isEmpty() {
    if (top == 0) {
        return true;
    }
    return false;
}
