#ifndef __SEGMENT_H
#define __SEGMENT_H

#include "gObject.h"

class Segment : public gObject
{
public:
	Segment(size_t length = 0) : length(length) {};
	virtual ~Segment() {};

	virtual void draw(SDL_Renderer* render, int x, int y);

protected:
	size_t length; 
};

#endif //__SEGMENT_H 
