#include "stack.h"
#include <cstdio>
#include <cstdlib> 
#include <iostream>

int error;

Stack::Stack(size_t maxsize):size(maxsize), top(0) {
    data = new int[size];
    if (data == nullptr) {
        error = OUT_OF_MEMORY;
    }
}


int Stack::push(int value) {
    if (top > value) {
        int *temp = new int[size * 2];

        if (temp == nullptr) {
            error = OUT_OF_MEMORY;
            return OUT_OF_MEMORY;
        }

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


int Stack::isFull() {
    if (top == size) {
        return 1;
    }
    return 0;
}


int Stack::isEmpty() {
    if (top == 0) {
        return 1;
    }
    return 0;
}
