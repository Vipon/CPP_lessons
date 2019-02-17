#include "CPPMath_0.hpp"

int main() {
    
    double V = 1.0; //initialisation of variatives for test of 0 HW
    double a = 1.0;
    double b = 1.0;
    
    cin >> a >> b;
    
    V = Sum(a, b); //checking sum
    cout << V << endl;
    
    V = Sub(a, b); //checking sublime
    cout << V << endl;
    
    V = Mul(a, b); //checking multiplication
    cout << V << endl;
    
    V = Div(a, b); //checking divide
    cout << V << endl;
    
    Complex A; // testing of Complex functions
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
