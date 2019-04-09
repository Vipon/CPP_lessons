#include "static.h"

int main()
{
    /**
     *  static methods could be called without really objects.
     */
    staticTest::printStaticField();
    return 0;
}