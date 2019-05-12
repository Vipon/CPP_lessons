#ifndef __VARRAY_H
#define __VARRAY_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include <exception>


template <typename T>
class vArray {
public:
	vArray(size_t num = 1) :
		size(num),
		num(num), 
		elements(new T[num]) {};

	vArray(T* elem, size_t num = 1) : 
		size(num),
		num(num), 
		elements(new T[num])
	{
		if (elem == nullptr) {
			throw std::invalid_argument("nullptr argument to vArray constructor");
		}

		memcpy(elements, elem, (num*(sizeof(T))));
	}

	vArray(const vArray& v) :
		size(v.num),
		num(v.num),
		elements(new T[num])
	{
		memcpy(this->elements, v.elements, (num*(sizeof(T))));
	}


	vArray(vArray&& v) noexcept :
		size(v.size),
		num(v.num),
		elements(v.elements)
	{
		v.elements = nullptr;
		v.num = 0;
		v.size = 0;
	}

	~vArray() { delete [] elements; }

	size_t arr_num() {
		return num;
	}

	void set_num(size_t new_num) {
		if (new_num == num) {
			return;
		}

		if (new_num <= size) {
			num = new_num;
			return;
		}

		T* temp = elements;
		elements = new T[new_num];

		if (new_num < num) {
			memcpy(elements, temp, (new_num * (sizeof(T))));
		}
		else {
			memcpy(elements, temp, (num * (sizeof(T))));
		}
		num = new_num;
		size = new_num;
		delete [] temp;
	}

	void set_size(size_t new_size) {
		if (new_size == size) {
			return;
		}

		T* temp = elements;
		elements = new T[new_size];
		if (new_size < num) {
			memcpy(elements, temp, (new_size * (sizeof(T))));
			num = new_size;
		}
		else {
			memcpy(elements, temp, (num * (sizeof(T))));
		}
		size = new_size;
		delete [] temp;
	}

	void push_back(T value) {
		if (num < size) {
			elements[num++] = value;
		}
		else {
			set_size((size * 2) + 1);
			elements[num++] = value;
		}
	}

	vArray& operator=(const vArray<T>& arr) {
		num = arr.num;
		size = arr.num;
		delete [] elements;
		elements = new T[num];
		memcpy(this->elements, arr.elements, (num * (sizeof(T))));
		return *this;
	}


	vArray& operator=(vArray<T>&& arr) {
		size = arr.size;
		num = arr.num;
		elements = arr.elements;
		arr.num = 0;
		arr.size = 0;
		arr.elements = nullptr;
		return *this;
	}

	vArray& operator+=(const vArray<T>& arr) {
		set_num(num + arr.num);
		memcpy(elements + num, arr.elements, (arr.num * (sizeof(T))));
		return *this;
	}

	vArray operator+(vArray<T>& arr) {
		return (vArray<T>(elements, num) += arr);
	}

	T& operator[](size_t pos) {
		if (pos >= num) {
			throw std::out_of_range("The size of the vArray is exceeded");
		}

		return (elements[pos]);
	}

	void sort(int begin, int end) {
		if ((begin < 0) || (end >= num)) {
			throw std::out_of_range("The size of the vArray is exceeded");
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
		for (size_t i = 0; i < num; i++) {
			if ((*this)[i] == value) {
				return i;
			}
		};

		return (num + 1);
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
		T temp;
		is >> sep;
		buf = sep;
		arr.num = 0;

		size_t i = 0;

		while (buf == sep) {
			is >> temp;
			arr.push_back(temp);
			is >> buf;
		}
		
		return is;
	} 

private:
	size_t size; // the size of the allocated memory for the array
	size_t num; //the size of the array
	T* elements;

};


#endif //__VARRAY_H