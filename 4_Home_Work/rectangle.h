#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "gObject.h"

class Rectangle : public gObject {
public:
	Rectangle() : width(0), height(0) {};
	Rectangle(int width, int height) : width(width), height(height) {};
	virtual ~Rectangle() {};

	virtual void draw();
protected:
	int width;
	int height;
};

#endif