#include <iostream>

using namespace std;

struct Complex {
    double x = 1;
    double y = 1;
};

template <class T>
T Sum(T a, T b){
    return a+b;
}

template <class T>
T Sub(T a, T b){
    return (a-b);
}

template <class T>
T Mul(T a, T b){
    return (a*b);
}

template <class T>
T Div(T a, T b){
    return (a/b);
}

template <> Complex Sum<Complex>(Complex a, Complex b){
   
    Complex c;
    
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    
    return c;
}

template <> Complex Sub<Complex>(Complex a, Complex b){
    
    Complex c;
    
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    
    return c;
}

template <> Complex Mul<Complex>(Complex a, Complex b){
    
    Complex c;
    
    c.x = (a.x * b.x) - (a.y * b.y);
    c.y = (a.y * b.x) + (b.y * a.x);
    
    return c;
}

template <> Complex Div<Complex>(Complex a, Complex b){
    
    Complex c;
    
    if (b.x != 0 || b.y != 0) {
        c.x = ((a.x * b.x) + (a.y * b.y))/(b.x*b.x+b.y*b.y);
        c.y = ((a.y * b.x) - (b.y * a.x))/(b.x*b.x+b.y*b.y);
    } else {
        cout << "Enter valid diverse" << endl;
    }
        
    return c;
}

void cPrint(Complex C){ //the optional programming needed
    
    if (C.x != 0 && C.y != 0){
    if (C.y > 0){
        cout << C.x << "+i" << C.y << endl;
    } else {
        cout << C.x << "-i" << (-1)*C.y << endl;
    }
    } else {
        if (C.x == 0 && C.y == 0){
            cout << C.x << endl;
        } else {
            if (C.x != 0 && C.y == 0){
                cout << C.x << endl;
            } else {
                if (C.x == 0 && C.y > 0){ //look for mistake
                    cout << "i" << C.y << endl;
                } else {
                    cout << "-i" << (-1)*C.y << endl;
                }
            }
        }
    }
}


void init_c(Complex * c, double a, double b){
    
    c->x = a;
    c->y = b;
    
}

int main() {
    
    double V = 1.0;
    double a = 1.0;
    double b = 1.0;
    
    cin >> a >> b;
    
    V = Sum(a, b);
    cout << V << endl;
    
    V = Sub(a, b);
    cout << V << endl;
    
    V = Mul(a, b);
    cout << V << endl;
    
    V = Div(a, b);
    cout << V << endl;
    
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
