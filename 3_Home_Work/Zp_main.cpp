#include "my_class.h"

int main()
{
	Zp a(7);
	std::cin >> a;
	Zp b(7);
	b = 10;
	Zp c(7), d(7), e(7);
	c = a + b;
	d = a ^ 3;
	e = a * b;
	std::cout << c << d << e;
	c = a;
	std::cout << c;
	 system("pause");
}