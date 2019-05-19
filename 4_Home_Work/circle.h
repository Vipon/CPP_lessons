#ifndef CIRCLE_H
#define CIRCLE_H

#include "ellipse.h"

class Circle : public Ellipse{
public:
	Circle() : Ellipse(0, 0) {};
	Circle(int a) : Ellipse (a, a) {};
	virtual ~Circle() {};
};

#endif