#include "my_class.h"
#include "Excep.h"

Zp::Zp(size_t Char)
{
	this->Char = Char;
}
Zp Zp::operator+(const Zp& lal) 
{
	if (lal.Char != this->Char)
		throw ArrayException("different characteristic");
	Zp buf(this->Char);
	buf.val = (val + lal.val) % this->Char;

	return buf;
}

Zp Zp::operator*(const Zp& lal) 
{
	if (lal.Char != this->Char)
		throw ArrayException("different characteristic");
	Zp buf(this->Char);
	buf.val=(val*lal.val) % this->Char;

	return buf;
}

Zp Zp::operator^(const int pow) 
{
	int lal = this->val;

	if (pow > 0)
	{
		for (int i = 1; i < pow; i++)
		{
			lal = lal*this->val % this->Char;
		}
	}

	if (pow < 0)
	{
		while (lal != 1)
		{
			lal = lal*this->val % this->Char;
		}

		for (int i = 1; i < -pow; i++)
		{
			lal = lal*this->val % this->Char;
		}
	}

	Zp buf(this->Char);
	buf.val =lal;

	return buf;

}

std::istream& operator>>(std::istream& in,Zp& input)
{
	int num;
	in >> num;

	while (num < 0)
	{
		num = num + input.Char;
	}

	num = num % input.Char;
	input.val = num;

	return in;
}

std::ostream& operator<<(std::ostream& op, const Zp& output)
{
	int val = output.val;
	op << val;

	return op;
}

Zp& Zp::operator=(const int lal)
{
	this->val = lal;
	while (this->val < 0)
	{
		this->val = this->val + this->Char;
	}
	this->val = val % this->Char;
	return *this;
}


