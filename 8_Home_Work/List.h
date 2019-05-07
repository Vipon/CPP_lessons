#include <cstdio>
#include <cstdint>
#include <iostream>

template <typename T>
class List {

public:
	List();
	~List();
	T& operator[](size_t n);
	void insert(T data, size_t n);
	template<typename Q>
	friend std::ostream &operator<<(std::ostream &stream, const List<Q>& list);

private:
	struct entry_list {
		T value;
		entry_list* next;
		entry_list* pre;
	};

	entry_list* first;
	entry_list* last;
	size_t size;
};

template <typename T>
List<T>::List() {
	first = new entry_list;
	last = first;
	last->pre = nullptr;
	last->next = last;
}

template <typename T>
List<T>::~List() {
	entry_list* entry = first;
	if (entry) {
		while (entry != last) {
			entry = entry->next;
			delete entry->pre;
		}
			delete entry;
	}
}

template <typename T>
T& List<T>::operator[](size_t n) {
	if (n >= size) {
		throw std::runtime_error("Out of range");
	}
	entry_list* t = first;
	for (size_t i = 0; i < n; i++) {
		t = t->next;
	}
	return (t->value);
};

template <typename T>
void List<T>::insert(T data, size_t n) {
	entry_list* entry = new entry_list;
	entry->value = data;
	size++;
	entry_list* t = (this[n]).next;
	(this[n]).next = entry;
	t->pre = entry;
	entry->pre = this[n];
	entry->next = t;
}

template<typename Q>
std::ostream &operator<<(std::ostream &stream, const List<Q>& list) {
	for (int i = 0; i < size; ++i) {
		stream << list[i] << ' ';
	}
	return stream;
}

#endif//__LIST_