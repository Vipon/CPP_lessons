#ifndef CPPMath_0_hpp
#define CPPMath_0_hpp

#include <iostream>

using namespace std;

struct Complex { //structure of Complex numbers
    double x = 1;
    double y = 1;
};

template <class T> //common functions
T Sum(T a, T b);

template <class T>
T Sub(T a, T b);

template <class T>
T Mul(T a, T b);

template <class T>
T Div(T a, T b);

template <> Complex Sum<Complex>(Complex a, Complex b); //Comlex functions

template <> Complex Sub<Complex>(Complex a, Complex b);

template <> Complex Mul<Complex>(Complex a, Complex b);

template <> Complex Div<Complex>(Complex a, Complex b);

void cPrint(Complex C);

void init_c(Complex * c, double a, double b);

#endif /* CPPMath_0_hpp */
