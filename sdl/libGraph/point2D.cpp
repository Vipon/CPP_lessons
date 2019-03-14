#include "point2D.h"

#include <iostream>


std::ostream& operator<<(std::ostream& os, const Point2D& p)
{
    os << '(' << p.x << ", " << p.y << ')';
    return os;
}
