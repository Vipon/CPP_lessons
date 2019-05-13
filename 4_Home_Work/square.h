#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include "gObject.h"

class square : public gObject{
private:
    point Centre;
    float Side;
    float Argument;
public:
    point &centre();
    float &side();
    float &argument();
    square(const point centre = {0, 0}, const float side = 0, const float argument = 0) : Centre(centre), Side(side), Argument(argument) {};
    ~square(){};
    virtual void draw();
};

#endif // SQUARE_H_INCLUDED
