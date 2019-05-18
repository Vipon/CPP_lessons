#include "Ellipse.h"

void Ellipse::_4points(SDL_Renderer* rend, int x, int y, int x_1, int y_1)
{
	SDL_RenderDrawPoint(rend, x + x_1, y + y_1);
	SDL_RenderDrawPoint(rend, x + x_1, y - y_1);
	SDL_RenderDrawPoint(rend, x - x_1, y - y_1);
	SDL_RenderDrawPoint(rend, x - x_1, y + y_1);
}


void Ellipse::draw(SDL_Renderer* rend, int x, int y)
{
	int x_1 = 0;
	int y_1 = b;
	size_t A = a * a;
	size_t B = b * b;
	int sqr_part = 4 * B * ((x_1 + 1) * (x_1 + 1)) + A * ((2 * y_1 - 1) * (2 * y_1 - 1)) - 4 * A * B;

	while (A * (2 * y_1 - 1) > 2 * B * (x_1 + 1))
	{
		_4points(rend, x, y, x_1, y_1);
		if (sqr_part < 0) {
			x_1++;
			sqr_part += 4 * B * (2 * x_1 + 3);
		}
		else {
			x_1++;
			sqr_part = sqr_part - 8 * A * (y_1 - 1) + 4 * B * (2 * x_1 + 3);
			y_1--;
		}
	}

	sqr_part = B * ((2 * x_1 + 1) * (2 * x_1 + 1)) + 4 * A * ((y_1 + 1) * (y_1 + 1)) - 4 * A * B;

	while (y_1 + 1 != 0)
	{
		_4points(rend, x, y, x_1, y_1);
		if (sqr_part < 0) {
			y_1--;
			sqr_part += 4 * A * (2 * y_1 + 3);
		}
		else {
			y_1--;
			sqr_part = sqr_part - 8 * B * (x_1 + 1) + 4 * A * (2 * y_1 + 3);
			x_1++;
		}
	}
}