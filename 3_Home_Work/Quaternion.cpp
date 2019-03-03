#include "Quaternion.h"
#include <cstdlib>
#include <iostream>

Quaternion::Quaternion(const double a, const double b, const double c, const double d):
    r(a),
    i(b),
    j(c),
    k(d)
{};

Quaternion& Quaternion::operator+=(const Quaternion& q)
{
    r += q.r;
    i += q.i;
    j += q.j;
    k += q.k;
    return *this;
}

Quaternion Quaternion::operator+(const Quaternion& q) const
{
    return (Quaternion(r, i, j, k) += q);
}

Quaternion Quaternion::operator+(const double& a) const
{
    return (Quaternion(r, i, j, k) += Quaternion(a));
}

Quaternion operator+(const double& a,const Quaternion& q)
{
    return (Quaternion(q.r, q.i, q.j, q.k) += Quaternion(a));
}

Quaternion Quaternion::operator*(const Quaternion& q) const
{
    double r0 = (this->r)*(q.r) - (this->i)*(q.i) - (this->j)*(q.j) - (this->k)*(q.k);
    double i0 = (this->r)*(q.i) + (this->i)*(q.r) + (this->j)*(q.k) + (this->k)*(q.j);
    double j0 = (this->r)*(q.j) + (this->j)*(q.r) - (this->i)*(q.k) + (this->k)*(q.i);
    double k0 = (this->r)*(q.k) + (this->k)*(q.r) + (this->i)*(q.j) - (this->j)*(q.i);
    Quaternion Mul(r0, i0, j0, k0);
    return Mul;
}

Quaternion Quaternion::operator*(const double& a) const
{
    Quaternion Mul((this->r)*a, (this->i)*a, (this->j)*a, (this->k)*a);
    return Mul;
}

Quaternion operator*(const double& a,const Quaternion& q)
{
    Quaternion Mul((q.r)*a, (q.i)*a, (q.j)*a, (q.k)*a);
    return Mul;
}

std::ostream& operator<<(std::ostream & os, const Quaternion& q)
{
    os << q.r << " + " << q.i << "i + "<< q.j << "j + "<< q.k << "k";
    return os;
}

std::istream& operator>>(std::istream & os, Quaternion& q)
{
    os >> q.r >> q.i >> q.j >> q.k;
    return os;
}