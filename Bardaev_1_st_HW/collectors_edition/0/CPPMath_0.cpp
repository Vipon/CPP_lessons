#include <iostream>

template <class T>
T Sum(T& a, T& b){
    return a + b;
}

template <class T>
T Sub(T& a, T& b){
    return a - b;
}

template <class T>
T Mul(T& a, T& b){
    return a * b;
}

template <class T>
T Div(T& a, T& b){
    return a / b;
}

int main() {
    
    double V = 1.0;
    double a = 1.0;
    double b = 1.0;
    
    std::cin >> a >> b;
    
    V = Sum(a, b);
    std::cout << V << std::endl;
    
    V = Sub(a, b);
    std::cout << V << std::endl;
    
    V = Mul(a, b);
    std::cout << V << std::endl;
    
    V = Div(a, b);
    std::cout << V << std::endl;
    
    return 0;
}
