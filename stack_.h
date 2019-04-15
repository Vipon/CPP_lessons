#ifndef stack__h
#define stack__h
#include <iostream>
#include <exception>

template<typename data, int N = 64>
class Stack {
public:
    
    void push(const data& F){
        if (current >= N) {
            throw std::range_error("out of range");
        }
        _ar[current++] = F;
    }
    
    data pop(){
        if (current == 0){
            throw std::underflow_error("Invalid memory");
        }
        return _ar[--current];
    }
    
    void dump(){
        for(current = 0; current<N;current++){
            std::cout << _ar[current] << " ";
        }
    }
    
    void isFull(){
        if (current >= N) {
            std::cout << "Full" << std::endl;
        } else {
            std::cout << "Not Full" << std::endl;
        }
    }
    
    void isEmpty(){
        if (current == 0){
            std::cout << "Empty" << std::endl;;
        } else {
            std::cout << "Not Empty" << std::endl;;
        }
    }
    
private:
    data _ar[N];
    unsigned int current = 0;
};

#endif /* stack__h */
