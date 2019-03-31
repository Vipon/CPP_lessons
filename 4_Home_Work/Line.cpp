#include "Line.h"

void Line::draw(SDL_Renderer* renderer, int x, int y)
{
    SDL_RenderDrawLine(renderer, x, y, x + len, y);
}