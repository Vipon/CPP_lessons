#include "Rectangle.h"

void Rectangle::draw(SDL_Renderer* rend, int x, int y)
{
	SDL_Rect rectangle = { x, y, sideline1, sideline2 };
	SDL_RenderDrawRect(rend, &rectangle);
}
