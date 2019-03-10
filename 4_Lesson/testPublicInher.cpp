#include "childClass.h"

int main()
{
    childClass child;

    /**
     *  printHello0() method of baseClass.
     */
    child.printHello0();

    /**
     *  printHello1() - method of childClass.
     *  printHello2() - method of childClass.
     */
    child.printHello1();
    child.printHello2();
    return 0;
}
