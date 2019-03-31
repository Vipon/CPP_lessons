#ifndef __GOBJECT_H
#define __GOBJECT_H

#include <SDL2/SDL.h>


//Draw a pixel for the first quadrant and, simmetrically, for others
void pixel4(SDL_Renderer* renderer, int x, int y, int _x, int _y);

class gObject {
public:
    virtual ~gObject() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y) = 0;
};

class Line : public gObject {
public:
    Line(int len = 0) : len(len) {};
    ~Line() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int len; //length of line 
};

class Triangle : public gObject {
public:
    Triangle() : a(0), b(0), c(0) {};
    Triangle(int a, int b, int c) : a(a), b(b), c(c) {};
    ~Triangle() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int a; //lenth of first side
    int b; //lenth of second side
    int c; //lenth of third side
};

class Ellipse : public gObject {
public:
    Ellipse() : width(0), hight(0) {};
    Ellipse(int width, int hight) : width(width), hight(hight) {};
    ~Ellipse() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int width;
    int hight;
};

class Circle : public Ellipse {
public:
    Circle() : Ellipse(0, 0) {};
    Circle(int r) : Ellipse(r, r) {}; // r for radius
    ~Circle() {};

};

class Rectangle : public gObject {
public:
    Rectangle() : a(0), b(0) {};
    Rectangle(int a, int b) : a(a), b(b) {};
    ~Rectangle() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int a; //length of first side
    int b; //length of second size
};


class Regular_Polygon : public gObject {
public:
    Regular_Polygon() : len(0), n(0) {};
    Regular_Polygon(int len, int n) : len(len), n(n) {};
    ~Regular_Polygon() {};

    virtual void draw(SDL_Renderer* renderer, int x, int y);

protected:
    int len; // length of one side
    int n; // number of sides
};


class Square : public Regular_Polygon {
public:
    Square() : Regular_Polygon(0, 0) {};
    Square(int len) : Regular_Polygon(len, 4) {};
    ~Square() {};
};

#endif //__GOBJECT_H 