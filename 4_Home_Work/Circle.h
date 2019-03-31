#ifndef __CIRCLE_H
#define __CIRCLE_H

#include "Ellipse.h"

class Circle : public Ellipse {
public:
    Circle() : Ellipse(0, 0) {};
    Circle(int r) : Ellipse(r, r) {}; // r for radius
    ~Circle() {};

};

#endif //__CIRCLE_H