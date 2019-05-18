#ifndef __CIRCLE_H
#define __CIRCLE_H

#include "Ellipse.h"

class Circle : public Ellipse 
{
public:
	Circle() : Ellipse(0, 0) {};
	Circle(size_t a) : Ellipse(a, a) {};
	virtual ~Circle() {};
};

#endif //__CIRCLE_H 