#include "Array.h"

template <typename T>
Array<T>::Array(size_t size)
{
	this->size = size;
	table = T new[size];
}

template <typename T>
Array<T>::~Array()
{
	delete[] table;
}
/*
template <typename T>
Array<T>& Array<T>::operator=(Array<T> dupl)
{
	this->table = dupl.table;
	this->size = dupl.size;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, Array<T>& output)
{
	for (int i = 0; i < output.size; i++)
	{
		stream << output.table[i];
	}
	return stream;
}

template <typename T>
std::istream& operator>>(std::istream& stream, Array<T>& input)
{
	for (int i = 0; i < input.size; i++)
	{
		stream >> input.table[i];
	}
	return stream;
}



*/