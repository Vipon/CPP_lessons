#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include "gObject.h"

class Rectangle : public gObject {
public:
    Rectangle() : a(0), b(0) {};
    Rectangle(int a, int b) : a(a), b(b) {};
    ~Rectangle() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int a; //length of first side
    int b; //length of second size
};

#endif //__RECTANGLE_H