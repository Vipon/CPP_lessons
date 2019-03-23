#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include "gObject.h"

class Rectangle : public gObject {
public:
	Rectangle() : side1(0), side2(0) {};
	Rectangle(int side1, int side2) : side1(side1), side2(side2) {};
	virtual ~Rectangle() {};

	virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
	// Length of the sides of the rectangle
	int side1;
	int side2;
};


#endif //__RECTANGLE_H