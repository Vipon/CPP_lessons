#ifndef __STRING_H
#define __STRING_H

#include <cstddef>
#include <iostream>

class String {

public:
    // default constructor
    String() : len(0), str(nullptr) {};
    // constructor from c-string
    String(const char *s);
    // constructor of copy
    String(const String& s);
    // move constructor
    String(String&& s) noexcept;
    ~String();

    size_t                  size() const;
    char&                   operator[](size_t pos);
    String&                 operator=(const String& s);
    String&                 operator+=(const String& s);
    String                  operator+(String& s);
    friend std::ostream&    operator<<(std::ostream& os, String& s);
    friend std::ostream&    operator<<(std::ostream& os, String&& s);
    friend std::istream&    operator>>(std::istream& is, String& s);

private:
    size_t  len;
    char*   str;
};

#endif /* __STRING_H */
