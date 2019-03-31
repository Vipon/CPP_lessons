#include "Array.h"

int main() {
	int arr[5] = {1, 2, 3, 4, 5};
	Array<int, 5> iArr(arr);
	std::cout << iArr;
	std::cin >> iArr;
	std::cout << iArr;
	return 0;
}