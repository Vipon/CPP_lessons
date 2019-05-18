#ifndef __ELLIPSE_H
#define __ELLIPSE_H

#include "gObject.h"

class Ellipse : public gObject 
{
public:
	Ellipse() : a(0), b(0) {};
	Ellipse(size_t a, size_t b) : a(a), b(b) {};
	virtual ~Ellipse() {};

	void _4points(SDL_Renderer* rend, int x, int y, int x_1, int y_1);

	virtual void draw(SDL_Renderer* rend, int x, int y) override;

protected:
	int a;
	int b; 
};

#endif //__ELLIPSE_H 
