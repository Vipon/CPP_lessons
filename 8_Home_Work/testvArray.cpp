#include "vArray.h"

int main() {
	int arr[5] = {1, 2, 3, 4, 5};
	vArray<int> iArr(arr, 5);
	std::cout << iArr;
	std::cin >> iArr;
	std::cout << iArr;
	vArray<int> iArr2(arr, 2);
	std::cout << iArr2;
	iArr = iArr2;
	std::cout << iArr;
	return 0;
}