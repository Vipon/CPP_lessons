#ifndef __LINE_H
#define __LINE_H

#include "gObject.h"

class Line : public gObject {
public:
    Line(int len = 0) : len(len) {};
    ~Line() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int len; //length of line 
};

#endif //__LINE_H