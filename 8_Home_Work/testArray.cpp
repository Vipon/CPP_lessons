#include "Array.h"

int main() {
	int arr[5] = {1, 2, 3, 4, 5};
	try {
		Array<int, 5> iArr(arr);
		std::cout << iArr;
		std::cin >> iArr;
		iArr.sort(0, 4);
		std::cout << iArr;
		Array<int, 5> iArr2(iArr);
		std::cout << iArr2;
		iArr2[2] = 15;
		iArr = iArr2;
		std::cout << iArr;
	}
	catch (std::exception& er) {
		std::cerr << er.what();
		exit(1);
	}
	return 0;
}