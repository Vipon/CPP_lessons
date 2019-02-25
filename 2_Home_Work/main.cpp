#include "my_Stack.h"
#include <iostream>
#include <cstddef>

int main()
{
    List <int> L;
    for (std::size_t i = 0; i < 15; ++i){
        L.push_back(static_cast<int>(i));
    }

    for (List<int>::iterator it = L.begin(); it != L.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    List<int>::iterator it = L[5];

    for (std::size_t i = 0; i < 5; ++i){
        it = L.remove(it);
    }

    for (List<int>::iterator it = L.begin(); it != L.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << L.front() << " " << L.back();
    return 0;
}
