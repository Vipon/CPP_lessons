#include "Array.h"

int main()
{
	Array<int, 10> array;
	for (size_t i = 0; i < 10; i++) {
		array[i] = i;
	} 
	std::cout << array;
	std::cin >> array;
	std::cout << array;
	return 0;
}