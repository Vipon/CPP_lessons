#ifndef MY_CLASS_H
#define MY_CLASS_H
#define p 7
#include "Stack02.h"
#include <iostream>
#include <cstdio>
using namespace std;

class Zp{
public:
	Zp();
	~Zp();
	Zp operator+(Zp lal);
	Zp operator*(Zp lal);
	Zp operator^(int pow);
	int val=0;
	friend std::ostream& operator<<(std::ostream& op, Zp& output);
    friend std::istream& operator>>(std::istream& in, Zp& input);
private:
	size_t Char;
};
#endif /*MY_CLASS_H*/