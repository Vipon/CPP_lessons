#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include "gObject.h"

class Triangle : public gObject {
public:
    Triangle() : a(0), b(0), c(0) {};
    Triangle(int a, int b, int c) : a(a), b(b), c(c) {};
    ~Triangle() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int a; //lenth of first side
    int b; //lenth of second side
    int c; //lenth of third side
};

#endif //__TRIANGLE_H