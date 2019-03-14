#ifndef __2D_POINT_H
#define __2D_POINT_H

#include <iostream>


class Point2D {

public:

    friend std::ostream& operator<<(std::ostream& os, const Point2D& p);

private:
    int x;
    int y;

    friend class Event;
    friend class Render;
};

#endif /* __2D_POINT_H */
