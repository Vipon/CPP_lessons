#ifndef __VARRAY_H
#define __VARRAY_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include <exception>
#include <iterator>


template <typename T>
class vArray {
public:
	vArray(T* elem, size_t num = 1);
	vArray(const vArray& v);
	vArray(vArray&& v) noexcept;
	~vArray() { delete [] elements; }

	vArray& operator=(const vArray<T>& arr);
	vArray& operator=(vArray<T>&& arr);
	vArray& operator+=(const vArray<T>& arr);
	vArray operator+(vArray<T>& arr);
	T& operator[](size_t pos);
	void sort(int begin, int end);
	size_t find(T& value) const;

	template <typename Type>
	friend std::ostream& operator<<(std::ostream& os, const vArray<Type>& arr);

	//Example of vArray input: ; x1; x2; x3) for num = 3; x1, x2, x3 - values;
	// ; - separating symbol, terminative symbol is a char symbol
	// that is different from the separating symbol (in this example - ) 

	template <typename Type>
	friend std::istream& operator>>(std::istream& is, vArray<Type>& arr);

	void set_size(size_t new_size);

	class Iterator : public std::iterator<std::random_access_iterator_tag, T, int> { 
	public:
		Iterator() {};
		Iterator(const Iterator& it) : ptr(it.ptr), pos(it.pos), size(it.size) {};
		~Iterator() {};

		T& operator*();
		Iterator operator++();
		Iterator operator++(int);
		Iterator operator--();
		Iterator operator--(int);
		bool operator==(Iterator& it);
		bool operator!=(Iterator& it);
		Iterator& operator=(const Iterator &it);
		int operator-(const Iterator &it);
		bool operator<(Iterator& it);
		bool operator>(Iterator& it);
		bool operator<=(Iterator& it);
		bool operator>=(Iterator& it);
		Iterator operator+(int n);
		Iterator operator+=(int n);
		Iterator operator-(int n);
		Iterator operator-=(int n);

		size_t it_pos();

	private:
		T** ptr; //pointer to the pointer to the first element of the vArray
		size_t pos; //number of the element
		size_t* size; //the pointer to the value of the current size of the vArray (num)
		friend vArray<T>;

		Iterator(T** elem, size_t pos, size_t* size) : ptr(elem), pos(pos), size(size) {};
	};

	Iterator begin();
	Iterator end();

private:
	size_t num;
	T* elements;
};



template <typename T>
vArray<T>::vArray(T* elem, size_t num) : 
	num(num), 
	elements(new T[num + 1])
{
	if (elem == nullptr) {
		throw std::invalid_argument("nullptr argument to vArray constructor");
	}

	memcpy(elements, elem, (num*(sizeof(T))));
}

template <typename T>
vArray<T>::vArray(const vArray<T>& v) :
	num(v.num),
	elements(new T[num + 1])
{
	memcpy(this->elements, v.elements, (num*(sizeof(T))));
}

template <typename T>
vArray<T>::vArray(vArray<T>&& v) noexcept :
	num(v.num),
	elements(v.elements)
{
	v.elements = nullptr;
	v.num = 0;
}

template <typename T>
vArray<T>& vArray<T>::operator=(const vArray<T>& arr) {
	num = arr.num;
	delete [] elements;
	elements = new T[num + 1];
	memcpy(this->elements, arr.elements, (num * (sizeof(T))));
	return *this;
}

template <typename T>
vArray<T>& vArray<T>::operator=(vArray<T>&& arr) {
	num = arr.num;
	elements = arr.elements;
	arr.num = 0;
	arr.elements = nullptr;
	return *this;
}

template <typename T>
vArray<T>& vArray<T>::operator+=(const vArray<T>& arr) {
	size_t newnum = num + arr.num;
	T* temp = new T[newnum + 1];
	memcpy(temp, elements, (num * (sizeof(T))));
	memcpy(temp + num, arr.elements, (arr.num * (sizeof(T))));
	delete [] elements;
	num = newnum;
	elements = temp;
	return *this;
}

template <typename T>
vArray<T> vArray<T>::operator+(vArray<T>& arr) {
	return (vArray<T>(elements, num) += arr);
}

template <typename T>
T& vArray<T>::operator[](size_t pos) {
	if (pos >= num) {
		throw std::out_of_range("The size of the vArray is exceeded");
	}

	return (elements[pos]);
}

