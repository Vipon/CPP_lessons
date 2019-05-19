#ifndef __CHILD_CLASS_H
#define __CHILD_CLASS_H

#include <iostream>
#include "baseClass.h"

class childClass : public baseClass {

public:
    childClass() { std::cout << "call childClass()\n"; }
    ~childClass() { std::cout << "call ~childClass()\n"; }

    void printHello1() { std::cout << "Hello1 from childClass\n"; };
    void printHello2()
    {
        baseClass::printHello2(); // call public method from baseClass.
        std::cout << "Hello2 from childClass\n";
    };

};

#endif /* __CHILD_CLASS_H */
