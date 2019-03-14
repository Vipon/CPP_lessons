#ifndef __WINDOW_H
#define __WINDOW_H

#include <string>
#include <SDL2/SDL.h>

class Window {

public:

    Window( int width = 640,
            int height = 480,
            const std::string& title = "",
            int xPos = SDL_WINDOWPOS_UNDEFINED,
            int yPos = SDL_WINDOWPOS_UNDEFINED  );
    ~Window();

private:

    int width;
    int height;
    std::string title;
    int xPos;
    int yPos;

    SDL_Window* win;

    friend class Render;
};

#endif /* __WINDOW_H */
