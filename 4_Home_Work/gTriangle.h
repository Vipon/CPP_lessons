#ifndef GTRIANGLE
#define GTRIANGLE

#include "gObject.h"

class Triangle : public G_Object
{
private:
    const double x1;
    const double y1;
    const double x2;
    const double y2;
    const double x3;
    const double y3;
    /*(xi;yi) - one point of Quadrangle, where i = 1,2,3*/
public:
    Triangle(
        const double val_x1, 
        const double val_y1, 
        const double val_x2, 
        const double val_y2, 
        const double val_x3, 
        const double val_y3);
    virtual ~Triangle(){};
    virtual void draw();
};

#endif //GTRIANGLE