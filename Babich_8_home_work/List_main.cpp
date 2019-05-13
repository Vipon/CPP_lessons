#include "List.h" 

int main()
{
	List<int> ls(5);
	std::cin >> ls >> ls >>ls;
	std::cout << ls;
	ls.DelLine(ls.findline(3));
	std::cout << ls;
//	system("pause");
}
