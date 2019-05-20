#include "gEllipse.h"
#include <iostream>

Ellipse::Ellipse(
    const double val_x, 
    const double val_y, 
    const double val_length, 
    const double val_width, 
    const double val_angle):
    x(val_x),
    y(val_y),
    length(val_length),
    width(val_width),
    angle(val_angle)
{};

void Ellipse::draw()
{
    std::cout <<"Ellipse with parameters: "
    <<"("<< x <<";"<< y <<")"
    <<" length = "<< length
    <<" width = "<< width
    <<" angle ="<< angle
    <<" was drawn"<< std::endl;
}