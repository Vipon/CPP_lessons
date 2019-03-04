#include "Matrix.h"
#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <iostream> 


Mat::Mat(const uint16_t *val, const size_t size) :
    size(size), 
    val(new uint16_t[size])
{
    memcpy(this->val, val, (size* sizeof(uint16_t)));
}

Mat::Mat(const Mat& m) :
    size(m.size),
    val(new uint16_t[size]) 
{
    memcpy(this->val, m.val, size);
}


Mat::Mat(Mat&& m) noexcept :
    size(m.size),
    val(m.val)
{
    m.val = nullptr;
    m.size = 0;
}


Mat::~Mat()
{
    delete[] val;
}


uint16_t& Mat::operator[](size_t pos)
{
    if (pos > size) {
        abort();
    }

    return val[pos];
}


Mat& Mat::operator=(const Mat& m)
{
    size = m.size;
    delete[] val;
    val = new uint16_t[size];
    memcpy(val, m.val, size * sizeof(uint16_t));

    return *this;
}


std::ostream& operator<<(std::ostream& os, const Mat& m)
{
    os << "| ";
    int t = sqrt(m.size);
    for (int i = 1; i < (m.size); ++i) {
        if (i % t == 1 && i != 1) {
            os << "|\n| ";
        }

        os << (m.val)[i - 1] << " ";
    };

    os << (m.val)[m.size - 1] << " |";
    return os;
}


std::istream& operator>>(std::istream& is, Mat& m)
{
    size_t i = 0;

    for (i = 0; i < m.size; ++i) {
        is >> (m.val)[i];
    };

    return is;
}


Mat& Mat::operator+=(const Mat& m)
{
    if ((this->size) < (m.size)) {
        uint16_t* temp = val;
        val = new uint16_t[m.size];
        memcpy(val, temp, (size * (sizeof(uint16_t))));

        size_t i = 0;
        for (i = size; i < m.size; ++i) {
            val[i] = i;
        };

        size = m.size;
        delete[] temp;
    }

    size_t i = 0;
    for (i = 0; i < m.size; ++i) {
        val[i] +=m.val[i];
    };

    return *this;
}

