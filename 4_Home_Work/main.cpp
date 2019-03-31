#include "Triangle.h"
#include "Circle.h"
#include "Line.h"
#include "Square.h"
#include "Ellipse.h"
#include "Regular_Polygon.h"
#include <SDL2/SDL.h>
#include <cstdio>
#include <cmath>

//Некоторые константы нашего окна
const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 720;

int main()
{
    //Какое окно будет рендерится
    SDL_Window* window = nullptr;

    //Поверхность окна
    SDL_Surface* screenSurface = nullptr;

    //Включим SDL
    SDL_Init(SDL_INIT_VIDEO);


     //Создаем окно
     window = SDL_CreateWindow("Try", 400, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

     //Отрисовка фигур не 100% точна, тк я решил использовать только int

     Triangle tr(35, 45, 55);
     Circle cr(45);
     Line lin(100);
     Square sq(55);
     Ellipse el(30, 20);
     Regular_Polygon re(50,7); //first size of a side then number of sides 
     gObject* obj[6] = { &tr, &cr, &lin, &sq, &el, &re };

     SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

     SDL_Event event = {};
     bool quit = false;

     while (!quit)
         {
              while (SDL_PollEvent(&event)) {
                  if (event.type == SDL_QUIT) {
                      quit = true;
                  }
              }

              SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
              SDL_RenderClear(renderer);
              SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

              for (int i = 0; i < 6; i++) {
                  (obj[i])->draw(renderer, 10 + (75 * i), 10 + (75 * i));
              }
               
              SDL_RenderPresent(renderer);
              //обновляем окно каждый цикл
         } 


    //Удаляем из памяти окно
    SDL_DestroyWindow(window);

    //Выход из SDL
    SDL_Quit();

    return 0;
}