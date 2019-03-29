#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cstdio>

template <typename T>
class Array
{
public:
	Array(size_t size);
		~Array();
	friend std::ostream& operator<<(std::ostream& stream, Array<T>& output);
	friend std::istream& operator>>(std::istream& stream, Array<T>& input);
	Array& operator=(Array<T> dupl);
private:
	const size_t size;
	T* table;
};
#endif /*ARRAY_H*/
