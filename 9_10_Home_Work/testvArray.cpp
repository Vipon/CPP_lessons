#include "vArray.h"
#include <algorithm>
#include <numeric>


int main() {
    int arr[7] = { 4, 2, 12, 8, 14, 6, 10 };
    try {
        vArray<int> aArr(arr, 7);
        std::sort(aArr.begin(), aArr.end());
        
        aArr.push_back(3);
        vArray<int> bArr;
        bArr = aArr;
        aArr.QSort(0, 7);
        bArr = aArr;

        std::cout << bArr << '\n'<< aArr;
        std::cin >> bArr;
        std::cout << bArr;
        std::cout << aArr[5] << '\n';
        std::cout << aArr.find(19);
    }
    catch (ArrException& problem) {
        std::cout << problem.what() << '\n';
    }
}