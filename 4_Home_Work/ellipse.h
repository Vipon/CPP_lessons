#ifndef ELLIPSE_H_INCLUDED
#define ELLIPSE_H_INCLUDED

#include "circle.h"
#include "gObject.h"

class ellipse : public circle{
private:
    float B;
    float Argument;
public:
    float &b();
    float &argument();
    ellipse(const point centre = {0, 0}, const float a = 0, const float b = 0, const float argument = 0) : circle(centre, a), B(b), Argument(argument) {};
    ~ellipse(){};
    virtual void draw();
};

#endif // ELLIPSE_H_INCLUDED
