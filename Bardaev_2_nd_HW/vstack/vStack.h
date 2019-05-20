#ifndef vStack_h
#define vStack_h

#include <exception>
#include <iostream>

template <typename T>
class vStack {
public:
    vStack(const unsigned int maxSize) {
        size = 0;
        array = new T [maxSize];
    }
    
    ~vStack() {
        delete[] array;
    }
    
    void push(const T newElement) {
        array[size] = newElement;
        size++;
    }
    
    void pop() {
        if (size == 0){
            throw std::underflow_error("Invalid memory");
        }
        size--;
    }
    
    T top() {
        return array[size-1];
    }
    
    unsigned int Size() {
        return size;
    }
    
    void dump(){
        for(int i = 0; i<size;i++){
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
    
    /*void isFull(){
        if (size >= N) {
            std::cout << "Full" << std::endl;
        } else {
            std::cout << "Not Full" << std::endl;
        }
    }*/
    
    void isEmpty(){
        if (size == 0){
            std::cout << "Empty" << std::endl;;
        } else {
            std::cout << "Not Empty" << std::endl;
        }
    }
    
private:
    unsigned int size;
    T *array;
    
};



/*class Stack {
public:
    
    void push(const int& F){
        if (current >= N) {
            throw std::range_error("out of range");
        }
        _ar[current++] = F;
    }
    
    int pop(){
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
            std::cout << "Not Empty" << std::endl;
        }
    }
    
    Stack() = default;
    Stack(const Stack& p);
    
    ~Stack() = default;
    
    
    
private:
    int _ar[N];
    unsigned int current = 0;
};*/



#endif /* vStack_h */
