#include "gObject.h"
#include <cmath>
#include <cstdio>


void pixel4(SDL_Renderer* renderer, int x, int y, int _x, int _y)
{
    SDL_RenderDrawPoint(renderer, x + _x, y + _y);
    SDL_RenderDrawPoint(renderer, x + _x, y - _y);
    SDL_RenderDrawPoint(renderer, x - _x, y - _y);
    SDL_RenderDrawPoint(renderer, x - _x, y + _y);
}


void Line::draw(SDL_Renderer* renderer, int x, int y)
{
    SDL_RenderDrawLine(renderer, x, y, x + len, y);
}


void Triangle::draw(SDL_Renderer* renderer, int x, int y)
{
    SDL_RenderDrawLine(renderer, x, y, x + a, y);
    double cosa = static_cast<double>((a * a) + (b * b) - (c * c)) / (2 * a * b);
    int x0 = static_cast<int>(b * cosa);
    int y0 = static_cast<int>(b * sqrt(1 - (cosa * cosa)));
    SDL_RenderDrawLine(renderer, x, y, x + x0, y + y0);
    SDL_RenderDrawLine(renderer, x + x0, y + y0, x + a, y);
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


void Rectangle::draw(SDL_Renderer* renderer, int x, int y)
{
    SDL_Rect rec = { x, y, a, b };
    SDL_RenderDrawRect(renderer, &rec);
}


void Regular_Polygon::draw(SDL_Renderer* renderer, int x, int y) {
    int v = 0;
    auto *px = new double[n + 1]; //Массив для хранения точек x
    auto *py = new double[n + 1]; //Массив для хранения точек y

    px[0] = x;
    py[0] = y;

    double pi = 3.1415926535897; //Это должно быть число ПИ

   //ПОИСК ТОЧЕК
    for (int i = 1; i < n + 1; i++)
    {
        {
            px[i] = px[i - 1] + len * cos(v*pi / 180);
            py[i] = py[i - 1] + len * sin(v*pi / 180);
        }
        v = v + 360 / n;
    }
    //ПОСЛЕДОВАТЕЛЬНО СОЕДИНЯЕМ ТОЧКИ
    for (int i = 1; i < n + 1; i++)
    {
        SDL_RenderDrawLine(renderer, int(px[i - 1]), int(py[i - 1]), int(px[i]), int(py[i]));
    }
    delete[]px; //Освобождаем память
    delete[]py; //Освобождаем память
}
