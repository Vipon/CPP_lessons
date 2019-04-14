#include "vArray.h"

int main() {
	int arr[5] = {1, 2, 3, 4, 5};
	try {
		vArray<int> iArr(arr, 5);
		std::cout << iArr;
		std::cin >> iArr;
		std::cout << iArr;
		vArray<int> iArr2(arr, 2);
		std::cout << iArr2;
		iArr = iArr2;
		std::cout << iArr;
	}
	catch (std::exception& er) {
		std::cerr << er.what();
		exit(1);
	}
	return 0;
}