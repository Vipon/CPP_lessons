#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cstring>
#include "my_Exception.h"

template <typename T, size_t Size>
class Array
{
public:
	Array() {};

	~Array() = default;

	friend std::ostream& operator<<(std::ostream& stream, Array<T, Size>& output)
	{
		for (size_t i = 1; i < Size+1; i++)
		{
			stream << output.table[i-1] << ' ';
		}
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, Array<T, Size>& input)
	{
		for (size_t i = 1; i < Size+1; i++)
		{
		stream >> input.table[i-1];
		}
		return stream;
	}

	Array& operator=(const Array<T, Size>& dupl)
	{
		memcpy(this->table, dupl.table, sizeof(T)*Size);
		return *this;
	}

	T& operator[] (size_t pos)
	{
		if (pos < Size)
		{
			return table[pos - 1];
		}
		else
		{
			throw ArrayException("out of range");
		}
	}

	void sortUp() //shellsort
	{
		for (size_t gap = Size / 2; gap > 0; gap /= 2)
		{
			for (size_t i = gap; i < Size; i++)
			{
				T buf = table[i];
				size_t j;
				for (j = i; j >= gap && table[j - gap] > buf; j -= gap)
					table[j] = table[j - gap];
				table[j] = buf;
			}
		}
		return;
	}

	void revert()
	{
		T buf = 0;
		for (size_t i = 0; i < (Size / 2); i++)
		{
			buf = table[i];
			table[i] = table[Size - 1 - i];
			table[Size - 1 - i] = buf;
		}
		return;
	}

private:
	T table[Size];
};
#endif /*ARRAY_H*/
