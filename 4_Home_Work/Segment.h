#ifndef __SEGMENT_H
#define __SEGMENT_H

#include "gObject.h"

class Segment : public gObject {
public: 
	Segment(int length = 0) : length(length) {};
	virtual ~Segment() {};

	virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
	int length; // Length of the segment
};

#endif //__SEGMENT_H