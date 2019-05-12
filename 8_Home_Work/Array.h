#ifndef __ARRAY_H
#define __ARRAY_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include <exception>

class ArrException : public std::exception {
public:
    ArrException(std::string&& err) noexcept : exc(std::move(err)) {}
    ArrException(ArrException&& gExc) noexcept : exc(std::move(gExc.exc)) {}
    const char* what() const noexcept { return exc.c_str(); }
private:
    std::string exc;
};

template <typename T, size_t SIZE>
class Array {

public:
    // default constructor
    Array(){};
    
    Array(T(&A)[SIZE]) {
        memcpy(val, A, sizeof(T) * SIZE);
    };

    // constructor of copy
    Array(const Array<T,SIZE>& A) {
        memcpy(val, A.val, sizeof(T) * SIZE);
    };

    //destructor
    ~Array() {}

    template <typename T0, size_t SIZE0>
    friend std::ostream& operator<<(std::ostream &out, const Array<T0, SIZE0> &A);

    template <typename T0, size_t SIZE0>
    friend std::istream& operator>>(std::istream &in, Array<T0, SIZE0> &A);

    Array& operator=(const Array<T, SIZE>& A) {
        memcpy(val, A.val, SIZE * sizeof(T));
        return *this;
    }

    T& operator[](size_t pos) {
        if (pos > SIZE-1) {
            throw ArrException("OUT OF SIZE");
        }
        return val[pos];
    }

    int find(T Req_val);

    void QSort(int begin, int end);

private:
    T val[SIZE];
};

template <typename T, size_t SIZE> 
std::istream& operator>>(std::istream &in, Array<T, SIZE> &A) {
    for (int i = 0; i < SIZE; i++) {
        in >> (A.val)[i];
    }
    return in;
}

template <typename T, size_t SIZE> 
int Array<T,SIZE>::find(T Req_val) {
    for (int i = 0; i < SIZE; i++) {
        if (Req_val == val[i]) {
            return i;
        }
    }
    return -1;
}


template <typename T, size_t SIZE> 
std::ostream& operator<<(std::ostream &out, const Array<T,SIZE> &A) {
    for (int i = 0; i < SIZE; i++) {
        out << (A.val)[i] << ' ';
    }
    out << '\n';
    return out;
}

template <typename T, size_t SIZE>
void Array <T,SIZE>::QSort(int begin, int end) {
    if ((begin < 0) || (end > SIZE - 1)) {
        throw ArrException("OUT OF SIZE");
    }

    T temp;
    int b = begin;
    int e = end;

    while (b <= e) {
        while (val[b] < val[((b + e) / 2)]) {
            b++;
        }

        while (val[e] > val[((b + e) / 2)]) {
            e--;
        }

        if (b <= e) {
            temp = val[b];
            val[b++] = val[e];
            val[e--] = temp;
        }
    }

    if (begin < e) {
        QSort(begin, e);
    }

    if (end > b) {
        QSort(b, end);
    }
}


#endif //__ARRAY_H