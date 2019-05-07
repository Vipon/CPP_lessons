#ifndef __ARRAY_H
#define __ARRAY_H

#include <iostream>
#include <cstring>
#include <exception>
#include <cstddef>

template <typename T, size_t N>
class Array {

public:
	Array() {
		memset(arr, 0, (sizeof(T)*N));
	}
	~Array() = default;

	Array& operator=(const Array <T, N> & sanyalove) {
		memcpy(this->arr, sanyalove.arr, ((sizeof(T)) * N));
		return *this;
	}
	T& operator[](size_t n) {
		if (n >= N) {
			abort();
		}

		return (arr[n]);
	}

	friend std::ostream& operator<<(std::ostream& os, const Array& sanyalove) {
		for (size_t i = 0; i < N; i++) {
			os << (sanyalove.arr)[i] << ' ';
		};
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Array& sanyalove) {
		for (size_t i = 0; i < N; i++) {
			is >> (sanyalove.arr)[i];
		};
		return is;
	}

private:
	T arr[N];
};

#endif //__ARRAY_H