#ifndef __VARRAY_H
#define __VARRAY_H

#include <cstddef>
#include <cstring>
#include <iostream>

template <typename T>
class vArray {
public:
	vArray(T* elem, size_t num = 1) : 
		num(num), 
		elements(new T[num])
	{
		if (elem == nullptr) {
			abort();
		}

		memcpy(elements, elem, (num*(sizeof(T))));
	}

	vArray(const vArray& v) :
		num(v.num),
		elements(new T[num])
	{
		memcpy(this->elements, v.elements, (num*(sizeof(T))));
	}


	vArray(vArray&& v) noexcept :
		num(v.num),
		elements(v.elements)
	{
		v.elements = nullptr;
		v.num = 0;
	}

	~vArray() { delete [] elements; }

	vArray operator=(const vArray<T>& arr) {
		num = arr.num;
		delete [] elements;
		elements = new T[num];
		memcpy(this->elements, arr.elements, (num * (sizeof(T))));
		return *this;
	}

	T operator[](size_t pos) {
		if (pos >= num) {
			abort();
		}

		return elements[pos];
	}

	friend std::ostream& operator<<(std::ostream& os, const vArray& arr) {
		os << '(';
		for (size_t i = 0; i < (arr.num - 1); ++i) {
			os << (arr.elements)[i] << "; ";
		};

		os << (arr.elements)[arr.num - 1] << ')';
		return os;
	}

	//Example of vArray input: (x1; x2; x3) for num = 3; x1, x2, x3 - values.
	friend std::istream& operator>>(std::istream& is, vArray& arr)
	{
		char buf = 0;
		is >> buf;

		if (buf != '(') {
			return is;
		}

		size_t i = 0;

		while (buf != ')') {
			if (i >= arr.num) {
				T* temp = arr.elements;
				arr.elements = new T[arr.num * 2];
				memcpy(arr.elements, temp, (arr.num * (sizeof(T))));
				arr.num *= 2;
				delete [] temp;
			}

			is >> arr.elements[i];
			is >> buf;
			i++;
		}

		T* temp = arr.elements;
		arr.elements = new T[i];
		memcpy(arr.elements, temp, (i * (sizeof(T))));
		delete [] temp;
		return is;
	} 

private:
	size_t num;
	T* elements;
};


#endif //__VARRAY_H