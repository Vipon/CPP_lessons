#ifndef __GOBJECT_H
#define __GOBJECT_H

#include <SDL2/SDL.h>

class gObject {
public:
    virtual ~gObject() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y) = 0;
};

#endif //__GOBJECT_H 