#include "my_class.h"

int main()
{
	Zp a;
	std::cin >> a;
	Zp b;
	b.val = 10;
	Zp c,d,e;
	c = a + b;
	d = a ^ 3;
	e = a * b;
	std::cout << c << d << e;
//  system("pause");
}