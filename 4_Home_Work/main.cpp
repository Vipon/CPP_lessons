#include "circle.h"
#include "ellipse.h"
#include "rectangle.h"
#include "square.h"
#include "segment.h"
#include "triangle.h"
#include <iostream>

int main()
{
	Triangle triangle(3, 13 ,5);
	Ellipse ellipse(7, 11);
	Circle circle(1);
	Segment segment(17);
	Rectangle rectangle(19, 23);
	Square square(29);

	triangle.draw();
	ellipse.draw();
	circle.draw();
	segment.draw();
	rectangle.draw();
	square.draw();
	
	return 0;
}