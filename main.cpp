#include "stack_.h"

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
    
    return 0;
}
