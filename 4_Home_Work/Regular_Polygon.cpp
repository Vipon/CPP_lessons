#include "Regular_Polygon.h"

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
