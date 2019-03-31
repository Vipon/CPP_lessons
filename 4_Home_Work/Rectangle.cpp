#include "Rectangle.h"

void Rectangle::draw(SDL_Renderer* renderer, int x, int y)
{
    SDL_Rect rec = { x, y, a, b };
    SDL_RenderDrawRect(renderer, &rec);
}