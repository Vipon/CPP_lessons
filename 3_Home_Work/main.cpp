#include <iostream>
#include "gObject.h"

int main()
{
    point a = {3, 10.5}, b = {13.242, -0.3}, c = {0, 2};
    segment seg(a, b);
    seg.draw();
    float arg = 1.57, q = 13, w = 10.1;
    triangle tri(a, b, c);
    tri.draw();
    circle cir(a, q);
    cir.draw();
    square squ(b, w, arg);
    squ.draw();
    ellipse ell(c, q, w);
    ell.draw();
    rectangle rec(a, w, q, arg);
    rec.draw();
    return 0;
}
