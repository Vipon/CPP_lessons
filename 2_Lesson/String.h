#ifndef __STRING_H
#define __STRING_H

#include <cstddef>


class String {

public:
	String(size_t size); 	// !TODO
	~String();				// !TODO

	char get(size_t pos);
	void insert(size_t pos, char a);
	String& append(String& s1);
	size_t size();

private:
	char*	str;
	size_t 	len;
};

#endif /* __STRING_H */
