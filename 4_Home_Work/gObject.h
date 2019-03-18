#ifndef __GOBJECT_H
#define __GOBJECT_H

#include <SDL.h>


//Draw a pixel for the first quadrant and, simmetrically, for others
void pixel4(SDL_Renderer* renderer, int x, int y, int _x, int _y);

class gObject {
public:
    virtual ~gObject() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y) = 0;
};

class Line : public gObject {
public:
    Line(int a = 0) : a(a) {};
    ~Line() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int a;
};

class Triangle : public gObject {
public:
    Triangle() : a(0), b(0), c(0) {};
    Triangle(int a, int b, int c) : a(a), b(b), c(c) {};
    ~Triangle() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int a;
    int b;
    int c;
};

class Ellipse : public gObject {
public:
    Ellipse() : a(0), b(0) {};
    Ellipse(int a, int b) : a(a), b(b) {};
    ~Ellipse() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int a;
    int b;
};

class Circle : public Ellipse {
public:
    Circle() : Ellipse(0, 0) {};
    Circle(int a) : Ellipse(a, a) {};
    ~Circle() {};

};

class Rectangle : public gObject {
public:
    Rectangle() : a(0), b(0) {};
    Rectangle(int a, int b) : a(a), b(b) {};
    ~Rectangle() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int a;
    int b;
};


class Regular_Polygon : public gObject {
public:
    Regular_Polygon() : a(0), n(0) {};
    Regular_Polygon(int a, int n) : a(a), n(n) {};
    ~Regular_Polygon() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int a;
    int n;
};


class Square : public Regular_Polygon {
public:
    Square() : Regular_Polygon(0, 0) {};
    Square(int a) : Regular_Polygon(a, 4) {};
    ~Square() {};
};

#endif //__GOBJECT_H 