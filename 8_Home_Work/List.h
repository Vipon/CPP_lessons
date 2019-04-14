#ifndef __LIST_H
#define __LIST_H

#include <cstddef>
#include <iostream>
#include <exception>

template <typename T>
class List {
public:
	List() : begin(nullptr), end(nullptr), size(0) {};
	
	void insert_start(T val) {
		Elem* entry = new Elem;
		entry->value = val;

		if ((!begin) || (!end)) {
			begin = entry;
			end = entry;
			entry->next = nullptr;
			entry->prev = nullptr;
			size++;
		}
		else {
			entry->next = begin;
			entry->prev = nullptr;
			begin = entry;
			(entry->next)->prev = entry; 
			size++;
		}
	}

	void insert_end(T val) {
		Elem* entry = new Elem;
		entry->value = val;

		if ((!begin) || (!end)) {
			begin = entry;
			end = entry;
			entry->next = nullptr;
			entry->prev = nullptr;
			size++;
		}
		else {
			entry->next = nullptr;
			entry->prev = end;
			end = entry;
			(entry->prev)->next = entry;
			size++;
		}
	}

	T& operator[](size_t pos) {
		if (pos >= size) {
			throw std::out_of_range("The size of the List is exceeded");
		}

		Elem* t = begin;

		for (size_t i = 0; i < pos; i++) {
			t = t->next;
		}

		return (t->value);
	}

	void insert_after(T val, size_t num) {
		Elem* entry = new Elem;
		entry->value = val;

		size++;
		Elem* t = (this[num]).next;
		(this[num]).next = entry;
		t->prev = entry;
		entry->prev = this[num];
		entry->next = t;
	}

	void delete_elem(size_t num) {
		Elem* entry = this[num];
		if (begin == entry) {
			(entry->next)->prev = nullptr;
			begin = entry->next;
		}

		if (end == entry) {
			(entry->prev)->next = nullptr;
			end = entry->prev;
		}
		else {
			(entry->next)->prev = entry->prev;
			(entry->prev)->next = entry->next;
		}

		size--;
		delete entry;
	}

	T& find(T& val) const {
		Elem* t = begin;

		while((t) && ((t->value) != val)) {
			t = t->next;
		}

		return t->value;
	}

	~List() {
		Elem* entry = begin;

		if (entry) {
			while (entry->next) {
				entry = entry->next;
				delete entry->prev;
			}
		}

		delete entry;
	}

	friend std::ostream& operator<<(std::ostream& os, List& list) {
		for (size_t i = 0; i < list.size; ++i) {
			os << list[i] << "  ";
		};

		return os;
	}

	//Example of List input: ; x1; x2; x3) for num = 3; x1, x2, x3 - values;
	// ; - separating symbol, terminative symbol is a char symbol
	// that is different from the separating symbol (in this example - ) ).
	friend std::istream& operator>>(std::istream& is, List& list)
	{
		char buf = 0;
		char sep = 0; //separating symbol
		is >> sep;
		buf = sep;

		size_t i = 0;

		Elem* entry = list.begin;
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

private:
	struct Elem {
		Elem* next;
		Elem* prev;
		T value;
	};
	Elem* begin;
	Elem* end;
	size_t size;
};


#endif //__LIST_H