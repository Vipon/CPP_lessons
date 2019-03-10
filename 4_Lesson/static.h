#ifndef __STATIC_H
#define __STATIC_H

#include <iostream>


class staticTest {
public:
    static void printStaticField()
    {
        std::cout << "staticField = " << staticField << '\n';
    }

private:
    static int staticField;
};

int staticTest::staticField = 42;

#endif /* __STATIC_H */
