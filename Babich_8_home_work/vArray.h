#ifndef VARRAY_H
#define VARRAY_H
#include "my_Exception.h"
#include <iostream>
#include <string.h>
#include <iterator>
#include <algorithm>

template <typename T>
class vArray 
{
public:
	vArray()
	{
		this->table = new T[Size];
	}

	vArray(vArray<T>& seq, T& begin, T& end)
	{
		int start = -1;
		int stop = -1;
		for (size_t i = 0; i < seq.Size; i++)
		{
			if (&(seq.table[i]) == &begin)
				start = i;
			if (&(seq.table[i]) == &end)
				stop = i;
		}
		if (start < 0 || stop < 0)
		{
			throw ArrayException("no such element.");
		}
		this->Size = std::max(stop,start) - std::min(start,stop) + 1;
		this->table = new T[Size];
		for (size_t i = 0; i < Size; i++)
		{
			this->table[i] = seq.table[i + std::min(start,stop)];
		}
	}

	~vArray()
	{
		delete[] table;
	}

	friend std::ostream& operator<<(std::ostream& stream, vArray<T>& output)
	{
		for (size_t i = 1; i < output.Size + 1; i++)
		{
			stream << output.table[i-1] << ' ';
		}

		stream << '\n';
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, vArray<T>& input)
	{
		for (size_t i = 1; i < input.Size + 1; i++)
		{
			stream >> input.table[i-1];
		}
		return stream;
	}

	void push(T data)
	{
		state(this->Size + 1);
		this->table[this->Size -1] = data;
		return;
	}

	void state(size_t newSize)
	{
		this->Size = newSize;
		T* buf = new T[Size];
		memcpy(buf, this->table, Size * sizeof(T));
		delete[] this->table;
		this->table = buf;

		return;
	}

	vArray& operator+=(const vArray<T>& add)
	{
		T* buf = new T[this->Size + add.Size];
		memcpy(buf, this->table, sizeof(T)*this->Size);
		int count=0;
		for (size_t i = Size + 1; i <= Size + add.Size; i++)
		{
			buf[i-1] = add.table[count];
			count++;
		}
		this->Size += add.Size;
		this->table = buf;
		return *this;
	}

	vArray& operator=(const vArray<T>& dupl)
	{
		memcpy(this->table, dupl.table, sizeof(T)*dupl.Size);
		this->Size = dupl.Size;
		return *this;
	}

	T pop()
	{
		T ret = this->table[Size - 1];
		state(this->Size - 1);
		return ret;
	}

	T& operator[] (size_t pos)
	{
		if (pos < Size)
		{
			return table[pos-1];
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
			for (size_t i = gap; i < Size; i ++)
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
		for (size_t i = 0; i < (Size/2); i++)
		{
			buf = table[i];
			table[i] = table[Size - 1 - i];
			table[Size - 1 - i] = buf;
		}
		return;
	}

	T& findElem(T elem)
	{
		for (size_t i = 0; i < Size; i++)
		{
			if (table[i] == elem)
				return table[i];
		}

		throw ArrayException("no such element");
	}
private:
	size_t Size = 10;
	T* table;
};
#endif /*VARRAY_H*/
