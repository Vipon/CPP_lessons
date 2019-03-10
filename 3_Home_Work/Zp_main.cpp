#include "my_class.h"

int main()
{
	Zp zp(7);
	int a = zp.operator+(0);

	for (int i = 0; i < 5; i++)
	{
		a = zp.operator+(i*i);
	}
	a = zp.operator^(zp.Char - 1);
	zp.dump();
}