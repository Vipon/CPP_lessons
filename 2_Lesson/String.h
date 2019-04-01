#ifndef __STRING_H
#define __STRING_H

#include <cstddef>

class String {

public:
    String(const char *str);
    String(const String& s);
    ~String();

    size_t  size() const;
    char    get(size_t pos) const;
    void    insert(size_t pos, char a);
    void    append(const String& s1);
    void    print() const;

private:
    size_t  len;
    char*   str;

};

#endif /* __STRING_H */
