#include "gTriangle.h"
#include <iostream>

Triangle::Triangle(
    const double val_x1, 
    const double val_y1, 
    const double val_x2, 
    const double val_y2, 
    const double val_x3, 
    const double val_y3):
    x1(val_x1),
    y1(val_y1),
    x2(val_x2),
    y2(val_y2),
    x3(val_x3),
    y3(val_y3)
{};

void Triangle::draw()
{
    std::cout <<"Triangle with parameters: "
    <<" ("<< x1 <<";"<< y1 <<") "
    <<" ("<< x2 <<";"<< y2 <<") "
    <<" ("<< x3 <<";"<< y3 <<") "
    <<"was drawn"<< std::endl;
}