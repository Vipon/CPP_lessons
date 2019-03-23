#include "my_class.h"

Zp Zp::operator+(Zp lal)
{
	while (lal.val < 0)
	{
		lal.val = lal.val + this->Char;
	}

	while (val < 0)
	{
		val = val + this->Char;
	}
	Zp buf;
	buf.val = (val + lal.val) % this->Char;

	return buf;
}

Zp Zp::operator*(Zp lal)
{
	while (lal.val < 0)
	{
		lal.val = lal.val + this->Char;
	}

	while (val < 0)
	{
		val = val + this->Char;
	}
	Zp buf;
	buf.val=(val*lal.val) % this->Char;

	return buf;
}

Zp Zp::operator^(int pow)
{
	while (val < 0)
	{
		val = val + this->Char;
	}

	int lal = val;

	if (pow > 0)
	{
		for (int i = 1; i < pow; i++)
		{
			lal = lal*val % this->Char;
		}
	}

	if (pow < 0)
	{
		while (lal*val % this->Char != 1)
		{
			for (int i = 1; i < -pow; i++)
			{
				lal = val*val % this->Char;
			}
		}
	}

	Zp buf;
	buf.val =lal;

	return buf;

}

std::istream& operator>>(std::istream& in, Zp& input)
{
	int num;
	in >> num;

	while (num < 0)
	{
		num = num + p;
	}

	num = num % p;
	input.val = num;
	
	return in;
}

std::ostream& operator<<(std::ostream& op, Zp& output)
{
	int val = output.val;
	op << val;

	return op;
}

void Zp::operator=(int lal)
{
	val = lal;
	return;
}