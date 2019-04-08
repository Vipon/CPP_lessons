#include "Array.h"

int main() {
	
	Array<int, 7> week;
	for (size_t i = 0; i<7; i++) {
		week[i]=i+1;
	}
	std::cout<< week;
	std::cin>> week;
	std::cout<< week;

	return 0;
} 