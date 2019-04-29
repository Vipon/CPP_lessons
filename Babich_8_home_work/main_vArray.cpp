#include "vArray.h"


int main()
{
	vArray<int> arr;
	arr.set_size(5);
	std::cin >> arr;
	std::cout << arr;
	arr.set_size(2);
	arr.push_back(33);
	std::cout << arr;

	vArray<int> r2d2;
	r2d2.set_size(1);
	std::cin >> r2d2;
	r2d2.push_back(17);
	std::cout << r2d2;
	
	arr += r2d2;
	arr.revert();
	std::cout << arr;
	try { arr[2] = 7; }
	catch (const class ArrayException& e)
	{
		std::cout << e.what();
		return -1;
	}
	std::cout << arr;
	arr.sortUp();
	std::cout << arr;

//	system("pause");
}
