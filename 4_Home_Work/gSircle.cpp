#include "gSircle.h"
#include <iostream>

Circle::Circle(const double val_x, const double val_y, const double val_radius):
    Ellipse(val_x - val_radius, val_y - val_radius, 2*val_radius, 2*val_radius, 0)
{};

void Circle::draw()
{
    std::cout <<"Circle with parameters: "
    <<"("<< x + length/2 <<";"<< y + length/2 <<") - centure, "
    <<" radius = "<< length/2
    <<" was drawn"<< std::endl;
};