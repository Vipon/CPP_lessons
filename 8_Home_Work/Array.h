#ifndef ARRAY_H
#define ARRAY_H

#include <cstring>
#include <iostream>
#include <exception>
#include <cstddef>

template <typename T, size_t N>
class Array {
public:
	Array(){
		memset(arr, 0, (sizeof(T) * N));
	}

	Array(T (&val)[N]){
		memcpy(arr, val, (sizeof(T) * N));
	}

	Array(const Array& arra) {
		memcpy(this -> arr, arra.arr, (sizeof(T) * N));
	}

	~Array() = default;


	T& operator[](size_t n) {
		if (n >= N) {
			throw std::out_of_range("n > N");
		}

		return(arr[n]);
	}

	Array& operator = (const Array <T, N>& rep) {
		memcpy(this -> arr, rep.arr, (sizeof(T) * N));
		return *this;
	}

	friend std::istream& operator>>(std::istream& is, Array& rep) {
		for(size_t i = 0; i < N; i++) {
			is >> (rep.arr)[i];
		};

		return is;
	}

	friend std::ostream& operator<<(std::ostream& os, const Array& rep) {
		for(size_t i = 0; i < N; i++) {
			os << (rep.arr)[i] << ' ';
		};

		return os;		
	}
private:
	T arr[N];

};

#endif