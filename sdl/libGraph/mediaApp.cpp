#include <SDL2/SDL.h>

#include "graphException.h"
#include "mediaApp.h"


mediaApp::mediaApp(mediaInitFlag flag)
{
    if (SDL_Init(flag) < 0) {
        throw graphException(SDL_GetError());
    }
}


mediaApp::~mediaApp()
{
    SDL_Quit();
}


void mediaApp::start(void (*program)())
{
    program();
}


void mediaApp::delay(uint32_t ms)
{
    SDL_Delay(ms);
}
