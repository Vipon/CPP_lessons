#include <iostream>

using namespace std;

template <typename T>
T Sum(T &a, T &b){
return a + b;
}

template <typename T>
T Sub(T &a, T &b){
return a - b;
}

template <typename T>
T Mul(T &a, T &b){
return a * b;
}

template <typename T>
T Div(T &a, T &b){
return a / b;
}

int main(){
    double a = 5, b = 9;
    cout << Sum(a, b) << " " << Sub(a, b) << " " << Mul(a, b) << " " << Div(a, b) << endl;
    return 0;
}
