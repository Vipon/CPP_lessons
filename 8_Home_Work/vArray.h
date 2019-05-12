#ifndef __vARRAY_H
#define __vARRAY_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include <exception>

class vArrException : public std::exception {
public:
    vArrException(std::string&& err) noexcept : exc(std::move(err)) {}
    vArrException(vArrException&& gExc) noexcept : exc(std::move(gExc.exc)) {}
    const char* what() const noexcept { return exc.c_str(); }
private:
    std::string exc;
};

template <typename T>
class vArray {

public:
    // default constructor
    vArray() {};

    vArray(T A[], size_t length) :size(length), val(new T[length]) {
        if (val == nullptr) {
            throw vArrException("OUT OF MEMORY");
        }
        memcpy(val, A, sizeof(T) * size);
    };

    // constructor of copy
    vArray(const vArray<T>& vA) : size(vA.size), val(new T[vA.size]) {
        if (val == nullptr) {
            throw vArrException("OUT OF MEMORY");
        }
        memcpy(val, vA.val, sizeof(T) * vA.size);
    };

    // move constructor
    vArray(T &&vA) noexcept : val(vA.val), size(vA.size) {
        vA.val = nullptr;
        vA.size = 0;
    };

    //destructor
    ~vArray() { delete[] val; }

    template <typename T0>
    friend std::ostream& operator<<(std::ostream &out, const vArray<T0> &vA);

    template <typename T0>
    friend std::istream& operator>>(std::istream &in, vArray<T0> &vA);

    vArray& operator=(const vArray<T>& vA) {
        size = vA.size;
        delete[] val;

        val = new T[size];
        if (val == nullptr) {
            throw vArrException("OUT OF MEMORY");
        }

        memcpy(val, vA.val, size * sizeof(T));
        return *this;
    }

    vArray& operator=(vArray<T>&& vA) {
        size = vA.size;
        val = vA.val;
        vA.size = 0;
        vA.val = nullptr;
        return *this;
    }

    T& operator[](size_t pos) {
        if (pos > size - 1) {
            throw vArrException("OUT OF SIZE");
        }
        return val[pos];
    }

    int find(T Req_val);

    void QSort(int begin, int end);

    void set_size(size_t new_size);

    void push_back(T elem);

private:
    T* val;
    size_t size;
};

/*first element you write wil be used only as closing one and not be put in list,
also you have to put the same element at the end to finish input */
template <typename T>
std::istream& operator>>(std::istream &in, vArray<T> &vA) {
    T end;
    T elem;
    in >> end;
    in >> elem;
    size_t i = 0;
    vA.size = 0;
     
    while (elem != end) {
        if (i >= vA.size) {
            T* temp = vA.val;

            vA.val = new T[(vA.size + 1) * 2];
            if (vA.val == nullptr) {
                throw vArrException("OUT OF MEMORY");
            }

            memcpy(vA.val, temp, sizeof(T) * vA.size);
            vA.size = (vA.size + 1) * 2;
            delete[] temp;
        }

        vA.val[i] = elem;
        i++;
        in >> elem;
    }

    T* temp = vA.val;
    vA.val = new T[i];
    if (vA.val == nullptr && vA.size != 0) {
        throw vArrException("OUT OF MEMORY");
    }

    memcpy(vA.val, temp, i * sizeof(T));
    delete[] temp;
    vA.size = i;

    return in;
}

template <typename T>
int vArray<T>::find(T Req_val) {
    for (int i = 0; i < size; i++) {
        if (Req_val == val[i]) {
            return i;
        }
    }
    return -1;
};


template <typename T>
std::ostream& operator<<(std::ostream &out, const vArray<T> &vA) {
    for (int i = 0; i < vA.size; i++) {
        out << (vA.val)[i] << ' ';
    }
    out << '\n';
    return out;
}

template <typename T>
void vArray <T>::QSort(int begin, int end) {
    if ((begin < 0) || (end > size - 1)) {
        throw vArrException("OUT OF SIZE");
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

template <typename T>
void vArray<T>::set_size(size_t new_size) {
    if (new_size == size) {
        return;
    }

    T* temp = val;
    val = new T[new_size];
    if (new_size < size) {
        memcpy(val, temp, new_size * sizeof(T));
    }
    else {
        memcpy(val, temp, size * sizeof(T));
    }
    size = new_size;
}


template <typename T>
void vArray<T>::push_back(T elem) {
    T* temp = val;
    val = new T[size + 1];
    if (val == nullptr) {
        throw vArrException("OUT OF MEMORY");
    }

    memcpy(val, temp, size * sizeof(T));
    delete[] temp;

    val[size] = elem;
    size++;
}

#endif //__vARRAY_H