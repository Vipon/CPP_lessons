#ifndef VARRAY_H
#define VARRAY_H
#include <iostream>

template <typename T, size_t Size>
class vArray 
{
public:
	vArray()
	{
		this->table = new T[Size];
	}

	~vArray()
	{
		delete[] table;
	}

	friend std::ostream& operator<<(std::ostream& stream, vArray<T, Size>& output)
	{
		for (size_t i = 1; i < Size + 1; i++)
		{
			stream << output.table[i-1];
		}
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, vArray<T, Size>& input)
	{
		for (size_t i = 1; i < Size + 1; i++)
		{
			stream >> input.table[i-1];
		}
		return stream;
	}

	vArray& operator=(const vArray<T, Size>& dupl)
	{
		memcpy(this->table, dupl.table, sizeof(T)*Size);
		return *this;
	}

private:
	T* table;
};
#endif /*VARRAY_H*/