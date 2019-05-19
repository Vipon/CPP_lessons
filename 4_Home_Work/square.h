#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle {
public:
	Square() : Rectangle(0, 0) {};
	Square(int width) : Rectangle(width, width) {};
	virtual ~Square() {};
};

#endif