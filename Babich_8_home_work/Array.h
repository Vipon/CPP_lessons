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
		for (size_t i = 1; i < (output.last_pos-1)+1; i++)
		{
			if(output.table[i-1] )
			stream << output.table[i-1] << " ";
		}
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, Array<T, Size>& input)
	{
		std::string buf = "oh shit";
		for(int i = 0; i< (input.last_pos-1); i++)
		{
			std::getline(stream, buf);

			if (buf == " ")
			{
				return stream;
			}
			
			input.table[i] = (T)stod(buf);
		}
		return stream;
	}

	void push_back(T data)
	{
		this->table[this->last_pos] = data;
		this->last_pos++;
		return;
	}

	Array& operator=(const Array<T, Size>& dupl)
	{
		memcpy(this->table, dupl.table, sizeof(T)*(last_pos-1));
		return *this;
	}

	T& operator[] (size_t pos)
	{
		if (pos < (last_pos-1))
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
		for (size_t gap = (last_pos-1) / 2; gap > 0; gap /= 2)
		{
			for (size_t i = gap; i < (last_pos-1); i++)
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
		for (size_t i = 0; i < ((last_pos-1) / 2); i++)
		{
			buf = table[i];
			table[i] = table[(last_pos-1) - 1 - i];
			table[(last_pos-1) - 1 - i] = buf;
		}
		return;
	}

private:
	T table[Size];
	size_t last_pos = 0;
};
#endif /*ARRAY_H*/
