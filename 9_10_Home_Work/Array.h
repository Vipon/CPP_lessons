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
	Array(T (&val)[NUM]);
	Array(T (&&val)[NUM]) : elements(val) {};
	~Array() {};

	Array& operator=(const Array<T, NUM>& arr);
	T& operator[](size_t pos);
	void sort(int begin, int end);
	size_t find(T& value) const;

	template <typename Type, size_t S>
	friend std::ostream& operator<<(std::ostream& os, const Array<Type, S>& arr);

	//Example of Array input: ; x1; x2; x3) for NUM = 3; x1, x2, x3 - values;
	// ; - separating symbol, terminative symbol is a char symbol
	// that is different from the separating symbol (in this example - ) ).
	//If the amount of entered values is less than NUM, then the other elements are not changed
	template <typename Type, size_t S>
	friend std::istream& operator>>(std::istream& is, Array<Type, S>& arr); 

	class Iterator : public std::iterator<std::random_access_iterator_tag, T, int> { 
	public:
		Iterator() {};
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
		T* ptr; //pointer to the first element of the Array
		size_t pos; //number of the element
		friend Array<T, NUM>;

		Iterator(T* elem, size_t pos) : ptr(elem), pos(pos) {};
	};

	Iterator begin();
	Iterator end();

private:
	T elements[NUM + 1];
};


template<typename T, size_t NUM>
Array<T, NUM>::Array(T (&val)[NUM]) { 
		memcpy(elements, val, ((sizeof(T)) * NUM)); 
}

template<typename T, size_t NUM>
Array<T, NUM>& Array<T, NUM>::operator=(const Array<T, NUM>& arr) {
		memcpy(this->elements, arr.elements, ((sizeof(T)) * NUM));
		return *this;
}

template<typename T, size_t NUM>
T& Array<T, NUM>::operator[](size_t pos) {
	if (pos >= NUM) {
		throw std::out_of_range("The size of the Array is exceeded");
	}

	return (elements[pos]);
}

template<typename T, size_t NUM>
void Array<T, NUM>::sort(int begin, int end) {
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

template<typename T, size_t NUM>
size_t Array<T, NUM>::find(T& value) const {
	for (size_t i = 0; i < NUM; i++) {
		if ((*this)[i] == value) {
			return i;
		}
	};

	return (NUM + 1);
}

template<typename T, size_t NUM>
std::ostream& operator<<(std::ostream& os, const Array<T, NUM>& arr) {
	for (size_t i = 0; i < NUM; i++) {
		os << (arr.elements)[i] << ' ';
	};

	os << '\n';
	return os;
}

template<typename T, size_t NUM>
std::istream& operator>>(std::istream& is, Array<T, NUM>& arr)
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
};



template<typename T, size_t NUM>
T& Array<T, NUM>::Iterator::operator*() {
	return ptr[pos];
};

template<typename T, size_t NUM>
typename Array<T, NUM>::Iterator Array<T, NUM>::Iterator::operator++() {
	if (pos == NUM) {
		return (*this);
	};

	++pos;
	return (*this);
};

template<typename T, size_t NUM>
typename Array<T, NUM>::Iterator Array<T, NUM>::Iterator::operator++(int) {
	if (pos == NUM) {
		return (*this);
	};

	return Iterator(this->ptr, (pos++));
};

template<typename T, size_t NUM>
typename Array<T, NUM>::Iterator Array<T, NUM>::Iterator::operator--() {
	if (pos == 0) {
		return (*this);
	}

	--pos;
	return (*this);
};

template<typename T, size_t NUM>
typename Array<T, NUM>::Iterator Array<T, NUM>::Iterator::operator--(int) {
	if (pos == 0) {
		return (*this);
	}

	return Iterator(this->ptr, (pos--));
};

template<typename T, size_t NUM>
bool Array<T, NUM>::Iterator::operator==(Iterator& it) {
	return ((this->ptr == it.ptr) && (this->pos == it.pos));
};

template<typename T, size_t NUM>
bool Array<T, NUM>::Iterator::operator!=(Iterator& it) {
	return ((this->ptr != it.ptr) || (this->pos != it.pos));
};

template<typename T, size_t NUM>
typename Array<T, NUM>::Iterator& Array<T, NUM>::Iterator::operator=(const Iterator &it){
	ptr = it.ptr;
	pos = it.pos;
	return (*this);
};

template<typename T, size_t NUM>
int Array<T, NUM>::Iterator::operator-(const Iterator &it) {
	return ((this->pos) - (it.pos));
}

template<typename T, size_t NUM>
bool Array<T, NUM>::Iterator::operator<(Iterator& it) {
	return ((this->pos) < (it.pos));
}

template<typename T, size_t NUM>
bool Array<T, NUM>::Iterator::operator>(Iterator& it) {
	return ((this->pos) > (it.pos));
}

template<typename T, size_t NUM>
bool Array<T, NUM>::Iterator::operator<=(Iterator& it) {
	return ((this->pos) <= (it.pos));
}

template<typename T, size_t NUM>
bool Array<T, NUM>::Iterator::operator>=(Iterator& it) {
	return ((this->pos) >= (it.pos));
}

template<typename T, size_t NUM>
typename Array<T, NUM>::Iterator Array<T, NUM>::Iterator::operator+(int n) {
	if (((pos + n) > NUM) || ((pos + n) < 0)) {
		return (*this);
	};

	return Iterator((this->ptr), ((this->pos) + n));
}

template<typename T, size_t NUM>
typename Array<T, NUM>::Iterator Array<T, NUM>::Iterator::operator+=(int n) {
	if (((pos + n) > NUM) || ((pos + n) < 0)) {
		return (*this);
	};

	this->pos += n;

	return (*this);
}

template<typename T, size_t NUM>
typename Array<T, NUM>::Iterator Array<T, NUM>::Iterator::operator-(int n) {
	if (((pos - n) > NUM) || ((pos - n) < 0)) {
		return (*this);
	};
	return Iterator((this->ptr), ((this->pos) - n));
}

template<typename T, size_t NUM>
typename Array<T, NUM>::Iterator Array<T, NUM>::Iterator::operator-=(int n) {
	if (((pos - n) > NUM) || ((pos - n) < 0)) {
		return (*this);
	};

	this->pos -= n;

	return (*this);
}

template<typename T, size_t NUM>
size_t Array<T, NUM>::Iterator::it_pos() {
	return pos;
}

template<typename T, size_t NUM>
typename Array<T, NUM>::Iterator Array<T, NUM>::begin() {
	return Iterator(this->elements, 0);
};

template<typename T, size_t NUM>
typename Array<T, NUM>::Iterator Array<T, NUM>::end() {
	return Iterator(this->elements, NUM);
};

#endif //__ARRAY_H 