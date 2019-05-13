#include "circle.h"
#include <iostream>

void circle::draw(){
    std::cout << "Centre of circle = (" << Centre.x << ", " << Centre.y << ")" << std::endl;
    std::cout << "Radius of circle = " << Radius << std::endl;
}

point &circle::centre(){
    return Centre;
}

float &circle::radius(){
    return Radius;
}
