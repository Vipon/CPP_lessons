#include "Triangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Segment.h"
#include "Square.h"
#include <SDL2/SDL.h>
#include <iostream>

const int width = 1280;
const int height = 960;


int main()
{
	std::cout << "trangle parameters; " << std::endl;
	size_t trline1, trline2, trline3;
	std::cin >> trline1 >> trline2 >> trline3;
	Triangle tr(trline1, trline2, trline3);

	std::cout << "circle radius; " << std::endl;
	size_t radius;
	std::cin >> radius;
	Circle ci(radius);

	std::cout << "ellips axes; " << std::endl;
	size_t bigaxis, smallaxis;
	std::cin >> bigaxis >> smallaxis;
	Ellipse el(smallaxis, bigaxis);

	std::cout << "square side; " << std::endl;
	size_t sqside;
	std::cin >> sqside;
	Square sq(sqside);

	std::cout << "segment lenght; " << std::endl;
	size_t segmentlength;
	std::cin >> segmentlength;
	Segment seg(segmentlength);

	gObject* gOb[5] = { &tr, &ci, &seg, &sq, &el };

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("figures", 0, 0, width, height, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* rend = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_Event peremennaya = {};
	bool exit = false;

	while (!exit)
	{
		while (SDL_PollEvent(&peremennaya) != 0)
		{
			if (peremennaya.type == SDL_QUIT)
			{
				exit = true;
			}
		}

		SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
		SDL_RenderClear(rend);
		SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

		for (int i = 0; i < 5; i++)
		{
			(gOb[i])->draw(rend, 10 + (100 * i), 100);
		}
		SDL_RenderPresent(rend);
	}

	SDL_Quit();
}