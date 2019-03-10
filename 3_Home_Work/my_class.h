#ifndef MY_CLASS_H
#define MY_CLASS_H
#include "Stack02.h"
#include <iostream>
#include <cstdio>
using namespace std;

class Zp{
public:
	Zp(size_t p);
	~Zp();
	int operator+(int val);
	int operator*(int val);
	int operator^(int pow);
	void dump();
	size_t Char;
//	friend std::ostream operator<<(std::ostream& op, const string& s);
//  friend std::istream operator>>(std::istream& ip, const string& s);
private:
	Stack zp;
};
#endif /*MY_CLASS_H*/