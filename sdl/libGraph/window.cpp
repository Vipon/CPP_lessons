#include "window.h"
#include "graphException.h"

#include <SDL2/SDL.h>

#include <string>


Window::Window(int width, int height, const std::string& title, int xPos, int yPos)
    :   width(width),
        height(height),
        title(title),
        xPos(xPos),
        yPos(yPos)
{
    win = SDL_CreateWindow(title.c_str(), xPos, yPos, width, height, SDL_WINDOW_OPENGL);
    if (win == nullptr) {
        throw graphException(SDL_GetError());
    }
}


Window::~Window()
{
    SDL_DestroyWindow(win);
}
