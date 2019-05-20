#include "gSegment.h"
#include <iostream>

Segment::Segment(
        const double val_x,
        const double val_y,
        const double val_length,
        const double val_angle):
    Rectangle(
        val_x, 
        val_y, 
        val_length, 
        0, 
        val_angle)
{};

void Segment::draw()
{
    std::cout <<"Segment with parameters: "
    <<"("<< x <<";"<< y <<")"
    <<" length = "<< length
    <<" angle ="<< angle
    <<" was drawn"<< std::endl;
}