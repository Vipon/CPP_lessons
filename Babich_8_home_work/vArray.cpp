#include "vArray.h"

template <typename T, size_t Size>
vArray<T, Size>& vArray<T, Size>::operator=(vArray dupl)
{
	this->table = dupl.table;
	this->Size = dupl.Size;
	return *this;
}

template <typename T, size_t Size>
std::ostream& operator<<(std::ostream& stream, vArray<T, Size > output)
{
	for (int i = 0; i < output.Size; i++)
	{
		stream << output.table[i];
	}
	return stream;
}

template <typename T, size_t Size>
std::istream& operator>>(std::istream& stream, vArray<T, Size> input)
{
	for (int i = 0; i < input.Size; i++)
	{
		stream >> input.table[i];
	}
	return stream;
}



