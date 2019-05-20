#include <iostream>

struct Complex {
    double x = 1;
    double y = 1;
};

template <class T>
T Sum(const T& a, const T& b){
    return a + b;
}

template <class T>
T Sub(const T& a, const T& b){
    return a - b;
}

template <class T>
T Mul(const T& a, const T& b){
    return a * b;
}

template <class T>
T Div(const T& a, const T& b){
    return a / b;
}

template <> Complex Sum<Complex>(const Complex& a, const Complex& b){
    
    Complex c;
    
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    
    return c;
}

template <> Complex Sub<Complex>(const Complex& a, const Complex& b){
    
    Complex c;
    
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    
    return c;
}

template <> Complex Mul<Complex>(const Complex& a, const Complex& b){
    
    Complex c;
    
    c.x = (a.x * b.x) - (a.y * b.y);
    c.y = (a.y * b.x) + (b.y * a.x);
    
    return c;
}

template <> Complex Div<Complex>(const Complex& a, const Complex& b){
    
    Complex c;
    
    if (b.x != 0 || b.y != 0) {
        c.x = ((a.x * b.x) + (a.y * b.y))/(b.x*b.x+b.y*b.y);
        c.y = ((a.y * b.x) - (b.y * a.x))/(b.x*b.x+b.y*b.y);
    } else {
        std::cout << "Enter valid diverse" << std::endl;
    }
    
    return c;
}

void init_c(Complex * c, double a, double b){
    
    c->x = a;
    c->y = b;
    
}

void cPrint(const Complex& C){ //the optional programming needed
    
    if (C.x != 0 && C.y != 0){
        if (C.y > 0){
            std::cout << C.x << "+i" << C.y << std::endl;
        } else {
            std::cout << C.x << "-i" << (-1)*C.y << std::endl;
        }
    } else {
        if (C.x == 0 && C.y == 0){
            std::cout << C.x << std::endl;
        } else {
            if (C.x != 0 && C.y == 0){
                std::cout << C.x << std::endl;
            } else {
                if (C.x == 0 && C.y > 0){ //look for mistake
                    std::cout << "i" << C.y << std::endl;
                } else {
                    std::cout << "-i" << (-1)*C.y << std::endl;
                }
            }
        }
    }
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
    
    Complex A;
    init_c(&A, a, b);
    Complex B;
    init_c(&B, b, a);
    Complex C;
    
    C = Sum(A, B);
    cPrint(C);
    
    C = Sub(A, B);
    cPrint(C);
    
    C = Mul(A, B);
    cPrint(C);
    
    C = Div(A, B);
    cPrint(C);
    
    return 0;
}
