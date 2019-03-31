#include "window.h"
#include "graphException.h"
#include "render.h"

#include <cstdint>


Render::Render(Window& win)
{
    rend = SDL_CreateRenderer(win.win, -1, SDL_RENDERER_ACCELERATED);
}


Render::~Render()
{
    SDL_DestroyRenderer(rend);
}


void Render::clear()
{
    if (SDL_RenderClear(rend) < 0) {
        throw graphException(SDL_GetError());
    }
}


void Render::update()
{
    SDL_RenderPresent(rend);
}


void Render::setDrawColor(uint8_t r, uint8_t g, uint8_t b)
{
    if (SDL_SetRenderDrawColor(rend, r, g, b, SDL_ALPHA_OPAQUE) < 0) {
        throw graphException(SDL_GetError());
    }
}


void Render::refresh()
{
    setDrawColor(0, 0, 0);
    clear();
    update();
}


void Render::drawLine(const Point2D& p0, const Point2D& p1)
{
    if (SDL_RenderDrawLine(rend, p0.x, p0.y, p1.x, p1.y) < 0) {
        throw graphException(SDL_GetError());
    }
}
