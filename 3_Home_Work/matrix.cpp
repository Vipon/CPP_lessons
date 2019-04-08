#include <cstdint>
#include <cstdlib>
#include <iostream>


#include "matrix.h"

matrix::matrix(int h, int w):
	height(h), 
	width(w)
{

	m = new int* [height];

	for (int i = 0; i < height; ++i)
	{
		m[i] = new int [width];

		for (int j = 0; j < width; ++j)
		{
			m[i][j] = 0;
		}
	}
}

matrix::matrix(const matrix& A):
	height(A.height),
	width(A.width)
{	
	m = new int * [height];
	for (int i = 0; i < height; ++i)
	{
		m[i] = new int [width];
		for (int j = 0; i < width; ++j)
		{
			m[i][j] = A.m[i][j];
		}
	}	
}
	
matrix::matrix(matrix&& A) noexcept	:	
	m(A.m), 
	height(A.height), 
	width(A.width)
{
	A.m = nullptr;
	A.height = 0;
	A.width = 0;
}

matrix::~matrix()
{
	for (int i = 0; i < height; ++i)
	{
		delete[] m[i];
	}
	delete[] m;
}


matrix matrix::operator*(const matrix& A)
{
	matrix M(height, A.width);
	if(width != A.height)
	{
		abort();
	}
	else
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < A.width; ++j)
			{
				for (int k = 0; k < width; ++k)
				{
					M.m[i][j] += (m[i][k] * A.m[k][j]);
				}
			}
		}
	}

	return M;
}

matrix matrix::operator+(const matrix& A)
{
	matrix M(height, width);
	if (height != A.height || width != A.width)
	{
		abort();
	}
	else
	{
	
		for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width; ++j)
						{
							M.m[i][j] = m[i][j] + A.m[i][j];
						}		
			}		
	}
	return M;
}

matrix matrix::operator* (int N)
{
	matrix M(height, width);
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			M.m[i][j] = m[i][j] * N;
		}
	}
	return M;
}

std::ostream& operator<<(std::ostream& out, const matrix& A)
{
	for (int i = 0; i < A.height; ++i)
	{
		for(int j = 0; j < A.width; ++j)
		{
			out << A.m[i][j] << '\t';
		}
		out << std::endl;
	}
	return out;
}

std::istream& operator>> (std::istream& in, const matrix& A)
{
	for (int i = 0; i < A.height; ++i)
	{
		for(int j = 0; j < A.width; ++j)
		{
			in >> A.m[i][j];
		}
	}
	return in;	
}

