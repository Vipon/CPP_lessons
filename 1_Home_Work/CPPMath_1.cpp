#include <iostream>

using namespace std;

struct Complex{
    double Re;
    double Im;
};

template <typename T>
T Sum(T &a, T &b){
    return a + b;
}

template <>
Complex Sum <Complex> (Complex &a, Complex &b){
    return {a.Re + b.Re, a.Im + b.Im};
}

template <typename T>
T Sub(T &a, T &b){
    return a - b;
}

template <>
Complex Sub <Complex> (Complex &a, Complex &b){
    return {a.Re - b.Re, a.Im - b.Im};
}

template <typename T>
T Mul(T &a, T &b){
    return a * b;
}

template <>
Complex Mul <Complex> (Complex &a, Complex &b){
    return {a.Re * b.Re - a.Im * b.Im, a.Im * b.Re + a.Re * b.Im};
}

template <typename T>
T Div(T &a, T &b){
    return a / b;
}

template <>
Complex Div <Complex> (Complex &a, Complex &b){
    return {(a.Re * b.Re + a.Im * b.Im)/(b.Re * b.Re + b.Im * b.Im), (a.Im * b.Re - a.Re * b.Im)/(b.Re * b.Re + b.Im * b.Im)};
}

ostream &operator<<(ostream &out, Complex C){
    out << C.Re << "+" << C.Im << "i";
    return out;
}

int main(){
    double a = 5, b = 9;
    Complex c = {1, 0}, d= {0, 1};
    cout << Sum(a, b) << " " << Sub(a, b) << " " << Mul(a, b) << " " << Div(a, b) << endl;
    cout << Sum(c, d) << " " << Sub(c, d) << " " << Mul(c, d) << " " << Div(c, d) << endl;
    return 0;
}
