#include "Stack.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib> 
#include <iostream>


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
    size_t i;
    for (i = 0; i < top; i++) {
        std::cout << data[i];
        std::cout << "    ";
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