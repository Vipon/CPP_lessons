#include "Segment.h"

void Segment::draw(SDL_Renderer* renderer, int x, int y) 
{
	SDL_RenderDrawLine(renderer, x, y, x + length, y);
}