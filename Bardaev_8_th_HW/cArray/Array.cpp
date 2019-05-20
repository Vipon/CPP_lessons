#include "Array.h"

int main() {
    
    Array<int, 8> s;
    
    try{
        
        std::cout << "Enter Array: ";
        std::cin >> s;
        
    } catch(std::range_error& msg) {
        std::cerr << msg.what() << std::endl;
    }
    
    std::cout << std::endl;
    
    try{
        
        std::cout << s << std::endl;
        
    } catch(std::underflow_error& msg) {
        std::cerr << std::endl;
        std::cerr << msg.what() << std::endl;
    }
    
    Array<int, 8> b = s;
    std::cout << b << std::endl;
    
    return 0;
}
