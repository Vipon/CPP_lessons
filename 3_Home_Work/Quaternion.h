#ifndef QUATERNION
#define QUATERNION

#include <cstdlib>
#include <iostream>

class Quaternion
{
private:
    double r;
    double i;
    double j;
    double k;
//r,i,j,k is corresponding components of some quaternion
//I use short names, becouse they make the code more readable in this situation 
public:
    Quaternion(
        const double a = 0, 
        const double b = 0, 
        const double c = 0, 
        const double d = 0);
    /* We don't need to write constructor of copy, becouse default constructor
    of copy is working right.
    Also, we don't need in move-constructor in class Quaternion, becouse
    Quaternion's constructor of copy is fast.*/
    Quaternion& operator+=(const Quaternion& q);
    Quaternion operator+(const Quaternion& q) const;
    Quaternion operator+(const double& a) const;
    friend Quaternion operator+(const double& a,const Quaternion& q);
    Quaternion operator*(const Quaternion& q) const;
    Quaternion operator*(const double& a) const;
    friend Quaternion operator*(const double& a,const Quaternion& q);
    friend std::ostream& operator<<(std::ostream & os, const Quaternion& q);
    friend std::istream& operator>>(std::istream & os, Quaternion& q);
    ~Quaternion(){};
};

#endif