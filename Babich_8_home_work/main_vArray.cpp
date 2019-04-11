#include "vArray.h"


int main()
{
	vArray<int> arr;
	arr.state(5);
	std::cin >> arr;
	std::cout << arr;
	arr.state(2);
	arr.push(33);
	std::cout << arr;

	vArray<int> r2d2;
	r2d2.state(1);
	std::cin >> r2d2;
	r2d2.push(17);
	std::cout << r2d2;
	
	arr += r2d2;
	arr.revert();
	std::cout << arr;
	arr[2] = 7;
	std::cout << arr;
	arr.sortUp();
	std::cout << arr;
	int& a = arr.findElem(2);
	int& b = arr.findElem(7);
	vArray<int> arr2(arr, b, a);
	std::cout << arr2;

//	system("pause");
}
