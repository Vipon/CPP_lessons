#include "Segment.h"

void Segment::draw(SDL_Renderer* rend, int x, int y)
{
	SDL_RenderDrawLine(rend, x, y, x + length, y);
}