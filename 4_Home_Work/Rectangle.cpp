#include "Rectangle.h"

void Rectangle::draw(SDL_Renderer* renderer, int x, int y)
{
	SDL_Rect rec = {x, y, side1, side2};
	SDL_RenderDrawRect(renderer, &rec);
}
