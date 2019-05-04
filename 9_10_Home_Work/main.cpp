#include "Array.h"
#include "vArray.h"
#include "List.h"
#include <algorithm>
#include <iostream>
#include <numeric>


int main()
{
	std::cout << "Array\n";
	int ar[5] = {8, 4, 3, 10, 9};
	Array<int, 5> iAr(ar);
	Array<int, 5> iAr2(ar);
	std::cout << iAr;
	std::for_each(iAr.begin(), iAr.end(), [](int& n){ n++; });
	std::cout << iAr;
	std::fill(iAr.begin(), iAr.end(), 10);
	std::cout << iAr;
	int sum = std::accumulate(iAr.begin(), iAr.end(), 0);
	std::cout << sum << '\n';
	std::cout << iAr2;
	std::sort(iAr2.begin(), iAr2.end());
	std::cout << "Sort: " << iAr2;

	std::cout << "vArray\n";
	int ar2[4] = {7, 6, 2, 4};
	vArray<int> vAr(ar2, 4);
	std::cout << vAr << '\n';
	std::sort(vAr.begin(), vAr.end());
	std::cout << "Sort: " << vAr << '\n';
	int value = 6;
	vArray<int>::Iterator it = std::find(vAr.begin(), vAr.end(), value);
	std::cout << (*it) << '\n';

	std::cout << "List\n";
	List<int> ls;
	ls.insert_start(5);
	ls.insert_start(7);
	ls.insert_end(10);
	ls.insert_end(9);
	std::cout << ls << '\n';
	std::for_each(ls.begin(), ls.end(), [](int& n){ n++; });
	std::cout << ls << '\n';
	std::transform(ls.begin(), ls.end(), vAr.begin(), [](int& n){ return ++n; });
	std::cout << vAr << '\n';
	return 0;
}