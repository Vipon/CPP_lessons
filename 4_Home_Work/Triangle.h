#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include "gObject.h"

class Triangle : public gObject {
public:
	Triangle() : side1(0), side2(0), side3(0) {};
	Triangle(int side1, int side2, int side3) : side1(side1), side2(side2), side3(side3) {};
	virtual ~Triangle() {};

	virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
	// Length of the sides of the triangle
	int side1;
	int side2;
	int side3;
};


#endif //__TRIANGLE_H