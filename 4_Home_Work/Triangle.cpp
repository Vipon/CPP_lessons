#include "Triangle.h"
#include <cmath>

void Triangle::draw(SDL_Renderer* renderer, int x, int y)
{
    SDL_RenderDrawLine(renderer, x, y, x + a, y);
    double cosa = static_cast<double>((a * a) + (b * b) - (c * c)) / (2 * a * b);
    int x0 = static_cast<int>(a * cosa);
    int y0 = static_cast<int>(b * sqrt(1 - (cosa * cosa)));
    SDL_RenderDrawLine(renderer, x, y, x + x0, y + y0);
    SDL_RenderDrawLine(renderer, x + x0, y + y0, x + a, y);
}