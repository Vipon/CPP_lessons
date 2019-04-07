#ifndef __VARRAY_H
#define __VARRAY_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include <exception>

class vArr_excess_of_size : public std::exception {
public:
	const char* what() { return "The size of the vArray is exceeded"; }
};

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

	vArray& operator=(const vArray<T>& arr) {
		num = arr.num;
		delete [] elements;
		elements = new T[num];
		memcpy(this->elements, arr.elements, (num * (sizeof(T))));
		return *this;
	}

	T& operator[](size_t pos) {
		if (pos >= num) {
			throw vArr_excess_of_size();
		}

		return &(elements[pos]);
	}

	friend std::ostream& operator<<(std::ostream& os, const vArray& arr) {
		os << '(';
		for (size_t i = 0; i < (arr.num - 1); ++i) {
			os << (arr.elements)[i] << "; ";
		};

		os << (arr.elements)[arr.num - 1] << ')';
		return os;
	}

	//Example of vArray input: ; x1; x2; x3) for num = 3; x1, x2, x3 - values;
	// ; - separating symbol, terminative symbol is a char symbol
	// that is different from the separating symbol (in this example - ) ).
	friend std::istream& operator>>(std::istream& is, vArray& arr)
	{
		char buf = 0;
		char sep = 0; //separating symbol
		is >> sep;
		buf = sep;

		size_t i = 0;

		while (buf == sep) {
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
		arr.num = i;
		return is;
	} 

	void set_size(size_t new_size) {
		if (new_size == num) {
			return;
		}

		T* temp = elements;
		elements = new T[new_size];
		if (new_size < num) {
			memcpy(elements, temp, (new_size * (sizeof(T))));
		}
		else {
			memcpy(elements, temp, (num * (sizeof(T))));
		}
		num = new_size;
	}

private:
	size_t num;
	T* elements;
};


#endif //__VARRAY_H