#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "gObject.h"

class triangle : public gObject{
private:
    point First;
    point Second;
    point Third;
public:
    point &first();
    point &second();
    point &third();
    triangle(const point first = {0, 0}, const point second = {0, 0}, const point third = {0, 0}) : First(first), Second(second), Third(third) {};
    ~triangle(){};
    virtual void draw();
};


#endif // TRIANGLE_H_INCLUDED
