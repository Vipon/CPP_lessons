#ifndef __RENDER_H
#define __RENDER_H

#include "window.h"
#include "point2D.h"

#include <SDL2/SDL.h>
#include <cstdint>


class Render {

public:

    Render(Window& win);
    ~Render();

    //  Clear the current rendering target with the drawing color.
    void clear();
    //  Update the screen with any rendering performed since the previous call.
    void update();
    //  Set the color used for drawing operations.
    void setDrawColor(uint8_t r, uint8_t g, uint8_t b);
    // Set the black screen.
    void refresh();

    void drawLine(const Point2D& p0, const Point2D& p1);

private:

    SDL_Renderer *rend;

};

#endif /* __RENDER_H */
