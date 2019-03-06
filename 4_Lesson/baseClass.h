#ifndef __BASE_CLASS_H
#define __BASE_CLASS_H

#include <iostream>


class baseClass {

public:
    baseClass() { std::cout << "call baseClass()\n"; }
    ~baseClass() { std::cout << "call ~baseClass()\n"; }

    void printHello0() { std::cout << "Hello0 from baseClass\n"; };
    void printHello1() { std::cout << "Hello1 from baseClass\n"; };
    void printHello2() { std::cout << "Hello2 from baseClass\n"; };

};

#endif /* __BASE_CLASS_H */
