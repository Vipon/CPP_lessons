#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include "gObject.h"

class Rectangle : public gObject
{
public:
	Rectangle() : sideline1(0), sideline2(0) {};
	Rectangle(size_t sideline1, size_t sideline2) : sideline1(sideline1), sideline2(sideline2) {};
	virtual ~Rectangle() {};

	virtual void draw(SDL_Renderer* rend, int x, int y);

protected:
	int sideline1;
	int sideline2;
};


#endif //__RECTANGLE_H 