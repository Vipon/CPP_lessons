#include "gObject.h"
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;


int main()
{
	Triangle tr(30, 40, 50);
	Circle cr(50);
	Segment seg(70);
	Square sq(55);
	Ellipse el(20, 30);
	gObject* obj[5] = {&tr, &cr, &seg, &sq, &el};

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Graphic Objects", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_Event event = {};
	bool quit = false;

	while (!quit)
	{
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				quit = true;
			}
		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		for (int i = 0; i < 5; i++) {
			(obj[i])->draw(renderer, 10 + (100 * i), 100);
			SDL_RenderPresent(renderer);
		}
	}
	SDL_Quit();	
	return 0;
} 
