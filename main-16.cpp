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
    
private:
    data _ar[N];
    unsigned int current = 0;
};

int main() {
 
    Stack<int, 8> s;
    
    try{
        s.push(2);
        s.push(7);
        s.push(1);
        s.push(8);
        s.push(2);
        s.push(6);
        s.push(1);
        s.push(8);
        s.push(2);
    } catch(std::range_error& msg) {
        std::cerr << msg.what() << std::endl;
    }
    
    s.dump();
    std::cout << std::endl;
    
    try{
        std::cout << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << std::endl;
    } catch(std::underflow_error& msg) {
        std::cerr << std::endl;
        std::cerr << msg.what() << std::endl;
    }
    
    s.isEmpty();
    s.isFull();
    
    return 0;
}


