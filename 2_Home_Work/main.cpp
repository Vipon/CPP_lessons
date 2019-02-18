#include "Stack.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib> 
#include <iostream>

int main() {
    std::cout << "Print size of stack\n";
    size_t size = 0;
    std::cin >> size;
    Stack wassap(size);

    if (wassap.isEmpty()) {
        std::cout << "Stack is Empty\n";
    }
    else {
        std::cout << "Stack isn't Empty\n";
    }

    size_t i;
    for (i = 0; i < size; i++) {
        wassap.push(i); 
        // stack is filling up with i

        if (i % 2 == 0) {
            wassap.pop();
            // i / 2 are popped  
        }
    }

    wassap.dump();

    if (wassap.isFull()) {
        std::cout << "\nStack is Full";
    }
    else {
        std::cout << "\nStack isn't Full";
    }
    // Stack isn't Full as we've deleted i/2

    std::cin >> i;
    return 0;
}