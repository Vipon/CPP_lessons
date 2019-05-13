#ifndef stack__h
#define stack__h
#include <exception>
#include <iostream>

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
            std::cout << "Not Empty" << std::endl;
        }
    }
    
    Stack() = default;
    Stack(const Stack& p);
    /* while(auto: w *_ar){
            _ar[n] = 0;
            N--;
        }*/  //TODO!
    ~Stack() = default;
    
    
    
private:
    data _ar[N];
    unsigned int current = 0;
};

#endif /* stack__h */

// methods >> alchoritms in priority of using
// qt for graphics, works with 3D objects, maps and sensors on phone (and not only)
// boost library is essential for C++ programminsts
// qt has expand for C++, Python etc. (расширения) 
