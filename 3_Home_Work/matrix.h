#ifndef MATRIX_H
#define MATRIX_H

#include <cstdint>
#include <iostream>
#include <cstdlib>


class matrix
{
public:

	matrix() {};//default constructor
	matrix(const int& h, const int& w);
	matrix (const matrix& A);//copy constructor
	matrix(matrix&& A) noexcept;//move constructor

	~matrix();
	matrix operator+ (const matrix& A);
	matrix operator* (const matrix& A);
	matrix operator* (int N);

	friend std::ostream& operator<< (std::ostream& out, const matrix& A);
	friend std::istream& operator>> (std::istream& in, const matrix& A);

 
private:
	int **m;
	int height, width;
	
};

#endif