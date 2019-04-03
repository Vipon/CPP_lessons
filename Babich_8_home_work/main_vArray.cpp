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
	std::cout << arr;
	
//	system("pause");
}
