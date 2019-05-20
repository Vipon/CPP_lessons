#ifndef GSIRCLE
#define GSIRCLE

#include "gObject.h"
#include "gEllipse.h"

class Circle : public Ellipse
{
public:
    Circle(const double val_x, const double val_y, const double val_radius);
    /*(x;y) - centure */
    virtual ~Circle(){};
    virtual void draw();
};

#endif //GSIRCLE