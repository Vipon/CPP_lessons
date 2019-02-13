#include "String.h"
#include <cstdlib>
#include <cstring>
#include <iostream> /**
                     *  class ostream;
                     *  class istream;
                     */

String::String(const char *s) :
    len(strlen(s)),
    str(new char[len + 1]) // extra space for '\0'
{
    if (s == nullptr) {
        abort();
    }

    // copy string including terminate '\0' symbol.
    memcpy(this->str, s, len + 1);
}


String::String(const String& s) :
    len(s.len),
    str(new char[len + 1]) // extra space for '\0'
{
    memcpy(this->str, s.str, len);
}


String::String(String&& s) noexcept :
    len(s.len),
    str(s.str)
{
    s.str = nullptr;
    s.len = 0;
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


char& String::operator[](size_t pos)
{
    if (pos > len) {
        abort();
    }

    return str[pos];
}


String& String::operator+=(const String& s)
{
    size_t newLen = len + s.len;
    // extra byte for terminate '\0'
    auto temp = new char[newLen + 1];
    memcpy(temp, str, len);
    memcpy(temp + len, s.str, s.len);

    delete [] str;
    len = newLen;
    str = temp;

    return *this;
}


String String::operator+(const String& s) const
{
    return (String(str) += s);
}


std::ostream& operator<<(std::ostream& os, const String& s)
{
    os << s.str;
    return os;
}


std::istream& operator>>(std::istream& is, String& s)
{
    if (s.len == 0) {
        s.str = new char[1];
        s.len = 1;
    }

    char buf = 0;
    size_t len = 0;
    while (is.get(buf)) {
        if (buf == ' ' || buf == '\n') {
            break;
        }

        if (s.len <= len) {
            char* temp = s.str;
            s.str = new char[s.len * 2];
            memcpy(s.str, temp, s.len);
            s.len *= 2;
            delete [] temp;
        }

        s.str[len] = buf;
        ++len;
    }

    char* temp = s.str;
    s.str = new char[len + 1];
    memcpy(s.str, temp, len);
    s.str[len] = '\0';
    s.len = len;
    delete [] temp;
    return is;
}


int main()
{
    std::cout << "What is your name?\n";
    String name;
    std::cin >> name;
    String str("Hello?");
    std::cout << str << ' ' << name << std::endl;
    std::cout << "Your name has " << name.size() << " characters\n";

    str[str.size()-1] = '!';
    std::cout << "Ooups! I meant " << str << ' ' << name << '!' << std::endl;

    String str1("Hello!");
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "String len = " << str1.size() << std::endl;

    String sum_str(str + str1);
    std::cout << "sum_str: " << sum_str << std::endl;
    std::cout << "String len = " << sum_str.size() << std::endl;

    str += str1;
    std::cout << "str: " << str << std::endl;
    std::cout << "String len = " << str.size() << std::endl;

    std::cout << "str1: " << str1 << std::endl;
    return 0;
}
