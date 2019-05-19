#ifndef __SIMPLE_TEMPLATE_H
#define __SIMPLE_TEMPLATE_H

#include <iostream>

template <typename T>
class simpleTemplate {

public:
    simpleTemplate(T& val) : field(val) {}
    simpleTemplate(T&& val) : field(std::move(val)) {}
    void show() const { std::cout << field << std::endl; }

private:
    T field;

};

#endif /* __SIMPLE_TEMPLATE_H */
