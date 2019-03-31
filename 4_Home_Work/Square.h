#ifndef __SQUARE_H
#define __SQUARE_H

#include "Regular_Polygon.h"

class Square : public Regular_Polygon {
public:
    Square() : Regular_Polygon(0, 0) {};
    Square(int len) : Regular_Polygon(len, 4) {};
    ~Square() {};
};

#endif //__SQUARE_H