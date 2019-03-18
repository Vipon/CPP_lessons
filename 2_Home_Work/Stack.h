#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "List.h"

template <typename T>
class Stack{
    List<T> L;
public:
    Stack(){};
    ~Stack(){};
    bool empty() const;
    std::size_t length() const;
    void push(const T &val);
    void pop();
    T &back();
};

template <typename T>
bool Stack<T>::empty() const{
    return L.empty();
};

template <typename T>
std::size_t Stack<T>::length() const{
    return L.length();
};

template <typename T>
void Stack<T>::push(const T &val){
    L.push(val);
}

template <typename T>
void Stack<T>::pop(){
    L.pop();
}

template <typename T>
T &Stack<T>::back(){
    return L.back();
};

#endif // STACK_H_INCLUDED
