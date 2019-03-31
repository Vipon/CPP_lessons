#ifndef __RECURSIVE_TEMPLATE_H
#define __RECURSIVE_TEMPLATE_H

#include <iostream>
#include <typeinfo>

template <typename T>
class recursiveTemplate {

public:
    recursiveTemplate(T& val) : field(val) {};
    recursiveTemplate(T&& val) : field(std::move(val)) {};

    friend std::ostream& operator<<(std::ostream& os, const recursiveTemplate& rT)
    {
        os << "ObjectType: " << typeid(rT).name() << std::endl;
        os << rT.field << std::endl;
        return os;
    }

private:
    T field;

};

#endif /* __RECURSIVE_TEMPLATE_H */
