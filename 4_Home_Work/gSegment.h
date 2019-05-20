#ifndef GSERGMENT
#define GSERGMENT value

#include "gRectangle.h"

class Segment : public Rectangle
{
public:
    Segment(
        const double val_x,
        const double val_y,
        const double val_length,
        const double val_angle);
    /*(x;y) - one point of Segment
    angle - angle between Ox and Segment*/
    virtual ~Segment() = default;
    virtual void draw();
};

#endif //GSERGMENT