#ifndef __ARRAY_H
#define __ARRAY_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include <exception>

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
			throw std::out_of_range("The size of the Array is exceeded");
		}

		return (elements[pos]);
	}

	void sort() {
		T temp; 

		for (size_t i = 0; i < NUM - 1; i++) {
			for (size_t j = 0; j < NUM - i - 1; j++) {
				if (elements[j] > elements[j + 1]) {
					temp = elements[j];
					elements[j] = elements[j + 1];
					elements[j + 1] = temp;
				}
			}
		}
	}

	size_t find(T& value) const {
		for (size_t i = 0; i < NUM; i++) {
			if ((*this)[i] == value) {
				return i;
			}
		};

		return (NUM + 1);
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