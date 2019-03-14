#include "event.h"
#include "point2D.h"


void Event::poll()
{
    SDL_PollEvent(&event);
}


EventType Event::getType()
{
    return static_cast<EventType>(event.type);
}


void Event::setPoint2D(Point2D& p)
{
    p.x = event.motion.x;
    p.y = event.motion.y;
}
