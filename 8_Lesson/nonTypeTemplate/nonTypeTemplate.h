#ifndef __NON_TYPE_TEMPLATE
#define __NON_TYPE_TEMPLATE

#include <cstddef>
#include <iostream>
#include <typeinfo>

template <typename T, size_t NUM>
class nonTypeTemplate {

public:
    nonTypeTemplate() : num(0)
    {
        std::cout << "create object nonTypeTemplate<" << typeid(T).name() << ", "
                                                << NUM << '>' << std::endl;
    }

    ~nonTypeTemplate()
    {
        std::cout << "destruct object nonTypeTemplate<" << typeid(T).name() << ", "
                                                << NUM << '>' << std::endl;
    }

    nonTypeTemplate(const T* a, size_t len) : num(len)
    {
        std::cout << "create object nonTypeTemplate<" << typeid(T).name() << ", "
                                                << NUM << '>' << std::endl;
        for (size_t i = 0; i < len && i < NUM; ++i) {
            array[i] = a[i];
        }
    }

    void show() const
    {
        std::cout << "object nonTypeTemplate<" << typeid(T).name() << ", "
                                                << NUM << "> constains:\t";
        for (size_t i = 0; i < num; ++i) {
            std::cout << array[i] << ' ';
        }

        std::cout << std::endl;
    }

private:
    size_t  num;
    T       array[NUM];

};

#endif /* __NON_TYPE_TEMPLATE */
