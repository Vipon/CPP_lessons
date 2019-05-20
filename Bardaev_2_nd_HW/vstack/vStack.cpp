#include "vStack.h"

int main() {
    
    vStack<int> a = vStack<int>(2);
    
    try{
    
    a.push(1);
    a.push(2);
        
    vStack<int> b = vStack<int>(a);
        
    a.isFull();
        
    a.push(3);
    
    std::cout << "Size: " << a.Size() << std::endl;
    
    a.push(4);
    a.push(5);
    a.dump();
    
    a.pop();
    a.dump();
    
    std::cout << "Size: " << a.Size() << std::endl;
    
        b.dump();
        std::cout << "Size b: " << a.Size() << std::endl;
        b.isEmpty();
        
    a.pop();
    a.pop();
    a.pop();
        
    } catch(std::underflow_error& msg) {
        std::cerr << std::endl;
        std::cerr << msg.what() << std::endl;
    }
    
    std::cout << "Size: " << a.Size() << std::endl;
    
    a.isFull();
    a.isEmpty();
    
    /*
     try{
     
     } catch(std::underflow_error& msg) {
     std::cerr << std::endl;
     std::cerr << msg.what() << std::endl;
     }
     */
    
    return 0;
}

