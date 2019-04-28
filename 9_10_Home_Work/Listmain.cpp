#include "List.h"
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    List<int> L;
    for (int i = 0; i < 5; ++i){
        L.push_back(0);
    }
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
