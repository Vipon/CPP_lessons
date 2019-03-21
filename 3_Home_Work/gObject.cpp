#include <iostream>
#include "gObject.h"

void segment::draw(){
    std::cout << "First point of segment = (" << First.x << ", " << First.y << ")" << std::endl;
    std::cout << "Second point of segment = (" << Second.x << ", " << Second.y << ")" << std::endl;
}

void triangle::draw(){
    std::cout << "First point of triangle = (" << First.x << ", " << First.y << ")" << std::endl;
    std::cout << "Second point of triangle = (" << Second.x << ", " << Second.y << ")" << std::endl;
    std::cout << "Third point of triangle = (" << Third.x << ", " << Third.y << ")" << std::endl;
}

void circle::draw(){
    std::cout << "Centre of circle = (" << Centre.x << ", " << Centre.y << ")" << std::endl;
    std::cout << "Radius of circle = " << Radius << std::endl;
}

void square::draw(){
    std::cout << "Centre of square = (" << Centre.x << ", " << Centre.y << ")" << std::endl;
    std::cout << "Radius of square = " << Radius << std::endl;
    std::cout << "Argument of square = " << Argument << std::endl;
}

void ellipse::draw(){
    std::cout << "Centre of ellipse = (" << Centre.x << ", " << Centre.y << ")" << std::endl;
    std::cout << "A of ellipse = " << Radius << std::endl;
    std::cout << "B of ellipse = " << B << std::endl;
    std::cout << "Argument of ellipse = " << Argument << std::endl;
}

void rectangle::draw(){
    std::cout << "Centre of rectangle = (" << Centre.x << ", " << Centre.y << ")" << std::endl;
    std::cout << "A of rectangle = " << Radius << std::endl;
    std::cout << "B of rectangle = " << B << std::endl;
    std::cout << "Argument of rectangle = " << Argument << std::endl;
}