template <typename T>
void vArray<T>::sort(int begin, int end) {
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

template <typename T>
size_t vArray<T>::find(T& value) const {
	for (size_t i = 0; i < num; i++) {
		if ((*this)[i] == value) {
			return i;
		}
	};

	return (num + 1);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const vArray<T>& arr) {
	os << '(';
	for (size_t i = 0; i < (arr.num - 1); ++i) {
		os << (arr.elements)[i] << "; ";
	};

	os << (arr.elements)[arr.num - 1] << ')';
	return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, vArray<T>& arr)
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
	arr.elements = new T[i + 1];
	memcpy(arr.elements, temp, (i * (sizeof(T))));
	delete [] temp;
	arr.num = i;
	return is;
} 

template <typename T>
void vArray<T>::set_size(size_t new_size) {
	if (new_size == num) {
		return;
	}

	T* temp = elements;
	elements = new T[new_size + 1];
	if (new_size < num) {
		memcpy(elements, temp, (new_size * (sizeof(T))));
	}
	else {
		memcpy(elements, temp, (num * (sizeof(T))));
	}
	num = new_size;
}



template <typename T>
T& vArray<T>::Iterator::operator*() {
	return (*ptr)[pos];
};

template <typename T>
typename vArray<T>::Iterator vArray<T>::Iterator::operator++() {
	if (pos == (*size)) {
		return (*this);
	};

	++pos;
	return (*this);
};

template <typename T>
typename vArray<T>::Iterator vArray<T>::Iterator::operator++(int) {
	if (pos == (*size)) {
		return (*this);
	};

	return Iterator(this->ptr, (pos++), size);
};

template <typename T>
typename vArray<T>::Iterator vArray<T>::Iterator::operator--() {
	if (pos == 0) {
		return (*this);
	}

	--pos;
	return (*this);
};

template <typename T>
typename vArray<T>::Iterator vArray<T>::Iterator::operator--(int) {
	if (pos == 0) {
		return (*this);
	}

	return Iterator(this->ptr, (pos--), size);
};

template <typename T>
bool vArray<T>::Iterator::operator==(Iterator& it) {
	return ((this->ptr == it.ptr) && (this->pos == it.pos) && (this->size == it.size));
};

template <typename T>
bool vArray<T>::Iterator::operator!=(Iterator& it) {
	return ((this->ptr != it.ptr) || (this->pos != it.pos) || (this->size != it.size));
};

template <typename T>
typename vArray<T>::Iterator& vArray<T>::Iterator::operator=(const Iterator &it){
	ptr = it.ptr;
	pos = it.pos;
	size = it.size;
	return (*this);
};

template <typename T>
int vArray<T>::Iterator::operator-(const Iterator &it) {
	return ((this->pos) - (it.pos));
}

template <typename T>
bool vArray<T>::Iterator::operator<(Iterator& it) {
	return ((this->pos) < (it.pos));
}

template <typename T>
bool vArray<T>::Iterator::operator>(Iterator& it) {
	return ((this->pos) > (it.pos));
}

template <typename T>
bool vArray<T>::Iterator::operator<=(Iterator& it) {
	return ((this->pos) <= (it.pos));
}

template <typename T>
bool vArray<T>::Iterator::operator>=(Iterator& it) {
	return ((this->pos) >= (it.pos));
}

template <typename T>
typename vArray<T>::Iterator vArray<T>::Iterator::operator+(int n) {
	if (((pos + n) > (*size)) || ((pos + n) < 0)) {
		return (*this);
	};

	return Iterator((this->ptr), ((this->pos) + n), this->size);
}

template <typename T>
typename vArray<T>::Iterator vArray<T>::Iterator::operator+=(int n) {
	if (((pos + n) > (*size)) || ((pos + n) < 0)) {
		return (*this);
	};

	this->pos += n;

	return (*this);
}

template <typename T>
typename vArray<T>::Iterator vArray<T>::Iterator::operator-(int n) {
	if (((pos - n) > (*size)) || ((pos - n) < 0)) {
		return (*this);
	};

	return Iterator((this->ptr), ((this->pos) - n), this->size);
}

template <typename T>
typename vArray<T>::Iterator vArray<T>::Iterator::operator-=(int n) {
	if (((pos - n) > (*size)) || ((pos - n) < 0)) {
		return (*this);
	};

	this->pos -= n;

	return (*this);
}

template <typename T>
size_t vArray<T>::Iterator::it_pos() {
	return pos;
}

template <typename T>
typename vArray<T>::Iterator vArray<T>::begin() {
	return Iterator(&elements, 0, &num);
};

template <typename T>
typename vArray<T>::Iterator vArray<T>::end() {
	return Iterator(&elements, num, &num);
};



#endif //__VARRAY_H 