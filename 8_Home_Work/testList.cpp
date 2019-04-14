#include "List.h"

int main() 
{
	List<int> ls;
	ls.insert_start(5);
	ls.insert_start(7);
	ls.insert_end(10);
	std::cout << ls[0] << '\n';
	std::cout << ls << '\n';
	return 0;
}