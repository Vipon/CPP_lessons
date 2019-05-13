#include "List.h"
#include <algorithm>
#include <iostream>

int main()
{
    List<int> L;
    std::cin >> L;
    std::cout << L;
    std::reverse(L.begin(), L.end());
    std::cout << L << std::endl;
    std::iter_swap(L.begin(), --L.end());
    std::cout << L << std::endl;
    std::fill(++L.begin(), --L.end(), -15);
    std::cout << L << std::endl;
    return 0;
}
