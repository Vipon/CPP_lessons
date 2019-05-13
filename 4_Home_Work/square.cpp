#include "square.h"
#include <iostream>

void square::draw(){
    std::cout << "Centre of square = (" << Centre.x << ", " << Centre.y << ")" << std::endl;
    std::cout << "Radius of square = " << Side << std::endl;
    std::cout << "Argument of square = " << Argument << std::endl;
}

point &square::centre(){
    return Centre;
}

float &square::side(){
    return Side;
}

float &square::argument(){
    return Argument;
}
