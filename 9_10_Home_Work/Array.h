#ifndef __ARRAY_H
#define __ARRAY_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include <exception>
#include <iterator>

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

	void sort(int begin, int end) {
		if ((begin < 0) || (end >= NUM)) {
			throw std::out_of_range("The size of the Array is exceeded");
		}

		T temp; 
		int l = begin;
		int r = end;
		T piv = elements[((l + r) / 2)];
		while (l <= r) {
			while (elements[l] < piv) {
				l++;
			}

			while (elements[r] > piv) {
				r--;
			}

			if (l <= r) {
				temp = elements[l];
				elements[l++] = elements[r];
				elements[r--] = temp;
			}
		}

		if (begin < r) {
			sort(begin, r);
		}

		if (end > l) {
			sort(l, end);
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

	//Example of Array input: ; x1; x2; x3) for NUM = 3; x1, x2, x3 - values;
	// ; - separating symbol, terminative symbol is a char symbol
	// that is different from the separating symbol (in this example - ) ).
	//If the amount of entered values is less than NUM, then the other elements are not changed
	friend std::istream& operator>>(std::istream& is, Array<T, NUM>& arr)
	{
		char buf = 0;
		char sep = 0; //separating symbol
		is >> sep;
		buf = sep;

		size_t i = 0;

		while (buf == sep) {
			if (i >= NUM) {
				return is;
			}

			is >> arr.elements[i];
			is >> buf;
			i++;
		}

		return is;
	} 

	class Iterator : public std::iterator<std::random_access_iterator_tag, T, size_t> { 
	public:
		Iterator() {};
		Iterator(const Iterator& it) : ptr(it.ptr), pos(it.pos) {};
		Iterator(T* elem, size_t pos) : ptr(elem), pos(pos) {};
		~Iterator() {};

		T& operator*() {
			return ptr[pos];
		};

		Iterator& operator++() {
			if (pos == NUM) {
				return (*this);
			};
			
			++pos;
			return (*this);
		};

		Iterator& operator++(int) {
			if (pos == NUM) {
				return (*this);
			};

			return Iterator(this->ptr, (pos++));
		};

		Iterator operator--() {
			if (pos == 0) {
				return (*this);
			}

			--pos;
			return (*this);
		};

		Iterator operator--(int) {
			if (pos == 0) {
				return (*this);
			}
			
			return Iterator(this->ptr, (pos--));
		};

		bool operator==(Iterator& it) {
			return ((this->ptr == it.ptr) && (this->pos == it.pos));
		};

		bool operator!=(Iterator& it) {
			return ((this->ptr != it.ptr) || (this->pos != it.pos));
		};

		Iterator& operator=(const Iterator &it){
			ptr = it.ptr;
			pos = it.pos;
			return (*this);
		};

		size_t operator-(const Iterator &it) {
			return ((this->pos) - (it.pos));
		}

		bool operator<(Iterator& it) {
			return ((this->pos) < (it.pos));
		}

		bool operator>(Iterator& it) {
			return ((this->pos) > (it.pos));
		}

		Iterator operator+(size_t n) {
			if ((pos + n) > NUM) {
				return (*this);
			};

			return Iterator((this->ptr), ((this->pos) + n));
		}

		Iterator operator-(size_t n) {
			if ((pos - n) < 0) {
				return (*this);
			};
			return Iterator((this->ptr), ((this->pos) - n));
		}

		size_t it_pos() {
			return pos;
		}

	private:
		T* ptr; //pointer to the first element of the Array
		size_t pos; //number of the element
		friend Array<T, NUM>;
	};

	Iterator begin() {
		return Iterator(elements, 0);
	};

	Iterator end() {
		return Iterator(elements, NUM);
	};

private:
	T elements[NUM + 1];
};

#endif //__ARRAY_H