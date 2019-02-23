#include "Vector.h"
#include <cstring>

Vector::Vector(size_t dim)
{
	this->dim = dim;
	crd = new double[dim];
	size_t i = 0;
	for (i = 0; i < 3; ++i) {
		crd[i] = 0;
	}
}


Vector::Vector(double* crd, size_t dim) 
{
	this->crd = new double[dim];
	this->dim = dim;
	memcpy(this->crd, crd, (dim*(sizeof(double))));
}


Vector::Vector(const Vector& v) :
    dim(v.dim),
    crd(new double[dim])
{
    memcpy(this->crd, v.crd, (dim*(sizeof(double))));
}


Vector::Vector(Vector&& v) noexcept :
    dim(v.dim),
    crd(v.crd)
{
    v.crd = nullptr;
    v.dim = 0;
}


Vector::~Vector()
{
	delete [] crd;
}


double Vector::abs()
{
	double a = 0;
	size_t i = 0;

	for (i = 0; i < dim; i++) {
		a += (crd[i]) * (crd[i]);
	}

	return a;
}


Vector& Vector::operator=(const Vector& v)
{
	dim = v.dim;
	delete [] crd;
	crd = new double[dim];
	memcpy(this->crd, v.crd, (dim * (sizeof(double))));
	return *this;
}


Vector& Vector::operator+=(const Vector& v)
{
	if ((this->dim) < (v.dim)) {
		double* temp = crd;
		crd = new double[v.dim];
		memcpy(crd, temp, (dim * (sizeof(double))));

		size_t i = 0;
		for (i = dim; i < v.dim; ++i) {
			crd[i] = 0;
		};

		dim = v.dim;
		delete [] temp;
	}

	size_t i = 0;
	for (i = 0; i < v.dim; ++i) {
		crd[i] += v.crd[i];
	};

	return *this;
}


Vector Vector::operator+(const Vector& v) const
{
	return (Vector(crd, dim) += v);
}


Vector& Vector::operator*=(double value)
{
	size_t i = 0;
	for (i = 0; i < dim; ++i) {
		crd[i] *= value;
	};

	return *this;
}


Vector& Vector::operator-=(const Vector& v)
{
	Vector temp(v);
	temp *= -1;
	(*this) += temp;
	return *this;
}


Vector Vector::operator-(const Vector& v) const
{
	return (Vector(crd, dim) -= v);
}


double Vector::operator[](size_t pos)
{
	if (pos >= dim) {
		abort();
	}

	return (crd[pos]);
}


std::ostream& operator<<(std::ostream& os, const Vector& v) 
{
	os << '(';
	size_t i = 0;
	for (i = 0; i < (v.dim - 1); ++i) {
		os << (v.crd)[i] << "; ";
	};

	os << (v.crd)[v.dim - 1] << ')';
	return os;
}


std::istream& operator>>(std::istream& is, Vector& v)
{
	size_t i = 0;

	for (i = 0; i < v.dim; ++i) {
		is >> (v.crd)[i];
	}; 

	return is;
}