#include "Array.h"

int main() {
	int arr[5] = {1, 2, 3, 4, 5};
	Array<int, 5> iArr(arr);
	std::cout << iArr;
	std::cin >> iArr;
	iArr.sort(0, 4);
	std::cout << iArr;
	return 0;
}