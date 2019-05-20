#ifndef GRECTANGLE
#define GRECTANGLE

#include "gObject.h"

class Rectangle : public G_Object
{
protected:
    const double x;
    const double y;
    const double length;
    const double width;
    const double angle;
    /* If name of Rectangle is ABCD, then
    (x;y) - point A
    length - length of side AB
    width - length of side DA
    angle - angle between Ox and side AB */
public:
    Rectangle(
        const double val_x, 
        const double val_y, 
        const double val_length, 
        const double val_width, 
        const double val_angle);
    virtual ~Rectangle(){};
    virtual void draw();
};
#endif //GRECTANGLE