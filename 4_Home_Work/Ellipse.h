#ifndef __ELLIPSE_H
#define __ELLIPSE_H

#include "gObject.h"

class Ellipse : public gObject {
public:
	Ellipse() : a(0), b(0) {};
	Ellipse(int a, int b) : a(a), b(b) {};
	virtual ~Ellipse() {};

	//Draw a pixel for the first quadrant and, simmetrically, for others
	void pixel4(SDL_Renderer* renderer, int x, int y, int _x, int _y); 

	virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
	int a; // Large half-axis of the ellipse
	int b; // Small half-axis of the ellipse
};

#endif //__ELLIPSE_H