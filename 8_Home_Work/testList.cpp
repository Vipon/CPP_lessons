#include "List.h"

int main()
{
	int a = 8;
	List<int> ls();
	ls.insert_start(5);
	ls.insert_start(7);
	ls.insert_end(10);
	std::cout << ls << "\n";
	return 0;
}