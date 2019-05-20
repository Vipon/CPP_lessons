#include "vStack.h"

int main() {
    
    vStack<int> a = vStack<int>(3);
    
    try{
    
    a.push(1);
    a.push(2);
    a.push(3);
    
    std::cout << "Size: " << a.Size() << std::endl;
    
    a.dump();
    
    a.pop();
    a.dump();
    
    std::cout << "Size: " << a.Size() << std::endl;
    
        
    a.pop();
    a.pop();
    a.pop();
        
    } catch(std::underflow_error& msg) {
        std::cerr << std::endl;
        std::cerr << msg.what() << std::endl;
    }
    
    std::cout << "Size: " << a.Size() << std::endl;
    
    /*
     try{
     
     } catch(std::underflow_error& msg) {
     std::cerr << std::endl;
     std::cerr << msg.what() << std::endl;
     }
     */
    
    return 0;
}

