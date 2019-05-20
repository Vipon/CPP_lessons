c#include "List.h"

int main() {
    try {
        char Arr[3] = { 'd', 'i', 'k' };
        List<char> list(Arr, 3);
        List<char> list2(list);
        list2.insert('s', 'i');
        std::cout << list2;
        list2.search_and_remove('k');
        std::cout << list2;
        List<char> list3;
        std::cin >> list3;
        std::cout << list3;
        getchar();
        getchar();
    }
    catch (ListException& problem) {
        std::cout << problem.what() << '\n';
    }
}