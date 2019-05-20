#include "gSquare.h"
#include <iostream>

Square::Square(
    const double val_x,
    const double val_y,
    const double val_length,
    const double val_angle):
    Rectangle(
        val_x, 
        val_y, 
        val_length, 
        val_length, 
        val_angle)
{};

void Square::draw()
{
    std::cout <<"Square with parameters: "
    <<"("<< x <<";"<< y <<")"
    <<" length = "<< length
    <<" angle ="<< angle
    <<" was drawn"<< std::endl;
}