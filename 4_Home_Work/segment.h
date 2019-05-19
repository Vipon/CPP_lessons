#ifndef SEGMENT_H
#define SEGMENT_H

#include "gObject.h"

class Segment : public gObject{
public:
	Segment() : lenght(0) {};
	Segment(int lenght) : lenght(lenght) {};
	virtual ~Segment() {};

	virtual void draw();
protected:
	int lenght;
};

#endif