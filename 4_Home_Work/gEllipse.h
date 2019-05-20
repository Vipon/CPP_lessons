#ifndef GELLIPSE
#define GELLIPSE

#include "gObject.h"

class Ellipse : public G_Object
{
protected:
    const double x;
    const double y;
    const double length;
    const double width;
    const double angle;
    /*It's ellipse that inscribed in Rectangle(double x1, double y1,
     double x2, double y2, double angle) */
public:
    Ellipse(
        const double val_x, 
        const double val_y, 
        const double val_length, 
        const double val_width, 
        const double val_angle);
    virtual ~Ellipse(){};
    virtual void draw();
};
#endif //GELLIPSE