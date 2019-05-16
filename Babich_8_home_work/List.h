#ifndef LIST_H
#define LIST_H
#include <iostream>





template <typename T>
class List
{
public:
	List(T firstline)
	{
		this->enter = new  Line;
		this->enter->data = firstline;
		this->enter->next = nullptr;
		this->length++;
	}
	List()
	{
		this->enter = new  Line;
		this->enter->next = nullptr;
		this->length++;
	}
	~List()
	{
		 Line* buf1 = this->enter;
		 Line* buf2 = this->enter;
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
		 Line* newLine = new  Line;
		stream >> newLine->data;
		newLine->next = nullptr;
		 Line* buf = input.enter;
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
		 Line* buf = output.enter;
		for (size_t i = 1; i < output.length+1; i++)
		{
			stream << buf->data << ' ';
			buf = buf->next;
		}
		return stream;
	}

	 T& operator[](size_t pos)
	{
		if (pos > length)
			return nullptr;
		 Line* buf = enter;
		for (size_t i = 0; i < pos; i++)
		{
			buf = buf->next;
		}
		return buf->data;
	}

	void DelLine(T data)
	{
		size_t count = 0;
		 Line* buf1 = this->enter;
		while (buf1->next != nullptr)
		{
			if (buf1->data == data)
			{
			count++;
			break;
			}
			buf1 = buf1->next;
		}
		
		if(count == 0)
			return;
	
		Line* prev = enter;
		while ((prev->next != buf1)&&(buf1 != enter))
		{
			prev=prev->next;
		}
		
		if(prev == enter)
		{
		Line* sec = enter->next;
		delete[] enter;
		enter = new Line;
		enter->next = sec;
		}
		 Line* buf = buf1->next;
		prev->next = (prev->next)->next;
		delete[] buf;
		if (this->length > 1)
		this->length--;
		return;
	}



private:
	struct Line {
	T data;
	 Line* next;
};
	size_t length = 0;
	 Line* enter;
	 
};

#endif /*LIST_H*/
