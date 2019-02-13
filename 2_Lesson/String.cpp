#include "String.h"
#include <cstring>

String::String(size_t size)
{
	/* C
	str = (char*)malloc(size*sizeof(char));
	if (str == nullptr)
		abort(); 
	*/
	str = new char[size];
	len = size;
}


String::~String()
{
	/* C
	free(str);
	*/
	delete [] str;
}


char String::get(size_t pos)
{
	if (pos > len) {
		//abort();
	}

	return str[pos];
}


void String::insert(size_t pos, char a)
{
	if (pos > len) {
		//abort();
	}

	str[pos] = a;
}


String& String::append(String& s1)
{
	char *temp = new char[this->len + s1.len];
	memcpy(temp, this->str, this->len);
	memcpy(&temp[this->len - 1], s1.str, s1.len);

	delete [] str;
	str = temp;
}


size_t String::size()
{
	return len;
}

#include <string>
#include <iostream> /* 	
						class ostream;
						class istream;
					*/

int main()
{
	std::string str, str0;
	std::cin >> str >> str0;
	std::cout << 100 << str << ' ' << str0 << std::endl;
}

