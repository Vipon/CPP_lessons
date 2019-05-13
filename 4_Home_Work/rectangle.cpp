#include "rectangle.h"
#include <iostream>

void rectangle::draw(){
    std::cout << "Centre of rectangle = (" << centre().x << ", " << centre().y << ")" << std::endl;
    std::cout << "A of rectangle = " << side() << std::endl;
    std::cout << "B of rectangle = " << B << std::endl;
    std::cout << "Argument of rectangle = " << argument() << std::endl;
}

float &rectangle::b(){
    return B;
}
