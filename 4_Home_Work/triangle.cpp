#include "triangle.h"
#include <iostream>

void triangle::draw(){
    std::cout << "First point of triangle = (" << First.x << ", " << First.y << ")" << std::endl;
    std::cout << "Second point of triangle = (" << Second.x << ", " << Second.y << ")" << std::endl;
    std::cout << "Third point of triangle = (" << Third.x << ", " << Third.y << ")" << std::endl;
}

point &triangle::first(){
    return First;
}

point &triangle::second(){
    return Second;
}

point &triangle::third(){
    return Third;
}
