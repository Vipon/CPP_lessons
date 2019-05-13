#include "segment.h"
#include <iostream>

void segment::draw(){
    std::cout << "First point of segment = (" << First.x << ", " << First.y << ")" << std::endl;
    std::cout << "Second point of segment = (" << Second.x << ", " << Second.y << ")" << std::endl;
}

point &segment::first(){
    return First;
}

point &segment::second(){
    return Second;
}
