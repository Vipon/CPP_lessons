#ifndef VARRAY_H
#define VARRAY_H
#include <iostream>

template <typename T>
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
			this->table[i-1] = add.table[count];
			count++;
		}
		this->Size += add.Size;
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
		return T;
	}


private:
	size_t Size = 10;
	T* table;
};
#endif /*VARRAY_H*/