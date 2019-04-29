#ifndef LIST_H
#define LIST_H
#include <iostream>

template <typename T>
struct Line {
	T data;
	struct Line<T>* next;
};



template <typename T>
class List
{
public:
	List(T firstline)
	{
		this->enter = new struct Line<T>;
		this->enter->data = firstline;
		this->enter->next = nullptr;
		this->length++;
	}
	List()
	{
		this->enter = new struct Line<T>;
		this->enter->next = nullptr;
		this->length++;
	}
	~List()
	{
		struct Line<T>* buf1 = this->enter;
		struct Line<T>* buf2 = this->enter;
		while (buf1->next != nullptr)
		{
			buf2 = buf1->next;
			delete[] buf1;
			buf1 = buf2;
		}
		delete[] buf1;
	}
	friend std::istream& operator>>(std::istream& stream, List<T>& input)
	{
		struct Line<T>* newLine = new struct Line<T>;
		stream >> newLine->data;
		newLine->next = nullptr;
		struct Line<T>* buf = input.enter;
		while (buf->next != nullptr)
		{
			buf = buf->next;
		}
		buf->next = newLine;
		input.length++;
		return stream;
	}

	friend std::ostream& operator<<(std::ostream& stream, List<T>& output)
	{
		struct Line<T>* buf = output.enter;
		for (size_t i = 1; i < output.length+1; i++)
		{
			stream << buf->data << ' ';
			buf = buf->next;
		}
		return stream;
	}

	struct Line<T>* operator[](size_t pos)
	{
		if (size_t pos > length)
			return nullptr;
		struct Line<T> buf = enter;
		for (size_t i = 0; i < pos; i++)
		{
			buf = buf->next;
		}
		return buf;
	}

	void DelLine(struct Line<T>* prev)
	{
		struct Line<T>* buf = prev->next;
		prev->next = prev->next->next;
		delete[] buf;
		if (this->length > 1)
		this->length--;
		return;
	}

	struct Line<T>* findline(T data)
	{
		struct Line<T>* buf = this->enter;
		while (buf->next != nullptr)
		{
			if (buf->data == data)
				return buf;
			buf = buf->next;
		}
		return nullptr;
	}

private:
	size_t length = 0;
	struct Line<T>* enter;
};

#endif /*LIST_H*/
