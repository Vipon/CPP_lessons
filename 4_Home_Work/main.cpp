#include "gObject.h"
#include "gEllipse.h"
#include "gRectangle.h"
#include "gSegment.h"
#include "gSircle.h"
#include "gSquare.h"
#include "gTriangle.h"
#include <iostream>

int main()
{
    G_Object go;
    G_Object *refer_go[7];
    Rectangle rec(1, 1, 2, 3, 0);
    Square sq(2, 2, 3, 0);
    Segment seg(1, 2, 7, 2);
    Triangle tri (1, -3, 7, 0, 6, 9);
    Ellipse ell(4, 5, 10, 8, 8);
    Circle cir(4, 3, 5);
    refer_go[0] = &go;
    refer_go[1] = &rec;
    refer_go[2] = &sq;
    refer_go[3] = &seg;
    refer_go[4] = &tri;
    refer_go[5] = &ell;
    refer_go[6] = &cir;
    for (int i = 0; i < 7; ++i)
    {
        refer_go[i]->draw();
    };
    return 0;
}