#ifndef VARRAY_H
#define VARRAY_H
#include "my_Exception.h"
#include <iostream>
#include <cstring>
#include <string>
#include <iterator>
#include <algorithm>
#include <cstddef>
#include<numeric>


template <typename T>
class vArray
{
public:

	class Iterator : public std::iterator<std::random_access_iterator_tag, T, int>
	{
	public:
		Iterator() {};
		Iterator(const Iterator& it) : Pointer(it.Pointer), pos(it.pos), num(it.num) {};
		~Iterator() {};

		T& operator*()
		{
			return *Pointer[pos];
		}

		Iterator operator++()
		{
			if (*num == pos)
				return *this;

			++pos;

			return *this;
		}

		Iterator operator--()
		{
			if (pos == 0)
				return *this;

			--pos;

			return *this;
		}

		bool operator==(Iterator& it)
		{
			return ((this->pos == it.pos) && (this->num == it.num) && (this->Pointer == it.Pointer));
		}

		bool operator!=(const Iterator& it) const
		{
			return !((this->pos == it.pos) && (this->num == it.num) && (this->Pointer == it.Pointer));
		}

		Iterator& operator=(const Iterator& it)
		{
			this->pos = it.pos;
			this->num = it.num;
			this->Pointer = it.Pointer;

			return *this;
		}

		int operator-(const Iterator& it) const
		{
			return this->pos - it.pos;
		}

		bool operator<(Iterator& it)
		{
			return this->pos < it.pos;
		}

		bool operator>(Iterator& it)
		{
			return this->pos > it.pos;
		}

		bool operator<=(Iterator& it)
		{
			return this->pos <= it.pos;
		}

		bool operator>=(Iterator& it)
		{
			return this->pos >= it.pos;
		}

		Iterator operator+(int n)
		{
			if ((this->pos + n > *this->num) || (this->pos + n < 0))
				return *this;

			return Iterator(this->Pointer, this->pos + n, this->num);
		}
		Iterator operator+=(int n)
		{
			if ((this->pos + n <= *num) && (this->pos + n >= 0))
				this->pos += n;

			return *this;
		}

		Iterator operator-(int n)
		{
			if ((this->pos - n > *this->num) || (this->pos - n < 0))
				return *this;

			return Iterator(this->Pointer, this->pos - n, this->num);
		}

		Iterator operator-=(int n)
		{
			if ((this->pos - n <= *num) && (this->pos - n >= 0))
				this->pos -= n;

			return *this;
		}

		size_t iter_pos() { return this->pos; }


	private:
		T** Pointer;
		size_t pos;
		size_t* num;
		friend vArray<T>;

		Iterator(T** elem, size_t pos, size_t* size) : Pointer(elem), pos(pos), num(size) {};
	};


	Iterator begin()
	{
		return Iterator(&table, 0, &Size);
	}

	Iterator end()
	{
		return Iterator(&table, Size, &Size);
	}

	vArray()
	{
		this->table = new T[this->Size];
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
		this->Size = std::max(stop, start) - std::min(start, stop) + 1;
		this->table = new T[Size];
		for (size_t i = 0; i < Size; i++)
		{
			this->table[i] = seq.table[i + std::min(start, stop)];
		}
		if (seq.last_pos <= std::max(stop, start))
		{
			this->last_pos = seq.last_pos - std::min(stop, start);
		}
		else
		{
			this->last_pos = this->Size + 1;
		}

	}

	vArray(size_t Size)
	{
		this->Size = Size;
		this->last_pos = 0;
		this->table = new T[Size];
	}

	~vArray()
	{
		delete[] table;
	}

	friend std::ostream& operator<<(std::ostream& stream, vArray<T>& output)
	{
		for (size_t i = 1; i < output.last_pos; i++)
		{
			stream << output.table[i - 1] << ' ';
		}

		stream << '\n';
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, vArray<T>& input)
	{
		std::string buf = "oh shit";
		while (true)
		{
			std::getline(stream, buf);

			if (buf == " ")
			{
				return stream;
			}

			if (input.last_pos == input.Size)
			{
				input.set_size(2 * (input.Size + 1));
			}

			input.table[input.last_pos] = (T)stod(buf);
			input.last_pos++;
		}

		if (input.last_pos < input.Size)
		{
			input.Size = input.last_pos - 1;
		}

		return stream;
	}

	void push_back(T data)
	{
		if (this->last_pos > this->Size)
			set_size(2 * (this->Size));
		this->table[this->last_pos] = data;
		this->last_pos++;
		return;
	}

	void set_size(size_t newSize)
	{
		if (this->last_pos > newSize)
		{
			this->last_pos = newSize;
		}

		this->Size = newSize;
		T* buf = new T[newSize];
		memcpy(buf, this->table, this->Size * sizeof(T));
		delete[] this->table;
		this->table = buf;

		return;
	}

	vArray& operator+=(const vArray<T>& add)
	{
		T* buf = new T[this->Size + add.Size];
		memcpy(buf, this->table, sizeof(T)*this->Size);
		int count = 0;
		for (size_t i = Size + 1; i <= Size + add.Size; i++)
		{
			buf[i - 1] = add.table[count];
			count++;
		}
		this->Size += add.Size;
		this->last_pos += (add.last_pos - 1);
		delete[] table;
		this->table = buf;

		return *this;
	}

	vArray& operator=(const vArray<T>&& dupl)
	{
		this->Size = dupl.Size;
		memcpy(this->table, dupl.table, sizeof(T)*dupl.Size);
		this->last_pos = dupl.last_pos;
		return *this;
	}

	T pop()
	{
		if (this->last_pos == 0)
			throw ArrayException("Array is empty.");
		T ret = this->table[Size - 1];
		this->last_pos--;
		return ret;
	}

	T& operator[] (size_t pos)
	{
		if (pos < this->last_pos)
		{
			return this->table[pos - 1];
		}
		else
		{
			throw ArrayException("out of range");
		}
	}

	void sortUp() //shellsort
	{
		if (last_pos <= 1)
			return;
		for (size_t gap = (last_pos - 1) / 2; gap > 0; gap /= 2)
		{
			for (size_t i = gap; i < last_pos - 1; i++)
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
		for (size_t i = 0; i < ((last_pos - 1) / 2); i++)
		{
			buf = table[i];
			table[i] = table[last_pos - 2 - i];
			table[last_pos - 2 - i] = buf;
		}
		return;
	}

	T& findElem(T elem)
	{
		for (size_t i = 0; i < this->last_pos - 1; i++)
		{
			if (table[i] == elem)
				return table[i];
		}

		throw ArrayException("no such element");
	}



private:
	size_t last_pos = 0;
	size_t Size = 10;
	T* table;
};
#endif /*VARRAY_H*/
