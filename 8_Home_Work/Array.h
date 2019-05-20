#ifndef __ARRAY_H
#define __ARRAY_H

#include <iostream>
#include <cstring>
#include <exception>
#include <cstddef>

template <typename Type, size_t size>
class Array {

public:
	Array() {
		memset(arr, 0, (sizeof(Type)*size));
	}
	~Array() = default;

	Array& operator=(const Array <Type, size> & last) {
		memcpy(this->arr, last.arr, ((sizeof(Type)) * size));
		return *this;
	}
	T& operator[](size_t s) {
		if (s >= size) {
			abort();
		}

		return (arr[s]);
	}

	friend std::ostream& operator<<(std::ostream& out, const Array& last) {
		for (size_t i = 0; i < size; i++) {
			out << (last.arr)[i] << ' ';
		};
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Array& last) {
		for (size_t i = 0; i < size; i++) {
			is >> (last.arr)[i];
		};
		return in;
	}

private:
	Type arr[size];
};

#endif //__ARRAY_H 