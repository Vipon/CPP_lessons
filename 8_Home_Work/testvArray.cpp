#include "vArray.h"

int main() {
    int arr[7] = { 4, 2, 12, 8, 14, 6, 10 };
    vArray<int> aArr(arr, 7);
    vArray<int> bArr;

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
        std::cout << aArr[5] << '\n';
    }
    catch (ArrException& problem) {
        std::cout << problem.what() << '\n';
    }
    
    std::cout << aArr.find(19);
    getchar();
    getchar();
}