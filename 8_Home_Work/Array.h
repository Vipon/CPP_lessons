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

	friend std::istream& operator>>(std::istream& is, Array <T, N>& rep) {
		size_t i = 0;
		bool b = 0;
		std::cout << "\n" << "More symbols? If yes print 1 else print 0" << "\n";
		is >> b;
		while((i < N) && b) {
			is >> (rep.arr)[i];
			std::cout <<  "\n" << "More symbols? If yes print 1 else print 0s" << "\n";
			is >> b;
			i++;
		};
		for (i =i; i < N; ++i)
		{
			rep.arr[i] = 0;
		}

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
