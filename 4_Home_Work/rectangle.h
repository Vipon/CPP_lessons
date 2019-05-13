#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "square.h"
#include "gObject.h"

class rectangle : public square{
private:
    float B;
public:
    float &b();
    rectangle(const point centre = {0, 0}, const float a = 0, const float b = 0, const float argument = 0) : square(centre, a, argument), B(b) {};
    ~rectangle(){};
    virtual void draw();
};

#endif // RECTANGLE_H_INCLUDED
