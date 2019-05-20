#include "Array.h"

int main() {

	Array<int, 13> arrrrr;
	for (size_t i = 0; i<13; i++) {
		arrrrr[i]=i+1;
	}
	std::cout<< arrrrr;
	std::cin>> arrrrr;
	std::cout<< arrrrr;

	return 0;
}  