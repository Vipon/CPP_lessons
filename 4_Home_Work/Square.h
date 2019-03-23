#ifndef __SQUARE_H
#define __SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
public:
	Square() : Rectangle(0, 0) {};
	Square(int a) : Rectangle (a, a) {};
	virtual ~Square() {};
};

#endif //__SQUARE_H