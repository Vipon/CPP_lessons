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

class segment : public gObject{
public:
    point First;
    point Second;
    segment(const point first = {0, 0}, const point second = {0, 0}) : First(first), Second(second) {};
    ~segment(){};
    virtual void draw();
};

class triangle : public segment{
public:
    point Third;
    triangle(const point first = {0, 0}, const point second = {0, 0}, const point third = {0, 0}) : segment(first, second), Third(third) {};
    ~triangle(){};
    virtual void draw();
};

class circle : public gObject{
public:
    point Centre;
    float Radius;
    circle(const point centre = {0, 0}, const float radius = 0) : Centre(centre), Radius(radius) {};
    ~circle(){};
    virtual void draw();
};

class square : public circle{
public:
    float Argument;
    square(const point centre = {0, 0}, const float radius = 0, const float argument = 0) : circle(centre, radius), Argument(argument) {};
    ~square(){};
    virtual void draw();
};

class ellipse : public square{
public:
    float B;
    ellipse(const point centre = {0, 0}, const float a = 0, const float b = 0, const float argument = 0) : square(centre, a, argument), B(b) {};
    ~ellipse(){};
    virtual void draw();
};

class rectangle : public ellipse{
public:
    rectangle(const point centre = {0, 0}, const float a = 0, const float b = 0, const float argument = 0) : ellipse(centre, a, b, argument) {};
    ~rectangle(){};
    virtual void draw();
};

#endif // GOBJECT_H_INCLUDED
