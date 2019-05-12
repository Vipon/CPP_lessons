#include "vArray.h"

int main() {
    int arr[7] = { 4, 2, 12, 8, 14, 6, 10 };
    vArray<int> aArr(arr, 7);

    try {
         aArr.push_back(3);
    }
    catch (vArrException& problem) {
        std::cout << problem.what();
    }

    vArray<int> bArr;

    try {
        aArr.QSort(0, 7);
    }
    catch (vArrException& problem) {
        std::cout << problem.what();
    }

    bArr = aArr;
    std::cout << bArr;
    std::cin >> bArr;
    std::cout << bArr;
    
    try {
        std::cout << aArr[5] << '\n';
    }
    catch (vArrException& problem) {
        std::cout << problem.what() << '\n';
    }
    
    std::cout << aArr.find(19);
}