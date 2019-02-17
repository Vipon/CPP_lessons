#include "CPPMath_0.hpp"

template <class T> //common operations, Math_0
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
    if (b == 0) {
        cout << "Dividing by 0 is forbiden here " << endl;
        return -2;
    }
    return (a/b);
}

template <> Complex Sum<Complex>(Complex a, Complex b){ //Complex operations, Math_1
   
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

void init_c(Complex * c, double a, double b){ //initializatiom of Complex Variable
    
    c->x = a;
    c->y = b;
    
}
