#ifndef __ARRAY_H
#define __ARRAY_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include <exception>

class Arr_excess_of_size : public std::exception {
public:
	const char* what() { return "The size of the array is exceeded"; }
};

template <typename T, size_t NUM = 10>
class Array {
public:
	Array(T (&val)[NUM]) { 
		memcpy(elements, val, ((sizeof(T)) * NUM)); 
	}

	Array(T (&&val)[NUM]) : elements(val) {}
	~Array() {}

	Array& operator=(const Array<T, NUM>& arr) {
		memcpy(this->elements, arr.elements, ((sizeof(T)) * NUM));
		return *this;
	}

	T& operator[](size_t pos) {
		if (pos >= NUM) {
			throw Arr_excess_of_size();
		}

		return &(elements[pos]);
	}

	friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
		for (size_t i = 0; i < NUM; i++) {
			os << (arr.elements)[i] << ' ';
		};

		os << '\n';
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Array& arr) {
		for (size_t i = 0; i < NUM; i++) {
			is >> (arr.elements)[i];
		};

		return is;
	}

private:
	T elements[NUM];
};

#endif //__ARRAY_H