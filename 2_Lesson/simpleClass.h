#ifndef __SIMPLE_CLASS_H
#define __SIMPLE_CLASS_H

class simpleClass {

public:
    simpleClass(int val = -1);
    simpleClass(simpleClass& sc);
    ~simpleClass() {};

    void print();

private:
    int a;

};

#endif /* __SIMPLE_CLASS_H */
