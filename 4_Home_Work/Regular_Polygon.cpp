#include "Regular_Polygon.h"

void Regular_Polygon::draw(SDL_Renderer* renderer, int x, int y) {
    int v = 0;
    auto *px = new double[n + 1];
    auto *py = new double[n + 1];

    px[0] = x;
    py[0] = y;

    double pi = 3.1415926535897;

    for (int i = 1; i < n + 1; i++)
    {
        {
            px[i] = px[i - 1] + len * cos(v*pi / 180);
            py[i] = py[i - 1] + len * sin(v*pi / 180);
        }
        v = v + 360 / n;
    }
    for (int i = 1; i < n + 1; i++)
    {
        SDL_RenderDrawLine(renderer, int(px[i - 1]), int(py[i - 1]), int(px[i]), int(py[i]));
    }
    delete[]px;
    delete[]py;
}