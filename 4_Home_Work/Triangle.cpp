#include "Triangle.h"
#include <cmath>

void Triangle::draw(SDL_Renderer* renderer, int x, int y)
{
	SDL_RenderDrawLine(renderer, x, y, x + side1, y);
	double cosa = static_cast<double>((side1 * side1) + (side2 * side2) - (side3 * side3)) / (2 * side1 * side2);
	int x0 = static_cast<int>(side2 * cosa);
	int y0 = static_cast<int>(side2 * sqrt(1 - (cosa * cosa)));
	SDL_RenderDrawLine(renderer, x, y, x + x0, y + y0);
	SDL_RenderDrawLine(renderer, x + x0, y + y0, x + side1, y);
}