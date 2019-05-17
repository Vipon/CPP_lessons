#include "vArray.h"

int main() {
    int arr[7] = { 4, 2, 12, 8, 14, 6, 10 };
    try {
        vArray<int> aArr(arr, 7);
        aArr.push_back(3);
        vArray<int> bArr;
        aArr.QSort(0, 7);
        bArr = aArr;
        std::cout << bArr;
        std::cin >> bArr;
        std::cout << bArr;
        std::cout << aArr[5] << '\n';
        std::cout << aArr.find(19);
    }
    catch (vArrException& problem) {
        std::cout << problem.what() << '\n';
    }
    getchar();
    getchar();
}