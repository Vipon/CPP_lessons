#ifndef __Matrix_H
#define __Matrix_H

#include <cstdint>
#include <cstddef>
#include <iostream>

class Mat {

public:
    // default constructor
    Mat() : size(0), val(nullptr) {};
    Mat(const size_t size = 1) : size(size), val(nullptr) {};

    Mat(const uint16_t *val, const size_t size);
    // constructor of copy
    Mat(const Mat& m);

    // move constructor
    Mat(Mat&& m) noexcept;
    ~Mat();

    Mat& operator=(const Mat& m);
    uint16_t& operator[](size_t pos);
    Mat& operator+=(const Mat& m);
    friend std::ostream& operator<<(std::ostream& os, const Mat& m);
    friend std::istream& operator>>(std::istream& is, Mat& m);

private:
    size_t size; 
    uint16_t * val; //elements of permuation

};




#endif //Matrix_H
