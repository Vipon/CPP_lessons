#ifndef __ELLIPSE_H
#define __ELLIPSE_H

#include "gObject.h"

class Ellipse : public gObject {
public:
    Ellipse() : width(0), hight(0) {};
    Ellipse(int width, int hight) : width(width), hight(hight) {};
    ~Ellipse() {};

    //Draw a pixel for the first quadrant and, simmetrically, for others
    void pixel4(SDL_Renderer* renderer, int x, int y, int _x, int _y);

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int width;
    int hight;
};

#endif //__ELLIPSE_H