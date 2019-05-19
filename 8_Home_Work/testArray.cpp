#include "Array.h"

int main()
{
	try{
		Array<int, 10> array;
		for (size_t i = 0; i < 10; i++) {
			array[i] = i;
		} 
		std::cout << array;
		std::cin >> array;
		std::cout << array;
	}
	catch (std::exception& er) {
		std::cerr << er.what();
		exit(1);
	}	
	return 0;
}
