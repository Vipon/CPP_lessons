#ifndef SEGMENT_H_INCLUDED
#define SEGMENT_H_INCLUDED

#include "gObject.h"

class segment : public gObject{
private:
    point First;
    point Second;
public:
    point &first();
    point &second();
    segment(const point first = {0, 0}, const point second = {0, 0}) : First(first), Second(second) {};
    ~segment(){};
    virtual void draw();
};

#endif // SEGMENT_H_INCLUDED
