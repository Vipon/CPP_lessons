#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include "gObject.h"

class Triangle : public gObject
{
public:
	Triangle() : sideline1(0), sideline2(0), sideline3(0) {};
	Triangle(size_t sideline1, size_t sideline2, size_t sideline3) : sideline1(sideline1), sideline2(sideline2), sideline3(sideline3) {};
	virtual ~Triangle() {};

	virtual void draw(SDL_Renderer* render, int x, int y);

protected:
	size_t sideline1;
	size_t sideline2;
	size_t sideline3;
};


#endif //__TRIANGLE_H 