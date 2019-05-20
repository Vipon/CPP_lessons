#include "vStack.h"

int main() {
    
    vStack<int> a = vStack<int>(1);
    
    a.push(1);
    a.push(2);
    
    std::cout << "Size: " << a.Size() << std::endl;
    
    a.dump();
    
    a.pop();
    a.dump();
    
    std::cout << "Size: " << a.Size() << std::endl;
    try{
        
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

