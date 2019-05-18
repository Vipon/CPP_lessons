#include "Triangle.h"
#include <cmath>

void Triangle::draw(SDL_Renderer* rend, int x, int y)
{
	SDL_RenderDrawLine(rend, x, y, x + sideline1, y);
	double cosinus = static_cast<double>((sideline1 * sideline1) + (sideline2 * sideline2) - (sideline3 * sideline3)) / (2 * sideline1 * sideline2);
	int x_0 = static_cast<int>(sideline2 * cosinus);
	int y_0 = static_cast<int>(sideline2 * sqrt(1 - (cosinus * cosinus)));
	SDL_RenderDrawLine(rend, x, y, x + x_0, y + y_0);
	SDL_RenderDrawLine(rend, x + x_0, y + y_0, x + sideline1, y);
}