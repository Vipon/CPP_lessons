#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "gObject.h"

class Ellipse : public gObject {
public:
	Ellipse() : a(0), b(0) {};
	Ellipse(int a, int b) : a(a), b(b) {};
	virtual ~Ellipse() {};

	virtual void draw();
protected:
	int a;
	int b;
};

#endif