#include "ellipse.h"
#include <iostream>

void ellipse::draw(){
    std::cout << "Centre of ellipse = (" << centre().x << ", " << centre().y << ")" << std::endl;
    std::cout << "A of ellipse = " << radius() << std::endl;
    std::cout << "B of ellipse = " << B << std::endl;
    std::cout << "Argument of ellipse = " << Argument << std::endl;
}

float &ellipse::b(){
    return B;
}

float &ellipse::argument(){
    return Argument;
}
