#include <iostream>

using namespace std;

class Complex{
public:
    double Re;
    double Im;
};

template <typename T, typename R>
auto Mul(T &a, R &b){
return a * b;
}

template <>
auto Mul <Complex, double> (Complex &a, double &b){
return (Complex) {a.Re * b, a.Im * b};
}

template <>
auto Mul <double, Complex> (double &a, Complex &b){
return (Complex) {b.Re * a, b.Im * a};
}

template <>
auto Mul <Complex, Complex> (Complex &a, Complex &b){
return (Complex) {a.Re * b.Re - a.Im * b.Im, a.Im * b.Re + a.Re * b.Im};
}

ostream &operator<<(ostream &out, Complex C){
out << C.Re << "+" << C.Im << "i";
return out;
}

int main(){
    double a = 5, b = 9;
    Complex c = {1, 0}, d= {0, 1};
    cout << Mul(a, b) << endl;
    cout << Mul(c, d) << endl;
    cout << Mul(a, d) << endl;
    cout << Mul(c, b) << endl;
    return 0;
}
