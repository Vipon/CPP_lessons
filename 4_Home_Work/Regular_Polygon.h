#ifndef __REGULAR_POLYGON_H
#define __REGULAR_POLYGON_H

#include "gObject.h"

class Regular_Polygon : public gObject {
public:
    Regular_Polygon() : len(0), n(0) {};
    Regular_Polygon(int len, int n) : len(len), n(n) {};
    ~Regular_Polygon() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int len; // length of one side
    int n; // number of sides
};

#endif //__REGULAR_POLYGON_H