#include "Stack02.h"
#include "my_class.h"
#include <iostream>

void Zp::dump()
{
	this->zp.dump();
}
Zp::Zp(size_t p)
{
	Stack zp;
	this->zp.push(1);
	this->Char = p;
}

Zp::~Zp()
{
	
}

int Zp::operator+(int val)
{
	while (val < 0)
	{
		val = val + this->Char;
	}

	int res = (zp.pop() + val) % this->Char;
	zp.push(res);
	zp.push(res);
	zp.push(res);
	return zp.pop();
}

int Zp::operator*(int val)
{
	while (val < 0)
	{
		val = val + this->Char;
	}

	int res = (zp.pop()*val) % this->Char;
	zp.push(res);
	zp.push(res);
	zp.push(res);
	return zp.pop();
}

int Zp::operator^(int pow)
{
	int val = zp.pop();
	zp.push(val);

	if (pow > 0)
	{
		for (int i = 1; i < pow; i++)
		{
			zp.push((zp.pop()*val) % this->Char);
		}
	}

	if (pow < 0)
	{
		while ((zp.pop()*val) % this->Char != 1)
		{
			for (int i = 1; i < -pow; i++)
			{
				zp.push((zp.pop()*val) % this->Char);
			}
		}
	}

	int res = zp.pop();
	zp.push(res);
	zp.push(res);

	return res;

}
