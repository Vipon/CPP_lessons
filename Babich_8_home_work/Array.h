#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

template <typename T>
class Array
{
public:
	Array(size_t Size)
	{
		this->table = new T[Size];
		this->Size = Size;
	}

	~Array()
	{
		delete[] table;
	}

	friend std::ostream& operator<<(std::ostream& stream, Array<T>& output)
	{
		for (size_t i = 1; i < output.Size+1; i++)
		{
			stream << output.table[i-1];
		}
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, Array<T>& input)
	{
		for (size_t i = 1; i < input.Size+1; i++)
		{
			stream >> input.table[i-1];
		}
		return stream;
	}

	Array& operator=(const Array<T>& dupl)
	{
		memcpy(this->table, dupl.table, sizeof(T)*Size);
		return *this;
	}

private:
	size_t Size;
	T* table;
};
#endif /*ARRAY_H*/