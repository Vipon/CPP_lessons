#include "vArray.h"

int main() {
    
    vArray a = vArray(4);
    
    std::cout << a;
    
    std::cin >> a;
    
    vArray b = vArray(a);
    
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    return 0;
}
