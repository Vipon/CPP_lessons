#include "Array.h"

int main() {
    int q = 0;
    int arr[7] = { 4, 2, 12, 8, 14, 6, 10 };
    Array<int, 7> aArr(arr);
    Array<int, 7> bArr;

    try {
        aArr.QSort(0, 6);
    }
    catch (ArrException& problem) {
        std::cout << problem.what();
    }

    bArr = aArr;
    std::cout << bArr;
    std::cin >> bArr;
    std::cout << bArr;

    try { 
        std::cout << aArr[7] << '\n'; 
    } catch(ArrException& problem) {
        std::cout << problem.what() << '\n';
    }

    std::cout << aArr.find(19);
}