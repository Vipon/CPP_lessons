#ifndef GOBJECT_H
#define GOBJECT_H

class gObject{
public:
	virtual ~gObject() {};

	virtual void draw() = 0;
};

#endif