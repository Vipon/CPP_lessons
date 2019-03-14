#ifndef __MEDIA_APP_H
#define __MEDIA_APP_H

#include <SDL2/SDL.h>
#include <cstdint>


enum mediaInitFlag {
    INIT_TIMER = SDL_INIT_TIMER,
    INIT_AUDIO = SDL_INIT_AUDIO,
    INIT_VIDEO = SDL_INIT_VIDEO,
    INIT_JOYSTICK = SDL_INIT_JOYSTICK,
    INIT_HAPTIC = SDL_INIT_HAPTIC,
    INIT_GAMECONTROLLER = SDL_INIT_GAMECONTROLLER,
    INIT_EVENTS = SDL_INIT_EVENTS,
    INIT_EVERYTHING = SDL_INIT_EVERYTHING
};

class mediaApp {

public:

    mediaApp(mediaInitFlag flag);
    ~mediaApp();

    void start(void (*program)());
    static void delay(uint32_t ms);
};

#endif /* __MEDIA_APP_H */
