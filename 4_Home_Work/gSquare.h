#ifndef GSQARE
#define GSQARE

#include "gRectangle.h"

class Square : public Rectangle
{
public:
    Square(
        const double val_x,
        const double val_y,
        const double val_length,
        const double val_angle);
    /*(x;y) - one point of Square
    angle - angle between Ox and one of sides*/
    virtual ~Square(){};
    virtual void draw();
};

#endif //GSQARE