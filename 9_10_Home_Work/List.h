#ifndef __LIST_H
#define __LIST_H

#include <cstddef>
#include <iostream>
#include <exception>
#include <iterator>

template <typename T>
class List {
private:
	struct Elem {
		Elem* next;
		Elem* prev;
		T value;
	};
	Elem* Begin;
	Elem* End; // pointer to the element after the last element  
	size_t size;

public:
	List();
	void insert_start(T val);
	void insert_end(T val);
	T& operator[](size_t pos);
	void insert_after(T val, size_t num);
	void delete_elem(size_t num);
	T& find(T& val) const;
	~List();

	template <typename Type>
	friend std::ostream& operator<<(std::ostream& os, List<Type>& list);

	//Example of List input: ; x1; x2; x3) for num = 3; x1, x2, x3 - values;
	// ; - separating symbol, terminative symbol is a char symbol
	// that is different from the separating symbol (in this example - ) ).
	template <typename Type>
	friend std::istream& operator>>(std::istream& is, List<Type>& list);

	class Iterator : public std::iterator<std::bidirectional_iterator_tag, T, int> {
	public:
		Iterator(){};
		Iterator(const Iterator& it) : ptr(it.ptr) {};
		~Iterator(){};
		T& operator*();
		Iterator operator++();
		Iterator operator++(int);
		Iterator operator--();
		Iterator operator--(int);
		Iterator& operator=(const Iterator &it);
		bool operator!=(const Iterator& it);
		bool operator==(const Iterator& it);
	private:
		Elem *ptr; // pointer to an element of the List
		friend List<T>;

		Iterator(Elem* elem) : ptr(elem) {};
	};

	Iterator begin();
	Iterator end(); 
};



template <typename T>
List<T>::List() : size(0) {
	Begin = new Elem;
	End = Begin;
	End->prev = nullptr;
	End->next = End;
};

template <typename T>
void List<T>::insert_start(T val) {
	Elem* entry = new Elem;
	entry->value = val;
	entry->next = Begin;
	entry->prev = nullptr;
	Begin = entry;
	(entry->next)->prev = entry; 
	size++;
}

template <typename T>
void List<T>::insert_end(T val) {
	Elem* entry = new Elem;
	entry->value = val;
	entry->prev = End->prev;
	End->prev = entry;
	entry->next = End;

	if (size == 0) {
		Begin = entry;
		size++;
	}
	else {
		(entry->prev)->next = entry;
		size++;
	}
}

template <typename T>
T& List<T>::operator[](size_t pos) {
	if (pos >= size) {
		throw std::out_of_range("The size of the List is exceeded");
	}

	Elem* t = Begin;

	for (size_t i = 0; i < pos; i++) {
		t = t->next;
	}

	return (t->value);
}

template <typename T>
void List<T>::insert_after(T val, size_t num) {
	Elem* entry = new Elem;
	entry->value = val;

	size++;
	Elem* t = (this[num]).next;
	(this[num]).next = entry;
	t->prev = entry;
	entry->prev = this[num];
	entry->next = t;
}

template <typename T>
void List<T>::delete_elem(size_t num) {
	Elem* entry = this[num];
	if (Begin == entry) {
		(entry->next)->prev = nullptr;
		Begin = entry->next;
	}

	if (End == entry) {
		(entry->prev)->next = nullptr;
		End = entry->prev;
	}
	else {
		(entry->next)->prev = entry->prev;
		(entry->prev)->next = entry->next;
	}

	size--;
	delete entry;
}

template <typename T>
T& List<T>::find(T& val) const {
	Elem* t = Begin;

	while((t) && ((t->value) != val) && (t != End)) {
		t = t->next;
	}

	return t->value;
}

template <typename T>
List<T>::~List() {
	Elem* entry = Begin;

	while (entry != End) {
		entry = entry->next;
		delete entry->prev;
	}

	delete entry;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, List<T>& list) {
	typename List<T>::Elem* t = list.Begin;
		
	while ((t) && (t != list.End)) {
		os << t->value << "  ";
		t = t->next;
	}

	return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, List<T>& list) {
	char buf = 0;
	char sep = 0; //separating symbol
	is >> sep;
	buf = sep;

	size_t i = 0;

	typename List<T>::Elem* entry = list.Begin;
	T val;

	while (buf == sep) {
		if (entry) {
			is >> entry->value;
			entry = entry->next;
		}
		else {
			is >> val;
			list.insert_end(val);
		}

		is >> buf;
		i++;
	}

	if (i < list.size) {
		for ( ; i < list.size; ++i) {
			list.delete_elem(i);
		}
	}

	return is;
} 



template <typename T>
T& List<T>::Iterator::operator*() {
	return (ptr->value);
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator++() {
	ptr = ptr->next;
	return (*this);
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
	Elem* temp = ptr;
	ptr = ptr->next;
	return Iterator(temp);
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator--() {
	if (ptr->prev) {
		ptr = ptr->prev;
	}

	return (*this);
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator--(int) {
	if (!(ptr->prev)) {
		return (*this);
	}

	Elem* temp = ptr;
	ptr = ptr->prev;
	return Iterator(temp);
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator=(const Iterator &it) {
	ptr = it.ptr;
	return (*this);
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator &it) {
	return (ptr != (it.ptr));
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator &it) {
	return (ptr == (it.ptr));
}

template <typename T>
typename List<T>::Iterator List<T>::begin() {
	return Iterator(Begin);
}

template <typename T>
typename List<T>::Iterator List<T>::end() {
	return Iterator(End);
}

#endif //__LIST_H 