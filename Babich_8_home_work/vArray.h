#ifndef VARRAY_H
#define VARRAY_H
#include <iostream>

template <typename T, size_t Size>
class vArray 
{
public:
	vArray() = default;
	~vArray() = default;
	friend std::ostream& operator<<(std::ostream& stream, vArray<T, Size> output);
	friend std::istream& operator>>(std::istream& stream, vArray<T, Size> input);
	vArray& operator=(vArray dupl);
private:
	size_t Size;
	T* table;
};
#endif /*VARRAY_H*/