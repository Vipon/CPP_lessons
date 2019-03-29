#include "Array.h"

template <typename T>
Array<T>::Array(size_t Size)
{
	this->Size = Size;
	table = new T[Size];
}

template <typename T>
Array<T>::~Array()
{
	delete[] table;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> dupl)
{
	this->table = dupl.table;
	this->Size = dupl.Size;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, Array<T>& output)
{
	for (int i = 0; i < output.Size; i++)
	{
		stream << output.table[i];
	}
	return stream;
}

template <typename T>
std::istream& operator>>(std::istream& stream, Array<T>& input)
{
	for (int i = 0; i < input.Size; i++)
	{
		stream >> input.table[i];
	}
	return stream;
}



