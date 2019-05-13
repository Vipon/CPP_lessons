#ifndef GOBJECT_H_INCLUDED
#define GOBJECT_H_INCLUDED

struct point{
    float x;
    float y;
};

class gObject{
public:
    virtual ~gObject() {};
    virtual void draw() = 0;
};

#endif // GOBJECT_H_INCLUDED
