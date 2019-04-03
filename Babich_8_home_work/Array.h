#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <string.h>

template <typename T, size_t Size>
class Array
{
public:
	Array() : table(new T[Size]) {}

	~Array()
	{
		delete[] table;
	}

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

private:
	T* const table;
};
#endif /*ARRAY_H*/
