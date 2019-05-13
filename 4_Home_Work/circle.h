#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "gObject.h"

class circle : public gObject{
private:
    point Centre;
    float Radius;
public:
    point &centre();
    float &radius();
    circle(const point centre = {0, 0}, const float radius = 0) : Centre(centre), Radius(radius) {};
    ~circle(){};
    virtual void draw();
};

#endif // CIRCLE_H_INCLUDED
