#ifndef __STACK_H
#define __STACK_H

#include <exception>
#include <iostream>
#include <typeinfo>


class stackException : public std::exception {

public:
    stackException(std::string&& err) noexcept : exc(std::move(err)) {}
    stackException(stackException&& gExc) noexcept : exc(std::move(gExc.exc)) {}
    const char* what() const noexcept { return exc.c_str(); }

private:
    std::string exc;

};


template <typename Type = int, size_t Size = 100>
class Stack {

public:
    Stack() : head(0)
    {
        std::cout << "Create object " << typeid(*this).name() << ".\n";
    }

    Stack(const Stack& st) : Stack()
    {
        head = st.head;
        for (size_t i = 0; i < head; ++i) {
            stack[i] = st.stack[i];
        }
    }

    Stack(Stack&& st) : Stack(st) { }

    ~Stack() { std::cout << "Destroy object " << typeid(*this).name() << ".\n"; }
    size_t size() const { return Size; }
    bool isFull() const { return head == Size; }
    bool isEmpty() const { return head == 0; }

    void push(const Type& elem)
    {
        if (isFull()) {
            throw stackException("Stack is Full.");
        }

        std::cout << "Push " << typeid(elem).name() << " " << elem
                    << " into the " << typeid(*this).name() << ".\n";
        stack[head++] = elem;
    }

    Type pop()
    {
        if (isEmpty()) {
            throw stackException("Stack is Empty.");
        }

        return stack[--head];
    }

    Stack& operator=(const Stack& st)
    {
        head = st.head;
        for (size_t i = 0; i < head; ++i) {
            stack[i] = st.stack[i];
        }

        return (*this);
    }

private:
    size_t  head;
    Type    stack[Size];

};

#endif /* __STACK_H */