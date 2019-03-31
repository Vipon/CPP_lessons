#include "Ellipse.h"

void Ellipse::pixel4(SDL_Renderer* renderer, int x, int y, int _x, int _y)
{
    SDL_RenderDrawPoint(renderer, x + _x, y + _y);
    SDL_RenderDrawPoint(renderer, x + _x, y - _y);
    SDL_RenderDrawPoint(renderer, x - _x, y - _y);
    SDL_RenderDrawPoint(renderer, x - _x, y + _y);
}


void Ellipse::draw(SDL_Renderer* renderer, int x, int y)
{
    int _x = 0;
    int _y = hight;
    int a_sqr = width * width;
    int b_sqr = hight * hight;
    int delta = 4 * b_sqr * ((_x + 1) * (_x + 1)) + a_sqr * ((2 * _y - 1) * (2 * _y - 1)) - 4 * a_sqr * b_sqr; // Функция координат точки (x+1, y-1/2)
    while (a_sqr * (2 * _y - 1) > 2 * b_sqr * (_x + 1))
    {
        pixel4(renderer, x, y, _x, _y);
        if (delta < 0) {
            _x++;
            delta += 4 * b_sqr * (2 * _x + 3);
        }
        else {
            _x++;
            delta = delta - 8 * a_sqr * (_y - 1) + 4 * b_sqr * (2 * _x + 3);
            _y--;
        }
    }

    delta = b_sqr * ((2 * _x + 1) * (2 * _x + 1)) + 4 * a_sqr * ((_y + 1) * (_y + 1)) - 4 * a_sqr * b_sqr;
    while (_y + 1 != 0)
    {
        pixel4(renderer, x, y, _x, _y);
        if (delta < 0) {
            _y--;
            delta += 4 * a_sqr * (2 * _y + 3);
        }
        else {
            _y--;
            delta = delta - 8 * b_sqr * (_x + 1) + 4 * a_sqr * (2 * _y + 3);
            _x++;
        }
    }
}

