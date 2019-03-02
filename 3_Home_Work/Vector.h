#ifndef __VECTOR_H
#define __VECTOR_H

#include <cstddef>
#include <iostream>

/*A class of a pointed section in n-dimentional (n = dim) space, that is defined 
by three coordinates*/ 
class Vector { 

public:
	Vector(size_t dim = 3);
	Vector(double* c, size_t dim = 1);
	// constructor of copy
	Vector(const Vector& v);
	// move constructor
	Vector(Vector&& v) noexcept;
	~Vector();

	double abs();

	Vector& operator=(const Vector& v);
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	//multiplication of Vector by a number
	Vector& operator*=(double value); 
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	double operator[](size_t pos);
	friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	//Example of Vector input: (x1; x2; x3) for dim = 3; x1, x2, x3 - coordinates.
	friend std::istream& operator>>(std::istream& is, Vector& v);

private:
	size_t dim; //dimension
	double* crd; //coordinates

};




#endif //__VECTOR_H