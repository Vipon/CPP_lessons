#include "String.h"
#include <cstdlib>
#include <cstring>
#include <iostream> /**
                     *  class ostream;
                     *  class istream;
                     */

String::String(const char *str)
{
    if (str == nullptr) {
        abort();
    }

    len = strlen(str);

    /** C-language
     *  this->str = (char*)malloc(len);
     *  if (this->str == nullptr)
     *      abort();
     */

    // C++-language
    this->str = new char[len];
    // copy string including terminate '\0' symbol.
    memcpy(this->str, str, len + 1);
}


String::~String()
{
    /** C
     *  free(str);
     */

    // C++-language
    delete [] str;
}


size_t String::size() const
{
    return len;
}


char String::get(size_t pos) const
{
    if (pos > len) {
        abort();
    }

    return str[pos];
}


void String::insert(size_t pos, char a)
{
    if (pos > len) {
        abort();
    }

    str[pos] = a;
}


void String::append(const String& s1)
{
    len = len + s1.len;
    // extra byte for terminate '\0'
    auto temp = new char[len + 1];
    memcpy(temp, str, len);
    memcpy(temp + len, s1.str, s1.len);

    delete [] str;
    str = temp;
}


void String::print() const
{
    std::cout << str << std::endl;
}


int main()
{
    String str("Hello world!");
    std::cout << "str: ";
    str.print();
    std::cout << "String len = " << str.size() << std::endl;

    String str1("Hello!");
    std::cout << "str1: ";
    str1.print();
    std::cout << "String len = " << str1.size() << std::endl;

    str.append(str1);
    std::cout << "str: ";
    str.print();
    std::cout << "String len = " << str.size() << std::endl;

    std::cout << "str1: ";
    str1.print();
    return 0;
}
