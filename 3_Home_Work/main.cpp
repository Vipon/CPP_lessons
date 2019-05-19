#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "Particle.h"

int main() 
{
	Particle pet;
	Particle din;
	std::cin >> pet;
	std::cin >> din;
	Particle sum = pet + din;

	std::cout << sum << '\n';
	//std::cout << pet- din << '\n';

	return 0;
}